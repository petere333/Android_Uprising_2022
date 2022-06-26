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


	
	file = fopen("result/objects1-2.txt", "w");
	FILE* bf = fopen("result/box1-2.txt", "w");
	FILE* hf = fopen("result/height1-2.txt", "w");
	
	writeHeight(hf, height1_2);

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
	createObstacles1_2(list, blist);
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