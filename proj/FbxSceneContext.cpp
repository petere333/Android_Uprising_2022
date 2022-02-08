#include "stdafx.h"
#include "GameObject.h"
#include "FbxSceneContext.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CFbxRenderInfo::CFbxRenderInfo()
{
}

CFbxRenderInfo::~CFbxRenderInfo()
{
	if (m_pMesh) m_pMesh->Release();

	if ((m_nLinkNodes > 0) && m_ppd3dcbLinkNodeTransforms)
	{
		for (int i = 0; i < m_nInstances; i++)
		{
			if (m_ppd3dcbLinkNodeTransforms[i]) m_ppd3dcbLinkNodeTransforms[i]->Release();
		}
		delete[] m_ppd3dcbLinkNodeTransforms;
	}
}

CShader *CFbxRenderInfo::m_pFbxModelShader = NULL;
CShader *CFbxRenderInfo::m_pFbxSkinnedModelShader = NULL;

void CFbxRenderInfo::CreateFbxModelShader(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature)
{
	m_pFbxModelShader = new CFbxModelShader();
	m_pFbxModelShader->CreateShader(pd3dDevice, pd3dGraphicsRootSignature);

	m_pFbxSkinnedModelShader = new CFbxSkinnedModelShader();
	m_pFbxSkinnedModelShader->CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

void CFbxRenderInfo::ReleaseFbxModelShader()
{
	if (m_pFbxModelShader) m_pFbxModelShader->Release();
	if (m_pFbxSkinnedModelShader) m_pFbxSkinnedModelShader->Release();
}

void CFbxRenderInfo::ReleaseUploadBuffers()
{
	if (m_pFbxModelShader) m_pFbxModelShader->ReleaseUploadBuffers();
	if (m_pFbxSkinnedModelShader) m_pFbxSkinnedModelShader->ReleaseUploadBuffers();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
XMFLOAT4X4 FbxMatrixToXmFloat4x4Matrix(FbxAMatrix *pfbxmtxSource)
{
	XMFLOAT4X4 xmf4x4Result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) xmf4x4Result.m[j][i] = (float)(*pfbxmtxSource)[i][j];
	}

	return(xmf4x4Result);
}

FbxAMatrix XmFloat4x4MatrixToFbxMatrix(XMFLOAT4X4& xmf4x4Source)
{
	FbxAMatrix fbxmtxResult;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) fbxmtxResult[i][j] = xmf4x4Source.m[i][j];
	}
	return(fbxmtxResult);
}

