#include "func.h"

int main()
{
	vector<Vec2*> data;
	vector<iVec2*> rescData;
	data = LoadData("res/vtx_통신병.txt");

	rescData = rescale(data);

	writeImage(rescData, "result/통신병PTSD.png");

	return 0;
}
