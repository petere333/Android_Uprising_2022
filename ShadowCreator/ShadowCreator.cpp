#include "func.h"

int main()
{
	vector<Vec2*> data;
	vector<iVec2*> rescData;
	data = LoadData("res/2-2/vtx_Counters2.txt");

	rescData = rescale(data);

	writeImage(rescData, "result/2-2/vtx_Counters2_T.png"); //2=1 ม๘วเ

	return 0;
}
