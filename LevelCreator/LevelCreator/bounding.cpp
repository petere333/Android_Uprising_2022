#include "bounding.h"

void writeBox(FILE* f, BoundingBox box)
{
	fprintf(f, "start : (%f,  %f,  %f)  end : (%f,  %f,  %f)\n", box.x1, box.y1, box.z1, box.x2, box.y2, box.z2);
}
void writeSphere(FILE* f, BoundingSphere sphere)
{
	fprintf(f, "center : (%f,  %f,  %f)  range : %f\n", sphere.x, sphere.y, sphere.z, sphere.dist);
}