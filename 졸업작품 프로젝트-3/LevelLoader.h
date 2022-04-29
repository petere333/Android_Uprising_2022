#pragma once

#include "stdafx.h"


#define PLAYER 1
#define CONTAINER 2
#define BOX 3
#define BARREL 4
#define PALLET 5
#define TRASH 6
#define TRUCK 7
#define TABLE 8
#define CHAIR 9


#define floor 12000
#define vWalls 2001
#define hWalls 2002
#define vWalls_1 2003
#define hWalls_1 2004

#define vWalls_S 2005

#define vWalls_1S 2006
#define vWalls_1SM 2007
#define vWalls_SM 2008 // ������ �Ϻ� �� �ߴ�

#define vWalls_H 2009 // �翷 ���
#define hWalls_H 2010 // �յ� ���

#define froom_set 2011
#define froom_set_H 2012
#define floor_T 12001
#define floor_Se 12002



#define loadwall_l 2013
#define loadwall_m 2014 // �ι�°������ ���ϴ� ��� ��
#define loadwall_h 2015

#define Se_room_L1_1 2016
#define Se_room_L1_2 2017 // �ι�° �� ���ʺ�2
#define Se_room_L1_3 2018

#define Se_room_R1_1 2019
#define Se_room_R1_2 2020
#define Se_room_R1_3 2021 // �ι�° �� ���ʺ�1


#define Se_room_RSL 2022
#define Se_room_RSM 2023
#define Se_room_RSH 2024 // �ι�°�� ������ ��

#define Se_room_FBL 2025
#define Se_room_FBM 2026
#define Se_room_FBH 2027 // �ι�° �� �յ� ��

#define Se_Busok1_1 2028
#define Se_Busok1_2 2029 // �ι�°�� �μӺ�1
#define Se_Busok1_3 2030

#define Se_Busok2_1 2031
#define Se_Busok2_2 2032
#define Se_Busok2_3 2033

#define Se_Busok3_1 2034
#define Se_Busok3_2 2035
#define Se_Busok3_3 2036

#define Se_Busok4_1 2037
#define Se_Busok4_2 2038
#define Se_Busok4_3 2039

#define Cont1_1 11 // ��������
#define Frs_H 123456*3 // ������ ��


#define BatSet1 2040
#define BatSet2 2041
#define BatSet3 2042

#define Bat_FB_set1 2043
#define Bat_FB_set2 2044


#define BatSet_1 2045
#define BatSet_2 2046

#define Bat_FB_101 2047
#define Bat_FB_102 2048

#define SeBatSet1 2049
#define SeBatSet3 2050

#define SeBat_FB_set1 2051
#define SeBat_FB_set2 2052

#define SeBatSet_1 2053
#define SeBatSet_2 2054

#define SeBat_FB_101 2055
#define SeBat_FB_102 2056


#define M_Contain 5010
#define J_Contain 5020
#define T_Contains 5030

#define B_Contain 5040
#define Stairs1 25000
#define Shell 50000


#define GyeDans1 25020
#define GyeDans2 25040
#define R_GyeDan1 25060

#define Frs_Pons1 2060
#define Frs_Pons2 2070
#define adds_beok1 2080
#define adds_beok2 2090
#define B_Door 35000

#define Add_squre1 75000

#define Add_squre2 75100
#define SeAddings1 2200
#define SeAddings2 2300
#define Heaters1 90000
#define F_Stages 95001
#define Factory_tool1 505
#define Factory_tool2 510
#define Factory_tool3 515
#define Factory_tool4 520
#define Factory_tool5 525
#define Factory_tool6 530
#define Factory_tool7 535
#define Factory_tool8 540
#define Factory_tool9 545
#define Factory_tool10 550
#define Factory_tool11 555


#define Wallz1 2100
#define Wallz2 2102
#define Wallz3 2104
#define Wallz4 2106
#define Wallz5 2108
#define Wallz6 2110
#define Wallz7 2112
#define Wallz8 2114
#define Wallz9 2116
#define Wallz10 2118
#define Chagsal1 2120
#define Chagsal2 2122
#define Pyo 2124
#define GamOk 2126
#define GamOk2 2128
#define GamOk_Shell 2130
#define Wallz11 2132
#define Wallz12 2134
#define Wallz13 2136
#define Wallz14 2138
#define Wallz15 2140
#define Wallz16 2142
#define Wallz17 2144
#define Wallz18 2146
#define Kidong 2148
#define KidongMom 2150
#define Wallz19 2152
#define Wallz20 2154
#define Wallz21 2156
#define Wallz22 2158
#define A_Wallz1 2160
#define A_Wallz2 2162
#define A_Wallz3 2164
#define A_Wallz4 2166


// ����
// 2000�� ���ڵ� : ������ (��ġ ����)
// 5000�� ���ڵ� : �����̳�
// 12000�� ���ڵ� : �ٴ�
// �׿ܴ� �����̳ʰ� �ƴ� �ٴ��̰ų�, �Ӽ��� �ٸ� ��, õ�� �� �����̰ų�, �� ������ ������ �޶� �Ϻη� �и��� �͵�



typedef struct Obj
{
	XMFLOAT3 position;
	XMFLOAT3 rotation;
	int type;
}Obj;



typedef struct BBox
{
	XMFLOAT3 start;
	XMFLOAT3 end;
}BoundBox;

typedef struct BoundingSphere
{
	XMFLOAT3 center;
	float dist;
}BoundSphere;

typedef struct Stair
{
	XMFLOAT2 start, end;
	float height;
}Stair;

std::vector<Obj> LoadObjects(const char* filename);
BoundBox* LoadBoxes(const char* filename, int*);
BoundBox* LoadStairs(const char* filename, int* n);

