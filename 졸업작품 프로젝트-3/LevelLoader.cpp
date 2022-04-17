#pragma once
#include "LevelLoader.h"


std::vector<Obj> LoadObjects(const char* filename)
{
	FILE* f = fopen(filename, "r");
	std::vector<Obj> list;

	while (!feof(f))
	{
		float f1, f2, f3;
		float r1, r2, r3;
		int t;
		fscanf(f, "position : (%f,  %f,  %f)  rotation : (%f,  %f,  %f)  type : %d\n", &f1, &f2, &f3, &r1, &r2, &r3, &t);

		Obj o;
		o.position = XMFLOAT3(f1, f2, f3);
		o.rotation = XMFLOAT3(r1, r2, r3);
		o.type = t;

		list.push_back(o);
	}
	return list;

}

BoundBox* LoadBoxes(const char* filename, int* n)
{
	BoundBox* bx;
	std::vector<BoundBox> result;
	FILE* f = fopen(filename, "r");
	while (!feof(f))
	{
		float x1, y1, z1, x2, y2, z2;
		BoundBox box;
		fscanf(f, "start : (%f,  %f,  %f)  end : (%f,  %f,  %f)\n", &x1, &y1, &z1, &x2, &y2, &z2);
		box.start = XMFLOAT3(x1, y1, z1);
		box.end = XMFLOAT3(x2, y2, z2);
		result.push_back(box);
	}
	bx = (BoundBox*)malloc(sizeof(BoundBox) * result.size());
	for (int i = 0; i < result.size(); ++i)
	{
		bx[i] = result[i];
	}
	*n = result.size();
	return bx;
}

BoundingStair* LoadStair(const char* filename, int* n)
{
	BoundingStair* bs;
	std::vector<BoundingStair> result;
	FILE* f = fopen(filename, "r");
	while(!feof(f))
	{
		float x1, x2, z1, z2, h;
		BoundingStair stair;
		fscanf(f, "xstart / xend : %f, %f\n zstart / zend : %f, %f \n height : %f \n\n", &x1, &x2, &z1, &z2, &h);
		stair.xstart = x1;
		stair.xend = x2;
		stair.zstart = z1;
		stair.zend = z2;
		stair.height = h;
		result.push_back(stair);
	}
	bs = (BoundingStair*)malloc(sizeof(BoundingStair) * result.size());
	for (int i = 0; i < result.size(); ++i)
	{
		bs[i] = result[i];
	}
	*n = result.size();
	return bs;
}