FbxAMatrix GetGeometricOffsetTransform(FbxNode *pfbxNode)
{
	const FbxVector4 T = pfbxNode->GetGeometricTranslation(FbxNode::eSourcePivot);
	const FbxVector4 R = pfbxNode->GetGeometricRotation(FbxNode::eSourcePivot);
	const FbxVector4 S = pfbxNode->GetGeometricScaling(FbxNode::eSourcePivot);

	return(FbxAMatrix(T, R, S));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
void RenderFbxNodeHierarchy(ID3D12GraphicsCommandList *pd3dCommandList, FbxNode *pfbxNode, FbxTime& fbxCurrentTime, FbxAMatrix& fbxmtxWorld, int nInstance)
{
	FbxNodeAttribute *pfbxNodeAttribute = pfbxNode->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh *pfbxMesh = pfbxNode->GetMesh();
		CFbxRenderInfo *pFbxRenderInfo = (CFbxRenderInfo *)pfbxMesh->GetUserDataPtr();
		if (pFbxRenderInfo->m_nLinkNodes > 0)
		{
			D3D12_GPU_VIRTUAL_ADDRESS d3dcbLinkNodeTransformsGpuVirtualAddress = pFbxRenderInfo->m_ppd3dcbLinkNodeTransforms[nInstance]->GetGPUVirtualAddress();
			pd3dCommandList->SetGraphicsRootConstantBufferView(6, d3dcbLinkNodeTransformsGpuVirtualAddress); //Skinned Bone Transforms

			FbxSkin *pfbxSkinDeformer = (FbxSkin *)pfbxMesh->GetDeformer(0, FbxDeformer::eSkin);
			for (int j = 0; j < pFbxRenderInfo->m_nLinkNodes; j++)
			{
				FbxCluster *pfbxCluster = pfbxSkinDeformer->GetCluster(j);
				FbxAMatrix fbxmtxAnimatedBoneToWorld = fbxmtxWorld * pfbxCluster->GetLink()->EvaluateGlobalTransform(fbxCurrentTime); //Cluster Link Node Global Transform
				pFbxRenderInfo->m_ppcbxmf4x4MappedLinkNodeTransforms[nInstance][j] = ::FbxMatrixToXmFloat4x4Matrix(&fbxmtxAnimatedBoneToWorld);
			}

			if (pFbxRenderInfo->m_pMesh) pFbxRenderInfo->m_pMesh->UpdateShaderVariables(pd3dCommandList);

			CFbxRenderInfo::m_pFbxSkinnedModelShader->Render(pd3dCommandList);
		}
		else
		{
			FbxAMatrix fbxmtxGeometryOffset = GetGeometricOffsetTransform(pfbxNode);
			FbxAMatrix fbxmtxNodeToRoot = pfbxNode->EvaluateGlobalTransform(fbxCurrentTime);
			FbxAMatrix fbxmtxTransform = fbxmtxWorld * fbxmtxNodeToRoot * fbxmtxGeometryOffset;
			CGameObject::UpdateShaderVariable(pd3dCommandList, &fbxmtxTransform);



			CFbxRenderInfo::m_pFbxModelShader->Render(pd3dCommandList);
		}

		if (pFbxRenderInfo->m_pMesh) pFbxRenderInfo->m_pMesh->Render(pd3dCommandList);
	}

	int nChilds = pfbxNode->GetChildCount();
	for (int i = 0; i < nChilds; i++)
	{
		RenderFbxNodeHierarchy(pd3dCommandList, pfbxNode->GetChild(i), fbxCurrentTime, fbxmtxWorld, nInstance);
	}
}

