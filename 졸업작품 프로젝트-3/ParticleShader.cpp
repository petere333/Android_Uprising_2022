#include "ParticleShader.h"

ParticleShader::ParticleShader(ResourceManager* r, ID3D12Device* device, ID3D12GraphicsCommandList* list)
{
	rm = r;
	partMesh = new ParticleMesh(device, list);

}
ParticleShader::~ParticleShader() {}

void ParticleShader::BuildObjects()
{

}

void ParticleShader::ReleaseObjects()
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
void ParticleShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void ParticleShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void ParticleShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		XMFLOAT3 pos = objects[i]->GetPosition();
		XMFLOAT3 camPos = pCamera->getPosition();
		XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);
		XMFLOAT3 look = pCamera->getLook();

		float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

		if (cosAngle >= cos(XMConvertToRadians(45.0f)) && cosAngle <= 1.0f)
		{
			if (objects[i]->type == 1)
			{	
				objects[i]->m_ppMaterials[0] = rm->materials[4];
			}
			objects[i]->Render(pd3dCommandList, pCamera);
		}

	}
}

D3D12_INPUT_LAYOUT_DESC ParticleShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC ParticleShader::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE ParticleShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Particles.hlsl", "vsParticle", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE ParticleShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Particles.hlsl", "psParticle", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void ParticleShader::createParticles(int type, int n, XMFLOAT3 pos, ID3D12Device* device, ID3D12GraphicsCommandList* list, float xd, float zd)
{


	//랜덤한 방향으로 나아가는 조그마한 입자를 해당 위치에 n개 생성
	for (int i = 0; i < n; ++i)
	{
		float x = static_cast<float>(rand() % 10000) / 10000.0f - 0.5f;
		float y = static_cast<float>(rand() % 10000) / 10000.0f - 0.5f;
		float z = static_cast<float>(rand() % 10000) / 10000.0f - 0.5f;


		XMFLOAT3 direct = XMFLOAT3(x, y, z);
		XMFLOAT3 tp = XMFLOAT3(xd, 0.0f, zd);
		direct = Vector3::Normalize(direct);
		float da = Vector3::DotProduct(direct, tp);
		/*
		while (da > -0.8f && da <0.8f)
		{
			
			float x = static_cast<float>(rand() % 10000) / 10000.0f - 0.5f;
			float y = static_cast<float>(rand() % 10000) / 10000.0f - 0.5f;
			float z = static_cast<float>(rand() % 10000) / 10000.0f - 0.5f;
			direct = XMFLOAT3(x, y, z);
			direct = Vector3::Normalize(direct);
			da = Vector3::DotProduct(direct, tp);
			
		}
		*/
		/*
		if (da < 0.0f)
		{
			direct.x *= -1.0f;
			direct.y *= -1.0f;
			direct.z *= -1.0f;
		}
		*/
		ParticleObject* obj = new ParticleObject(1);
		obj->type = type;
		obj->timeCreated = std::chrono::system_clock::now();
		obj->SetMaterial(0, rm->materials[4]);
		obj->speed = 0.03f;
		obj->direction = direct;
		obj->SetPosition(pos);
		obj->SetMesh(partMesh);
		objects.push_back(obj);
	}
}