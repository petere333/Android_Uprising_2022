#include "func.h"

int main()
{
	vector<Vec2*> data;
	vector<iVec2*> rescData;
	data = LoadData("res/vtx_體陳欽匐2.txt");

	rescData = rescale(data);

	writeImage(rescData, "result/sdw_體陳欽匐2.png");

	return 0;
}
