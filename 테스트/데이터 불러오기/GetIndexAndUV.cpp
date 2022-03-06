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

vector<int> idx;//������ �ε��� ����Ʈ
vector<int> uvIdx;//������ uv �ε��� ����Ʈ
int indexCount = 0;



vector<float2> uvList;//������ uv ��ǥ�� ����Ʈ
vector<float3> posList;//������ ��ǥ�� ����Ʈ

vector<char*> animationNamesList;
vector<AnimationData> animationDataList;

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

	VertexUV vertices[1060];
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
	for (int i = 0; i < idx.size(); i+=3)
	{
		fprintf(idxOut, "(%d, %d, %d)\n", idx[i],idx[i+1],idx[i+2]);
	}
	printf("���Ͽ� ���� �ε��� ��� �Ϸ�\n");

	printf("���Ͽ� ���� uv �ε��� ��� ��\n");
	for (int i = 0; i < uvIdx.size(); i+=3)
	{
		fprintf(uvOut, "(%d, %d, %d)\n", uvIdx[i],uvIdx[i+1],uvIdx[i+2]);
	}
	printf("���Ͽ� ���� uv �ε��� ��� �Ϸ�\n");

	printf("���Ͽ� ���� uv �� ��� ��\n");
	for (int i = 0; i < uvList.size(); i+=3)
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