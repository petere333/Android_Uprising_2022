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


#define f800x600 800600*1
#define vWall600x500 600500*2
#define hWall800x500 800500*3

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

std::vector<Obj> LoadObjects(const char* filename);
std::vector<BoundBox> LoadBoxes(const char* filename);
