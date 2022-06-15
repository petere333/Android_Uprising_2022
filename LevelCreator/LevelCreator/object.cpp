#include "object.h"

void writeFile(FILE* file, Object obj)
{
	fprintf(file, "position : (%f,  %f,  %f)  rotation : (%f,  %f,  %f)  type : %d\n", obj.location.x, obj.location.y, obj.location.z, obj.rotation.x, obj.rotation.y, obj.rotation.z, obj.type);
}

float3 f3(float f1, float f2, float f3)
{
	float3 f;
	f.x = f1;
	f.y = f2;
	f.z = f3;

	return f;
}

void writeHeight(FILE* file, float* data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		fprintf(file, "%f ", data[i]);
	}
}


void setAreaHeight(float* data, int areaWidth, int areaHeight, float startx, float startz, float endx, float endz, float height)
{
	int rx = (int)((endx - startx) / 0.5f);
	int rz = (int)((endz - startz) / 0.5f);

	int sx = (int)(startx / 0.5f);
	int sz = (int)(startz / 0.5f);

	

	for (int i = sx; i < sx+rx; ++i)
	{
		for (int j = sz; j < sz+rz; ++j)
		{
			data[i * areaWidth + j] = height;
		}
	}
}