#define _CRT_SECURE_NO_WARNINGS
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
int z21 = 474;

int x22 = 200;
int z22 = 606;

int x23 = 600;
int z23 = 180;



std::vector<HeightData> height1_1;
std::vector<HeightData> height1_2;
std::vector<HeightData> height1_22;
std::vector<HeightData> height1_3;
std::vector<HeightData> height2_1;
std::vector<HeightData> height2_2;
std::vector<HeightData> height2_3;

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


	
	/*file = fopen("result/objects2-1.txt", "w");
	FILE* bf = fopen("result/box2-1.txt", "w");
	FILE* hf = fopen("result/height2-1.txt", "w");
	
	writeHeight(hf, height2_1);*/

	file = fopen("result/1_3/objects1-3.txt", "w");
	FILE* bf = fopen("result/1_3/box1-3.txt", "w");
	FILE* hf = fopen("result/1_3/height1-3.txt", "w");

	writeHeight(hf, height1_3);

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

	fclose(hf);




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
	createObstacles1_3(list, blist);
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
		boxRightWall->end = f3(200.0f, 10.0f, 195.0f);
		setAreaHeight(height1_1, x11, z11, 199.5f, 0.0f, 200.0f, 195.0f, 10.0f);

		Object* RightWall2 = (Object*)malloc(sizeof(Object));
		RightWall2->location = f3(199.999f, 5.0f, 195.0f);
		RightWall2->rotation = f3(0.0f, 0.0f, 0.0f);
		RightWall2->type = RustyMetal_Wall_Right2;

		BoundingBox* boxRightWall2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxRightWall2->start = f3(199.999f, 5.0f, 195.0f);
		boxRightWall2->end = f3(200.0f, 10.0f, 197.5f);
		setAreaHeight(height1_1, x11, z11, 199.5f, 195.0f, 200.0f, 197.5f, 0.0f);

		Object* RightWall3 = (Object*)malloc(sizeof(Object));
		RightWall3->location = f3(199.999f, 0.0f, 197.5f);
		RightWall3->rotation = f3(0.0f, 0.0f, 0.0f);
		RightWall3->type = RustyMetal_Wall_Right3;

		BoundingBox* boxRightWall3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxRightWall3->start = f3(199.999f, 0.0f, 197.5f);
		boxRightWall3->end = f3(200.0f, 10.0f, 200.0f);
		setAreaHeight(height1_1, x11, z11, 199.5f, 197.5f, 200.0f, 200.0f, 10.0f);


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

		list.push_back(*RightWall2);
		blist.push_back(*boxRightWall2);

		list.push_back(*RightWall3);
		blist.push_back(*boxRightWall3);

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

	

	
}

