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

	//바닥 및 벽생성
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
	}
	//A site의 상자 밀집 구간
	for (float x = 20.0f; x < 90.0f; x += 10.0f)
	{
		for (float z = 20.0f; z < 90.0f; z += 10.0f)
		{

			int width = rand() % 3;
			int height = rand() % 3;

			for (float dx = 0.0f; dx <= width * 1.5f+0.1f; dx += 1.5f)
			{
				for (float dz= 0.0f; dz <= width * 1.5f+0.1f; dz += 1.5f)
				{

					for (float dy = 0.0f; dy <= height * 1.5f + 0.1f; dy += 1.5f)
					{
						Object* box = (Object*)malloc(sizeof(Object));
						box->location = f3(x+dx, dy, z+dz);
						box->rotation = f3(0.0f, 0.0f, 0.0f);
						box->type = RustyMetal_Box;

						BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxbox->start = f3(x + dx - 0.75f, dy,			z + dz - 0.75f);
						boxbox->end =	f3(x + dx + 0.75f, dy + 1.5f,	z + dz + 0.75f);



						list.push_back(*box);
						blist.push_back(*boxbox);
					}

				}
			}
			setAreaHeight(height1_1, x11,z11, x - 1.0f, z - 1.0f, x + width * 1.5f + 1.0f, z + width * 1.5f + 1.0f, (height + 1) * 1.5f);



			



		}
	}

	//시작지점 뒷편 배럴
	{
	for (float x = 0.75f; x < 15.75f; x += 1.5f)
	{
		for (float z = 2.75f; z <= 5.75f; z += 3.0f)
		{
			for (float y = 0.0f; y < 3.0f; y += 2.25f)
			{
				Object* barrel = (Object*)malloc(sizeof(Object));
				barrel->location = f3(x, y, 200.0f - z);
				barrel->rotation = f3(0.0f, 0.0f, 0.0f);
				barrel->type = RustyMetal_Barrel;

				BoundingBox* boxBarrel = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxBarrel->start = f3(x - 0.75f, y, 200.0f - z - 0.75f);
				boxBarrel->end = f3(x + 0.75f, y + 2.25f, 200.0f - z + 0.75f);

				Object* barrel2 = (Object*)malloc(sizeof(Object));
				barrel2->location = f3(18.0f + x, y, 200.0f - z);
				barrel2->rotation = f3(0.0f, 0.0f, 0.0f);
				barrel2->type = RustyMetal_Barrel;

				BoundingBox* boxBarrel2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxBarrel2->start = f3(18.0f + x - 0.75f, y, 200.0f - z - 0.75f);
				boxBarrel2->end = f3(18.0f + x + 0.75f, y + 2.25f, 200.0f - z + 0.75f);

				Object* barrel3 = (Object*)malloc(sizeof(Object));
				barrel3->location = f3(50.0f - x, y, 200.0f - z);
				barrel3->rotation = f3(0.0f, 0.0f, 0.0f);
				barrel3->type = RustyMetal_Barrel;

				BoundingBox* boxBarrel3 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxBarrel3->start = f3(50.0f - x - 0.75f, y, 200.0f - z - 0.75f);
				boxBarrel3->end = f3(50.0f - x + 0.75f, y + 2.25f, 200.0f - z + 0.75f);

				list.push_back(*barrel);
				blist.push_back(*boxBarrel);
				list.push_back(*barrel2);
				blist.push_back(*boxBarrel2);
				list.push_back(*barrel3);
				blist.push_back(*boxBarrel3);
			}
		}
	}
	for (float x = 3.0f; x <= 48.0f; x += 4.0f)
	{
		Object* fence = (Object*)malloc(sizeof(Object));
		fence->location = f3(x, 0.0f, 200.0f - 9.75f);
		fence->rotation = f3(0.0f, 90.0f, 0.0f);
		fence->type = RustyFence;

		BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxFence->start = f3(x - 2.0f, 0.0f, 200.0f - 9.5f);
		boxFence->end = f3(x + 2.0f, 1.5f, 200.0f - 10.0f);

		list.push_back(*fence);
		blist.push_back(*boxFence);
	}
	for (float x = 10.0f; x < 45.0f; x += 10.0f)
	{
		Object* warningSign = (Object*)malloc(sizeof(Object));
		warningSign->location = f3(x, 0.0f, 200.0f - 8.75f);
		warningSign->rotation = f3(0.0f, 0.0f, 0.0f);
		warningSign->type = WarningSign;

		BoundingBox* boxSign = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxSign->start = f3(x - 0.5f, 0.0f, 200.0f - 8.5f);
		boxSign->end = f3(x + 0.5f, 1.5f, 200.0f - 9.0f);

		list.push_back(*warningSign);
		blist.push_back(*boxSign);

	}

	setAreaHeight(height1_1, x11, z11, 0.0f, 190.0f, 50.0f, 200.0f, 10.0f);
	}
	
	//건축폐기물 구간 양 사이드의 시멘트 포대 더미
	{
		for (float x = 4.5f; x <= 50.0f; x += 41.0f)
		{
			for (float z = 125.0f; z <= 166.0f; z += 13.0f)
			{
				for (float dx = -3.0f; dx < 3.6f; dx += 3.0f)
				{
					for (float dz = -3.0f; dz < 3.6f; dz += 3.0f)
					{
						int tp = rand() % 6;
						float tx = x + dx;
						float tz = z + dz;
						switch (tp)
						{
						case 0:
						{
							Object* wdPallet = (Object*)malloc(sizeof(Object));
							wdPallet->location = f3(tx, 0.0f, tz);
							wdPallet->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet->type = WoodenPallet;

							BoundingBox* boxPallet = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet->start = f3(tx - 1.5f, 0.0f, tz - 1.5f);
							boxPallet->end = f3(tx + 1.5f, 0.6f, tz + 1.5f);
							setAreaHeight(height1_1, x11, z11, tx - 1.5f, tz - 1.5f, tx + 1.5f, tz + 1.5f, 0.6f);

							list.push_back(*wdPallet);
							blist.push_back(*boxPallet);

							break;
						}
						case 1:
						{
							Object* wdPallet = (Object*)malloc(sizeof(Object));
							wdPallet->location = f3(tx, 0.0f, tz);
							wdPallet->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet->type = WoodenPalletLayer;

							BoundingBox* boxPallet = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet->start = f3(tx - 1.5f, 0.0f, tz - 1.5f);
							boxPallet->end = f3(tx + 1.5f, 1.65f, tz + 1.5f);
							setAreaHeight(height1_1, x11, z11, tx - 1.5f, tz - 1.5f, tx + 1.5f, tz + 1.5f, 1.65f);

							list.push_back(*wdPallet);
							blist.push_back(*boxPallet);
							break;
						}
						case 2:
						{
							Object* wdPallet = (Object*)malloc(sizeof(Object));
							wdPallet->location = f3(tx, 0.0f, tz);
							wdPallet->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet->type = CementBag1;

							BoundingBox* boxPallet = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet->start = f3(tx - 1.5f, 0.0f, tz - 1.5f);
boxPallet->end = f3(tx + 1.5f, 1.65f, tz + 1.5f);
setAreaHeight(height1_1, x11, z11, tx - 1.5f, tz - 1.5f, tx + 1.5f, tz + 1.5f, 1.65f);

list.push_back(*wdPallet);
blist.push_back(*boxPallet);
break;
						}
						case 3:
						{
							Object* wdPallet = (Object*)malloc(sizeof(Object));
							wdPallet->location = f3(tx, 0.0f, tz);
							wdPallet->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet->type = WoodenPallet;

							BoundingBox* boxPallet = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet->start = f3(tx - 1.5f, 0.0f, tz - 1.5f);
							boxPallet->end = f3(tx + 1.5f, 0.6f, tz + 1.5f);

							Object* wdPallet2 = (Object*)malloc(sizeof(Object));
							wdPallet2->location = f3(tx, 0.5f, tz);
							wdPallet2->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet2->type = CementBag1;

							BoundingBox* boxPallet2 = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet2->start = f3(tx - 1.5f, 0.5f, tz - 1.5f);
							boxPallet2->end = f3(tx + 1.5f, 2.25f, tz + 1.5f);

							setAreaHeight(height1_1, x11, z11, tx - 1.5f, tz - 1.5f, tx + 1.5f, tz + 1.5f, 2.25f);

							list.push_back(*wdPallet);
							blist.push_back(*boxPallet);
							list.push_back(*wdPallet2);
							blist.push_back(*boxPallet2);
							break;
						}
						case 4:
						{
							Object* wdPallet = (Object*)malloc(sizeof(Object));
							wdPallet->location = f3(tx, 0.0f, tz);
							wdPallet->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet->type = WoodenPalletLayer;

							BoundingBox* boxPallet = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet->start = f3(tx - 1.5f, 0.0f, tz - 1.5f);
							boxPallet->end = f3(tx + 1.5f, 1.65f, tz + 1.5f);

							Object* wdPallet2 = (Object*)malloc(sizeof(Object));
							wdPallet2->location = f3(tx, 1.55f, tz);
							wdPallet2->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet2->type = CementBag1;

							BoundingBox* boxPallet2 = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet2->start = f3(tx - 1.5f, 1.55f, tz - 1.5f);
							boxPallet2->end = f3(tx + 1.5f, 3.3f, tz + 1.5f);

							setAreaHeight(height1_1, x11, z11, tx - 1.5f, tz - 1.5f, tx + 1.5f, tz + 1.5f, 3.3f);

							list.push_back(*wdPallet);
							blist.push_back(*boxPallet);
							list.push_back(*wdPallet2);
							blist.push_back(*boxPallet2);
							break;
						}

						case 5:
						{
							Object* wdPallet = (Object*)malloc(sizeof(Object));
							wdPallet->location = f3(tx, 0.0f, tz);
							wdPallet->rotation = f3(0.0f, 0.0f, 0.0f);
							wdPallet->type = CementBag1;

							BoundingBox* boxPallet = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet->start = f3(tx - 1.5f, 0.0f, tz - 1.5f);
							boxPallet->end = f3(tx + 1.5f, 1.65f, tz + 1.5f);

							Object* wdPallet2 = (Object*)malloc(sizeof(Object));
							wdPallet2->location = f3(tx, 1.55f, tz);
							wdPallet2->rotation = f3(0.0f, 90.0f, 0.0f);
							wdPallet2->type = CementBag1;

							BoundingBox* boxPallet2 = (BoundingBox*)malloc(sizeof(BoundingBox));
							boxPallet2->start = f3(tx - 1.5f, 1.55f, tz - 1.5f);
							boxPallet2->end = f3(tx + 1.5f, 3.3f, tz + 1.5f);

							setAreaHeight(height1_1, x11, z11, tx - 1.5f, tz - 1.5f, tx + 1.5f, tz + 1.5f, 3.3f);

							list.push_back(*wdPallet);
							blist.push_back(*boxPallet);
							list.push_back(*wdPallet2);
							blist.push_back(*boxPallet2);
							break;
						}
						}
					}
				}
			}
		}
	}

	//건축폐기물 중앙 폐기물컨테이너
	{
		for (float x = 18.0f; x < 33.0f; x += 7.0f)
		{
			for (float z = 125.0f; z <= 166.0f; z += 6.5f)
			{
				Object* cont = (Object*)malloc(sizeof(Object));
				cont->location = f3(x, 0.0f, z);
				cont->rotation = f3(0.0f, 90.0f, 0.0f);
				cont->type = TrashContainer;

				BoundingBox* boxcont = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxcont->start = f3(x - 2.0f, 0.0f, z - 1.0f);
				boxcont->end = f3(x + 2.0f, 2.0f, z + 1.0f);
				setAreaHeight(height1_1, x11, z11, x - 2.0f, z - 1.0f, x + 2.0f, z + 1.0f, 2.0f);

				Object* base = (Object*)malloc(sizeof(Object));
				base->location = f3(x, 0.95f, z);
				base->rotation = f3(0.0f, 0.0f, 0.0f);
				base->type = RuinBase;

				BoundingBox* boxbase = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbase->start = f3(x - 2.0f, 0.0f, z - 1.0f);
				boxbase->end = f3(x + 2.0f, 2.0f, z + 1.0f);
				


				list.push_back(*cont);
				blist.push_back(*boxcont);
				list.push_back(*base);
				blist.push_back(*boxbase);

				for (float dx = -1.0f; dx <= 1.0f; dx += 1.0f)
				{
					int irand = rand() % 10;

					switch (irand)
					{
					case 0:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x+dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick1;
						list.push_back(*ruin);
						break;
					}

					case 1:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x+dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick2;
						list.push_back(*ruin);
						break;
					}
					case 2:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick3;
						list.push_back(*ruin);
						break;
					}
					case 3:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick4;
						list.push_back(*ruin);
						break;
					}
					case 4:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick5;
						list.push_back(*ruin);
						break;
					}
					case 5:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinCeramic1;
						list.push_back(*ruin);
						break;
					}
					case 6:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinCeramic2;
						list.push_back(*ruin);
						break;
					}
					case 7:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinMix1;
						list.push_back(*ruin);
						break;
					}
					case 8:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinWood2;
						list.push_back(*ruin);
						break;
					}
					case 9:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x + dx, 1.0f, z);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinWood1;
						list.push_back(*ruin);
						break;
					}

					}
					BoundingBox* boxruin = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxruin->start = f3(x - 2.0f, 0.0f, z - 1.0f);
					boxruin->end = f3(x + 2.0f, 2.0f, z + 1.0f);

					blist.push_back(*boxruin);
				}
			}
		}

	}
	// 폐기물 트럭 주차장 구간
	{
		for (float x = 110.0f; x <= 180.0f; x += 4.0f)
		{
			int irand = rand() % 3;
			if (irand != 0)
			{
				Object* truck = (Object*)malloc(sizeof(Object));
				truck->location = f3(x, 0.0f, 2.0f);
				truck->rotation = f3(0.0f, 0.0f, 0.0f);
				truck->type = FuelTruck;

				BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxTruck->start = f3(x - 1.5f, 0.0f, 0.5f);
				boxTruck->end = f3(x + 1.5f, 3.0f, 10.5f);
				setAreaHeight(height1_1, x11, z11, x - 1.5f, 0.5f, x + 1.5f, 10.5f, 3.0f);

				list.push_back(*truck);
				blist.push_back(*boxTruck);
			}
			else
			{
				Object* truck = (Object*)malloc(sizeof(Object));
				truck->location = f3(x - 0.25f, 0.0f, 7.75f);
				truck->rotation = f3(0.0f, 0.0f, 0.0f);
				truck->type = Chon;

				BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxTruck->start = f3(x - 0.5f, 0.0f, 7.5f);
				boxTruck->end = f3(x, 1.5f, 8.0f);
				setAreaHeight(height1_1, x11, z11, x - 0.5f, 7.5f, x, 8.0f, 1.5f);



				list.push_back(*truck);
				blist.push_back(*boxTruck);
			}
		}
		for (float x = 110.0f; x <= 150.0f; x += 11.0f)
		{
			Object* truck = (Object*)malloc(sizeof(Object));
			truck->location = f3(x, 0.0f, 48.0f);
			truck->rotation = f3(0.0f, 90.0f, 0.0f);
			truck->type = FuelTruck;

			BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxTruck->start = f3(x - 1.5f, 0.0f, 46.5f);
			boxTruck->end = f3(x + 8.5f + 10.0f, 3.0f, 49.5f);
			setAreaHeight(height1_1, x11, z11, x - 1.5f, 46.5f, x + 8.5f, 49.5f, 3.0f);

			list.push_back(*truck);
			blist.push_back(*boxTruck);
		}

		for (float x = 110.0f; x <= 160.0f; x += 8.0f)
		{
			Object* truck = (Object*)malloc(sizeof(Object));
			truck->location = f3(x, 2.0f, 25.0f);
			truck->rotation = f3(0.0f, 0.0f, 180.0f);
			truck->type = GuardRail;

			BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxTruck->start = f3(x - 4.0f, 0.0f, 24.5f);
			boxTruck->end = f3(x + 4.0f, 2.0f, 26.0f);
			setAreaHeight(height1_1, x11, z11, x - 4.0f, 24.5f, x + 4.0f, 26.0f, 2.0f);



			list.push_back(*truck);
			blist.push_back(*boxTruck);
		}
		Object* bump = (Object*)malloc(sizeof(Object));
		bump->location = f3(120.25f, 0.0f, 18.0f);
		bump->rotation = f3(0.0f, 90.0f, 0.0f);
		bump->type = SpeedBump;

		BoundingBox* boxbump = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxbump->start = f3(119.5f, 0.0f, 13.0f);
		boxbump->end = f3(121.0f, 2.0f, 23.0f);

		Object* bump2 = (Object*)malloc(sizeof(Object));
		bump2->location = f3(140.25f, 0.0f, 32.0f);
		bump2->rotation = f3(0.0f, 90.0f, 0.0f);
		bump2->type = SpeedBump;

		BoundingBox* boxbump2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxbump2->start = f3(139.5f, 0.0f, 27.0f);
		boxbump2->end = f3(141.0f, 2.0f, 37.0f);

		list.push_back(*bump);
		blist.push_back(*boxbump);
		list.push_back(*bump2);
		blist.push_back(*boxbump2);
	}

	//종이 쓰레기 구간
	{
		// 공간을 막는 종이 무더기
		for (float x = 151.5f; x < 177.0f; x += 3.0f)
		{
			int height = rand() % 2+2;
			for (int i = 0; i < height; ++i)
			{
				Object* papers = (Object*)malloc(sizeof(Object));
				papers->location = f3(x, i*2.0f, 51.0f);
				papers->rotation = f3(0.0f, 0.0f, 0.0f);
				papers->type = PaperWaste;

				BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxpap->start = f3(x - 1.5f, i*2.0f, 50.0f);
				boxpap->end = f3(x + 1.5f, (i+1)*2.0f, 52.0f);

				list.push_back(*papers);
				blist.push_back(*boxpap);
			}
			setAreaHeight(height1_1, x11, z11, x-1.5f, 50.0f, x+1.5f, 52.0f, (height+1)*2.0f);
		}

		for (float z = 101.0f; z < 128.0f; z += 2.0f)
		{
			int height = rand() % 2 + 2;
			for (int i = 0; i < height; ++i)
			{
				Object* papers = (Object*)malloc(sizeof(Object));
				papers->location = f3(101.5, i*2.0f, z);
				papers->rotation = f3(0.0f, 0.0f, 0.0f);
				papers->type = PaperWaste;

				BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxpap->start = f3(100.0f, i*2.0f, z - 1.0f);
				boxpap->end = f3(103.0f, (i+1)*2.0f, z + 1.0f);

				list.push_back(*papers);
				blist.push_back(*boxpap);
			}
			setAreaHeight(height1_1, x11, z11, 100.0f, z - 1.0f, 103.0f, z + 1.0f, (height+1)*2.0f);


		}
		for (float x = 101.5f; x < 177.0f; x += 3.0f)
		{
			int height = rand() % 2 + 2;
			for (int i = 0; i < height; ++i)
			{
				Object* papers = (Object*)malloc(sizeof(Object));
				papers->location = f3(x, i*2.0f, 129.0f);
				papers->rotation = f3(0.0f, 0.0f, 0.0f);
				papers->type = PaperWaste;

				BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxpap->start = f3(x - 1.5f, i*2.0f, 128.0f);
				boxpap->end = f3(x + 1.5f, (i+1)*2.0f, 130.0f);

				list.push_back(*papers);
				blist.push_back(*boxpap);
			}
			setAreaHeight(height1_1, x11, z11, x - 1.5f, 128.0f, x + 1.5f, 130.0f, (height+1)*2.0f);
		}
		for (float z = 51.0f; z < 128.0f; z += 2.0f)
		{
			int height = rand() % 2 + 2;
			for (int i = 0; i < height; ++i)
			{
				Object* papers = (Object*)malloc(sizeof(Object));
				papers->location = f3(178.5, i*2.0f, z);
				papers->rotation = f3(0.0f, 0.0f, 0.0f);
				papers->type = PaperWaste;

				BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxpap->start = f3(177.0f, i*2.0f, z - 1.0f);
				boxpap->end = f3(180.0f, (i+1)*2.0f, z + 1.0f);

				list.push_back(*papers);
				blist.push_back(*boxpap);
			}

			setAreaHeight(height1_1, x11, z11, 177.0f, z - 1.0f, 180.0f, z + 1.0f, (height+1)+2.0f);
		}


		// 무더기와 벽 사이 공간의 상자종이
		for (float z = 50.0f; z <= 130.0f; z += 5.0f)
		{
			for (float x = 182.0f; x < 200.0f; x += 16.0f)
			{

				int irand = rand() % 4;

				switch (irand)
				{
				case 0:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard1;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 0.5f, 0.0f, z-0.5f);
					boxpap->end = f3(x + 0.5f, 0.1f, z+0.5f);
					setAreaHeight(height1_1, x11, z11, x - 0.5f, z - 0.5f, x + 0.5f, z + 0.5f, 0.1f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				case 1:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard2;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 1.0f, 0.0f, z - 1.0f);
					boxpap->end = f3(x + 1.0f, 0.75f, z + 1.0f);
					setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 0.75f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				case 2:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard3;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 1.0f, 0.0f, z - 1.0f);
					boxpap->end = f3(x + 1.0f, 0.75f, z + 1.0f);
					setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 0.75f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				case 3:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard4;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 1.5f, 0.0f, z - 1.5f);
					boxpap->end = f3(x + 1.5f, 0.75f, z + 1.5f);
					setAreaHeight(height1_1, x11, z11, x - 1.5f, z - 1.5f, x + 1.5f, z + 1.5f, 0.75f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				}

			}
		}

		for (float x = 105.0f; x <= 180.0f; x += 5.0f)
		{
			for (float z = 132.0f; z <= 150.0f; z += 16.0f)
			{
				int irand = rand() % 4;

				switch (irand)
				{
				case 0:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard1;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 0.5f, 0.0f, z - 0.5f);
					boxpap->end = f3(x + 0.5f, 0.1f, z + 0.5f);
					setAreaHeight(height1_1, x11, z11, x - 0.5f, z - 0.5f, x + 0.5f, z + 0.5f, 0.1f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				case 1:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard2;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 1.0f, 0.0f, z - 1.0f);
					boxpap->end = f3(x + 1.0f, 0.75f, z + 1.0f);
					setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 0.75f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				case 2:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard3;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 1.0f, 0.0f, z - 1.0f);
					boxpap->end = f3(x + 1.0f, 0.75f, z + 1.0f);
					setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 0.75f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				case 3:
				{
					Object* papers = (Object*)malloc(sizeof(Object));
					papers->location = f3(x, 0.0f, z);
					papers->rotation = f3(0.0f, 0.0f, 0.0f);
					papers->type = Cardboard4;

					BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxpap->start = f3(x - 1.5f, 0.0f, z - 1.5f);
					boxpap->end = f3(x + 1.5f, 0.75f, z + 1.5f);
					setAreaHeight(height1_1, x11, z11, x - 1.5f, z - 1.5f, x + 1.5f, z + 1.5f, 0.75f);

					list.push_back(*papers);
					blist.push_back(*boxpap);
					break;
				}
				}
			}
		}

		// 우상단 구석 여분 공간의 쓰레기수거함
		for (float x = 186.0f; x < 195.0f; x += 4.0f)
		{
			for (float z = 135.0f; z < 150.0f; z += 10.0f)
			{
				
				Object* papers = (Object*)malloc(sizeof(Object));
				papers->location = f3(x, 0.0f, z);
				papers->rotation = f3(0.0f, 0.0f, 0.0f);
				papers->type = TrashContainer;

				BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxpap->start = f3(x - 1.0f, 0.0f, z-2.0f);
				boxpap->end = f3(x + 1.0f, 2.0f, z+2.0f);

				setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 2.0f, x + 1.0f, z + 2.0f, 2.0f);

				list.push_back(*papers);
				blist.push_back(*boxpap);

				for (float dx = -1.0f; dx <= 1.0f; dx += 1.0f)
				{
					int irand = rand() % 10;

					switch (irand)
					{
					case 0:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick1;
						list.push_back(*ruin);
						break;
					}

					case 1:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick2;
						list.push_back(*ruin);
						break;
					}
					case 2:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick3;
						list.push_back(*ruin);
						break;
					}
					case 3:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick4;
						list.push_back(*ruin);
						break;
					}
					case 4:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinBrick5;
						list.push_back(*ruin);
						break;
					}
					case 5:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinCeramic1;
						list.push_back(*ruin);
						break;
					}
					case 6:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinCeramic2;
						list.push_back(*ruin);
						break;
					}
					case 7:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinMix1;
						list.push_back(*ruin);
						break;
					}
					case 8:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinWood2;
						list.push_back(*ruin);
						break;
					}
					case 9:
					{
						Object* ruin = (Object*)malloc(sizeof(Object));
						ruin->location = f3(x, 1.0f, z + dx);
						ruin->rotation = f3(0.0f, 90.0f, 0.0f);
						ruin->type = RuinWood1;
						list.push_back(*ruin);
						break;
					}

					}
					BoundingBox* boxruin = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxruin->start = f3(x - 1.0f, 0.0f, z - 2.0f);
					boxruin->end = f3(x + 1.0f, 2.0f, z + 2.0f);

					blist.push_back(*boxruin);
				}
			}




		}

	}


	// 일반쓰레기 수거함 구간.
	{
		//울타리로 막혀있는 좌하단 구역. 박스 밀집 배치.
		for (float x = 52.0f; x <= 70.0f; x += 4.0f)
		{
			for (float y = 0.0f; y < 7.0f; y += 1.5f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, y, 140.25);
				fence->rotation = f3(0.0f, 90.0f, 0.0f);
				fence->type = RustyFence;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(x - 2.0f, y, 140.0f);
				boxFence->end = f3(x + 2.0f, y+1.5f, 140.5f);

				setAreaHeight(height1_1, x11, z11, x - 2.0f, 140.0f, x + 2.0f, 140.5f, 6.0f);

				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		for (float z = 102.0f; z < 140.0f; z += 4.0f)
		{
			for (float y = 0.0f; y < 7.0f; y += 1.5f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(70.25f, y, z);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = RustyFence;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(70.0f, y, z - 2.0f);
				boxFence->end = f3(70.5f, y+1.5f, z + 2.0f);

				setAreaHeight(height1_1, x11, z11, 70.0f, z - 2.0f, 70.5f, z + 2.0f, 6.0f);

				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		for (float z = 100.75f; z < 139.0f; z += 1.5f)
		{
			for (float y = 0.0f; y < 5.0f; y += 1.5f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(67.25, y, z);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = RustyMetal_Box;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(66.5f, y, z-0.75f);
				boxFence->end = f3(68.0f, y+1.5f, z+0.75f);

				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		for (float x = 50.75f; x < 66.0f; x += 1.5f)
		{
			for (float y = 0.0f; y < 5.0f; y += 1.5f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, y, 138.25f);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = RustyMetal_Box;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(x-0.75f, y, 137.5f);
				boxFence->end = f3(x+0.75f, y + 1.5f, 139.0f);


				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		//울타리로 막혀있는 좌상단 구역. 배럴 밀집 배치.
		for (float x = 52.0f; x <= 70.0f; x += 4.0f)
		{
			for (float y = 0.0f; y < 7.0f; y += 1.5f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, y, 160.25);
				fence->rotation = f3(0.0f, 90.0f, 0.0f);
				fence->type = RustyFence;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(x - 2.0f, y, 160.0f);
				boxFence->end = f3(x + 2.0f, y + 1.5f, 160.5f);

				setAreaHeight(height1_1, x11, z11, x - 2.0f, 140.0f, x + 2.0f, 140.5f, 6.0f);

				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		for (float z = 162.0f; z < 200.0f; z += 4.0f)
		{
			for (float y = 0.0f; y < 7.0f; y += 1.5f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(70.25f, y, z);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = RustyFence;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(70.0f, y, z - 2.0f);
				boxFence->end = f3(70.5f, y + 1.5f, z + 2.0f);

				setAreaHeight(height1_1, x11, z11, 70.0f, z - 2.0f, 70.5f, z + 2.0f, 6.0f);

				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		for (float z = 199.25f; z > 161.0f; z -= 1.5f)
		{
			for (float y = 0.0f; y < 5.0f; y += 2.25f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(67.25, y, z);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = RustyMetal_Barrel;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(66.5f, y, z - 0.75f);
				boxFence->end = f3(68.0f, y + 2.25f, z + 0.75f);

				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		for (float x = 50.75f; x < 66.0f; x += 1.5f)
		{
			for (float y = 0.0f; y < 5.0f; y += 2.25f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, y, 161.75f);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = RustyMetal_Barrel;

				BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxFence->start = f3(x - 0.75f, y, 161.0f);
				boxFence->end = f3(x + 0.75f, y + 2.25f, 162.5f);


				list.push_back(*fence);
				blist.push_back(*boxFence);
			}
		}

		// 펜스 틈 사이 트럭
		for (float z = 145.0f; z < 160.0f; z += 5.0f)
		{
			Object* truck = (Object*)malloc(sizeof(Object));
			truck->location = f3(56.0f, 0.2f, z);
			truck->rotation = f3(0.0f, 90.0f, 0.0f);
			truck->type = Truck2Body;

			BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxTruck->start = f3(51.0f, 0.0f, z-1.5f);
			boxTruck->end = f3(61.0f, 3.0f, z+1.5f);


			Object* truck2 = (Object*)malloc(sizeof(Object));
			truck2->location = f3(56.0f-0.7f, 0.0f, z);
			truck2->rotation = f3(0.0f, 90.0f, 0.0f);
			truck2->type = Truck2Wheel;

			BoundingBox* boxTruck2 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxTruck2->start = f3(51.0f, 0.0f, z-1.5f);
			boxTruck2->end = f3(61.0f, 3.0f, z+1.5f);



			setAreaHeight(height1_1, x11, z11, 51.0f, z-1.5f, 61.0f, z+1.5f, 3.0f);

			list.push_back(*truck);
			blist.push_back(*boxTruck);
			list.push_back(*truck2);
			blist.push_back(*boxTruck2);
		}
		//중앙부
		for (float z = 130.0f; z < 180.0f; z += 20.0f)
		{
			for (float x = 82.5f; x < 100.0f; x += 7.5f)
			{
				int irand = rand() % 2;
				if (irand)
				{
					Object* truck = (Object*)malloc(sizeof(Object));
					truck->location = f3(x, 0.2f, z);
					truck->rotation = f3(0.0f, 0.0f, 0.0f);
					truck->type = Truck2Body;

					BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxTruck->start = f3(x-1.5f, 0.0f, z-5.0f);
					boxTruck->end = f3(x+1.5f, 3.0f, z+5.0f);


					Object* truck2 = (Object*)malloc(sizeof(Object));
					truck2->location = f3(x, 0.0f, z - 0.7f);
					truck2->rotation = f3(0.0f, 0.0f, 0.0f);
					truck2->type = Truck2Wheel;

					BoundingBox* boxTruck2 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxTruck2->start = f3(x-1.5f, 0.0f, z-5.0f);
					boxTruck2->end = f3(x+1.5f, 3.0f, z+5.0f);

					setAreaHeight(height1_1, x11, z11, x-1.5f, z-5.0f, x+1.5f, z+5.0f, 3.0f);

					list.push_back(*truck);
					blist.push_back(*boxTruck);
					list.push_back(*truck2);
					blist.push_back(*boxTruck2);
				}
				else
				{
					Object* truck = (Object*)malloc(sizeof(Object));
					truck->location = f3(x - 0.25f, 0.0f, z-0.25f);
					truck->rotation = f3(0.0f, 0.0f, 0.0f);
					truck->type = Chon;

					BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxTruck->start = f3(x - 0.5f, 0.0f, z-0.5f);
					boxTruck->end = f3(x, 1.5f, z);
					setAreaHeight(height1_1, x11, z11, x - 0.5f, z-0.5f, x, z, 1.5f);

					list.push_back(*truck);
					blist.push_back(*boxTruck);
				}
			}
		}

		
		// 중상단 비닐봉투 밀집지역
		
			for (float x = 92.0f; x < 140.0f; x += 1.5f)
			{
				for (int z = 197.0f; z < 199.0f; z += 1.0f)
				{
				int irand = rand() % 3;
				if (irand == 0)
				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(x, 0.0f, z);
					fence->rotation = f3(0.0f, 0.0f, 0.0f);
					fence->type = Envelop1;

					BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxFence->start = f3(x - 0.5f, 0.0f, z - 0.5f);
					boxFence->end = f3(x + 0.5f, 1.0f, z + 0.5f);

					setAreaHeight(height1_1, x11, z11, x - 0.5f, z - 0.5f, x + 0.5f, z + 0.5f, 0.75f);

					list.push_back(*fence);
					blist.push_back(*boxFence);
				}
				else if (irand == 1)
				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(x, 0.0f, z);
					fence->rotation = f3(0.0f, 0.0f, 0.0f);
					fence->type = Envelop2;

					BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxFence->start = f3(x - 0.5f, 0.0f, z - 0.5f);
					boxFence->end = f3(x + 0.5f, 1.0f, z + 0.5f);

					setAreaHeight(height1_1, x11, z11, x - 0.5f, z - 0.5f, x + 0.5f, z + 0.5f, 0.75f);

					list.push_back(*fence);
					blist.push_back(*boxFence);
				}
				else if (irand == 2)
				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(x, 0.0f, z);
					fence->rotation = f3(0.0f, 0.0f, 0.0f);
					fence->type = Envelop3;

					BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxFence->start = f3(x - 0.5f, 0.0f, z - 0.5f);
					boxFence->end = f3(x + 0.5f, 1.0f, z + 0.5f);

					setAreaHeight(height1_1, x11, z11, x - 0.5f, z - 0.5f, x + 0.5f, z + 0.5f, 0.75f);

					list.push_back(*fence);
					blist.push_back(*boxFence);
				}
				}
			}

			for (float x = 95.0f; x < 140.0f; x += 2.5f)
			{
				int irand = rand() % 3;
				if (irand==0)
				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(x, 0.0f, 195.0f);
					fence->rotation = f3(0.0f, 180.0f, 0.0f);
					fence->type = RustyTrashCan;

					BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxFence->start = f3(x - 0.5f, 0.0f, 194.5f);
					boxFence->end = f3(x + 0.5f, 1.5f, 195.5f);

					setAreaHeight(height1_1, x11, z11, x - 0.5f, 194.5f, x + 0.5f, 195.5f, 1.5f);

					list.push_back(*fence);
					blist.push_back(*boxFence);
				}
				else if(irand==1)
				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(x, 0.0f, 195.0f);
					fence->rotation = f3(0.0f, 180.0f, 0.0f);
					fence->type = FoodBin;

					BoundingBox* boxFence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxFence->start = f3(x - 0.5f, 0.0f, 194.5f);
					boxFence->end = f3(x + 0.5f, 1.5f, 195.5f);

					setAreaHeight(height1_1, x11, z11, x - 0.5f, 194.5f, x + 0.5f, 195.5f, 1.5f);

					list.push_back(*fence);
					blist.push_back(*boxFence);
				}

			}





	}


	//제어함 구간

	{
		// 중앙부 배럴 박스
		for (float x = 160.0f; x < 170.0f; x += 1.5f)
		{
			for (float z = 160.0f; z < 170.0f; z += 1.5f)
			{
				for(float y=0.0f; y<4.0f;y+=1.5f)
				{
					if (x == 160.0f || x == 169.0f || z == 160.0f || z == 169.0f)
					{
						Object* box = (Object*)malloc(sizeof(Object));
						box->location = f3(x, y, z);
						box->rotation = f3(0.0f, 0.0f, 0.0f);
						box->type = RustyMetal_Box;

						BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxbox->start = f3(x - 0.75f, y, z - 0.75f);
						boxbox->end = f3(x + 0.75f, y + 1.5f, z + 0.75f);

						list.push_back(*box);
						blist.push_back(*boxbox);
					}
				}
				setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 4.5f);
			}
		}

		for (float x = 180.0f; x < 190.0f; x += 1.5f)
		{
			for (float z = 180.0f; z < 190.0f; z += 1.5f)
			{
				for (float y = 0.0f; y < 4.0f; y += 1.5f)
				{
					if (x == 180.0f || x == 189.0f || z == 180.0f || z == 189.0f)
					{
						Object* box = (Object*)malloc(sizeof(Object));
						box->location = f3(x, y, z);
						box->rotation = f3(0.0f, 0.0f, 0.0f);
						box->type = RustyMetal_Box;

						BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxbox->start = f3(x - 0.75f, y, z - 0.75f);
						boxbox->end = f3(x + 0.75f, y + 1.5f, z + 0.75f);
						list.push_back(*box);
						blist.push_back(*boxbox);
					}
				}
				setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 4.5f);
			}
		}

		for (float x = 160.0f; x < 170.0f; x += 1.5f)
		{
			for (float z = 180.0f; z < 190.0f; z += 1.5f)
			{
				for (float y = 0.0f; y < 4.0f; y += 2.25f)
				{
					if (x == 160.0f || x == 169.0f || z == 180.0f || z == 189.0f)
					{
						Object* box = (Object*)malloc(sizeof(Object));
						box->location = f3(x, y, z);
						box->rotation = f3(0.0f, 0.0f, 0.0f);
						box->type = RustyMetal_Barrel;

						BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxbox->start = f3(x - 0.75f, y, z - 0.75f);
						boxbox->end = f3(x + 0.75f, y + 2.25f, z + 0.75f);
						list.push_back(*box);
						blist.push_back(*boxbox);
					}
				}
				setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 4.5f);
			}
		}

		for (float x = 180.0f; x < 190.0f; x += 1.5f)
		{
			for (float z = 160.0f; z < 170.0f; z += 1.5f)
			{
				for (float y = 0.0f; y < 4.0f; y += 2.25f)
				{
					if (x == 180.0f || x == 189.0f || z == 160.0f || z == 169.0f)
					{
						Object* box = (Object*)malloc(sizeof(Object));
						box->location = f3(x, y, z);
						box->rotation = f3(0.0f, 0.0f, 0.0f);
						box->type = RustyMetal_Barrel;

						BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxbox->start = f3(x - 0.75f, y, z - 0.75f);
						boxbox->end = f3(x + 0.75f, y + 2.25f, z + 0.75f);
						list.push_back(*box);
						blist.push_back(*boxbox);
					}
				}
				setAreaHeight(height1_1, x11, z11, x - 1.0f, z - 1.0f, x + 1.0f, z + 1.0f, 4.5f);
			}
		}

		//양 사이드 제어기기

		for (float x = 155.0f; x < 195.0f; x += 5.0f)
		{
			for (float z = 150.25f; z < 200.0f; z += 49.5f)
			{
				int r = rand() % 2;
				for(float dx= -r; dx<r+0.1f;dx+=2.0f)
				{
					int r2 = rand() % 3;
					if (r2 == 0)
					{
						Object* cont1 = (Object*)malloc(sizeof(Object));
						cont1->location = f3(x+dx, 0.0f, z);
						cont1->rotation = f3(0.0f, 90.0f, 0.0f);
						if (z == 150.25f)
						{
							cont1->rotation = f3(0.0f, 270.0f, 0.0f);
						}
						cont1->type = Controller1;

						BoundingBox* boxCont1 = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxCont1->start = f3(x+dx-1.0f, 0.0f, z-0.5f);
						boxCont1->end = f3(x+dx+1.0f, 1.75f, z+0.5f);

						setAreaHeight(height1_1, x11, z11, x+dx-1.0f, z-0.5f, x+dx+1.0f, z+0.5f, 1.75f);

						list.push_back(*cont1);
						blist.push_back(*boxCont1);
					}
					else if (r2 == 1)
					{
						Object* cont1 = (Object*)malloc(sizeof(Object));
						cont1->location = f3(x + dx, 1.0f, z);
						cont1->rotation = f3(0.0f, 90.0f, 0.0f);
						if (z == 150.25f)
						{
							cont1->rotation = f3(0.0f, 270.0f, 0.0f);
						}
						cont1->type = Controller2;

						BoundingBox* boxCont1 = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxCont1->start = f3(x + dx - 0.5f, 1.0f, z - 0.5f);
						boxCont1->end = f3(x + dx + 0.5f, 1.85f, z + 0.5f);

						setAreaHeight(height1_1, x11, z11, x + dx - 0.5f, z - 0.5f, x + dx + 0.5f, z + 0.5f, 2.85f);
						list.push_back(*cont1);
						blist.push_back(*boxCont1);
					}
					else if (r2 == 2)
					{
						Object* cont1 = (Object*)malloc(sizeof(Object));
						cont1->location = f3(x + dx, 1.0f, z);
						cont1->rotation = f3(0.0f, 90.0f, 0.0f);
						if (z == 150.25f)
						{
							cont1->rotation = f3(0.0f, 270.0f, 0.0f);
						}
						cont1->type = Controller4;

						BoundingBox* boxCont1 = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxCont1->start = f3(x + dx - 0.5f, 1.0f, z - 0.5f);
						boxCont1->end = f3(x + dx + 0.5f, 1.9f, z + 0.5f);

						setAreaHeight(height1_1, x11, z11, x + dx - 0.5f, z - 0.5f, x + dx + 0.5f, z + 0.5f, 2.9f);
						list.push_back(*cont1);
						blist.push_back(*boxCont1);
					}
				}
			}
		}

		//출구 앞 레버
		Object* handle = (Object*)malloc(sizeof(Object));
		handle->location = f3(199.0f, 0.2f, 199.0f);
		handle->rotation = f3(0.0f, 0.0f, 0.0f);
		handle->type = LeverHandle;

		BoundingBox* boxhandle = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhandle->start = f3(198.5f, 0.0f, 198.5f);
		boxhandle->end = f3(199.5f, 2.75f, 199.5f);

		Object* body = (Object*)malloc(sizeof(Object));
		body->location = f3(199.0f, 0.0f, 199.0f);
		body->rotation = f3(0.0f, 0.0f, 0.0f);
		body->type = LeverBody;

		BoundingBox* boxbody = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxbody->start = f3(198.5f, 0.0f, 198.5f);
		boxbody->end = f3(199.5f, 2.75f, 199.5f);

		setAreaHeight(height1_1, x11, z11, 198.5f, 198.5f, 199.5f, 199.5f, 2.75f);

		list.push_back(*handle);
		blist.push_back(*boxhandle);
		list.push_back(*body);
		blist.push_back(*boxbody);
	}

	//기둥
	{
		Object* pillar = (Object*)malloc(sizeof(Object));
		pillar->location = f3(24.0f, 0.0f, 149.0f);
		pillar->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar->type = Pillar;

		BoundingBox* boxpillar = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar->start = f3(24.0f, 0.0f, 149.0f);
		boxpillar->end = f3(26.0f, 10.0f, 151.0f);

		setAreaHeight(height1_1, x11, z11, 24.0f, 149.0f, 26.0f, 151.0f, 10.0f);

		Object* pillar2 = (Object*)malloc(sizeof(Object));
		pillar2->location = f3(24.0f, 0.0f, 74.0f);
		pillar2->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar2->type = Pillar;

		BoundingBox* boxpillar2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar2->start = f3(24.0f, 0.0f, 74.0f);
		boxpillar2->end = f3(26.0f, 10.0f, 76.0f);

		setAreaHeight(height1_1, x11, z11, 24.0f, 74.0f, 26.0f, 76.0f, 10.0f);

		Object* pillar3 = (Object*)malloc(sizeof(Object));
		pillar3->location = f3(24.0f, 0.0f, 24.0f);
		pillar3->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar3->type = Pillar;

		BoundingBox* boxpillar3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar3->start = f3(24.0f, 0.0f, 24.0f);
		boxpillar3->end = f3(26.0f, 10.0f, 26.0f);

		setAreaHeight(height1_1, x11, z11, 24.0f, 24.0f, 26.0f, 26.0f, 10.0f);


		Object* pillar4 = (Object*)malloc(sizeof(Object));
		pillar4->location = f3(74.0f, 0.0f, 24.0f);
		pillar4->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar4->type = Pillar;

		BoundingBox* boxpillar4 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar4->start = f3(74.0f, 0.0f, 24.0f);
		boxpillar4->end = f3(76.0f, 10.0f, 26.0f);

		setAreaHeight(height1_1, x11, z11, 74.0f, 24.0f, 76.0f, 26.0f, 10.0f);

		Object* pillar5 = (Object*)malloc(sizeof(Object));
		pillar5->location = f3(74.0f, 0.0f, 74.0f);
		pillar5->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar5->type = Pillar;

		BoundingBox* boxpillar5 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar5->start = f3(74.0f, 0.0f, 74.0f);
		boxpillar5->end = f3(76.0f, 10.0f, 76.0f);

		setAreaHeight(height1_1, x11, z11, 74.0f, 74.0f, 76.0f, 76.0f, 10.0f);

		Object* pillar6 = (Object*)malloc(sizeof(Object));
		pillar6->location = f3(190.0f, 0.0f, 8.0f);
		pillar6->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar6->type = Pillar;

		BoundingBox* boxpillar6 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar6->start = f3(190.0f, 0.0f, 8.0f);
		boxpillar6->end = f3(192.0f, 10.0f, 10.0f);

		setAreaHeight(height1_1, x11, z11, 190.0f, 8.0f, 192.0f, 10.0f, 10.0f);

		Object* pillar7 = (Object*)malloc(sizeof(Object));
		pillar7->location = f3(149.0f, 0.0f, 84.0f);
		pillar7->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar7->type = Pillar;

		BoundingBox* boxpillar7 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar7->start = f3(149.0f, 0.0f, 84.0f);
		boxpillar7->end = f3(151.0f, 10.0f, 86.0f);

		setAreaHeight(height1_1, x11, z11, 149.0f, 84.0f, 151.0f, 86.0f, 10.0f);

		Object* pillar8 = (Object*)malloc(sizeof(Object));
		pillar8->location = f3(149.0f, 0.0f, 139.0f);
		pillar8->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar8->type = Pillar;

		BoundingBox* boxpillar8 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar8->start = f3(149.0f, 0.0f, 139.0f);
		boxpillar8->end = f3(151.0f, 10.0f, 141.0f);

		setAreaHeight(height1_1, x11, z11, 149.0f, 139.0f, 151.0f, 141.0f, 10.0f);


		Object* pillar9 = (Object*)malloc(sizeof(Object));
		pillar9->location = f3(124.0f, 0.0f, 79.0f);
		pillar9->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar9->type = Pillar;

		BoundingBox* boxpillar9 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar9->start = f3(124.0f, 0.0f, 79.0f);
		boxpillar9->end = f3(126.0f, 10.0f, 81.0f);

		setAreaHeight(height1_1, x11, z11, 124.0f, 79.0f, 126.0f, 81.0f, 10.0f);

		Object* pillar0 = (Object*)malloc(sizeof(Object));
		pillar0->location = f3(174.0f, 0.0f, 174.0f);
		pillar0->rotation = f3(0.0f, 0.0f, 0.0f);
		pillar0->type = Pillar;

		BoundingBox* boxpillar0 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpillar0->start = f3(174.0f, 0.0f, 174.0f);
		boxpillar0->end = f3(176.0f, 10.0f, 176.0f);

		setAreaHeight(height1_1, x11, z11, 174.0f, 174.0f, 176.0f, 176.0f, 10.0f);


		list.push_back(*pillar2);
		blist.push_back(*boxpillar2);
		list.push_back(*pillar3);
		blist.push_back(*boxpillar3);
		list.push_back(*pillar4);
		blist.push_back(*boxpillar4);
		list.push_back(*pillar5);
		blist.push_back(*boxpillar5);

		list.push_back(*pillar6);
		blist.push_back(*boxpillar6);
		list.push_back(*pillar7);
		blist.push_back(*boxpillar7);
		list.push_back(*pillar8);
		blist.push_back(*boxpillar8);
		list.push_back(*pillar9);
		blist.push_back(*boxpillar9);
		list.push_back(*pillar0);
		blist.push_back(*boxpillar0);
	}

	/*
	//트럭2실험
	{
		Object* truck = (Object*)malloc(sizeof(Object));
		truck->location = f3(20.0f, 0.2f, 160.0f);
		truck->rotation = f3(0.0f, 0.0f, 0.0f);
		truck->type = Truck2Body;

		BoundingBox* boxTruck = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxTruck->start = f3(18.5f, 0.0f, 155.0f);
		boxTruck->end = f3(21.5f, 3.0f, 165.0f);


		Object* truck2 = (Object*)malloc(sizeof(Object));
		truck2->location = f3(20.0f, 0.0f, 160.0f - 0.7f);
		truck2->rotation = f3(0.0f, 0.0f, 0.0f);
		truck2->type = Truck2Wheel;

		BoundingBox* boxTruck2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxTruck2->start = f3(18.5f, 0.0f, 155.0f);
		boxTruck2->end = f3(21.5f, 3.0f, 165.0f);



		setAreaHeight(height1_1, x11, z11, 18.5f, 155.0f, 21.5f, 165.0f, 3.0f);

		list.push_back(*truck);
		blist.push_back(*boxTruck);
		list.push_back(*truck2);
		blist.push_back(*boxTruck2);
	}
	//박스종이 실험
	{
		Object* cardboard1 = (Object*)malloc(sizeof(Object));
		cardboard1->location = f3(15.0f, 0.0f, 160.0f);
		cardboard1->rotation = f3(0.0f, 0.0f, 0.0f);
		cardboard1->type = Cardboard1;

		BoundingBox* boxBoard1 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxBoard1->start = f3(14.5f, 0.0f, 159.5f);
		boxBoard1->end = f3(15.5f, 0.1f, 161.5f);

		setAreaHeight(height1_1, x11, z11, 14.5f, 159.5f, 15.5f, 161.5f, 0.1f);

		Object* cardboard2 = (Object*)malloc(sizeof(Object));
		cardboard2->location = f3(13.0f, 0.0f, 160.0f);
		cardboard2->rotation = f3(0.0f, 0.0f, 0.0f);
		cardboard2->type = Cardboard2;

		BoundingBox* boxBoard2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxBoard2->start = f3(12.0f, 0.0f, 159.0f);
		boxBoard2->end = f3(14.0f, 0.75f, 161.0f);

		setAreaHeight(height1_1, x11, z11, 12.0f, 159.0f, 14.0f, 161.0f, 0.75f);

		Object* cardboard3 = (Object*)malloc(sizeof(Object));
		cardboard3->location = f3(11.0f, 0.0f, 160.0f);
		cardboard3->rotation = f3(0.0f, 0.0f, 0.0f);
		cardboard3->type = Cardboard3;

		BoundingBox* boxBoard3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxBoard3->start = f3(10.0f, 0.0f, 159.0f);
		boxBoard3->end = f3(12.0f, 0.9f, 161.0f);

		setAreaHeight(height1_1, x11, z11, 10.0f, 159.0f, 12.0f, 161.0f, 0.75f);

		Object* cardboard4 = (Object*)malloc(sizeof(Object));
		cardboard4->location = f3(8.0f, 0.0f, 160.0f);
		cardboard4->rotation = f3(0.0f, 0.0f, 0.0f);
		cardboard4->type = Cardboard4;

		BoundingBox* boxBoard4 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxBoard4->start = f3(6.5f, 0.0f, 158.5f);
		boxBoard4->end = f3(9.5f, 1.0f, 161.5f);

		setAreaHeight(height1_1, x11, z11, 6.5f, 158.5f, 9.5f, 161.5f, 0.75f);

		list.push_back(*cardboard1);
		blist.push_back(*boxBoard1);
		list.push_back(*cardboard2);
		blist.push_back(*boxBoard2);
		list.push_back(*cardboard3);
		blist.push_back(*boxBoard3);
		list.push_back(*cardboard4);
		blist.push_back(*boxBoard4);
	}

	//제어판 테스트
	{
		Object* cont1 = (Object*)malloc(sizeof(Object));
		cont1->location = f3(25.25f, 0.0f, 160.25f);
		cont1->rotation = f3(0.0f, 0.0f, 0.0f);
		cont1->type = Controller1;

		BoundingBox* boxCont1 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxCont1->start = f3(25.0f, 0.0f, 159.5f);
		boxCont1->end = f3(25.5f, 1.75f, 161.0f);

		setAreaHeight(height1_1, x11, z11, 25.0f, 159.5f, 25.5f, 161.0f, 1.75f);

		Object* cont2 = (Object*)malloc(sizeof(Object));
		cont2->location = f3(24.25f, 0.0f, 160.25f);
		cont2->rotation = f3(0.0f, 0.0f, 0.0f);
		cont2->type = Controller2;

		BoundingBox* boxCont2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxCont2->start = f3(24.0f, 0.0f, 160.0f);
		boxCont2->end = f3(24.5f, 0.85f, 160.5f);

		setAreaHeight(height1_1, x11, z11, 24.0f, 160.0f, 24.5f, 160.5f, 0.85f);

		Object* cont3 = (Object*)malloc(sizeof(Object));
		cont3->location = f3(23.25f, 0.0f, 160.0f);
		cont3->rotation = f3(0.0f, 0.0f, 0.0f);
		cont3->type = Controller4;

		BoundingBox* boxCont3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxCont3->start = f3(23.0f, 0.0f, 159.5f);
		boxCont3->end = f3(23.5f, 0.9f, 160.5f);

		setAreaHeight(height1_1, x11, z11, 23.0f, 159.5f, 23.5f, 160.5f, 0.9f);

		list.push_back(*cont1);
		blist.push_back(*boxCont1);
		list.push_back(*cont2);
		blist.push_back(*boxCont2);
		list.push_back(*cont3);
		blist.push_back(*boxCont3);

	}

	//lever test
	{
		Object* handle = (Object*)malloc(sizeof(Object));
		handle->location = f3(25.25f, 0.2f, 150.0f);
		handle->rotation = f3(0.0f, 0.0f, 0.0f);
		handle->type = LeverHandle;

		BoundingBox* boxhandle = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhandle->start = f3(25.0f, 0.0f, 149.5f);
		boxhandle->end = f3(25.5f, 2.75f, 150.5f);

		Object* body = (Object*)malloc(sizeof(Object));
		body->location = f3(25.25f, 0.0f, 150.0f);
		body->rotation = f3(0.0f, 0.0f, 0.0f);
		body->type = LeverBody;

		BoundingBox* boxbody = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxbody->start = f3(25.0f, 0.0f, 149.5f);
		boxbody->end = f3(25.5f, 2.75f, 150.5f);

		setAreaHeight(height1_1, x11, z11, 25.0f, 149.5f, 25.5f, 150.5f, 2.75f);

		list.push_back(*handle);
		blist.push_back(*boxhandle);
		list.push_back(*body);
		blist.push_back(*boxbody);
	}
	//papers test
	{
		Object* papers = (Object*)malloc(sizeof(Object));
		papers->location = f3(20.0f, 0.0f, 150.0f);
		papers->rotation = f3(0.0f, 0.0f, 0.0f);
		papers->type = PaperWaste;

		BoundingBox* boxpap = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxpap->start = f3(18.5f, 0.0f, 149.0f);
		boxpap->end = f3(21.5f, 2.0f, 151.0f);

		setAreaHeight(height1_1, x11, z11, 18.5f, 149.0f, 21.5f, 151.0f, 2.0f);

		list.push_back(*papers);
		blist.push_back(*boxpap);
	}
	*/

	/*
	//피자박스, 쓰레기 컨테이너, 과속방지턱 실험
	{
		Object* pizza = (Object*)malloc(sizeof(Object));
		pizza->location = f3(25.0f, 0.0f, 160.0f);
		pizza->rotation = f3(0.0f, 0.0f, 0.0f);
		pizza->type = PizzaBox;
	
		BoundingBox* boxPizza = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxPizza->start = f3(24.5f, 0.0f, 159.5f);
		boxPizza->end = f3(25.5f, 0.2f, 160.5f);
		setAreaHeight(height1_1, x11, z11, 24.5f, 159.5f, 25.5f, 160.5f, 0.2f);

		Object* bump = (Object*)malloc(sizeof(Object));
		bump->location = f3(25.0f, 0.0f, 140.25f);
		bump->rotation = f3(0.0f, 0.0f, 0.0f);
		bump->type = SpeedBump;

		BoundingBox* boxBump = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxBump->start = f3(20.0f, 0.0f, 139.5f);
		boxBump->end = f3(30.0f, 0.1f, 141.0f);
		setAreaHeight(height1_1, x11, z11, 20.0f, 139.5f, 30.0f, 141.0f, 0.0f);

		Object* trashContainer = (Object*)malloc(sizeof(Object));
		trashContainer->location = f3(20.0f, 0.0f, 160.0f);
		trashContainer->rotation = f3(0.0f, 0.0f, 0.0f);
		trashContainer->type = TrashContainer;

		BoundingBox* boxContainer = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxContainer->start = f3(19.0f, 0.0f, 158.0f);
		boxContainer->end = f3(21.0f, 1.0f, 162.0f);
		setAreaHeight(height1_1, x11, z11, 19.0f, 158.0f, 21.0f, 162.0f, 1.0f);

		list.push_back(*pizza);
		blist.push_back(*boxPizza);
		list.push_back(*bump);
		blist.push_back(*boxBump);
		list.push_back(*trashContainer);
		blist.push_back(*boxContainer);

	}
	*/
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