#include "InterfaceShader.h"


InterfaceShader::InterfaceShader(ResourceManager* r) 
{ 
	rm = r; 
}
InterfaceShader::~InterfaceShader() {}

void InterfaceShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	CubeMeshOffset* mesh = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* meshr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* melee = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(50.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* meleer = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (50.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);
	
	CubeMeshOffset* range = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(90.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ranger = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (90.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* micro = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(130.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* micror = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (130.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* succeed = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 689.0f / 450.0f, 782.0f / 450.0f, 0.02f, -(600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* succeedr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 689.0f / 450.0f, 782.0f / 450.0f, 0.02f, (600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* retry = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, (721.0f - 600.0f) / 450.0f, -(592.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* retryr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, -(721.0f - 600.0f) / 450.0f, -(592.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* back = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, (866.0f - 600.0f) / 450.0f, -(592.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* backr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 130.0f / 450.0f, 65.0f / 450.0f, 0.03f, -(866.0f - 600.0f) / 450.0f, -(592.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exp_melee1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_melee1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_melee2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_melee3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(416.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exp_ranged1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_ranged1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_ranged2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_ranged3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(456.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exp_radio1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* exp_radio1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_radio2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* exp_radio3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(496.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* gold1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (487.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (507.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, (527.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(487.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* gold2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(507.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* gold3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.03f, -(527.0f - 600.0f) / 450.0f, -(536.0f - 450.0f) / 450.0f, true);


	meshes.push_back(mesh);
	revmeshes.push_back(meshr);

	meshes.push_back(melee);
	revmeshes.push_back(meleer);
	meshes.push_back(range);
	revmeshes.push_back(ranger);
	meshes.push_back(micro);
	revmeshes.push_back(micror);




	//�÷��̾� ü�¹�
	for (float i = 0.0f; i < 20.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(0.0f + 5.0f * (20.0f - i + 1.0f)) / 450.0f, -(500.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (0.0f + 5.0f * (20.0f - i + 1.0f)) / 450.0f, -(500.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}

	//��������ġ
	for (float i = 0.0f; i < 10.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(500.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(500.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}
	//���Ÿ�����ġ
	for (float i = 0.0f; i < 10.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(515.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(515.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}
	//���İ���ġ
	for (float i = 0.0f; i < 10.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(530.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(530.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}

	meshes.push_back(succeed);
	meshes.push_back(retry);
	meshes.push_back(back);

	meshes.push_back(exp_melee1);
	meshes.push_back(exp_melee2);
	meshes.push_back(exp_melee3);
	meshes.push_back(exp_ranged1);
	meshes.push_back(exp_ranged2);
	meshes.push_back(exp_ranged3);
	meshes.push_back(exp_radio1);
	meshes.push_back(exp_radio2);
	meshes.push_back(exp_radio3);
	meshes.push_back(gold1);
	meshes.push_back(gold2);
	meshes.push_back(gold3);

	revmeshes.push_back(succeedr);
	revmeshes.push_back(retryr);
	revmeshes.push_back(backr);

	revmeshes.push_back(exp_melee1r);
	revmeshes.push_back(exp_melee2r);
	revmeshes.push_back(exp_melee3r);
	revmeshes.push_back(exp_ranged1r);
	revmeshes.push_back(exp_ranged2r);
	revmeshes.push_back(exp_ranged3r);
	revmeshes.push_back(exp_radio1r);
	revmeshes.push_back(exp_radio2r);
	revmeshes.push_back(exp_radio3r);
	revmeshes.push_back(gold1r);
	revmeshes.push_back(gold2r);
	revmeshes.push_back(gold3r);

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, -1, -1, -1, -1, 263);
	UIObject* obj3 = new UIObject(1, -1, -1, -1, -1, 265);
	UIObject* obj4 = new UIObject(1, -1, -1, -1, -1, 267);
	
	UIObject* obj5 = new UIObject(1, -1, -1, -1, -1, 269);
	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, 270);
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, 271);
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, 272);

	UIObject* obj9 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj10 = new UIObject(1, 656, 559, 786, 625, 302);//retry
	UIObject* obj11 = new UIObject(1, 801, 559, 931, 625, 304);//back
	
	//exp melee
	UIObject* obj12 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj13 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj14 = new UIObject(1, -1, -1, -1, -1, 273);
	//exp range
	UIObject* obj15 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj16 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj17 = new UIObject(1, -1, -1, -1, -1, 273);
	//exp radio
	UIObject* obj18 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj19 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj20 = new UIObject(1, -1, -1, -1, -1, 273);
	//gold
	UIObject* obj21 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj22 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj23 = new UIObject(1, -1, -1, -1, -1, 273);





	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[262]);
	obj->SetPosition(100.0f, 2.0f, 105.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[263]);
	obj2->SetPosition(100.0f, 2.0f, 105.0f);

	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[265]);
	obj3->SetPosition(100.0f, 2.0f, 105.0f);

	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[267]);
	obj4->SetPosition(100.0f, 2.0f, 105.0f);

	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[269]);
	obj5->SetPosition(100.0f, 2.0f, 105.0f);

	obj6->SetMesh(meshes[24]);
	obj6->SetMaterial(0, rm->materials[270]);
	obj6->SetPosition(100.0f, 2.0f, 105.0f);

	obj7->SetMesh(meshes[34]);
	obj7->SetMaterial(0, rm->materials[271]);
	obj7->SetPosition(100.0f, 2.0f, 105.0f);

	obj8->SetMesh(meshes[44]);
	obj8->SetMaterial(0, rm->materials[272]);
	obj8->SetPosition(100.0f, 2.0f, 105.0f);


	//success

	obj9->SetMesh(meshes[54]);
	obj9->SetMaterial(0, rm->materials[301]);
	obj9->SetPosition(100.0f, 2.0f, 105.0f);

	obj10->SetMesh(meshes[55]);
	obj10->SetMaterial(0, rm->materials[302]);
	obj10->SetPosition(100.0f, 2.0f, 105.0f);

	obj11->SetMesh(meshes[56]);
	obj11->SetMaterial(0, rm->materials[304]);
	obj11->SetPosition(100.0f, 2.0f, 105.0f);

	//reward

	//melee
	obj12->SetMesh(meshes[57]);
	obj12->SetMaterial(0, rm->materials[273]);
	obj12->SetPosition(100.0f, 2.0f, 105.0f);
	obj13->SetMesh(meshes[58]);
	obj13->SetMaterial(0, rm->materials[273]);
	obj13->SetPosition(100.0f, 2.0f, 105.0f);
	obj14->SetMesh(meshes[59]);
	obj14->SetMaterial(0, rm->materials[273]);
	obj14->SetPosition(100.0f, 2.0f, 105.0f);

	//range
	obj15->SetMesh(meshes[60]);
	obj15->SetMaterial(0, rm->materials[273]);
	obj15->SetPosition(100.0f, 2.0f, 105.0f);
	obj16->SetMesh(meshes[61]);
	obj16->SetMaterial(0, rm->materials[273]);
	obj16->SetPosition(100.0f, 2.0f, 105.0f);
	obj17->SetMesh(meshes[62]);
	obj17->SetMaterial(0, rm->materials[273]);
	obj17->SetPosition(100.0f, 2.0f, 105.0f);
	//radio
	obj18->SetMesh(meshes[63]);
	obj18->SetMaterial(0, rm->materials[273]);
	obj18->SetPosition(100.0f, 2.0f, 105.0f);
	obj19->SetMesh(meshes[64]);
	obj19->SetMaterial(0, rm->materials[273]);
	obj19->SetPosition(100.0f, 2.0f, 105.0f);
	obj20->SetMesh(meshes[65]);
	obj20->SetMaterial(0, rm->materials[273]);
	obj20->SetPosition(100.0f, 2.0f, 105.0f);

	obj21->SetMesh(meshes[66]);
	obj21->SetMaterial(0, rm->materials[273]);
	obj21->SetPosition(100.0f, 2.0f, 105.0f);
	obj22->SetMesh(meshes[67]);
	obj22->SetMaterial(0, rm->materials[273]);
	obj22->SetPosition(100.0f, 2.0f, 105.0f);
	obj23->SetMesh(meshes[68]);
	obj23->SetMaterial(0, rm->materials[273]);
	obj23->SetPosition(100.0f, 2.0f, 105.0f);

	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
	objects.push_back(obj4);
	objects.push_back(obj5);
	objects.push_back(obj6);
	objects.push_back(obj7);
	objects.push_back(obj8);
	objects.push_back(obj9);

	objects.push_back(obj10);
	objects.push_back(obj11);
	objects.push_back(obj12);
	objects.push_back(obj13);
	objects.push_back(obj14);
	objects.push_back(obj15);
	objects.push_back(obj16);
	objects.push_back(obj17);
	objects.push_back(obj18);
	objects.push_back(obj19);

	objects.push_back(obj20);
	objects.push_back(obj21);
	objects.push_back(obj22);
	objects.push_back(obj23);
}

void InterfaceShader::ReleaseObjects()
{

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Release();
			objects.erase(objects.begin() + i);
		}
	}
	objects.clear();
}
void InterfaceShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void InterfaceShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void InterfaceShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC InterfaceShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 1, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//pd3dInputElementDescs[2] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 2, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC InterfaceShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
#ifdef _WITH_LEFT_HAND_COORDINATES
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
#else
	d3dRasterizerDesc.FrontCounterClockwise = TRUE;
#endif
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return(d3dRasterizerDesc);
}

D3D12_DEPTH_STENCIL_DESC InterfaceShader::CreateDepthStencilState()
{
	D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc;
	::ZeroMemory(&d3dDepthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));
	d3dDepthStencilDesc.DepthEnable = TRUE;
	d3dDepthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	d3dDepthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
	d3dDepthStencilDesc.StencilEnable = FALSE;
	d3dDepthStencilDesc.StencilReadMask = 0x00;
	d3dDepthStencilDesc.StencilWriteMask = 0x00;
	d3dDepthStencilDesc.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	d3dDepthStencilDesc.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;

	return(d3dDepthStencilDesc);
}

D3D12_SHADER_BYTECODE InterfaceShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE InterfaceShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void InterfaceShader::Animate(CCamera* cam, PlayerInfoManager* in)
{
	info = in;

	XMFLOAT3 cp = cam->getPosition();
	XMFLOAT3 cl = cam->getLook();
	XMFLOAT3 cr = cam->getRight();
	XMFLOAT3 cu = cam->getUp();
	float pitch = XMConvertToDegrees(atan(cl.y / sqrt(cl.x * cl.x + cl.z * cl.z)));
	
	float yaw = XMConvertToDegrees(atan(cl.x / cl.z));
	float roll = XMConvertToDegrees(atan(cl.x / cl.y));

	if (cl.z < 0)
	{
		pitch = -pitch;

	}

	


	for (int i = 0; i < objects.size(); ++i)
	{
		//��ġ ���밡 �ƴ� ���
		if (i < 4)
		{
			if (cl.z < 0.0f)
			{
				objects[i]->SetMesh(revmeshes[i]);
			}
			else
			{
				objects[i]->SetMesh(meshes[i]);
			}
		}
		else if (i>=4 && i<54)
		{
			int cap = (info->stats.capacity * 100 / info->stats.maxhp - 2) / 5; //������� ��Ÿ�� �� 5�� ����. 20����

			int melee = (info->growth.melee.exp * 100 / expNeed[info->growth.melee.level-1] - 5) / 10; // �ִ뷮 ��� ���緮�� 10������
			int ranged = (info->growth.ranged.exp * 100 / expNeed[info->growth.ranged.level - 1]-5) / 10; // �ִ뷮 ��� ���緮�� 10������
			int radio = (info->growth.radio.exp * 100 / expNeed[info->growth.radio.level - 1]-5) / 10; // �ִ뷮 ��� ���緮�� 10������

			if (cap < 0)
				cap = 0;

			if (melee < 0)
				melee = 0;

			if (ranged < 0)
				ranged = 0;

			if (radio < 0)
				radio = 0;

			if (i == 4)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[4 + cap]);
				}
				else
				{
					objects[i]->SetMesh(meshes[4 + cap]);
				}
			}
			else if (i == 5)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[24 + melee]);
				}
				else
				{
					objects[i]->SetMesh(meshes[24 + melee]);
				}
			}
			else if (i == 6)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[34 + ranged]);
				}
				else
				{
					objects[i]->SetMesh(meshes[34 + ranged]);
				}
			}
			else if (i == 7)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[44 + radio]);
				}
				else
				{
					objects[i]->SetMesh(meshes[44 + radio]);
				}
			}
		}
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y+cl.y, cp.z+cl.z);
	}

	if (stageClear == false)
	{
		for (int i = 8; i < objects.size(); ++i)
		{
			objects[i]->m_pMesh = NULL;
		}

	}
	else
	{
		for (int i = 8; i < objects.size(); ++i)
		{
			if (cl.z < 0.0f)
			{
				objects[i]->SetMesh(revmeshes[46 + i]);
			}
			else
			{
				objects[i]->SetMesh(meshes[46 + i]);
			}
		}
	}
	//	XMFLOAT3 p = objects[1]->GetPosition();
	//objects[1]->SetPosition(p.x+ cu.x, p.y+cu.y, p.z+cu.z);
}