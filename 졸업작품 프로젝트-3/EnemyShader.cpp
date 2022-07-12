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
	{
		EnemyObject* obj = new EnemyObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1, height11, 0.0f, 0.0f);
		obj->SetPosition(12.0f, 0.0f, 165.0f);
		obj->origin = XMFLOAT3(12.0f, 0.0f, 165.0f);
		obj->seekPoint.push_back(XMFLOAT2(12.0f, 164.5f));
		obj->seekPoint.push_back(XMFLOAT2(22.0f, 164.5f));
		obj->type = -10;
		obj->SetTrackAnimationSet(0, 0);
		obj->attackRange = 2.0f;
		obj->bState.stateID = IDLE_STATE;
		obj->bState.hp = 20;
		obj->maxHP = 20;
		obj->lastAttack = chrono::system_clock::now();
		obj->attackDuration = 0.2f;

		objects.push_back(obj);

	




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

		if ((px >= 0.0f && px <= 400.0f && pz >= 0.0f && pz <= 200.0f) &&
			(ex >= 0.0f && ex <= 400.0f && ez >= 0.0f && ez <= 200.0f))//1-1
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 250.0f)
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


		else if ((px >= 0.0f && px <= 200.0f && pz >= 200.0f && pz <= 600.0f) &&
			(ex >= 0.0f && ex <= 200.0f && ez >= 200.0f && ez <= 600.0f))//1-2
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 250.0f)
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

		else if ((px >= 280.0f && px <= 400.0f && pz >= 200.0f && pz <= 600.0f) &&
			(ex >= 280.0f && ex <= 400.0f && ez >= 200.0f && ez <= 600.0f))//1-3
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 250.0f)
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

		else if ((px >= 400.0f && px <= 600.0f && pz >= 0.0f && pz <= 600.0f) &&
			(ex >= 400.0f && ex <= 600.0f && ez >= 0.0f && ez <= 600.0f))//1-4
		{
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(50.0f)) && dist <= 250.0f)
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
		// 체력이 막 떨어진 시점에
		if (objects[i]->bState.hp <= 0 && objects[i]->bState.stateID != DEAD_STATE)
		{
			//죽은 것으로 판정하고 죽은 시점 구하기
			objects[i]->bState.stateID = DEAD_STATE;
			objects[i]->deathMoment = chrono::system_clock::now();

			//애니메이션도 죽는 것으로 변경
			if (objects[i]->m_pChild != rm->enemyModels[1]->m_pModelRootObject)
			{
				objects[i]->setRoot(rm->enemyModels[1]->m_pModelRootObject, true);
				objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[1]);
			}
			objects[i]->SetTrackAnimationSet(0, 0);
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
				if (dist > 30.0f)
				{
					continue;
				}
				if (ex < px)
				{
					for (float x = ex; x < px; x += 0.5f)
					{
						float z = ez + nz / nx * 0.5f;

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
						float z = ez - nz / nx * 0.5f;
						int ix = (int)((x - 0.25f) / 0.5f) + 1;
						int iz = (int)((z - 0.25f) / 0.5f) + 1;

						
						if (objects[i]->heightmap[ix][iz] >= 2.0f)
						{
							found = false;
							break;
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

			// 현재 가고자 하는 곳까지 경로 계산
			if ((objects[i]->routeIdx == objects[i]->route.size()) || (objects[i]->route.size() == 0))
			{
				objects[i]->currentPoint += 1;
				if (objects[i]->currentPoint == objects[i]->seekPoint.size())
					objects[i]->currentPoint = 0;
				objects[i]->route = objects[i]->NavigateMovement(objects[i]->seekPoint[objects[i]->currentPoint].x, objects[i]->seekPoint[objects[i]->currentPoint].y);
				objects[i]->routeIdx = 0;

			}
			objects[i]->moveByRoute(objects[i]->route);
			//이동 애니메이션으로 변경
			if (objects[i]->m_pChild != rm->enemyModels[2]->m_pModelRootObject)
			{
				objects[i]->setRoot(rm->enemyModels[2]->m_pModelRootObject, true);
				objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[2]);
			}
			objects[i]->SetTrackAnimationSet(0, 0);

			

		}

		else if (objects[i]->bState.stateID == CHASE_STATE)
		{
			//빠르게 이동하는 애니메이션으로 변경
			if (objects[i]->m_pChild != rm->enemyModels[3]->m_pModelRootObject)
			{
				objects[i]->setRoot(rm->enemyModels[3]->m_pModelRootObject, true);
				objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[3]);
			}
			objects[i]->SetTrackAnimationSet(0, 0);


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
						float z = ez + nz / nx * 0.5f;

						int ix = (int)((x - 0.25f) / 0.5f) + 1;
						int iz = (int)((z - 0.25f) / 0.5f) + 1;

						if (objects[i]->heightmap[ix][iz] >= 2.0f)
						{
							found = false;
							break;
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
						float z = ez - nz / nx * 0.5f;
						int ix = (int)((x - 0.25f) / 0.5f) + 1;
						int iz = (int)((z - 0.25f) / 0.5f) + 1;
						if (objects[i]->heightmap[ix][iz] >= 1.0f)
						{
							found = false;
							break;
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
			if (dist >= 30.0f || objects[i]->routeIdx==objects[i]->route.size())
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
					//30미터 너머의 적은 봐도 못본 것으로 처리
					if (dist > 30.0f)
					{
						objects[i]->chaseTarget = -1;
						objects[i]->attackTarget = -1;
						objects[i]->bState.stateID = PATROL_STATE;
						continue;
					}
					if (ex < px)
					{
						for (float x = ex; x < px; x += 0.5f)
						{
							float z = ez + nz / nx * 0.5f;

							int ix = (int)((x-0.25f) / 0.5f)+1;
							int iz = (int)((z-0.25f) / 0.5f)+1;
							
							if (objects[i]->heightmap[ix][iz] >= 2.0f)
							{
								found = false;
								break;
							}
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
							float z = ez - nz / nx * 0.5f;
							int ix = (int)((x - 0.25f) / 0.5f) + 1;
							int iz = (int)((z - 0.25f) / 0.5f) + 1;
							
							if (objects[i]->heightmap[ix][iz] >= 2.0f)
							{
								found = false;
								break;
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

			//1초, 즉 죽는 애니메이션의 재생 시간이 지나면 해당 적 삭제.
			if (dt >= 1.0f)
			{
				delete objects[i];
				objects.erase(objects.begin() + i);
			}
		}

		else if (objects[i]->bState.stateID == BATTLE_STATE)
		{
			//공격하는 애니메이션으로 변경
			if (objects[i]->m_pChild != rm->enemyModels[4]->m_pModelRootObject)
			{
				objects[i]->setRoot(rm->enemyModels[4]->m_pModelRootObject, true);
				objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[4]);
			}
			objects[i]->SetTrackAnimationSet(0, 0);
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