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

		obj->bState.stateID = IDLE_STATE;
		obj->bState.hp = 20;
		obj->maxHP = 20;
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

void EnemyShader::animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float elapsed)
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

			if ((objects[i]->routeIdx == objects[i]->route.size()) || (objects[i]->route.size() == 0))
			{
				objects[i]->currentPoint += 1;
				if (objects[i]->currentPoint == objects[i]->seekPoint.size())
					objects[i]->currentPoint = 0;
				objects[i]->route = objects[i]->NavigateMovement(objects[i]->seekPoint[objects[i]->currentPoint].x, objects[i]->seekPoint[objects[i]->currentPoint].y);
				objects[i]->routeIdx = 0;

			}


			objects[i]->moveByRoute(objects[i]->route);
			
		}

		else if (objects[i]->bState.stateID == DEAD_STATE)
		{
			chrono::duration<double> timeFromDeath = chrono::system_clock::now() - objects[i]->deathMoment;
			float dt = (float)timeFromDeath.count();
			if (dt >= 1.0f)
			{
				delete objects[i];
				objects.erase(objects.begin() + i);
			}
		}

		
	}
}