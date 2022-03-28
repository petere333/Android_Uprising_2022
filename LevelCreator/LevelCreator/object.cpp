#include "object.h"

void writeFile(FILE* file, Object obj)
{
	fprintf(file, "position : (%f,  %f,  %f)   type : %d\n", obj.location.x, obj.location.y, obj.location.z, obj.type);
}

float3 f3(float f1, float f2, float f3)
{
	float3 f;
	f.x = f1;
	f.y = f2;
	f.z = f3;

	return f;
}

void createFloor(vector<Object>& list, float width, float height)
{
	int x = static_cast<int>(width / TileSize);
	int y = static_cast<int>(height / TileSize);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			Object o;
			o.location.x = TileSize * i;
			o.location.z = TileSize * j;
			o.location.y = 0.0f;
			o.type = TILE;

			list.push_back(o);
		}
	}
}