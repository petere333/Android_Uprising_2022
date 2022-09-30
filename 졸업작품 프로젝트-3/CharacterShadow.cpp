#include "CharacterShadow.h"

/*
--	1-1 폐기물 처리장에 있는 물체들만 담당하는 쉐이더 코드.
--
--
*/


CharShadow::CharShadow(ResourceManager* r)
{
	rm = r;
}
CharShadow::~CharShadow() {}

void CharShadow::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	mesh = new RectMesh(pd3dDevice, pd3dCommandList, 1.1f, 1.1f);
	mBlunt = new RectMesh(pd3dDevice, pd3dCommandList, 1.2f, 1.6f);
	mBazuka = new RectMesh(pd3dDevice, pd3dCommandList, 1.25f, 1.45f);

	mIdle= new RectMesh(pd3dDevice, pd3dCommandList, 0.95f, 0.95f);
	mRadioIdle = new RectMesh(pd3dDevice, pd3dCommandList, 0.95f, 0.35f);

}





void CharShadow::ReleaseObjects()
{


}
void CharShadow::ReleaseUploadBuffers()
{

}
void CharShadow::ReleaseShaderVariables()
{

}

void CharShadow::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	XMFLOAT3 cp = pCamera->getPosition();

	XMFLOAT3 look = pCamera->getLook();



	for (int i = 0; i < op.size(); ++i)
	{

			XMFLOAT3 pos = op[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			//벽종류이거나 객체가 카메라와 10미터 이내인 경우 그냥 그림.

		
			//벽이 아니거나 거리가 10미터 이상 멀 경우 각도를 고려하여 그릴지 말지 판단.

			if (dist <= 10.0f)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				op[i]->Render(pd3dCommandList, pCamera);
			}
			else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				op[i]->Render(pd3dCommandList, pCamera);
			}
			
		
	}
	for (int i = 0; i < oe.size(); ++i)
	{

		XMFLOAT3 pos = oe[i]->GetPosition();
		XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
		float dist = Vector3::Length(direction);
		XMFLOAT3 dir = Vector3::Normalize(direction);
		float cosAngle = Vector3::DotProduct(look, dir);

		//벽종류이거나 객체가 카메라와 10미터 이내인 경우 그냥 그림.


		//벽이 아니거나 거리가 10미터 이상 멀 경우 각도를 고려하여 그릴지 말지 판단.

		if (dist <= 10.0f)
		{
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			oe[i]->Render(pd3dCommandList, pCamera);
		}
		else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
		{
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			oe[i]->Render(pd3dCommandList, pCamera);
		}


	}
	
}

