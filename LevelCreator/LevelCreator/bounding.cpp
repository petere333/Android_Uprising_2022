#include "bounding.h"

void writeBox(FILE* f, BoundingBox box)
{
	fprintf(f, "start : (%f,  %f,  %f)  end : (%f,  %f,  %f)\n", box.start.x, box.start.y, box.start.z, box.end.x, box.end.y, box.end.z);
}
void writeSphere(FILE* f, BoundingSphere sphere)
{
	fprintf(f, "center : (%f,  %f,  %f)  range : %f\n", sphere.center.x, sphere.center.y, sphere.center.z, sphere.dist);
}