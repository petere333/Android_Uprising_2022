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