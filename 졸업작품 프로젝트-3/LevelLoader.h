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


#define floor 10000 // 1-1~4를 아우르는 구간들
#define vWalls 10001 // 공통
#define hWalls 10002 // 공통
#define vWalls_1 10003 // 공통
#define hWalls_1 10004 // 공통

#define vWalls_S 10005 // 공통

#define vWalls_1S 10006 // 공통
#define vWalls_1SM 10007 // 공통
#define vWalls_SM 10008 // 공통

#define vWalls_H 10009 // 공통
#define hWalls_H 10010 // 공통
//////////////////////////////////////////

#define froom_set 10011 // 공통
#define froom_set1_3 13001 // 1-3
#define froom_set1_3_h 13002 // 1-3
#define froom_set_H 10012 // 공통
#define floor_T 14901 // 1-4
#define floor_Se 20000 // 2 공통



#define loadwall_l 14013  // 1-4
#define loadwall_m 14014 // 두번째방으로 향하는 통로 벽 // 1-4
#define loadwall_h 14015 // 1-4

#define Se_room_L1_1 20001 // 2 공통
#define Se_room_L1_2 20002 // 두번째 방 왼쪽벽2 // 2공통
#define Se_room_L1_3 20003 // 2공통

#define Se_room_R1_1 20004 // 2공통
#define Se_room_R1_2 20005 // 2공통
#define Se_room_R1_3 20006 // 두번째 방 왼쪽벽1 2공통


#define Se_room_RSL 20007 // 2공통
#define Se_room_RSM 20008 // 2공통
#define Se_room_RSH 20009 // 두번째방 오른쪽 벽 //2공통

#define Se_room_FBL 20010 // 2공통
#define Se_room_FBM 20011 // 2공통
#define Se_room_FBH 20012 // 2공통 두번째 방 앞뒤 벽

#define Se_Busok1_1 20013 // 2공통
#define Se_Busok1_2 20014 // 2공통 두번째방 부속벽1
#define Se_Busok1_3 20015 // 2공통

#define Se_Busok2_1 20016 // 2공통
#define Se_Busok2_2 20017 // 2공통
#define Se_Busok2_3 20018 // 2공통

#define Se_Busok3_1 20019 // 2공통
#define Se_Busok3_2 20020 // 2공통 
#define Se_Busok3_3 20021 // 2공통

#define Se_Busok4_1 20022 // 2공통 
#define Se_Busok4_2 20023 // 2공통
#define Se_Busok4_3 20024 // 2공통

#define Se_Busok5_1 20025
#define Se_Busok5_2 20026

#define Cont1_1 11
#define Frs_H 123456*3


#define BatSet1 10013 // 1공통
#define BatSet2 30014 // 1공통
#define BatSet3 10015 // 1 공통

#define Bat_FB_set1 10016 // 1공통
#define Bat_FB_set2 10017 // 1공통


#define BatSet_1 10018 // 1공통
#define BatSet_2 10019// 1공통

#define Bat_FB_101 10020 // 1공통
#define Bat_FB_102 10021 // 1공통

#define SeBatSet1 20025 // 2공통
#define SeBatSet3 20026 // 2공통

#define SeBat_FB_set1 20027 // 2공통
#define SeBat_FB_set2 20028 // 2공통

#define SeBatSet_1 20029 // 2공통
#define SeBatSet_2 20030 // 2공통

#define SeBat_FB_101 20031 // 2공통
#define SeBat_FB_102 20032 // 2공통


#define M_Contain 12000 // 1-2
#define J_Contain 12001 // 1-2
#define T_Contains 13003 // 1-3

#define B_Contain 22000 // 2-2
#define Stairs1 25000
#define Shell 30000 // 3공통


#define GyeDans1 13004 // 1-3
#define GyeDans2 13005 // 1-3
#define R_GyeDan1 22001 // 2-2
#define didims 30049
#define R_GyeDan1_1 30050

#define Frs_Pons1 30099// 1-2
#define Frs_Pons2 30098 // 1-2
#define adds_beok1 14000 // 1-4
#define adds_beok2 14001 // 1-4
#define B_Door 23000 // 2-3

