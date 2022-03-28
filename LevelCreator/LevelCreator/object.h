#pragma once

#include "common.h"

#define CONTAINER 1
#define CUBE 2
#define TILE 3

#define f800x600 800600*1
#define vWall600x500 600500*2
#define hWall800x500 800500*3
#define Enemy -1

#define TileSize 2.5f

using namespace std;

typedef struct float3
{
	float x, y, z;
}float3;

typedef struct Object
{
	float3 location;
	int type;
};

void writeFile(FILE* file, Object o);

void createFloor(vector<Object>& list, float, float);

float3 f3(float f1, float f2, float f3);