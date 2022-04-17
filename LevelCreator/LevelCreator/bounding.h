#pragma once

#include "common.h"

typedef struct BoundingBox
{
	float3 start;
	float3 end;
}BoundingBox;

typedef struct BoundingSphere
{
	float3 center;
	float dist;
}BoundingSphere;

typedef struct BoundingStair {
	float xstart, xend;
	float zstart, zend;
	float height;
}BoundingStair;

void writeBox(FILE* f, BoundingBox box);
void writeSphere(FILE* f, BoundingSphere sphere);
void writeStair(FILE* f, BoundingStair Stairs);
