#include "levelMaker.h"

vector<Object> list;

vector<BoundingBox> bList;
vector<BoundingSphere> sList;

FILE* file;

float contX = 10.0f, contY = 2.5f, contZ = 6.0f;
float boxX = 0.5f, boxY = 0.5f, boxZ = 0.5f;
float palletX = 4.0f, palletY = 2.0f, palletZ = 3.0f;
float tableX = 2.0f, tableY = 1.0f, tableZ = 1.0f;
float chairX = 0.4f, chairY = 1.2f, chairZ = 0.4f;
float barrelX = 0.5f, barrelY = 1.5f, barrelZ = 0.5f;
float trashX = 1.0f, trashY = 1.2f, trashZ = 0.6f;
float truckX = 1.8f, truckY = 2.0f, truckZ = 6.0f;

int main()
{
	createObjects(list,bList);
	
	file = fopen("result/objects.txt", "w");
	FILE* bf = fopen("result/box.txt", "w");
	//FILE* sf = fopen("result/sphere.txt", "w");


	for (int i = 0; i < list.size(); ++i)
	{
		writeFile(file, list[i]);
	}

	for (int i = 0; i < bList.size(); ++i)
	{
		writeBox(bf, bList[i]);
	}

	fclose(file);
	fclose(bf);
	return 0;
}

