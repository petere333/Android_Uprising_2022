#include "mat.h"

using namespace std;

FbxArray<FbxString*> names;

FbxScene* LoadFbxSceneFromFile(FbxManager*, const char*);

FbxScene* LoadFbxSceneFromFile(FbxManager* pfbxSdkManager, const char* pstrFbxFileName)
{
	FbxScene* pfbxScene = NULL;

	int nSDKMajor, nSDKMinor, nSDKRevision;
	FbxManager::GetFileFormatVersion(nSDKMajor, nSDKMinor, nSDKRevision);

	FbxIOSettings* pfbxIOSettings = pfbxSdkManager->GetIOSettings();
	FbxImporter* pfbxImporter = FbxImporter::Create(pfbxSdkManager, " ");
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

void getIndices(FbxNode* node);
void getUVs(FbxNode* node);
void getUVCoords(FbxNode* node);
void getAnimationData(FbxScene* scene);
void getBones(FbxNode* node);
FbxAMatrix GetGeometricOffsetTransform(FbxNode* pfbxNode);

void getMeshVertexAtTime();
void getBoneTransAtTime(FbxNode* node, int ms);


matrix4x4 FbxMatrixToXmFloat4x4Matrix(FbxAMatrix* pfbxmtxSource);

vector<int> idx;//������ �ε��� ����Ʈ
vector<int> uvIdx;//������ uv �ε��� ����Ʈ
int indexCount = 0;



vector<float2> uvList;//������ uv ��ǥ�� ����Ʈ
vector<float3> posList;//������ ��ǥ�� ����Ʈ

vector<char*> animationNamesList;
vector<AnimationData> animationDataList;

int(*skinIndex)[4];
float(*skinWeight)[4];
matrix4x4* pxmf4x4VertextToLinkNodes;
int nClust;

int maxIndex;

VertexUV vertices[1060];
vector<float3> mesh0; // �ִϸ��̼� �ð��� 0ms�϶� ���
vector<float3> mesh1; // �ִϸ��̼� �ð��� 33ms�϶� ���

vector<matrix4x4> boneTrans;
int main()
{
	printf("FBX ���� �ε� ��\n");
	FbxManager* manager = FbxManager::Create();
	FbxScene* scene = LoadFbxSceneFromFile(manager, "sample.fbx");
	printf("FBX ���� �ε� �Ϸ�\n");
	FbxNode* root = scene->GetRootNode();


	printf("�������� ���� �ε� ��\n");
	getIndices(root);
	getUVs(root);
	getUVCoords(root);
	printf("�������� ���� �ε� �Ϸ�\n");

	printf("�ִϸ��̼� ���� �ε� ��\n");
	getAnimationData(scene);
	printf("�ִϸ��̼� ���� �ε� �Ϸ�\n");

	printf("��Ų ���� �ε� ��\n");
	getBones(root);
	printf("��Ų ���� �ε� �Ϸ�\n");

	printf("0.5���� ���� �ε� ��");
	getBoneTransAtTime(root, 500);
	getMeshVertexAtTime();
	printf("0.5���� ���� �ε� �Ϸ�");

	FILE* idxOut = fopen("indices.txt", "w");
	FILE* uvOut = fopen("uvs.txt", "w");
	FILE* coordOut = fopen("uvCoords.txt", "w");
	FILE* posOut = fopen("positions.txt", "w");
	FILE* vtxOut = fopen("vertices.txt", "w");

	FILE* animOut = fopen("animations.txt", "w");

	FILE* skinOut = fopen("skinData.txt", "w");
	FILE * frameOut = fopen("frame0.txt", "w");
	FILE* boneTrans0Out = fopen("boneTrans0.txt", "w");
	//1061
	int maxidx = 0;
	for (int i = 0; i < idx.size(); ++i)
	{
		if (idx[i] > maxidx)
		{
			maxidx = idx[i];
		}
	}
	printf("���� ū ���� �ε��� = %d\n", maxidx);

	int maxuvidx = 0;

	for (int i = 0; i < uvIdx.size(); ++i)
	{
		if (uvIdx[i] > maxuvidx)
		{
			maxuvidx = uvIdx[i];
		}
	}
	printf("���� ū ���� uv �ε��� = %d\n", maxuvidx);

	
	for (int i = 0; i < idx.size(); ++i)
	{
		vertices[idx[i]].position = posList[i];


		vertices[idx[i]].uv = uvList[i];

	}

	printf("���Ͽ� ���� ��ǥ ��� ��\n");
	for (int i = 0; i < posList.size(); i += 3)
	{
		fprintf(posOut, "(%f, %f, %f),  (%f, %f, %f),  (%f, %f, %f)\n", posList[i].x, posList[i].y, posList[i].z,
			posList[i + 1].x, posList[i + 1].y, posList[i + 1].z, posList[i + 2].x, posList[i + 2].y, posList[i + 2].z);
	}
	printf("���Ͽ� ���� ��ǥ ��� �Ϸ�\n");


	printf("���Ͽ� ���� �ε��� ��� ��\n");
	for (int i = 0; i < idx.size(); i += 3)
	{
		fprintf(idxOut, "(%d, %d, %d)\n", idx[i], idx[i + 1], idx[i + 2]);
	}
	printf("���Ͽ� ���� �ε��� ��� �Ϸ�\n");

	printf("���Ͽ� ���� uv �ε��� ��� ��\n");
	for (int i = 0; i < uvIdx.size(); i += 3)
	{
		fprintf(uvOut, "(%d, %d, %d)\n", uvIdx[i], uvIdx[i + 1], uvIdx[i + 2]);
	}
	printf("���Ͽ� ���� uv �ε��� ��� �Ϸ�\n");

	printf("���Ͽ� ���� uv �� ��� ��\n");
	for (int i = 0; i < uvList.size(); i += 3)
	{
		fprintf(coordOut, "(%f, %f),  (%f, %f),  (%f, %f)\n", uvList[i].x, uvList[i].y, uvList[i + 1].x, uvList[i + 1].y,
			uvList[i + 2].x, uvList[i + 2].y);
	}
	printf("���Ͽ� ���� uv �� ��� �Ϸ�\n");

	printf("���Ͽ� �������� ��� ��\n");
	for (int i = 0; i < 1060; ++i)
	{

		fprintf(vtxOut, "position : (%f,  %f,  %f),    uv : (%f,  %f)\n", vertices[i].position.x, vertices[i].position.y,
			vertices[i].position.z, vertices[i].uv.x, vertices[i].uv.y);
	}
	printf("���Ͽ� �������� ��� �Ϸ�\n");

	printf("���Ͽ� �ִϸ��̼� ���� ��� ��\n");
	for (int i = 0; i < animationNamesList.size(); ++i)
	{
		fprintf(animOut, "�ִϸ��̼� �̸� : %s      ���� �ð� : %ld,     �� �ð� : %ld\n", animationNamesList[i], animationDataList[i].start, animationDataList[i].end);
	}
	printf("���Ͽ� �ִϸ��̼� ���� ��� �Ϸ�\n");

	printf("���Ͽ� ��Ų ���� ��� ��\n");
	fprintf(skinOut, "Ŭ������ �� : %d\n", nClust);
	fprintf(skinOut, "��Ų �ε���\n");
	for (int i = 0; i < maxIndex + 1; ++i)
	{
		fprintf(skinOut, "(%d,  %d,  %d,  %d)\n", skinIndex[i][0], skinIndex[i][1], skinIndex[i][2], skinIndex[i][3]);
	}
	fprintf(skinOut, "��Ų ����ġ\n");
	for (int i = 0; i < maxIndex + 1; ++i)
	{
		fprintf(skinOut, "(%f,  %f,  %f,  %f)\n", skinWeight[i][0], skinWeight[i][1], skinWeight[i][2], skinWeight[i][3]);
	}
	fprintf(skinOut, "�� ������ ��ȯ\n");
	for (int i = 0; i < nClust; ++i)
	{
		fprintf(skinOut, "%f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f\n",
			pxmf4x4VertextToLinkNodes[i].m00, pxmf4x4VertextToLinkNodes[i].m01, pxmf4x4VertextToLinkNodes[i].m02, pxmf4x4VertextToLinkNodes[i].m03,
			pxmf4x4VertextToLinkNodes[i].m10, pxmf4x4VertextToLinkNodes[i].m11, pxmf4x4VertextToLinkNodes[i].m12, pxmf4x4VertextToLinkNodes[i].m13,
			pxmf4x4VertextToLinkNodes[i].m20, pxmf4x4VertextToLinkNodes[i].m21, pxmf4x4VertextToLinkNodes[i].m22, pxmf4x4VertextToLinkNodes[i].m23,
			pxmf4x4VertextToLinkNodes[i].m30, pxmf4x4VertextToLinkNodes[i].m31, pxmf4x4VertextToLinkNodes[i].m32, pxmf4x4VertextToLinkNodes[i].m33);
	}

	printf("���Ͽ� ��Ų ���� ��� �Ϸ�\n");

	printf("���Ͽ� 0.5���� ������ ��ȯ ���� ��� ��\n");
	for (int i = 0; i < boneTrans.size(); ++i)
	{
		fprintf(boneTrans0Out, "%f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f\n",
			boneTrans[i].m00, boneTrans[i].m01, boneTrans[i].m02, boneTrans[i].m03,
			boneTrans[i].m10, boneTrans[i].m11, boneTrans[i].m12, boneTrans[i].m13,
			boneTrans[i].m20, boneTrans[i].m21, boneTrans[i].m22, boneTrans[i].m23,
			boneTrans[i].m30, boneTrans[i].m31, boneTrans[i].m32, boneTrans[i].m33);
	}
	printf("���Ͽ� 0.5���� ������ ��ȯ ���� ��� �Ϸ�\n");

	printf("���Ͽ� 0.5���� ������ ��ġ ��� ��\n");
	for (int i = 0; i < mesh0.size(); ++i)
	{
		fprintf(frameOut, "(%f,  %f,  %f)\n", mesh0[i].x, mesh0[i].y, mesh0[i].z);
	}
	printf("���Ͽ� 0.5���� ������ ��ġ ��� �Ϸ�\n");


	fclose(idxOut);
	fclose(coordOut);
	fclose(uvOut);
	fclose(posOut);
	fclose(vtxOut);
	fclose(animOut);
	fclose(skinOut);
	fclose(boneTrans0Out);
	fclose(frameOut);
	FbxArrayDelete(names);
	return 0;
}

void getIndices(FbxNode* node)
{
	FbxNodeAttribute* pfbxNodeAttribute = node->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh* mesh = node->GetMesh();
		if (mesh)
		{
			FbxVector4* pVertices = mesh->GetControlPoints();
			int cnt = mesh->GetControlPointsCount();
			printf("���������� : %d\n", cnt);
			//�ε��� ��=�����￡ ���Ե� ��� ������ ����

			int polygonCount = mesh->GetPolygonCount();
			for (int i = 0; i < polygonCount; ++i)
			{
				indexCount += mesh->GetPolygonSize(i);
			}
			float3 pos;
			//�ε��� ����ϱ�
			for (int i = 0; i < polygonCount; ++i)
			{
				for (int j = 0; j < mesh->GetPolygonSize(i); ++j)
				{
					idx.push_back(mesh->GetPolygonVertex(i, j));

					pos.x = static_cast<float>(pVertices[mesh->GetPolygonVertex(i, j)].mData[0]);
					pos.y = static_cast<float>(pVertices[mesh->GetPolygonVertex(i, j)].mData[1]);
					pos.z = static_cast<float>(pVertices[mesh->GetPolygonVertex(i, j)].mData[2]);

					posList.push_back(pos);
				}
			}

		}
	}
	int childs = node->GetChildCount();
	for (int i = 0; i < childs; ++i)
	{
		getIndices(node->GetChild(i));
	}
	int maxidx = 0;
	for (int i = 0; i < idx.size(); ++i)
	{
		if (idx[i] > maxidx)
		{
			maxidx = idx[i];
		}
	}
	maxIndex = maxidx;
}

