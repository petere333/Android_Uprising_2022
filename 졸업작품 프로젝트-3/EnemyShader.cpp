#include "EnemyShader.h"

EnemyShader::EnemyShader(ResourceManager* r, float** height, float** height2, float** height3, float** height4, float** height5, float** height6)
{
	rm = r;
	height11 = height;
	height12 = height2;
	height13 = height3;
	height21 = height4;
	height22 = height5;
	height23 = height6;
}
EnemyShader::~EnemyShader() {}

void EnemyShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* sig)
{
	int mhp = 20;
	int rhp = 20;
	float mdur = 0.833333f;
	float mrange = 2.0f;
	float rrange = 8.0f;
	float rdur = 0.2f;
	EnemyObject* obj1 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj1->SetPosition      (170.0f, 0.0f, 20.0f);
	obj1->origin = XMFLOAT3(170.0f, 0.0f, 20.0f);
	obj1->bState.hp = mhp;
	obj1->weapon = 2;
	obj1->maxHP = mhp;
	obj1->attackRange = mrange;
	obj1->attackDuration = mdur;

	EnemyObject* obj3 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj3->SetPosition		(170.0f, 0.0f, 30.0f);
	obj3->origin = XMFLOAT3	(170.0f, 0.0f, 30.0f);
	obj3->bState.hp = mhp;
	obj3->weapon = 2;
	obj3->maxHP = mhp;
	obj3->attackRange = mrange;
	obj3->attackDuration = mdur;

	EnemyObject* obj4 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj4->SetPosition(12.5f, 0.0f, 145.0f);
	obj4->origin = XMFLOAT3(37.5f, 0.0f, 145.0f);
	obj4->bState.hp = mhp;
	obj4->weapon = 2;
	obj4->maxHP = mhp;
	obj4->attackRange = mrange;
	obj4->attackDuration = mdur;

	EnemyObject* obj5 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj5->SetPosition(55.0f, 0.0f, 88.0f);
	obj5->origin = XMFLOAT3(55.0f, 0.0f, 88.0f);
	obj5->bState.hp = mhp;
	obj5->weapon = 2;
	obj5->maxHP = mhp;
	obj5->attackRange = mrange;
	obj5->attackDuration = mdur;

	EnemyObject* obj6 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj6->SetPosition(17.0f, 0.0f, 86.0f);
	obj6->origin = XMFLOAT3(17.0f, 0.0f, 86.0f);
	obj6->bState.hp = mhp;
	obj6->weapon = 2;
	obj6->maxHP = mhp;
	obj6->attackRange = mrange;
	obj6->attackDuration = mdur;
	
	EnemyObject* obj7 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj7->SetPosition(103.0f, 0.0f, 18.0f);
	obj7->origin = XMFLOAT3(103.0f, 0.0f, 18.0f);
	obj7->bState.hp = mhp;
	obj7->weapon = 2;
	obj7->maxHP = mhp;
	obj7->attackRange = mrange;
	obj7->attackDuration = mdur;

	EnemyObject* obj8 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj8->SetPosition(103.0f, 0.0f, 32.0f);
	obj8->origin = XMFLOAT3(103.0f, 0.0f, 32.0f);
	obj8->bState.hp = mhp;
	obj8->weapon = 2;
	obj8->maxHP = mhp;
	obj8->attackRange = mrange;
	obj8->attackDuration = mdur;

	EnemyObject* obj9 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj9->SetPosition(184.0f, 0.0f, 102.0f);
	obj9->origin = XMFLOAT3(184.0f, 0.0f, 102.0f);
	obj9->bState.hp = mhp;
	obj9->weapon = 2;
	obj9->maxHP = mhp;
	obj9->attackRange = mrange;
	obj9->attackDuration = mdur;

	EnemyObject* obj10 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj10->SetPosition(195.0f, 0.0f, 102.0f);
	obj10->origin = XMFLOAT3(185.0f, 0.0f, 102.0f);
	obj10->bState.hp = mhp;
	obj10->weapon = 2;
	obj10->maxHP = mhp;
	obj10->attackRange = mrange;
	obj10->attackDuration = mdur;

	EnemyObject* obj11 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj11->SetPosition(162.0f, 0.0f, 137.0f);
	obj11->origin = XMFLOAT3(162.0f, 0.0f, 137.0f);
	obj11->bState.hp = mhp;
	obj11->weapon = 2;
	obj11->maxHP = mhp;
	obj11->attackRange = mrange;
	obj11->attackDuration = mdur;

	EnemyObject* obj12 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj12->SetPosition(162.0f, 0.0f, 145.0f);
	obj12->origin = XMFLOAT3(162.0f, 0.0f, 145.0f);
	obj12->bState.hp = mhp;
	obj12->weapon = 2;
	obj12->maxHP = mhp;
	obj12->attackRange = mrange;
	obj12->attackDuration = mdur;

	EnemyObject* obj13 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj13->SetPosition(86.0f, 0.0f, 138.0f);
	obj13->origin = XMFLOAT3(86.0f, 0.0f, 138.0f);
	obj13->bState.hp = mhp;
	obj13->weapon = 2;
	obj13->maxHP = mhp;
	obj13->attackRange = mrange;
	obj13->attackDuration = mdur;

	EnemyObject* obj14 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj14->SetPosition(97.0f, 0.0f, 146.0f);
	obj14->origin = XMFLOAT3(97.0f, 0.0f, 146.0f);
	obj14->bState.hp = mhp;
	obj14->weapon = 2;
	obj14->maxHP = mhp;
	obj14->attackRange = mrange;
	obj14->attackDuration = mdur;

	EnemyObject* obj15 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj15->SetPosition(122.0f, 0.0f, 185.0f);
	obj15->origin = XMFLOAT3(122.0f, 0.0f, 185.0f);
	obj15->bState.hp = mhp;
	obj15->weapon = 2;
	obj15->maxHP = mhp;
	obj15->attackRange = mrange;
	obj15->attackDuration = mdur;

	EnemyObject* obj16 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj16->SetPosition(122.0f, 0.0f, 175.0f);
	obj16->origin = XMFLOAT3(122.0f, 0.0f, 175.0f);
	obj16->bState.hp = mhp;
	obj16->weapon = 2;
	obj16->maxHP = mhp;
	obj16->attackRange = mrange;
	obj16->attackDuration = mdur;

	EnemyObject* obj17 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj17->SetPosition(122.0f, 0.0f, 165.0f);
	obj17->origin = XMFLOAT3(122.0f, 0.0f, 165.0f);
	obj17->bState.hp = mhp;
	obj17->weapon = 2;
	obj17->maxHP = mhp;
	obj17->attackRange = mrange;
	obj17->attackDuration = mdur;

	EnemyObject* obj18 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj18->SetPosition(122.0f, 0.0f, 155.0f);
	obj18->origin = XMFLOAT3(122.0f, 0.0f, 155.0f);
	obj18->bState.hp = mhp;
	obj18->weapon = 2;
	obj18->maxHP = mhp;
	obj18->attackRange = mrange;
	obj18->attackDuration = mdur;

	EnemyObject* obj19 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj19->SetPosition(165.0f, 0.0f, 195.0f);
	obj19->origin = XMFLOAT3(165.0f, 0.0f, 195.0f);
	obj19->bState.hp = mhp;
	obj19->weapon = 2;
	obj19->maxHP = mhp;
	obj19->attackRange = mrange;
	obj19->attackDuration = mdur;

	EnemyObject* obj20 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj20->SetPosition(165.0f, 0.0f, 174.0f);
	obj20->origin = XMFLOAT3(165.0f, 0.0f, 174.0f);
	obj20->bState.hp = mhp;
	obj20->weapon = 2;
	obj20->maxHP = mhp;
	obj20->attackRange = mrange;
	obj20->attackDuration = mdur;

	EnemyObject* obj21 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj21->SetPosition(165.0f, 0.0f, 156.0f);
	obj21->origin = XMFLOAT3(165.0f, 0.0f, 156.0f);
	obj21->bState.hp = mhp;
	obj21->weapon = 2;
	obj21->maxHP = mhp;
	obj21->attackRange = mrange;
	obj21->attackDuration = mdur;

	EnemyObject* obj2 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj2->SetPosition(185.0f, 0.0f, 16.0f);
	obj2->origin = XMFLOAT3(185.0f, 0.0f, 16.0f);
	obj2->bState.hp = rhp;
	obj2->weapon = 1;
	obj2->maxHP = rhp;
	obj2->attackRange = rrange;
	obj2->attackDuration = rdur;

	EnemyObject* obj22 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj22->SetPosition(185.0f, 0.0f, 27.0f);
	obj22->origin = XMFLOAT3(185.0f, 0.0f, 27.0f);
	obj22->bState.hp = rhp;
	obj22->weapon = 1;
	obj22->maxHP = rhp;
	obj22->attackRange = rrange;
	obj22->attackDuration = rdur;

	EnemyObject* obj23 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj23->SetPosition(185.0f, 0.0f, 36.0f);
	obj23->origin = XMFLOAT3(185.0f, 0.0f, 36.0f);
	obj23->bState.hp = rhp;
	obj23->weapon = 1;
	obj23->maxHP = rhp;
	obj23->attackRange = rrange;
	obj23->attackDuration = rdur;

	EnemyObject* obj24 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj24->SetPosition(21.0f, 0.0f, 135.0f);
	obj24->origin = XMFLOAT3(21.0f, 0.0f, 135.0f);
	obj24->bState.hp = rhp;
	obj24->weapon = 1;
	obj24->maxHP = rhp;
	obj24->attackRange = rrange;
	obj24->attackDuration = rdur;

	EnemyObject* obj25 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj25->SetPosition(28.0f, 0.0f, 135.0f);
	obj25->origin = XMFLOAT3(28.0f, 0.0f, 135.0f);
	obj25->bState.hp = rhp;
	obj25->weapon = 1;
	obj25->maxHP = rhp;
	obj25->attackRange = rrange;
	obj25->attackDuration = rdur;

	EnemyObject* obj26 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj26->SetPosition(36.0f, 0.0f, 68.0f);
	obj26->origin = XMFLOAT3(36.0f, 0.0f, 68.0f);
	obj26->bState.hp = rhp;
	obj26->weapon = 1;
	obj26->maxHP = rhp;
	obj26->attackRange = rrange;
	obj26->attackDuration = rdur;

	EnemyObject* obj27 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj27->SetPosition(64.0f, 0.0f, 64.0f);
	obj27->origin = XMFLOAT3(64.0f, 0.0f, 64.0f);
	obj27->bState.hp = rhp;
	obj27->weapon = 1;
	obj27->maxHP = rhp;
	obj27->attackRange = rrange;
	obj27->attackDuration = rdur;

	EnemyObject* obj28 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj28->SetPosition(120.0f, 0.0f, 40.0f);
	obj28->origin = XMFLOAT3(120.0f, 0.0f, 40.0f);
	obj28->bState.hp = rhp;
	obj28->weapon = 1;
	obj28->maxHP = rhp;
	obj28->attackRange = rrange;
	obj28->attackDuration = rdur;

	EnemyObject* obj29 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj29->SetPosition(120.0f, 0.0f, 30.0f);
	obj29->origin = XMFLOAT3(120.0f, 0.0f, 30.0f);
	obj29->bState.hp = rhp;
	obj29->weapon = 1;
	obj29->maxHP = rhp;
	obj29->attackRange = rrange;
	obj29->attackDuration = rdur;

	EnemyObject* obj30 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj30->SetPosition(120.0f, 0.0f, 22.0f);
	obj30->origin = XMFLOAT3(120.0f, 0.0f, 22.0f);
	obj30->bState.hp = rhp;
	obj30->weapon = 1;
	obj30->maxHP = rhp;
	obj30->attackRange = rrange;
	obj30->attackDuration = rdur;

	EnemyObject* obj31 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj31->SetPosition(120.0f, 0.0f, 13.0f);
	obj31->origin = XMFLOAT3(120.0f, 0.0f, 13.0f);
	obj31->bState.hp = rhp;
	obj31->weapon = 1;
	obj31->maxHP = rhp;
	obj31->attackRange = rrange;
	obj31->attackDuration = rdur;

	EnemyObject* obj32 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj32->SetPosition(192.0f, 0.0f, 110.0f);
	obj32->origin = XMFLOAT3(192.0f, 0.0f, 110.0f);
	obj32->bState.hp = rhp;
	obj32->weapon = 1;
	obj32->maxHP = rhp;
	obj32->attackRange = rrange;
	obj32->attackDuration = rdur;

	EnemyObject* obj33 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj33->SetPosition(184.0f, 0.0f, 110.0f);
	obj33->origin = XMFLOAT3(184.0f, 0.0f, 110.0f);
	obj33->bState.hp = rhp;
	obj33->weapon = 1;
	obj33->maxHP = rhp;
	obj33->attackRange = rrange;
	obj33->attackDuration = rdur;

	EnemyObject* obj34 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj34->SetPosition(151.0f, 0.0f, 144.0f);
	obj34->origin = XMFLOAT3(151.0f, 0.0f, 144.0f);
	obj34->bState.hp = rhp;
	obj34->weapon = 1;
	obj34->maxHP = rhp;
	obj34->attackRange = rrange;
	obj34->attackDuration = rdur;

	EnemyObject* obj35 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj35->SetPosition(151.0f, 0.0f, 135.0f);
	obj35->origin = XMFLOAT3(151.0f, 0.0f, 135.0f);
	obj35->bState.hp = rhp;
	obj35->weapon = 1;
	obj35->maxHP = rhp;
	obj35->attackRange = rrange;
	obj35->attackDuration = rdur;

	EnemyObject* obj36 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj36->SetPosition(93.0f, 0.0f, 132.0f);
	obj36->origin = XMFLOAT3(93.0f, 0.0f, 132.0f);
	obj36->bState.hp = rhp;
	obj36->weapon = 1;
	obj36->maxHP = rhp;
	obj36->attackRange = rrange;
	obj36->attackDuration = rdur;

	EnemyObject* obj37 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj37->SetPosition(85.0f, 0.0f, 132.0f);
	obj37->origin = XMFLOAT3(85.0f, 0.0f, 132.0f);
	obj37->bState.hp = rhp;
	obj37->weapon = 1;
	obj37->maxHP = rhp;
	obj37->attackRange = rrange;
	obj37->attackDuration = rdur;

	EnemyObject* obj38 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj38->SetPosition(76.0f, 0.0f, 132.0f);
	obj38->origin = XMFLOAT3(76.0f, 0.0f, 132.0f);
	obj38->bState.hp = rhp;
	obj38->weapon = 1;
	obj38->maxHP = rhp;
	obj38->attackRange = rrange;
	obj38->attackDuration = rdur;

	EnemyObject* obj39 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj39->SetPosition(142.0f, 0.0f, 185.0f);
	obj39->origin = XMFLOAT3(142.0f, 0.0f, 185.0f);
	obj39->bState.hp = rhp;
	obj39->weapon = 1;
	obj39->maxHP = rhp;
	obj39->attackRange = rrange;
	obj39->attackDuration = rdur;

	EnemyObject* obj40 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj40->SetPosition(142.0f, 0.0f, 175.0f);
	obj40->origin = XMFLOAT3(142.0f, 0.0f, 175.0f);
	obj40->bState.hp = rhp;
	obj40->weapon = 1;
	obj40->maxHP = rhp;
	obj40->attackRange = rrange;
	obj40->attackDuration = rdur;

	EnemyObject* obj41 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj41->SetPosition(142.0f, 0.0f, 165.0f);
	obj41->origin = XMFLOAT3(142.0f, 0.0f, 165.0f);
	obj41->bState.hp = rhp;
	obj41->weapon = 1;
	obj41->maxHP = rhp;
	obj41->attackRange = rrange;
	obj41->attackDuration = rdur;

	EnemyObject* obj42 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj42->SetPosition(142.0f, 0.0f, 155.0f);
	obj42->origin = XMFLOAT3(142.0f, 0.0f, 155.0f);
	obj42->bState.hp = rhp;
	obj42->weapon = 1;
	obj42->maxHP = rhp;
	obj42->attackRange = rrange;
	obj42->attackDuration = rdur;

	EnemyObject* obj43 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj43->SetPosition(173.0f, 0.0f, 165.0f);
	obj43->origin = XMFLOAT3(173.0f, 0.0f, 165.0f);
	obj43->bState.hp = rhp;
	obj43->weapon = 1;
	obj43->maxHP = rhp;
	obj43->attackRange = rrange;
	obj43->attackDuration = rdur;

	EnemyObject* obj44 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
	obj44->SetPosition(174.0f, 0.0f, 182.0f);
	obj44->origin = XMFLOAT3(174.0f, 0.0f, 182.0f);
	obj44->bState.hp = rhp;
	obj44->weapon = 1;
	obj44->maxHP = rhp;
	obj44->attackRange = rrange;
	obj44->attackDuration = rdur;


	objects.push_back(obj1);
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
	objects.push_back(obj40);
	objects.push_back(obj41);
	objects.push_back(obj42);
	objects.push_back(obj43);
	objects.push_back(obj44);

	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->type = -10;
		objects[i]->SetTrackAnimationSet(0, 0);
		objects[i]->bState.stateID = IDLE_STATE;
		objects[i]->lastAttack = chrono::system_clock::now();

	}




	// 각 적들의 위치에 바운딩 박스 생성
	for (int i = 0; i < objects.size(); ++i)
	{
		//x,y=-0.25~0.25 z=0.0~1.7

		XMFLOAT3 pos = objects[i]->GetPosition();

		BoundBox* box = new BoundBox;
		box->start = XMFLOAT3(pos.x - 0.4f, pos.y, pos.z - 0.4f);
		box->end = XMFLOAT3(pos.x + 0.4f, pos.y + 1.7f, pos.z + 0.4f);

		objects[i]->mbox = box;
	}
	
	
}