void createPlayer(vector<Object>& list)
{
	Object player;
	player.location = f3(100.0f, 0.85f, 100.0f);
	player.rotation = f3(0.0f, 0.0f, 0.0f);
	player.type = 1;

	list.push_back(player);
}
void createSpace(vector<Object>& list, vector<BoundingBox>& blist)
{
	//floor
	Object floors;
	floors.location = f3(0.0f, 0.0f, 0.0f);
	floors.rotation = f3(0.0f, 0.0f, 0.0f);
	floors.type = floor;

	// 다른 방 가는 통로
	Object floors_T;
	floors_T.location = f3(600.0f, 0.0f, 550.0f);
	floors_T.rotation = f3(0.0f, 0.0f, 0.0f);
	floors_T.type = floor_T;

	// 두번째 방 바닥
	Object floors_Se;
	floors_Se.location = f3(800.0f, 0.0f, 0.0f);
	floors_Se.rotation = f3(0.0f, 0.0f, 0.0f);
	floors_Se.type = floor_Se;


	list.push_back(floors);
	list.push_back(floors_T);
	list.push_back(floors_Se);

	//walls
	Object vWall1, vWall2, hWall1, hWall2;
	Object vWall1_1, vWall2_1, hWall1_1, hWall2_1;
	Object vWall_S, vWall_SM;
	Object vWall_1S, vWall_1SM;
	Object vWall_H, hWall_H, vWall_H2, hWall_H2;
	Object froom1, froom2, froom3;
	Object load_wall1_r, load_wall2_r, load_wall3_r;
	Object load_wall1_l, load_wall2_l, load_wall3_l;

	Object Se_room_l1, Se_room_l2, Se_room_l3, Se_room_r1, Se_room_r2, Se_room_r3;
	Object Se_RS1, Se_RS2, Se_RS3;
	Object Se_FB1, Se_FB2, Se_FB3;
	Object Se_FB1_1, Se_FB2_1, Se_FB3_1;

	Object Se_busok1_1, Se_busok1_2, Se_busok1_3;
	Object Se_busok2_1, Se_busok2_2, Se_busok2_3;
	Object Se_busok3_1, Se_busok3_2, Se_busok3_3;
	Object Se_busok4_1, Se_busok4_2, Se_busok4_3;
	Object Frst_LH, Frst_RH;

	Object Batchim1, Batchim2, Batchim3;
	Object Batchim_FB1, Batchim_FB2;

	Object Batchim1_1,Batchim3_1;
	Object BatFBS_1, BatFBS_2;

	Object SeBatchim1, SeBatchim3;
	Object SeBatchim_FB1, SeBatchim_FB2;
	Object SeBatchim1_1, SeBatchim3_1;
	Object SeBatFBS_1, SeBatFBS_2;

	Object Contain1, Contain2, Contain3, Contain4;
	Object JobCont;
	Object T_Cont1;
	Object B_Cont1;
	Object Celing, Celing2;
	Object Frs_WL1, Frs_WL2;
	Object added_wall_1, added_wall_2, added_wall_3, added_wall_4;

	added_wall_1.location = f3(450.0f, 0.0f, 300.0f);
	added_wall_1.rotation = f3(0.0f, 0.0f, 0.0f);
	added_wall_1.type = adds_beok1;

	added_wall_2.location = f3(450.0f, 5.0f, 300.0f);
	added_wall_2.rotation = f3(0.0f, 0.0f, 0.0f);
	added_wall_2.type = adds_beok2;

	added_wall_3.location = f3(400.0f, 0.0f, 500.0f);
	added_wall_3.rotation = f3(0.0f, 0.0f, 0.0f);
	added_wall_3.type = adds_beok1;

	added_wall_4.location = f3(400.0f, 5.0f, 500.0f);
	added_wall_4.rotation = f3(0.0f, 0.0f, 0.0f);
	added_wall_4.type = adds_beok2;

	Frs_WL1.location = f3(200.0f, 0.0f, 200.0f);
	Frs_WL1.rotation = f3(0.0f, 0.0f, 0.0f);
	Frs_WL1.type = Frs_Pons1;

	Frs_WL2.location = f3(200.0f, 5.0f, 200.0f);
	Frs_WL2.rotation = f3(0.0f, 0.0f, 0.0f);
	Frs_WL2.type = Frs_Pons2;

	Celing2.location = f3(1100.0f, 24.0f, 300.0f);
	Celing2.rotation = f3(0.0f, 0.0f, 0.0f);
	Celing2.type = Shell;

	Celing.location = f3(300.0f, 24.0f, 300.0f);
	Celing.rotation = f3(0.0f, 0.0f, 0.0f);
	Celing.type = Shell;

	B_Cont1.location = f3(1010.0f, 6.25f, 435.0f);
	B_Cont1.rotation = f3(0.0f, 0.0f, 0.0f);
	B_Cont1.type = B_Contain;

	T_Cont1.location = f3(360.0f, 2.5f, 450.0f);
	T_Cont1.rotation = f3(0.0f, 0.0f, 0.0f);
	T_Cont1.type = T_Contains;

	JobCont.location = f3(25.0f, 3.75f, 60.0f);
	JobCont.rotation = f3(0.0f, 0.0f, 0.0f);
	JobCont.type = J_Contain;

	Contain1.location = f3(50.0f, 0.0f, 425.0f);
	Contain1.rotation = f3(0.0f, 0.0f, 0.0f);
	Contain1.type = M_Contain;

	Contain2.location = f3(50.0f, 0.0f, 475.0f);
	Contain2.rotation = f3(0.0f, 0.0f, 0.0f);
	Contain2.type = M_Contain;

	Contain3.location = f3(50.0f, 0.0f, 525.0f);
	Contain3.rotation = f3(0.0f, 0.0f, 0.0f);
	Contain3.type = M_Contain;

	Contain4.location = f3(50.0f, 0.0f, 575.0f);
	Contain4.rotation = f3(0.0f, 0.0f, 0.0f);
	Contain4.type = M_Contain;


	SeBatchim1.location = f3(800.0f, 12.5f, 0.0f);
	SeBatchim1.rotation = f3(0.0f, 0.0f, 90.0f);
	SeBatchim1.type = SeBatSet1;


	SeBatchim3.location = f3(1400.0f, 12.5f, 0.0f);
	SeBatchim3.rotation = f3(0.0f, 0.0f, -90.0f);
	SeBatchim3.type = SeBatSet3;

	SeBatchim_FB1.location = f3(790.0f, 12.5f, 0.0f);
	SeBatchim_FB1.rotation = f3(-90.0f, 0.0f, 0.0f);
	SeBatchim_FB1.type = SeBat_FB_set1;

	SeBatchim_FB2.location = f3(790.0f, 12.5f, 600.0f);
	SeBatchim_FB2.rotation = f3(90.0f, 0.0f, 0.0f);
	SeBatchim_FB2.type = SeBat_FB_set2;

	SeBatchim1_1.location = f3(790.0f, 12.5f, -10.0f);
	SeBatchim1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	SeBatchim1_1.type = SeBatSet_1;

	SeBatchim3_1.location = f3(1410.0f, 12.5f, -10.0f);
	SeBatchim3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	SeBatchim3_1.type = SeBatSet_2;

	SeBatFBS_1.location = f3(790.0f, 12.5f, -10.0f);
	SeBatFBS_1.rotation = f3(0.0f, 0.0f, 0.0f);
	SeBatFBS_1.type = SeBat_FB_101; // 앞뒤 천장벽

	SeBatFBS_2.location = f3(790.0f, 12.5f, 610.0f);
	SeBatFBS_2.rotation = f3(0.0f, 0.0f, 0.0f);
	SeBatFBS_2.type = SeBat_FB_102;

	////////////////////

	BatFBS_1.location = f3(-10.0f, 12.5f, -10.0f);
	BatFBS_1.rotation = f3(0.0f, 0.0f, 0.0f);
	BatFBS_1.type = Bat_FB_101; // 앞뒤 천장벽

	BatFBS_2.location = f3(-10.0f, 12.5f, 610.0f);
	BatFBS_2.rotation = f3(0.0f, 0.0f, 0.0f);
	BatFBS_2.type = Bat_FB_102;

	Batchim1_1.location = f3(-10.0f, 12.5f, -10.0f);
	Batchim1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Batchim1_1.type = BatSet_1;

	Batchim3_1.location = f3(610.0f, 12.5f, -10.0f);
	Batchim3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Batchim3_1.type = BatSet_2;

	Batchim_FB1.location = f3(-10.0f, 12.5f, 0.0f);
	Batchim_FB1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Batchim_FB1.type = Bat_FB_set1;

	Batchim_FB2.location = f3(-10.0f, 12.5f, 600.0f);
	Batchim_FB2.rotation = f3(90.0f, 0.0f, 0.0f);
	Batchim_FB2.type = Bat_FB_set2;

	Batchim1.location = f3(0.0f, 12.5f, 0.0f);
	Batchim1.rotation = f3(0.0f, 0.0f, 90.0f);
	Batchim1.type = BatSet1;


	Batchim3.location = f3(600.0f, 12.5f, 0.0f);
	Batchim3.rotation = f3(0.0f, 0.0f, -90.0f);
	Batchim3.type = BatSet3;



	Batchim2.location = f3(600.0f, 12.5f, 550.0f);
	Batchim2.rotation = f3(0.0f, 0.0f, -90.0f);
	Batchim2.type = BatSet2;


	//
	Frst_LH.location = f3(0.0f, 5.0f, 0.0f);
	Frst_LH.rotation = f3(0.0f, 0.0f, 0.0f);
	Frst_LH.type = Frs_H;

	Frst_RH.location = f3(600.0f, 5.0f, 0.0f);
	Frst_RH.rotation = f3(0.0f, 0.0f, 0.0f);
	Frst_RH.type = Frs_H;


	// 두번째 방 부속 벽
	Se_busok1_1.location = f3(875.0f, 0.0f, 150.0f);
	Se_busok1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok1_1.type = Se_Busok1_1;

	Se_busok1_2.location = f3(875.0f, 2.5f, 150.0f);
	Se_busok1_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok1_2.type = Se_Busok1_2;

	Se_busok1_3.location = f3(875.0f, 5.0f, 150.0f);
	Se_busok1_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok1_3.type = Se_Busok1_3;

	// 345, 390
	Se_busok2_1.location = f3(1145.0f, 0.0f, 210.0f);
	Se_busok2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok2_1.type = Se_Busok2_1;

	Se_busok2_2.location = f3(1145.0f, 2.5f, 210.0f);
	Se_busok2_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok2_2.type = Se_Busok2_2;

	Se_busok2_3.location = f3(1145.0f, 5.0f, 210.0f);
	Se_busok2_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok2_3.type = Se_Busok2_3;

	// 210 ,120

	Se_busok3_1.location = f3(1010.0f, 0.0f, 150.0f);
	Se_busok3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok3_1.type = Se_Busok3_1;

	Se_busok3_2.location = f3(1010.0f, 2.5f, 150.0f);
	Se_busok3_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok3_2.type = Se_Busok3_2;

	Se_busok3_3.location = f3(1010.0f, 5.0f, 150.0f);
	Se_busok3_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok3_3.type = Se_Busok3_3;

	// x 길이 390, z는 210

	Se_busok4_1.location = f3(1010.0f, 0.0f, 150.0f);
	Se_busok4_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok4_1.type = Se_Busok4_1;

	Se_busok4_2.location = f3(1010.0f, 2.5f, 150.0f);
	Se_busok4_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok4_2.type = Se_Busok4_2;

	Se_busok4_3.location = f3(1010.0f, 5.0f, 150.0f);
	Se_busok4_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_busok4_3.type = Se_Busok4_3;


	Se_RS1.location = f3(1400.0f, 0.0f, 0.0f);
	Se_RS1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_RS1.type = Se_room_RSL;
	Se_RS2.location = f3(1400.0f, 2.5f, 0.0f);
	Se_RS2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_RS2.type = Se_room_RSM;
	Se_RS3.location = f3(1400.0f, 5.0f, 0.0f);
	Se_RS3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_RS3.type = Se_room_RSH;

	Se_FB1.location = f3(800.0f, 0.0f, 0.0f);
	Se_FB1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_FB1.type = Se_room_FBL;

	Se_FB2.location = f3(800.0f, 2.5f, 0.0f);
	Se_FB2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_FB2.type = Se_room_FBM;

	Se_FB3.location = f3(800.0f, 5.0f, 0.0f);
	Se_FB3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_FB3.type = Se_room_FBH;

	Se_FB1_1.location = f3(800.0f, 0.0f, 600.0f);
	Se_FB1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_FB1_1.type = Se_room_FBL;

	Se_FB2_1.location = f3(800.0f, 2.5f, 600.0f);
	Se_FB2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_FB2_1.type = Se_room_FBM;

	Se_FB3_1.location = f3(800.0f, 5.0f, 600.0f);
	Se_FB3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_FB3_1.type = Se_room_FBH;


	// 두번째 방 왼쪽 벽
	Se_room_l1.location = f3(800.0f, 0.0f, 0.0f);
	Se_room_l1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_room_l1.type = Se_room_L1_1;

	Se_room_l2.location = f3(800.0f, 2.5f, 0.0f);
	Se_room_l2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_room_l2.type = Se_room_L1_2;

	Se_room_l3.location = f3(800.0f, 5.0f, 0.0f);
	Se_room_l3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_room_l3.type = Se_room_L1_3;


	Se_room_r1.location = f3(800.0f, 0.0f, 570.0f);
	Se_room_r1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_room_r1.type = Se_room_R1_1;


	Se_room_r2.location = f3(800.0f, 2.5f, 570.0f);
	Se_room_r2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_room_r2.type = Se_room_R1_2;


	Se_room_r3.location = f3(800.0f, 5.0f, 570.0f);
	Se_room_r3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_room_r3.type = Se_room_R1_3;

	// 통로 벽 3개
	load_wall1_r.location = f3(600.0f, 0.0f, 550.0f);
	load_wall1_r.rotation = f3(0.0f, 0.0f, 0.0f);
	load_wall1_r.type = loadwall_l;

	load_wall2_r.location = f3(600.0f, 2.5f, 550.0f);
	load_wall2_r.rotation = f3(0.0f, 0.0f, 0.0f);
	load_wall2_r.type = loadwall_m;

	load_wall3_r.location = f3(600.0f, 5.0f, 550.0f);
	load_wall3_r.rotation = f3(0.0f, 0.0f, 0.0f);
	load_wall3_r.type = loadwall_h;

	load_wall1_l.location = f3(600.0f, 0.0f, 570.0f);
	load_wall1_l.rotation = f3(0.0f, 0.0f, 0.0f);
	load_wall1_l.type = loadwall_l;


	load_wall2_l.location = f3(600.0f, 2.5f, 570.0f);
	load_wall2_l.rotation = f3(0.0f, 0.0f, 0.0f);
	load_wall2_l.type = loadwall_m;

	load_wall3_l.location = f3(600.0f, 5.0f, 570.0f);
	load_wall3_l.rotation = f3(0.0f, 0.0f, 0.0f);
	load_wall3_l.type = loadwall_h;

	// 부속품

	froom1.location = f3(400.0f, 0.0f, 200.0f);
	froom1.rotation = f3(0.0f, 0.0f, 0.0f);
	froom1.type = froom_set;

	froom2.location = f3(400.0f, 2.5f, 200.0f);
	froom2.rotation = f3(0.0f, 0.0f, 0.0f);
	froom2.type = froom_set;

	froom3.location = f3(400.0f, 5.0f, 200.0f);
	froom3.rotation = f3(0.0f, 0.0f, 0.0f);
	froom3.type = froom_set_H;



	/////////////////////////////
	// 메인 방
	////////////////////////////

	vWall1.location = f3(0.0f, 0.0f, 0.0f);
	vWall1.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall1.type = vWalls;
	
	vWall_H.location = f3(0.0f, 5.0f, 0.0f);
	vWall_H.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall_H.type = vWalls_H;

	vWall_1S.location = f3(0.0f, 0.0f, 400.0f);
	vWall_1S.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall_1S.type = vWalls_1S;

	vWall_1SM.location = f3(0.0f, 2.5f, 400.0f);
	vWall_1SM.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall_1SM.type = vWalls_1SM;


	vWall1_1.location = f3(0.0f, 2.5f, 0.0f);
	vWall1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall1_1.type = vWalls_1; // 왼쪽 중단



	vWall2.location = f3(600.0f, 0.0f, 0.0f);
	vWall2.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall2.type = vWalls;

	vWall_H2.location = f3(600.0f, 5.0f, 0.0f);
	vWall_H2.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall_H2.type = vWalls_H;

	vWall_S.location = f3(600.0f, 0.0f, 570.0f);
	vWall_S.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall_S.type = vWalls_S;

	vWall_SM.location = f3(600.0f, 2.5f, 570.0f);
	vWall_SM.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall_SM.type = vWalls_SM;

	vWall2_1.location = f3(600.0f, 2.5f, 0.0f);
	vWall2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	vWall2_1.type = vWalls_1; // 문쪽 벽

	hWall1.location = f3(0.0f, 0.0f, 0.0f);
	hWall1.rotation = f3(0.0f, 0.0f, 0.0f);
	hWall1.type = hWalls;

	hWall1_1.location = f3(0.0f, 2.5f, 0.0f);
	hWall1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	hWall1_1.type = hWalls_1; // 상위벽

	hWall2.location = f3(0.0f, 0.0f, 600.0f);
	hWall2.rotation = f3(0.0f, 0.0f, 0.0f);
	hWall2.type = hWalls;

	hWall_H.location = f3(0.0f, 5.0f, 0.0f);
	hWall_H.rotation = f3(0.0f, 0.0f, 0.0f);
	hWall_H.type = hWalls_H;

	hWall_H2.location = f3(0.0f, 5.0f, 600.0f);
	hWall_H2.rotation = f3(0.0f, 0.0f, 0.0f);
	hWall_H2.type = hWalls_H;


	hWall2_1.location = f3(0.0f, 2.5f, 600.0f);
	hWall2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	hWall2_1.type = hWalls_1; // 상위벽

	list.push_back(vWall1);
	list.push_back(vWall2);
	list.push_back(hWall1);
	list.push_back(hWall2);

	list.push_back(vWall1_1);
	list.push_back(vWall2_1);
	list.push_back(hWall1_1);
	list.push_back(hWall2_1);
	list.push_back(vWall_S);
	list.push_back(vWall_1S);
	list.push_back(vWall_1SM);
	list.push_back(vWall_SM);
	list.push_back(vWall_H);
	list.push_back(vWall_H2);
	list.push_back(hWall_H);
	list.push_back(hWall_H2);
	list.push_back(froom1);
	list.push_back(froom2);
	list.push_back(froom3);

	list.push_back(load_wall1_l);
	list.push_back(load_wall2_l);
	list.push_back(load_wall3_l);
	list.push_back(load_wall1_r);
	list.push_back(load_wall2_r);
	list.push_back(load_wall3_r);

	list.push_back(Se_room_l1);
	list.push_back(Se_room_l2);
	list.push_back(Se_room_l3);
	list.push_back(Se_room_r1);
	list.push_back(Se_room_r2);
	list.push_back(Se_room_r3);

	list.push_back(Se_RS1);
	list.push_back(Se_RS2);
	list.push_back(Se_RS3);
	list.push_back(Se_FB1);
	list.push_back(Se_FB2);
	list.push_back(Se_FB3);
	list.push_back(Se_FB1_1);
	list.push_back(Se_FB2_1);
	list.push_back(Se_FB3_1);
	list.push_back(Se_busok1_1);
	list.push_back(Se_busok1_2);
	list.push_back(Se_busok1_3);
	list.push_back(Se_busok2_1);
	list.push_back(Se_busok2_2);
	list.push_back(Se_busok2_3);
	list.push_back(Se_busok3_1);
	list.push_back(Se_busok3_2);
	list.push_back(Se_busok3_3);
	list.push_back(Se_busok4_1);
	list.push_back(Se_busok4_2);
	list.push_back(Se_busok4_3);
	list.push_back(Frst_LH);
	list.push_back(Frst_RH);
	list.push_back(Batchim1);
	list.push_back(Batchim2);
	list.push_back(Batchim3);
	list.push_back(Batchim_FB1);
	list.push_back(Batchim_FB2);
	list.push_back(Batchim1_1);
	list.push_back(Batchim3_1);
	list.push_back(BatFBS_1);
	list.push_back(BatFBS_2);
	list.push_back(SeBatchim1);
	list.push_back(SeBatchim3);
	list.push_back(SeBatchim_FB1);
	list.push_back(SeBatchim_FB2);
	list.push_back(SeBatchim1_1);
	list.push_back(SeBatchim3_1);
	list.push_back(SeBatFBS_1);
	list.push_back(SeBatFBS_2);
	list.push_back(Contain1);
	list.push_back(Contain2);
	list.push_back(Contain3);
	list.push_back(Contain4);
	list.push_back(JobCont);
	list.push_back(T_Cont1);
	list.push_back(B_Cont1);
	list.push_back(Celing);
	list.push_back(Celing2);
	list.push_back(Frs_WL1);
	list.push_back(Frs_WL2);
	list.push_back(added_wall_1);
	list.push_back(added_wall_2);
	list.push_back(added_wall_3);
	list.push_back(added_wall_4);



	BoundingBox fl, v1, v2, h1, h2;
	BoundingBox v1_1, v2_1, h1_1, h2_1;
	BoundingBox v_s, v_sm;
	BoundingBox v_1s, v_1sm;
	BoundingBox v_H, v_H2;
	BoundingBox h_H, h_H2;
	BoundingBox fr_1, fr_2, fr_3;
	BoundingBox fl_t;
	BoundingBox lwall1_r, lwall2_r, lwall3_r;
	BoundingBox lwall1_l, lwall2_l, lwall3_l;
	BoundingBox fl_Se;
	BoundingBox Se_r_l1, Se_r_l2, Se_r_l3;
	BoundingBox Se_r_r1, Se_r_r2, Se_r_r3;
	BoundingBox Se_rs1, Se_rs2, Se_rs3;
	BoundingBox Se_fb1, Se_fb2, Se_fb3;
	BoundingBox Se_fb1_1, Se_fb2_1, Se_fb3_1;
	BoundingBox Se_bs1_1, Se_bs1_2, Se_bs1_3;
	BoundingBox Se_bs2_1, Se_bs2_2, Se_bs2_3;
	BoundingBox Se_bs3_1, Se_bs3_2, Se_bs3_3;
	BoundingBox Se_bs4_1, Se_bs4_2, Se_bs4_3;
	BoundingBox frst_lh, frst_rh;
	BoundingBox Bat_set1, Bat_set2, Bat_set3;
	BoundingBox Bat_FBS1, Bat_FBS2;
	BoundingBox Bat_set1_1, Bat_set3_1;
	BoundingBox bfbs_1, bfbs_2;
	BoundingBox SeBat_set1, SeBat_set2, SeBat_set3;
	BoundingBox SeBat_FBS1, SeBat_FBS2;
	BoundingBox SeBat_set1_1, SeBat_set3_1;
	BoundingBox Sebfbs_1, Sebfbs_2;
	BoundingBox Cons_1, Cons_2, Cons_3, Cons_4;
	BoundingBox Jc1;
	BoundingBox T_Co1;
	BoundingBox B_Co1;
	BoundingBox Cel, Cel2;
	BoundingBox Frs_WLs1, Frs_WLs2;
	BoundingBox added_W1, added_W2, added_W3, added_W4;



	//////////////////////////////////////////

	added_W1.start = f3(450.0f, 0.0f, 300.0f);
	added_W1.end = f3(550.0f, 5.0f, 300.0f);

	added_W2.start = f3(450.0f, 5.0f, 300.0f);
	added_W2.end = f3(600.0f, 12.5f, 300.0f);

	added_W3.start = f3(400.0f, 0.0f, 500.0f);
	added_W3.end = f3(550.0f, 5.0f, 500.0f);

	added_W4.start = f3(400.0f, 5.0f, 500.0f);
	added_W4.end = f3(550.0f, 12.5f, 500.0f);

	Frs_WLs1.start = f3(200.0f, 0.0f, 200.0f);
	Frs_WLs1.end = f3(200.0f, 5.0f, 600.0f);

	Frs_WLs2.start = f3(200.0f, 5.0f, 200.0f);
	Frs_WLs2.end = f3(200.0f, 12.5f, 600.0f);

	
	Cel2.start = f3(1100.0f, 22.5f, 300.0f);
	Cel2.end = f3(1420.0f, 25.5f, 620.0f);

	Cel.start = f3(300.0f, 22.5f, 300.0f);
	Cel.end = f3(620.0f, 25.5f, 620.0f);

	B_Co1.start = f3(880.0f, 0.0f, 275.0f);
	B_Co1.end = f3(1140.0f, 12.4f, 595.0f);

	T_Co1.start = f3(340.0f, 0.0f, 350.0f);
	T_Co1.end = f3(380.0f, 5.0f, 550.0f);

	Jc1.start = f3(0.0f, 0.0f, 0.0f);
	Jc1.end = f3(50.0f, 7.5f, 120.0f);


	Cons_1.start = f3(0.0f, 0.0f, 400.0f);
	Cons_1.end = f3(100.0f, 25.0f, 450.0f);


	Cons_2.start = f3(0.0f, 0.0f, 450.0f);
	Cons_2.end = f3(100.0f, 25.0f, 500.0f);

	Cons_3.start = f3(0.0f, 0.0f, 500.0f);
	Cons_3.end = f3(100.0f, 25.0f, 550.0f);

	Cons_4.start = f3(0.0f, 0.0f, 550.0f);
	Cons_4.end = f3(100.0f, 25.0f, 600.0f);


	SeBat_set1.start = f3(800.0f, 12.5f, 0.0f);
	SeBat_set1.end = f3(800.0f, 22.5f, 600.0f);

	SeBat_set3.start = f3(1400.0f, 12.5f, 0.0f);
	SeBat_set3.end = f3(1400.0f, 22.5f, 600.0f);

	SeBat_FBS1.start = f3(790.0f, 12.5f, 0.0f);
	SeBat_FBS1.end = f3(1410.0f, 22.5f, 0.0f);

	SeBat_FBS2.start = f3(790.0f, 12.5f, 600.0f);
	SeBat_FBS2.end = f3(1410.0f, 22.5f, 600.0f);

	SeBat_set1_1.start = f3(790.0f, 12.5f, -10.0f);
	SeBat_set1_1.end = f3(790.0f, 22.5f, 610.0f);

	SeBat_set3_1.start = f3(1410.0f, 12.5f, -10.0f);
	SeBat_set3_1.end = f3(1410.0f, 22.5f, 610.0f);

	Sebfbs_1.start = f3(790.0f, 12.5f, -10.0f);
	Sebfbs_1.end = f3(1410.0f, 22.5f, -10.0f);

	Sebfbs_2.start = f3(790.0f, 12.5f, 610.0f);
	Sebfbs_2.end = f3(1410.0f, 22.5f, 610.0f);

	//////////////////////////////////////////////
	bfbs_1.start = f3(-10.0f, 12.5f, -10.0f);
	bfbs_1.end = f3(610.0f, 22.5f, -10.0f);

	bfbs_2.start = f3(-10.0f, 12.5f, 610.0f);
	bfbs_2.end = f3(610.0f, 22.5f, 610.0f);


	Bat_set1_1.start = f3(-10.0f, 12.5f, -10.0f);
	Bat_set1_1.end = f3(-10.0f, 22.5f, 610.0f);

	Bat_set3_1.start = f3(610.0f, 12.5f, -10.0f);
	Bat_set3_1.end = f3(610.0f, 22.5f, 610.0f);


	Bat_FBS1.start = f3(-10.0f, 12.5f, 0.0f);
	Bat_FBS1.end = f3(610.0f, 22.5f, 0.0f);
	
	Bat_FBS2.start = f3(-10.0f, 12.5f, 600.0f);
	Bat_FBS2.end = f3(610.0f, 22.5f, 600.0f);

	Bat_set1.start = f3(0.0f, 12.5f, 0.0f);
	Bat_set1.end = f3(0.0f, 22.5f, 600.0f);

	Bat_set3.start = f3(600.0f, 12.5f, 0.0f);
	Bat_set3.end = f3(600.0f, 22.5f, 600.0f);

	///////////////////////////////////////////

	Bat_set2.start = f3(600.0f, 12.5f, 550.0f);
	Bat_set2.end = f3(600.0f, 212.5f, 570.0f); // 통로 지붕

	frst_lh.start = f3(0.0f, 5.0f, 0.0f);
	frst_lh.end = f3(0.0f, 12.5f, 600.0f);

	frst_rh.start = f3(600.0f, 5.0f, 0.0f);
	frst_rh.end = f3(600.0f, 12.5f, 600.0f);

	Se_bs4_1.start = f3(1010.0f, 0.0f, 150.0f);
	Se_bs4_1.end = f3(1400.0f, 2.5f, 150.0f);

	Se_bs4_2.start = f3(1010.0f, 2.5f, 150.0f);
	Se_bs4_2.end = f3(1400.0f, 5.0f, 150.0f);

	Se_bs4_3.start = f3(1010.0f, 5.0f, 150.0f);
	Se_bs4_3.end = f3(1400.0f, 12.5f, 150.0f);

	Se_bs3_1.start = f3(1010.0f, 0.0f, 150.0f);
	Se_bs3_1.end = f3(1010.0f, 2.5f, 270.0f);

	Se_bs3_2.start = f3(1010.0f, 2.5f, 150.0f);
	Se_bs3_2.end = f3(1010.0f, 5.0f, 270.0f);

	Se_bs3_3.start = f3(1010.0f, 5.0f, 150.0f);
	Se_bs3_3.end = f3(1010.0f, 12.5f, 270.0f);

	Se_bs2_1.start = f3(1145.0f, 0.0f, 210.0f);
	Se_bs2_1.end = f3(1145.0f, 2.5f, 600.0f);

	Se_bs2_2.start = f3(1145.0f, 2.5f, 210.0f);
	Se_bs2_2.end = f3(1145.0f, 5.0f, 600.0f);

	Se_bs2_3.start = f3(1145.0f, 5.0f, 210.0f);
	Se_bs2_3.end = f3(1145.0f, 12.5f, 600.0f);

	Se_bs1_1.start = f3(875.0f, 0.0f, 150.0f);
	Se_bs1_1.end = f3(878.0f, 2.5f, 600.0f);

	Se_bs1_2.start = f3(875.0f, 2.5f, 150.0f);
	Se_bs1_2.end = f3(878.0f, 5.0f, 600.0f);

	Se_bs1_3.start = f3(875.0f, 5.0f, 150.0f);
	Se_bs1_3.end = f3(878.0f, 12.5f, 600.0f);

	


	Se_rs1.start = f3(1400.0f, 0.0f, 0.0f);
	Se_rs1.end = f3(1400.0f, 2.5f, 600.0f);
	Se_rs2.start = f3(1400.0f, 2.5f, 0.0f);
	Se_rs2.end = f3(1400.0f, 5.0f, 600.0f);
	Se_rs3.start = f3(1400.0f, 5.0f, 0.0f);
	Se_rs3.end = f3(1400.0f, 12.5f, 600.0f);

	Se_fb1.start = f3(800.0f, 0.0f, 0.0f);
	Se_fb1.end = f3(1400.0f, 2.5f, 0.0f);
	Se_fb2.start = f3(800.0f, 2.5f, 0.0f);
	Se_fb2.end = f3(1400.0f, 5.0f, 0.0f);
	Se_fb3.start = f3(800.0f, 5.0f, 0.0f);
	Se_fb3.end = f3(1400.0f, 12.5f, 0.0f);

	Se_fb1_1.start = f3(800.0f, 0.0f, 600.0f);
	Se_fb1_1.end = f3(1400.0f, 2.5f, 600.0f);
	Se_fb2_1.start = f3(800.0f, 2.5f, 600.0f);
	Se_fb2_1.end = f3(1400.0f, 5.0f, 600.0f);
	Se_fb3_1.start = f3(800.0f, 5.0f, 600.0f);
	Se_fb3_1.end = f3(1400.0f, 12.5f, 600.0f);

	Se_r_l1.start = f3(800.0f, 0.0f, 0.0f);
	Se_r_l1.end = f3(800.0f, 2.5f, 550.0f);
	Se_r_l2.start = f3(800.0f, 2.5f, 0.0f);
	Se_r_l2.end = f3(800.0f, 5.0f, 550.0f);
	Se_r_l3.start = f3(800.0f, 5.0f, 0.0f);
	Se_r_l3.end = f3(800.0f, 12.5f, 550.0f);

	Se_r_r1.start = f3(800.0f, 0.0f, 570.0f);
	Se_r_r1.end = f3(800.0f, 2.5f, 600.0f);
	Se_r_r2.start = f3(800.0f, 2.5f, 570.0f);
	Se_r_r2.end = f3(800.0f, 5.0f, 600.0f);
	Se_r_r3.start = f3(800.0f, 5.0f, 570.0f);
	Se_r_r3.end = f3(800.0f, 12.5f, 600.0f);

	fr_1.start = f3(400.0f, 0.0f, 200.0f);
	fr_1.end = f3(400.0f, 2.5f, 600.0f);
	fr_2.start = f3(400.0f, 2.5f, 200.0f);
	fr_2.end = f3(400.0f, 5.0f, 600.0f);
	fr_3.start = f3(400.0f, 5.0f, 200.0f);
	fr_3.end = f3(400.0f, 12.5f, 600.0f);

	lwall1_r.start = f3(600.0f, 0.0f, 550.0f);
	lwall1_r.end = f3(800.0f, 2.5f, 550.0f);

	lwall2_r.start = f3(600.0f, 2.5f, 550.0f);
	lwall2_r.end = f3(800.0f, 5.0f, 550.0f);

	lwall3_r.start = f3(600.0f, 5.0f, 550.0f);
	lwall3_r.end = f3(800.0f, 12.5f, 550.0f);

	lwall1_l.start = f3(600.0f, 0.0f, 570.0f);
	lwall1_l .end = f3(800.0f, 2.5f, 570.0f);

	lwall2_l.start = f3(600.0f, 2.5f, 570.0f);
	lwall2_l.end = f3(800.0f, 5.0f, 570.0f);

	lwall3_l.start = f3(600.0f, 5.0f, 570.0f);
	lwall3_l.end = f3(800.0f, 12.5f, 570.0f);

	fl.start = f3(0.0f, -1.0f, 0.0f);
	fl.end = f3(600.0f, 0.0f, 600.0f);

	fl_t.start = f3(600.0f, -1.0f, 550.0f);
	fl_t.end = f3(800.0f, 0.0f, 570.0f);

	fl_Se.start = f3(800.0f, -1.0f, 0.0f);
	fl_Se.end = f3(1400.0f, 0.0f, 600.0f);


	v1.start = f3(0.0f, 0.0f, 0.0f);
	v1.end = f3(0.0f, 2.5f, 600.0f);

	v_H.start = f3(0.0f, 5.0f, 0.0f);
	v_H.end = f3(0.0f, 12.5f, 600.0f);

	v_1s.start = f3(0.0f, 0.0f, 400.0f);
	v_1s.end = f3(0.0f, 2.5f, 600.0f);

	v_1sm.start = f3(0.0f, 2.5f, 400.0f);
	v_1sm.end = f3(0.0f, 5.0f, 600.0f);

	v2.start = f3(600.0f, 0.0f, 0.0f);
	v2.end = f3(600.0f, 2.5f, 550.0f);

	v_H2.start = f3(600.0f, 5.0f, 0.0f);
	v_H2.end = f3(600.0f, 12.5f, 600.0f);

	h1.start = f3(0.0f, 0.0f, 0.0f);
	h1.end = f3(600.0f, 2.5f, 0.0f);
	
	h_H.start = f3(0.0f, 5.0f, 0.0f);
	h_H.end = f3(600.0f, 12.5f, 0.0f);

	h2.start = f3(0.0f, 0.0f, 600.0f);
	h2.end = f3(600.0f, 2.5f, 600.0f);

	h_H2.start = f3(0.0f, 5.0f, 600.0f);
	h_H2.end = f3(600.0f, 12.5f, 600.0f);

	v1_1.start = f3(0.0f, 2.5f, 0.0f);
	v1_1.end = f3(0.0f, 5.0f, 600.0f);

	v2_1.start = f3(600.0f, 2.5f, 0.0f);
	v2_1.end = f3(600.0f, 5.0f, 550.0f);

	v_s.start = f3(600.0f, 0.0f, 570.0f);
	v_s.end = f3(600.0f, 2.5f, 600.0f);

	v_sm.start = f3(600.0f, 2.5f, 570.0f);
	v_sm.end = f3(600.0f, 5.0f, 600.0f);

	h1_1.start = f3(0.0f, 2.5f, 0.0f);
	h1_1.end = f3(600.0f, 5.0f, 0.0f);

	h2_1.start = f3(0.0f, 2.5f, 600.0f);
	h2_1.end = f3(600.0f, 5.0f, 600.0f);


	blist.push_back(fl);
	blist.push_back(v1);
	blist.push_back(v2);
	blist.push_back(h1);
	blist.push_back(h2);
	blist.push_back(v1_1);
	blist.push_back(v2_1);
	blist.push_back(h1_1);
	blist.push_back(h2_1);
	blist.push_back(v_s);
	blist.push_back(v_sm);
	blist.push_back(v_1s);
	blist.push_back(v_1sm);
	blist.push_back(v_H);
	blist.push_back(v_H2);
	blist.push_back(h_H);
	blist.push_back(h_H2);
	blist.push_back(fr_1);
	blist.push_back(fr_2);
	blist.push_back(fr_3);
	blist.push_back(fl_t);
	blist.push_back(lwall1_l);
	blist.push_back(lwall2_l);
	blist.push_back(lwall3_l);
	blist.push_back(lwall1_r);
	blist.push_back(lwall2_r);
	blist.push_back(lwall3_r);
	blist.push_back(fl_Se);
	blist.push_back(Se_r_l1);
	blist.push_back(Se_r_l2);
	blist.push_back(Se_r_l3);
	blist.push_back(Se_r_r1);
	blist.push_back(Se_r_r2);
	blist.push_back(Se_r_r3);
	blist.push_back(Se_rs1);
	blist.push_back(Se_rs2);
	blist.push_back(Se_rs3);
	blist.push_back(Se_fb1);
	blist.push_back(Se_fb2);
	blist.push_back(Se_fb3);
	blist.push_back(Se_fb1_1);
	blist.push_back(Se_fb2_1);
	blist.push_back(Se_fb3_1);
	blist.push_back(Se_bs1_1);
	blist.push_back(Se_bs1_2);
	blist.push_back(Se_bs1_3);
	blist.push_back(Se_bs2_1);
	blist.push_back(Se_bs2_2);
	blist.push_back(Se_bs2_3);
	blist.push_back(Se_bs3_1);
	blist.push_back(Se_bs3_2);
	blist.push_back(Se_bs3_3);
	blist.push_back(Se_bs4_1);
	blist.push_back(Se_bs4_2);
	blist.push_back(Se_bs4_3);
	blist.push_back(frst_lh);
	blist.push_back(frst_rh);
	blist.push_back(Bat_set1);
	blist.push_back(Bat_set2);
	blist.push_back(Bat_set3);
	blist.push_back(Bat_FBS1);
	blist.push_back(Bat_FBS2);
	blist.push_back(Bat_set1_1);
	blist.push_back(Bat_set3_1);
	blist.push_back(bfbs_1);
	blist.push_back(bfbs_2);
	blist.push_back(SeBat_set1);
	blist.push_back(SeBat_set3);
	blist.push_back(SeBat_FBS1);
	blist.push_back(SeBat_FBS2);
	blist.push_back(SeBat_set1_1);
	blist.push_back(SeBat_set3_1);
	blist.push_back(Sebfbs_1);
	blist.push_back(Sebfbs_2);
	blist.push_back(Cons_1);
	blist.push_back(Cons_2);
	blist.push_back(Cons_3);
	blist.push_back(Cons_4);
	blist.push_back(Jc1);
	blist.push_back(T_Co1);
	blist.push_back(B_Co1);
	blist.push_back(Cel);
	blist.push_back(Cel2);
	blist.push_back(Frs_WLs1);
	blist.push_back(Frs_WLs2);
	blist.push_back(added_W1);
	blist.push_back(added_W2);
	blist.push_back(added_W3);
	blist.push_back(added_W4);


}

