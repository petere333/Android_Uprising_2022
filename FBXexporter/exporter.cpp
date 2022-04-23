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
void getBones(FbxNode* node);

void getAnimationData(FbxScene* scene);
FbxAMatrix GetGeometricOffsetTransform(FbxNode* pfbxNode);

void getMeshVertexAtTime();
void getBoneTransAtTime(FbxNode* node, int ms);

void CreateMeshFromFbxNodeHierarchy(FbxNode* pfbxNode);

matrix4x4 FbxMatrixToXmFloat4x4Matrix(FbxAMatrix* pfbxmtxSource);

vector<int> idx;//제어점 인덱스 리스트
vector<int> uvIdx;//제어점 uv 인덱스 리스트
int indexCount = 0;



vector<float2> uvList;//제어점 uv 좌표값 리스트
vector<float3> posList;//제어점 좌표값 리스트
vector<float3> ctrlPoints;
vector<char*> animationNamesList;
vector<AnimationData> animationDataList;


vector<int4> skinIdx;// 본 인덱스
vector<float4> skinWeit;// 본 웨이트


vector<matrix4x4> pxmf4x4VertextToLinkNodes;//스킨 트랜스폼
int nClust;

int maxIndex;



vector<float3> mesh0; // 애니메이션 시간이 0ms일때 모양
vector<float3> mesh1; // 애니메이션 시간이 33ms일때 모양