void getUVs(FbxNode* node)
{
	FbxNodeAttribute* pfbxNodeAttribute = node->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh* mesh = node->GetMesh();
		if (mesh)
		{
			//FbxGeometryElementUV* uvData = mesh->GetElementUV(0);

			int polygonCount = mesh->GetPolygonCount();
			for (int i = 0; i < polygonCount; ++i)
			{
				for (int j = 0; j < mesh->GetPolygonSize(i); ++j)
				{
					uvIdx.push_back(mesh->GetTextureUVIndex(i, j));
				}
			}
		}
	}
	int childs = node->GetChildCount();
	for (int i = 0; i < childs; ++i)
	{
		getUVs(node->GetChild(i));
	}
}

void getUVCoords(FbxNode* node)
{
	FbxNodeAttribute* pfbxNodeAttribute = node->GetNodeAttribute();

	float2 sample;


	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh* mesh = node->GetMesh();
		if (mesh)
		{
			FbxGeometryElementUV* uvData = mesh->GetElementUV(0);


			//��� ������ ���Ͽ�
			int polygonCount = mesh->GetPolygonCount();
			for (int i = 0; i < polygonCount; ++i)
			{
				for (int j = 0; j < mesh->GetPolygonSize(i); ++j)
				{
					//�� ���� �ε���
					int temp = mesh->GetPolygonVertex(i, j);
					int temp2 = mesh->GetTextureUVIndex(i, j);

					switch (uvData->GetMappingMode())
					{
					case FbxGeometryElement::eByControlPoint:
						switch (uvData->GetReferenceMode())
						{
						case FbxGeometryElement::eDirect:
						{
							sample.x = static_cast<float>(uvData->GetDirectArray().GetAt(temp).mData[0]);
							sample.y = static_cast<float>(uvData->GetDirectArray().GetAt(temp).mData[1]);
						}
						break;
						case FbxGeometryElement::eIndexToDirect:
						{
							int t2 = uvData->GetIndexArray().GetAt(temp);
							sample.x = static_cast<float>(uvData->GetDirectArray().GetAt(t2).mData[0]);
							sample.y = static_cast<float>(uvData->GetDirectArray().GetAt(t2).mData[1]);
						}
						break;
						default:
							throw exception("Invalid Reference(eByControlPoint)");
						}
						break;
					case FbxGeometryElement::eByPolygonVertex:
						switch (uvData->GetReferenceMode())
						{
						case FbxGeometryElement::eDirect:
						{
							sample.x = static_cast<float>(uvData->GetDirectArray().GetAt(temp2).mData[0]);
							sample.y = 1.0f - static_cast<float>(uvData->GetDirectArray().GetAt(temp2).mData[1]);
						}
						break;
						case FbxGeometryElement::eIndexToDirect:
						{
							sample.x = static_cast<float>(uvData->GetDirectArray().GetAt(temp2).mData[0]);
							sample.y = 1.0f - static_cast<float>(uvData->GetDirectArray().GetAt(temp2).mData[1]);
						}
						break;
						default:
							throw exception("invalid reference(eByPolygonVertex)");
						}
						break;
					default:
						throw exception("Invalid Reference");
						break;
					}
					uvList.push_back(sample);
				}
			}


		}
	}
	int childs = node->GetChildCount();
	for (int i = 0; i < childs; ++i)
	{
		getUVCoords(node->GetChild(i));
	}
}

