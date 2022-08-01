#include "HealthBarShader.h"


HealthBarShader::HealthBarShader(ResourceManager* r)
{
	rm = r;
}
HealthBarShader::~HealthBarShader() {}

void HealthBarShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, std::vector<XMFLOAT3> pos, std::vector<int> health)
{
	hp = new UIMesh * [10];
	hpReversed = new UIMesh * [10];
	
	for (int i = 0; i < 10; ++i)
	{
		UIMesh* m1 = new UIMesh(pd3dDevice, pd3dCommandList, 0.1f * (i + 1), 0.2f, false, 0.05f * (10 - i + 1), 2.0f);
		UIMesh* m2 = new UIMesh(pd3dDevice, pd3dCommandList, 0.1f * (i + 1), 0.2f, true, 0.05f * (10 - i + 1), 2.0f);
		hp[i] = m1;
		hpReversed[i] = m2;
		
	}

	enemyHealth = health;
	enemyPos = pos;

	

	

	for (int i = 0; i < pos.size(); ++i)
	{
		CGameObject* obj;
		obj = new CGameObject(1);
		obj->SetPosition(pos[i].x, pos[i].y+2.0f, pos[i].z);
		obj->SetMesh(hp[0]);
		obj->SetMaterial(0, rm->materials[270]);
		objects.push_back(obj);
	}

	//objects.push_back(obj);
	//objects.push_back(obj2);
}

void HealthBarShader::ReleaseObjects()
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
void HealthBarShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void HealthBarShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void HealthBarShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

		if (objects[i])
		{
			if ((px >= 0.0f && px <= 400.0f && pz >= 0.0f && pz <= 200.0f) &&
				(ex >= 0.0f && ex <= 400.0f && ez >= 0.0f && ez <= 200.0f))//1-1
			{
				if (dist < 20.0f)
				{
					objects[i]->Render(pd3dCommandList, pCamera);
				}
			}
			else if ((px >= 0.0f && px <= 200.0f && pz >= 200.0f && pz <= 600.0f) &&
				(ex >= 0.0f && ex <= 200.0f && ez >= 200.0f && ez <= 600.0f))//1-2
			{
				if(dist<20.0f)
					objects[i]->Render(pd3dCommandList, pCamera);
			}
			else if ((px >= 280.0f && px <= 400.0f && pz >= 200.0f && pz <= 600.0f) &&
				(ex >= 280.0f && ex <= 400.0f && ez >= 200.0f && ez <= 600.0f))//1-3
			{
				if (dist < 20.0f)
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			else if ((px >= 400.0f && px <= 600.0f && pz >= 0.0f && pz <= 600.0f) &&
				(ex >= 400.0f && ex <= 600.0f && ez >= 0.0f && ez <= 600.0f))//1-4
			{
				if (dist < 20.0f)
				objects[i]->Render(pd3dCommandList, pCamera);
			}
		}
	}
}

D3D12_INPUT_LAYOUT_DESC HealthBarShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC HealthBarShader::CreateRasterizerState()
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

D3D12_DEPTH_STENCIL_DESC HealthBarShader::CreateDepthStencilState()
{
	D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc;
	::ZeroMemory(&d3dDepthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));
	d3dDepthStencilDesc.DepthEnable = TRUE;
	d3dDepthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	d3dDepthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
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

D3D12_SHADER_BYTECODE HealthBarShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Health.hlsl", "vsHealth", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE HealthBarShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Health.hlsl", "psHealth", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void HealthBarShader::Animate(CCamera* cam, std::vector<XMFLOAT3> pos, std::vector<int> health)
{
	enemyPos = pos;
	enemyHealth = health;

	XMFLOAT3 cp = cam->getPosition();
	XMFLOAT3 cl = cam->getLook();
	XMFLOAT3 cr = cam->getRight();
	XMFLOAT3 cu = cam->getUp();
	float pitch = XMConvertToDegrees(atan(cl.y / sqrt(cl.x * cl.x + cl.z * cl.z)));

	float yaw = XMConvertToDegrees(atan(cl.x / cl.z));
	float roll = XMConvertToDegrees(atan(cl.x / cl.y));

	//적의 수가 바뀐경우 체력바 다시 생성
	if (objects.size() != enemyPos.size())
	{
		for (int i = 0; i < objects.size(); ++i)
		{
			delete objects[i];
		}
		objects.clear();

		for (int i = 0; i < enemyPos.size(); ++i)
		{
			CGameObject* obj;
			obj = new CGameObject(1);
			obj->SetPosition(pos[i].x, pos[i].y + 2.0f, pos[i].z);
			obj->SetMesh(hp[0]);
			obj->SetMaterial(0, rm->materials[17]);
			objects.push_back(obj);
		}
	}

	if (cl.z < 0)
	{
		pitch = -pitch;
		for (int i = 0; i < objects.size(); ++i)
		{
			if (enemyHealth[i] > 0)
			{
				objects[i]->SetMesh(hpReversed[enemyHealth[i]]);
			}
			else
			{
				objects[i]->SetMesh(NULL);
			}
			
		}
	}
	else
	{
		for (int i = 0; i < objects.size(); ++i)
		{
			if (enemyHealth[i] > 0)
			{
				objects[i]->SetMesh(hp[enemyHealth[i]]);
			}
			else
			{
				objects[i]->SetMesh(NULL);
			}
		}
	}

	
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(enemyPos[i].x, enemyPos[i].y+0.5f, enemyPos[i].z);
	}
	
}