#define Add_squre1 30001 // 3공통

#define Add_squre2 30002 // 3공통
#define SeAddings1 23001 // 2-3
#define SeAddings2 23002 // 2-3
#define Heaters1 30003 // 
#define F_Stages 13006

#define Factory_tool1 12505 // 1-2
#define Factory_tool2 22510 // 2-2
#define Factory_tool3 22515 // 2-2
#define Factory_tool4 22520 // 2-2 
#define Factory_tool5 14525 // 1-4
#define Factory_tool6 11530 // 1-1
#define Factory_tool7 14535 // 1-4
#define Factory_tool8 11540 // 1-1
#define Factory_tool9 14545 // 1-4
#define Factory_tool10 14550 // 1-4
#define Factory_tool11 14555 // 1-4
#define Factory_tool12 13560 // 1-3
#define Factory_tool13 13565 // 1-3
#define Factory_tool14 13570 // 1-3
#define Factory_tool15 14575 // 1-4
#define Factory_tool16 21580 // 2-1
#define Factory_tool17 23582 // 2-3
#define Factory_tool18 23584 // 2-3
#define Factory_tool19 23586 // 2-3
#define Factory_tool20 23588 // 2-3


#define Wallz1 30093 // 1-1
#define Wallz2 30094 // 1-1
#define Wallz3 30095 // 1-1
#define Wallz4 30097 // 1-3
#define Wallz5 30096 // 1-3
#define Wallz6 12110 // 1-2
#define Wallz7 12112 // 1-2
#define Wallz8 30114// 1-1
#define Wallz9 30116 // 1-1
#define Wallz10 30118 // 1-1
#define Chagsal1 11120 // 1-1
#define Chagsal2 11122 // 1-1
#define Pyo 11124 // 1-1
#define GamOk 14126 // 1-4 
#define GamOk_1 14127 // 1-4
#define GamOk2 14128 // 1-4 
#define GamOk_Shell 14130 // 1-4
#define Wallz11 11132 // 1-1
#define Wallz12 11134 // 1-1
#define Wallz13 11136 // 1-1
#define Wallz14 11138 // 1-1
#define Wallz15 14140 // 1-4
#define Wallz16 14142 // 1-4
#define Wallz17 14144 // 1-4
#define Wallz18 14146 // 1-4
#define Kidong 11148 // 1-1
#define KidongMom 11150 // 1-1
#define Wallz19 14152 // 1-4
#define Wallz20 14154 // 1-4
#define Wallz21 14156 // 1-4
#define Wallz22 14158 // 1-4
#define A_Wallz1 14160 // 1-4
#define A_Wallz2 14162 // 1-4
#define A_Wallz3 14164 // 1=4
#define A_Wallz4 14166 // 1-4
#define S_Wallz1 21168 // 2-1
#define S_Wallz2 21170 // 2-1
#define S_Wallz3 21172 // 2-1
#define S_Wallz4 21174 // 2-1
#define S_Wallz5 21176 // 2-1
#define S_Wallz6 21178 // 2-1
#define S_Wallz7 21180 // 2-1
#define S_Wallz8 21182 // 2-1

#define S_Wallz9 2184 //
#define S_Wallz10 2186 //
#define S_Wallz11 2188
#define S_Wallz12 2190

#define S_Wallz13 23192 // 2-3
#define S_Wallz14 23194 // 2-3

#define S_Wallz15 23196 // 2-3
#define S_Wallz16 23198 // 2-3

#define S_Wallz17 23201 // 2-3
#define S_Wallz18 23203 // 2-3
#define S_Wallz19 14205 // 1-4
#define S_Wallz20 23207 // 2-3
#define S_Wallz21 23209 // 2-3
#define S_Wallz22 23211 // 2-3
#define S_Wallz23 23213 // 2-3
#define S_Wallz24 23215 // 2-3