void getAnimationData(FbxScene* scene)
{
	// �ִϸ��̼� ����, �� ������ �ִϸ��̼� �̸�. (�ȱ�, �ٱ� ���)
	scene->FillAnimStackNameArray(names);

	//�ִϸ��̼� ����, �� �ִϸ��̼��� �������� �� ����?
	int nstacks = names.Size();

	//�� �ִϸ��̼� ����
	FbxAnimStack** animData = new FbxAnimStack * [nstacks];

	//�� �ִϸ��̼��� ���� �ð�. ���� 0��?
	FbxTime* timeStart = new FbxTime[nstacks];

	//�� �ִϸ��̼��� ������ �ð�.
	FbxTime* timeStop = new FbxTime[nstacks];

	//���� ��� �ð��� �������?
	FbxTime* timeNow = new FbxTime[nstacks];

	//��� �ִϸ��̼ǵ鿡 ���Ͽ�
	for (int i = 0; i < nstacks; i++)
	{
		//i ��° �ִϸ��̼� �̸��� �����´�.
		FbxString* currentName = names[i];
		animationNamesList.push_back(currentName->Buffer());

		//i ��° �ִϸ��̼� �����´�.
		FbxAnimStack* pfbxAnimationStack = scene->FindMember<FbxAnimStack>(currentName->Buffer());
		animData[i] = pfbxAnimationStack;

		//����ũ������ ��������, �ִϸ��̼� ���� ������ �����ö�� ������ ����ũ������� ��ü�� �ҷ��;ߵ�.
		FbxTakeInfo* takeInfo = scene->GetTakeInfo(*currentName);
		FbxTime fbxStartTime, fbxStopTime;


		if (takeInfo)
		{
			//����ũ ������ �����ϸ� �����׼� ������.
			fbxStartTime = takeInfo->mLocalTimeSpan.GetStart();
			fbxStopTime = takeInfo->mLocalTimeSpan.GetStop();
		}
		else
		{
			//�� ����ũ���� ��ü�� ������ �׳� fbx ���Ͽ� ������ �⺻ �ð������� �ҷ���.
			FbxTimeSpan fbxTimeLineTimeSpan;
			scene->GetGlobalSettings().GetTimelineDefaultTimeSpan(fbxTimeLineTimeSpan);
			fbxStartTime = fbxTimeLineTimeSpan.GetStart();
			fbxStopTime = fbxTimeLineTimeSpan.GetStop();
		}
		timeStart[i] = fbxStartTime;
		timeStop[i] = fbxStopTime;
		timeNow[i] = FbxTime(0);

		AnimationData data;
		data.start = timeStart[i].GetMilliSeconds();
		data.end = timeStop[i].GetMilliSeconds();

		animationDataList.push_back(data);
	}

}

