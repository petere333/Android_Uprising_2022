#include "EnemyShader.h"

EnemyShader::EnemyShader(ResourceManager* r)
{
	rm = r;
}
EnemyShader::~EnemyShader() {}

void EnemyShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* sig)
{
	CGameObject* obj = new CLionObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1);
	obj->SetPosition(90.0f, 0.0f, 150.0f);
	obj->type = -10;
	obj->SetTrackAnimationSet(0, 0);

	obj->bState.stateID = IDLE_STATE;
	obj->bState.hp = 10;
	objects.push_back(obj);

	CGameObject* obj2 = new CLionObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1);
	obj2->SetPosition(92.0f, 0.0f, 152.0f);
	obj2->type = -10;
	obj2->SetTrackAnimationSet(0, 0);

	obj2->bState.stateID = IDLE_STATE;
	obj2->bState.hp = 10;
	objects.push_back(obj2);

	CGameObject* obj3 = new CLionObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1);
	obj3->SetPosition(94.0f, 0.0f, 150.0f);
	obj3->type = -10;
	obj3->SetTrackAnimationSet(0, 0);

	obj3->bState.stateID = IDLE_STATE;
	obj3->bState.hp = 10;
	objects.push_back(obj3);

	CGameObject* obj4 = new CLionObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1);
	obj4->SetPosition(120.0f, 0.0f, 220.0f);
	obj4->type = -10;
	obj4->SetTrackAnimationSet(0, 0);

	obj4->bState.stateID = IDLE_STATE;
	obj4->bState.hp = 10;
	objects.push_back(obj4);

	CGameObject* obj5 = new CLionObject(pd3dDevice, pd3dCommandList, sig, rm->enemyModels[0], 1);
	obj5->SetPosition(450.0f, 0.0f, 330.0f);
	obj5->type = -10;
	obj5->SetTrackAnimationSet(0, 0);

	obj5->bState.stateID = IDLE_STATE;
	obj5->bState.hp = 10;
	objects.push_back(obj5);

	// 각 적들의 위치에 바운딩 박스 생성
	for (int i = 0; i < objects.size(); ++i)
	{
		//x,y=-0.25~0.25 z=0.0~1.7

		XMFLOAT3 pos = objects[i]->GetPosition();

		BoundBox* box = new BoundBox;
		box->start = XMFLOAT3(pos.x - 0.4f, pos.y, pos.z - 0.4f);
		box->end = XMFLOAT3(pos.x + 0.4f, pos.y + 1.7f, pos.z + 0.4f);

		enemyBoxes.push_back(box);
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
				rm->materials[34]->UpdateShaderVariable(pd3dCommandList);
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
				rm->materials[34]->UpdateShaderVariable(pd3dCommandList);
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
				rm->materials[34]->UpdateShaderVariable(pd3dCommandList);
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
				rm->materials[34]->UpdateShaderVariable(pd3dCommandList);
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