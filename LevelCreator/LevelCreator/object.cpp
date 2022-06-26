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

void writeHeight(FILE* file, std::vector<HeightData> data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		fprintf(file, "start : (%f, %f)   end : (%f, %f)   height : %f\n", data[i].startx, data[i].startz, data[i].endx, data[i].endz, data[i].height);
	}
}


void setAreaHeight(std::vector<HeightData>& data, int areaWidth, int areaHeight, float startx, float startz, float endx, float endz, float height)
{
	HeightData* d = (HeightData*)malloc(sizeof(HeightData));
	d->startx = startx;
	d->endx = endx;
	d->startz = startz;
	d->endz = endz;
	d->height = height;

	data.push_back(*d);
}