void getBones(FbxNode* node)
{
	FbxNodeAttribute* pfbxNodeAttribute = node->GetNodeAttribute();

	float2 sample;


	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh* pfbxMesh = node->GetMesh();
		if (pfbxMesh)
		{
			int nDeform = pfbxMesh->GetDeformerCount(FbxDeformer::eSkin);
			if (nDeform > 0)
			{
				FbxSkin* pfbxSkinDeformer = (FbxSkin*)pfbxMesh->GetDeformer(0, FbxDeformer::eSkin);
				int nClusters = pfbxSkinDeformer->GetClusterCount();

				int* pnBonesPerVertex = new int[maxIndex + 1];
				memset(pnBonesPerVertex, 0, maxIndex + 1 * sizeof(int));
				for (int i = 0; i < maxIndex + 1; ++i)
				{
					pnBonesPerVertex[i] = 0;
				}
				for (int j = 0; j < nClusters; j++)
				{
					FbxCluster* pfbxCluster = pfbxSkinDeformer->GetCluster(j);
					int nControlPointIndices = pfbxCluster->GetControlPointIndicesCount();
					int* pnControlPointIndices = pfbxCluster->GetControlPointIndices();
					for (int k = 0; k < nControlPointIndices; k++)
					{
						pnBonesPerVertex[pnControlPointIndices[k]]++;
					}
				}

				int nMaxBonesPerVertex = 0;
				for (int i = 0; i < maxIndex + 1; i++)
				{
					if (pnBonesPerVertex[i] > nMaxBonesPerVertex)
					{
						nMaxBonesPerVertex = pnBonesPerVertex[i];
					}
				}

				int** ppnBoneIDs = new int* [maxIndex + 1];// �� �������� ������ �޴� ���� ��ȣ
				float** ppnBoneWeights = new float* [maxIndex + 1]; // �� �������� �� ���� �󸶳� ������ �޳�?
				for (int i = 0; i < maxIndex + 1; i++)
				{
					ppnBoneIDs[i] = new int[pnBonesPerVertex[i]];
					ppnBoneWeights[i] = new float[pnBonesPerVertex[i]];
					::memset(ppnBoneIDs[i], 0, pnBonesPerVertex[i] * sizeof(int));
					::memset(ppnBoneWeights[i], 0, pnBonesPerVertex[i] * sizeof(float));
					for (int j = 0; j < pnBonesPerVertex[i]; ++j)
					{
						ppnBoneIDs[i][j] = 0;
						ppnBoneWeights[i][j] = 0.0f;
					}

				}

				int* pnBones = new int[maxIndex + 1];
				::memset(pnBones, 0, maxIndex + 1 * sizeof(int));
				for (int i = 0; i < maxIndex + 1; ++i)
				{
					pnBones[i] = 0;
				}

				//				FbxAMatrix fbxmtxGeometryOffset = GetGeometricOffsetTransform(pfbxNode);
				FbxAMatrix fbxmtxGeometryOffset = GetGeometricOffsetTransform(pfbxMesh->GetNode());

				FbxAMatrix* pfbxmtxVertextToLinkNodes = new FbxAMatrix[nClusters];
				for (int j = 0; j < nClusters; j++)
				{
					FbxCluster* pfbxCluster = pfbxSkinDeformer->GetCluster(j);

					FbxAMatrix fbxmtxBindPoseMeshToRoot; //Cluster Transform
					pfbxCluster->GetTransformMatrix(fbxmtxBindPoseMeshToRoot);
					FbxAMatrix fbxmtxBindPoseBoneToRoot; //Cluster Link Transform
					pfbxCluster->GetTransformLinkMatrix(fbxmtxBindPoseBoneToRoot);

					pfbxmtxVertextToLinkNodes[j] = fbxmtxBindPoseBoneToRoot.Inverse() * fbxmtxBindPoseMeshToRoot * fbxmtxGeometryOffset;

					int* pnControlPointIndices = pfbxCluster->GetControlPointIndices();
					double* pfControlPointWeights = pfbxCluster->GetControlPointWeights();
					int nControlPointIndices = pfbxCluster->GetControlPointIndicesCount();

					for (int k = 0; k < nControlPointIndices; k++)
					{
						int nVertex = pnControlPointIndices[k];
						ppnBoneIDs[nVertex][pnBones[nVertex]] = j;
						ppnBoneWeights[nVertex][pnBones[nVertex]++] = (float)pfControlPointWeights[k];
					}
				}

				float* pnSumOfBoneWeights = new float[maxIndex + 1];
				::memset(pnSumOfBoneWeights, 0, maxIndex + 1 * sizeof(float));

				for (int i = 0; i < maxIndex + 1; i++)
				{
					for (int j = 0; j < pnBonesPerVertex[i]; j++)
					{
						pnSumOfBoneWeights[i] += ppnBoneWeights[i][j];
					}
					for (int j = 0; j < pnBonesPerVertex[i]; j++)
					{
						ppnBoneWeights[i][j] /= pnSumOfBoneWeights[i];
					}
				}

				if (pnSumOfBoneWeights) delete[] pnSumOfBoneWeights;

				for (int i = 0; i < maxIndex + 1; i++)
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

				int(*pnSkinningIndices)[4] = new int[maxIndex + 1][4];
				float(*pfSkinningWeights)[4] = new float[maxIndex + 1][4];

				for (int i = 0; i < maxIndex + 1; i++)
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

				skinIndex = pnSkinningIndices;
				skinWeight = pfSkinningWeights;

				pxmf4x4VertextToLinkNodes = new matrix4x4[nClusters]; //Bone Offset Transforms
				for (int j = 0; j < nClusters; j++)
				{
					pxmf4x4VertextToLinkNodes[j] = FbxMatrixToXmFloat4x4Matrix(&pfbxmtxVertextToLinkNodes[j]);
				}
				nClust = nClusters;
			}
		}
	}
	int nchild = node->GetChildCount();
	for (int i = 0; i < nchild; ++i)
	{
		getBones(node->GetChild(i));
	}
}

