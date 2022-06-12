#include "levelMaker.h"

vector<Object> list;

vector<BoundingBox> bList;
vector<BoundingSphere> sList;

FILE* file;

float contX = 10.0f, contY = 2.5f, contZ = 6.0f;
float boxX = 0.5f, boxY = 0.5f, boxZ = 0.5f;
float palletX = 4.0f, palletY = 2.0f, palletZ = 3.0f;
float tableX = 2.0f, tableY = 1.0f, tableZ = 1.0f;
float chairX = 0.4f, chairY = 1.2f, chairZ = 0.4f;
float barrelX = 0.5f, barrelY = 1.5f, barrelZ = 0.5f;
float trashX = 1.0f, trashY = 1.2f, trashZ = 0.6f;
float truckX = 1.8f, truckY = 2.0f, truckZ = 6.0f;

int main()
{
	createObjects(list,bList);

	//파일 이름도 구역마다 다르게 구분을 주어야 한다.
	//그래야 구역 별로 나눈 쉐이더 하나 당 하나씩 넣을 수 있다.
	
	file = fopen("result/objects1-1.txt", "w");
	FILE* bf = fopen("result/box1-1.txt", "w");
	
	//file = fopen("result/objects1-2.txt", "w");
	//FILE* bf = fopen("result/box1-2.txt", "w");

	//file = fopen("result/objects1-3.txt", "w");
	//FILE* bf = fopen("result/box1-3.txt", "w");

	//file = fopen("result/objects2-1.txt", "w");
	//FILE* bf = fopen("result/box2-1.txt", "w");
	
	//file = fopen("result/objects2-2.txt", "w");
	//FILE* bf = fopen("result/box2-2.txt", "w");
	
	//file = fopen("result/objects2-3.txt", "w");
	//FILE* bf = fopen("result/box2-3.txt", "w");

	for (int i = 0; i < list.size(); ++i)
	{
		writeFile(file, list[i]);
	}

	for (int i = 0; i < bList.size(); ++i)
	{
		writeBox(bf, bList[i]);
	}

	fclose(file);
	fclose(bf);
	return 0;
}

void createPlayer(vector<Object>& list)
{

}
void createSpace(vector<Object>& list, vector<BoundingBox>& blist)
{
	
}
void createObjects(vector<Object>& list, vector<BoundingBox>& blist)
{
	createObstacles1_1(list, blist);

	// 자신이 배치하고자 하는 구역 한 번에 하나씩만 주석을 풀면 된다.

	//createObstacles1_2(list, blist);
	//createObstacles1_3(list, blist);
	//createObstacles2_1(list, blist);
	//createObstacles2_2(list, blist);
	//createObstacles2_3(list, blist);
}

void createObstacles1_1(vector<Object>& list, vector<BoundingBox>& blist)
{
	Object* floor = (Object*)malloc(sizeof(Object));
	floor->location = f3(0.0f, 0.001f, 0.0f);
	floor->rotation = f3(0.0f, 0.0f, 0.0f);
	floor->type = RustyMetal_Floor;

	Object* FrontWall = (Object*)malloc(sizeof(Object));
	FrontWall->location = f3(0.0f, 0.0f, 199.999f);
	FrontWall->rotation = f3(0.0f, 0.0f, 0.0f);
	FrontWall->type = RustyMetal_Wall_Front;

	Object* BackWall = (Object*)malloc(sizeof(Object));
	BackWall->location = f3(0.0f, 0.0f, 0.001f);
	BackWall->rotation = f3(0.0f, 0.0f, 0.0f);
	BackWall->type = RustyMetal_Wall_Back;

	Object* LeftWall = (Object*)malloc(sizeof(Object));
	LeftWall->location = f3(0.001f, 0.0f, 0.0f);
	LeftWall->rotation = f3(0.0f, 0.0f, 0.0f);
	LeftWall->type = RustyMetal_Wall_Left;

	Object* RightWall = (Object*)malloc(sizeof(Object));
	RightWall->location = f3(199.999f, 0.0f, 0.0f);
	RightWall->rotation = f3(0.0f, 0.0f, 0.0f);
	RightWall->type = RustyMetal_Wall_Right;

	Object* Ceiling = (Object*)malloc(sizeof(Object));
	Ceiling->location = f3(0.0f, 9.999f, 0.0f);
	Ceiling->rotation = f3(0.0f, 0.0f, 0.0f);
	Ceiling->type = RustyMetal_Ceiling;

	BoundingBox* boxFloor = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxFloor->start = f3(0.0f, 0.0f, 0.0f);
	boxFloor->end = f3(200.0f, 0.001f, 200.0f);


	BoundingBox* boxFrontWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxFrontWall->start = f3(0.0f, 0.0f, 199.999f);
	boxFrontWall->end = f3(200.0f, 10.0f, 200.0f);

	BoundingBox* boxBackWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBackWall->start = f3(0.0f, 0.0f, 0.0f);
	boxBackWall->end = f3(200.0f, 10.0f, 0.001f);

	BoundingBox* boxLeftWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxLeftWall->start = f3(0.0f, 0.0f, 0.0f);
	boxLeftWall->end = f3(0.001f, 10.0f, 200.0f);

	BoundingBox* boxRightWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxRightWall->start = f3(199.999f, 0.0f, 0.0f);
	boxRightWall->end = f3(200.0f, 10.0f, 200.0f);

	BoundingBox* boxCeiling = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxCeiling->start = f3(0.0f, 9.999f, 0.0f);
	boxCeiling->end = f3(200.0f, 10.0f, 200.0f);

	list.push_back(*floor);
	blist.push_back(*boxFloor);

	list.push_back(*FrontWall);
	blist.push_back(*boxFrontWall);

	list.push_back(*BackWall);
	blist.push_back(*boxBackWall);

	list.push_back(*LeftWall);
	blist.push_back(*boxLeftWall);

	list.push_back(*RightWall);
	blist.push_back(*boxRightWall);

	list.push_back(*Ceiling);
	blist.push_back(*boxCeiling);
}

void createObstacles1_2(vector<Object>& list, vector<BoundingBox>& blist)
{

}

void createObstacles1_3(vector<Object>& list, vector<BoundingBox>& blist)
{

}

void createObstacles2_1(vector<Object>& list, vector<BoundingBox>& blist)
{

}

void createObstacles2_2(vector<Object>& list, vector<BoundingBox>& blist)
{

}

void createObstacles2_3(vector<Object>& list, vector<BoundingBox>& blist)
{

}