void createObjects(vector<Object>& list, vector<BoundingBox>& blist)
{
	createPlayer(list);
	createSpace(list,blist);
	 createObstacles(list, blist);
}

void createObstacles(vector<Object>& list, vector<BoundingBox>& blist)
{

	Object GyoDan;
	GyoDan.location = f3(387.5f, 2.5f, 440.0f);
	GyoDan.rotation = f3(0.0f, 0.0f, 0.0f);
	GyoDan.type = GyeDans1;

	Object GyoDan2;
	GyoDan2.location = f3(360.0f, 2.5f, 340.0f);
	GyoDan2.rotation = f3(0.0f, 0.0f, 0.0f);
	GyoDan2.type = GyeDans2;

	Object R_stair1;
	R_stair1.location = f3(940.0f, 6.25f, 262.5f);
	R_stair1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair1.type = R_GyeDan1;

	Object R_stair2;
	R_stair2.location = f3(1080.0f, 6.25f, 262.5f);
	R_stair2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair2.type = R_GyeDan1;

	Object R_stair3;
	R_stair3.location = f3(50.0f, 6.25f, 387.5f);
	R_stair3.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair3.type = R_GyeDan1;

	Object B_doorlock1;
	B_doorlock1.location = f3(600.0f, 1.25f, 560.0f);
	B_doorlock1.rotation = f3(0.0f, 0.0f, 0.0f);
	B_doorlock1.type = B_Door;

	Object B_doorlock2;
	B_doorlock2.location = f3(800.0f, 1.25f, 560.0f);
	B_doorlock2.rotation = f3(0.0f, 0.0f, 0.0f);
	B_doorlock2.type = B_Door;

	Object B_doorlock3;
	B_doorlock3.location = f3(1400.0f, 1.25f, 560.0f);
	B_doorlock3.rotation = f3(0.0f, 0.0f, 0.0f);
	B_doorlock3.type = B_Door;

	list.push_back(GyoDan);
	list.push_back(GyoDan2);
	list.push_back(R_stair1);
	list.push_back(R_stair2);
	list.push_back(R_stair3);
	list.push_back(B_doorlock1);
	list.push_back(B_doorlock2);
	list.push_back(B_doorlock3);

	BoundingBox GyoDa1;
	GyoDa1.start = f3(380.0f, 0.0f, 430.0f);
	GyoDa1.end = f3(395.0f, 5.0f, 450.0f);

	BoundingBox GyoDa2;
	GyoDa2.start = f3(352.5f, 0.0f, 330.0f);
	GyoDa2.end = f3(367.5f, 5.0f, 350.0f);

	BoundingBox R_sta1;
	R_sta1.start = f3(890.0f, 0.0f, 250.0f);
	R_sta1.end = f3(990.0f, 12.5f, 275.0f);

	BoundingBox R_sta2;
	R_sta2.start = f3(1030.0f, 0.0f, 250.0f);
	R_sta2.end = f3(1130.0f, 12.5f, 275.0f);

	BoundingBox R_sta3;
	R_sta3.start = f3(0.0f, 0.0f, 375.0f);
	R_sta3.end = f3(100.0f, 12.5f, 400.0f);

	BoundingBox B_lock1;
	B_lock1.start = f3(599.0f, 0.0f, 550.0f);
	B_lock1.end = f3(601.0f, 2.5f, 570.0f);

	BoundingBox B_lock2;
	B_lock2.start = f3(799.0f, 0.0f, 550.0f);
	B_lock2.end = f3(801.0f, 2.5f, 570.0f);

	BoundingBox B_lock3;
	B_lock3.start = f3(1399.0f, 0.0f, 550.0f);
	B_lock3.end = f3(1401.0f, 2.5f, 570.0f);




	blist.push_back(GyoDa1);
	blist.push_back(GyoDa2);
	blist.push_back(R_sta1);
	blist.push_back(R_sta2);
	blist.push_back(R_sta3);
	blist.push_back(B_lock1);
	blist.push_back(B_lock2);
	blist.push_back(B_lock3);


	/*
	Object Container1_1;
	BoundingBox Conts1_1;

	Container1_1.location = f3(50.0f, 0.0f, 500.0f);
	Container1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Container1_1.type = Cont1_1;

	Conts1_1.start = f3(0.0f, 0.0f, 500.0f);
	Conts1_1.end = f3(100.0f, 25.0f, 600.0f);
	
	list.push_back(Container1_1);
	blist.push_back(Conts1_1);
	*/

	/*
	Object container[10];
	BoundingBox contBox[10];
	for (int i = 0; i < 10; ++i)
	{
		container[i].location = f3(10.0f, 1.25f, 20.0f+50.0f*i);
		container[i].rotation = f3(0.0f, 90.0f, 0.0f);
		container[i].type = CONTAINER;

		contBox[i].start = f3(container[i].location.x - contZ * 0.5f, container[i].location.y - contY * 0.5f, container[i].location.z - contX * 0.5f);
		contBox[i].end = f3(container[i].location.x + contZ * 0.5f, container[i].location.y + contY * 0.5f, container[i].location.z + contX * 0.5f);

		list.push_back(container[i]);
		blist.push_back(contBox[i]);
	}

	Object container2[10];
	BoundingBox contBox2[10];
	for (int i = 0; i < 10; ++i)
	{
		container2[i].location = f3(60.0f, 1.25f, 20.0f + 50.0f * i);
		container2[i].rotation = f3(0.0f, 90.0f, 0.0f);
		container2[i].type = CONTAINER;

		contBox2[i].start = f3(container2[i].location.x - contZ * 0.5f, container2[i].location.y - contY * 0.5f, container2[i].location.z - contX * 0.5f);
		contBox2[i].end = f3(container2[i].location.x + contZ * 0.5f, container2[i].location.y + contY * 0.5f, container2[i].location.z + contX * 0.5f);

		list.push_back(container2[i]);
		blist.push_back(contBox2[i]);
	}

	Object boxes[30];
	BoundingBox boxBox[30];
	for (int i = 0; i < 30; i+=3)
	{
		boxes[i].location = f3(19.5f, 0.25f, 20.0f + 50.0f * (i/3));
		boxes[i].rotation = f3(0.0f, 0.0f, 0.0f);
		boxes[i].type = BOX;

		boxes[i+1].location = f3(20.0f, 0.25f, 20.0f + 50.0f * (i/3));
		boxes[i+1].rotation = f3(0.0f, 0.0f, 0.0f);
		boxes[i+1].type = BOX;

		boxes[i+2].location = f3(19.75f, 0.75f, 20.0f + 50.0f * (i/3));
		boxes[i+2].rotation = f3(0.0f, 0.0f, 0.0f);
		boxes[i+2].type = BOX;

		boxBox[i].start = f3(boxes[i].location.x - boxX * 0.5f, boxes[i].location.y - boxY * 0.5f, boxes[i].location.z - boxZ * 0.5);
		boxBox[i].end = f3(boxes[i].location.x + boxX * 0.5f, boxes[i].location.y + boxY * 0.5f, boxes[i].location.z + boxZ * 0.5);

		boxBox[i + 1].start = f3(boxes[i + 1].location.x - boxX * 0.5f, boxes[i + 1].location.y - boxY * 0.5f, boxes[i + 1].location.z - boxZ * 0.5);
		boxBox[i+1].end = f3(boxes[i + 1].location.x + boxX * 0.5f, boxes[i + 1].location.y + boxY * 0.5f, boxes[i + 1].location.z + boxZ * 0.5);

		boxBox[i+2].start = f3(boxes[i + 2].location.x - boxX * 0.5f, boxes[i + 2].location.y - boxY * 0.5f, boxes[i + 2].location.z - boxZ * 0.5);
		boxBox[i+2].end = f3(boxes[i + 2].location.x + boxX * 0.5f, boxes[i + 2].location.y + boxY * 0.5f, boxes[i + 2].location.z + boxZ * 0.5);

		list.push_back(boxes[i]);
		list.push_back(boxes[i+1]);
		list.push_back(boxes[i+2]);

		blist.push_back(boxBox[i]);
		blist.push_back(boxBox[i+1]);
		blist.push_back(boxBox[i+2]);
	}

	Object boxes2[30];
	BoundingBox boxBox2[30];
	for (int i = 0; i < 30; i += 3)
	{
		boxes2[i].location = f3(69.5f, 0.25f, 20.0f + 50.0f * (i / 3));
		boxes2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		boxes2[i].type = BOX;

		boxes2[i + 1].location = f3(70.0f, 0.25f, 20.0f + 50.0f * (i / 3));
		boxes2[i + 1].rotation = f3(0.0f, 0.0f, 0.0f);
		boxes2[i + 1].type = BOX;

		boxes2[i + 2].location = f3(69.75f, 0.75f, 20.0f + 50.0f * (i / 3));
		boxes2[i + 2].rotation = f3(0.0f, 0.0f, 0.0f);
		boxes2[i + 2].type = BOX;

		boxBox2[i].start = f3(boxes2[i].location.x - boxX * 0.5f, boxes2[i].location.y - boxY * 0.5f, boxes2[i].location.z - boxZ * 0.5);
		boxBox2[i].end = f3(boxes2[i].location.x + boxX * 0.5f, boxes2[i].location.y + boxY * 0.5f, boxes2[i].location.z + boxZ * 0.5);

		boxBox2[i + 1].start = f3(boxes2[i + 1].location.x - boxX * 0.5f, boxes2[i + 1].location.y - boxY * 0.5f, boxes2[i + 1].location.z - boxZ * 0.5);
		boxBox2[i + 1].end = f3(boxes2[i + 1].location.x + boxX * 0.5f, boxes2[i + 1].location.y + boxY * 0.5f, boxes2[i + 1].location.z + boxZ * 0.5);

		boxBox2[i + 2].start = f3(boxes2[i + 2].location.x - boxX * 0.5f, boxes2[i + 2].location.y - boxY * 0.5f, boxes2[i + 2].location.z - boxZ * 0.5);
		boxBox2[i + 2].end = f3(boxes2[i + 2].location.x + boxX * 0.5f, boxes2[i + 2].location.y + boxY * 0.5f, boxes2[i + 2].location.z + boxZ * 0.5);

		list.push_back(boxes2[i]);
		list.push_back(boxes2[i + 1]);
		list.push_back(boxes2[i + 2]);

		blist.push_back(boxBox2[i]);
		blist.push_back(boxBox2[i + 1]);
		blist.push_back(boxBox2[i + 2]);
	}

	Object pallet[10*3];
	BoundingBox pBox[10 * 3];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			pallet[i * 3 + j].location = f3(100.0f * j + 120.0f, 0.5f, 20.0f + 50.0f * i);
			pallet[i * 3 + j].rotation = f3(-90.0f, 0.0f, 90.0f);
			pallet[i * 3 + j].type = PALLET;

			pBox[i * 3 + j].start = f3(pallet[i * 3 + j].location.x - palletX * 0.5f, pallet[i * 3 + j].location.y - palletY * 0.5f, pallet[i * 3 + j].location.z - palletZ * 0.5f);
			pBox[i * 3 + j].end = f3(pallet[i * 3 + j].location.x + palletX * 0.5f, pallet[i * 3 + j].location.y + palletY * 0.5f, pallet[i * 3 + j].location.z + palletZ * 0.5f);

			list.push_back(pallet[i * 3 + j]);
			blist.push_back(pBox[i * 3 + j]);
		}
	}
	Object garbage[100];
	BoundingBox gBox[100];

	for (int i = 0; i < 100; i += 2)
	{
		garbage[i].location = f3(450.0f, 0.5f, 10.0f * i + 15.0f);
		garbage[i].rotation = f3(-90.0f, 0.0f, 0.0f);
		garbage[i].type = TRASH;

		garbage[i+1].location = f3(455.0f, 0.5f, 10.0f * i + 15.0f);
		garbage[i+1].rotation = f3(0.0f, 0.0f, 0.0f);
		garbage[i+1].type = BARREL;

		gBox[i].start = f3(garbage[i].location.x - trashX * 0.5f, garbage[i].location.y - trashY * 0.5f, garbage[i].location.z - trashZ * 0.5f);
		gBox[i].end = f3(garbage[i].location.x + trashX * 0.5f, garbage[i].location.y + trashY * 0.5f, garbage[i].location.z + trashZ * 0.5f);

		gBox[i + 1].start = f3(garbage[i + 1].location.x - barrelX * 0.5f, garbage[i + 1].location.y - barrelY * 0.5f, garbage[i + 1].location.z - barrelZ * 0.5f);
		gBox[i + 1].end = f3(garbage[i + 1].location.x + barrelX * 0.5f, garbage[i + 1].location.y + barrelY * 0.5f, garbage[i + 1].location.z + barrelZ * 0.5f);

		list.push_back(garbage[i]);
		list.push_back(garbage[i + 1]);

		blist.push_back(gBox[i]);
		blist.push_back(gBox[i+1]);
	}
	Object truck[10];
	BoundingBox truckBox[10];
	for (int i = 0; i < 10; ++i)
	{
		truck[i].location = f3(550.0f, 0.5f, 30.0f * i + 50.0f);
		truck[i].rotation = f3(0.0f, 0.0f, 0.0f);
		truck[i].type = TRUCK;

		truckBox[i].start = f3(truck[i].location.x - truckX * 0.5f, truck[i].location.y - truckY * 0.5f, truck[i].location.z - truckZ * 0.5f);
		truckBox[i].end = f3(truck[i].location.x + truckX * 0.5f, truck[i].location.y + truckY * 0.5f, truck[i].location.z + truckZ * 0.5f);

		list.push_back(truck[i]);
		blist.push_back(truckBox[i]);
	}
	Object table[30];
	BoundingBox tableBox[30];
	for (int i = 0; i < 30; i += 3)
	{
		table[i].location = f3(170.0f, 0.5f, 30.0f + 80.0f * (i / 3));
		table[i].rotation = f3(0.0f, 90.0f, 0.0f);
		table[i].type = TABLE;

		table[i + 1].location = f3(168.0f, 0.5f, 30.0f + 80.0f * (i / 3));
		table[i + 1].rotation = f3(0.0f, 90.0f, 0.0f);
		table[i + 1].type = CHAIR;

		table[i + 2].location = f3(172.0f, 0.5f, 30.0f + 80.0f * (i / 3));
		table[i + 2].rotation = f3(0.0f, -90.0f, 0.0f);
		table[i + 2].type = CHAIR;

		tableBox[i].start = f3(table[i].location.x - tableX * 0.5f, table[i].location.y - tableY * 0.5f, table[i].location.z - tableZ * 0.5f);
		tableBox[i].end = f3(table[i].location.x + tableX * 0.5f, table[i].location.y + tableY * 0.5f, table[i].location.z + tableZ * 0.5f);

		tableBox[i + 1].start = f3(table[i + 1].location.x - chairX * 0.5f, table[i + 1].location.y - chairY * 0.5f, table[i + 1].location.z - chairZ * 0.5f);
		tableBox[i + 1].end = f3(table[i + 1].location.x + chairX * 0.5f, table[i + 1].location.y + chairY * 0.5f, table[i + 1].location.z + chairZ * 0.5f);

		tableBox[i + 2].start = f3(table[i + 2].location.x - chairX * 0.5f, table[i + 2].location.y - chairY * 0.5f, table[i + 2].location.z - chairZ * 0.5f);
		tableBox[i + 2].end = f3(table[i + 2].location.x + chairX * 0.5f, table[i + 2].location.y + chairY * 0.5f, table[i + 2].location.z + chairZ * 0.5f);

		list.push_back(table[i]);
		list.push_back(table[i+1]);
		list.push_back(table[i+2]);

		blist.push_back(tableBox[i]);
		blist.push_back(tableBox[i+1]);
		blist.push_back(tableBox[i+2]);
	}
	*/
}