FbxAMatrix GetGeometricOffsetTransform(FbxNode* pfbxNode)
{
	const FbxVector4 T = pfbxNode->GetGeometricTranslation(FbxNode::eSourcePivot);
	const FbxVector4 R = pfbxNode->GetGeometricRotation(FbxNode::eSourcePivot);
	const FbxVector4 S = pfbxNode->GetGeometricScaling(FbxNode::eSourcePivot);

	return(FbxAMatrix(T, R, S));
}

matrix4x4 FbxMatrixToXmFloat4x4Matrix(FbxAMatrix* pfbxmtxSource)
{
	matrix4x4 xmf4x4Result;

	xmf4x4Result.m00 = (float)(*pfbxmtxSource)[0][0];
	xmf4x4Result.m10 = (float)(*pfbxmtxSource)[0][1];
	xmf4x4Result.m20 = (float)(*pfbxmtxSource)[0][2];
	xmf4x4Result.m30 = (float)(*pfbxmtxSource)[0][3];

	xmf4x4Result.m01 = (float)(*pfbxmtxSource)[1][0];
	xmf4x4Result.m11 = (float)(*pfbxmtxSource)[1][1];
	xmf4x4Result.m21 = (float)(*pfbxmtxSource)[1][2];
	xmf4x4Result.m31 = (float)(*pfbxmtxSource)[1][3];

	xmf4x4Result.m02 = (float)(*pfbxmtxSource)[2][0];
	xmf4x4Result.m12 = (float)(*pfbxmtxSource)[2][1];
	xmf4x4Result.m22 = (float)(*pfbxmtxSource)[2][2];
	xmf4x4Result.m32 = (float)(*pfbxmtxSource)[2][3];

	xmf4x4Result.m03 = (float)(*pfbxmtxSource)[3][0];
	xmf4x4Result.m13 = (float)(*pfbxmtxSource)[3][1];
	xmf4x4Result.m23 = (float)(*pfbxmtxSource)[3][2];
	xmf4x4Result.m33 = (float)(*pfbxmtxSource)[3][3];


	return(xmf4x4Result);
}

