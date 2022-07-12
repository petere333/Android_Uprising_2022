#include "TerrainShader1_2.h"

TerrainShader1_2::TerrainShader1_2(ResourceManager* r)
{
	rm = r;
}
TerrainShader1_2::~TerrainShader1_2() {}

void TerrainShader1_2::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* sig)
{
	data = LoadObjects("res/map/area1_2/objects1-2.txt");
	boxesWorld = LoadBoxes("res/map/area1_2/box1-2.txt", &nBox);

	for (int i = 0; i < 5; ++i)
	{
		productCreated[i] = chrono::system_clock::now();
	}
	goodsMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase1.txt", NULL);
	CLoadedMesh* shield = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_shield.txt", NULL);
	CLoadedMesh* bigshield = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_bigshield.txt", NULL);
	CLoadedMesh* longtank = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_longtank.txt", NULL);
	CLoadedMesh* fan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_airfan.txt", NULL);

	CLoadedMesh* m1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine1.txt", NULL);
	CLoadedMesh* m3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine3.txt", NULL);
	CLoadedMesh* m4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine4.txt", NULL);
	CLoadedMesh* m6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine6.txt", NULL);
	CLoadedMesh* m7 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine7.txt", NULL);

	CLoadedMesh* arm = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_robotarm.txt", NULL);
	CLoadedMesh* sewer = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_sewer.txt", NULL);

	WallMeshHorizontal* front = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshHorizontal* back = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);

	WallMeshVertical* left1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 195.0f, 10.0f);
	WallMeshVertical* left2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 5.0f);
	WallMeshVertical* left3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 10.0f);

	WallMeshVertical* right1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 195.0f, 10.0f);
	WallMeshVertical* right2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 5.0f);
	WallMeshVertical* right3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 10.0f);

	PillarMesh* center1 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 150, 10);
	PillarMesh* center2 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 4, 5);
	PillarMesh* center3 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 43, 5);
	PillarMesh* center4 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 3, 2);

	PillarMesh* hcenter1 = new PillarMesh(pd3dDevice, pd3dCommandList, 10, 1, 10);
	PillarMesh* hcenter2 = new PillarMesh(pd3dDevice, pd3dCommandList, 92, 1, 10);
	PillarMesh* hcenter3 = new PillarMesh(pd3dDevice, pd3dCommandList, 92, 1, 10);
	PillarMesh* hcenter4 = new PillarMesh(pd3dDevice, pd3dCommandList, 3, 1, 5);
	PillarMesh* hcenter5 = new PillarMesh(pd3dDevice, pd3dCommandList, 3, 1, 5);

	PillarMesh* wire = new PillarMesh(pd3dDevice, pd3dCommandList, 100, 50, 5);


	GridMesh* basefloor = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 200.0f);
	GridMesh* upperfloor = new GridMesh(pd3dDevice, pd3dCommandList, 100.0f, 50.0f);

	CLoadedMesh* fence = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_fence.txt", NULL);
	CLoadedMesh* chon = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_chon.txt", NULL);

	CLoadedMesh* cont1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_control1.txt", NULL);
	CLoadedMesh* cont2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_control2.txt", NULL);
	CLoadedMesh* cont4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_control4.txt", NULL);

	CLoadedMesh* contain = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_container.txt", NULL);

	CLoadedMesh* box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_box.txt", NULL);

	PillarMesh* chargeSlot = new PillarMesh(pd3dDevice, pd3dCommandList, 2, 2, 2);
	PillarMesh* chargeFloor = new PillarMesh(pd3dDevice, pd3dCommandList, 40, 40, 1);
	
	GridMesh* chargeFloor2 = new GridMesh(pd3dDevice, pd3dCommandList, 40.0f, 40.0f);

	PillarMesh* woodmanu_front = new PillarMesh(pd3dDevice, pd3dCommandList, 70, 1, 10);
	PillarMesh* woodmanu_back = new PillarMesh(pd3dDevice, pd3dCommandList, 70, 1, 10);

	PillarMesh* woodmanu_right1 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 145, 10);
	PillarMesh* woodmanu_right2 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 3, 7);
	PillarMesh* woodmanu_right3 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 12, 10);

	CLoadedMesh* table2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_table2.txt", NULL);
	CLoadedMesh* drill = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_drill.txt", NULL);
	CLoadedMesh* saw = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_saw.txt", NULL);

	CLoadedMesh* furniture1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_furniture1.txt", NULL);
	CLoadedMesh* furniture2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_furniture2.txt", NULL);

	CLoadedMesh* wood1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinWood1.txt", NULL);
	CLoadedMesh* wood2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_ruinWood2.txt", NULL);

	CLoadedMesh* log1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_log1.txt", NULL);
	CLoadedMesh* log2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_log2.txt", NULL);

	CLoadedMesh* shelf = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_shelf.txt", NULL);

	CLoadedMesh* glue = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_glue.txt", NULL);
	CLoadedMesh* bottle = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_bottle.txt", NULL);
	CLoadedMesh* hammer = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_hammer.txt", NULL);



	CLoadedMesh* toolbox = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_toolbox.txt", NULL);
	CLoadedMesh* bucket = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_bucket.txt", NULL);

	PillarMesh* pot_front = new PillarMesh(pd3dDevice, pd3dCommandList, 70, 1, 10);
	PillarMesh* pot_back1 = new PillarMesh(pd3dDevice, pd3dCommandList, 63, 1, 10);
	PillarMesh* pot_back2 = new PillarMesh(pd3dDevice, pd3dCommandList, 3, 1, 7);
	PillarMesh* pot_back3 = new PillarMesh(pd3dDevice, pd3dCommandList, 4, 1, 10);

	PillarMesh* pot_right = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 79, 10);

	PillarMesh* pot_center = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 70, 10);
	PillarMesh* pot_hcenter = new PillarMesh(pd3dDevice, pd3dCommandList, 10, 1, 10);

	GridMesh* pot_floor = new GridMesh(pd3dDevice, pd3dCommandList, 10.0f, 80.0f);

	CCubeMeshTextured* stair = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 1.0f, 10.0f);

	CLoadedMesh* pot1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase1.txt", NULL);
	CLoadedMesh* pot2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase2.txt", NULL);
	CLoadedMesh* pot3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase3.txt", NULL);
	CLoadedMesh* pot4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase4.txt", NULL);
	CLoadedMesh* pot5 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase5.txt", NULL);
	CLoadedMesh* pot6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase6.txt", NULL);
	CLoadedMesh* pot7 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase7.txt", NULL);
	CLoadedMesh* pot8 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase8.txt", NULL);
	CLoadedMesh* pot9 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase9.txt", NULL);
	CLoadedMesh* pot10 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase10.txt", NULL);
	CLoadedMesh* pot11 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase11.txt", NULL);
	CLoadedMesh* pot12 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase12.txt", NULL);
	CLoadedMesh* pot13 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase13.txt", NULL);
	CLoadedMesh* pot14 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase14.txt", NULL);
	CLoadedMesh* pot15 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_vase15.txt", NULL);

	CLoadedMesh* wdPallet = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_woodenPallet.txt", NULL);
	CLoadedMesh* wdPalletLayer = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_woodenPalletLayer.txt", NULL);

	CLoadedMesh* cement1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_Cement1.txt", NULL);

	GridMesh* trans_floor = new GridMesh(pd3dDevice, pd3dCommandList, 30.0f, 7.5f);

	PillarMesh* trans_hcenter = new PillarMesh(pd3dDevice, pd3dCommandList, 40, 1, 10);
	PillarMesh* trans_back1 = new PillarMesh(pd3dDevice, pd3dCommandList, 40, 1, 10);
	PillarMesh* trans_back2 = new PillarMesh(pd3dDevice, pd3dCommandList, 3, 1, 6);
	PillarMesh* trans_back3 = new PillarMesh(pd3dDevice, pd3dCommandList, 27, 1, 10);
	PillarMesh* trans_right = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 50, 10);

	CCubeMeshTextured* trans_stair = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 1.0f, 8.0f);
	
	PillarMesh* ev = new PillarMesh(pd3dDevice, pd3dCommandList, 20, 35, 10);

	RectMeshVertical* ev_door = new RectMeshVertical(pd3dDevice, pd3dCommandList, 3.0f, 4.0f);
	GridMesh* belt = new GridMesh(pd3dDevice, pd3dCommandList, 50.0f, 2.5f);

	CLoadedMesh* klinopen = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_klinopen.txt", NULL);
	CLoadedMesh* klinclose = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_klinclose.txt", NULL);
	CLoadedMesh* wheel = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_wheel.txt", NULL);
	CLoadedMesh* banner = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_banner.txt", NULL);
	CLoadedMesh* whitebd = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_whiteboard.txt", NULL);

	PillarMesh* woodPillar1 = new PillarMesh(pd3dDevice, pd3dCommandList, 60, 1, 10);
	PillarMesh* woodPillar2 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 50, 10);

	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;
		RectMesh* shadow = NULL;
		CGameObject* shd = NULL;


		if (data[i].type == Shield)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[44]);
			obj->SetMesh(shield);
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
			shd->SetMaterial(0, rm->materials[171]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == BigShield)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[45]);
			obj->SetMesh(bigshield);
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
			shd->SetMaterial(0, rm->materials[161]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == AirFan)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[47]);
			obj->SetMesh(fan);
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
			shd->SetMaterial(0, rm->materials[159]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);

		}
		else if (data[i].type == LongTank)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[46]);
			obj->SetMesh(longtank);
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
			shd->SetMaterial(0, rm->materials[183]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Machine1)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[48]);
			obj->SetMesh(m1);
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
			shd->SetMaterial(0, rm->materials[184]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Machine3)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[49]);
			obj->SetMesh(m3);
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
			shd->SetMaterial(0, rm->materials[185]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Machine4)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[50]);
			obj->SetMesh(m4);
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
			shd->SetMaterial(0, rm->materials[186]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Machine6)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[51]);
			obj->SetMesh(m6);
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
			shd->SetMaterial(0, rm->materials[187]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Machine7)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[52]);
			obj->SetMesh(m7);
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
			shd->SetMaterial(0, rm->materials[188]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == RobotArm)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[53]);
			obj->SetMesh(arm);
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
			shd->SetMaterial(0, rm->materials[189]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Sewer)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[54]);
			obj->SetMesh(sewer);
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
			shd->SetMaterial(0, rm->materials[191]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * dx , data[i].position.y, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}

		else if (data[i].type == Wall12_Left1)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[55]);
			obj->SetMesh(left1);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Left2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(left2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Left3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(left3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Right1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(right1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Right2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(right2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Right3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(right3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Front)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(front);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Back)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(back);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Floor)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(basefloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Ceiling)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[56]);
		obj->SetMesh(basefloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_UpperFloor)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(upperfloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(center1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(center2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(center3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center4)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(center4);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(hcenter1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(hcenter2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(hcenter3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter4)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(hcenter4);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter5)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(hcenter5);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WireFrame)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[58]);
		obj->SetMesh(wire);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Fence12)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[10]);
		obj->SetMesh(fence);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;

		//원본 물체 크기의 x,y 길이
		float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
		float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
		float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;

		if (data[i].rotation.y == 0.0f)
		{
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[172]);
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
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, dx, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[173]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x - 0.5f * w - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		}
		else if (data[i].type == Chon12)
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
		shd->SetMaterial(0, rm->materials[165]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Controller12_1)
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
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[167]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Controller12_2)
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
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[168]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Controller12_4)
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
		shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
		shd = new (std::nothrow) CGameObject(1);
		shd->SetMaterial(0, rm->materials[169]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Container12)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[59]);
		obj->SetMesh(contain);
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
		shd->SetMaterial(0, rm->materials[166]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == ChargeSlot)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[58]);
		obj->SetMesh(chargeSlot);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == ChargeFloor)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(chargeFloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == ChargeFloor2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(chargeFloor2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == ChargingRobot)
		{
		obj = new (std::nothrow) CGameObject(pd3dDevice, pd3dCommandList, sig, rm->playerModels[0], 1);

		obj->SetTrackAnimationSet(0, 0);

		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Box12)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[8]);
		obj->SetMesh(box);
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
		shd->SetMaterial(0, rm->materials[163]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == WoodManu_WallFront)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodmanu_front);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WoodManu_WallBack)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodmanu_back);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WoodManu_WallRight1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodmanu_right1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WoodManu_WallRight2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodmanu_right2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WoodManu_WallRight3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodmanu_right3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == TableBig)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[66]);
		obj->SetMesh(table2);
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
		shd->SetMaterial(0, rm->materials[194]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Saw)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[62]);
		obj->SetMesh(saw);
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
		shd->SetMaterial(0, rm->materials[190]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Drill)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[61]);
		obj->SetMesh(drill);
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
		shd->SetMaterial(0, rm->materials[170]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Woods1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[19]);
		obj->SetMesh(wood1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Woods2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[19]);
		obj->SetMesh(wood2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == PlainLog1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[67]);
		obj->SetMesh(log1);
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
		shd->SetMaterial(0, rm->materials[181]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == PlainLog2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[68]);
		obj->SetMesh(log2);
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
		shd->SetMaterial(0, rm->materials[182]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Furniture1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[63]);
		obj->SetMesh(furniture1);
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
		shd->SetMaterial(0, rm->materials[174]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Furniture2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[64]);
		obj->SetMesh(furniture2);
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
		shd->SetMaterial(0, rm->materials[175]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Shelf)
		{	
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[64]);
		obj->SetMesh(shelf);
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
		shd->SetMaterial(0, rm->materials[192]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == ToolBox)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[69]);
		obj->SetMesh(toolbox);
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
		shd->SetMaterial(0, rm->materials[195]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Glue)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[70]);
		obj->SetMesh(glue);
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
		shd->SetMaterial(0, rm->materials[176]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Hammer)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[71]);
		obj->SetMesh(glue);
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
		shd->SetMaterial(0, rm->materials[177]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Bottle)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[72]);
		obj->SetMesh(glue);
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
		shd->SetMaterial(0, rm->materials[162]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == PaintBarrel)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[66]);
		obj->SetMesh(bucket);
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
		shd->SetMaterial(0, rm->materials[164]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == Pottery_WallFront)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_front);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_WallBack1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_back1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_WallBack2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_back2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_WallBack3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_back3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_WallRight)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_right);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_WallCenter)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_center);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_WallHCenter)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[73]);
		obj->SetMesh(pot_hcenter);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_UpperFloor)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(pot_floor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pottery_Stair)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(stair);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}

		else if (data[i].type == Pottery1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot1);
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
		shd->SetMaterial(0, rm->materials[196]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx , data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot2);
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
		shd->SetMaterial(0, rm->materials[197]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);

		}
		else if (data[i].type == Pottery3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot3);
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
		shd->SetMaterial(0, rm->materials[198]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery4)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot4);
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
		shd->SetMaterial(0, rm->materials[199]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == Pottery5)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot5);
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
		shd->SetMaterial(0, rm->materials[200]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery6)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot6);
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
		shd->SetMaterial(0, rm->materials[201]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery7)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot7);
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
		shd->SetMaterial(0, rm->materials[202]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery8)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot8);
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
		shd->SetMaterial(0, rm->materials[203]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == Pottery9)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot9);
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
		shd->SetMaterial(0, rm->materials[204]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery10)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot10);
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
		shd->SetMaterial(0, rm->materials[205]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery11)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot11);
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
		shd->SetMaterial(0, rm->materials[206]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery12)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot12);
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
		shd->SetMaterial(0, rm->materials[207]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == Pottery13)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot13);
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
		shd->SetMaterial(0, rm->materials[208]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery14)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot14);
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
		shd->SetMaterial(0, rm->materials[209]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Pottery15)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(pot15);
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
		shd->SetMaterial(0, rm->materials[210]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx, data[i].position.y, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}

		else if (data[i].type == PotterySoil)
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
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == PotterySoilPallet)
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
		else if (data[i].type == PotterySoilPalletLayer)
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
		else if (data[i].type == Transfer_UpperFloor)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(trans_floor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Transfer_HCenter)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(trans_hcenter);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Transfer_WallBack1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(trans_back1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Transfer_WallBack2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(trans_back2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Transfer_WallBack3)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(trans_back3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Transfer_WallRight)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(trans_right);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Transfer_Stair)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[57]);
		obj->SetMesh(trans_stair);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}

		else if (data[i].type == ConveyorDoor)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[76]);
		obj->SetMesh(ev_door);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == ConveyorBelt)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[77]);
		obj->SetMesh(belt);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Elevator)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[55]);
		obj->SetMesh(ev);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == PotteryKlinClose)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[79]);
		obj->SetMesh(klinclose);
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
		shd->SetMaterial(0, rm->materials[179]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == PotteryKlinOpen)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[79]);
		obj->SetMesh(klinopen);
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
		shd->SetMaterial(0, rm->materials[180]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * dx - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);

		}
		else if (data[i].type == PotteryWheel)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[80]);
		obj->SetMesh(wheel);
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
		shd->SetMaterial(0, rm->materials[211]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);

		}
		else if (data[i].type == Banner)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[78]);
		obj->SetMesh(banner);
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
		shd->SetMaterial(0, rm->materials[160]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == Whiteboard)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[81]);
		obj->SetMesh(whitebd);
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
		shd->SetMaterial(0, rm->materials[212]);
		shd->SetMesh(shadow);

		//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

		//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
		shd->SetPosition(data[i].position.x - 0.5f * h - data[i].position.y, 0.0f, data[i].position.z);
		shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

		shadows.push_back(shd);
		}
		else if (data[i].type == WoodManu_Pillar1)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodPillar1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WoodManu_Pillar2)
		{
		obj = new (std::nothrow) CGameObject(1);
		obj->SetMaterial(0, rm->materials[75]);
		obj->SetMesh(woodPillar2);
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

void TerrainShader1_2::ReleaseObjects()
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
	for (int i = 0; i < products.size(); ++i)
	{
		if (products[i])
		{
			products[i]->Release();
			products.erase(products.begin() + i);
		}
	}
	products.clear();
}
void TerrainShader1_2::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
	for (int i = 0; i < products.size(); ++i)
	{
		if (products[i])
		{
			products[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader1_2::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
	for (int i = 0; i < products.size(); ++i)
	{
		if (products[i])
		{
			products[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader1_2::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, float elapsed)
{
	XMFLOAT3 cp = pCamera->getPosition();

	XMFLOAT3 look = pCamera->getLook();
	for (int i = 0; i < products.size(); ++i)
	{
		if (products[i])
		{
			XMFLOAT3 pos = products[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			if (dist <= 10.0f)
			{

				products[i]->Render(pd3dCommandList, pCamera);
			}
			else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
			{

				products[i]->Render(pd3dCommandList, pCamera);
			}
		}
	}

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			XMFLOAT3 pos = objects[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			//벽인경우 그냥 그림
			if ((objects[i]->type >= 12000 && objects[i]->type < 12200))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}

			//아닌경우
			else
			{
				if (dist <= 10.0f)
				{
					if (objects[i]->type == ChargingRobot)
					{

						objects[i]->Animate(elapsed);
						if (objects[i]->m_pSkinnedAnimationController)
						{
							objects[i]->UpdateTransform(NULL);
						}
						rm->materials[33]->UpdateShaderVariable(pd3dCommandList);

					}
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
				else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 55.0f))
				{
					if (objects[i]->type == ChargingRobot)
					{

						objects[i]->Animate(elapsed);
						if (objects[i]->m_pSkinnedAnimationController)
						{
							objects[i]->UpdateTransform(NULL);
						}
						rm->materials[33]->UpdateShaderVariable(pd3dCommandList);

					}
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
			}
			

			objects[i]->Render(pd3dCommandList, pCamera);
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

D3D12_INPUT_LAYOUT_DESC TerrainShader1_2::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader1_2::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader1_2::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader1_2::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}


void TerrainShader1_2::animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float elapsed)
{
	
	// 모든 상품 생성 지점에 대해
	for (int i = 0; i < 5; ++i)
	{
		chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
		chrono::duration<double> fromCreated = moment - productCreated[i];
		float sec = (float)fromCreated.count();
		//마지막으로 생성된지 4초가 지나면 생성시점을 현재로 하고 물체 생성
		if (sec > 4.0f)
		{
			CGameObject* goods = new CGameObject(1);
			goods->SetMaterial(0, rm->materials[125]);
			goods->SetMesh(goodsMesh);
			goods->shadowHeight = 0.0f;
			goods->shadowX = 0.0f;
			goods->shadowZ = 0.0f;

			goods->type = 12400;
			goods->SetPosition(540.0f, 0.0f, 167.5f + 7.5f*i);
			goods->Rotate(0.0f, 0.0f, 0.0f);

			products.push_back(goods);

			BoundBox* box = (BoundBox*)malloc(sizeof(BoundBox));
			box->start = XMFLOAT3(539.85f, 0.0f, 167.35f + 7.5f * i);
			box->end = XMFLOAT3(540.15f, 0.5f, 167.65f + 7.5f * i);

			boxGoods.push_back(box);

			productCreated[i] = chrono::system_clock::now();
			lastMove.push_back(chrono::system_clock::now());
			
		}
	}

	//모든 물체에 대해
	for (int i = 0; i < products.size(); ++i)
	{
		chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
		chrono::duration<double> fromCreated = moment - lastMove[i];
		float ftime = (float)fromCreated.count();

		XMFLOAT3 pt = products[i]->GetPosition();
		products[i]->SetPosition(pt.x - ftime * 5.0f, pt.y, pt.z);
		boxGoods[i]->start.x -= ftime * 5.0f;
		boxGoods[i]->end.x -= ftime * 5.0f;

		lastMove[i] = moment;
		// 엘베 안으로 들어가면
		if (pt.x - ftime * 5.0f < 490.0f)
		{
			products.erase(products.begin() + i);
			boxGoods.erase(boxGoods.begin() + i);
			lastMove.erase(lastMove.begin() + i);
		}
	}
	
}