#define S_Wallz25 21217 // 2-1
#define S_Wallz26 21219 // 2-1
#define Top_wall1 30004
#define Top_wall2 30005
#define Janhae1 11899 // 1-1
#define Janhae2 11898
#define Janhae3 11897
#define Janhae2_1 11896
#define Janhae4 11895
#define Janhae5 11894
#define Janhae6 11893
#define Janhae7 11892
#define Janhae8 30891
#define Janhae9 11890
#define Janhae10 13899
#define Janhae11 30598
#define Janhae12 14899
#define Janhae13 30199
#define Janhae14 30898
#define Janhae15 30897
#define Janhae16 30896
#define Janhae17 30895
#define Janhae18 21899
#define Janhae19 21898
#define Janhae20 20899
#define Janhae21 22899
#define Janhae22 30849
#define Janhae23 30848

//이 위엔 이제부터 안쓰는 것들임.

//1-1 wall

#define RustyMetal_Floor 11001
#define RustyMetal_Wall_Left 11002
#define RustyMetal_Wall_Right 11003
#define RustyMetal_Wall_Front 11004
#define RustyMetal_Wall_Back 11005
#define RustyMetal_Ceiling 11006

#define RustyMetal_Wall_Left_100m 11007
#define RustyMetal_Wall_Center_50m 11008

#define RustyMetal_Wall_HCenter_50m 11009
#define RustyMetal_Wall_Bottom_50m 11010
#define RustyMetal_Wall_Top_100m 11011

#define RustyMetal_Wall_Right2 11012
#define RustyMetal_Wall_Right3 11013

//1-1 object

#define Dustbin 11200
#define RustyMetal_Box 11201
#define RustyMetal_Barrel 11202

#define WallPipe 11203
#define FloorPipe 11204

#define RustyFence 11205
#define FoodBin 11206
#define Envelop1 11207
#define MetalLadder 11208
#define RailBend 11209
#define RuinWood1 11210
#define RuinWood2 11211
#define RuinBrick1 11212
#define RuinBrick2 11213
#define RuinBrick3 11214
#define RuinBrick4 11215
#define RuinBrick5 11216
#define RuinCeramic1 11217
#define RuinCeramic2 11218
#define RuinMix1 11219
#define RuinMix2 11220
#define RustyStair 11221
#define RustyTrashCan 11222

#define Envelop2 11223
#define Envelop3 11224

#define RailStraight 11225

#define RuinBrick6 11226
#define RuinCeramic3 11227

#define CementBag1 11228
#define CementBag2 11229
#define WoodenPallet 11230
#define WoodenPalletLayer 11231

#define WarningSign 11232
#define FuelTruck 11233
#define Chon 11234
#define GuardRail 11235

#define Truck2Wheel 11236
#define Truck2Body 11245

#define Cardboard1 11237
#define Cardboard2 11238
#define Cardboard3 11239
#define Cardboard4 11240

#define Controller1 11241
#define Controller2 11242
#define Controller3 11243
#define Controller4 11244

#define LeverHandle 11246
#define LeverBody 11247

#define PaperWaste 11248

#define PizzaBox 11249
#define SpeedBump 11250
#define TrashContainer 11251

#define RuinBase 11252

#define Pillar 11253

//1-2 space

#define Wall12_Left1 12000
#define Wall12_Left2 12001
#define Wall12_Left3 12002

#define Wall12_Front 12003
#define Wall12_Back 12004

#define Wall12_Right1 12005

#define Wall12_Center1 12006
#define Wall12_Center2 12007
#define Wall12_Center3 12008
#define Wall12_HCenter1 12009

#define Wall12_Floor 12010
#define Wall12_UpperFloor 12011

#define Wall12_Right2 12012
#define Wall12_Right3 12013

#define Wall12_Ceiling 12014

#define Wall12_LeftUnder 12015
#define Wall12_RightUnder 12016
#define Wall12_CenterUnder 12017

#define Wall12_HCenter2 12018
#define Wall12_HCenter3 12019

#define Wall12_Center4 12020

#define Wall12_HCenter4 12021
#define Wall12_HCenter5 12022

#define WireFrame 12023

#define WoodManu_WallBack 12024
#define WoodManu_WallFront 12025
#define WoodManu_WallRight1 12026
#define WoodManu_WallRight2 12027
#define WoodManu_WallRight3 12028

#define Pottery_WallFront 12029
#define Pottery_WallBack1 12030
#define Pottery_WallBack2 12031
#define Pottery_WallBack3 12032

