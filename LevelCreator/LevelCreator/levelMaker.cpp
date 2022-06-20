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
	
//	file = fopen("result/objects1-1.txt", "w");
//	FILE* bf = fopen("result/box1-1.txt", "w");
	
//	FILE* hf11 = fopen("result/height1-1.txt", "w");
//	FILE* hf12 = fopen("result/height1-2.txt", "w");
//	FILE* hf13 = fopen("result/height1-3.txt", "w");
	FILE* hf21 = fopen("result/height2-1.txt", "w");
//	FILE* hf22 = fopen("result/height2-2.txt", "w");
//	FILE* hf23 = fopen("result/height2-3.txt", "w");
	//file = fopen("result/objects1-2.txt", "w");
	//FILE* bf = fopen("result/box1-2.txt", "w");

	//file = fopen("result/objects1-3.txt", "w");
	//FILE* bf = fopen("result/box1-3.txt", "w");

	file = fopen("result/objects2-1.txt", "w");
	FILE* bf = fopen("result/box2-1.txt", "w");
	
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
//	writeHeight(hf11, height1_1, x11 * z11);
    writeHeight(hf21, height2_1, x11 * z11);
	fclose(file);
	fclose(bf);
//	fclose(hf11);
//	fclose(hf12);
//	fclose(hf13);
	fclose(hf21);
//	fclose(hf22);
//	fclose(hf23);

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
	// createObstacles1_1(list, blist);

	// 자신이 배치하고자 하는 구역 한 번에 하나씩만 주석을 풀면 된다.

	//createObstacles1_2(list, blist);
	//createObstacles1_3(list, blist);
	createObstacles2_1(list, blist);
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

	Object* Kwan_wall00 = (Object*)malloc(sizeof(Object));
	Kwan_wall00->location = f3(799.6f, 3.75f, 602.5f);
	Kwan_wall00->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall00->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall00 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall00->start = f3(800.0f, 0.0f, 592.5f);
	Gwangjae_wall00->end = f3(800.0f, 7.5f, 612.5f);

	Object* Kwan_wall0 = (Object*)malloc(sizeof(Object));
	Kwan_wall0->location = f3(799.6f, 3.75f, 582.5f);
	Kwan_wall0->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall0->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall0 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall0->start = f3(800.0f, 0.0f, 572.5f);
	Gwangjae_wall0->end = f3(800.0f, 7.5f, 592.5f);

	///////////////////////////////
	Object* Kwan_wall1 = (Object*)malloc(sizeof(Object));
	Kwan_wall1->location = f3(812.1f, 3.75f, 535.0f);
	Kwan_wall1->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1->start = f3(812.0f, 0.0f, 525.0f);
	Gwangjae_wall1->end = f3(813.0f, 7.5f, 545.0f);


	////////////
	Object* Kwan_wall2 = (Object*)malloc(sizeof(Object));
	Kwan_wall2->location = f3(812.1f, 3.75f, 515.0f);
	Kwan_wall2->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2->start = f3(812.0f, 0.0f, 505.0f);
	Gwangjae_wall2->end = f3(813.0f, 7.5f, 525.0f);

	////////////////////
	Object* Kwan_wall3 = (Object*)malloc(sizeof(Object));
	Kwan_wall3->location = f3(812.1f, 3.75f, 495.0f);
	Kwan_wall3->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3->start = f3(812.0f, 0.0f, 485.0f);
	Gwangjae_wall3->end = f3(813.0f, 7.5f, 505.0f);

	///////////////////////////////

	Object* Kwan_wall4 = (Object*)malloc(sizeof(Object));
	Kwan_wall4->location = f3(812.1f, 3.75f, 475.0f);
	Kwan_wall4->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4->start = f3(812.0f, 0.0f, 465.0f);
	Gwangjae_wall4->end = f3(813.0f, 7.5f, 485.0f);

	/////////////////////////////////

	Object* Kwan_wall5 = (Object*)malloc(sizeof(Object));
	Kwan_wall5->location = f3(812.1f, 3.75f, 455.0f);
	Kwan_wall5->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5->start = f3(812.0f, 0.0f, 445.0f);
	Gwangjae_wall5->end = f3(813.0f, 7.5f, 465.0f);

	Object* Kwan_wall6 = (Object*)malloc(sizeof(Object));
	Kwan_wall6->location = f3(812.1f, 3.75f, 435.0f);
	Kwan_wall6->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6->start = f3(812.0f, 0.0f, 425.0f);
	Gwangjae_wall6->end = f3(813.0f, 7.5f, 445.0f);

	Object* Kwan_wall7 = (Object*)malloc(sizeof(Object));
	Kwan_wall7->location = f3(812.1f, 3.75f, 415.0f);
	Kwan_wall7->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7->start = f3(812.0f, 0.0f, 405.0f);
	Gwangjae_wall7->end = f3(813.0f, 7.5f, 425.0f);

	Object* Kwan_wall8 = (Object*)malloc(sizeof(Object));
	Kwan_wall8->location = f3(812.1f, 3.75f, 395.0f);
	Kwan_wall8->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8->start = f3(812.0f, 0.0f, 385.0f);
	Gwangjae_wall8->end = f3(813.0f, 7.5f, 405.0f);

	Object* Kwan_wall9 = (Object*)malloc(sizeof(Object));
	Kwan_wall9->location = f3(812.1f, 3.75f, 375.0f);
	Kwan_wall9->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9->start = f3(812.0f, 0.0f, 365.0f);
	Gwangjae_wall9->end = f3(813.0f, 7.5f, 385.0f);


	/// <summary>
	/// //  관제실 왼쪽 벽 중단
	/// </summary>
	/// <param name="list"></param>
	/// <param name="blist"></param>
	Object* Kwan_wall1L = (Object*)malloc(sizeof(Object));
	Kwan_wall1L->location = f3(875.4f, 3.75f, 595.0f);
	Kwan_wall1L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall1L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1L->start = f3(875.0f, 0.0f, 585.0f);
	Gwangjae_wall1L->end = f3(875.0f, 7.5f, 605.0f);

	Object* Kwan_wall2L = (Object*)malloc(sizeof(Object));
	Kwan_wall2L->location = f3(875.4f, 3.75f, 575.0f);
	Kwan_wall2L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall2L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2L->start = f3(875.0f, 0.0f, 565.0f);
	Gwangjae_wall2L->end = f3(875.0f, 7.5f, 585.0f);

	Object* Kwan_wall3L = (Object*)malloc(sizeof(Object));
	Kwan_wall3L->location = f3(875.4f, 3.75f, 555.0f);
	Kwan_wall3L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall3L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3L->start = f3(875.0f, 0.0f, 545.0f);
	Gwangjae_wall3L->end = f3(875.0f, 7.5f, 565.0f);

	Object* Kwan_wall4L = (Object*)malloc(sizeof(Object));
	Kwan_wall4L->location = f3(875.4f, 3.75f, 535.0f);
	Kwan_wall4L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall4L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4L->start = f3(875.0f, 0.0f, 525.0f);
	Gwangjae_wall4L->end = f3(875.0f, 7.5f, 545.0f);

	Object* Kwan_wall5L = (Object*)malloc(sizeof(Object));
	Kwan_wall5L->location = f3(875.4f, 3.75f, 515.0f);
	Kwan_wall5L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall5L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5L->start = f3(875.0f, 0.0f, 505.0f);
	Gwangjae_wall5L->end = f3(875.0f, 7.5f, 525.0f);

	Object* Kwan_wall6L = (Object*)malloc(sizeof(Object));
	Kwan_wall6L->location = f3(875.4f, 3.75f, 495.0f);
	Kwan_wall6L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall6L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6L->start = f3(875.0f, 0.0f, 485.0f);
	Gwangjae_wall6L->end = f3(875.0f, 7.5f, 505.0f);

	Object* Kwan_wall7L = (Object*)malloc(sizeof(Object));
	Kwan_wall7L->location = f3(875.4f, 3.75f, 475.0f);
	Kwan_wall7L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall7L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7L->start = f3(875.0f, 0.0f, 465.0f);
	Gwangjae_wall7L->end = f3(875.0f, 7.5f, 485.0f);

	Object* Kwan_wall8L = (Object*)malloc(sizeof(Object));
	Kwan_wall8L->location = f3(875.4f, 3.75f, 455.0f);
	Kwan_wall8L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall8L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8L->start = f3(875.0f, 0.0f, 445.0f);
	Gwangjae_wall8L->end = f3(875.0f, 7.5f, 465.0f);

	Object* Kwan_wall9L = (Object*)malloc(sizeof(Object));
	Kwan_wall9L->location = f3(875.4f, 3.75f, 435.0f);
	Kwan_wall9L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall9L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9L->start = f3(875.0f, 0.0f, 425.0f);
	Gwangjae_wall9L->end = f3(875.0f, 10.0f, 445.0f);

	Object* Kwan_wall10L = (Object*)malloc(sizeof(Object));
	Kwan_wall10L->location = f3(875.4f, 3.75f, 415.0f);
	Kwan_wall10L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall10L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall10L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall10L->start = f3(875.0f, 0.0f, 405.0f);
	Gwangjae_wall10L->end = f3(875.0f, 10.0f, 425.0f);

	Object* Kwan_wall11L = (Object*)malloc(sizeof(Object));
	Kwan_wall11L->location = f3(875.4f, 3.75f, 395.0f);
	Kwan_wall11L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall11L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall11L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall11L->start = f3(875.0f, 0.0f, 385.0f);
	Gwangjae_wall11L->end = f3(875.0f, 10.0f, 405.0f);

	Object* Kwan_wall12L = (Object*)malloc(sizeof(Object));
	Kwan_wall12L->location = f3(875.4f, 3.75f, 375.0f);
	Kwan_wall12L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall12L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall12L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall12L->start = f3(875.0f, 0.0f, 365.0f);
	Gwangjae_wall12L->end = f3(875.0f, 10.0f, 385.0f);

	/// <summary>
	///  관제실 앞쪽 벽 중단
	/// </summary>
	/// <param name="list"></param>
	/// <param name="blist"></param>
	///

	Object* Kwan_wall1F = (Object*)malloc(sizeof(Object));
	Kwan_wall1F->location = f3(805.0f, 3.75f, 599.6f);
	Kwan_wall1F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall1F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall1F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1F->start = f3(795.0f, 0.0f, 599.1f);
	Gwangjae_wall1F->end = f3(815.0f, 10.0f, 600.1f);

	Object* Kwan_wall2F = (Object*)malloc(sizeof(Object));
	Kwan_wall2F->location = f3(825.0f, 3.75f, 599.6f);
	Kwan_wall2F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall2F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall2F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2F->start = f3(815.0f, 0.0f, 599.1f);
	Gwangjae_wall2F->end = f3(835.0f, 10.0f, 600.1f);

	Object* Kwan_wall3F = (Object*)malloc(sizeof(Object));
	Kwan_wall3F->location = f3(845.0f, 3.75f, 599.6f);
	Kwan_wall3F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall3F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall3F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3F->start = f3(835.0f, 0.0f, 599.1f);
	Gwangjae_wall3F->end = f3(855.0f, 10.0f, 600.1f);

	Object* Kwan_wall4F = (Object*)malloc(sizeof(Object));
	Kwan_wall4F->location = f3(865.0f, 3.75f, 599.6f);
	Kwan_wall4F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall4F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall4F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4F->start = f3(855.0f, 0.0f, 599.1f);
	Gwangjae_wall4F->end = f3(875.0f, 10.0f, 600.1f);


	///////////////////////////////////////////////////
