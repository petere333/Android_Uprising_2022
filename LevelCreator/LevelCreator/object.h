#pragma once

#include "common.h"

#pragma once

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
#define vWalls_SM 2008 // 오른쪽 일부 벽 중단

#define vWalls_H 2009 // 양옆 상단
#define hWalls_H 2010 // 앞뒤 상단

#define froom_set 2011
#define froom_set_H 2012
#define floor_T 12001
#define floor_Se 12002



#define loadwall_l 2013
#define loadwall_m 2014 // 두번째방으로 향하는 통로 벽
#define loadwall_h 2015

#define Se_room_L1_1 2016
#define Se_room_L1_2 2017 // 두번째 방 왼쪽벽2
#define Se_room_L1_3 2018

#define Se_room_R1_1 2019
#define Se_room_R1_2 2020
#define Se_room_R1_3 2021 // 두번째 방 왼쪽벽1


#define Se_room_RSL 2022
#define Se_room_RSM 2023
#define Se_room_RSH 2024 // 두번째방 오른쪽 벽

#define Se_room_FBL 2025
#define Se_room_FBM 2026
#define Se_room_FBH 2027 // 두번째 방 앞뒤 벽

#define Se_Busok1_1 2028
#define Se_Busok1_2 2029 // 두번째방 부속벽1
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

#define Cont1_1 11
#define Frs_H 123456*3


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
using namespace std;



typedef struct Object
{
	float3 location;
	float3 rotation;
	int type;
};

void writeFile(FILE* file, Object o);



float3 f3(float f1, float f2, float f3);