vector<matrix4x4> boneTrans;
int main()
{
	printf("FBX 파일 로딩 중\n");
	FbxManager* manager = FbxManager::Create();
	FbxScene* scene = LoadFbxSceneFromFile(manager, "/fbx/pallet_wrapped.fbx");
	printf("FBX 파일 로딩 완료\n");
	FbxNode* root = scene->GetRootNode();

	printf("정점들의 정보 로딩 중\n");
	
	getIndices(root);
	getUVs(root);
	getUVCoords(root);
	printf("정점들의 정보 로딩 완료\n");

	FILE* idxOut = fopen("result/idx_짐덩이.txt", "w");
	FILE* frameOut = fopen("result/vtx_짐덩이.txt", "w");
	
	int maxidx = 0;
	for (int i = 0; i < idx.size(); ++i)
	{
		if (idx[i] > maxidx)
		{
			maxidx = idx[i];
		}
	}
	printf("가장 큰 정점 인덱스 = %d\n", maxidx);

	int maxuvidx = 0;

	for (int i = 0; i < uvIdx.size(); ++i)
	{
		if (uvIdx[i] > maxuvidx)
		{
			maxuvidx = uvIdx[i];
		}
	}
	printf("가장 큰 정점 uv 인덱스 = %d\n", maxuvidx);

	/*
	VertexUV* vertices = new VertexUV[ctrlPoints.size()];
	
	for (int i = 0; i < posList.size(); ++i)
	{
		vertices[idx[i]].position = ctrlPoints[idx[i]];
		vertices[idx[i]].uv = uvList[i];

		
	}
	*/
	
	VertexUV* vertices = new VertexUV[posList.size()];

	for (int i = 0; i < posList.size(); ++i)
	{
		vertices[i].position = posList[i];
		vertices[i].uv = uvList[i];


	}

	printf("파일에 인덱스 기록 중\n");
	for (int i = 0; i < idx.size(); ++i)
	{
		fprintf(idxOut, "%d, ", idx[i]);
	}
	printf("파일에 인덱스 기록 완료\n");
	
	
	FbxArrayDelete(names);
	float min = 999999.0f;
	float max = -999999.0f;

	float xmin = 999999.0f;
	float xmax = -999999.0f;

	float zmin = 999999.0f;
	float zmax = -999999.0f;
	for (int i = 0; i < ctrlPoints.size(); ++i)
	{
		if (ctrlPoints[i].y > max)
		{
			max = ctrlPoints[i].y;
		}
		if (ctrlPoints[i].x > xmax)
		{
			xmax = ctrlPoints[i].x;
		}
		if (ctrlPoints[i].z > zmax)
		{
			zmax = ctrlPoints[i].z;
		}

		if (ctrlPoints[i].y < min)
		{
			min = ctrlPoints[i].y;
		}
		if (ctrlPoints[i].x < xmin)
		{
			xmin = ctrlPoints[i].x;
		}
		if (ctrlPoints[i].z < zmin)
		{
			zmin = ctrlPoints[i].z;
		}
	}
	float xscale = 5.0f/ (xmax - xmin);
	float yscale = 5.0f/(max - min);
	float zscale = 5.0f/(zmax - zmin);
	//for (int i = 0; i < maxidx + 1; ++i)
	for (int i = 0; i < posList.size(); ++i)
	{
		// fprintf(frameOut, "(%f,  %f,  %f),  (%f,  %f)\n", vertices[i].position.x*xscale, vertices[i].position.y*yscale, vertices[i].position.z*zscale, vertices[i].uv.x, vertices[i].uv.y);

		fprintf(frameOut, "(%f,  %f,  %f),  (%f,  %f)\n", vertices[i].position.x * xscale, vertices[i].position.z * zscale, vertices[i].position.y * yscale, vertices[i].uv.x, vertices[i].uv.y);
	}
	printf("max : %f, min : %f, y size : %f\n",max,min,max-min);
	printf("xmax : %f, xmin : %f, x size : %f\n", xmax, xmin, xmax - xmin);
	printf("zmax : %f, xmin : %f, z size : %f\n", zmax, zmin, zmax - zmin);


	fclose(idxOut);
	fclose(frameOut);
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
			printf("제어점갯수 : %d\n", cnt);
			//인덱스 수=폴리곤에 포함된 모든 정점의 갯수
			for (int i = 0; i < cnt; ++i)
			{
				float3 temp;
				temp.x = static_cast<float>(mesh->GetControlPointAt(i).mData[0]);
				temp.y = static_cast<float>(mesh->GetControlPointAt(i).mData[1]);
				temp.z = static_cast<float>(mesh->GetControlPointAt(i).mData[2]);
				ctrlPoints.push_back(temp);
			}
			int polygonCount = mesh->GetPolygonCount();
			for (int i = 0; i < polygonCount; ++i)
			{
				indexCount += mesh->GetPolygonSize(i);
			}
			float3 pos;
			//인덱스 기록하기
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


			//모든 정점에 대하여
			int polygonCount = mesh->GetPolygonCount();
			for (int i = 0; i < polygonCount; ++i)
			{
				for (int j = 0; j < mesh->GetPolygonSize(i); ++j)
				{
					//한 점의 인덱스
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
	// 애니메이션 스택, 즉 각각의 애니메이션 이름. (걷기, 뛰기 등등)
	scene->FillAnimStackNameArray(names);

	//애니메이션 스택, 즉 애니메이션의 가짓수가 몇 개지?
	int nstacks = names.Size();

	//각 애니메이션 정보
	FbxAnimStack** animData = new FbxAnimStack * [nstacks];

	//각 애니메이션의 시작 시간. 보통 0초?
	FbxTime* timeStart = new FbxTime[nstacks];

	//각 애니메이션이 끝나는 시간.
	FbxTime* timeStop = new FbxTime[nstacks];

	//현재 어느 시각의 장면이지?
	FbxTime* timeNow = new FbxTime[nstacks];

	//모든 애니메이션들에 대하여
	for (int i = 0; i < nstacks; i++)
	{
		//i 번째 애니메이션 이름을 가져온다.
		FbxString* currentName = names[i];
		animationNamesList.push_back(currentName->Buffer());

		//i 번째 애니메이션 가져온다.
		FbxAnimStack* pfbxAnimationStack = scene->FindMember<FbxAnimStack>(currentName->Buffer());
		animData[i] = pfbxAnimationStack;

		//테이크인포가 뭔진몰라도, 애니메이션 동작 정보를 가져올라면 씬에서 테이크인포라는 객체를 불러와야되.
		FbxTakeInfo* takeInfo = scene->GetTakeInfo(*currentName);
		FbxTime fbxStartTime, fbxStopTime;


		if (takeInfo)
		{
			//테이크 인포가 존재하면 얘한테서 가져와.
			fbxStartTime = takeInfo->mLocalTimeSpan.GetStart();
			fbxStopTime = takeInfo->mLocalTimeSpan.GetStop();
		}
		else
		{
			//이 테이크인포 객체가 없으면 그냥 fbx 파일에 설정된 기본 시간정보를 불러와.
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

		temp = matAdd(temp, matMulFloat(skinWeit[i].x, matMul(pxmf4x4VertextToLinkNodes[skinIdx[i].x], boneTrans[skinIdx[i].x])));
		temp = matAdd(temp, matMulFloat(skinWeit[i].y, matMul(pxmf4x4VertextToLinkNodes[skinIdx[i].y], boneTrans[skinIdx[i].y])));
		temp = matAdd(temp, matMulFloat(skinWeit[i].z, matMul(pxmf4x4VertextToLinkNodes[skinIdx[i].z], boneTrans[skinIdx[i].z])));
		temp = matAdd(temp, matMulFloat(skinWeit[i].a, matMul(pxmf4x4VertextToLinkNodes[skinIdx[i].a], boneTrans[skinIdx[i].a])));


		//float3 tpos = Multiply(temp, vertices[i].position);
		//mesh0.push_back(tpos);
	}
}


void CreateMeshFromFbxNodeHierarchy(FbxNode* pfbxNode)
{
	FbxNodeAttribute* pfbxNodeAttribute = pfbxNode->GetNodeAttribute();
	if (pfbxNodeAttribute && (pfbxNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh))
	{
		FbxMesh* pfbxMesh = pfbxNode->GetMesh();
		if (pfbxMesh)
		{
			//제어점 좌표 구하기
			int nVertices = pfbxMesh->GetControlPointsCount();
			FbxVector4* pfbxv4Vertices = new FbxVector4[nVertices];
			::memcpy(pfbxv4Vertices, pfbxMesh->GetControlPoints(), nVertices * sizeof(FbxVector4));

			//float4* pxmf4Vertices = new float4[nVertices];
			for (int j = 0; j < nVertices; j++)
			{
				float3 sample;
				sample.x = (float)pfbxv4Vertices[j][0];
				sample.y = (float)pfbxv4Vertices[j][1];
				sample.z = (float)pfbxv4Vertices[j][2];
				
				//posList.push_back(sample);
			}

			// 인덱스 구해오기

			int nIndices = 0;
			int nPolygons = pfbxMesh->GetPolygonCount();
			for (int i = 0; i < nPolygons; i++)
			{
				nIndices += pfbxMesh->GetPolygonSize(i);
			}//Triangle: 3, Triangulate(), nIndices = nPolygons * 3


			int* pnIndices = new int[nIndices];

			for (int i = 0, k = 0; i < nPolygons; i++)
			{
				int nPolygonSize = pfbxMesh->GetPolygonSize(i);
				for (int j = 0; j < nPolygonSize; j++)
				{
					float3 pos;
					pnIndices[k++] = pfbxMesh->GetPolygonVertex(i, j);
					
					pos.x = static_cast<float>(pfbxv4Vertices[pfbxMesh->GetPolygonVertex(i, j)].mData[0]);
					pos.y = static_cast<float>(pfbxv4Vertices[pfbxMesh->GetPolygonVertex(i, j)].mData[1]);
					pos.z = static_cast<float>(pfbxv4Vertices[pfbxMesh->GetPolygonVertex(i, j)].mData[2]);

					//posList.push_back(pos);
					//idx.push_back(pfbxMesh->GetPolygonVertex(i, j));
				}
			}

			//텍스처 인덱스 구하기
			int* uvIdxs = new int[nIndices];
			int t = 0;
			for (int i = 0; i < nPolygons; ++i)
			{
				for (int j = 0; j < pfbxMesh->GetPolygonSize(i); ++j)
				{
					uvIdxs[t] = pfbxMesh->GetTextureUVIndex(i, j);
					t += 1;
				}
			}
			//for (int i = 0; i < nIndices; ++i)
			//{
				//uvIdx.push_back(uvIdxs[i]);
			//}
			//텍스처 uv 값 구하기
			float2* uvValue = new float2[nIndices];
			FbxGeometryElementUV* uvData = pfbxMesh->GetElementUV(0);
			float2 sample;
			t = 0;
			for (int i = 0; i < nPolygons; ++i)
			{
				for (int j = 0; j < pfbxMesh->GetPolygonSize(i); ++j)
				{
					//한 점의 인덱스
					int temp = pfbxMesh->GetPolygonVertex(i, j);
					int temp2 = pfbxMesh->GetTextureUVIndex(i, j);

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
							throw std::exception("Invalid Reference(eByControlPoint)");
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
							throw std::exception("invalid reference(eByPolygonVertex)");
						}
						break;
					default:
						throw std::exception("Invalid Reference");
						break;
					}
					//uvList.push_back(sample);
					t += 1;
				}
			}
			//인덱스가 아닌 고정된 점들의 형태로 변환




			

			int nSkinDeformers = pfbxMesh->GetDeformerCount(FbxDeformer::eSkin);
			if (nSkinDeformers > 0)
			{
				FbxSkin* pfbxSkinDeformer = (FbxSkin*)pfbxMesh->GetDeformer(0, FbxDeformer::eSkin);
				int nClusters = pfbxSkinDeformer->GetClusterCount();
				nClust = nClusters;
				int* pnBonesPerVertex = new int[nVertices];
				::memset(pnBonesPerVertex, 0, nVertices * sizeof(int));
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
				for (int i = 0; i < nVertices; i++)
				{
					if (pnBonesPerVertex[i] > nMaxBonesPerVertex)
					{
						nMaxBonesPerVertex = pnBonesPerVertex[i];
					}
				}

				int** ppnBoneIDs = new int* [nVertices];// 각 정점마다 영향을 받는 뼈의 번호
				float** ppnBoneWeights = new float* [nVertices]; // 각 정점마다 그 뼈에 얼마나 영향을 받나?
				for (int i = 0; i < nVertices; i++)
				{
					ppnBoneIDs[i] = new int[pnBonesPerVertex[i]];
					ppnBoneWeights[i] = new float[pnBonesPerVertex[i]];
					::memset(ppnBoneIDs[i], 0, pnBonesPerVertex[i] * sizeof(int));
					::memset(ppnBoneWeights[i], 0, pnBonesPerVertex[i] * sizeof(float));
				}

				int* pnBones = new int[nVertices];
				::memset(pnBones, 0, nVertices * sizeof(int));

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

				float* pnSumOfBoneWeights = new float[nVertices];
				::memset(pnSumOfBoneWeights, 0, nVertices * sizeof(float));

				for (int i = 0; i < nVertices; i++)
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

				int(*pnSkinningIndices)[4] = new int[nVertices][4];
				float(*pfSkinningWeights)[4] = new float[nVertices][4];

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
				for (int i = 0; i < nVertices; ++i)
				{
					int4 ti;
					float4 tf;

					ti.x = pnSkinningIndices[i][0];
					ti.y = pnSkinningIndices[i][1];
					ti.z = pnSkinningIndices[i][2];
					ti.a = pnSkinningIndices[i][3];

					tf.x = pfSkinningWeights[i][0];
					tf.y = pfSkinningWeights[i][1];
					tf.z = pfSkinningWeights[i][2];
					tf.a = pfSkinningWeights[i][3];

					skinIdx.push_back(ti);
					skinWeit.push_back(tf);
				}
				
				for (int j = 0; j < nClusters; j++)
				{
					pxmf4x4VertextToLinkNodes.push_back(FbxMatrixToXmFloat4x4Matrix(&pfbxmtxVertextToLinkNodes[j]));
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
			

			

			if (pfbxv4Vertices) delete[] pfbxv4Vertices;
			
			if (pnIndices) delete[] pnIndices;
		}
	}

	int nChilds = pfbxNode->GetChildCount();
	for (int i = 0; i < nChilds; i++)
	{
		CreateMeshFromFbxNodeHierarchy(pfbxNode->GetChild(i));
	}
}