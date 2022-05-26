#include "levelMaker.h"

vector<Object> list;

vector<BoundingBox> bList;
vector<BoundingSphere> sList;
vector<BoundingStair> gList;

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
	createObjects(list, bList, gList);

	file = fopen("result/Objects.txt", "w");
	FILE* bf = fopen("result/box.txt", "w");
	//FILE* sf = fopen("result/stair.txt", "w");
	//FILE* sf = fopen("result/sphere.txt", "w");


	for (int i = 0; i < list.size(); ++i)
	{
		writeFile(file, list[i]);
	}

	for (int i = 0; i < bList.size(); ++i)
	{
		writeBox(bf, bList[i]);
	}

	for (int i = 0; i < gList.size(); ++i)
	{
		//		writeStair(sf, gList[i]);
	}

	fclose(file);
	fclose(bf);
	//	fclose(sf);
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
	floors_Se.type = floor_Se; // 2번째


	list.push_back(floors);
	list.push_back(floors_T);
	list.push_back(floors_Se);

	//walls
	Object vWall1;
	Object vWall2;
	Object hWall1;
	Object hWall2;
	Object vWall1_1;
	Object vWall2_1;
	Object hWall1_1;
	Object hWall2_1;
	Object vWall_S;
	Object vWall_SM;
	Object vWall_1S;
	Object vWall_1SM;
	Object vWall_H;
	Object hWall_H;
	Object vWall_H2;
	Object hWall_H2;
	Object froom1;
	Object froom2;
	Object froom3;
	Object load_wall1_r;
	Object load_wall2_r;
	Object load_wall3_r;
	Object load_wall1_l;
	Object load_wall2_l;
	Object load_wall3_l;

	Object Se_room_l1;
	Object Se_room_l2;
	Object Se_room_l3;
	Object Se_room_r1;
	Object Se_room_r2;
	Object Se_room_r3;
	Object Se_RS1;
	Object Se_RS2;
	Object Se_RS3;
	Object Se_FB1;
	Object Se_FB2;
	Object Se_FB3;
	Object Se_FB1_1;
	Object Se_FB2_1;
	Object Se_FB3_1;

	Object Se_busok1_1;
	Object Se_busok1_2;
	Object Se_busok1_3;
	Object Se_busok2_1;
	Object Se_busok2_2;
	Object Se_busok2_3;
	Object Se_busok3_1;
	Object Se_busok3_2;
	Object Se_busok3_3;
	Object Se_busok4_1;
	Object Se_busok4_2;
	Object Se_busok4_3;
	Object Frst_LH;
	Object Frst_RH;

	Object Batchim1;
	Object Batchim2;
	Object Batchim3;
	Object Batchim_FB1;
	Object Batchim_FB2;

	Object Batchim1_1;
	Object Batchim3_1;
	Object BatFBS_1;
	Object BatFBS_2;

	Object SeBatchim1;
	Object SeBatchim3;
	Object SeBatchim_FB1;
	Object SeBatchim_FB2;
	Object SeBatchim1_1;
	Object SeBatchim3_1;
	Object SeBatFBS_1;
	Object SeBatFBS_2;

	Object Contain1;
	Object Contain2;
	Object Contain3;
	Object Contain4;
	Object JobCont;
	Object T_Cont1;
	Object B_Cont1;
	Object Celing;
	Object Celing2;
	Object Frs_WL1;
	Object Frs_WL2;
	Object added_wall_1;
	Object added_wall_2;
	Object added_wall_3;
	Object added_wall_4;
	Object Add_sector1_1;
	Object Add_sector1_2;
	Object Add_sector1_3;
	Object Add_sector2_1;
	Object Add_sector2_2;
	Object Add_sector2_3;
	Object Se_Addings1_1;
	Object Se_Addings1_2;
	Object Se_Addings2_1;
	Object Se_Addings2_2;
	Object Se_Addings3_1;
	Object Se_Addings3_2;

	Object Wall_Beok1;
	Object Wall_Beok2;
	Object Wall_Beok1_1;
	Object Wall_Beok2_1;
	Object Wall_Meok1; //첫방 0~200까지의 거리의 벽들 

	Object Firse_Cross1;
	Object Firse_Cross2; // 보일러방과 컨테이너, 계단 분리.

	Object Hide_wall1;
	Object Hide_wall2; // 첫방 0~200방 숨기 위한 벽
	Object Firse_Add1;
	Object Firse_Add2;
	Object Firse_Add3;
	Object Firse_Add4;
	Object Firse_Add5;

	Object ChangSal1;
	Object ChangSal2;
	Object ChangSal3;
	Object Pyoji1;
	Object Prism1;
	Object Prism2;
	Object Prism3;
	Object Prism4;
	Object Prism_l[4];
	Object Prism_r[4];
	Object Gam_Shell1;
	Object Gam_Shell2;
	Object F_de1;
	Object F_de2;
	Object F_des1;
	Object F_des2;
	Object F_dess1;
	Object F_dess2;
	Object big_wall1;
	Object big_wall2;
	Object big_wall3;
	Object big_wall4;
	Object big_wall5;
	Object big_wall6;
	Object Kidong_batchim1;
	Object Kidongs_mom;
	Object Kidong_batchim2;
	Object Kidong_batchim3;
	Object Kidong_batchim4;
	Object Kidongs_mom2;
	Object Kidong_batchim5;
	Object Kidong_batchim6;
	Object Kidongs_mom3;
	Object Dollp1;
	Object Dollp2;
	Object Dollp3;
	Object Dollp4;
	Object Dollp5;
	Object Dollp6;
	Object addes_1;
	Object addes_2;
	Object addes_3;
	Object addes_4;
	Object addes_5;
	Object addes_6;
	Object addes_7;
	Object addes_8;
	Object Se_plus1;
	Object Se_plus2;
	Object Se_plus3;
	Object Se_plus4;
	Object Se_plus5;
	Object Se_plus6;
	Object nanuki1;
	Object nanuki2;
	Object nanuki3;
	Object nanuki4;
	Object nanuki5;
	Object nanuki6;
	Object nanuki1_1;
	Object nanuki2_1;
	Object nanuki3_1;
	Object nanuki4_1;
	Object nanuki5_1;
	Object nanuki6_1;
	Object Se_Ado1;
	Object Se_Ado2;
	Object Se_Ado3;
	Object Se_Ado4;
	Object Se_Ado5;
	Object Se_Ado6;
	Object Se_Dedo1;
	Object Se_Dedo2;
	Object Se_Dedo3;
	Object Se_Dedo4;
	Object Se_Dedo5;
	Object Se_Dedo6;
	Object Se_Dedo7;
	Object Se_Dedo8;
	Object Se_Dedo9;
	Object Se_Dedo10;
	Object Add_Cheol1;
	Object Addos_1;
	Object Addos_2;
	Object Addos_3;
	Object Addos_4;
	Object Addos_5;
	Object Barigate1;
	Object Barigate2;
	Object Barigate3;
	Object Barigate4;
	Object Barigate5;
	Object Barigate6;
	Object ggokji1;
	Object ggokji2;

	ggokji1.location = f3(0.0f, 12.5f, 200.0f);
	ggokji1.rotation = f3(0.0f, 0.0f, 0.0f);
	ggokji1.type = Top_wall1;

	ggokji2.location = f3(400.0f, 12.5f, 200.0f);
	ggokji2.rotation = f3(0.0f, 0.0f, 0.0f);
	ggokji2.type = Top_wall2;


	Barigate1.location = f3(828.125f, 2.5f, 290.0f);
	Barigate1.rotation = f3(0.0f, 0.0f, 0.0f);
	Barigate1.type = S_Wallz25; // 2번째

	Barigate2.location = f3(859.375f, 2.5f, 398.0f);
	Barigate2.rotation = f3(0.0f, 0.0f, 0.0f);
	Barigate2.type = S_Wallz25;

	Barigate3.location = f3(828.125f, 2.5f, 506.0f);
	Barigate3.rotation = f3(0.0f, 0.0f, 0.0f);
	Barigate3.type = S_Wallz25;

	Barigate4.location = f3(859.375f, 2.5f, 290.0f);
	Barigate4.rotation = f3(0.0f, 0.0f, 0.0f);
	Barigate4.type = S_Wallz26;

	Barigate5.location = f3(828.125f, 2.5f, 398.0f);
	Barigate5.rotation = f3(0.0f, 0.0f, 0.0f);
	Barigate5.type = S_Wallz26;

	Barigate6.location = f3(859.375f, 2.5f, 506.0f);
	Barigate6.rotation = f3(0.0f, 0.0f, 0.0f);
	Barigate6.type = S_Wallz26;




	Addos_1.location = f3(1145.0f, 0.0f, 300.0f);
	Addos_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Addos_1.type = S_Wallz20;

	Addos_2.location = f3(1145.0f, 0.0f, 350.0f);
	Addos_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Addos_2.type = S_Wallz21;


	Addos_3.location = f3(1310.0f, 0.0f, 350.0f);
	Addos_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Addos_3.type = S_Wallz22;

	Addos_4.location = f3(1145.0f, 0.0f, 430.0f);
	Addos_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Addos_4.type = S_Wallz23;

	Addos_5.location = f3(1265.0f, 0.0f, 430.0f);
	Addos_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Addos_5.type = S_Wallz24;


	Add_Cheol1.location = f3(533.0f, 0.0f, 300.0f);
	Add_Cheol1.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_Cheol1.type = S_Wallz19;


	Se_Dedo5.location = f3(1165.0f, 0.0f, 440.0f);
	Se_Dedo5.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo5.type = SeAddings1;

	Se_Dedo6.location = f3(1165.0f, 5.0f, 440.0f);
	Se_Dedo6.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo6.type = SeAddings2;

	Se_Dedo7.location = f3(1165.0f, 0.0f, 430.0f);
	Se_Dedo7.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo7.type = S_Wallz17;

	Se_Dedo8.location = f3(1165.0f, 5.0f, 430.0f);
	Se_Dedo8.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo8.type = S_Wallz18;

	Se_Dedo9.location = f3(1265.0f, 0.0f, 430.0f);
	Se_Dedo9.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo9.type = S_Wallz17;

	Se_Dedo10.location = f3(1265.0f, 5.0f, 430.0f);
	Se_Dedo10.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo10.type = S_Wallz18;


	nanuki1_1.location = f3(1050.0f, 0.0f, 5.0f);
	nanuki1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki1_1.type = Wallz9;

	nanuki2_1.location = f3(1050.0f, 5.0f, 5.0f);
	nanuki2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki2_1.type = Wallz10;

	nanuki3_1.location = f3(1060.0f, 0.0f, 5.0f);
	nanuki3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki3_1.type = Wallz9;

	nanuki4_1.location = f3(1060.0f, 5.0f, 5.0f);
	nanuki4_1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki4_1.type = Wallz10;

	nanuki5_1.location = f3(1050.0f, 0.0f, 5.0f);
	nanuki5_1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki5_1.type = Wallz11;

	nanuki6_1.location = f3(1050.0f, 5.0f, 5.0f);
	nanuki6_1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki6_1.type = Wallz12;


	nanuki1.location = f3(800.0f, 0.0f, 60.0f);
	nanuki1.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki1.type = S_Wallz5;

	nanuki2.location = f3(800.0f, 5.0f, 60.0f);
	nanuki2.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki2.type = S_Wallz6;

	nanuki3.location = f3(800.0f, 0.0f, 75.0f);
	nanuki3.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki3.type = S_Wallz5;

	nanuki4.location = f3(800.0f, 5.0f, 75.0f);
	nanuki4.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki4.type = S_Wallz6;

	nanuki5.location = f3(1050.0f, 0.0f, 60.0f);
	nanuki5.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki5.type = S_Wallz7;

	nanuki6.location = f3(1050.0f, 5.0f, 60.0f);
	nanuki6.rotation = f3(0.0f, 0.0f, 0.0f);
	nanuki6.type = S_Wallz8;


	Se_plus1.location = f3(812.5f, 0.0f, 230.0f);
	Se_plus1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_plus1.type = S_Wallz1;

	Se_plus2.location = f3(812.5f, 5.0f, 230.0f);
	Se_plus2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_plus2.type = S_Wallz2;

	Se_plus3.location = f3(800.0f, 0.0f, 230.0f);
	Se_plus3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_plus3.type = S_Wallz3;

	Se_plus4.location = f3(800.0f, 5.0f, 230.0f);
	Se_plus4.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_plus4.type = S_Wallz4;

	Se_plus5.location = f3(800.0f, 0.0f, 545.0f);
	Se_plus5.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_plus5.type = S_Wallz3;

	Se_plus6.location = f3(800.0f, 5.0f, 545.0f);
	Se_plus6.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_plus6.type = S_Wallz4;

	addes_5.location = f3(400.0f, 0.0f, 510.0f);
	addes_5.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_5.type = adds_beok1;

	addes_6.location = f3(400.0f, 5.0f, 510.0f);
	addes_6.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_6.type = adds_beok2;

	addes_7.location = f3(550.0f, 0.0f, 500.0f);
	addes_7.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_7.type = A_Wallz3;

	addes_8.location = f3(550.0f, 5.0f, 500.0f);
	addes_8.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_8.type = A_Wallz4;

	addes_1.location = f3(450.0f, 0.0f, 305.0f);
	addes_1.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_1.type = adds_beok1;

	addes_2.location = f3(450.0f, 5.0f, 305.0f);
	addes_2.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_2.type = adds_beok2;

	addes_3.location = f3(450.0f, 0.0f, 300.0f);
	addes_3.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_3.type = A_Wallz1; 

	addes_4.location = f3(450.0f, 5.0f, 300.0f);
	addes_4.rotation = f3(0.0f, 0.0f, 0.0f);
	addes_4.type = A_Wallz2;

	Dollp1.location = f3(525.0f, 0.0f, 400.0f);
	Dollp1.rotation = f3(0.0f, 0.0f, 0.0f);
	Dollp1.type = Wallz19;

	Dollp2.location = f3(525.0f, 5.0f, 400.0f);
	Dollp2.rotation = f3(0.0f, 0.0f, 0.0f);
	Dollp2.type = Wallz20;

	Dollp3.location = f3(525.0f, 0.0f, 407.5f);
	Dollp3.rotation = f3(0.0f, 0.0f, 0.0f);
	Dollp3.type = Wallz19;

	Dollp4.location = f3(525.0f, 5.0f, 407.5f);
	Dollp4.rotation = f3(0.0f, 0.0f, 0.0f);
	Dollp4.type = Wallz20;

	Dollp5.location = f3(525.0f, 0.0f, 400.0f);
	Dollp5.rotation = f3(0.0f, 0.0f, 0.0f);
	Dollp5.type = Wallz21;

	Dollp6.location = f3(525.0f, 5.0f, 400.0f);
	Dollp6.rotation = f3(0.0f, 0.0f, 0.0f);
	Dollp6.type = Wallz22;


	Kidong_batchim5.location = f3(350.0f, 0.65f, 75.0f);
	Kidong_batchim5.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidong_batchim5.type = Kidong;

	Kidong_batchim6.location = f3(350.0f, 21.85f, 75.0f);
	Kidong_batchim6.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidong_batchim6.type = Kidong;

	Kidongs_mom3.location = f3(350.0f, 11.25f, 75.0f);
	Kidongs_mom3.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidongs_mom3.type = KidongMom;

	Kidong_batchim3.location = f3(350.0f, 0.65f, 165.0f);
	Kidong_batchim3.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidong_batchim3.type = Kidong;

	Kidong_batchim4.location = f3(350.0f, 21.85f, 165.0f);
	Kidong_batchim4.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidong_batchim4.type = Kidong;

	Kidongs_mom2.location = f3(350.0f, 11.25f, 165.0f);
	Kidongs_mom2.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidongs_mom2.type = KidongMom;

	Kidongs_mom.location = f3(240.0f, 11.25f, 110.0f);
	Kidongs_mom.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidongs_mom.type = KidongMom;

	Kidong_batchim1.location = f3(240.0f, 0.65f, 110.0f);
	Kidong_batchim1.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidong_batchim1.type = Kidong;

	Kidong_batchim2.location = f3(240.0f, 21.85f, 110.0f);
	Kidong_batchim2.rotation = f3(0.0f, 0.0f, 0.0f);
	Kidong_batchim2.type = Kidong;

	big_wall1.location = f3(420.0f, 0.0f, 0.0f);
	big_wall1.rotation = f3(0.0f, 0.0f, 0.0f);
	big_wall1.type = Wallz15;

	big_wall2.location = f3(420.0f, 5.0f, 0.0f);
	big_wall2.rotation = f3(0.0f, 0.0f, 0.0f);
	big_wall2.type = Wallz16;

	big_wall3.location = f3(430.0f, 0.0f, 0.0f);
	big_wall3.rotation = f3(0.0f, 0.0f, 0.0f);
	big_wall3.type = Wallz15;

	big_wall4.location = f3(430.0f, 5.0f, 0.0f);
	big_wall4.rotation = f3(0.0f, 0.0f, 0.0f);
	big_wall4.type = Wallz16;

	big_wall5.location = f3(420.0f, 0.0f, 115.0f);
	big_wall5.rotation = f3(0.0f, 0.0f, 0.0f);
	big_wall5.type = Wallz17;

	big_wall6.location = f3(420.0f, 5.0f, 115.0f);
	big_wall6.rotation = f3(0.0f, 0.0f, 0.0f);
	big_wall6.type = Wallz18;




	F_de1.location = f3(125.0f, 0.0f, 55.0f);
	F_de1.rotation = f3(0.0f, 0.0f, 0.0f);
	F_de1.type = Wallz11;

	F_de2.location = f3(125.0f, 5.0f, 55.0f);
	F_de2.rotation = f3(0.0f, 0.0f, 0.0f);
	F_de2.type = Wallz12;

	F_des1.location = f3(130.0f, 0.0f, 55.0f);
	F_des1.rotation = f3(0.0f, 0.0f, 0.0f);
	F_des1.type = Wallz11;

	F_des2.location = f3(130.0f, 5.0f, 55.0f);
	F_des2.rotation = f3(0.0f, 0.0f, 0.0f);
	F_des2.type = Wallz12;

	F_dess1.location = f3(125.0f, 0.0f, 55.0f);
	F_dess1.rotation = f3(0.0f, 0.0f, 0.0f);
	F_dess1.type = Wallz13;

	F_dess2.location = f3(125.0f, 5.0f, 55.0f);
	F_dess2.rotation = f3(0.0f, 0.0f, 0.0f);
	F_dess2.type = Wallz14;



	Gam_Shell1.location = f3(540.0f, 13.5f, 105.0f);
	Gam_Shell1.rotation = f3(0.0f, 0.0f, 0.0f);
	Gam_Shell1.type = GamOk_Shell;

	Gam_Shell2.location = f3(540.0f, 13.5f, 30.0f);
	Gam_Shell2.rotation = f3(0.0f, 0.0f, 0.0f);
	Gam_Shell2.type = GamOk_Shell;

	for (int i = 0; i < 4; ++i)
	{
		Prism_l[i].location = f3(480.0f + (30.0f * i), 0.0f, 75.0f);
		Prism_l[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Prism_l[i].type = GamOk2;
		list.push_back(Prism_l[i]);
	}

	for (int i = 0; i < 4; ++i)
	{
		Prism_r[i].location = f3(480.0f + (30.0f * i), 0.0f, 0.01f);
		Prism_r[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Prism_r[i].type = GamOk2;
		list.push_back(Prism_r[i]);
	}

	Prism1.location = f3(480.0f, 0.0f, 135.0f);
	Prism1.rotation = f3(0.0f, 0.0f, 0.0f);
	Prism1.type = GamOk_1;

	Prism2.location = f3(480.0f, 0.0f, 75.0f);
	Prism2.rotation = f3(0.0f, 0.0f, 0.0f);
	Prism2.type = GamOk;

	Prism3.location = f3(480.0f, 0.0f, 60.0f);
	Prism3.rotation = f3(0.0f, 0.0f, 0.0f);
	Prism3.type = GamOk;

	Prism4.location = f3(480.0f, 0.0f, 0.01f);
	Prism4.rotation = f3(0.0f, 0.0f, 0.0f);
	Prism4.type = GamOk_1;




	Pyoji1.location = f3(234.0f, 8.25f, 200.0f);
	Pyoji1.rotation = f3(0.0f, 0.0f, 0.0f);
	Pyoji1.type = Pyo;

	ChangSal1.location = f3(200.0f, 0.0f, 200.0f);
	ChangSal1.rotation = f3(0.0f, 0.0f, 0.0f);
	ChangSal1.type = Chagsal1;

	ChangSal2.location = f3(235.0f, 0.0f, 200.0f);
	ChangSal2.rotation = f3(0.0f, 0.0f, 0.0f);
	ChangSal2.type = Chagsal1;

	ChangSal3.location = f3(230.0f, 0.0f, 200.0f);
	ChangSal3.rotation = f3(0.0f, 0.0f, 0.0f);
	ChangSal3.type = Chagsal2;


	Firse_Add1.location = f3(265.0f, 0.0f, 200.0f);
	Firse_Add1.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Add1.type = Wallz8;

	Firse_Add2.location = f3(265.0f, 5.0f, 200.0f);
	Firse_Add2.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Add2.type = Wallz9;

	Firse_Add3.location = f3(335.0f, 0.0f, 200.0f);
	Firse_Add3.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Add3.type = Wallz8;

	Firse_Add4.location = f3(335.0f, 5.0f, 200.0f);
	Firse_Add4.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Add4.type = Wallz9;

	Firse_Add5.location = f3(330.0f, 5.0f, 200.0f);
	Firse_Add5.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Add5.type = Wallz10;


	Hide_wall1.location = f3(45.0f, 0.0f, 265.0f);
	Hide_wall1.rotation = f3(0.0f, 0.0f, 0.0f);
	Hide_wall1.type = Wallz6;

	Hide_wall2.location = f3(45.0f, 5.0f, 265.0f);
	Hide_wall2.rotation = f3(0.0f, 0.0f, 0.0f);
	Hide_wall2.type = Wallz7;

	Firse_Cross1.location = f3(280.0f, 0.0f, 200.0f);
	Firse_Cross1.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Cross1.type = Wallz4;

	Firse_Cross2.location = f3(280.0f, 5.0f, 200.0f);
	Firse_Cross2.rotation = f3(0.0f, 0.0f, 0.0f);
	Firse_Cross2.type = Wallz5;


	Wall_Beok1.location = f3(0.0f, 0.0f, 200.0f);
	Wall_Beok1.rotation = f3(0.0f, 0.0f, 0.0f);
	Wall_Beok1.type = Wallz1;

	Wall_Beok2.location = f3(0.0f, 5.0f, 200.0f);
	Wall_Beok2.rotation = f3(0.0f, 0.0f, 0.0f);
	Wall_Beok2.type = Wallz2;

	Wall_Beok1_1.location = f3(102.5f, 0.0f, 200.0f);
	Wall_Beok1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Wall_Beok1_1.type = Wallz1;

	Wall_Beok2_1.location = f3(102.5f, 5.0f, 200.0f);
	Wall_Beok2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Wall_Beok2_1.type = Wallz2;

	Wall_Meok1.location = f3(97.5f, 5.0f, 200.0f);
	Wall_Meok1.rotation = f3(0.0f, 0.0f, 0.0f);
	Wall_Meok1.type = Wallz3;

	Se_Ado1.location = f3(1210.0f, 0.0f, 360.0f);
	Se_Ado1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Ado1.type = SeAddings1;

	Se_Ado2.location = f3(1210.0f, 5.0f, 360.0f);
	Se_Ado2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Ado2.type = SeAddings2;

	Se_Ado3.location = f3(1210.0f, 0.0f, 350.0f);
	Se_Ado3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Ado3.type = S_Wallz13;

	Se_Ado4.location = f3(1210.0f, 5.0f, 350.0f);
	Se_Ado4.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Ado4.type = S_Wallz14;

	Se_Ado5.location = f3(1310.0f, 0.0f, 350.0f);
	Se_Ado5.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Ado5.type = S_Wallz13;

	Se_Ado6.location = f3(1310.0f, 5.0f, 350.0f);
	Se_Ado6.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Ado6.type = S_Wallz14;

	Se_Addings1_1.location = f3(1210.0f, 0.0f, 350.0f);
	Se_Addings1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Addings1_1.type = SeAddings1;

	Se_Addings1_2.location = f3(1210.0f, 5.0f, 350.0f);
	Se_Addings1_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Addings1_2.type = SeAddings2; // 추가해야할 것


	Se_Addings2_1.location = f3(1165.0f, 0.0f, 430.0f);
	Se_Addings2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Addings2_1.type = SeAddings1;

	Se_Addings2_2.location = f3(1165.0f, 5.0f, 430.0f);
	Se_Addings2_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Addings2_2.type = SeAddings2;

	Se_Dedo1.location = f3(1300.0f, 0.0f, 300.0f);
	Se_Dedo1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo1.type = SeAddings1;

	Se_Dedo2.location = f3(1300.0f, 5.0f, 300.0f);
	Se_Dedo2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo2.type = SeAddings2;

	Se_Dedo3.location = f3(1300.0f, 0.0f, 290.0f);
	Se_Dedo3.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo3.type = S_Wallz15;

	Se_Dedo4.location = f3(1300.0f, 5.0f, 290.0f);
	Se_Dedo4.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Dedo4.type = S_Wallz16;



	Se_Addings3_1.location = f3(1300.0f, 0.0f, 290.0f);
	Se_Addings3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Addings3_1.type = SeAddings1;

	Se_Addings3_2.location = f3(1300.0f, 5.0f, 290.0f);
	Se_Addings3_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Se_Addings3_2.type = SeAddings2;

	Celing.location = f3(-10.0f, 22.5f, -10.0f);
	Celing.rotation = f3(0.0f, 0.0f, 0.0f);
	Celing.type = Shell;

	Celing2.location = f3(790.0f, 22.5f, -10.0f);
	Celing2.rotation = f3(0.0f, 0.0f, 0.0f);
	Celing2.type = Shell;

	Add_sector1_1.location = f3(595.0f, 8.75f, 560.0f);
	Add_sector1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_sector1_1.type = Add_squre1;

	Add_sector1_2.location = f3(595.0f, 2.5f, 571.25f);
	Add_sector1_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_sector1_2.type = Add_squre2;

	Add_sector1_3.location = f3(595.0f, 2.5f, 548.75f);
	Add_sector1_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_sector1_3.type = Add_squre2;

	Add_sector2_1.location = f3(805.0f, 8.75f, 560.0f);
	Add_sector2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_sector2_1.type = Add_squre1;

	Add_sector2_2.location = f3(805.0f, 2.5f, 571.25f);
	Add_sector2_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_sector2_2.type = Add_squre2;

	Add_sector2_3.location = f3(805.0f, 2.5f, 548.75f);
	Add_sector2_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Add_sector2_3.type = Add_squre2;

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
	Frs_WL2.type = Frs_Pons2; // 첫번째방 첫번째 부속 벽



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

	Object froom1_3;
	froom1_3.location = f3(397.5f, 0.0f, 200.0f);
	froom1_3.rotation = f3(0.0f, 0.0f, 0.0f);
	froom1_3.type = froom_set1_3;

	Object froom1_3h;
	froom1_3h.location = f3(397.5f, 5.0f, 200.0f);
	froom1_3h.rotation = f3(0.0f, 0.0f, 0.0f);
	froom1_3h.type = froom_set1_3_h;

	list.push_back(froom1_3);
	list.push_back(froom1_3h);

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
	list.push_back(Frs_WL1);
	list.push_back(Frs_WL2);
	list.push_back(added_wall_1);
	list.push_back(added_wall_2);
	list.push_back(added_wall_3);
	list.push_back(added_wall_4);
	list.push_back(Add_sector1_1);
	list.push_back(Add_sector1_2);
	list.push_back(Add_sector1_3);
	list.push_back(Add_sector2_1);
	list.push_back(Add_sector2_2);
	list.push_back(Add_sector2_3);
	list.push_back(Se_Addings1_1);
	list.push_back(Se_Addings1_2);
	list.push_back(Se_Addings2_1);
	list.push_back(Se_Addings2_2);
	list.push_back(Se_Addings3_1);
	list.push_back(Se_Addings3_2);
	list.push_back(Celing);
	list.push_back(Celing2);
	list.push_back(Wall_Beok1);
	list.push_back(Wall_Beok2);
	list.push_back(Wall_Beok1_1);
	list.push_back(Wall_Beok2_1);
	list.push_back(Wall_Meok1);
	list.push_back(Firse_Cross1);
	list.push_back(Firse_Cross2);
	list.push_back(Hide_wall1);
	list.push_back(Hide_wall2);
	list.push_back(Firse_Add1);
	list.push_back(Firse_Add2);
	list.push_back(Firse_Add3);
	list.push_back(Firse_Add4);
	list.push_back(Firse_Add5);
	list.push_back(ChangSal1);
	list.push_back(ChangSal2);
	list.push_back(ChangSal3);
	list.push_back(Pyoji1);
	list.push_back(Prism1);
	list.push_back(Prism2);
	list.push_back(Prism3);
	list.push_back(Prism4);
	list.push_back(Gam_Shell1);
	list.push_back(Gam_Shell2);
	list.push_back(F_de1);
	list.push_back(F_de2);
	list.push_back(F_des1);
	list.push_back(F_des2);
	list.push_back(F_dess1);
	list.push_back(F_dess2);
	list.push_back(big_wall1);
	list.push_back(big_wall2);
	list.push_back(big_wall3);
	list.push_back(big_wall4);
	list.push_back(big_wall5);
	list.push_back(big_wall6);
	list.push_back(Kidong_batchim1);
	list.push_back(Kidongs_mom);
	list.push_back(Kidong_batchim2);
	list.push_back(Kidong_batchim3);
	list.push_back(Kidongs_mom2);
	list.push_back(Kidong_batchim4);
	list.push_back(Kidong_batchim5);
	list.push_back(Kidongs_mom3);
	list.push_back(Kidong_batchim6);
	list.push_back(Dollp1);
	list.push_back(Dollp2);
	list.push_back(Dollp3);
	list.push_back(Dollp4);
	list.push_back(Dollp5);
	list.push_back(Dollp6);
	list.push_back(addes_1);
	list.push_back(addes_2);
	list.push_back(addes_3);
	list.push_back(addes_4);
	list.push_back(addes_5);
	list.push_back(addes_6);
	list.push_back(addes_7);
	list.push_back(addes_8);
	list.push_back(Se_plus1);
	list.push_back(Se_plus2);
	list.push_back(Se_plus3);
	list.push_back(Se_plus4);
	list.push_back(Se_plus5);
	list.push_back(Se_plus6);
	list.push_back(nanuki1);
	list.push_back(nanuki2);
	list.push_back(nanuki3);
	list.push_back(nanuki4);
	list.push_back(nanuki5);
	list.push_back(nanuki6);
	list.push_back(nanuki1_1);
	list.push_back(nanuki2_1);
	list.push_back(nanuki3_1);
	list.push_back(nanuki4_1);
	list.push_back(nanuki5_1);
	list.push_back(nanuki6_1);
	list.push_back(Se_Ado1);
	list.push_back(Se_Ado2);
	list.push_back(Se_Ado3);
	list.push_back(Se_Ado4);
	list.push_back(Se_Ado5);
	list.push_back(Se_Ado6);
	list.push_back(Se_Dedo1);
	list.push_back(Se_Dedo2);
	list.push_back(Se_Dedo3);
	list.push_back(Se_Dedo4);
	list.push_back(Se_Dedo5);
	list.push_back(Se_Dedo6);
	list.push_back(Se_Dedo7);
	list.push_back(Se_Dedo8);
	list.push_back(Se_Dedo9);
	list.push_back(Se_Dedo10);
	list.push_back(Add_Cheol1); // 추가 철창
	list.push_back(Addos_1);
	list.push_back(Addos_2);
	list.push_back(Addos_3);
	list.push_back(Addos_4);
	list.push_back(Addos_5);
	list.push_back(Barigate1);
	list.push_back(Barigate2);
	list.push_back(Barigate3);
	list.push_back(Barigate4);
	list.push_back(Barigate5);
	list.push_back(Barigate6);
	list.push_back(ggokji1);
	list.push_back(ggokji2);



	BoundingBox fl;
	BoundingBox v1;
	BoundingBox v2;
	BoundingBox h1;
	BoundingBox h2;
	BoundingBox v1_1;
	BoundingBox v2_1;
	BoundingBox h1_1;
	BoundingBox h2_1;
	BoundingBox v_s;
	BoundingBox v_sm;
	BoundingBox v_1s;
	BoundingBox v_1sm;
	BoundingBox v_H;
	BoundingBox v_H2;
	BoundingBox h_H;
	BoundingBox h_H2;
	BoundingBox fr_1;
	BoundingBox fr_2;
	BoundingBox fr_3;
	BoundingBox fl_t;
	BoundingBox lwall1_r;
	BoundingBox lwall2_r;
	BoundingBox lwall3_r;
	BoundingBox lwall1_l;
	BoundingBox lwall2_l;
	BoundingBox lwall3_l;
	BoundingBox fl_Se;
	BoundingBox Se_r_l1;
	BoundingBox Se_r_l2;
	BoundingBox Se_r_l3;
	BoundingBox Se_r_r1;
	BoundingBox Se_r_r2;
	BoundingBox Se_r_r3;
	BoundingBox Se_rs1;
	BoundingBox Se_rs2;
	BoundingBox Se_rs3;
	BoundingBox Se_fb1;
	BoundingBox Se_fb2;
	BoundingBox Se_fb3;
	BoundingBox Se_fb1_1;
	BoundingBox Se_fb2_1;
	BoundingBox Se_fb3_1;
	BoundingBox Se_bs1_1;
	BoundingBox Se_bs1_2;
	BoundingBox Se_bs1_3;
	BoundingBox Se_bs2_1;
	BoundingBox Se_bs2_2;
	BoundingBox Se_bs2_3;
	BoundingBox Se_bs3_1;
	BoundingBox Se_bs3_2;
	BoundingBox Se_bs3_3;
	BoundingBox Se_bs4_1;
	BoundingBox Se_bs4_2;
	BoundingBox Se_bs4_3;
	BoundingBox frst_lh;
	BoundingBox frst_rh;
	BoundingBox Bat_set1;
	BoundingBox Bat_set2;
	BoundingBox Bat_set3;
	BoundingBox Bat_FBS1;
	BoundingBox Bat_FBS2;
	BoundingBox Bat_set1_1;
	BoundingBox Bat_set3_1;
	BoundingBox bfbs_1;
	BoundingBox bfbs_2;
	BoundingBox SeBat_set1;
	BoundingBox SeBat_set2;
	BoundingBox SeBat_set3;
	BoundingBox SeBat_FBS1;
	BoundingBox SeBat_FBS2;
	BoundingBox SeBat_set1_1;
	BoundingBox SeBat_set3_1;
	BoundingBox Sebfbs_1;
	BoundingBox Sebfbs_2;
	BoundingBox Cons_1;
	BoundingBox Cons_2;
	BoundingBox Cons_3;
	BoundingBox Cons_4;
	BoundingBox Jc1;
	BoundingBox T_Co1;
	BoundingBox B_Co1;
	BoundingBox Cel;
	BoundingBox Cel2;
	BoundingBox Frs_WLs1;
	BoundingBox Frs_WLs2;
	BoundingBox added_W1;
	BoundingBox added_W2;
	BoundingBox added_W3;
	BoundingBox added_W4;
	BoundingBox Adder_se1_1;
	BoundingBox Adder_se1_2;
	BoundingBox Adder_se1_3;
	BoundingBox Adder_se2_1;
	BoundingBox Adder_se2_2;
	BoundingBox Adder_se2_3;
	BoundingBox SeAo1_1;
	BoundingBox SeAo1_2;
	BoundingBox SeAo2_1;
	BoundingBox SeAo2_2;
	BoundingBox SeAo3_1;
	BoundingBox SeAo3_2;
	BoundingBox wb1;
	BoundingBox wb2;
	BoundingBox wb1_1;
	BoundingBox wb2_1;
	BoundingBox wm1;
	BoundingBox Fcro1;
	BoundingBox Fcro2;
	BoundingBox HideW1;
	BoundingBox HideW2;
	BoundingBox Fadd1;
	BoundingBox Fadd2;
	BoundingBox Fadd3;
	BoundingBox Fadd4;
	BoundingBox Fadd5;
	BoundingBox Ch_s1;
	BoundingBox Ch_s2;
	BoundingBox Ch_s3;
	BoundingBox yoyoji1;
	BoundingBox Prsm1;
	BoundingBox Prsm2;
	BoundingBox Prsm3;
	BoundingBox Prsm4;
	BoundingBox Prsm_l[4];
	BoundingBox Prsm_r[4];
	BoundingBox Gam_S1;
	BoundingBox Gam_S2;
	BoundingBox des1;
	BoundingBox des2;
	BoundingBox des3;
	BoundingBox des4;
	BoundingBox des5;
	BoundingBox des6; // 시작지점 근처 벽
	BoundingBox Ken_w1;
	BoundingBox Ken_w2;
	BoundingBox Ken_w3;
	BoundingBox Ken_w4;
	BoundingBox Ken_w5;
	BoundingBox Ken_w6; // 시작지점 근처 벽2
	BoundingBox dongki; // 기둥 아랫받침
	BoundingBox dongkimom;
	BoundingBox dongki2; // 기둥 아랫받침
	BoundingBox dongki3;
	BoundingBox dongki4;
	BoundingBox dongkimom2;
	BoundingBox dongki5;
	BoundingBox dongki6;
	BoundingBox dongkimom3;
	BoundingBox Dol_w1;
	BoundingBox Dol_w2;
	BoundingBox Dol_w3;
	BoundingBox Dol_w4;
	BoundingBox Dol_w5;
	BoundingBox Dol_w6;
	BoundingBox ader1;
	BoundingBox ader2;
	BoundingBox ader3;
	BoundingBox ader4;
	BoundingBox ader5;
	BoundingBox ader6;
	BoundingBox ader7;
	BoundingBox ader8;
	BoundingBox S_plus1;
	BoundingBox S_plus2;
	BoundingBox S_plus3;
	BoundingBox S_plus4;
	BoundingBox S_plus5;
	BoundingBox S_plus6;
	BoundingBox nanuk1;
	BoundingBox nanuk2;
	BoundingBox nanuk3;
	BoundingBox nanuk4;
	BoundingBox nanuk5;
	BoundingBox nanuk6;
	BoundingBox nanuk1_1;
	BoundingBox nanuk2_1;
	BoundingBox nanuk3_1;
	BoundingBox nanuk4_1;
	BoundingBox nanuk5_1;
	BoundingBox nanuk6_1;
	BoundingBox Aop1;
	BoundingBox Aop2;
	BoundingBox Aop3;
	BoundingBox Aop4;
	BoundingBox Aop5;
	BoundingBox Aop6;
	BoundingBox Aader1;
	BoundingBox Aader2;
	BoundingBox Aader3;
	BoundingBox Aader4;
	BoundingBox Aader5;
	BoundingBox Aader6;
	BoundingBox Aader7;
	BoundingBox Aader8;
	BoundingBox Aader9;
	BoundingBox Aader10;
	BoundingBox Chuga1; // 추가 철창
	BoundingBox Adoe1;
	BoundingBox Adoe2;
	BoundingBox Adoe3;
	BoundingBox Adoe4;
	BoundingBox Adoe5;
	BoundingBox K_bari1;
	BoundingBox K_bari2;
	BoundingBox K_bari3;
	BoundingBox K_bari4;
	BoundingBox K_bari5;
	BoundingBox K_bari6;
	BoundingBox fr1_3;
	BoundingBox fr1_3_h;
	BoundingBox kkokji1;
	BoundingBox kkokji2;

	kkokji1.start = f3(0.0f, 12.5f, 200.0f);
	kkokji1.end = f3(400.0f, 20.0f, 200.0f);

	kkokji2.start = f3(400.0f, 12.5f, 200.0f);
	kkokji2.end = f3(400.0f, 20.0f, 600.0f);

	fr1_3.start = f3(397.5f, 0.0f, 200.0f);
	fr1_3.end = f3(397.5f, 5.0f, 600.0f);
	
	fr1_3_h.start = f3(397.5f, 5.0f, 200.0f);
	fr1_3_h.end = f3(397.5f, 12.5f, 600.0f);

	K_bari1.start = f3(812.5f, 0.0f, 289.0f);
	K_bari1.end = f3(843.75f, 5.0f, 291.0f);

	K_bari2.start = f3(843.75f, 0.0f, 397.0f);
	K_bari2.end = f3(875.0f, 5.0f, 399.0f);

	K_bari3.start = f3(812.5f, 0.0f, 505.0f);
	K_bari3.end = f3(843.75f, 5.0f, 507.0f);

	K_bari4.start = f3(843.75f, 0.0f, 289.0f);
	K_bari4.end = f3(875.0f, 5.0f, 291.0f);

	K_bari5.start = f3(812.5f, 0.0f, 397.0f);
	K_bari5.end = f3(843.75f, 5.0f, 399.0f);

	K_bari6.start = f3(843.75f, 0.0f, 505.0f);
	K_bari6.end = f3(875.0f, 5.0f, 507.0f);


	Adoe1.start = f3(1145.0f, 0.0f, 300.0f);
	Adoe1.end = f3(1300.0f, 12.5f, 300.0f);

	Adoe2.start = f3(1145.0f, 0.0f, 300.0f);
	Adoe2.end = f3(1210.0f, 12.5f, 300.0f);

	Adoe3.start = f3(1310.0f, 0.0f, 300.0f);
	Adoe3.end = f3(1400.0f, 12.5f, 300.0f);

	Adoe4.start = f3(1145.0f, 0.0f, 300.0f);
	Adoe4.end = f3(1165.0f, 12.5f, 300.0f);

	Adoe5.start = f3(1265.0f, 0.0f, 300.0f);
	Adoe5.end = f3(1400.0f, 12.5f, 300.0f);

	Chuga1.start = f3(540.0f, 0.0f, 300.0f);
	Chuga1.end = f3(540.0f, 12.5f, 400.0f);

	Aader1.start = f3(1300.0f, 0.0f, 300.0f);
	Aader1.end = f3(1400.0f, 5.0f, 300.0f);

	Aader2.start = f3(1300.0f, 5.0f, 300.0f);
	Aader2.end = f3(1400.0f, 12.5f, 300.0f);

	Aader3.start = f3(1300.0f, 0.0f, 290.0f);
	Aader3.end = f3(1300.0f, 5.0f, 300.0f);

	Aader4.start = f3(1300.0f, 5.0f, 290.0f);
	Aader4.end = f3(1300.0f, 12.5f, 300.0f);

	Aader5.start = f3(1165.0f, 0.0f, 440.0f);
	Aader5.end = f3(1265.0f, 5.0f, 440.0f);

	Aader6.start = f3(1165.0f, 5.0f, 440.0f);
	Aader6.end = f3(1265.0f, 12.5f, 440.0f);

	Aader7.start = f3(1165.0f, 0.0f, 430.0f);
	Aader7.end = f3(1165.0f, 5.0f, 440.0f);

	Aader8.start = f3(1165.0f, 5.0f, 430.0f);
	Aader8.end = f3(1165.0f, 12.5f, 440.0f);

	Aader9.start = f3(1265.0f, 0.0f, 430.0f);
	Aader9.end = f3(1265.0f, 5.0f, 440.0f);

	Aader10.start = f3(1265.0f, 5.0f, 430.0f);
	Aader10.end = f3(1265.0f, 12.5f, 440.0f);


	Aop1.start = f3(1210.0f, 0.0f, 360.0f);
	Aop1.end = f3(1310.0f, 5.0f, 360.0f);

	Aop2.start = f3(1210.0f, 5.0f, 360.0f);
	Aop2.end = f3(1310.0f, 12.5f, 360.0f);

	Aop3.start = f3(1210.0f, 0.0f, 350.0f);
	Aop3.end = f3(1210.0f, 5.0f, 360.0f);

	Aop4.start = f3(1210.0f, 5.0f, 350.0f);
	Aop4.end = f3(1210.0f, 12.5f, 360.0f);

	Aop5.start = f3(1310.0f, 0.0f, 350.0f);
	Aop5.end = f3(1310.0f, 5.0f, 360.0f);

	Aop6.start = f3(1310.0f, 5.0f, 350.0f);
	Aop6.end = f3(1310.0f, 12.5f, 360.0f);


	nanuk1_1.start = f3(1050.0f, 0.0f, 5.0f);
	nanuk1_1.end = f3(1050.0f, 5.0f, 150.0f);

	nanuk2_1.start = f3(1050.0f, 5.0f, 5.0f);
	nanuk2_1.end = f3(1050.0f, 12.5f, 150.0f);

	nanuk3_1.start = f3(1060.0f, 0.0f, 5.0f);
	nanuk3_1.end = f3(1060.0f, 5.0f, 150.0f);

	nanuk4_1.start = f3(1060.0f, 5.0f, 5.0f);
	nanuk4_1.end = f3(1060.0f, 12.5f, 150.0f);

	nanuk5_1.start = f3(1050.0f, 0.0f, 5.0f);
	nanuk5_1.end = f3(1060.0f, 5.0f, 5.0f);

	nanuk6_1.start = f3(1050.0f, 5.0f, 5.0f);
	nanuk6_1.end = f3(1060.0f, 12.5f, 5.0f);


	nanuk1.start = f3(800.0f, 0.0f, 60.0f);
	nanuk1.end = f3(1050.0f, 5.0f, 60.0f);

	nanuk2.start = f3(800.0f, 5.0f, 60.0f);
	nanuk2.end = f3(1050.0f, 12.5f, 60.0f);

	nanuk3.start = f3(800.0f, 0.0f, 75.0f);
	nanuk3.end = f3(1050.0f, 5.0f, 75.0f);

	nanuk4.start = f3(800.0f, 5.0f, 75.0f);
	nanuk4.end = f3(1050.0f, 12.5f, 75.0f);

	nanuk5.start = f3(1050.0f, 0.0f, 60.0f);
	nanuk5.end = f3(1050.0f, 5.0f, 75.0f);

	nanuk6.start = f3(1050.0f, 5.0f, 60.0f);
	nanuk6.end = f3(1050.0f, 12.5f, 75.0f);


	S_plus1.start = f3(812.5f, 0.0f, 230.0f);
	S_plus1.end = f3(812.5f, 5.0f, 545.0f);

	S_plus2.start = f3(812.5f, 5.0f, 230.0f);
	S_plus2.end = f3(812.5f, 12.5f, 545.0f);

	S_plus3.start = f3(800.0f, 0.0f, 230.0f);
	S_plus3.end = f3(812.5f, 5.0f, 230.0f);

	S_plus4.start = f3(800.0f, 5.0f, 230.0f);
	S_plus4.end = f3(812.5f, 12.5f, 230.0f);

	S_plus5.start = f3(800.0f, 0.0f, 545.0f);
	S_plus5.end = f3(812.5f, 5.0f, 545.0f);

	S_plus6.start = f3(800.0f, 5.0f, 545.0f);
	S_plus6.end = f3(812.5f, 12.5f, 545.0f);

	ader5.start = f3(400.0f, 0.0f, 510.0f);
	ader5.end = f3(550.0f, 5.0f, 510.0f);

	ader6.start = f3(400.0f, 5.0f, 510.0f);
	ader6.end = f3(550.0f, 12.5f, 510.0f);

	ader7.start = f3(550.0f, 0.0f, 500.0f);
	ader7.end = f3(550.0f, 5.0f, 510.0f);

	ader8.start = f3(550.0f, 5.0f, 500.0f);
	ader8.end = f3(550.0f, 12.5f, 510.0f);

	ader1.start = f3(450.0f, 0.0f, 305.0f);
	ader1.end = f3(600.0f, 5.0f, 305.0f);

	ader2.start = f3(450.0f, 5.0f, 305.0f);
	ader2.end = f3(600.0f, 12.5f, 305.0f);

	ader3.start = f3(450.0f, 0.0f, 300.0f);
	ader3.end = f3(450.0f, 5.0f, 305.0f);

	ader4.start = f3(450.0f, 5.0f, 300.0f);
	ader4.end = f3(450.0f, 12.5f, 305.0f);



	Dol_w1.start = f3(525.0f, 0.0f, 400.0f);
	Dol_w1.end = f3(600.0f, 5.0f, 400.0f);

	Dol_w2.start = f3(525.0f, 5.0f, 400.0f);
	Dol_w2.end = f3(600.0f, 12.5f, 400.0f);

	Dol_w3.start = f3(525.0f, 0.0f, 407.5f);
	Dol_w3.end = f3(600.0f, 5.0f, 407.5f);

	Dol_w4.start = f3(525.0f, 5.0f, 407.5f);
	Dol_w4.end = f3(600.0f, 12.5f, 407.5f);

	Dol_w5.start = f3(525.0f, 0.0f, 400.0f);
	Dol_w5.end = f3(525.0f, 5.0f, 407.5f);

	Dol_w6.start = f3(525.0f, 5.0f, 400.0f);
	Dol_w6.end = f3(525.0f, 12.5f, 407.5f);

	dongki5.start = f3(340.0f, 0.0f, 65.0f);
	dongki5.end = f3(360.0f, 1.3f, 85.0f);

	dongki6.start = f3(340.0f, 21.2f, 65.0f);
	dongki6.end = f3(360.0f, 22.5f, 85.0f);

	dongkimom3.start = f3(342.0f, 1.3f, 67.0f);
	dongkimom3.end = f3(358.0f, 21.2f, 83.0f);

	dongki3.start = f3(340.0f, 0.0f, 155.0f);
	dongki3.end = f3(360.0f, 1.3f, 175.0f);

	dongki4.start = f3(340.0f, 21.2f, 155.0f);
	dongki4.end = f3(360.0f, 22.5f, 175.0f);

	dongkimom2.start = f3(342.0f, 1.3f, 157.0f);
	dongkimom2.end = f3(358.0f, 21.2f, 173.0f);

	dongkimom.start = f3(232.0f, 1.3f, 102.0f);
	dongkimom.end = f3(248.0f, 21.2f, 118.0f);

	dongki.start = f3(230.0f, 0.0f, 100.0f);
	dongki.end = f3(250.0f, 1.3f, 120.0f);

	dongki2.start = f3(230.0f, 21.2f, 100.0f);
	dongki2.end = f3(250.0f, 22.5f, 120.0f);

	Ken_w1.start = f3(420.0f, 0.0f, 0.0f);
	Ken_w1.end = f3(420.0f, 5.0f, 115.0f);

	Ken_w2.start = f3(420.0f, 5.0f, 0.0f);
	Ken_w2.end = f3(420.0f, 12.5f, 115.0f);

	Ken_w3.start = f3(430.0f, 0.0f, 0.0f);
	Ken_w3.end = f3(430.0f, 5.0f, 115.0f);

	Ken_w4.start = f3(430.0f, 5.0f, 0.0f);
	Ken_w4.end = f3(430.0f, 12.5f, 115.0f);

	Ken_w5.start = f3(420.0f, 0.0f, 115.0f);
	Ken_w5.end = f3(430.0f, 5.0f, 115.0f);

	Ken_w6.start = f3(420.0f, 5.0f, 115.0f);
	Ken_w6.end = f3(430.0f, 12.5f, 115.0f);


	des1.start = f3(125.0f, 0.0f, 55.0f);
	des1.end = f3(125.0f, 5.0f, 200.0f);

	des2.start = f3(125.0f, 5.0f, 55.0f);
	des2.end = f3(125.0f, 12.5f, 200.0f);

	des3.start = f3(130.0f, 0.0f, 55.0f);
	des3.end = f3(130.0f, 5.0f, 200.0f);

	des4.start = f3(130.0f, 5.0f, 55.0f);
	des4.end = f3(130.0f, 12.5f, 200.0f);

	des5.start = f3(125.0f, 0.0f, 55.0f);
	des5.end = f3(130.0f, 5.0f, 55.0f);

	des6.start = f3(125.0f, 5.0f, 55.0f);
	des6.end = f3(130.0f, 12.5f, 55.0f);



	Gam_S1.start = f3(480.0f, 12.5f, 75.0f);
	Gam_S1.end = f3(600.0f, 14.5f, 135.0f);

	Gam_S2.start = f3(480.0f, 12.5f, 0.01f);
	Gam_S2.end = f3(600.0f, 14.5f, 60.0f);



	for (int i = 0; i < 4; ++i)
	{
		Prsm_l[i].start = f3(480.0f + (30.0f * i), 0.0f, 75.0f);
		Prsm_l[i].end = f3(480.0f + (30.0f * i), 12.5f, 135.0f);
		blist.push_back(Prsm_l[i]);

	}

	for (int i = 0; i < 4; ++i)
	{
		Prsm_r[i].start = f3(480.0f + (30.0f * i), 0.0f, 0.01f);
		Prsm_r[i].end = f3(480.0f + (30.0f * i), 12.5f, 60.0f);
		blist.push_back(Prsm_r[i]);
	}

	Prsm1.start = f3(480.0f, 0.0f, 135.0f);
	Prsm1.end = f3(600.0f, 12.5f, 135.0f);

	Prsm2.start = f3(480.0f, 0.0f, 75.0f);
	Prsm2.end = f3(600.0f, 12.5f, 75.0f);

	Prsm3.start = f3(480.0f, 0.0f, 60.0f);
	Prsm3.end = f3(600.0f, 12.5f, 60.0f);

	Prsm4.start = f3(480.0f, 0.0f, 0.01f);
	Prsm4.end = f3(600.0f, 12.5f, 0.01f);

	yoyoji1.start = f3(230.0f, 6.75f, 198.0f);
	yoyoji1.end = f3(238.0f, 9.75f, 200.0f);

	Ch_s1.start = f3(200.0f, 0.0f, 200.0f);
	Ch_s1.end = f3(230.0f, 12.5f, 200.0f);

	Ch_s2.start = f3(235.0f, 0.0f, 200.0f);
	Ch_s2.end = f3(265.0f, 12.5f, 200.0f);

	Ch_s3.start = f3(230.0f, 0.0f, 200.0f);
	Ch_s3.end = f3(235.0f, 12.5f, 200.0f);

	Fadd1.start = f3(265.0f, 0.0f, 200.0f);
	Fadd1.end = f3(330.0f, 5.0f, 200.0f);

	Fadd2.start = f3(265.0f, 5.0f, 200.0f);
	Fadd2.end = f3(330.0f, 12.5f, 200.0f);

	Fadd3.start = f3(335.0f, 0.0f, 200.0f);
	Fadd3.end = f3(400.0f, 5.0f, 200.0f);

	Fadd4.start = f3(335.0f, 5.0f, 200.0f);
	Fadd4.end = f3(400.0f, 12.5f, 200.0f);

	Fadd5.start = f3(330.0f, 5.0f, 200.0f);
	Fadd5.end = f3(335.0f, 12.5f, 200.0f);


	HideW1.start = f3(45.0f, 0.0f, 265.0f);
	HideW1.end = f3(200.0f, 5.0f, 265.0f);

	HideW2.start = f3(45.0f, 5.0f, 265.0f);
	HideW2.end = f3(200.0f, 12.5f, 265.0f);

	Fcro1.start = f3(280.0f, 0.0f, 200.0f);
	Fcro1.end = f3(280.0f, 5.0f, 600.0f);

	Fcro2.start = f3(280.0f, 5.0f, 200.0f);
	Fcro2.end = f3(280.0f, 12.5f, 600.0f);

	wb1.start = f3(0.0f, 0.0f, 200.0f);
	wb1.end = f3(97.5f, 5.0f, 200.0f);

	wb2.start = f3(0.0f, 5.0f, 200.0f);
	wb2.end = f3(97.5f, 12.5f, 200.0f);

	wb1_1.start = f3(102.5f, 0.0f, 200.0f);
	wb1_1.end = f3(200.0f, 5.0f, 200.0f);

	wb2_1.start = f3(102.5f, 5.0f, 200.0f);
	wb2_1.end = f3(200.0f, 12.5f, 200.0f);

	wm1.start = f3(97.5f, 5.0f, 200.0f);
	wm1.end = f3(102.5f, 12.5f, 200.0f);




	//////////////////////////////////////////

	SeAo1_1.start = f3(1210.0f, 0.0f, 350.0f);
	SeAo1_1.end = f3(1310.0f, 5.0f, 350.0f);

	SeAo1_2.start = f3(1210.0f, 5.0f, 350.0f);
	SeAo1_2.end = f3(1310.0f, 12.5f, 350.0f);

	SeAo2_1.start = f3(1165.0f, 0.0f, 430.0f);
	SeAo2_1.end = f3(1265.0f, 5.0f, 430.0f);

	SeAo2_2.start = f3(1165.0f, 5.0f, 430.0f);
	SeAo2_2.end = f3(1265.0f, 12.5f, 430.0f);

	SeAo3_1.start = f3(1300.0f, 0.0f, 290.0f);
	SeAo3_1.end = f3(1400.0f, 5.0f, 290.0f);

	SeAo3_2.start = f3(1300.0f, 5.0f, 290.0f);
	SeAo3_2.end = f3(1400.0f, 12.5f, 290.0f);

	Adder_se1_1.start = f3(590.0f, 5.0f, 550.0f);
	Adder_se1_1.end = f3(600.0f, 12.5f, 570.0f);

	Adder_se1_2.start = f3(590.0f, 0.0f, 570.0f);
	Adder_se1_2.end = f3(600.0f, 5.0f, 572.5f);

	Adder_se1_3.start = f3(590.0f, 0.0f, 547.5f);
	Adder_se1_3.end = f3(600.0f, 5.0f, 550.0f);

	Adder_se2_1.start = f3(800.0f, 5.0f, 550.0f);
	Adder_se2_1.end = f3(810.0f, 12.5f, 570.0f);

	Adder_se2_2.start = f3(800.0f, 0.0f, 570.0f);
	Adder_se2_2.end = f3(810.0f, 5.0f, 572.5f);

	Adder_se2_3.start = f3(800.0f, 0.0f, 547.5f);
	Adder_se2_3.end = f3(810.0f, 5.0f, 550.0f);

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


	Cel.start = f3(-10.0f, 22.5f, -10.0f);
	Cel.end = f3(610.0f, 22.5f, 610.0f);

	Cel2.start = f3(790.0f, 22.5f, -10.0f);
	Cel2.end = f3(1410.0f, 22.5f, 610.0f);


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
	lwall1_l.end = f3(800.0f, 2.5f, 570.0f);

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

	blist.push_back(Frs_WLs1);
	blist.push_back(Frs_WLs2);
	blist.push_back(added_W1);
	blist.push_back(added_W2);
	blist.push_back(added_W3);
	blist.push_back(added_W4);
	blist.push_back(Adder_se1_1);
	blist.push_back(Adder_se1_2);
	blist.push_back(Adder_se1_3);
	blist.push_back(Adder_se2_1);
	blist.push_back(Adder_se2_2);
	blist.push_back(Adder_se2_3);
	blist.push_back(SeAo1_1);
	blist.push_back(SeAo1_2);
	blist.push_back(SeAo2_1);
	blist.push_back(SeAo2_2);
	blist.push_back(SeAo3_1);
	blist.push_back(SeAo3_2);
	blist.push_back(Cel);
	blist.push_back(Cel2);
	blist.push_back(wb1);
	blist.push_back(wb2);
	blist.push_back(wb1_1);
	blist.push_back(wb2_1);
	blist.push_back(wm1);
	blist.push_back(Fcro1);
	blist.push_back(Fcro2);
	blist.push_back(HideW1);
	blist.push_back(HideW2);
	blist.push_back(Fadd1);
	blist.push_back(Fadd2);
	blist.push_back(Fadd3);
	blist.push_back(Fadd4);
	blist.push_back(Fadd5);
	blist.push_back(Ch_s1);
	blist.push_back(Ch_s2);
	blist.push_back(Ch_s3);
	blist.push_back(yoyoji1);
	blist.push_back(Prsm1);
	blist.push_back(Prsm2);
	blist.push_back(Prsm3);
	blist.push_back(Prsm4);
	blist.push_back(Gam_S1);
	blist.push_back(Gam_S2);
	blist.push_back(des1);
	blist.push_back(des2);
	blist.push_back(des3);
	blist.push_back(des4);
	blist.push_back(des5);
	blist.push_back(des6);

	blist.push_back(Ken_w1);
	blist.push_back(Ken_w2);
	blist.push_back(Ken_w3);
	blist.push_back(Ken_w4);
	blist.push_back(Ken_w5);
	blist.push_back(Ken_w6);
	blist.push_back(dongki);
	blist.push_back(dongkimom);
	blist.push_back(dongki2);
	blist.push_back(dongki3);
	blist.push_back(dongkimom2);
	blist.push_back(dongki4);
	blist.push_back(dongki5);
	blist.push_back(dongkimom3);
	blist.push_back(dongki6);
	blist.push_back(Dol_w1);
	blist.push_back(Dol_w2);
	blist.push_back(Dol_w3);
	blist.push_back(Dol_w4);
	blist.push_back(Dol_w5);
	blist.push_back(Dol_w6);
	blist.push_back(ader1);
	blist.push_back(ader2);
	blist.push_back(ader3);
	blist.push_back(ader4);
	blist.push_back(ader5);
	blist.push_back(ader6);
	blist.push_back(ader7);
	blist.push_back(ader8);
	blist.push_back(S_plus1);
	blist.push_back(S_plus2);
	blist.push_back(S_plus3);
	blist.push_back(S_plus4);
	blist.push_back(S_plus5);
	blist.push_back(S_plus6);
	blist.push_back(nanuk1);
	blist.push_back(nanuk2);
	blist.push_back(nanuk3);
	blist.push_back(nanuk4);
	blist.push_back(nanuk5);
	blist.push_back(nanuk6);
	blist.push_back(nanuk1_1);
	blist.push_back(nanuk2_1);
	blist.push_back(nanuk3_1);
	blist.push_back(nanuk4_1);
	blist.push_back(nanuk5_1);
	blist.push_back(nanuk6_1);

	blist.push_back(Aop1);
	blist.push_back(Aop2);
	blist.push_back(Aop3);
	blist.push_back(Aop4);
	blist.push_back(Aop5);
	blist.push_back(Aop6);

	blist.push_back(Aader1);
	blist.push_back(Aader2);
	blist.push_back(Aader3);
	blist.push_back(Aader4);
	blist.push_back(Aader5);
	blist.push_back(Aader6);
	blist.push_back(Aader7);
	blist.push_back(Aader8);
	blist.push_back(Aader9);
	blist.push_back(Aader10);
	blist.push_back(Chuga1);
	blist.push_back(Adoe1);
	blist.push_back(Adoe2);
	blist.push_back(Adoe3);
	blist.push_back(Adoe4);
	blist.push_back(Adoe5);
	blist.push_back(K_bari1);
	blist.push_back(K_bari2);
	blist.push_back(K_bari3);
	blist.push_back(K_bari4);
	blist.push_back(K_bari5);
	blist.push_back(K_bari6);
	blist.push_back(fr1_3);
	blist.push_back(fr1_3_h);
	blist.push_back(kkokji1);
	blist.push_back(kkokji2);



}

void createObjects(vector<Object>& list, vector<BoundingBox>& blist, vector<BoundingStair>& slist)
{
	createPlayer(list);
	createObstacles(list, blist);
	createSpace(list, blist);

	createStairBox(list, blist, slist);
}

void createStairBox(vector<Object>& list, vector<BoundingBox>& blist, vector<BoundingStair>& slist)
{








}

void createObstacles(vector<Object>& list, vector<BoundingBox>& blist)
{

	Object Janhaes1;
	Janhaes1.location = f3(290.0f, 0.0f, 135.0f);
	Janhaes1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes1.type = Janhae1;
	list.push_back(Janhaes1);
	

	Object Janhaes2;
	Janhaes2.location = f3(145.0f, 0.0f, 15.0f);
	Janhaes2.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes2.type = Janhae1;
	list.push_back(Janhaes2);

	Object Janhaes3;
	Janhaes3.location = f3(145.0f, 0.0f, 26.0f);
	Janhaes3.rotation = f3(-90.0f, -45.0f, 0.0f);
	Janhaes3.type = Janhae1;
	list.push_back(Janhaes3);

	Object Janhaes4;
	Janhaes4.location = f3(140.0f, 0.0f, 65.0f);
	Janhaes4.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes4.type = Janhae1;
	list.push_back(Janhaes4);

	Object Janhaes5;
	Janhaes5.location = f3(140.0f, 0.0f, 42.0f);
	Janhaes5.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes5.type = Janhae1;
	list.push_back(Janhaes5);

	Object Janhaes6;
	Janhaes6.location = f3(128.0f, 0.0f, 47.0f);
	Janhaes6.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes6.type = Janhae1;
	list.push_back(Janhaes6);

	Object Janhaes7;
	Janhaes7.location = f3(184.0f, 0.0f, 78.0f);
	Janhaes7.rotation = f3(-90.0f, -40.0f, 0.0f);
	Janhaes7.type = Janhae1;
	list.push_back(Janhaes7);

	Object Janhaes8;
	Janhaes8.location = f3(161.0f, 0.0f, 83.0f);
	Janhaes8.rotation = f3(-90.0f, 8.0f, 0.0f);
	Janhaes8.type = Janhae1;
	list.push_back(Janhaes8);

	Object Janhaes9;
	Janhaes9.location = f3(247.0f, 0.0f, 155.0f);
	Janhaes9.rotation = f3(-90.0f, 45.0f, 0.0f);
	Janhaes9.type = Janhae1;
	list.push_back(Janhaes9);
	
	Object Janhaes10;
	Janhaes10.location = f3(159.0f, 0.0f, 138.0f);
	Janhaes10.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes10.type = Janhae1;
	list.push_back(Janhaes10);

	Object Janhaes11;
	Janhaes11.location = f3(188.0f, 0.0f, 142.0f);
	Janhaes11.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes11.type = Janhae1;
	list.push_back(Janhaes11);



	Object Janhaes2_1;
	Janhaes2_1.location = f3(177.0f, 0.0f, 20.0f);
	Janhaes2_1.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes2_1.type = Janhae2;
	list.push_back(Janhaes2_1);

	Object Janhaes2_2;
	Janhaes2_2.location = f3(150.0f, 0.0f, 175.0f);
	Janhaes2_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes2_2.type = Janhae2;
	list.push_back(Janhaes2_2);

	Object Janhaes2_3;
	Janhaes2_3.location = f3(150.0f, 0.0f, 105.0f);
	Janhaes2_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes2_3.type = Janhae2;
	list.push_back(Janhaes2_3);

	Object Janhaes2_4;
	Janhaes2_4.location = f3(215.0f, 0.0f, 20.0f);
	Janhaes2_4.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes2_4.type = Janhae2;
	list.push_back(Janhaes2_4);

	Object Janhaes3_1_1;
	Janhaes3_1_1.location = f3(244.0f, 0.0f, 70.0f);
	Janhaes3_1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_1_1.type = Janhae2_1;
	list.push_back(Janhaes3_1_1);

	Object Janhaes3_1_2;
	Janhaes3_1_2.location = f3(211.0f, 0.0f, 65.0f);
	Janhaes3_1_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_1_2.type = Janhae2_1;
	list.push_back(Janhaes3_1_2);

	Object Janhaes3_1_3;
	Janhaes3_1_3.location = f3(152.0f, 0.0f, 64.0f);
	Janhaes3_1_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_1_3.type = Janhae2_1;
	list.push_back(Janhaes3_1_3);

	Object Janhaes3_1_4;
	Janhaes3_1_4.location = f3(95.0f, 0.0f, 305.0f);
	Janhaes3_1_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_1_4.type = Janhae2_1;
	list.push_back(Janhaes3_1_4);




	Object Janhaes3_1;
	Janhaes3_1.location = f3(196.0f, 0.0f, 115.0f);
	Janhaes3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_1.type = Janhae3;
	list.push_back(Janhaes3_1);

	Object Janhaes3_2;
	Janhaes3_2.location = f3(244.0f, 0.0f, 87.0f);
	Janhaes3_2.rotation = f3(0.0f, 32.5f, 0.0f);
	Janhaes3_2.type = Janhae3;
	list.push_back(Janhaes3_2);

	Object Janhaes3_3;
	Janhaes3_3.location = f3(259.0f, 0.0f, 166.0f);
	Janhaes3_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_3.type = Janhae3;
	list.push_back(Janhaes3_3);

	Object Janhaes3_4;
	Janhaes3_4.location = f3(199.0f, 0.0f, 180.0f);
	Janhaes3_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes3_4.type = Janhae3;
	list.push_back(Janhaes3_4);


	Object Janhaes4_1;
	Janhaes4_1.location = f3(45.0f, 0.0f, 280.0f);
	Janhaes4_1.rotation = f3(0.0f, -90.0f, 0.0f);
	Janhaes4_1.type = Janhae4;
	list.push_back(Janhaes4_1);

	Object Janhaes4_2;
	Janhaes4_2.location = f3(45.0f, 0.0f, 289.0f);
	Janhaes4_2.rotation = f3(0.0f, -90.0f, 0.0f);
	Janhaes4_2.type = Janhae4;
	list.push_back(Janhaes4_2);

	Object Janhaes5_1;
	Janhaes5_1.location = f3(66.0f, 0.25f, 292.0f);
	Janhaes5_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes5_1.type = Janhae5;
	list.push_back(Janhaes5_1);

	Object Janhaes5_2;
	Janhaes5_2.location = f3(57.0f, 0.25f, 275.0f);
	Janhaes5_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes5_2.type = Janhae5;
	list.push_back(Janhaes5_2);

	Object Janhaes5_3;
	Janhaes5_3.location = f3(75.0f, 0.7f, 275.0f);
	Janhaes5_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes5_3.type = Janhae5;
	list.push_back(Janhaes5_3);

	Object Janhaes5_4;
	Janhaes5_4.location = f3(84.0f, 0.7f, 290.0f);
	Janhaes5_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes5_4.type = Janhae5;
	list.push_back(Janhaes5_4);

	Object Janhaes6_1;
	Janhaes6_1.location = f3(80.0f, 0.0f, 325.0f);
	Janhaes6_1.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes6_1.type = Janhae6;
	list.push_back(Janhaes6_1);

	Object Janhaes6_2;
	Janhaes6_2.location = f3(86.0f, 0.0f, 325.0f);
	Janhaes6_2.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes6_2.type = Janhae6;
	list.push_back(Janhaes6_2);

	Object Janhaes7_1;
	Janhaes7_1.location = f3(78.0f, 0.0f, 283.0f);
	Janhaes7_1.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes7_1.type = Janhae7;
	list.push_back(Janhaes7_1);

	Object Janhaes7_2;
	Janhaes7_2.location = f3(112.0f, 0.0f, 330.0f);
	Janhaes7_2.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes7_2.type = Janhae7;
	list.push_back(Janhaes7_2);

	Object Janhaes7_3;
	Janhaes7_3.location = f3(133.0f, 0.0f, 319.0f);
	Janhaes7_3.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes7_3.type = Janhae7;
	list.push_back(Janhaes7_3);

	Object Janhaes7_4;
	Janhaes7_4.location = f3(128.0f, 0.0f, 347.0f);
	Janhaes7_4.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes7_4.type = Janhae7;
	list.push_back(Janhaes7_4);

	Object Janhaes7_5;
	Janhaes7_5.location = f3(36.0f, 0.0f, 310.0f);
	Janhaes7_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes7_5.type = Janhae7;
	list.push_back(Janhaes7_5);

	Object Janhaes7_6;
	Janhaes7_6.location = f3(47.0f, 0.0f, 337.0f);
	Janhaes7_6.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes7_6.type = Janhae7;
	list.push_back(Janhaes7_6);

	Object Janhaes7_7;
	Janhaes7_7.location = f3(60.0f, 0.0f, 219.0f);
	Janhaes7_7.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes7_7.type = Janhae7;
	list.push_back(Janhaes7_7);

	Object Janhaes7_8;
	Janhaes7_8.location = f3(115.0f, 0.0f, 375.0f);
	Janhaes7_8.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes7_8.type = Janhae7;
	list.push_back(Janhaes7_8);

	Object Janhaes8_1;
	Janhaes8_1.location = f3(122.0f, 0.0f, 415.0f);
	Janhaes8_1.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes8_1.type = Janhae8;
	list.push_back(Janhaes8_1);

	Object Janhaes8_2;
	Janhaes8_2.location = f3(134.0f, 0.0f, 415.0f);
	Janhaes8_2.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes8_2.type = Janhae8;
	list.push_back(Janhaes8_2);


	Object Janhaes8_3;
	Janhaes8_3.location = f3(146.0f, 0.0f, 415.0f);
	Janhaes8_3.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes8_3.type = Janhae8;
	list.push_back(Janhaes8_3);

	Object Janhaes8_4;
	Janhaes8_4.location = f3(383.0f, 0.0f, 270.0f);
	Janhaes8_4.rotation = f3(-90.0f, 180.0f, 0.0f);
	Janhaes8_4.type = Janhae8;
	list.push_back(Janhaes8_4);

	Object Janhaes8_5;
	Janhaes8_5.location = f3(383.0f, 0.0f, 280.0f);
	Janhaes8_5.rotation = f3(-90.0f, 180.0f, 0.0f);
	Janhaes8_5.type = Janhae8;
	list.push_back(Janhaes8_5);

	Object Janhaes8_6;
	Janhaes8_6.location = f3(353.0f, 0.0f, 270.0f);
	Janhaes8_6.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes8_6.type = Janhae8;
	list.push_back(Janhaes8_6);

	Object Janhaes8_7;
	Janhaes8_7.location = f3(353.0f, 0.0f, 280.0f);
	Janhaes8_7.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes8_7.type = Janhae8;
	list.push_back(Janhaes8_7);


	
	Object Janhaes9_1;
	Janhaes9_1.location = f3(280.0f, 0.0f, 40.0f);
	Janhaes9_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_1.type = Janhae9;
	list.push_back(Janhaes9_1);

	Object Janhaes9_2;
	Janhaes9_2.location = f3(280.0f, 0.0f, 52.0f);
	Janhaes9_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_2.type = Janhae9;
	list.push_back(Janhaes9_2);

	Object Janhaes9_3;
	Janhaes9_3.location = f3(280.0f, 0.0f, 64.0f);
	Janhaes9_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_3.type = Janhae9;
	list.push_back(Janhaes9_3);

	Object Janhaes9_4;
	Janhaes9_4.location = f3(280.0f, 0.0f, 76.0f);
	Janhaes9_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_4.type = Janhae9;
	list.push_back(Janhaes9_4);

	Object Janhaes9_5;
	Janhaes9_5.location = f3(280.0f, 0.0f, 88.0f);
	Janhaes9_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_5.type = Janhae9;
	list.push_back(Janhaes9_5);

	Object Janhaes9_6;
	Janhaes9_6.location = f3(280.0f, 0.0f, 100.0f);
	Janhaes9_6.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_6.type = Janhae9;
	list.push_back(Janhaes9_6);

	Object Janhaes9_7;
	Janhaes9_7.location = f3(280.0f, 0.0f, 112.0f);
	Janhaes9_7.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_7.type = Janhae9;
	list.push_back(Janhaes9_7);

	Object Janhaes9_8;
	Janhaes9_8.location = f3(280.0f, 0.0f, 124.0f);
	Janhaes9_8.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes9_8.type = Janhae9;
	list.push_back(Janhaes9_8);

	Object Janhaes10_1;
	Janhaes10_1.location = f3(345.0f, 2.75f, 215.0f);
	Janhaes10_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes10_1.type = Janhae10;
	list.push_back(Janhaes10_1);
	

	Object Janhaes10_2;
	Janhaes10_2.location = f3(365.0f, 2.75f, 230.0f);
	Janhaes10_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes10_2.type = Janhae10;
	list.push_back(Janhaes10_2);

	Object Janhaes10_3;
	Janhaes10_3.location = f3(355.0f, 2.75f, 245.0f);
	Janhaes10_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes10_3.type = Janhae10;
	list.push_back(Janhaes10_3);

	Object Janhaes11_1;
	Janhaes11_1.location = f3(367.0f, 5.0f, 388.0f);
	Janhaes11_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_1.type = Janhae11;
	list.push_back(Janhaes11_1);

	Object Janhaes11_2;
	Janhaes11_2.location = f3(363.0f, 5.0f, 375.0f);
	Janhaes11_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_2.type = Janhae11;
	list.push_back(Janhaes11_2);

	Object Janhaes11_3;
	Janhaes11_3.location = f3(353.0f, 5.0f, 358.0f);
	Janhaes11_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_3.type = Janhae11;
	list.push_back(Janhaes11_3);

	Object Janhaes11_4;
	Janhaes11_4.location = f3(353.0f, 5.0f, 379.0f);
	Janhaes11_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_4.type = Janhae11;
	list.push_back(Janhaes11_4);

	Object Janhaes11_5;
	Janhaes11_5.location = f3(353.0f, 5.0f, 390.0f);
	Janhaes11_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_5.type = Janhae11;
	list.push_back(Janhaes11_5);

	Object Janhaes11_6;
	Janhaes11_6.location = f3(435.0f, 0.0f, 390.0f);
	Janhaes11_6.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_6.type = Janhae11;
	list.push_back(Janhaes11_6);

	Object Janhaes11_7;
	Janhaes11_7.location = f3(447.0f, 0.0f, 390.0f);
	Janhaes11_7.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_7.type = Janhae11;
	list.push_back(Janhaes11_7);

	Object Janhaes11_8;
	Janhaes11_8.location = f3(459.0f, 0.0f, 390.0f);
	Janhaes11_8.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_8.type = Janhae11;
	list.push_back(Janhaes11_8);

	Object Janhaes11_9;
	Janhaes11_9.location = f3(471.0f, 0.0f, 390.0f);
	Janhaes11_9.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_9.type = Janhae11;
	list.push_back(Janhaes11_9);

	Object Janhaes11_10;
	Janhaes11_10.location = f3(483.0f, 0.0f, 390.0f);
	Janhaes11_10.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes11_10.type = Janhae11;
	list.push_back(Janhaes11_10);


	Object Janhaes12_1;
	Janhaes12_1.location = f3(469.0f, 0.0f, 175.0f);
	Janhaes12_1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_1.type = Janhae12;
	list.push_back(Janhaes12_1);

	Object Janhaes12_2;
	Janhaes12_2.location = f3(493.0f, 0.0f, 175.0f);
	Janhaes12_2.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_2.type = Janhae12;
	list.push_back(Janhaes12_2);

	Object Janhaes12_3;
	Janhaes12_3.location = f3(517.0f, 0.0f, 175.0f);
	Janhaes12_3.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_3.type = Janhae12;
	list.push_back(Janhaes12_3);

	Object Janhaes12_4;
	Janhaes12_4.location = f3(541.0f, 0.0f, 175.0f);
	Janhaes12_4.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_4.type = Janhae12;
	list.push_back(Janhaes12_4);

	Object Janhaes12_5;
	Janhaes12_5.location = f3(565.0f, 0.0f, 175.0f);
	Janhaes12_5.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_5.type = Janhae12;
	list.push_back(Janhaes12_5);



	///////////////////////////////////////////////////////////


	Object Janhaes12_6;
	Janhaes12_6.location = f3(469.0f, 0.0f, 195.0f);
	Janhaes12_6.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_6.type = Janhae12;
	list.push_back(Janhaes12_6);

	Object Janhaes12_7;
	Janhaes12_7.location = f3(493.0f, 0.0f, 195.0f);
	Janhaes12_7.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_7.type = Janhae12;
	list.push_back(Janhaes12_7);

	Object Janhaes12_8;
	Janhaes12_8.location = f3(517.0f, 0.0f, 195.0f);
	Janhaes12_8.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_8.type = Janhae12;
	list.push_back(Janhaes12_8);

	Object Janhaes12_9;
	Janhaes12_9.location = f3(541.0f, 0.0f, 195.0f);
	Janhaes12_9.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_9.type = Janhae12;
	list.push_back(Janhaes12_4);

	Object Janhaes12_10;
	Janhaes12_10.location = f3(565.0f, 0.0f, 195.0f);
	Janhaes12_10.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_10.type = Janhae12;
	list.push_back(Janhaes12_10);


	///////////////////////////////////////////////////////////////////////////////////////////

	Object Janhaes12_11;
	Janhaes12_11.location = f3(469.0f, 0.0f, 215.0f);
	Janhaes12_11.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_11.type = Janhae12;
	list.push_back(Janhaes12_11);

	Object Janhaes12_12;
	Janhaes12_12.location = f3(493.0f, 0.0f, 215.0f);
	Janhaes12_12.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_12.type = Janhae12;
	list.push_back(Janhaes12_12);

	Object Janhaes12_13;
	Janhaes12_13.location = f3(517.0f, 0.0f, 215.0f);
	Janhaes12_13.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_13.type = Janhae12;
	list.push_back(Janhaes12_13);

	Object Janhaes12_14;
	Janhaes12_14.location = f3(541.0f, 0.0f, 215.0f);
	Janhaes12_14.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_14.type = Janhae12;
	list.push_back(Janhaes12_14);

	Object Janhaes12_15;
	Janhaes12_15.location = f3(565.0f, 0.0f, 215.0f);
	Janhaes12_15.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_15.type = Janhae12;
	list.push_back(Janhaes12_15);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Object Janhaes12_16;
	Janhaes12_16.location = f3(469.0f, 0.0f, 235.0f);
	Janhaes12_16.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_16.type = Janhae12;
	list.push_back(Janhaes12_16);

	Object Janhaes12_17;
	Janhaes12_17.location = f3(493.0f, 0.0f, 235.0f);
	Janhaes12_17.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_17.type = Janhae12;
	list.push_back(Janhaes12_17);

	Object Janhaes12_18;
	Janhaes12_18.location = f3(517.0f, 0.0f, 235.0f);
	Janhaes12_18.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_18.type = Janhae12;
	list.push_back(Janhaes12_18);

	Object Janhaes12_19;
	Janhaes12_19.location = f3(541.0f, 0.0f, 235.0f);
	Janhaes12_19.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_19.type = Janhae12;
	list.push_back(Janhaes12_19);

	Object Janhaes12_20;
	Janhaes12_20.location = f3(565.0f, 0.0f, 235.0f);
	Janhaes12_20.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_20.type = Janhae12;
	list.push_back(Janhaes12_20);



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////


	Object Janhaes12_21;
	Janhaes12_21.location = f3(469.0f, 0.0f, 255.0f);
	Janhaes12_21.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_21.type = Janhae12;
	list.push_back(Janhaes12_21);

	Object Janhaes12_22;
	Janhaes12_22.location = f3(493.0f, 0.0f, 255.0f);
	Janhaes12_22.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_22.type = Janhae12;
	list.push_back(Janhaes12_22);

	Object Janhaes12_23;
	Janhaes12_23.location = f3(517.0f, 0.0f, 255.0f);
	Janhaes12_23.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_23.type = Janhae12;
	list.push_back(Janhaes12_23);

	Object Janhaes12_24;
	Janhaes12_24.location = f3(541.0f, 0.0f, 255.0f);
	Janhaes12_24.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_24.type = Janhae12;
	list.push_back(Janhaes12_24);

	Object Janhaes12_25;
	Janhaes12_25.location = f3(565.0f, 0.0f, 255.0f);
	Janhaes12_25.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes12_25.type = Janhae12;
	list.push_back(Janhaes12_25);

	///////////////////////////////////////

	Object Janhaes13_1;
	Janhaes13_1.location = f3(405.0f, 1.5f, 200.0f);
	Janhaes13_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes13_1.type = Janhae13;
	list.push_back(Janhaes13_1);

	Object Janhaes13_2;
	Janhaes13_2.location = f3(405.0f, 1.5f, 224.0f);
	Janhaes13_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes13_2.type = Janhae13;
	list.push_back(Janhaes13_2);

	Object Janhaes13_3;
	Janhaes13_3.location = f3(405.0f, 1.5f, 176.0f);
	Janhaes13_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes13_3.type = Janhae13;
	list.push_back(Janhaes13_3);

	Object Janhaes13_4;
	Janhaes13_4.location = f3(418.0f, 1.5f, 164.0f);
	Janhaes13_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes13_4.type = Janhae13;
	list.push_back(Janhaes13_4);

	Object Janhaes13_5;
	Janhaes13_5.location = f3(430.0f, 1.5f, 188.0f);
	Janhaes13_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes13_5.type = Janhae13;
	list.push_back(Janhaes13_5);

	Object Janhaes13_6;
	Janhaes13_6.location = f3(425.0f, 1.5f, 305.0f);
	Janhaes13_6.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes13_6.type = Janhae13;
	list.push_back(Janhaes13_6);

	Object Janhaes14_1;
	Janhaes14_1.location = f3(495.0f, 3.75f, 355.0f);
	Janhaes14_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes14_1.type = Janhae14;
	list.push_back(Janhaes14_1);

	Object Janhaes14_2;
	Janhaes14_2.location = f3(425.0f, 3.75f, 355.0f);
	Janhaes14_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes14_2.type = Janhae14;
	list.push_back(Janhaes14_2);

	Object Janhaes15_1;
	Janhaes15_1.location = f3(460.0f, 0.0f, 355.0f);
	Janhaes15_1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes15_1.type = Janhae15;
	list.push_back(Janhaes15_1);

	Object Janhaes16_1;
	Janhaes16_1.location = f3(97.5f, 2.5f, 200.0f);
	Janhaes16_1.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes16_1.type = Janhae16;
	list.push_back(Janhaes16_1);

	Object Janhaes16_2;
	Janhaes16_2.location = f3(330.0f, 2.5f, 200.0f);
	Janhaes16_2.rotation = f3(0.0f, 90.0f, 0.0f);
	Janhaes16_2.type = Janhae16; // 일반 문
	list.push_back(Janhaes16_2);

	Object Janhaes17_1;
	Janhaes17_1.location = f3(600.0f, 2.5f, 571.0f);
	Janhaes17_1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes17_1.type = Janhae17;
	list.push_back(Janhaes17_1); // 게이트 문

	Object Janhaes17_2;
	Janhaes17_2.location = f3(800.0f, 2.5f, 571.0f);
	Janhaes17_2.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes17_2.type = Janhae17;
	list.push_back(Janhaes17_2);


	Object Janhaes18_1;
	Janhaes18_1.location = f3(862.5f, 0.0f, 311.0f);
	Janhaes18_1.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_1.type = Janhae18;
	list.push_back(Janhaes18_1);

	Object Janhaes18_2;
	Janhaes18_2.location = f3(862.5f, 0.0f, 332.5f);
	Janhaes18_2.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_2.type = Janhae18;
	list.push_back(Janhaes18_2);

	Object Janhaes18_3;
	Janhaes18_3.location = f3(862.5f, 0.0f, 354.0f);
	Janhaes18_3.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_3.type = Janhae18;
	list.push_back(Janhaes18_3);

	Object Janhaes18_4;
	Janhaes18_4.location = f3(862.5f, 0.0f, 375.5f);
	Janhaes18_4.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_4.type = Janhae18;
	list.push_back(Janhaes18_4);

	Object Janhaes18_5;
	Janhaes18_5.location = f3(822.5f, 0.0f, 311.0f);
	Janhaes18_5.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_5.type = Janhae18;
	list.push_back(Janhaes18_5);

	Object Janhaes18_6;
	Janhaes18_6.location = f3(822.5f, 0.0f, 332.5f);
	Janhaes18_6.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_6.type = Janhae18;
	list.push_back(Janhaes18_6);

	Object Janhaes18_7;
	Janhaes18_7.location = f3(822.5f, 0.0f, 354.0f);
	Janhaes18_7.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_7.type = Janhae18;
	list.push_back(Janhaes18_7);

	Object Janhaes18_8;
	Janhaes18_8.location = f3(822.5f, 0.0f, 375.5f);
	Janhaes18_8.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_8.type = Janhae18;
	list.push_back(Janhaes18_8);

	Object Janhaes18_9;
	Janhaes18_9.location = f3(862.5f, 0.0f, 411.0f);
	Janhaes18_9.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_9.type = Janhae18;
	list.push_back(Janhaes18_9);

	Object Janhaes18_10;
	Janhaes18_10.location = f3(862.5f, 0.0f, 432.5f);
	Janhaes18_10.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_10.type = Janhae18;
	list.push_back(Janhaes18_10);

	Object Janhaes18_11;
	Janhaes18_11.location = f3(862.5f, 0.0f, 454.0f);
	Janhaes18_11.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_11.type = Janhae18;
	list.push_back(Janhaes18_11);

	Object Janhaes18_12;
	Janhaes18_12.location = f3(862.5f, 0.0f, 475.5f);
	Janhaes18_12.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_12.type = Janhae18;
	list.push_back(Janhaes18_12);

	Object Janhaes18_13;
	Janhaes18_13.location = f3(822.5f, 0.0f, 411.0f);
	Janhaes18_13.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_13.type = Janhae18;
	list.push_back(Janhaes18_13);

	Object Janhaes18_14;
	Janhaes18_14.location = f3(822.5f, 0.0f, 432.5f);
	Janhaes18_14.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_14.type = Janhae18;
	list.push_back(Janhaes18_14);

	Object Janhaes18_15;
	Janhaes18_15.location = f3(822.5f, 0.0f, 454.0f);
	Janhaes18_15.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_15.type = Janhae18;
	list.push_back(Janhaes18_15);

	Object Janhaes18_16;
	Janhaes18_16.location = f3(822.5f, 0.0f, 475.5f);
	Janhaes18_16.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes18_16.type = Janhae18;
	list.push_back(Janhaes18_16);

	///////////////////////////////////////////////////

	Object Janhaes19_1;
	Janhaes19_1.location = f3(860.0f, 0.0f, 135.0f);
	Janhaes19_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes19_1.type = Janhae19;
	list.push_back(Janhaes19_1);

	Object Janhaes19_2;
	Janhaes19_2.location = f3(826.0f, -0.2f, 164.0f);
	Janhaes19_2.rotation = f3(0.0f, 24.0f, 0.0f);
	Janhaes19_2.type = Janhae19;
	list.push_back(Janhaes19_2);

	Object Janhaes19_3;
	Janhaes19_3.location = f3(845.0f, 0.3f, 200.5f);
	Janhaes19_3.rotation = f3(0.0f, 7.0f, 0.0f);
	Janhaes19_3.type = Janhae19;
	list.push_back(Janhaes19_3);

	Object Janhaes19_4;
	Janhaes19_4.location = f3(869.5f, 0.1f, 210.0f);
	Janhaes19_4.rotation = f3(0.0f, 42.5f, 0.0f);
	Janhaes19_4.type = Janhae19;
	list.push_back(Janhaes19_4);

	Object Janhaes19_5;
	Janhaes19_5.location = f3(821.0f, 1.5f, 210.0f);
	Janhaes19_5.rotation = f3(0.0f, 33.3f, 0.0f);
	Janhaes19_5.type = Janhae19;
	list.push_back(Janhaes19_5);

	Object Janhaes19_6;
	Janhaes19_6.location = f3(839.0f, 0.0f, 245.0f);
	Janhaes19_6.rotation = f3(0.0f, 68.2f, 0.0f);
	Janhaes19_6.type = Janhae19;
	list.push_back(Janhaes19_6);

	Object Janhaes19_7;
	Janhaes19_7.location = f3(852.5f, 0.0f, 249.0f);
	Janhaes19_7.rotation = f3(0.0f, 39.5f, 0.0f);
	Janhaes19_7.type = Janhae19;
	list.push_back(Janhaes19_7);

	Object Janhaes19_8;
	Janhaes19_8.location = f3(866.0f, 0.0f, 229.0f);
	Janhaes19_8.rotation = f3(0.0f, 44.3f, 0.0f);
	Janhaes19_8.type = Janhae19;
	list.push_back(Janhaes19_8);

	Object Janhaes19_9;
	Janhaes19_9.location = f3(833.0f, 0.0f, 227.0f);
	Janhaes19_9.rotation = f3(0.0f, 93.25f, 0.0f);
	Janhaes19_9.type = Janhae19;
	list.push_back(Janhaes19_9);

	Object Janhaes19_10;
	Janhaes19_10.location = f3(831.0f, 0.0f, 274.5f);
	Janhaes19_10.rotation = f3(0.0f, 2.5f, 0.0f);
	Janhaes19_10.type = Janhae19;
	list.push_back(Janhaes19_10);

	Object Janhaes19_11;
	Janhaes19_11.location = f3(849.5f, 0.0f, 269.8f);
	Janhaes19_11.rotation = f3(0.0f, 77.7f, 0.0f);
	Janhaes19_11.type = Janhae19;
	list.push_back(Janhaes19_11);

	Object Janhaes19_12;
	Janhaes19_12.location = f3(839.2f, 0.0f, 180.0f);
	Janhaes19_12.rotation = f3(0.0f, 59.5f, 0.0f);
	Janhaes19_12.type = Janhae19;
	list.push_back(Janhaes19_12);

	Object Janhaes19_13;
	Janhaes19_13.location = f3(865.5f, 0.0f, 157.0f);
	Janhaes19_13.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes19_13.type = Janhae19;
	list.push_back(Janhaes19_13);

	Object Janhaes20_1;
	Janhaes20_1.location = f3(885.0f, 0.0f, 159.0f);
	Janhaes20_1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_1.type = Janhae20;
	list.push_back(Janhaes20_1);

	Object Janhaes20_2;
	Janhaes20_2.location = f3(899.0f, 0.0f, 146.5f);
	Janhaes20_2.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_2.type = Janhae20;
	list.push_back(Janhaes20_2);

	Object Janhaes20_3;
	Janhaes20_3.location = f3(917.5f, 0.0f, 168.0f);
	Janhaes20_3.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_3.type = Janhae20;
	list.push_back(Janhaes20_3);

	Object Janhaes20_4;
	Janhaes20_4.location = f3(900.0f, 0.0f, 196.0f);
	Janhaes20_4.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_4.type = Janhae20;
	list.push_back(Janhaes20_4);

	Object Janhaes20_5;
	Janhaes20_5.location = f3(934.5f, 0.0f, 171.0f);
	Janhaes20_5.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_5.type = Janhae20;
	list.push_back(Janhaes20_5);

	Object Janhaes20_6;
	Janhaes20_6.location = f3(949.0f, 0.0f, 165.0f);
	Janhaes20_6.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_6.type = Janhae20;
	list.push_back(Janhaes20_6);

	Object Janhaes20_7;
	Janhaes20_7.location = f3(985.0f, 0.0f, 160.0f);
	Janhaes20_7.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_7.type = Janhae20;
	list.push_back(Janhaes20_7);

	Object Janhaes20_8;
	Janhaes20_8.location = f3(1009.5f, 0.0f, 175.0f);
	Janhaes20_8.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_8.type = Janhae20;
	list.push_back(Janhaes20_8);

	Object Janhaes20_9;
	Janhaes20_9.location = f3(924.5f, 0.0f, 181.0f);
	Janhaes20_9.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_9.type = Janhae20;
	list.push_back(Janhaes20_9);

	Object Janhaes20_10;
	Janhaes20_10.location = f3(951.0f, 0.0f, 192.0f);
	Janhaes20_10.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_10.type = Janhae20;
	list.push_back(Janhaes20_10);

	Object Janhaes20_11;
	Janhaes20_11.location = f3(974.0f, 0.0f, 188.5f);
	Janhaes20_11.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_11.type = Janhae20;
	list.push_back(Janhaes20_11);

	Object Janhaes20_12;
	Janhaes20_12.location = f3(1002.0f, 0.0f, 185.0f);
	Janhaes20_12.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes20_12.type = Janhae20;
	list.push_back(Janhaes20_12);

	Object Janhaes21_1;
	Janhaes21_1.location = f3(1011.5f, 12.5f, 285.0f);
	Janhaes21_1.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_1.type = Janhae21;
	list.push_back(Janhaes21_1);

	Object Janhaes21_2;
	Janhaes21_2.location = f3(1011.5f, 12.5f, 305.0f);
	Janhaes21_2.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_2.type = Janhae21;
	list.push_back(Janhaes21_2);

	Object Janhaes21_3;
	Janhaes21_3.location = f3(1011.5f, 12.5f, 325.0f);
	Janhaes21_3.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_3.type = Janhae21;
	list.push_back(Janhaes21_3);

	Object Janhaes21_4;
	Janhaes21_4.location = f3(1011.5f, 12.5f, 345.0f);
	Janhaes21_4.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_4.type = Janhae21;
	list.push_back(Janhaes21_4);

	Object Janhaes21_5;
	Janhaes21_5.location = f3(1011.5f, 12.5f, 365.0f);
	Janhaes21_5.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_5.type = Janhae21;
	list.push_back(Janhaes21_5);

	Object Janhaes21_6;
	Janhaes21_6.location = f3(1011.5f, 12.5f, 385.0f);
	Janhaes21_6.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_6.type = Janhae21;
	list.push_back(Janhaes21_6);

	Object Janhaes21_7;
	Janhaes21_7.location = f3(1011.5f, 12.5f, 405.0f);
	Janhaes21_7.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_7.type = Janhae21;
	list.push_back(Janhaes21_7);

	Object Janhaes21_8;
	Janhaes21_8.location = f3(1011.5f, 12.5f, 425.0f);
	Janhaes21_8.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_8.type = Janhae21;
	list.push_back(Janhaes21_8);

	Object Janhaes21_9;
	Janhaes21_9.location = f3(1011.5f, 12.5f, 445.0f);
	Janhaes21_9.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_9.type = Janhae21;
	list.push_back(Janhaes21_9);

	Object Janhaes21_10;
	Janhaes21_10.location = f3(1011.5f, 12.5f, 465.0f);
	Janhaes21_10.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_10.type = Janhae21;
	list.push_back(Janhaes21_10);

	Object Janhaes21_11;
	Janhaes21_11.location = f3(1011.5f, 12.5f, 485.0f);
	Janhaes21_11.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_11.type = Janhae21;
	list.push_back(Janhaes21_11);

	Object Janhaes21_12;
	Janhaes21_12.location = f3(1011.5f, 12.5f, 505.0f);
	Janhaes21_12.rotation = f3(-90.0f, 90.0f, 0.0f);
	Janhaes21_12.type = Janhae21;
	list.push_back(Janhaes21_12);

	Object Janhaes22_1;
	Janhaes22_1.location = f3(955.0f, 12.5f, 540.0f);
	Janhaes22_1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes22_1.type = Janhae22;
	list.push_back(Janhaes22_1);

	Object Janhaes22_2;
	Janhaes22_2.location = f3(1000.0f, 12.5f, 540.0f);
	Janhaes22_2.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes22_2.type = Janhae22;
	list.push_back(Janhaes22_2);

	Object Janhaes22_3;
	Janhaes22_3.location = f3(1045.0f, 12.5f, 540.0f);
	Janhaes22_3.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes22_3.type = Janhae22;
	list.push_back(Janhaes22_3);

	Object Janhaes22_4;
	Janhaes22_4.location = f3(1090.0f, 12.5f, 540.0f);
	Janhaes22_4.rotation = f3(-90.0f, 0.0f, 0.0f);
	Janhaes22_4.type = Janhae22;
	list.push_back(Janhaes22_4);

	Object Janhaes23_1;
	Janhaes23_1.location = f3(1040.0f, 0.0f, 200.0f);
	Janhaes23_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_1.type = Janhae23;
	list.push_back(Janhaes23_1);

	Object Janhaes23_2;
	Janhaes23_2.location = f3(1077.0f, 0.0f, 184.0f);
	Janhaes23_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_2.type = Janhae23;
	list.push_back(Janhaes23_2);

	Object Janhaes23_3;
	Janhaes23_3.location = f3(1059.0f, 0.0f, 172.0f);
	Janhaes23_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_3.type = Janhae23;
	list.push_back(Janhaes23_3);

	Object Janhaes23_4;
	Janhaes23_4.location = f3(1085.0f, 0.0f, 159.5f);
	Janhaes23_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_4.type = Janhae23;
	list.push_back(Janhaes23_4);

	Object Janhaes23_5;
	Janhaes23_5.location = f3(1063.0f, 0.0f, 156.0f);
	Janhaes23_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_5.type = Janhae23;
	list.push_back(Janhaes23_5);

	Object Janhaes23_6;
	Janhaes23_6.location = f3(1059.0f, 0.0f, 199.0f);
	Janhaes23_6.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_6.type = Janhae23;
	list.push_back(Janhaes23_6);

	Object Janhaes23_7;
	Janhaes23_7.location = f3(1077.0f, 0.0f, 206.0f);
	Janhaes23_7.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_7.type = Janhae23;
	list.push_back(Janhaes23_7);

	Object Janhaes23_8;
	Janhaes23_8.location = f3(1111.0f, 0.0f, 197.0f);
	Janhaes23_8.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_8.type = Janhae23;
	list.push_back(Janhaes23_8);

	Object Janhaes23_9;
	Janhaes23_9.location = f3(1088.0f, 0.0f, 221.0f);
	Janhaes23_9.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_9.type = Janhae23;
	list.push_back(Janhaes23_9);

	Object Janhaes23_10;
	Janhaes23_10.location = f3(1075.0f, 0.0f, 215.0f);
	Janhaes23_10.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_10.type = Janhae23;
	list.push_back(Janhaes23_10);

	Object Janhaes23_11;
	Janhaes23_11.location = f3(1100.0f, 0.0f, 209.0f);
	Janhaes23_11.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_11.type = Janhae23;
	list.push_back(Janhaes23_11);

	Object Janhaes23_12;
	Janhaes23_12.location = f3(1126.0f, 0.0f, 144.0f);
	Janhaes23_12.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_12.type = Janhae23;
	list.push_back(Janhaes23_12);

	Object Janhaes23_13;
	Janhaes23_13.location = f3(1119.0f, 0.0f, 156.0f);
	Janhaes23_13.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_13.type = Janhae23;
	list.push_back(Janhaes23_13);

	Object Janhaes23_14;
	Janhaes23_14.location = f3(1130.0f, 0.0f, 175.0f);
	Janhaes23_14.rotation = f3(0.0f, 0.0f, 0.0f);
	Janhaes23_14.type = Janhae23;
	list.push_back(Janhaes23_14);

	Object Dungle1;
	Dungle1.location = f3(1260.0f, 0.0f, 330.0f);
	Dungle1.rotation = f3(-90.0f, 0.0f, 0.0f);
	Dungle1.type = Factory_tool18;
	list.push_back(Dungle1);

	Object Dungle2;
	Dungle2.location = f3(1260.0f, 0.0f, 400.0f);
	Dungle2.rotation = f3(-90.0f, 0.0f, 0.0f);
	Dungle2.type = Factory_tool19;
	list.push_back(Dungle2);

	Object Dungle3;
	Dungle3.location = f3(1325.0f, 7.5f, 550.0f);
	Dungle3.rotation = f3(-90.0f, 0.0f, 0.0f);
	Dungle3.type = Factory_tool20;
	list.push_back(Dungle3);


	Object gidung1[8];
	for (int i = 0; i < 8; ++i)
	{
		gidung1[i].location = f3(825.0f + (25.0f * i), 0.0f, 120.0f);
		gidung1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		gidung1[i].type = Factory_tool16;
		list.push_back(gidung1[i]);
	}

	Object gidung2[8];
	for (int i = 0; i < 8; ++i)
	{
		gidung2[i].location = f3(825.0f + (25.0f * i), 0.0f, 90.0f);
		gidung2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		gidung2[i].type = Factory_tool16;
		list.push_back(gidung2[i]);
	}


	Object Baljeon2[3];
	for (int i = 0; i < 3; ++i)
	{
		Baljeon2[i].location = f3(570.0f, 0.0f, 320.0f + (30.0f * i));
		Baljeon2[i].rotation = f3(-90.0f, 0.0f, 0.0f);
		Baljeon2[i].type = Factory_tool15;
		list.push_back(Baljeon2[i]);
	}

	Object Baljeon1[3];
	for (int i = 0; i < 3; ++i)
	{
		Baljeon1[i].location = f3(305.0f, 0.0f, 280.0f + (120.0f * i));
		Baljeon1[i].rotation = f3(-90.0f, 0.0f, 0.0f);
		Baljeon1[i].type = Factory_tool14;
		list.push_back(Baljeon1[i]);
	}

	Object Tas2[10];
	for (int i = 0; i < 10; ++i)
	{
		Tas2[i].location = f3(329.4f, 1.4f, 258.0f + (38.0f * i));
		Tas2[i].rotation = f3(270.0f, 0.0f, 0.0f);
		Tas2[i].type = Factory_tool13;
		list.push_back(Tas2[i]);
	}

	Object Tas1[2];
	for (int i = 0; i < 2; ++i)
	{
		Tas1[i].location = f3(292.5f + (25.0f * i), 1.4f, 220.6f);
		Tas1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tas1[i].type = Factory_tool12;
		list.push_back(Tas1[i]);
	}

	Object Bag1[3];
	for (int i = 0; i < 3; ++i)
	{
		Bag1[i].location = f3(416.0f + (5.0f * i), 3.5f, 495.5f);
		Bag1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Bag1[i].type = Factory_tool11;
		list.push_back(Bag1[i]);
	}


	Object Bag2[3];
	for (int i = 0; i < 3; ++i)
	{
		Bag2[i].location = f3(441.0f + (5.0f * i), 3.5f, 495.5f);
		Bag2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Bag2[i].type = Factory_tool11;
		list.push_back(Bag2[i]);
	}


	Object Bag3[3];
	for (int i = 0; i < 3; ++i)
	{
		Bag3[i].location = f3(466.0f + (5.0f * i), 3.5f, 495.5f);
		Bag3[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Bag3[i].type = Factory_tool11;
		list.push_back(Bag3[i]);
	}

	Object Bag4[3];
	for (int i = 0; i < 3; ++i)
	{
		Bag4[i].location = f3(491.0f + (5.0f * i), 3.5f, 495.5f);
		Bag4[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Bag4[i].type = Factory_tool11;
		list.push_back(Bag4[i]);
	}

	Object Bag5[3];
	for (int i = 0; i < 3; ++i)
	{
		Bag5[i].location = f3(516.0f + (5.0f * i), 3.5f, 495.5f);
		Bag5[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Bag5[i].type = Factory_tool11;
		list.push_back(Bag5[i]);
	}

	Object HwaMul1[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1[i].location = f3(450.0f + (3.0f * i), 3.1f, 293.0f);
		HwaMul1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1[i].type = Factory_tool10;
		list.push_back(HwaMul1[i]);
	}



	Object HwaMul2[7];

	for (int i = 0; i < 7; ++i)
	{
		HwaMul2[i].location = f3(450.0f + (3.0f * i), 3.1f, 291.5f);
		HwaMul2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2[i].type = Factory_tool10;
		list.push_back(HwaMul2[i]);
	}

	Object HwaMul3[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3[i].location = f3(450.0f + (3.0f * i), 3.1f, 290.0f);
		HwaMul3[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3[i].type = Factory_tool10;
		list.push_back(HwaMul3[i]);
	}


	Object HwaMul4[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4[i].location = f3(450.0f + (3.0f * i), 3.1f, 288.5f);
		HwaMul4[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4[i].type = Factory_tool10;
		list.push_back(HwaMul4[i]);
	}

	Object HwaMul1_m[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_m[i].location = f3(450.0f + (3.0f * i), 3.9f, 293.0f);
		HwaMul1_m[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_m[i].type = Factory_tool10;
		list.push_back(HwaMul1_m[i]);
	}

	Object HwaMul2_m[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_m[i].location = f3(450.0f + (3.0f * i), 3.9f, 291.5f);
		HwaMul2_m[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_m[i].type = Factory_tool10;
		list.push_back(HwaMul2_m[i]);
	}

	Object HwaMul3_m[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_m[i].location = f3(450.0f + (3.0f * i), 3.9f, 290.0f);
		HwaMul3_m[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_m[i].type = Factory_tool10;
		list.push_back(HwaMul3_m[i]);
	}

	Object HwaMul4_m[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_m[i].location = f3(450.0f + (3.0f * i), 3.9f, 288.5f);
		HwaMul4_m[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_m[i].type = Factory_tool10;
		list.push_back(HwaMul4_m[i]);
	}


	///
	Object HwaMul1_h[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_h[i].location = f3(450.0f + (3.0f * i), 4.7f, 293.0f);
		HwaMul1_h[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_h[i].type = Factory_tool10;
		list.push_back(HwaMul1_h[i]);
	}

	Object HwaMul2_h[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_h[i].location = f3(450.0f + (3.0f * i), 4.7f, 291.5f);
		HwaMul2_h[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_h[i].type = Factory_tool10;
		list.push_back(HwaMul2_h[i]);
	}

	Object HwaMul3_h[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_h[i].location = f3(450.0f + (3.0f * i), 4.7f, 290.0f);
		HwaMul3_h[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_h[i].type = Factory_tool10;
		list.push_back(HwaMul3_h[i]);
	}

	Object HwaMul4_h[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_h[i].location = f3(450.0f + (3.0f * i), 4.7f, 288.5f);
		HwaMul4_h[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_h[i].type = Factory_tool10;
		list.push_back(HwaMul4_h[i]);
	}




	///////////////////////////////////

	Object HwaMul1a[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1a[i].location = f3(475.0f + (3.0f * i), 3.1f, 293.0f);
		HwaMul1a[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1a[i].type = Factory_tool10;
		list.push_back(HwaMul1a[i]);
	}

	Object HwaMul2a[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2a[i].location = f3(475.0f + (3.0f * i), 3.1f, 291.5f);
		HwaMul2a[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2a[i].type = Factory_tool10;
		list.push_back(HwaMul2a[i]);
	}

	Object HwaMul3a[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3a[i].location = f3(475.0f + (3.0f * i), 3.1f, 290.0f);
		HwaMul3a[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3a[i].type = Factory_tool10;
		list.push_back(HwaMul3a[i]);
	}


	Object HwaMul4a[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4a[i].location = f3(475.0f + (3.0f * i), 3.1f, 288.5f);
		HwaMul4a[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4a[i].type = Factory_tool10;
		list.push_back(HwaMul4a[i]);
	}

	Object HwaMul1_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_ma[i].location = f3(475.0f + (3.0f * i), 3.9f, 293.0f);
		HwaMul1_ma[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_ma[i].type = Factory_tool10;
		list.push_back(HwaMul1_ma[i]);
	}

	Object HwaMul2_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_ma[i].location = f3(475.0f + (3.0f * i), 3.9f, 291.5f);
		HwaMul2_ma[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_ma[i].type = Factory_tool10;
		list.push_back(HwaMul2_ma[i]);
	}

	Object HwaMul3_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_ma[i].location = f3(475.0f + (3.0f * i), 3.9f, 290.0f);
		HwaMul3_ma[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_ma[i].type = Factory_tool10;
		list.push_back(HwaMul3_ma[i]);
	}

	Object HwaMul4_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_ma[i].location = f3(475.0f + (3.0f * i), 3.9f, 288.5f);
		HwaMul4_ma[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_ma[i].type = Factory_tool10;
		list.push_back(HwaMul4_ma[i]);
	}


	///
	Object HwaMul1_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_ha[i].location = f3(475.0f + (3.0f * i), 4.7f, 293.0f);
		HwaMul1_ha[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_ha[i].type = Factory_tool10;
		list.push_back(HwaMul1_ha[i]);
	}

	Object HwaMul2_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_ha[i].location = f3(475.0f + (3.0f * i), 4.7f, 291.5f);
		HwaMul2_ha[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_ha[i].type = Factory_tool10;
		list.push_back(HwaMul2_ha[i]);
	}

	Object HwaMul3_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_ha[i].location = f3(475.0f + (3.0f * i), 4.7f, 290.0f);
		HwaMul3_ha[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_ha[i].type = Factory_tool10;
		list.push_back(HwaMul3_ha[i]);
	}

	Object HwaMul4_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_ha[i].location = f3(475.0f + (3.0f * i), 4.7f, 288.5f);
		HwaMul4_ha[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_ha[i].type = Factory_tool10;
		list.push_back(HwaMul4_ha[i]);
	}

	////////////////////////////////////
	Object HwaMul1b[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1b[i].location = f3(500.0f + (3.0f * i), 3.1f, 293.0f);
		HwaMul1b[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1b[i].type = Factory_tool10;
		list.push_back(HwaMul1b[i]);
	}



	Object HwaMul2b[7];

	for (int i = 0; i < 7; ++i)
	{
		HwaMul2b[i].location = f3(500.0f + (3.0f * i), 3.1f, 291.5f);
		HwaMul2b[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2b[i].type = Factory_tool10;
		list.push_back(HwaMul2b[i]);
	}

	Object HwaMul3b[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3b[i].location = f3(500.0f + (3.0f * i), 3.1f, 290.0f);
		HwaMul3b[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3b[i].type = Factory_tool10;
		list.push_back(HwaMul3b[i]);
	}


	Object HwaMul4b[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4b[i].location = f3(500.0f + (3.0f * i), 3.1f, 288.5f);
		HwaMul4b[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4b[i].type = Factory_tool10;
		list.push_back(HwaMul4b[i]);
	}

	Object HwaMul1_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_mb[i].location = f3(500.0f + (3.0f * i), 3.9f, 293.0f);
		HwaMul1_mb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_mb[i].type = Factory_tool10;
		list.push_back(HwaMul1_mb[i]);
	}

	Object HwaMul2_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_mb[i].location = f3(500.0f + (3.0f * i), 3.9f, 291.5f);
		HwaMul2_mb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_mb[i].type = Factory_tool10;
		list.push_back(HwaMul2_mb[i]);
	}

	Object HwaMul3_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_mb[i].location = f3(500.0f + (3.0f * i), 3.9f, 290.0f);
		HwaMul3_mb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_mb[i].type = Factory_tool10;
		list.push_back(HwaMul3_mb[i]);
	}

	Object HwaMul4_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_mb[i].location = f3(500.0f + (3.0f * i), 3.9f, 288.5f);
		HwaMul4_mb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_mb[i].type = Factory_tool10;
		list.push_back(HwaMul4_mb[i]);
	}


	///
	Object HwaMul1_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_hb[i].location = f3(500.0f + (3.0f * i), 4.7f, 293.0f);
		HwaMul1_hb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_hb[i].type = Factory_tool10;
		list.push_back(HwaMul1_hb[i]);
	}

	Object HwaMul2_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_hb[i].location = f3(500.0f + (3.0f * i), 4.7f, 291.5f);
		HwaMul2_hb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_hb[i].type = Factory_tool10;
		list.push_back(HwaMul2_hb[i]);
	}

	Object HwaMul3_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_hb[i].location = f3(500.0f + (3.0f * i), 4.7f, 290.0f);
		HwaMul3_hb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_hb[i].type = Factory_tool10;
		list.push_back(HwaMul3_hb[i]);
	}

	Object HwaMul4_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_hb[i].location = f3(500.0f + (3.0f * i), 4.7f, 288.5f);
		HwaMul4_hb[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_hb[i].type = Factory_tool10;
		list.push_back(HwaMul4_hb[i]);
	}



	////////////////////////////

	Object HwaMul1c[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1c[i].location = f3(525.0f + (3.0f * i), 3.1f, 293.0f);
		HwaMul1c[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1c[i].type = Factory_tool10;
		list.push_back(HwaMul1c[i]);
	}



	Object HwaMul2c[7];

	for (int i = 0; i < 7; ++i)
	{
		HwaMul2c[i].location = f3(525.0f + (3.0f * i), 3.1f, 291.5f);
		HwaMul2c[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2c[i].type = Factory_tool10;
		list.push_back(HwaMul2c[i]);
	}

	Object HwaMul3c[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3c[i].location = f3(525.0f + (3.0f * i), 3.1f, 290.0f);
		HwaMul3c[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3c[i].type = Factory_tool10;
		list.push_back(HwaMul3c[i]);
	}


	Object HwaMul4c[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4c[i].location = f3(525.0f + (3.0f * i), 3.1f, 288.5f);
		HwaMul4c[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4c[i].type = Factory_tool10;
		list.push_back(HwaMul4c[i]);
	}

	Object HwaMul1_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_mc[i].location = f3(525.0f + (3.0f * i), 3.9f, 293.0f);
		HwaMul1_mc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_mc[i].type = Factory_tool10;
		list.push_back(HwaMul1_mc[i]);
	}

	Object HwaMul2_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_mc[i].location = f3(525.0f + (3.0f * i), 3.9f, 291.5f);
		HwaMul2_mc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_mc[i].type = Factory_tool10;
		list.push_back(HwaMul2_mc[i]);
	}

	Object HwaMul3_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_mc[i].location = f3(525.0f + (3.0f * i), 3.9f, 290.0f);
		HwaMul3_mc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_mc[i].type = Factory_tool10;
		list.push_back(HwaMul3_mc[i]);
	}

	Object HwaMul4_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_mc[i].location = f3(525.0f + (3.0f * i), 3.9f, 288.5f);
		HwaMul4_mc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_mc[i].type = Factory_tool10;
		list.push_back(HwaMul4_mc[i]);
	}


	///
	Object HwaMul1_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_hc[i].location = f3(525.0f + (3.0f * i), 4.7f, 293.0f);
		HwaMul1_hc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_hc[i].type = Factory_tool10;
		list.push_back(HwaMul1_hc[i]);
	}

	Object HwaMul2_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_hc[i].location = f3(525.0f + (3.0f * i), 4.7f, 291.5f);
		HwaMul2_hc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_hc[i].type = Factory_tool10;
		list.push_back(HwaMul2_hc[i]);
	}

	Object HwaMul3_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_hc[i].location = f3(525.0f + (3.0f * i), 4.7f, 290.0f);
		HwaMul3_hc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_hc[i].type = Factory_tool10;
		list.push_back(HwaMul3_hc[i]);
	}

	Object HwaMul4_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_hc[i].location = f3(525.0f + (3.0f * i), 4.7f, 288.5f);
		HwaMul4_hc[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_hc[i].type = Factory_tool10;
		list.push_back(HwaMul4_hc[i]);
	}



	///////////////////////////////


	Object HwaMul1d[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1d[i].location = f3(550.0f + (3.0f * i), 3.1f, 293.0f);
		HwaMul1d[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1d[i].type = Factory_tool10;
		list.push_back(HwaMul1d[i]);
	}



	Object HwaMul2d[7];

	for (int i = 0; i < 7; ++i)
	{
		HwaMul2d[i].location = f3(550.0f + (3.0f * i), 3.1f, 291.5f);
		HwaMul2d[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2d[i].type = Factory_tool10;
		list.push_back(HwaMul2d[i]);
	}

	Object HwaMul3d[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3d[i].location = f3(550.0f + (3.0f * i), 3.1f, 290.0f);
		HwaMul3d[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3d[i].type = Factory_tool10;
		list.push_back(HwaMul3d[i]);
	}


	Object HwaMul4d[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4d[i].location = f3(550.0f + (3.0f * i), 3.1f, 288.5f);
		HwaMul4d[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4d[i].type = Factory_tool10;
		list.push_back(HwaMul4d[i]);
	}

	Object HwaMul1_md[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_md[i].location = f3(550.0f + (3.0f * i), 3.9f, 293.0f);
		HwaMul1_md[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_md[i].type = Factory_tool10;
		list.push_back(HwaMul1_md[i]);
	}

	Object HwaMul2_md[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_md[i].location = f3(550.0f + (3.0f * i), 3.9f, 291.5f);
		HwaMul2_md[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_md[i].type = Factory_tool10;
		list.push_back(HwaMul2_md[i]);
	}

	Object HwaMul3_md[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_md[i].location = f3(550.0f + (3.0f * i), 3.9f, 290.0f);
		HwaMul3_md[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_md[i].type = Factory_tool10;
		list.push_back(HwaMul3_md[i]);
	}

	Object HwaMul4_md[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_md[i].location = f3(550.0f + (3.0f * i), 3.9f, 288.5f);
		HwaMul4_md[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_md[i].type = Factory_tool10;
		list.push_back(HwaMul4_md[i]);
	}


	///
	Object HwaMul1_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_hd[i].location = f3(550.0f + (3.0f * i), 4.7f, 293.0f);
		HwaMul1_hd[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_hd[i].type = Factory_tool10;
		list.push_back(HwaMul1_hd[i]);
	}

	Object HwaMul2_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_hd[i].location = f3(550.0f + (3.0f * i), 4.7f, 291.5f);
		HwaMul2_hd[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_hd[i].type = Factory_tool10;
		list.push_back(HwaMul2_hd[i]);
	}

	Object HwaMul3_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_hd[i].location = f3(550.0f + (3.0f * i), 4.7f, 290.0f);
		HwaMul3_hd[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_hd[i].type = Factory_tool10;
		list.push_back(HwaMul3_hd[i]);
	}

	Object HwaMul4_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_hd[i].location = f3(550.0f + (3.0f * i), 4.7f, 288.5f);
		HwaMul4_hd[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_hd[i].type = Factory_tool10;
		list.push_back(HwaMul4_hd[i]);
	}



	////////////////////////////////////

	Object HwaMul1e[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1e[i].location = f3(575.0f + (3.0f * i), 3.1f, 293.0f);
		HwaMul1e[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1e[i].type = Factory_tool10;
		list.push_back(HwaMul1e[i]);
	}



	Object HwaMul2e[7];

	for (int i = 0; i < 7; ++i)
	{
		HwaMul2e[i].location = f3(575.0f + (3.0f * i), 3.1f, 291.5f);
		HwaMul2e[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2e[i].type = Factory_tool10;
		list.push_back(HwaMul2e[i]);
	}

	Object HwaMul3e[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3e[i].location = f3(575.0f + (3.0f * i), 3.1f, 290.0f);
		HwaMul3e[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3e[i].type = Factory_tool10;
		list.push_back(HwaMul3e[i]);
	}


	Object HwaMul4e[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4e[i].location = f3(575.0f + (3.0f * i), 3.1f, 288.5f);
		HwaMul4e[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4e[i].type = Factory_tool10;
		list.push_back(HwaMul4e[i]);
	}

	Object HwaMul1_me[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_me[i].location = f3(575.0f + (3.0f * i), 3.9f, 293.0f);
		HwaMul1_me[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_me[i].type = Factory_tool10;
		list.push_back(HwaMul1_me[i]);
	}

	Object HwaMul2_me[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_me[i].location = f3(575.0f + (3.0f * i), 3.9f, 291.5f);
		HwaMul2_me[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_me[i].type = Factory_tool10;
		list.push_back(HwaMul2_me[i]);
	}

	Object HwaMul3_me[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_me[i].location = f3(575.0f + (3.0f * i), 3.9f, 290.0f);
		HwaMul3_me[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_me[i].type = Factory_tool10;
		list.push_back(HwaMul3_me[i]);
	}

	Object HwaMul4_me[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_me[i].location = f3(575.0f + (3.0f * i), 3.9f, 288.5f);
		HwaMul4_me[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_me[i].type = Factory_tool10;
		list.push_back(HwaMul4_mc[i]);
	}


	///
	Object HwaMul1_he[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul1_he[i].location = f3(575.0f + (3.0f * i), 4.7f, 293.0f);
		HwaMul1_he[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul1_he[i].type = Factory_tool10;
		list.push_back(HwaMul1_he[i]);
	}

	Object HwaMul2_he[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul2_he[i].location = f3(575.0f + (3.0f * i), 4.7f, 291.5f);
		HwaMul2_he[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul2_he[i].type = Factory_tool10;
		list.push_back(HwaMul2_he[i]);
	}

	Object HwaMul3_he[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul3_he[i].location = f3(575.0f + (3.0f * i), 4.7f, 290.0f);
		HwaMul3_he[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul3_he[i].type = Factory_tool10;
		list.push_back(HwaMul3_he[i]);
	}

	Object HwaMul4_he[7];
	for (int i = 0; i < 7; ++i)
	{
		HwaMul4_he[i].location = f3(575.0f + (3.0f * i), 4.7f, 288.5f);
		HwaMul4_he[i].rotation = f3(0.0f, 0.0f, 0.0f);
		HwaMul4_he[i].type = Factory_tool10;
		list.push_back(HwaMul4_he[i]);
	}


	//////////////////////////////////




	Object SonVan2[5];
	for (int i = 0; i < 5; ++i)
	{
		SonVan2[i].location = f3(426.0f + (25.0f * i), 1.75f, 492.0f);
		SonVan2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		SonVan2[i].type = Factory_tool9;
		list.push_back(SonVan2[i]);
	}

	Object SonVan1[6];

	for (int i = 0; i < 6; ++i)
	{
		SonVan1[i].location = f3(460.0f + (25.0f * i), 1.75f, 292.0f);
		SonVan1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		SonVan1[i].type = Factory_tool9;
		list.push_back(SonVan1[i]);
	}

	Object Tims1[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims1[i].location = f3(1225.0f + (5.0f * i), 0.0f, 30.0f);
		Tims1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims1[i].type = Factory_tool8;
		list.push_back(Tims1[i]);

	}

	Object Tims2[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims2[i].location = f3(1225.0f + (5.0f * i), 0.0f, 39.0f);
		Tims2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims2[i].type = Factory_tool8;
		list.push_back(Tims2[i]);

	}

	Object Tims3[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims3[i].location = f3(1225.0f + (5.0f * i), 0.0f, 48.0f);
		Tims3[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims3[i].type = Factory_tool8;
		list.push_back(Tims3[i]);

	}

	Object Tims4[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims4[i].location = f3(1225.0f + (5.0f * i), 0.0f, 57.0f);
		Tims4[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims4[i].type = Factory_tool8;
		list.push_back(Tims4[i]);

	}

	Object Tims5[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims5[i].location = f3(1225.0f + (5.0f * i), 0.0f, 66.0f);
		Tims5[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims5[i].type = Factory_tool8;
		list.push_back(Tims5[i]);

	}

	Object Tims6[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims6[i].location = f3(1225.0f + (5.0f * i), 0.0f, 75.0f);
		Tims6[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims6[i].type = Factory_tool8;
		list.push_back(Tims6[i]);

	}

	Object Tims7[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims7[i].location = f3(1225.0f + (5.0f * i), 0.0f, 84.0f);
		Tims7[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims7[i].type = Factory_tool8;
		list.push_back(Tims7[i]);

	}

	Object Tims8[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims8[i].location = f3(1225.0f + (5.0f * i), 0.0f, 93.0f);
		Tims8[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims8[i].type = Factory_tool8;
		list.push_back(Tims8[i]);

	}

	Object Tims9[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims9[i].location = f3(1225.0f + (5.0f * i), 0.0f, 102.0f);
		Tims9[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims9[i].type = Factory_tool8;
		list.push_back(Tims9[i]);

	}

	Object Tims10[10];
	for (int i = 0; i < 10; ++i)
	{
		Tims10[i].location = f3(1225.0f + (5.0f * i), 0.0f, 111.0f);
		Tims10[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Tims10[i].type = Factory_tool8;
		list.push_back(Tims10[i]);

	}



	Object Jims1[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims1[i].location = f3(1225.0f + (5.0f * i), 0.0f, 545.0f);
		Jims1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims1[i].type = Factory_tool8;
		list.push_back(Jims1[i]);

	}


	Object Jims2[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims2[i].location = f3(1225.0f + (5.0f * i), 0.0f, 550.0f);
		Jims2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims2[i].type = Factory_tool8;
		list.push_back(Jims2[i]);

	}

	Object Jims3[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims3[i].location = f3(1225.0f + (5.0f * i), 0.0f, 555.0f);
		Jims3[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims3[i].type = Factory_tool8;
		list.push_back(Jims3[i]);

	}


	Object Jims4[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims4[i].location = f3(1225.0f + (5.0f * i), 0.0f, 560.0f);
		Jims4[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims4[i].type = Factory_tool8;
		list.push_back(Jims4[i]);

	}

	Object Jims5[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims5[i].location = f3(1225.0f + (5.0f * i), 0.0f, 565.0f);
		Jims5[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims5[i].type = Factory_tool8;
		list.push_back(Jims5[i]);

	}

	Object Jims6[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims6[i].location = f3(1225.0f + (5.0f * i), 0.0f, 570.0f);
		Jims6[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims6[i].type = Factory_tool8;
		list.push_back(Jims6[i]);

	}

	Object Jims7[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims7[i].location = f3(1225.0f + (5.0f * i), 0.0f, 480.0f);
		Jims7[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims7[i].type = Factory_tool8;
		list.push_back(Jims1[i]);

	}


	Object Jims8[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims8[i].location = f3(1225.0f + (5.0f * i), 0.0f, 485.0f);
		Jims8[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims8[i].type = Factory_tool8;
		list.push_back(Jims8[i]);

	}

	Object Jims9[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims9[i].location = f3(1225.0f + (5.0f * i), 0.0f, 490.0f);
		Jims9[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims9[i].type = Factory_tool8;
		list.push_back(Jims9[i]);

	}


	Object Jims10[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims10[i].location = f3(1225.0f + (5.0f * i), 0.0f, 495.0f);
		Jims10[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims10[i].type = Factory_tool8;
		list.push_back(Jims10[i]);

	}

	Object Jims11[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims11[i].location = f3(1225.0f + (5.0f * i), 0.0f, 500.0f);
		Jims11[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims11[i].type = Factory_tool8;
		list.push_back(Jims11[i]);

	}

	Object Jims12[5];
	for (int i = 0; i < 5; ++i)
	{
		Jims12[i].location = f3(1225.0f + (5.0f * i), 0.0f, 505.0f);
		Jims12[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Jims12[i].type = Factory_tool8;
		list.push_back(Jims12[i]);

	}
	


	Object Edin1[20];

	for (int i = 0; i < 20; ++i)
	{
		Edin1[i].location = f3(250.0f + (5.0f * i), 0.0f, 2.5f);
		Edin1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Edin1[i].type = Factory_tool6;

		list.push_back(Edin1[i]);
	}

	Object Cabi1[30];

	for (int i = 0; i < 30; ++i)
	{
		Cabi1[i].location = f3(401.5f, 0.0f, 300.0f + (3.0f * i));
		Cabi1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Cabi1[i].type = Factory_tool5;

		list.push_back(Cabi1[i]);
	}

	Object Drums1[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums1[i].location = f3(420.0f + (5.0f * i), 0.0f, 565.0f);
		Drums1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums1[i].type = Factory_tool7;

		list.push_back(Drums1[i]);
	}

	Object Drums2[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums2[i].location = f3(420.0f + (5.0f * i), 0.0f, 570.0f);
		Drums2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums2[i].type = Factory_tool7;
		list.push_back(Drums2[i]);
	}

	Object Drums3[2];
	for (int i = 0; i < 2; ++i)
	{
		Drums3[i].location = f3(450.0f + (5.0f * i), 0.0f, 565.0f);
		Drums3[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums3[i].type = Factory_tool7;
		list.push_back(Drums3[i]);
	}

	Object Drums4[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums4[i].location = f3(450.0f + (5.0f * i), 0.0f, 570.0f);
		Drums4[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums4[i].type = Factory_tool7;
		list.push_back(Drums4[i]);
	}

	Object Drums5[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums5[i].location = f3(420.0f + (5.0f * i), 0.0f, 535.0f);
		Drums5[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums5[i].type = Factory_tool7;

		list.push_back(Drums5[i]);
	}

	Object Drums6[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums6[i].location = f3(420.0f + (5.0f * i), 0.0f, 540.0f);
		Drums6[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums6[i].type = Factory_tool7;
		list.push_back(Drums6[i]);
	}

	Object Drums7[2];
	for (int i = 0; i < 2; ++i)
	{
		Drums7[i].location = f3(450.0f + (5.0f * i), 0.0f, 535.0f);
		Drums7[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums7[i].type = Factory_tool7;
		list.push_back(Drums7[i]);
	}

	Object Drums8[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums8[i].location = f3(450.0f + (5.0f * i), 0.0f, 540.0f);
		Drums8[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums8[i].type = Factory_tool7;
		list.push_back(Drums8[i]);
	}





	Object Drums9[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums9[i].location = f3(480.0f + (5.0f * i), 0.0f, 565.0f);
		Drums9[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums9[i].type = Factory_tool7;

		list.push_back(Drums9[i]);
	}

	Object Drums10[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums10[i].location = f3(480.0f + (5.0f * i), 0.0f, 570.0f);
		Drums10[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums10[i].type = Factory_tool7;
		list.push_back(Drums10[i]);
	}

	Object Drums11[2];
	for (int i = 0; i < 2; ++i)
	{
		Drums11[i].location = f3(510.0f + (5.0f * i), 0.0f, 565.0f);
		Drums11[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums11[i].type = Factory_tool7;
		list.push_back(Drums11[i]);
	}

	Object Drums12[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums12[i].location = f3(510.0f + (5.0f * i), 0.0f, 570.0f);
		Drums12[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums12[i].type = Factory_tool7;
		list.push_back(Drums12[i]);
	}

	Object Drums13[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums13[i].location = f3(480.0f + (5.0f * i), 0.0f, 535.0f);
		Drums13[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums13[i].type = Factory_tool7;

		list.push_back(Drums13[i]);
	}

	Object Drums14[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums14[i].location = f3(480.0f + (5.0f * i), 0.0f, 540.0f);
		Drums14[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums14[i].type = Factory_tool7;
		list.push_back(Drums14[i]);
	}

	Object Drums15[2];
	for (int i = 0; i < 2; ++i)
	{
		Drums15[i].location = f3(510.0f + (5.0f * i), 0.0f, 535.0f);
		Drums15[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums15[i].type = Factory_tool7;
		list.push_back(Drums15[i]);
	}

	Object Drums16[2];

	for (int i = 0; i < 2; ++i)
	{
		Drums16[i].location = f3(510.0f + (5.0f * i), 0.0f, 540.0f);
		Drums16[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Drums16[i].type = Factory_tool7;
		list.push_back(Drums16[i]);
	}


	Object Engine1;
	Engine1.location = f3(802.0f, 0.0f, 375.0f);
	Engine1.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine1.type = Factory_tool4;

	Object Engine2;
	Engine2.location = f3(802.0f, 0.0f, 400.0f);
	Engine2.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine2.type = Factory_tool4;

	Object Engine3;
	Engine3.location = f3(802.0f, 0.0f, 425.0f);
	Engine3.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine3.type = Factory_tool4;

	Object Engine4;
	Engine4.location = f3(802.0f, 0.0f, 450.0f);
	Engine4.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine4.type = Factory_tool4;

	Object Engine5;
	Engine5.location = f3(802.0f, 0.0f, 475.0f);
	Engine5.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine5.type = Factory_tool4;

	Object Engine6;
	Engine6.location = f3(802.0f, 0.0f, 500.0f);
	Engine6.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine6.type = Factory_tool4;

	Object Engine7;
	Engine7.location = f3(802.0f, 0.0f, 525.0f);
	Engine7.rotation = f3(0.0f, 0.0f, 0.0f);
	Engine7.type = Factory_tool4;




	Object Pbox1;
	Pbox1.location = f3(1000.0f, 12.5f, 500.0f);
	Pbox1.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox1.type = Factory_tool3;

	Object Pbox2;
	Pbox2.location = f3(1003.0f, 12.5f, 500.0f);
	Pbox2.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox2.type = Factory_tool3;

	Object Pbox3;
	Pbox3.location = f3(1006.0f, 12.5f, 500.0f);
	Pbox3.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox3.type = Factory_tool3;

	Object Pbox4;
	Pbox4.location = f3(1009.0f, 12.5f, 500.0f);
	Pbox4.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox4.type = Factory_tool3;

	Object Pbox5;
	Pbox5.location = f3(1012.0f, 12.5f, 500.0f);
	Pbox5.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox5.type = Factory_tool3;

	Object Pbox6;
	Pbox6.location = f3(1015.0f, 12.5f, 500.0f);
	Pbox6.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox6.type = Factory_tool3;

	Object Pbox7;
	Pbox7.location = f3(1018.0f, 12.5f, 500.0f);
	Pbox7.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox7.type = Factory_tool3;

	Object Pbox8;
	Pbox8.location = f3(1021.0f, 12.5f, 500.0f);
	Pbox8.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox8.type = Factory_tool3;

	Object Pbox9;
	Pbox9.location = f3(1024.0f, 12.5f, 500.0f);
	Pbox9.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox9.type = Factory_tool3;

	Object Pbox10;
	Pbox10.location = f3(1027.0f, 12.5f, 500.0f);
	Pbox10.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox10.type = Factory_tool3;

	Object Pbox11;
	Pbox11.location = f3(1030.0f, 12.5f, 500.0f);
	Pbox11.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox11.type = Factory_tool3;


	Object Pbox12;
	Pbox12.location = f3(1060.0f, 12.5f, 500.0f);
	Pbox12.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox12.type = Factory_tool3;


	Object Pbox13;
	Pbox13.location = f3(1063.0f, 12.5f, 500.0f);
	Pbox13.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox13.type = Factory_tool3;

	Object Pbox14;
	Pbox14.location = f3(1066.0f, 12.5f, 500.0f);
	Pbox14.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox14.type = Factory_tool3;


	Object Pbox15;
	Pbox15.location = f3(1069.0f, 12.5f, 500.0f);
	Pbox15.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox15.type = Factory_tool3;

	Object Pbox16;
	Pbox16.location = f3(1072.0f, 12.5f, 500.0f);
	Pbox16.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox16.type = Factory_tool3;

	Object Pbox17;
	Pbox17.location = f3(1075.0f, 12.5f, 500.0f);
	Pbox17.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox17.type = Factory_tool3;


	Object Pbox18;
	Pbox18.location = f3(1078.0f, 12.5f, 500.0f);
	Pbox18.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox18.type = Factory_tool3;

	Object Pbox19;
	Pbox19.location = f3(1081.0f, 12.5f, 500.0f);
	Pbox19.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox19.type = Factory_tool3;

	Object Pbox20;
	Pbox20.location = f3(1084.0f, 12.5f, 500.0f);
	Pbox20.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox20.type = Factory_tool3;

	Object Pbox21;
	Pbox21.location = f3(1087.0f, 12.5f, 500.0f);
	Pbox21.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox21.type = Factory_tool3;

	Object Pbox22;
	Pbox22.location = f3(1090.0f, 12.5f, 500.0f);
	Pbox22.rotation = f3(0.0f, 0.0f, 0.0f);
	Pbox22.type = Factory_tool3;

	Object Conv_1;
	Conv_1.location = f3(910.0f, 12.5f, 300.0f);
	Conv_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_1.type = Factory_tool2;

	Object Conv_2;
	Conv_2.location = f3(910.0f, 12.5f, 315.0f);
	Conv_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_2.type = Factory_tool2;

	Object Conv_3;
	Conv_3.location = f3(910.0f, 12.5f, 330.0f);
	Conv_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_3.type = Factory_tool2;

	Object Conv_4;
	Conv_4.location = f3(910.0f, 12.5f, 345.0f);
	Conv_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_4.type = Factory_tool2;

	Object Conv_5;
	Conv_5.location = f3(910.0f, 12.5f, 360.0f);
	Conv_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_5.type = Factory_tool2;

	Object Conv_6;
	Conv_6.location = f3(910.0f, 12.5f, 375.0f);
	Conv_6.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_6.type = Factory_tool2;

	Object Conv_7;
	Conv_7.location = f3(910.0f, 12.5f, 390.0f);
	Conv_7.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_7.type = Factory_tool2;

	Object Conv_8;
	Conv_8.location = f3(910.0f, 12.5f, 405.0f);
	Conv_8.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_8.type = Factory_tool2;

	Object Conv_9;
	Conv_9.location = f3(910.0f, 12.5f, 420.0f);
	Conv_9.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_9.type = Factory_tool2;

	Object Conv_10;
	Conv_10.location = f3(910.0f, 12.5f, 435.0f);
	Conv_10.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_10.type = Factory_tool2;

	Object Conv_11;
	Conv_11.location = f3(910.0f, 12.5f, 450.0f);
	Conv_11.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_11.type = Factory_tool2;

	Object Conv_12;
	Conv_12.location = f3(1020.0f, 12.5f, 300.0f);
	Conv_12.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_12.type = Factory_tool2;

	Object Conv_13;
	Conv_13.location = f3(1020.0f, 12.5f, 315.0f);
	Conv_13.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_13.type = Factory_tool2;

	Object Conv_14;
	Conv_14.location = f3(1020.0f, 12.5f, 330.0f);
	Conv_14.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_14.type = Factory_tool2;

	Object Conv_15;
	Conv_15.location = f3(1020.0f, 12.5f, 345.0f);
	Conv_15.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_15.type = Factory_tool2;

	Object Conv_16;
	Conv_16.location = f3(1020.0f, 12.5f, 360.0f);
	Conv_16.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_16.type = Factory_tool2;

	Object Conv_17;
	Conv_17.location = f3(1020.0f, 12.5f, 375.0f);
	Conv_17.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_17.type = Factory_tool2;

	Object Conv_18;
	Conv_18.location = f3(1020.0f, 12.5f, 390.0f);
	Conv_18.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_18.type = Factory_tool2;

	Object Conv_19;
	Conv_19.location = f3(1020.0f, 12.5f, 405.0f);
	Conv_19.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_19.type = Factory_tool2;

	Object Conv_20;
	Conv_20.location = f3(1020.0f, 12.5f, 420.0f);
	Conv_20.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_20.type = Factory_tool2;

	Object Conv_21;
	Conv_21.location = f3(1020.0f, 12.5f, 435.0f);
	Conv_21.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_21.type = Factory_tool2;

	Object Conv_22;
	Conv_22.location = f3(1020.0f, 12.5f, 450.0f);
	Conv_22.rotation = f3(0.0f, 0.0f, 0.0f);
	Conv_22.type = Factory_tool2;

	Object Fact_1;
	Fact_1.location = f3(40.0f, 5.0f, 450.0f);
	Fact_1.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_1.type = Factory_tool1;

	Object Fact_2;
	Fact_2.location = f3(46.0f, 5.0f, 450.0f);
	Fact_2.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_2.type = Factory_tool1;

	Object Fact_3;
	Fact_3.location = f3(52.0f, 5.0f, 450.0f);
	Fact_3.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_3.type = Factory_tool1;

	Object Fact_4;
	Fact_4.location = f3(869.0f, 0.0f, 600.0f);
	Fact_4.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_4.type = Factory_tool1;

	Object Fact_5;
	Fact_5.location = f3(869.0f, 0.0f, 594.0f);
	Fact_5.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_5.type = Factory_tool1;

	Object Fact_6;
	Fact_6.location = f3(869.0f, 0.0f, 588.0f);
	Fact_6.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_6.type = Factory_tool1;

	Object Fact_7;
	Fact_7.location = f3(869.0f, 0.0f, 582.0f);
	Fact_7.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_7.type = Factory_tool1;

	Object Fact_8;
	Fact_8.location = f3(869.0f, 0.0f, 576.0f);
	Fact_8.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_8.type = Factory_tool1;

	Object Fact_9;
	Fact_9.location = f3(869.0f, 0.0f, 570.0f);
	Fact_9.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_9.type = Factory_tool1;

	Object Fact_10;
	Fact_10.location = f3(869.0f, 0.0f, 564.0f);
	Fact_10.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_10.type = Factory_tool1;

	Object Fact_11;
	Fact_11.location = f3(869.0f, 0.0f, 558.0f);
	Fact_11.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_11.type = Factory_tool1;

	Object Fact_12;
	Fact_12.location = f3(869.0f, 0.0f, 552.0f);
	Fact_12.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_12.type = Factory_tool1;

	Object Fact_13;
	Fact_13.location = f3(869.0f, 0.0f, 546.0f);
	Fact_13.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_13.type = Factory_tool1;

	Object Fact_14;
	Fact_14.location = f3(869.0f, 0.0f, 540.0f);
	Fact_14.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_14.type = Factory_tool1;

	Object Fact_15;
	Fact_15.location = f3(869.0f, 2.0f, 600.0f);
	Fact_15.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_15.type = Factory_tool1;

	Object Fact_16;
	Fact_16.location = f3(869.0f, 2.0f, 594.0f);
	Fact_16.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_16.type = Factory_tool1;

	Object Fact_17;
	Fact_17.location = f3(869.0f, 2.0f, 588.0f);
	Fact_17.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_17.type = Factory_tool1;

	Object Fact_18;
	Fact_18.location = f3(869.0f, 2.0f, 582.0f);
	Fact_18.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_18.type = Factory_tool1;

	Object Fact_19;
	Fact_19.location = f3(869.0f, 2.0f, 576.0f);
	Fact_19.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_19.type = Factory_tool1;

	Object Fact_20;
	Fact_20.location = f3(869.0f, 2.0f, 570.0f);
	Fact_20.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_20.type = Factory_tool1;

	Object Fact_21;
	Fact_21.location = f3(869.0f, 2.0f, 564.0f);
	Fact_21.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_21.type = Factory_tool1;

	Object Fact_22;
	Fact_22.location = f3(869.0f, 2.0f, 558.0f);
	Fact_22.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_22.type = Factory_tool1;

	Object Fact_23;
	Fact_23.location = f3(869.0f, 2.0f, 552.0f);
	Fact_23.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_23.type = Factory_tool1;

	Object Fact_24;
	Fact_24.location = f3(869.0f, 2.0f, 546.0f);
	Fact_24.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_24.type = Factory_tool1;

	Object Fact_25;
	Fact_25.location = f3(869.0f, 2.0f, 540.0f);
	Fact_25.rotation = f3(0.0f, 0.0f, 0.0f);
	Fact_25.type = Factory_tool1;

	////////////////////////////////////////////

	Object B_doorlock3;
	B_doorlock3.location = f3(1399.0f, 2.5f, 560.0f);
	B_doorlock3.rotation = f3(0.0f, 0.0f, 0.0f);
	B_doorlock3.type = B_Door;


	Object Heaterz1[5];
	for (int i = 0; i < 5; ++i)
	{
		Heaterz1[i].location = f3(170.0f, 0.0f, 295.0f + (50.0f * i));
		Heaterz1[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Heaterz1[i].type = Heaters1;
		list.push_back(Heaterz1[i]);
	}

	Object Heaterz2[5];
	for (int i = 0; i < 5; ++i)
	{
		Heaterz2[i].location = f3(230.0f, 0.0f, 295.0f + (50.0f * i));
		Heaterz2[i].rotation = f3(0.0f, 0.0f, 0.0f);
		Heaterz2[i].type = Heaters1;
		list.push_back(Heaterz2[i]);
	}

	Object H_heater1;
	H_heater1.location = f3(195.0f, 0.0f, 295.0f);
	H_heater1.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater1.type = Heaters1;

	Object H_heater2;
	H_heater2.location = f3(195.0f, 0.0f, 345.0f);
	H_heater2.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater2.type = Heaters1;

	Object H_heater3;
	H_heater3.location = f3(195.0f, 0.0f, 395.0f);
	H_heater3.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater3.type = Heaters1;

	Object H_heater4;
	H_heater4.location = f3(195.0f, 0.0f, 445.0f);
	H_heater4.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater4.type = Heaters1;

	Object H_heater5;
	H_heater5.location = f3(195.0f, 0.0f, 495.0f);
	H_heater5.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater5.type = Heaters1;

	Object H_heater6;
	H_heater6.location = f3(145.0f, 0.0f, 295.0f);
	H_heater6.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater6.type = Heaters1;

	Object H_heater7;
	H_heater7.location = f3(145.0f, 0.0f, 345.0f);
	H_heater7.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater7.type = Heaters1;

	Object H_heater8;
	H_heater8.location = f3(145.0f, 0.0f, 395.0f);
	H_heater8.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater8.type = Heaters1;

	Object H_heater9;
	H_heater9.location = f3(145.0f, 0.0f, 445.0f);
	H_heater9.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater9.type = Heaters1;

	Object H_heater10;
	H_heater10.location = f3(145.0f, 0.0f, 495.0f);
	H_heater10.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater10.type = Heaters1;

	Object H_heater11;
	H_heater11.location = f3(205.0f, 0.0f, 295.0f);
	H_heater11.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater11.type = Heaters1;

	Object H_heater12;
	H_heater12.location = f3(205.0f, 0.0f, 345.0f);
	H_heater12.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater12.type = Heaters1;

	Object H_heater13;
	H_heater13.location = f3(205.0f, 0.0f, 395.0f);
	H_heater13.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater13.type = Heaters1;

	Object H_heater14;
	H_heater14.location = f3(205.0f, 0.0f, 445.0f);
	H_heater14.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater14.type = Heaters1;

	Object H_heater15;
	H_heater15.location = f3(205.0f, 0.0f, 495.0f);
	H_heater15.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater15.type = Heaters1;

	Object H_heater16;
	H_heater16.location = f3(255.0f, 0.0f, 295.0f);
	H_heater16.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater16.type = Heaters1;

	Object H_heater17;
	H_heater17.location = f3(255.0f, 0.0f, 345.0f);
	H_heater17.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater17.type = Heaters1;

	Object H_heater18;
	H_heater18.location = f3(255.0f, 0.0f, 395.0f);
	H_heater18.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater18.type = Heaters1;

	Object H_heater19;
	H_heater19.location = f3(255.0f, 0.0f, 445.0f);
	H_heater19.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater19.type = Heaters1;

	Object H_heater20;
	H_heater20.location = f3(255.0f, 0.0f, 495.0f);
	H_heater20.rotation = f3(0.0f, 0.0f, 0.0f);
	H_heater20.type = Heaters1;

	Object BoBox;
	BoBox.location = f3(360.0f, 0.0f, 565.0f);
	BoBox.rotation = f3(0.0f, 0.0f, 0.0f);
	BoBox.type = F_Stages;





	Object GyoDan;
	GyoDan.location = f3(382.0f, 0.0f, 430.0f);
	GyoDan.rotation = f3(0.0f, 0.0f, 0.0f);
	GyoDan.type = GyeDans1;

	Object GyoDan2;
	GyoDan2.location = f3(352.5f, 0.0f, 336.0f);
	GyoDan2.rotation = f3(0.0f, 0.0f, 0.0f);
	GyoDan2.type = GyeDans2;

	Object R_stair1;
	R_stair1.location = f3(890.0f, 0.0f, 258.0f);
	R_stair1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair1.type = R_GyeDan1;

	Object R_stair1_1;
	R_stair1_1.location = f3(890.0f, 5.5f, 270.5f);
	R_stair1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair1_1.type = R_GyeDan1;
	list.push_back(R_stair1_1);

	Object R_stair1_2;
	R_stair1_2.location = f3(930.0f, 2.5f, 273.5f);
	R_stair1_2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair1_2.type = R_GyeDan1_1;
	list.push_back(R_stair1_2);

	Object R_didim1_1;
	R_didim1_1.location = f3(925.0f, 5.0166f, 258.0f);
	R_didim1_1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_didim1_1.type = didims;
	list.push_back(R_didim1_1);

	Object R_didim1_2;
	R_didim1_2.location = f3(925.0f, 10.566f, 270.5f);
	R_didim1_2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_didim1_2.type = didims;
	list.push_back(R_didim1_2);



	////////////////////



	Object R_stair2;
	R_stair2.location = f3(1030.0f, 0.0f, 258.0f);
	R_stair2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair2.type = R_GyeDan1;

	Object R_stair2_1;
	R_stair2_1.location = f3(1030.0f, 5.5f, 270.5f);
	R_stair2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair2_1.type = R_GyeDan1;
	list.push_back(R_stair2_1);

	Object R_stair2_2;
	R_stair2_2.location = f3(1070.0f, 2.5f, 273.5f);
	R_stair2_2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair2_2.type = R_GyeDan1_1;
	list.push_back(R_stair2_2);

	Object R_didim2_1;
	R_didim2_1.location = f3(1065.0f, 5.0166f, 258.0f);
	R_didim2_1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_didim2_1.type = didims;
	list.push_back(R_didim2_1);

	Object R_didim2_2;
	R_didim2_2.location = f3(1065.0f, 10.566f, 270.5f);
	R_didim2_2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_didim2_2.type = didims;
	list.push_back(R_didim2_2);


	///////////////////////////////////////////////////





	Object R_stair3;
	R_stair3.location = f3(10.0f, 0.0f, 377.5f);
	R_stair3.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair3.type = R_GyeDan1;

	Object R_stair3_1;
	R_stair3_1.location = f3(10.0f, 5.5f, 390.0f);
	R_stair3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair3_1.type = R_GyeDan1;
	list.push_back(R_stair3_1);

	Object R_stair3_2;
	R_stair3_2.location = f3(50.0f, 2.5f, 393.0f);
	R_stair3_2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_stair3_2.type = R_GyeDan1_1;
	list.push_back(R_stair3_2);

	Object R_didim3_1;
	R_didim3_1.location = f3(45.0f, 5.0166f, 387.0f);
	R_didim3_1.rotation = f3(0.0f, 0.0f, 0.0f);
	R_didim3_1.type = didims;
	list.push_back(R_didim3_1);

	Object R_didim3_2;
	R_didim3_2.location = f3(45.0f, 10.566f, 399.0f);
	R_didim3_2.rotation = f3(0.0f, 0.0f, 0.0f);
	R_didim3_2.type = didims;
	list.push_back(R_didim3_2);



	Object electric1[3];
	for (int i = 0; i < 3; ++i)
	{
		electric1[i].location = f3(1160.0f + (60.0f * i), 0.0f, 180.0f);
		electric1[i].rotation = f3(270.0f, 0.0f, 0.0f);
		electric1[i].type = Factory_tool17;
		list.push_back(electric1[i]);
	}


	list.push_back(GyoDan);
	list.push_back(GyoDan2);
	list.push_back(R_stair1);
	list.push_back(R_stair2);
	list.push_back(R_stair3);

	list.push_back(B_doorlock3);
	list.push_back(H_heater1);
	list.push_back(H_heater2);
	list.push_back(H_heater3);
	list.push_back(H_heater4);
	list.push_back(H_heater5);
	list.push_back(H_heater6);
	list.push_back(H_heater7);
	list.push_back(H_heater8);
	list.push_back(H_heater9);
	list.push_back(H_heater10);
	list.push_back(H_heater11);
	list.push_back(H_heater12);
	list.push_back(H_heater13);
	list.push_back(H_heater14);
	list.push_back(H_heater15);
	list.push_back(H_heater16);
	list.push_back(H_heater17);
	list.push_back(H_heater18);
	list.push_back(H_heater19);
	list.push_back(H_heater20);
	list.push_back(BoBox);


	list.push_back(Fact_1);
	list.push_back(Fact_2);
	list.push_back(Fact_3);
	list.push_back(Fact_4);
	list.push_back(Fact_5);
	list.push_back(Fact_6);
	list.push_back(Fact_7);
	list.push_back(Fact_8);
	list.push_back(Fact_9);
	list.push_back(Fact_10);
	list.push_back(Fact_11);
	list.push_back(Fact_12);
	list.push_back(Fact_13);
	list.push_back(Fact_14);
	list.push_back(Fact_15);
	list.push_back(Fact_16);
	list.push_back(Fact_17);
	list.push_back(Fact_18);
	list.push_back(Fact_19);
	list.push_back(Fact_20);
	list.push_back(Fact_21);
	list.push_back(Fact_22);
	list.push_back(Fact_23);
	list.push_back(Fact_24);
	list.push_back(Fact_25);
	list.push_back(Conv_1);
	list.push_back(Conv_2);
	list.push_back(Conv_3);
	list.push_back(Conv_4);
	list.push_back(Conv_5);
	list.push_back(Conv_6);
	list.push_back(Conv_7);
	list.push_back(Conv_8);
	list.push_back(Conv_9);
	list.push_back(Conv_10);
	list.push_back(Conv_11);
	list.push_back(Conv_12);
	list.push_back(Conv_13);
	list.push_back(Conv_14);
	list.push_back(Conv_15);
	list.push_back(Conv_16);
	list.push_back(Conv_17);
	list.push_back(Conv_18);
	list.push_back(Conv_19);
	list.push_back(Conv_20);
	list.push_back(Conv_21);
	list.push_back(Conv_22);
	list.push_back(Pbox1);
	list.push_back(Pbox2);
	list.push_back(Pbox3);



	BoundingBox Jans1;
	Jans1.start = f3(287.0f, 0.0f, 130.0f);
	Jans1.end = f3(293.0f, 5.0f, 140.0f);
	blist.push_back(Jans1);

	BoundingBox Jans2;
	Jans2.start = f3(142.0f, 0.0f, 10.0f);
	Jans2.end = f3(148.0f, 5.0f, 20.0f);
	blist.push_back(Jans2);

	BoundingBox Jans3;
	Jans3.start = f3(142.0f, 0.0f, 21.0f);
	Jans3.end = f3(148.0f, 5.0f, 31.0f);
	blist.push_back(Jans3);
	
	BoundingBox Jans4;
	Jans4.start = f3(137.0f, 0.0f, 60.0f);
	Jans4.end = f3(143.0f, 5.0f, 70.0f);
	blist.push_back(Jans4);
	
	BoundingBox Jans5;
	Jans5.start = f3(137.0f, 0.0f, 37.0f);
	Jans5.end = f3(143.0f, 5.0f, 47.0f);
	blist.push_back(Jans5);

	BoundingBox Jans6;
	Jans6.start = f3(125.0f, 0.0f, 42.0f);
	Jans6.end = f3(131.0f, 5.0f, 52.0f);
	blist.push_back(Jans6);

	BoundingBox Jans7;
	Jans7.start = f3(180.6f, 0.0f, 72.8f);
	Jans7.end = f3(187.3f, 5.0f, 83.3f);
	blist.push_back(Jans7);

	BoundingBox Jans8;
	Jans8.start = f3(158.0f, 0.0f, 77.8f);
	Jans8.end = f3(164.2f, 5.0f, 88.2f);
	blist.push_back(Jans8);

	BoundingBox Jans9;
	Jans9.start = f3(244.0f, 0.0f, 150.0f);
	Jans9.end = f3(250.0f, 5.0f, 160.0f);
	blist.push_back(Jans9); // 159 138

	BoundingBox Jans10;
	Jans10.start = f3(156.0f, 0.0f, 133.0f);
	Jans10.end = f3(162.0f, 5.0f, 143.0f);
	blist.push_back(Jans10); // 188 142

	BoundingBox Jans11;
	Jans11.start = f3(185.0f, 0.0f, 139.0f);
	Jans11.end = f3(191.0f, 5.0f, 145.0f);
	blist.push_back(Jans11);

	BoundingBox Jans2_1;
	Jans2_1.start = f3(171.0f, 0.0f, 0.0f);
	Jans2_1.end = f3(183.0f, 6.0f, 40.0f);
	blist.push_back(Jans2_1);

	BoundingBox Jans2_2;
	Jans2_2.start = f3(130.0f, 0.0f, 169.0f);
	Jans2_2.end = f3(170.0f, 6.0f, 181.0f);
	blist.push_back(Jans2_2);

	BoundingBox Jans2_3;
	Jans2_3.start = f3(130.0f, 0.0f, 99.0f);
	Jans2_3.end = f3(170.0f, 6.0f, 111.0f);
	blist.push_back(Jans2_3);

	BoundingBox Jans2_4;
	Jans2_4.start = f3(209.0f, 0.0f, 0.0f);
	Jans2_4.end = f3(221.0f, 6.0f, 40.0f);
	blist.push_back(Jans2_4);

	BoundingBox Jans3_1;
	Jans3_1.start = f3(190.0f, 0.0f, 109.0f);
	Jans3_1.end = f3(202.0f, 12.0f, 121.0f);
	blist.push_back(Jans3_1);

	BoundingBox Jans3_2;
	Jans3_2.start = f3(238.0f, 0.0f, 81.0f);
	Jans3_2.end = f3(250.0f, 12.0f, 93.0f);
	blist.push_back(Jans3_2);

	BoundingBox Jans3_3;
	Jans3_3.start = f3(247.0f, 0.0f, 154.0f);
	Jans3_3.end = f3(271.0f, 12.0f, 178.0f);
	blist.push_back(Jans3_3);

	BoundingBox Jans3_4;
	Jans3_4.start = f3(187.0f, 0.0f, 168.0f);
	Jans3_4.end = f3(211.0f, 12.0f, 192.0f);
	blist.push_back(Jans3_4);


	BoundingBox Jans3_1_1;
	Jans3_1_1.start = f3(240.5f, 0.0f, 66.5f);
	Jans3_1_1.end = f3(247.5f, 7.0f, 73.5f);
	blist.push_back(Jans3_1_1);

	BoundingBox Jans3_1_2;
	Jans3_1_2.start = f3(207.5f, 0.0f, 61.5f);
	Jans3_1_2.end = f3(214.5f, 7.0f, 68.5f);
	blist.push_back(Jans3_1_2);

	BoundingBox Jans3_1_3;
	Jans3_1_3.start = f3(148.5f, 0.0f, 60.5f);
	Jans3_1_3.end = f3(155.5f, 7.0f, 67.5f);
	blist.push_back(Jans3_1_3);

	BoundingBox Jans3_1_4;
	Jans3_1_4.start = f3(91.5f, 0.0f, 301.5f);
	Jans3_1_4.end = f3(98.5f, 7.0f, 308.5f);
	blist.push_back(Jans3_1_4);


	BoundingBox Jans4_1;
	Jans4_1.start = f3(40.5f, 0.0f, 275.5f);
	Jans4_1.end = f3(49.5f, 4.0f, 284.5f);
	blist.push_back(Jans4_1);

	BoundingBox Jans4_2;
	Jans4_2.start = f3(40.5f, 0.0f, 284.5f);
	Jans4_2.end = f3(49.5f, 4.0f, 293.5f);
	blist.push_back(Jans4_2);

	BoundingBox Jans5_1;
	Jans5_1.start = f3(64.5f, 0.0f, 290.5f);
	Jans5_1.end = f3(67.5f, 0.5f, 293.5f);
	blist.push_back(Jans5_1);

	BoundingBox Jans5_2;
	Jans5_2.start = f3(55.5f, 0.0f, 273.5f);
	Jans5_2.end = f3(58.5f, 0.5f, 276.5f);
	blist.push_back(Jans5_2);

	BoundingBox Jans5_3;
	Jans5_3.start = f3(73.5f, 0.0f, 273.5f);
	Jans5_3.end = f3(76.5f, 1.4f, 276.5f);
	blist.push_back(Jans5_3);

	BoundingBox Jans5_4;
	Jans5_4.start = f3(82.5f, 0.0f, 288.5f);
	Jans5_4.end = f3(85.5f, 1.4f, 291.5f);
	blist.push_back(Jans5_4);

	BoundingBox Jans6_1;
	Jans6_1.start = f3(77.0f, 0.0f, 322.0f);
	Jans6_1.end = f3(83.0f, 2.0f, 328.0f);
	blist.push_back(Jans6_1);

	BoundingBox Jans6_2;
	Jans6_2.start = f3(83.0f, 0.0f, 322.0f);
	Jans6_2.end = f3(89.0f, 2.0f, 328.0f);
	blist.push_back(Jans6_2);

	BoundingBox Jans7_1;
	Jans7_1.start = f3(66.0f, 0.0f, 280.0f);
	Jans7_1.end = f3(90.0f, 6.0f, 286.0f);
	blist.push_back(Jans7_1);

	BoundingBox Jans7_2;
	Jans7_2.start = f3(100.0f, 0.0f, 327.0f);
	Jans7_2.end = f3(124.0f, 6.0f, 333.0f);
	blist.push_back(Jans7_2);

	BoundingBox Jans7_3;
	Jans7_3.start = f3(121.0f, 0.0f, 316.0f);
	Jans7_3.end = f3(145.0f, 6.0f, 322.0f);
	blist.push_back(Jans7_3);

	BoundingBox Jans7_4;
	Jans7_4.start = f3(116.0f, 0.0f, 344.0f);
	Jans7_4.end = f3(140.0f, 6.0f, 350.0f);
	blist.push_back(Jans7_4);

	BoundingBox Jans7_5;
	Jans7_5.start = f3(33.0f, 0.0f, 298.0f);
	Jans7_5.end = f3(39.0f, 6.0f, 322.0f);
	blist.push_back(Jans7_5);

	BoundingBox Jans7_6;
	Jans7_6.start = f3(44.0f, 0.0f, 325.0f);
	Jans7_6.end = f3(50.0f, 6.0f, 349.0f);
	blist.push_back(Jans7_6);

	BoundingBox Jans7_7;
	Jans7_7.start = f3(57.0f, 0.0f, 207.0f);
	Jans7_7.end = f3(63.0f, 6.0f, 231.0f);
	blist.push_back(Jans7_7);

	BoundingBox Jans7_8;
	Jans7_8.start = f3(112.0f, 0.0f, 363.0f);
	Jans7_8.end = f3(118.0f, 6.0f, 387.0f);
	blist.push_back(Jans7_8);

	BoundingBox Jans8_1;
	Jans8_1.start = f3(118.0f, 0.0f, 411.0f);
	Jans8_1.end = f3(126.0f, 12.0f, 419.0f);
	blist.push_back(Jans8_1);

	BoundingBox Jans8_2;
	Jans8_2.start = f3(130.0f, 0.0f, 411.0f);
	Jans8_2.end = f3(138.0f, 12.0f, 419.0f);
	blist.push_back(Jans8_2);

	BoundingBox Jans8_3;
	Jans8_3.start = f3(142.0f, 0.0f, 411.0f);
	Jans8_3.end = f3(150.0f, 12.0f, 419.0f);
	blist.push_back(Jans8_3);

	BoundingBox Jans8_4; //370 270
	Jans8_4.start = f3(378.0f, 0.0f, 266.0f);
	Jans8_4.end = f3(386.0f, 12.0f, 274.0f);
	blist.push_back(Jans8_4);

	BoundingBox Jans8_5;
	Jans8_5.start = f3(378.0f, 0.0f, 276.0f);
	Jans8_5.end = f3(386.0f, 12.0f, 284.0f);
	blist.push_back(Jans8_5);

	BoundingBox Jans8_6; //370 270
	Jans8_6.start = f3(348.0f, 0.0f, 266.0f);
	Jans8_6.end = f3(356.0f, 12.0f, 274.0f);
	blist.push_back(Jans8_6);

	BoundingBox Jans8_7;
	Jans8_7.start = f3(348.0f, 0.0f, 276.0f);
	Jans8_7.end = f3(356.0f, 12.0f, 284.0f);
	blist.push_back(Jans8_7);


	BoundingBox Jans9_1;
	Jans9_1.start = f3(276.0f, 0.0f, 32.0f);
	Jans9_1.end = f3(284.0f, 4.0f, 40.0f);
	blist.push_back(Jans9_1);

	BoundingBox Jans9_2;
	Jans9_2.start = f3(276.0f, 0.0f, 44.0f);
	Jans9_2.end = f3(284.0f, 4.0f, 52.0f);
	blist.push_back(Jans9_2);

	BoundingBox Jans9_3;
	Jans9_3.start = f3(276.0f, 0.0f, 56.0f);
	Jans9_3.end = f3(284.0f, 4.0f, 64.0f);
	blist.push_back(Jans9_3);

	BoundingBox Jans9_4;
	Jans9_4.start = f3(276.0f, 0.0f, 68.0f);
	Jans9_4.end = f3(284.0f, 4.0f, 76.0f);
	blist.push_back(Jans9_4);

	BoundingBox Jans9_5;
	Jans9_5.start = f3(276.0f, 0.0f, 80.0f);
	Jans9_5.end = f3(284.0f, 4.0f, 88.0f);
	blist.push_back(Jans9_5);

	BoundingBox Jans9_6;
	Jans9_6.start = f3(276.0f, 0.0f, 92.0f);
	Jans9_6.end = f3(284.0f, 4.0f,100.0f);
	blist.push_back(Jans9_6);

	BoundingBox Jans9_7;
	Jans9_7.start = f3(276.0f, 0.0f, 104.0f);
	Jans9_7.end = f3(284.0f, 4.0f, 112.0f);
	blist.push_back(Jans9_7);

	BoundingBox Jans9_8;
	Jans9_8.start = f3(276.0f, 0.0f, 116.0f);
	Jans9_8.end = f3(284.0f, 4.0f, 124.0f);
	blist.push_back(Jans9_8); // 310 215

	BoundingBox Jans10_1;
	Jans10_1.start = f3(325.0f, 0.0f, 213.5f);
	Jans10_1.end = f3(365.0f, 5.5f, 216.5f);
	blist.push_back(Jans10_1);

	BoundingBox Jans10_2;
	Jans10_2.start = f3(345.0f, 0.0f, 228.5f);
	Jans10_2.end = f3(385.0f, 5.5f, 231.5f);
	blist.push_back(Jans10_2);

	BoundingBox Jans10_3;
	Jans10_3.start = f3(335.0f, 0.0f, 243.5f);
	Jans10_3.end = f3(375.0f, 5.5f, 246.5f);
	blist.push_back(Jans10_3);
	
	BoundingBox Jans11_1; //353 488
	Jans11_1.start = f3(364.0f, 5.0f, 385.0f);
	Jans11_1.end = f3(370.0f, 11.0f, 391.0f);
	blist.push_back(Jans11_1); // 363 375

	BoundingBox Jans11_2;
	Jans11_2.start = f3(360.0f, 5.0f, 372.0f);
	Jans11_2.end = f3(366.0f, 11.0f, 378.0f);
	blist.push_back(Jans11_2);

	BoundingBox Jans11_3;
	Jans11_3.start = f3(350.0f, 5.0f, 355.0f);
	Jans11_3.end = f3(356.0f, 11.0f, 361.0f);
	blist.push_back(Jans11_3);

	BoundingBox Jans11_4;
	Jans11_4.start = f3(350.0f, 5.0f, 376.0f);
	Jans11_4.end = f3(356.0f, 11.0f, 382.0f);
	blist.push_back(Jans11_4);


	BoundingBox Jans11_5;
	Jans11_5.start = f3(350.0f, 5.0f, 387.0f);
	Jans11_5.end = f3(356.0f, 11.0f, 393.0f);
	blist.push_back(Jans11_5);

	// 435 390
	BoundingBox Jans11_6;
	Jans11_6.start = f3(432.0f, 0.0f, 387.0f);
	Jans11_6.end = f3(438.0f, 6.0f, 393.0f);
	blist.push_back(Jans11_6);

	BoundingBox Jans11_7;
	Jans11_7.start = f3(444.0f, 0.0f, 387.0f);
	Jans11_7.end = f3(450.0f, 6.0f, 393.0f);
	blist.push_back(Jans11_7);

	BoundingBox Jans11_8;
	Jans11_8.start = f3(456.0f, 0.0f, 387.0f);
	Jans11_8.end = f3(462.0f, 6.0f, 393.0f);
	blist.push_back(Jans11_8);

	BoundingBox Jans11_9;
	Jans11_9.start = f3(468.0f, 0.0f, 387.0f);
	Jans11_9.end = f3(474.0f, 6.0f, 393.0f);
	blist.push_back(Jans11_9);

	BoundingBox Jans11_10;
	Jans11_10.start = f3(480.0f, 0.0f, 387.0f);
	Jans11_10.end = f3(486.0f, 6.0f, 393.0f);
	blist.push_back(Jans11_10);

	// 469 175
	BoundingBox Jans12_1;
	Jans12_1.start = f3(462.5f, 0.0f, 168.5f);
	Jans12_1.end = f3(475.5f, 4.0f, 181.5f);
	blist.push_back(Jans12_1);

	BoundingBox Jans12_2;
	Jans12_2.start = f3(486.5f, 0.0f, 168.5f);
	Jans12_2.end = f3(499.5f, 4.0f, 181.5f);
	blist.push_back(Jans12_2);

	BoundingBox Jans12_3;
	Jans12_3.start = f3(510.5f, 0.0f, 168.5f);
	Jans12_3.end = f3(523.5f, 4.0f, 181.5f);
	blist.push_back(Jans12_3);

	BoundingBox Jans12_4;
	Jans12_4.start = f3(534.5f, 0.0f, 168.5f);
	Jans12_4.end = f3(547.5f, 4.0f, 181.5f);
	blist.push_back(Jans12_4);

	BoundingBox Jans12_5;
	Jans12_5.start = f3(558.5f, 0.0f, 168.5f);
	Jans12_5.end = f3(571.5f, 4.0f, 181.5f);
	blist.push_back(Jans12_5);


	//////////////////////////////////////////////////


	BoundingBox Jans12_6;
	Jans12_6.start = f3(462.5f, 0.0f, 188.5f);
	Jans12_6.end = f3(475.5f, 4.0f, 201.5f);
	blist.push_back(Jans12_6);

	BoundingBox Jans12_7;
	Jans12_7.start = f3(486.5f, 0.0f, 188.5f);
	Jans12_7.end = f3(499.5f, 4.0f, 201.5f);
	blist.push_back(Jans12_7);

	BoundingBox Jans12_8;
	Jans12_8.start = f3(510.5f, 0.0f, 188.5f);
	Jans12_8.end = f3(523.5f, 4.0f, 201.5f);
	blist.push_back(Jans12_8);

	BoundingBox Jans12_9;
	Jans12_9.start = f3(534.5f, 0.0f, 188.5f);
	Jans12_9.end = f3(547.5f, 4.0f, 201.5f);
	blist.push_back(Jans12_9);

	BoundingBox Jans12_10;
	Jans12_10.start = f3(558.5f, 0.0f, 188.5f);
	Jans12_10.end = f3(571.5f, 4.0f, 201.5f);
	blist.push_back(Jans12_10);


	//////////////////////////////////////////////////////////////////////////////////////////////////////


	BoundingBox Jans12_11;
	Jans12_11.start = f3(462.5f, 0.0f, 208.5f);
	Jans12_11.end = f3(475.5f, 4.0f, 221.5f);
	blist.push_back(Jans12_11);

	BoundingBox Jans12_12;
	Jans12_12.start = f3(486.5f, 0.0f, 208.5f);
	Jans12_12.end = f3(499.5f, 4.0f, 221.5f);
	blist.push_back(Jans12_12);

	BoundingBox Jans12_13;
	Jans12_13.start = f3(510.5f, 0.0f, 208.5f);
	Jans12_13.end = f3(523.5f, 4.0f, 221.5f);
	blist.push_back(Jans12_13);

	BoundingBox Jans12_14;
	Jans12_14.start = f3(534.5f, 0.0f, 208.5f);
	Jans12_14.end = f3(547.5f, 4.0f, 221.5f);
	blist.push_back(Jans12_14);

	BoundingBox Jans12_15;
	Jans12_15.start = f3(558.5f, 0.0f, 208.5f);
	Jans12_15.end = f3(571.5f, 4.0f, 221.5f);
	blist.push_back(Jans12_15);


	/////////////////////////////////////////////////////////////////////////////////////////////

	BoundingBox Jans12_16;
	Jans12_16.start = f3(462.5f, 0.0f, 228.5f);
	Jans12_16.end = f3(475.5f, 4.0f, 241.5f);
	blist.push_back(Jans12_16);

	BoundingBox Jans12_17;
	Jans12_17.start = f3(486.5f, 0.0f, 228.5f);
	Jans12_17.end = f3(499.5f, 4.0f, 241.5f);
	blist.push_back(Jans12_17);

	BoundingBox Jans12_18;
	Jans12_18.start = f3(510.5f, 0.0f, 228.5f);
	Jans12_18.end = f3(523.5f, 4.0f, 241.5f);
	blist.push_back(Jans12_18);

	BoundingBox Jans12_19;
	Jans12_19.start = f3(534.5f, 0.0f, 228.5f);
	Jans12_19.end = f3(547.5f, 4.0f, 241.5f);
	blist.push_back(Jans12_19);

	BoundingBox Jans12_20;
	Jans12_20.start = f3(558.5f, 0.0f, 228.5f);
	Jans12_20.end = f3(571.5f, 4.0f, 241.5f);
	blist.push_back(Jans12_20);


	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	BoundingBox Jans12_21;
	Jans12_21.start = f3(462.5f, 0.0f, 248.5f);
	Jans12_21.end = f3(475.5f, 4.0f, 261.5f);
	blist.push_back(Jans12_21);

	BoundingBox Jans12_22;
	Jans12_22.start = f3(486.5f, 0.0f, 248.5f);
	Jans12_22.end = f3(499.5f, 4.0f, 261.5f);
	blist.push_back(Jans12_22);

	BoundingBox Jans12_23;
	Jans12_23.start = f3(510.5f, 0.0f, 248.5f);
	Jans12_23.end = f3(523.5f, 4.0f, 261.5f);
	blist.push_back(Jans12_23);

	BoundingBox Jans12_24;
	Jans12_24.start = f3(534.5f, 0.0f, 248.5f);
	Jans12_24.end = f3(547.5f, 4.0f, 261.5f);
	blist.push_back(Jans12_24);

	BoundingBox Jans12_25;
	Jans12_25.start = f3(558.5f, 0.0f, 248.5f);
	Jans12_25.end = f3(571.5f, 4.0f, 261.5f);
	blist.push_back(Jans12_25);


	//////////////////////////////////////////////////////////////////////

	BoundingBox Jans13_1;
	Jans13_1.start = f3(403.5f, 0.0f, 188.0f);
	Jans13_1.end = f3(406.5f, 3.0f, 212.0f);
	blist.push_back(Jans13_1);

	BoundingBox Jans13_2;
	Jans13_2.start = f3(403.5f, 0.0f, 212.0f);
	Jans13_2.end = f3(406.5f, 3.0f, 236.0f);
	blist.push_back(Jans13_2);

	BoundingBox Jans13_3;
	Jans13_3.start = f3(403.5f, 0.0f, 164.0f);
	Jans13_3.end = f3(406.5f, 3.0f, 188.0f);
	blist.push_back(Jans13_3);

	BoundingBox Jans13_4;
	Jans13_4.start = f3(416.5f, 0.0f, 152.0f);
	Jans13_4.end = f3(419.5f, 3.0f, 176.0f);
	blist.push_back(Jans13_4);

	BoundingBox Jans13_5;
	Jans13_5.start = f3(428.5f, 0.0f, 176.0f);
	Jans13_5.end = f3(431.5f, 3.0f, 200.0f);
	blist.push_back(Jans13_5);

	BoundingBox Jans13_6;
	Jans13_6.start = f3(413.0f, 0.0f, 303.5f);
	Jans13_6.end = f3(437.0f, 3.0f, 306.5f);
	blist.push_back(Jans13_6);

	BoundingBox Jans14_1;
	Jans14_1.start = f3(492.0f, 0.0f, 320.0f);
	Jans14_1.end = f3(498.0f, 7.5f, 390.0f);
	blist.push_back(Jans14_1);

	BoundingBox Jans14_2;
	Jans14_2.start = f3(422.0f, 0.0f, 320.0f);
	Jans14_2.end = f3(428.0f, 7.5f, 390.0f);
	blist.push_back(Jans14_2);

	BoundingBox Jans15_1;
	Jans15_1.start = f3(435.0f, 0.0f, 330.0f);
	Jans15_1.end = f3(485.0f, 1.6f, 380.0f);
	blist.push_back(Jans15_1);

	BoundingBox Jans16_1;
	Jans16_1.start = f3(97.5f, 0.0f, 199.9f);
	Jans16_1.end = f3(102.5f, 0.0f, 200.1f);
	blist.push_back(Jans16_1);

	BoundingBox Jans16_2;
	Jans16_2.start = f3(330.0f, 0.0f, 199.9f);
	Jans16_2.end = f3(335.0f, 0.0f, 200.1f);
	blist.push_back(Jans16_2);

	BoundingBox Jans17_1;
	Jans17_1.start = f3(599.9f, 0.0f, 550.0f);
	Jans17_1.end = f3(600.1f, 5.0f, 570.0f);
	blist.push_back(Jans17_1);

	BoundingBox Jans17_2;
	Jans17_2.start = f3(799.9f, 0.0f, 550.0f);
	Jans17_2.end = f3(800.1f, 5.0f, 570.0f);
	blist.push_back(Jans17_2);

	// 862.5 311
	BoundingBox Jans18_1;
	Jans18_1.start = f3(854.5f, 0.0f, 303.0f);
	Jans18_1.end = f3(870.5f, 8.0f, 319.0f);
	blist.push_back(Jans18_1);

	BoundingBox Jans18_2;
	Jans18_2.start = f3(854.5f, 0.0f, 324.5f);
	Jans18_2.end = f3(870.5f, 8.0f, 340.5f);
	blist.push_back(Jans18_2);

	BoundingBox Jans18_3;
	Jans18_3.start = f3(854.5f, 0.0f, 346.0f);
	Jans18_3.end = f3(870.5f, 8.0f, 362.0f);
	blist.push_back(Jans18_3);

	BoundingBox Jans18_4;
	Jans18_4.start = f3(854.5f, 0.0f, 367.5f);
	Jans18_4.end = f3(870.5f, 8.0f, 383.5f);
	blist.push_back(Jans18_4);


	///////////////////////////////////////


	BoundingBox Jans18_5;
	Jans18_5.start = f3(814.5f, 0.0f, 303.0f);
	Jans18_5.end = f3(830.5f, 8.0f, 319.0f);
	blist.push_back(Jans18_5);

	BoundingBox Jans18_6;
	Jans18_6.start = f3(814.5f, 0.0f, 324.5f);
	Jans18_6.end = f3(830.5f, 8.0f, 340.5f);
	blist.push_back(Jans18_6);

	BoundingBox Jans18_7;
	Jans18_7.start = f3(814.5f, 0.0f, 346.0f);
	Jans18_7.end = f3(830.5f, 8.0f, 362.0f);
	blist.push_back(Jans18_7);

	BoundingBox Jans18_8;
	Jans18_8.start = f3(814.5f, 0.0f, 367.5f);
	Jans18_8.end = f3(830.5f, 8.0f, 383.5f);
	blist.push_back(Jans18_8);

	//////////////////////////////////////////////

	BoundingBox Jans18_9;
	Jans18_9.start = f3(854.5f, 0.0f, 403.0f);
	Jans18_9.end = f3(870.5f, 8.0f, 419.0f);
	blist.push_back(Jans18_9);

	BoundingBox Jans18_10;
	Jans18_10.start = f3(854.5f, 0.0f, 424.5f);
	Jans18_10.end = f3(870.5f, 8.0f, 440.5f);
	blist.push_back(Jans18_10);

	BoundingBox Jans18_11;
	Jans18_11.start = f3(854.5f, 0.0f, 446.0f);
	Jans18_11.end = f3(870.5f, 8.0f, 462.0f);
	blist.push_back(Jans18_11);

	BoundingBox Jans18_12;
	Jans18_12.start = f3(854.5f, 0.0f, 467.5f);
	Jans18_12.end = f3(870.5f, 8.0f, 483.5f);
	blist.push_back(Jans18_12);


	///////////////////////////////////////////////////


	BoundingBox Jans18_13;
	Jans18_13.start = f3(814.5f, 0.0f, 403.0f);
	Jans18_13.end = f3(830.5f, 8.0f, 419.0f);
	blist.push_back(Jans18_13);

	BoundingBox Jans18_14;
	Jans18_14.start = f3(814.5f, 0.0f, 424.5f);
	Jans18_14.end = f3(830.5f, 8.0f, 440.5f);
	blist.push_back(Jans18_14);

	BoundingBox Jans18_15;
	Jans18_15.start = f3(814.5f, 0.0f, 446.0f);
	Jans18_15.end = f3(830.5f, 8.0f, 462.0f);
	blist.push_back(Jans18_15);

	BoundingBox Jans18_16;
	Jans18_16.start = f3(814.5f, 0.0f, 467.5f);
	Jans18_16.end = f3(830.5f, 8.0f, 483.5f);
	blist.push_back(Jans18_16);

	// 930 75
	BoundingBox Jans19_1;
	Jans19_1.start = f3(856.0f, 0.0f, 131.0f);
	Jans19_1.end = f3(864.0f, 2.5f, 139.0f);
	blist.push_back(Jans19_1);

	// 826 164
	BoundingBox Jans19_2;
	Jans19_2.start = f3(822.0f, 0.0f, 160.0f);
	Jans19_2.end = f3(830.0f, 2.3f, 168.0f);
	blist.push_back(Jans19_2);

	// 845 200.5
	BoundingBox Jans19_3;
	Jans19_3.start = f3(841.0f, 0.0f, 196.5f);
	Jans19_3.end = f3(849.0f, 2.8f, 204.5f);
	blist.push_back(Jans19_3);

	// 869.5f, 210.0f
	BoundingBox Jans19_4;
	Jans19_4.start = f3(865.5f, 0.0f, 206.0f);
	Jans19_4.end = f3(873.5f, 2.5f, 214.0f);
	blist.push_back(Jans19_4);

	// 821 1.5, 210
	BoundingBox Jans19_5;
	Jans19_5.start = f3(817.0f, 0.0f, 206.0f);
	Jans19_5.end = f3(825.0f, 4.0f, 214.0f);
	blist.push_back(Jans19_5);

	BoundingBox Jans19_6;
	Jans19_6.start = f3(835.0f, 0.0f, 241.0f);
	Jans19_6.end = f3(843.0f, 2.5f, 249.0f);
	blist.push_back(Jans19_6);

	BoundingBox Jans19_7;
	Jans19_7.start = f3(852.5f, 0.0f, 245.0f);
	Jans19_7.end = f3(860.5f, 2.5f, 253.0f);
	blist.push_back(Jans19_7);

	BoundingBox Jans19_8;
	Jans19_8.start = f3(862.0f, 0.0f, 225.0f);
	Jans19_8.end = f3(870.0f, 2.5f, 233.0f);
	blist.push_back(Jans19_8);

	BoundingBox Jans19_9;
	Jans19_9.start = f3(829.0f, 0.0f, 223.0f);
	Jans19_9.end = f3(837.0f, 2.5f, 231.0f);
	blist.push_back(Jans19_9);

	BoundingBox Jans19_10;
	Jans19_10.start = f3(827.0f, 0.0f, 270.5f);
	Jans19_10.end = f3(835.0f, 2.5f, 278.5f);
	blist.push_back(Jans19_10);

	BoundingBox Jans19_11;
	Jans19_11.start = f3(845.5f, 0.0f, 265.8f);
	Jans19_11.end = f3(853.5f, 2.5f, 273.8f);
	blist.push_back(Jans19_11);

	BoundingBox Jans19_12;
	Jans19_12.start = f3(835.2f, 0.0f, 176.0f);
	Jans19_12.end = f3(843.2f, 2.5f, 184.0f);
	blist.push_back(Jans19_12);

	BoundingBox Jans19_13;
	Jans19_13.start = f3(861.5f, 0.0f, 153.0f);
	Jans19_13.end = f3(869.5f, 2.5f, 161.0f);
	blist.push_back(Jans19_13);

	BoundingBox Jans20_1;
	Jans20_1.start = f3(881.5f, 0.0f, 155.5f);
	Jans20_1.end = f3(888.5f, 3.0f, 162.5f);
	blist.push_back(Jans20_1);

	BoundingBox Jans20_2;
	Jans20_2.start = f3(895.5f, 0.0f, 143.0f);
	Jans20_2.end = f3(902.5f, 3.0f, 150.0f);
	blist.push_back(Jans20_2);

	BoundingBox Jans20_3;
	Jans20_3.start = f3(914.0f, 0.0f, 164.5f);
	Jans20_3.end = f3(921.0f, 3.0f, 171.5f);
	blist.push_back(Jans20_3);

	BoundingBox Jans20_4;
	Jans20_4.start = f3(896.5f, 0.0f, 192.5f);
	Jans20_4.end = f3(903.5f, 3.0f, 199.5f);
	blist.push_back(Jans20_4);

	BoundingBox Jans20_5;
	Jans20_5.start = f3(931.0f, 0.0f, 167.5f);
	Jans20_5.end = f3(938.0f, 3.0f, 174.5f);
	blist.push_back(Jans20_5);

	BoundingBox Jans20_6;
	Jans20_6.start = f3(945.5f, 0.0f, 161.5f);
	Jans20_6.end = f3(952.5f, 3.0f, 168.5f);
	blist.push_back(Jans20_6);

	BoundingBox Jans20_7;
	Jans20_7.start = f3(981.5f, 0.0f, 156.5f);
	Jans20_7.end = f3(988.5f, 3.0f, 163.5f);
	blist.push_back(Jans20_7);

	BoundingBox Jans20_8;
	Jans20_8.start = f3(1006.0f, 0.0f, 171.5f);
	Jans20_8.end = f3(1013.0f, 3.0f, 178.5f);
	blist.push_back(Jans20_8);

	BoundingBox Jans20_9;
	Jans20_9.start = f3(921.0f, 0.0f, 177.5f);
	Jans20_9.end = f3(928.0f, 3.0f, 184.5f);
	blist.push_back(Jans20_9);

	BoundingBox Jans20_10;
	Jans20_10.start = f3(947.5f, 0.0f, 188.5f);
	Jans20_10.end = f3(954.5f, 3.0f, 195.5f);
	blist.push_back(Jans20_10);

	BoundingBox Jans20_11;
	Jans20_11.start = f3(970.5f, 0.0f, 185.0f);
	Jans20_11.end = f3(977.5f, 3.0f, 192.0f);
	blist.push_back(Jans20_11);

	BoundingBox Jans20_12;
	Jans20_12.start = f3(998.5f, 0.0f, 181.5f);
	Jans20_12.end = f3(1005.5f, 3.0f, 188.5f);
	blist.push_back(Jans20_12);

	BoundingBox Jans21_1;
	Jans21_1.start = f3(1008.5f, 12.5f, 275.0f);
	Jans21_1.end = f3(1011.5f, 15.5f, 295.0f);
	blist.push_back(Jans21_1);

	BoundingBox Jans21_2;
	Jans21_2.start = f3(1008.5f, 12.5f, 295.0f);
	Jans21_2.end = f3(1011.5f, 15.5f, 315.0f);
	blist.push_back(Jans21_2);

	BoundingBox Jans21_3;
	Jans21_3.start = f3(1008.5f, 12.5f, 315.0f);
	Jans21_3.end = f3(1011.5f, 15.5f, 335.0f);
	blist.push_back(Jans21_3);

	BoundingBox Jans21_4;
	Jans21_4.start = f3(1008.5f, 12.5f, 335.0f);
	Jans21_4.end = f3(1011.5f, 15.5f, 355.0f);
	blist.push_back(Jans21_4);

	BoundingBox Jans21_5;
	Jans21_5.start = f3(1008.5f, 12.5f, 355.0f);
	Jans21_5.end = f3(1011.5f, 15.5f, 375.0f);
	blist.push_back(Jans21_5);

	BoundingBox Jans21_6;
	Jans21_6.start = f3(1008.5f, 12.5f, 375.0f);
	Jans21_6.end = f3(1011.5f, 15.5f, 395.0f);
	blist.push_back(Jans21_6);

	BoundingBox Jans21_7;
	Jans21_7.start = f3(1008.5f, 12.5f, 395.0f);
	Jans21_7.end = f3(1011.5f, 15.5f, 415.0f);
	blist.push_back(Jans21_7);

	BoundingBox Jans21_8;
	Jans21_8.start = f3(1008.5f, 12.5f, 415.0f);
	Jans21_8.end = f3(1011.5f, 15.5f, 435.0f);
	blist.push_back(Jans21_8);

	BoundingBox Jans21_9;
	Jans21_9.start = f3(1008.5f, 12.5f, 435.0f);
	Jans21_9.end = f3(1011.5f, 15.5f, 455.0f);
	blist.push_back(Jans21_9);

	BoundingBox Jans21_10;
	Jans21_10.start = f3(1008.5f, 12.5f, 455.0f);
	Jans21_10.end = f3(1011.5f, 15.5f, 475.0f);
	blist.push_back(Jans21_10);

	BoundingBox Jans21_11;
	Jans21_11.start = f3(1008.5f, 12.5f, 475.0f);
	Jans21_11.end = f3(1011.5f, 15.5f, 495.0f);
	blist.push_back(Jans21_11);

	BoundingBox Jans21_12;
	Jans21_12.start = f3(1008.5f, 12.5f, 495.0f);
	Jans21_12.end = f3(1011.5f, 15.5f, 515.0f);
	blist.push_back(Jans21_12);

	BoundingBox Jans22_1;
	Jans22_1.start = f3(930.0f, 12.5f, 535.0f);
	Jans22_1.end = f3(960.0f, 17.5f, 555.0f);
	blist.push_back(Jans22_1);

	BoundingBox Jans22_2;
	Jans22_2.start = f3(975.0f, 12.5f, 535.0f);
	Jans22_2.end = f3(1005.0f, 17.5f, 555.0f);
	blist.push_back(Jans22_2);


	BoundingBox Jans22_3;
	Jans22_3.start = f3(1020.0f, 12.5f, 535.0f);
	Jans22_3.end = f3(1050.0f, 17.5f, 555.0f);
	blist.push_back(Jans22_3);

	BoundingBox Jans22_4;
	Jans22_4.start = f3(1065.0f, 12.5f, 535.0f);
	Jans22_4.end = f3(1095.0f, 17.5f, 555.0f);
	blist.push_back(Jans22_4);

	// 1040 200
	BoundingBox Jans23_1;
	Jans23_1.start = f3(1037.0f, 0.0f, 197.0f);
	Jans23_1.end = f3(1043.0f, 3.0f, 203.0f);
	blist.push_back(Jans23_1);

	BoundingBox Jans23_2;
	Jans23_2.start = f3(1074.0f, 0.0f, 181.0f);
	Jans23_2.end = f3(1080.0f, 3.0f, 187.0f);
	blist.push_back(Jans23_2);

	BoundingBox Jans23_3;
	Jans23_3.start = f3(1056.0f, 0.0f, 169.0f);
	Jans23_3.end = f3(1062.0f, 3.0f, 175.0f);
	blist.push_back(Jans23_3);

	BoundingBox Jans23_4;
	Jans23_4.start = f3(1082.0f, 0.0f, 156.5f);
	Jans23_4.end = f3(1088.0f, 3.0f, 162.5f);
	blist.push_back(Jans23_4);

	BoundingBox Jans23_5;
	Jans23_5.start = f3(1060.0f, 0.0f, 153.0f);
	Jans23_5.end = f3(1066.0f, 3.0f, 159.0f);
	blist.push_back(Jans23_5);

	BoundingBox Jans23_6;
	Jans23_6.start = f3(1056.0f, 0.0f, 196.0f);
	Jans23_6.end = f3(1062.0f, 3.0f, 202.0f);
	blist.push_back(Jans23_6);

	BoundingBox Jans23_7;
	Jans23_7.start = f3(1074.0f, 0.0f, 203.0f);
	Jans23_7.end = f3(1080.0f, 3.0f, 209.0f);
	blist.push_back(Jans23_7);

	BoundingBox Jans23_8;
	Jans23_8.start = f3(1108.0f, 0.0f, 194.0f);
	Jans23_8.end = f3(1114.0f, 3.0f, 200.0f);
	blist.push_back(Jans23_8);

	BoundingBox Jans23_9;
	Jans23_9.start = f3(1085.0f, 0.0f, 218.0f);
	Jans23_9.end = f3(1091.0f, 3.0f, 224.0f);
	blist.push_back(Jans23_9);

	BoundingBox Jans23_10;
	Jans23_10.start = f3(1072.0f, 0.0f, 212.0f);
	Jans23_10.end = f3(1078.0f, 3.0f, 218.0f);
	blist.push_back(Jans23_10);

	BoundingBox Jans23_11;
	Jans23_11.start = f3(1097.0f, 0.0f, 206.0f);
	Jans23_11.end = f3(1103.0f, 3.0f, 212.0f);
	blist.push_back(Jans23_11);

	BoundingBox Jans23_12;
	Jans23_12.start = f3(1123.0f, 0.0f, 141.0f);
	Jans23_12.end = f3(1129.0f, 3.0f, 147.0f);
	blist.push_back(Jans23_12);

	BoundingBox Jans23_13;
	Jans23_13.start = f3(1116.0f, 0.0f, 153.0f);
	Jans23_13.end = f3(1122.0f, 3.0f, 159.0f);
	blist.push_back(Jans23_13);

	BoundingBox Jans23_14;
	Jans23_14.start = f3(1127.0f, 0.0f, 172.0f);
	Jans23_14.end = f3(1133.0f, 3.0f, 178.0f);
	blist.push_back(Jans23_14);


	/// <summary
	/// </summary>
	/// <param name="list"></param>
	/// <param name="blist"></param>
	/// 
	/// 

	BoundingBox Dongle1;
	Dongle1.start = f3(1235.0f, 0.0f, 305.0f);
	Dongle1.end = f3(1285.0f, 15.0f, 355.0f);
	blist.push_back(Dongle1);

	BoundingBox Dongle2;
	Dongle2.start = f3(1235.0f, 0.0f, 375.0f);
	Dongle2.end = f3(1285.0f, 15.0f, 425.0f);
	blist.push_back(Dongle2);

	BoundingBox Dongle3;
	Dongle3.start = f3(1300.0f, 0.0f, 525.0f);
	Dongle3.end = f3(1350.0f, 15.0f, 575.0f);
	blist.push_back(Dongle3);




	BoundingBox kingdo1[8];
	for (int i = 0; i < 8; ++i)
	{
		kingdo1[i].start = f3(817.5f + (25.0f * i), 0.0f, 112.5f);
		kingdo1[i].end = f3(832.5f + (25.0f * i), 12.5f, 127.5f);
		blist.push_back(kingdo1[i]);
	}

	BoundingBox kingdo2[8];
	for (int i = 0; i < 8; ++i)
	{
		kingdo2[i].start = f3(817.5f + (25.0f * i), 0.0f, 82.5f);
		kingdo2[i].end = f3(832.5f + (25.0f * i), 12.5f, 97.5f);
		blist.push_back(kingdo2[i]);
	}


	BoundingBox Bals2[3];
	for (int i = 0; i < 3; ++i)
	{
		Bals2[i].start = f3(540.0f, 0.0f, 305.0f + (30.0f * i));
		Bals2[i].end = f3(600.0f, 6.0f, 335.0f + (30.0f * i));
		blist.push_back(Bals2[i]);
	}

	BoundingBox Bals[3];
	for (int i = 0; i < 3; ++i)
	{
		Bals[i].start = f3(290.0f, 0.0f, 230.0f + (120.0f * i));
		Bals[i].end = f3(320.0f, 10.0f, 330.0f + (120.0f * i));
		blist.push_back(Bals[i]);
	}

	BoundingBox T_wall1[2];
	for (int i = 0; i < 2; ++i)
	{
		T_wall1[i].start = f3(280.0f + (25.0f * i), 0.0f, 220.0f);
		T_wall1[i].end = f3(305.0f + (25.0f * i), 2.8f, 221.2f);
		blist.push_back(T_wall1[i]);
	}

	BoundingBox T_Wall2[10];
	for (int i = 0; i < 10; ++i)
	{
		T_Wall2[i].start = f3(328.8f, 0.0f, 220.0f + (38.0f * i));
		T_Wall2[i].end = f3(330.0f, 2.8f, 258.0f + (38.0f * i));
		blist.push_back(T_Wall2[i]);
	}

	BoundingBox TrashBag1[3];
	for (int i = 0; i < 3; ++i)
	{
		TrashBag1[i].start = f3(413.5f + (5.0f * i), 2.7f, 493.0f);
		TrashBag1[i].end = f3(418.5f + (5.0f * i), 4.3f, 498.0f);
		blist.push_back(TrashBag1[i]);

	}

	BoundingBox TrashBag2[3];
	for (int i = 0; i < 3; ++i)
	{
		TrashBag2[i].start = f3(438.5f + (5.0f * i), 2.7f, 493.0f);
		TrashBag2[i].end = f3(443.5f + (5.0f * i), 4.3f, 498.0f);
		blist.push_back(TrashBag2[i]);

	}

	BoundingBox TrashBag3[3];
	for (int i = 0; i < 3; ++i)
	{
		TrashBag3[i].start = f3(463.5f + (5.0f * i), 2.7f, 493.0f);
		TrashBag3[i].end = f3(468.5f + (5.0f * i), 4.3f, 498.0f);
		blist.push_back(TrashBag3[i]);

	}

	BoundingBox TrashBag4[3];
	for (int i = 0; i < 3; ++i)
	{
		TrashBag4[i].start = f3(488.5f + (5.0f * i), 2.7f, 493.0f);
		TrashBag4[i].end = f3(493.5f + (5.0f * i), 4.3f, 498.0f);
		blist.push_back(TrashBag4[i]);

	}

	BoundingBox TrashBag5[3];
	for (int i = 0; i < 3; ++i)
	{
		TrashBag5[i].start = f3(513.5f + (5.0f * i), 2.7f, 493.0f);
		TrashBag5[i].end = f3(518.5f + (5.0f * i), 4.3f, 498.0f);
		blist.push_back(TrashBag5[i]);

	}



	BoundingBox SwaMul1[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1[i].start = f3(448.5f + (3.0f * i), 2.7f, 292.25f);
		SwaMul1[i].end = f3(451.5f + (3.0f * i), 3.5f, 293.75f);
		blist.push_back(SwaMul1[i]);
	}


	BoundingBox SwaMul2[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2[i].start = f3(448.5f + (3.0f * i), 2.7f, 290.75f);
		SwaMul2[i].end = f3(451.5f + (3.0f * i), 3.5f, 292.25f);
		blist.push_back(SwaMul2[i]);
	}


	BoundingBox SwaMul3[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3[i].start = f3(448.5f + (3.0f * i), 2.7f, 289.25f);
		SwaMul3[i].end = f3(451.5f + (3.0f * i), 3.5f, 290.75f);
		blist.push_back(SwaMul3[i]);
	}


	BoundingBox SwaMul4[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4[i].start = f3(448.5f + (3.0f * i), 2.7f, 287.75f);
		SwaMul4[i].end = f3(451.5f + (3.0f * i), 3.5f, 289.25f);
		blist.push_back(SwaMul4[i]);
	}


	BoundingBox SwaMul1_m[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_m[i].start = f3(448.5f + (3.0f * i), 3.5f, 292.25f);
		SwaMul1_m[i].end = f3(451.5f + (3.0f * i), 4.3f, 293.75f);
		blist.push_back(SwaMul1_m[i]);
	}

	BoundingBox SwaMul2_m[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_m[i].start = f3(448.5f + (3.0f * i), 3.5f, 290.75f);
		SwaMul2_m[i].end = f3(451.5f + (3.0f * i), 4.3f, 292.25f);
		blist.push_back(SwaMul2_m[i]);
	}


	BoundingBox SwaMul3_m[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_m[i].start = f3(448.5f + (3.0f * i), 3.5f, 289.25f);
		SwaMul3_m[i].end = f3(451.5f + (3.0f * i), 4.3f, 290.75f);
		blist.push_back(SwaMul3_m[i]);
	}


	BoundingBox SwaMul4_m[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_m[i].start = f3(448.5f + (3.0f * i), 3.5f, 287.75f);
		SwaMul4_m[i].end = f3(451.5f + (3.0f * i), 4.3f, 289.25f);
		blist.push_back(SwaMul4_m[i]);
	}

	BoundingBox SwaMul1_h[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_h[i].start = f3(448.5f + (3.0f * i), 4.3f, 292.25f);
		SwaMul1_h[i].end = f3(451.5f + (3.0f * i), 5.1f, 293.75f);
		blist.push_back(SwaMul1_h[i]);
	}

	BoundingBox SwaMul2_h[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_h[i].start = f3(448.5f + (3.0f * i), 4.3f, 290.75f);
		SwaMul2_h[i].end = f3(451.5f + (3.0f * i), 5.1f, 292.25f);
		blist.push_back(SwaMul2_h[i]);
	}

	BoundingBox SwaMul3_h[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_h[i].start = f3(448.5f + (3.0f * i), 4.3f, 289.25f);
		SwaMul3_h[i].end = f3(451.5f + (3.0f * i), 5.1f, 290.75f);
		blist.push_back(SwaMul3_h[i]);
	}


	BoundingBox SwaMul4_h[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_h[i].start = f3(448.5f + (3.0f * i), 4.3f, 287.75f);
		SwaMul4_h[i].end = f3(451.5f + (3.0f * i), 5.1f, 289.25f);
		blist.push_back(SwaMul4_h[i]);
	}





	//////////////////////////////////



	BoundingBox SwaMul1a[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1a[i].start = f3(448.5f + (3.0f * i) + 25.0f, 2.7f, 292.25f);
		SwaMul1a[i].end = f3(451.5f + (3.0f * i) + 25.0f, 3.5f, 293.75f);
		blist.push_back(SwaMul1a[i]);
	}


	BoundingBox SwaMul2a[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2a[i].start = f3(448.5f + 25.0f + (3.0f * i), 2.7f, 290.75f);
		SwaMul2a[i].end = f3(451.5f + 25.0f + (3.0f * i), 3.5f, 292.25f);
		blist.push_back(SwaMul2a[i]);
	}


	BoundingBox SwaMul3a[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3a[i].start = f3(448.5f + 25.0f + (3.0f * i), 2.7f, 289.25f);
		SwaMul3a[i].end = f3(451.5f + 25.0f + (3.0f * i), 3.5f, 290.75f);
		blist.push_back(SwaMul3a[i]);
	}


	BoundingBox SwaMul4a[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4a[i].start = f3(448.5f + 25.0f + (3.0f * i), 2.7f, 287.75f);
		SwaMul4a[i].end = f3(451.5f + 25.0f + (3.0f * i), 3.5f, 289.25f);
		blist.push_back(SwaMul4a[i]);
	}


	BoundingBox SwaMul1_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_ma[i].start = f3(448.5f + 25.0f + (3.0f * i), 3.5f, 292.25f);
		SwaMul1_ma[i].end = f3(451.5f + 25.0f + (3.0f * i), 4.3f, 293.75f);
		blist.push_back(SwaMul1_ma[i]);
	}

	BoundingBox SwaMul2_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_ma[i].start = f3(448.5f + 25.0f + (3.0f * i), 3.5f, 290.75f);
		SwaMul2_ma[i].end = f3(451.5f + 25.0f + (3.0f * i), 4.3f, 292.25f);
		blist.push_back(SwaMul2_ma[i]);
	}


	BoundingBox SwaMul3_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_ma[i].start = f3(448.5f + 25.0f + (3.0f * i), 3.5f, 289.25f);
		SwaMul3_ma[i].end = f3(451.5f + 25.0f + (3.0f * i), 4.3f, 290.75f);
		blist.push_back(SwaMul3_ma[i]);
	}


	BoundingBox SwaMul4_ma[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_ma[i].start = f3(448.5f + 25.0f + (3.0f * i), 3.5f, 287.75f);
		SwaMul4_ma[i].end = f3(451.5f + 25.0f + (3.0f * i), 4.3f, 289.25f);
		blist.push_back(SwaMul4_ma[i]);
	}

	BoundingBox SwaMul1_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_ha[i].start = f3(448.5f + 25.0f + (3.0f * i), 4.3f, 292.25f);
		SwaMul1_ha[i].end = f3(451.5f + 25.0f + (3.0f * i), 5.1f, 293.75f);
		blist.push_back(SwaMul1_ha[i]);
	}

	BoundingBox SwaMul2_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_ha[i].start = f3(448.5f + 25.0f + (3.0f * i), 4.3f, 290.75f);
		SwaMul2_ha[i].end = f3(451.5f + 25.0f + (3.0f * i), 5.1f, 292.25f);
		blist.push_back(SwaMul2_ha[i]);
	}

	BoundingBox SwaMul3_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_ha[i].start = f3(448.5f + 25.0f + (3.0f * i), 4.3f, 289.25f);
		SwaMul3_ha[i].end = f3(451.5f + 25.0f + (3.0f * i), 5.1f, 290.75f);
		blist.push_back(SwaMul3_ha[i]);
	}


	BoundingBox SwaMul4_ha[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_ha[i].start = f3(448.5f + 25.0f + (3.0f * i), 4.3f, 287.75f);
		SwaMul4_ha[i].end = f3(451.5f + 25.0f + (3.0f * i), 5.1f, 289.25f);
		blist.push_back(SwaMul4_ha[i]);
	}




	////////////////////////////////


	BoundingBox SwaMul1b[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1b[i].start = f3(448.5f + (3.0f * i) + 50.0f, 2.7f, 292.25f);
		SwaMul1b[i].end = f3(451.5f + (3.0f * i) + 50.0f, 3.5f, 293.75f);
		blist.push_back(SwaMul1b[i]);
	}


	BoundingBox SwaMul2b[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2b[i].start = f3(448.5f + 50.0f + (3.0f * i), 2.7f, 290.75f);
		SwaMul2b[i].end = f3(451.5f + 50.0f + (3.0f * i), 3.5f, 292.25f);
		blist.push_back(SwaMul2b[i]);
	}


	BoundingBox SwaMul3b[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3b[i].start = f3(448.5f + 50.0f + (3.0f * i), 2.7f, 289.25f);
		SwaMul3b[i].end = f3(451.5f + 50.0f + (3.0f * i), 3.5f, 290.75f);
		blist.push_back(SwaMul3b[i]);
	}


	BoundingBox SwaMul4b[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4b[i].start = f3(448.5f + 50.0f + (3.0f * i), 2.7f, 287.75f);
		SwaMul4b[i].end = f3(451.5f + 50.0f + (3.0f * i), 3.5f, 289.25f);
		blist.push_back(SwaMul4b[i]);
	}


	BoundingBox SwaMul1_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_mb[i].start = f3(448.5f + 50.0f + (3.0f * i), 3.5f, 292.25f);
		SwaMul1_mb[i].end = f3(451.5f + 50.0f + (3.0f * i), 4.3f, 293.75f);
		blist.push_back(SwaMul1_mb[i]);
	}

	BoundingBox SwaMul2_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_mb[i].start = f3(448.5f + 50.0f + (3.0f * i), 3.5f, 290.75f);
		SwaMul2_mb[i].end = f3(451.5f + 50.0f + (3.0f * i), 4.3f, 292.25f);
		blist.push_back(SwaMul2_mb[i]);
	}


	BoundingBox SwaMul3_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_mb[i].start = f3(448.5f + 50.0f + (3.0f * i), 3.5f, 289.25f);
		SwaMul3_mb[i].end = f3(451.5f + 50.0f + (3.0f * i), 4.3f, 290.75f);
		blist.push_back(SwaMul3_mb[i]);
	}


	BoundingBox SwaMul4_mb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_mb[i].start = f3(448.5f + 50.0f + (3.0f * i), 3.5f, 287.75f);
		SwaMul4_mb[i].end = f3(451.5f + 50.0f + (3.0f * i), 4.3f, 289.25f);
		blist.push_back(SwaMul4_mb[i]);
	}

	BoundingBox SwaMul1_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_hb[i].start = f3(448.5f + 50.0f + (3.0f * i), 4.3f, 292.25f);
		SwaMul1_hb[i].end = f3(451.5f + 50.0f + (3.0f * i), 5.1f, 293.75f);
		blist.push_back(SwaMul1_hb[i]);
	}

	BoundingBox SwaMul2_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_hb[i].start = f3(448.5f + 50.0f + (3.0f * i), 4.3f, 290.75f);
		SwaMul2_hb[i].end = f3(451.5f + 50.0f + (3.0f * i), 5.1f, 292.25f);
		blist.push_back(SwaMul2_hb[i]);
	}

	BoundingBox SwaMul3_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_hb[i].start = f3(448.5f + 50.0f + (3.0f * i), 4.3f, 289.25f);
		SwaMul3_hb[i].end = f3(451.5f + 50.0f + (3.0f * i), 5.1f, 290.75f);
		blist.push_back(SwaMul3_hb[i]);
	}


	BoundingBox SwaMul4_hb[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_hb[i].start = f3(448.5f + 50.0f + (3.0f * i), 4.3f, 287.75f);
		SwaMul4_hb[i].end = f3(451.5f + 50.0f + (3.0f * i), 5.1f, 289.25f);
		blist.push_back(SwaMul4_hb[i]);
	}


	//////////////////////////////////////////////////\\


	BoundingBox SwaMul1c[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1c[i].start = f3(448.5f + (3.0f * i) + 75.0f, 2.7f, 292.25f);
		SwaMul1c[i].end = f3(451.5f + (3.0f * i) + 75.0f, 3.5f, 293.75f);
		blist.push_back(SwaMul1c[i]);
	}


	BoundingBox SwaMul2c[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2c[i].start = f3(448.5f + 75.0f + (3.0f * i), 2.7f, 290.75f);
		SwaMul2c[i].end = f3(451.5f + 75.0f + (3.0f * i), 3.5f, 292.25f);
		blist.push_back(SwaMul2c[i]);
	}


	BoundingBox SwaMul3c[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3c[i].start = f3(448.5f + 75.0f + (3.0f * i), 2.7f, 289.25f);
		SwaMul3c[i].end = f3(451.5f + 75.0f + (3.0f * i), 3.5f, 290.75f);
		blist.push_back(SwaMul3c[i]);
	}


	BoundingBox SwaMul4c[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4c[i].start = f3(448.5f + 75.0f + (3.0f * i), 2.7f, 287.75f);
		SwaMul4c[i].end = f3(451.5f + 75.0f + (3.0f * i), 3.5f, 289.25f);
		blist.push_back(SwaMul4c[i]);
	}


	BoundingBox SwaMul1_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_mc[i].start = f3(448.5f + 75.0f + (3.0f * i), 3.5f, 292.25f);
		SwaMul1_mc[i].end = f3(451.5f + 75.0f + (3.0f * i), 4.3f, 293.75f);
		blist.push_back(SwaMul1_mc[i]);
	}

	BoundingBox SwaMul2_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_mc[i].start = f3(448.5f + 75.0f + (3.0f * i), 3.5f, 290.75f);
		SwaMul2_mc[i].end = f3(451.5f + 75.0f + (3.0f * i), 4.3f, 292.25f);
		blist.push_back(SwaMul2_mc[i]);
	}


	BoundingBox SwaMul3_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_mc[i].start = f3(448.5f + 75.0f + (3.0f * i), 3.5f, 289.25f);
		SwaMul3_mc[i].end = f3(451.5f + 75.0f + (3.0f * i), 4.3f, 290.75f);
		blist.push_back(SwaMul3_mc[i]);
	}


	BoundingBox SwaMul4_mc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_mc[i].start = f3(448.5f + 75.0f + (3.0f * i), 3.5f, 287.75f);
		SwaMul4_mc[i].end = f3(451.5f + 75.0f + (3.0f * i), 4.3f, 289.25f);
		blist.push_back(SwaMul4_mc[i]);
	}

	BoundingBox SwaMul1_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_hc[i].start = f3(448.5f + 75.0f + (3.0f * i), 4.3f, 292.25f);
		SwaMul1_hc[i].end = f3(451.5f + 75.0f + (3.0f * i), 5.1f, 293.75f);
		blist.push_back(SwaMul1_hc[i]);
	}

	BoundingBox SwaMul2_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_hc[i].start = f3(448.5f + 75.0f + (3.0f * i), 4.3f, 290.75f);
		SwaMul2_hc[i].end = f3(451.5f + 75.0f + (3.0f * i), 5.1f, 292.25f);
		blist.push_back(SwaMul2_hc[i]);
	}

	BoundingBox SwaMul3_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_hc[i].start = f3(448.5f + 75.0f + (3.0f * i), 4.3f, 289.25f);
		SwaMul3_hc[i].end = f3(451.5f + 75.0f + (3.0f * i), 5.1f, 290.75f);
		blist.push_back(SwaMul3_hc[i]);
	}


	BoundingBox SwaMul4_hc[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_hc[i].start = f3(448.5f + 75.0f + (3.0f * i), 4.3f, 287.75f);
		SwaMul4_hc[i].end = f3(451.5f + 75.0f + (3.0f * i), 5.1f, 289.25f);
		blist.push_back(SwaMul4_hc[i]);
	}


	//////////////////////////////////////////////////


	BoundingBox SwaMul1d[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1d[i].start = f3(448.5f + (3.0f * i) + 100.0f, 2.7f, 292.25f);
		SwaMul1d[i].end = f3(451.5f + (3.0f * i) + 100.0f, 3.5f, 293.75f);
		blist.push_back(SwaMul1d[i]);
	}


	BoundingBox SwaMul2d[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2d[i].start = f3(448.5f + 100.0f + (3.0f * i), 2.7f, 290.75f);
		SwaMul2d[i].end = f3(451.5f + 100.0f + (3.0f * i), 3.5f, 292.25f);
		blist.push_back(SwaMul2d[i]);
	}


	BoundingBox SwaMul3d[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3d[i].start = f3(448.5f + 100.0f + (3.0f * i), 2.7f, 289.25f);
		SwaMul3d[i].end = f3(451.5f + 100.0f + (3.0f * i), 3.5f, 290.75f);
		blist.push_back(SwaMul3d[i]);
	}


	BoundingBox SwaMul4d[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4d[i].start = f3(448.5f + 100.0f + (3.0f * i), 2.7f, 287.75f);
		SwaMul4d[i].end = f3(451.5f + 100.0f + (3.0f * i), 3.5f, 289.25f);
		blist.push_back(SwaMul4d[i]);
	}


	BoundingBox SwaMul1_md[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_md[i].start = f3(448.5f + 100.0f + (3.0f * i), 3.5f, 292.25f);
		SwaMul1_md[i].end = f3(451.5f + 100.0f + (3.0f * i), 4.3f, 293.75f);
		blist.push_back(SwaMul1_md[i]);
	}

	BoundingBox SwaMul2_md[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_md[i].start = f3(448.5f + 100.0f + (3.0f * i), 3.5f, 290.75f);
		SwaMul2_md[i].end = f3(451.5f + 100.0f + (3.0f * i), 4.3f, 292.25f);
		blist.push_back(SwaMul2_md[i]);
	}


	BoundingBox SwaMul3_md[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_md[i].start = f3(448.5f + 100.0f + (3.0f * i), 3.5f, 289.25f);
		SwaMul3_md[i].end = f3(451.5f + 100.0f + (3.0f * i), 4.3f, 290.75f);
		blist.push_back(SwaMul3_md[i]);
	}


	BoundingBox SwaMul4_md[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_md[i].start = f3(448.5f + 100.0f + (3.0f * i), 3.5f, 287.75f);
		SwaMul4_md[i].end = f3(451.5f + 100.0f + (3.0f * i), 4.3f, 289.25f);
		blist.push_back(SwaMul4_md[i]);
	}

	BoundingBox SwaMul1_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_hd[i].start = f3(448.5f + 100.0f + (3.0f * i), 4.3f, 292.25f);
		SwaMul1_hd[i].end = f3(451.5f + 100.0f + (3.0f * i), 5.1f, 293.75f);
		blist.push_back(SwaMul1_hd[i]);
	}

	BoundingBox SwaMul2_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_hd[i].start = f3(448.5f + 100.0f + (3.0f * i), 4.3f, 290.75f);
		SwaMul2_hd[i].end = f3(451.5f + 100.0f + (3.0f * i), 5.1f, 292.25f);
		blist.push_back(SwaMul2_hd[i]);
	}

	BoundingBox SwaMul3_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_hd[i].start = f3(448.5f + 100.0f + (3.0f * i), 4.3f, 289.25f);
		SwaMul3_hd[i].end = f3(451.5f + 100.0f + (3.0f * i), 5.1f, 290.75f);
		blist.push_back(SwaMul3_hd[i]);
	}


	BoundingBox SwaMul4_hd[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_hd[i].start = f3(448.5f + 100.0f + (3.0f * i), 4.3f, 287.75f);
		SwaMul4_hd[i].end = f3(451.5f + 100.0f + (3.0f * i), 5.1f, 289.25f);
		blist.push_back(SwaMul4_hd[i]);
	}



	/////////////////////////////////////////////////



	BoundingBox SwaMul1e[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1e[i].start = f3(448.5f + (3.0f * i) + 125.0f, 2.7f, 292.25f);
		SwaMul1e[i].end = f3(451.5f + (3.0f * i) + 125.0f, 3.5f, 293.75f);
		blist.push_back(SwaMul1e[i]);
	}


	BoundingBox SwaMul2e[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2e[i].start = f3(448.5f + 125.0f + (3.0f * i), 2.7f, 290.75f);
		SwaMul2e[i].end = f3(451.5f + 125.0f + (3.0f * i), 3.5f, 292.25f);
		blist.push_back(SwaMul2e[i]);
	}


	BoundingBox SwaMul3e[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3e[i].start = f3(448.5f + 125.0f + (3.0f * i), 2.7f, 289.25f);
		SwaMul3e[i].end = f3(451.5f + 125.0f + (3.0f * i), 3.5f, 290.75f);
		blist.push_back(SwaMul3e[i]);
	}


	BoundingBox SwaMul4e[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4e[i].start = f3(448.5f + 125.0f + (3.0f * i), 2.7f, 287.75f);
		SwaMul4e[i].end = f3(451.5f + 125.0f + (3.0f * i), 3.5f, 289.25f);
		blist.push_back(SwaMul4e[i]);
	}


	BoundingBox SwaMul1_me[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_me[i].start = f3(448.5f + 125.0f + (3.0f * i), 3.5f, 292.25f);
		SwaMul1_me[i].end = f3(451.5f + 125.0f + (3.0f * i), 4.3f, 293.75f);
		blist.push_back(SwaMul1_me[i]);
	}

	BoundingBox SwaMul2_me[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_me[i].start = f3(448.5f + 125.0f + (3.0f * i), 3.5f, 290.75f);
		SwaMul2_me[i].end = f3(451.5f + 125.0f + (3.0f * i), 4.3f, 292.25f);
		blist.push_back(SwaMul2_me[i]);
	}


	BoundingBox SwaMul3_me[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_me[i].start = f3(448.5f + 125.0f + (3.0f * i), 3.5f, 289.25f);
		SwaMul3_me[i].end = f3(451.5f + 125.0f + (3.0f * i), 4.3f, 290.75f);
		blist.push_back(SwaMul3_me[i]);
	}


	BoundingBox SwaMul4_me[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_me[i].start = f3(448.5f + 125.0f + (3.0f * i), 3.5f, 287.75f);
		SwaMul4_me[i].end = f3(451.5f + 125.0f + (3.0f * i), 4.3f, 289.25f);
		blist.push_back(SwaMul4_me[i]);
	}

	BoundingBox SwaMul1_he[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul1_he[i].start = f3(448.5f + 125.0f + (3.0f * i), 4.3f, 292.25f);
		SwaMul1_he[i].end = f3(451.5f + 125.0f + (3.0f * i), 5.1f, 293.75f);
		blist.push_back(SwaMul1_he[i]);
	}

	BoundingBox SwaMul2_he[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul2_he[i].start = f3(448.5f + 125.0f + (3.0f * i), 4.3f, 290.75f);
		SwaMul2_he[i].end = f3(451.5f + 125.0f + (3.0f * i), 5.1f, 292.25f);
		blist.push_back(SwaMul2_he[i]);
	}

	BoundingBox SwaMul3_he[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul3_he[i].start = f3(448.5f + 125.0f + (3.0f * i), 4.3f, 289.25f);
		SwaMul3_he[i].end = f3(451.5f + 125.0f + (3.0f * i), 5.1f, 290.75f);
		blist.push_back(SwaMul3_he[i]);
	}


	BoundingBox SwaMul4_he[7];
	for (int i = 0; i < 7; ++i)
	{
		SwaMul4_he[i].start = f3(448.5f + 125.0f + (3.0f * i), 4.3f, 287.75f);
		SwaMul4_he[i].end = f3(451.5f + 125.0f + (3.0f * i), 5.1f, 289.25f);
		blist.push_back(SwaMul4_he[i]);
	}



	///////////////////////////////////////////////////


	BoundingBox SSonVan2[5];
	for (int i = 0; i < 5; ++i)
	{
		SSonVan2[i].start = f3(413.5f + (25.0f * i), 0.0f, 488.5f);
		SSonVan2[i].end = f3(438.0f + (25.0f * i), 3.5f, 495.5f);
		blist.push_back(SSonVan2[i]);
	}


	BoundingBox SSonVan1[6];
	for (int i = 0; i < 6; ++i)
	{
		SSonVan1[i].start = f3(447.5f + (25.0f * i), 0.0f, 288.5f);
		SSonVan1[i].end = f3(472.5f + (25.0f * i), 3.5f, 295.5f);
		blist.push_back(SSonVan1[i]);
	}

	BoundingBox Cov_tim1[4];
	for (int i = 0; i < 4; ++i)
	{
		Cov_tim1[i].start = f3(1220.0f + (5.0f * i), 0.0f, 30.0f);
		Cov_tim1[i].end = f3(1225.0f + (5.0f * i), 5.0f, 35.0f);
		blist.push_back(Cov_tim1[i]);
	}

	BoundingBox Cov_tim2[4];
	for (int i = 0; i < 4; ++i)
	{
		Cov_tim2[i].start = f3(1220.0f + (5.0f * i), 0.0f, 39.0f);
		Cov_tim2[i].end = f3(1225.0f + (5.0f * i), 5.0f, 44.0f);
		blist.push_back(Cov_tim2[i]);
	}

	BoundingBox Cov_tim3[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim3[i].start = f3(1220.0f + (5.0f * i), 0.0f, 48.0f);
		Cov_tim3[i].end = f3(1225.0f + (5.0f * i), 5.0f, 53.0f);
		blist.push_back(Cov_tim3[i]);
	}

	BoundingBox Cov_tim4[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim4[i].start = f3(1220.0f + (5.0f * i), 0.0f, 57.0f);
		Cov_tim4[i].end = f3(1225.0f + (5.0f * i), 5.0f, 62.0f);
		blist.push_back(Cov_tim4[i]);
	}

	BoundingBox Cov_tim5[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim5[i].start = f3(1220.0f + (5.0f * i), 0.0f, 66.0f);
		Cov_tim5[i].end = f3(1225.0f + (5.0f * i), 5.0f, 71.0f);
		blist.push_back(Cov_tim5[i]);
	}

	BoundingBox Cov_tim6[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim6[i].start = f3(1220.0f + (5.0f * i), 0.0f, 75.0f);
		Cov_tim6[i].end = f3(1225.0f + (5.0f * i), 5.0f, 80.0f);
		blist.push_back(Cov_tim6[i]);
	}

	BoundingBox Cov_tim7[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim7[i].start = f3(1220.0f + (5.0f * i), 0.0f, 84.0f);
		Cov_tim7[i].end = f3(1225.0f + (5.0f * i), 5.0f, 89.0f);
		blist.push_back(Cov_tim7[i]);
	}

	BoundingBox Cov_tim8[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim8[i].start = f3(1220.0f + (5.0f * i), 0.0f, 93.0f);
		Cov_tim8[i].end = f3(1225.0f + (5.0f * i), 5.0f, 98.0f);
		blist.push_back(Cov_tim8[i]);
	}

	BoundingBox Cov_tim9[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim9[i].start = f3(1220.0f + (5.0f * i), 0.0f, 102.0f);
		Cov_tim9[i].end = f3(1225.0f + (5.0f * i), 5.0f, 107.0f);
		blist.push_back(Cov_tim9[i]);
	}

	BoundingBox Cov_tim10[10];
	for (int i = 0; i < 10; ++i)
	{
		Cov_tim10[i].start = f3(1220.0f + (5.0f * i), 0.0f, 111.0f);
		Cov_tim10[i].end = f3(1225.0f + (5.0f * i), 5.0f, 116.0f);
		blist.push_back(Cov_tim10[i]);
	}





	BoundingBox Cov_jim1[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim1[i].start = f3(1220.0f + (5.0f * i), 0.0f, 545.0f);
		Cov_jim1[i].end = f3(1225.0f + (5.0f * i), 5.0f, 550.0f);
		blist.push_back(Cov_jim1[i]);
	}

	BoundingBox Cov_jim2[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim2[i].start = f3(1220.0f + (5.0f * i), 0.0f, 550.0f);
		Cov_jim2[i].end = f3(1225.0f + (5.0f * i), 5.0f, 555.0f);
		blist.push_back(Cov_jim2[i]);
	}

	BoundingBox Cov_jim3[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim3[i].start = f3(1220.0f + (5.0f * i), 0.0f, 555.0f);
		Cov_jim3[i].end = f3(1225.0f + (5.0f * i), 5.0f, 560.0f);
		blist.push_back(Cov_jim3[i]);
	}

	BoundingBox Cov_jim4[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim4[i].start = f3(1220.0f + (5.0f * i), 0.0f, 560.0f);
		Cov_jim4[i].end = f3(1225.0f + (5.0f * i), 5.0f, 565.0f);
		blist.push_back(Cov_jim4[i]);
	}

	BoundingBox Cov_jim5[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim5[i].start = f3(1220.0f + (5.0f * i), 0.0f, 565.0f);
		Cov_jim5[i].end = f3(1225.0f + (5.0f * i), 5.0f, 570.0f);
		blist.push_back(Cov_jim5[i]);
	}

	BoundingBox Cov_jim6[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim6[i].start = f3(1220.0f + (5.0f * i), 0.0f, 570.0f);
		Cov_jim6[i].end = f3(1225.0f + (5.0f * i), 5.0f, 575.0f);
		blist.push_back(Cov_jim6[i]);
	}

	BoundingBox Cov_jim7[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim7[i].start = f3(1220.0f + (5.0f * i), 0.0f, 480.0f);
		Cov_jim7[i].end = f3(1225.0f + (5.0f * i), 5.0f, 485.0f);
		blist.push_back(Cov_jim7[i]);
	}

	BoundingBox Cov_jim8[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim8[i].start = f3(1220.0f + (5.0f * i), 0.0f, 485.0f);
		Cov_jim8[i].end = f3(1225.0f + (5.0f * i), 5.0f, 490.0f);
		blist.push_back(Cov_jim8[i]);
	}

	BoundingBox Cov_jim9[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim9[i].start = f3(1220.0f + (5.0f * i), 0.0f, 490.0f);
		Cov_jim9[i].end = f3(1225.0f + (5.0f * i), 5.0f, 495.0f);
		blist.push_back(Cov_jim9[i]);
	}

	BoundingBox Cov_jim10[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim10[i].start = f3(1220.0f + (5.0f * i), 0.0f, 495.0f);
		Cov_jim10[i].end = f3(1225.0f + (5.0f * i), 5.0f, 500.0f);
		blist.push_back(Cov_jim10[i]);
	}

	BoundingBox Cov_jim11[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim11[i].start = f3(1220.0f + (5.0f * i), 0.0f, 500.0f);
		Cov_jim11[i].end = f3(1225.0f + (5.0f * i), 5.0f, 505.0f);
		blist.push_back(Cov_jim11[i]);
	}

	BoundingBox Cov_jim12[5];
	for (int i = 0; i < 5; ++i)
	{
		Cov_jim12[i].start = f3(1220.0f + (5.0f * i), 0.0f, 505.0f);
		Cov_jim12[i].end = f3(1225.0f + (5.0f * i), 5.0f, 510.0f);
		blist.push_back(Cov_jim12[i]);
	}


	BoundingBox Dom1[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom1[i].start = f3(420.0f + (5.0f * i), 0.0f, 560.0f);
		Dom1[i].end = f3(425.0f + (5.0f * i), 5.0f, 565.0f);
		blist.push_back(Dom1[i]);
	}

	BoundingBox Dom2[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom2[i].start = f3(420.0f + (5.0f * i), 0.0f, 565.0f);
		Dom2[i].end = f3(425.0f + (5.0f * i), 5.0f, 570.0f);
		blist.push_back(Dom2[i]);
	}

	BoundingBox Dom3[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom3[i].start = f3(450.0f + (5.0f * i), 0.0f, 560.0f);
		Dom3[i].end = f3(455.0f + (5.0f * i), 5.0f, 565.0f);
		blist.push_back(Dom3[i]);
	}

	BoundingBox Dom4[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom4[i].start = f3(450.0f + (5.0f * i), 0.0f, 565.0f);
		Dom4[i].end = f3(455.0f + (5.0f * i), 5.0f, 570.0f);
		blist.push_back(Dom4[i]);
	}

	BoundingBox Dom5[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom5[i].start = f3(420.0f + (5.0f * i), 0.0f, 530.0f);
		Dom5[i].end = f3(425.0f + (5.0f * i), 5.0f, 535.0f);
		blist.push_back(Dom5[i]);
	}

	BoundingBox Dom6[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom6[i].start = f3(420.0f + (5.0f * i), 0.0f, 535.0f);
		Dom6[i].end = f3(425.0f + (5.0f * i), 5.0f, 540.0f);
		blist.push_back(Dom6[i]);
	}

	BoundingBox Dom7[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom7[i].start = f3(450.0f + (5.0f * i), 0.0f, 530.0f);
		Dom7[i].end = f3(455.0f + (5.0f * i), 5.0f, 535.0f);
		blist.push_back(Dom7[i]);
	}

	BoundingBox Dom8[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom8[i].start = f3(450.0f + (5.0f * i), 0.0f, 535.0f);
		Dom8[i].end = f3(455.0f + (5.0f * i), 5.0f, 540.0f);
		blist.push_back(Dom8[i]);
	}



	BoundingBox Dom9[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom9[i].start = f3(480.0f + (5.0f * i), 0.0f, 560.0f);
		Dom9[i].end = f3(485.0f + (5.0f * i), 5.0f, 565.0f);
		blist.push_back(Dom9[i]);
	}

	BoundingBox Dom10[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom10[i].start = f3(480.0f + (5.0f * i), 0.0f, 565.0f);
		Dom10[i].end = f3(485.0f + (5.0f * i), 5.0f, 570.0f);
		blist.push_back(Dom10[i]);
	}

	BoundingBox Dom11[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom11[i].start = f3(510.0f + (5.0f * i), 0.0f, 560.0f);
		Dom11[i].end = f3(515.0f + (5.0f * i), 5.0f, 565.0f);
		blist.push_back(Dom11[i]);
	}

	BoundingBox Dom12[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom12[i].start = f3(510.0f + (5.0f * i), 0.0f, 565.0f);
		Dom12[i].end = f3(515.0f + (5.0f * i), 5.0f, 570.0f);
		blist.push_back(Dom12[i]);
	}

	BoundingBox Dom13[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom13[i].start = f3(480.0f + (5.0f * i), 0.0f, 530.0f);
		Dom13[i].end = f3(485.0f + (5.0f * i), 5.0f, 535.0f);
		blist.push_back(Dom13[i]);
	}

	BoundingBox Dom14[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom14[i].start = f3(480.0f + (5.0f * i), 0.0f, 535.0f);
		Dom14[i].end = f3(485.0f + (5.0f * i), 5.0f, 540.0f);
		blist.push_back(Dom14[i]);
	}

	BoundingBox Dom15[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom15[i].start = f3(510.0f + (5.0f * i), 0.0f, 530.0f);
		Dom15[i].end = f3(515.0f + (5.0f * i), 5.0f, 535.0f);
		blist.push_back(Dom15[i]);
	}

	BoundingBox Dom16[2];

	for (int i = 0; i < 2; ++i)
	{
		Dom16[i].start = f3(510.0f + (5.0f * i), 0.0f, 535.0f);
		Dom16[i].end = f3(515.0f + (5.0f * i), 5.0f, 540.0f);
		blist.push_back(Dom16[i]);
	}


	BoundingBox Edi[20];

	for (int i = 0; i < 20; ++i)
	{
		Edi[i].start = f3(250.0f + (5.0f * i), 0.0f, 2.5f);
		Edi[i].end = f3(255.0f + (5.0f * i), 5.0f, 12.5f);

		blist.push_back(Edi[i]);
	}

	BoundingBox binet1[30];

	for (int i = 0; i < 30; ++i)
	{
		binet1[i].start = f3(401.5f, 0.0f, 300.0f + (3.0f * i));
		binet1[i].end = f3(404.5f, 7.0f, 303.0f + (3.0f * i));

		blist.push_back(binet1[i]);
	}

	BoundingBox Egin1;
	Egin1.start = f3(802.0f, 0.0f, 375.0f);
	Egin1.end = f3(812.0f, 6.0f, 385.0f);

	BoundingBox Egin2;
	Egin2.start = f3(802.0f, 0.0f, 400.0f);
	Egin2.end = f3(812.0f, 6.0f, 410.0f);

	BoundingBox Egin3;
	Egin3.start = f3(802.0f, 0.0f, 425.0f);
	Egin3.end = f3(812.0f, 6.0f, 435.0f);

	BoundingBox Egin4;
	Egin4.start = f3(802.0f, 0.0f, 450.0f);
	Egin4.end = f3(812.0f, 6.0f, 460.0f);

	BoundingBox Egin5;
	Egin5.start = f3(802.0f, 0.0f, 475.0f);
	Egin5.end = f3(812.0f, 6.0f, 485.0f);

	BoundingBox Egin6;
	Egin6.start = f3(802.0f, 0.0f, 500.0f);
	Egin6.end = f3(812.0f, 6.0f, 510.0f);

	BoundingBox Egin7;
	Egin7.start = f3(802.0f, 0.0f, 525.0f);
	Egin7.end = f3(812.0f, 6.0f, 535.0f);



	BoundingBox Pox1;
	Pox1.start = f3(998.5f, 12.5f, 500.0f);
	Pox1.end = f3(1001.5f, 15.5f, 503.0f);

	BoundingBox Pox2;
	Pox2.start = f3(1001.5f, 12.5f, 500.0f);
	Pox2.end = f3(1004.5f, 15.5f, 503.0f);

	BoundingBox Pox3;
	Pox3.start = f3(1004.5f, 12.5f, 500.0f);
	Pox3.end = f3(1007.5f, 15.5f, 503.0f);

	BoundingBox Pox4;
	Pox4.start = f3(1009.0f, 12.5f, 500.0f);
	Pox4.end = f3(1012.0f, 15.5f, 503.0f);

	BoundingBox Pox5;
	Pox5.start = f3(1012.0f, 12.5f, 500.0f);
	Pox5.end = f3(1015.0f, 15.5f, 503.0f);

	BoundingBox Pox6;
	Pox6.start = f3(1015.0f, 12.5f, 500.0f);
	Pox6.end = f3(1018.0f, 15.5f, 503.0f);

	BoundingBox Pox7;
	Pox7.start = f3(1018.0f, 12.5f, 500.0f);
	Pox7.end = f3(1021.0f, 15.5f, 503.0f);

	BoundingBox Pox8;
	Pox8.start = f3(1021.0f, 12.5f, 500.0f);
	Pox8.end = f3(1024.0f, 15.5f, 503.0f);

	BoundingBox Pox9;
	Pox9.start = f3(1024.0f, 12.5f, 500.0f);
	Pox9.end = f3(1027.0f, 15.5f, 503.0f);

	BoundingBox Pox10;
	Pox10.start = f3(1027.0f, 12.5f, 500.0f);
	Pox10.end = f3(1030.0f, 15.5f, 503.0f);

	BoundingBox Pox11;
	Pox11.start = f3(1030.0f, 12.5f, 500.0f);
	Pox11.end = f3(1033.0f, 15.5f, 503.0f);

	BoundingBox Pox12;
	Pox12.start = f3(1060.0f, 12.5f, 500.0f);
	Pox12.end = f3(1063.0f, 15.5f, 503.0f);

	BoundingBox Pox13;
	Pox13.start = f3(1063.0f, 12.5f, 500.0f);
	Pox13.end = f3(1066.0f, 15.5f, 503.0f);

	BoundingBox Pox14;
	Pox14.start = f3(1066.0f, 12.5f, 500.0f);
	Pox14.end = f3(1069.0f, 15.5f, 503.0f);

	BoundingBox Pox15;
	Pox15.start = f3(1069.0f, 12.5f, 500.0f);
	Pox15.end = f3(1072.0f, 15.5f, 503.0f);

	BoundingBox Pox16;
	Pox16.start = f3(1072.0f, 12.5f, 500.0f);
	Pox16.end = f3(1075.0f, 15.5f, 503.0f);

	BoundingBox Pox17;
	Pox17.start = f3(1075.0f, 12.5f, 500.0f);
	Pox17.end = f3(1078.0f, 15.5f, 503.0f);

	BoundingBox Pox18;
	Pox18.start = f3(1078.0f, 12.5f, 500.0f);
	Pox18.end = f3(1081.0f, 15.5f, 503.0f);

	BoundingBox Pox19;
	Pox19.start = f3(1081.0f, 12.5f, 500.0f);
	Pox19.end = f3(1084.0f, 15.5f, 503.0f);

	BoundingBox Pox20;
	Pox20.start = f3(1084.0f, 12.5f, 500.0f);
	Pox20.end = f3(1087.0f, 15.5f, 503.0f);

	BoundingBox Pox21;
	Pox21.start = f3(1087.0f, 12.5f, 500.0f);
	Pox21.end = f3(1090.0f, 15.5f, 503.0f);

	BoundingBox Pox22;
	Pox22.start = f3(1090.0f, 12.5f, 500.0f);
	Pox22.end = f3(1093.0f, 15.5f, 503.0f);

	BoundingBox Coned_1;
	Coned_1.start = f3(910.0f, 12.5f, 296.5f);
	Coned_1.end = f3(1000.0f, 13.5f, 303.5f);

	BoundingBox Coned_2;
	Coned_2.start = f3(910.0f, 12.5f, 311.5f);
	Coned_2.end = f3(1000.0f, 13.5f, 318.5f);

	BoundingBox Coned_3;
	Coned_3.start = f3(910.0f, 12.5f, 326.5f);
	Coned_3.end = f3(1000.0f, 13.5f, 333.5f);

	BoundingBox Coned_4;
	Coned_4.start = f3(910.0f, 12.5f, 341.5f);
	Coned_4.end = f3(1000.0f, 13.5f, 348.5f);

	BoundingBox Coned_5;
	Coned_5.start = f3(910.0f, 12.5f, 356.5f);
	Coned_5.end = f3(1000.0f, 13.5f, 363.5f);

	BoundingBox Coned_6;
	Coned_6.start = f3(910.0f, 12.5f, 371.5f);
	Coned_6.end = f3(1000.0f, 13.5f, 378.5f);

	BoundingBox Coned_7;
	Coned_7.start = f3(910.0f, 12.5f, 386.5f);
	Coned_7.end = f3(1000.0f, 13.5f, 393.5f);

	BoundingBox Coned_8;
	Coned_8.start = f3(910.0f, 12.5f, 401.5f);
	Coned_8.end = f3(1000.0f, 13.5f, 408.5f);

	BoundingBox Coned_9;
	Coned_9.start = f3(910.0f, 12.5f, 416.5f);
	Coned_9.end = f3(1000.0f, 13.5f, 423.5f);

	BoundingBox Coned_10;
	Coned_10.start = f3(910.0f, 12.5f, 431.5f);
	Coned_10.end = f3(1000.0f, 13.5f, 438.5f);

	BoundingBox Coned_11;
	Coned_11.start = f3(910.0f, 12.5f, 446.5f);
	Coned_11.end = f3(1000.0f, 13.5f, 453.5f);

	BoundingBox Coned_12;
	Coned_12.start = f3(1020.0f, 12.5f, 296.5f);
	Coned_12.end = f3(1110.0f, 13.5f, 303.5f);

	BoundingBox Coned_13;
	Coned_13.start = f3(1020.0f, 12.5f, 311.5f);
	Coned_13.end = f3(1110.0f, 13.5f, 318.5f);

	BoundingBox Coned_14;
	Coned_14.start = f3(1020.0f, 12.5f, 326.5f);
	Coned_14.end = f3(1110.0f, 13.5f, 333.5f);

	BoundingBox Coned_15;
	Coned_15.start = f3(1020.0f, 12.5f, 341.5f);
	Coned_15.end = f3(1110.0f, 13.5f, 348.5f);

	BoundingBox Coned_16;
	Coned_16.start = f3(1020.0f, 12.5f, 356.5f);
	Coned_16.end = f3(1110.0f, 13.5f, 363.5f);

	BoundingBox Coned_17;
	Coned_17.start = f3(1020.0f, 12.5f, 371.5f);
	Coned_17.end = f3(1110.0f, 13.5f, 378.5f);

	BoundingBox Coned_18;
	Coned_18.start = f3(1020.0f, 12.5f, 386.5f);
	Coned_18.end = f3(1110.0f, 13.5f, 393.5f);

	BoundingBox Coned_19;
	Coned_19.start = f3(1020.0f, 12.5f, 401.5f);
	Coned_19.end = f3(1110.0f, 13.5f, 408.5f);

	BoundingBox Coned_20;
	Coned_20.start = f3(1020.0f, 12.5f, 416.5f);
	Coned_20.end = f3(1110.0f, 13.5f, 423.5f);

	BoundingBox Coned_21;
	Coned_21.start = f3(1020.0f, 12.5f, 431.5f);
	Coned_21.end = f3(1110.0f, 13.5f, 438.5f);

	BoundingBox Coned_22;
	Coned_22.start = f3(1020.0f, 12.5f, 446.5f);
	Coned_22.end = f3(1110.0f, 13.5f, 453.5f);

	BoundingBox Fa_1;
	Fa_1.start = f3(40.0f, 5.0f, 450.0f);
	Fa_1.end = f3(46.0f, 8.0f, 456.0f);

	BoundingBox Fa_2;
	Fa_2.start = f3(46.0f, 5.0f, 450.0f);
	Fa_2.end = f3(52.0f, 8.0f, 456.0f);

	BoundingBox Fa_3;
	Fa_3.start = f3(52.0f, 5.0f, 450.0f);
	Fa_3.end = f3(58.0f, 8.0f, 456.0f);

	BoundingBox Fa_4;
	Fa_4.start = f3(869.0f, 0.0f, 594.0f);
	Fa_4.end = f3(875.0f, 3.0f, 600.0f);

	BoundingBox Fa_5;
	Fa_5.start = f3(869.0f, 0.0f, 588.0f);
	Fa_5.end = f3(875.0f, 3.0f, 594.0f);

	BoundingBox Fa_6;
	Fa_6.start = f3(869.0f, 0.0f, 582.0f);
	Fa_6.end = f3(875.0f, 3.0f, 588.0f);

	BoundingBox Fa_7;
	Fa_7.start = f3(869.0f, 0.0f, 576.0f);
	Fa_7.end = f3(875.0f, 3.0f, 582.0f);

	BoundingBox Fa_8;
	Fa_8.start = f3(869.0f, 0.0f, 570.0f);
	Fa_8.end = f3(875.0f, 3.0f, 576.0f);

	BoundingBox Fa_9;
	Fa_9.start = f3(869.0f, 0.0f, 564.0f);
	Fa_9.end = f3(875.0f, 3.0f, 570.0f);

	BoundingBox Fa_10;
	Fa_10.start = f3(869.0f, 0.0f, 558.0f);
	Fa_10.end = f3(875.0f, 3.0f, 564.0f);

	BoundingBox Fa_11;
	Fa_11.start = f3(869.0f, 0.0f, 552.0f);
	Fa_11.end = f3(875.0f, 3.0f, 558.0f);

	BoundingBox Fa_12;
	Fa_12.start = f3(869.0f, 0.0f, 546.0f);
	Fa_12.end = f3(875.0f, 3.0f, 552.0f);

	BoundingBox Fa_13;
	Fa_13.start = f3(869.0f, 0.0f, 540.0f);
	Fa_13.end = f3(875.0f, 3.0f, 546.0f);

	BoundingBox Fa_14;
	Fa_14.start = f3(869.0f, 0.0f, 534.0f);
	Fa_14.end = f3(875.0f, 3.0f, 540.0f);

	BoundingBox Fa_15;
	Fa_15.start = f3(869.0f, 2.0f, 594.0f);
	Fa_15.end = f3(875.0f, 5.0f, 600.0f);

	BoundingBox Fa_16;
	Fa_16.start = f3(869.0f, 2.0f, 588.0f);
	Fa_16.end = f3(875.0f, 5.0f, 594.0f);

	BoundingBox Fa_17;
	Fa_17.start = f3(869.0f, 2.0f, 582.0f);
	Fa_17.end = f3(875.0f, 5.0f, 588.0f);

	BoundingBox Fa_18;
	Fa_18.start = f3(869.0f, 2.0f, 576.0f);
	Fa_18.end = f3(875.0f, 5.0f, 582.0f);

	BoundingBox Fa_19;
	Fa_19.start = f3(869.0f, 2.0f, 570.0f);
	Fa_19.end = f3(875.0f, 5.0f, 576.0f);

	BoundingBox Fa_20;
	Fa_20.start = f3(869.0f, 2.0f, 564.0f);
	Fa_20.end = f3(875.0f, 5.0f, 570.0f);

	BoundingBox Fa_21;
	Fa_21.start = f3(869.0f, 2.0f, 558.0f);
	Fa_21.end = f3(875.0f, 5.0f, 564.0f);

	BoundingBox Fa_22;
	Fa_22.start = f3(869.0f, 2.0f, 552.0f);
	Fa_22.end = f3(875.0f, 5.0f, 558.0f);

	BoundingBox Fa_23;
	Fa_23.start = f3(869.0f, 2.0f, 546.0f);
	Fa_23.end = f3(875.0f, 5.0f, 552.0f);

	BoundingBox Fa_24;
	Fa_24.start = f3(869.0f, 2.0f, 540.0f);
	Fa_24.end = f3(875.0f, 5.0f, 546.0f);

	BoundingBox Fa_25;
	Fa_25.start = f3(869.0f, 2.0f, 534.0f);
	Fa_25.end = f3(875.0f, 5.0f, 540.0f);


	///////////////////////////////

	BoundingBox B_lock3;
	B_lock3.start = f3(1398.0f, 0.0f, 550.0f);
	B_lock3.end = f3(1400.0f, 5.0f, 570.0f);

	BoundingBox Hiterz1[5];
	for (int i = 0; i < 5; ++i)
	{
		Hiterz1[i].start = f3(165.0f, 0.0f, 290.0f + (50.0f * i));
		Hiterz1[i].end = f3(175.0f, 5.0f, 300.0f + (50.0f * i));
		blist.push_back(Hiterz1[i]);
	}

	BoundingBox Hiterz2[5];
	for (int i = 0; i < 5; ++i)
	{
		Hiterz2[i].start = f3(225.0f, 0.0f, 290.0f + (50.0f * i));
		Hiterz2[i].end = f3(235.0f, 5.0f, 300.0f + (50.0f * i));
		blist.push_back(Hiterz2[i]);
	}

	BoundingBox Hiter1;
	Hiter1.start = f3(190.0f, 0.0f, 290.0f);
	Hiter1.end = f3(200.0f, 5.0f, 300.0f);

	BoundingBox Hiter2;
	Hiter2.start = f3(190.0f, 0.0f, 340.0f);
	Hiter2.end = f3(200.0f, 5.0f, 350.0f);

	BoundingBox Hiter3;
	Hiter3.start = f3(190.0f, 0.0f, 390.0f);
	Hiter3.end = f3(200.0f, 5.0f, 400.0f);

	BoundingBox Hiter4;
	Hiter4.start = f3(190.0f, 0.0f, 440.0f);
	Hiter4.end = f3(200.0f, 5.0f, 450.0f);

	BoundingBox Hiter5;
	Hiter5.start = f3(190.0f, 0.0f, 490.0f);
	Hiter5.end = f3(200.0f, 5.0f, 500.0f);

	BoundingBox Hiter6;
	Hiter6.start = f3(140.0f, 0.0f, 290.0f);
	Hiter6.end = f3(150.0f, 5.0f, 300.0f);

	BoundingBox Hiter7;
	Hiter7.start = f3(140.0f, 0.0f, 340.0f);
	Hiter7.end = f3(150.0f, 5.0f, 350.0f);

	BoundingBox Hiter8;
	Hiter8.start = f3(140.0f, 0.0f, 390.0f);
	Hiter8.end = f3(150.0f, 5.0f, 400.0f);

	BoundingBox Hiter9;
	Hiter9.start = f3(140.0f, 0.0f, 440.0f);
	Hiter9.end = f3(150.0f, 5.0f, 450.0f);

	BoundingBox Hiter10;
	Hiter10.start = f3(140.0f, 0.0f, 490.0f);
	Hiter10.end = f3(150.0f, 5.0f, 500.0f);

	BoundingBox Hiter11;
	Hiter11.start = f3(200.0f, 0.0f, 290.0f);
	Hiter11.end = f3(210.0f, 5.0f, 300.0f);

	BoundingBox Hiter12;
	Hiter12.start = f3(200.0f, 0.0f, 340.0f);
	Hiter12.end = f3(210.0f, 5.0f, 350.0f);

	BoundingBox Hiter13;
	Hiter13.start = f3(200.0f, 0.0f, 390.0f);
	Hiter13.end = f3(210.0f, 5.0f, 400.0f);

	BoundingBox Hiter14;
	Hiter14.start = f3(200.0f, 0.0f, 440.0f);
	Hiter14.end = f3(210.0f, 5.0f, 450.0f);

	BoundingBox Hiter15;
	Hiter15.start = f3(200.0f, 0.0f, 490.0f);
	Hiter15.end = f3(210.0f, 5.0f, 500.0f);

	BoundingBox Hiter16;
	Hiter16.start = f3(250.0f, 0.0f, 290.0f);
	Hiter16.end = f3(260.0f, 5.0f, 300.0f);

	BoundingBox Hiter17;
	Hiter17.start = f3(250.0f, 0.0f, 340.0f);
	Hiter17.end = f3(260.0f, 5.0f, 350.0f);

	BoundingBox Hiter18;
	Hiter18.start = f3(250.0f, 0.0f, 390.0f);
	Hiter18.end = f3(260.0f, 5.0f, 400.0f);

	BoundingBox Hiter19;
	Hiter19.start = f3(250.0f, 0.0f, 440.0f);
	Hiter19.end = f3(260.0f, 5.0f, 450.0f);

	BoundingBox Hiter20;
	Hiter20.start = f3(250.0f, 0.0f, 490.0f);
	Hiter20.end = f3(260.0f, 5.0f, 500.0f);

	BoundingBox GyoDa1;
	GyoDa1.start = f3(380.0f, 0.0f, 449.0f);
	GyoDa1.end = f3(395.0f, 5.0f, 450.0f);

	BoundingBox GyoDa2;
	GyoDa2.start = f3(352.5f, 0.0f, 349.0f);
	GyoDa2.end = f3(367.5f, 5.0f, 350.0f);

	BoundingBox R_sta1;
	R_sta1.start = f3(890.0f, 0.0f, 274.0f);
	R_sta1.end = f3(990.0f, 12.5f, 275.0f);

	BoundingBox R_sta2;
	R_sta2.start = f3(1030.0f, 0.0f, 274.0f);
	R_sta2.end = f3(1130.0f, 12.5f, 275.0f);

	BoundingBox R_sta3;
	R_sta3.start = f3(0.0f, 0.0f, 399.0f);
	R_sta3.end = f3(100.0f, 12.5f, 400.0f);

	BoundingBox elec1[3];
	for (int i = 0; i < 3; ++i)
	{
		elec1[i].start = f3(1135.0f + (60.0f * i), 0.0f, 165.0f);
		elec1[i].end = f3(1185.0f + (60.0f * i), 9.0f, 195.0f);
		blist.push_back(elec1[i]);
	}



	blist.push_back(GyoDa1);
	blist.push_back(GyoDa2);
	blist.push_back(R_sta1);
	blist.push_back(R_sta2);
	blist.push_back(R_sta3);
	blist.push_back(B_lock3);
	blist.push_back(Hiter1);
	blist.push_back(Hiter2);
	blist.push_back(Hiter3);
	blist.push_back(Hiter4);
	blist.push_back(Hiter5);
	blist.push_back(Hiter6);
	blist.push_back(Hiter7);
	blist.push_back(Hiter8);
	blist.push_back(Hiter9);
	blist.push_back(Hiter10);
	blist.push_back(Hiter11);
	blist.push_back(Hiter12);
	blist.push_back(Hiter13);
	blist.push_back(Hiter14);
	blist.push_back(Hiter15);
	blist.push_back(Hiter16);
	blist.push_back(Hiter17);
	blist.push_back(Hiter18);
	blist.push_back(Hiter19);
	blist.push_back(Hiter20);

	blist.push_back(Fa_1);
	blist.push_back(Fa_2);
	blist.push_back(Fa_3);
	blist.push_back(Fa_4);
	blist.push_back(Fa_5);
	blist.push_back(Fa_6);
	blist.push_back(Fa_7);
	blist.push_back(Fa_8);
	blist.push_back(Fa_9);
	blist.push_back(Fa_10);
	blist.push_back(Fa_11);
	blist.push_back(Fa_12);
	blist.push_back(Fa_13);
	blist.push_back(Fa_14);
	blist.push_back(Fa_15);
	blist.push_back(Fa_16);
	blist.push_back(Fa_17);
	blist.push_back(Fa_18);
	blist.push_back(Fa_19);
	blist.push_back(Fa_20);
	blist.push_back(Fa_21);
	blist.push_back(Fa_22);
	blist.push_back(Fa_23);
	blist.push_back(Fa_24);
	blist.push_back(Fa_25);
	blist.push_back(Coned_1);
	blist.push_back(Coned_2);
	blist.push_back(Coned_3);
	blist.push_back(Coned_4);
	blist.push_back(Coned_5);
	blist.push_back(Coned_6);
	blist.push_back(Coned_7);
	blist.push_back(Coned_8);
	blist.push_back(Coned_9);
	blist.push_back(Coned_10);
	blist.push_back(Coned_11);
	blist.push_back(Coned_12);
	blist.push_back(Coned_13);
	blist.push_back(Coned_14);
	blist.push_back(Coned_15);
	blist.push_back(Coned_16);
	blist.push_back(Coned_17);
	blist.push_back(Coned_18);
	blist.push_back(Coned_19);
	blist.push_back(Coned_20);
	blist.push_back(Coned_21);
	blist.push_back(Coned_22);
	blist.push_back(Pox1);
	blist.push_back(Pox2);
	blist.push_back(Pox3);
	blist.push_back(Pox4);
	blist.push_back(Pox5);
	blist.push_back(Pox6);
	blist.push_back(Pox7);
	blist.push_back(Pox8);
	blist.push_back(Pox9);
	blist.push_back(Pox10);
	blist.push_back(Pox11);
	blist.push_back(Pox12);
	blist.push_back(Pox13);
	blist.push_back(Pox14);
	blist.push_back(Pox15);
	blist.push_back(Pox16);
	blist.push_back(Pox17);
	blist.push_back(Pox18);
	blist.push_back(Pox19);
	blist.push_back(Pox20);
	blist.push_back(Pox21);
	blist.push_back(Pox22);
	blist.push_back(Egin1);
	blist.push_back(Egin2);
	blist.push_back(Egin3);
	blist.push_back(Egin4);
	blist.push_back(Egin5);
	blist.push_back(Egin6);
	blist.push_back(Egin7);



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