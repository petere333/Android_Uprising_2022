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

void writeBox(FILE* f, BoundingBox box);
void writeSphere(FILE* f, BoundingSphere sphere);