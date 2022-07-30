#include "func.h"

int main()
{
	vector<Vec2*> data;
	vector<iVec2*> rescData;
	data = LoadData("res/2-2/vtx_Counters.txt");

	rescData = rescale(data);

	writeImage(rescData, "result/2-2/vtx_Counters_S.png"); //2=1 ม๘วเ

	return 0;
}
