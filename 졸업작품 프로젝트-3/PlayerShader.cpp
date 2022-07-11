#include "PlayerShader.h"

PlayerShader::PlayerShader(ResourceManager* r) 
{
	rm = r;
}
PlayerShader::~PlayerShader() {}

void PlayerShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

}

void PlayerShader::ReleaseObjects()
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
void PlayerShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void PlayerShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void PlayerShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, float elapsed, ID3D12DescriptorHeap * heap)
{
	for (int i = 0; i < objects.size(); ++i)
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

		if (i == 0)
		{
			rm->materials[0]->UpdateShaderVariable(pd3dCommandList);
		}
		else if (i == 1)
		{
			rm->materials[1]->UpdateShaderVariable(pd3dCommandList);
		}
		else if (i == 2)
		{
			rm->materials[3]->UpdateShaderVariable(pd3dCommandList);
		}
		objects[i]->Render(pd3dCommandList, pCamera);	
	}
}

D3D12_INPUT_LAYOUT_DESC PlayerShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC PlayerShader::CreateRasterizerState()
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


D3D12_SHADER_BYTECODE PlayerShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Player.hlsl", "vsPlayer", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE PlayerShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Player.hlsl", "psPlayer", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void PlayerShader::addPlayer(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, XMFLOAT3 pos, ID3D12RootSignature* sig)
{
	PlayerObject* obj = new PlayerObject(pd3dDevice, pd3dCommandList, sig, rm->playerModels[0], 1);
	obj->type = 1;
	obj->objType = 1;

	obj->SetPosition(pos);
	obj->Rotate(0.0f, 0.0f, 0.0f);
	obj->currentRotation = XMFLOAT3(0.0f, 0.0f, 0.0f);


	obj->lastMove = chrono::system_clock::now();



	PlayerInfoManager* manager = new PlayerInfoManager();
	

	obj->info = manager;
	obj->SetTrackAnimationSet(0, 11);


	objects.push_back(obj);
}

std::vector<XMFLOAT3> PlayerShader::getPlayerLocation()
{
	vector<XMFLOAT3> location;
	for (int i = 0; i < objects.size(); ++i)
	{
		location.push_back(objects[i]->GetPosition());
	}
	return location;
}