// 바닥

	Object* Kwan_floor1 = (Object*)malloc(sizeof(Object));
	Kwan_floor1->location = f3(800.0f, 0.001f, 540.0f);
	Kwan_floor1->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_floor1->type = Gwanja_floor;

	BoundingBox* Gwangjae_floor1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_floor1->start = f3(800.0f, 0.00f, 540.0f);
	Gwangjae_floor1->end = f3(875.0f, 0.00f, 600.0f);


	/////////////////////////////////////////////////////////
	// 벽

	Object* Kwan_front1 = (Object*)malloc(sizeof(Object));
	Kwan_front1->location = f3(822.916f, 7.5f, 539.0f); // 20.833
	Kwan_front1->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front1->type = Gwanja_front;

	BoundingBox* Gwangjae_front1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front1->start = f3(812.5f, 2.5f, 538.0f);
	Gwangjae_front1->end = f3(833.333f, 12.5f, 540.0f);

	Object* Kwan_front2 = (Object*)malloc(sizeof(Object));
	Kwan_front2->location = f3(843.799f, 7.5f, 539.0f);
	Kwan_front2->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front2->type = Gwanja_front;

	BoundingBox* Gwangjae_front2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front2->start = f3(833.333f, 2.5f, 538.0f);
	Gwangjae_front2->end = f3(854.166f, 12.5f, 540.0f);

	Object* Kwan_front3 = (Object*)malloc(sizeof(Object));
	Kwan_front3->location = f3(864.633f, 7.5f, 539.0f);
	Kwan_front3->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front3->type = Gwanja_front;

	BoundingBox* Gwangjae_front3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front3->start = f3(854.166f, 2.5f, 538.0f);
	Gwangjae_front3->end = f3(875.0f, 12.5f, 540.0f);


	///////////////////////////////////////////////////////////////


	Object* Kwan_front4 = (Object*)malloc(sizeof(Object));
	Kwan_front4->location = f3(822.916f, 7.5f, 481.0f); // 20.833
	Kwan_front4->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front4->type = Gwanja_front;

	BoundingBox* Gwangjae_front4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front4->start = f3(812.5f, 2.5f, 480.0f);
	Gwangjae_front4->end = f3(833.333f, 12.5f, 482.0f);

	Object* Kwan_front5 = (Object*)malloc(sizeof(Object));
	Kwan_front5->location = f3(843.799f, 7.5f, 481.0f);
	Kwan_front5->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front5->type = Gwanja_front;

	BoundingBox* Gwangjae_front5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front5->start = f3(833.333f, 2.5f, 480.0f);
	Gwangjae_front5->end = f3(854.166f, 12.5f, 482.0f);

	Object* Kwan_front6 = (Object*)malloc(sizeof(Object));
	Kwan_front6->location = f3(864.633f, 7.5f, 481.0f);
	Kwan_front6->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front6->type = Gwanja_front;

	BoundingBox* Gwangjae_front6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front6->start = f3(854.166f, 2.5f, 480.0f);
	Gwangjae_front6->end = f3(875.0f, 12.5f, 482.0f);

	/////////////////////////////////////////////////////////////////////////


	Object* Kwan_front7 = (Object*)malloc(sizeof(Object));
	Kwan_front7->location = f3(822.916f, 7.5f, 423.0f); // 20.833
	Kwan_front7->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front7->type = Gwanja_front;

	BoundingBox* Gwangjae_front7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front7->start = f3(812.5f, 2.5f, 422.0f);
	Gwangjae_front7->end = f3(833.333f, 12.5f, 424.0f);

	Object* Kwan_front8 = (Object*)malloc(sizeof(Object));
	Kwan_front8->location = f3(843.799f, 7.5f, 423.0f);
	Kwan_front8->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front8->type = Gwanja_front;

	BoundingBox* Gwangjae_front8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front8->start = f3(833.333f, 2.5f, 422.0f);
	Gwangjae_front8->end = f3(854.166f, 12.5f, 424.0f);

	Object* Kwan_front9 = (Object*)malloc(sizeof(Object));
	Kwan_front9->location = f3(864.633f, 7.5f, 423.0f);
	Kwan_front9->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front9->type = Gwanja_front;

	BoundingBox* Gwangjae_front9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front9->start = f3(854.166f, 2.5f, 422.0f);
	Gwangjae_front9->end = f3(875.0f, 12.5f, 424.0f);

	///////////////////////////////////////////////////////////////////


	Object* Kwan_front10 = (Object*)malloc(sizeof(Object));
	Kwan_front10->location = f3(822.916f, 7.5f, 364.0f); // 20.833
	Kwan_front10->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front10->type = Gwanja_front;

	BoundingBox* Gwangjae_front10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front10->start = f3(812.5f, 2.5f, 363.0f);
	Gwangjae_front10->end = f3(833.333f, 12.5f, 365.0f);

	Object* Kwan_front11 = (Object*)malloc(sizeof(Object));
	Kwan_front11->location = f3(843.799f, 7.5f, 364.0f);
	Kwan_front11->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front11->type = Gwanja_front;

	BoundingBox* Gwangjae_front11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front11->start = f3(833.333f, 2.5f, 363.0f);
	Gwangjae_front11->end = f3(854.166f, 12.5f, 365.0f);

	Object* Kwan_front12 = (Object*)malloc(sizeof(Object));
	Kwan_front12->location = f3(864.633f, 7.5f, 364.0f);
	Kwan_front12->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front12->type = Gwanja_front;

	BoundingBox* Gwangjae_front12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front12->start = f3(854.166f, 2.5f, 363.0f);
	Gwangjae_front12->end = f3(875.0f, 12.5f, 365.0f);

	///////////////////////////////////////////////////////////////////

	Object* Kwan_celing1 = (Object*)malloc(sizeof(Object));
	Kwan_celing1->location = f3(800.0f, 12.3f, 365.0f);
	Kwan_celing1->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_celing1->type = Gwanja_celing;

	BoundingBox* Gwangjae_celing1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_celing1->start = f3(800.0f, 12.3f, 365.0f);
	Gwangjae_celing1->end = f3(875.0f, 12.5f, 600.0f);

	/////////////////////////////////////////////////////////////////////


	Object* Kwan_floor2 = (Object*)malloc(sizeof(Object));
	Kwan_floor2->location = f3(800.0f, 0.001f, 365.0f);
	Kwan_floor2->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_floor2->type = Gwanja_floor2;

	BoundingBox* Gwangjae_floor2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_floor2->start = f3(800.0f, 0.00f, 365.0f);
	Gwangjae_floor2->end = f3(875.0f, 0.00f, 540.0f);

	////////////////////////////////////////////////

	Object* Kwan_walle_1 = (Object*)malloc(sizeof(Object));
	Kwan_walle_1->location = f3(820.0f, 1.25f, 539.0f);
	Kwan_walle_1->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_1->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_1->start = f3(812.5f, 0.0f, 538.0f); /// 뭐야 이게
	Gwangjae_walle_1->end = f3(827.5f, 2.5f, 540.0f);

	Object* Kwan_walle_2 = (Object*)malloc(sizeof(Object));
	Kwan_walle_2->location = f3(835.0f, 1.25f, 539.0f);
	Kwan_walle_2->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_2->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_2->start = f3(827.5f, 0.0f, 538.0f);
	Gwangjae_walle_2->end = f3(842.5f, 2.5f, 540.0f);

	Object* Kwan_walle_3 = (Object*)malloc(sizeof(Object));
	Kwan_walle_3->location = f3(852.5f, 1.25f, 539.0f);
	Kwan_walle_3->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_3->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_3->start = f3(845.0f, 0.0f, 538.0f);
	Gwangjae_walle_3->end = f3(860.0f, 2.5f, 540.0f);

	Object* Kwan_walle_4 = (Object*)malloc(sizeof(Object));
	Kwan_walle_4->location = f3(867.5f, 1.25f, 539.0f);
	Kwan_walle_4->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_4->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_4->start = f3(860.0f, 0.0f, 538.0f);
	Gwangjae_walle_4->end = f3(875.0f, 2.5f, 540.0f);


	//////////////////////////////////////////////////////////////////////////

	Object* Kwan_walle_5 = (Object*)malloc(sizeof(Object));
	Kwan_walle_5->location = f3(820.0f, 1.25f, 481.0f);
	Kwan_walle_5->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_5->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_5->start = f3(812.5f, 0.0f, 480.0f);
	Gwangjae_walle_5->end = f3(827.5f, 2.5f, 482.0f);

	Object* Kwan_walle_6 = (Object*)malloc(sizeof(Object));
	Kwan_walle_6->location = f3(835.0f, 1.25f, 481.0f);
	Kwan_walle_6->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_6->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_6->start = f3(827.5f, 0.0f, 480.0f);
	Gwangjae_walle_6->end = f3(842.5f, 2.5f, 482.0f);

	Object* Kwan_walle_7 = (Object*)malloc(sizeof(Object));
	Kwan_walle_7->location = f3(852.5f, 1.25f, 481.0f);
	Kwan_walle_7->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_7->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_7->start = f3(845.0f, 0.0f, 480.0f);
	Gwangjae_walle_7->end = f3(860.0f, 2.5f, 482.0f);

	Object* Kwan_walle_8 = (Object*)malloc(sizeof(Object));
	Kwan_walle_8->location = f3(867.5f, 1.25f, 481.0f);
	Kwan_walle_8->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_8->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_8->start = f3(860.0f, 0.0f, 480.0f);
	Gwangjae_walle_8->end = f3(875.0f, 2.5f, 482.0f);

	//////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_walle_9 = (Object*)malloc(sizeof(Object));
	Kwan_walle_9->location = f3(820.0f, 1.25f, 423.0f);
	Kwan_walle_9->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_9->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_9->start = f3(812.5f, 0.0f, 422.0f);
	Gwangjae_walle_9->end = f3(827.5f, 2.5f, 424.0f);

	Object* Kwan_walle_10 = (Object*)malloc(sizeof(Object));
	Kwan_walle_10->location = f3(835.0f, 1.25f, 423.0f);
	Kwan_walle_10->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_10->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_10->start = f3(827.5f, 0.0f, 422.0f);
	Gwangjae_walle_10->end = f3(842.5f, 2.5f, 424.0f);

	Object* Kwan_walle_11 = (Object*)malloc(sizeof(Object));
	Kwan_walle_11->location = f3(852.5f, 1.25f, 423.0f);
	Kwan_walle_11->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_11->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_11->start = f3(845.0f, 0.0f, 422.0f);
	Gwangjae_walle_11->end = f3(860.0f, 2.5f, 424.0f);

	Object* Kwan_walle_12 = (Object*)malloc(sizeof(Object));
	Kwan_walle_12->location = f3(867.5f, 1.25f, 423.0f);
	Kwan_walle_12->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_12->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_12->start = f3(860.0f, 0.0f, 422.0f);
	Gwangjae_walle_12->end = f3(875.0f, 2.5f, 424.0f);

	/////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_walle_13 = (Object*)malloc(sizeof(Object));
	Kwan_walle_13->location = f3(820.0f, 1.25f, 364.0f);
	Kwan_walle_13->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_13->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_13->start = f3(812.5f, 0.0f, 363.0f);
	Gwangjae_walle_13->end = f3(827.5f, 2.5f, 365.0f);

	Object* Kwan_walle_14 = (Object*)malloc(sizeof(Object));
	Kwan_walle_14->location = f3(835.0f, 1.25f, 364.0f);
	Kwan_walle_14->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_14->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_14->start = f3(827.5f, 0.0f, 363.0f);
	Gwangjae_walle_14->end = f3(842.5f, 2.5f, 365.0f);

	Object* Kwan_walle_15 = (Object*)malloc(sizeof(Object));
	Kwan_walle_15->location = f3(852.5f, 1.25f, 364.0f);
	Kwan_walle_15->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_15->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_15->start = f3(845.0f, 0.0f, 363.0f);
	Gwangjae_walle_15->end = f3(860.0f, 2.5f, 365.0f);

	Object* Kwan_walle_16 = (Object*)malloc(sizeof(Object));
	Kwan_walle_16->location = f3(867.5f, 1.25f, 364.0f);
	Kwan_walle_16->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_16->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_16 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_16->start = f3(860.0f, 0.0f, 363.0f);
	Gwangjae_walle_16->end = f3(875.0f, 2.5f, 365.0f);


	///////////////////////////////////////////////////////////////

	Object* Kwan_wallFe = (Object*)malloc(sizeof(Object));
	Kwan_wallFe->location = f3(805.0f, 10.0f, 599.6f);
	Kwan_wallFe->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe->start = f3(795.0f, 7.5f, 599.1f);
	Gwangjae_wallFe->end = f3(815.0f, 12.5f, 600.1f);

	Object* Kwan_wallFe2 = (Object*)malloc(sizeof(Object));
	Kwan_wallFe2->location = f3(825.0f, 10.0f, 599.6f);
	Kwan_wallFe2->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe2->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe2->start = f3(815.0f, 7.5f, 599.1f);
	Gwangjae_wallFe2->end = f3(835.0f, 12.5f, 600.1f);

	Object* Kwan_wallFe3 = (Object*)malloc(sizeof(Object));
	Kwan_wallFe3->location = f3(845.0f, 10.0f, 599.6f);
	Kwan_wallFe3->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe3->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe3->start = f3(835.0f, 7.5f, 599.1f);
	Gwangjae_wallFe3->end = f3(855.0f, 12.5f, 600.1f);

	Object* Kwan_wallFe4 = (Object*)malloc(sizeof(Object));
	Kwan_wallFe4->location = f3(865.0f, 10.0f, 599.6f);
	Kwan_wallFe4->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe4->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe4->start = f3(855.0f, 7.5f, 599.1f);
	Gwangjae_wallFe4->end = f3(875.0f, 12.5f, 600.1f);

	//////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_wall1Le = (Object*)malloc(sizeof(Object));
	Kwan_wall1Le->location = f3(875.4f, 10.0f, 595.0f);
	Kwan_wall1Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall1Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1Le->start = f3(875.0f, 7.5f, 585.0f);
	Gwangjae_wall1Le->end = f3(875.0f, 12.5f, 605.0f);

	Object* Kwan_wall2Le = (Object*)malloc(sizeof(Object));
	Kwan_wall2Le->location = f3(875.4f, 10.0f, 575.0f);
	Kwan_wall2Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall2Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2Le->start = f3(875.0f, 7.5f, 565.0f);
	Gwangjae_wall2Le->end = f3(875.0f, 12.5f, 585.0f);

	Object* Kwan_wall3Le = (Object*)malloc(sizeof(Object));
	Kwan_wall3Le->location = f3(875.4f, 10.0f, 555.0f);
	Kwan_wall3Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall3Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3Le->start = f3(875.0f, 7.5f, 545.0f);
	Gwangjae_wall3Le->end = f3(875.0f, 12.5f, 565.0f);

	Object* Kwan_wall4Le = (Object*)malloc(sizeof(Object));
	Kwan_wall4Le->location = f3(875.4f, 10.0f, 535.0f);
	Kwan_wall4Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall4Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4Le->start = f3(875.0f, 7.5f, 525.0f);
	Gwangjae_wall4Le->end = f3(875.0f, 12.5f, 545.0f);

	Object* Kwan_wall5Le = (Object*)malloc(sizeof(Object));
	Kwan_wall5Le->location = f3(875.4f, 10.0f, 515.0f);
	Kwan_wall5Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall5Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5Le->start = f3(875.0f, 7.5f, 505.0f);
	Gwangjae_wall5Le->end = f3(875.0f, 12.5f, 525.0f);

	Object* Kwan_wall6Le = (Object*)malloc(sizeof(Object));
	Kwan_wall6Le->location = f3(875.4f, 10.0f, 495.0f);
	Kwan_wall6Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall6Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6Le->start = f3(875.0f, 7.5f, 485.0f);
	Gwangjae_wall6Le->end = f3(875.0f, 12.5f, 505.0f);

	Object* Kwan_wall7Le = (Object*)malloc(sizeof(Object));
	Kwan_wall7Le->location = f3(875.4f, 10.0f, 475.0f);
	Kwan_wall7Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall7Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7Le->start = f3(875.0f, 7.5f, 465.0f);
	Gwangjae_wall7Le->end = f3(875.0f, 12.5f, 485.0f);

	Object* Kwan_wall8Le = (Object*)malloc(sizeof(Object));
	Kwan_wall8Le->location = f3(875.4f, 10.0f, 455.0f);
	Kwan_wall8Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall8Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8Le->start = f3(875.0f, 7.5f, 445.0f);
	Gwangjae_wall8Le->end = f3(875.0f, 12.5f, 465.0f);

	Object* Kwan_wall9Le = (Object*)malloc(sizeof(Object));
	Kwan_wall9Le->location = f3(875.4f, 10.0f, 435.0f);
	Kwan_wall9Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall9Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9Le->start = f3(875.0f, 7.5f, 425.0f);
	Gwangjae_wall9Le->end = f3(875.0f, 12.5f, 445.0f);

	Object* Kwan_wall10Le = (Object*)malloc(sizeof(Object));
	Kwan_wall10Le->location = f3(875.4f, 10.0f, 415.0f);
	Kwan_wall10Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall10Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall10Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall10Le->start = f3(875.0f, 7.5f, 405.0f);
	Gwangjae_wall10Le->end = f3(875.0f, 12.5f, 425.0f);

	Object* Kwan_wall11Le = (Object*)malloc(sizeof(Object));
	Kwan_wall11Le->location = f3(875.4f, 10.0f, 395.0f);
	Kwan_wall11Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall11Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall11Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall11Le->start = f3(875.0f, 7.5f, 385.0f);
	Gwangjae_wall11Le->end = f3(875.0f, 12.5f, 405.0f);

	Object* Kwan_wall12Le = (Object*)malloc(sizeof(Object));
	Kwan_wall12Le->location = f3(875.4f, 10.0f, 375.0f);
	Kwan_wall12Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall12Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall12Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall12Le->start = f3(875.0f, 7.5f, 365.0f);
	Gwangjae_wall12Le->end = f3(875.0f, 12.5f, 385.0f);

	///////////////////////////////////////////////////////////////////

	Object* Kwan_wall00e = (Object*)malloc(sizeof(Object));
	Kwan_wall00e->location = f3(799.6f, 10.0f, 602.5f);
	Kwan_wall00e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall00e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall00e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall00e->start = f3(800.0f, 7.5f, 592.5f);
	Gwangjae_wall00e->end = f3(800.0f, 12.5f, 612.5f);

	Object* Kwan_wall0e = (Object*)malloc(sizeof(Object));
	Kwan_wall0e->location = f3(799.6f, 10.0f, 582.5f);
	Kwan_wall0e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall0e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall0e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall0e->start = f3(800.0f, 7.5f, 572.5f);
	Gwangjae_wall0e->end = f3(800.0f, 12.5f, 592.5f);

	///////////////////////////////
	Object* Kwan_wall1e = (Object*)malloc(sizeof(Object));
	Kwan_wall1e->location = f3(812.1f, 10.0f, 535.0f);
	Kwan_wall1e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall1e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1e->start = f3(812.0f, 7.5f, 525.0f);
	Gwangjae_wall1e->end = f3(813.0f, 12.5f, 545.0f);


	////////////
	Object* Kwan_wall2e = (Object*)malloc(sizeof(Object));
	Kwan_wall2e->location = f3(812.1f, 10.0f, 515.0f);
	Kwan_wall2e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall2e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2e->start = f3(812.0f, 7.5f, 505.0f);
	Gwangjae_wall2e->end = f3(813.0f, 12.5f, 525.0f);

	////////////////////
	Object* Kwan_wall3e = (Object*)malloc(sizeof(Object));
	Kwan_wall3e->location = f3(812.1f, 10.0f, 495.0f);
	Kwan_wall3e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall3e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3e->start = f3(812.0f, 7.5f, 485.0f);
	Gwangjae_wall3e->end = f3(813.0f, 12.5f, 505.0f);

	///////////////////////////////

	Object* Kwan_wall4e = (Object*)malloc(sizeof(Object));
	Kwan_wall4e->location = f3(812.1f, 10.0f, 475.0f);
	Kwan_wall4e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall4e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4e->start = f3(812.0f, 7.5f, 465.0f);
	Gwangjae_wall4e->end = f3(813.0f, 12.5f, 485.0f);

	/////////////////////////////////

	Object* Kwan_wall5e = (Object*)malloc(sizeof(Object));
	Kwan_wall5e->location = f3(812.1f, 10.0f, 455.0f);
	Kwan_wall5e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall5e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5e->start = f3(812.0f, 7.5f, 445.0f);
	Gwangjae_wall5e->end = f3(813.0f, 12.5f, 465.0f);

	Object* Kwan_wall6e = (Object*)malloc(sizeof(Object));
	Kwan_wall6e->location = f3(812.1f, 10.0f, 435.0f);
	Kwan_wall6e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall6e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6e->start = f3(812.0f, 7.5f, 425.0f);
	Gwangjae_wall6e->end = f3(813.0f, 12.5f, 445.0f);

	Object* Kwan_wall7e = (Object*)malloc(sizeof(Object));
	Kwan_wall7e->location = f3(812.1f, 10.0f, 415.0f);
	Kwan_wall7e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall7e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7e->start = f3(812.0f, 7.5f, 405.0f);
	Gwangjae_wall7e->end = f3(813.0f, 12.5f, 425.0f);

	Object* Kwan_wall8e = (Object*)malloc(sizeof(Object));
	Kwan_wall8e->location = f3(812.1f, 10.0f, 395.0f);
	Kwan_wall8e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall8e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8e->start = f3(812.0f, 7.5f, 385.0f);
	Gwangjae_wall8e->end = f3(813.0f, 12.5f, 405.0f);

	Object* Kwan_wall9e = (Object*)malloc(sizeof(Object));
	Kwan_wall9e->location = f3(812.1f, 10.0f, 375.0f);
	Kwan_wall9e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall9e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9e->start = f3(812.0f, 7.5f, 365.0f);
	Gwangjae_wall9e->end = f3(813.0f, 12.5f, 385.0f);

	Object* Kwan_wallss = (Object*)malloc(sizeof(Object));
	Kwan_wallss->location = f3(802.5f, 3.75f, 545.5f);
	Kwan_wallss->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallss->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wallss = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallss->start = f3(792.5f, 0.0f, 545.0f);
	Gwangjae_wallss->end = f3(812.5f, 7.5f, 546.0f);

	Object* Kwan_walles = (Object*)malloc(sizeof(Object));
	Kwan_walles->location = f3(802.5f, 10.0f, 545.5f);
	Kwan_walles->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walles->type = Gwanja_wall3;

	BoundingBox* Gwangjae_walles = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walles->start = f3(792.5f, 7.5f, 545.0f);
	Gwangjae_walles->end = f3(812.5f, 12.5f, 546.0f);

	list.push_back(*Kwan_wall00);
	blist.push_back(*Gwangjae_wall00);

	list.push_back(*Kwan_wall0);
	blist.push_back(*Gwangjae_wall0);

	list.push_back(*Kwan_wall1);
	blist.push_back(*Gwangjae_wall1);

	list.push_back(*Kwan_wall2);
	blist.push_back(*Gwangjae_wall2);

	list.push_back(*Kwan_wall3);
	blist.push_back(*Gwangjae_wall3);

	list.push_back(*Kwan_wall4);
	blist.push_back(*Gwangjae_wall4);

	list.push_back(*Kwan_wall5);
	blist.push_back(*Gwangjae_wall5);

	list.push_back(*Kwan_wall6);
	blist.push_back(*Gwangjae_wall6);

	list.push_back(*Kwan_wall7);
	blist.push_back(*Gwangjae_wall7);

	list.push_back(*Kwan_wall8);
	blist.push_back(*Gwangjae_wall8);

	list.push_back(*Kwan_wall9);
	blist.push_back(*Gwangjae_wall9);

	////////////////////////////////////////

	list.push_back(*Kwan_wall1L);
	blist.push_back(*Gwangjae_wall1L);

	list.push_back(*Kwan_wall2L);
	blist.push_back(*Gwangjae_wall2L);

	list.push_back(*Kwan_wall3L);
	blist.push_back(*Gwangjae_wall3L);

	list.push_back(*Kwan_wall4L);
	blist.push_back(*Gwangjae_wall4L);

	list.push_back(*Kwan_wall5L);
	blist.push_back(*Gwangjae_wall5L);

	list.push_back(*Kwan_wall6L);
	blist.push_back(*Gwangjae_wall6L);

	list.push_back(*Kwan_wall7L);
	blist.push_back(*Gwangjae_wall7L);

	list.push_back(*Kwan_wall8L);
	blist.push_back(*Gwangjae_wall8L);

	list.push_back(*Kwan_wall9L);
	blist.push_back(*Gwangjae_wall9L);

	list.push_back(*Kwan_wall10L);
	blist.push_back(*Gwangjae_wall10L);

	list.push_back(*Kwan_wall11L);
	blist.push_back(*Gwangjae_wall11L);

	list.push_back(*Kwan_wall12L);
	blist.push_back(*Gwangjae_wall12L);

	/////////////////////////////////////////////////////////

	list.push_back(*Kwan_wall1F);
	blist.push_back(*Gwangjae_wall1F);

	list.push_back(*Kwan_wall2F);
	blist.push_back(*Gwangjae_wall2F);

	list.push_back(*Kwan_wall3F);
	blist.push_back(*Gwangjae_wall3F);

	list.push_back(*Kwan_wall4F);
	blist.push_back(*Gwangjae_wall4F);

	/////////////////////////////////////////////////////////

	list.push_back(*Kwan_floor1);
	blist.push_back(*Gwangjae_floor1);

	list.push_back(*Kwan_front1);
	blist.push_back(*Gwangjae_front1);

	list.push_back(*Kwan_front2);
	blist.push_back(*Gwangjae_front2);

	list.push_back(*Kwan_front3);
	blist.push_back(*Gwangjae_front3);

	//////////////////////////////////////////////////////////

	list.push_back(*Kwan_front4);
	blist.push_back(*Gwangjae_front4);

	list.push_back(*Kwan_front5);
	blist.push_back(*Gwangjae_front5);

	list.push_back(*Kwan_front6);
	blist.push_back(*Gwangjae_front6);

	///////////////////////////////////////////////////////////

	list.push_back(*Kwan_front7);
	blist.push_back(*Gwangjae_front7);

	list.push_back(*Kwan_front8);
	blist.push_back(*Gwangjae_front8);

	list.push_back(*Kwan_front9);
	blist.push_back(*Gwangjae_front9);

	//////////////////////////////////////////////////////////////////////

	list.push_back(*Kwan_front10);
	blist.push_back(*Gwangjae_front10);

	list.push_back(*Kwan_front11);
	blist.push_back(*Gwangjae_front11);

	list.push_back(*Kwan_front12);
	blist.push_back(*Gwangjae_front12);

	///////////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Kwan_celing1);
	blist.push_back(*Gwangjae_celing1);

	list.push_back(*Kwan_floor2);
	blist.push_back(*Gwangjae_floor2);

	///////////////////////////////////////

	list.push_back(*Kwan_walle_1);
	blist.push_back(*Gwangjae_walle_1);

	list.push_back(*Kwan_walle_2);
	blist.push_back(*Gwangjae_walle_2);

	list.push_back(*Kwan_walle_3);
	blist.push_back(*Gwangjae_walle_3);

	list.push_back(*Kwan_walle_4);
	blist.push_back(*Gwangjae_walle_4);

	list.push_back(*Kwan_walle_5);
	blist.push_back(*Gwangjae_walle_5);

	list.push_back(*Kwan_walle_6);
	blist.push_back(*Gwangjae_walle_6);

	list.push_back(*Kwan_walle_7);
	blist.push_back(*Gwangjae_walle_7);

	list.push_back(*Kwan_walle_8);
	blist.push_back(*Gwangjae_walle_8);

	list.push_back(*Kwan_walle_9);
	blist.push_back(*Gwangjae_walle_9);

	list.push_back(*Kwan_walle_10);
	blist.push_back(*Gwangjae_walle_10);

	list.push_back(*Kwan_walle_11);
	blist.push_back(*Gwangjae_walle_11);

	list.push_back(*Kwan_walle_12);
	blist.push_back(*Gwangjae_walle_12);

	list.push_back(*Kwan_walle_13);
	blist.push_back(*Gwangjae_walle_13);

	list.push_back(*Kwan_walle_14);
	blist.push_back(*Gwangjae_walle_14);

	list.push_back(*Kwan_walle_15);
	blist.push_back(*Gwangjae_walle_15);

	list.push_back(*Kwan_walle_16);
	blist.push_back(*Gwangjae_walle_16);

	///////////////////////////////////////////////


	list.push_back(*Kwan_wallFe);
	blist.push_back(*Gwangjae_wallFe);

	list.push_back(*Kwan_wallFe2);
	blist.push_back(*Gwangjae_wallFe2);

	list.push_back(*Kwan_wallFe3);
	blist.push_back(*Gwangjae_wallFe3);

	list.push_back(*Kwan_wallFe4);
	blist.push_back(*Gwangjae_wallFe4);

	/////////////////////////////////////////////////////

	list.push_back(*Kwan_wall1Le);
	blist.push_back(*Gwangjae_wall1Le);

	list.push_back(*Kwan_wall2Le);
	blist.push_back(*Gwangjae_wall2Le);

	list.push_back(*Kwan_wall3Le);
	blist.push_back(*Gwangjae_wall3Le);

	list.push_back(*Kwan_wall4Le);
	blist.push_back(*Gwangjae_wall4Le);

	list.push_back(*Kwan_wall5Le);
	blist.push_back(*Gwangjae_wall5Le);

	list.push_back(*Kwan_wall6Le);
	blist.push_back(*Gwangjae_wall6Le);

	list.push_back(*Kwan_wall7Le);
	blist.push_back(*Gwangjae_wall7Le);

	list.push_back(*Kwan_wall8Le);
	blist.push_back(*Gwangjae_wall8Le);

	list.push_back(*Kwan_wall9Le);
	blist.push_back(*Gwangjae_wall9Le);

	list.push_back(*Kwan_wall10Le);
	blist.push_back(*Gwangjae_wall10Le);

	list.push_back(*Kwan_wall11Le);
	blist.push_back(*Gwangjae_wall11Le);

	list.push_back(*Kwan_wall12Le);
	blist.push_back(*Gwangjae_wall12Le);


	/////////////////////////////////////////////////////////////////////////

	list.push_back(*Kwan_wall00e);
	blist.push_back(*Gwangjae_wall00e);

	list.push_back(*Kwan_wall0e);
	blist.push_back(*Gwangjae_wall0e);

	list.push_back(*Kwan_wall1e);
	blist.push_back(*Gwangjae_wall1e);

	list.push_back(*Kwan_wall2e);
	blist.push_back(*Gwangjae_wall2e);

	list.push_back(*Kwan_wall3e);
	blist.push_back(*Gwangjae_wall3e);

	list.push_back(*Kwan_wall4e);
	blist.push_back(*Gwangjae_wall4e);

	list.push_back(*Kwan_wall5e);
	blist.push_back(*Gwangjae_wall5e);

	list.push_back(*Kwan_wall6e);
	blist.push_back(*Gwangjae_wall6e);

	list.push_back(*Kwan_wall7e);
	blist.push_back(*Gwangjae_wall7e);

	list.push_back(*Kwan_wall8e);
	blist.push_back(*Gwangjae_wall8e);

	list.push_back(*Kwan_wall9e);
	blist.push_back(*Gwangjae_wall9e);

	////////////////////////////////////////////////////

	list.push_back(*Kwan_walles);
	blist.push_back(*Gwangjae_walles);

	list.push_back(*Kwan_wallss);
	blist.push_back(*Gwangjae_wallss);

}