void CreateMeshFromFbxNodeHierarchy(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, FbxNode *pfbxNode, int nInstances)
{
	FbxNodeAttribute *pfbxNodeAttribute = pfbxNode->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh *pfbxMesh = pfbxNode->GetMesh();
		if (pfbxMesh)
		{
			int nVertices = pfbxMesh->GetControlPointsCount();
			FbxVector4 *pfbxv4Vertices = new FbxVector4[nVertices];
			::memcpy(pfbxv4Vertices, pfbxMesh->GetControlPoints(), nVertices * sizeof(FbxVector4));

			XMFLOAT4 *pxmf4Vertices = new XMFLOAT4[nVertices];
			for (int j = 0; j < nVertices; j++)
			{
				pxmf4Vertices[j] = XMFLOAT4((float)pfbxv4Vertices[j][0], (float)pfbxv4Vertices[j][1], (float)pfbxv4Vertices[j][2], 1.0f);
			}

			int nIndices = 0;
			int nPolygons = pfbxMesh->GetPolygonCount();
			for (int i = 0; i < nPolygons; i++)
			{
				nIndices += pfbxMesh->GetPolygonSize(i);
			}//Triangle: 3, Triangulate(), nIndices = nPolygons * 3

			int *pnIndices = new int[nIndices];
			for (int i = 0, k = 0; i < nPolygons; i++)
			{
				int nPolygonSize = pfbxMesh->GetPolygonSize(i); 
				for (int j = 0; j < nPolygonSize; j++) pnIndices[k++] = pfbxMesh->GetPolygonVertex(i, j);
			}

			CFbxRenderInfo *pFbxRenderInfo = new CFbxRenderInfo();

			int nSkinDeformers = pfbxMesh->GetDeformerCount(FbxDeformer::eSkin);
			if (nSkinDeformers > 0)
			{
				FbxSkin *pfbxSkinDeformer = (FbxSkin *)pfbxMesh->GetDeformer(0, FbxDeformer::eSkin);
				int nClusters = pfbxSkinDeformer->GetClusterCount();

				int *pnBonesPerVertex = new int[nVertices];
				::memset(pnBonesPerVertex, 0, nVertices * sizeof(int));
				for (int j = 0; j < nClusters; j++)
				{
					FbxCluster *pfbxCluster = pfbxSkinDeformer->GetCluster(j);
					int nControlPointIndices = pfbxCluster->GetControlPointIndicesCount();
					int *pnControlPointIndices = pfbxCluster->GetControlPointIndices();
					for (int k = 0; k < nControlPointIndices; k++)
					{
						pnBonesPerVertex[pnControlPointIndices[k]]++;
					}
				}
				int nMaxBonesPerVertex = 0;
				for (int i = 0; i < nVertices; i++)
				{
					if (pnBonesPerVertex[i] > nMaxBonesPerVertex)
					{
						nMaxBonesPerVertex = pnBonesPerVertex[i];
					}
				}

				int **ppnBoneIDs = new int*[nVertices];
				float **ppnBoneWeights = new float*[nVertices];
				for (int i = 0; i < nVertices; i++)
				{
					ppnBoneIDs[i] = new int[pnBonesPerVertex[i]];
					ppnBoneWeights[i] = new float[pnBonesPerVertex[i]];
					::memset(ppnBoneIDs[i], 0, pnBonesPerVertex[i] * sizeof(int));
					::memset(ppnBoneWeights[i], 0, pnBonesPerVertex[i] * sizeof(float));
				}

				int *pnBones = new int[nVertices];
				::memset(pnBones, 0, nVertices * sizeof(int));

//				FbxAMatrix fbxmtxGeometryOffset = GetGeometricOffsetTransform(pfbxNode);
				FbxAMatrix fbxmtxGeometryOffset = GetGeometricOffsetTransform(pfbxMesh->GetNode());

				FbxAMatrix *pfbxmtxVertextToLinkNodes = new FbxAMatrix[nClusters];
				for (int j = 0; j < nClusters; j++)
				{
					FbxCluster *pfbxCluster = pfbxSkinDeformer->GetCluster(j);

					FbxAMatrix fbxmtxBindPoseMeshToRoot; //Cluster Transform
					pfbxCluster->GetTransformMatrix(fbxmtxBindPoseMeshToRoot);
					FbxAMatrix fbxmtxBindPoseBoneToRoot; //Cluster Link Transform
					pfbxCluster->GetTransformLinkMatrix(fbxmtxBindPoseBoneToRoot);

					pfbxmtxVertextToLinkNodes[j] = fbxmtxBindPoseBoneToRoot.Inverse() * fbxmtxBindPoseMeshToRoot * fbxmtxGeometryOffset;

					int *pnControlPointIndices = pfbxCluster->GetControlPointIndices();
					double *pfControlPointWeights = pfbxCluster->GetControlPointWeights();
					int nControlPointIndices = pfbxCluster->GetControlPointIndicesCount();

					for (int k = 0; k < nControlPointIndices; k++)
					{
						int nVertex = pnControlPointIndices[k];
						ppnBoneIDs[nVertex][pnBones[nVertex]] = j;
						ppnBoneWeights[nVertex][pnBones[nVertex]++] = (float)pfControlPointWeights[k];
					}
				}
					
				float *pnSumOfBoneWeights = new float[nVertices];
				::memset(pnSumOfBoneWeights, 0, nVertices * sizeof(float));

				for (int i = 0; i < nVertices; i++)
				{
					for (int j = 0; j < pnBonesPerVertex[i]; j++) 
					{ pnSumOfBoneWeights[i] += ppnBoneWeights[i][j]; }
					for (int j = 0; j < pnBonesPerVertex[i]; j++) 
					{ ppnBoneWeights[i][j] /= pnSumOfBoneWeights[i]; }
				}

				if (pnSumOfBoneWeights) delete[] pnSumOfBoneWeights;

				for (int i = 0; i < nVertices; i++)
				{
					for (int j = 0; j < pnBonesPerVertex[i] - 1; j++)
					{
						for (int k = j + 1; k < pnBonesPerVertex[i]; k++)
						{
							if (ppnBoneWeights[i][j] < ppnBoneWeights[i][k])
							{
								float fTemp = ppnBoneWeights[i][j];
								ppnBoneWeights[i][j] = ppnBoneWeights[i][k];
								ppnBoneWeights[i][k] = fTemp;
								int nTemp = ppnBoneIDs[i][j];
								ppnBoneIDs[i][j] = ppnBoneIDs[i][k];
								ppnBoneIDs[i][k] = nTemp;
							}
						}
					}
				}

				int (*pnSkinningIndices)[4] = new int[nVertices][4];
				float (*pfSkinningWeights)[4] = new float[nVertices][4];

				for (int i = 0; i < nVertices; i++)
				{
					::memset(pnSkinningIndices[i], 0, 4 * sizeof(int));
					::memset(pfSkinningWeights[i], 0, 4 * sizeof(float));

					for (int j = 0; j < pnBonesPerVertex[i]; j++)
					{
						if (j < 4)
						{
							pnSkinningIndices[i][j] = ppnBoneIDs[i][j];
							pfSkinningWeights[i][j] = ppnBoneWeights[i][j];
						}
					}
				}

				XMFLOAT4X4 *pxmf4x4VertextToLinkNodes = new XMFLOAT4X4[nClusters]; //Bone Offset Transforms
				for (int j = 0; j < nClusters; j++)
				{
					pxmf4x4VertextToLinkNodes[j] = ::FbxMatrixToXmFloat4x4Matrix(&pfbxmtxVertextToLinkNodes[j]);
				}

				pFbxRenderInfo->m_pMesh = new CMeshFromFbx(pd3dDevice, pd3dCommandList, nVertices, pxmf4Vertices, nIndices, pnIndices, pnSkinningIndices, pfSkinningWeights, nClusters, pxmf4x4VertextToLinkNodes);

				pFbxRenderInfo->m_nLinkNodes = nClusters;
				pFbxRenderInfo->m_nInstances = nInstances;
				pFbxRenderInfo->m_ppd3dcbLinkNodeTransforms = new ID3D12Resource*[nInstances]; //Bone Transforms
				pFbxRenderInfo->m_ppcbxmf4x4MappedLinkNodeTransforms = new XMFLOAT4X4*[nInstances]; //Bone Transforms

				UINT ncbElementBytes = (((sizeof(XMFLOAT4X4) * SKINNED_ANIMATION_BONES) + 255) & ~255); //256ÀÇ ¹è¼ö
				for (int i = 0; i < nInstances; i++)
				{
					pFbxRenderInfo->m_ppd3dcbLinkNodeTransforms[i] = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
					pFbxRenderInfo->m_ppd3dcbLinkNodeTransforms[i]->Map(0, NULL, (void **)&pFbxRenderInfo->m_ppcbxmf4x4MappedLinkNodeTransforms[i]);
				}

				for (int i = 0; i < nVertices; i++)
				{
					if (ppnBoneIDs[i]) delete[] ppnBoneIDs[i];
					if (ppnBoneWeights[i]) delete[] ppnBoneWeights[i];
				}
				if (ppnBoneIDs) delete[] ppnBoneIDs;
				if (ppnBoneWeights) delete[] ppnBoneWeights;

				if (pnBones) delete[] pnBones;
				if (pnBonesPerVertex) delete[] pnBonesPerVertex;
				if (pnSkinningIndices) delete[] pnSkinningIndices;
				if (pfSkinningWeights) delete[] pfSkinningWeights;

				if (pfbxmtxVertextToLinkNodes) delete[] pfbxmtxVertextToLinkNodes;
			}
			else
			{
				pFbxRenderInfo->m_pMesh = new CMeshFromFbx(pd3dDevice, pd3dCommandList, nVertices, pxmf4Vertices, nIndices, pnIndices, NULL, NULL, 0, NULL);
			}

			pfbxMesh->SetUserDataPtr(pFbxRenderInfo);

			if (pfbxv4Vertices) delete[] pfbxv4Vertices;
			if (pxmf4Vertices) delete[] pxmf4Vertices;
			if (pnIndices) delete[] pnIndices;
		}
	}

	int nChilds = pfbxNode->GetChildCount();
	for (int i = 0; i < nChilds; i++)
	{
		CreateMeshFromFbxNodeHierarchy(pd3dDevice, pd3dCommandList, pfbxNode->GetChild(i), nInstances);
	}
}