void EnemyShader::ReleaseObjects()
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
void EnemyShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void EnemyShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void EnemyShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, float elapsed, ID3D12DescriptorHeap* heap)
{
	
	for (int i = 0; i < objects.size(); ++i)
	{
		XMFLOAT3 pos = objects[i]->GetPosition();
		XMFLOAT3 camPos = pCamera->getPosition();

		float px = camPos.x;
		float pz = camPos.z;

		float ex = pos.x;
		float ez = pos.z;
		XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);

		float dist = Vector3::Length(fromCamera);

		XMFLOAT3 look = pCamera->getLook();
		look.y = 0.0f;
		fromCamera.y = 0.0f;

		float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

		if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 250.0f)
		{

			if (objects[i]->erased == false)
			{
				objects[i]->Animate(elapsed);
				if (objects[i]->m_pSkinnedAnimationController)
				{
					objects[i]->UpdateTransform(NULL);
				}
				if (heap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &heap);
				}
				rm->materials[2]->UpdateShaderVariable(pd3dCommandList);
				objects[i]->Render(pd3dCommandList, pCamera);
			}
		}
	}

	
}

D3D12_INPUT_LAYOUT_DESC EnemyShader::CreateInputLayout()
{
	UINT nInputElementDescs = 4;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "BONEINDEX", 0, DXGI_FORMAT_R32G32B32A32_SINT, 1, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[2] = { "BONEWEIGHT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 2, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[3] = { "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 3, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//pd3dInputElementDescs[4] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 4, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC EnemyShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE EnemyShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Enemy.hlsl", "vsEnemy", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE EnemyShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Enemy.hlsl", "psEnemy", "ps_5_1", &m_pd3dPixelShaderBlob));
}
std::vector<XMFLOAT3> EnemyShader::getEnemyPosition()
{
	std::vector<XMFLOAT3> result;
	for (int i = 0; i < objects.size(); ++i)
	{
		XMFLOAT3 pos = objects[i]->GetPosition();
		result.push_back(pos);
	}
	return result;
}

std::vector<int> EnemyShader::getHealthRate()
{
	std::vector<int> result;

	for (int i = 0; i < objects.size(); ++i)
	{
		int hprate = (int)((float)objects[i]->bState.hp / (float)objects[i]->maxHP * 9.0f);
		result.push_back(hprate);
	}
	return result;
}

void EnemyShader::animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float elapsed, vector<XMFLOAT3> ppos, PlayerShader* ps, ParticleShader* part)
{
	
	for (int i = 0; i < objects.size(); ++i)
	{
		if(objects[i]->erased==false)
		{

		// 체력이 막 떨어진 시점에
		if (objects[i]->bState.hp <= 0 && objects[i]->bState.stateID != DEAD_STATE)
		{
			//죽은 것으로 판정하고 죽은 시점 구하기
			objects[i]->bState.stateID = DEAD_STATE;
			objects[i]->stunned = false;
			objects[i]->deathMoment = chrono::system_clock::now();
			if (objects[i]->weapon == 1)
			{
				//애니메이션도 죽는 것으로 변경
				if (objects[i]->m_pChild != rm->enemyModels[1]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[1]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[1]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			else
			{
				//애니메이션도 죽는 것으로 변경
				if (objects[i]->m_pChild != rm->enemyModels[8]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[8]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[8]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			
		}

		if (objects[i]->stunned == true)
		{
			chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
			chrono::duration<double> dt = moment - objects[i]->lastStun;
			//기절 애니메이션으로 변경
			if (objects[i]->weapon == 1)
			{
				if (objects[i]->m_pChild != rm->enemyModels[5]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[5]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[5]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			else
			{
				if (objects[i]->m_pChild != rm->enemyModels[6]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[6]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[6]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			//기절 지속시간이 끝난 경우
			if ((float)dt.count() >= objects[i]->stunDuration)
			{
				objects[i]->stunned = false;
				objects[i]->stunDuration = 0.0f;
				objects[i]->bState.stateID = PATROL_STATE;
			}

			break;
		}
		if (objects[i]->bState.stateID == PATROL_STATE)
		{
			//플레이어 발견 여부 설정
			float minDist = 9999.0f;
			int playerID = -1; // 발견한 적의 아이디
//높이맵에서, 적과 플레이어 사이의 어느 위치에 높이가 1.0이상인 구간이 존재할 경우 그 플레이어는 발견되지 않았다는 뜻
			for (int p = 0; p < ppos.size(); ++p)
			{
				bool found = true;
				XMFLOAT3 ep = objects[i]->GetPosition();


				float ex = ep.x;
				float ez = ep.z;
				float px = ppos[p].x;
				float pz = ppos[p].z;

				float dx = px - ex;
				float dz = pz - ez;
				float dist = sqrt(dx * dx + dz * dz);
				float nx = dx / dist;
				float nz = dz / dist;
				//30미터 너머의 적은 봐도 못본 것으로 처리
				if (dist > 20.0f)
				{
					continue;
				}

				
				if (abs(dx) > abs(dz))
				{
					if (ex < px)
					{
						for (float x = ex; x < px; x += 0.5f)
						{

							float z = ez + (dz / dx) * 0.5f * (x - ex) * 2.0f;
							if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
							{
								int ix = (int)((x - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}
							else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
							{
								int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}
							if (found == false)
								break;
						}
						if (found == true)
						{
							if (minDist > dist)
							{
								minDist = dist;
								playerID = p;
							}
						}

					}
					else
					{
						for (float x = ex; x > px; x -= 0.5f)
						{
							float z = ez + nz / nx * 0.5f * (x - ex) * 2.0f;

							if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ex < 200.0f)
							{
								int ix = (int)((x - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}
							else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ex < 200.0f)
							{
								int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}

							if (found == false)
								break;
						}
						if (found == true)
						{
							if (minDist > dist)
							{
								minDist = dist;
								playerID = p;
							}
						}
					}
				}
				else
				{
					if (ez < pz)
					{
						for (float z = ez; z < pz; z += 0.5f)
						{
							float x = ex + dx / dz * 0.5f * (z - ez) * 2.0f;

							if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
							{
								int ix = (int)((x - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}
							else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
							{
								int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}
							if (found == false)
								break;

						}
						if (found == true)
						{
							if (minDist > dist)
							{
								minDist = dist;
								playerID = p;
							}
						}
					}
					else
					{
						for (float z = ez; z > pz; z -= 0.5f)
						{
							float x = ex + (dx / dz) * 0.5f * (z - ez) * 2.0f;

							if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
							{
								int ix = (int)((x - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}
							else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
							{
								int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
								int iz = (int)((z - 0.25f) / 0.5f) + 1;
								//ix = (int)((x + 0.25f) / 0.5f);
								//iz = (int)((z + 0.25f) / 0.5f);
								if (objects[i]->heightmap[ix][iz] >= 2.0f)
								{
									found = false;
									break;
								}
							}

							if (found == false)
								break;
						}
						if (found == true)
						{
							if (minDist > dist)
							{
								minDist = dist;
								playerID = p;
							}
						}
					}
				}

			}

			//적이 플레이어에게 타격받거나, 플레이어를 발견한 경우 추적 상태로 전환
			if (playerID != -1)
			{
				printf("적이 플레이어 찾음\n");
				objects[i]->bState.stateID = CHASE_STATE;
				objects[i]->chaseTargetPos = ppos[playerID];
				float xx = (float)((int)((ppos[playerID].x - 0.25f) / 0.5f) + 1) * 0.5f;
				float zz = (float)((int)((ppos[playerID].z - 0.25f) / 0.5f) + 1) * 0.5f;
				objects[i]->chaseTarget = playerID;
				objects[i]->route = objects[i]->NavigateMovement(xx, zz);
				objects[i]->lastSearch = chrono::system_clock::now();
				objects[i]->routeIdx = 0;
				continue;
			}
			else if (objects[i]->hitPlayerID != -1)
			{
				printf("적이 플레이어 찾음\n");
				objects[i]->bState.stateID = CHASE_STATE;
				objects[i]->chaseTargetPos = ppos[objects[i]->hitPlayerID];
				objects[i]->chaseTarget = objects[i]->hitPlayerID;
				objects[i]->route = objects[i]->NavigateMovement(objects[i]->chaseTargetPos.x, objects[i]->chaseTargetPos.z);
				objects[i]->lastSearch = chrono::system_clock::now();
				objects[i]->routeIdx = 0;
				continue;
			}

			// 현재 가고자 하는 곳까지 경로 계산
			if ((objects[i]->routeIdx == objects[i]->route.size()) || (objects[i]->route.size() == 0))
			{
				objects[i]->currentPoint += 1;
				if (objects[i]->seekPoint.size() != 0)
				{
					if (objects[i]->currentPoint == objects[i]->seekPoint.size())
						objects[i]->currentPoint = 0;
					objects[i]->route = objects[i]->NavigateMovement(objects[i]->seekPoint[objects[i]->currentPoint].x, objects[i]->seekPoint[objects[i]->currentPoint].y);
					objects[i]->routeIdx = 0;
				}
				

			}
			objects[i]->moveByRoute(objects[i]->route);
			//이동 애니메이션으로 변경
			if (objects[i]->weapon == 1)
			{
				if (objects[i]->m_pChild != rm->enemyModels[0]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[0]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[0]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			else
			{
				if (objects[i]->m_pChild != rm->enemyModels[10]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[10]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[10]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			

		}

		else if (objects[i]->bState.stateID == CHASE_STATE)
		{
			//빠르게 이동하는 애니메이션으로 변경
			if (objects[i]->weapon == 1)
			{
				if (objects[i]->m_pChild != rm->enemyModels[3]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[3]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[3]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			else
			{
				if (objects[i]->m_pChild != rm->enemyModels[11]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[11]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[11]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}

			//2초에 한번 경로 재설정
			chrono::time_point<chrono::system_clock> moment =  chrono::system_clock::now();
			chrono::duration<double> dtm = moment - objects[i]->lastSearch;
			if ((float)dtm.count() >= 2.0f)
			{
				//플레이어 발견 여부 설정
				float minDist = 9999.0f;
				int playerID = -1; // 발견한 적의 아이디
				for (int p = 0; p < ppos.size(); ++p)
				{
					bool found = true;
					XMFLOAT3 ep = objects[i]->GetPosition();


					float ex = ep.x;
					float ez = ep.z;
					float px = ppos[p].x;
					float pz = ppos[p].z;

					float dx = px - ex;
					float dz = pz - ez;
					float dist = sqrt(dx * dx + dz * dz);
					float nx = dx / dist;
					float nz = dz / dist;
					//30미터 너머의 적은 봐도 못본 것으로 처리
					if (dist > 20.0f)
					{
						continue;
					}


					if (abs(dx) > abs(dz))
					{
						if (ex < px)
						{
							for (float x = ex; x < px; x += 0.5f)
							{

								float z = ez + (dz / dx) * 0.5f * (x - ex) * 2.0f;
								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								if (found == false)
									break;
							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}

						}
						else
						{
							for (float x = ex; x > px; x -= 0.5f)
							{
								float z = ez + nz / nx * 0.5f * (x - ex) * 2.0f;

								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ex < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ex < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}

								if (found == false)
									break;
							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}
						}
					}
					else
					{
						if (ez < pz)
						{
							for (float z = ez; z < pz; z += 0.5f)
							{
								float x = ex + dx / dz * 0.5f * (z - ez) * 2.0f;

								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								if (found == false)
									break;

							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}
						}
						else
						{
							for (float z = ez; z > pz; z -= 0.5f)
							{
								float x = ex + (dx / dz) * 0.5f * (z - ez) * 2.0f;

								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}

								if (found == false)
									break;
							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}
						}
					}

				}

				//적이 플레이어에게 타격받거나, 플레이어를 발견한 경우 추적 상태로 전환
				if (playerID != -1)
				{
					printf("적이 플레이어 찾음\n");
					objects[i]->bState.stateID = CHASE_STATE;
					objects[i]->chaseTargetPos = ppos[playerID];
					float xx = (float)((int)((ppos[playerID].x - 0.25f) / 0.5f) + 1) * 0.5f;
					float zz = (float)((int)((ppos[playerID].z - 0.25f) / 0.5f) + 1) * 0.5f;
					objects[i]->chaseTarget = playerID;
					objects[i]->route = objects[i]->NavigateMovement(xx, zz);
					objects[i]->lastSearch = chrono::system_clock::now();
					objects[i]->routeIdx = 0;
					continue;
				}
				else if (objects[i]->hitPlayerID != -1)
				{
					printf("적이 플레이어 찾음\n");
					objects[i]->bState.stateID = CHASE_STATE;
					objects[i]->chaseTargetPos = ppos[objects[i]->hitPlayerID];
					objects[i]->chaseTarget = objects[i]->hitPlayerID;
					objects[i]->route = objects[i]->NavigateMovement(objects[i]->chaseTargetPos.x, objects[i]->chaseTargetPos.z);
					objects[i]->lastSearch = chrono::system_clock::now();
					objects[i]->routeIdx = 0;
					continue;
				}
			}

			//플레이어의 위치를 향해 감.
			if (objects[i]->routeIdx < objects[i]->route.size())
			{
				objects[i]->moveByRoute(objects[i]->route);
			}
			

			float dist = Vector3::Length(Vector3::Subtract(ppos[objects[i]->chaseTarget], objects[i]->GetPosition()));
			
			float minDist = 9999.0f;
			int attackTarget = -1;
			//추적중인 플레이어와 거리가 공격 사거리보다 짧고, 그 사이에 높이맵이 모두 0인경우
			if (dist <= objects[i]->attackRange)
			{
				bool found = true;
				float ex = objects[i]->GetPosition().x;
				float ez = objects[i]->GetPosition().z;
				float px = ppos[objects[i]->chaseTarget].x;
				float pz = ppos[objects[i]->chaseTarget].z;
				float dx = px - ex;
				float dz = pz - ez;
				float dist = sqrt(dx * dx + dz * dz);
				float nx = dx / dist;
				float nz = dz / dist;
				if (ex < px)
				{
					for (float x = ex; x < px; x += 0.5f)
					{
						float z = ez + nz / nx * 0.5f * (x - ex) * 2.0f;
						if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ex < 200.0f)
						{
							int ix = (int)((x - 0.25f) / 0.5f) + 1;
							int iz = (int)((z - 0.25f) / 0.5f) + 1;

							if (objects[i]->heightmap[ix][iz] >= 2.0f)
							{
								found = false;
								break;
							}
						}
						else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ex < 200.0f)
						{
							int ix = (int)((x -200.0f- 0.25f) / 0.5f) + 1;
							int iz = (int)((z - 0.25f) / 0.5f) + 1;

							if (objects[i]->heightmap[ix][iz] >= 2.0f)
							{
								found = false;
								break;
							}
						}
					}
					if (found == true)
					{
						objects[i]->bState.stateID = BATTLE_STATE;
						objects[i]->attackTarget = objects[i]->chaseTarget;
					}

				}
				else
				{
					for (float x = ex; x > px; x -= 0.5f)
					{
						float z = ez + nz / nx * 0.5f * (x - ex) * 2.0f;

						if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ex < 200.0f)
						{
							int ix = (int)((x - 0.25f) / 0.5f) + 1;
							int iz = (int)((z - 0.25f) / 0.5f) + 1;
							if (objects[i]->heightmap[ix][iz] >= 1.0f)
							{
								found = false;
								break;
							}
						}
						else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ex < 200.0f)
						{
							int ix = (int)((x -200.0f- 0.25f) / 0.5f) + 1;
							int iz = (int)((z - 0.25f) / 0.5f) + 1;
							if (objects[i]->heightmap[ix][iz] >= 1.0f)
							{
								found = false;
								break;
							}
						}
						if (found == false)
							break;
					}
					if (found == true)
					{
						objects[i]->bState.stateID = BATTLE_STATE;
						objects[i]->attackTarget = objects[i]->chaseTarget;
					}
				}

			}


			//추적중인 플레이어와 거리가 너무 멀어지거나, 도착 완료한 경우
			if (dist >= 20.0f || objects[i]->routeIdx==objects[i]->route.size())
			{
				int playerID = -1; // 발견한 적의 아이디
				//높이맵에서, 적과 플레이어 사이의 어느 위치에 높이가 1.0이상인 구간이 존재할 경우 그 플레이어는 발견되지 않았다는 뜻
				for (int p = 0; p < ppos.size(); ++p)
				{
					bool found = true;
					XMFLOAT3 ep = objects[i]->GetPosition();


					float ex = ep.x;
					float ez = ep.z;
					float px = ppos[p].x;
					float pz = ppos[p].z;

					float dx = px - ex;
					float dz = pz - ez;
					float dist = sqrt(dx * dx + dz * dz);
					float nx = dx / dist;
					float nz = dz / dist;
					//15미터 너머의 적은 봐도 못본 것으로 처리
					if (dist > 20.0f)
					{
						objects[i]->chaseTarget = -1;
						objects[i]->attackTarget = -1;
						objects[i]->bState.stateID = PATROL_STATE;
						continue;
					}
					if (abs(dx) > abs(dz))
					{
						if (ex < px)
						{
							for (float x = ex; x < px; x += 0.5f)
							{

								float z = ez + (dz / dx) * 0.5f * (x - ex) * 2.0f;
								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								if (found == false)
									break;
							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}

						}
						else
						{
							for (float x = ex; x > px; x -= 0.5f)
							{
								float z = ez + (dz / dx) * 0.5f * (x - ex) * 2.0f;

								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ex < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ex < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}

								if (found == false)
									break;
							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}
						}
					}
					else
					{
						if (ez < pz)
						{
							for (float z = ez; z < pz; z += 0.5f)
							{
								float x = ex + (dx / dz) * 0.5f * (z - ez) * 2.0f;

								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								if (found == false)
									break;

							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}
						}
						else
						{
							for (float z = ez; z > pz; z -= 0.5f)
							{
								float x = ex + (dx / dz) * 0.5f * (z - ez) * 2.0f;

								if (ex >= 0.0f && ex < 200.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 200.0f && ex < 600.0f && ez >= 0.0f && ez < 200.0f)
								{
									int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}

								if (found == false)
									break;
							}
							if (found == true)
							{
								if (minDist > dist)
								{
									minDist = dist;
									playerID = p;
								}
							}
						}
					}


				}

				//적이 플레이어에게 타격받거나, 플레이어를 발견한 경우 추적 상태로 전환
				if (playerID != -1)
				{
					objects[i]->bState.stateID = CHASE_STATE;
					objects[i]->chaseTargetPos = ppos[playerID];
					float xx = (float)((int)((ppos[playerID].x - 0.25f) / 0.5f) + 1) * 0.5f;
					float zz = (float)((int)((ppos[playerID].z - 0.25f) / 0.5f) + 1) * 0.5f;
					objects[i]->chaseTarget = playerID;
					objects[i]->route = objects[i]->NavigateMovement(xx, zz);
					objects[i]->routeIdx = 0;
					continue;
				}
				else if (objects[i]->hitPlayerID != -1)
				{
					objects[i]->bState.stateID = CHASE_STATE;
					objects[i]->chaseTargetPos = ppos[objects[i]->hitPlayerID];
					objects[i]->chaseTarget = objects[i]->hitPlayerID;
					objects[i]->route = objects[i]->NavigateMovement(objects[i]->chaseTargetPos.x, objects[i]->chaseTargetPos.z);
					objects[i]->routeIdx = 0;
					continue;
				}

			}


		}

		else if (objects[i]->bState.stateID == DEAD_STATE)
		{
			//죽고난 후 시점까지의 경과시간 구하기.
			chrono::duration<double> timeFromDeath = chrono::system_clock::now() - objects[i]->deathMoment;
			float dt = (float)timeFromDeath.count();
			objects[i]->mbox->start = XMFLOAT3(-1.0f, -1.0f, -1.0f);
			objects[i]->mbox->end = XMFLOAT3(-0.5f, -0.5f, -0.5f);
			//1초, 즉 죽는 애니메이션의 재생 시간이 지나면 해당 적 삭제.
			if (dt >= 1.0f)
			{
				objects[i]->m_pMesh = NULL;
				
				objects[i]->erased = true;
			}
		}

		else if (objects[i]->bState.stateID == BATTLE_STATE)
		{
			//공격하는 애니메이션으로 변경
			if (objects[i]->weapon == 1)
			{
				if (objects[i]->m_pChild != rm->enemyModels[4]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[4]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[4]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			else
			{
				if (objects[i]->m_pChild != rm->enemyModels[7]->m_pModelRootObject)
				{
					objects[i]->setRoot(rm->enemyModels[7]->m_pModelRootObject, true);
					objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[7]);
				}
				objects[i]->SetTrackAnimationSet(0, 0);
			}
			XMFLOAT3 pp = XMFLOAT3(ppos[objects[i]->attackTarget].x, 0.0f, ppos[objects[i]->attackTarget].z);
			XMFLOAT3 toPlayer = Vector3::Subtract(pp, objects[i]->GetPosition());

			XMFLOAT3 ntp = Vector3::Normalize(toPlayer);

			float dist = Vector3::Length(toPlayer);
			//공격 대상이 사거리 밖으로 벗어났을 경우
			if (dist > objects[i]->attackRange)
			{
				//다시 순찰모드
				objects[i]->chaseTarget = -1;
				objects[i]->attackTarget = -1;
				objects[i]->bState.stateID = PATROL_STATE;
			}
			else
			{
				float angle = atan2f(ntp.x, ntp.z);
				angle = angle / 3.141592f * 180.0f;
				if (angle >= 360.0f)
					angle -= 360.0f;
				objects[i]->Rotate(0.0f, angle, 0.0f);

				chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
				chrono::duration<double> fromLastAttack = moment - objects[i]->lastAttack;

				float dt = (float)fromLastAttack.count();
				if (dt > objects[i]->attackDuration)
				{
					Line line;
					line.start = objects[i]->GetPosition();
					line.end = pp;

					std::vector<XYZPlane> checkList;

					XYZPlane p1;
					XYZPlane p2;
					XYZPlane p3;
					XYZPlane p4;
					p1.pos = ppos[objects[i]->chaseTarget].x+0.3f;
					p1.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
					checkList.push_back(p1);

					p2.pos = ppos[objects[i]->chaseTarget].x-0.3f;
					p2.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
					checkList.push_back(p2);

					p3.pos = ppos[objects[i]->chaseTarget].z-0.3f;
					p3.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
					checkList.push_back(p3);

					p4.pos = ppos[objects[i]->chaseTarget].z + 0.3f;
					p4.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
					checkList.push_back(p4);
					
					XMFLOAT3 targetPos;
					float md = 9999.0f;

					for (int c = 0; c < checkList.size(); ++c)
					{
						XMFLOAT3 temp = getIntersectPoint(line, checkList[c]);
						if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
						{
							
							float d = Vector3::Length(Vector3::Subtract(temp, objects[i]->GetPosition()));

							if (d < md)
							{
								targetPos = temp;
								targetPos.y = 1.0f;

							}
							

							
						}
					}
					part->createParticles(100, targetPos, pd3dDevice, pd3dCommandList);
					ps->objects[objects[i]->chaseTarget]->info->stats.capacity -= 1;
					objects[i]->lastAttack = chrono::system_clock::now();
				}
			}
		}
		}
	}

	
	
}


XMFLOAT3 getIntersectPoint(Line line, XYZPlane plane)
{
	float u1 = plane.normal.x * line.start.x + plane.normal.y * line.start.y + plane.normal.z * line.start.z - plane.pos;

	float u2 = plane.normal.x * (line.start.x - line.end.x) + plane.normal.y * (line.start.y - line.end.y) + plane.normal.z * (line.start.z - line.end.z);

	if (u1 / u2 < 1.0f && u1 / u2 > 0.0f)
	{

		XMFLOAT3 lineNorm = XMFLOAT3(line.end.x - line.start.x, line.end.y - line.start.y, line.end.z - line.start.z);
		lineNorm.x *= u1 / u2;
		lineNorm.y *= u1 / u2;
		lineNorm.z *= u1 / u2;

		lineNorm.x += line.start.x;
		lineNorm.y += line.start.y;
		lineNorm.z += line.start.z;

		return lineNorm;
	}
	else
	{
		return XMFLOAT3(-9999.0f, -9999.0f, -9999.0f);
	}
}