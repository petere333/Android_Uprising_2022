#include "DropItemShader.h"

/*
--	1-1 폐기물 처리장에 있는 물체들만 담당하는 쉐이더 코드.
--
--
*/


DropItemShader::DropItemShader(ResourceManager* r)
{
	rm = r;
}
DropItemShader::~DropItemShader() {}

void DropItemShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	capacity = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/item/vtx_capacity.txt", NULL);
	hard = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/item/vtx_hard.txt", NULL);
	power = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/item/vtx_power.txt", NULL);
	precision = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/item/vtx_precision.txt", NULL);
	booster = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/item/vtx_fast.txt", NULL);
}





void DropItemShader::ReleaseObjects()
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
void DropItemShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void DropItemShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void DropItemShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	XMFLOAT3 cp = pCamera->getPosition();

	XMFLOAT3 look = pCamera->getLook();



	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			XMFLOAT3 pos = objects[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			//벽종류이거나 객체가 카메라와 10미터 이내인 경우 그냥 그림.



			if (dist <= 10.0f)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			}
	}
	

	
}

D3D12_INPUT_LAYOUT_DESC DropItemShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC DropItemShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE DropItemShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE DropItemShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}


void DropItemShader::addItem(int t, XMFLOAT3 pos)
{
	CGameObject* obj = new CGameObject(1);
	if (t == 1)
	{
		obj->SetMaterial(0, rm->materials[396]);
		obj->SetMesh(capacity);
		type.push_back(1);
	}
	else if (t == 2)//hard
	{
		obj->SetMaterial(0, rm->materials[398]);
		obj->SetMesh(hard);
		type.push_back(2);
	}
	else if (t == 3)//power
	{
		obj->SetMaterial(0, rm->materials[399]);
		obj->SetMesh(power);
		type.push_back(3);
	}

	else if (t == 4)//precision
	{
		obj->SetMaterial(0, rm->materials[400]);
		obj->SetMesh(precision);
		type.push_back(4);
	}
	else if (t == 5)//precision
	{
		obj->SetMaterial(0, rm->materials[397]);
		obj->SetMesh(booster);
		type.push_back(5);
	}

	obj->SetPosition(pos);
	obj->Rotate(0.0f, 0.0f, 0.0f);

	objects.push_back(obj);
	
	rotation.push_back(0.0f);
}
void DropItemShader::animate(PlayerShader* ps)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		//모든 아이템의 회전각도 증가
		rotation[i] += 1.0f;
		if (rotation[i] >= 360.0f)
		{
			rotation[i] -= 360.0f;
		}
		objects[i]->Rotate(0.0f, rotation[i], 0.0f);


		//모든 플레이어에 대해
		for (int p = 0; p < ps->objects.size(); ++p)
		{
			XMFLOAT3 pp = ps->objects[p]->GetPosition();

			XMFLOAT3 ip = objects[i]->GetPosition();

			float dx = pp.x - ip.x;
			float dz = pp.z - ip.z;
			float dst = sqrt((dx * dx) + (dz * dz));
			//플레이어와 아이템의 거리가 가까워진경우
			if (dst < 1.2f && pp.y < 1.2f)
			{
				//효과 적용

				//체력포션
				if (type[i] == 1)
				{
					ps->objects[p]->info->stats.capacity += ps->objects[p]->info->stats.maxhp / 5;
					if (ps->objects[p]->info->stats.capacity > ps->objects[p]->info->stats.maxhp)
					{
						ps->objects[p]->info->stats.capacity = ps->objects[p]->info->stats.maxhp;
					}
				}

				//경도포션
				else if (type[i] == 2)
				{
					ps->objects[p]->info->stats.hardness += ps->objects[p]->info->stats.hardness / 5;
				}
				//출력포션
				else if (type[i] == 3)
				{
					ps->objects[p]->info->stats.power += ps->objects[p]->info->stats.power / 5;
				}
				//정밀도포션
				else if (type[i] == 4)
				{
					ps->objects[p]->info->stats.precision += ps->objects[p]->info->stats.precision / 5;
				}
				//이속버프
				else if (type[i] == 5)
				{
					ps->objects[p]->lastBoost = chrono::system_clock::now();
					ps->objects[p]->notYetBoosted = false;
				}
				//아이템 제거
				objects.erase(objects.begin() + i);
				type.erase(type.begin() + i);
				rotation.erase(rotation.begin() + i);
			}
		}
	}
}