#include "func.h"

int main()
{
	vector<Vec2*> data;
	vector<iVec2*> rescData;
	data = LoadData("res/vtx_��ź�.txt");

	rescData = rescale(data);

	writeImage(rescData, "result/��ź�PTSD.png");

	return 0;
}