void ReleaseRenderInfoFromFbxNodeHierarchy(FbxNode *pfbxNode)
{
	FbxNodeAttribute *pfbxNodeAttribute = pfbxNode->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh *pfbxMesh = pfbxNode->GetMesh();
		if (pfbxMesh) 
		{
			CFbxRenderInfo *pFbxRenderInfo = (CFbxRenderInfo *)pfbxMesh->GetUserDataPtr();
			if (pFbxRenderInfo) delete pFbxRenderInfo;
		}
	}

	int nChilds = pfbxNode->GetChildCount();
	for (int i = 0; i < nChilds; i++) ReleaseRenderInfoFromFbxNodeHierarchy(pfbxNode->GetChild(i));
}

void ReleaseUploadBufferFromFbxNodeHierarchy(FbxNode *pfbxNode)
{
	FbxNodeAttribute *pfbxNodeAttribute = pfbxNode->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh *pfbxMesh = pfbxNode->GetMesh();
		if (pfbxMesh) 
		{
			CFbxRenderInfo *pFbxRenderInfo = (CFbxRenderInfo *)pfbxMesh->GetUserDataPtr();
			if (pFbxRenderInfo && pFbxRenderInfo->m_pMesh) pFbxRenderInfo->m_pMesh->ReleaseUploadBuffers();
		}
	}

	int nChilds = pfbxNode->GetChildCount();
	for (int i = 0; i < nChilds; i++) ReleaseUploadBufferFromFbxNodeHierarchy(pfbxNode->GetChild(i));
}

