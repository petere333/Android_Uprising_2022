#include "DyingEnemyShader.h"

/*
--	1-1 폐기물 처리장에 있는 물체들만 담당하는 쉐이더 코드.
--
--
*/


DyingEnemyShader::DyingEnemyShader(ResourceManager* r)
{
	rm = r;
}
DyingEnemyShader::~DyingEnemyShader() {}

void DyingEnemyShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

}

void DyingEnemyShader::animate()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
		chrono::duration<double> dt = moment - created[i];
		float d = (float)dt.count();
		if (d < 1.0f)
		{
			int animIdx = (int)(d * 10.0);
			objects[i]->SetMesh(rm->enemyBluntDie[animIdx]);
			if (objects[i]->m_ppMaterials == NULL)
			{
				objects[i]->m_ppMaterials = new CMaterial * [1];
				objects[i]->m_nMaterials = 1;
			}

			objects[i]->m_ppMaterials[0] = rm->materials[2];
		}
		else if (d >= 1.0f && d < 2.0f)
		{
			objects[i]->SetMesh(rm->enemyBluntDie[9]);
			objects[i]->m_ppMaterials[0] = rm->materials[2];
		}
		else if (d >= 2.0f)
		{
			
			objects.erase(objects.begin() + i);
			created.erase(created.begin() + i);
		}
	}
}



void DyingEnemyShader::ReleaseObjects()
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
void DyingEnemyShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void DyingEnemyShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void DyingEnemyShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

			if ((objects[i]->type >= 11000 && objects[i]->type < 11200))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			//벽이 아니거나 거리가 10미터 이상 멀 경우 각도를 고려하여 그릴지 말지 판단.
			else
			{
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

	for (int i = 0; i < shadows.size(); ++i)
	{
		if (shadows[i])
		{
			XMFLOAT3 pos = shadows[i]->GetPosition();
			XMFLOAT3 direction = XMFLOAT3(pos.x - cp.x, pos.y - cp.y, pos.z - cp.z);
			float dist = Vector3::Length(direction);
			XMFLOAT3 dir = Vector3::Normalize(direction);
			float cosAngle = Vector3::DotProduct(look, dir);

			//그림자의 위치가 카메라로부터 10미터 이내이거나, 카메라 방향으로부터 70도 이내에 있는 경우에만 그림
			if (dist <= 10.0f)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				shadows[i]->Render(pd3dCommandList, pCamera);
			}
			else if (cosAngle <= 1.0f && cosAngle >= cos(3.141592f / 180.0f * 70.0f))
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				shadows[i]->Render(pd3dCommandList, pCamera);
			}
		}
	}
}

D3D12_INPUT_LAYOUT_DESC DyingEnemyShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC DyingEnemyShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE DyingEnemyShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE DyingEnemyShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}