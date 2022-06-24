#pragma once

#include "common.h"

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



using namespace std;



typedef struct Object
{
	float3 location;
	float3 rotation;
	int type;
};

void writeFile(FILE* file, Object o);

void writeHeight(FILE* file, float* data, int size);

void setAreaHeight(float* data, int,int,float sx, float sz, float ex, float ez, float height);


float3 f3(float f1, float f2, float f3);