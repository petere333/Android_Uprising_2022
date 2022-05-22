#pragma once

#include "common.h"

class Vec3
{
public:
	float x, y, z;
	Vec3(float, float, float);
	~Vec3();
};

class Vec2
{
public:
	float x, y;
	Vec2(float, float);
	~Vec2();
};

class iVec2
{
public:
	int x, y;
	iVec2(int i, int j)
	{
		x = i; y = j;
	};
	~iVec2() {};
};

vector<Vec2*> LoadData(const char*);

float getStartX(vector<Vec2*> data);
float getStartY(vector<Vec2*> data);
float getEndY(vector<Vec2*> data);
float getEndY(vector<Vec2*> data);

vector<iVec2*> rescale(vector<Vec2*> data);



void writeImage(vector<iVec2*> data, const char* name);