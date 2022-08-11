#include "DropItemShader.h"

/*
--	1-1 ��⹰ ó���忡 �ִ� ��ü�鸸 ����ϴ� ���̴� �ڵ�.
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

			//�������̰ų� ��ü�� ī�޶�� 10���� �̳��� ��� �׳� �׸�.



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
	obj->SetPosition(pos);
	obj->Rotate(0.0f, 0.0f, 0.0f);

	objects.push_back(obj);
	
	rotation.push_back(0.0f);
}
void DropItemShader::animate(PlayerShader* ps)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		//��� �������� ȸ������ ����
		rotation[i] += 1.0f;
		if (rotation[i] >= 360.0f)
		{
			rotation[i] -= 360.0f;
		}
		objects[i]->Rotate(0.0f, rotation[i], 0.0f);


		//��� �÷��̾ ����
		for (int p = 0; p < ps->objects.size(); ++p)
		{
			XMFLOAT3 pp = ps->objects[p]->GetPosition();

			XMFLOAT3 ip = objects[i]->GetPosition();

			float dx = pp.x - ip.x;
			float dz = pp.z - ip.z;
			float dst = sqrt((dx * dx) + (dz * dz));
			//�÷��̾�� �������� �Ÿ��� ����������
			if (dst < 0.5f && pp.y < 0.5f)
			{
				//ȿ�� ����
				if (type[i] == 1)
				{
					ps->objects[p]->info->stats.capacity += ps->objects[p]->info->stats.maxhp / 5;
					if (ps->objects[p]->info->stats.capacity > ps->objects[p]->info->stats.maxhp)
					{
						ps->objects[p]->info->stats.capacity = ps->objects[p]->info->stats.maxhp;
					}
				}
				//������ ����
				objects.erase(objects.begin() + i);
				type.erase(type.begin() + i);
				rotation.erase(rotation.begin() + i);
			}
		}
	}
}