void createObstacles1_2(vector<Object>& list, vector<BoundingBox>& blist)
{

	//외곽 벽
	{
		Object* left1 = (Object*)malloc(sizeof(Object));
		left1->location = f3(200.01f, 0.0f, 0.0f);
		left1->rotation = f3(0.0f, 0.0f, 0.0f);
		left1->type = Wall12_Left1;

		BoundingBox* boxleft1 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxleft1->start = f3(200.0f, 0.0f, 0.0f);
		boxleft1->end = f3(200.01f, 10.0f, 195.0f);

		setAreaHeight(height1_2, x12, z12, 0.0f, 0.0f, 0.5f, 195.0f, 10.0f);

		Object* left2 = (Object*)malloc(sizeof(Object));
		left2->location = f3(200.01f, 5.0f, 195.0f);
		left2->rotation = f3(0.0f, 0.0f, 0.0f);
		left2->type = Wall12_Left2;

		BoundingBox* boxleft2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxleft2->start = f3(200.0f, 5.0f, 195.0f);
		boxleft2->end = f3(200.01f, 10.0f, 197.5f);

		setAreaHeight(height1_2, x12, z12, 0.0f, 195.0f, 0.5f, 197.5f, 0.0f);

		Object* left3 = (Object*)malloc(sizeof(Object));
		left3->location = f3(200.01f, 0.0f, 197.5f);
		left3->rotation = f3(0.0f, 0.0f, 0.0f);
		left3->type = Wall12_Left3;

		BoundingBox* boxleft3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxleft3->start = f3(200.0f, 0.0f, 197.5f);
		boxleft3->end = f3(200.01f, 10.0f, 200.0f);

		setAreaHeight(height1_2, x12, z12, 0.0f, 197.5f, 0.5f, 200.0f, 10.0f);

		Object* right = (Object*)malloc(sizeof(Object));
		right->location = f3(399.99f, 0.0f, 0.0f);
		right->rotation = f3(0.0f, 0.0f, 0.0f);
		right->type = Wall12_Right1;

		BoundingBox* boxright = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxright->start = f3(399.99f, 0.0f, 0.0f);
		boxright->end = f3(400.00f, 10.0f, 195.0f);

		setAreaHeight(height1_2, x12, z12, 199.5f, 0.0f, 200.0f, 195.0f, 10.0f);

		Object* right2 = (Object*)malloc(sizeof(Object));
		right2->location = f3(399.99f, 5.0f, 195.0f);
		right2->rotation = f3(0.0f, 0.0f, 0.0f);
		right2->type = Wall12_Right2;

		BoundingBox* boxright2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxright2->start = f3(399.99f, 5.0f, 195.0f);
		boxright2->end = f3(400.00f, 10.0f, 197.5f);

		setAreaHeight(height1_2, x12, z12, 199.5f, 195.0f, 200.0f, 197.5f, 0.0f);

		Object* right3 = (Object*)malloc(sizeof(Object));
		right3->location = f3(399.99f, 0.0f, 197.5f);
		right3->rotation = f3(0.0f, 0.0f, 0.0f);
		right3->type = Wall12_Right3;

		BoundingBox* boxright3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxright3->start = f3(399.99f, 0.0f, 197.5f);
		boxright3->end = f3(400.00f, 10.0f, 200.0f);

		setAreaHeight(height1_2, x12, z12, 199.5f, 197.5f, 200.0f, 197.5f, 10.0f);

		Object* front = (Object*)malloc(sizeof(Object));
		front->location = f3(200.0f, 0.0f, 0.01f);
		front->rotation = f3(0.0f, 0.0f, 0.0f);
		front->type = Wall12_Front;

		BoundingBox* boxfront = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxfront->start = f3(200.0f, 0.0f, 0.0f);
		boxfront->end = f3(600.0f, 10.0f, 0.01f);

		setAreaHeight(height1_2, x12, z12, 0.0f, 0.0f, 200.0f, 0.5f, 10.0f);


		Object* back = (Object*)malloc(sizeof(Object));
		back->location = f3(200.0f, 0.0f, 199.99f);
		back->rotation = f3(0.0f, 0.0f, 0.0f);
		back->type = Wall12_Back;

		BoundingBox* boxback = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxback->start = f3(200.0f, 0.0f, 199.99f);
		boxback->end = f3(600.0f, 10.0f, 200.0f);

		setAreaHeight(height1_2, x12, z12, 0.0f, 199.5f, 200.0f, 200.0f, 10.0f);


		Object* floor = (Object*)malloc(sizeof(Object));
		floor->location = f3(200.0f, 0.01f, 0.0f);
		floor->rotation = f3(0.0f, 0.0f, 0.0f);
		floor->type = Wall12_Floor;

		BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxfloor->start = f3(200.0f, 0.0f, 0.0f);
		boxfloor->end = f3(600.0f, 0.0f, 200.0f);

		Object* ceiling = (Object*)malloc(sizeof(Object));
		ceiling->location = f3(200.0f, 9.99f, 0.0f);
		ceiling->rotation = f3(0.0f, 0.0f, 0.0f);
		ceiling->type = Wall12_Ceiling;

		BoundingBox* boxceiling = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxceiling->start = f3(200.0f, 0.0f, 0.0f);
		boxceiling->end = f3(600.0f, 0.0f, 200.0f);

		list.push_back(*left1);
		list.push_back(*left2);
		list.push_back(*left3);
		list.push_back(*right);
		list.push_back(*right2);
		list.push_back(*right3);
		list.push_back(*front);
		list.push_back(*back);
		list.push_back(*floor);
		list.push_back(*ceiling);

		blist.push_back(*boxleft1);
		blist.push_back(*boxleft2);
		blist.push_back(*boxleft3);
		blist.push_back(*boxright);
		blist.push_back(*boxright2);
		blist.push_back(*boxright3);
		blist.push_back(*boxfront);
		blist.push_back(*boxback);
		blist.push_back(*boxfloor);
		blist.push_back(*boxceiling);
	}

	//내부 벽
	{
		Object* center1 = (Object*)malloc(sizeof(Object));
		center1->location = f3(300.25f, 0.0f, 50.0f);
		center1->rotation = f3(0.0f, 0.0f, 0.0f);
		center1->type = Wall12_Center1;

		BoundingBox* boxcenter1 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxcenter1->start = f3(300.25f, 0.0f, 50.0f);
		boxcenter1->end = f3(301.25f, 10.0f, 200.0f);

		setAreaHeight(height1_2, x12, z12, 100.0f, 50.0f, 101.5f, 200.0f, 10.0f);

		Object* center2 = (Object*)malloc(sizeof(Object));
		center2->location = f3(300.25f, 5.0f, 0.0f);
		center2->rotation = f3(0.0f, 0.0f, 0.0f);
		center2->type = Wall12_Center2;

		BoundingBox* boxcenter2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxcenter2->start = f3(300.25f, 5.0f, 0.0f);
		boxcenter2->end = f3(301.25f, 10.0f, 4.0f);

		setAreaHeight(height1_2, x12, z12, 100.0f, 0.0f, 101.5f, 4.0f, 10.0f);

		Object* center3 = (Object*)malloc(sizeof(Object));
		center3->location = f3(300.25f, 5.0f, 7.0f);
		center3->rotation = f3(0.0f, 0.0f, 0.0f);
		center3->type = Wall12_Center3;

		BoundingBox* boxcenter3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxcenter3->start = f3(300.25f, 5.0f, 7.0f);
		boxcenter3->end = f3(301.25f, 10.0f, 50.0f);

		setAreaHeight(height1_2, x12, z12, 100.0f, 7.0f, 101.5f, 50.0f, 10.0f);

		Object* center4 = (Object*)malloc(sizeof(Object));
		center4->location = f3(300.25f, 8.0f, 4.0f);
		center4->rotation = f3(0.0f, 0.0f, 0.0f);
		center4->type = Wall12_Center4;

		BoundingBox* boxcenter4 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxcenter4->start = f3(300.25f, 8.0f, 4.0f);
		boxcenter4->end = f3(301.25f, 10.0f, 7.0f);

		setAreaHeight(height1_2, x12, z12, 100.0f, 4.0f, 101.5f, 7.0f, 10.0f);


		Object* hcenter = (Object*)malloc(sizeof(Object));
		hcenter->location = f3(295.0f, 0.0f, 100.25f);
		hcenter->rotation = f3(0.0f, 0.0f, 0.0f);
		hcenter->type = Wall12_HCenter1;

		BoundingBox* boxhcenter = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhcenter->start = f3(295.0f, 0.0f, 100.25f);
		boxhcenter->end = f3(305.0f, 10.0f, 101.25f);

		setAreaHeight(height1_2, x12, z12, 95.0f, 99.0f, 105.0f, 102.5f, 10.0f);

		Object* hcenter2 = (Object*)malloc(sizeof(Object));
		hcenter2->location = f3(200.0f, 0.0f, 100.25f);
		hcenter2->rotation = f3(0.0f, 0.0f, 0.0f);
		hcenter2->type = Wall12_HCenter2;

		BoundingBox* boxhcenter2 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhcenter2->start = f3(200.0f, 0.0f, 100.25f);
		boxhcenter2->end = f3(292.0f, 10.0f, 101.25f);

		setAreaHeight(height1_2, x12, z12, 0.0f, 99.0f, 92.0f, 102.5f, 10.0f);

		Object* hcenter3 = (Object*)malloc(sizeof(Object));
		hcenter3->location = f3(308.0f, 0.0f, 100.25f);
		hcenter3->rotation = f3(0.0f, 0.0f, 0.0f);
		hcenter3->type = Wall12_HCenter3;

		BoundingBox* boxhcenter3 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhcenter3->start = f3(308.0f, 0.0f, 100.25f);
		boxhcenter3->end = f3(400.0f, 10.0f, 101.25f);

		setAreaHeight(height1_2, x12, z12, 108.0f, 99.0f, 200.0f, 102.5f, 10.0f);

		Object* hcenter4 = (Object*)malloc(sizeof(Object));
		hcenter4->location = f3(292.0f, 5.0f, 100.25f);
		hcenter4->rotation = f3(0.0f, 0.0f, 0.0f);
		hcenter4->type = Wall12_HCenter4;

		BoundingBox* boxhcenter4 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhcenter4->start = f3(292.0f, 5.0f, 100.25f);
		boxhcenter4->end = f3(295.0f, 10.0f, 101.25f);

		setAreaHeight(height1_2, x12, z12, 92.0f, 99.0f, 95.0f, 102.5f, 0.0f);

		Object* hcenter5 = (Object*)malloc(sizeof(Object));
		hcenter5->location = f3(305.0f, 5.0f, 100.25f);
		hcenter5->rotation = f3(0.0f, 0.0f, 0.0f);
		hcenter5->type = Wall12_HCenter5;

		BoundingBox* boxhcenter5 = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxhcenter5->start = f3(305.0f, 5.0f, 100.25f);
		boxhcenter5->end = f3(308.0f, 10.0f, 101.25f);

		setAreaHeight(height1_2, x12, z12, 105.0f, 99.0f, 108.0f, 102.5f, 0.0f);

		Object* ufloor = (Object*)malloc(sizeof(Object));
		ufloor->location = f3(250.0f, 5.0f, 0.0f);
		ufloor->rotation = f3(0.0f, 0.0f, 0.0f);
		ufloor->type = Wall12_UpperFloor;

		BoundingBox* boxufloor = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxufloor->start = f3(250.0f, 4.99f, 0.0f);
		boxufloor->end = f3(350.0f, 5.0f, 50.0f);

		setAreaHeight(height1_2, x12, z12, 50.0f, 0.0f, 150.0f, 50.0f, 5.0f);

		Object* frame = (Object*)malloc(sizeof(Object));
		frame->location = f3(250.0f, 0.0f, 0.0f);
		frame->rotation = f3(0.0f, 0.0f, 0.0f);
		frame->type = WireFrame;

		BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
		boxframe->start = f3(250.0f, 0.0f, 0.0f);
		boxframe->end = f3(350.0f, 5.0f, 50.0f);





		list.push_back(*center1);
		list.push_back(*center2);
		list.push_back(*center3);
		list.push_back(*center4);
		list.push_back(*hcenter);
		list.push_back(*hcenter2);
		list.push_back(*hcenter3);
		list.push_back(*hcenter4);
		list.push_back(*hcenter5);
		list.push_back(*ufloor);
		list.push_back(*frame);


		blist.push_back(*boxcenter1);
		blist.push_back(*boxcenter2);
		blist.push_back(*boxcenter3);
		blist.push_back(*boxcenter4);
		blist.push_back(*boxhcenter);
		blist.push_back(*boxhcenter2);
		blist.push_back(*boxhcenter3);
		blist.push_back(*boxhcenter4);
		blist.push_back(*boxhcenter5);
		blist.push_back(*boxufloor);
		blist.push_back(*boxframe);
	}

	//좌상단 기계구역
	{
		//cont & shield
		
		for (float x = 212.0f; x < 290.0f; x += 4.0f)
			{
				int irand = rand() % 3;

				int ir = rand() % 2;

				if (irand == 0)
				{

					Object* frame = (Object*)malloc(sizeof(Object));
					frame->location = f3(x, 0.0f, 199.75f);
					frame->rotation = f3(0.0f, 90.0f, 0.0f);
					frame->type = Controller12_1;

					BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxframe->start = f3(x - 0.5f, 0.0f, 199.5f);
					boxframe->end = f3(x + 0.5, 2.0f, 200.0f);

					list.push_back(*frame);
					blist.push_back(*boxframe);
				}
				else if (irand == 1)
				{

					Object* frame = (Object*)malloc(sizeof(Object));
					frame->location = f3(x, 1.0f, 199.75f);
					frame->rotation = f3(0.0f, 90.0f, 0.0f);
					frame->type = Controller12_2;

					BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxframe->start = f3(x - 0.5f, 0.0f, 199.5f);
					boxframe->end = f3(x + 0.5, 2.0f, 200.0f);

					list.push_back(*frame);
					blist.push_back(*boxframe);
				}
				else if (irand == 2)
				{

					Object* frame = (Object*)malloc(sizeof(Object));
					frame->location = f3(x, 1.0f, 199.75f);
					frame->rotation = f3(0.0f, 90.0f, 0.0f);
					frame->type = Controller12_4;

					BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxframe->start = f3(x - 0.5f, 0.0f, 199.5f);
					boxframe->end = f3(x + 0.5, 2.0f, 200.0f);
					list.push_back(*frame);
					blist.push_back(*boxframe);
				}

				if (ir)
				{
					Object* frame = (Object*)malloc(sizeof(Object));
					frame->location = f3(x, 0.0f, 195.0f);
					frame->rotation = f3(0.0f, 0.0f, 0.0f);
					frame->type = Shield;

					BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxframe->start = f3(x - 0.5f, 0.0f, 194.5f);
					boxframe->end = f3(x + 0.5f, 2.0f, 195.5f);
					list.push_back(*frame);
					blist.push_back(*boxframe);
				}
				else
				{
					Object* frame = (Object*)malloc(sizeof(Object));
					frame->location = f3(x, 0.0f, 195.0f);
					frame->rotation = f3(0.0f, 0.0f, 0.0f);
					frame->type = BigShield;
					if (x == 288.0f)
					{
						frame->type = Shield;
					}

					BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxframe->start = f3(x - 2.5f, 0.0f, 194.5f);
					boxframe->end = f3(x + 2.5f, 2.0f, 195.5f);
					list.push_back(*frame);
					blist.push_back(*boxframe);
				}
			}

		//fence
		for (float z = 198.0f; z > 191.0f; z -= 4.0f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(210.0f, 0.0f, z);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(209.75f, 0.0f, z - 2.0f);
				boxfence->end = f3(210.25f, 3.0f, z + 2.0f);

				Object* fence2 = (Object*)malloc(sizeof(Object));
				fence2->location = f3(290.0f, 0.0f, z);
				fence2->rotation = f3(0.0f, 0.0f, 0.0f);
				fence2->type = Fence12;

				BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence2->start = f3(289.75f, 0.0f, z - 2.0f);
				boxfence2->end = f3(290.25f, 3.0f, z + 2.0f);

				list.push_back(*fence);
				list.push_back(*fence2);
				blist.push_back(*boxfence);
				blist.push_back(*boxfence2);
			}
		for (float x = 212.0f; x < 290.0f; x += 4.0f)
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, 0.0f, 192.0f);
				fence->rotation = f3(0.0f, 90.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(x - 2.0f, 0.0f, 191.75f);
				boxfence->end = f3(x + 2.0f, 3.0f, 192.25f);

				list.push_back(*fence);
				blist.push_back(*boxfence);
			}

		setAreaHeight(height1_2, x12, z12, 9.75f, 191.75f, 90.25f, 200.0f, 3.0f);
		
		//container
		for (float z = 141.0f; z <= 160.0f; z += 9.0f)
		{
			if (z == 150.0f)
			{
				for (float x = 220.0f; x <= 290.0f; x += 12.0f)
				{
					Object* con = (Object*)malloc(sizeof(Object));
					con->location = f3(x, 0.0f, z);
					con->rotation = f3(0.0f, 90.0f, 0.0f);
					con->type = Container12;

					BoundingBox* boxcon = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxcon->start = f3(x - 3.0f, 0.0f, z - 1.5f);
					boxcon->end = f3(x + 3.0f, 3.0f, z + 1.5f);

					setAreaHeight(height1_2, x12, z12, x - 3.5f - 200.0f, z - 2.0f, x + 3.5f -200.0f, z + 2.0f, 3.0f);

					list.push_back(*con);
					blist.push_back(*boxcon);
				}
			}
			else
			{
				for (float x = 214.0f; x <= 290.0f; x += 12.0f)
				{
					Object* con = (Object*)malloc(sizeof(Object));
					con->location = f3(x, 0.0f, z);
					con->rotation = f3(0.0f, 90.0f, 0.0f);
					con->type = Container12;

					BoundingBox* boxcon = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxcon->start = f3(x - 3.0f, 0.0f, z - 1.5f);
					boxcon->end = f3(x + 3.0f, 3.0f, z + 1.5f);

					setAreaHeight(height1_2, x12, z12, x - 3.5f-200.0f, z - 2.0f, x + 3.5f-200.0f, z + 2.0f, 3.0f);

					list.push_back(*con);
					blist.push_back(*boxcon);
				}
			}

		}


		//fan & machine
		for (float x = 210.0f; x < 241.0f; x += 3.0f)
		{
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(x, 0.0f, 180.0f);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = AirFan;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(x - 1.25f, 0.0f, 177.0f);
				boxfan->end = f3(x + 1.25f, 2.5f, 183.0f);



				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(x + 50.0f, 0.0f, 180.0f);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = AirFan;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(x + 50.0f - 1.25f, 0.0f, 177.0f);
				boxfan2->end = f3(x + 50.0f + 1.25f, 2.5f, 183.0f);



				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}

			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(x, 0.0f, 120.0f);
				fan->rotation = f3(0.0f, 180.0f, 0.0f);
				fan->type = AirFan;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(x - 1.25f, 0.0f, 117.0f);
				boxfan->end = f3(x + 1.25f, 2.5f, 123.0f);



				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(x + 50.0f, 0.0f, 120.0f);
				fan2->rotation = f3(0.0f, 180.0f, 0.0f);
				fan2->type = AirFan;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(x + 50.0f - 1.25f, 0.0f, 117.0f);
				boxfan2->end = f3(x + 50.0f + 1.25f, 2.5f, 123.0f);



				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}

		}

		for (float x = 210.0f; x < 240.0f; x += 7.0f)
		{
			{
				int irand = rand() % 5;
				if (irand == 0)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine1;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 2.5f, 0.0f, 169.0f);
					boxm->end = f3(x + 2.5f, 2.5f, 173.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}

				else if (irand == 1)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine3;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 3.0f, 0.0f, 169.0f);
					boxm->end = f3(x + 3.0f, 3.0f, 173.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (irand == 2)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine4;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 1.5f, 0.0f, 169.5f);
					boxm->end = f3(x + 1.5f, 5.0f, 172.5f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (irand == 3)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine6;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 3.0f, 0.0f, 168.0f);
					boxm->end = f3(x + 3.0f, 4.0f, 174.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}

				else if (irand == 4)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine7;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 2.5f, 0.0f, 169.5f);
					boxm->end = f3(x + 2.5f, 4.0f, 172.5f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}

				int r2 = rand() % 5;
				if (r2 == 0)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine1;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 169.0f);
					boxm->end = f3(x + 50.0f + 2.5f, 2.5f, 173.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 1)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine3;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 169.0f);
					boxm->end = f3(x + 50.0f + 3.0f, 3.0f, 173.0f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 2)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine4;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 1.5f, 0.0f, 169.5f);
					boxm->end = f3(x + 50.0f + 1.5f, 5.0f, 172.5f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 3)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine6;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 168.0f);
					boxm->end = f3(x + 50.0f + 3.0f, 4.0f, 174.0f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 4)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 171.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine7;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 169.5f);
					boxm->end = f3(x + 50.0f + 2.5f, 1.5f, 172.5f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
			}

			{
				int irand = rand() % 5;
				if (irand == 0)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine1;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 2.5f, 0.0f, 123.0f);
					boxm->end = f3(x + 2.5f, 2.5f, 127.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}

				else if (irand == 1)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine3;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 3.0f, 0.0f, 123.0f);
					boxm->end = f3(x + 3.0f, 3.0f, 127.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (irand == 2)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine4;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 1.5f, 0.0f, 123.5f);
					boxm->end = f3(x + 1.5f, 5.0f, 126.5f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (irand == 3)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine6;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 3.0f, 0.0f, 122.0f);
					boxm->end = f3(x + 3.0f, 4.0f, 128.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}

				else if (irand == 4)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine7;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x - 2.5f, 0.0f, 123.5f);
					boxm->end = f3(x + 2.5f, 4.0f, 126.5f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}

				int r2 = rand() % 5;
				if (r2 == 0)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine1;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 123.0f);
					boxm->end = f3(x + 50.0f + 2.5f, 2.5f, 127.0f);



					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 1)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine3;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 123.0f);
					boxm->end = f3(x + 50.0f + 3.0f, 3.0f, 127.0f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 2)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine4;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 1.5f, 0.0f, 123.5f);
					boxm->end = f3(x + 50.0f + 1.5f, 5.0f, 126.5f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 3)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine6;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 122.0f);
					boxm->end = f3(x + 50.0f + 3.0f, 4.0f, 128.0f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
				else if (r2 == 4)
				{
					Object* m = (Object*)malloc(sizeof(Object));
					m->location = f3(x + 50.0f, 0.0f, 125.0f);
					m->rotation = f3(0.0f, 0.0f, 0.0f);
					m->type = Machine7;

					BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 123.5f);
					boxm->end = f3(x + 50.0f + 2.5f, 1.5f, 126.5f);

					list.push_back(*m);
					blist.push_back(*boxm);
				}
			}
		}

		//fence
		for (float x = 208.0f; x < 244.4f; x += 4.0f)
		{
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, 0.0f, 185.0f);
				fence->rotation = f3(0.0f, 90.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(x - 2.0f, 0.0f, 184.75f);
				boxfence->end = f3(x + 2.0f, 3.0f, 185.25f);

				Object* fence2 = (Object*)malloc(sizeof(Object));
				fence2->location = f3(x, 0.0f, 169.0f);
				fence2->rotation = f3(0.0f, 90.0f, 0.0f);
				fence2->type = Fence12;

				BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence2->start = f3(x - 2.0f, 0.0f, 168.75f);
				boxfence2->end = f3(x + 2.0f, 3.0f, 169.25f);


				Object* fence3 = (Object*)malloc(sizeof(Object));
				fence3->location = f3(300.0f - (x - 200.0f), 0.0f, 185.0f);
				fence3->rotation = f3(0.0f, 90.0f, 0.0f);
				fence3->type = Fence12;

				BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence3->start = f3(300.0f - (x - 200.0f) - 2.0f, 0.0f, 184.75f);
				boxfence3->end = f3(300.0f - (x - 200.0f) + 2.0f, 3.0f, 185.25f);

				Object* fence4 = (Object*)malloc(sizeof(Object));
				fence4->location = f3(300.0f - (x - 200.0f), 0.0f, 169.0f);
				fence4->rotation = f3(0.0f, 90.0f, 0.0f);
				fence4->type = Fence12;

				BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence4->start = f3(300.0f - (x - 200.0f) - 2.0f, 0.0f, 168.75f);
				boxfence4->end = f3(300.0f - (x - 200.0f) + 2.0f, 3.0f, 169.25f);

				list.push_back(*fence);
				blist.push_back(*boxfence);
				list.push_back(*fence2);
				blist.push_back(*boxfence2);
				list.push_back(*fence3);
				blist.push_back(*boxfence3);
				list.push_back(*fence4);
				blist.push_back(*boxfence4);
			}

			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, 0.0f, 115.0f);
				fence->rotation = f3(0.0f, 90.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(x - 2.0f, 0.0f, 114.75f);
				boxfence->end = f3(x + 2.0f, 3.0f, 115.25f);

				Object* fence2 = (Object*)malloc(sizeof(Object));
				fence2->location = f3(x, 0.0f, 131.0f);
				fence2->rotation = f3(0.0f, 90.0f, 0.0f);
				fence2->type = Fence12;

				BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence2->start = f3(x - 2.0f, 0.0f, 130.75f);
				boxfence2->end = f3(x + 2.0f, 3.0f, 131.25f);


				Object* fence3 = (Object*)malloc(sizeof(Object));
				fence3->location = f3(300.0f - (x - 200.0f), 0.0f, 115.0f);
				fence3->rotation = f3(0.0f, 90.0f, 0.0f);
				fence3->type = Fence12;

				BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence3->start = f3(300.0f - (x - 200.0f) - 2.0f, 0.0f, 114.75f);
				boxfence3->end = f3(300.0f - (x - 200.0f) + 2.0f, 3.0f, 115.25f);

				Object* fence4 = (Object*)malloc(sizeof(Object));
				fence4->location = f3(300.0f - (x - 200.0f), 0.0f, 131.0f);
				fence4->rotation = f3(0.0f, 90.0f, 0.0f);
				fence4->type = Fence12;

				BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence4->start = f3(300.0f - (x - 200.0f) - 2.0f, 0.0f, 130.75f);
				boxfence4->end = f3(300.0f - (x - 200.0f) + 2.0f, 3.0f, 131.25f);

				list.push_back(*fence);
				blist.push_back(*boxfence);
				list.push_back(*fence2);
				blist.push_back(*boxfence2);
				list.push_back(*fence3);
				blist.push_back(*boxfence3);
				list.push_back(*fence4);
				blist.push_back(*boxfence4);
			}
		}

		for (float z = 171.0f; z < 186.0f; z += 4.0f)
		{
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(206.0, 0.0f, z);
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(205.75f, 0.0f, z - 2.0f);
				boxfence->end = f3(206.25f, 3.0f, z + 2.0f);

				Object* fence2 = (Object*)malloc(sizeof(Object));
				fence2->location = f3(294.0, 0.0f, z);
				fence2->rotation = f3(0.0f, 0.0f, 0.0f);
				fence2->type = Fence12;

				BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence2->start = f3(293.75f, 0.0f, z - 2.0f);
				boxfence2->end = f3(294.25f, 3.0f, z + 2.0f);

				Object* fence3 = (Object*)malloc(sizeof(Object));
				fence3->location = f3(246.0, 0.0f, z);
				fence3->rotation = f3(0.0f, 0.0f, 0.0f);
				fence3->type = Fence12;

				BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence3->start = f3(245.75f, 0.0f, z - 2.0f);
				boxfence3->end = f3(246.25f, 3.0f, z + 2.0f);

				Object* fence4 = (Object*)malloc(sizeof(Object));
				fence4->location = f3(254.0, 0.0f, z);
				fence4->rotation = f3(0.0f, 0.0f, 0.0f);
				fence4->type = Fence12;

				BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence4->start = f3(253.75f, 0.0f, z - 2.0f);
				boxfence4->end = f3(254.25f, 3.0f, z + 2.0f);

				list.push_back(*fence);
				list.push_back(*fence2);
				list.push_back(*fence3);
				list.push_back(*fence4);
				blist.push_back(*boxfence);
				blist.push_back(*boxfence2);
				blist.push_back(*boxfence3);
				blist.push_back(*boxfence4);
			}

			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(206.0, 0.0f, 100.0f + (200.0f - z));
				fence->rotation = f3(0.0f, 0.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(205.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
				boxfence->end = f3(206.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

				Object* fence2 = (Object*)malloc(sizeof(Object));
				fence2->location = f3(294.0, 0.0f, 100.0f + (200.0f - z));
				fence2->rotation = f3(0.0f, 0.0f, 0.0f);
				fence2->type = Fence12;

				BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence2->start = f3(293.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
				boxfence2->end = f3(294.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

				Object* fence3 = (Object*)malloc(sizeof(Object));
				fence3->location = f3(246.0, 0.0f, 100.0f + (200.0f - z));
				fence3->rotation = f3(0.0f, 0.0f, 0.0f);
				fence3->type = Fence12;

				BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence3->start = f3(245.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
				boxfence3->end = f3(246.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

				Object* fence4 = (Object*)malloc(sizeof(Object));
				fence4->location = f3(254.0, 0.0f, 100.0f + (200.0f - z));
				fence4->rotation = f3(0.0f, 0.0f, 0.0f);
				fence4->type = Fence12;

				BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence4->start = f3(253.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
				boxfence4->end = f3(254.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

				list.push_back(*fence);
				list.push_back(*fence2);
				list.push_back(*fence3);
				list.push_back(*fence4);
				blist.push_back(*boxfence);
				blist.push_back(*boxfence2);
				blist.push_back(*boxfence3);
				blist.push_back(*boxfence4);
			}
		}

		setAreaHeight(height1_2, x12, z12, 5.5f, 168.5f, 46.5f, 185.5f, 3.0f);

		setAreaHeight(height1_2, x12, z12, 53.5f, 168.5f, 94.5f, 185.5f, 3.0f);

		setAreaHeight(height1_2, x12, z12, 53.5f, 114.5f, 94.5f, 131.5f, 3.0f);

		setAreaHeight(height1_2, x12, z12, 5.5f, 114.5f, 46.5f, 131.5f, 3.0f);
	}


	//우상단 기계구역(거의 대칭)

	{
		//cont & shield
		
		for (float x = 312.0f; x < 390.0f; x += 4.0f)
		{
			int irand = rand() % 3;

			int ir = rand() % 2;

			if (irand == 0)
			{

				Object* frame = (Object*)malloc(sizeof(Object));
				frame->location = f3(x, 0.0f, 199.75f);
				frame->rotation = f3(0.0f, 90.0f, 0.0f);
				frame->type = Controller12_1;

				BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxframe->start = f3(x - 0.5f, 0.0f, 199.5f);
				boxframe->end = f3(x + 0.5, 2.0f, 200.0f);

				list.push_back(*frame);
				blist.push_back(*boxframe);
			}
			else if (irand == 1)
			{

				Object* frame = (Object*)malloc(sizeof(Object));
				frame->location = f3(x, 1.0f, 199.75f);
				frame->rotation = f3(0.0f, 90.0f, 0.0f);
				frame->type = Controller12_2;

				BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxframe->start = f3(x - 0.5f, 0.0f, 199.5f);
				boxframe->end = f3(x + 0.5, 2.0f, 200.0f);

				list.push_back(*frame);
				blist.push_back(*boxframe);
			}
			else if (irand == 2)
			{

				Object* frame = (Object*)malloc(sizeof(Object));
				frame->location = f3(x, 1.0f, 199.75f);
				frame->rotation = f3(0.0f, 90.0f, 0.0f);
				frame->type = Controller12_4;

				BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxframe->start = f3(x - 0.5f, 0.0f, 199.5f);
				boxframe->end = f3(x + 0.5, 2.0f, 200.0f);
				list.push_back(*frame);
				blist.push_back(*boxframe);
			}

			if (ir)
			{
				Object* frame = (Object*)malloc(sizeof(Object));
				frame->location = f3(x, 0.0f, 195.0f);
				frame->rotation = f3(0.0f, 0.0f, 0.0f);
				frame->type = Shield;

				BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxframe->start = f3(x - 0.5f, 0.0f, 194.5f);
				boxframe->end = f3(x + 0.5f, 2.0f, 195.5f);
				list.push_back(*frame);
				blist.push_back(*boxframe);
			}
			else
			{
				Object* frame = (Object*)malloc(sizeof(Object));
				frame->location = f3(x, 0.0f, 195.0f);
				frame->rotation = f3(0.0f, 0.0f, 0.0f);
				frame->type = BigShield;
				if (x == 288.0f)
				{
					frame->type = Shield;
				}

				BoundingBox* boxframe = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxframe->start = f3(x - 2.5f, 0.0f, 194.5f);
				boxframe->end = f3(x + 2.5f, 2.0f, 195.5f);
				list.push_back(*frame);
				blist.push_back(*boxframe);
			}
		}

		//fence
		for (float z = 198.0f; z > 191.0f; z -= 4.0f)
		{
			Object* fence = (Object*)malloc(sizeof(Object));
			fence->location = f3(310.0f, 0.0f, z);
			fence->rotation = f3(0.0f, 0.0f, 0.0f);
			fence->type = Fence12;

			BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfence->start = f3(309.75f, 0.0f, z - 2.0f);
			boxfence->end = f3(310.25f, 3.0f, z + 2.0f);

			Object* fence2 = (Object*)malloc(sizeof(Object));
			fence2->location = f3(390.0f, 0.0f, z);
			fence2->rotation = f3(0.0f, 0.0f, 0.0f);
			fence2->type = Fence12;

			BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfence2->start = f3(389.75f, 0.0f, z - 2.0f);
			boxfence2->end = f3(390.25f, 3.0f, z + 2.0f);

			list.push_back(*fence);
			list.push_back(*fence2);
			blist.push_back(*boxfence);
			blist.push_back(*boxfence2);
		}
		for (float x = 312.0f; x < 390.0f; x += 4.0f)
		{
			Object* fence = (Object*)malloc(sizeof(Object));
			fence->location = f3(x, 0.0f, 192.0f);
			fence->rotation = f3(0.0f, 90.0f, 0.0f);
			fence->type = Fence12;

			BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfence->start = f3(x - 2.0f, 0.0f, 191.75f);
			boxfence->end = f3(x + 2.0f, 3.0f, 192.25f);

			list.push_back(*fence);
			blist.push_back(*boxfence);
		}

		setAreaHeight(height1_2, x12, z12, 109.75f, 191.75f, 190.25f, 200.0f, 3.0f);

		//container
		for (float z = 141.0f; z <= 160.0f; z += 9.0f)
		{
			if (z == 150.0f)
			{
				for (float x = 320.0f; x <= 390.0f; x += 12.0f)
				{
					Object* con = (Object*)malloc(sizeof(Object));
					con->location = f3(x, 0.0f, z);
					con->rotation = f3(0.0f, 90.0f, 0.0f);
					con->type = Container12;

					BoundingBox* boxcon = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxcon->start = f3(x - 3.0f, 0.0f, z - 1.5f);
					boxcon->end = f3(x + 3.0f, 3.0f, z + 1.5f);

					setAreaHeight(height1_2, x12, z12, x - 3.5f - 200.0f, z - 2.0f, x + 3.5f - 200.0f, z + 2.0f, 3.0f);

					list.push_back(*con);
					blist.push_back(*boxcon);
				}
			}
			else
			{
				for (float x = 314.0f; x <= 390.0f; x += 12.0f)
				{
					Object* con = (Object*)malloc(sizeof(Object));
					con->location = f3(x, 0.0f, z);
					con->rotation = f3(0.0f, 90.0f, 0.0f);
					con->type = Container12;

					BoundingBox* boxcon = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxcon->start = f3(x - 3.0f, 0.0f, z - 1.5f);
					boxcon->end = f3(x + 3.0f, 3.0f, z + 1.5f);

					setAreaHeight(height1_2, x12, z12, x - 3.5f - 200.0f, z - 2.0f, x + 3.5f - 200.0f, z + 2.0f, 3.0f);

					list.push_back(*con);
					blist.push_back(*boxcon);
				}
			}
		}

		//fan & machine
		for (float x = 310.0f; x < 341.0f; x += 3.0f)
			{
				{
					Object* fan = (Object*)malloc(sizeof(Object));
					fan->location = f3(x, 0.0f, 180.0f);
					fan->rotation = f3(0.0f, 0.0f, 0.0f);
					fan->type = AirFan;

					BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfan->start = f3(x - 1.25f, 0.0f, 177.0f);
					boxfan->end = f3(x + 1.25f, 2.5f, 183.0f);



					Object* fan2 = (Object*)malloc(sizeof(Object));
					fan2->location = f3(x + 50.0f, 0.0f, 180.0f);
					fan2->rotation = f3(0.0f, 0.0f, 0.0f);
					fan2->type = AirFan;

					BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfan2->start = f3(x + 50.0f - 1.25f, 0.0f, 177.0f);
					boxfan2->end = f3(x + 50.0f + 1.25f, 2.5f, 183.0f);



					list.push_back(*fan);
					blist.push_back(*boxfan);
					list.push_back(*fan2);
					blist.push_back(*boxfan2);
				}

				{
					Object* fan = (Object*)malloc(sizeof(Object));
					fan->location = f3(x, 0.0f, 120.0f);
					fan->rotation = f3(0.0f, 180.0f, 0.0f);
					fan->type = AirFan;

					BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfan->start = f3(x - 1.25f, 0.0f, 117.0f);
					boxfan->end = f3(x + 1.25f, 2.5f, 123.0f);



					Object* fan2 = (Object*)malloc(sizeof(Object));
					fan2->location = f3(x + 50.0f, 0.0f, 120.0f);
					fan2->rotation = f3(0.0f, 180.0f, 0.0f);
					fan2->type = AirFan;

					BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfan2->start = f3(x + 50.0f - 1.25f, 0.0f, 117.0f);
					boxfan2->end = f3(x + 50.0f + 1.25f, 2.5f, 123.0f);



					list.push_back(*fan);
					blist.push_back(*boxfan);
					list.push_back(*fan2);
					blist.push_back(*boxfan2);
				}

			}
		for (float x = 310.0f; x < 340.0f; x += 7.0f)
			{
				{
					int irand = rand() % 5;
					if (irand == 0)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine1;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 2.5f, 0.0f, 169.0f);
						boxm->end = f3(x + 2.5f, 2.5f, 173.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}

					else if (irand == 1)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine3;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 3.0f, 0.0f, 169.0f);
						boxm->end = f3(x + 3.0f, 3.0f, 173.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (irand == 2)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine4;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 1.5f, 0.0f, 169.5f);
						boxm->end = f3(x + 1.5f, 5.0f, 172.5f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (irand == 3)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine6;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 3.0f, 0.0f, 168.0f);
						boxm->end = f3(x + 3.0f, 4.0f, 174.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}

					else if (irand == 4)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine7;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 2.5f, 0.0f, 169.5f);
						boxm->end = f3(x + 2.5f, 4.0f, 172.5f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}

					int r2 = rand() % 5;
					if (r2 == 0)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine1;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 169.0f);
						boxm->end = f3(x + 50.0f + 2.5f, 2.5f, 173.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 1)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine3;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 169.0f);
						boxm->end = f3(x + 50.0f + 3.0f, 3.0f, 173.0f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 2)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine4;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 1.5f, 0.0f, 169.5f);
						boxm->end = f3(x + 50.0f + 1.5f, 5.0f, 172.5f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 3)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine6;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 168.0f);
						boxm->end = f3(x + 50.0f + 3.0f, 4.0f, 174.0f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 4)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 171.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine7;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 169.5f);
						boxm->end = f3(x + 50.0f + 2.5f, 1.5f, 172.5f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
				}

				{
					int irand = rand() % 5;
					if (irand == 0)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine1;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 2.5f, 0.0f, 123.0f);
						boxm->end = f3(x + 2.5f, 2.5f, 127.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}

					else if (irand == 1)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine3;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 3.0f, 0.0f, 123.0f);
						boxm->end = f3(x + 3.0f, 3.0f, 127.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (irand == 2)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine4;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 1.5f, 0.0f, 123.5f);
						boxm->end = f3(x + 1.5f, 5.0f, 126.5f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (irand == 3)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine6;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 3.0f, 0.0f, 122.0f);
						boxm->end = f3(x + 3.0f, 4.0f, 128.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}

					else if (irand == 4)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine7;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x - 2.5f, 0.0f, 123.5f);
						boxm->end = f3(x + 2.5f, 4.0f, 126.5f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}

					int r2 = rand() % 5;
					if (r2 == 0)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine1;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 123.0f);
						boxm->end = f3(x + 50.0f + 2.5f, 2.5f, 127.0f);



						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 1)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine3;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 123.0f);
						boxm->end = f3(x + 50.0f + 3.0f, 3.0f, 127.0f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 2)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine4;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 1.5f, 0.0f, 123.5f);
						boxm->end = f3(x + 50.0f + 1.5f, 5.0f, 126.5f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 3)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine6;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 3.0f, 0.0f, 122.0f);
						boxm->end = f3(x + 50.0f + 3.0f, 4.0f, 128.0f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
					else if (r2 == 4)
					{
						Object* m = (Object*)malloc(sizeof(Object));
						m->location = f3(x + 50.0f, 0.0f, 125.0f);
						m->rotation = f3(0.0f, 0.0f, 0.0f);
						m->type = Machine7;

						BoundingBox* boxm = (BoundingBox*)malloc(sizeof(BoundingBox));
						boxm->start = f3(x + 50.0f - 2.5f, 0.0f, 123.5f);
						boxm->end = f3(x + 50.0f + 2.5f, 1.5f, 126.5f);

						list.push_back(*m);
						blist.push_back(*boxm);
					}
				}
			}

		//fence
		for (float x = 308.0f; x < 344.4f; x += 4.0f)
		{
			{
				Object* fence = (Object*)malloc(sizeof(Object));
				fence->location = f3(x, 0.0f, 185.0f);
				fence->rotation = f3(0.0f, 90.0f, 0.0f);
				fence->type = Fence12;

				BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence->start = f3(x - 2.0f, 0.0f, 184.75f);
				boxfence->end = f3(x + 2.0f, 3.0f, 185.25f);

				Object* fence2 = (Object*)malloc(sizeof(Object));
				fence2->location = f3(x, 0.0f, 169.0f);
				fence2->rotation = f3(0.0f, 90.0f, 0.0f);
				fence2->type = Fence12;

				BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence2->start = f3(x - 2.0f, 0.0f, 168.75f);
				boxfence2->end = f3(x + 2.0f, 3.0f, 169.25f);


				Object* fence3 = (Object*)malloc(sizeof(Object));
				fence3->location = f3(400.0f - (x - 300.0f), 0.0f, 185.0f);
				fence3->rotation = f3(0.0f, 90.0f, 0.0f);
				fence3->type = Fence12;

				BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence3->start = f3(400.0f - (x - 300.0f) - 2.0f, 0.0f, 184.75f);
				boxfence3->end = f3(400.0f - (x - 300.0f) + 2.0f, 3.0f, 185.25f);

				Object* fence4 = (Object*)malloc(sizeof(Object));
				fence4->location = f3(400.0f - (x - 300.0f), 0.0f, 169.0f);
				fence4->rotation = f3(0.0f, 90.0f, 0.0f);
				fence4->type = Fence12;

				BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfence4->start = f3(400.0f - (x - 300.0f) - 2.0f, 0.0f, 168.75f);
				boxfence4->end = f3(400.0f - (x - 300.0f) + 2.0f, 3.0f, 169.25f);

				list.push_back(*fence);
				blist.push_back(*boxfence);
				list.push_back(*fence2);
				blist.push_back(*boxfence2);
				list.push_back(*fence3);
				blist.push_back(*boxfence3);
				list.push_back(*fence4);
				blist.push_back(*boxfence4);
			}

			{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(x, 0.0f, 115.0f);
					fence->rotation = f3(0.0f, 90.0f, 0.0f);
					fence->type = Fence12;

					BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence->start = f3(x - 2.0f, 0.0f, 114.75f);
					boxfence->end = f3(x + 2.0f, 3.0f, 115.25f);

					Object* fence2 = (Object*)malloc(sizeof(Object));
					fence2->location = f3(x, 0.0f, 131.0f);
					fence2->rotation = f3(0.0f, 90.0f, 0.0f);
					fence2->type = Fence12;

					BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence2->start = f3(x - 2.0f, 0.0f, 130.75f);
					boxfence2->end = f3(x + 2.0f, 3.0f, 131.25f);


					Object* fence3 = (Object*)malloc(sizeof(Object));
					fence3->location = f3(400.0f - (x - 300.0f), 0.0f, 115.0f);
					fence3->rotation = f3(0.0f, 90.0f, 0.0f);
					fence3->type = Fence12;

					BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence3->start = f3(400.0f - (x - 300.0f) - 2.0f, 0.0f, 114.75f);
					boxfence3->end = f3(400.0f - (x - 300.0f) + 2.0f, 3.0f, 115.25f);

					Object* fence4 = (Object*)malloc(sizeof(Object));
					fence4->location = f3(400.0f - (x - 300.0f), 0.0f, 131.0f);
					fence4->rotation = f3(0.0f, 90.0f, 0.0f);
					fence4->type = Fence12;

					BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence4->start = f3(400.0f - (x - 300.0f) - 2.0f, 0.0f, 130.75f);
					boxfence4->end = f3(400.0f - (x - 300.0f) + 2.0f, 3.0f, 131.25f);

					list.push_back(*fence);
					blist.push_back(*boxfence);
					list.push_back(*fence2);
					blist.push_back(*boxfence2);
					list.push_back(*fence3);
					blist.push_back(*boxfence3);
					list.push_back(*fence4);
					blist.push_back(*boxfence4);
				}
		}

		for (float z = 171.0f; z < 186.0f; z += 4.0f)
			{
				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(306.0, 0.0f, z);
					fence->rotation = f3(0.0f, 0.0f, 0.0f);
					fence->type = Fence12;

					BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence->start = f3(305.75f, 0.0f, z - 2.0f);
					boxfence->end = f3(306.25f, 3.0f, z + 2.0f);

					Object* fence2 = (Object*)malloc(sizeof(Object));
					fence2->location = f3(394.0, 0.0f, z);
					fence2->rotation = f3(0.0f, 0.0f, 0.0f);
					fence2->type = Fence12;

					BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence2->start = f3(393.75f, 0.0f, z - 2.0f);
					boxfence2->end = f3(394.25f, 3.0f, z + 2.0f);

					Object* fence3 = (Object*)malloc(sizeof(Object));
					fence3->location = f3(346.0, 0.0f, z);
					fence3->rotation = f3(0.0f, 0.0f, 0.0f);
					fence3->type = Fence12;

					BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence3->start = f3(345.75f, 0.0f, z - 2.0f);
					boxfence3->end = f3(346.25f, 3.0f, z + 2.0f);

					Object* fence4 = (Object*)malloc(sizeof(Object));
					fence4->location = f3(354.0, 0.0f, z);
					fence4->rotation = f3(0.0f, 0.0f, 0.0f);
					fence4->type = Fence12;

					BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence4->start = f3(353.75f, 0.0f, z - 2.0f);
					boxfence4->end = f3(354.25f, 3.0f, z + 2.0f);

					list.push_back(*fence);
					list.push_back(*fence2);
					list.push_back(*fence3);
					list.push_back(*fence4);
					blist.push_back(*boxfence);
					blist.push_back(*boxfence2);
					blist.push_back(*boxfence3);
					blist.push_back(*boxfence4);
				}

				{
					Object* fence = (Object*)malloc(sizeof(Object));
					fence->location = f3(306.0, 0.0f, 100.0f + (200.0f - z));
					fence->rotation = f3(0.0f, 0.0f, 0.0f);
					fence->type = Fence12;

					BoundingBox* boxfence = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence->start = f3(305.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
					boxfence->end = f3(306.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

					Object* fence2 = (Object*)malloc(sizeof(Object));
					fence2->location = f3(394.0, 0.0f, 100.0f + (200.0f - z));
					fence2->rotation = f3(0.0f, 0.0f, 0.0f);
					fence2->type = Fence12;

					BoundingBox* boxfence2 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence2->start = f3(393.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
					boxfence2->end = f3(394.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

					Object* fence3 = (Object*)malloc(sizeof(Object));
					fence3->location = f3(346.0, 0.0f, 100.0f + (200.0f - z));
					fence3->rotation = f3(0.0f, 0.0f, 0.0f);
					fence3->type = Fence12;

					BoundingBox* boxfence3 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence3->start = f3(345.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
					boxfence3->end = f3(346.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

					Object* fence4 = (Object*)malloc(sizeof(Object));
					fence4->location = f3(354.0, 0.0f, 100.0f + (200.0f - z));
					fence4->rotation = f3(0.0f, 0.0f, 0.0f);
					fence4->type = Fence12;

					BoundingBox* boxfence4 = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfence4->start = f3(353.75f, 0.0f, 100.0f + (200.0f - z) - 2.0f);
					boxfence4->end = f3(354.25f, 3.0f, 100.0f + (200.0f - z) + 2.0f);

					list.push_back(*fence);
					list.push_back(*fence2);
					list.push_back(*fence3);
					list.push_back(*fence4);
					blist.push_back(*boxfence);
					blist.push_back(*boxfence2);
					blist.push_back(*boxfence3);
					blist.push_back(*boxfence4);
				}
			}

		setAreaHeight(height1_2, x12, z12, 105.5f, 168.5f, 146.5f, 185.5f, 3.0f);

		setAreaHeight(height1_2, x12, z12, 153.5f, 168.5f, 194.5f, 185.5f, 3.0f);

		setAreaHeight(height1_2, x12, z12, 153.5f, 114.5f, 194.5f, 131.5f, 3.0f);

		setAreaHeight(height1_2, x12, z12, 105.5f, 114.5f, 146.5f, 131.5f, 3.0f);
	}

	//좌하단 안드로이드 충전소
	{
	//좌상단 충전소
		{
			Object* floor = (Object*)malloc(sizeof(Object));
			floor->location = f3(200.0, 2.0f, 60.0f);
			floor->rotation = f3(0.0f, 0.0f, 0.0f);
			floor->type = ChargeFloor;

			BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor->start = f3(200.0f, 2.0f, 60.0f);
			boxfloor->end = f3(240.0f, 3.0f, 100.0f);

			Object* floor2 = (Object*)malloc(sizeof(Object));
			floor2->location = f3(200.0, 5.0f, 60.0f);
			floor2->rotation = f3(0.0f, 0.0f, 0.0f);
			floor2->type = ChargeFloor;

			BoundingBox* boxfloor2 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor2->start = f3(200.0f, 5.0f, 60.0f);
			boxfloor2->end = f3(240.0f, 6.0f, 100.0f);

			Object* floor21 = (Object*)malloc(sizeof(Object));
			floor21->location = f3(200.0, 6.0f, 60.0f);
			floor21->rotation = f3(0.0f, 0.0f, 0.0f);
			floor21->type = ChargeFloor2;

			BoundingBox* boxfloor21 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor21->start = f3(200.0f, 5.99f, 60.0f);
			boxfloor21->end = f3(240.0f, 6.0f, 100.0f);

			Object* floor212 = (Object*)malloc(sizeof(Object));
			floor212->location = f3(200.0, 2.0f, 60.0f);
			floor212->rotation = f3(0.0f, 0.0f, 0.0f);
			floor212->type = ChargeFloor2;

			BoundingBox* boxfloor212 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor212->start = f3(200.0f, 1.99f, 60.0f);
			boxfloor212->end = f3(240.0f, 2.0f, 100.0f);

			Object* floor213 = (Object*)malloc(sizeof(Object));
			floor213->location = f3(200.0, 3.0f, 60.0f);
			floor213->rotation = f3(0.0f, 0.0f, 0.0f);
			floor213->type = ChargeFloor2;

			BoundingBox* boxfloor213 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor213->start = f3(200.0f, 2.99f, 60.0f);
			boxfloor213->end = f3(240.0f, 3.0f, 100.0f);

			list.push_back(*floor);
			blist.push_back(*boxfloor);
			list.push_back(*floor2);
			blist.push_back(*boxfloor2);
			list.push_back(*floor21);
			blist.push_back(*boxfloor21);
			list.push_back(*floor212);
			blist.push_back(*boxfloor212);
			list.push_back(*floor213);
			blist.push_back(*boxfloor213);

			for (float x = 200.0f; x < 240.0f; x += 2.0f)
			{
				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 0.0f, 61.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 0.0f, 60.5f);
					boxrobot->end = f3(x + 1.5f, 1.7f, 61.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 3.0f, 61.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 3.0f, 60.5f);
					boxrobot->end = f3(x + 1.5f, 4.7f, 61.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}




			}
			for (float z = 62.0f; z < 99.0f; z += 2.0f)
			{


				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(239.0f, 0.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(238.5f, 0.0f, z + 0.5f);
					boxrobot->end = f3(239.5f, 1.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(239.0f, 3.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(238.5f, 3.0f, z + 0.5f);
					boxrobot->end = f3(239.5f, 4.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
			}
			for (float x = 200.0f; x < 240.0f; x += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(x, 0.0f, 60.0f);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(x, 0.0f, 60.0f);
				boxfan->end = f3(x + 2.0f, 2.0f, 62.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(x, 3.0f, 60.0f);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(x, 3.0f, 60.0f);
				boxfan2->end = f3(x + 2.0f, 5.0f, 62.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}

			for (float z = 62.0f; z < 99.0f; z += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(238.0, 0.0f, z);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(238.0f, 0.0f, z);
				boxfan->end = f3(240.0f, 2.0f, z + 2.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(238.0, 3.0f, z);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(238.0f, 3.0f, z);
				boxfan2->end = f3(240.0f, 5.0f, z + 2.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}


			setAreaHeight(height1_2, x12, z12, 0.0f, 59.5f, 40.5f, 100.0f, 6.0f);

		}

		//우상단 충전소
		{
			Object* floor3 = (Object*)malloc(sizeof(Object));
			floor3->location = f3(260.0, 2.0f, 50.0f);
			floor3->rotation = f3(0.0f, 0.0f, 0.0f);
			floor3->type = ChargeFloor;

			BoundingBox* boxfloor3 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor3->start = f3(260.0f, 2.0f, 50.0f);
			boxfloor3->end = f3(300.0f, 3.0f, 90.0f);

			Object* floor4 = (Object*)malloc(sizeof(Object));
			floor4->location = f3(260.0, 5.0f, 50.0f);
			floor4->rotation = f3(0.0f, 0.0f, 0.0f);
			floor4->type = ChargeFloor;

			BoundingBox* boxfloor4 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor4->start = f3(260.0f, 5.0f, 50.0f);
			boxfloor4->end = f3(300.0f, 6.0f, 90.0f);

			Object* floor22 = (Object*)malloc(sizeof(Object));
			floor22->location = f3(260.0, 6.0f, 50.0f);
			floor22->rotation = f3(0.0f, 0.0f, 0.0f);
			floor22->type = ChargeFloor2;

			BoundingBox* boxfloor22 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor22->start = f3(260.0f, 5.99f, 50.0f);
			boxfloor22->end = f3(300.0f, 6.0f, 90.0f);

			Object* floor222 = (Object*)malloc(sizeof(Object));
			floor222->location = f3(260.0, 2.0f, 50.0f);
			floor222->rotation = f3(0.0f, 0.0f, 0.0f);
			floor222->type = ChargeFloor2;

			BoundingBox* boxfloor222 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor222->start = f3(260.0f, 1.99f, 50.0f);
			boxfloor222->end = f3(300.0f, 2.0f, 90.0f);

			Object* floor223 = (Object*)malloc(sizeof(Object));
			floor223->location = f3(260.0, 3.0f, 50.0f);
			floor223->rotation = f3(0.0f, 0.0f, 0.0f);
			floor223->type = ChargeFloor2;

			BoundingBox* boxfloor223 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor223->start = f3(260.0f, 2.99f, 50.0f);
			boxfloor223->end = f3(300.0f, 3.0f, 90.0f);

			list.push_back(*floor3);
			blist.push_back(*boxfloor3);
			list.push_back(*floor4);
			blist.push_back(*boxfloor4);
			list.push_back(*floor22);
			blist.push_back(*boxfloor22);
			list.push_back(*floor222);
			blist.push_back(*boxfloor222);
			list.push_back(*floor223);
			blist.push_back(*boxfloor223);

			for (float x = 260.0f; x < 300.0f; x += 2.0f)
			{

				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 0.0f, 89.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 0.0f, 88.5f);
					boxrobot->end = f3(x + 1.5f, 1.7f, 89.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 3.0f, 89.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 3.0f, 88.5f);
					boxrobot->end = f3(x + 1.5f, 4.7f, 89.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
			}
			for (float z = 50.0f; z < 87.0f; z += 2.0f)
			{
				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(261.0f, 0.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(260.5f, 0.0f, z + 0.5f);
					boxrobot->end = f3(261.5f, 1.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(261.0f, 3.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(260.5f, 3.0f, z + 0.5f);
					boxrobot->end = f3(261.5f, 4.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}



			}
			for (float x = 260.0f; x < 300.0f; x += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(x, 0.0f, 88.0f);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(x, 0.0f, 88.0f);
				boxfan->end = f3(x + 2.0f, 2.0f, 90.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(x, 3.0f, 88.0f);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(x, 3.0f, 88.0f);
				boxfan2->end = f3(x + 2.0f, 5.0f, 90.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}

			for (float z = 50.0f; z < 87.0f; z += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(260.0, 0.0f, z);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(260.0f, 0.0f, z);
				boxfan->end = f3(262.0f, 2.0f, z + 2.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(260.0, 3.0f, z);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(260.0f, 3.0f, z);
				boxfan2->end = f3(262.0f, 5.0f, z + 2.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}


			setAreaHeight(height1_2, x12, z12, 59.5f, 50.0f, 100.0f, 90.5f, 6.0f);
		}

		//좌하단 에너지실드
		{
			for (float z = 2.5f; z < 45.0f; z += 5.0f)
			{
				int ir = rand() % 2;
				if (ir)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(204.0, 0.0f, z);
					floor->rotation = f3(0.0f, 270.0f, 0.0f);
					floor->type = Shield;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(203.75f, 0.0f, z - 0.4f);
					boxfloor->end = f3(204.25f, 2.0f, z + 0.4f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}
				else
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(204.0, 0.0f, z);
					floor->rotation = f3(0.0f, 270.0f, 0.0f);
					floor->type = BigShield;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(203.75f, 0.0f, z - 2.0f);
					boxfloor->end = f3(204.25f, 2.0f, z + 2.0f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}

				int ir2 = rand() % 3;
				if (ir == 0)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(200.25, 0.0f, z);
					floor->rotation = f3(0.0f, 0.0f, 0.0f);
					floor->type = Controller12_1;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(200.0f, 0.0f, z - 0.75f);
					boxfloor->end = f3(200.5f, 1.75f, z + 0.75f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}
				else if (ir == 1)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(200.25, 0.0f, z);
					floor->rotation = f3(0.0f, 0.0f, 0.0f);
					floor->type = Controller12_2;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(200.0f, 0.0f, z - 0.25f);
					boxfloor->end = f3(200.5f, 0.85f, z + 0.25f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}
				else if (ir == 2)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(200.25, 0.0f, z);
					floor->rotation = f3(0.0f, 0.0f, 0.0f);
					floor->type = Controller12_4;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(200.0f, 0.0f, z - 0.5f);
					boxfloor->end = f3(200.5f, 0.9f, z + 0.5f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}


			}
			for (float z = 2.0f; z <= 46.1f; z += 4.0f)
			{

				Object* floor = (Object*)malloc(sizeof(Object));
				floor->location = f3(208.0, 0.0f, z);
				floor->rotation = f3(0.0f, 0.0f, 0.0f);
				floor->type = Fence12;

				BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfloor->start = f3(207.75f, 0.0f, z - 2.0f);
				boxfloor->end = f3(208.25f, 3.0f, z + 2.0f);

				list.push_back(*floor);
				blist.push_back(*boxfloor);
			}

			for (float x = 202.0f; x < 206.1f; x += 4.0f)
			{
				Object* floor = (Object*)malloc(sizeof(Object));
				floor->location = f3(x, 0.0f, 48.0f);
				floor->rotation = f3(0.0f, 90.0f, 0.0f);
				floor->type = Fence12;

				BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfloor->start = f3(x - 2.0f, 0.0f, 47.75f);
				boxfloor->end = f3(x + 2.0f, 3.0f, 48.25f);

				list.push_back(*floor);
				blist.push_back(*boxfloor);
			}

			setAreaHeight(height1_2, x12, z12, 0.0f, 0.0f, 8.5f, 48.5f, 5.0f);
		}

		//위층 올라가는길

		for (float z = 10.75f; z < 40.0f; z += 1.5f)
		{
			for (float x = 241.75f; x < 244.0f; x += 1.5f)
			{
				Object* box = (Object*)malloc(sizeof(Object));
				box->location = f3(x, 0.0f, z);
				box->rotation = f3(0.0f, 90.0f, 0.0f);
				box->type = Box12;

				BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbox->start = f3(x - 1.0f, 0.0f, z - 1.0f);
				boxbox->end = f3(x + 1.0f, 1.5f, z + 1.0f);

				Object* box2 = (Object*)malloc(sizeof(Object));
				box2->location = f3(x + 6.0f, 3.0f, z);
				box2->rotation = f3(0.0f, 90.0f, 0.0f);
				box2->type = Box12;

				BoundingBox* boxbox2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbox2->start = f3(x + 5.0f, 3.0f, z - 1.0f);
				boxbox2->end = f3(x + 7.0f, 4.5f, z + 1.0f);

				list.push_back(*box);
				blist.push_back(*boxbox);
				list.push_back(*box2);
				blist.push_back(*boxbox2);
			}
		}
		for (float z = 13.0f; z < 40.0f; z += 6.0f)
		{
			for (float x = 245.5f; x < 250.0f; x += 3.0f)
			{
				Object* box = (Object*)malloc(sizeof(Object));
				box->location = f3(x, 0.0f, z);
				box->rotation = f3(0.0f, 0.0f, 0.0f);
				box->type = Container12;

				BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbox->start = f3(x - 1.5f, 0.0f, z - 3.0f);
				boxbox->end = f3(x + 1.5f, 3.0f, z + 3.0f);

				list.push_back(*box);
				blist.push_back(*boxbox);
			}
		}
		setAreaHeight(height1_2, x12, z12, 40.5f, 9.5f, 50.0f, 40.5f, 1.5f);
		setAreaHeight(height1_2, x12, z12, 43.5f, 9.5f, 50.0f, 40.5f, 3.0f);
		setAreaHeight(height1_2, x12, z12, 46.5f, 9.5f, 50.0f, 40.5f, 4.5f);
	}
	
	//우하단 안드로이드 충전소
	{
	//우상단 충전소
		{
			Object* floor = (Object*)malloc(sizeof(Object));
			floor->location = f3(360.0, 2.0f, 60.0f);
			floor->rotation = f3(0.0f, 0.0f, 0.0f);
			floor->type = ChargeFloor;

			BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor->start = f3(360.0f, 2.0f, 60.0f);
			boxfloor->end = f3(400.0f, 3.0f, 100.0f);

			Object* floor2 = (Object*)malloc(sizeof(Object));
			floor2->location = f3(360.0, 5.0f, 60.0f);
			floor2->rotation = f3(0.0f, 0.0f, 0.0f);
			floor2->type = ChargeFloor;

			BoundingBox* boxfloor2 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor2->start = f3(360.0f, 5.0f, 60.0f);
			boxfloor2->end = f3(400.0f, 6.0f, 100.0f);

			Object* floor21 = (Object*)malloc(sizeof(Object));
			floor21->location = f3(360.0, 6.0f, 60.0f);
			floor21->rotation = f3(0.0f, 0.0f, 0.0f);
			floor21->type = ChargeFloor2;

			BoundingBox* boxfloor21 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor21->start = f3(360.0f, 5.99f, 60.0f);
			boxfloor21->end = f3(400.0f, 6.0f, 100.0f);

			Object* floor212 = (Object*)malloc(sizeof(Object));
			floor212->location = f3(360.0, 2.0f, 60.0f);
			floor212->rotation = f3(0.0f, 0.0f, 0.0f);
			floor212->type = ChargeFloor2;

			BoundingBox* boxfloor212 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor212->start = f3(360.0f, 1.99f, 60.0f);
			boxfloor212->end = f3(400.0f, 2.0f, 100.0f);

			Object* floor213 = (Object*)malloc(sizeof(Object));
			floor213->location = f3(360.0, 3.0f, 60.0f);
			floor213->rotation = f3(0.0f, 0.0f, 0.0f);
			floor213->type = ChargeFloor2;

			BoundingBox* boxfloor213 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor213->start = f3(360.0f, 2.99f, 60.0f);
			boxfloor213->end = f3(400.0f, 3.0f, 100.0f);

			list.push_back(*floor);
			blist.push_back(*boxfloor);
			list.push_back(*floor2);
			blist.push_back(*boxfloor2);
			list.push_back(*floor21);
			blist.push_back(*boxfloor21);
			list.push_back(*floor212);
			blist.push_back(*boxfloor212);
			list.push_back(*floor213);
			blist.push_back(*boxfloor213);

			for (float x = 360.0f; x < 400.0f; x += 2.0f)
			{
				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 0.0f, 61.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 0.0f, 60.5f);
					boxrobot->end = f3(x + 1.5f, 1.7f, 61.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 3.0f, 61.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 3.0f, 60.5f);
					boxrobot->end = f3(x + 1.5f, 4.7f, 61.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}




			}
			for (float z = 62.0f; z < 99.0f; z += 2.0f)
			{


				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(361.0f, 0.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(360.5f, 0.0f, z + 0.5f);
					boxrobot->end = f3(361.5f, 1.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(361.0f, 3.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(360.5f, 3.0f, z + 0.5f);
					boxrobot->end = f3(361.5f, 4.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
			}
			for (float x = 360.0f; x < 400.0f; x += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(x, 0.0f, 60.0f);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(x, 0.0f, 60.0f);
				boxfan->end = f3(x + 2.0f, 2.0f, 62.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(x, 3.0f, 60.0f);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(x, 3.0f, 60.0f);
				boxfan2->end = f3(x + 2.0f, 5.0f, 62.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}

			for (float z = 62.0f; z < 99.0f; z += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(360.0, 0.0f, z);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(360.0f, 0.0f, z);
				boxfan->end = f3(362.0f, 2.0f, z + 2.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(360.0, 3.0f, z);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(360.0f, 3.0f, z);
				boxfan2->end = f3(362.0f, 5.0f, z + 2.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}


			setAreaHeight(height1_2, x12, z12, 159.5f, 59.5f, 200.0f, 100.0f, 6.0f);

		}



		//좌상단 충전소
		{
			Object* floor3 = (Object*)malloc(sizeof(Object));
			floor3->location = f3(300.0, 2.0f, 50.0f);
			floor3->rotation = f3(0.0f, 0.0f, 0.0f);
			floor3->type = ChargeFloor;

			BoundingBox* boxfloor3 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor3->start = f3(300.0f, 2.0f, 50.0f);
			boxfloor3->end = f3(340.0f, 3.0f, 90.0f);

			Object* floor4 = (Object*)malloc(sizeof(Object));
			floor4->location = f3(300.0, 5.0f, 50.0f);
			floor4->rotation = f3(0.0f, 0.0f, 0.0f);
			floor4->type = ChargeFloor;

			BoundingBox* boxfloor4 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor4->start = f3(300.0f, 5.0f, 50.0f);
			boxfloor4->end = f3(340.0f, 6.0f, 90.0f);

			Object* floor22 = (Object*)malloc(sizeof(Object));
			floor22->location = f3(300.0, 6.0f, 50.0f);
			floor22->rotation = f3(0.0f, 0.0f, 0.0f);
			floor22->type = ChargeFloor2;

			BoundingBox* boxfloor22 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor22->start = f3(300.0f, 5.99f, 50.0f);
			boxfloor22->end = f3(340.0f, 6.0f, 90.0f);

			Object* floor222 = (Object*)malloc(sizeof(Object));
			floor222->location = f3(300.0, 2.0f, 50.0f);
			floor222->rotation = f3(0.0f, 0.0f, 0.0f);
			floor222->type = ChargeFloor2;

			BoundingBox* boxfloor222 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor222->start = f3(300.0f, 1.99f, 50.0f);
			boxfloor222->end = f3(340.0f, 2.0f, 90.0f);

			Object* floor223 = (Object*)malloc(sizeof(Object));
			floor223->location = f3(300.0, 3.0f, 50.0f);
			floor223->rotation = f3(0.0f, 0.0f, 0.0f);
			floor223->type = ChargeFloor2;

			BoundingBox* boxfloor223 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxfloor223->start = f3(300.0f, 2.99f, 50.0f);
			boxfloor223->end = f3(340.0f, 3.0f, 90.0f);

			list.push_back(*floor3);
			blist.push_back(*boxfloor3);
			list.push_back(*floor4);
			blist.push_back(*boxfloor4);
			list.push_back(*floor22);
			blist.push_back(*boxfloor22);
			list.push_back(*floor222);
			blist.push_back(*boxfloor222);
			list.push_back(*floor223);
			blist.push_back(*boxfloor223);

			for (float x = 300.0f; x < 340.0f; x += 2.0f)
			{

				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 0.0f, 89.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 0.0f, 88.5f);
					boxrobot->end = f3(x + 1.5f, 1.7f, 89.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(x + 1.0f, 3.0f, 89.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(x + 0.5f, 3.0f, 88.5f);
					boxrobot->end = f3(x + 1.5f, 4.7f, 89.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
			}
			for (float z = 50.0f; z < 87.0f; z += 2.0f)
			{
				int ir = rand() % 2;
				if (ir)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(339.0f, 0.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(338.5f, 0.0f, z + 0.5f);
					boxrobot->end = f3(339.5f, 1.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}
				int ir2 = rand() % 2;
				if (ir2)
				{
					Object* robot = (Object*)malloc(sizeof(Object));
					robot->location = f3(339.0f, 3.0f, z + 1.0f);
					robot->rotation = f3(0.0f, 0.0f, 0.0f);
					robot->type = ChargingRobot;

					BoundingBox* boxrobot = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxrobot->start = f3(338.5f, 3.0f, z + 0.5f);
					boxrobot->end = f3(339.5f, 4.7f, z + 1.5f);

					list.push_back(*robot);
					blist.push_back(*boxrobot);
				}



			}
			for (float x = 300.0f; x < 340.0f; x += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(x, 0.0f, 88.0f);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(x, 0.0f, 88.0f);
				boxfan->end = f3(x + 2.0f, 2.0f, 90.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(x, 3.0f, 88.0f);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(x, 3.0f, 88.0f);
				boxfan2->end = f3(x + 2.0f, 5.0f, 90.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}

			for (float z = 50.0f; z < 87.0f; z += 2.0f)
			{
				Object* fan = (Object*)malloc(sizeof(Object));
				fan->location = f3(338.0, 0.0f, z);
				fan->rotation = f3(0.0f, 0.0f, 0.0f);
				fan->type = ChargeSlot;

				BoundingBox* boxfan = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan->start = f3(338.0f, 0.0f, z);
				boxfan->end = f3(340.0f, 2.0f, z + 2.0f);

				Object* fan2 = (Object*)malloc(sizeof(Object));
				fan2->location = f3(338.0, 3.0f, z);
				fan2->rotation = f3(0.0f, 0.0f, 0.0f);
				fan2->type = ChargeSlot;

				BoundingBox* boxfan2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfan2->start = f3(338.0f, 3.0f, z);
				boxfan2->end = f3(340.0f, 5.0f, z + 2.0f);

				list.push_back(*fan);
				blist.push_back(*boxfan);
				list.push_back(*fan2);
				blist.push_back(*boxfan2);
			}


			setAreaHeight(height1_2, x12, z12, 100.0f, 50.0f, 140.5f, 90.5f, 6.0f);
		}

		//우하단 에너지실드
		{
			for (float z = 2.5f; z < 45.0f; z += 5.0f)
			{
				int ir = rand() % 2;
				if (ir)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(396.0, 0.0f, z);
					floor->rotation = f3(0.0f, 90.0f, 0.0f);
					floor->type = Shield;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(395.75f, 0.0f, z - 0.4f);
					boxfloor->end = f3(396.25f, 2.0f, z + 0.4f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}
				else
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(396.0, 0.0f, z);
					floor->rotation = f3(0.0f, 90.0f, 0.0f);
					floor->type = BigShield;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(395.75f, 0.0f, z - 2.0f);
					boxfloor->end = f3(396.25f, 2.0f, z + 2.0f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}

				int ir2 = rand() % 3;
				if (ir == 0)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(399.75, 0.0f, z);
					floor->rotation = f3(0.0f, 180.0f, 0.0f);
					floor->type = Controller12_1;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(399.5f, 0.0f, z - 0.75f);
					boxfloor->end = f3(400.0f, 1.75f, z + 0.75f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}
				else if (ir == 1)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(399.75, 0.0f, z);
					floor->rotation = f3(0.0f, 180.0f, 0.0f);
					floor->type = Controller12_2;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(399.5f, 0.0f, z - 0.25f);
					boxfloor->end = f3(400.0f, 0.85f, z + 0.25f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}
				else if (ir == 2)
				{
					Object* floor = (Object*)malloc(sizeof(Object));
					floor->location = f3(399.75, 0.0f, z);
					floor->rotation = f3(0.0f, 180.0f, 0.0f);
					floor->type = Controller12_4;

					BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
					boxfloor->start = f3(399.5f, 0.0f, z - 0.5f);
					boxfloor->end = f3(400.0f, 0.9f, z + 0.5f);

					list.push_back(*floor);
					blist.push_back(*boxfloor);
				}


			}
			for (float z = 2.0f; z <= 46.1f; z += 4.0f)
			{

				Object* floor = (Object*)malloc(sizeof(Object));
				floor->location = f3(392.0, 0.0f, z);
				floor->rotation = f3(0.0f, 0.0f, 0.0f);
				floor->type = Fence12;

				BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfloor->start = f3(391.75f, 0.0f, z - 2.0f);
				boxfloor->end = f3(392.25f, 3.0f, z + 2.0f);

				list.push_back(*floor);
				blist.push_back(*boxfloor);
			}

			for (float x = 398.0f; x > 393.9f; x -= 4.0f)
			{
				Object* floor = (Object*)malloc(sizeof(Object));
				floor->location = f3(x, 0.0f, 48.0f);
				floor->rotation = f3(0.0f, 90.0f, 0.0f);
				floor->type = Fence12;

				BoundingBox* boxfloor = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxfloor->start = f3(x - 2.0f, 0.0f, 47.75f);
				boxfloor->end = f3(x + 2.0f, 3.0f, 48.25f);

				list.push_back(*floor);
				blist.push_back(*boxfloor);
			}

			setAreaHeight(height1_2, x12, z12, 191.5f, 0.0f, 200.0f, 48.5f, 5.0f);
		}

		//위층 올라가는길

		for (float z = 10.75f; z < 40.0f; z += 1.5f)
		{
			for (float x = 358.25f; x > 356.0f; x -= 1.5f)
			{
				Object* box = (Object*)malloc(sizeof(Object));
				box->location = f3(x, 0.0f, z);
				box->rotation = f3(0.0f, 90.0f, 0.0f);
				box->type = Box12;

				BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbox->start = f3(x - 1.0f, 0.0f, z - 1.0f);
				boxbox->end = f3(x + 1.0f, 1.5f, z + 1.0f);

				Object* box2 = (Object*)malloc(sizeof(Object));
				box2->location = f3(x - 6.0f, 3.0f, z);
				box2->rotation = f3(0.0f, 90.0f, 0.0f);
				box2->type = Box12;

				BoundingBox* boxbox2 = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbox2->start = f3(x - 5.0f, 3.0f, z - 1.0f);
				boxbox2->end = f3(x - 7.0f, 4.5f, z + 1.0f);

				list.push_back(*box);
				blist.push_back(*boxbox);
				list.push_back(*box2);
				blist.push_back(*boxbox2);
			}
		}
		for (float z = 13.0f; z < 40.0f; z += 6.0f)
		{
			for (float x = 354.5f; x > 350.0f; x -= 3.0f)
			{
				Object* box = (Object*)malloc(sizeof(Object));
				box->location = f3(x, 0.0f, z);
				box->rotation = f3(0.0f, 0.0f, 0.0f);
				box->type = Container12;

				BoundingBox* boxbox = (BoundingBox*)malloc(sizeof(BoundingBox));
				boxbox->start = f3(x - 1.5f, 0.0f, z - 3.0f);
				boxbox->end = f3(x + 1.5f, 3.0f, z + 3.0f);

				list.push_back(*box);
				blist.push_back(*boxbox);
			}
		}
		setAreaHeight(height1_2, x12, z12, 150.0f, 9.5f, 159.5f, 40.5f, 1.5f);
		setAreaHeight(height1_2, x12, z12, 150.0f, 9.5f, 156.5f, 40.5f, 3.0f);
		setAreaHeight(height1_2, x12, z12, 150.0f, 9.5f, 153.5f, 40.5f, 4.5f);
	}
}



void createObstacles1_3(vector<Object>& list, vector<BoundingBox>& blist)
{
	//컨테이너
	Object* cont = (Object*)malloc(sizeof(Object));
	cont->location = f3(530.0f, -10.0f, 281.0f);
	cont->rotation = f3(90.0f, 0.0f, 0.0f);
	cont->type = Container13;

	BoundingBox* boxcont = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxcont->start = f3(530.0f - 2.0f, 0.0f, 281.0f - 1.0f);
	boxcont->end = f3(530.0f + 2.0f, 2.0f, 281.0f + 1.0f);
	setAreaHeight(height1_3, x13, z13, 530.0f - 2.0f, 281.0f - 1.0f, 530.0f + 2.0f, 281.0f + 1.0f, 2.0f);

	list.push_back(*cont);
	blist.push_back(*boxcont);

	Object* cont2 = (Object*)malloc(sizeof(Object));
	cont2->location = f3(400.0f, -10.0f, 200.0f);
	cont2->rotation = f3(90.0f, 90.0f, 0.0f);
	cont2->type = Container13;

	BoundingBox* boxcont2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	boxcont2->start = f3(400.0f - 2.0f, 0.0f, 200.0f - 1.0f);
	boxcont2->end = f3(400.0f + 2.0f, 2.0f, 200.0f + 1.0f);
	setAreaHeight(height1_3, x13, z13, 400.0f - 2.0f, 200.0f - 1.0f, 400.0f + 2.0f, 200.0f + 1.0f, 2.0f);


	list.push_back(*cont2);
	blist.push_back(*boxcont2);

	//선반

	for (float z = 310.0f; z < 360.0f; z += 8.0f) {
		for (float x = 450.0f; x < 500.0f; x += 15.0f) {
			Object* shelf2 = (Object*)malloc(sizeof(Object));
			shelf2->location = f3(x, 2.5f, z);
			shelf2->rotation = f3(-90.0f, 0.0f, -90.0f);
			shelf2->type = Shelf02;

			BoundingBox* boxshelf2 = (BoundingBox*)malloc(sizeof(BoundingBox));
			boxshelf2->start = f3(x - 2.0f, 2.5f, z - 1.0f);
			boxshelf2->end = f3(x + 2.0f, 5.0f, z + 1.0f);
			setAreaHeight(height1_3, x13, z13, x - 2.0f, z - 1.0f, x + 2.0f, z + 1.0f, 2.0f);

			list.push_back(*shelf2);
			blist.push_back(*boxshelf2);
		}
	}
}

void createObstacles2_1(vector<Object>& list, vector<BoundingBox>& blist)
{


	Object* Kwan_wall00 = (Object*)malloc(sizeof(Object));
	Kwan_wall00->location = f3(799.6f, 3.75f, 602.5f);
	Kwan_wall00->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall00->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall00 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall00->start = f3(800.0f, 0.0f, 592.5f);
	Gwangjae_wall00->end = f3(801.0f, 7.5f, 612.5f);
	setAreaHeight(height2_1, x21, z21, 0.5f, 229.5f, 1.0f, 249.5f, 7.5f);

	Object* Kwan_wall0 = (Object*)malloc(sizeof(Object));
	Kwan_wall0->location = f3(799.6f, 3.75f, 582.5f);
	Kwan_wall0->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall0->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall0 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall0->start = f3(800.0f, 0.0f, 572.5f);
	Gwangjae_wall0->end = f3(801.0f, 7.5f, 592.5f);
	setAreaHeight(height2_1, x21, z21, 0.5f, 209.5f, 1.0f, 229.5f, 7.5f);

	///////////////////////////////
	Object* Kwan_wall1 = (Object*)malloc(sizeof(Object));
	Kwan_wall1->location = f3(812.1f, 3.75f, 535.0f);
	Kwan_wall1->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1->start = f3(812.0f, 0.0f, 525.0f);
	Gwangjae_wall1->end = f3(813.0f, 7.5f, 545.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 162.0f, 13.0f, 182.0f, 7.5f);

	////////////
	Object* Kwan_wall2 = (Object*)malloc(sizeof(Object));
	Kwan_wall2->location = f3(812.1f, 3.75f, 515.0f);
	Kwan_wall2->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2->start = f3(812.0f, 0.0f, 505.0f);
	Gwangjae_wall2->end = f3(813.0f, 7.5f, 525.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 142.0f, 13.0f, 162.0f, 7.5f);

	////////////////////
	Object* Kwan_wall3 = (Object*)malloc(sizeof(Object));
	Kwan_wall3->location = f3(812.1f, 3.75f, 495.0f);
	Kwan_wall3->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3->start = f3(812.0f, 0.0f, 485.0f);
	Gwangjae_wall3->end = f3(813.0f, 7.5f, 505.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 122.0f, 13.0f, 142.0f, 7.5f);

	///////////////////////////////

	Object* Kwan_wall4 = (Object*)malloc(sizeof(Object));
	Kwan_wall4->location = f3(812.1f, 3.75f, 475.0f);
	Kwan_wall4->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4->start = f3(812.0f, 0.0f, 465.0f);
	Gwangjae_wall4->end = f3(813.0f, 7.5f, 485.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 102.0f, 13.0f, 122.0f, 7.5f);

	/////////////////////////////////

	Object* Kwan_wall5 = (Object*)malloc(sizeof(Object));
	Kwan_wall5->location = f3(812.1f, 3.75f, 455.0f);
	Kwan_wall5->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5->start = f3(812.0f, 0.0f, 445.0f);
	Gwangjae_wall5->end = f3(813.0f, 7.5f, 465.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 82.0f, 13.0f, 102.0f, 7.5f);

	Object* Kwan_wall6 = (Object*)malloc(sizeof(Object));
	Kwan_wall6->location = f3(812.1f, 3.75f, 435.0f);
	Kwan_wall6->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6->start = f3(812.0f, 0.0f, 425.0f);
	Gwangjae_wall6->end = f3(813.0f, 7.5f, 445.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 62.0f, 13.0f, 82.0f, 7.5f);

	Object* Kwan_wall7 = (Object*)malloc(sizeof(Object));
	Kwan_wall7->location = f3(812.1f, 3.75f, 415.0f);
	Kwan_wall7->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7->start = f3(812.0f, 0.0f, 405.0f);
	Gwangjae_wall7->end = f3(813.0f, 7.5f, 425.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 42.0f, 13.0f, 62.0f, 7.5f);

	Object* Kwan_wall8 = (Object*)malloc(sizeof(Object));
	Kwan_wall8->location = f3(812.1f, 3.75f, 395.0f);
	Kwan_wall8->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8->start = f3(812.0f, 0.0f, 385.0f);
	Gwangjae_wall8->end = f3(813.0f, 7.5f, 405.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 22.0f, 13.0f, 42.0f, 7.5f);

	Object* Kwan_wall9 = (Object*)malloc(sizeof(Object));
	Kwan_wall9->location = f3(812.1f, 3.75f, 375.0f);
	Kwan_wall9->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9->start = f3(812.0f, 0.0f, 365.0f);
	Gwangjae_wall9->end = f3(813.0f, 7.5f, 385.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 2.0f, 13.0f, 22.0f, 7.5f);


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
	Gwangjae_wall1L->start = f3(874.9f, 0.0f, 585.0f);
	Gwangjae_wall1L->end = f3(875.4f, 7.5f, 605.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 222.0f, 75.0f, 242.0f, 7.5f);

	Object* Kwan_wall2L = (Object*)malloc(sizeof(Object));
	Kwan_wall2L->location = f3(875.4f, 3.75f, 575.0f);
	Kwan_wall2L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall2L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2L->start = f3(874.9f, 0.0f, 565.0f);
	Gwangjae_wall2L->end = f3(875.4f, 7.5f, 585.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 202.0f, 75.0f, 222.0f, 7.5f);

	Object* Kwan_wall3L = (Object*)malloc(sizeof(Object));
	Kwan_wall3L->location = f3(875.4f, 3.75f, 555.0f);
	Kwan_wall3L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall3L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3L->start = f3(874.9f, 0.0f, 545.0f);
	Gwangjae_wall3L->end = f3(875.4f, 7.5f, 565.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 182.0f, 75.0f, 202.0f, 7.5f);

	Object* Kwan_wall4L = (Object*)malloc(sizeof(Object));
	Kwan_wall4L->location = f3(875.4f, 3.75f, 535.0f);
	Kwan_wall4L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall4L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4L->start = f3(874.9f, 0.0f, 525.0f);
	Gwangjae_wall4L->end = f3(875.4f, 7.5f, 545.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 162.0f, 75.0f, 182.0f, 7.5f);

	Object* Kwan_wall5L = (Object*)malloc(sizeof(Object));
	Kwan_wall5L->location = f3(875.4f, 3.75f, 515.0f);
	Kwan_wall5L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall5L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5L->start = f3(874.9f, 0.0f, 505.0f);
	Gwangjae_wall5L->end = f3(875.4f, 7.5f, 525.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 142.0f, 75.0f, 162.0f, 7.5f);

	Object* Kwan_wall6L = (Object*)malloc(sizeof(Object));
	Kwan_wall6L->location = f3(875.4f, 3.75f, 495.0f);
	Kwan_wall6L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall6L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6L->start = f3(874.9f, 0.0f, 485.0f);
	Gwangjae_wall6L->end = f3(875.4f, 7.5f, 505.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 122.0f, 75.0f, 142.0f, 7.5f);

	Object* Kwan_wall7L = (Object*)malloc(sizeof(Object));
	Kwan_wall7L->location = f3(875.4f, 3.75f, 475.0f);
	Kwan_wall7L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall7L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7L->start = f3(874.9f, 0.0f, 465.0f);
	Gwangjae_wall7L->end = f3(875.4f, 7.5f, 485.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 102.0f, 75.0f, 122.0f, 7.5f);

	Object* Kwan_wall8L = (Object*)malloc(sizeof(Object));
	Kwan_wall8L->location = f3(875.4f, 3.75f, 455.0f);
	Kwan_wall8L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall8L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8L->start = f3(874.9f, 0.0f, 445.0f);
	Gwangjae_wall8L->end = f3(875.4f, 7.5f, 465.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 82.0f, 75.0f, 102.0f, 7.5f);

	Object* Kwan_wall9L = (Object*)malloc(sizeof(Object));
	Kwan_wall9L->location = f3(875.4f, 3.75f, 435.0f);
	Kwan_wall9L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall9L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9L->start = f3(874.9f, 0.0f, 425.0f);
	Gwangjae_wall9L->end = f3(875.4f, 10.0f, 445.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 62.0f, 75.0f, 82.0f, 10.0f);

	Object* Kwan_wall10L = (Object*)malloc(sizeof(Object));
	Kwan_wall10L->location = f3(875.4f, 3.75f, 415.0f);
	Kwan_wall10L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall10L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall10L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall10L->start = f3(874.9f, 0.0f, 405.0f);
	Gwangjae_wall10L->end = f3(875.4f, 10.0f, 425.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 42.0f, 75.0f, 62.0f, 10.0f);

	Object* Kwan_wall11L = (Object*)malloc(sizeof(Object));
	Kwan_wall11L->location = f3(875.4f, 3.75f, 395.0f);
	Kwan_wall11L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall11L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall11L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall11L->start = f3(874.9f, 0.0f, 385.0f);
	Gwangjae_wall11L->end = f3(875.4f, 10.0f, 405.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 22.0f, 75.0f, 42.0f, 10.0f);

	Object* Kwan_wall12L = (Object*)malloc(sizeof(Object));
	Kwan_wall12L->location = f3(875.4f, 3.75f, 375.0f);
	Kwan_wall12L->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall12L->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall12L = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall12L->start = f3(874.9f, 0.0f, 365.0f);
	Gwangjae_wall12L->end = f3(875.4f, 10.0f, 385.0f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 2.0f, 75.0f, 22.0f, 10.0f);

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
	setAreaHeight(height2_1, x21, z21, 0.5f, 236.0f, 15.0f, 237.0f, 10.0f);

	Object* Kwan_wall2F = (Object*)malloc(sizeof(Object));
	Kwan_wall2F->location = f3(825.0f, 3.75f, 599.6f);
	Kwan_wall2F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall2F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall2F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2F->start = f3(815.0f, 0.0f, 599.1f);
	Gwangjae_wall2F->end = f3(835.0f, 10.0f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 15.0f, 236.0f, 35.0f, 237.0f, 10.0f);

	Object* Kwan_wall3F = (Object*)malloc(sizeof(Object));
	Kwan_wall3F->location = f3(845.0f, 3.75f, 599.6f);
	Kwan_wall3F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall3F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall3F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3F->start = f3(835.0f, 0.0f, 599.1f);
	Gwangjae_wall3F->end = f3(855.0f, 10.0f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 35.0f, 236.0f, 55.0f, 237.0f, 10.0f);

	Object* Kwan_wall4F = (Object*)malloc(sizeof(Object));
	Kwan_wall4F->location = f3(865.0f, 3.75f, 599.6f);
	Kwan_wall4F->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wall4F->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wall4F = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4F->start = f3(855.0f, 0.0f, 599.1f);
	Gwangjae_wall4F->end = f3(875.0f, 10.0f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 55.0f, 236.0f, 75.0f, 237.0f, 10.0f);


	///////////////////////////////////////////////////
// 바닥

	Object* Kwan_floor1 = (Object*)malloc(sizeof(Object));
	Kwan_floor1->location = f3(800.0f, 0.001f, 540.0f);
	Kwan_floor1->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_floor1->type = Gwanja_floor;

	BoundingBox* Gwangjae_floor1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_floor1->start = f3(800.0f, 0.00f, 540.0f);
	Gwangjae_floor1->end = f3(875.0f, 0.000f, 600.0f);
	setAreaHeight(height2_1, x21, z21, 0.5f, 177.0f, 75.0f, 237.0f, 0.0f);


	/////////////////////////////////////////////////////////
	// 벽

	Object* Kwan_front1 = (Object*)malloc(sizeof(Object));
	Kwan_front1->location = f3(822.916f, 7.5f, 539.0f); // 20.833
	Kwan_front1->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front1->type = Gwanja_front;

	BoundingBox* Gwangjae_front1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front1->start = f3(812.5f, 2.5f, 538.0f);
	Gwangjae_front1->end = f3(833.333f, 12.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 175.0f, 33.5f, 177.0f, 12.5f);

	Object* Kwan_front2 = (Object*)malloc(sizeof(Object));
	Kwan_front2->location = f3(843.799f, 7.5f, 539.0f);
	Kwan_front2->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front2->type = Gwanja_front;

	BoundingBox* Gwangjae_front2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front2->start = f3(833.333f, 2.5f, 538.0f);
	Gwangjae_front2->end = f3(854.166f, 12.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 175.0f, 54.5f, 177.0f, 12.5f);

	Object* Kwan_front3 = (Object*)malloc(sizeof(Object));
	Kwan_front3->location = f3(864.633f, 7.5f, 539.0f);
	Kwan_front3->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front3->type = Gwanja_front;

	BoundingBox* Gwangjae_front3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front3->start = f3(854.166f, 2.5f, 538.0f);
	Gwangjae_front3->end = f3(875.0f, 12.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 54.5f, 175.0f, 75.0f, 177.0f, 12.5f);


	///////////////////////////////////////////////////////////////


	Object* Kwan_front4 = (Object*)malloc(sizeof(Object));
	Kwan_front4->location = f3(822.916f, 7.5f, 481.0f); // 20.833
	Kwan_front4->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front4->type = Gwanja_front;

	BoundingBox* Gwangjae_front4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front4->start = f3(812.5f, 2.5f, 480.0f);
	Gwangjae_front4->end = f3(833.333f, 12.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 117.0f, 33.5f, 119.0f, 12.5f);

	Object* Kwan_front5 = (Object*)malloc(sizeof(Object));
	Kwan_front5->location = f3(843.799f, 7.5f, 481.0f);
	Kwan_front5->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front5->type = Gwanja_front;

	BoundingBox* Gwangjae_front5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front5->start = f3(833.333f, 2.5f, 480.0f);
	Gwangjae_front5->end = f3(854.166f, 12.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 117.0f, 54.5f, 119.0f, 12.5f);

	Object* Kwan_front6 = (Object*)malloc(sizeof(Object));
	Kwan_front6->location = f3(864.633f, 7.5f, 481.0f);
	Kwan_front6->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front6->type = Gwanja_front;

	BoundingBox* Gwangjae_front6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front6->start = f3(854.166f, 2.5f, 480.0f);
	Gwangjae_front6->end = f3(875.0f, 12.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 54.5f, 117.0f, 75.0f, 119.0f, 12.5f);

	/////////////////////////////////////////////////////////////////////////


	Object* Kwan_front7 = (Object*)malloc(sizeof(Object));
	Kwan_front7->location = f3(822.916f, 7.5f, 423.0f); // 20.833
	Kwan_front7->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front7->type = Gwanja_front;

	BoundingBox* Gwangjae_front7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front7->start = f3(812.5f, 2.5f, 422.0f);
	Gwangjae_front7->end = f3(833.333f, 12.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 59.0f, 33.5f, 61.0f, 12.5f);

	Object* Kwan_front8 = (Object*)malloc(sizeof(Object));
	Kwan_front8->location = f3(843.799f, 7.5f, 423.0f);
	Kwan_front8->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front8->type = Gwanja_front;

	BoundingBox* Gwangjae_front8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front8->start = f3(833.333f, 2.5f, 422.0f);
	Gwangjae_front8->end = f3(854.166f, 12.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 59.0f, 54.5f, 61.0f, 12.5f);

	Object* Kwan_front9 = (Object*)malloc(sizeof(Object));
	Kwan_front9->location = f3(864.633f, 7.5f, 423.0f);
	Kwan_front9->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front9->type = Gwanja_front;

	BoundingBox* Gwangjae_front9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front9->start = f3(854.166f, 2.5f, 422.0f);
	Gwangjae_front9->end = f3(875.0f, 12.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 54.5f, 59.0f, 75.0f, 61.0f, 12.5f);

	///////////////////////////////////////////////////////////////////


	Object* Kwan_front10 = (Object*)malloc(sizeof(Object));
	Kwan_front10->location = f3(822.916f, 7.5f, 364.0f); // 20.833
	Kwan_front10->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front10->type = Gwanja_front;

	BoundingBox* Gwangjae_front10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front10->start = f3(812.5f, 2.5f, 363.0f);
	Gwangjae_front10->end = f3(833.333f, 12.5f, 365.0f);
//	setAreaHeight(height2_1, x21, z21, 12.5f, 0.0f, 33.5f, 2.0f, 12.5f);

	Object* Kwan_front11 = (Object*)malloc(sizeof(Object));
	Kwan_front11->location = f3(843.799f, 7.5f, 364.0f);
	Kwan_front11->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front11->type = Gwanja_front;

	BoundingBox* Gwangjae_front11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front11->start = f3(833.333f, 2.5f, 363.0f);
	Gwangjae_front11->end = f3(854.166f, 12.5f, 365.0f);
// 	setAreaHeight(height2_1, x21, z21, 33.5f, 0.0f, 54.5f, 2.0f, 12.5f);

	Object* Kwan_front12 = (Object*)malloc(sizeof(Object));
	Kwan_front12->location = f3(864.633f, 7.5f, 364.0f);
	Kwan_front12->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_front12->type = Gwanja_front;

	BoundingBox* Gwangjae_front12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_front12->start = f3(854.166f, 2.5f, 363.0f);
	Gwangjae_front12->end = f3(875.0f, 12.5f, 365.0f);
	// setAreaHeight(height2_1, x21, z21, 54.5f, 0.0f, 75.0f, 2.0f, 12.5f);

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
	Gwangjae_floor2->end = f3(875.0f, 0.000f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 0.0f, 2.0f, 75.0f, 177.0f, 0.0f);

	////////////////////////////////////////////////

	Object* Kwan_walle_1 = (Object*)malloc(sizeof(Object));
	Kwan_walle_1->location = f3(820.0f, 1.25f, 539.0f);
	Kwan_walle_1->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_1->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_1->start = f3(812.5f, 0.0f, 538.0f); ///
	Gwangjae_walle_1->end = f3(827.5f, 2.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 174.5f, 27.5f, 177.5f, 2.5f); 

	Object* Kwan_walle_2 = (Object*)malloc(sizeof(Object));
	Kwan_walle_2->location = f3(835.0f, 1.25f, 539.0f);
	Kwan_walle_2->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_2->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_2->start = f3(827.5f, 0.0f, 538.0f);
	Gwangjae_walle_2->end = f3(842.5f, 2.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 27.5f, 174.5f, 42.5f, 177.5f, 2.5f);

	Object* Kwan_walle_3 = (Object*)malloc(sizeof(Object));
	Kwan_walle_3->location = f3(852.5f, 1.25f, 539.0f);
	Kwan_walle_3->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_3->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_3->start = f3(845.0f, 0.0f, 538.0f);
	Gwangjae_walle_3->end = f3(860.0f, 2.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 45.0f, 174.5f, 60.0f, 177.5f, 2.5f);

	Object* Kwan_walle_4 = (Object*)malloc(sizeof(Object));
	Kwan_walle_4->location = f3(867.5f, 1.25f, 539.0f);
	Kwan_walle_4->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_4->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_4->start = f3(860.0f, 0.0f, 538.0f);
	Gwangjae_walle_4->end = f3(875.0f, 2.5f, 540.0f);
	setAreaHeight(height2_1, x21, z21, 60.0f, 174.5f, 75.0f, 177.5f, 2.5f);

	//////////////////////////////////////////////////////////////////////////

	Object* Kwan_walle_5 = (Object*)malloc(sizeof(Object));
	Kwan_walle_5->location = f3(820.0f, 1.25f, 481.0f);
	Kwan_walle_5->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_5->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_5->start = f3(812.5f, 0.0f, 480.0f);
	Gwangjae_walle_5->end = f3(827.5f, 2.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 116.5f, 27.5f, 119.5f, 2.5f);

	Object* Kwan_walle_6 = (Object*)malloc(sizeof(Object));
	Kwan_walle_6->location = f3(835.0f, 1.25f, 481.0f);
	Kwan_walle_6->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_6->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_6->start = f3(827.5f, 0.0f, 480.0f);
	Gwangjae_walle_6->end = f3(842.5f, 2.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 27.5f, 116.5f, 42.5f, 119.5f, 2.5f);

	Object* Kwan_walle_7 = (Object*)malloc(sizeof(Object));
	Kwan_walle_7->location = f3(852.5f, 1.25f, 481.0f);
	Kwan_walle_7->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_7->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_7->start = f3(845.0f, 0.0f, 480.0f);
	Gwangjae_walle_7->end = f3(860.0f, 2.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 45.0f, 116.5f, 60.0f, 119.5f, 2.5f);

	Object* Kwan_walle_8 = (Object*)malloc(sizeof(Object));
	Kwan_walle_8->location = f3(867.5f, 1.25f, 481.0f);
	Kwan_walle_8->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_8->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_8->start = f3(860.0f, 0.0f, 480.0f);
	Gwangjae_walle_8->end = f3(875.0f, 2.5f, 482.0f);
	setAreaHeight(height2_1, x21, z21, 60.0f, 116.5f, 75.0f, 119.5f, 2.5f);

	//////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_walle_9 = (Object*)malloc(sizeof(Object));
	Kwan_walle_9->location = f3(820.0f, 1.25f, 423.0f);
	Kwan_walle_9->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_9->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_9->start = f3(812.5f, 0.0f, 422.0f);
	Gwangjae_walle_9->end = f3(827.5f, 2.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 58.5f, 27.5f, 61.5f, 2.5f);

	Object* Kwan_walle_10 = (Object*)malloc(sizeof(Object));
	Kwan_walle_10->location = f3(835.0f, 1.25f, 423.0f);
	Kwan_walle_10->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_10->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_10->start = f3(827.5f, 0.0f, 422.0f);
	Gwangjae_walle_10->end = f3(842.5f, 2.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 27.5f, 58.5f, 42.5f, 61.5f, 2.5f);

	Object* Kwan_walle_11 = (Object*)malloc(sizeof(Object));
	Kwan_walle_11->location = f3(852.5f, 1.25f, 423.0f);
	Kwan_walle_11->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_11->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_11->start = f3(845.0f, 0.0f, 422.0f);
	Gwangjae_walle_11->end = f3(860.0f, 2.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 45.0f, 58.5f, 60.0f, 61.5f, 2.5f);

	Object* Kwan_walle_12 = (Object*)malloc(sizeof(Object));
	Kwan_walle_12->location = f3(867.5f, 1.25f, 423.0f);
	Kwan_walle_12->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_12->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_12->start = f3(860.0f, 0.0f, 422.0f);
	Gwangjae_walle_12->end = f3(875.0f, 2.5f, 424.0f);
	setAreaHeight(height2_1, x21, z21, 60.0f, 58.5f, 75.0f, 61.5f, 2.5f);

	/////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_walle_13 = (Object*)malloc(sizeof(Object));
	Kwan_walle_13->location = f3(820.0f, 1.25f, 364.0f);
	Kwan_walle_13->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_13->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_13->start = f3(812.5f, 0.0f, 363.0f);
	Gwangjae_walle_13->end = f3(827.5f, 2.5f, 365.0f);
	setAreaHeight(height2_1, x21, z21, 12.5f, 0.0f, 27.5f, 2.5f, 2.5f);

	Object* Kwan_walle_14 = (Object*)malloc(sizeof(Object));
	Kwan_walle_14->location = f3(835.0f, 1.25f, 364.0f);
	Kwan_walle_14->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_14->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_14->start = f3(827.5f, 0.0f, 363.0f);
	Gwangjae_walle_14->end = f3(842.5f, 2.5f, 365.0f);
	setAreaHeight(height2_1, x21, z21, 27.5f, 0.0f, 42.5f, 2.5f, 2.5f);

	Object* Kwan_walle_15 = (Object*)malloc(sizeof(Object));
	Kwan_walle_15->location = f3(852.5f, 1.25f, 364.0f);
	Kwan_walle_15->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_15->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_15->start = f3(845.0f, 0.0f, 363.0f);
	Gwangjae_walle_15->end = f3(860.0f, 2.5f, 365.0f);
	setAreaHeight(height2_1, x21, z21, 45.0f, 0.0f, 60.0f, 2.5f, 2.5f);

	Object* Kwan_walle_16 = (Object*)malloc(sizeof(Object));
	Kwan_walle_16->location = f3(867.5f, 1.25f, 364.0f);
	Kwan_walle_16->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walle_16->type = Gwanja_wall2;

	BoundingBox* Gwangjae_walle_16 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walle_16->start = f3(860.0f, 0.0f, 363.0f);
	Gwangjae_walle_16->end = f3(875.0f, 2.5f, 365.0f);
	setAreaHeight(height2_1, x21, z21, 60.0f, 0.0f, 75.0f, 2.5f, 2.5f);


	///////////////////////////////////////////////////////////////

	Object* Kwan_wallFe = (Object*)malloc(sizeof(Object));
	Kwan_wallFe->location = f3(805.0f, 10.0f, 599.6f);
	Kwan_wallFe->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe->start = f3(795.0f, 7.5f, 599.1f);
	Gwangjae_wallFe->end = f3(815.0f, 12.5f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 0.0f, 236.0f, 15.0f, 237.0f, 12.5f);

	Object* Kwan_wallFe2 = (Object*)malloc(sizeof(Object));
	Kwan_wallFe2->location = f3(825.0f, 10.0f, 599.6f);
	Kwan_wallFe2->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe2->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe2->start = f3(815.0f, 7.5f, 599.1f);
	Gwangjae_wallFe2->end = f3(835.0f, 12.5f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 15.0f, 236.0f, 35.0f, 237.0f, 12.5f);

	Object* Kwan_wallFe3 = (Object*)malloc(sizeof(Object));
	Kwan_wallFe3->location = f3(845.0f, 10.0f, 599.6f);
	Kwan_wallFe3->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe3->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe3->start = f3(835.0f, 7.5f, 599.1f);
	Gwangjae_wallFe3->end = f3(855.0f, 12.5f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 35.0f, 236.0f, 55.0f, 237.0f, 12.5f);

	Object* Kwan_wallFe4 = (Object*)malloc(sizeof(Object));
	Kwan_wallFe4->location = f3(865.0f, 10.0f, 599.6f);
	Kwan_wallFe4->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallFe4->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wallFe4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallFe4->start = f3(855.0f, 7.5f, 599.1f);
	Gwangjae_wallFe4->end = f3(875.0f, 12.5f, 600.1f);
	setAreaHeight(height2_1, x21, z21, 55.0f, 236.0f, 75.0f, 237.0f, 12.5f);

	//////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_wall1Le = (Object*)malloc(sizeof(Object));
	Kwan_wall1Le->location = f3(875.4f, 10.0f, 595.0f);
	Kwan_wall1Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall1Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1Le->start = f3(875.0f, 7.5f, 585.0f);
	Gwangjae_wall1Le->end = f3(875.0f, 12.5f, 605.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 222.0f, 75.0f, 242.0f, 12.5f);

	Object* Kwan_wall2Le = (Object*)malloc(sizeof(Object));
	Kwan_wall2Le->location = f3(875.4f, 10.0f, 575.0f);
	Kwan_wall2Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall2Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2Le->start = f3(875.0f, 7.5f, 565.0f);
	Gwangjae_wall2Le->end = f3(875.0f, 12.5f, 585.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 202.0f, 75.0f, 222.0f, 12.5f);

	Object* Kwan_wall3Le = (Object*)malloc(sizeof(Object));
	Kwan_wall3Le->location = f3(875.4f, 10.0f, 555.0f);
	Kwan_wall3Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall3Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3Le->start = f3(875.0f, 7.5f, 545.0f);
	Gwangjae_wall3Le->end = f3(875.0f, 12.5f, 565.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 182.0f, 75.0f, 202.0f, 12.5f);

	Object* Kwan_wall4Le = (Object*)malloc(sizeof(Object));
	Kwan_wall4Le->location = f3(875.4f, 10.0f, 535.0f);
	Kwan_wall4Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall4Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4Le->start = f3(875.0f, 7.5f, 525.0f);
	Gwangjae_wall4Le->end = f3(875.0f, 12.5f, 545.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 162.0f, 75.0f, 182.0f, 12.5f);

	Object* Kwan_wall5Le = (Object*)malloc(sizeof(Object));
	Kwan_wall5Le->location = f3(875.4f, 10.0f, 515.0f);
	Kwan_wall5Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall5Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5Le->start = f3(875.0f, 7.5f, 505.0f);
	Gwangjae_wall5Le->end = f3(875.0f, 12.5f, 525.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 142.0f, 75.0f, 162.0f, 12.5f);

	Object* Kwan_wall6Le = (Object*)malloc(sizeof(Object));
	Kwan_wall6Le->location = f3(875.4f, 10.0f, 495.0f);
	Kwan_wall6Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall6Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6Le->start = f3(875.0f, 7.5f, 485.0f);
	Gwangjae_wall6Le->end = f3(875.0f, 12.5f, 505.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 122.0f, 75.0f, 142.0f, 12.5f);

	Object* Kwan_wall7Le = (Object*)malloc(sizeof(Object));
	Kwan_wall7Le->location = f3(875.4f, 10.0f, 475.0f);
	Kwan_wall7Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall7Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7Le->start = f3(875.0f, 7.5f, 465.0f);
	Gwangjae_wall7Le->end = f3(875.0f, 12.5f, 485.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 102.0f, 75.0f, 122.0f, 12.5f);

	Object* Kwan_wall8Le = (Object*)malloc(sizeof(Object));
	Kwan_wall8Le->location = f3(875.4f, 10.0f, 455.0f);
	Kwan_wall8Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall8Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8Le->start = f3(875.0f, 7.5f, 445.0f);
	Gwangjae_wall8Le->end = f3(875.0f, 12.5f, 465.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 82.0f, 75.0f, 102.0f, 12.5f);

	Object* Kwan_wall9Le = (Object*)malloc(sizeof(Object));
	Kwan_wall9Le->location = f3(875.4f, 10.0f, 435.0f);
	Kwan_wall9Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall9Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9Le->start = f3(875.0f, 7.5f, 425.0f);
	Gwangjae_wall9Le->end = f3(875.0f, 12.5f, 445.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 62.0f, 75.0f, 82.0f, 12.5f);

	Object* Kwan_wall10Le = (Object*)malloc(sizeof(Object));
	Kwan_wall10Le->location = f3(875.4f, 10.0f, 415.0f);
	Kwan_wall10Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall10Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall10Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall10Le->start = f3(875.0f, 7.5f, 405.0f);
	Gwangjae_wall10Le->end = f3(875.0f, 12.5f, 425.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 42.0f, 75.0f, 62.0f, 12.5f);

	Object* Kwan_wall11Le = (Object*)malloc(sizeof(Object));
	Kwan_wall11Le->location = f3(875.4f, 10.0f, 395.0f);
	Kwan_wall11Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall11Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall11Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall11Le->start = f3(875.0f, 7.5f, 385.0f);
	Gwangjae_wall11Le->end = f3(875.0f, 12.5f, 405.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 22.0f, 75.0f, 42.0f, 12.5f);

	Object* Kwan_wall12Le = (Object*)malloc(sizeof(Object));
	Kwan_wall12Le->location = f3(875.4f, 10.0f, 375.0f);
	Kwan_wall12Le->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall12Le->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall12Le = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall12Le->start = f3(875.0f, 7.5f, 365.0f);
	Gwangjae_wall12Le->end = f3(875.0f, 12.5f, 385.0f);
	setAreaHeight(height2_1, x21, z21, 75.0f, 2.0f, 75.0f, 22.0f, 12.5f);

	///////////////////////////////////////////////////////////////////

	Object* Kwan_wall00e = (Object*)malloc(sizeof(Object));
	Kwan_wall00e->location = f3(799.6f, 10.0f, 602.5f);
	Kwan_wall00e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall00e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall00e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall00e->start = f3(800.0f, 7.5f, 592.5f);
	Gwangjae_wall00e->end = f3(800.0f, 12.5f, 612.5f);
	setAreaHeight(height2_1, x21, z21, 0.0f, 229.5f, 0.0f, 249.5f, 12.5f);

	Object* Kwan_wall0e = (Object*)malloc(sizeof(Object));
	Kwan_wall0e->location = f3(799.6f, 10.0f, 582.5f);
	Kwan_wall0e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall0e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall0e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall0e->start = f3(800.0f, 7.5f, 572.5f);
	Gwangjae_wall0e->end = f3(800.0f, 12.5f, 592.5f);
	setAreaHeight(height2_1, x21, z21, 0.0f, 209.5f, 0.0f, 229.5f, 12.5f);

	///////////////////////////////
	Object* Kwan_wall1e = (Object*)malloc(sizeof(Object));
	Kwan_wall1e->location = f3(812.1f, 10.0f, 535.0f);
	Kwan_wall1e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall1e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall1e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall1e->start = f3(812.0f, 7.5f, 525.0f);
	Gwangjae_wall1e->end = f3(813.0f, 12.5f, 545.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 162.0f, 13.0f, 182.0f, 12.5f);

	////////////
	Object* Kwan_wall2e = (Object*)malloc(sizeof(Object));
	Kwan_wall2e->location = f3(812.1f, 10.0f, 515.0f);
	Kwan_wall2e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall2e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall2e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall2e->start = f3(812.0f, 7.5f, 505.0f);
	Gwangjae_wall2e->end = f3(813.0f, 12.5f, 525.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 142.0f, 13.0f, 162.0f, 12.5f);

	////////////////////
	Object* Kwan_wall3e = (Object*)malloc(sizeof(Object));
	Kwan_wall3e->location = f3(812.1f, 10.0f, 495.0f);
	Kwan_wall3e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall3e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall3e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall3e->start = f3(812.0f, 7.5f, 485.0f);
	Gwangjae_wall3e->end = f3(813.0f, 12.5f, 505.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 122.0f, 13.0f, 142.0f, 12.5f);

	///////////////////////////////

	Object* Kwan_wall4e = (Object*)malloc(sizeof(Object));
	Kwan_wall4e->location = f3(812.1f, 10.0f, 475.0f);
	Kwan_wall4e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall4e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall4e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall4e->start = f3(812.0f, 7.5f, 465.0f);
	Gwangjae_wall4e->end = f3(813.0f, 12.5f, 485.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 102.0f, 13.0f, 122.0f, 12.5f);

	/////////////////////////////////

	Object* Kwan_wall5e = (Object*)malloc(sizeof(Object));
	Kwan_wall5e->location = f3(812.1f, 10.0f, 455.0f);
	Kwan_wall5e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall5e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall5e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall5e->start = f3(812.0f, 7.5f, 445.0f);
	Gwangjae_wall5e->end = f3(813.0f, 12.5f, 465.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 82.0f, 13.0f, 102.0f, 12.5f);

	Object* Kwan_wall6e = (Object*)malloc(sizeof(Object));
	Kwan_wall6e->location = f3(812.1f, 10.0f, 435.0f);
	Kwan_wall6e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall6e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall6e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall6e->start = f3(812.0f, 7.5f, 425.0f);
	Gwangjae_wall6e->end = f3(813.0f, 12.5f, 445.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 62.0f, 13.0f, 82.0f, 12.5f);

	Object* Kwan_wall7e = (Object*)malloc(sizeof(Object));
	Kwan_wall7e->location = f3(812.1f, 10.0f, 415.0f);
	Kwan_wall7e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall7e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall7e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall7e->start = f3(812.0f, 7.5f, 405.0f);
	Gwangjae_wall7e->end = f3(813.0f, 12.5f, 425.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 42.0f, 13.0f, 62.0f, 12.5f);

	Object* Kwan_wall8e = (Object*)malloc(sizeof(Object));
	Kwan_wall8e->location = f3(812.1f, 10.0f, 395.0f);
	Kwan_wall8e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall8e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall8e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall8e->start = f3(812.0f, 7.5f, 385.0f);
	Gwangjae_wall8e->end = f3(813.0f, 12.5f, 405.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 22.0f, 13.0f, 42.0f, 12.5f);

	Object* Kwan_wall9e = (Object*)malloc(sizeof(Object));
	Kwan_wall9e->location = f3(812.1f, 10.0f, 375.0f);
	Kwan_wall9e->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_wall9e->type = Gwanja_wall3;

	BoundingBox* Gwangjae_wall9e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wall9e->start = f3(812.0f, 7.5f, 365.0f);
	Gwangjae_wall9e->end = f3(813.0f, 12.5f, 385.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 2.0f, 13.0f, 22.0f, 12.5f);

	///////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_wallss = (Object*)malloc(sizeof(Object));
	Kwan_wallss->location = f3(802.5f, 3.75f, 545.5f);
	Kwan_wallss->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_wallss->type = Gwanja_wall1;

	BoundingBox* Gwangjae_wallss = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_wallss->start = f3(792.5f, 0.0f, 545.0f);
	Gwangjae_wallss->end = f3(812.5f, 7.5f, 546.0f);
	setAreaHeight(height2_1, x21, z21, 0.0f, 182.0f, 12.5f, 183.0f, 7.5f);

	Object* Kwan_walles = (Object*)malloc(sizeof(Object));
	Kwan_walles->location = f3(802.5f, 10.0f, 545.5f);
	Kwan_walles->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_walles->type = Gwanja_wall3;

	BoundingBox* Gwangjae_walles = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_walles->start = f3(792.5f, 7.5f, 545.0f);
	Gwangjae_walles->end = f3(812.5f, 12.5f, 546.0f);
	setAreaHeight(height2_1, x21, z21, 0.0f, 182.0f, 12.5f, 183.0f, 12.5f);


	////////////////////////////////////////////////////////////////////////
	Object* Kwan_Screens = (Object*)malloc(sizeof(Object));
	Kwan_Screens->location = f3(874.0f, 6.0f, 510.5f);
	Kwan_Screens->rotation = f3(0.0f, 0.0f, 90.0f);
	Kwan_Screens->type = Gwanja_Screen;

	BoundingBox* Gwangjae_Screens = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Screens->start = f3(873.0f, 2.0f, 498.5f);
	Gwangjae_Screens->end = f3(875.0f, 10.0f, 522.5f);
	setAreaHeight(height2_1, x21, z21, 73.0f, 135.5f, 75.0f, 159.5f, 10.0f);

	Object* Kwan_Screens2 = (Object*)malloc(sizeof(Object));
	Kwan_Screens2->location = f3(874.0f, 6.0f, 454.5f);
	Kwan_Screens2->rotation = f3(0.0f, 0.0f, 90.0f);
	Kwan_Screens2->type = Gwanja_Screen2;

	BoundingBox* Gwangjae_Screens2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Screens2->start = f3(873.0f, 2.0f, 442.5f);
	Gwangjae_Screens2->end = f3(875.0f, 10.0f, 466.5f);
	setAreaHeight(height2_1, x21, z21, 73.0f, 79.5f, 75.0f, 103.5f, 10.0f);

	Object* Kwan_Screens3 = (Object*)malloc(sizeof(Object));
	Kwan_Screens3->location = f3(874.0f, 6.0f, 398.5f);
	Kwan_Screens3->rotation = f3(0.0f, 0.0f, 90.0f);
	Kwan_Screens3->type = Gwanja_Screen3;

	BoundingBox* Gwangjae_Screens3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Screens3->start = f3(873.0f, 2.0f, 386.5f);
	Gwangjae_Screens3->end = f3(875.0f, 10.0f, 410.5f);
	setAreaHeight(height2_1, x21, z21, 74.5f, 2.5f, 75.0f, 237.5f, 10.0f);

	/////////////////////////////////////////////////////////////////////


	Object* Kwan_tables1 = (Object*)malloc(sizeof(Object));
	Kwan_tables1->location = f3(832.0f, 0.0f, 511.5f); // 30
	Kwan_tables1->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables1->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables1->start = f3(830.0f, 0.0f, 496.5f);
	Gwangjae_tables1->end = f3(834.0f, 2.0f, 526.5f);
	setAreaHeight(height2_1, x21, z21, 29.5f, 133.0f, 34.5f, 164.0f, 2.0f);

	Object* Kwan_tables2 = (Object*)malloc(sizeof(Object));
	Kwan_tables2->location = f3(822.0f, 0.0f, 511.5f); // 30
	Kwan_tables2->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables2->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables2->start = f3(820.0f, 0.0f, 496.5f);
	Gwangjae_tables2->end = f3(824.0f, 2.0f, 526.5f);
	setAreaHeight(height2_1, x21, z21, 19.5f, 133.0f, 24.5f, 164.0f, 2.0f);

	Object* Kwan_tables3 = (Object*)malloc(sizeof(Object));
	Kwan_tables3->location = f3(842.0f, 0.0f, 511.5f); // 30
	Kwan_tables3->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables3->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables3->start = f3(840.0f, 0.0f, 496.5f);
	Gwangjae_tables3->end = f3(844.0f, 2.0f, 526.5f);
	setAreaHeight(height2_1, x21, z21, 39.5f, 133.0f, 44.5f, 164.0f, 2.0f);

	Object* Kwan_tables4 = (Object*)malloc(sizeof(Object));
	Kwan_tables4->location = f3(852.0f, 0.0f, 511.5f); // 30
	Kwan_tables4->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables4->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables4->start = f3(850.0f, 0.0f, 496.5f);
	Gwangjae_tables4->end = f3(854.0f, 2.0f, 526.5f);
	setAreaHeight(height2_1, x21, z21, 49.5f, 133.0f, 54.5f, 164.0f, 2.0f);

	/////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_tables5 = (Object*)malloc(sizeof(Object));
	Kwan_tables5->location = f3(859.0f, 0.0f, 452.5f); // 30
	Kwan_tables5->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_tables5->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables5->start = f3(857.0f, 0.0f, 437.5f);
	Gwangjae_tables5->end = f3(861.0f, 2.0f, 467.5f);
	setAreaHeight(height2_1, x21, z21, 56.5f, 74.0f, 61.5f, 105.0f, 2.0f);

	Object* Kwan_tables6 = (Object*)malloc(sizeof(Object));
	Kwan_tables6->location = f3(840.0f, 0.0f, 438.5f); // 30
	Kwan_tables6->rotation = f3(0.0f, 180.0f, 0.0f);
	Kwan_tables6->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables6->start = f3(825.0f, 0.0f, 436.5f);
	Gwangjae_tables6->end = f3(855.0f, 2.0f, 440.5f);
	setAreaHeight(height2_1, x21, z21, 24.5f, 73.0f, 55.5f, 78.0f, 2.0f);

	Object* Kwan_tables7 = (Object*)malloc(sizeof(Object));
	Kwan_tables7->location = f3(840.0f, 0.0f, 465.5f); // 30
	Kwan_tables7->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_tables7->type = Gwanja_tables;

	BoundingBox* Gwangjae_tables7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables7->start = f3(825.0f, 0.0f, 463.5f);
	Gwangjae_tables7->end = f3(855.0f, 2.0f, 467.5f);
	setAreaHeight(height2_1, x21, z21, 24.5f, 100.0f, 55.5f, 105.0f, 2.0f);

	//////////////////////////////////////////////////////////////////////////////////


	Object* Kwan_tables8 = (Object*)malloc(sizeof(Object));
	Kwan_tables8->location = f3(855.0f, 0.0f, 406.0f); // 8 4 (4 8)
	Kwan_tables8->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables8->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables8->start = f3(853.0f, 0.0f, 402.0f);
	Gwangjae_tables8->end = f3(857.0f, 2.0f, 410.0f);
	setAreaHeight(height2_1, x21, z21, 52.5f, 38.5f, 57.5f, 47.5f, 2.0f);

	Object* Kwan_tables9 = (Object*)malloc(sizeof(Object));
	Kwan_tables9->location = f3(855.0f, 0.0f, 393.0f); // 8 4 (4 8)
	Kwan_tables9->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables9->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables9->start = f3(853.0f, 0.0f, 389.0f);
	Gwangjae_tables9->end = f3(857.0f, 2.0f, 397.0f);
	setAreaHeight(height2_1, x21, z21, 52.5f, 25.5f, 57.5f, 34.5f, 2.0f);

	Object* Kwan_tables10 = (Object*)malloc(sizeof(Object));
	Kwan_tables10->location = f3(855.0f, 0.0f, 380.0f); // 8 4 (4 8)
	Kwan_tables10->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables10->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables10->start = f3(853.0f, 0.0f, 376.0f);
	Gwangjae_tables10->end = f3(857.0f, 2.0f, 384.0f);
	setAreaHeight(height2_1, x21, z21, 52.5f, 12.5f, 57.5f, 21.5f, 2.0f);

	///////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_tables11 = (Object*)malloc(sizeof(Object));
	Kwan_tables11->location = f3(843.0f, 0.0f, 406.0f); // 8 4 (4 8)
	Kwan_tables11->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables11->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables11->start = f3(841.0f, 0.0f, 402.0f);
	Gwangjae_tables11->end = f3(845.0f, 2.0f, 410.0f);
	setAreaHeight(height2_1, x21, z21, 40.5f, 38.5f, 45.5f, 47.5f, 2.0f);

	Object* Kwan_tables12 = (Object*)malloc(sizeof(Object));
	Kwan_tables12->location = f3(843.0f, 0.0f, 393.0f); // 8 4 (4 8)
	Kwan_tables12->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables12->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables12->start = f3(841.0f, 0.0f, 389.0f);
	Gwangjae_tables12->end = f3(845.0f, 2.0f, 397.0f);
	setAreaHeight(height2_1, x21, z21, 40.5f, 25.5f, 45.5f, 34.5f, 2.0f);

	Object* Kwan_tables13 = (Object*)malloc(sizeof(Object));
	Kwan_tables13->location = f3(843.0f, 0.0f, 380.0f); // 8 4 (4 8)
	Kwan_tables13->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables13->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables13->start = f3(841.0f, 0.0f, 376.0f);
	Gwangjae_tables13->end = f3(845.0f, 2.0f, 384.0f);
	setAreaHeight(height2_1, x21, z21, 40.5f, 12.5f, 45.5f, 21.5f, 2.0f);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_tables14 = (Object*)malloc(sizeof(Object));
	Kwan_tables14->location = f3(831.0f, 0.0f, 406.0f); // 8 4 (4 8)
	Kwan_tables14->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables14->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables14->start = f3(829.0f, 0.0f, 402.0f);
	Gwangjae_tables14->end = f3(833.0f, 2.0f, 410.0f);
	setAreaHeight(height2_1, x21, z21, 28.5f, 38.5f, 33.5f, 47.5f, 2.0f);

	Object* Kwan_tables15 = (Object*)malloc(sizeof(Object));
	Kwan_tables15->location = f3(831.0f, 0.0f, 393.0f); // 8 4 (4 8)
	Kwan_tables15->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables15->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables15->start = f3(829.0f, 0.0f, 389.0f);
	Gwangjae_tables15->end = f3(833.0f, 2.0f, 397.0f);
	setAreaHeight(height2_1, x21, z21, 28.5f, 25.5f, 33.5f, 34.5f, 2.0f);

	Object* Kwan_tables16 = (Object*)malloc(sizeof(Object));
	Kwan_tables16->location = f3(831.0f, 0.0f, 380.0f); // 8 4 (4 8)
	Kwan_tables16->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_tables16->type = Gwanja_tablesA;

	BoundingBox* Gwangjae_tables16 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_tables16->start = f3(829.0f, 0.0f, 376.0f);
	Gwangjae_tables16->end = f3(833.0f, 2.0f, 384.0f);
	setAreaHeight(height2_1, x21, z21, 28.5f, 12.5f, 33.5f, 21.5f, 2.0f);

	///////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair1 = (Object*)malloc(sizeof(Object));
	Kwan_Chair1->location = f3(849.8f, 0.0f, 500.5f); // 8 4 (4 8)
	Kwan_Chair1->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair1->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair1->start = f3(848.0f, 0.0f, 499.5f);
	Gwangjae_Chair1->end = f3(851.6f, 2.0f, 501.5f);
	setAreaHeight(height2_1, x21, z21, 48.0f, 136.5f, 52.0f, 138.5f, 2.0f);

	Object* Kwan_Chair2 = (Object*)malloc(sizeof(Object));
	Kwan_Chair2->location = f3(849.8f, 0.0f, 506.5f); // 8 4 (4 8)
	Kwan_Chair2->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair2->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair2->start = f3(848.0f, 0.0f, 505.5f);
	Gwangjae_Chair2->end = f3(851.6f, 2.0f, 507.5f);
	setAreaHeight(height2_1, x21, z21, 48.0f, 142.5f, 52.0f, 144.5f, 2.0f);

	Object* Kwan_Chair3 = (Object*)malloc(sizeof(Object));
	Kwan_Chair3->location = f3(849.8f, 0.0f, 512.5f); // 8 4 (4 8)
	Kwan_Chair3->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair3->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair3->start = f3(848.0f, 0.0f, 511.5f);
	Gwangjae_Chair3->end = f3(851.6f, 2.0f, 513.5f);
	setAreaHeight(height2_1, x21, z21, 48.0f, 148.5f, 52.0f, 150.5f, 2.0f);

	Object* Kwan_Chair4 = (Object*)malloc(sizeof(Object));
	Kwan_Chair4->location = f3(849.8f, 0.0f, 518.5f); // 8 4 (4 8)
	Kwan_Chair4->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair4->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair4->start = f3(848.0f, 0.0f, 517.5f);
	Gwangjae_Chair4->end = f3(851.6f, 2.0f, 519.5f);
	setAreaHeight(height2_1, x21, z21, 48.0f, 154.5f, 52.0f, 156.5f, 2.0f);

	Object* Kwan_Chair5 = (Object*)malloc(sizeof(Object));
	Kwan_Chair5->location = f3(849.8f, 0.0f, 524.5f); // 8 4 (4 8)
	Kwan_Chair5->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair5->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair5->start = f3(848.0f, 0.0f, 523.5f);
	Gwangjae_Chair5->end = f3(851.6f, 2.0f, 525.5f);
	setAreaHeight(height2_1, x21, z21, 48.0f, 160.5f, 52.0f, 162.5f, 2.0f);

	/////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair6 = (Object*)malloc(sizeof(Object));
	Kwan_Chair6->location = f3(839.8f, 0.0f, 500.5f); // 8 4 (4 8)
	Kwan_Chair6->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair6->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair6->start = f3(838.0f, 0.0f, 499.5f);
	Gwangjae_Chair6->end = f3(841.6f, 2.0f, 501.5f);
	setAreaHeight(height2_1, x21, z21, 38.0f, 136.5f, 42.0f, 138.5f, 2.0f);

	Object* Kwan_Chair7 = (Object*)malloc(sizeof(Object));
	Kwan_Chair7->location = f3(839.8f, 0.0f, 506.5f); // 8 4 (4 8)
	Kwan_Chair7->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair7->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair7->start = f3(838.0f, 0.0f, 505.5f);
	Gwangjae_Chair7->end = f3(841.6f, 2.0f, 507.5f);
	setAreaHeight(height2_1, x21, z21, 38.0f, 142.5f, 42.0f, 144.5f, 2.0f);

	Object* Kwan_Chair8 = (Object*)malloc(sizeof(Object));
	Kwan_Chair8->location = f3(839.8f, 0.0f, 512.5f); // 8 4 (4 8)
	Kwan_Chair8->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair8->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair8->start = f3(838.0f, 0.0f, 511.5f);
	Gwangjae_Chair8->end = f3(841.6f, 2.0f, 513.5f);
	setAreaHeight(height2_1, x21, z21, 38.0f, 148.5f, 42.0f, 150.5f, 2.0f);

	Object* Kwan_Chair9 = (Object*)malloc(sizeof(Object));
	Kwan_Chair9->location = f3(839.8f, 0.0f, 518.5f); // 8 4 (4 8)
	Kwan_Chair9->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair9->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair9->start = f3(838.0f, 0.0f, 517.5f);
	Gwangjae_Chair9->end = f3(841.6f, 2.0f, 519.5f);
	setAreaHeight(height2_1, x21, z21, 38.0f, 154.5f, 42.0f, 156.5f, 2.0f);

	Object* Kwan_Chair10 = (Object*)malloc(sizeof(Object));
	Kwan_Chair10->location = f3(839.8f, 0.0f, 524.5f); // 8 4 (4 8)
	Kwan_Chair10->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair10->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair10->start = f3(838.0f, 0.0f, 523.5f);
	Gwangjae_Chair10->end = f3(841.6f, 2.0f, 525.5f);
	setAreaHeight(height2_1, x21, z21, 38.0f, 160.5f, 42.0f, 162.5f, 2.0f);

	///////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair11 = (Object*)malloc(sizeof(Object));
	Kwan_Chair11->location = f3(829.8f, 0.0f, 500.5f); // 8 4 (4 8)
	Kwan_Chair11->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair11->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair11->start = f3(828.0f, 0.0f, 499.5f);
	Gwangjae_Chair11->end = f3(831.6f, 2.0f, 501.5f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 136.5f, 32.0f, 138.5f, 2.0f);

	Object* Kwan_Chair12 = (Object*)malloc(sizeof(Object));
	Kwan_Chair12->location = f3(829.8f, 0.0f, 506.5f); // 8 4 (4 8)
	Kwan_Chair12->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair12->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair12->start = f3(828.0f, 0.0f, 505.5f);
	Gwangjae_Chair12->end = f3(831.6f, 2.0f, 507.5f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 142.5f, 32.0f, 144.5f, 2.0f);

	Object* Kwan_Chair13 = (Object*)malloc(sizeof(Object));
	Kwan_Chair13->location = f3(829.8f, 0.0f, 512.5f); // 8 4 (4 8)
	Kwan_Chair13->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair13->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair13->start = f3(828.0f, 0.0f, 511.5f);
	Gwangjae_Chair13->end = f3(831.6f, 2.0f, 513.5f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 148.5f, 32.0f, 150.5f, 2.0f);

	Object* Kwan_Chair14 = (Object*)malloc(sizeof(Object));
	Kwan_Chair14->location = f3(829.8f, 0.0f, 518.5f); // 8 4 (4 8)
	Kwan_Chair14->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair14->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair14->start = f3(828.0f, 0.0f, 517.5f);
	Gwangjae_Chair14->end = f3(831.6f, 2.0f, 519.5f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 154.5f, 32.0f, 156.5f, 2.0f);

	Object* Kwan_Chair15 = (Object*)malloc(sizeof(Object));
	Kwan_Chair15->location = f3(829.8f, 0.0f, 524.5f); // 8 4 (4 8)
	Kwan_Chair15->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair15->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair15->start = f3(828.0f, 0.0f, 523.5f);
	Gwangjae_Chair15->end = f3(831.6f, 2.0f, 525.5f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 160.5f, 32.0f, 162.5f, 2.0f);

	//////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair16 = (Object*)malloc(sizeof(Object));
	Kwan_Chair16->location = f3(819.8f, 0.0f, 500.5f); // 8 4 (4 8)
	Kwan_Chair16->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair16->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair16 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair16->start = f3(818.0f, 0.0f, 499.5f);
	Gwangjae_Chair16->end = f3(821.6f, 2.0f, 501.5f);
	setAreaHeight(height2_1, x21, z21, 18.0f, 136.5f, 22.0f, 138.5f, 2.0f);

	Object* Kwan_Chair17 = (Object*)malloc(sizeof(Object));
	Kwan_Chair17->location = f3(819.8f, 0.0f, 506.5f); // 8 4 (4 8)
	Kwan_Chair17->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair17->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair17 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair17->start = f3(818.0f, 0.0f, 505.5f);
	Gwangjae_Chair17->end = f3(821.6f, 2.0f, 507.5f);
	setAreaHeight(height2_1, x21, z21, 18.0f, 142.5f, 22.0f, 144.5f, 2.0f);

	Object* Kwan_Chair18 = (Object*)malloc(sizeof(Object));
	Kwan_Chair18->location = f3(819.8f, 0.0f, 512.5f); // 8 4 (4 8)
	Kwan_Chair18->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair18->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair18 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair18->start = f3(818.0f, 0.0f, 511.5f);
	Gwangjae_Chair18->end = f3(821.6f, 2.0f, 513.5f);
	setAreaHeight(height2_1, x21, z21, 18.0f, 148.5f, 22.0f, 150.5f, 2.0f);

	Object* Kwan_Chair19 = (Object*)malloc(sizeof(Object));
	Kwan_Chair19->location = f3(819.8f, 0.0f, 518.5f); // 8 4 (4 8)
	Kwan_Chair19->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair19->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair19 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair19->start = f3(818.0f, 0.0f, 517.5f);
	Gwangjae_Chair19->end = f3(821.6f, 2.0f, 519.5f);
	setAreaHeight(height2_1, x21, z21, 18.0f, 154.5f, 22.0f, 156.5f, 2.0f);

	Object* Kwan_Chair20 = (Object*)malloc(sizeof(Object));
	Kwan_Chair20->location = f3(819.8f, 0.0f, 524.5f); // 8 4 (4 8)
	Kwan_Chair20->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair20->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair20 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair20->start = f3(818.0f, 0.0f, 523.5f);
	Gwangjae_Chair20->end = f3(821.6f, 2.0f, 525.5f);
	setAreaHeight(height2_1, x21, z21, 18.0f, 160.5f, 22.0f, 162.5f, 2.0f);

	////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair21 = (Object*)malloc(sizeof(Object));
	Kwan_Chair21->location = f3(829.0f, 0.0f, 466.0f); // 8 4 (4 8)
	Kwan_Chair21->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_Chair21->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair21 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair21->start = f3(828.0f, 0.0f, 464.2f);
	Gwangjae_Chair21->end = f3(830.0f, 2.0f, 467.8f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 101.5f, 30.0f, 105.0f, 2.0f);

	Object* Kwan_Chair22 = (Object*)malloc(sizeof(Object));
	Kwan_Chair22->location = f3(835.0f, 0.0f, 466.0f); // 8 4 (4 8)
	Kwan_Chair22->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_Chair22->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair22 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair22->start = f3(834.0f, 0.0f, 464.2f);
	Gwangjae_Chair22->end = f3(836.0f, 2.0f, 467.8f);
	setAreaHeight(height2_1, x21, z21, 34.0f, 101.5f, 36.0f, 105.0f, 2.0f);

	Object* Kwan_Chair23 = (Object*)malloc(sizeof(Object));
	Kwan_Chair23->location = f3(841.0f, 0.0f, 466.0f); // 8 4 (4 8)
	Kwan_Chair23->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_Chair23->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair23 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair23->start = f3(840.0f, 0.0f, 464.2f);
	Gwangjae_Chair23->end = f3(842.0f, 2.0f, 467.8f);
	setAreaHeight(height2_1, x21, z21, 40.0f, 101.5f, 42.0f, 105.0f, 2.0f);

	Object* Kwan_Chair24 = (Object*)malloc(sizeof(Object));
	Kwan_Chair24->location = f3(847.0f, 0.0f, 466.0f); // 8 4 (4 8)
	Kwan_Chair24->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_Chair24->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair24 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair24->start = f3(846.0f, 0.0f, 464.2f);
	Gwangjae_Chair24->end = f3(848.0f, 2.0f, 467.8f);
	setAreaHeight(height2_1, x21, z21, 46.0f, 101.5f, 48.0f, 105.0f, 2.0f);

	Object* Kwan_Chair25 = (Object*)malloc(sizeof(Object));
	Kwan_Chair25->location = f3(853.0f, 0.0f, 466.0f); // 8 4 (4 8)
	Kwan_Chair25->rotation = f3(0.0f, 0.0f, 0.0f);
	Kwan_Chair25->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair25 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair25->start = f3(852.0f, 0.0f, 464.2f);
	Gwangjae_Chair25->end = f3(854.0f, 2.0f, 467.8f);
	setAreaHeight(height2_1, x21, z21, 52.0f, 101.5f, 54.0f, 105.0f, 2.0f);

	/////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair26 = (Object*)malloc(sizeof(Object));
	Kwan_Chair26->location = f3(829.0f, 0.0f, 434.8f); // 8 4 (4 8)
	Kwan_Chair26->rotation = f3(0.0f, 180.0f, 0.0f);
	Kwan_Chair26->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair26 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair26->start = f3(828.0f, 0.0f, 433.0f);
	Gwangjae_Chair26->end = f3(830.0f, 2.0f, 436.6f);
	setAreaHeight(height2_1, x21, z21, 28.0f, 70.0f, 30.0f, 74.0f, 2.0f);

	Object* Kwan_Chair27 = (Object*)malloc(sizeof(Object));
	Kwan_Chair27->location = f3(835.0f, 0.0f, 434.8f); // 8 4 (4 8)
	Kwan_Chair27->rotation = f3(0.0f, 180.0f, 0.0f);
	Kwan_Chair27->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair27 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair27->start = f3(834.0f, 0.0f, 433.0f);
	Gwangjae_Chair27->end = f3(836.0f, 2.0f, 436.6f);
	setAreaHeight(height2_1, x21, z21, 34.0f, 70.0f, 36.0f, 74.0f, 2.0f);

	Object* Kwan_Chair28 = (Object*)malloc(sizeof(Object));
	Kwan_Chair28->location = f3(841.0f, 0.0f, 434.8f); // 8 4 (4 8)
	Kwan_Chair28->rotation = f3(0.0f, 180.0f, 0.0f);
	Kwan_Chair28->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair28 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair28->start = f3(840.0f, 0.0f, 433.0f);
	Gwangjae_Chair28->end = f3(842.0f, 2.0f, 436.6f);
	setAreaHeight(height2_1, x21, z21, 40.0f, 70.0f, 42.0f, 74.0f, 2.0f);

	Object* Kwan_Chair29 = (Object*)malloc(sizeof(Object));
	Kwan_Chair29->location = f3(847.0f, 0.0f, 434.8f); // 8 4 (4 8)
	Kwan_Chair29->rotation = f3(0.0f, 180.0f, 0.0f);
	Kwan_Chair29->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair29 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair29->start = f3(846.0f, 0.0f, 433.0f);
	Gwangjae_Chair29->end = f3(848.0f, 2.0f, 436.6f);
	setAreaHeight(height2_1, x21, z21, 46.0f, 70.0f, 48.0f, 74.0f, 2.0f);

	Object* Kwan_Chair30 = (Object*)malloc(sizeof(Object));
	Kwan_Chair30->location = f3(853.0f, 0.0f, 434.8f); // 8 4 (4 8)
	Kwan_Chair30->rotation = f3(0.0f, 180.0f, 0.0f);
	Kwan_Chair30->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair30 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair30->start = f3(852.0f, 0.0f, 433.0f);
	Gwangjae_Chair30->end = f3(854.0f, 2.0f, 436.6f);
	setAreaHeight(height2_1, x21, z21, 52.0f, 70.0f, 54.0f, 74.0f, 2.0f);

	///////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair31 = (Object*)malloc(sizeof(Object));
	Kwan_Chair31->location = f3(862.6f, 0.0f, 441.5f); // 8 4 (4 8)
	Kwan_Chair31->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_Chair31->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair31 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair31->start = f3(860.8f, 0.0f, 440.5f);
	Gwangjae_Chair31->end = f3(864.4f, 2.0f, 442.5f);
	setAreaHeight(height2_1, x21, z21, 61.0f, 77.5f, 64.5f, 79.5f, 2.0f);

	Object* Kwan_Chair32 = (Object*)malloc(sizeof(Object));
	Kwan_Chair32->location = f3(862.6f, 0.0f, 447.5f); // 8 4 (4 8)
	Kwan_Chair32->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_Chair32->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair32 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair32->start = f3(860.8f, 0.0f, 446.5f);
	Gwangjae_Chair32->end = f3(864.4f, 2.0f, 448.5f);
	setAreaHeight(height2_1, x21, z21, 61.0f, 83.5f, 64.5f, 85.5f, 2.0f);

	Object* Kwan_Chair33 = (Object*)malloc(sizeof(Object));
	Kwan_Chair33->location = f3(862.6f, 0.0f, 453.5f); // 8 4 (4 8)
	Kwan_Chair33->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_Chair33->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair33 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair33->start = f3(860.8f, 0.0f, 452.5f);
	Gwangjae_Chair33->end = f3(864.4f, 2.0f, 454.5f);
	setAreaHeight(height2_1, x21, z21, 61.0f, 89.5f, 64.5f, 91.5f, 2.0f);

	Object* Kwan_Chair34 = (Object*)malloc(sizeof(Object));
	Kwan_Chair34->location = f3(862.6f, 0.0f, 459.5f); // 8 4 (4 8)
	Kwan_Chair34->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_Chair34->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair34 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair34->start = f3(860.8f, 0.0f, 458.5f);
	Gwangjae_Chair34->end = f3(864.4f, 2.0f, 460.5f);
	setAreaHeight(height2_1, x21, z21, 61.0f, 95.5f, 64.5f, 97.5f, 2.0f);

	Object* Kwan_Chair35 = (Object*)malloc(sizeof(Object));
	Kwan_Chair35->location = f3(862.6f, 0.0f, 465.5f); // 8 4 (4 8)
	Kwan_Chair35->rotation = f3(0.0f, 90.0f, 0.0f);
	Kwan_Chair35->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair35 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair35->start = f3(860.8f, 0.0f, 464.5f);
	Gwangjae_Chair35->end = f3(864.4f, 2.0f, 466.5f);
	setAreaHeight(height2_1, x21, z21, 61.0f, 101.5f, 64.5f, 103.5f, 2.0f);

	////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair36 = (Object*)malloc(sizeof(Object));
	Kwan_Chair36->location = f3(851.6f, 0.0f, 406.0f); // 8 4 (4 8)
	Kwan_Chair36->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair36->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair36 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair36->start = f3(849.8f, 0.0f, 405.0f);
	Gwangjae_Chair36->end = f3(853.4f, 2.0f, 407.0f);
	setAreaHeight(height2_1, x21, z21, 50.0f, 42.0f, 53.5f, 44.0f, 2.0f);

	Object* Kwan_Chair37 = (Object*)malloc(sizeof(Object));
	Kwan_Chair37->location = f3(851.6f, 0.0f, 393.0f); // 8 4 (4 8)
	Kwan_Chair37->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair37->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair37 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair37->start = f3(849.8f, 0.0f, 392.0f);
	Gwangjae_Chair37->end = f3(853.4f, 2.0f, 394.0f);
	setAreaHeight(height2_1, x21, z21, 50.0f, 29.0f, 53.5f, 31.0f, 2.0f);

	Object* Kwan_Chair38 = (Object*)malloc(sizeof(Object));
	Kwan_Chair38->location = f3(851.6f, 0.0f, 380.0f); // 8 4 (4 8)
	Kwan_Chair38->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair38->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair38 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair38->start = f3(849.8f, 0.0f, 379.0f);
	Gwangjae_Chair38->end = f3(853.4f, 2.0f, 381.0f);
	setAreaHeight(height2_1, x21, z21, 50.0f, 16.0f, 53.5f, 18.0f, 2.0f);

	/////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair39 = (Object*)malloc(sizeof(Object));
	Kwan_Chair39->location = f3(838.6f, 0.0f, 406.0f); // 8 4 (4 8)
	Kwan_Chair39->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair39->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair39 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair39->start = f3(836.8f, 0.0f, 405.0f);
	Gwangjae_Chair39->end = f3(840.4f, 2.0f, 407.0f);
	setAreaHeight(height2_1, x21, z21, 37.0f, 42.0f, 40.5f, 44.0f, 2.0f);

	Object* Kwan_Chair40 = (Object*)malloc(sizeof(Object));
	Kwan_Chair40->location = f3(838.6f, 0.0f, 393.0f); // 8 4 (4 8)
	Kwan_Chair40->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair40->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair40 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair40->start = f3(836.8f, 0.0f, 392.0f);
	Gwangjae_Chair40->end = f3(840.4f, 2.0f, 394.0f);
	setAreaHeight(height2_1, x21, z21, 37.0f, 29.0f, 40.5f, 31.0f, 2.0f);

	Object* Kwan_Chair41 = (Object*)malloc(sizeof(Object));
	Kwan_Chair41->location = f3(838.6f, 0.0f, 380.0f); // 8 4 (4 8)
	Kwan_Chair41->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair41->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair41 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair41->start = f3(836.8f, 0.0f, 379.0f);
	Gwangjae_Chair41->end = f3(840.4f, 2.0f, 381.0f);
	setAreaHeight(height2_1, x21, z21, 37.0f, 16.0f, 40.5f, 18.0f, 2.0f);

	////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Chair42 = (Object*)malloc(sizeof(Object));
	Kwan_Chair42->location = f3(828.6f, 0.0f, 406.0f); // 8 4 (4 8)
	Kwan_Chair42->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair42->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair42 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair42->start = f3(826.8f, 0.0f, 405.0f);
	Gwangjae_Chair42->end = f3(830.4f, 2.0f, 407.0f);
	setAreaHeight(height2_1, x21, z21, 27.0f, 42.0f, 30.5f, 44.0f, 2.0f);

	Object* Kwan_Chair43 = (Object*)malloc(sizeof(Object));
	Kwan_Chair43->location = f3(828.6f, 0.0f, 393.0f); // 8 4 (4 8)
	Kwan_Chair43->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair43->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair43 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair43->start = f3(826.8f, 0.0f, 392.0f);
	Gwangjae_Chair43->end = f3(830.4f, 2.0f, 394.0f);
	setAreaHeight(height2_1, x21, z21, 27.0f, 29.0f, 30.5f, 31.0f, 2.0f);

	Object* Kwan_Chair44 = (Object*)malloc(sizeof(Object));
	Kwan_Chair44->location = f3(828.6f, 0.0f, 380.0f); // 8 4 (4 8)
	Kwan_Chair44->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Chair44->type = Gwanja_Chair;

	BoundingBox* Gwangjae_Chair44 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Chair44->start = f3(826.8f, 0.0f, 379.0f);
	Gwangjae_Chair44->end = f3(830.4f, 2.0f, 381.0f);
	setAreaHeight(height2_1, x21, z21, 27.0f, 16.0f, 30.5f, 18.0f, 2.0f);

	///////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_gar1 = (Object*)malloc(sizeof(Object));
	Receps_gar1->location = f3(843.75f, 1.5f, 534.5f);
	Receps_gar1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar1->type = Recep_garomak;

	BoundingBox* Receps_garo1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo1->start = f3(833.75f, 0.0f, 533.0f);
	Receps_garo1->end = f3(853.75f, 3.0f, 536.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 169.5f, 54.5f, 173.5f, 3.0f);

	Object* Receps_gar2 = (Object*)malloc(sizeof(Object));
	Receps_gar2->location = f3(843.75f, 1.5f, 488.5f);
	Receps_gar2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar2->type = Recep_garomak;

	BoundingBox* Receps_garo2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo2->start = f3(833.75f, 0.0f, 487.0f);
	Receps_garo2->end = f3(853.75f, 3.0f, 490.0f); // 44 더하기
	setAreaHeight(height2_1, x21, z21, 33.5f, 123.5f, 54.5f, 127.5f, 3.0f);

	Object* Receps_gar3 = (Object*)malloc(sizeof(Object));
	Receps_gar3->location = f3(843.75f, 1.5f, 473.5f);
	Receps_gar3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar3->type = Recep_garomak;

	BoundingBox* Receps_garo3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo3->start = f3(833.75f, 0.0f, 472.0f);
	Receps_garo3->end = f3(853.75f, 3.0f, 475.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 108.5f, 54.5f, 112.5f, 3.0f);

	Object* Receps_gar4 = (Object*)malloc(sizeof(Object));
	Receps_gar4->location = f3(843.75f, 1.5f, 430.5f);
	Receps_gar4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar4->type = Recep_garomak;

	BoundingBox* Receps_garo4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo4->start = f3(833.75f, 0.0f, 429.0f);
	Receps_garo4->end = f3(853.75f, 3.0f, 432.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 65.5f, 54.5f, 69.5f, 3.0f);

	Object* Receps_gar5 = (Object*)malloc(sizeof(Object));
	Receps_gar5->location = f3(843.75f, 1.5f, 415.5f);
	Receps_gar5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar5->type = Recep_garomak;

	BoundingBox* Receps_garo5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo5->start = f3(833.75f, 0.0f, 414.0f);
	Receps_garo5->end = f3(853.75f, 3.0f, 417.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 50.5f, 54.5f, 54.5f, 3.0f);

	Object* Receps_gar6 = (Object*)malloc(sizeof(Object));
	Receps_gar6->location = f3(843.75f, 1.5f, 371.5f);
	Receps_gar6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_gar6->type = Recep_garomak;

	BoundingBox* Receps_garo6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_garo6->start = f3(833.75f, 0.0f, 370.0f);
	Receps_garo6->end = f3(853.75f, 3.0f, 373.0f);
	setAreaHeight(height2_1, x21, z21, 33.5f, 6.5f, 54.5f, 10.5f, 3.0f);

	// 540 482
	Object* Kwan_Cabin = (Object*)malloc(sizeof(Object));
	Kwan_Cabin->location = f3(814.0f, 0.0f, 535.0f); // 8 4 (4 8)
	Kwan_Cabin->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet->start = f3(812.5f, 0.0f, 532.0f);
	Gwangjae_Cabinet->end = f3(815.5f, 8.0f, 538.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 169.0f, 16.0f, 175.0f, 8.0f);

	Object* Kwan_Cabin2 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin2->location = f3(814.0f, 0.0f, 507.0f); // 8 4 (4 8)
	Kwan_Cabin2->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin2->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet2->start = f3(812.5f, 0.0f, 504.0f);
	Gwangjae_Cabinet2->end = f3(815.5f, 8.0f, 510.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 140.5f, 16.0f, 147.5f, 8.0f);

	Object* Kwan_Cabin3 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin3->location = f3(814.0f, 0.0f, 485.0f); // 8 4 (4 8)
	Kwan_Cabin3->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin3->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet3->start = f3(812.5f, 0.0f, 482.0f);
	Gwangjae_Cabinet3->end = f3(815.5f, 8.0f, 488.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 118.5f, 16.0f, 125.5f, 8.0f);

	/////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Cabin4 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin4->location = f3(814.0f, 0.0f, 477.0f); // 8 4 (4 8)
	Kwan_Cabin4->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin4->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet4->start = f3(812.5f, 0.0f, 474.0f);
	Gwangjae_Cabinet4->end = f3(815.5f, 8.0f, 480.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 111.5f, 16.0f, 117.5f, 8.0f);

	Object* Kwan_Cabin5 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin5->location = f3(814.0f, 0.0f, 449.0f); // 8 4 (4 8)
	Kwan_Cabin5->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin5->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet5->start = f3(812.5f, 0.0f, 446.0f);
	Gwangjae_Cabinet5->end = f3(815.5f, 8.0f, 452.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 83.5f, 16.0f, 89.5f, 8.0f);

	Object* Kwan_Cabin6 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin6->location = f3(814.0f, 0.0f, 427.0f); // 8 4 (4 8)
	Kwan_Cabin6->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin6->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet6->start = f3(812.5f, 0.0f, 424.0f);
	Gwangjae_Cabinet6->end = f3(815.5f, 8.0f, 430.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 61.5f, 16.0f, 67.5f, 8.0f);

	//////////////////////////////////////////////////////////////////////////////////////////////

	Object* Kwan_Cabin7 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin7->location = f3(814.0f, 0.0f, 419.0f); // 8 4 (4 8)
	Kwan_Cabin7->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin7->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet7->start = f3(812.5f, 0.0f, 416.0f);
	Gwangjae_Cabinet7->end = f3(815.5f, 8.0f, 422.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 53.5f, 16.0f, 59.5f, 8.0f);

	Object* Kwan_Cabin8 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin8->location = f3(814.0f, 0.0f, 400.5f); // 8 4 (4 8)
	Kwan_Cabin8->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin8->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet8->start = f3(812.5f, 0.0f, 397.5f);
	Gwangjae_Cabinet8->end = f3(815.5f, 8.0f, 403.5f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 35.0f, 16.0f, 41.0f, 8.0f);

	Object* Kwan_Cabin9 = (Object*)malloc(sizeof(Object));
	Kwan_Cabin9->location = f3(814.0f, 0.0f, 368.0f); // 8 4 (4 8)
	Kwan_Cabin9->rotation = f3(0.0f, -90.0f, 0.0f);
	Kwan_Cabin9->type = Gwanja_Cabinet;

	BoundingBox* Gwangjae_Cabinet9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Gwangjae_Cabinet9->start = f3(812.5f, 0.0f, 365.0f);
	Gwangjae_Cabinet9->end = f3(815.5f, 8.0f, 371.0f);
	setAreaHeight(height2_1, x21, z21, 12.0f, 2.5f, 16.0f, 8.5f, 8.0f);




	///////////////////////////////////////////////////////////////////////////////////////////////


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


	list.push_back(*Kwan_Screens);
	blist.push_back(*Gwangjae_Screens);

	list.push_back(*Kwan_Screens2);
	blist.push_back(*Gwangjae_Screens2);

	list.push_back(*Kwan_Screens3);
	blist.push_back(*Gwangjae_Screens3);

	//////////////////////////////////////////////////


	list.push_back(*Kwan_tables1);
	blist.push_back(*Gwangjae_tables1);

	list.push_back(*Kwan_tables2);
	blist.push_back(*Gwangjae_tables2);

	list.push_back(*Kwan_tables3);
	blist.push_back(*Gwangjae_tables3);

	list.push_back(*Kwan_tables4);
	blist.push_back(*Gwangjae_tables4);

	list.push_back(*Kwan_tables5);
	blist.push_back(*Gwangjae_tables5);

	list.push_back(*Kwan_tables6);
	blist.push_back(*Gwangjae_tables6);

	list.push_back(*Kwan_tables7);
	blist.push_back(*Gwangjae_tables7);

	list.push_back(*Kwan_tables8);
	blist.push_back(*Gwangjae_tables8);

	list.push_back(*Kwan_tables9);
	blist.push_back(*Gwangjae_tables9);

	list.push_back(*Kwan_tables10);
	blist.push_back(*Gwangjae_tables10);

	list.push_back(*Kwan_tables11);
	blist.push_back(*Gwangjae_tables11);

	list.push_back(*Kwan_tables12);
	blist.push_back(*Gwangjae_tables12);

	list.push_back(*Kwan_tables13);
	blist.push_back(*Gwangjae_tables13);

	list.push_back(*Kwan_tables14);
	blist.push_back(*Gwangjae_tables14);

	list.push_back(*Kwan_tables15);
	blist.push_back(*Gwangjae_tables15);

	list.push_back(*Kwan_tables16);
	blist.push_back(*Gwangjae_tables16);

	///////////////////////////////////

	list.push_back(*Kwan_Chair1);
	blist.push_back(*Gwangjae_Chair1);

	list.push_back(*Kwan_Chair2);
	blist.push_back(*Gwangjae_Chair2);

	list.push_back(*Kwan_Chair3);
	blist.push_back(*Gwangjae_Chair3);

	list.push_back(*Kwan_Chair4);
	blist.push_back(*Gwangjae_Chair4);

	list.push_back(*Kwan_Chair5);
	blist.push_back(*Gwangjae_Chair5);

	list.push_back(*Kwan_Chair6);
	blist.push_back(*Gwangjae_Chair6);

	list.push_back(*Kwan_Chair7);
	blist.push_back(*Gwangjae_Chair7);

	list.push_back(*Kwan_Chair8);
	blist.push_back(*Gwangjae_Chair8);

	list.push_back(*Kwan_Chair9);
	blist.push_back(*Gwangjae_Chair9);

	list.push_back(*Kwan_Chair10);
	blist.push_back(*Gwangjae_Chair10);

	list.push_back(*Kwan_Chair11);
	blist.push_back(*Gwangjae_Chair11);

	list.push_back(*Kwan_Chair12);
	blist.push_back(*Gwangjae_Chair12);

	list.push_back(*Kwan_Chair13);
	blist.push_back(*Gwangjae_Chair13);

	list.push_back(*Kwan_Chair14);
	blist.push_back(*Gwangjae_Chair14);

	list.push_back(*Kwan_Chair15);
	blist.push_back(*Gwangjae_Chair15);

	list.push_back(*Kwan_Chair16);
	blist.push_back(*Gwangjae_Chair16);

	list.push_back(*Kwan_Chair17);
	blist.push_back(*Gwangjae_Chair17);

	list.push_back(*Kwan_Chair18);
	blist.push_back(*Gwangjae_Chair18);

	list.push_back(*Kwan_Chair19);
	blist.push_back(*Gwangjae_Chair19);

	list.push_back(*Kwan_Chair20);
	blist.push_back(*Gwangjae_Chair20);

	list.push_back(*Kwan_Chair21);
	blist.push_back(*Gwangjae_Chair21);

	list.push_back(*Kwan_Chair22);
	blist.push_back(*Gwangjae_Chair22);

	list.push_back(*Kwan_Chair23);
	blist.push_back(*Gwangjae_Chair23);

	list.push_back(*Kwan_Chair24);
	blist.push_back(*Gwangjae_Chair24);

	list.push_back(*Kwan_Chair25);
	blist.push_back(*Gwangjae_Chair25);

	list.push_back(*Kwan_Chair26);
	blist.push_back(*Gwangjae_Chair26);

	list.push_back(*Kwan_Chair27);
	blist.push_back(*Gwangjae_Chair27);

	list.push_back(*Kwan_Chair28);
	blist.push_back(*Gwangjae_Chair28);

	list.push_back(*Kwan_Chair29);
	blist.push_back(*Gwangjae_Chair29);

	list.push_back(*Kwan_Chair30);
	blist.push_back(*Gwangjae_Chair30);

	list.push_back(*Kwan_Chair31);
	blist.push_back(*Gwangjae_Chair31);

	list.push_back(*Kwan_Chair32);
	blist.push_back(*Gwangjae_Chair32);

	list.push_back(*Kwan_Chair33);
	blist.push_back(*Gwangjae_Chair33);

	list.push_back(*Kwan_Chair34);
	blist.push_back(*Gwangjae_Chair34);

	list.push_back(*Kwan_Chair35);
	blist.push_back(*Gwangjae_Chair35);

	list.push_back(*Kwan_Chair36);
	blist.push_back(*Gwangjae_Chair36);

	list.push_back(*Kwan_Chair37);
	blist.push_back(*Gwangjae_Chair37);

	list.push_back(*Kwan_Chair38);
	blist.push_back(*Gwangjae_Chair38);

	list.push_back(*Kwan_Chair39);
	blist.push_back(*Gwangjae_Chair39);

	list.push_back(*Kwan_Chair40);
	blist.push_back(*Gwangjae_Chair40);

	list.push_back(*Kwan_Chair41);
	blist.push_back(*Gwangjae_Chair41);

	list.push_back(*Kwan_Chair42);
	blist.push_back(*Gwangjae_Chair42);

	list.push_back(*Kwan_Chair43);
	blist.push_back(*Gwangjae_Chair43);

	list.push_back(*Kwan_Chair44);
	blist.push_back(*Gwangjae_Chair44);

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

	/////////////////////////////////////////

	list.push_back(*Kwan_Cabin);
	blist.push_back(*Gwangjae_Cabinet);

	list.push_back(*Kwan_Cabin2);
	blist.push_back(*Gwangjae_Cabinet2);

	list.push_back(*Kwan_Cabin3);
	blist.push_back(*Gwangjae_Cabinet3);

	list.push_back(*Kwan_Cabin4);
	blist.push_back(*Gwangjae_Cabinet4);

	list.push_back(*Kwan_Cabin5);
	blist.push_back(*Gwangjae_Cabinet5);

	list.push_back(*Kwan_Cabin6);
	blist.push_back(*Gwangjae_Cabinet6);

	list.push_back(*Kwan_Cabin7);
	blist.push_back(*Gwangjae_Cabinet7);

	list.push_back(*Kwan_Cabin8);
	blist.push_back(*Gwangjae_Cabinet8);

	list.push_back(*Kwan_Cabin9);
	blist.push_back(*Gwangjae_Cabinet9);
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
	//setAreaHeight(height2_2, x22, z22, 0.0f, 0.0f, 75.0f, 305.0f, 12.5f);

	Object* Receps_floor1 = (Object*)malloc(sizeof(Object));
	Receps_floor1->location = f3(800.0f, 0.001f, 0.0f);
	Receps_floor1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_floor1->type = Recep_floor;

	BoundingBox* receps_floor1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	receps_floor1->start = f3(800.0f, 0.00f, 0.0f);
	receps_floor1->end = f3(875.0f, 0.00f, 365.0f);
	setAreaHeight(height2_2, x22, z22, 0.0f, 0.0f, 75.0f, 305.0f, 0.0f);

	/////////////////////////////////////////////////////////////////

	Object* Receps_wall1 = (Object*)malloc(sizeof(Object));
	Receps_wall1->location = f3(875.4f, 3.75f, 355.0f);
	Receps_wall1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1->type = Recep_wall1;

	BoundingBox* Receps_walled1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled1->start = f3(874.9f, 0.0f, 345.0f);
	Receps_walled1->end = f3(875.4f, 7.5f, 365.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 285.0f, 75.5f, 305.0f, 7.5f);

	Object* Receps_wall2 = (Object*)malloc(sizeof(Object));
	Receps_wall2->location = f3(875.4f, 3.75f, 335.0f);
	Receps_wall2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2->type = Recep_wall1;

	BoundingBox* Receps_walled2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled2->start = f3(874.9f, 0.0f, 325.0f);
	Receps_walled2->end = f3(875.4f, 7.5f, 345.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 265.0f, 75.5f, 285.0f, 7.5f);

	Object* Receps_wall3 = (Object*)malloc(sizeof(Object));
	Receps_wall3->location = f3(875.4f, 3.75f, 315.0f);
	Receps_wall3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3->type = Recep_wall1;

	BoundingBox* Receps_walled3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled3->start = f3(874.9f, 0.0f, 305.0f);
	Receps_walled3->end = f3(875.4f, 7.5f, 325.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 245.0f, 75.5f, 265.0f, 7.5f);

	Object* Receps_wall4 = (Object*)malloc(sizeof(Object));
	Receps_wall4->location = f3(875.4f, 3.75f, 295.0f);
	Receps_wall4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4->type = Recep_wall1;

	BoundingBox* Receps_walled4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled4->start = f3(874.9f, 0.0f, 285.0f);
	Receps_walled4->end = f3(875.4f, 7.5f, 305.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 225.0f, 75.5f, 245.0f, 7.5f);

	Object* Receps_wall5 = (Object*)malloc(sizeof(Object));
	Receps_wall5->location = f3(875.4f, 3.75f, 275.0f);
	Receps_wall5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5->type = Recep_wall1;

	BoundingBox* Receps_walled5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled5->start = f3(874.9f, 0.0f, 265.0f);
	Receps_walled5->end = f3(875.4f, 7.5f, 285.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 205.0f, 75.5f, 225.0f, 7.5f);

	Object* Receps_wall6 = (Object*)malloc(sizeof(Object));
	Receps_wall6->location = f3(875.4f, 3.75f, 255.0f);
	Receps_wall6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6->type = Recep_wall1;

	BoundingBox* Receps_walled6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled6->start = f3(874.9f, 0.0f, 245.0f);
	Receps_walled6->end = f3(875.4f, 7.5f, 265.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 185.0f, 75.5f, 205.0f, 7.5f);

	Object* Receps_wall7 = (Object*)malloc(sizeof(Object));
	Receps_wall7->location = f3(875.4f, 3.75f, 235.0f);
	Receps_wall7->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7->type = Recep_wall1;

	BoundingBox* Receps_walled7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled7->start = f3(874.9f, 0.0f, 225.0f);
	Receps_walled7->end = f3(875.4f, 7.5f, 245.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 165.0f, 75.5f, 185.0f, 7.5f);

	/////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_wall1R = (Object*)malloc(sizeof(Object));
	Receps_wall1R->location = f3(812.1f, 3.75f, 355.0f);
	Receps_wall1R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1R->type = Recep_wall1;

	BoundingBox* Receps_walled1R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled1R->start = f3(812.0f, 0.0f, 345.0f);
	Receps_walled1R->end = f3(813.0f, 7.5f, 365.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 285.0f, 13.0f, 305.0f, 7.5f);

	Object* Receps_wall2R = (Object*)malloc(sizeof(Object));
	Receps_wall2R->location = f3(812.1f, 3.75f, 335.0f);
	Receps_wall2R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2R->type = Recep_wall1;

	BoundingBox* Receps_walled2R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled2R->start = f3(812.0f, 0.0f, 325.0f);
	Receps_walled2R->end = f3(813.0f, 7.5f, 345.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 265.0f, 13.0f, 285.0f, 7.5f);

	Object* Receps_wall3R = (Object*)malloc(sizeof(Object));
	Receps_wall3R->location = f3(812.1f, 3.75f, 315.0f);
	Receps_wall3R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3R->type = Recep_wall1;

	BoundingBox* Receps_walled3R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled3R->start = f3(812.0f, 0.0f, 305.0f);
	Receps_walled3R->end = f3(813.0f, 7.5f, 325.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 245.0f, 13.0f, 265.0f, 7.5f);

	Object* Receps_wall4R = (Object*)malloc(sizeof(Object));
	Receps_wall4R->location = f3(812.1f, 3.75f, 295.0f);
	Receps_wall4R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4R->type = Recep_wall1;

	BoundingBox* Receps_walled4R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled4R->start = f3(812.0f, 0.0f, 285.0f);
	Receps_walled4R->end = f3(813.0f, 7.5f, 305.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 225.0f, 13.0f, 245.0f, 7.5f);

	Object* Receps_wall5R = (Object*)malloc(sizeof(Object));
	Receps_wall5R->location = f3(812.1f, 3.75f, 275.0f);
	Receps_wall5R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5R->type = Recep_wall1;

	BoundingBox* Receps_walled5R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled5R->start = f3(812.0f, 0.0f, 265.0f);
	Receps_walled5R->end = f3(813.0f, 7.5f, 285.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 205.0f, 13.0f, 225.0f, 7.5f);


	Object* Receps_wall6R = (Object*)malloc(sizeof(Object));
	Receps_wall6R->location = f3(812.1f, 3.75f, 255.0f);
	Receps_wall6R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6R->type = Recep_wall1;

	BoundingBox* Receps_walled6R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled6R->start = f3(812.0f, 0.0f, 245.0f);
	Receps_walled6R->end = f3(813.0f, 7.5f, 265.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 185.0f, 13.0f, 205.0f, 7.5f);

	Object* Receps_wall7R = (Object*)malloc(sizeof(Object));
	Receps_wall7R->location = f3(812.1f, 3.75f, 235.0f);
	Receps_wall7R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7R->type = Recep_wall1;

	BoundingBox* Receps_walled7R = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_walled7R->start = f3(812.0f, 0.0f, 225.0f);
	Receps_walled7R->end = f3(813.0f, 7.5f, 245.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 165.0f, 13.0f, 185.0f, 7.5f);

	////////////////////////////////////////////////////////////////////////

	Object* Receps_wall1e = (Object*)malloc(sizeof(Object));
	Receps_wall1e->location = f3(812.1f, 10.0f, 355.0f);
	Receps_wall1e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1e->type = Recep_wall2;

	BoundingBox* Receps_wall1ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall1ede->start = f3(812.0f, 7.5f, 345.0f);
	Receps_wall1ede->end = f3(813.0f, 12.5f, 365.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 285.0f, 13.0f, 305.0f, 12.5f);

	Object* Receps_wall2e = (Object*)malloc(sizeof(Object));
	Receps_wall2e->location = f3(812.1f, 10.0f, 335.0f);
	Receps_wall2e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2e->type = Recep_wall2;

	BoundingBox* Receps_wall2ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall2ede->start = f3(812.0f, 7.5f, 325.0f);
	Receps_wall2ede->end = f3(813.0f, 12.5f, 345.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 265.0f, 13.0f, 285.0f, 12.5f);

	Object* Receps_wall3e = (Object*)malloc(sizeof(Object));
	Receps_wall3e->location = f3(812.1f, 10.0f, 315.0f);
	Receps_wall3e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3e->type = Recep_wall2;

	BoundingBox* Receps_wall3ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall3ede->start = f3(812.0f, 7.5f, 305.0f);
	Receps_wall3ede->end = f3(813.0f, 12.5f, 325.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 245.0f, 13.0f, 265.0f, 12.5f);

	Object* Receps_wall4e = (Object*)malloc(sizeof(Object));
	Receps_wall4e->location = f3(812.1f, 10.0f, 295.0f);
	Receps_wall4e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4e->type = Recep_wall2;

	BoundingBox* Receps_wall4ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall4ede->start = f3(812.0f, 7.5f, 285.0f);
	Receps_wall4ede->end = f3(813.0f, 12.5f, 305.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 225.0f, 13.0f, 245.0f, 12.5f);

	Object* Receps_wall5e = (Object*)malloc(sizeof(Object));
	Receps_wall5e->location = f3(812.1f, 10.0f, 275.0f);
	Receps_wall5e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5e->type = Recep_wall2;

	BoundingBox* Receps_wall5ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall5ede->start = f3(812.0f, 7.5f, 265.0f);
	Receps_wall5ede->end = f3(813.0f, 12.5f, 285.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 205.0f, 13.0f, 225.0f, 12.5f);

	Object* Receps_wall6e = (Object*)malloc(sizeof(Object));
	Receps_wall6e->location = f3(812.1f, 10.0f, 255.0f);
	Receps_wall6e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6e->type = Recep_wall2;

	BoundingBox* Receps_wall6ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall6ede->start = f3(812.0f, 7.5f, 245.0f);
	Receps_wall6ede->end = f3(813.0f, 12.5f, 265.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 185.0f, 13.0f, 205.0f, 12.5f);

	Object* Receps_wall7e = (Object*)malloc(sizeof(Object));
	Receps_wall7e->location = f3(812.1f, 10.0f, 235.0f);
	Receps_wall7e->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7e->type = Recep_wall2;

	BoundingBox* Receps_wall7ede = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall7ede->start = f3(812.0f, 7.5f, 225.0f);
	Receps_wall7ede->end = f3(813.0f, 12.5f, 245.0f);
	setAreaHeight(height2_2, x22, z22, 12.0f, 165.0f, 13.0f, 185.0f, 12.5f);

	////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_wall1eL = (Object*)malloc(sizeof(Object));
	Receps_wall1eL->location = f3(875.4f, 10.0f, 355.0f);
	Receps_wall1eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall1eL->type = Recep_wall2;

	BoundingBox* Receps_wall1edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall1edeL->start = f3(875.0f, 7.5f, 345.0f);
	Receps_wall1edeL->end = f3(875.4f, 12.5f, 365.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 285.0f, 75.5f, 305.0f, 12.5f);

	Object* Receps_wall2eL = (Object*)malloc(sizeof(Object));
	Receps_wall2eL->location = f3(875.4f, 10.0f, 335.0f);
	Receps_wall2eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall2eL->type = Recep_wall2;

	BoundingBox* Receps_wall2edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall2edeL->start = f3(875.0f, 7.5f, 325.0f);
	Receps_wall2edeL->end = f3(875.4f, 12.5f, 345.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 265.0f, 75.5f, 285.0f, 12.5f);

	Object* Receps_wall3eL = (Object*)malloc(sizeof(Object));
	Receps_wall3eL->location = f3(875.4f, 10.0f, 315.0f);
	Receps_wall3eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall3eL->type = Recep_wall2;

	BoundingBox* Receps_wall3edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall3edeL->start = f3(875.0f, 7.5f, 305.0f);
	Receps_wall3edeL->end = f3(875.4f, 12.5f, 325.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 245.0f, 75.5f, 265.0f, 12.5f);

	Object* Receps_wall4eL = (Object*)malloc(sizeof(Object));
	Receps_wall4eL->location = f3(875.4f, 10.0f, 295.0f);
	Receps_wall4eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall4eL->type = Recep_wall2;

	BoundingBox* Receps_wall4edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall4edeL->start = f3(875.0f, 7.5f, 285.0f);
	Receps_wall4edeL->end = f3(875.4f, 12.5f, 305.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 225.0f, 75.5f, 245.0f, 12.5f);

	Object* Receps_wall5eL = (Object*)malloc(sizeof(Object));
	Receps_wall5eL->location = f3(875.4f, 10.0f, 275.0f);
	Receps_wall5eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall5eL->type = Recep_wall2;

	BoundingBox* Receps_wall5edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall5edeL->start = f3(875.0f, 7.5f, 265.0f);
	Receps_wall5edeL->end = f3(875.4f, 12.5f, 285.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 205.0f, 75.5f, 225.0f, 12.5f);

	Object* Receps_wall6eL = (Object*)malloc(sizeof(Object));
	Receps_wall6eL->location = f3(875.4f, 10.0f, 255.0f);
	Receps_wall6eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall6eL->type = Recep_wall2;

	BoundingBox* Receps_wall6edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall6edeL->start = f3(875.0f, 7.5f, 245.0f);
	Receps_wall6edeL->end = f3(875.4f, 12.5f, 265.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 185.0f, 75.5f, 205.0f, 12.5f);

	Object* Receps_wall7eL = (Object*)malloc(sizeof(Object));
	Receps_wall7eL->location = f3(875.4f, 10.0f, 235.0f);
	Receps_wall7eL->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_wall7eL->type = Recep_wall2;

	BoundingBox* Receps_wall7edeL = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_wall7edeL->start = f3(875.0f, 7.5f, 225.0f);
	Receps_wall7edeL->end = f3(875.4f, 12.5f, 245.0f);
	setAreaHeight(height2_2, x22, z22, 74.5f, 165.0f, 75.5f, 185.0f, 12.5f);

	//////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_front1 = (Object*)malloc(sizeof(Object));
	Receps_front1->location = f3(822.916f, 7.5f, 224.0f); // 20.833
	Receps_front1->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_front1->type = Recep_front;

	BoundingBox* Receps_fronted1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronted1->start = f3(812.5f, 2.5f, 223.0f);
	Receps_fronted1->end = f3(833.333f, 12.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 12.5f, 162.5f, 33.5f, 165.5f, 12.5f);

	Object* Receps_front2 = (Object*)malloc(sizeof(Object));
	Receps_front2->location = f3(843.799f, 7.5f, 224.0f); // 20.833
	Receps_front2->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_front2->type = Recep_front;

	BoundingBox* Receps_fronted2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronted2->start = f3(833.333f, 2.5f, 223.0f);
	Receps_fronted2->end = f3(854.166f, 12.5f, 225.0f);
	// setAreaHeight(height2_2, x22, z22, 33.5f, 163.0f, 54.5f, 165.0f, 12.5f);

	Object* Receps_front3 = (Object*)malloc(sizeof(Object));
	Receps_front3->location = f3(864.633f, 7.5f, 224.0f); // 20.833
	Receps_front3->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_front3->type = Recep_front;

	BoundingBox* Receps_fronted3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronted3->start = f3(854.166f, 2.5f, 223.0f);
	Receps_fronted3->end = f3(875.0f, 12.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 54.5f, 162.5f, 75.0f, 165.5f, 12.5f);

	////////////////////////////////////////////////////////////////////////////////

	Object* Receps_fronte1 = (Object*)malloc(sizeof(Object));
	Receps_fronte1->location = f3(820.0f, 1.25f, 224.0f);
	Receps_fronte1->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte1->type = Recep_front2;

	BoundingBox* Receps_fronte1e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte1e->start = f3(812.5f, 0.0f, 223.0f);
	Receps_fronte1e->end = f3(827.5f, 2.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 12.5f, 162.5f, 27.5f, 165.5f, 2.5f);

	Object* Receps_fronte2 = (Object*)malloc(sizeof(Object));
	Receps_fronte2->location = f3(835.0f, 1.25f, 224.0f);
	Receps_fronte2->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte2->type = Recep_front2;

	BoundingBox* Receps_fronte2e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte2e->start = f3(827.5f, 0.0f, 223.0f);
	Receps_fronte2e->end = f3(842.5f, 2.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 27.5f, 162.5f, 42.5f, 165.5f, 2.5f);

	Object* Receps_fronte3 = (Object*)malloc(sizeof(Object));
	Receps_fronte3->location = f3(852.5f, 1.25f, 224.0f);
	Receps_fronte3->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte3->type = Recep_front2;

	BoundingBox* Receps_fronte3e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte3e->start = f3(845.0f, 0.0f, 223.0f);
	Receps_fronte3e->end = f3(860.0f, 2.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 45.0f, 162.5f, 60.0f, 165.5f, 2.5f);

	Object* Receps_fronte4 = (Object*)malloc(sizeof(Object));
	Receps_fronte4->location = f3(867.5f, 1.25f, 224.0f);
	Receps_fronte4->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_fronte4->type = Recep_front2;

	BoundingBox* Receps_fronte4e = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_fronte4e->start = f3(860.0f, 0.0f, 223.0f);
	Receps_fronte4e->end = f3(875.0f, 2.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 60.0f, 162.5f, 75.0f, 165.5f, 2.5f);

	///////////////////////////////////////////////////////////////////////////


	Object* Receps_ipgu = (Object*)malloc(sizeof(Object));
	Receps_ipgu->location = f3(874.0f, 7.5f, 87.5f);
	Receps_ipgu->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu->type = Recep_wall3;

	BoundingBox* Receps_iping = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping->start = f3(873.0f, 2.5f, 75.0f);
	Receps_iping->end = f3(875.0f, 12.5f, 100.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 15.0f, 75.5f, 40.0f, 12.5f);

	Object* Receps_ipgu2 = (Object*)malloc(sizeof(Object));
	Receps_ipgu2->location = f3(874.0f, 7.5f, 112.5f);
	Receps_ipgu2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu2->type = Recep_wall3;

	BoundingBox* Receps_iping2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping2->start = f3(873.0f, 2.5f, 100.0f);
	Receps_iping2->end = f3(875.0f, 12.5f, 125.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 40.0f, 75.5f, 65.0f, 12.5f);

	Object* Receps_ipgu3 = (Object*)malloc(sizeof(Object));
	Receps_ipgu3->location = f3(874.0f, 7.5f, 137.5f);
	Receps_ipgu3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu3->type = Recep_wall3;

	BoundingBox* Receps_iping3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping3->start = f3(873.0f, 2.5f, 125.0f);
	Receps_iping3->end = f3(875.0f, 12.5f, 150.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 65.0f, 75.5f, 90.0f, 12.5f);

	Object* Receps_ipgu4 = (Object*)malloc(sizeof(Object));
	Receps_ipgu4->location = f3(874.0f, 7.5f, 162.5f);
	Receps_ipgu4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu4->type = Recep_wall3;

	BoundingBox* Receps_iping4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping4->start = f3(873.0f, 2.5f, 150.0f);
	Receps_iping4->end = f3(875.0f, 12.5f, 175.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 90.0f, 75.5f, 115.0f, 12.5f);

	Object* Receps_ipgu5 = (Object*)malloc(sizeof(Object));
	Receps_ipgu5->location = f3(874.0f, 7.5f, 187.5f);
	Receps_ipgu5->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu5->type = Recep_wall3;

	BoundingBox* Receps_iping5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping5->start = f3(873.0f, 2.5f, 175.0f);
	Receps_iping5->end = f3(875.0f, 12.5f, 200.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 115.0f, 75.5f, 140.0f, 12.5f);

	Object* Receps_ipgu6 = (Object*)malloc(sizeof(Object));
	Receps_ipgu6->location = f3(874.0f, 7.5f, 212.5f);
	Receps_ipgu6->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu6->type = Recep_wall3;

	BoundingBox* Receps_iping6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping6->start = f3(873.0f, 2.5f, 200.0f);
	Receps_iping6->end = f3(875.0f, 12.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 140.0f, 75.5f, 165.0f, 12.5f);

	////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu4_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu4_l->location = f3(874.0f, 1.25f, 162.5f);
	Receps_ipgu4_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu4_l->type = Recep_wall5;

	BoundingBox* Receps_iping4_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping4_l->start = f3(873.0f, 0.0f, 150.0f);
	Receps_iping4_l->end = f3(875.0f, 2.5f, 175.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 90.0f, 75.5f, 115.0f, 2.5f);

	Object* Receps_ipgu5_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu5_l->location = f3(874.0f, 1.25f, 187.5f);
	Receps_ipgu5_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu5_l->type = Recep_wall5;

	BoundingBox* Receps_iping5_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping5_l->start = f3(873.0f, 0.0f, 175.0f);
	Receps_iping5_l->end = f3(875.0f, 2.5f, 200.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f, 115.0f, 75.5f, 140.0f, 2.5f);

	Object* Receps_ipgu6_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu6_l->location = f3(874.0f, 1.25f, 212.5f);
	Receps_ipgu6_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu6_l->type = Recep_wall5;

	BoundingBox* Receps_iping6_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping6_l->start = f3(873.0f, 0.0f, 200.0f);
	Receps_iping6_l->end = f3(875.0f, 2.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 72.5f,140.0f, 75.5f, 165.0f, 2.5f);

	////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu7 = (Object*)malloc(sizeof(Object));
	Receps_ipgu7->location = f3(811.6f, 7.5f, 87.5f);
	Receps_ipgu7->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu7->type = Recep_wall3;

	BoundingBox* Receps_iping7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping7->start = f3(810.6f, 2.5f, 75.0f);
	Receps_iping7->end = f3(812.6f, 12.5f, 100.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 15.0f, 13.0f, 40.0f, 12.5f);

	Object* Receps_ipgu8 = (Object*)malloc(sizeof(Object));
	Receps_ipgu8->location = f3(811.6f, 7.5f, 112.5f);
	Receps_ipgu8->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu8->type = Recep_wall3;

	BoundingBox* Receps_iping8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping8->start = f3(810.6f, 2.5f, 100.0f);
	Receps_iping8->end = f3(812.6f, 12.5f, 125.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 40.0f, 13.0f, 65.0f, 12.5f);

	Object* Receps_ipgu9 = (Object*)malloc(sizeof(Object));
	Receps_ipgu9->location = f3(811.6f, 7.5f, 137.5f);
	Receps_ipgu9->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu9->type = Recep_wall3;

	BoundingBox* Receps_iping9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping9->start = f3(810.6f, 2.5f, 125.0f);
	Receps_iping9->end = f3(812.6f, 12.5f, 150.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 65.0f, 13.0f, 90.0f, 12.5f);

	Object* Receps_ipgu10 = (Object*)malloc(sizeof(Object));
	Receps_ipgu10->location = f3(811.6f, 7.5f, 162.5f);
	Receps_ipgu10->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu10->type = Recep_wall3;

	BoundingBox* Receps_iping10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping10->start = f3(810.6f, 2.5f, 150.0f);
	Receps_iping10->end = f3(812.6f, 12.5f, 175.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 90.0f, 13.0f, 115.0f, 12.5f);

	Object* Receps_ipgu11 = (Object*)malloc(sizeof(Object));
	Receps_ipgu11->location = f3(811.6f, 7.5f, 187.5f);
	Receps_ipgu11->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu11->type = Recep_wall3;

	BoundingBox* Receps_iping11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping11->start = f3(810.6f, 2.5f, 175.0f);
	Receps_iping11->end = f3(812.6f, 12.5f, 200.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 115.0f, 13.0f, 140.0f, 12.5f);

	Object* Receps_ipgu12 = (Object*)malloc(sizeof(Object));
	Receps_ipgu12->location = f3(811.6f, 7.5f, 212.5f);
	Receps_ipgu12->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu12->type = Recep_wall3;

	BoundingBox* Receps_iping12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping12->start = f3(810.6f, 2.5f, 200.0f);
	Receps_iping12->end = f3(812.6f, 12.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 140.0f, 13.0f, 165.0f, 12.5f);

	//////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu7_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu7_l->location = f3(811.6f, 1.25f, 87.5f);
	Receps_ipgu7_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu7_l->type = Recep_wall5;

	BoundingBox* Receps_iping7_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping7_l->start = f3(810.6f, 0.0f, 75.0f);
	Receps_iping7_l->end = f3(812.6f, 2.5f, 100.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 15.0f, 13.0f, 40.0f, 2.5f);

	Object* Receps_ipgu8_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu8_l->location = f3(811.6f, 1.25f, 112.5f);
	Receps_ipgu8_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu8_l->type = Recep_wall5;

	BoundingBox* Receps_iping8_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping8_l->start = f3(810.6f, 0.0f, 100.0f);
	Receps_iping8_l->end = f3(812.6f, 2.5f, 125.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 40.0f, 13.0f, 65.0f, 2.5f);

	Object* Receps_ipgu9_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu9_l->location = f3(811.6f, 1.25f, 137.5f);
	Receps_ipgu9_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu9_l->type = Recep_wall5;

	BoundingBox* Receps_iping9_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping9_l->start = f3(810.6f, 0.0f, 125.0f);
	Receps_iping9_l->end = f3(812.6f, 2.5f, 150.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 65.0f, 13.0f, 90.0f, 2.5f);

	Object* Receps_ipgu10_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu10_l->location = f3(811.6f, 1.25f, 162.5f);
	Receps_ipgu10_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu10_l->type = Recep_wall5;

	BoundingBox* Receps_iping10_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping10_l->start = f3(810.6f, 0.0f, 150.0f);
	Receps_iping10_l->end = f3(812.6f, 2.5f, 175.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 90.0f, 13.0f, 115.0f, 2.5f);

	Object* Receps_ipgu11_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu11_l->location = f3(811.6f, 1.25f, 187.5f);
	Receps_ipgu11_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu11_l->type = Recep_wall5;

	BoundingBox* Receps_iping11_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping11_l->start = f3(810.6f, 0.0f, 175.0f);
	Receps_iping11_l->end = f3(812.6f, 2.5f, 200.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 115.0f, 13.0f, 140.0f, 2.5f);

	Object* Receps_ipgu12_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu12_l->location = f3(811.6f, 1.25f, 212.5f);
	Receps_ipgu12_l->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu12_l->type = Recep_wall5;

	BoundingBox* Receps_iping12_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping12_l->start = f3(810.6f, 0.0f, 200.0f);
	Receps_iping12_l->end = f3(812.6f, 2.5f, 225.0f);
	setAreaHeight(height2_2, x22, z22, 11.0f, 140.0f, 13.0f, 165.0f, 2.5f);

	//////////////////////////////////////////////////////////////////////////////////////
	// front

	Object* Receps_ipgu13 = (Object*)malloc(sizeof(Object));
	Receps_ipgu13->location = f3(862.5f, 7.5f, 74.1f);
	Receps_ipgu13->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu13->type = Recep_wall3;

	BoundingBox* Receps_iping13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping13->start = f3(850.0f, 2.5f, 73.1f);
	Receps_iping13->end = f3(875.0f, 12.5f, 75.1f);
	setAreaHeight(height2_2, x22, z22, 50.0f, 13.5f, 75.0f, 15.5f, 12.5f);

	Object* Receps_ipgu14 = (Object*)malloc(sizeof(Object));
	Receps_ipgu14->location = f3(837.5f, 7.5f, 74.1f);
	Receps_ipgu14->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu14->type = Recep_wall3;

	BoundingBox* Receps_iping14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping14->start = f3(825.0f, 2.5f, 73.1f);
	Receps_iping14->end = f3(850.0f, 12.5f, 75.1f);
	setAreaHeight(height2_2, x22, z22, 25.0f, 13.5f, 50.0f, 15.5f, 12.5f);

	Object* Receps_ipgu15 = (Object*)malloc(sizeof(Object));
	Receps_ipgu15->location = f3(812.5f, 7.5f, 74.1f);
	Receps_ipgu15->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu15->type = Recep_wall3;

	BoundingBox* Receps_iping15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping15->start = f3(800.0f, 2.5f, 73.1f);
	Receps_iping15->end = f3(825.0f, 12.5f, 75.1f);
	setAreaHeight(height2_2, x22, z22, 0.0f, 13.5f, 25.0f, 15.5f, 12.5f);

	///////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu13_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu13_l->location = f3(862.5f, 1.25f, 74.1f);
	Receps_ipgu13_l->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu13_l->type = Recep_wall5;

	BoundingBox* Receps_iping13_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping13_l->start = f3(850.0f, 0.0f, 73.1f);
	Receps_iping13_l->end = f3(875.0f, 2.5f, 75.1f);
	setAreaHeight(height2_2, x22, z22, 50.0f, 13.5f, 75.0f, 15.5f, 2.5f);

	Object* Receps_ipgu14_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu14_l->location = f3(837.5f, 1.25f, 74.1f);
	Receps_ipgu14_l->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu14_l->type = Recep_wall5;

	BoundingBox* Receps_iping14_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping14_l->start = f3(825.0f, 0.0f, 73.1f);
	Receps_iping14_l->end = f3(850.0f, 2.5f, 75.1f);
	setAreaHeight(height2_2, x22, z22, 25.0f, 13.5f, 50.0f, 15.5f, 2.5f);

	Object* Receps_ipgu15_l = (Object*)malloc(sizeof(Object));
	Receps_ipgu15_l->location = f3(812.5f, 1.25f, 74.1f);
	Receps_ipgu15_l->rotation = f3(0.0f, 90.0f, 0.0f);
	Receps_ipgu15_l->type = Recep_wall5;

	BoundingBox* Receps_iping15_l = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping15_l->start = f3(800.0f, 0.0f, 73.1f);
	Receps_iping15_l->end = f3(825.0f, 2.5f, 75.1f);
	setAreaHeight(height2_2, x22, z22, 0.0f, 13.5f, 25.0f, 15.5f, 2.5f);

	///////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ipgu_1 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_1->location = f3(874.0f, 1.25f, 84.0625f);
	Receps_ipgu_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_1->type = Recep_wall4;

	BoundingBox* Receps_iping_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_1->start = f3(873.0f, 0.0f, 75.0f);
	Receps_iping_1->end = f3(875.0f, 2.5f, 93.125f);
	setAreaHeight(height2_2, x22, z22, 73.0f, 15.0f, 75.0f, 33.5f, 2.5f);

	Object* Receps_ipgu_2 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_2->location = f3(874.0f, 1.25f, 102.1875f);
	Receps_ipgu_2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_2->type = Recep_wall4;

	BoundingBox* Receps_iping_2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_2->start = f3(873.0f, 0.0f, 93.125f);
	Receps_iping_2->end = f3(875.0f, 2.5f, 111.25f);
	setAreaHeight(height2_2, x22, z22, 73.0f, 33.5f, 75.0f, 51.5f, 2.5f);

	Object* Receps_ipgu_3 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_3->location = f3(874.0f, 1.25f, 122.8125f);
	Receps_ipgu_3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_3->type = Recep_wall4;

	BoundingBox* Receps_iping_3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_3->start = f3(873.0f, 0.0f, 113.75f);
	Receps_iping_3->end = f3(875.0f, 2.5f, 131.875f);
	setAreaHeight(height2_2, x22, z22, 73.0f, 53.5f, 75.0f, 72.0f, 2.5f);

	Object* Receps_ipgu_4 = (Object*)malloc(sizeof(Object));
	Receps_ipgu_4->location = f3(874.0f, 1.25f, 140.9375f);
	Receps_ipgu_4->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_ipgu_4->type = Recep_wall4;

	BoundingBox* Receps_iping_4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_iping_4->start = f3(873.0f, 0.0f, 131.875f);
	Receps_iping_4->end = f3(875.0f, 2.5f, 150.0f);
	setAreaHeight(height2_2, x22, z22, 73.0f, 72.0f, 75.0f, 90.0f, 2.5f);

	////////////////////////////////////////////////////////////////////////


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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f+(10*i), 285.0f, 29.5f + (10 * i), 295.5f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 275.0f, 29.5f + (10 * i), 285.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 265.0f, 29.5f + (10 * i), 275.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 255.0f, 29.5f + (10 * i), 265.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 245.0f, 29.5f + (10 * i), 255.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 235.0f, 29.5f + (10 * i), 245.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 225.0f, 29.5f + (10 * i), 235.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 215.0f, 29.5f + (10 * i), 225.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 205.0f, 29.5f + (10 * i), 215.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 195.0f, 29.5f + (10 * i), 205.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 185.0f, 29.5f + (10 * i), 195.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 18.5f + (10 * i), 174.5f, 29.5f + (10 * i), 185.0f, 2.5f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 285.0f, 29.0f + (10 * i), 295.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 275.0f, 29.0f + (10 * i), 285.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 265.0f, 29.0f + (10 * i), 275.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 255.0f, 29.0f + (10 * i), 265.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 245.0f, 29.0f + (10 * i), 255.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 235.0f, 29.0f + (10 * i), 245.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 225.0f, 29.0f + (10 * i), 235.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 215.0f, 29.0f + (10 * i), 225.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 205.0f, 29.0f + (10 * i), 215.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 195.0f, 29.0f + (10 * i), 205.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 185.0f, 29.0f + (10 * i), 195.0f, 5.0f);
	}

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

	for (int i = 0; i < 5; ++i)
	{
		setAreaHeight(height2_2, x22, z22, 19.0f + (10 * i), 175.0f, 29.0f + (10 * i), 185.0f, 5.0f);
	}

	////////////////////////////////////////////////////////////////////////////

	Object* Receps_Kan1 = (Object*)malloc(sizeof(Object));
	Receps_Kan1->location = f3(827.5f, 3.00f, 180.0f);
	Receps_Kan1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Kan1->type = Recep_Kanmak;

	BoundingBox* Receps_Kans1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Kans1->start = f3(812.5f, 0.0f, 175.0f);
	Receps_Kans1->end = f3(842.5f, 6.0f, 185.0f);

	setAreaHeight(height2_2, x22, z22, 12.0f, 114.5f, 43.0f, 125.0f, 6.0f);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_dables1 = (Object*)malloc(sizeof(Object));
	Receps_dables1->location = f3(834.0f, 0.00f, 209.0f);
	Receps_dables1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_dables1->type = Recep_Tables;

	BoundingBox* Receps_table1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_table1->start = f3(828.0f, 0.0f, 206.0f);
	Receps_table1->end = f3(840.0f, 1.8f, 212.0f);
	setAreaHeight(height2_2, x22, z22, 27.5f, 145.5f, 40.0f, 152.5f, 1.8f);

	Object* Receps_dables2 = (Object*)malloc(sizeof(Object));
	Receps_dables2->location = f3(860.0f, 0.00f, 209.0f);
	Receps_dables2->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_dables2->type = Recep_Tables;

	BoundingBox* Receps_table2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_table2->start = f3(854.0f, 0.0f, 206.0f);
	Receps_table2->end = f3(866.0f, 1.8f, 212.0f);
	setAreaHeight(height2_2, x22, z22, 53.5f, 145.5f, 66.5f, 152.5f, 1.8f);

	Object* Receps_Cou1 = (Object*)malloc(sizeof(Object));
	Receps_Cou1->location = f3(857.0f, 0.00f, 214.0f);
	Receps_Cou1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Cou1->type = Recep_Couch;

	BoundingBox* Receps_Couch1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch1->start = f3(855.2f, 0.0f, 212.2f);
	Receps_Couch1->end = f3(858.8f, 1.8f, 215.8f);
	setAreaHeight(height2_2, x22, z22, 55.5f, 152.5f, 59.0f, 156.0f, 1.8f);

	Object* Receps_Cou1_1 = (Object*)malloc(sizeof(Object));
	Receps_Cou1_1->location = f3(861.20f, 0.00f, 214.0f);
	Receps_Cou1_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Cou1_1->type = Recep_Couch;

	BoundingBox* Receps_Couch1_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch1_1->start = f3(859.4f, 0.0f, 212.2f);
	Receps_Couch1_1->end = f3(863.0f, 1.8f, 215.8f);
	setAreaHeight(height2_2, x22, z22, 59.5f, 152.5f, 63.0f, 156.0f, 1.8f);

	Object* Receps_Cou2 = (Object*)malloc(sizeof(Object));
	Receps_Cou2->location = f3(857.0f, 0.00f, 204.0f);
	Receps_Cou2->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Cou2->type = Recep_Couch;

	BoundingBox* Receps_Couch2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch2->start = f3(855.2f, 0.0f, 202.2f);
	Receps_Couch2->end = f3(858.8f, 1.8f, 205.8f);
	setAreaHeight(height2_2, x22, z22, 55.5f, 142.5f, 59.0f, 146.0f, 1.8f);

	Object* Receps_Cou2_1 = (Object*)malloc(sizeof(Object));
	Receps_Cou2_1->location = f3(861.2f, 0.00f, 204.0f);
	Receps_Cou2_1->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Cou2_1->type = Recep_Couch;

	BoundingBox* Receps_Couch2_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch2_1->start = f3(859.4f, 0.0f, 202.2f);
	Receps_Couch2_1->end = f3(863.0f, 1.8f, 205.8f);
	setAreaHeight(height2_2, x22, z22, 59.5f, 142.5f, 63.0f, 146.0f, 1.8f);

	///////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_Cou3 = (Object*)malloc(sizeof(Object));
	Receps_Cou3->location = f3(831.0f, 0.00f, 214.0f);
	Receps_Cou3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Cou3->type = Recep_Couch;

	BoundingBox* Receps_Couch3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch3->start = f3(829.2f, 0.0f, 212.2f);
	Receps_Couch3->end = f3(832.8f, 1.8f, 215.8f);
	setAreaHeight(height2_2, x22, z22, 29.5f, 152.5f, 33.0f, 156.0f, 1.8f);

	Object* Receps_Cou3_1 = (Object*)malloc(sizeof(Object));
	Receps_Cou3_1->location = f3(837.0f, 0.00f, 214.0f);
	Receps_Cou3_1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Cou3_1->type = Recep_Couch;

	BoundingBox* Receps_Couch3_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch3_1->start = f3(835.2f, 0.0f, 212.2f);
	Receps_Couch3_1->end = f3(838.8f, 1.8f, 215.8f);
	setAreaHeight(height2_2, x22, z22, 35.5f, 152.5f, 39.0f, 156.0f, 1.8f);

	Object* Receps_Cou4 = (Object*)malloc(sizeof(Object));
	Receps_Cou4->location = f3(831.0f, 0.00f, 204.0f);
	Receps_Cou4->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Cou4->type = Recep_Couch;

	BoundingBox* Receps_Couch4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch4->start = f3(829.2f, 0.0f, 202.2f);
	Receps_Couch4->end = f3(832.8f, 1.8f, 205.8f);
	setAreaHeight(height2_2, x22, z22, 29.5f, 142.5f, 33.0f, 146.0f, 1.8f);

	Object* Receps_Cou4_1 = (Object*)malloc(sizeof(Object));
	Receps_Cou4_1->location = f3(837.0f, 0.00f, 204.0f);
	Receps_Cou4_1->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Cou4_1->type = Recep_Couch;

	BoundingBox* Receps_Couch4_1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Couch4_1->start = f3(835.2f, 0.0f, 202.2f);
	Receps_Couch4_1->end = f3(837.0f, 1.8f, 205.8f);
	setAreaHeight(height2_2, x22, z22, 35.5f, 142.5f, 39.0f, 146.0f, 1.8f);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_Ven1 = (Object*)malloc(sizeof(Object));
	Receps_Ven1->location = f3(846.0f, 1.35f, 204.3f);
	Receps_Ven1->rotation = f3(-90.0f, 90.0f, 0.0f);
	Receps_Ven1->type = Recep_Vending;

	BoundingBox* Receps_Vending1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Vending1->start = f3(843.0f, 0.0f, 201.6f);
	Receps_Vending1->end = f3(846.0f, 5.4f, 207.0f);
	setAreaHeight(height2_2, x22, z22, 42.5f, 141.5f, 46.5f, 147.5f, 5.4f);

	Object* Receps_Ven2 = (Object*)malloc(sizeof(Object));
	Receps_Ven2->location = f3(846.0f, 1.35f, 209.7f);
	Receps_Ven2->rotation = f3(-90.0f, 90.0f, 0.0f);
	Receps_Ven2->type = Recep_Vending;

	BoundingBox* Receps_Vending2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Vending2->start = f3(843.0f, 0.0f, 207.0f);
	Receps_Vending2->end = f3(846.0f, 5.4f, 212.4f);
	setAreaHeight(height2_2, x22, z22, 42.5f, 146.5f, 46.5f, 152.5f, 5.4f);

	Object* Receps_Ven3 = (Object*)malloc(sizeof(Object));
	Receps_Ven3->location = f3(846.0f, 1.35f, 204.3f);
	Receps_Ven3->rotation = f3(-90.0f, -90.0f, 0.0f);
	Receps_Ven3->type = Recep_Vending;

	BoundingBox* Receps_Vending3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Vending3->start = f3(846.0f, 0.0f, 201.6f);
	Receps_Vending3->end = f3(849.0f, 5.4f, 207.0f);
	setAreaHeight(height2_2, x22, z22, 45.5f, 141.5f, 49.5f, 147.5f, 5.4f);

	Object* Receps_Ven4 = (Object*)malloc(sizeof(Object));
	Receps_Ven4->location = f3(846.0f, 1.35f, 209.7f);
	Receps_Ven4->rotation = f3(-90.0f, -90.0f, 0.0f);
	Receps_Ven4->type = Recep_Vending;

	BoundingBox* Receps_Vending4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Vending4->start = f3(846.0f, 0.0f, 207.0f);
	Receps_Vending4->end = f3(849.0f, 5.4f, 212.4f);
	setAreaHeight(height2_2, x22, z22, 45.5f, 146.5f, 49.5f, 152.5f, 5.4f);

	////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_Coun1 = (Object*)malloc(sizeof(Object));
	Receps_Coun1->location = f3(820.0f, 0.0f, 205.0f);
	Receps_Coun1->rotation = f3(0.0f, -90.0f, 0.0f);
	Receps_Coun1->type = Recep_Counter1;

	BoundingBox* Receps_Counter1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Counter1->start = f3(814.0f, 0.0f, 190.0f);
	Receps_Counter1->end = f3(826.0f, 2.7f, 220.0f);
	setAreaHeight(height2_2, x22, z22, 14.0f, 130.0f, 26.0f, 160.0f, 2.7f);


	////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_Creen1 = (Object*)malloc(sizeof(Object));
	Receps_Creen1->location = f3(813.2f, 3.0f, 205.0f);
	Receps_Creen1->rotation = f3(0.0f, -90.0f, 0.0f);
	Receps_Creen1->type = Recep_Screened1;

	BoundingBox* Receps_Creens1 = (BoundingBox*)malloc(sizeof(BoundingBox)); // 2, 8 18
	Receps_Creens1->start = f3(812.2f, 3.0f, 196.0f);
	Receps_Creens1->end = f3(814.2f, 11.0f, 214.0f);
	setAreaHeight(height2_2, x22, z22, 12.5f, 136.0f, 14.5f, 154.0f, 11.0f);

	Object* Receps_Creen2 = (Object*)malloc(sizeof(Object));
	Receps_Creen2->location = f3(843.5f, 3.0f, 125.0f);
	Receps_Creen2->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Creen2->type = Recep_Screened1;

	BoundingBox* Receps_Creens2 = (BoundingBox*)malloc(sizeof(BoundingBox)); // 2, 8 18
	Receps_Creens2->start = f3(834.5f, 3.0f, 124.0f);
	Receps_Creens2->end = f3(852.5f, 11.0f, 126.0f);
	setAreaHeight(height2_2, x22, z22, 34.5f, 64.0f, 52.5f, 66.0f, 11.0f);

	Object* Receps_Creen3 = (Object*)malloc(sizeof(Object));
	Receps_Creen3->location = f3(843.5f, 3.0f, 119.0f);
	Receps_Creen3->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Creen3->type = Recep_Screened1;

	BoundingBox* Receps_Creens3 = (BoundingBox*)malloc(sizeof(BoundingBox)); // 2, 8 18
	Receps_Creens3->start = f3(834.5f, 3.0f, 118.0f);
	Receps_Creens3->end = f3(852.5f, 11.0f, 120.0f);
	setAreaHeight(height2_2, x22, z22, 34.5f, 58.0f, 52.5f, 60.0f, 11.0f);

	/////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_MidWals1 = (Object*)malloc(sizeof(Object));
	Receps_MidWals1->location = f3(843.75f, 6.25f, 122.0f);
	Receps_MidWals1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_MidWals1->type = Recep_MidWal;

	BoundingBox* Receps_MWal1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_MWal1->start = f3(823.75f, 0.0f, 120.0f);
	Receps_MWal1->end = f3(863.75f, 12.5f, 124.0f);
	setAreaHeight(height2_2, x22, z22, 23.5f, 60.0f, 64.0f, 64.0f, 12.5f);

	Object* Receps_Second_Counter1 = (Object*)malloc(sizeof(Object));
	Receps_Second_Counter1->location = f3(843.75f, 0.0f, 111.0f);
	Receps_Second_Counter1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Second_Counter1->type = Recep_Counter2;

	BoundingBox* Receps_Second1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Second1->start = f3(829.75f, 0.0f, 104.0f);
	Receps_Second1->end = f3(857.75f, 2.2f, 118.0f);
	setAreaHeight(height2_2, x22, z22, 30.0f, 44.0f, 58.0f, 58.0f, 2.2f);

	Object* Receps_Second_Counter2 = (Object*)malloc(sizeof(Object));
	Receps_Second_Counter2->location = f3(843.75f, 0.0f, 133.0f);
	Receps_Second_Counter2->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Second_Counter2->type = Recep_Counter2;

	BoundingBox* Receps_Second2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Second2->start = f3(829.75f, 0.0f, 126.0f);
	Receps_Second2->end = f3(857.75f, 2.2f, 140.0f);
	setAreaHeight(height2_2, x22, z22, 30.0f, 66.0f, 58.0f, 80.0f, 2.2f);

	//////////////////////////////////////////////////////////////////////////////

	Object* Receps_Airs1 = (Object*)malloc(sizeof(Object));
	Receps_Airs1->location = f3(866.0f, 0.0f, 175.0f);
	Receps_Airs1->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Airs1->type = Recep_Air;

	BoundingBox* Receps_air1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_air1->start = f3(862.0f, 0.0f, 173.5f);
	Receps_air1->end = f3(870.00f, 2.2f, 176.5f);
	setAreaHeight(height2_2, x22, z22, 61.5f, 111.0f, 70.5f, 119.0f, 2.2f);

	Object* Receps_Airs2 = (Object*)malloc(sizeof(Object));
	Receps_Airs2->location = f3(858.0f, 0.0f, 175.0f);
	Receps_Airs2->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Airs2->type = Recep_Air;

	BoundingBox* Receps_air2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_air2->start = f3(854.0f, 0.0f, 173.5f);
	Receps_air2->end = f3(862.00f, 2.2f, 176.5f);
	setAreaHeight(height2_2, x22, z22, 53.5f, 111.0f, 62.5f, 119.0f, 2.2f);

	Object* Receps_Airs3 = (Object*)malloc(sizeof(Object));
	Receps_Airs3->location = f3(850.0f, 0.0f, 175.0f);
	Receps_Airs3->rotation = f3(0.0f, 180.0f, 0.0f);
	Receps_Airs3->type = Recep_Air;

	BoundingBox* Receps_air3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_air3->start = f3(846.0f, 0.0f, 173.5f);
	Receps_air3->end = f3(854.00f, 2.2f, 176.5f);
	setAreaHeight(height2_2, x22, z22, 45.5f, 111.0f, 54.5f, 119.0f, 2.2f);

	Object* Receps_Dosang1 = (Object*)malloc(sizeof(Object));
	Receps_Dosang1->location = f3(822.5f, 0.0f, 165.0f);
	Receps_Dosang1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Dosang1->type = Recep_DongSSang1;

	BoundingBox* Receps_Donsang1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_Donsang1->start = f3(812.5f, 0.0f, 155.0f);
	Receps_Donsang1->end = f3(832.50f, 9.0f, 175.0f);
	setAreaHeight(height2_2, x22, z22, 12.5f, 95.0f, 32.5f, 115.0f, 9.0f);

	Object* Receps_Paint1 = (Object*)malloc(sizeof(Object));
	Receps_Paint1->location = f3(843.5f, 0.0f, 92.0f);
	Receps_Paint1->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Paint1->type = Recep_Misul;

	BoundingBox* Receps_paint1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_paint1->start = f3(823.5f, 0.0f, 84.0f);
	Receps_paint1->end = f3(863.5f, 12.5f, 100.0f);
	setAreaHeight(height2_2, x22, z22, 23.5f, 24.0f, 63.5f, 40.0f, 12.5f);

	///////////////////////////////////////////////////////////////

	Object* Receps_ramp1 = (Object*)malloc(sizeof(Object));
	Receps_ramp1->location = f3(812.5f, 9.0f, 82.0f);
	Receps_ramp1->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp1->type = Recep_Lamps;

	BoundingBox* Receps_lamp1 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp1->start = f3(812.5f, 9.0f, 80.0f);
	Receps_lamp1->end = f3(816.5f, 10.6f, 84.0f);

	Object* Receps_ramp2 = (Object*)malloc(sizeof(Object));
	Receps_ramp2->location = f3(812.5f, 9.0f, 92.0f);
	Receps_ramp2->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp2->type = Recep_Lamps;

	BoundingBox* Receps_lamp2 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp2->start = f3(812.5f, 9.0f, 90.0f);
	Receps_lamp2->end = f3(816.5f, 10.6f, 94.0f);

	Object* Receps_ramp3 = (Object*)malloc(sizeof(Object));
	Receps_ramp3->location = f3(812.5f, 9.0f, 102.0f);
	Receps_ramp3->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp3->type = Recep_Lamps;

	BoundingBox* Receps_lamp3 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp3->start = f3(812.5f, 9.0f, 100.0f);
	Receps_lamp3->end = f3(816.5f, 10.6f, 104.0f);

	Object* Receps_ramp4 = (Object*)malloc(sizeof(Object));
	Receps_ramp4->location = f3(812.5f, 9.0f, 112.0f);
	Receps_ramp4->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp4->type = Recep_Lamps;

	BoundingBox* Receps_lamp4 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp4->start = f3(812.5f, 9.0f, 110.0f);
	Receps_lamp4->end = f3(816.5f, 10.6f, 114.0f);

	Object* Receps_ramp5 = (Object*)malloc(sizeof(Object));
	Receps_ramp5->location = f3(812.5f, 9.0f, 122.0f);
	Receps_ramp5->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp5->type = Recep_Lamps;

	BoundingBox* Receps_lamp5 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp5->start = f3(812.5f, 9.0f, 120.0f);
	Receps_lamp5->end = f3(816.5f, 10.6f, 124.0f);

	Object* Receps_ramp6 = (Object*)malloc(sizeof(Object));
	Receps_ramp6->location = f3(812.5f, 9.0f, 132.0f);
	Receps_ramp6->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp6->type = Recep_Lamps;

	BoundingBox* Receps_lamp6 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp6->start = f3(812.5f, 9.0f, 130.0f);
	Receps_lamp6->end = f3(816.5f, 10.6f, 134.0f);

	Object* Receps_ramp7 = (Object*)malloc(sizeof(Object));
	Receps_ramp7->location = f3(812.5f, 9.0f, 142.0f);
	Receps_ramp7->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp7->type = Recep_Lamps;

	BoundingBox* Receps_lamp7 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp7->start = f3(812.5f, 9.0f, 140.0f);
	Receps_lamp7->end = f3(816.5f, 10.6f, 144.0f);

	Object* Receps_ramp8 = (Object*)malloc(sizeof(Object));
	Receps_ramp8->location = f3(812.5f, 9.0f, 152.0f);
	Receps_ramp8->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp8->type = Recep_Lamps;

	BoundingBox* Receps_lamp8 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp8->start = f3(812.5f, 9.0f, 150.0f);
	Receps_lamp8->end = f3(816.5f, 10.6f, 154.0f);


	///////////////////////////////////////////////////////////////////////////////

	Object* Receps_ramp9 = (Object*)malloc(sizeof(Object));
	Receps_ramp9->location = f3(873.0f, 9.0f, 82.0f);
	Receps_ramp9->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp9->type = Recep_Lamps;

	BoundingBox* Receps_lamp9 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp9->start = f3(871.0f, 9.0f, 80.0f);
	Receps_lamp9->end = f3(875.0f, 10.6f, 84.0f);

	Object* Receps_ramp10 = (Object*)malloc(sizeof(Object));
	Receps_ramp10->location = f3(873.0f, 9.0f, 92.0f);
	Receps_ramp10->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp10->type = Recep_Lamps;

	BoundingBox* Receps_lamp10 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp10->start = f3(871.0f, 9.0f, 90.0f);
	Receps_lamp10->end = f3(875.0f, 10.6f, 94.0f);

	Object* Receps_ramp11 = (Object*)malloc(sizeof(Object));
	Receps_ramp11->location = f3(873.0f, 9.0f, 102.0f);
	Receps_ramp11->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp11->type = Recep_Lamps;

	BoundingBox* Receps_lamp11 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp11->start = f3(873.0f, 9.0f, 100.0f);
	Receps_lamp11->end = f3(875.0f, 10.6f, 104.0f);

	Object* Receps_ramp12 = (Object*)malloc(sizeof(Object));
	Receps_ramp12->location = f3(873.0f, 9.0f, 112.0f);
	Receps_ramp12->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp12->type = Recep_Lamps;

	BoundingBox* Receps_lamp12 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp12->start = f3(871.0f, 9.0f, 110.0f);
	Receps_lamp12->end = f3(875.0f, 10.6f, 114.0f);

	Object* Receps_ramp13 = (Object*)malloc(sizeof(Object));
	Receps_ramp13->location = f3(873.0f, 9.0f, 122.0f);
	Receps_ramp13->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp13->type = Recep_Lamps;

	BoundingBox* Receps_lamp13 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp13->start = f3(871.0f, 9.0f, 120.0f);
	Receps_lamp13->end = f3(875.0f, 10.6f, 124.0f);

	Object* Receps_ramp14 = (Object*)malloc(sizeof(Object));
	Receps_ramp14->location = f3(873.0f, 9.0f, 132.0f);
	Receps_ramp14->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp14->type = Recep_Lamps;

	BoundingBox* Receps_lamp14 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp14->start = f3(871.0f, 9.0f, 130.0f);
	Receps_lamp14->end = f3(875.0f, 10.6f, 134.0f);

	Object* Receps_ramp15 = (Object*)malloc(sizeof(Object));
	Receps_ramp15->location = f3(873.0f, 9.0f, 142.0f);
	Receps_ramp15->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp15->type = Recep_Lamps;

	BoundingBox* Receps_lamp15 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp15->start = f3(871.0f, 9.0f, 140.0f);
	Receps_lamp15->end = f3(875.0f, 10.6f, 144.0f);

	Object* Receps_ramp16 = (Object*)malloc(sizeof(Object));
	Receps_ramp16->location = f3(873.0f, 9.0f, 152.0f);
	Receps_ramp16->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp16->type = Recep_Lamps;

	BoundingBox* Receps_lamp16 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp16->start = f3(871.0f, 9.0f, 150.0f);
	Receps_lamp16->end = f3(875.0f, 10.6f, 154.0f);

	Object* Receps_ramp17 = (Object*)malloc(sizeof(Object));
	Receps_ramp17->location = f3(873.0f, 9.0f, 162.0f);
	Receps_ramp17->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp17->type = Recep_Lamps;

	BoundingBox* Receps_lamp17 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp17->start = f3(871.0f, 9.0f, 160.0f);
	Receps_lamp17->end = f3(875.0f, 10.6f, 164.0f);

	Object* Receps_ramp18 = (Object*)malloc(sizeof(Object));
	Receps_ramp18->location = f3(873.0f, 9.0f, 172.0f);
	Receps_ramp18->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp18->type = Recep_Lamps;

	BoundingBox* Receps_lamp18 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp18->start = f3(871.0f, 9.0f, 170.0f);
	Receps_lamp18->end = f3(875.0f, 10.6f, 174.0f);

	Object* Receps_ramp19 = (Object*)malloc(sizeof(Object));
	Receps_ramp19->location = f3(873.0f, 9.0f, 182.0f);
	Receps_ramp19->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp19->type = Recep_Lamps;

	BoundingBox* Receps_lamp19 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp19->start = f3(871.0f, 9.0f, 180.0f);
	Receps_lamp19->end = f3(875.0f, 10.6f, 184.0f);

	Object* Receps_ramp20 = (Object*)malloc(sizeof(Object));
	Receps_ramp20->location = f3(873.0f, 9.0f, 192.0f);
	Receps_ramp20->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp20->type = Recep_Lamps;

	BoundingBox* Receps_lamp20 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp20->start = f3(871.0f, 9.0f, 190.0f);
	Receps_lamp20->end = f3(875.0f, 10.6f, 194.0f);

	Object* Receps_ramp21 = (Object*)malloc(sizeof(Object));
	Receps_ramp21->location = f3(873.0f, 9.0f, 202.0f);
	Receps_ramp21->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp21->type = Recep_Lamps;

	BoundingBox* Receps_lamp21 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp21->start = f3(871.0f, 9.0f, 200.0f);
	Receps_lamp21->end = f3(875.0f, 10.6f, 204.0f);

	Object* Receps_ramp22 = (Object*)malloc(sizeof(Object));
	Receps_ramp22->location = f3(873.0f, 9.0f, 212.0f);
	Receps_ramp22->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp22->type = Recep_Lamps;

	BoundingBox* Receps_lamp22 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp22->start = f3(871.0f, 9.0f, 210.0f);
	Receps_lamp22->end = f3(875.0f, 10.6f, 214.0f);




	//////////////////////////////////////////////////////////////////////////


	Object* Receps_ramp23 = (Object*)malloc(sizeof(Object));
	Receps_ramp23->location = f3(812.5f, 9.0f, 242.0f);
	Receps_ramp23->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp23->type = Recep_Lamps;

	BoundingBox* Receps_lamp23 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp23->start = f3(812.5f, 9.0f, 240.0f);
	Receps_lamp23->end = f3(816.5f, 10.6f, 244.0f);

	Object* Receps_ramp24 = (Object*)malloc(sizeof(Object));
	Receps_ramp24->location = f3(812.5f, 9.0f, 252.0f);
	Receps_ramp24->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp24->type = Recep_Lamps;

	BoundingBox* Receps_lamp24 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp24->start = f3(812.5f, 9.0f, 250.0f);
	Receps_lamp24->end = f3(816.5f, 10.6f, 254.0f);

	Object* Receps_ramp25 = (Object*)malloc(sizeof(Object));
	Receps_ramp25->location = f3(812.5f, 9.0f, 262.0f);
	Receps_ramp25->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp25->type = Recep_Lamps;

	BoundingBox* Receps_lamp25 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp25->start = f3(812.5f, 9.0f, 260.0f);
	Receps_lamp25->end = f3(816.5f, 10.6f, 264.0f);

	Object* Receps_ramp26 = (Object*)malloc(sizeof(Object));
	Receps_ramp26->location = f3(812.5f, 9.0f, 272.0f);
	Receps_ramp26->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp26->type = Recep_Lamps;

	BoundingBox* Receps_lamp26 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp26->start = f3(812.5f, 9.0f, 270.0f);
	Receps_lamp26->end = f3(816.5f, 10.6f, 274.0f);

	Object* Receps_ramp27 = (Object*)malloc(sizeof(Object));
	Receps_ramp27->location = f3(812.5f, 9.0f, 282.0f);
	Receps_ramp27->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp27->type = Recep_Lamps;

	BoundingBox* Receps_lamp27 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp27->start = f3(812.5f, 9.0f, 280.0f);
	Receps_lamp27->end = f3(816.5f, 10.6f, 284.0f);

	Object* Receps_ramp28 = (Object*)malloc(sizeof(Object));
	Receps_ramp28->location = f3(812.5f, 9.0f, 292.0f);
	Receps_ramp28->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp28->type = Recep_Lamps;

	BoundingBox* Receps_lamp28 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp28->start = f3(812.5f, 9.0f, 290.0f);
	Receps_lamp28->end = f3(816.5f, 10.6f, 294.0f);

	Object* Receps_ramp29 = (Object*)malloc(sizeof(Object));
	Receps_ramp29->location = f3(812.5f, 9.0f, 302.0f);
	Receps_ramp29->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp29->type = Recep_Lamps;

	BoundingBox* Receps_lamp29 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp29->start = f3(812.5f, 9.0f, 300.0f);
	Receps_lamp29->end = f3(816.5f, 10.6f, 304.0f);

	Object* Receps_ramp30 = (Object*)malloc(sizeof(Object));
	Receps_ramp30->location = f3(812.5f, 9.0f, 312.0f);
	Receps_ramp30->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp30->type = Recep_Lamps;

	BoundingBox* Receps_lamp30 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp30->start = f3(812.5f, 9.0f, 310.0f);
	Receps_lamp30->end = f3(816.5f, 10.6f, 314.0f);

	Object* Receps_ramp31 = (Object*)malloc(sizeof(Object));
	Receps_ramp31->location = f3(812.5f, 9.0f, 322.0f);
	Receps_ramp31->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp31->type = Recep_Lamps;

	BoundingBox* Receps_lamp31 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp31->start = f3(812.5f, 9.0f, 320.0f);
	Receps_lamp31->end = f3(816.5f, 10.6f, 324.0f);

	Object* Receps_ramp32 = (Object*)malloc(sizeof(Object));
	Receps_ramp32->location = f3(812.5f, 9.0f, 332.0f);
	Receps_ramp32->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp32->type = Recep_Lamps;

	BoundingBox* Receps_lamp32 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp32->start = f3(812.5f, 9.0f, 330.0f);
	Receps_lamp32->end = f3(816.5f, 10.6f, 334.0f);

	Object* Receps_ramp33 = (Object*)malloc(sizeof(Object));
	Receps_ramp33->location = f3(812.5f, 9.0f, 342.0f);
	Receps_ramp33->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp33->type = Recep_Lamps;

	BoundingBox* Receps_lamp33 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp33->start = f3(812.5f, 9.0f, 340.0f);
	Receps_lamp33->end = f3(816.5f, 10.6f, 344.0f);

	Object* Receps_ramp34 = (Object*)malloc(sizeof(Object));
	Receps_ramp34->location = f3(812.5f, 9.0f, 352.0f);
	Receps_ramp34->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp34->type = Recep_Lamps;

	BoundingBox* Receps_lamp34 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp34->start = f3(812.5f, 9.0f, 350.0f);
	Receps_lamp34->end = f3(816.5f, 10.6f, 354.0f);



	///////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_ramp35 = (Object*)malloc(sizeof(Object));
	Receps_ramp35->location = f3(875.0f, 9.0f, 232.0f);
	Receps_ramp35->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp35->type = Recep_Lamps;

	BoundingBox* Receps_lamp35 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp35->start = f3(871.0f, 9.0f, 230.0f);
	Receps_lamp35->end = f3(875.0f, 10.6f, 234.0f);

	Object* Receps_ramp36 = (Object*)malloc(sizeof(Object));
	Receps_ramp36->location = f3(875.0f, 9.0f, 242.0f);
	Receps_ramp36->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp36->type = Recep_Lamps;

	BoundingBox* Receps_lamp36 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp36->start = f3(871.0f, 9.0f, 240.0f);
	Receps_lamp36->end = f3(875.0f, 10.6f, 244.0f);

	Object* Receps_ramp37 = (Object*)malloc(sizeof(Object));
	Receps_ramp37->location = f3(875.0f, 9.0f, 252.0f);
	Receps_ramp37->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp37->type = Recep_Lamps;

	BoundingBox* Receps_lamp37 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp37->start = f3(871.0f, 9.0f, 250.0f);
	Receps_lamp37->end = f3(875.0f, 10.6f, 254.0f);

	Object* Receps_ramp38 = (Object*)malloc(sizeof(Object));
	Receps_ramp38->location = f3(875.0f, 9.0f, 262.0f);
	Receps_ramp38->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp38->type = Recep_Lamps;

	BoundingBox* Receps_lamp38 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp38->start = f3(871.0f, 9.0f, 260.0f);
	Receps_lamp38->end = f3(875.0f, 10.6f, 264.0f);

	Object* Receps_ramp39 = (Object*)malloc(sizeof(Object));
	Receps_ramp39->location = f3(875.0f, 9.0f, 272.0f);
	Receps_ramp39->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp39->type = Recep_Lamps;

	BoundingBox* Receps_lamp39 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp39->start = f3(871.0f, 9.0f, 270.0f);
	Receps_lamp39->end = f3(875.0f, 10.6f, 274.0f);

	Object* Receps_ramp40 = (Object*)malloc(sizeof(Object));
	Receps_ramp40->location = f3(875.0f, 9.0f, 282.0f);
	Receps_ramp40->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp40->type = Recep_Lamps;

	BoundingBox* Receps_lamp40 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp40->start = f3(871.0f, 9.0f, 280.0f);
	Receps_lamp40->end = f3(875.0f, 10.6f, 284.0f);

	Object* Receps_ramp41 = (Object*)malloc(sizeof(Object));
	Receps_ramp41->location = f3(875.0f, 9.0f, 292.0f);
	Receps_ramp41->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp41->type = Recep_Lamps;

	BoundingBox* Receps_lamp41 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp41->start = f3(871.0f, 9.0f, 290.0f);
	Receps_lamp41->end = f3(875.0f, 10.6f, 294.0f);

	Object* Receps_ramp42 = (Object*)malloc(sizeof(Object));
	Receps_ramp42->location = f3(875.0f, 9.0f, 302.0f);
	Receps_ramp42->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp42->type = Recep_Lamps;

	BoundingBox* Receps_lamp42 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp42->start = f3(871.0f, 9.0f, 300.0f);
	Receps_lamp42->end = f3(875.0f, 10.6f, 304.0f);

	Object* Receps_ramp43 = (Object*)malloc(sizeof(Object));
	Receps_ramp43->location = f3(875.0f, 9.0f, 312.0f);
	Receps_ramp43->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp43->type = Recep_Lamps;

	BoundingBox* Receps_lamp43 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp43->start = f3(871.0f, 9.0f, 310.0f);
	Receps_lamp43->end = f3(875.0f, 10.6f, 314.0f);

	Object* Receps_ramp44 = (Object*)malloc(sizeof(Object));
	Receps_ramp44->location = f3(875.0f, 9.0f, 322.0f);
	Receps_ramp44->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp44->type = Recep_Lamps;

	BoundingBox* Receps_lamp44 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp44->start = f3(871.0f, 9.0f, 320.0f);
	Receps_lamp44->end = f3(875.0f, 10.6f, 324.0f);

	Object* Receps_ramp45 = (Object*)malloc(sizeof(Object));
	Receps_ramp45->location = f3(875.0f, 9.0f, 332.0f);
	Receps_ramp45->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp45->type = Recep_Lamps;

	BoundingBox* Receps_lamp45 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp45->start = f3(871.0f, 9.0f, 330.0f);
	Receps_lamp45->end = f3(875.0f, 10.6f, 334.0f);

	Object* Receps_ramp46 = (Object*)malloc(sizeof(Object));
	Receps_ramp46->location = f3(875.0f, 9.0f, 342.0f);
	Receps_ramp46->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp46->type = Recep_Lamps;

	BoundingBox* Receps_lamp46 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp46->start = f3(871.0f, 9.0f, 340.0f);
	Receps_lamp46->end = f3(875.0f, 10.6f, 344.0f);

	Object* Receps_ramp47 = (Object*)malloc(sizeof(Object));
	Receps_ramp47->location = f3(875.0f, 9.0f, 352.0f);
	Receps_ramp47->rotation = f3(270.0f, 90.0f, 0.0f);
	Receps_ramp47->type = Recep_Lamps;

	BoundingBox* Receps_lamp47 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp47->start = f3(871.0f, 9.0f, 350.0f);
	Receps_lamp47->end = f3(875.0f, 10.6f, 354.0f);

	Object* Receps_ramp48 = (Object*)malloc(sizeof(Object));
	Receps_ramp48->location = f3(812.5f, 9.0f, 232.0f);
	Receps_ramp48->rotation = f3(270.0f, 270.0f, 0.0f);
	Receps_ramp48->type = Recep_Lamps;

	BoundingBox* Receps_lamp48 = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_lamp48->start = f3(812.5f, 9.0f, 230.0f);
	Receps_lamp48->end = f3(816.5f, 10.6f, 234.0f);



	//////////////////////////////////////////////////////////////////////////////////////////////

	Object* Receps_MoonBonchae = (Object*)malloc(sizeof(Object));
	Receps_MoonBonchae->location = f3(874.0f, 0.0f, 112.5f);
	Receps_MoonBonchae->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_MoonBonchae->type = Recep_Door1;


	BoundingBox* Receps_MoonBonchaes = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_MoonBonchaes->start = f3(872.0f, 0.0f, 111.25f);
	Receps_MoonBonchaes->end = f3(876.0f, 2.5f, 113.75f);
	setAreaHeight(height2_2, x22, z22, 72.0f, 111.5f, 76.0f, 114.0f, 2.5f);

	Object* Receps_Moon_L = (Object*)malloc(sizeof(Object));
	Receps_Moon_L->location = f3(874.0f, 0.0f, 111.875f);
	Receps_Moon_L->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Moon_L->type = Recep_DoorL;

	BoundingBox* Receps_MoonLeft = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_MoonLeft->start = f3(873.0f, 0.0f, 111.25f);
	Receps_MoonLeft->end = f3(875.0f, 2.5f, 112.5f);
	setAreaHeight(height2_2, x22, z22, 73.0f, 111.5f, 75.0f, 112.5f, 2.5f);


	Object* Receps_Moon_R = (Object*)malloc(sizeof(Object));
	Receps_Moon_R->location = f3(874.0f, 0.0f, 113.125f);
	Receps_Moon_R->rotation = f3(0.0f, 0.0f, 0.0f);
	Receps_Moon_R->type = Recep_DoorL;

	BoundingBox* Receps_MoonRight = (BoundingBox*)malloc(sizeof(BoundingBox));
	Receps_MoonRight->start = f3(873.0f, 0.0f, 112.5f);
	Receps_MoonRight->end = f3(875.0f, 2.5f, 113.75f);
	setAreaHeight(height2_2, x22, z22, 73.0f, 112.5f, 75.0f, 114.0f, 2.5f);



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

	/////////////////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_Kan1);
	blist.push_back(*Receps_Kans1);

	list.push_back(*Receps_dables1);
	blist.push_back(*Receps_table1);

	list.push_back(*Receps_dables2);
	blist.push_back(*Receps_table2);

	list.push_back(*Receps_Cou1);
	blist.push_back(*Receps_Couch1);

	list.push_back(*Receps_Cou1_1);
	blist.push_back(*Receps_Couch1_1);

	list.push_back(*Receps_Cou2);
	blist.push_back(*Receps_Couch2);

	list.push_back(*Receps_Cou2_1);
	blist.push_back(*Receps_Couch2_1);

	list.push_back(*Receps_Cou3);
	blist.push_back(*Receps_Couch3);

	list.push_back(*Receps_Cou3_1);
	blist.push_back(*Receps_Couch3_1);

	list.push_back(*Receps_Cou4);
	blist.push_back(*Receps_Couch4);

	list.push_back(*Receps_Cou4_1);
	blist.push_back(*Receps_Couch4_1);

	///////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_Ven1);
	blist.push_back(*Receps_Vending1);

	list.push_back(*Receps_Ven2);
	blist.push_back(*Receps_Vending2);

	list.push_back(*Receps_Ven3);
	blist.push_back(*Receps_Vending3);

	list.push_back(*Receps_Ven4);
	blist.push_back(*Receps_Vending4);

	/////////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_Coun1);
	blist.push_back(*Receps_Counter1);

	list.push_back(*Receps_Creen1);
	blist.push_back(*Receps_Creens1);

	list.push_back(*Receps_Creen2);
	blist.push_back(*Receps_Creens2);

	list.push_back(*Receps_Creen3);
	blist.push_back(*Receps_Creens3);

	/////////////////////////////////////////////////////////////////////////////////////////////////

	list.push_back(*Receps_MidWals1);
	blist.push_back(*Receps_MWal1);

	list.push_back(*Receps_Second_Counter1);
	blist.push_back(*Receps_Second1);

	list.push_back(*Receps_Second_Counter2);
	blist.push_back(*Receps_Second2);

	///////////////////////////////////////////////////////////////////

	list.push_back(*Receps_Airs1);
	blist.push_back(*Receps_air1);

	list.push_back(*Receps_Airs2);
	blist.push_back(*Receps_air2);

	list.push_back(*Receps_Airs3);
	blist.push_back(*Receps_air3);

	////////////////////////////////////////////////////////////////

	list.push_back(*Receps_Dosang1);
	blist.push_back(*Receps_Donsang1);

	//////////////////////////////////////////////////////////////////

	list.push_back(*Receps_Paint1);
	blist.push_back(*Receps_paint1);

	/////////////////////////////////////////////////////////////////

	list.push_back(*Receps_ramp1);
	blist.push_back(*Receps_lamp1);

	list.push_back(*Receps_ramp2);
	blist.push_back(*Receps_lamp2);

	list.push_back(*Receps_ramp3);
	blist.push_back(*Receps_lamp3);

	list.push_back(*Receps_ramp4);
	blist.push_back(*Receps_lamp4);

	list.push_back(*Receps_ramp5);
	blist.push_back(*Receps_lamp5);

	list.push_back(*Receps_ramp6);
	blist.push_back(*Receps_lamp6);

	list.push_back(*Receps_ramp7);
	blist.push_back(*Receps_lamp7);

	list.push_back(*Receps_ramp8);
	blist.push_back(*Receps_lamp8);

	list.push_back(*Receps_ramp9);
	blist.push_back(*Receps_lamp9);

	list.push_back(*Receps_ramp10);
	blist.push_back(*Receps_lamp10);

	list.push_back(*Receps_ramp11);
	blist.push_back(*Receps_lamp11);

	list.push_back(*Receps_ramp12);
	blist.push_back(*Receps_lamp12);

	list.push_back(*Receps_ramp13);
	blist.push_back(*Receps_lamp13);

	list.push_back(*Receps_ramp14);
	blist.push_back(*Receps_lamp14);

	list.push_back(*Receps_ramp15);
	blist.push_back(*Receps_lamp15);

	list.push_back(*Receps_ramp16);
	blist.push_back(*Receps_lamp16);

	list.push_back(*Receps_ramp17);
	blist.push_back(*Receps_lamp17);

	list.push_back(*Receps_ramp18);
	blist.push_back(*Receps_lamp18);

	list.push_back(*Receps_ramp19);
	blist.push_back(*Receps_lamp19);

	list.push_back(*Receps_ramp20);
	blist.push_back(*Receps_lamp20);

	list.push_back(*Receps_ramp21);
	blist.push_back(*Receps_lamp21);

	list.push_back(*Receps_ramp22);
	blist.push_back(*Receps_lamp22);

	list.push_back(*Receps_ramp23);
	blist.push_back(*Receps_lamp23);

	list.push_back(*Receps_ramp24);
	blist.push_back(*Receps_lamp24);

	list.push_back(*Receps_ramp25);
	blist.push_back(*Receps_lamp25);

	list.push_back(*Receps_ramp26);
	blist.push_back(*Receps_lamp26);

	list.push_back(*Receps_ramp27);
	blist.push_back(*Receps_lamp27);

	list.push_back(*Receps_ramp28);
	blist.push_back(*Receps_lamp28);

	list.push_back(*Receps_ramp29);
	blist.push_back(*Receps_lamp29);

	list.push_back(*Receps_ramp30);
	blist.push_back(*Receps_lamp30);

	list.push_back(*Receps_ramp31);
	blist.push_back(*Receps_lamp31);

	list.push_back(*Receps_ramp32);
	blist.push_back(*Receps_lamp32);

	list.push_back(*Receps_ramp33);
	blist.push_back(*Receps_lamp33);

	list.push_back(*Receps_ramp34);
	blist.push_back(*Receps_lamp34);

	list.push_back(*Receps_ramp35);
	blist.push_back(*Receps_lamp35);

	list.push_back(*Receps_ramp36);
	blist.push_back(*Receps_lamp36);

	list.push_back(*Receps_ramp37);
	blist.push_back(*Receps_lamp37);

	list.push_back(*Receps_ramp38);
	blist.push_back(*Receps_lamp38);

	list.push_back(*Receps_ramp39);
	blist.push_back(*Receps_lamp39);

	list.push_back(*Receps_ramp40);
	blist.push_back(*Receps_lamp40);

	list.push_back(*Receps_ramp41);
	blist.push_back(*Receps_lamp41);

	list.push_back(*Receps_ramp42);
	blist.push_back(*Receps_lamp42);

	list.push_back(*Receps_ramp43);
	blist.push_back(*Receps_lamp43);

	list.push_back(*Receps_ramp44);
	blist.push_back(*Receps_lamp44);

	list.push_back(*Receps_ramp45);
	blist.push_back(*Receps_lamp45);

	list.push_back(*Receps_ramp46);
	blist.push_back(*Receps_lamp46);

	list.push_back(*Receps_ramp47);
	blist.push_back(*Receps_lamp47);

	list.push_back(*Receps_ramp48);
	blist.push_back(*Receps_lamp48);


	////////////////////////////////////////

	list.push_back(*Receps_MoonBonchae);
	blist.push_back(*Receps_MoonBonchaes);

	list.push_back(*Receps_Moon_L);
	blist.push_back(*Receps_MoonLeft);

	list.push_back(*Receps_Moon_R);
	blist.push_back(*Receps_MoonRight);

}

void createObstacles2_3(vector<Object>& list, vector<BoundingBox>& blist)
{

}