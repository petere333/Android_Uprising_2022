#include "levelMaker.h"

vector<Object> list;

vector<BoundingBox> bList;
vector<BoundingSphere> sList;

FILE* file;
int main()
{
	createObjects(list);
	createBoxes(bList);
	file = fopen("objects.txt", "w");
	FILE* bf = fopen("box.txt", "w");
	FILE* sf = fopen("sphere.txt", "w");


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

void createObjects(vector<Object>& list)
{
	Object o, o2;
	//player
	o.location = f3(3.0f, 0.85f, 3.0f);
	o.type = CONTAINER;

	//container
	o2.location = f3(10.0f, 1.25f, 10.0f);
	o2.type = CUBE;

	list.push_back(o);
	list.push_back(o2);

	//floor
	Object floor;
	floor.location = f3(0.0f, 0.0f, 0.0f);
	floor.type = f800x600;

	list.push_back(floor);

	//walls
	Object vWall1, vWall2, hWall1, hWall2;

	vWall1.location = f3(0.0f, 0.0f, 0.0f);
	vWall1.type = vWall600x500;

	vWall2.location = f3(800.0f, 0.0f, 0.0f);
	vWall2.type = vWall600x500;

	hWall1.location = f3(0.0f, 0.0f, 0.0f);
	hWall1.type = hWall800x500;

	hWall2.location = f3(0.0f, 0.0f, 600.0f);
	hWall2.type = hWall800x500;

	//enemy
	Object e;
	e.location = f3(30.0f, 0.0f, 30.0f);
	e.type = Enemy;

	list.push_back(vWall1);
	list.push_back(vWall2);
	list.push_back(hWall1);
	list.push_back(hWall2);
	list.push_back(e);
}

void createBoxes(vector<BoundingBox>& list)
{
	BoundingBox cont, floor, v1, v2, h1, h2, e;

	cont.x1 = 5.0f;
	cont.y1 = 0.0f;
	cont.z1 = 7.0f;

	cont.x2 = 15.0f;
	cont.y2 = 2.5f;
	cont.z2 = 13.0f;

	floor.x1 = 0.0f;
	floor.y1 = -1.0f;
	floor.z1 = 0.0f;

	floor.x2 = 800.0f;
	floor.y2 = 0.0f;
	floor.z2 = 600.0f;

	v1.x1 = 0.0f;
	v1.y1 = 0.0f;
	v1.z1 = 0.0f;

	v1.x2 = 0.0f;
	v1.y2 = 5.0f;
	v1.z2 = 600.0f;

	v2.x1 = 800.0f;
	v2.y1 = 0.0f;
	v2.z1 = 0.0f;

	v2.x2 = 800.0f;
	v2.y2 = 5.0f;
	v2.z2 = 600.0f;

	h1.x1 = 0.0f;
	h1.y1 = 0.0f;
	h1.z1 = 0.0f;

	h1.x2 = 800.0f;
	h1.y2 = 5.0f;
	h1.z2 = 0.0f;

	h2.x1 = 0.0f;
	h2.y1 = 0.0f;
	h2.z1 = 600.0f;

	h2.x2 = 800.0f;
	h2.y2 = 5.0f;
	h2.z2 = 600.0f;

	e.x1 = 29.5f;
	e.y1 = 0.0f;
	e.z1 = 29.5f;

	e.x2 = 30.5f;
	e.y2 = 1.7f;
	e.z2 = 30.5f;

	list.push_back(cont);
	list.push_back(floor);
	list.push_back(v1);
	list.push_back(v2);
	list.push_back(h1);
	list.push_back(h2);
	list.push_back(e);
}