#define Pottery_WallRight 12033

#define Pottery_WallCenter 12034
#define Pottery_WallHCenter 12035

#define Pottery_UpperFloor 12036

#define Pottery_Stair 12037

#define Transfer_UpperFloor 12038
#define Transfer_WallRight 12039
#define Transfer_WallBack1 12040
#define Transfer_WallBack2 12041
#define Transfer_WallBack3 12042

#define Transfer_Stair 12043
#define Transfer_HCenter 12044



//1-2 object


#define Shield 12200
#define BigShield 12201
#define AirFan 12202
#define LongTank 12203

#define Machine1 12204
#define Machine3 12205
#define Machine4 12206
#define Machine6 12207
#define Machine7 12208

#define RobotArm 12209
#define Sewer 12210

#define Fence12 12211
#define Pillar12 12212

#define Container12 12213

#define Chon12 12214

#define Heater 12215

#define Controller12_1 12216
#define Controller12_2 12217
#define Controller12_4 12218

#define ChargeSlot 12219
#define ChargeFloor 12220

#define ChargingRobot 12221

#define ChargeFloor2 12222
#define Box12 12223

#define TableBig 12224
#define Saw 12225
#define Drill 12226
#define Woods1 12227
#define Woods2 12228

#define PlainLog1 12229
#define PlainLog2 12230

#define Furniture1 12231
#define Furniture2 12232

#define Shelf 12233

#define ToolBox 12234
#define PaintBarrel 12235
#define Bottle 12236
#define Hammer 12237
#define Glue 12238

#define PotterySoil 12239
#define PotterySoilPallet 12240
#define Pottery1 12241
#define Pottery2 12242
#define Pottery3 12243
#define Pottery4 12244
#define Pottery5 12245
#define Pottery6 12246
#define Pottery7 12247
#define Pottery8 12248
#define Pottery9 12249
#define Pottery10 12250
#define Pottery11 12251
#define Pottery12 12252
#define Pottery13 12253
#define Pottery14 12254
#define Pottery15 12255

#define PotterySoilPalletLayer 12256

#define ConveyorDoor 12257
#define ConveyorBelt 12258
#define ConveyorCover 12259

#define Elevator 12260

#define PotteryKlinOpen 12261
#define PotteryWheel 12262
#define PotteryKlinClose 12263
#define Whiteboard 12264
#define Banner 12265
#define WoodManu_Pillar1 12266
#define WoodManu_Pillar2 12267


//2-1
#define Gwanja_wall1 21001
#define Gwanja_floor 21002
#define Gwanja_front 21003
#define Gwanja_celing 21004
#define Gwanja_floor2 21005
#define Gwanja_wall2 21006
#define Gwanja_wall3 21007
#define Gwanja_Screen 21020
#define Gwanja_tables 21019
#define Gwanja_tablesA 21021
#define Gwanja_Chair 21022
#define Gwanja_Screen2 21038
#define Gwanja_Screen3 21039
#define Gwanja_Cabinet 21040

//2-2

#define Recep_celing 21008
#define Recep_floor 21009
#define Recep_wall1 21010
#define Recep_wall2 21011
#define Recep_front 21012
#define Recep_front2 21013
#define Recep_wall3 21014
#define Recep_wall4 21015
#define Recep_wall4_F 21999
#define Recep_wall5 21016
#define Recep_garomak 21017
#define Recep_kidung 21018
#define Recep_Kanmak 21023
#define Recep_Tables 21024
#define Recep_Couch 21025
#define Recep_Vending 21026
#define Recep_Counter1 21027
#define Recep_Screened1 21028
#define Recep_MidWal 21029
#define Recep_Counter2 21030
#define Recep_Air 21031
#define Recep_DongSSang1 21032
#define Recep_Misul 21033
#define Recep_Lamps 21034
#define Recep_Door1 21035
#define Recep_DoorL 21036
#define Recep_DoorR 21037

#define Parking_floor1 23999
#define Parking_Wall1 23998
#define Parking_FWall1 23997
#define Parking_Fence 23996
#define Parking_Area 23995
#define Parking_Area2 23994


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

void LoadHeight(const char* filename, float** data);