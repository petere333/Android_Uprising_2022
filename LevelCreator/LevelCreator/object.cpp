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

