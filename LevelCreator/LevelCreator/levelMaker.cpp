#include "levelMaker.h"

vector<Object> list;

vector<BoundingBox> bList;
vector<BoundingSphere> sList;

int x11 = 400;
int z11 = 400;

int x12 = 800;
int z12 = 400;

int x13 = 400;
int z13 = 800;

int x21 = 200;
int z21 = 400;

int x22 = 200;
int z22 = 680;

int x23 = 600;
int z23 = 180;


float* height1_1;
float* height1_2;
float* height1_3;
float* height2_1;
float* height2_2;
float* height2_3;

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
	
	FILE* hf11 = fopen("result/height1-1.txt", "w");
	FILE* hf12 = fopen("result/height1-2.txt", "w");
	FILE* hf13 = fopen("result/height1-3.txt", "w");
	FILE* hf21 = fopen("result/height2-1.txt", "w");
	FILE* hf22 = fopen("result/height2-2.txt", "w");
	FILE* hf23 = fopen("result/height2-3.txt", "w");
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
	writeHeight(hf11, height1_1, x11 * z11);
	fclose(file);
	fclose(bf);
	fclose(hf11);
	fclose(hf12);
	fclose(hf13);
	fclose(hf21);
	fclose(hf22);
	fclose(hf23);

	delete height1_1;
	delete height1_2;
	delete height1_3;
	delete height2_1;
	delete height2_2;
	delete height2_3;

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

	height1_1 = new float[x11*z11];
	height1_2 = new float[x12*z12];
	height1_3 = new float[x13*z13];
	height2_1 = new float[x21*z21];
	height2_2 = new float[x22*z22];
	height2_3 = new float[x23*z23];

	for (int i = 0; i < x11 * z11; ++i)
	{
		height1_1[i] = 0.0f;
	}
	for (int i = 0; i < x12 * z12; ++i)
	{
		height1_2[i] = 0.0f;
	}
	for (int i = 0; i < x13 * z13; ++i)
	{
		height1_3[i] = 0.0f;
	}
	for (int i = 0; i < x21 * z21; ++i)
	{
		height2_1[i] = 0.0f;
	}
	for (int i = 0; i < x22 * z22; ++i)
	{
		height2_2[i] = 0.0f;
	}
	for (int i = 0; i < x23 * z23; ++i)
	{
		height2_3[i] = 0.0f;
	}
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

	Object* Left100m = (Object*)malloc(sizeof(Object));
	Left100m->location = f3(50.0f, 0.0f, 100.0f);
	Left100m->rotation = f3(0.0f, 0.0f, 0.0f);
	Left100m->type = RustyMetal_Wall_Left_100m;

	Object* center50m = (Object*)malloc(sizeof(Object));
	center50m->location = f3(100.0f, 0.0f, 50.0f);
	center50m->rotation = f3(0.0f, 0.0f, 0.0f);
	center50m->type = RustyMetal_Wall_Center_50m;

	Object* hcenter50m = (Object*)malloc(sizeof(Object));
	hcenter50m->location = f3(50.0f, 0.0f, 100.0f);
	hcenter50m->rotation = f3(0.0f, 0.0f, 0.0f);
	hcenter50m->type = RustyMetal_Wall_HCenter_50m;

	Object* bottom50m = (Object*)malloc(sizeof(Object));
	bottom50m->location = f3(100.0f, 0.0f, 50.0f);
	bottom50m->rotation = f3(0.0f, 0.0f, 0.0f);
	bottom50m->type = RustyMetal_Wall_Bottom_50m;

	Object* top100m = (Object*)malloc(sizeof(Object));
	top100m->location = f3(100.0f, 0.0f, 150.0f);
	top100m->rotation = f3(0.0f, 0.0f, 0.0f);
	top100m->type = RustyMetal_Wall_Top_100m;




	Object* Barrel = (Object*)malloc(sizeof(Object));
	Barrel->location = f3(50.0f, 2.625f, 50.0f);
	Barrel->rotation = f3(0.0f, 0.0f, 0.0f);
	Barrel->type = RustyMetal_Barrel;

	Object* wpipe = (Object*)malloc(sizeof(Object));
	wpipe->location = f3(0.0f, 1.5f, 50.0f);
	wpipe->rotation = f3(0.0f, 0.0f, 0.0f);
	wpipe->type = WallPipe;

	Object* cpipe = (Object*)malloc(sizeof(Object));
	cpipe->location = f3(0.0f, 0.5f, 50.0f);
	cpipe->rotation = f3(0.0f, 0.0f, 0.0f);
	cpipe->type = FloorPipe;

	


	BoundingBox* boxFloor = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxFloor->start = f3(0.0f, 0.0f, 0.0f);
	boxFloor->end = f3(200.0f, 0.001f, 200.0f);
	
	

	BoundingBox* boxFrontWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxFrontWall->start = f3(0.0f, 0.0f, 199.999f);
	boxFrontWall->end = f3(200.0f, 10.0f, 200.0f);
	setAreaHeight(height1_1, x11, z11, 0.0f, 199.5f, 200.0f, 200.0f, 10.0f);

	BoundingBox* boxBackWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBackWall->start = f3(0.0f, 0.0f, 0.0f);
	boxBackWall->end = f3(200.0f, 10.0f, 0.001f);
	setAreaHeight(height1_1, x11, z11, 0.0f, 0.0f, 200.0f, 0.5f, 10.0f);


	BoundingBox* boxLeftWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxLeftWall->start = f3(0.0f, 0.0f, 0.0f);
	boxLeftWall->end = f3(0.001f, 10.0f, 200.0f);
	setAreaHeight(height1_1, x11, z11, 0.0f, 0.0f, 0.5f, 200.0f, 10.0f);

	BoundingBox* boxRightWall = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxRightWall->start = f3(199.999f, 0.0f, 0.0f);
	boxRightWall->end = f3(200.0f, 10.0f, 200.0f);
	setAreaHeight(height1_1, x11, z11, 199.5f, 0.0f, 200.0f, 200.0f, 10.0f);


	BoundingBox* boxCeiling = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxCeiling->start = f3(0.0f, 9.999f, 0.0f);
	boxCeiling->end = f3(200.0f, 10.0f, 200.0f);



	BoundingBox* boxLeft100m = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxLeft100m->start = f3(49.999f, 0.0f, 100.0f);
	boxLeft100m->end = f3(50.001f, 10.0f, 200.0f);
	setAreaHeight(height1_1, x11, z11, 49.5f, 99.5f, 50.5f, 200.0f, 10.0f);


	BoundingBox* boxCenter50m = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxCenter50m->start = f3(99.999f, 0.0f, 50.0f);
	boxCenter50m->end = f3(100.001f, 10.0f, 100.0f);
	setAreaHeight(height1_1, x11, z11, 99.5f, 49.5f, 100.5f, 100.5f, 10.0f);


	BoundingBox* boxHCenter50m = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxHCenter50m->start = f3(50.0f, 0.0f, 99.999f);
	boxHCenter50m->end = f3(100.0f, 10.0f, 100.001f);
	setAreaHeight(height1_1, x11, z11, 49.5f, 99.5f, 100.5f, 100.5f, 10.0f);


	BoundingBox* boxBottom50m = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBottom50m->start = f3(100.0f, 0.0f, 49.999f);
	boxBottom50m->end = f3(150.0f, 10.0f, 50.001f);
	setAreaHeight(height1_1, x11, z11, 99.5f, 49.5f, 150.5f, 50.5f, 10.0f);

	BoundingBox* boxTop100m = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxTop100m->start = f3(100.0f, 0.0f, 149.999f);
	boxTop100m->end = f3(200.0f, 10.0f, 150.001f);
	setAreaHeight(height1_1, x11, z11, 99.5f, 149.5f, 200.0, 150.5f, 10.0f);


	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			float x = 10.0f * i + 20.0f;
			float y = 10.0f * j + 20.0f;

			Object* Box = (Object*)malloc(sizeof(Object));
			Box->location = f3(x - 1.0f, 0.75f, y - 1.0f);
			Box->rotation = f3(0.0f, 0.0f, 0.0f);
			Box->type = RustyMetal_Box;

			BoundingBox* boxBox = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxBox->start = f3(x - 1.5f, 0.0f, y - 1.5f);
			boxBox->end = f3(x, 1.5f, y);
			setAreaHeight(height1_1, x11, z11, x - 1.75f, y - 1.75f, x+0.25f, y+0.25f, 1.5f);


			Object* Box2 = (Object*)malloc(sizeof(Object));
			Box2->location = f3(x + 0.5f, 0.75f, y - 1.0f);
			Box2->rotation = f3(0.0f, 0.0f, 0.0f);
			Box2->type = RustyMetal_Box;

			BoundingBox* boxBox2 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxBox2->start = f3(x, 0.0f, y - 1.5f);
			boxBox2->end = f3(x + 1.5f, 1.5f, y);
			setAreaHeight(height1_1, x11, z11, x-0.25f, y - 1.75f, x+1.75f, y+0.25f, 1.5f);


			Object* Box3 = (Object*)malloc(sizeof(Object));
			Box3->location = f3(x - 1.0f, 0.75f, y + 0.5f);
			Box3->rotation = f3(0.0f, 0.0f, 0.0f);
			Box3->type = RustyMetal_Box;

			BoundingBox* boxBox3 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxBox3->start = f3(x - 1.5f, 0.0f, y);
			boxBox3->end = f3(x, 1.5f, y + 1.5f);
			setAreaHeight(height1_1, x11, z11, x - 1.75f, y-0.25f, x+0.25f, y+1.75f, 1.5f);


			Object* Box4 = (Object*)malloc(sizeof(Object));
			Box4->location = f3(x + 0.5f, 0.75f, y + 0.5f);
			Box4->rotation = f3(0.0f, 0.0f, 0.0f);
			Box4->type = RustyMetal_Box;

			BoundingBox* boxBox4 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxBox4->start = f3(x, 0.0f, y);
			boxBox4->end = f3(x + 1.5f, 1.5f, y + 1.5f);
			setAreaHeight(height1_1, x11, z11, x-0.25f, y-0.25f, x+1.75f, y+1.75f, 1.5f);


			Object* Box5 = (Object*)malloc(sizeof(Object));
			Box5->location = f3(x, 2.25f, y);
			Box5->rotation = f3(0.0f, 0.0f, 0.0f);
			Box5->type = RustyMetal_Box;

			BoundingBox* boxBox5 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxBox5->start = f3(x-0.75f, 1.5f, y - 0.75f);
			boxBox5->end = f3(x+0.75f, 3.0f, y+0.75f);
			setAreaHeight(height1_1, x11, z11, x-1.0f, y-1.0f, x+1.0f, y+1.0f, 3.0f);

			list.push_back(*Box);
			blist.push_back(*boxBox);
			list.push_back(*Box2);
			blist.push_back(*boxBox2);
			list.push_back(*Box3);
			blist.push_back(*boxBox3);
			list.push_back(*Box4);
			blist.push_back(*boxBox4);
			list.push_back(*Box5);
			blist.push_back(*boxBox5);
		}
	}

	

	BoundingBox* boxBarrel = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBarrel->start = f3(49.25f, 1.5f, 49.25f);
	boxBarrel->end = f3(50.75f, 3.75f, 50.75f);
	setAreaHeight(height1_1, x11, z11, 49.25f, 49.25f, 50.75f, 50.75f, 3.75f);

	BoundingBox* boxPipe1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxPipe1->start = f3(-1.0f, -1.0f, -1.0f);
	boxPipe1->end = f3(0.0f, 0.0f, 0.0f);
	//setAreaHeight(height1_1, x11, z11, 49.25f, 49.25f, 50.75f, 50.75f, 3.75f);

	BoundingBox* boxPipe2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxPipe2->start = f3(-1.0f, -1.0f, -1.0f);
	boxPipe2->end = f3(0.0f, 0.0f, 0.0f);

	Object* fence = (Object*)malloc(sizeof(Object));
	fence->location = f3(25.0f, 0.3f, 160.0f);
	fence->rotation = f3(0.0f, 0.0f, 0.0f);
	fence->type = RustyFence;

	BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxFence->start = f3(24.875f, 0.0f,156.0f);
	boxFence->end = f3(25.125f, 1.5f, 160.0f);
	setAreaHeight(height1_1, x11, z11, 24.75f, 156.0f, 25.25f, 160.0f, 2.5f);

	Object* food = (Object*)malloc(sizeof(Object));
	food->location = f3(27.0f, 0.0f, 160.0f);
	food->rotation = f3(0.0f, 0.0f, 0.0f);
	food->type = FoodBin;

	BoundingBox* boxFood = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxFood->start = f3(26.5f, 0.0f, 159.5f);
	boxFood->end = f3(27.5f, 1.5f, 160.5f);
	setAreaHeight(height1_1, x11, z11, 26.5f, 159.5f, 27.5f, 160.5f, 1.5f);

	Object* envelope1 = (Object*)malloc(sizeof(Object));
	envelope1->location = f3(29.0f, 0.0f, 160.0f);
	envelope1->rotation = f3(0.0f, 0.0f, 0.0f);
	envelope1->type = Envelop1;

	BoundingBox* boxEnv1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxEnv1->start = f3(28.5f, 0.0f, 159.5f);
	boxEnv1->end = f3(29.5f, 0.5f, 160.5f);
	setAreaHeight(height1_1, x11, z11, 28.5f, 159.5f, 29.5f, 160.5f, 0.75f);

	Object* envelope2 = (Object*)malloc(sizeof(Object));
	envelope2->location = f3(30.0f, 0.5f, 160.0f);
	envelope2->rotation = f3(0.0f, 0.0f, 0.0f);
	envelope2->type = Envelop2;

	BoundingBox* boxEnv2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxEnv2->start = f3(29.5f, 0.0f, 159.5f);
	boxEnv2->end = f3(30.5f, 0.5f, 160.5f);
	setAreaHeight(height1_1, x11, z11, 29.5f, 159.5f, 30.5f, 160.5f, 0.75f);

	Object* envelope3 = (Object*)malloc(sizeof(Object));
	envelope3->location = f3(31.0f, 0.5f, 160.0f);
	envelope3->rotation = f3(0.0f, 0.0f, 180.0f);
	envelope3->type = Envelop3;

	BoundingBox* boxEnv3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxEnv3->start = f3(30.5f, 0.0f, 159.5f);
	boxEnv3->end = f3(31.5f, 0.5f, 160.5f);
	setAreaHeight(height1_1, x11, z11, 30.5f, 159.5f, 31.5f, 160.5f, 0.75f);

	Object* ladder = (Object*)malloc(sizeof(Object));
	ladder->location = f3(23.0f, 1.0f, 160.0f);
	ladder->rotation = f3(0.0f, 0.0f, 0.0f);
	ladder->type = MetalLadder;

	BoundingBox* boxLadder = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxLadder->start = f3(22.25f, 0.0f, 159.5f);
	boxLadder->end = f3(23.75f, 0.5f, 160.5f);
	setAreaHeight(height1_1, x11, z11, 22.25f, 159.5f, 23.75f, 160.5f, 1.0f);

	Object* railBend = (Object*)malloc(sizeof(Object));
	railBend->location = f3(22.0f, 0.0f, 160.0f);
	railBend->rotation = f3(0.0f, 0.0f, 0.0f);
	railBend->type = RailBend;

	BoundingBox* boxBend = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBend->start = f3(21.5f, 0.0f, 156.75f);
	boxBend->end = f3(22.5f, 0.1f, 163.25f);
	
	Object* railStr = (Object*)malloc(sizeof(Object));
	railStr->location = f3(21.0f, 0.0f, 160.0f);
	railStr->rotation = f3(0.0f, 0.0f, 0.0f);
	railStr->type = RailStraight;

	BoundingBox* boxStraight = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxStraight->start = f3(20.5f, 0.0f, 156.75f);
	boxStraight->end = f3(21.5f, 0.1f, 163.25f);

	Object* ruinBrick1 = (Object*)malloc(sizeof(Object));
	ruinBrick1->location = f3(25.0f, 0.0f, 165.0f);
	ruinBrick1->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinBrick1->type = RuinBrick1;

	BoundingBox* boxBrick1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBrick1->start = f3(24.5f, 0.0f, 164.5f);
	boxBrick1->end = f3(25.5f, 0.3f, 165.5f);
	setAreaHeight(height1_1, x11, z11, 24.5f, 164.5f, 25.5f, 165.5f, 0.2f);

	Object* ruinBrick2 = (Object*)malloc(sizeof(Object));
	ruinBrick2->location = f3(24.0f, 0.0f, 165.0f);
	ruinBrick2->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinBrick2->type = RuinBrick2;

	BoundingBox* boxBrick2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBrick2->start = f3(23.75f, 0.0f, 164.75f);
	boxBrick2->end = f3(24.25f, 0.2f, 165.25f);
	setAreaHeight(height1_1, x11, z11, 23.75f, 164.75f, 24.25f, 165.25f, 0.2f);

	Object* ruinBrick3 = (Object*)malloc(sizeof(Object));
	ruinBrick3->location = f3(23.0f, 0.0f, 165.0f);
	ruinBrick3->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinBrick3->type = RuinBrick3;

	BoundingBox* boxBrick3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBrick3->start = f3(22.75f, 0.0f, 164.75f);
	boxBrick3->end = f3(23.25f, 0.2f, 165.25f);
	setAreaHeight(height1_1, x11, z11, 22.75f, 164.75f, 23.25f, 165.25f, 0.2f);

	Object* ruinBrick4 = (Object*)malloc(sizeof(Object));
	ruinBrick4->location = f3(22.0f, 0.0f, 165.0f);
	ruinBrick4->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinBrick4->type = RuinBrick4;

	BoundingBox* boxBrick4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBrick4->start = f3(21.5f, 0.0f, 164.5f);
	boxBrick4->end = f3(22.5f, 0.25f, 165.5f);
	setAreaHeight(height1_1, x11, z11, 21.5f, 164.5f, 22.5f, 165.5f, 0.2f);

	Object* ruinBrick5 = (Object*)malloc(sizeof(Object));
	ruinBrick5->location = f3(21.0f, 0.0f, 165.0f);
	ruinBrick5->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinBrick5->type = RuinBrick5;

	BoundingBox* boxBrick5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxBrick5->start = f3(20.5f, 0.0f, 164.5f);
	boxBrick5->end = f3(21.5f, 0.25f, 165.5f);
	setAreaHeight(height1_1, x11, z11, 20.5f, 164.5f, 21.5f, 165.5f, 0.2f);

	Object* ruinCeramic1 = (Object*)malloc(sizeof(Object));
	ruinCeramic1->location = f3(26.0f, 0.0f, 165.0f);
	ruinCeramic1->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinCeramic1->type = RuinCeramic1;

	BoundingBox* boxCeramic1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxCeramic1->start = f3(25.5f, 0.0f, 164.5f);
	boxCeramic1->end = f3(26.5f, 0.2f, 165.5f);
	setAreaHeight(height1_1, x11, z11, 25.5f, 164.5f, 26.5f, 165.5f, 0.2f);

	Object* ruinCeramic2 = (Object*)malloc(sizeof(Object));
	ruinCeramic2->location = f3(27.0f, 0.0f, 165.0f);
	ruinCeramic2->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinCeramic2->type = RuinCeramic2;

	BoundingBox* boxCeramic2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxCeramic2->start = f3(26.5f, 0.0f, 164.5f);
	boxCeramic2->end = f3(27.5f, 0.3f, 165.5f);
	setAreaHeight(height1_1, x11, z11, 26.5f, 164.5f, 27.5f, 165.5f, 0.2f);

	Object* ruinMix1 = (Object*)malloc(sizeof(Object));
	ruinMix1->location = f3(25.0f, 0.0f, 170.0f);
	ruinMix1->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinMix1->type = RuinMix1;

	BoundingBox* boxMix1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxMix1->start = f3(23.875f, 0.0f, 168.875f);
	boxMix1->end = f3(26.125f, 0.2f, 171.125f);
	setAreaHeight(height1_1, x11, z11, 24.0f, 168.5f, 26.0f, 171.5f, 0.2f);

	Object* ruinMix2 = (Object*)malloc(sizeof(Object));
	ruinMix2->location = f3(27.0f, 0.0f, 170.0f);
	ruinMix2->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinMix2->type = RuinMix2;

	BoundingBox* boxMix2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxMix2->start = f3(25.875f, 0.0f, 168.875f);
	boxMix2->end = f3(28.125f, 0.2f, 171.125f);
	setAreaHeight(height1_1, x11, z11, 26.0f, 168.5f, 28.0f, 171.5f, 0.2f);

	Object* ruinWood1 = (Object*)malloc(sizeof(Object));
	ruinWood1->location = f3(23.0f, 0.0f, 170.0f);
	ruinWood1->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinWood1->type = RuinWood1;

	BoundingBox* boxWood1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxWood1->start = f3(21.875f, 0.0f, 168.875f);
	boxWood1->end = f3(24.125f, 0.2f, 171.125f);
	setAreaHeight(height1_1, x11, z11, 22.0f, 168.5f, 24.0f, 171.5f, 0.2f);

	Object* ruinWood2 = (Object*)malloc(sizeof(Object));
	ruinWood2->location = f3(21.0f, 0.0f, 170.0f);
	ruinWood2->rotation = f3(0.0f, 0.0f, 0.0f);
	ruinWood2->type = RuinWood2;

	BoundingBox* boxWood2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxWood2->start = f3(19.875f, 0.0f, 168.875f);
	boxWood2->end = f3(22.125f, 0.2f, 171.125f);
	setAreaHeight(height1_1, x11, z11, 20.0f, 168.5f, 22.0f, 171.5f, 0.2f);

	Object* rustyStair = (Object*)malloc(sizeof(Object));
	rustyStair->location = f3(15.0f, 0.0f, 165.0f);
	rustyStair->rotation = f3(0.0f, 0.0f, 0.0f);
	rustyStair->type = RustyStair;

	BoundingBox* boxStair = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxStair->start = f3(15.0f, 0.0f, 165.0f);
	boxStair->end = f3(18.0f, 3.0f, 168.0f);
	setAreaHeight(height1_1, x11, z11, 15.0f, 165.0f, 18.0f, 168.0f, 3.0f);

	Object* garbageCan = (Object*)malloc(sizeof(Object));
	garbageCan->location = f3(12.0f, 0.0f, 165.0f);
	garbageCan->rotation = f3(0.0f, 0.0f, 0.0f);
	garbageCan->type = RustyTrashCan;

	BoundingBox* boxCan = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxCan->start = f3(11.625f, 0.0f, 164.625f);
	boxCan->end = f3(12.375f, 1.5f, 165.375f);
	setAreaHeight(height1_1, x11, z11, 11.5f, 164.75f, 12.55f, 165.75f, 1.5f);

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

	list.push_back(*Left100m);
	blist.push_back(*boxLeft100m);

	list.push_back(*center50m);
	blist.push_back(*boxCenter50m);

	list.push_back(*hcenter50m);
	blist.push_back(*boxHCenter50m);

	list.push_back(*bottom50m);
	blist.push_back(*boxBottom50m);

	list.push_back(*top100m);
	blist.push_back(*boxTop100m);

	

	list.push_back(*Barrel);
	blist.push_back(*boxBarrel);

	list.push_back(*wpipe);
	blist.push_back(*boxPipe1);
	list.push_back(*cpipe);
	blist.push_back(*boxPipe2);

	list.push_back(*fence);
	blist.push_back(*boxFence);

	list.push_back(*food);
	blist.push_back(*boxFood);

	list.push_back(*envelope1);
	blist.push_back(*boxEnv1);

	list.push_back(*envelope2);
	blist.push_back(*boxEnv2);

	list.push_back(*envelope3);
	blist.push_back(*boxEnv3);

	list.push_back(*ladder);
	blist.push_back(*boxLadder);

	list.push_back(*railBend);
	blist.push_back(*boxBend);

	list.push_back(*railStr);
	blist.push_back(*boxStraight);

	list.push_back(*ruinBrick1);
	blist.push_back(*boxBrick1);
	list.push_back(*ruinBrick2);
	blist.push_back(*boxBrick2);
	list.push_back(*ruinBrick3);
	blist.push_back(*boxBrick3);
	list.push_back(*ruinBrick4);
	blist.push_back(*boxBrick4);
	list.push_back(*ruinBrick5);
	blist.push_back(*boxBrick5);

	list.push_back(*ruinCeramic1);
	blist.push_back(*boxCeramic1);
	list.push_back(*ruinCeramic2);
	blist.push_back(*boxCeramic2);

	list.push_back(*ruinMix1);
	blist.push_back(*boxMix1);
	list.push_back(*ruinMix2);
	blist.push_back(*boxMix2);

	list.push_back(*ruinWood1);
	blist.push_back(*boxWood1);
	list.push_back(*ruinWood2);
	blist.push_back(*boxWood2);

	list.push_back(*rustyStair);
	blist.push_back(*boxStair);

	list.push_back(*garbageCan);
	blist.push_back(*boxCan);
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