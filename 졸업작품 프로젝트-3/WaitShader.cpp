#include "WaitShader.h"


WaitShader::WaitShader(ResourceManager* r)
{
	rm = r;
	
}
WaitShader::~WaitShader() {}

void WaitShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

	//윈도우 크기 450픽셀당 1.0f로 환산.

	CubeMeshOffset* inter = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* inter2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (198.0f - 600.0f) / 450.0f, -(116.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* mainr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (198.0f - 600.0f) / 450.0f, -(116.0f - 450.0f) / 450.0f, true);
	
	CubeMeshOffset* start = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 160.0f / 450.0f, 54.0f / 450.0f, 0.01f, (618.0f - 600.0f) / 450.0f, -(296.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* startr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 160.0f / 450.0f, 54.0f / 450.0f, 0.01f, (618.0f - 600.0f) / 450.0f, -(296.0f - 450.0f) / 450.0f, true);
	
	//인덱스 3~12 레벨 표기

	CubeMeshOffset* total_lv1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (630.0f - 600.0f) / 450.0f, -(137.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_lv2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (650.0f - 600.0f) / 450.0f, -(137.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* total_exp1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (522.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_exp2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (542.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_exp3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (562.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_exp4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (582.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* total_exp5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (621.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_exp6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (641.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_exp7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (661.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* total_exp8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (681.0f - 600.0f) / 450.0f, -(191.0f - 450.0f) / 450.0f, false);

	//인덱스 13~22 골드 표기
	
	CubeMeshOffset* gold1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (880.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (900.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (920.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (940.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (960.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold6 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (980.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold7 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (1000.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold8 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (1020.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold9 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (1040.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* gold10 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 15.0f / 450.0f, 20.0f / 450.0f, 0.02f, (1060.0f - 600.0f) / 450.0f, -(132.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* stageText = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 297.0f / 450.0f, 24.0f / 450.0f, 0.02f, (657.0f - 600.0f) / 450.0f, -(273.0f - 450.0f) / 450.0f, false);

	//인덱스 24~28 플레이어1 상태

	CubeMeshOffset* preview1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 191.0f / 450.0f, 211.0f / 450.0f, 0.02f, (228.0f - 600.0f) / 450.0f, -(510.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* melee1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (161.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ranged1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (227.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* radio1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (293.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ready1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 190.0f / 450.0f, 20.0f / 450.0f, 0.02f, (227.0f - 600.0f) / 450.0f, -(696.0f - 450.0f) / 450.0f, false);

	//인덱스 29~33 플레이어2
	CubeMeshOffset* preview2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 191.0f / 450.0f, 211.0f / 450.0f, 0.02f, (579.0f - 600.0f) / 450.0f, -(510.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* melee2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (512.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ranged2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (578.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* radio2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (644.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ready2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 190.0f / 450.0f, 20.0f / 450.0f, 0.02f, (578.0f - 600.0f) / 450.0f, -(696.0f - 450.0f) / 450.0f, false);

	//인덱스 34~38 플레이어3
	CubeMeshOffset* preview3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 191.0f / 450.0f, 211.0f / 450.0f, 0.02f, (930.0f - 600.0f) / 450.0f, -(510.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* melee3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (863.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ranged3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (929.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* radio3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 58.0f / 450.0f, 36.0f / 450.0f, 0.02f, (995.0f - 600.0f) / 450.0f, -(643.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ready3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 190.0f / 450.0f, 20.0f / 450.0f, 0.02f, (929.0f - 600.0f) / 450.0f, -(696.0f - 450.0f) / 450.0f, false);
	meshes.push_back(inter);
	meshesRev.push_back(inter2);

	meshes.push_back(main);
	meshes.push_back(start);
	meshesRev.push_back(mainr);
	meshesRev.push_back(startr);

	//3~12
	meshes.push_back(total_lv1);
	meshes.push_back(total_lv2);
	meshes.push_back(total_exp1);
	meshes.push_back(total_exp2);
	meshes.push_back(total_exp3);
	meshes.push_back(total_exp4);
	meshes.push_back(total_exp5);
	meshes.push_back(total_exp6);
	meshes.push_back(total_exp7);
	meshes.push_back(total_exp8);
	//13~22
	meshes.push_back(gold1);
	meshes.push_back(gold2);
	meshes.push_back(gold3);
	meshes.push_back(gold4);
	meshes.push_back(gold5);
	meshes.push_back(gold6);
	meshes.push_back(gold7);
	meshes.push_back(gold8);
	meshes.push_back(gold9);
	meshes.push_back(gold10);

	meshes.push_back(stageText);

	//24~28
	meshes.push_back(preview1);
	meshes.push_back(melee1);
	meshes.push_back(ranged1);
	meshes.push_back(radio1);
	meshes.push_back(ready1);

	//29~33
	meshes.push_back(preview2);
	meshes.push_back(melee2);
	meshes.push_back(ranged2);
	meshes.push_back(radio2);
	meshes.push_back(ready2);

	//34~38
	meshes.push_back(preview3);
	meshes.push_back(melee3);
	meshes.push_back(ranged3);
	meshes.push_back(radio3);
	meshes.push_back(ready3);

	meshesRev.push_back(total_lv1);
	meshesRev.push_back(total_lv2);
	meshesRev.push_back(total_exp1);
	meshesRev.push_back(total_exp2);
	meshesRev.push_back(total_exp3);
	meshesRev.push_back(total_exp4);
	meshesRev.push_back(total_exp5);
	meshesRev.push_back(total_exp6);
	meshesRev.push_back(total_exp7);
	meshesRev.push_back(total_exp8);

	meshesRev.push_back(gold1);
	meshesRev.push_back(gold2);
	meshesRev.push_back(gold3);
	meshesRev.push_back(gold4);
	meshesRev.push_back(gold5);
	meshesRev.push_back(gold6);
	meshesRev.push_back(gold7);
	meshesRev.push_back(gold8);
	meshesRev.push_back(gold9);
	meshesRev.push_back(gold10);

	meshesRev.push_back(stageText);

	meshesRev.push_back(preview1);
	meshesRev.push_back(melee1);
	meshesRev.push_back(ranged1);
	meshesRev.push_back(radio1);
	meshesRev.push_back(ready1);
	meshesRev.push_back(preview2);
	meshesRev.push_back(melee2);
	meshesRev.push_back(ranged2);
	meshesRev.push_back(radio2);
	meshesRev.push_back(ready2);
	meshesRev.push_back(preview3);
	meshesRev.push_back(melee3);
	meshesRev.push_back(ranged3);
	meshesRev.push_back(radio3);
	meshesRev.push_back(ready3);

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, 96, 116, 300, 162, 284);
	UIObject* obj3 = new UIObject(1, 538, 296, 698, 350, 290);
	
	UIObject* obj4 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj5 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj9 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj10 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj11 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj12 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj13 = new UIObject(1, -1, -1, -1, -1, 273);

	UIObject* obj14 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj15 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj16 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj17 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj18 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj19 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj20 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj21 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj22 = new UIObject(1, -1, -1, -1, -1, 273);
	UIObject* obj23 = new UIObject(1, -1, -1, -1, -1, 273);

	UIObject* obj24 = new UIObject(1, -1, -1, -1, -1, -1);

	//플1
	UIObject* obj25 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj26 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj27 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj28 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj29 = new UIObject(1, -1, -1, -1, -1, -1);

	//플2
	UIObject* obj30 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj31 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj32 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj33 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj34 = new UIObject(1, -1, -1, -1, -1, -1);


	//플3
	UIObject* obj35 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj36 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj37 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj38 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj39 = new UIObject(1, -1, -1, -1, -1, -1);

	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[283]);
	obj->SetPosition(0.0f, 0.0f, 0.0f);
	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[284]);
	obj2->SetPosition(0.0f, 0.0f, 0.0f);
	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[290]);
	obj3->SetPosition(0.0f, 0.0f, 0.0f);
	
	obj4->SetMesh(meshes[3]);
	obj5->SetMesh(meshes[4]);
	obj6->SetMesh(meshes[5]);
	obj7->SetMesh(meshes[6]);
	obj8->SetMesh(meshes[7]);
	obj9->SetMesh(meshes[8]);
	obj10->SetMesh(meshes[9]);
	obj11->SetMesh(meshes[10]);
	obj12->SetMesh(meshes[11]);
	obj13->SetMesh(meshes[12]);
	
	obj14->SetMesh(meshes[13]);
	obj15->SetMesh(meshes[14]);
	obj16->SetMesh(meshes[15]);
	obj17->SetMesh(meshes[16]);
	obj18->SetMesh(meshes[17]);
	obj19->SetMesh(meshes[18]);
	obj20->SetMesh(meshes[19]);
	obj21->SetMesh(meshes[20]);
	obj22->SetMesh(meshes[21]);
	obj23->SetMesh(meshes[22]);

	obj24->SetMesh(meshes[23]);

	obj25->SetMesh(meshes[24]);
	obj26->SetMesh(meshes[25]);
	obj27->SetMesh(meshes[26]);
	obj28->SetMesh(meshes[27]);
	obj29->SetMesh(NULL);

	obj30->SetMesh(meshes[29]);
	obj31->SetMesh(meshes[30]);
	obj32->SetMesh(meshes[31]);
	obj33->SetMesh(meshes[32]);
	obj34->SetMesh(NULL);

	obj35->SetMesh(meshes[34]);
	obj36->SetMesh(meshes[35]);
	obj37->SetMesh(meshes[36]);
	obj38->SetMesh(meshes[37]);
	obj39->SetMesh(NULL);
	
	obj4->SetMaterial(0, rm->materials[273]);
	obj5->SetMaterial(0, rm->materials[273]);
	obj6->SetMaterial(0, rm->materials[273]);
	obj7->SetMaterial(0, rm->materials[273]);
	obj8->SetMaterial(0, rm->materials[273]);
	obj9->SetMaterial(0, rm->materials[273]);
	obj10->SetMaterial(0, rm->materials[273]);
	obj11->SetMaterial(0, rm->materials[273]);
	obj12->SetMaterial(0, rm->materials[273]);
	obj13->SetMaterial(0, rm->materials[273]);

	obj14->SetMaterial(0, rm->materials[273]);
	obj15->SetMaterial(0, rm->materials[273]);
	obj16->SetMaterial(0, rm->materials[273]);
	obj17->SetMaterial(0, rm->materials[273]);
	obj18->SetMaterial(0, rm->materials[273]);
	obj19->SetMaterial(0, rm->materials[273]);
	obj20->SetMaterial(0, rm->materials[273]);
	obj21->SetMaterial(0, rm->materials[273]);
	obj22->SetMaterial(0, rm->materials[273]);
	obj23->SetMaterial(0, rm->materials[273]);

	obj24->SetMaterial(0, rm->materials[299]);

	obj25->SetMaterial(0, rm->materials[293]);
	obj26->SetMaterial(0, rm->materials[296]);
	obj27->SetMaterial(0, rm->materials[297]);
	obj28->SetMaterial(0, rm->materials[298]);
	obj29->SetMaterial(0, rm->materials[297]);

	obj30->SetMaterial(0, rm->materials[294]);
	obj31->SetMaterial(0, rm->materials[296]);
	obj32->SetMaterial(0, rm->materials[297]);
	obj33->SetMaterial(0, rm->materials[298]);
	obj34->SetMaterial(0, rm->materials[297]);

	obj35->SetMaterial(0, rm->materials[295]);
	obj36->SetMaterial(0, rm->materials[296]);
	obj37->SetMaterial(0, rm->materials[297]);
	obj38->SetMaterial(0, rm->materials[298]);
	obj39->SetMaterial(0, rm->materials[297]);

	obj4->SetPosition(0.0f, 0.0f, 0.0f);
	obj5->SetPosition(0.0f, 0.0f, 0.0f);
	obj6->SetPosition(0.0f, 0.0f, 0.0f);
	obj7->SetPosition(0.0f, 0.0f, 0.0f);
	obj8->SetPosition(0.0f, 0.0f, 0.0f);
	obj9->SetPosition(0.0f, 0.0f, 0.0f);
	obj10->SetPosition(0.0f, 0.0f, 0.0f);

	obj11->SetPosition(0.0f, 0.0f, 0.0f);
	obj12->SetPosition(0.0f, 0.0f, 0.0f);
	obj13->SetPosition(0.0f, 0.0f, 0.0f);
	obj14->SetPosition(0.0f, 0.0f, 0.0f);
	obj15->SetPosition(0.0f, 0.0f, 0.0f);
	obj16->SetPosition(0.0f, 0.0f, 0.0f);
	obj17->SetPosition(0.0f, 0.0f, 0.0f);
	obj18->SetPosition(0.0f, 0.0f, 0.0f);
	obj19->SetPosition(0.0f, 0.0f, 0.0f);

	obj20->SetPosition(0.0f, 0.0f, 0.0f);
	obj21->SetPosition(0.0f, 0.0f, 0.0f);
	obj22->SetPosition(0.0f, 0.0f, 0.0f);
	obj23->SetPosition(0.0f, 0.0f, 0.0f);
	obj24->SetPosition(0.0f, 0.0f, 0.0f);
	obj25->SetPosition(0.0f, 0.0f, 0.0f);
	obj26->SetPosition(0.0f, 0.0f, 0.0f);
	obj27->SetPosition(0.0f, 0.0f, 0.0f);
	obj28->SetPosition(0.0f, 0.0f, 0.0f);
	obj29->SetPosition(0.0f, 0.0f, 0.0f);

	obj30->SetPosition(0.0f, 0.0f, 0.0f);
	obj31->SetPosition(0.0f, 0.0f, 0.0f);
	obj32->SetPosition(0.0f, 0.0f, 0.0f);
	obj33->SetPosition(0.0f, 0.0f, 0.0f);
	obj34->SetPosition(0.0f, 0.0f, 0.0f);
	obj35->SetPosition(0.0f, 0.0f, 0.0f);
	obj36->SetPosition(0.0f, 0.0f, 0.0f);
	obj37->SetPosition(0.0f, 0.0f, 0.0f);
	obj38->SetPosition(0.0f, 0.0f, 0.0f);
	obj39->SetPosition(0.0f, 0.0f, 0.0f);

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
	objects.push_back(obj24);

	objects.push_back(obj25);
	objects.push_back(obj26);
	objects.push_back(obj27);
	objects.push_back(obj28);
	objects.push_back(obj29);

	objects.push_back(obj30);
	objects.push_back(obj31);
	objects.push_back(obj32);
	objects.push_back(obj33);
	objects.push_back(obj34);

	objects.push_back(obj35);
	objects.push_back(obj36);
	objects.push_back(obj37);
	objects.push_back(obj38);
	objects.push_back(obj39);
}

void WaitShader::ReleaseObjects()
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
void WaitShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void WaitShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void WaitShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC WaitShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC WaitShader::CreateRasterizerState()
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

D3D12_DEPTH_STENCIL_DESC WaitShader::CreateDepthStencilState()
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

D3D12_SHADER_BYTECODE WaitShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE WaitShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void WaitShader::Animate(CCamera* cam, PlayerInfoManager* info)
{
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
		if (cl.z < 0)
		{
			objects[i]->SetMesh(meshesRev[i]);
		}
		else
		{
			objects[i]->SetMesh(meshes[i]);
		}
		/*
		if (objects[i]->defaultMesh != -1)
		{
			if (objects[i]->mouseOn == true)
			{
				if (objects[i]->meshChanged == false)
				{
					objects[i]->SetMaterial(0, rm->materials[objects[i]->defaultMesh + 1]);

					objects[i]->meshChanged = true;
				}
			}
			else
			{
				if (objects[i]->meshChanged == false)
				{
					objects[i]->SetMaterial(0, rm->materials[objects[i]->defaultMesh]);

					objects[i]->meshChanged = true;
				}
			}
		}
		*/
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y + cl.y, cp.z + cl.z);
	}
	//	XMFLOAT3 p = objects[1]->GetPosition();
	//objects[1]->SetPosition(p.x+ cu.x, p.y+cu.y, p.z+cu.z);
	{
		int t1 = info->growth.total.level / 10;
		int t2 = info->growth.total.level % 10;

		int t3 = info->growth.total.exp / 1000;
		int t4 = (info->growth.total.exp % 1000) / 100;
		int t5 = (info->growth.total.exp % 100) / 10;
		int t6 = (info->growth.total.exp % 10);

		int t7 = totalExpNeed[info->growth.total.level - 1] / 1000;
		int t8 = (totalExpNeed[info->growth.total.level - 1] % 1000) / 100;
		int t9 = (totalExpNeed[info->growth.total.level - 1] % 100) / 10;
		int t10 = (totalExpNeed[info->growth.total.level - 1] % 10);

		objects[3]->m_ppMaterials[0] = rm->materials[273 + t1];
		objects[4]->m_ppMaterials[0] = rm->materials[273 + t2];
		objects[5]->m_ppMaterials[0] = rm->materials[273 + t3];
		objects[6]->m_ppMaterials[0] = rm->materials[273 + t4];
		objects[7]->m_ppMaterials[0] = rm->materials[273 + t5];
		objects[8]->m_ppMaterials[0] = rm->materials[273 + t6];
		objects[9]->m_ppMaterials[0] = rm->materials[273 + t7];
		objects[10]->m_ppMaterials[0] = rm->materials[273 + t8];
		objects[11]->m_ppMaterials[0] = rm->materials[273 + t9];
		objects[12]->m_ppMaterials[0] = rm->materials[273 + t10];
	}

	int t1 = info->gold / 1000000000;
	int t2 = (info->gold % 1000000000) / 100000000;

	int t3 = (info->gold % 100000000) / 10000000;
	int t4 = (info->gold % 10000000) / 1000000;
	int t5 = (info->gold % 1000000) / 100000;
	int t6 = (info->gold % 100000) / 10000;

	int t7 = (info->gold % 10000) / 1000;
	int t8 = (info->gold % 1000) / 100;
	int t9 = (info->gold % 100) / 10;
	int t10 = (info->gold % 10);

	objects[13]->m_ppMaterials[0] = rm->materials[273 + t1];
	objects[14]->m_ppMaterials[0] = rm->materials[273 + t2];
	objects[15]->m_ppMaterials[0] = rm->materials[273 + t3];
	objects[16]->m_ppMaterials[0] = rm->materials[273 + t4];
	objects[17]->m_ppMaterials[0] = rm->materials[273 + t5];
	objects[18]->m_ppMaterials[0] = rm->materials[273 + t6];
	objects[19]->m_ppMaterials[0] = rm->materials[273 + t7];
	objects[20]->m_ppMaterials[0] = rm->materials[273 + t8];
	objects[21]->m_ppMaterials[0] = rm->materials[273 + t9];
	objects[22]->m_ppMaterials[0] = rm->materials[273 + t10];

	
}