void createObstacles2_2(vector<Object>& list, vector<BoundingBox>& blist)
{
	Object* Receps_celing1 = (Object*)malloc(sizeof(Object));
	Receps_celing1->location = f3(800.0f, 12.3f, 0.0f);
	Receps_celing1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_celing1->type = Recep_celing;

	BoundingBox* receps_celing1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	receps_celing1->start = f3(800.0f, 12.3f, 0.0f);
	receps_celing1->end = f3(875.0f, 12.5f, 365.0f);

	Object* Receps_floor1 = (Object*)malloc(sizeof(Object));
	Receps_floor1->location = f3(800.0f, 0.001f, 0.0f);
	Receps_floor1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_floor1->type = Recep_floor;

	BoundingBox* receps_floor1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	receps_floor1->start = f3(800.0f, 0.00f, 0.0f);
	receps_floor1->end = f3(875.0f, 0.00f, 365.0f);

	/////////////////////////////////////////////////////////////////

	Object* Receps_wall1 = (Object*)malloc(sizeof(Object));
	Receps_wall1->location = f3(875.4f, 3.75f, 355.0f);
	Receps_wall1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1->type = Recep_wall1;

	BoundingBox* Receps_walled1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled1->start = f3(875.0f, 0.0f, 345.0f);
	Receps_walled1->end = f3(875.0f, 7.5f, 365.0f);

	Object* Receps_wall2 = (Object*)malloc(sizeof(Object));
	Receps_wall2->location = f3(875.4f, 3.75f, 335.0f);
	Receps_wall2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2->type = Recep_wall1;

	BoundingBox* Receps_walled2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled2->start = f3(875.0f, 0.0f, 325.0f);
	Receps_walled2->end = f3(875.0f, 7.5f, 345.0f);

	Object* Receps_wall3 = (Object*)malloc(sizeof(Object));
	Receps_wall3->location = f3(875.4f, 3.75f, 315.0f);
	Receps_wall3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3->type = Recep_wall1;

	BoundingBox* Receps_walled3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled3->start = f3(875.0f, 0.0f, 305.0f);
	Receps_walled3->end = f3(875.0f, 7.5f, 325.0f);

	Object* Receps_wall4 = (Object*)malloc(sizeof(Object));
	Receps_wall4->location = f3(875.4f, 3.75f, 295.0f);
	Receps_wall4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4->type = Recep_wall1;

	BoundingBox* Receps_walled4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled4->start = f3(875.0f, 0.0f, 285.0f);
	Receps_walled4->end = f3(875.0f, 7.5f, 305.0f);

	Object* Receps_wall5 = (Object*)malloc(sizeof(Object));
	Receps_wall5->location = f3(875.4f, 3.75f, 275.0f);
	Receps_wall5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5->type = Recep_wall1;

	BoundingBox* Receps_walled5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled5->start = f3(875.0f, 0.0f, 265.0f);
	Receps_walled5->end = f3(875.0f, 7.5f, 285.0f);

	Object* Receps_wall6 = (Object*)malloc(sizeof(Object));
	Receps_wall6->location = f3(875.4f, 3.75f, 255.0f);
	Receps_wall6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6->type = Recep_wall1;

	BoundingBox* Receps_walled6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled6->start = f3(875.0f, 0.0f, 245.0f);
	Receps_walled6->end = f3(875.0f, 7.5f, 265.0f);

	Object* Receps_wall7 = (Object*)malloc(sizeof(Object));
	Receps_wall7->location = f3(875.4f, 3.75f, 235.0f);
	Receps_wall7->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7->type = Recep_wall1;

	BoundingBox* Receps_walled7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled7->start = f3(875.0f, 0.0f, 225.0f);
	Receps_walled7->end = f3(875.0f, 7.5f, 245.0f);

	/////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_wall1R = (Object*)malloc(sizeof(Object));
	Receps_wall1R->location = f3(812.1f, 3.75f, 355.0f);
	Receps_wall1R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1R->type = Recep_wall1;

	BoundingBox* Receps_walled1R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled1R->start = f3(812.0f, 0.0f, 345.0f);
	Receps_walled1R->end = f3(813.0f, 7.5f, 365.0f);

	Object* Receps_wall2R = (Object*)malloc(sizeof(Object));
	Receps_wall2R->location = f3(812.1f, 3.75f, 335.0f);
	Receps_wall2R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2R->type = Recep_wall1;

	BoundingBox* Receps_walled2R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled2R->start = f3(812.0f, 0.0f, 325.0f);
	Receps_walled2R->end = f3(813.0f, 7.5f, 345.0f);

	Object* Receps_wall3R = (Object*)malloc(sizeof(Object));
	Receps_wall3R->location = f3(812.1f, 3.75f, 315.0f);
	Receps_wall3R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3R->type = Recep_wall1;

	BoundingBox* Receps_walled3R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled3R->start = f3(812.0f, 0.0f, 305.0f);
	Receps_walled3R->end = f3(813.0f, 7.5f, 325.0f);

	Object* Receps_wall4R = (Object*)malloc(sizeof(Object));
	Receps_wall4R->location = f3(812.1f, 3.75f, 295.0f);
	Receps_wall4R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4R->type = Recep_wall1;

	BoundingBox* Receps_walled4R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled4R->start = f3(812.0f, 0.0f, 285.0f);
	Receps_walled4R->end = f3(813.0f, 7.5f, 305.0f);

	Object* Receps_wall5R = (Object*)malloc(sizeof(Object));
	Receps_wall5R->location = f3(812.1f, 3.75f, 275.0f);
	Receps_wall5R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5R->type = Recep_wall1;

	BoundingBox* Receps_walled5R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled5R->start = f3(812.0f, 0.0f, 265.0f);
	Receps_walled5R->end = f3(813.0f, 7.5f, 285.0f);


	Object* Receps_wall6R = (Object*)malloc(sizeof(Object));
	Receps_wall6R->location = f3(812.1f, 3.75f, 255.0f);
	Receps_wall6R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6R->type = Recep_wall1;

	BoundingBox* Receps_walled6R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled6R->start = f3(812.0f, 0.0f, 245.0f);
	Receps_walled6R->end = f3(813.0f, 7.5f, 265.0f);

	Object* Receps_wall7R = (Object*)malloc(sizeof(Object));
	Receps_wall7R->location = f3(812.1f, 3.75f, 235.0f);
	Receps_wall7R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7R->type = Recep_wall1;

	BoundingBox* Receps_walled7R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled7R->start = f3(812.0f, 0.0f, 225.0f);
	Receps_walled7R->end = f3(813.0f, 7.5f, 245.0f);

	////////////////////////////////////////////////////////////////////////

	Object* Receps_wall1e = (Object*)malloc(sizeof(Object));
	Receps_wall1e->location = f3(812.1f, 10.0f, 355.0f);
	Receps_wall1e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1e->type = Recep_wall2;

	BoundingBox* Receps_wall1ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall1ede->start = f3(812.0f, 7.5f, 345.0f);
	Receps_wall1ede->end = f3(813.0f, 12.5f, 365.0f);

	Object* Receps_wall2e = (Object*)malloc(sizeof(Object));
	Receps_wall2e->location = f3(812.1f, 10.0f, 335.0f);
	Receps_wall2e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2e->type = Recep_wall2;

	BoundingBox* Receps_wall2ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall2ede->start = f3(812.0f, 7.5f, 325.0f);
	Receps_wall2ede->end = f3(813.0f, 12.5f, 345.0f);

	Object* Receps_wall3e = (Object*)malloc(sizeof(Object));
	Receps_wall3e->location = f3(812.1f, 10.0f, 315.0f);
	Receps_wall3e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3e->type = Recep_wall2;

	BoundingBox* Receps_wall3ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall3ede->start = f3(812.0f, 7.5f, 305.0f);
	Receps_wall3ede->end = f3(813.0f, 12.5f, 325.0f);

	Object* Receps_wall4e = (Object*)malloc(sizeof(Object));
	Receps_wall4e->location = f3(812.1f, 10.0f, 295.0f);
	Receps_wall4e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4e->type = Recep_wall2;

	BoundingBox* Receps_wall4ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall4ede->start = f3(812.0f, 7.5f, 285.0f);
	Receps_wall4ede->end = f3(813.0f, 12.5f, 305.0f);

	Object* Receps_wall5e = (Object*)malloc(sizeof(Object));
	Receps_wall5e->location = f3(812.1f, 10.0f, 275.0f);
	Receps_wall5e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5e->type = Recep_wall2;

	BoundingBox* Receps_wall5ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall5ede->start = f3(812.0f, 7.5f, 265.0f);
	Receps_wall5ede->end = f3(813.0f, 12.5f, 285.0f);

	Object* Receps_wall6e = (Object*)malloc(sizeof(Object));
	Receps_wall6e->location = f3(812.1f, 10.0f, 255.0f);
	Receps_wall6e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6e->type = Recep_wall2;

	BoundingBox* Receps_wall6ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall6ede->start = f3(812.0f, 7.5f, 245.0f);
	Receps_wall6ede->end = f3(813.0f, 12.5f, 265.0f);

	Object* Receps_wall7e = (Object*)malloc(sizeof(Object));
	Receps_wall7e->location = f3(812.1f, 10.0f, 235.0f);
	Receps_wall7e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7e->type = Recep_wall2;

	BoundingBox* Receps_wall7ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall7ede->start = f3(812.0f, 7.5f, 225.0f);
	Receps_wall7ede->end = f3(813.0f, 12.5f, 245.0f);

	////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_wall1eL = (Object*)malloc(sizeof(Object));
	Receps_wall1eL->location = f3(875.4f, 10.0f, 355.0f);
	Receps_wall1eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1eL->type = Recep_wall2;

	BoundingBox* Receps_wall1edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall1edeL->start = f3(875.0f, 7.5f, 345.0f);
	Receps_wall1edeL->end = f3(875.4f, 12.5f, 365.0f);

	Object* Receps_wall2eL = (Object*)malloc(sizeof(Object));
	Receps_wall2eL->location = f3(875.4f, 10.0f, 335.0f);
	Receps_wall2eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2eL->type = Recep_wall2;

	BoundingBox* Receps_wall2edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall2edeL->start = f3(875.0f, 7.5f, 325.0f);
	Receps_wall2edeL->end = f3(875.4f, 12.5f, 345.0f);

	Object* Receps_wall3eL = (Object*)malloc(sizeof(Object));
	Receps_wall3eL->location = f3(875.4f, 10.0f, 315.0f);
	Receps_wall3eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3eL->type = Recep_wall2;

	BoundingBox* Receps_wall3edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall3edeL->start = f3(875.0f, 7.5f, 305.0f);
	Receps_wall3edeL->end = f3(875.4f, 12.5f, 325.0f);

	Object* Receps_wall4eL = (Object*)malloc(sizeof(Object));
	Receps_wall4eL->location = f3(875.4f, 10.0f, 295.0f);
	Receps_wall4eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4eL->type = Recep_wall2;

	BoundingBox* Receps_wall4edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall4edeL->start = f3(875.0f, 7.5f, 285.0f);
	Receps_wall4edeL->end = f3(875.4f, 12.5f, 305.0f);

	Object* Receps_wall5eL = (Object*)malloc(sizeof(Object));
	Receps_wall5eL->location = f3(875.4f, 10.0f, 275.0f);
	Receps_wall5eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5eL->type = Recep_wall2;

	BoundingBox* Receps_wall5edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall5edeL->start = f3(875.0f, 7.5f, 265.0f);
	Receps_wall5edeL->end = f3(875.4f, 12.5f, 285.0f);

	Object* Receps_wall6eL = (Object*)malloc(sizeof(Object));
	Receps_wall6eL->location = f3(875.4f, 10.0f, 255.0f);
	Receps_wall6eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6eL->type = Recep_wall2;

	BoundingBox* Receps_wall6edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall6edeL->start = f3(875.0f, 7.5f, 245.0f);
	Receps_wall6edeL->end = f3(875.4f, 12.5f, 265.0f);

	Object* Receps_wall7eL = (Object*)malloc(sizeof(Object));
	Receps_wall7eL->location = f3(875.4f, 10.0f, 235.0f);
	Receps_wall7eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7eL->type = Recep_wall2;

	BoundingBox* Receps_wall7edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall7edeL->start = f3(875.0f, 7.5f, 225.0f);
	Receps_wall7edeL->end = f3(875.4f, 12.5f, 245.0f);

	//////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_front1 = (Object*)malloc(sizeof(Object));
	Receps_front1->location = f3(822.916f, 7.5f, 224.0f); // 20.833
	Receps_front1->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_front1->type = Recep_front;

	BoundingBox* Receps_fronted1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronted1->start = f3(812.5f, 2.5f, 223.0f);
	Receps_fronted1->end = f3(833.333f, 12.5f, 225.0f);

	Object* Receps_front2 = (Object*)malloc(sizeof(Object));
	Receps_front2->location = f3(843.799f, 7.5f, 224.0f); // 20.833
	Receps_front2->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_front2->type = Recep_front;

	BoundingBox* Receps_fronted2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronted2->start = f3(833.333f, 2.5f, 223.0f);
	Receps_fronted2->end = f3(854.166f, 12.5f, 225.0f);

	Object* Receps_front3 = (Object*)malloc(sizeof(Object));
	Receps_front3->location = f3(864.633f, 7.5f, 224.0f); // 20.833
	Receps_front3->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_front3->type = Recep_front;

	BoundingBox* Receps_fronted3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronted3->start = f3(854.166f, 2.5f, 223.0f);
	Receps_fronted3->end = f3(875.0f, 12.5f, 225.0f);

	////////////////////////////////////////////////////////////////////////////////

	Object* Receps_fronte1 = (Object*)malloc(sizeof(Object));
	Receps_fronte1->location = f3(820.0f, 1.25f, 224.0f);
	Receps_fronte1->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte1->type = Recep_front2;

	BoundingBox* Receps_fronte1e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte1e->start = f3(812.5f, 0.0f, 223.0f);
	Receps_fronte1e->end = f3(827.5f, 2.5f, 225.0f);

	Object* Receps_fronte2 = (Object*)malloc(sizeof(Object));
	Receps_fronte2->location = f3(835.0f, 1.25f, 224.0f);
	Receps_fronte2->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte2->type = Recep_front2;

	BoundingBox* Receps_fronte2e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte2e->start = f3(827.5f, 0.0f, 223.0f);
	Receps_fronte2e->end = f3(842.5f, 2.5f, 225.0f);

	Object* Receps_fronte3 = (Object*)malloc(sizeof(Object));
	Receps_fronte3->location = f3(852.5f, 1.25f, 224.0f);
	Receps_fronte3->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte3->type = Recep_front2;

	BoundingBox* Receps_fronte3e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte3e->start = f3(845.0f, 0.0f, 223.0f);
	Receps_fronte3e->end = f3(860.0f, 2.5f, 225.0f);

	Object* Receps_fronte4 = (Object*)malloc(sizeof(Object));
	Receps_fronte4->location = f3(867.5f, 1.25f, 224.0f);
	Receps_fronte4->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte4->type = Recep_front2;

	BoundingBox* Receps_fronte4e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte4e->start = f3(860.0f, 0.0f, 223.0f);
	Receps_fronte4e->end = f3(875.0f, 2.5f, 225.0f);

	///////////////////////////////////////////////////////////////////////////


	Object* Receps_ipgu = (Object*)malloc(sizeof(Object));
	Receps_ipgu->location = f3(874.0f, 7.5f, 87.5f);
	Receps_ipgu->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu->type = Recep_wall3;

	BoundingBox* Receps_iping = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping->start = f3(873.0f, 2.5f, 75.0f);
	Receps_iping->end = f3(875.0f, 12.5f, 100.0f);

	Object* Receps_ipgu2 = (Object*)malloc(sizeof(Object));
	Receps_ipgu2->location = f3(874.0f, 7.5f, 112.5f);
	Receps_ipgu2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu2->type = Recep_wall3;

	BoundingBox* Receps_iping2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping2->start = f3(873.0f, 2.5f, 100.0f);
	Receps_iping2->end = f3(875.0f, 12.5f, 125.0f);

	Object* Receps_ipgu3 = (Object*)malloc(sizeof(Object));
	Receps_ipgu3->location = f3(874.0f, 7.5f, 137.5f);
	Receps_ipgu3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu3->type = Recep_wall3;

	BoundingBox* Receps_iping3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping3->start = f3(873.0f, 2.5f, 125.0f);
	Receps_iping3->end = f3(875.0f, 12.5f, 150.0f);

	Object* Receps_ipgu4 = (Object*)malloc(sizeof(Object));
	Receps_ipgu4->location = f3(874.0f, 7.5f, 162.5f);
	Receps_ipgu4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu4->type = Recep_wall3;

	BoundingBox* Receps_iping4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping4->start = f3(873.0f, 2.5f, 150.0f);
	Receps_iping4->end = f3(875.0f, 12.5f, 175.0f);

	Object* Receps_ipgu5 = (Object*)malloc(sizeof(Object));
	Receps_ipgu5->location = f3(874.0f, 7.5f, 187.5f);
	Receps_ipgu5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu5->type = Recep_wall3;

	BoundingBox* Receps_iping5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping5->start = f3(873.0f, 2.5f, 175.0f);
	Receps_iping5->end = f3(875.0f, 12.5f, 200.0f);

	Object* Receps_ipgu6 = (Object*)malloc(sizeof(Object));
	Receps_ipgu6->location = f3(874.0f, 7.5f, 212.5f);
	Receps_ipgu6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu6->type = Recep_wall3;

	BoundingBox* Receps_iping6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping6->start = f3(873.0f, 2.5f, 200.0f);
	Receps_iping6->end = f3(875.0f, 12.5f, 225.0f);

	////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu4_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu4_l->location = f3(874.0f, 1.25f, 162.5f);
	Receps_ipgu4_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu4_l->type = Recep_wall5;

	BoundingBox* Receps_iping4_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping4_l->start = f3(873.0f, 0.0f, 150.0f);
	Receps_iping4_l->end = f3(875.0f, 2.5f, 175.0f);

	Object* Receps_ipgu5_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu5_l->location = f3(874.0f, 1.25f, 187.5f);
	Receps_ipgu5_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu5_l->type = Recep_wall5;

	BoundingBox* Receps_iping5_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping5_l->start = f3(873.0f, 0.0f, 175.0f);
	Receps_iping5_l->end = f3(875.0f, 2.5f, 200.0f);

	Object* Receps_ipgu6_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu6_l->location = f3(874.0f, 1.25f, 212.5f);
	Receps_ipgu6_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu6_l->type = Recep_wall5;

	BoundingBox* Receps_iping6_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping6_l->start = f3(873.0f, 0.0f, 200.0f);
	Receps_iping6_l->end = f3(875.0f, 2.5f, 225.0f);

	////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu7 = (Object*)malloc(sizeof(Object));
	Receps_ipgu7->location = f3(811.6f, 7.5f, 87.5f);
	Receps_ipgu7->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu7->type = Recep_wall3;

	BoundingBox* Receps_iping7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping7->start = f3(810.6f, 2.5f, 75.0f);
	Receps_iping7->end = f3(812.6f, 12.5f, 100.0f);

	Object* Receps_ipgu8 = (Object*)malloc(sizeof(Object));
	Receps_ipgu8->location = f3(811.6f, 7.5f, 112.5f);
	Receps_ipgu8->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu8->type = Recep_wall3;

	BoundingBox* Receps_iping8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping8->start = f3(810.6f, 2.5f, 100.0f);
	Receps_iping8->end = f3(812.6f, 12.5f, 125.0f);

	Object* Receps_ipgu9 = (Object*)malloc(sizeof(Object));
	Receps_ipgu9->location = f3(811.6f, 7.5f, 137.5f);
	Receps_ipgu9->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu9->type = Recep_wall3;

	BoundingBox* Receps_iping9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping9->start = f3(810.6f, 2.5f, 125.0f);
	Receps_iping9->end = f3(812.6f, 12.5f, 150.0f);

	Object* Receps_ipgu10 = (Object*)malloc(sizeof(Object));
	Receps_ipgu10->location = f3(811.6f, 7.5f, 162.5f);
	Receps_ipgu10->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu10->type = Recep_wall3;

	BoundingBox* Receps_iping10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping10->start = f3(810.6f, 2.5f, 150.0f);
	Receps_iping10->end = f3(812.6f, 12.5f, 175.0f);

	Object* Receps_ipgu11 = (Object*)malloc(sizeof(Object));
	Receps_ipgu11->location = f3(811.6f, 7.5f, 187.5f);
	Receps_ipgu11->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu11->type = Recep_wall3;

	BoundingBox* Receps_iping11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping11->start = f3(810.6f, 2.5f, 175.0f);
	Receps_iping11->end = f3(812.6f, 12.5f, 200.0f);

	Object* Receps_ipgu12 = (Object*)malloc(sizeof(Object));
	Receps_ipgu12->location = f3(811.6f, 7.5f, 212.5f);
	Receps_ipgu12->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu12->type = Recep_wall3;

	BoundingBox* Receps_iping12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping12->start = f3(810.6f, 2.5f, 200.0f);
	Receps_iping12->end = f3(812.6f, 12.5f, 225.0f);

	//////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu7_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu7_l->location = f3(811.6f, 1.25f, 87.5f);
	Receps_ipgu7_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu7_l->type = Recep_wall5;

	BoundingBox* Receps_iping7_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping7_l->start = f3(810.6f, 0.0f, 75.0f);
	Receps_iping7_l->end = f3(812.6f, 2.5f, 100.0f);

	Object* Receps_ipgu8_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu8_l->location = f3(811.6f, 1.25f, 112.5f);
	Receps_ipgu8_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu8_l->type = Recep_wall5;

	BoundingBox* Receps_iping8_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping8_l->start = f3(810.6f, 0.0f, 100.0f);
	Receps_iping8_l->end = f3(812.6f, 2.5f, 125.0f);

	Object* Receps_ipgu9_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu9_l->location = f3(811.6f, 1.25f, 137.5f);
	Receps_ipgu9_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu9_l->type = Recep_wall5;

	BoundingBox* Receps_iping9_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping9_l->start = f3(810.6f, 0.0f, 125.0f);
	Receps_iping9_l->end = f3(812.6f, 2.5f, 150.0f);

	Object* Receps_ipgu10_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu10_l->location = f3(811.6f, 1.25f, 162.5f);
	Receps_ipgu10_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu10_l->type = Recep_wall5;

	BoundingBox* Receps_iping10_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping10_l->start = f3(810.6f, 0.0f, 150.0f);
	Receps_iping10_l->end = f3(812.6f, 2.5f, 175.0f);

	Object* Receps_ipgu11_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu11_l->location = f3(811.6f, 1.25f, 187.5f);
	Receps_ipgu11_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu11_l->type = Recep_wall5;

	BoundingBox* Receps_iping11_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping11_l->start = f3(810.6f, 0.0f, 175.0f);
	Receps_iping11_l->end = f3(812.6f, 2.5f, 200.0f);

	Object* Receps_ipgu12_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu12_l->location = f3(811.6f, 1.25f, 212.5f);
	Receps_ipgu12_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu12_l->type = Recep_wall5;

	BoundingBox* Receps_iping12_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping12_l->start = f3(810.6f, 0.0f, 200.0f);
	Receps_iping12_l->end = f3(812.6f, 2.5f, 225.0f);

	//////////////////////////////////////////////////////////////////////////////////////
	// front

	Object* Receps_ipgu13 = (Object*)malloc(sizeof(Object));
	Receps_ipgu13->location = f3(862.5f, 7.5f, 74.1f);
	Receps_ipgu13->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu13->type = Recep_wall3;

	BoundingBox* Receps_iping13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping13->start = f3(850.0f, 2.5f, 73.1f);
	Receps_iping13->end = f3(875.0f, 12.5f, 75.1f);

	Object* Receps_ipgu14 = (Object*)malloc(sizeof(Object));
	Receps_ipgu14->location = f3(837.5f, 7.5f, 74.1f);
	Receps_ipgu14->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu14->type = Recep_wall3;

	BoundingBox* Receps_iping14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping14->start = f3(825.0f, 2.5f, 73.1f);
	Receps_iping14->end = f3(850.0f, 12.5f, 75.1f);

	Object* Receps_ipgu15 = (Object*)malloc(sizeof(Object));
	Receps_ipgu15->location = f3(812.5f, 7.5f, 74.1f);
	Receps_ipgu15->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu15->type = Recep_wall3;

	BoundingBox* Receps_iping15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping15->start = f3(800.0f, 2.5f, 73.1f);
	Receps_iping15->end = f3(825.0f, 12.5f, 75.1f);

	///////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu13_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu13_l->location = f3(862.5f, 1.25f, 74.1f);
	Receps_ipgu13_l->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu13_l->type = Recep_wall5;

	BoundingBox* Receps_iping13_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping13_l->start = f3(850.0f, 0.0f, 73.1f);
	Receps_iping13_l->end = f3(875.0f, 2.5f, 75.1f);

	Object* Receps_ipgu14_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu14_l->location = f3(837.5f, 1.25f, 74.1f);
	Receps_ipgu14_l->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu14_l->type = Recep_wall5;

	BoundingBox* Receps_iping14_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping14_l->start = f3(825.0f, 0.0f, 73.1f);
	Receps_iping14_l->end = f3(850.0f, 2.5f, 75.1f);

	Object* Receps_ipgu15_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu15_l->location = f3(812.5f, 1.25f, 74.1f);
	Receps_ipgu15_l->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu15_l->type = Recep_wall5;

	BoundingBox* Receps_iping15_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping15_l->start = f3(800.0f, 0.0f, 73.1f);
	Receps_iping15_l->end = f3(825.0f, 2.5f, 75.1f);

	///////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu_1 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_1->location = f3(874.0f, 1.25f, 84.0625f);
	Receps_ipgu_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_1->type = Recep_wall4;

	BoundingBox* Receps_iping_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_1->start = f3(873.0f, 0.0f, 75.0f);
	Receps_iping_1->end = f3(875.0f, 2.5f, 93.125f);

	Object* Receps_ipgu_2 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_2->location = f3(874.0f, 1.25f, 102.1875f);
	Receps_ipgu_2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_2->type = Recep_wall4;

	BoundingBox* Receps_iping_2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_2->start = f3(873.0f, 0.0f, 93.125f);
	Receps_iping_2->end = f3(875.0f, 2.5f, 111.25f);

	Object* Receps_ipgu_3 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_3->location = f3(874.0f, 1.25f, 122.8125f);
	Receps_ipgu_3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_3->type = Recep_wall4;

	BoundingBox* Receps_iping_3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_3->start = f3(873.0f, 0.0f, 113.75f);
	Receps_iping_3->end = f3(875.0f, 2.5f, 131.875f);

	Object* Receps_ipgu_4 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_4->location = f3(874.0f, 1.25f, 140.9375f);
	Receps_ipgu_4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_4->type = Recep_wall4;

	BoundingBox* Receps_iping_4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_4->start = f3(873.0f, 0.0f, 131.875f);
	Receps_iping_4->end = f3(875.0f, 2.5f, 150.0f);

	////////////////////////////////////////////////////////////////////////

	Object* Receps_gar1 = (Object*)malloc(sizeof(Object));
	Receps_gar1->location = f3(843.75f, 1.5f, 534.5f);
	Receps_gar1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar1->type = Recep_garomak;

	BoundingBox* Receps_garo1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo1->start = f3(833.75f, 0.0f, 533.0f);
	Receps_garo1->end = f3(853.75f, 3.0f, 536.0f);

	Object* Receps_gar2 = (Object*)malloc(sizeof(Object));
	Receps_gar2->location = f3(843.75f, 1.5f, 488.5f);
	Receps_gar2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar2->type = Recep_garomak;

	BoundingBox* Receps_garo2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo2->start = f3(833.75f, 0.0f, 487.0f);
	Receps_garo2->end = f3(853.75f, 3.0f, 490.0f); // 44 더하기

	Object* Receps_gar3 = (Object*)malloc(sizeof(Object));
	Receps_gar3->location = f3(843.75f, 1.5f, 473.5f);
	Receps_gar3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar3->type = Recep_garomak;

	BoundingBox* Receps_garo3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo3->start = f3(833.75f, 0.0f, 472.0f);
	Receps_garo3->end = f3(853.75f, 3.0f, 475.0f);

	Object* Receps_gar4 = (Object*)malloc(sizeof(Object));
	Receps_gar4->location = f3(843.75f, 1.5f, 430.5f);
	Receps_gar4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar4->type = Recep_garomak;

	BoundingBox* Receps_garo4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo4->start = f3(833.75f, 0.0f, 429.0f);
	Receps_garo4->end = f3(853.75f, 3.0f, 432.0f);

	Object* Receps_gar5 = (Object*)malloc(sizeof(Object));
	Receps_gar5->location = f3(843.75f, 1.5f, 415.5f);
	Receps_gar5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar5->type = Recep_garomak;

	BoundingBox* Receps_garo5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo5->start = f3(833.75f, 0.0f, 414.0f);
	Receps_garo5->end = f3(853.75f, 3.0f, 417.0f);

	Object* Receps_gar6 = (Object*)malloc(sizeof(Object));
	Receps_gar6->location = f3(843.75f, 1.5f, 371.5f);
	Receps_gar6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar6->type = Recep_garomak;

	BoundingBox* Receps_garo6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo6->start = f3(833.75f, 0.0f, 370.0f);
	Receps_garo6->end = f3(853.75f, 3.0f, 373.0f);

	/////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong1 = (Object*)malloc(sizeof(Object));
	Receps_gidong1->location = f3(823.75f, 1.25f, 350.0f);
	Receps_gidong1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong1->type = Recep_kidung;

	BoundingBox* Receps_kkidung1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung1->start = f3(818.75f, 0.0f, 345.0f);
	Receps_kkidung1->end = f3(828.75f, 2.5f, 355.0f);

	Object* Receps_gidong2 = (Object*)malloc(sizeof(Object));
	Receps_gidong2->location = f3(833.75f, 1.25f, 350.0f);
	Receps_gidong2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong2->type = Recep_kidung;

	BoundingBox* Receps_kkidung2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung2->start = f3(828.75f, 0.0f, 345.0f);
	Receps_kkidung2->end = f3(838.75f, 2.5f, 355.0f);

	Object* Receps_gidong3 = (Object*)malloc(sizeof(Object));
	Receps_gidong3->location = f3(843.75f, 1.25f, 350.0f);
	Receps_gidong3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong3->type = Recep_kidung;

	BoundingBox* Receps_kkidung3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung3->start = f3(838.75f, 0.0f, 345.0f);
	Receps_kkidung3->end = f3(848.75f, 2.5f, 355.0f);

	Object* Receps_gidong4 = (Object*)malloc(sizeof(Object));
	Receps_gidong4->location = f3(853.75f, 1.25f, 350.0f);
	Receps_gidong4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong4->type = Recep_kidung;

	BoundingBox* Receps_kkidung4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung4->start = f3(848.75f, 0.0f, 345.0f);
	Receps_kkidung4->end = f3(858.75f, 2.5f, 355.0f);

	Object* Receps_gidong5 = (Object*)malloc(sizeof(Object));
	Receps_gidong5->location = f3(863.75f, 1.25f, 350.0f);
	Receps_gidong5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong5->type = Recep_kidung;

	BoundingBox* Receps_kkidung5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung5->start = f3(858.75f, 0.0f, 345.0f);
	Receps_kkidung5->end = f3(868.75f, 2.5f, 355.0f);

	///////////////////////////////////////////////////////////////////////

	Object* Receps_gidong6 = (Object*)malloc(sizeof(Object));
	Receps_gidong6->location = f3(823.75f, 1.25f, 340.0f);
	Receps_gidong6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong6->type = Recep_kidung;

	BoundingBox* Receps_kkidung6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung6->start = f3(818.75f, 0.0f, 335.0f);
	Receps_kkidung6->end = f3(828.75f, 2.5f, 345.0f);

	Object* Receps_gidong7 = (Object*)malloc(sizeof(Object));
	Receps_gidong7->location = f3(833.75f, 1.25f, 340.0f);
	Receps_gidong7->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong7->type = Recep_kidung;

	BoundingBox* Receps_kkidung7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung7->start = f3(828.75f, 0.0f, 335.0f);
	Receps_kkidung7->end = f3(838.75f, 2.5f, 345.0f);

	Object* Receps_gidong8 = (Object*)malloc(sizeof(Object));
	Receps_gidong8->location = f3(843.75f, 1.25f, 340.0f);
	Receps_gidong8->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong8->type = Recep_kidung;

	BoundingBox* Receps_kkidung8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung8->start = f3(838.75f, 0.0f, 335.0f);
	Receps_kkidung8->end = f3(848.75f, 2.5f, 345.0f);

	Object* Receps_gidong9 = (Object*)malloc(sizeof(Object));
	Receps_gidong9->location = f3(853.75f, 1.25f, 340.0f);
	Receps_gidong9->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong9->type = Recep_kidung;

	BoundingBox* Receps_kkidung9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung9->start = f3(848.75f, 0.0f, 335.0f);
	Receps_kkidung9->end = f3(858.75f, 2.5f, 345.0f);

	Object* Receps_gidong10 = (Object*)malloc(sizeof(Object));
	Receps_gidong10->location = f3(863.75f, 1.25f, 340.0f);
	Receps_gidong10->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong10->type = Recep_kidung;

	BoundingBox* Receps_kkidung10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung10->start = f3(858.75f, 0.0f, 335.0f);
	Receps_kkidung10->end = f3(868.75f, 2.5f, 345.0f);

	////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong11 = (Object*)malloc(sizeof(Object));
	Receps_gidong11->location = f3(823.75f, 1.25f, 330.0f);
	Receps_gidong11->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong11->type = Recep_kidung;

	BoundingBox* Receps_kkidung11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung11->start = f3(818.75f, 0.0f, 325.0f);
	Receps_kkidung11->end = f3(828.75f, 2.5f, 335.0f);

	Object* Receps_gidong12 = (Object*)malloc(sizeof(Object));
	Receps_gidong12->location = f3(833.75f, 1.25f, 330.0f);
	Receps_gidong12->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong12->type = Recep_kidung;

	BoundingBox* Receps_kkidung12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung12->start = f3(828.75f, 0.0f, 325.0f);
	Receps_kkidung12->end = f3(838.75f, 2.5f, 335.0f);

	Object* Receps_gidong13 = (Object*)malloc(sizeof(Object));
	Receps_gidong13->location = f3(843.75f, 1.25f, 330.0f);
	Receps_gidong13->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong13->type = Recep_kidung;

	BoundingBox* Receps_kkidung13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung13->start = f3(838.75f, 0.0f, 325.0f);
	Receps_kkidung13->end = f3(848.75f, 2.5f, 335.0f);

	Object* Receps_gidong14 = (Object*)malloc(sizeof(Object));
	Receps_gidong14->location = f3(853.75f, 1.25f, 330.0f);
	Receps_gidong14->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong14->type = Recep_kidung;

	BoundingBox* Receps_kkidung14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung14->start = f3(848.75f, 0.0f, 325.0f);
	Receps_kkidung14->end = f3(858.75f, 2.5f, 335.0f);

	Object* Receps_gidong15 = (Object*)malloc(sizeof(Object));
	Receps_gidong15->location = f3(863.75f, 1.25f, 330.0f);
	Receps_gidong15->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong15->type = Recep_kidung;

	BoundingBox* Receps_kkidung15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung15->start = f3(858.75f, 0.0f, 325.0f);
	Receps_kkidung15->end = f3(868.75f, 2.5f, 335.0f);

	//////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong16 = (Object*)malloc(sizeof(Object));
	Receps_gidong16->location = f3(823.75f, 1.25f, 320.0f);
	Receps_gidong16->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong16->type = Recep_kidung;

	BoundingBox* Receps_kkidung16 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung16->start = f3(818.75f, 0.0f, 315.0f);
	Receps_kkidung16->end = f3(828.75f, 2.5f, 325.0f);

	Object* Receps_gidong17 = (Object*)malloc(sizeof(Object));
	Receps_gidong17->location = f3(833.75f, 1.25f, 320.0f);
	Receps_gidong17->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong17->type = Recep_kidung;

	BoundingBox* Receps_kkidung17 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung17->start = f3(828.75f, 0.0f, 315.0f);
	Receps_kkidung17->end = f3(838.75f, 2.5f, 325.0f);

	Object* Receps_gidong18 = (Object*)malloc(sizeof(Object));
	Receps_gidong18->location = f3(843.75f, 1.25f, 320.0f);
	Receps_gidong18->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong18->type = Recep_kidung;

	BoundingBox* Receps_kkidung18 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung18->start = f3(838.75f, 0.0f, 315.0f);
	Receps_kkidung18->end = f3(848.75f, 2.5f, 325.0f);

	Object* Receps_gidong19 = (Object*)malloc(sizeof(Object));
	Receps_gidong19->location = f3(853.75f, 1.25f, 320.0f);
	Receps_gidong19->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong19->type = Recep_kidung;

	BoundingBox* Receps_kkidung19 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung19->start = f3(848.75f, 0.0f, 315.0f);
	Receps_kkidung19->end = f3(858.75f, 2.5f, 325.0f);

	Object* Receps_gidong20 = (Object*)malloc(sizeof(Object));
	Receps_gidong20->location = f3(863.75f, 1.25f, 320.0f);
	Receps_gidong20->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong20->type = Recep_kidung;

	BoundingBox* Receps_kkidung20 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung20->start = f3(858.75f, 0.0f, 315.0f);
	Receps_kkidung20->end = f3(868.75f, 2.5f, 325.0f);

	///////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong21 = (Object*)malloc(sizeof(Object));
	Receps_gidong21->location = f3(823.75f, 1.25f, 310.0f);
	Receps_gidong21->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong21->type = Recep_kidung;

	BoundingBox* Receps_kkidung21 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung21->start = f3(818.75f, 0.0f, 305.0f);
	Receps_kkidung21->end = f3(828.75f, 2.5f, 315.0f);

	Object* Receps_gidong22 = (Object*)malloc(sizeof(Object));
	Receps_gidong22->location = f3(833.75f, 1.25f, 310.0f);
	Receps_gidong22->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong22->type = Recep_kidung;

	BoundingBox* Receps_kkidung22 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung22->start = f3(828.75f, 0.0f, 305.0f);
	Receps_kkidung22->end = f3(838.75f, 2.5f, 315.0f);

	Object* Receps_gidong23 = (Object*)malloc(sizeof(Object));
	Receps_gidong23->location = f3(843.75f, 1.25f, 310.0f);
	Receps_gidong23->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong23->type = Recep_kidung;

	BoundingBox* Receps_kkidung23 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung23->start = f3(838.75f, 0.0f, 305.0f);
	Receps_kkidung23->end = f3(848.75f, 2.5f, 315.0f);

	Object* Receps_gidong24 = (Object*)malloc(sizeof(Object));
	Receps_gidong24->location = f3(853.75f, 1.25f, 310.0f);
	Receps_gidong24->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong24->type = Recep_kidung;

	BoundingBox* Receps_kkidung24 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung24->start = f3(848.75f, 0.0f, 305.0f);
	Receps_kkidung24->end = f3(858.75f, 2.5f, 315.0f);

	Object* Receps_gidong25 = (Object*)malloc(sizeof(Object));
	Receps_gidong25->location = f3(863.75f, 1.25f, 310.0f);
	Receps_gidong25->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong25->type = Recep_kidung;

	BoundingBox* Receps_kkidung25 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung25->start = f3(858.75f, 0.0f, 305.0f);
	Receps_kkidung25->end = f3(868.75f, 2.5f, 315.0f);

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong26 = (Object*)malloc(sizeof(Object));
	Receps_gidong26->location = f3(823.75f, 1.25f, 300.0f);
	Receps_gidong26->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong26->type = Recep_kidung;

	BoundingBox* Receps_kkidung26 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung26->start = f3(818.75f, 0.0f, 295.0f);
	Receps_kkidung26->end = f3(828.75f, 2.5f, 305.0f);

	Object* Receps_gidong27 = (Object*)malloc(sizeof(Object));
	Receps_gidong27->location = f3(833.75f, 1.25f, 300.0f);
	Receps_gidong27->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong27->type = Recep_kidung;

	BoundingBox* Receps_kkidung27 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung27->start = f3(828.75f, 0.0f, 295.0f);
	Receps_kkidung27->end = f3(838.75f, 2.5f, 305.0f);

	Object* Receps_gidong28 = (Object*)malloc(sizeof(Object));
	Receps_gidong28->location = f3(843.75f, 1.25f, 300.0f);
	Receps_gidong28->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong28->type = Recep_kidung;

	BoundingBox* Receps_kkidung28 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung28->start = f3(838.75f, 0.0f, 295.0f);
	Receps_kkidung28->end = f3(848.75f, 2.5f, 305.0f);

	Object* Receps_gidong29 = (Object*)malloc(sizeof(Object));
	Receps_gidong29->location = f3(853.75f, 1.25f, 300.0f);
	Receps_gidong29->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong29->type = Recep_kidung;

	BoundingBox* Receps_kkidung29 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung29->start = f3(848.75f, 0.0f, 295.0f);
	Receps_kkidung29->end = f3(858.75f, 2.5f, 305.0f);

	Object* Receps_gidong30 = (Object*)malloc(sizeof(Object));
	Receps_gidong30->location = f3(863.75f, 1.25f, 300.0f);
	Receps_gidong30->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong30->type = Recep_kidung;

	BoundingBox* Receps_kkidung30 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung30->start = f3(858.75f, 0.0f, 295.0f);
	Receps_kkidung30->end = f3(868.75f, 2.5f, 305.0f);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong31 = (Object*)malloc(sizeof(Object));
	Receps_gidong31->location = f3(823.75f, 1.25f, 290.0f);
	Receps_gidong31->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong31->type = Recep_kidung;

	BoundingBox* Receps_kkidung31 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung31->start = f3(818.75f, 0.0f, 285.0f);
	Receps_kkidung31->end = f3(828.75f, 2.5f, 295.0f);

	Object* Receps_gidong32 = (Object*)malloc(sizeof(Object));
	Receps_gidong32->location = f3(833.75f, 1.25f, 290.0f);
	Receps_gidong32->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong32->type = Recep_kidung;

	BoundingBox* Receps_kkidung32 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung32->start = f3(828.75f, 0.0f, 285.0f);
	Receps_kkidung32->end = f3(838.75f, 2.5f, 295.0f);

	Object* Receps_gidong33 = (Object*)malloc(sizeof(Object));
	Receps_gidong33->location = f3(843.75f, 1.25f, 290.0f);
	Receps_gidong33->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong33->type = Recep_kidung;

	BoundingBox* Receps_kkidung33 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung33->start = f3(838.75f, 0.0f, 285.0f);
	Receps_kkidung33->end = f3(848.75f, 2.5f, 295.0f);

	Object* Receps_gidong34 = (Object*)malloc(sizeof(Object));
	Receps_gidong34->location = f3(853.75f, 1.25f, 290.0f);
	Receps_gidong34->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong34->type = Recep_kidung;

	BoundingBox* Receps_kkidung34 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung34->start = f3(848.75f, 0.0f, 285.0f);
	Receps_kkidung34->end = f3(858.75f, 2.5f, 295.0f);

	Object* Receps_gidong35 = (Object*)malloc(sizeof(Object));
	Receps_gidong35->location = f3(863.75f, 1.25f, 290.0f);
	Receps_gidong35->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong35->type = Recep_kidung;

	BoundingBox* Receps_kkidung35 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung35->start = f3(858.75f, 0.0f, 285.0f);
	Receps_kkidung35->end = f3(868.75f, 2.5f, 295.0f);

	///////////////////////////////////////////////////////////////////////

	Object* Receps_gidong36 = (Object*)malloc(sizeof(Object));
	Receps_gidong36->location = f3(823.75f, 1.25f, 280.0f);
	Receps_gidong36->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong36->type = Recep_kidung;

	BoundingBox* Receps_kkidung36 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung36->start = f3(818.75f, 0.0f, 275.0f);
	Receps_kkidung36->end = f3(828.75f, 2.5f, 285.0f);

	Object* Receps_gidong37 = (Object*)malloc(sizeof(Object));
	Receps_gidong37->location = f3(833.75f, 1.25f, 280.0f);
	Receps_gidong37->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong37->type = Recep_kidung;

	BoundingBox* Receps_kkidung37 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung37->start = f3(828.75f, 0.0f, 275.0f);
	Receps_kkidung37->end = f3(838.75f, 2.5f, 285.0f);

	Object* Receps_gidong38 = (Object*)malloc(sizeof(Object));
	Receps_gidong38->location = f3(843.75f, 1.25f, 280.0f);
	Receps_gidong38->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong38->type = Recep_kidung;

	BoundingBox* Receps_kkidung38 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung38->start = f3(838.75f, 0.0f, 275.0f);
	Receps_kkidung38->end = f3(848.75f, 2.5f, 285.0f);

	Object* Receps_gidong39 = (Object*)malloc(sizeof(Object));
	Receps_gidong39->location = f3(853.75f, 1.25f, 280.0f);
	Receps_gidong39->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong39->type = Recep_kidung;

	BoundingBox* Receps_kkidung39 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung39->start = f3(848.75f, 0.0f, 275.0f);
	Receps_kkidung39->end = f3(858.75f, 2.5f, 285.0f);

	Object* Receps_gidong40 = (Object*)malloc(sizeof(Object));
	Receps_gidong40->location = f3(863.75f, 1.25f, 280.0f);
	Receps_gidong40->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong40->type = Recep_kidung;

	BoundingBox* Receps_kkidung40 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung40->start = f3(858.75f, 0.0f, 275.0f);
	Receps_kkidung40->end = f3(868.75f, 2.5f, 285.0f);

	////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong41 = (Object*)malloc(sizeof(Object));
	Receps_gidong41->location = f3(823.75f, 1.25f, 270.0f);
	Receps_gidong41->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong41->type = Recep_kidung;

	BoundingBox* Receps_kkidung41 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung41->start = f3(818.75f, 0.0f, 265.0f);
	Receps_kkidung41->end = f3(828.75f, 2.5f, 275.0f);

	Object* Receps_gidong42 = (Object*)malloc(sizeof(Object));
	Receps_gidong42->location = f3(833.75f, 1.25f, 270.0f);
	Receps_gidong42->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong42->type = Recep_kidung;

	BoundingBox* Receps_kkidung42 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung42->start = f3(828.75f, 0.0f, 265.0f);
	Receps_kkidung42->end = f3(838.75f, 2.5f, 275.0f);

	Object* Receps_gidong43 = (Object*)malloc(sizeof(Object));
	Receps_gidong43->location = f3(843.75f, 1.25f, 270.0f);
	Receps_gidong43->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong43->type = Recep_kidung;

	BoundingBox* Receps_kkidung43 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung43->start = f3(838.75f, 0.0f, 265.0f);
	Receps_kkidung43->end = f3(848.75f, 2.5f, 275.0f);

	Object* Receps_gidong44 = (Object*)malloc(sizeof(Object));
	Receps_gidong44->location = f3(853.75f, 1.25f, 270.0f);
	Receps_gidong44->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong44->type = Recep_kidung;

	BoundingBox* Receps_kkidung44 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung44->start = f3(848.75f, 0.0f, 265.0f);
	Receps_kkidung44->end = f3(858.75f, 2.5f, 275.0f);

	Object* Receps_gidong45 = (Object*)malloc(sizeof(Object));
	Receps_gidong45->location = f3(863.75f, 1.25f, 270.0f);
	Receps_gidong45->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong45->type = Recep_kidung;

	BoundingBox* Receps_kkidung45 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung45->start = f3(858.75f, 0.0f, 265.0f);
	Receps_kkidung45->end = f3(868.75f, 2.5f, 275.0f);

	//////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong46 = (Object*)malloc(sizeof(Object));
	Receps_gidong46->location = f3(823.75f, 1.25f, 260.0f);
	Receps_gidong46->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong46->type = Recep_kidung;

	BoundingBox* Receps_kkidung46 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung46->start = f3(818.75f, 0.0f, 255.0f);
	Receps_kkidung46->end = f3(828.75f, 2.5f, 265.0f);

	Object* Receps_gidong47 = (Object*)malloc(sizeof(Object));
	Receps_gidong47->location = f3(833.75f, 1.25f, 260.0f);
	Receps_gidong47->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong47->type = Recep_kidung;

	BoundingBox* Receps_kkidung47 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung47->start = f3(828.75f, 0.0f, 255.0f);
	Receps_kkidung47->end = f3(838.75f, 2.5f, 265.0f);

	Object* Receps_gidong48 = (Object*)malloc(sizeof(Object));
	Receps_gidong48->location = f3(843.75f, 1.25f, 260.0f);
	Receps_gidong48->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong48->type = Recep_kidung;

	BoundingBox* Receps_kkidung48 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung48->start = f3(838.75f, 0.0f, 255.0f);
	Receps_kkidung48->end = f3(848.75f, 2.5f, 265.0f);

	Object* Receps_gidong49 = (Object*)malloc(sizeof(Object));
	Receps_gidong49->location = f3(853.75f, 1.25f, 260.0f);
	Receps_gidong49->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong49->type = Recep_kidung;

	BoundingBox* Receps_kkidung49 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung49->start = f3(848.75f, 0.0f, 255.0f);
	Receps_kkidung49->end = f3(858.75f, 2.5f, 265.0f);

	Object* Receps_gidong50 = (Object*)malloc(sizeof(Object));
	Receps_gidong50->location = f3(863.75f, 1.25f, 260.0f);
	Receps_gidong50->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong50->type = Recep_kidung;

	BoundingBox* Receps_kkidung50 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung50->start = f3(858.75f, 0.0f, 255.0f);
	Receps_kkidung50->end = f3(868.75f, 2.5f, 265.0f);

	///////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong51 = (Object*)malloc(sizeof(Object));
	Receps_gidong51->location = f3(823.75f, 1.25f, 250.0f);
	Receps_gidong51->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong51->type = Recep_kidung;

	BoundingBox* Receps_kkidung51 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung51->start = f3(818.75f, 0.0f, 245.0f);
	Receps_kkidung51->end = f3(828.75f, 2.5f, 255.0f);

	Object* Receps_gidong52 = (Object*)malloc(sizeof(Object));
	Receps_gidong52->location = f3(833.75f, 1.25f, 250.0f);
	Receps_gidong52->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong52->type = Recep_kidung;

	BoundingBox* Receps_kkidung52 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung52->start = f3(828.75f, 0.0f, 245.0f);
	Receps_kkidung52->end = f3(838.75f, 2.5f, 255.0f);

	Object* Receps_gidong53 = (Object*)malloc(sizeof(Object));
	Receps_gidong53->location = f3(843.75f, 1.25f, 250.0f);
	Receps_gidong53->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong53->type = Recep_kidung;

	BoundingBox* Receps_kkidung53 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung53->start = f3(838.75f, 0.0f, 245.0f);
	Receps_kkidung53->end = f3(848.75f, 2.5f, 255.0f);

	Object* Receps_gidong54 = (Object*)malloc(sizeof(Object));
	Receps_gidong54->location = f3(853.75f, 1.25f, 250.0f);
	Receps_gidong54->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong54->type = Recep_kidung;

	BoundingBox* Receps_kkidung54 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung54->start = f3(848.75f, 0.0f, 245.0f);
	Receps_kkidung54->end = f3(858.75f, 2.5f, 255.0f);

	Object* Receps_gidong55 = (Object*)malloc(sizeof(Object));
	Receps_gidong55->location = f3(863.75f, 1.25f, 250.0f);
	Receps_gidong55->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong55->type = Recep_kidung;

	BoundingBox* Receps_kkidung55 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung55->start = f3(858.75f, 0.0f, 245.0f);
	Receps_kkidung55->end = f3(868.75f, 2.5f, 255.0f);

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong56 = (Object*)malloc(sizeof(Object));
	Receps_gidong56->location = f3(823.75f, 1.25f, 240.0f);
	Receps_gidong56->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong56->type = Recep_kidung;

	BoundingBox* Receps_kkidung56 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung56->start = f3(818.75f, 0.0f, 235.0f);
	Receps_kkidung56->end = f3(828.75f, 2.5f, 245.0f);

	Object* Receps_gidong57 = (Object*)malloc(sizeof(Object));
	Receps_gidong57->location = f3(833.75f, 1.25f, 240.0f);
	Receps_gidong57->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong57->type = Recep_kidung;

	BoundingBox* Receps_kkidung57 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung57->start = f3(828.75f, 0.0f, 235.0f);
	Receps_kkidung57->end = f3(838.75f, 2.5f, 245.0f);

	Object* Receps_gidong58 = (Object*)malloc(sizeof(Object));
	Receps_gidong58->location = f3(843.75f, 1.25f, 240.0f);
	Receps_gidong58->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong58->type = Recep_kidung;

	BoundingBox* Receps_kkidung58 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung58->start = f3(838.75f, 0.0f, 235.0f);
	Receps_kkidung58->end = f3(848.75f, 2.5f, 245.0f);

	Object* Receps_gidong59 = (Object*)malloc(sizeof(Object));
	Receps_gidong59->location = f3(853.75f, 1.25f, 240.0f);
	Receps_gidong59->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong59->type = Recep_kidung;

	BoundingBox* Receps_kkidung59 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung59->start = f3(848.75f, 0.0f, 235.0f);
	Receps_kkidung59->end = f3(858.75f, 2.5f, 245.0f);

	Object* Receps_gidong60 = (Object*)malloc(sizeof(Object));
	Receps_gidong60->location = f3(863.75f, 1.25f, 240.0f);
	Receps_gidong60->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong60->type = Recep_kidung;

	BoundingBox* Receps_kkidung60 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung60->start = f3(858.75f, 0.0f, 235.0f);
	Receps_kkidung60->end = f3(868.75f, 2.5f, 245.0f);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong1_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong1_1->location = f3(823.75f, 3.75f, 350.0f);
	Receps_gidong1_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong1_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung1_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung1_1->start = f3(818.75f, 2.5f, 345.0f);
	Receps_kkidung1_1->end = f3(828.75f, 5.0f, 355.0f);

	Object* Receps_gidong2_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong2_1->location = f3(833.75f, 3.75f, 350.0f);
	Receps_gidong2_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong2_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung2_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung2_1->start = f3(828.75f, 2.5f, 345.0f);
	Receps_kkidung2_1->end = f3(838.75f, 5.0f, 355.0f);

	Object* Receps_gidong3_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong3_1->location = f3(843.75f, 3.75f, 350.0f);
	Receps_gidong3_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong3_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung3_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung3_1->start = f3(838.75f, 2.5f, 345.0f);
	Receps_kkidung3_1->end = f3(848.75f, 5.0f, 355.0f);

	Object* Receps_gidong4_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong4_1->location = f3(853.75f, 3.75f, 350.0f);
	Receps_gidong4_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong4_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung4_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung4_1->start = f3(848.75f, 2.5f, 345.0f);
	Receps_kkidung4_1->end = f3(858.75f, 5.0f, 355.0f);

	Object* Receps_gidong5_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong5_1->location = f3(863.75f, 3.75f, 350.0f);
	Receps_gidong5_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong5_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung5_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung5_1->start = f3(858.75f, 2.5f, 345.0f);
	Receps_kkidung5_1->end = f3(868.75f, 5.0f, 355.0f);

	///////////////////////////////////////////////////////////////////////

	Object* Receps_gidong6_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong6_1->location = f3(823.75f, 3.75f, 340.0f);
	Receps_gidong6_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong6_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung6_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung6_1->start = f3(818.75f, 2.5f, 335.0f);
	Receps_kkidung6_1->end = f3(828.75f, 5.0f, 345.0f);

	Object* Receps_gidong7_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong7_1->location = f3(833.75f, 3.75f, 340.0f);
	Receps_gidong7_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong7_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung7_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung7_1->start = f3(828.75f, 2.5f, 335.0f);
	Receps_kkidung7_1->end = f3(838.75f, 5.0f, 345.0f);

	Object* Receps_gidong8_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong8_1->location = f3(843.75f, 3.75f, 340.0f);
	Receps_gidong8_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong8_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung8_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung8_1->start = f3(838.75f, 2.5f, 335.0f);
	Receps_kkidung8_1->end = f3(848.75f, 5.0f, 345.0f);

	Object* Receps_gidong9_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong9_1->location = f3(853.75f, 3.75f, 340.0f);
	Receps_gidong9_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong9_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung9_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung9_1->start = f3(848.75f, 2.5f, 335.0f);
	Receps_kkidung9_1->end = f3(858.75f, 5.0f, 345.0f);

	Object* Receps_gidong10_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong10_1->location = f3(863.75f, 3.75f, 340.0f);
	Receps_gidong10_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong10_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung10_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung10_1->start = f3(858.75f, 2.5f, 335.0f);
	Receps_kkidung10_1->end = f3(868.75f, 5.0f, 345.0f);

	////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong11_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong11_1->location = f3(823.75f, 3.75f, 330.0f);
	Receps_gidong11_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong11_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung11_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung11_1->start = f3(818.75f, 2.5f, 325.0f);
	Receps_kkidung11_1->end = f3(828.75f, 5.0f, 335.0f);

	Object* Receps_gidong12_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong12_1->location = f3(833.75f, 3.75f, 330.0f);
	Receps_gidong12_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong12_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung12_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung12_1->start = f3(828.75f, 2.5f, 325.0f);
	Receps_kkidung12_1->end = f3(838.75f, 5.0f, 335.0f);

	Object* Receps_gidong13_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong13_1->location = f3(843.75f, 3.75f, 330.0f);
	Receps_gidong13_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong13_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung13_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung13_1->start = f3(838.75f, 2.5f, 325.0f);
	Receps_kkidung13_1->end = f3(848.75f, 5.0f, 335.0f);

	Object* Receps_gidong14_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong14_1->location = f3(853.75f, 2.75f, 330.0f);
	Receps_gidong14_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong14_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung14_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung14_1->start = f3(848.75f, 2.5f, 325.0f);
	Receps_kkidung14_1->end = f3(858.75f, 5.0f, 335.0f);

	Object* Receps_gidong15_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong15_1->location = f3(863.75f, 3.75f, 330.0f);
	Receps_gidong15_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong15_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung15_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung15_1->start = f3(858.75f, 2.5f, 325.0f);
	Receps_kkidung15_1->end = f3(868.75f, 5.0f, 335.0f);

	//////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong16_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong16_1->location = f3(823.75f, 3.75f, 320.0f);
	Receps_gidong16_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong16_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung16_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung16_1->start = f3(818.75f, 2.5f, 315.0f);
	Receps_kkidung16_1->end = f3(828.75f, 5.0f, 325.0f);

	Object* Receps_gidong17_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong17_1->location = f3(833.75f, 3.75f, 320.0f);
	Receps_gidong17_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong17_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung17_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung17_1->start = f3(828.75f, 2.5f, 315.0f);
	Receps_kkidung17_1->end = f3(838.75f, 5.0f, 325.0f);

	Object* Receps_gidong18_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong18_1->location = f3(843.75f, 3.75f, 320.0f);
	Receps_gidong18_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong18_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung18_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung18_1->start = f3(838.75f, 2.5f, 315.0f);
	Receps_kkidung18_1->end = f3(848.75f, 5.0f, 325.0f);

	Object* Receps_gidong19_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong19_1->location = f3(853.75f, 3.75f, 320.0f);
	Receps_gidong19_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong19_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung19_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung19_1->start = f3(848.75f, 2.5f, 315.0f);
	Receps_kkidung19_1->end = f3(858.75f, 5.0f, 325.0f);

	Object* Receps_gidong20_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong20_1->location = f3(863.75f, 3.75f, 320.0f);
	Receps_gidong20_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong20_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung20_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung20_1->start = f3(858.75f, 2.5f, 315.0f);
	Receps_kkidung20_1->end = f3(868.75f, 5.0f, 325.0f);

	///////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong21_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong21_1->location = f3(823.75f, 3.75f, 310.0f);
	Receps_gidong21_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong21_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung21_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung21_1->start = f3(818.75f, 2.5f, 305.0f);
	Receps_kkidung21_1->end = f3(828.75f, 5.0f, 315.0f);

	Object* Receps_gidong22_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong22_1->location = f3(833.75f, 3.75f, 310.0f);
	Receps_gidong22_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong22_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung22_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung22_1->start = f3(828.75f, 2.5f, 305.0f);
	Receps_kkidung22_1->end = f3(838.75f, 5.0f, 315.0f);

	Object* Receps_gidong23_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong23_1->location = f3(843.75f, 3.75f, 310.0f);
	Receps_gidong23_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong23_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung23_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung23_1->start = f3(838.75f, 2.5f, 305.0f);
	Receps_kkidung23_1->end = f3(848.75f, 5.0f, 315.0f);

	Object* Receps_gidong24_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong24_1->location = f3(853.75f, 3.75f, 310.0f);
	Receps_gidong24_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong24_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung24_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung24_1->start = f3(848.75f, 2.5f, 305.0f);
	Receps_kkidung24_1->end = f3(858.75f, 5.0f, 315.0f);

	Object* Receps_gidong25_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong25_1->location = f3(863.75f, 3.75f, 310.0f);
	Receps_gidong25_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong25_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung25_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung25_1->start = f3(858.75f, 2.5f, 305.0f);
	Receps_kkidung25_1->end = f3(868.75f, 5.0f, 315.0f);

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong26_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong26_1->location = f3(823.75f, 3.75f, 300.0f);
	Receps_gidong26_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong26_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung26_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung26_1->start = f3(818.75f, 2.5f, 295.0f);
	Receps_kkidung26_1->end = f3(828.75f, 5.0f, 305.0f);

	Object* Receps_gidong27_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong27_1->location = f3(833.75f, 3.75f, 300.0f);
	Receps_gidong27_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong27_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung27_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung27_1->start = f3(828.75f, 2.5f, 295.0f);
	Receps_kkidung27_1->end = f3(838.75f, 5.0f, 305.0f);

	Object* Receps_gidong28_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong28_1->location = f3(843.75f, 3.75f, 300.0f);
	Receps_gidong28_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong28_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung28_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung28_1->start = f3(838.75f, 2.5f, 295.0f);
	Receps_kkidung28_1->end = f3(848.75f, 5.0f, 305.0f);

	Object* Receps_gidong29_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong29_1->location = f3(853.75f, 3.75f, 300.0f);
	Receps_gidong29_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong29_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung29_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung29_1->start = f3(848.75f, 2.5f, 295.0f);
	Receps_kkidung29_1->end = f3(858.75f, 5.0f, 305.0f);

	Object* Receps_gidong30_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong30_1->location = f3(863.75f, 3.75f, 300.0f);
	Receps_gidong30_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong30_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung30_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung30_1->start = f3(858.75f, 2.5f, 295.0f);
	Receps_kkidung30_1->end = f3(868.75f, 5.0f, 305.0f);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong31_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong31_1->location = f3(823.75f, 3.75f, 290.0f);
	Receps_gidong31_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong31_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung31_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung31_1->start = f3(818.75f, 2.5f, 285.0f);
	Receps_kkidung31_1->end = f3(828.75f, 5.0f, 295.0f);

	Object* Receps_gidong32_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong32_1->location = f3(833.75f, 3.75f, 290.0f);
	Receps_gidong32_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong32_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung32_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung32_1->start = f3(828.75f, 2.5f, 285.0f);
	Receps_kkidung32_1->end = f3(838.75f, 5.0f, 295.0f);

	Object* Receps_gidong33_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong33_1->location = f3(843.75f, 3.75f, 290.0f);
	Receps_gidong33_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong33_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung33_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung33_1->start = f3(838.75f, 2.5f, 285.0f);
	Receps_kkidung33_1->end = f3(848.75f, 5.0f, 295.0f);

	Object* Receps_gidong34_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong34_1->location = f3(853.75f, 3.75f, 290.0f);
	Receps_gidong34_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong34_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung34_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung34_1->start = f3(848.75f, 2.5f, 285.0f);
	Receps_kkidung34_1->end = f3(858.75f, 5.0f, 295.0f);

	Object* Receps_gidong35_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong35_1->location = f3(863.75f, 3.75f, 290.0f);
	Receps_gidong35_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong35_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung35_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung35_1->start = f3(858.75f, 2.5f, 285.0f);
	Receps_kkidung35_1->end = f3(868.75f, 5.0f, 295.0f);

	///////////////////////////////////////////////////////////////////////

	Object* Receps_gidong36_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong36_1->location = f3(823.75f, 3.75f, 280.0f);
	Receps_gidong36_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong36_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung36_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung36_1->start = f3(818.75f, 2.5f, 275.0f);
	Receps_kkidung36_1->end = f3(828.75f, 5.0f, 285.0f);

	Object* Receps_gidong37_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong37_1->location = f3(833.75f, 3.75f, 280.0f);
	Receps_gidong37_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong37_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung37_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung37_1->start = f3(828.75f, 2.5f, 275.0f);
	Receps_kkidung37_1->end = f3(838.75f, 5.0f, 285.0f);

	Object* Receps_gidong38_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong38_1->location = f3(843.75f, 3.75f, 280.0f);
	Receps_gidong38_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong38_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung38_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung38_1->start = f3(838.75f, 2.5f, 275.0f);
	Receps_kkidung38_1->end = f3(848.75f, 5.0f, 285.0f);

	Object* Receps_gidong39_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong39_1->location = f3(853.75f, 3.75f, 280.0f);
	Receps_gidong39_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong39_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung39_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung39_1->start = f3(848.75f, 2.5f, 275.0f);
	Receps_kkidung39_1->end = f3(858.75f, 5.0f, 285.0f);

	Object* Receps_gidong40_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong40_1->location = f3(863.75f, 3.75f, 280.0f);
	Receps_gidong40_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong40_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung40_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung40_1->start = f3(858.75f, 2.5f, 275.0f);
	Receps_kkidung40_1->end = f3(868.75f, 5.0f, 285.0f);

	////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong41_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong41_1->location = f3(823.75f, 3.75f, 270.0f);
	Receps_gidong41_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong41_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung41_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung41_1->start = f3(818.75f, 2.5f, 265.0f);
	Receps_kkidung41_1->end = f3(828.75f, 5.0f, 275.0f);

	Object* Receps_gidong42_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong42_1->location = f3(833.75f, 3.75f, 270.0f);
	Receps_gidong42_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong42_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung42_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung42_1->start = f3(828.75f, 2.5f, 265.0f);
	Receps_kkidung42_1->end = f3(838.75f, 5.0f, 275.0f);

	Object* Receps_gidong43_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong43_1->location = f3(843.75f, 3.75f, 270.0f);
	Receps_gidong43_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong43_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung43_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung43_1->start = f3(838.75f, 2.5f, 265.0f);
	Receps_kkidung43_1->end = f3(848.75f, 5.0f, 275.0f);

	Object* Receps_gidong44_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong44_1->location = f3(853.75f, 3.75f, 270.0f);
	Receps_gidong44_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong44_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung44_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung44_1->start = f3(848.75f, 2.5f, 265.0f);
	Receps_kkidung44_1->end = f3(858.75f, 5.0f, 275.0f);

	Object* Receps_gidong45_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong45_1->location = f3(863.75f, 3.75f, 270.0f);
	Receps_gidong45_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong45_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung45_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung45_1->start = f3(858.75f, 2.5f, 265.0f);
	Receps_kkidung45_1->end = f3(868.75f, 5.0f, 275.0f);

	//////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong46_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong46_1->location = f3(823.75f, 3.75f, 260.0f);
	Receps_gidong46_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong46_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung46_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung46_1->start = f3(818.75f, 2.5f, 255.0f);
	Receps_kkidung46_1->end = f3(828.75f, 5.0f, 265.0f);

	Object* Receps_gidong47_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong47_1->location = f3(833.75f, 3.75f, 260.0f);
	Receps_gidong47_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong47_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung47_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung47_1->start = f3(828.75f, 2.5f, 255.0f);
	Receps_kkidung47_1->end = f3(838.75f, 5.0f, 265.0f);

	Object* Receps_gidong48_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong48_1->location = f3(843.75f, 3.75f, 260.0f);
	Receps_gidong48_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong48_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung48_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung48_1->start = f3(838.75f, 2.5f, 255.0f);
	Receps_kkidung48_1->end = f3(848.75f, 5.0f, 265.0f);

	Object* Receps_gidong49_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong49_1->location = f3(853.75f, 3.75f, 260.0f);
	Receps_gidong49_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong49_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung49_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung49_1->start = f3(848.75f, 2.5f, 255.0f);
	Receps_kkidung49_1->end = f3(858.75f, 5.0f, 265.0f);

	Object* Receps_gidong50_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong50_1->location = f3(863.75f, 3.75f, 260.0f);
	Receps_gidong50_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong50_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung50_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung50_1->start = f3(858.75f, 2.5f, 255.0f);
	Receps_kkidung50_1->end = f3(868.75f, 5.0f, 265.0f);

	///////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong51_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong51_1->location = f3(823.75f, 3.75f, 250.0f);
	Receps_gidong51_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong51_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung51_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung51_1->start = f3(818.75f, 2.5f, 245.0f);
	Receps_kkidung51_1->end = f3(828.75f, 5.0f, 255.0f);

	Object* Receps_gidong52_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong52_1->location = f3(833.75f, 3.75f, 250.0f);
	Receps_gidong52_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong52_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung52_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung52_1->start = f3(828.75f, 2.5f, 245.0f);
	Receps_kkidung52_1->end = f3(838.75f, 5.0f, 255.0f);

	Object* Receps_gidong53_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong53_1->location = f3(843.75f, 3.75f, 250.0f);
	Receps_gidong53_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong53_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung53_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung53_1->start = f3(838.75f, 2.5f, 245.0f);
	Receps_kkidung53_1->end = f3(848.75f, 5.0f, 255.0f);

	Object* Receps_gidong54_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong54_1->location = f3(853.75f, 3.75f, 250.0f);
	Receps_gidong54_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong54_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung54_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung54_1->start = f3(848.75f, 2.5f, 245.0f);
	Receps_kkidung54_1->end = f3(858.75f, 5.0f, 255.0f);

	Object* Receps_gidong55_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong55_1->location = f3(863.75f, 3.75f, 250.0f);
	Receps_gidong55_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong55_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung55_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung55_1->start = f3(858.75f, 2.5f, 245.0f);
	Receps_kkidung55_1->end = f3(868.75f, 5.0f, 255.0f);

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gidong56_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong56_1->location = f3(823.75f, 3.75f, 240.0f);
	Receps_gidong56_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong56_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung56_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung56_1->start = f3(818.75f, 2.5f, 235.0f);
	Receps_kkidung56_1->end = f3(828.75f, 5.0f, 245.0f);

	Object* Receps_gidong57_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong57_1->location = f3(833.75f, 3.75f, 240.0f);
	Receps_gidong57_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong57_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung57_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung57_1->start = f3(828.75f, 2.5f, 235.0f);
	Receps_kkidung57_1->end = f3(838.75f, 5.0f, 245.0f);

	Object* Receps_gidong58_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong58_1->location = f3(843.75f, 3.75f, 240.0f);
	Receps_gidong58_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong58_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung58_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung58_1->start = f3(838.75f, 2.5f, 235.0f);
	Receps_kkidung58_1->end = f3(848.75f, 5.0f, 245.0f);

	Object* Receps_gidong59_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong59_1->location = f3(853.75f, 3.75f, 240.0f);
	Receps_gidong59_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong59_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung59_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung59_1->start = f3(848.75f, 2.5f, 235.0f);
	Receps_kkidung59_1->end = f3(858.75f, 5.0f, 245.0f);

	Object* Receps_gidong60_1 = (Object*)malloc(sizeof(Object));
	Receps_gidong60_1->location = f3(863.75f, 3.75f, 240.0f);
	Receps_gidong60_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gidong60_1->type = Recep_kidung;

	BoundingBox* Receps_kkidung60_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_kkidung60_1->start = f3(858.75f, 2.5f, 235.0f);
	Receps_kkidung60_1->end = f3(868.75f, 5.0f, 245.0f);

	////////////////////////////////////////////////////////////////////////////



	list.push_back(*Receps_celing1);
	blist.push_back(*receps_celing1);

	list.push_back(*Receps_floor1);
	blist.push_back(*receps_floor1);

	list.push_back(*Receps_wall1);
	blist.push_back(*Receps_walled1);

	list.push_back(*Receps_wall2);
	blist.push_back(*Receps_walled2);

	list.push_back(*Receps_wall3);
	blist.push_back(*Receps_walled3);

	list.push_back(*Receps_wall4);
	blist.push_back(*Receps_walled4);

	list.push_back(*Receps_wall5);
	blist.push_back(*Receps_walled5);

	list.push_back(*Receps_wall6);
	blist.push_back(*Receps_walled6);

	list.push_back(*Receps_wall7);
	blist.push_back(*Receps_walled7);

	///////////////////////////////////////////////////////////

	list.push_back(*Receps_wall1R);
	blist.push_back(*Receps_walled1R);

	list.push_back(*Receps_wall2R);
	blist.push_back(*Receps_walled2R);

	list.push_back(*Receps_wall3R);
	blist.push_back(*Receps_walled3R);

	list.push_back(*Receps_wall4R);
	blist.push_back(*Receps_walled4R);

	list.push_back(*Receps_wall5R);
	blist.push_back(*Receps_walled5R);

	list.push_back(*Receps_wall6R);
	blist.push_back(*Receps_walled6R);

	list.push_back(*Receps_wall7R);
	blist.push_back(*Receps_walled7R);

	////////////////////////////////////////////////////////////

	list.push_back(*Receps_wall1e);
	blist.push_back(*Receps_wall1ede);

	list.push_back(*Receps_wall2e);
	blist.push_back(*Receps_wall2ede);

	list.push_back(*Receps_wall3e);
	blist.push_back(*Receps_wall3ede);

	list.push_back(*Receps_wall4e);
	blist.push_back(*Receps_wall4ede);

	list.push_back(*Receps_wall5e);
	blist.push_back(*Receps_wall5ede);

	list.push_back(*Receps_wall6e);
	blist.push_back(*Receps_wall6ede);

	list.push_back(*Receps_wall7e);
	blist.push_back(*Receps_wall7ede);

	//////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_wall1eL);
	blist.push_back(*Receps_wall1edeL);

	list.push_back(*Receps_wall2eL);
	blist.push_back(*Receps_wall2edeL);

	list.push_back(*Receps_wall3eL);
	blist.push_back(*Receps_wall3edeL);

	list.push_back(*Receps_wall4eL);
	blist.push_back(*Receps_wall4edeL);

	list.push_back(*Receps_wall5eL);
	blist.push_back(*Receps_wall5edeL);

	list.push_back(*Receps_wall6eL);
	blist.push_back(*Receps_wall6edeL);

	list.push_back(*Receps_wall7eL);
	blist.push_back(*Receps_wall7edeL);

	////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_front1);
	blist.push_back(*Receps_fronted1);

	list.push_back(*Receps_front2);
	blist.push_back(*Receps_fronted2);

	list.push_back(*Receps_front3);
	blist.push_back(*Receps_fronted3);

	////////////////////////////////////////////////////////////////////////


	list.push_back(*Receps_fronte1);
	blist.push_back(*Receps_fronte1e);

	list.push_back(*Receps_fronte2);
	blist.push_back(*Receps_fronte2e);

	list.push_back(*Receps_fronte3);
	blist.push_back(*Receps_fronte3e);

	list.push_back(*Receps_fronte4);
	blist.push_back(*Receps_fronte4e);

	//////////////////////////////////////////////

	list.push_back(*Receps_ipgu);
	blist.push_back(*Receps_iping);

	list.push_back(*Receps_ipgu2);
	blist.push_back(*Receps_iping2);

	list.push_back(*Receps_ipgu3);
	blist.push_back(*Receps_iping3);

	list.push_back(*Receps_ipgu4);
	blist.push_back(*Receps_iping4);

	list.push_back(*Receps_ipgu5);
	blist.push_back(*Receps_iping5);

	list.push_back(*Receps_ipgu6);
	blist.push_back(*Receps_iping6);

	///////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_ipgu4_l);
	blist.push_back(*Receps_iping4_l);

	list.push_back(*Receps_ipgu5_l);
	blist.push_back(*Receps_iping5_l);

	list.push_back(*Receps_ipgu6_l);
	blist.push_back(*Receps_iping6_l);

	/////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_ipgu7);
	blist.push_back(*Receps_iping7);

	list.push_back(*Receps_ipgu8);
	blist.push_back(*Receps_iping8);

	list.push_back(*Receps_ipgu9);
	blist.push_back(*Receps_iping9);

	list.push_back(*Receps_ipgu10);
	blist.push_back(*Receps_iping10);

	list.push_back(*Receps_ipgu11);
	blist.push_back(*Receps_iping11);

	list.push_back(*Receps_ipgu12);
	blist.push_back(*Receps_iping12);

	//////////////////////////////////////////////////////////////////////////////////


	list.push_back(*Receps_ipgu7_l);
	blist.push_back(*Receps_iping7_l);

	list.push_back(*Receps_ipgu8_l);
	blist.push_back(*Receps_iping8_l);

	list.push_back(*Receps_ipgu9_l);
	blist.push_back(*Receps_iping9_l);

	list.push_back(*Receps_ipgu10_l);
	blist.push_back(*Receps_iping10_l);

	list.push_back(*Receps_ipgu11_l);
	blist.push_back(*Receps_iping11_l);

	list.push_back(*Receps_ipgu12_l);
	blist.push_back(*Receps_iping12_l);

	////////////////////////////////////////////////////////////////////////////////////
	// front

	list.push_back(*Receps_ipgu13);
	blist.push_back(*Receps_iping13);

	list.push_back(*Receps_ipgu14);
	blist.push_back(*Receps_iping14);

	list.push_back(*Receps_ipgu15);
	blist.push_back(*Receps_iping15);

	/////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_ipgu13_l);
	blist.push_back(*Receps_iping13_l);

	list.push_back(*Receps_ipgu14_l);
	blist.push_back(*Receps_iping14_l);

	list.push_back(*Receps_ipgu15_l);
	blist.push_back(*Receps_iping15_l);

	///////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_ipgu_1);
	blist.push_back(*Receps_iping_1);

	list.push_back(*Receps_ipgu_2);
	blist.push_back(*Receps_iping_2);

	list.push_back(*Receps_ipgu_3);
	blist.push_back(*Receps_iping_3);

	list.push_back(*Receps_ipgu_4);
	blist.push_back(*Receps_iping_4);

	////////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_gar1);
	blist.push_back(*Receps_garo1);

	list.push_back(*Receps_gar2);
	blist.push_back(*Receps_garo2);

	list.push_back(*Receps_gar3);
	blist.push_back(*Receps_garo3);

	list.push_back(*Receps_gar4);
	blist.push_back(*Receps_garo4);

	list.push_back(*Receps_gar5);
	blist.push_back(*Receps_garo5);

	list.push_back(*Receps_gar6);
	blist.push_back(*Receps_garo6);

	/////////////////////////////////////////////////////

	list.push_back(*Receps_gidong1);
	blist.push_back(*Receps_kkidung1);

	list.push_back(*Receps_gidong2);
	blist.push_back(*Receps_kkidung2);

	list.push_back(*Receps_gidong3);
	blist.push_back(*Receps_kkidung3);

	list.push_back(*Receps_gidong4);
	blist.push_back(*Receps_kkidung4);

	list.push_back(*Receps_gidong5);
	blist.push_back(*Receps_kkidung5);

	list.push_back(*Receps_gidong6);
	blist.push_back(*Receps_kkidung6);

	list.push_back(*Receps_gidong7);
	blist.push_back(*Receps_kkidung7);

	list.push_back(*Receps_gidong8);
	blist.push_back(*Receps_kkidung8);

	list.push_back(*Receps_gidong9);
	blist.push_back(*Receps_kkidung9);

	list.push_back(*Receps_gidong10);
	blist.push_back(*Receps_kkidung10);

	list.push_back(*Receps_gidong11);
	blist.push_back(*Receps_kkidung11);

	list.push_back(*Receps_gidong12);
	blist.push_back(*Receps_kkidung12);

	list.push_back(*Receps_gidong13);
	blist.push_back(*Receps_kkidung13);

	list.push_back(*Receps_gidong14);
	blist.push_back(*Receps_kkidung14);

	list.push_back(*Receps_gidong15);
	blist.push_back(*Receps_kkidung15);

	list.push_back(*Receps_gidong16);
	blist.push_back(*Receps_kkidung16);

	list.push_back(*Receps_gidong17);
	blist.push_back(*Receps_kkidung17);

	list.push_back(*Receps_gidong18);
	blist.push_back(*Receps_kkidung18);

	list.push_back(*Receps_gidong19);
	blist.push_back(*Receps_kkidung19);

	list.push_back(*Receps_gidong20);
	blist.push_back(*Receps_kkidung20);

	list.push_back(*Receps_gidong21);
	blist.push_back(*Receps_kkidung21);

	list.push_back(*Receps_gidong22);
	blist.push_back(*Receps_kkidung22);

	list.push_back(*Receps_gidong23);
	blist.push_back(*Receps_kkidung23);

	list.push_back(*Receps_gidong24);
	blist.push_back(*Receps_kkidung24);

	list.push_back(*Receps_gidong25);
	blist.push_back(*Receps_kkidung25);

	list.push_back(*Receps_gidong26);
	blist.push_back(*Receps_kkidung26);

	list.push_back(*Receps_gidong27);
	blist.push_back(*Receps_kkidung27);

	list.push_back(*Receps_gidong28);
	blist.push_back(*Receps_kkidung28);

	list.push_back(*Receps_gidong29);
	blist.push_back(*Receps_kkidung29);

	list.push_back(*Receps_gidong30);
	blist.push_back(*Receps_kkidung30);

	//////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_gidong31);
	blist.push_back(*Receps_kkidung31);

	list.push_back(*Receps_gidong32);
	blist.push_back(*Receps_kkidung32);

	list.push_back(*Receps_gidong33);
	blist.push_back(*Receps_kkidung33);

	list.push_back(*Receps_gidong34);
	blist.push_back(*Receps_kkidung34);

	list.push_back(*Receps_gidong35);
	blist.push_back(*Receps_kkidung35);

	list.push_back(*Receps_gidong36);
	blist.push_back(*Receps_kkidung36);

	list.push_back(*Receps_gidong37);
	blist.push_back(*Receps_kkidung37);

	list.push_back(*Receps_gidong38);
	blist.push_back(*Receps_kkidung38);

	list.push_back(*Receps_gidong39);
	blist.push_back(*Receps_kkidung39);

	list.push_back(*Receps_gidong40);
	blist.push_back(*Receps_kkidung40);

	list.push_back(*Receps_gidong41);
	blist.push_back(*Receps_kkidung41);

	list.push_back(*Receps_gidong42);
	blist.push_back(*Receps_kkidung42);

	list.push_back(*Receps_gidong43);
	blist.push_back(*Receps_kkidung43);

	list.push_back(*Receps_gidong44);
	blist.push_back(*Receps_kkidung44);

	list.push_back(*Receps_gidong45);
	blist.push_back(*Receps_kkidung45);

	list.push_back(*Receps_gidong46);
	blist.push_back(*Receps_kkidung46);

	list.push_back(*Receps_gidong47);
	blist.push_back(*Receps_kkidung47);

	list.push_back(*Receps_gidong48);
	blist.push_back(*Receps_kkidung48);

	list.push_back(*Receps_gidong49);
	blist.push_back(*Receps_kkidung49);

	list.push_back(*Receps_gidong50);
	blist.push_back(*Receps_kkidung50);

	list.push_back(*Receps_gidong51);
	blist.push_back(*Receps_kkidung51);

	list.push_back(*Receps_gidong52);
	blist.push_back(*Receps_kkidung52);

	list.push_back(*Receps_gidong53);
	blist.push_back(*Receps_kkidung53);

	list.push_back(*Receps_gidong54);
	blist.push_back(*Receps_kkidung54);

	list.push_back(*Receps_gidong55);
	blist.push_back(*Receps_kkidung55);

	list.push_back(*Receps_gidong56);
	blist.push_back(*Receps_kkidung56);

	list.push_back(*Receps_gidong57);
	blist.push_back(*Receps_kkidung57);

	list.push_back(*Receps_gidong58);
	blist.push_back(*Receps_kkidung58);

	list.push_back(*Receps_gidong59);
	blist.push_back(*Receps_kkidung59);

	list.push_back(*Receps_gidong60);
	blist.push_back(*Receps_kkidung60);

	/////////////////////////////////////////////////////

	list.push_back(*Receps_gidong1_1);
	blist.push_back(*Receps_kkidung1_1);

	list.push_back(*Receps_gidong2_1);
	blist.push_back(*Receps_kkidung2_1);

	list.push_back(*Receps_gidong3_1);
	blist.push_back(*Receps_kkidung3_1);

	list.push_back(*Receps_gidong4_1);
	blist.push_back(*Receps_kkidung4_1);

	list.push_back(*Receps_gidong5_1);
	blist.push_back(*Receps_kkidung5_1);

	list.push_back(*Receps_gidong6_1);
	blist.push_back(*Receps_kkidung6_1);

	list.push_back(*Receps_gidong7_1);
	blist.push_back(*Receps_kkidung7_1);

	list.push_back(*Receps_gidong8_1);
	blist.push_back(*Receps_kkidung8_1);

	list.push_back(*Receps_gidong9_1);
	blist.push_back(*Receps_kkidung9_1);

	list.push_back(*Receps_gidong10_1);
	blist.push_back(*Receps_kkidung10_1);

	list.push_back(*Receps_gidong11_1);
	blist.push_back(*Receps_kkidung11_1);

	list.push_back(*Receps_gidong12_1);
	blist.push_back(*Receps_kkidung12_1);

	list.push_back(*Receps_gidong13_1);
	blist.push_back(*Receps_kkidung13_1);

	list.push_back(*Receps_gidong14_1);
	blist.push_back(*Receps_kkidung14_1);

	list.push_back(*Receps_gidong15_1);
	blist.push_back(*Receps_kkidung15_1);

	list.push_back(*Receps_gidong16_1);
	blist.push_back(*Receps_kkidung16_1);

	list.push_back(*Receps_gidong17_1);
	blist.push_back(*Receps_kkidung17_1);

	list.push_back(*Receps_gidong18_1);
	blist.push_back(*Receps_kkidung18_1);

	list.push_back(*Receps_gidong19_1);
	blist.push_back(*Receps_kkidung19_1);

	list.push_back(*Receps_gidong20_1);
	blist.push_back(*Receps_kkidung20_1);

	list.push_back(*Receps_gidong21_1);
	blist.push_back(*Receps_kkidung21_1);

	list.push_back(*Receps_gidong22_1);
	blist.push_back(*Receps_kkidung22_1);

	list.push_back(*Receps_gidong23_1);
	blist.push_back(*Receps_kkidung23_1);

	list.push_back(*Receps_gidong24_1);
	blist.push_back(*Receps_kkidung24_1);

	list.push_back(*Receps_gidong25_1);
	blist.push_back(*Receps_kkidung25_1);

	list.push_back(*Receps_gidong26_1);
	blist.push_back(*Receps_kkidung26_1);

	list.push_back(*Receps_gidong27_1);
	blist.push_back(*Receps_kkidung27_1);

	list.push_back(*Receps_gidong28_1);
	blist.push_back(*Receps_kkidung28_1);

	list.push_back(*Receps_gidong29_1);
	blist.push_back(*Receps_kkidung29_1);

	list.push_back(*Receps_gidong30_1);
	blist.push_back(*Receps_kkidung30_1);

	//////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_gidong31_1);
	blist.push_back(*Receps_kkidung31_1);

	list.push_back(*Receps_gidong32_1);
	blist.push_back(*Receps_kkidung32_1);

	list.push_back(*Receps_gidong33_1);
	blist.push_back(*Receps_kkidung33_1);

	list.push_back(*Receps_gidong34_1);
	blist.push_back(*Receps_kkidung34_1);

	list.push_back(*Receps_gidong35_1);
	blist.push_back(*Receps_kkidung35_1);

	list.push_back(*Receps_gidong36_1);
	blist.push_back(*Receps_kkidung36_1);

	list.push_back(*Receps_gidong37_1);
	blist.push_back(*Receps_kkidung37_1);

	list.push_back(*Receps_gidong38_1);
	blist.push_back(*Receps_kkidung38_1);

	list.push_back(*Receps_gidong39_1);
	blist.push_back(*Receps_kkidung39_1);

	list.push_back(*Receps_gidong40_1);
	blist.push_back(*Receps_kkidung40_1);

	list.push_back(*Receps_gidong41_1);
	blist.push_back(*Receps_kkidung41_1);

	list.push_back(*Receps_gidong42_1);
	blist.push_back(*Receps_kkidung42_1);

	list.push_back(*Receps_gidong43_1);
	blist.push_back(*Receps_kkidung43_1);

	list.push_back(*Receps_gidong44_1);
	blist.push_back(*Receps_kkidung44_1);

	list.push_back(*Receps_gidong45_1);
	blist.push_back(*Receps_kkidung45_1);

	list.push_back(*Receps_gidong46_1);
	blist.push_back(*Receps_kkidung46_1);

	list.push_back(*Receps_gidong47_1);
	blist.push_back(*Receps_kkidung47_1);

	list.push_back(*Receps_gidong48_1);
	blist.push_back(*Receps_kkidung48_1);

	list.push_back(*Receps_gidong49_1);
	blist.push_back(*Receps_kkidung49_1);

	list.push_back(*Receps_gidong50_1);
	blist.push_back(*Receps_kkidung50_1);

	list.push_back(*Receps_gidong51_1);
	blist.push_back(*Receps_kkidung51_1);

	list.push_back(*Receps_gidong52_1);
	blist.push_back(*Receps_kkidung52_1);

	list.push_back(*Receps_gidong53_1);
	blist.push_back(*Receps_kkidung53_1);

	list.push_back(*Receps_gidong54_1);
	blist.push_back(*Receps_kkidung54_1);

	list.push_back(*Receps_gidong55_1);
	blist.push_back(*Receps_kkidung55_1);

	list.push_back(*Receps_gidong56_1);
	blist.push_back(*Receps_kkidung56_1);

	list.push_back(*Receps_gidong57_1);
	blist.push_back(*Receps_kkidung57_1);

	list.push_back(*Receps_gidong58_1);
	blist.push_back(*Receps_kkidung58_1);

	list.push_back(*Receps_gidong59_1);
	blist.push_back(*Receps_kkidung59_1);

	list.push_back(*Receps_gidong60_1);
	blist.push_back(*Receps_kkidung60_1);


}


void createObstacles2_3(vector<Object>& list, vector<BoundingBox>& blist)
{

}