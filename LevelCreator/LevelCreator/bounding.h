#pragma once

#include "common.h"

typedef struct BoundingBox
{
	float x1, y1, z1;
	float x2, y2, z2;
}BoundingBox;

typedef struct BoundingSphere
{
	float x, y, z;
	float dist;
}BoundingSphere;

void writeBox(FILE* f, BoundingBox box);
void writeSphere(FILE* f, BoundingSphere sphere);