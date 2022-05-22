#include "TerrainShader.h"

TerrainShader::TerrainShader(ResourceManager* r)
{
	rm = r;
}
TerrainShader::~TerrainShader() {}

void TerrainShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/objects.txt");
	boxesWorld = LoadBoxes("res/map/box.txt", &nBox);
	stairsWorld = LoadStairs("res/map/stair.txt", &nStairs);

	CCubeMeshTextured* pPlayerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 1.7f, 1.0f);
	CCubeMeshTextured* ContMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 100.0f, 25.0f, 50.0f);
	CCubeMeshTextured* J_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 50.0f, 7.5f, 120.0f);
	CCubeMeshTextured* T_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 5.0f, 200.0f);
	CCubeMeshTextured* B_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 260.0f, 12.5f, 320.0f);
	// CCubeMeshTextured* ChonJang = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 620.0f, 3.0f, 620.0f);
	CCubeMeshTextured* Add_block1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 7.5f, 25.0f);
	CCubeMeshTextured* Add_block2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 5.0f, 2.5f);
	CCubeMeshTextured* Pan1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 0.0f, 0.0f, 0.0f);
	CCubeMeshTextured* Pan2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 120.0f, 2.0f, 60.0f);
	CCubeMeshTextured* Pan3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 20.0f, 1.3f, 20.0f);
	CCubeMeshTextured* Pan4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 16.0f, 19.9f, 16.0f);
	//CCubeMeshTextured* pContainerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 2.5f, 6.0f);
	//CCubeMeshTextured* Contain1_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 25.0f, 20.0f);
	CCubeMeshTextured* Not_ddul = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 31.25f, 5.0f, 2.0f);
	CCubeMeshTextured* ddul = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 31.25f, 5.0f, 2.0f); // 뚫을 수 있는 벽
	CCubeMeshTextured* Gongjang_janhae10 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 5.5f, 3.0f); //
	CCubeMeshTextured* Gongjang_janhae13 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 3.0f, 3.0f, 24.0f); //
	CCubeMeshTextured* Gongjang_janhae14 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 6.0f, 7.5f, 70.0f); //
	CCubeMeshTextured* didimz1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 80.0f, 0.7f, 2.0f); //
	CCubeMeshTextured* R_GyeDan_1_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 92.0f, 6.0f, 14.0f); //

	//CRectMeshTextured* pTileMesh = new CRectMeshTextured(pd3dDevice, pd3dCommandList, 2.5f, 2.5f);

	GridMesh* pGrid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);
	GridMesh* t_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 20.0f);
	GridMesh* Se_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);
	GridMesh* ChonJang = new GridMesh(pd3dDevice, pd3dCommandList, 670.0f, 640.0f);




	WallMeshHorizontal* hWall = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* hWall_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* vWall = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* vWall_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* vWall_S = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* vWall_SM = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* vWall_1S = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshVertical* vWall_1SM = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshVertical* vWall_H = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshHorizontal* hWall_H = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshVertical* frooms = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 2.5f);
	WallMeshVertical* frooms_H = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshHorizontal* loadwall1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshHorizontal* loadwall2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshHorizontal* loadwall3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 7.5f);
	WallMeshVertical* Se_room_l1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* Se_room_l2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* Se_room_l3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 7.5f);
	WallMeshVertical* Se_room_r1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* Se_room_r2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* Se_room_r3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 7.5f);
	WallMeshVertical* Se_rs1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* Se_rs2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* Se_rs3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshHorizontal* Se_fb1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* Se_fb2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* Se_fb3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshVertical* Se_BS1_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 2.5f);
	WallMeshVertical* Se_BS1_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 2.5f);
	WallMeshVertical* Se_BS1_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 7.5f);
	WallMeshVertical* Se_BS2_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshVertical* Se_BS2_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshVertical* Se_BS2_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 7.5f);
	WallMeshVertical* Se_BS3_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 2.5f);
	WallMeshVertical* Se_BS3_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 2.5f);
	WallMeshVertical* Se_BS3_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 7.5f);
	WallMeshHorizontal* Se_BS4_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshHorizontal* Se_BS4_2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshHorizontal* Se_BS4_3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 7.5f);
	WallMeshVertical* Frst_lh = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);

	WallMeshVertical* Bated_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* Bated_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* Bat_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshVertical* Bat_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 20.0f, 200.0f);
	WallMeshVertical* Bat_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshHorizontal* Bat_FB1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB_11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB_12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBated_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBated_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBat_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshVertical* SeBat_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 20.0f, 200.0f);
	WallMeshVertical* SeBat_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB_11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB_12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* add_wall1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 5.0f);
	WallMeshVertical* add_wall2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);

	WallMeshHorizontal* Add_Bak1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 150.0f, 5.0f);
	WallMeshHorizontal* Add_Bak2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 150.0f, 7.5f);
	WallMeshHorizontal* SeAdders1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 100.0f, 5.0f);
	WallMeshHorizontal* SeAdders2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 100.0f, 7.5f);


	WallMeshHorizontal* Walz1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 97.5f, 5.0f);
	WallMeshHorizontal* Walz2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 97.5f, 7.5f);
	WallMeshHorizontal* Walz3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshVertical* Walz4 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 5.0f);
	WallMeshVertical* Walz5 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshHorizontal* Walz6 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 155.0f, 5.0f);
	WallMeshHorizontal* Walz7 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 155.0f, 7.5f);
	WallMeshHorizontal* Walz8 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 65.0f, 5.0f);
	WallMeshHorizontal* Walz9 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 65.0f, 7.5f);
	WallMeshHorizontal* Walz10 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshHorizontal* Walz11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 30.0f, 12.5f);
	WallMeshHorizontal* Walz12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshHorizontal* Walz13 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 120.0f, 12.5f); // 감옥창살
	WallMeshHorizontal* Walz13_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 120.0f, 12.5f); // 감옥창살
	WallMeshVertical* Walz14 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 60.0f, 12.5f);
	WallMeshVertical* Walz15 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 145.0f, 5.0f);
	WallMeshVertical* Walz16 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 145.0f, 7.5f);
	WallMeshHorizontal* Walz17 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 5.0f); // 시작지점 근처 벽
	WallMeshHorizontal* Walz18 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshVertical* Walz19 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 115.0f, 5.0f);
	WallMeshVertical* Walz20 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 115.0f, 7.5f);
	WallMeshHorizontal* Walz21 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 5.0f); // 시작지점 근처 벽
	WallMeshHorizontal* Walz22 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshHorizontal* Walz23 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 75.0f, 5.0f); // 시작지점 근처 벽
	WallMeshHorizontal* Walz24 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 75.0f, 7.5f);
	WallMeshVertical* Walz25 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 7.5f, 5.0f);
	WallMeshVertical* Walz26 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 7.5f, 7.5f);


	WallMeshVertical* Walz27 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 5.0f, 5.0f);
	WallMeshVertical* Walz28 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshVertical* Walz29 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz30 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz31 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 315.0f, 5.0f);
	WallMeshVertical* Walz32 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 315.0f, 7.5f);
	WallMeshHorizontal* Walz33 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 12.5f, 5.0f);
	WallMeshHorizontal* Walz34 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 12.5f, 7.5f);
	WallMeshHorizontal* Walz35 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 250.0f, 5.0f);
	WallMeshHorizontal* Walz36 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 250.0f, 7.5f);
	WallMeshVertical* Walz37 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 15.0f, 5.0f);
	WallMeshVertical* Walz38 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 15.0f, 7.5f);
	WallMeshVertical* Walz39 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 90.0f, 5.0f);
	WallMeshVertical* Walz40 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 90.0f, 7.5f);
	WallMeshHorizontal* Walz41 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshHorizontal* Walz42 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz43 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz44 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);

	WallMeshVertical* Walz45 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz46 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz47 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz48 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz49 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 100.0f, 12.5f);
	WallMeshHorizontal* Walz50 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 155.0f, 12.5f);
	WallMeshHorizontal* Walz51 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 65.0f, 12.5f);
	WallMeshHorizontal* Walz52 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 90.0f, 12.5f);
	WallMeshHorizontal* Walz53 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 20.0f, 12.5f);
	WallMeshHorizontal* Walz54 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 135.0f, 12.5f);
	WallMeshVertical* Fro1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 5.0f);
	WallMeshVertical* Fro2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshHorizontal* tpw1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshVertical* tpw2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);

	CLoadedMesh* container = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_container2.txt", NULL);
	CLoadedMesh* box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_box.txt", NULL);
	CLoadedMesh* tableMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_table.txt", "res/idx_table.txt");
	CLoadedMesh* chairMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_chair3.txt", "res/idx_chair3.txt");
	CLoadedMesh* cartMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_pallet.txt", "res/idx_pallet.txt");
	CLoadedMesh* binMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_bin.txt", "res/idx_bin.txt");
	CLoadedMesh* barrelMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_barrel.txt", "res/idx_barrel.txt");
	CLoadedMesh* truckMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_truck.txt", "res/idx_truck.txt");

	CLoadedMesh* Container1_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Cont1_1.txt", "res/idx_Cont1_1.txt");
	CLoadedMesh* GyeDan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_신계단1.txt", NULL);
	CLoadedMesh* GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_신계단1.txt", NULL);
	CLoadedMesh* R_GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_new계단.txt", NULL);
	CLoadedMesh* P_Doors = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Doors.txt", NULL);
	CLoadedMesh* H_Heat = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_공장_히터.txt", NULL);
	CLoadedMesh* B_box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_1Stage_Box.txt", NULL);
	CLoadedMesh* Gongjang_tool1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Covers.txt", NULL);
	CLoadedMesh* Gongjang_tool2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Convel.txt", NULL);
	CLoadedMesh* Gongjang_tool3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_종이박스.txt", NULL);
	CLoadedMesh* Gongjang_tool4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_발전기.txt", NULL);
	CLoadedMesh* Gongjang_tool5 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_케비넷.txt", NULL);
	CLoadedMesh* Gongjang_tool6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_어느기계.txt", NULL);
	CLoadedMesh* Gongjang_tool7 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_드럼통.txt", NULL);
	CLoadedMesh* Gongjang_tool8 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_짐덩이.txt", NULL);
	CLoadedMesh* Gongjang_tool9 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_어느선반.txt", NULL);
	CLoadedMesh* Gongjang_tool10 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_그냥화물1.txt", NULL);
	CLoadedMesh* Gongjang_tool11 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_쓰레기봉투.txt", NULL);
	CLoadedMesh* Gongjang_tool12 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_철벽.txt", NULL);
	CLoadedMesh* Gongjang_tool13 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_철벽2.txt", NULL);
	CLoadedMesh* Gongjang_tool14 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_발전소.txt", NULL);
	CLoadedMesh* Gongjang_tool15 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_발전소2.txt", NULL);
	CLoadedMesh* Gongjang_tool16 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_주기둥.txt", NULL);
	CLoadedMesh* Gongjang_tool17 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_긴탱크.txt", NULL);
	CLoadedMesh* Gongjang_tool18 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_둥글뱅이탱크.txt", NULL);
	CLoadedMesh* Gongjang_tool19 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_둥글뱅이탱크.txt", NULL);
	CLoadedMesh* Gongjang_tool20 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_둥글뱅이탱크.txt", NULL);
	CLoadedMesh* Gongjang_janhae1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해물.txt", NULL);
	CLoadedMesh* Gongjang_janhae2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해물2.txt", NULL);
	CLoadedMesh* Gongjang_janhae3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해물3.txt", NULL);
	CLoadedMesh* Gongjang_janhae3_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해물3_1.txt", NULL);
	CLoadedMesh* Gongjang_janhae4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_구데기통.txt", NULL);
	CLoadedMesh* Gongjang_janhae5 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_삽.txt", NULL);
	CLoadedMesh* Gongjang_janhae6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_톱날단검.txt", NULL);
	CLoadedMesh* Gongjang_janhae7 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_톱날단검2.txt", NULL);
	CLoadedMesh* Gongjang_janhae8 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해기계.txt", NULL);
	CLoadedMesh* Gongjang_janhae9 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해트럭.txt", NULL);
	CLoadedMesh* Gongjang_janhae11 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해드럼통.txt", NULL);
	CLoadedMesh* Gongjang_janhae12 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_잔해탁자.txt", NULL);
	CLoadedMesh* Gongjang_janhae15 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_대회의실.txt", NULL);
	CLoadedMesh* Gongjang_janhae16 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_문1.txt", NULL);
	CLoadedMesh* Gongjang_janhae17 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_문짝.txt", NULL);
	CLoadedMesh* Gongjang_janhae18 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_소형발전.txt", NULL);
	CLoadedMesh* Gongjang_janhae19 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_돌덩이1.txt", NULL);
	CLoadedMesh* Gongjang_janhae20 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_통신병PTSD.txt", NULL);
	CLoadedMesh* Gongjang_janhae21 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_팬스.txt", NULL);
	CLoadedMesh* Gongjang_janhae22 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_물돼지.txt", NULL);
	CLoadedMesh* Gongjang_janhae23 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_스윽삭.txt", NULL);


	/*
	RectMesh** shadowRect = new RectMesh * [nShadows];
	m_ppShadows = new CGameObject * [m_nGameObjects];

	for (int i = 0; i < nShadows; ++i)
	{
		shadowRect[i] = NULL;
	}
	for (int i = 0; i < m_nGameObjects; ++i)
	{
		m_ppShadows[i] = NULL;
	}
	*/


	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj;

		if (data[i].type == PLAYER)//player
		{
			obj = new CGameObject(1);
			obj->SetMesh(barrelMesh);
			obj->SetMaterial(0, rm->materials[9]);
			

		}
		else if (data[i].type == CONTAINER)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(container);
			obj->SetMaterial(0, rm->materials[0]);


		}
		else if (data[i].type == floor)
		{
			obj = new CGameObject(1);
			obj->SetMesh(pGrid);
			obj->SetMaterial(0, rm->materials[17]);
		}
		else if (data[i].type == vWalls)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == hWalls)
		{
			obj = new CGameObject(1);
			obj->SetMesh(hWall);
			obj->SetMaterial(0, rm->materials[12]);

		}
		else if (data[i].type == BOX)
		{
			obj = new CGameObject(1);
			obj->SetMesh(box);
			obj->SetMaterial(0, rm->materials[5]);
		}
		else if (data[i].type == PALLET)
		{
			obj = new CGameObject(1);
			obj->SetMesh(cartMesh);
			obj->SetMaterial(0, rm->materials[7]);
		}
		else if (data[i].type == TRASH)
		{
			obj = new CGameObject(1);
			obj->SetMesh(binMesh);
			obj->SetMaterial(0, rm->materials[8]);
		}
		else if (data[i].type == BARREL)
		{
			obj = new CGameObject(1);
			obj->SetMesh(barrelMesh);
			obj->SetMaterial(0, rm->materials[9]);
		}
		else if (data[i].type == TRUCK)
		{
			obj = new CGameObject(1);
			obj->SetMesh(truckMesh);
			obj->SetMaterial(0, rm->materials[10]);
		}
		else if (data[i].type == TABLE)
		{
			obj = new CGameObject(1);
			obj->SetMesh(tableMesh);
			obj->SetMaterial(0, rm->materials[6]);
		}
		else if (data[i].type == CHAIR)
		{
			obj = new CGameObject(1);
			obj->SetMesh(chairMesh);
			obj->SetMaterial(0, rm->materials[1]);
		}
		else if (data[i].type == vWalls_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_1);
			obj->SetMaterial(0, rm->materials[2]);
		}
		else if (data[i].type == hWalls_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(hWall_1);
			obj->SetMaterial(0, rm->materials[2]);
		}
		else if (data[i].type == vWalls_S)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_S);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == vWalls_SM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_SM);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == vWalls_1S)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_1S);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == vWalls_1SM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_1SM);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == vWalls_H)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_H);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == hWalls_H)
		{
			obj = new CGameObject(1);
			obj->SetMesh(hWall_H);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == froom_set)
		{
			obj = new CGameObject(1);
			obj->SetMesh(frooms);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == froom_set_H)
		{
			obj = new CGameObject(1);
			obj->SetMesh(frooms_H);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == floor_T)
		{
			obj = new CGameObject(1);
			obj->SetMesh(t_Grid);
			obj->SetMaterial(0, rm->materials[17]);
		}
		else if (data[i].type == loadwall_l)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(loadwall1);
			obj->SetMaterial(0, rm->materials[12]);

		}
		else if (data[i].type == loadwall_m)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(loadwall2);
			obj->SetMaterial(0, rm->materials[12]);

		}
		else if (data[i].type == loadwall_h)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(loadwall3);
			obj->SetMaterial(0, rm->materials[11]);

		}
		else if (data[i].type == floor_Se)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_Grid);
			obj->SetMaterial(0, rm->materials[17]);
		}
		else if (data[i].type == Se_room_L1_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_l1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_L1_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_l2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_L1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_l3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_room_R1_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_r1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_R1_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_r2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_R1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_r3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_room_RSL)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_rs1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_RSM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_rs2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_RSH)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_rs3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_room_FBL)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_fb1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_FBM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_fb2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_room_FBH)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_fb3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_Busok1_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS1_1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok1_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS1_2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS1_3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_Busok2_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS2_1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok2_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS2_2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok2_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS2_3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_Busok3_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS3_1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok3_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS3_2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok3_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS3_3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Se_Busok4_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS4_1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok4_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS4_2);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == Se_Busok4_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS4_3);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Cont1_1)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(Container1_1);
			obj->Rotate(0.0f, 90.0f, 0.0f);
			obj->SetMaterial(0, rm->materials[0]);

		}
		else if (data[i].type == Frs_H)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(Frst_lh);
			obj->SetMaterial(0, rm->materials[11]);

		}
		else if (data[i].type == BatSet1)//지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_1);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == BatSet2)//지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_2);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == BatSet3)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_3);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == Bat_FB_set1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB1);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == Bat_FB_set2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB2);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == BatSet_1)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bated_1);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == BatSet_2)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bated_2);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == Bat_FB_101)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB_11);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == Bat_FB_102)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB_12);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBatSet1)//지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_1);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBatSet3)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_3);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBat_FB_set1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB1);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBat_FB_set2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB2);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBatSet_1)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBated_1);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBatSet_2)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBated_2);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBat_FB_101)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB_11);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == SeBat_FB_102)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB_12);
			obj->SetMaterial(0, rm->materials[1]);

		}
		else if (data[i].type == M_Contain)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(ContMesh1);
			obj->SetMaterial(0, rm->materials[0]);

		}
		else if (data[i].type == J_Contain)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(J_ConMesh1);
			obj->SetMaterial(0, rm->materials[14]);

		}
		else if (data[i].type == T_Contains)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(T_ConMesh1);
			obj->SetMaterial(0, rm->materials[15]);

		}
		else if (data[i].type == B_Contain)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(B_ConMesh1);
			obj->SetMaterial(0, rm->materials[16]);

		}
		else if (data[i].type == Shell)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(ChonJang);
			obj->SetMaterial(0, rm->materials[18]);

		}
		else if (data[i].type == GyeDans1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(GyeDan);
			//obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, rm->materials[20]);
		}
		else if (data[i].type == Frs_Pons1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(add_wall1);
			obj->SetMaterial(0, rm->materials[12]);

		}
		else if (data[i].type == Frs_Pons2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(add_wall2);
			obj->SetMaterial(0, rm->materials[11]);

		}
		else if (data[i].type == GyeDans2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(GyeDan_1);
			//	obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, rm->materials[20]);

		}
		else if (data[i].type == R_GyeDan1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(R_GyeDan_1);
			//	obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, rm->materials[20]);

		}
		else if (data[i].type == adds_beok1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_Bak1);
			obj->SetMaterial(0, rm->materials[12]);

		}
		else if (data[i].type == adds_beok2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_Bak2);
			obj->SetMaterial(0, rm->materials[11]);

		}
		else if (data[i].type == B_Door)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(P_Doors);
			//	obj->SetMaterial(0, rm->materials[1]);
			obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Add_squre1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_block1);
			obj->SetMaterial(0, rm->materials[19]);

		}
		else if (data[i].type == Add_squre2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_block2);
			obj->SetMaterial(0, rm->materials[19]);

		}
		else if (data[i].type == SeAddings1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeAdders1);
			obj->SetMaterial(0, rm->materials[12]);

		}
		else if (data[i].type == SeAddings2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeAdders2);
			obj->SetMaterial(0, rm->materials[11]);

		}
		else if (data[i].type == Heaters1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(H_Heat);
			obj->SetMaterial(0, rm->materials[21]);

		}
		else if (data[i].type == F_Stages)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(B_box);
			obj->SetMaterial(0, rm->materials[22]);
			//obj->SetMaterial(0, rm->materials[23]);
		}
		else if (data[i].type == Factory_tool1)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool1);
			obj->SetMaterial(0, rm->materials[24]);
			obj->Rotate(270.0f, 0.0f, 0.0f);
		}
		else if (data[i].type == Factory_tool2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool2);
			obj->SetMaterial(0, rm->materials[25]);

		}
		else if (data[i].type == Factory_tool3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool3);
			obj->SetMaterial(0, rm->materials[26]);

		}
		else if (data[i].type == Factory_tool4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool4);
			obj->SetMaterial(0, rm->materials[27]);

		}
		else if (data[i].type == Factory_tool5)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool5);
			obj->SetMaterial(0, rm->materials[28]);
			obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool6)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool6);
			obj->SetMaterial(0, rm->materials[29]);
			obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool7)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool7);
			obj->SetMaterial(0, rm->materials[30]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool8)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool8);
			obj->SetMaterial(0, rm->materials[31]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool9)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool9);
			obj->SetMaterial(0, rm->materials[35]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool10)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool10);
			obj->SetMaterial(0, rm->materials[36]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool11)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool11);
			obj->SetMaterial(0, rm->materials[36]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz1);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz2);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz3);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz4);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz5)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz5);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz6)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz6);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz7)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz7);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz8)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz8);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz9)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz9);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz10)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz10);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Chagsal1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz11);
			obj->SetMaterial(0, rm->materials[37]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Chagsal2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz12);
			obj->SetMaterial(0, rm->materials[37]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Pyo)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Pan1);
			obj->SetMaterial(0, rm->materials[13]);
			//	obj->Rotate(0.0f, 0.0f, 90.0f);

		}
		else if (data[i].type == GamOk)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz13);
			obj->SetMaterial(0, rm->materials[38]);
			//	obj->Rotate(0.0f, 0.0f, 90.0f);

		}
		else if (data[i].type == GamOk2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz14);
			obj->SetMaterial(0, rm->materials[39]);
			//obj->Rotate(0.0f, 90.0f, 0.0f);

		}
		else if (data[i].type == GamOk_Shell)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Pan2);
			obj->SetMaterial(0, rm->materials[36]);
			//obj->Rotate(0.0f, 90.0f, 0.0f);

		}
		else if (data[i].type == Wallz11)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz15);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz12)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz16);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz13)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz17);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz14)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz18);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz15)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz19);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		if (data[i].type == Wallz16)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz20);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz17)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz21);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz18)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz22);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Kidong)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Pan3);
			obj->SetMaterial(0, rm->materials[40]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == KidongMom)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Pan4);
			obj->SetMaterial(0, rm->materials[41]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz19)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz23);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		if (data[i].type == Wallz20)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz24);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == GamOk_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz13_1);
			obj->SetMaterial(0, rm->materials[39]);
			//	obj->Rotate(0.0f, 0.0f, 90.0f);

		}
		else if (data[i].type == Wallz21)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz25);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz22)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz26);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz27);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz28);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz29);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz30);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz31);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz32);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz33);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz34);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz5)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz35);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz6)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz36);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz7)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz37);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz8)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz38);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz9)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz39);
			obj->SetMaterial(0, rm->materials[12]); // 바꿀 예정
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz10)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz40);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz11)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz41);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz12)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz42);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz13)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz43);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz14)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz44);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		else if (data[i].type == S_Wallz15)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz45);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz16)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz46);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz17)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz47);
			obj->SetMaterial(0, rm->materials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz18)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz48);
			obj->SetMaterial(0, rm->materials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool12)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool12);
			obj->SetMaterial(0, rm->materials[42]);
			obj->Rotate(270.0f, 0.0f, 0.0f);
		}
		else if (data[i].type == Factory_tool13)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool13);
			obj->SetMaterial(0, rm->materials[42]);
			obj->Rotate(0.0f, 90.0f, 0.0f);
		}
		else if (data[i].type == Factory_tool14)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool14);
			obj->SetMaterial(0, rm->materials[43]);

		}
		else if (data[i].type == S_Wallz19)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz49);
			obj->SetMaterial(0, rm->materials[38]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool15)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool15);
			obj->SetMaterial(0, rm->materials[44]);
			obj->Rotate(-90.0f, 0.0f, 0.0f);
		}
		else if (data[i].type == Factory_tool16)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool16);
			obj->SetMaterial(0, rm->materials[45]);
			obj->Rotate(0.0f, 0.0f, 0.0f);
		}
		else if (data[i].type == Factory_tool17)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool17);
			obj->SetMaterial(0, rm->materials[46]);

		}
		else if (data[i].type == S_Wallz20)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz50);
			obj->SetMaterial(0, rm->materials[47]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz21)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz51);
			obj->SetMaterial(0, rm->materials[47]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz22)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz52);
			obj->SetMaterial(0, rm->materials[47]);


		}
		else if (data[i].type == S_Wallz23)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz53);
			obj->SetMaterial(0, rm->materials[47]);


		}
		else if (data[i].type == S_Wallz24)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz54);
			obj->SetMaterial(0, rm->materials[47]);


		}
		else if (data[i].type == Factory_tool18)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool18);
			obj->SetMaterial(0, rm->materials[48]);

		}
		else if (data[i].type == Factory_tool19)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool19);
			obj->SetMaterial(0, rm->materials[48]);

		}
		else if (data[i].type == Factory_tool20)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool20);
			obj->SetMaterial(0, rm->materials[48]);

		}
		else if (data[i].type == S_Wallz25)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Not_ddul);
			obj->SetMaterial(0, rm->materials[49]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz26)
		{
			obj = new CGameObject(1);
			obj->SetMesh(ddul);
			obj->SetMaterial(0, rm->materials[50]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == froom_set1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Fro1);
			obj->SetMaterial(0, rm->materials[12]);
		}
		else if (data[i].type == froom_set1_3_h)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Fro2);
			obj->SetMaterial(0, rm->materials[11]);
		}
		else if (data[i].type == Top_wall1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(tpw1);
			obj->SetMaterial(0, rm->materials[51]);
		}
		else if (data[i].type == Top_wall2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(tpw2);
			obj->SetMaterial(0, rm->materials[51]);

		}
		else if (data[i].type == Janhae1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae1);
			obj->SetMaterial(0, rm->materials[52]);

		}
		else if (data[i].type == Janhae2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae2);
			obj->SetMaterial(0, rm->materials[53]);

		}
		else if (data[i].type == Janhae3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae3);
			obj->SetMaterial(0, rm->materials[54]);

		}
		else if (data[i].type == Janhae2_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae3_1);
			obj->SetMaterial(0, rm->materials[54]);

		}
		else if (data[i].type == Janhae4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae4);
			obj->SetMaterial(0, rm->materials[55]);

		}
		else if (data[i].type == Janhae5)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae5);
			obj->SetMaterial(0, rm->materials[56]);

		}
		else if (data[i].type == Janhae6)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae6);
			obj->SetMaterial(0, rm->materials[57]);

		}
		else if (data[i].type == Janhae7)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae7);
			obj->SetMaterial(0, rm->materials[57]);

		}
		else if (data[i].type == Janhae8)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae8);
			obj->SetMaterial(0, rm->materials[58]);

		}
		else if (data[i].type == Janhae9)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae9);
			obj->SetMaterial(0, rm->materials[59]);

		}
		else if (data[i].type == Janhae10)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae10);
			obj->SetMaterial(0, rm->materials[60]);

		}
		else if (data[i].type == Janhae11)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae11);
			obj->SetMaterial(0, rm->materials[61]);

		}
		else if (data[i].type == Janhae12)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae12);
			obj->SetMaterial(0, rm->materials[62]);

		}
		else if (data[i].type == Janhae13)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae13);
			obj->SetMaterial(0, rm->materials[60]);

		}
		else if (data[i].type == Janhae14)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae14);
			obj->SetMaterial(0, rm->materials[60]);

		}
		else if (data[i].type == Janhae15)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae15);
			obj->SetMaterial(0, rm->materials[62]);

		}
		else if (data[i].type == Janhae16)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae16);
			obj->SetMaterial(0, rm->materials[63]);

		}
		else if (data[i].type == Janhae17)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae17);
			obj->SetMaterial(0, rm->materials[64]);

		}
		else if (data[i].type == Janhae18)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae18);
			obj->SetMaterial(0, rm->materials[67]);

		}
		else if (data[i].type == Janhae19)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae19);
			obj->SetMaterial(0, rm->materials[68]);

		}
		else if (data[i].type == Janhae20)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae20);
			obj->SetMaterial(0, rm->materials[69]);

		}
		else if (data[i].type == Janhae21)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_janhae21);
			obj->SetMaterial(0, rm->materials[70]);

		}
		else if (data[i].type == Janhae22)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Gongjang_janhae22);
		obj->SetMaterial(0, rm->materials[71]);

		}
		else if (data[i].type == Janhae23)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Gongjang_janhae23);
		obj->SetMaterial(0, rm->materials[72]);

		}
		else if (data[i].type == didims)
		{
		obj = new CGameObject(1);
		obj->SetMesh(didimz1);
		obj->SetMaterial(0, rm->materials[40]);

		}
		else if (data[i].type == R_GyeDan1_1)// 지붕의 시작점
		{
		obj = new CGameObject(1);
		obj->SetMesh(R_GyeDan_1_1);
		//	obj->Rotate(270.0f, 0.0f, 0.0f);
		obj->SetMaterial(0, rm->materials[40]);

		}



		obj->type = data[i].type;
		obj->SetPosition(data[i].position.x, data[i].position.y, data[i].position.z);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		//obj->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * i));
		objects.push_back(obj);
	}
}

