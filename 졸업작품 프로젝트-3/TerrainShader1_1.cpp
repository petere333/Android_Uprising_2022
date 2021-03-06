#include "TerrainShader1_1.h"

/*
--	1-1 폐기물 처리장에 있는 물체들만 담당하는 쉐이더 코드.
--	
--
*/


TerrainShader1_1::TerrainShader1_1(ResourceManager* r)
{
	rm = r;
}
TerrainShader1_1::~TerrainShader1_1() {}

void TerrainShader1_1::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/area1_1/objects1-1.txt");
	boxesWorld = LoadBoxes("res/map/area1_1/box1-1.txt", &nBox);

	GridMesh* RustyFloor = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 200.0f);
	WallMeshHorizontal* RustyWallFront = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshHorizontal* RustyWallBack = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshVertical* RustyWallLeft = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshVertical* RustyWallRight = new WallMeshVertical(pd3dDevice, pd3dCommandList, 195.0f, 10.0f);
	WallMeshVertical* RustyWallRight2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 5.0f);
	WallMeshVertical* RustyWallRight3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 10.0f);



	WallMeshVertical* RustyWallLeft100m = new WallMeshVertical(pd3dDevice, pd3dCommandList, 100.0f, 10.0f);
	WallMeshVertical* RustyWallCenter50m = new WallMeshVertical(pd3dDevice, pd3dCommandList, 50.0f, 10.0f);

	WallMeshHorizontal* RustyWallHCenter50m = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 50.0f, 10.0f);
	WallMeshHorizontal* RustyWallBottom50m = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 50.0f, 10.0f);
	WallMeshHorizontal* RustyWallTop100m = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 100.0f, 10.0f);


	CLoadedMesh* Metal_Box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_box.txt", NULL);
	CLoadedMesh* RustyBarrel = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_barrel.txt", NULL);

	CLoadedMesh* Pipe_Wall = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_wallpipe.txt", NULL);
	CLoadedMesh* Pipe_Floor = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_floorpipe.txt", NULL);

	CLoadedMesh* Fence = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_fence.txt", NULL);
	CLoadedMesh* Foodbin = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_foodBin.txt", NULL);
	CLoadedMesh* env1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_envelope1.txt", NULL);
	CLoadedMesh* env2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_envelope2.txt", NULL);
	CLoadedMesh* env3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_envelope3.txt", NULL);
	CLoadedMesh* SteelLadder = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ladder.txt", NULL);
	CLoadedMesh* BendRail = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_railBend.txt", NULL);
	CLoadedMesh* StraightRail = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_railStraight.txt", NULL);

	CLoadedMesh* brick1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinBrick1.txt", NULL);
	CLoadedMesh* brick2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinBrick2.txt", NULL);
	CLoadedMesh* brick3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinBrick3.txt", NULL);
	CLoadedMesh* brick4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinBrick4.txt", NULL);
	CLoadedMesh* brick5 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinBrick5.txt", NULL);

	CLoadedMesh* ceramic1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinCeramic1.txt", NULL);
	CLoadedMesh* ceramic2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinCeramic2.txt", NULL);

	CLoadedMesh* mix1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinMix1.txt", NULL);
	CLoadedMesh* mix2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinMix2.txt", NULL);

	CLoadedMesh* wood1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinWood1.txt", NULL);
	CLoadedMesh* wood2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinWood2.txt", NULL);

	CLoadedMesh* rustyStair = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_rustyStair.txt", NULL);
	CLoadedMesh* trashCan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_GarbageCan.txt", NULL);

	CLoadedMesh* ruinBrick6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinBrick6.txt", NULL);
	CLoadedMesh* ruinCeramic3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinCeramic3.txt", NULL);

	CLoadedMesh* wdPallet = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_woodenPallet.txt", NULL);
	CLoadedMesh* wdPalletLayer = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_woodenPalletLayer.txt", NULL);

	CLoadedMesh* cement1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_Cement1.txt", NULL);
	CLoadedMesh* cement2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_Cement2.txt", NULL);

	CLoadedMesh* warnSign = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_radiationSign.txt", NULL);

	CLoadedMesh* fuelTruck = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_truck.txt", NULL);

	CLoadedMesh* chon = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_chon.txt", NULL);
	CLoadedMesh* guardRail = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_guardrail.txt", NULL);

	CLoadedMesh* twheel = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_truckwheel.txt", NULL);
	CLoadedMesh* tbody = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_truckbody.txt", NULL);

	CLoadedMesh* cardboard1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_cardboards1.txt", NULL);
	CLoadedMesh* cardboard2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_cardboards2.txt", NULL);
	CLoadedMesh* cardboard3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_cardboards3.txt", NULL);
	CLoadedMesh* cardboard4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_cardboards4.txt", NULL);

	CLoadedMesh* cont1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_control1.txt", NULL);
	CLoadedMesh* cont2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_control2.txt", NULL);
	CLoadedMesh* cont4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_control4.txt", NULL);

	CLoadedMesh* leverBody = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_leverbody.txt", NULL);
	CLoadedMesh* leverHandle = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_leverhandle.txt", NULL);

	CLoadedMesh* papers = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_papers.txt", NULL);

	CLoadedMesh* pizzaBox = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_pizzabox.txt", NULL);
	CLoadedMesh* speedBump = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_speedbump.txt", NULL);
	CLoadedMesh* trashCont = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_trashContainer.txt", NULL);


	//CLoadedMesh* enemydie = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/enemy/vtx_gundeath_10.txt", NULL);     
	                  

	RectMesh* ruinbase = new RectMesh(pd3dDevice, pd3dCommandList, 3.9f, 1.9f);

	PillarMesh* pillar = new PillarMesh(pd3dDevice, pd3dCommandList, 2, 2, 10);



	for (int i = 0; i < data.size(); ++i)
	{   
		CGameObject* obj = NULL;
		RectMesh* shadow = NULL;
		CGameObject* shd = NULL;
		if (data[i].type == RustyMetal_Floor)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[6]);
			obj->SetMesh(RustyFloor);
		}
		else if (data[i].type == RustyMetal_Ceiling)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[6]);
			obj->SetMesh(RustyFloor);
		}
		else if (data[i].type == RustyMetal_Wall_Front)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallFront);
		}
		else if (data[i].type == RustyMetal_Wall_Back)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallBack);
		}
		else if (data[i].type == RustyMetal_Wall_Left)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallLeft);
		}
		else if (data[i].type == RustyMetal_Wall_Right)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallRight);
		}
		else if (data[i].type == RustyMetal_Wall_Right2)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallRight2);
		}
		else if (data[i].type == RustyMetal_Wall_Right3)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallRight3);
		}
		else if (data[i].type == RustyMetal_Wall_Left_100m)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallLeft100m);
		}

		else if (data[i].type == RustyMetal_Wall_Center_50m)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallCenter50m);
		}
		else if (data[i].type == RustyMetal_Wall_HCenter_50m)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallHCenter50m);
		}
		else if (data[i].type == RustyMetal_Wall_Bottom_50m)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallBottom50m);
		}
		else if (data[i].type == RustyMetal_Wall_Top_100m)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallTop100m);
		}


		else if (data[i].type == RustyMetal_Wall_Right)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[9]);
			obj->SetMesh(RustyWallRight);
		}

		else if (data[i].type == RustyMetal_Box) // 밑면 -0.75f
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[8]);

			//obj->SetMesh(Metal_Box);
	//		obj->SetMesh(enemydie);

			obj->SetMesh(Metal_Box);


			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[114]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
			
		}
		else if (data[i].type == RustyMetal_Barrel) // 밑면 - 1.125f
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[7]);
			obj->SetMesh(RustyBarrel);
			obj->shadowHeight = 1.125f;

			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[113]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.
			
			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f*dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);

		}
		else if (data[i].type == WallPipe)//밑면 1.25
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[7]);
			obj->SetMesh(Pipe_Wall);
			obj->shadowHeight = 1.25f;
		}
		else if (data[i].type == FloorPipe)//밑면 0.375
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[7]);
			obj->SetMesh(Pipe_Floor);
			obj->shadowHeight = 0.375f;
		}
		else if (data[i].type == RustyFence)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[10]);
			obj->SetMesh(Fence);
			obj->shadowHeight = 0.3f;
			obj->shadowZ = 2.0f;

			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;

			if (data[i].rotation.y == 0.0f)
			{
				//그림자의 가로 길이는, 원본 물체의 x너비의 절반
				shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
				shd = new (std::nothrow) CGameObject(1);
				shd->SetMaterial(0, rm->materials[129]);
				shd->SetMesh(shadow);

				//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

				//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
				shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
				shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

				shadows.push_back(shd);
			}
			else
			{
				//그림자의 가로 길이는, 원본 물체의 x너비의 절반
				shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, h/3);
				shd = new (std::nothrow) CGameObject(1);
				shd->SetMaterial(0, rm->materials[130]);
				shd->SetMesh(shadow);

				//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

				//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
				shd->SetPosition(data[i].position.x - 0.5f * w - data[i].position.y, 0.0f, data[i].position.z);
				shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

				shadows.push_back(shd);
			}
		}
		else if (data[i].type == FoodBin)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[11]);
			obj->SetMesh(Foodbin);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[125]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z-0.3f);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
			
		}
		else if (data[i].type == Envelop1)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[12]);
			obj->SetMesh(env1);
			obj->shadowHeight = 0.25f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[126]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z-0.3f);
			shd->Rotate(0.0f, data[i].rotation.y + 0.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Envelop2)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[12]);
			obj->SetMesh(env2);
			obj->shadowHeight = 0.25f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[127]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z-0.3f);
			shd->Rotate(0.0f, data[i].rotation.y + 0.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Envelop3)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[12]);
			obj->SetMesh(env3);
			obj->shadowHeight = 0.25f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[128]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z-0.3f);
			shd->Rotate(0.0f, data[i].rotation.y + 0.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == MetalLadder)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[13]);
			obj->SetMesh(SteelLadder);
			obj->shadowHeight = 1.0f;
		}
		else if (data[i].type == RailBend)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[14]);
			obj->SetMesh(BendRail);
			obj->shadowHeight = 0.0f;
		}
		else if (data[i].type == RailStraight)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[14]);
			obj->SetMesh(StraightRail);
			obj->shadowHeight = 0.0f;
		}
		else if (data[i].type == RuinBrick1)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[15]);
			obj->SetMesh(brick1);
			obj->shadowHeight = 0.0f;

			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[138]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinBrick2)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[15]);
			obj->SetMesh(brick2);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[139]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinBrick3)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[15]);
			obj->SetMesh(brick3);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[140]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinBrick4)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[15]);
			obj->SetMesh(brick4);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[141]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinBrick5)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[15]);
			obj->SetMesh(brick5);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[142]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinCeramic1)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[16]);
			obj->SetMesh(ceramic1);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[144]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinCeramic2)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[16]);
			obj->SetMesh(ceramic2);
			obj->shadowHeight = 0.0f;
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[145]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RuinMix1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[17]);
		obj->SetMesh(mix1);
		obj->shadowHeight = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[147]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == RuinMix2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[18]);
		obj->SetMesh(mix2);
		obj->shadowHeight = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[148]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == RuinWood1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[19]);
		obj->SetMesh(wood1);
		obj->shadowHeight = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx*0.5f, w*0.5f);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[149]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == RuinWood2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[19]);
		obj->SetMesh(wood2);
		obj->shadowHeight = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx * 0.5f, w * 0.5f);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[150]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x , data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == RustyStair)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[20]);
		obj->SetMesh(rustyStair);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 1.5f;
		obj->shadowZ = 1.5f;
		}
		else if (data[i].type == RustyTrashCan)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[21]);
		obj->SetMesh(trashCan);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[131]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == RuinBrick6)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[15]);
		obj->SetMesh(ruinBrick6);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 1.5f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == RuinCeramic3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[16]);
		obj->SetMesh(ruinCeramic3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WoodenPallet)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[22]);
		obj->SetMesh(wdPallet);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[156]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == WoodenPalletLayer)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[22]);
		obj->SetMesh(wdPalletLayer);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[157]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == CementBag1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[23]);
		obj->SetMesh(cement1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[119]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 0.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == CementBag2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[23]);
		obj->SetMesh(cement2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[120]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 0.0f, 0.0f);

		shadows.push_back(shd);

		}
		else if (data[i].type == WarningSign)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[24]);
		obj->SetMesh(warnSign);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[137]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == FuelTruck)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[25]);
		obj->SetMesh(fuelTruck);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		if (data[i].rotation.y == 0.0f)
		{
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[153]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y + 3.0f, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else
		{
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx/2, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[114]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y+3, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		}
		else if (data[i].type == Chon)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[26]);
		obj->SetMesh(chon);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[121]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == GuardRail)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[27]);
		obj->SetMesh(guardRail);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h*4);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[163]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y + 4.0f, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Truck2Wheel)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[29]);
		obj->SetMesh(twheel);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[155]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Truck2Body)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[28]);
		obj->SetMesh(tbody);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[154]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Cardboard1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[30]);
		obj->SetMesh(cardboard1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[115]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y +0.7f, 0.0f, data[i].position.z+0.2f);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Cardboard2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[30]);
		obj->SetMesh(cardboard2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[116]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y + 0.7f, 0.0f, data[i].position.z+0.2f);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Cardboard3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[30]);
		obj->SetMesh(cardboard3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[117]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y + 0.7f, 0.0f, data[i].position.z+0.2f);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Cardboard4)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[30]);
		obj->SetMesh(cardboard4);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[118]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y + 0.7f, 0.0f, data[i].position.z+0.2f);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);

		}
		else if (data[i].type == Controller1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[31]);
		obj->SetMesh(cont1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, h, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[122]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Controller2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[31]);
		obj->SetMesh(cont2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, h, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[123]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Controller4)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[31]);
		obj->SetMesh(cont4);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, h, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[124]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == LeverBody)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[20]);
		obj->SetMesh(leverBody);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[133]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == LeverHandle)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[20]);
		obj->SetMesh(leverHandle);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[134]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == PaperWaste)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[32]);
		obj->SetMesh(papers);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[135]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == PizzaBox)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[33]);
		obj->SetMesh(pizzaBox);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[136]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == SpeedBump)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[34]);
		obj->SetMesh(speedBump);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
		//그림자의 가로 길이는, 원본 물체의 x너비의 절반
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, w);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[151]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == TrashContainer)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[35]);
		obj->SetMesh(trashCont);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		if (data[i].rotation.y == 0.0f)
		{
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[114]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else
		{
			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[114]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		}
		else if (data[i].type == RuinBase)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[30]);
			obj->SetMesh(ruinbase);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pillar)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[6]);
			obj->SetMesh(pillar);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		obj->type = data[i].type;
		obj->SetPosition(data[i].position);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		objects.push_back(obj);
	}

}
	
	
	