void getBoneTransAtTime(FbxNode* node, int ms)
{
	FbxNodeAttribute* pfbxNodeAttribute = node->GetNodeAttribute();

	
	FbxTime time = FbxTime(ms);
	time.SetMilliSeconds(ms);

	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh* pfbxMesh = node->GetMesh();
		int t = pfbxMesh->GetDeformerCount(FbxDeformer::eSkin);
		if (t > 0)
		{
			FbxSkin* skin = (FbxSkin*)pfbxMesh->GetDeformer(0, FbxDeformer::eSkin);
			for (int i = 0; i < nClust; ++i)
			{
				
				FbxCluster* pfbxCluster = skin->GetCluster(i);
				FbxAMatrix boneWorld = pfbxCluster->GetLink()->EvaluateGlobalTransform(time);
				matrix4x4 bones = FbxMatrixToXmFloat4x4Matrix(&boneWorld);
				boneTrans.push_back(bones);


			}
		}
	}
	int childs = node->GetChildCount();
	for (int i = 0; i < childs; ++i)
	{
		getBoneTransAtTime(node->GetChild(i), ms);
	}
}
void getMeshVertexAtTime()
{
	for (int i = 0; i < maxIndex+1; ++i)
	{
		matrix4x4 temp;
		temp.m00 = 0; temp.m01 = 0; temp.m02 = 0; temp.m03 = 0;
		temp.m10 = 0; temp.m11 = 0; temp.m12 = 0; temp.m13 = 0;
		temp.m20 = 0; temp.m21 = 0; temp.m22 = 0; temp.m23 = 0;
		temp.m30 = 0; temp.m31 = 0; temp.m32 = 0; temp.m33 = 0;

		for (int j = 0; j < 4; ++j)
		{
			temp = matAdd(temp, matMulFloat(skinWeight[i][j], matMul(pxmf4x4VertextToLinkNodes[skinIndex[i][j]], boneTrans[skinIndex[i][j]])));
		}
		float3 tpos = Multiply(temp, vertices[i].position);
		mesh0.push_back(tpos);
	}
}


