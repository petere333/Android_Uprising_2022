#include <stdio.h>
#include <stdlib.h>
#include <fbxsdk.h>
#include <vector>

#pragma comment(lib, "libfbxsdk-md.lib")
#pragma comment(lib, "libxml2-md.lib")
#pragma comment(lib, "zlib-md.lib")

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

void getIndices(FbxNode *node);
void getUVs(FbxNode *node);
void getUVCoords(FbxNode* node);
void getAnimationData(FbxScene* scene);

typedef struct float2
{
	float x, y;
}float2;

typedef struct float3
{
	float x, y, z;
}float3;

typedef struct VertexUV
{
	float3 position;
	float2 uv;
};

typedef struct AnimationData
{
	long start;
	long end;
};

vector<int> idx;//제어점 인덱스 리스트
vector<int> uvIdx;//제어점 uv 인덱스 리스트
int indexCount = 0;



vector<float2> uvList;//제어점 uv 좌표값 리스트
vector<float3> posList;//제어점 좌표값 리스트

vector<char*> animationNamesList;
vector<AnimationData> animationDataList;

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

	FILE* idxOut = fopen("indices.txt", "w");
	FILE* uvOut = fopen("uvs.txt", "w");
	FILE* coordOut = fopen("uvCoords.txt", "w");
	FILE* posOut = fopen("positions.txt", "w");
	FILE* vtxOut = fopen("vertices.txt", "w");

	FILE* animOut = fopen("animations.txt", "w");
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

	VertexUV vertices[1060];
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
	for (int i = 0; i < idx.size(); i+=3)
	{
		fprintf(idxOut, "(%d, %d, %d)\n", idx[i],idx[i+1],idx[i+2]);
	}
	printf("파일에 정점 인덱스 기록 완료\n");

	printf("파일에 정점 uv 인덱스 기록 중\n");
	for (int i = 0; i < uvIdx.size(); i+=3)
	{
		fprintf(uvOut, "(%d, %d, %d)\n", uvIdx[i],uvIdx[i+1],uvIdx[i+2]);
	}
	printf("파일에 정점 uv 인덱스 기록 완료\n");

	printf("파일에 정점 uv 값 기록 중\n");
	for (int i = 0; i < uvList.size(); i+=3)
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
	fclose(idxOut);
	fclose(coordOut);
	fclose(uvOut);
	fclose(posOut);
	fclose(vtxOut);
	fclose(animOut);
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