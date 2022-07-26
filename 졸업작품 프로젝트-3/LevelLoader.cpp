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

BoundBox* LoadStairs(const char* filename, int* n)
{
	int count = 0;
	BoundBox* bx;
	std::vector<Stair> str;
	FILE* f = fopen(filename, "r");
	while (!feof(f))
	{
		float sx, sz, ex, ez, h;

		Stair st;
		fscanf(f, "xstart / xend : %f, %f\n zstart / zend : %f, %f \n height : %f \n\n", &sx, &ex, &sz, &ez, &h);
		st.start = XMFLOAT2(sx, sz);
		st.end = XMFLOAT2(ex, ez);
		st.height = h;
		str.push_back(st);
		count += static_cast<int>(h / 0.15f);
	}
	bx = new BoundBox[count];

	int idx = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		int steps = static_cast<int>(str[i].height / 0.15f);

		float dz = (str[i].end.y - str[i].start.y) / static_cast<float>(steps);
		for (int j = 0; j < steps; ++j)
		{
			BoundBox box;
			float sx, sy, sz;
			float ex, ey, ez;

			sx = str[i].start.x;
			sy = 0.0f;
			sz = str[i].start.y + dz * j;

			ex = str[i].end.x;
			ey = 0.15f * (static_cast<float>(j + 1));
			ez = str[i].start.y + dz * (j + 1);
			box.start = XMFLOAT3(sx, sy, sz);
			box.end = XMFLOAT3(ex, ey, ez);
			bx[idx] = box;
			idx += 1;
		}
	}
	*n = count;
	return bx;
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

void LoadHeight(const char* filename, float** data)
{
	FILE* f = fopen(filename, "r");
	
	

	while (!feof(f))
	{
		float sx, sz, ex, ez, h;
		fscanf(f, "start : (%f, %f)   end : (%f, %f)   height : %f\n", &sx, &sz, &ex, &ez, &h);
		
		int x1 = (int)(sx / 0.5f);
		int z1 = (int)(sz / 0.5f);
		int x2 = (int)(ex / 0.5f)-1;
		int z2 = (int)(ez / 0.5f)-1;

		for (int x = x1; x <= x2; ++x)
		{
			for (int z = z1; z <= z2; ++z)
			{
				data[x][z] = h;
			}
		}
	}
	
	fclose(f);
}