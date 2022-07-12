#include "BoomShader.h"

/*
--	1-1 ��⹰ ó���忡 �ִ� ��ü�鸸 ����ϴ� ���̴� �ڵ�.
--
--
*/


BoomShader::BoomShader(ResourceManager* r, ParticleShader* p, EnemyShader* e)
{
	rm = r;
	part = p;
	enemy = e;
}
BoomShader::~BoomShader() {}

void BoomShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	boomMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/vtx_boom.txt", NULL);
}





void BoomShader::ReleaseObjects()
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
void BoomShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void BoomShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void BoomShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

			
			//���� �ƴϰų� �Ÿ��� 10���� �̻� �� ��� ������ ����Ͽ� �׸��� ���� �Ǵ�.
			if ((dist <= 10.0f) || (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f)))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->SetMesh(boomMesh);
				objects[i]->Render(pd3dCommandList, pCamera);
			}

		}
	}

	
}

D3D12_INPUT_LAYOUT_DESC BoomShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC BoomShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE BoomShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE BoomShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void BoomShader::animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ParticleShader* part)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		bool erased = false;
		chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
		chrono::duration<double> dt = moment - objects[i]->created;

		//�������� 1�ʰ� �����ų�, �׻��̿� ��ü Ȥ�� ������ ���� ��� ��ü ����.

		if ((float)dt.count() >= 1.0f)
		{
			part->createParticles(100, objects[i]->GetPosition(), pd3dDevice, pd3dCommandList);
			delete objects[i];
			objects.erase(objects.begin() + i);
			erased = true;
			
		}
		else
		{
			

			float tx = objects[i]->origin.x + objects[i]->direction.x * objects[i]->speed * (float)dt.count();
			float tz = objects[i]->origin.z + objects[i]->direction.z * objects[i]->speed * (float)dt.count();
			int ix = (int)(tx / 0.5f);
			int iz = (int)(tz / 0.5f);

			//���̸ʿ����� ���̰� �� �������, �� ��ü ���鿡 �浹�� ���
			if (enemy->height11[ix][iz] >= objects[i]->origin.y)
			{
				part->createParticles(100, objects[i]->GetPosition(), pd3dDevice, pd3dCommandList);
				delete objects[i];
				objects.erase(objects.begin() + i);
				erased = true;
			}

			//��ü���� �浹���� �ʾ����� ���� ���� ���
			else
			{
				
				for (int i = 0; i < enemy->objects.size(); ++i)
				{
					XMFLOAT3 pos = objects[i]->GetPosition();
					//������ �Ÿ��� xz��鿡�� 0.6���� �̳��̰�, y��ǥ�� ���� y���� ���� �ִ� ���, �� ���� �΋Hģ ���
					XMFLOAT3 ep = enemy->objects[i]->GetPosition();
					XMFLOAT3 dst = XMFLOAT3(ep.x - pos.x, 0.0f, ep.z - pos.z);
					if (Vector3::Length(dst) <= 0.6f && (pos.y > ep.y && pos.y < ep.y + 1.7f))
					{
						//�����ϰ�, ���� ü�� ����
						enemy->objects[i]->bState.hp -= 10;
						part->createParticles(100, pos, pd3dDevice, pd3dCommandList);
						delete objects[i];
						objects.erase(objects.begin() + i);

						erased = true;
						break;
					}
				}
				
				
			}
		}
		if (erased == true)
		{
			continue;
		}
		else
		{
			//������� ���� �浹���� �ʾҴٴ� ���̹Ƿ� �̵�.

			XMFLOAT3 pos = objects[i]->GetPosition();

			chrono::time_point<chrono::system_clock> mom = chrono::system_clock::now();
			chrono::duration<double> dt2 = mom - objects[i]->lastMove;


			float tx = pos.x + objects[i]->direction.x * objects[i]->speed * (float)dt2.count();
			float tz = pos.z + objects[i]->direction.z * objects[i]->speed * (float)dt2.count();

			objects[i]->SetPosition(tx, pos.y, tz);
			objects[i]->lastMove = chrono::system_clock::now();
		}
	}
}