#pragma once

#include "common.h"

#define PLAYER 1
#define CONTAINER 2
#define BOX 3
#define BARREL 4
#define PALLET 5
#define TRASH 6
#define TRUCK 7
#define TABLE 8
#define CHAIR 9


#define floor 600600*1
#define vWalls 600600*2
#define hWalls 600600*3
#define vWalls_1 600600*2*1// �¿� �� ��Ʈ �ߴ�
#define hWalls_1 600600*3*1 // ���� �� ��Ʈ �ߴ�
#define vWalls_S 600600*2*1*1 // ������ �Ϻ� ��
#define vWalls_1S 600600*1*1*1 // ���� �Ϻ� �ϴ�
#define vWalls_1SM 600600*1*1*2 // ���� �Ϻ� �ߴ�
#define vWalls_SM 600600*2*1*2 // ������ �Ϻ� �� �ߴ�
#define vWalls_H 600600*2*2 // �翷 ���
#define hWalls_H 600600*3*2 // �յ� ���

#define froom_set 1515*1
#define froom_set_H 1515*2
#define floor_T 600600600
#define floor_Se 600300600

#define TileSize 2.5f

#define loadwall_l 505050*1
#define loadwall_m 505050*2
#define loadwall_h 505050*3 // ��� ��

#define Se_room_L1_1 121212*1
#define Se_room_L1_2 121212*2
#define Se_room_L1_3 121212*3 // �ι�° �� ����2

#define Se_room_R1_1 131313*1
#define Se_room_R1_2 131313*2
#define Se_room_R1_3 131313*3 // �ι�°�� ���� 1

#define Se_room_RSL 141414*1
#define Se_room_RSM 141414*2
#define Se_room_RSH 141414*3 // �ι�°�� ������ ��

#define Se_room_FBL 151515*1
#define Se_room_FBM 151515*2
#define Se_room_FBH 151515*3 // �ι�° �� �յ� ��



using namespace std;



typedef struct Object
{
	float3 location;
	float3 rotation;
	int type;
};

void writeFile(FILE* file, Object o);



float3 f3(float f1, float f2, float f3);