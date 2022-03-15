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

vector<int> idx;//제어점 인덱스 리스트
vector<int> uvIdx;//제어점 uv 인덱스 리스트
int indexCount = 0;



vector<float2> uvList;//제어점 uv 좌표값 리스트
vector<float3> posList;//제어점 좌표값 리스트

vector<char*> animationNamesList;
vector<AnimationData> animationDataList;

int(*skinIndex)[4];
float(*skinWeight)[4];
matrix4x4* pxmf4x4VertextToLinkNodes;
int nClust;

int maxIndex;

VertexUV vertices[1060];
vector<float3> mesh0; // 애니메이션 시간이 0ms일때 모양
vector<float3> mesh1; // 애니메이션 시간이 33ms일때 모양

vector<matrix4x4> boneTrans;
int main()
{
	printf("FBX 파일 로딩 중\n");
	FbxManager* manager = FbxManager::Create();
	FbxScene* scene = LoadFbxSceneFromFile(manager, "sample.fbx");
	printf("FBX 파일 로딩 완료\n");
	FbxNode* root = scene->GetRootNode();


	printf("정점들의 정보 로딩 중\n");
	getIndices(root);
	getUVs(root);
	getUVCoords(root);
	printf("정점들의 정보 로딩 완료\n");

	printf("애니메이션 정보 로딩 중\n");
	getAnimationData(scene);
	printf("애니메이션 정보 로딩 완료\n");

	printf("스킨 정보 로딩 중\n");
	getBones(root);
	printf("스킨 정보 로딩 완료\n");

	printf("0.5초후 형태 로딩 중");
	getBoneTransAtTime(root, 500);
	getMeshVertexAtTime();
	printf("0.5초후 형태 로딩 완료");

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

	
	for (int i = 0; i < idx.size(); ++i)
	{
		vertices[idx[i]].position = posList[i];


		vertices[idx[i]].uv = uvList[i];

	}

	printf("파일에 정점 좌표 기록 중\n");
	for (int i = 0; i < posList.size(); i += 3)
	{
		fprintf(posOut, "(%f, %f, %f),  (%f, %f, %f),  (%f, %f, %f)\n", posList[i].x, posList[i].y, posList[i].z,
			posList[i + 1].x, posList[i + 1].y, posList[i + 1].z, posList[i + 2].x, posList[i + 2].y, posList[i + 2].z);
	}
	printf("파일에 정점 좌표 기록 완료\n");


	printf("파일에 정점 인덱스 기록 중\n");
	for (int i = 0; i < idx.size(); i += 3)
	{
		fprintf(idxOut, "(%d, %d, %d)\n", idx[i], idx[i + 1], idx[i + 2]);
	}
	printf("파일에 정점 인덱스 기록 완료\n");

	printf("파일에 정점 uv 인덱스 기록 중\n");
	for (int i = 0; i < uvIdx.size(); i += 3)
	{
		fprintf(uvOut, "(%d, %d, %d)\n", uvIdx[i], uvIdx[i + 1], uvIdx[i + 2]);
	}
	printf("파일에 정점 uv 인덱스 기록 완료\n");

	printf("파일에 정점 uv 값 기록 중\n");
	for (int i = 0; i < uvList.size(); i += 3)
	{
		fprintf(coordOut, "(%f, %f),  (%f, %f),  (%f, %f)\n", uvList[i].x, uvList[i].y, uvList[i + 1].x, uvList[i + 1].y,
			uvList[i + 2].x, uvList[i + 2].y);
	}
	printf("파일에 정점 uv 값 기록 완료\n");

	printf("파일에 제어점들 기록 중\n");
	for (int i = 0; i < 1060; ++i)
	{

		fprintf(vtxOut, "position : (%f,  %f,  %f),    uv : (%f,  %f)\n", vertices[i].position.x, vertices[i].position.y,
			vertices[i].position.z, vertices[i].uv.x, vertices[i].uv.y);
	}
	printf("파일에 제어점들 기록 완료\n");

	printf("파일에 애니메이션 정보 기록 중\n");
	for (int i = 0; i < animationNamesList.size(); ++i)
	{
		fprintf(animOut, "애니메이션 이름 : %s      시작 시간 : %ld,     끝 시간 : %ld\n", animationNamesList[i], animationDataList[i].start, animationDataList[i].end);
	}
	printf("파일에 애니메이션 정보 기록 완료\n");

	printf("파일에 스킨 정보 기록 중\n");
	fprintf(skinOut, "클러스터 수 : %d\n", nClust);
	fprintf(skinOut, "스킨 인덱스\n");
	for (int i = 0; i < maxIndex + 1; ++i)
	{
		fprintf(skinOut, "(%d,  %d,  %d,  %d)\n", skinIndex[i][0], skinIndex[i][1], skinIndex[i][2], skinIndex[i][3]);
	}
	fprintf(skinOut, "스킨 가중치\n");
	for (int i = 0; i < maxIndex + 1; ++i)
	{
		fprintf(skinOut, "(%f,  %f,  %f,  %f)\n", skinWeight[i][0], skinWeight[i][1], skinWeight[i][2], skinWeight[i][3]);
	}
	fprintf(skinOut, "본 오프셋 변환\n");
	for (int i = 0; i < nClust; ++i)
	{
		fprintf(skinOut, "%f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f\n",
			pxmf4x4VertextToLinkNodes[i].m00, pxmf4x4VertextToLinkNodes[i].m01, pxmf4x4VertextToLinkNodes[i].m02, pxmf4x4VertextToLinkNodes[i].m03,
			pxmf4x4VertextToLinkNodes[i].m10, pxmf4x4VertextToLinkNodes[i].m11, pxmf4x4VertextToLinkNodes[i].m12, pxmf4x4VertextToLinkNodes[i].m13,
			pxmf4x4VertextToLinkNodes[i].m20, pxmf4x4VertextToLinkNodes[i].m21, pxmf4x4VertextToLinkNodes[i].m22, pxmf4x4VertextToLinkNodes[i].m23,
			pxmf4x4VertextToLinkNodes[i].m30, pxmf4x4VertextToLinkNodes[i].m31, pxmf4x4VertextToLinkNodes[i].m32, pxmf4x4VertextToLinkNodes[i].m33);
	}

	printf("파일에 스킨 정보 기록 완료\n");

	printf("파일에 0.5초후 뼈들의 변환 상태 기록 중\n");
	for (int i = 0; i < boneTrans.size(); ++i)
	{
		fprintf(boneTrans0Out, "%f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f,  %f\n",
			boneTrans[i].m00, boneTrans[i].m01, boneTrans[i].m02, boneTrans[i].m03,
			boneTrans[i].m10, boneTrans[i].m11, boneTrans[i].m12, boneTrans[i].m13,
			boneTrans[i].m20, boneTrans[i].m21, boneTrans[i].m22, boneTrans[i].m23,
			boneTrans[i].m30, boneTrans[i].m31, boneTrans[i].m32, boneTrans[i].m33);
	}
	printf("파일에 0.5초후 뼈들의 변환 상태 기록 완료\n");

	printf("파일에 0.5초후 정점의 위치 기록 중\n");
	for (int i = 0; i < mesh0.size(); ++i)
	{
		fprintf(frameOut, "(%f,  %f,  %f)\n", mesh0[i].x, mesh0[i].y, mesh0[i].z);
	}
	printf("파일에 0.5초후 정점의 위치 기록 완료\n");


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
			printf("제어점갯수 : %d\n", cnt);
			//인덱스 수=폴리곤에 포함된 모든 정점의 갯수

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

				int** ppnBoneIDs = new int* [maxIndex + 1];// 각 정점마다 영향을 받는 뼈의 번호
				float** ppnBoneWeights = new float* [maxIndex + 1]; // 각 정점마다 그 뼈에 얼마나 영향을 받나?
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