void TerrainShader::ReleaseObjects()
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
void TerrainShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			XMFLOAT3 pos = objects[i]->GetPosition();
			XMFLOAT3 camPos = pCamera->getPosition();

			XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);
			XMFLOAT3 look = pCamera->getLook();
			float px = camPos.x;
			float pz = camPos.z;
			float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

			float dist = Vector3::Length(fromCamera);
			/*
			//	1. 객체의 유형이 벽인 경우 그냥 그린다.
			//	2. 객체의 유형이 xyz 크기가 3m 이상인 대형 물체인 경우 카메라의 방향 벡터로부터 양쪽 70도 내에 있는 경우에만 그린다.
			//	3. 객체의 유형이 소형 물체, 혹은 움직이는 캐릭터인 경우 양쪽 55도 내에 있는 경우에만 그린다.
			*/
			int tp = objects[i]->type;

			float ox = objects[i]->GetPosition().x;
			float oz = objects[i]->GetPosition().z;


			if (tp >= 30000 && tp != Heaters1)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
				continue;
			}

			//1구역
			if ((px >= 0.0f && px <= 600.0f) && (pz >= 0.0f && pz <= 600.0f))
			{
				if (tp >= 10000 && tp < 11000)
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
					continue;
				}
				if (px >= 0.0f && px <= 400.0f && pz >= 0.0f && pz <= 200.0f)//1-1
				{
					if ((tp >= 11000 && tp < 11200) || (tp == Wallz6 || tp == Wallz7) || (tp == Janhae2) || (tp >= 14140 && tp <= 14146))
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if ((tp >= 11200 && tp < 11900) || (tp == Heaters1) || (tp >= 14126 && tp <= 14130) || (tp == Janhae10))
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist < 300.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
						else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(110.0f)) && dist < 10.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
					}
				}

				if (px >= 0.0f && px <= 200.0f && pz >= 200.0f && pz <= 600.0f)//1-2
				{
					if ((tp >= 12000 && tp < 12200) || (tp == GyeDans1 || tp == GyeDans2 || tp == R_GyeDan1 || tp == Stairs1))
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if ((tp >= 12200 && tp < 13000) || (tp >= 11890 && tp < 11900) || (tp == Heaters1))
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(65.0f)) && dist < 300.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
						else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(120.0f)) && dist < 15.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
					}
				}

				if (px >= 280.0f && px <= 400.0f && pz >= 200.0f && pz <= 600.0f)//1-3
				{
					if (tp >= 13000 && tp < 13200 || tp == Janhae10 || (ox >= 280.0f && ox <= 400.0f && oz >= 200.0f && oz <= 600.0f))
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if (tp >= 13200 && tp < 14000)
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(65.0f)) && dist < 300.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
						else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(110.0f)) && dist < 10.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
					}
				}

				if (px >= 400.0f && px <= 600.0f && pz >= 0.0f && pz <= 600.0f)//1-4
				{
					if (tp >= 14000 && tp < 14200)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if (tp >= 14200 && tp < 15000)
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(60.0f)) && dist < 300.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
						else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(100.0f)) && dist < 10.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
							continue;
						}
					}
				}
			}

			//2구역

			else if (px >= 800.0f && px <= 1400.0f && pz >= 0.0f && pz <= 600.0f)
			{
				//2구역공통물체
				if (tp >= 20000 && tp < 21000)
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
				//2-1
				else if ((px >= 800.0f && px <= 875.0f && pz >= 60.0f && pz <= 600.0f) || (px >= 800.0f && px <= 1050.0f && pz >= 60.0f && pz <= 150.0f))
				{
					if (tp >= 21000 && tp < 21200 || (tp >= 14000 && tp <= 14200) || tp == 14901 || tp == 14205 || tp == 10014)//그들중 큰물체는 무조건 그리고
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
					}
					else if (tp >= 21200 && tp < 22000) // 작은 물체는 카메라 방향에따라 그릴지 말지 결정.
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist <= 300.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
						}
					}
				}
				//2-2
				else if ((px >= 876.0f && px <= 1010.0f && pz >= 150.0f && pz <= 210.0f) || (px >= 876.0f && px <= 1140.0f && pz >= 210.0f && pz <= 600.0f))
				{
					if (tp >= 22000 && tp < 22200)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
					}
					else if (tp >= 22200 && tp < 23000)
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist <= 300.0f)
						{
							if (m_pd3dCbvSrvDescriptorHeap)
							{
								pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
							}
							objects[i]->Render(pd3dCommandList, pCamera);
						}
					}
				}
				//2-3
				else if ((px >= 1010.0f && px <= 1400.0f && pz >= 150.0f && pz <= 210.0f) || (px >= 1140.0f && px <= 1400.0f && pz >= 150.0f && pz <= 600.0f))
				{
					if (tp >= 23000 && tp < 23200)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
					}
					else if (tp >= 23200 && tp < 24000)
					{
						if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist <= 300.0f)
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
			//통로
			else if (px >= 600.0f && px <= 800.0f && pz >= 550.0f && pz <= 570.0f)
			{
				if ((tp >= 14000 && tp < 14200) || tp == 14901 || (tp >= 10000 && tp < 11000) || (tp >= 20000 && tp < 21200) || tp >= 30000)
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
}

D3D12_INPUT_LAYOUT_DESC TerrainShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}