FbxScene *LoadFbxSceneFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, FbxManager *pfbxSdkManager, const char *pstrFbxFileName)
{
	FbxScene *pfbxScene = NULL;

	int nSDKMajor, nSDKMinor, nSDKRevision;
	FbxManager::GetFileFormatVersion(nSDKMajor, nSDKMinor, nSDKRevision);

	FbxIOSettings *pfbxIOSettings = pfbxSdkManager->GetIOSettings();
	FbxImporter *pfbxImporter = FbxImporter::Create(pfbxSdkManager, " ");
	bool bImportStatus = pfbxImporter->Initialize(pstrFbxFileName, -1, pfbxIOSettings);

	int nFileFormatMajor, nFileFormatMinor, nFileFormatRevision;
	pfbxImporter->GetFileVersion(nFileFormatMajor, nFileFormatMinor, nFileFormatRevision);

	pfbxScene = FbxScene::Create(pfbxSdkManager, " ");
	bool bStatus = pfbxImporter->Import(pfbxScene);

	FbxGeometryConverter fbxGeomConverter(pfbxSdkManager);
	fbxGeomConverter.Triangulate(pfbxScene, true);
//	fbxGeomConverter.SplitMeshesPerMaterial(pfbxScene, true);

//	FbxAxisSystem fbxSceneAxisSystem = pfbxScene->GetGlobalSettings().GetAxisSystem();
//	FbxAxisSystem fbxDirectXAxisSystem(FbxAxisSystem::eDirectX);
//	if (fbxSceneAxisSystem != fbxDirectXAxisSystem) fbxDirectXAxisSystem.ConvertScene(pfbxScene);
//	fbxSceneAxisSystem = pfbxScene->GetGlobalSettings().GetAxisSystem();

	FbxSystemUnit fbxSceneSystemUnit = pfbxScene->GetGlobalSettings().GetSystemUnit();
	if (fbxSceneSystemUnit.GetScaleFactor() != 1.0) FbxSystemUnit::cm.ConvertScene(pfbxScene);

	pfbxImporter->Destroy();

	return(pfbxScene);
}