void TerrainShader1_1::ReleaseObjects()
{

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Release();
			objects.erase(objects.begin() + i);
		}
	}
	objects.clear();
}
void TerrainShader1_1::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader1_1::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader1_1::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	XMFLOAT3 cp = pCamera->getPosition();

	XMFLOAT3 look = pCamera->getLook();



	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			XMFLOAT3 pos = objects[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			//벽종류이거나 객체가 카메라와 10미터 이내인 경우 그냥 그림.

			if ((objects[i]->type >= 11000 && objects[i]->type < 11200))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			//벽이 아니거나 거리가 10미터 이상 멀 경우 각도를 고려하여 그릴지 말지 판단.
			else
			{
				if (dist <= 10.0f)
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
				else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
			}
		}
	}

	for (int i = 0; i < shadows.size(); ++i)
	{
		if (shadows[i])
		{
			XMFLOAT3 pos = shadows[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			//그림자의 위치가 카메라로부터 10미터 이내이거나, 카메라 방향으로부터 70도 이내에 있는 경우에만 그림
			if (dist <= 10.0f)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				shadows[i]->Render(pd3dCommandList, pCamera);
			}
			else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				shadows[i]->Render(pd3dCommandList, pCamera);
			}
		}
	}
}

D3D12_INPUT_LAYOUT_DESC TerrainShader1_1::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 1, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//pd3dInputElementDescs[2] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 2, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC TerrainShader1_1::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
#ifdef _WITH_LEFT_HAND_COORDINATES
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
#else
	d3dRasterizerDesc.FrontCounterClockwise = TRUE;
#endif
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return(d3dRasterizerDesc);
}

D3D12_SHADER_BYTECODE TerrainShader1_1::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader1_1::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}