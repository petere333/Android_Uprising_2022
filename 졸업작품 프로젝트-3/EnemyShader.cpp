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

void EnemyShader::restart()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->SetPosition(objects[i]->origin);

		objects[i]->mbox->start = XMFLOAT3(objects[i]->origin.x - 0.4f, 0.0f, objects[i]->origin.z - 0.4f);
		objects[i]->mbox->end = XMFLOAT3(objects[i]->origin.x + 0.4f, 1.7f, objects[i]->origin.z + 0.4f);
		if (objects[i]->weapon == 2)
		{
			objects[i]->maxHP = mhp;
			objects[i]->bState.hp = mhp;
			objects[i]->attackRange = mrange;
			objects[i]->attackDuration = mdur;

		}
		else
		{
			objects[i]->maxHP = rhp;
			objects[i]->bState.hp = rhp;
			objects[i]->attackRange = rrange;
			objects[i]->attackDuration = rdur;
		}
		objects[i]->attackTarget = -1;
		XMFLOAT3 op = objects[i]->origin;
		objects[i]->seekPoint.push_back(XMFLOAT2(op.x - 0.5f, op.z - 0.5f));
		objects[i]->seekPoint.push_back(XMFLOAT2(op.x + 0.5f, op.z + 0.5f));
		objects[i]->type = -10;
		objects[i]->SetTrackAnimationSet(0, 0);
		objects[i]->bState.stateID = PATROL_STATE;
		objects[i]->lastAttack = chrono::system_clock::now();
		objects[i]->erased = false;
	}
}

void EnemyShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* sig)
{

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







	//여기서부터 1-2구역의 근접 적들
	EnemyObject* obj45 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj45->SetPosition(248.0f, 0.0f, 188.0f);
	obj45->origin = XMFLOAT3(248.0f, 0.0f, 188.0f);
	obj45->bState.hp = mhp;
	obj45->weapon = 2;
	obj45->maxHP = mhp;
	obj45->attackRange = mrange;
	obj45->attackDuration = mdur;

	EnemyObject* obj46 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj46->SetPosition(279.0f, 0.0f, 158.0f);
	obj46->origin = XMFLOAT3(279.0f, 0.0f, 158.0f);
	obj46->bState.hp = mhp;
	obj46->weapon = 2;
	obj46->maxHP = mhp;
	obj46->attackRange = mrange;
	obj46->attackDuration = mdur;

	EnemyObject* obj47 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj47->SetPosition(203.0f, 0.0f, 167.0f);
	obj47->origin = XMFLOAT3(203.0f, 0.0f, 167.0f);
	obj47->bState.hp = mhp;
	obj47->weapon = 2;
	obj47->maxHP = mhp;
	obj47->attackRange = mrange;
	obj47->attackDuration = mdur;

	EnemyObject* obj48 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj48->SetPosition(268.0f, 0.0f, 158.0f);
	obj48->origin = XMFLOAT3(263.0f, 0.0f, 158.0f);
	obj48->bState.hp = mhp;
	obj48->weapon = 2;
	obj48->maxHP = mhp;
	obj48->attackRange = mrange;
	obj48->attackDuration = mdur;

	EnemyObject* obj49 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj49->SetPosition(296.0f, 0.0f, 187.0f);
	obj49->origin = XMFLOAT3(296.0f, 0.0f, 187.0f);
	obj49->bState.hp = mhp;
	obj49->weapon = 2;
	obj49->maxHP = mhp;
	obj49->attackRange = mrange;
	obj49->attackDuration = mdur;

	EnemyObject* obj50 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj50->SetPosition(256.0f, 0.0f, 158.0f);
	obj50->origin = XMFLOAT3(256.0f, 0.0f, 158.0f);
	obj50->bState.hp = mhp;
	obj50->weapon = 2;
	obj50->maxHP = mhp;
	obj50->attackRange = mrange;
	obj50->attackDuration = mdur;

	EnemyObject* obj51 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj51->SetPosition(290.0f, 0.0f, 154.0f);
	obj51->origin = XMFLOAT3(256.0f, 0.0f, 158.0f);
	obj51->bState.hp = mhp;
	obj51->weapon = 2;
	obj51->maxHP = mhp;
	obj51->attackRange = mrange;
	obj51->attackDuration = mdur;

	EnemyObject* obj52 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj52->SetPosition(243.0f, 0.0f, 158.0f);
	obj52->origin = XMFLOAT3(256.0f, 0.0f, 158.0f);
	obj52->bState.hp = mhp;
	obj52->weapon = 2;
	obj52->maxHP = mhp;
	obj52->attackRange = mrange;
	obj52->attackDuration = mdur;

	EnemyObject* obj53 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj53->SetPosition(231.0f, 0.0f, 158.0f);
	obj53->origin = XMFLOAT3(231.0f, 0.0f, 158.0f);
	obj53->bState.hp = mhp;
	obj53->weapon = 2;
	obj53->maxHP = mhp;
	obj53->attackRange = mrange;
	obj53->attackDuration = mdur;

	EnemyObject* obj54 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj54->SetPosition(220.0f, 0.0f, 158.0f);
	obj54->origin = XMFLOAT3(220.0f, 0.0f, 158.0f);
	obj54->bState.hp = mhp;
	obj54->weapon = 2;
	obj54->maxHP = mhp;
	obj54->attackRange = mrange;
	obj54->attackDuration = mdur;

	EnemyObject* obj55 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj55->SetPosition(245.0f, 0.0f, 83.0f);
	obj55->origin = XMFLOAT3(245.0f, 0.0f, 83.0f);
	obj55->bState.hp = mhp;
	obj55->weapon = 2;
	obj55->maxHP = mhp;
	obj55->attackRange = mrange;
	obj55->attackDuration = mdur;

	EnemyObject* obj56 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj56->SetPosition(255.0f, 0.0f, 83.0f);
	obj56->origin = XMFLOAT3(255.0f, 0.0f, 83.0f);
	obj56->bState.hp = mhp;
	obj56->weapon = 2;
	obj56->maxHP = mhp;
	obj56->attackRange = mrange;
	obj56->attackDuration = mdur;

	EnemyObject* obj57 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj57->SetPosition(215.0f, 0.0f, 57.0f);
	obj57->origin = XMFLOAT3(215.0f, 0.0f, 57.0f);
	obj57->bState.hp = mhp;
	obj57->weapon = 2;
	obj57->maxHP = mhp;
	obj57->attackRange = mrange;
	obj57->attackDuration = mdur;

	EnemyObject* obj58 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj58->SetPosition(219.0f, 0.0f, 50.0f);
	obj58->origin = XMFLOAT3(219.0f, 0.0f, 50.0f);
	obj58->bState.hp = mhp;
	obj58->weapon = 2;
	obj58->maxHP = mhp;
	obj58->attackRange = mrange;
	obj58->attackDuration = mdur;

	EnemyObject* obj59 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj59->SetPosition(221.0f, 0.0f, 44.0f);
	obj59->origin = XMFLOAT3(221.0f, 0.0f, 44.0f);
	obj59->bState.hp = mhp;
	obj59->weapon = 2;
	obj59->maxHP = mhp;
	obj59->attackRange = mrange;
	obj59->attackDuration = mdur;

	EnemyObject* obj60 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj60->SetPosition(228.0f, 0.0f, 38.0f);
	obj60->origin = XMFLOAT3(228.0f, 0.0f, 38.0f);
	obj60->bState.hp = mhp;
	obj60->weapon = 2;
	obj60->maxHP = mhp;
	obj60->attackRange = mrange;
	obj60->attackDuration = mdur;

	EnemyObject* obj61 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj61->SetPosition(236.0f, 0.0f, 33.0f);
	obj61->origin = XMFLOAT3(236.0f, 0.0f, 33.0f);
	obj61->bState.hp = mhp;
	obj61->weapon = 2;
	obj61->maxHP = mhp;
	obj61->attackRange = mrange;
	obj61->attackDuration = mdur;

	EnemyObject* obj62 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj62->SetPosition(365.0f, 0.0f, 5.0f);
	obj62->origin = XMFLOAT3(365.0f, 0.0f, 5.0f);
	obj62->bState.hp = mhp;
	obj62->weapon = 2;
	obj62->maxHP = mhp;
	obj62->attackRange = mrange;
	obj62->attackDuration = mdur;

	EnemyObject* obj63 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj63->SetPosition(365.0f, 0.0f, 12.0f);
	obj63->origin = XMFLOAT3(365.0f, 0.0f, 12.0f);
	obj63->bState.hp = mhp;
	obj63->weapon = 2;
	obj63->maxHP = mhp;
	obj63->attackRange = mrange;
	obj63->attackDuration = mdur;

	EnemyObject* obj64 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj64->SetPosition(365.0f, 0.0f, 20.0f);
	obj64->origin = XMFLOAT3(365.0f, 0.0f, 20.0f);
	obj64->bState.hp = mhp;
	obj64->weapon = 2;
	obj64->maxHP = mhp;
	obj64->attackRange = mrange;
	obj64->attackDuration = mdur;

	EnemyObject* obj65 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj65->SetPosition(365.0f, 0.0f, 30.0f);
	obj65->origin = XMFLOAT3(365.0f, 0.0f, 30.0f);
	obj65->bState.hp = mhp;
	obj65->weapon = 2;
	obj65->maxHP = mhp;
	obj65->attackRange = mrange;
	obj65->attackDuration = mdur;

	EnemyObject* obj66 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj66->SetPosition(365.0f, 0.0f, 42.0f);
	obj66->origin = XMFLOAT3(365.0f, 0.0f, 42.0f);
	obj66->bState.hp = mhp;
	obj66->weapon = 2;
	obj66->maxHP = mhp;
	obj66->attackRange = mrange;
	obj66->attackDuration = mdur;

	EnemyObject* obj67 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj67->SetPosition(333.0f, 0.0f, 103.0f);
	obj67->origin = XMFLOAT3(333.0f, 0.0f, 103.0f);
	obj67->bState.hp = mhp;
	obj67->weapon = 2;
	obj67->maxHP = mhp;
	obj67->attackRange = mrange;
	obj67->attackDuration = mdur;

	EnemyObject* obj68 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj68->SetPosition(303.0f, 0.0f, 119.0f);
	obj68->origin = XMFLOAT3(303.0f, 0.0f, 119.0f);
	obj68->bState.hp = mhp;
	obj68->weapon = 2;
	obj68->maxHP = mhp;
	obj68->attackRange = mrange;
	obj68->attackDuration = mdur;

	EnemyObject* obj69 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj69->SetPosition(333.0f, 0.0f, 111.0f);
	obj69->origin = XMFLOAT3(333.0f, 0.0f, 111.0f);
	obj69->bState.hp = mhp;
	obj69->weapon = 2;
	obj69->maxHP = mhp;
	obj69->attackRange = mrange;
	obj69->attackDuration = mdur;

	EnemyObject* obj70 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj70->SetPosition(350.0f, 0.0f, 110.0f);
	obj70->origin = XMFLOAT3(350.0f, 0.0f, 110.0f);
	obj70->bState.hp = mhp;
	obj70->weapon = 2;
	obj70->maxHP = mhp;
	obj70->attackRange = mrange;
	obj70->attackDuration = mdur;

	EnemyObject* obj71 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj71->SetPosition(350.0f, 0.0f, 130.0f);
	obj71->origin = XMFLOAT3(350.0f, 0.0f, 130.0f);
	obj71->bState.hp = mhp;
	obj71->weapon = 2;
	obj71->maxHP = mhp;
	obj71->attackRange = mrange;
	obj71->attackDuration = mdur;

	EnemyObject* obj72 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj72->SetPosition(418.0f, 0.0f, 182.0f);
	obj72->origin = XMFLOAT3(418.0f, 0.0f, 182.0f);
	obj72->bState.hp = mhp;
	obj72->weapon = 2;
	obj72->maxHP = mhp;
	obj72->attackRange = mrange;
	obj72->attackDuration = mdur;

	EnemyObject* obj73 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj73->SetPosition(418.0f, 0.0f, 189.0f);
	obj73->origin = XMFLOAT3(418.0f, 0.0f, 189.0f);
	obj73->bState.hp = mhp;
	obj73->weapon = 2;
	obj73->maxHP = mhp;
	obj73->attackRange = mrange;
	obj73->attackDuration = mdur;

	EnemyObject* obj74 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj74->SetPosition(418.0f, 0.0f, 196.0f);
	obj74->origin = XMFLOAT3(418.0f, 0.0f, 196.0f);
	obj74->bState.hp = mhp;
	obj74->weapon = 2;
	obj74->maxHP = mhp;
	obj74->attackRange = mrange;
	obj74->attackDuration = mdur;

	EnemyObject* obj75 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj75->SetPosition(440.0f, 0.0f, 78.0f);
	obj75->origin = XMFLOAT3(440.0f, 0.0f, 78.0f);
	obj75->bState.hp = mhp;
	obj75->weapon = 2;
	obj75->maxHP = mhp;
	obj75->attackRange = mrange;
	obj75->attackDuration = mdur;
	
	EnemyObject* obj76 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj76->SetPosition(440.0f, 0.0f, 88.0f);
	obj76->origin = XMFLOAT3(440.0f, 0.0f, 88.0f);
	obj76->bState.hp = mhp;
	obj76->weapon = 2;
	obj76->maxHP = mhp;
	obj76->attackRange = mrange;
	obj76->attackDuration = mdur;

	EnemyObject* obj77 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj77->SetPosition(495.0f, 0.0f, 85.0f);
	obj77->origin = XMFLOAT3(495.0f, 0.0f, 85.0f);
	obj77->bState.hp = mhp;
	obj77->weapon = 2;
	obj77->maxHP = mhp;
	obj77->attackRange = mrange;
	obj77->attackDuration = mdur;

	EnemyObject* obj78 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj78->SetPosition(495.0f, 0.0f, 99.0f);
	obj78->origin = XMFLOAT3(495.0f, 0.0f, 99.0f);
	obj78->bState.hp = mhp;
	obj78->weapon = 2;
	obj78->maxHP = mhp;
	obj78->attackRange = mrange;
	obj78->attackDuration = mdur;

	EnemyObject* obj79 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj79->SetPosition(483.0f, 0.0f, 109.0f);
	obj79->origin = XMFLOAT3(483.0f, 0.0f, 109.0f);
	obj79->bState.hp = mhp;
	obj79->weapon = 2;
	obj79->maxHP = mhp;
	obj79->attackRange = mrange;
	obj79->attackDuration = mdur;

	//여기서부터 1-2구역 원거리 적

	EnemyObject* obj80 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj80->SetPosition(273.0f, 0.0f, 189.0f);
	obj80->origin = XMFLOAT3(273.0f, 0.0f, 189.0f);
	obj80->bState.hp = rhp;
	obj80->weapon = 1;
	obj80->maxHP = rhp;
	obj80->attackRange = rrange;
	obj80->attackDuration = rdur;

	EnemyObject* obj81 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj81->SetPosition(207.0f, 0.0f, 154.0f);
	obj81->origin = XMFLOAT3(207.0f, 0.0f, 154.0f);
	obj81->bState.hp = rhp;
	obj81->weapon = 1;
	obj81->maxHP = rhp;
	obj81->attackRange = rrange;
	obj81->attackDuration = rdur;

	EnemyObject* obj82 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj82->SetPosition(296.0f, 0.0f, 166.0f);
	obj82->origin = XMFLOAT3(296.0f, 0.0f, 166.0f);
	obj82->bState.hp = rhp;
	obj82->weapon = 1;
	obj82->maxHP = rhp;
	obj82->attackRange = rrange;
	obj82->attackDuration = rdur;

	EnemyObject* obj83 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj83->SetPosition(294.0f, 0.0f, 136.0f);
	obj83->origin = XMFLOAT3(294.0f, 0.0f, 136.0f);
	obj83->bState.hp = rhp;
	obj83->weapon = 1;
	obj83->maxHP = rhp;
	obj83->attackRange = rrange;
	obj83->attackDuration = rdur;

	EnemyObject* obj84 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj84->SetPosition(280.0f, 0.0f, 137.0f);
	obj84->origin = XMFLOAT3(280.0f, 0.0f, 137.0f);
	obj84->bState.hp = rhp;
	obj84->weapon = 1;
	obj84->maxHP = rhp;
	obj84->attackRange = rrange;
	obj84->attackDuration = rdur;

	EnemyObject* obj85 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj85->SetPosition(268.0f, 0.0f, 138.0f);
	obj85->origin = XMFLOAT3(268.0f, 0.0f, 138.0f);
	obj85->bState.hp = rhp;
	obj85->weapon = 1;
	obj85->maxHP = rhp;
	obj85->attackRange = rrange;
	obj85->attackDuration = rdur;

	EnemyObject* obj86 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj86->SetPosition(256.0f, 0.0f, 138.0f);
	obj86->origin = XMFLOAT3(256.0f, 0.0f, 138.0f);
	obj86->bState.hp = rhp;
	obj86->weapon = 1;
	obj86->maxHP = rhp;
	obj86->attackRange = rrange;
	obj86->attackDuration = rdur;

	EnemyObject* obj87 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj87->SetPosition(244.0f, 0.0f, 138.0f);
	obj87->origin = XMFLOAT3(244.0f, 0.0f, 138.0f);
	obj87->bState.hp = rhp;
	obj87->weapon = 1;
	obj87->maxHP = rhp;
	obj87->attackRange = rrange;
	obj87->attackDuration = rdur;

	EnemyObject* obj88 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj88->SetPosition(232.0f, 0.0f, 138.0f);
	obj88->origin = XMFLOAT3(232.0f, 0.0f, 138.0f);
	obj88->bState.hp = rhp;
	obj88->weapon = 1;
	obj88->maxHP = rhp;
	obj88->attackRange = rrange;
	obj88->attackDuration = rdur;

	EnemyObject* obj89 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj89->SetPosition(219.0f, 0.0f, 139.0f);
	obj89->origin = XMFLOAT3(219.0f, 0.0f, 139.0f);
	obj89->bState.hp = rhp;
	obj89->weapon = 1;
	obj89->maxHP = rhp;
	obj89->attackRange = rrange;
	obj89->attackDuration = rdur;

	EnemyObject* obj90 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj90->SetPosition(206.0f, 0.0f, 139.0f);
	obj90->origin = XMFLOAT3(206.0f, 0.0f, 139.0f);
	obj90->bState.hp = rhp;
	obj90->weapon = 1;
	obj90->maxHP = rhp;
	obj90->attackRange = rrange;
	obj90->attackDuration = rdur;

	EnemyObject* obj91 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj91->SetPosition(242.0f, 0.0f, 70.0f);
	obj91->origin = XMFLOAT3(242.0f, 0.0f, 70.0f);
	obj91->bState.hp = rhp;
	obj91->weapon = 1;
	obj91->maxHP = rhp;
	obj91->attackRange = rrange;
	obj91->attackDuration = rdur;

	EnemyObject* obj92 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj92->SetPosition(249.0f, 0.0f, 70.0f);
	obj92->origin = XMFLOAT3(249.0f, 0.0f, 70.0f);
	obj92->bState.hp = rhp;
	obj92->weapon = 1;
	obj92->maxHP = rhp;
	obj92->attackRange = rrange;
	obj92->attackDuration = rdur;

	EnemyObject* obj93 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj93->SetPosition(258.0f, 0.0f, 70.0f);
	obj93->origin = XMFLOAT3(258.0f, 0.0f, 70.0f);
	obj93->bState.hp = rhp;
	obj93->weapon = 1;
	obj93->maxHP = rhp;
	obj93->attackRange = rrange;
	obj93->attackDuration = rdur;

	EnemyObject* obj94 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj94->SetPosition(209.0f, 0.0f, 36.0f);
	obj94->origin = XMFLOAT3(209.0f, 0.0f, 36.0f);
	obj94->bState.hp = rhp;
	obj94->weapon = 1;
	obj94->maxHP = rhp;
	obj94->attackRange = rrange;
	obj94->attackDuration = rdur;

	EnemyObject* obj95 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj95->SetPosition(215.0f, 0.0f, 29.0f);
	obj95->origin = XMFLOAT3(215.0f, 0.0f, 29.0f);
	obj95->bState.hp = rhp;
	obj95->weapon = 1;
	obj95->maxHP = rhp;
	obj95->attackRange = rrange;
	obj95->attackDuration = rdur;

	EnemyObject* obj96 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj96->SetPosition(222.0f, 0.0f, 25.0f);
	obj96->origin = XMFLOAT3(222.0f, 0.0f, 25.0f);
	obj96->bState.hp = rhp;
	obj96->weapon = 1;
	obj96->maxHP = rhp;
	obj96->attackRange = rrange;
	obj96->attackDuration = rdur;

	EnemyObject* obj97 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj97->SetPosition(230.0f, 0.0f, 21.0f);
	obj97->origin = XMFLOAT3(230.0f, 0.0f, 21.0f);
	obj97->bState.hp = rhp;
	obj97->weapon = 1;
	obj97->maxHP = rhp;
	obj97->attackRange = rrange;
	obj97->attackDuration = rdur;

	EnemyObject* obj98 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj98->SetPosition(239.0f, 0.0f, 17.0f);
	obj98->origin = XMFLOAT3(239.0f, 0.0f, 17.0f);
	obj98->bState.hp = rhp;
	obj98->weapon = 1;
	obj98->maxHP = rhp;
	obj98->attackRange = rrange;
	obj98->attackDuration = rdur;

	EnemyObject* obj99 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj99->SetPosition(358.0f, 0.0f, 55.0f);
	obj99->origin = XMFLOAT3(358.0f, 0.0f, 55.0f);
	obj99->bState.hp = rhp;
	obj99->weapon = 1;
	obj99->maxHP = rhp;
	obj99->attackRange = rrange;
	obj99->attackDuration = rdur;

	EnemyObject* obj100 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj100->SetPosition(371.0f, 0.0f, 55.0f);
	obj100->origin = XMFLOAT3(371.0f, 0.0f, 55.0f);
	obj100->bState.hp = rhp;
	obj100->weapon = 1;
	obj100->maxHP = rhp;
	obj100->attackRange = rrange;
	obj100->attackDuration = rdur;

	EnemyObject* obj101 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj101->SetPosition(384.0f, 0.0f, 55.0f);
	obj101->origin = XMFLOAT3(384.0f, 0.0f, 55.0f);
	obj101->bState.hp = rhp;
	obj101->weapon = 1;
	obj101->maxHP = rhp;
	obj101->attackRange = rrange;
	obj101->attackDuration = rdur;

	EnemyObject* obj102 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj102->SetPosition(385.0f, 0.0f, 43.0f);
	obj102->origin = XMFLOAT3(385.0f, 0.0f, 43.0f);
	obj102->bState.hp = rhp;
	obj102->weapon = 1;
	obj102->maxHP = rhp;
	obj102->attackRange = rrange;
	obj102->attackDuration = rdur;

	EnemyObject* obj103 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj103->SetPosition(385.0f, 0.0f, 31.0f);
	obj103->origin = XMFLOAT3(385.0f, 0.0f, 31.0f);
	obj103->bState.hp = rhp;
	obj103->weapon = 1;
	obj103->maxHP = rhp;
	obj103->attackRange = rrange;
	obj103->attackDuration = rdur;

	EnemyObject* obj104 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj104->SetPosition(385.0f, 0.0f, 20.0f);
	obj104->origin = XMFLOAT3(385.0f, 0.0f, 20.0f);
	obj104->bState.hp = rhp;
	obj104->weapon = 1;
	obj104->maxHP = rhp;
	obj104->attackRange = rrange;
	obj104->attackDuration = rdur;

	EnemyObject* obj105 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj105->SetPosition(385.0f, 0.0f, 12.0f);
	obj105->origin = XMFLOAT3(385.0f, 0.0f, 12.0f);
	obj105->bState.hp = rhp;
	obj105->weapon = 1;
	obj105->maxHP = rhp;
	obj105->attackRange = rrange;
	obj105->attackDuration = rdur;

	EnemyObject* obj106 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj106->SetPosition(385.0f, 0.0f, 5.0f);
	obj106->origin = XMFLOAT3(385.0f, 0.0f, 5.0f);
	obj106->bState.hp = rhp;
	obj106->weapon = 1;
	obj106->maxHP = rhp;
	obj106->attackRange = rrange;
	obj106->attackDuration = rdur;

	EnemyObject* obj107 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj107->SetPosition(327.0f, 0.0f, 92.0f);
	obj107->origin = XMFLOAT3(327.0f, 0.0f, 92.0f);
	obj107->bState.hp = rhp;
	obj107->weapon = 1;
	obj107->maxHP = rhp;
	obj107->attackRange = rrange;
	obj107->attackDuration = rdur;

	EnemyObject* obj108 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj108->SetPosition(327.0f, 0.0f, 95.0f);
	obj108->origin = XMFLOAT3(327.0f, 0.0f, 95.0f);
	obj108->bState.hp = rhp;
	obj108->weapon = 1;
	obj108->maxHP = rhp;
	obj108->attackRange = rrange;
	obj108->attackDuration = rdur;

	EnemyObject* obj109 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj109->SetPosition(327.0f, 0.0f, 98.0f);
	obj109->origin = XMFLOAT3(327.0f, 0.0f, 98.0f);
	obj109->bState.hp = rhp;
	obj109->weapon = 1;
	obj109->maxHP = rhp;
	obj109->attackRange = rrange;
	obj109->attackDuration = rdur;

	EnemyObject* obj110 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj110->SetPosition(370.0f, 0.0f, 134.0f);
	obj110->origin = XMFLOAT3(370.0f, 0.0f, 134.0f);
	obj110->bState.hp = rhp;
	obj110->weapon = 1;
	obj110->maxHP = rhp;
	obj110->attackRange = rrange;
	obj110->attackDuration = rdur;

	EnemyObject* obj111 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj111->SetPosition(332.0f, 0.0f, 135.0f);
	obj111->origin = XMFLOAT3(332.0f, 0.0f, 135.0f);
	obj111->bState.hp = rhp;
	obj111->weapon = 1;
	obj111->maxHP = rhp;
	obj111->attackRange = rrange;
	obj111->attackDuration = rdur;

	EnemyObject* obj112 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj112->SetPosition(350.0f, 0.0f, 115.0f);
	obj112->origin = XMFLOAT3(350.0f, 0.0f, 115.0f);
	obj112->bState.hp = rhp;
	obj112->weapon = 1;
	obj112->maxHP = rhp;
	obj112->attackRange = rrange;
	obj112->attackDuration = rdur;

	EnemyObject* obj113 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj113->SetPosition(350.0f, 0.0f, 102.0f);
	obj113->origin = XMFLOAT3(350.0f, 0.0f, 102.0f);
	obj113->bState.hp = rhp;
	obj113->weapon = 1;
	obj113->maxHP = rhp;
	obj113->attackRange = rrange;
	obj113->attackDuration = rdur;

	EnemyObject* obj114 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj114->SetPosition(314.0f, 0.0f, 152.0f);
	obj114->origin = XMFLOAT3(314.0f, 0.0f, 152.0f);
	obj114->bState.hp = rhp;
	obj114->weapon = 1;
	obj114->maxHP = rhp;
	obj114->attackRange = rrange;
	obj114->attackDuration = rdur;

	EnemyObject* obj115 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj115->SetPosition(326.0f, 0.0f, 145.0f);
	obj115->origin = XMFLOAT3(326.0f, 0.0f, 145.0f);
	obj115->bState.hp = rhp;
	obj115->weapon = 1;
	obj115->maxHP = rhp;
	obj115->attackRange = rrange;
	obj115->attackDuration = rdur;

	EnemyObject* obj116 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj116->SetPosition(350.0f, 0.0f, 145.0f);
	obj116->origin = XMFLOAT3(350.0f, 0.0f, 145.0f);
	obj116->bState.hp = rhp;
	obj116->weapon = 1;
	obj116->maxHP = rhp;
	obj116->attackRange = rrange;
	obj116->attackDuration = rdur;

	EnemyObject* obj117 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj117->SetPosition(375.0f, 0.0f, 145.0f);
	obj117->origin = XMFLOAT3(375.0f, 0.0f, 145.0f);
	obj117->bState.hp = rhp;
	obj117->weapon = 1;
	obj117->maxHP = rhp;
	obj117->attackRange = rrange;
	obj117->attackDuration = rdur;

	EnemyObject* obj118 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj118->SetPosition(338.0f, 0.0f, 150.0f);
	obj118->origin = XMFLOAT3(338.0f, 0.0f, 150.0f);
	obj118->bState.hp = rhp;
	obj118->weapon = 1;
	obj118->maxHP = rhp;
	obj118->attackRange = rrange;
	obj118->attackDuration = rdur;

	EnemyObject* obj119 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj119->SetPosition(363.0f, 0.0f, 150.0f);
	obj119->origin = XMFLOAT3(363.0f, 0.0f, 150.0f);
	obj119->bState.hp = rhp;
	obj119->weapon = 1;
	obj119->maxHP = rhp;
	obj119->attackRange = rrange;
	obj119->attackDuration = rdur;

	EnemyObject* obj120 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj120->SetPosition(389.0f, 0.0f, 150.0f);
	obj120->origin = XMFLOAT3(389.0f, 0.0f, 150.0f);
	obj120->bState.hp = rhp;
	obj120->weapon = 1;
	obj120->maxHP = rhp;
	obj120->attackRange = rrange;
	obj120->attackDuration = rdur;

	EnemyObject* obj121 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj121->SetPosition(350.0f, 0.0f, 120.0f);
	obj121->origin = XMFLOAT3(350.0f, 0.0f, 120.0f);
	obj121->bState.hp = rhp;
	obj121->weapon = 1;
	obj121->maxHP = rhp;
	obj121->attackRange = rrange;
	obj121->attackDuration = rdur;

	EnemyObject* obj122 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj122->SetPosition(433.0f, 0.0f, 193.0f);
	obj122->origin = XMFLOAT3(433.0f, 0.0f, 193.0f);
	obj122->bState.hp = rhp;
	obj122->weapon = 1;
	obj122->maxHP = rhp;
	obj122->attackRange = rrange;
	obj122->attackDuration = rdur;

	EnemyObject* obj123 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj123->SetPosition(433.0f, 0.0f, 185.0f);
	obj123->origin = XMFLOAT3(433.0f, 0.0f, 185.0f);
	obj123->bState.hp = rhp;
	obj123->weapon = 1;
	obj123->maxHP = rhp;
	obj123->attackRange = rrange;
	obj123->attackDuration = rdur;

	EnemyObject* obj124 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj124->SetPosition(420.0f, 0.0f, 135.0f);
	obj124->origin = XMFLOAT3(420.0f, 0.0f, 135.0f);
	obj124->bState.hp = rhp;
	obj124->weapon = 1;
	obj124->maxHP = rhp;
	obj124->attackRange = rrange;
	obj124->attackDuration = rdur;

	EnemyObject* obj125 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj125->SetPosition(420.0f, 0.0f, 146.0f);
	obj125->origin = XMFLOAT3(420.0f, 0.0f, 146.0f);
	obj125->bState.hp = rhp;
	obj125->weapon = 1;
	obj125->maxHP = rhp;
	obj125->attackRange = rrange;
	obj125->attackDuration = rdur;

	EnemyObject* obj126 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj126->SetPosition(420.0f, 0.0f, 160.0f);
	obj126->origin = XMFLOAT3(420.0f, 0.0f, 160.0f);
	obj126->bState.hp = rhp;
	obj126->weapon = 1;
	obj126->maxHP = rhp;
	obj126->attackRange = rrange;
	obj126->attackDuration = rdur;

	EnemyObject* obj127 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj127->SetPosition(420.0f, 0.0f, 177.0f);
	obj127->origin = XMFLOAT3(420.0f, 0.0f, 177.0f);
	obj127->bState.hp = rhp;
	obj127->weapon = 1;
	obj127->maxHP = rhp;
	obj127->attackRange = rrange;
	obj127->attackDuration = rdur;

	EnemyObject* obj128 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj128->SetPosition(450.0f, 0.0f, 176.0f);
	obj128->origin = XMFLOAT3(450.0f, 0.0f, 176.0f);
	obj128->bState.hp = rhp;
	obj128->weapon = 1;
	obj128->maxHP = rhp;
	obj128->attackRange = rrange;
	obj128->attackDuration = rdur;

	EnemyObject* obj129 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj129->SetPosition(450.0f, 0.0f, 165.0f);
	obj129->origin = XMFLOAT3(450.0f, 0.0f, 165.0f);
	obj129->bState.hp = rhp;
	obj129->weapon = 1;
	obj129->maxHP = rhp;
	obj129->attackRange = rrange;
	obj129->attackDuration = rdur;

	EnemyObject* obj130 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj130->SetPosition(450.0f, 0.0f, 155.0f);
	obj130->origin = XMFLOAT3(450.0f, 0.0f, 155.0f);
	obj130->bState.hp = rhp;
	obj130->weapon = 1;
	obj130->maxHP = rhp;
	obj130->attackRange = rrange;
	obj130->attackDuration = rdur;

	EnemyObject* obj131 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj131->SetPosition(450.0f, 0.0f, 145.0f);
	obj131->origin = XMFLOAT3(450.0f, 0.0f, 145.0f);
	obj131->bState.hp = rhp;
	obj131->weapon = 1;
	obj131->maxHP = rhp;
	obj131->attackRange = rrange;
	obj131->attackDuration = rdur;

	EnemyObject* obj132 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj132->SetPosition(450.0f, 0.0f, 133.0f);
	obj132->origin = XMFLOAT3(450.0f, 0.0f, 133.0f);
	obj132->bState.hp = rhp;
	obj132->weapon = 1;
	obj132->maxHP = rhp;
	obj132->attackRange = rrange;
	obj132->attackDuration = rdur;

	EnemyObject* obj133 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj133->SetPosition(424.0f, 0.0f, 103.0f);
	obj133->origin = XMFLOAT3(424.0f, 0.0f, 103.0f);
	obj133->bState.hp = rhp;
	obj133->weapon = 1;
	obj133->maxHP = rhp;
	obj133->attackRange = rrange;
	obj133->attackDuration = rdur;

	EnemyObject* obj134 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj134->SetPosition(413.0f, 0.0f, 103.0f);
	obj134->origin = XMFLOAT3(413.0f, 0.0f, 103.0f);
	obj134->bState.hp = rhp;
	obj134->weapon = 1;
	obj134->maxHP = rhp;
	obj134->attackRange = rrange;
	obj134->attackDuration = rdur;

	EnemyObject* obj135 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj135->SetPosition(403.0f, 0.0f, 103.0f);
	obj135->origin = XMFLOAT3(403.0f, 0.0f, 103.0f);
	obj135->bState.hp = rhp;
	obj135->weapon = 1;
	obj135->maxHP = rhp;
	obj135->attackRange = rrange;
	obj135->attackDuration = rdur;

	EnemyObject* obj136 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj136->SetPosition(414.0f, 0.0f, 107.0f);
	obj136->origin = XMFLOAT3(414.0f, 0.0f, 107.0f);
	obj136->bState.hp = rhp;
	obj136->weapon = 1;
	obj136->maxHP = rhp;
	obj136->attackRange = rrange;
	obj136->attackDuration = rdur;

	EnemyObject* obj137 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj137->SetPosition(404.0f, 0.0f, 107.0f);
	obj137->origin = XMFLOAT3(404.0f, 0.0f, 107.0f);
	obj137->bState.hp = rhp;
	obj137->weapon = 1;
	obj137->maxHP = rhp;
	obj137->attackRange = rrange;
	obj137->attackDuration = rdur;

	EnemyObject* obj138 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj138->SetPosition(450.0f, 0.0f, 78.0f);
	obj138->origin = XMFLOAT3(450.0f, 0.0f, 78.0f);
	obj138->bState.hp = rhp;
	obj138->weapon = 1;
	obj138->maxHP = rhp;
	obj138->attackRange = rrange;
	obj138->attackDuration = rdur;

	EnemyObject* obj139 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj139->SetPosition(450.0f, 0.0f, 88.0f);
	obj139->origin = XMFLOAT3(450.0f, 0.0f, 88.0f);
	obj139->bState.hp = rhp;
	obj139->weapon = 1;
	obj139->maxHP = rhp;
	obj139->attackRange = rrange;
	obj139->attackDuration = rdur;

	EnemyObject* obj140 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj140->SetPosition(450.0f, 0.0f, 83.0f);
	obj140->origin = XMFLOAT3(450.0f, 0.0f, 83.0f);
	obj140->bState.hp = rhp;
	obj140->weapon = 1;
	obj140->maxHP = rhp;
	obj140->attackRange = rrange;
	obj140->attackDuration = rdur;

	EnemyObject* obj141 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj141->SetPosition(533.0f, 0.0f, 193.0f);
	obj141->origin = XMFLOAT3(533.0f, 0.0f, 193.0f);
	obj141->bState.hp = rhp;
	obj141->weapon = 1;
	obj141->maxHP = rhp;
	obj141->attackRange = rrange;
	obj141->attackDuration = rdur;

	EnemyObject* obj142 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj142->SetPosition(518.0f, 0.0f, 193.0f);
	obj142->origin = XMFLOAT3(518.0f, 0.0f, 193.0f);
	obj142->bState.hp = rhp;
	obj142->weapon = 1;
	obj142->maxHP = rhp;
	obj142->attackRange = rrange;
	obj142->attackDuration = rdur;

	EnemyObject* obj143 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj143->SetPosition(506.0f, 0.0f, 193.0f);
	obj143->origin = XMFLOAT3(506.0f, 0.0f, 193.0f);
	obj143->bState.hp = rhp;
	obj143->weapon = 1;
	obj143->maxHP = rhp;
	obj143->attackRange = rrange;
	obj143->attackDuration = rdur;

	EnemyObject* obj144 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj144->SetPosition(495.0f, 0.0f, 193.0f);
	obj144->origin = XMFLOAT3(495.0f, 0.0f, 193.0f);
	obj144->bState.hp = rhp;
	obj144->weapon = 1;
	obj144->maxHP = rhp;
	obj144->attackRange = rrange;
	obj144->attackDuration = rdur;

	EnemyObject* obj145 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj145->SetPosition(496.0f, 0.0f, 185.0f);
	obj145->origin = XMFLOAT3(496.0f, 0.0f, 185.0f);
	obj145->bState.hp = rhp;
	obj145->weapon = 1;
	obj145->maxHP = rhp;
	obj145->attackRange = rrange;
	obj145->attackDuration = rdur;

	EnemyObject* obj146 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj146->SetPosition(507.0f, 0.0f, 185.0f);
	obj146->origin = XMFLOAT3(507.0f, 0.0f, 185.0f);
	obj146->bState.hp = rhp;
	obj146->weapon = 1;
	obj146->maxHP = rhp;
	obj146->attackRange = rrange;
	obj146->attackDuration = rdur;

	EnemyObject* obj147 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj147->SetPosition(519.0f, 0.0f, 185.0f);
	obj147->origin = XMFLOAT3(519.0f, 0.0f, 185.0f);
	obj147->bState.hp = rhp;
	obj147->weapon = 1;
	obj147->maxHP = rhp;
	obj147->attackRange = rrange;
	obj147->attackDuration = rdur;

	EnemyObject* obj148 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj148->SetPosition(518.0f, 0.0f, 178.0f);
	obj148->origin = XMFLOAT3(518.0f, 0.0f, 178.0f);
	obj148->bState.hp = rhp;
	obj148->weapon = 1;
	obj148->maxHP = rhp;
	obj148->attackRange = rrange;
	obj148->attackDuration = rdur;

	EnemyObject* obj149 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj149->SetPosition(505.0f, 0.0f, 178.0f);
	obj149->origin = XMFLOAT3(505.0f, 0.0f, 178.0f);
	obj149->bState.hp = rhp;
	obj149->weapon = 1;
	obj149->maxHP = rhp;
	obj149->attackRange = rrange;
	obj149->attackDuration = rdur;

	EnemyObject* obj150 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj150->SetPosition(494.0f, 0.0f, 178.0f);
	obj150->origin = XMFLOAT3(494.0f, 0.0f, 178.0f);
	obj150->bState.hp = rhp;
	obj150->weapon = 1;
	obj150->maxHP = rhp;
	obj150->attackRange = rrange;
	obj150->attackDuration = rdur;

	EnemyObject* obj151 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj151->SetPosition(506.0f, 0.0f, 170.0f);
	obj151->origin = XMFLOAT3(506.0f, 0.0f, 170.0f);
	obj151->bState.hp = rhp;
	obj151->weapon = 1;
	obj151->maxHP = rhp;
	obj151->attackRange = rrange;
	obj151->attackDuration = rdur;

	EnemyObject* obj152 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj152->SetPosition(516.0f, 0.0f, 170.0f);
	obj152->origin = XMFLOAT3(516.0f, 0.0f, 170.0f);
	obj152->bState.hp = rhp;
	obj152->weapon = 1;
	obj152->maxHP = rhp;
	obj152->attackRange = rrange;
	obj152->attackDuration = rdur;

	EnemyObject* obj153 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height12, 0.0f, 0.0f);
	obj153->SetPosition(529.0f, 0.0f, 170.0f);
	obj153->origin = XMFLOAT3(529.0f, 0.0f, 170.0f);
	obj153->bState.hp = rhp;
	obj153->weapon = 1;
	obj153->maxHP = rhp;
	obj153->attackRange = rrange;
	obj153->attackDuration = rdur;

	/////////////////

	EnemyObject* obj154 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj154->SetPosition(859.0f, 0.0f, 507.0f);
	obj154->origin = XMFLOAT3(859.0f, 0.0f, 507.0f);
	obj154->bState.hp = mhp;
	obj154->weapon = 2;
	obj154->maxHP = mhp;
	obj154->attackRange = mrange;
	obj154->attackDuration = mdur;

	EnemyObject* obj155 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj155->SetPosition(859.0f, 0.0f, 512.0f);
	obj155->origin = XMFLOAT3(859.0f, 0.0f, 512.0f);
	obj155->bState.hp = mhp;
	obj155->weapon = 2;
	obj155->maxHP = mhp;
	obj155->attackRange = mrange;
	obj155->attackDuration = mdur;

	EnemyObject* obj156 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj156->SetPosition(856.0f, 0.0f, 510.0f);
	obj156->origin = XMFLOAT3(856.0f, 0.0f, 510.0f);
	obj156->bState.hp = mhp;
	obj156->weapon = 2;
	obj156->maxHP = mhp;
	obj156->attackRange = mrange;
	obj156->attackDuration = mdur;

	EnemyObject* obj157 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj157->SetPosition(859.0f, 0.0f, 500.0f);
	obj157->origin = XMFLOAT3(859.0f, 0.0f, 500.0f);
	obj157->bState.hp = mhp;
	obj157->weapon = 2;
	obj157->maxHP = mhp;
	obj157->attackRange = mrange;
	obj157->attackDuration = mdur;

	EnemyObject* obj158 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj158->SetPosition(861.0f, 0.0f, 500.0f);
	obj158->origin = XMFLOAT3(861.0f, 0.0f, 500.0f);
	obj158->bState.hp = mhp;
	obj158->weapon = 2;
	obj158->maxHP = mhp;
	obj158->attackRange = mrange;
	obj158->attackDuration = mdur;

	EnemyObject* obj159 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj159->SetPosition(823.0f, 0.0f, 485.0f);
	obj159->origin = XMFLOAT3(823.0f, 0.0f, 485.0f);
	obj159->bState.hp = mhp;
	obj159->weapon = 2;
	obj159->maxHP = mhp;
	obj159->attackRange = mrange;
	obj159->attackDuration = mdur;

	EnemyObject* obj160 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj160->SetPosition(816.0f, 0.0f, 490.0f);
	obj160->origin = XMFLOAT3(816.0f, 0.0f, 490.0f);
	obj160->bState.hp = rhp;
	obj160->weapon = 1;
	obj160->maxHP = rhp;
	obj160->attackRange = rrange;
	obj160->attackDuration = rdur;

	EnemyObject* obj161 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj161->SetPosition(836.0f, 0.0f, 507.0f);
	obj161->origin = XMFLOAT3(836.0f, 0.0f, 507.0f);
	obj161->bState.hp = rhp;
	obj161->weapon = 1;
	obj161->maxHP = rhp;
	obj161->attackRange = rrange;
	obj161->attackDuration = rdur;

	EnemyObject* obj162 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj162->SetPosition(819.0f, 0.0f, 519.0f);
	obj162->origin = XMFLOAT3(819.0f, 0.0f, 519.0f);
	obj162->bState.hp = rhp;
	obj162->weapon = 1;
	obj162->maxHP = rhp;
	obj162->attackRange = rrange;
	obj162->attackDuration = rdur;

	EnemyObject* obj163 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj163->SetPosition(818.0f, 0.0f, 513.0f);
	obj163->origin = XMFLOAT3(818.0f, 0.0f, 513.0f);
	obj163->bState.hp = mhp;
	obj163->weapon = 2;
	obj163->maxHP = mhp;
	obj163->attackRange = mrange;
	obj163->attackDuration = mdur;

	EnemyObject* obj164 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj164->SetPosition(820.0f, 0.0f, 492.0f);
	obj164->origin = XMFLOAT3(820.0f, 0.0f, 492.0f);
	obj164->bState.hp = mhp;
	obj164->weapon = 2;
	obj164->maxHP = mhp;
	obj164->attackRange = mrange;
	obj164->attackDuration = mdur;

	EnemyObject* obj165 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj165->SetPosition(833.0f, 0.0f, 482.0f);
	obj165->origin = XMFLOAT3(833.0f, 0.0f, 482.0f);
	obj165->bState.hp = mhp;
	obj165->weapon = 2;
	obj165->maxHP = mhp;
	obj165->attackRange = mrange;
	obj165->attackDuration = mdur;

	EnemyObject* obj166 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj166->SetPosition(855.0f, 0.0f, 488.0f);
	obj166->origin = XMFLOAT3(848.0f, 0.0f, 488.0f);
	obj166->bState.hp = mhp;
	obj166->weapon = 2;
	obj166->maxHP = mhp;
	obj166->attackRange = mrange;
	obj166->attackDuration = mdur;

	EnemyObject* obj167 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj167->SetPosition(838.0f, 0.0f, 468.0f);
	obj167->origin = XMFLOAT3(838.0f, 0.0f, 468.0f);
	obj167->bState.hp = mhp;
	obj167->weapon = 2;
	obj167->maxHP = mhp;
	obj167->attackRange = mrange;
	obj167->attackDuration = mdur;

	EnemyObject* obj168 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj168->SetPosition(849.0f, 0.0f, 470.0f);
	obj168->origin = XMFLOAT3(849.0f, 0.0f, 470.0f);
	obj168->bState.hp = mhp;
	obj168->weapon = 2;
	obj168->maxHP = mhp;
	obj168->attackRange = mrange;
	obj168->attackDuration = mdur;

	EnemyObject* obj169 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj169->SetPosition(864.0f, 0.0f, 438.0f);
	obj169->origin = XMFLOAT3(864.0f, 0.0f, 438.0f);
	obj169->bState.hp = mhp;
	obj169->weapon = 2;
	obj169->maxHP = mhp;
	obj169->attackRange = mrange;
	obj169->attackDuration = mdur;

	EnemyObject* obj170 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj170->SetPosition(864.0f, 0.0f, 455.0f);
	obj170->origin = XMFLOAT3(864.0f, 0.0f, 455.0f);
	obj170->bState.hp = mhp;
	obj170->weapon = 2;
	obj170->maxHP = mhp;
	obj170->attackRange = mrange;
	obj170->attackDuration = mdur;

	EnemyObject* obj171 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj171->SetPosition(854.0f, 0.0f, 449.0f);
	obj171->origin = XMFLOAT3(854.0f, 0.0f, 449.0f);
	obj171->bState.hp = rhp;
	obj171->weapon = 1;
	obj171->maxHP = rhp;
	obj171->attackRange = rrange;
	obj171->attackDuration = rdur;

	EnemyObject* obj172 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj172->SetPosition(837.0f, 0.0f, 461.0f);
	obj172->origin = XMFLOAT3(837.0f, 0.0f, 461.0f);
	obj172->bState.hp = rhp;
	obj172->weapon = 1;
	obj172->maxHP = rhp;
	obj172->attackRange = rrange;
	obj172->attackDuration = rdur;

	EnemyObject* obj173 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj173->SetPosition(829.0f, 0.0f, 442.0f);
	obj173->origin = XMFLOAT3(829.0f, 0.0f, 442.0f);
	obj173->bState.hp = rhp;
	obj173->weapon = 1;
	obj173->maxHP = rhp;
	obj173->attackRange = rrange;
	obj173->attackDuration = rdur;

	EnemyObject* obj174 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj174->SetPosition(824.0f, 0.0f, 436.0f);
	obj174->origin = XMFLOAT3(824.0f, 0.0f, 436.0f);
	obj174->bState.hp = mhp;
	obj174->weapon = 2;
	obj174->maxHP = mhp;
	obj174->attackRange = mrange;
	obj174->attackDuration = mdur;

	EnemyObject* obj175 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj175->SetPosition(838.0f, 0.0f, 426.0f);
	obj175->origin = XMFLOAT3(838.0f, 0.0f, 426.0f);
	obj175->bState.hp = mhp;
	obj175->weapon = 2;
	obj175->maxHP = mhp;
	obj175->attackRange = mrange;
	obj175->attackDuration = mdur;

	EnemyObject* obj176 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj176->SetPosition(836.0f, 0.0f, 410.0f);
	obj176->origin = XMFLOAT3(836.0f, 0.0f, 410.0f);
	obj176->bState.hp = mhp;
	obj176->weapon = 2;
	obj176->maxHP = mhp;
	obj176->attackRange = mrange;
	obj176->attackDuration = mdur;

	EnemyObject* obj177 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj177->SetPosition(843.0f, 0.0f, 410.0f);
	obj177->origin = XMFLOAT3(843.0f, 0.0f, 410.0f);
	obj177->bState.hp = mhp;
	obj177->weapon = 2;
	obj177->maxHP = mhp;
	obj177->attackRange = mrange;
	obj177->attackDuration = mdur;

	EnemyObject* obj178 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj178->SetPosition(847.0f, 0.0f, 406.0f);
	obj178->origin = XMFLOAT3(847.0f, 0.0f, 406.0f);
	obj178->bState.hp = mhp;
	obj178->weapon = 2;
	obj178->maxHP = mhp;
	obj178->attackRange = mrange;
	obj178->attackDuration = mdur;

	EnemyObject* obj179 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj179->SetPosition(846.0f, 0.0f, 400.0f);
	obj179->origin = XMFLOAT3(846.0f, 0.0f, 400.0f);
	obj179->bState.hp = mhp;
	obj179->weapon = 2;
	obj179->maxHP = mhp;
	obj179->attackRange = mrange;
	obj179->attackDuration = mdur;

	EnemyObject* obj180 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj180->SetPosition(840.0f, 0.0f, 399.0f);
	obj180->origin = XMFLOAT3(840.0f, 0.0f, 399.0f);
	obj180->bState.hp = mhp;
	obj180->weapon = 2;
	obj180->maxHP = mhp;
	obj180->attackRange = mrange;
	obj180->attackDuration = mdur;

	EnemyObject* obj181 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj181->SetPosition(836.0f, 0.0f, 388.0f);
	obj181->origin = XMFLOAT3(836.0f, 0.0f, 388.0f);
	obj181->bState.hp = mhp;
	obj181->weapon = 2;
	obj181->maxHP = mhp;
	obj181->attackRange = mrange;
	obj181->attackDuration = mdur;

	EnemyObject* obj182 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height21, 0.0f, 0.0f);
	obj182->SetPosition(848.0f, 0.0f, 381.0f);
	obj182->origin = XMFLOAT3(848.0f, 0.0f, 381.0f);
	obj182->bState.hp = rhp;
	obj182->weapon = 1;
	obj182->maxHP = rhp;
	obj182->attackRange = rrange;
	obj182->attackDuration = rdur;

	EnemyObject* obj183 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj183->SetPosition(855.0f, 0.0f, 358.0f);
	obj183->origin = XMFLOAT3(855.0f, 0.0f, 358.0f);
	obj183->bState.hp = rhp;
	obj183->weapon = 1;
	obj183->maxHP = rhp;
	obj183->attackRange = rrange;
	obj183->attackDuration = rdur;

	EnemyObject* obj184 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj184->SetPosition(836.0f, 0.0f, 358.0f);
	obj184->origin = XMFLOAT3(836.0f, 0.0f, 358.0f);
	obj184->bState.hp = mhp;
	obj184->weapon = 2;
	obj184->maxHP = mhp;
	obj184->attackRange = mrange;
	obj184->attackDuration = mdur;

	EnemyObject* obj185 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj185->SetPosition(871.0f, 0.0f, 351.0f);
	obj185->origin = XMFLOAT3(871.0f, 0.0f, 351.0f);
	obj185->bState.hp = mhp;
	obj185->weapon = 2;
	obj185->maxHP = mhp;
	obj185->attackRange = mrange;
	obj185->attackDuration = mdur;

	EnemyObject* obj186 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj186->SetPosition(869.0f, 0.0f, 339.0f);
	obj186->origin = XMFLOAT3(869.0f, 0.0f, 339.0f);
	obj186->bState.hp = mhp;
	obj186->weapon = 2;
	obj186->maxHP = mhp;
	obj186->attackRange = mrange;
	obj186->attackDuration = mdur;

	EnemyObject* obj187 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj187->SetPosition(873.0f, 0.0f, 326.0f);
	obj187->origin = XMFLOAT3(873.0f, 0.0f, 326.0f);
	obj187->bState.hp = mhp;
	obj187->weapon = 2;
	obj187->maxHP = mhp;
	obj187->attackRange = mrange;
	obj187->attackDuration = mdur;

	EnemyObject* obj188 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj188->SetPosition(871.0f, 0.0f, 311.0f);
	obj188->origin = XMFLOAT3(871.0f, 0.0f, 311.0f);
	obj188->bState.hp = mhp;
	obj188->weapon = 2;
	obj188->maxHP = mhp;
	obj188->attackRange = mrange;
	obj188->attackDuration = mdur;

	EnemyObject* obj189 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj189->SetPosition(872.0f, 0.0f, 296.0f);
	obj189->origin = XMFLOAT3(872.0f, 0.0f, 296.0f);
	obj189->bState.hp = mhp;
	obj189->weapon = 2;
	obj189->maxHP = mhp;
	obj189->attackRange = mrange;
	obj189->attackDuration = mdur;

	EnemyObject* obj190 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj190->SetPosition(870.0f, 0.0f, 280.0f);
	obj190->origin = XMFLOAT3(870.0f, 0.0f, 280.0f);
	obj190->bState.hp = rhp;
	obj190->weapon = 1;
	obj190->maxHP = rhp;
	obj190->attackRange = rrange;
	obj190->attackDuration = rdur;

	EnemyObject* obj191 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj191->SetPosition(872.0f, 0.0f, 268.0f);
	obj191->origin = XMFLOAT3(872.0f, 0.0f, 268.0f);
	obj191->bState.hp = mhp;
	obj191->weapon = 2;
	obj191->maxHP = mhp;
	obj191->attackRange = mrange;
	obj191->attackDuration = mdur;

	EnemyObject* obj192 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj192->SetPosition(858.0f, 0.0f, 229.0f);
	obj192->origin = XMFLOAT3(872.0f, 0.0f, 229.0f);
	obj192->bState.hp = mhp;
	obj192->weapon = 2;
	obj192->maxHP = mhp;
	obj192->attackRange = mrange;
	obj192->attackDuration = mdur;

	EnemyObject* obj193 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj193->SetPosition(858.0f, 0.0f, 229.0f);
	obj193->origin = XMFLOAT3(858.0f, 0.0f, 229.0f);
	obj193->bState.hp = mhp;
	obj193->weapon = 2;
	obj193->maxHP = mhp;
	obj193->attackRange = mrange;
	obj193->attackDuration = mdur;

	EnemyObject* obj194 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj194->SetPosition(832.0f, 0.0f, 231.0f);
	obj194->origin = XMFLOAT3(832.0f, 0.0f, 231.0f);
	obj194->bState.hp = mhp;
	obj194->weapon = 2;
	obj194->maxHP = mhp;
	obj194->attackRange = mrange;
	obj194->attackDuration = mdur;

	EnemyObject* obj195 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj195->SetPosition(816.0f, 0.0f, 255.0f);
	obj195->origin = XMFLOAT3(816.0f, 0.0f, 255.0f);
	obj195->bState.hp = mhp;
	obj195->weapon = 2;
	obj195->maxHP = mhp;
	obj195->attackRange = mrange;
	obj195->attackDuration = mdur;

	EnemyObject* obj196 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj196->SetPosition(854.0f, 0.0f, 213.0f);
	obj196->origin = XMFLOAT3(854.0f, 0.0f, 213.0f);
	obj196->bState.hp = mhp;
	obj196->weapon = 2;
	obj196->maxHP = mhp;
	obj196->attackRange = mrange;
	obj196->attackDuration = mdur;

	EnemyObject* obj197 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj197->SetPosition(863.0f, 0.0f, 219.0f);
	obj197->origin = XMFLOAT3(863.0f, 0.0f, 219.0f);
	obj197->bState.hp = mhp;
	obj197->weapon = 2;
	obj197->maxHP = mhp;
	obj197->attackRange = mrange;
	obj197->attackDuration = mdur;

	EnemyObject* obj198 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj198->SetPosition(872.0f, 0.0f, 212.0f);
	obj198->origin = XMFLOAT3(872.0f, 0.0f, 212.0f);
	obj198->bState.hp = mhp;
	obj198->weapon = 2;
	obj198->maxHP = mhp;
	obj198->attackRange = mrange;
	obj198->attackDuration = mdur;

	EnemyObject* obj199 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj199->SetPosition(865.0f, 0.0f, 197.0f);
	obj199->origin = XMFLOAT3(865.0f, 0.0f, 197.0f);
	obj199->bState.hp = mhp;
	obj199->weapon = 2;
	obj199->maxHP = mhp;
	obj199->attackRange = mrange;
	obj199->attackDuration = mdur;

	EnemyObject* obj200 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj200->SetPosition(834.0f, 0.0f, 195.0f);
	obj200->origin = XMFLOAT3(834.0f, 0.0f, 195.0f);
	obj200->bState.hp = mhp;
	obj200->weapon = 2;
	obj200->maxHP = mhp;
	obj200->attackRange = mrange;
	obj200->attackDuration = mdur;

	EnemyObject* obj201 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj201->SetPosition(826.0f, 0.0f, 204.0f);
	obj201->origin = XMFLOAT3(826.0f, 0.0f, 204.0f);
	obj201->bState.hp = mhp;
	obj201->weapon = 2;
	obj201->maxHP = mhp;
	obj201->attackRange = mrange;
	obj201->attackDuration = mdur;

	EnemyObject* obj202 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj202->SetPosition(853.0f, 0.0f, 166.0f);
	obj202->origin = XMFLOAT3(853.0f, 0.0f, 166.0f);
	obj202->bState.hp = mhp;
	obj202->weapon = 2;
	obj202->maxHP = mhp;
	obj202->attackRange = mrange;
	obj202->attackDuration = mdur;

	EnemyObject* obj203 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj203->SetPosition(859.0f, 0.0f, 162.0f);
	obj203->origin = XMFLOAT3(859.0f, 0.0f, 162.0f);
	obj203->bState.hp = mhp;
	obj203->weapon = 2;
	obj203->maxHP = mhp;
	obj203->attackRange = mrange;
	obj203->attackDuration = mdur;

	EnemyObject* obj204 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj204->SetPosition(859.0f, 0.0f, 146.0f);
	obj204->origin = XMFLOAT3(859.0f, 0.0f, 146.0f);
	obj204->bState.hp = rhp;
	obj204->weapon = 1;
	obj204->maxHP = rhp;
	obj204->attackRange = rrange;
	obj204->attackDuration = rdur;

	EnemyObject* obj205 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj205->SetPosition(842.0f, 0.0f, 143.0f);
	obj205->origin = XMFLOAT3(842.0f, 0.0f, 143.0f);
	obj205->bState.hp = rhp;
	obj205->weapon = 1;
	obj205->maxHP = rhp;
	obj205->attackRange = rrange;
	obj205->attackDuration = rdur;

	EnemyObject* obj206 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj206->SetPosition(826.0f, 0.0f, 147.0f);
	obj206->origin = XMFLOAT3(826.0f, 0.0f, 147.0f);
	obj206->bState.hp = rhp;
	obj206->weapon = 1;
	obj206->maxHP = rhp;
	obj206->attackRange = rrange;
	obj206->attackDuration = rdur;

	EnemyObject* obj207 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj207->SetPosition(822.0f, 0.0f, 128.0f);
	obj207->origin = XMFLOAT3(822.0f, 0.0f, 128.0f);
	obj207->bState.hp = rhp;
	obj207->weapon = 1;
	obj207->maxHP = rhp;
	obj207->attackRange = rrange;
	obj207->attackDuration = rdur;

	EnemyObject* obj208 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj208->SetPosition(824.0f, 0.0f, 111.0f);
	obj208->origin = XMFLOAT3(824.0f, 0.0f, 111.0f);
	obj208->bState.hp = rhp;
	obj208->weapon = 1;
	obj208->maxHP = rhp;
	obj208->attackRange = rrange;
	obj208->attackDuration = rdur;

	EnemyObject* obj209 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj209->SetPosition(834.0f, 0.0f, 102.0f);
	obj209->origin = XMFLOAT3(834.0f, 0.0f, 102.0f);
	obj209->bState.hp = rhp;
	obj209->weapon = 1;
	obj209->maxHP = rhp;
	obj209->attackRange = rrange;
	obj209->attackDuration = rdur;

	EnemyObject* obj210 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj210->SetPosition(858.0f, 0.0f, 101.0f);
	obj210->origin = XMFLOAT3(858.0f, 0.0f, 101.0f);
	obj210->bState.hp = mhp;
	obj210->weapon = 2;
	obj210->maxHP = mhp;
	obj210->attackRange = mrange;
	obj210->attackDuration = mdur;

	EnemyObject* obj211 = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height22, 0.0f, 0.0f);
	obj211->SetPosition(867.0f, 0.0f, 90.0f);
	obj211->origin = XMFLOAT3(867.0f, 0.0f, 90.0f);
	obj211->bState.hp = mhp;
	obj211->weapon = 2;
	obj211->maxHP = mhp;
	obj211->attackRange = mrange;
	obj211->attackDuration = mdur;

	
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

	objects.push_back(obj45);
	objects.push_back(obj46);
	objects.push_back(obj47);
	objects.push_back(obj48);
	objects.push_back(obj49);

	objects.push_back(obj50);
	objects.push_back(obj51);
	objects.push_back(obj52);
	objects.push_back(obj53);
	objects.push_back(obj54);
	objects.push_back(obj55);
	objects.push_back(obj56);
	objects.push_back(obj57);
	objects.push_back(obj58);
	objects.push_back(obj59);

	objects.push_back(obj60);
	objects.push_back(obj61);
	objects.push_back(obj62);
	objects.push_back(obj63);
	objects.push_back(obj64);
	objects.push_back(obj65);
	objects.push_back(obj66);
	objects.push_back(obj67);
	objects.push_back(obj68);
	objects.push_back(obj69);

	objects.push_back(obj70);
	objects.push_back(obj71);
	objects.push_back(obj72);
	objects.push_back(obj73);
	objects.push_back(obj74);
	objects.push_back(obj75);
	objects.push_back(obj76);
	objects.push_back(obj77);
	objects.push_back(obj78);
	objects.push_back(obj79);

	objects.push_back(obj80);
	objects.push_back(obj81);
	objects.push_back(obj82);
	objects.push_back(obj83);
	objects.push_back(obj84);
	objects.push_back(obj85);
	objects.push_back(obj86);
	objects.push_back(obj87);
	objects.push_back(obj88);
	objects.push_back(obj89);

	objects.push_back(obj90);
	objects.push_back(obj91);
	objects.push_back(obj92);
	objects.push_back(obj93);
	objects.push_back(obj94);
	objects.push_back(obj95);
	objects.push_back(obj96);
	objects.push_back(obj97);
	objects.push_back(obj98);
	objects.push_back(obj99);

	objects.push_back(obj100);
	objects.push_back(obj101);
	objects.push_back(obj102);
	objects.push_back(obj103);
	objects.push_back(obj104);
	objects.push_back(obj105);
	objects.push_back(obj106);
	objects.push_back(obj107);
	objects.push_back(obj108);
	objects.push_back(obj109);

	objects.push_back(obj110);
	objects.push_back(obj111);
	objects.push_back(obj112);
	objects.push_back(obj113);
	objects.push_back(obj114);
	objects.push_back(obj115);
	objects.push_back(obj116);
	objects.push_back(obj117);
	objects.push_back(obj118);
	objects.push_back(obj119);

	objects.push_back(obj120);
	objects.push_back(obj121);
	objects.push_back(obj122);
	objects.push_back(obj123);
	objects.push_back(obj124);
	objects.push_back(obj125);
	objects.push_back(obj126);
	objects.push_back(obj127);
	objects.push_back(obj128);
	objects.push_back(obj129);

	objects.push_back(obj130);
	objects.push_back(obj131);
	objects.push_back(obj132);
	objects.push_back(obj133);
	objects.push_back(obj134);
	objects.push_back(obj135);
	objects.push_back(obj136);
	objects.push_back(obj137);
	objects.push_back(obj138);
	objects.push_back(obj139);

	objects.push_back(obj140);
	objects.push_back(obj141);
	objects.push_back(obj142);
	objects.push_back(obj143);
	objects.push_back(obj144);
	objects.push_back(obj145);
	objects.push_back(obj146);
	objects.push_back(obj147);
	objects.push_back(obj148);
	objects.push_back(obj149);

	objects.push_back(obj150);
	objects.push_back(obj151);
	objects.push_back(obj152);
	objects.push_back(obj153);
	objects.push_back(obj154);
	
	objects.push_back(obj155);
	objects.push_back(obj156);
	objects.push_back(obj157);
	objects.push_back(obj158);
	objects.push_back(obj159);
	objects.push_back(obj160);

	objects.push_back(obj160);
	objects.push_back(obj161);
	objects.push_back(obj162);
	objects.push_back(obj163);
	objects.push_back(obj164);
	objects.push_back(obj165);
	objects.push_back(obj166);
	objects.push_back(obj167);
	objects.push_back(obj168);
	objects.push_back(obj169);
	objects.push_back(obj170);

	objects.push_back(obj170);
	objects.push_back(obj171);
	objects.push_back(obj172);
	objects.push_back(obj173);
	objects.push_back(obj174);
	objects.push_back(obj175);
	objects.push_back(obj176);
	objects.push_back(obj177);
	objects.push_back(obj178);
	objects.push_back(obj179);
	objects.push_back(obj180);

	objects.push_back(obj180);
	objects.push_back(obj181);
	objects.push_back(obj182);
	objects.push_back(obj183);
	objects.push_back(obj184);
	objects.push_back(obj185);
	objects.push_back(obj186);
	objects.push_back(obj187);
	objects.push_back(obj188);
	objects.push_back(obj189);
	objects.push_back(obj190);

	objects.push_back(obj190);
	objects.push_back(obj191);
	objects.push_back(obj192);
	objects.push_back(obj193);
	objects.push_back(obj194);
	objects.push_back(obj195);
	objects.push_back(obj196);
	objects.push_back(obj197);
	objects.push_back(obj198);
	objects.push_back(obj199);
	objects.push_back(obj200);

	objects.push_back(obj200);
	objects.push_back(obj201);
	objects.push_back(obj202);
	objects.push_back(obj203);
	objects.push_back(obj204);
	objects.push_back(obj205);
	objects.push_back(obj206);
	objects.push_back(obj207);
	objects.push_back(obj208);
	objects.push_back(obj209);
	objects.push_back(obj210);

	objects.push_back(obj211);
	
						  
	for (int i = 0; i < objects.size(); ++i)
	{
		XMFLOAT3 op = objects[i]->GetPosition();
		objects[i]->seekPoint.push_back(XMFLOAT2(op.x - 0.5f, op.z - 0.5f));
		objects[i]->seekPoint.push_back(XMFLOAT2(op.x + 0.5f, op.z + 0.5f));
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
		//1-1

		if (px >= 0.0f && px <= 50.0f && pz >= 100.0f && pz <= 200.0f)
		{
			if ((pos.x >= 0.0f && pos.x <= 50.0f && pos.z >= 100.0f && pos.z <= 200.0f) || (pos.x >= 0.0f && pos.x <= 100.0f && pos.z >= 0.0f && pos.z <= 100.0f))
			{
				if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
				{

					if (objects[i]->erased == false)
					{
						if (objects[i]->weapon == 1)
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (rangeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (rangeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (rangeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeAttackAnimated = true;
								}
							}
						}
						else
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (meleeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (meleeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (meleeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeAttackAnimated = true;
								}
							}
						}
						
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
		else if (px >= 0.0f && px <= 100.0f && pz >= 0.0f && pz <= 100.0f)
		{
			if ((pos.x >= 0.0f && pos.x <= 100.0f && pos.z >= 0.0f && pos.z <= 100.0f) || (pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 0.0f && pos.z <= 50.0f)
				|| (pos.x >= 0.0f && pos.x <= 50.0f && pos.z >= 100.0f && pos.z <= 200.0f))
			{
				if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
				{

					if (objects[i]->erased == false)
					{
						if (objects[i]->weapon == 1)
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (rangeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (rangeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (rangeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeAttackAnimated = true;
								}
							}
						}
						else
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (meleeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (meleeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (meleeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeAttackAnimated = true;
								}
							}
						}
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
		else if (px >= 100.0f && px <= 150.0f && pz >= 0.0f && pz <= 50.0f)
		{
			if ((pos.x >= 0.0f && pos.x <= 100.0f && pos.z >= 0.0f && pos.z <= 100.0f) || (pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 0.0f && pos.z <= 50.0f)
				|| (pos.x >= 150.0f && pos.x <= 200.0f && pos.z >= 50.0f && pos.z <= 100.0f))
			{
				if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
				{

					if (objects[i]->erased == false)
					{
						if (objects[i]->weapon == 1)
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (rangeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (rangeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (rangeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeAttackAnimated = true;
								}
							}
						}
						else
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (meleeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (meleeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (meleeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeAttackAnimated = true;
								}
							}
						}
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
		else if (px >= 150.0f && px <= 200.0f && pz >= 0.0f && pz <= 50.0f)
		{
			if ((pos.x >= 0.0f && pos.x <= 100.0f && pos.z >= 0.0f && pos.z <= 100.0f) || (pos.x >= 150.0f && pos.x <= 200.0f && pos.z >= 0.0f && pos.z <= 50.0f)
				|| (pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 50.0f && pos.z <= 150.0f))
			{
				if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
				{

					if (objects[i]->erased == false)
					{
						if (objects[i]->weapon == 1)
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (rangeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (rangeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (rangeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									rangeAttackAnimated = true;
								}
							}
						}
						else
						{
							if (objects[i]->bState.stateID == PATROL_STATE)
							{
								if (meleeWalkAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeWalkAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == CHASE_STATE)
							{
								if (meleeRunAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeRunAnimated = true;
								}
							}
							else if (objects[i]->bState.stateID == BATTLE_STATE)
							{
								if (meleeAttackAnimated == false)
								{
									objects[i]->Animate(elapsed);
									meleeAttackAnimated = true;
								}
							}
						}
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
		else if (px >= 150.0f && px <= 200.0f && pz >= 50.0f && pz <= 150.0f)
		{
		if ((pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 0.0f && pos.z <= 50.0f) || (pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 50.0f && pos.z <= 150.0f)
			|| (pos.x >= 50.0f && pos.x <= 100.0f && pos.z >= 100.0f && pos.z <= 150.0f))
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		else if (px >= 100.0f && px <= 150.0f && pz >= 50.0f && pz <= 150.0f)
		{
		if ((pos.x >= 150.0f && pos.x <= 200.0f && pos.z >= 0.0f && pos.z <= 50.0f) || (pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 50.0f && pos.z <= 150.0f)
			|| (pos.x >= 50.0f && pos.x <= 100.0f && pos.z >= 100.0f && pos.z <= 200.0f))
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		else if (px >= 50.0f && px <= 100.0f && pz >= 100.0f && pz <= 150.0f)
		{
		if ((pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 50.0f && pos.z <= 150.0f) || (pos.x >= 50.0f && pos.x <= 100.0f && pos.z >= 100.0f && pos.z <= 200.0f)
			|| (pos.x >= 100.0f && pos.x <= 150.0f && pos.z >= 150.0f && pos.z <= 200.0f))
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		else if (px >= 50.0f && px <= 100.0f && pz >= 150.0f && pz <= 200.0f)
		{
		if ((pos.x >= 50.0f && pos.x <= 100.0f && pos.z >= 100.0f && pos.z <= 200.0f) || (pos.x >= 100.0f && pos.x <= 200.0f && pos.z >= 150.0f && pos.z <= 200.0f)
			|| (pos.x >= 100.0f && pos.x <= 150.0f && pos.z >= 50.0f && pos.z <= 150.0f))
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		else if (px >= 100.0f && px <= 200.0f && pz >= 150.0f && pz <= 200.0f)
		{
		if ((pos.x >= 50.0f && pos.x <= 100.0f && pos.z >= 100.0f && pos.z <= 150.0f) || (pos.x >= 50.0f && pos.x <= 200.0f && pos.z >= 150.0f && pos.z <= 200.0f))
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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

		//1-2

		//machinery
		else if (px >= 200.0f && px <= 300.0f && pz >= 0.0f && pz <= 200.0f)
		{
		if (pos.x >= 200.0f && pos.x <= 300.0f && pos.z >= 0.0f && pos.z <= 200.0f)
			
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		else if (px >= 300.0f && px <= 400.0f && pz >= 0.0f && pz <= 200.0f)
		{
		if (pos.x >= 300.0f && pos.x <= 400.0f && pos.z >= 0.0f && pos.z <= 200.0f)

		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		//wood
		else if (px >= 400.0f && px <= 470.0f && pz >= 0.0f && pz <= 200.0f)
		{
		if (pos.x >= 390.0f && pos.x <= 490.0f && pos.z >= 0.0f && pos.z <= 200.0f)

		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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
		//pottery
		else if (px >= 470.0f && px <= 600.0f && pz >= 0.0f && pz <= 150.0f)
		{
		if (pos.x >= 450.0f && pos.x <= 600.0f && pos.z >= 0.0f && pos.z <= 150.0f)

		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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

		//conveyor
		else if (px >= 470.0f && px <= 600.0f && pz >= 150.0f && pz <= 200.0f)
		{
		if (pos.x >= 470.0f && pos.x <= 600.0f && pos.z >= 150.0f && pos.z <= 200.0f)

		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
			{

				if (objects[i]->erased == false)
				{
					if (objects[i]->weapon == 1)
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (rangeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (rangeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (rangeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								rangeAttackAnimated = true;
							}
						}
					}
					else
					{
						if (objects[i]->bState.stateID == PATROL_STATE)
						{
							if (meleeWalkAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeWalkAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == CHASE_STATE)
						{
							if (meleeRunAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeRunAnimated = true;
							}
						}
						else if (objects[i]->bState.stateID == BATTLE_STATE)
						{
							if (meleeAttackAnimated == false)
							{
								objects[i]->Animate(elapsed);
								meleeAttackAnimated = true;
							}
						}
					}
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

		else
		{
		if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 100.0f)
		{

			if (objects[i]->erased == false)
			{
				if (objects[i]->weapon == 1)
				{
					if (objects[i]->bState.stateID == PATROL_STATE)
					{
						if (rangeWalkAnimated == false)
						{
							objects[i]->Animate(elapsed);
							rangeWalkAnimated = true;
						}
					}
					else if (objects[i]->bState.stateID == CHASE_STATE)
					{
						if (rangeRunAnimated == false)
						{
							objects[i]->Animate(elapsed);
							rangeRunAnimated = true;
						}
					}
					else if (objects[i]->bState.stateID == BATTLE_STATE)
					{
						if (rangeAttackAnimated == false)
						{
							objects[i]->Animate(elapsed);
							rangeAttackAnimated = true;
						}
					}
				}
				else
				{
					if (objects[i]->bState.stateID == PATROL_STATE)
					{
						if (meleeWalkAnimated == false)
						{
							objects[i]->Animate(elapsed);
							meleeWalkAnimated = true;
						}
					}
					else if (objects[i]->bState.stateID == CHASE_STATE)
					{
						if (meleeRunAnimated == false)
						{
							objects[i]->Animate(elapsed);
							meleeRunAnimated = true;
						}
					}
					else if (objects[i]->bState.stateID == BATTLE_STATE)
					{
						if (meleeAttackAnimated == false)
						{
							objects[i]->Animate(elapsed);
							meleeAttackAnimated = true;
						}
					}
				}
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
	meleeWalkAnimated = false;
	meleeRunAnimated = false;
	meleeAttackAnimated = false;

	rangeWalkAnimated = false;
	rangeRunAnimated = false;
	rangeAttackAnimated = false;
	
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

void EnemyShader::animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float elapsed, vector<XMFLOAT3> ppos, PlayerShader* ps, ParticleShader* part, DyingEnemyShader* die, ID3D12RootSignature* sig)
{

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i]->erased == false)
		{

			// 체력이 막 떨어진 시점에
			if (objects[i]->bState.hp <= 0 && objects[i]->bState.stateID != DEAD_STATE)
			{
				//죽은 것으로 판정하고 죽은 시점 구하기
				objects[i]->bState.stateID = DEAD_STATE;
				objects[i]->stunned = false;
				objects[i]->deathMoment = chrono::system_clock::now();
				objects[i]->erased = true;


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
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[5], true);
					}
					objects[i]->SetTrackAnimationSet(0, 0);
				}
				else
				{
					if (objects[i]->m_pChild != rm->enemyModels[6]->m_pModelRootObject)
					{
						objects[i]->setRoot(rm->enemyModels[6]->m_pModelRootObject, true);
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[6], true);
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

				continue;
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
								else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
								{
									int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
								{
									int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
								else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
								{
									int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
								{
									int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
								else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
								{
									int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
									//ix = (int)((x + 0.25f) / 0.5f);
									//iz = (int)((z + 0.25f) / 0.5f);
									if (objects[i]->heightmap[ix][iz] >= 2.0f)
									{
										found = false;
										break;
									}
								}
								else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
								{
									int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
									int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
				objects[i]->moveByRoute(objects[i]->route, objects);
				//이동 애니메이션으로 변경
				if (objects[i]->weapon == 1)
				{
					if (objects[i]->m_pChild != rm->enemyModels[2]->m_pModelRootObject)
					{
						objects[i]->setRoot(rm->enemyModels[2]->m_pModelRootObject, true);
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[2], true);
						
					}
					objects[i]->SetTrackAnimationSet(0, 0);
				}
				else
				{
					if (objects[i]->m_pChild != rm->enemyModels[9]->m_pModelRootObject)
					{
						objects[i]->setRoot(rm->enemyModels[9]->m_pModelRootObject, true);
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[9], true); 
						
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
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[3], true);
					}
					objects[i]->SetTrackAnimationSet(0, 0);
				}
				else
				{
					if (objects[i]->m_pChild != rm->enemyModels[11]->m_pModelRootObject)
					{
						objects[i]->setRoot(rm->enemyModels[11]->m_pModelRootObject, true);
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[11], true);
					}
					objects[i]->SetTrackAnimationSet(0, 0);
				}

				//2초에 한번 경로 재설정
				chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
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
									else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
										//ix = (int)((x + 0.25f) / 0.5f);
										//iz = (int)((z + 0.25f) / 0.5f);
										if (objects[i]->heightmap[ix][iz] >= 2.0f)
										{
											found = false;
											break;
										}
									}
									else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
									else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
										//ix = (int)((x + 0.25f) / 0.5f);
										//iz = (int)((z + 0.25f) / 0.5f);
										if (objects[i]->heightmap[ix][iz] >= 2.0f)
										{
											found = false;
											break;
										}
									}
									else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
									else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
										//ix = (int)((x + 0.25f) / 0.5f);
										//iz = (int)((z + 0.25f) / 0.5f);
										if (objects[i]->heightmap[ix][iz] >= 2.0f)
										{
											found = false;
											break;
										}
									}
									else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
					objects[i]->moveByRoute(objects[i]->route, objects);
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
								int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
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
								int ix = (int)((x - 200.0f - 0.25f) / 0.5f) + 1;
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
				if (dist >= 20.0f || objects[i]->routeIdx == objects[i]->route.size())
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
									else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
										//ix = (int)((x + 0.25f) / 0.5f);
										//iz = (int)((z + 0.25f) / 0.5f);
										if (objects[i]->heightmap[ix][iz] >= 2.0f)
										{
											found = false;
											break;
										}
									}
									else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
									else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
										//ix = (int)((x + 0.25f) / 0.5f);
										//iz = (int)((z + 0.25f) / 0.5f);
										if (objects[i]->heightmap[ix][iz] >= 2.0f)
										{
											found = false;
											break;
										}
									}
									else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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
									else if (ex >= 800.0f && ex < 900.0f && ez >= 363.0f && ez < 600.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 363.0f - 0.25f) / 0.5f) + 1;
										//ix = (int)((x + 0.25f) / 0.5f);
										//iz = (int)((z + 0.25f) / 0.5f);
										if (objects[i]->heightmap[ix][iz] >= 2.0f)
										{
											found = false;
											break;
										}
									}
									else if (ex >= 800.0f && ex < 900.0f && ez >= 60.0f && ez < 363.0f)
									{
										int ix = (int)((x - 800.0f - 0.25f) / 0.5f) + 1;
										int iz = (int)((z - 60.0f - 0.25f) / 0.5f) + 1;
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

				//i//f (dt > 2.0f)
				//{
				//	objects[i]->SetMesh(NULL);
				//}

				//1초, 즉 죽는 애니메이션의 재생 시간이 지나면 해당 적 삭제.

				CGameObject* tmp = new CGameObject(1);




				tmp->SetPosition(objects[i]->GetPosition());
				objects[i]->SetPosition(-100.0f, -100.0f, -100.0f);
				if (objects[i]->attackTarget != -1)
				{
					XMFLOAT3 toPlayer = Vector3::Subtract(ps->objects[objects[i]->attackTarget]->GetPosition(), objects[i]->GetPosition());
					XMFLOAT3 ntp = Vector3::Normalize(toPlayer);
					float angle = atan2f(ntp.x, ntp.z);
					angle = angle / 3.141592f * 180.0f;
					if (angle >= 360.0f)
						angle -= 360.0f;

					tmp->Rotate(0.0f, angle, 0.0f);
				}





				tmp->SetMaterial(0, rm->materials[2]);
				if (objects[i]->weapon == 1)
				{
					die->type.push_back(1);
					tmp->SetMesh(die->enemyGunDie[0]);
				}
				else if (objects[i]->weapon == 2)
				{
					die->type.push_back(2);
					tmp->SetMesh(die->enemyBluntDie[0]);
				}
				die->objects.push_back(tmp);
				chrono::time_point<chrono::system_clock> m = chrono::system_clock::now();
				die->created.push_back(m);

			}

			else if (objects[i]->bState.stateID == BATTLE_STATE)
			{
				//공격하는 애니메이션으로 변경
				if (objects[i]->weapon == 1)
				{
					if (objects[i]->m_pChild != rm->enemyModels[4]->m_pModelRootObject)
					{
						objects[i]->setRoot(rm->enemyModels[4]->m_pModelRootObject, true);
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[4], true);
					}
					objects[i]->SetTrackAnimationSet(0, 0);
				}
				else
				{
					if (objects[i]->m_pChild != rm->enemyModels[7]->m_pModelRootObject)
					{
						objects[i]->setRoot(rm->enemyModels[7]->m_pModelRootObject, true);
						objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[7], true);
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
						p1.pos = ppos[objects[i]->chaseTarget].x + 0.3f;
						p1.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						checkList.push_back(p1);

						p2.pos = ppos[objects[i]->chaseTarget].x - 0.3f;
						p2.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						checkList.push_back(p2);

						p3.pos = ppos[objects[i]->chaseTarget].z - 0.3f;
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

						XMFLOAT3 tp = XMFLOAT3(targetPos.x - objects[i]->GetPosition().x, 0.0f, targetPos.z - objects[i]->GetPosition().z);

						XMFLOAT3 np = Vector3::Normalize(tp);
						part->createParticles(1, 100, targetPos, pd3dDevice, pd3dCommandList, np.x,np.y);
						ps->objects[objects[i]->chaseTarget]->info->stats.capacity -= 1;

						if (objects[i]->weapon == 1)
						{
							rm->effect[1]->play();
							rm->effect[1]->Update();
						}
						else
						{
							rm->effect[4]->play();
							rm->effect[4]->Update();
						}

						objects[i]->lastAttack = chrono::system_clock::now();
					}
				}
			}
		}


		objects[i]->lastMove = chrono::system_clock::now();
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