#include "ShadowShader.h"

ShadowShader::ShadowShader(ResourceManager* r)
{
	rm = r;
}
ShadowShader::~ShadowShader() {}

void ShadowShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/objects.txt");
	boxesWorld = LoadBoxes("res/map/box.txt", &nBox);
	stairsWorld = LoadStairs("res/map/stair.txt", &nStairs);

	CGameObject* obj;

	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i].type == Janhae6)
		{
			obj = new CGameObject(1);
			RectMesh* mesh = new RectMesh(pd3dDevice, pd3dCommandList, boxesWorld[i].end.x - boxesWorld[i].start.x, boxesWorld[i].end.z - boxesWorld[i].start.z);
			obj->SetMesh(mesh);
			obj->SetMaterial(0, rm->materials[74]);

			obj->type = -data[i].type;
			float randomY = (float)(rand() % 10000) / 10000.0f / 50.0f;

			obj->SetPosition(data[i].position.x+0.5f, 0.0f + randomY, data[i].position.z);
			obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
			objects.push_back(obj);
		}

	}
}
void ShadowShader::ReleaseObjects()
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
void ShadowShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void ShadowShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void ShadowShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		XMFLOAT3 pos = objects[i]->GetPosition();
		XMFLOAT3 camPos = pCamera->getPosition();

		XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);
		XMFLOAT3 look = pCamera->getLook();
		float px = camPos.x;
		float pz = camPos.z;
		float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

		float dist = Vector3::Length(fromCamera);
		/*
		//	1. 객체의 유형이 벽인 경우 그냥 그린다.
		//	2. 객체의 유형이 xyz 크기가 3m 이상인 대형 물체인 경우 카메라의 방향 벡터로부터 양쪽 70도 내에 있는 경우에만 그린다.
		//	3. 객체의 유형이 소형 물체, 혹은 움직이는 캐릭터인 경우 양쪽 55도 내에 있는 경우에만 그린다.
		*/
		int tp = objects[i]->type;

		float ox = objects[i]->GetPosition().x;
		float oz = objects[i]->GetPosition().z;


		if (-tp >= 30000 && -tp != Heaters1)
		{
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			objects[i]->Render(pd3dCommandList, pCamera);
			continue;
		}

		//1구역
		if ((px >= 0.0f && px <= 600.0f) && (pz >= 0.0f && pz <= 600.0f))
		{
			if (-tp >= 10000 && -tp < 11000)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
				continue;
			}
			if (px >= 0.0f && px <= 400.0f && pz >= 0.0f && pz <= 200.0f)//1-1
			{
				if ((-tp >= 11000 && -tp < 11200) || (-tp == Wallz6 || -tp == Wallz7) || (-tp == Janhae2) || (-tp >= 14140 && -tp <= 14146))
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
					continue;
				}
				else if ((-tp >= 11200 && -tp < 11900) || (-tp == Heaters1) || (-tp >= 14126 && -tp <= 14130) || (-tp == Janhae10))
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist < 300.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(110.0f)) && dist < 10.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
				}
			}

			if (px >= 0.0f && px <= 200.0f && pz >= 200.0f && pz <= 600.0f)//1-2
			{
				if ((-tp >= 12000 && -tp < 12200) || (-tp == GyeDans1 || -tp == GyeDans2 || -tp == R_GyeDan1 || -tp == Stairs1))
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
					continue;
				}
				else if ((-tp >= 12200 && -tp < 13000) || (-tp >= 11890 && -tp < 11900) || (-tp == Heaters1))
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(65.0f)) && dist < 300.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(120.0f)) && dist < 15.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
				}
			}

			if (px >= 280.0f && px <= 400.0f && pz >= 200.0f && pz <= 600.0f)//1-3
			{
				if (-tp >= 13000 && -tp < 13200 || -tp == Janhae10 || (ox >= 280.0f && ox <= 400.0f && oz >= 200.0f && oz <= 600.0f))
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
					continue;
				}
				else if (-tp >= 13200 && -tp < 14000)
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(65.0f)) && dist < 300.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(110.0f)) && dist < 10.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
				}
			}

			if (px >= 400.0f && px <= 600.0f && pz >= 0.0f && pz <= 600.0f)//1-4
			{
				if (-tp >= 14000 && -tp < 14200)
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
					continue;
				}
				else if (-tp >= 14200 && -tp < 15000)
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(60.0f)) && dist < 300.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
					else if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(100.0f)) && dist < 10.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
						continue;
					}
				}
			}
		}

		//2구역

			else if (px >= 800.0f && px <= 1400.0f && pz >= 0.0f && pz <= 600.0f)
			{
			//2구역공통물체
			if (-tp >= 20000 && -tp < 21000)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			//2-1
			else if ((px >= 800.0f && px <= 875.0f && pz >= 60.0f && pz <= 600.0f) || (px >= 800.0f && px <= 1050.0f && pz >= 60.0f && pz <= 150.0f))
			{
				if (-tp >= 21000 && -tp < 21200 || (-tp >= 14000 && -tp <= 14200) || -tp == 14901 || -tp == 14205 || -tp == 10014)//그들중 큰물체는 무조건 그리고
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
				else if (-tp >= 21200 && -tp < 22000) // 작은 물체는 카메라 방향에따라 그릴지 말지 결정.
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist <= 300.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
					}
				}
			}
			//2-2
			else if ((px >= 876.0f && px <= 1010.0f && pz >= 150.0f && pz <= 210.0f) || (px >= 876.0f && px <= 1140.0f && pz >= 210.0f && pz <= 600.0f))
			{
				if (-tp >= 22000 && -tp < 22200)
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
				else if (-tp >= 22200 && -tp < 23000)
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist <= 300.0f)
					{
						if (m_pd3dCbvSrvDescriptorHeap)
						{
							pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
						}
						objects[i]->Render(pd3dCommandList, pCamera);
					}
				}
			}
			//2-3
			else if ((px >= 1010.0f && px <= 1400.0f && pz >= 150.0f && pz <= 210.0f) || (px >= 1140.0f && px <= 1400.0f && pz >= 150.0f && pz <= 600.0f))
			{
				if (-tp >= 23000 && -tp < 23200)
				{
					if (m_pd3dCbvSrvDescriptorHeap)
					{
						pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
					}
					objects[i]->Render(pd3dCommandList, pCamera);
				}
				else if (-tp >= 23200 && -tp < 24000)
				{
					if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(70.0f)) && dist <= 300.0f)
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
			//통로
			else if (px >= 600.0f && px <= 800.0f && pz >= 550.0f && pz <= 570.0f)
			{
			if ((-tp >= 14000 && -tp < 14200) || -tp == 14901 || (-tp >= 10000 && -tp < 11000) || (-tp >= 20000 && -tp < 21200) || -tp >= 30000)
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


D3D12_INPUT_LAYOUT_DESC ShadowShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC ShadowShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE ShadowShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Shadow.hlsl", "vsShadow", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE ShadowShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Shadow.hlsl", "psShadow", "ps_5_1", &m_pd3dPixelShaderBlob));
}