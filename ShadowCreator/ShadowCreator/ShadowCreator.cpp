#include "func.h"

int main()
{
	vector<Vec2*> data;
	vector<iVec2*> rescData;
	data = LoadData("res/vtx_�鳯�ܰ�2.txt");

	rescData = rescale(data);

	writeImage(rescData, "result/sdw_�鳯�ܰ�2.png");

	return 0;
}
