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

std::vector<BoundBox> LoadBoxes(const char* filename)
{
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
	return result;
}
