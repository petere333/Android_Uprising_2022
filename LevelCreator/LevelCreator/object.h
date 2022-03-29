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


#define f800x600 800600*1
#define vWall600x500 600500*2
#define hWall800x500 800500*3


#define TileSize 2.5f



using namespace std;



typedef struct Object
{
	float3 location;
	float3 rotation;
	int type;
};

void writeFile(FILE* file, Object o);



float3 f3(float f1, float f2, float f3);