void CharShadow::animate(PlayerShader* ps, EnemyShader* es, int stage)
{
	pp.clear();
	ep.clear();
	pRot.clear();
	eRot.clear();

	pElapsed.clear();

	op.clear();
	oe.clear();

	


	for (int i = 0; i < ps->objects.size(); ++i)
	{
		pp.push_back(ps->objects[i]->GetPosition());
		pRot.push_back(ps->objects[i]->kState.rotation);
		
	}


	for (int i = 0; i < es->currentObject.size(); ++i)
	{
		ep.push_back(es->currentObject[i]->GetPosition());

		eRot.push_back(es->currentObject[i]->rot);
		erased.push_back(es->currentObject[i]->erased);
	}
	

	if (op.size() != pp.size())//초기화가 안된경우 초기화
	{
		op.clear();
		for (int i = 0; i < pp.size(); ++i)
		{
			CGameObject* o = new CGameObject(1);

			o->SetMesh(mesh);
			

			o->SetPosition(pp[i].x, 0.0f, pp[i].z);
			
			if (pp[i].x >= 250.0f && pp[i].x <= 350.0f && pp[i].z >= 0.0f && pp[i].z <= 50.0f)
			{
				o->SetPosition(pp[i].x, 5.0f , pp[i].z);
			}
			o->Rotate(0.0f, pRot[i]+270.0f, 0.0f);
			

			std::chrono::duration<double> dt = chrono::system_clock::now() - ps->objects[i]->lastAttack;
			std::chrono::duration<double> dt2 = chrono::system_clock::now() - ps->objects[i]->lastWave;

			if (dt.count()<0.833333 && ps->objects[i]->bState.attackID == TYPE_MELEE && ps->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
			{
				if (ps->objects[i]->atttype == 1)
				{
					o->SetMesh(mIdle);
					int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 15;
					o->m_ppMaterials[0] = rm->materials[580+f];
				}
				else
				{
					o->SetMesh(mIdle);
					int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 15;
					o->m_ppMaterials[0] = rm->materials[595 + f];
				}
			}
			else if (dt.count() < 0.833333 && ps->objects[i]->bState.attackID == TYPE_MELEE && ps->objects[i]->info->slot.meleeWeapon->type == BLUNT)
			{
				if (ps->objects[i]->atttype == 1)
				{
					o->SetMesh(mIdle);
					int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 15;
					o->m_ppMaterials[0] = rm->materials[580 + f];
				}
				else
				{
					o->SetMesh(mIdle);
					int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 15;
					o->m_ppMaterials[0] = rm->materials[595 + f];
				}
			}
			else if (dt.count() < 0.2 && ps->objects[i]->bState.attackID == TYPE_RANGED && ps->objects[i]->info->slot.rangedWeapon->type == RIFLE)
			{
				o->SetMesh(mIdle);
				o->m_ppMaterials[0] = rm->materials[611];
			}
			else if (dt2.count() <= 1.0 && ps->objects[i]->bState.attackID == TYPE_MICROWAVE)
			{
				o->SetMesh(mRadioIdle);
				o->m_ppMaterials[0] = rm->materials[627];
			}

			else
			{
				if (ps->objects[i]->bState.stateID == MOVE_STATE || ps->objects[i]->bState.stateID == JUMP_STATE)
				{
					if (ps->objects[i]->bState.attackID == TYPE_RANGED)
					{
						if (ps->objects[i]->info->slot.rangedWeapon->type == RIFLE)
						{
							int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 20;
							o->m_ppMaterials[0] = rm->materials[402 + f];
						}
						else if (ps->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
						{
							o->SetMesh(mBazuka);
							int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 20;
							o->m_ppMaterials[0] = rm->materials[422 + f];
						}
					}
					else if (ps->objects[i]->bState.attackID == TYPE_MELEE)
					{
						if (ps->objects[i]->info->slot.meleeWeapon->type == BLUNT)
						{
							o->SetMesh(mBlunt);

							float rd = XMConvertToRadians(ps->objects[i]->kState.rotation - 45.0f);
							XMFLOAT3 dir = XMFLOAT3(cos(rd), 0.0f, sin(rd));


							o->SetPosition(pp[i].x - dir.x * 0.1f, 0.0f, pp[i].z - dir.z * 0.1f);

							if (pp[i].x >= 250.0f && pp[i].x <= 350.0f && pp[i].z >= 0.0f && pp[i].z <= 50.0f)
							{
								o->SetPosition(pp[i].x - dir.x * 0.1f, 5.0f, pp[i].z - dir.z * 0.1f);
							}

							int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 20;
							o->m_ppMaterials[0] = rm->materials[462 + f];
						}
						else if (ps->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
						{
							int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (2.0f / 30.0f)) % 20;
							o->m_ppMaterials[0] = rm->materials[442 + f];
						}
					}
					else if (ps->objects[i]->bState.attackID == TYPE_MICROWAVE)
					{
						int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 20;
						o->m_ppMaterials[0] = rm->materials[482 + f];
					}
				}

				else if (ps->objects[i]->bState.stateID == IDLE_STATE)
				{

					if (ps->objects[i]->bState.attackID == TYPE_RANGED)
					{
						if (ps->objects[i]->info->slot.rangedWeapon->type == RIFLE)
						{
							o->SetMesh(mIdle);
							o->m_ppMaterials[0] = rm->materials[610];
						}
						else if (ps->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
						{
							o->SetMesh(mIdle);
							o->m_ppMaterials[0] = rm->materials[502];
						}
					}
					else if (ps->objects[i]->bState.attackID == TYPE_MELEE)
					{
						if (ps->objects[i]->info->slot.meleeWeapon->type == BLUNT)
						{
							o->SetMesh(mIdle);
							o->m_ppMaterials[0] = rm->materials[395];
						}
						else if (ps->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
						{
							o->SetMesh(mIdle);
							int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (4.0f / 30.0f)) % 15;
							o->m_ppMaterials[0] = rm->materials[f + 565];
						}
					}
					else if (ps->objects[i]->bState.attackID == TYPE_MICROWAVE)
					{
						o->SetMesh(mRadioIdle);
						int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (4.0f / 30.0f)) % 15;
						o->m_ppMaterials[0] = rm->materials[f+612];
					}
				}

				else
				{
					o->m_ppMaterials[0] = rm->materials[395];
				}
			}
			op.push_back(o);
		}
	}
	else//초기화 된경우 위치, 회전만 변경
	{
		for (int i = 0; i < pp.size(); ++i)
		{
			op[i]->SetPosition(pp[i].x , 0.0f, pp[i].z);
			if (pp[i].x >= 250.0f && pp[i].x <= 350.0f && pp[i].z >= 0.0f && pp[i].z <= 50.0f)
			{
				op[i]->SetPosition(pp[i].x, 5.0f, pp[i].z);
			}

			op[i]->Rotate(0.0f, pRot[i]+270.0f, 0.0f);
			if (ps->objects[i]->bState.stateID == MOVE_STATE && ps->objects[i]->info->slot.rangedWeapon->type == RIFLE && ps->objects[i]->bState.attackID == TYPE_RANGED)
			{
				int f = (int)(ps->objects[i]->m_pSkinnedAnimationController->m_fTime / (4.0f / 30.0f)) % 20;
				if (f >= 0 && f < 4)
				{
					op[i]->m_ppMaterials[0] = rm->materials[402];
				}
				else if (f >= 4 && f < 8)
				{
					op[i]->m_ppMaterials[0] = rm->materials[403];
				}
				else if (f >= 8 && f < 12)
				{
					op[i]->m_ppMaterials[0] = rm->materials[404];
				}
				else if (f >= 12 && f < 16)
				{
					op[i]->m_ppMaterials[0] = rm->materials[405];
				}
				else if (f >= 16 && f < 20)
				{
					op[i]->m_ppMaterials[0] = rm->materials[406];
				}
			}
			else
			{
				op[i]->m_ppMaterials[0] = rm->materials[395];
			}

		}
	}
	if (oe.size() != ep.size())
	{
		oe.clear();
		for (int i = 0; i < ep.size(); ++i)
		{
			CGameObject* o = new CGameObject(1);

			o->SetMesh(mesh);
			o->SetMaterial(0, rm->materials[395]);
			o->SetPosition(ep[i].x , 0.0f, ep[i].z);
			o->Rotate(0.0f, XMConvertToDegrees(eRot[i]), 0.0f);
			if (es->currentObject[i]->bState.stateID == CHASE_STATE)
			{
				if (es->currentObject[i]->weapon == 2)
				{
					int f = (int)(es->currentObject[i]->m_pSkinnedAnimationController->m_fTime / (2.0f / 30.0f)) % 20;
					o->m_ppMaterials[0] = rm->materials[f + 530];
				}
				
			}
			else if (es->currentObject[i]->bState.stateID == BATTLE_STATE)
			{
				if (es->currentObject[i]->weapon == 2)
				{
					int f = (int)(es->currentObject[i]->m_pSkinnedAnimationController->m_fTime / (1.0f / 30.0f)) % 24;
					o->m_ppMaterials[0] = rm->materials[f + 505];
				}
			}


			oe.push_back(o);



		}
	}
	else
	{
		for (int i = 0; i < ep.size(); ++i)
		{
			if (erased[i] == false)
			{
				oe[i]->SetPosition(ep[i].x , 0.0f, ep[i].z);
			}
		}
	}
}


D3D12_INPUT_LAYOUT_DESC CharShadow::CreateInputLayout()
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

D3D12_RASTERIZER_DESC CharShadow::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE CharShadow::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE CharShadow::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}