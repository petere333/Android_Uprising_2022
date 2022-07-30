#include "TerrainShader2_1.h"

TerrainShader2_1::TerrainShader2_1(ResourceManager* r)
{
	rm = r;
}
TerrainShader2_1::~TerrainShader2_1() {}

void TerrainShader2_1::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

	data = LoadObjects("res/map/area2-1/objects2-1.txt");
	boxesWorld = LoadBoxes("res/map/area2-1/box2-1.txt", &nBox);

	CCubeMeshTextured* Gwang_wall1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 7.5f, 20.0f);
	GridMesh* Gwang_floor1 = new GridMesh(pd3dDevice, pd3dCommandList, 75.0f, 60.0f);
	CCubeMeshTextured* Gwang_front1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 10.0f, 20.833f);
	GridMesh* Gwang_Cheons1 = new GridMesh(pd3dDevice, pd3dCommandList, 75.0f, 235.0f);
	GridMesh* Gwang_floor2 = new GridMesh(pd3dDevice, pd3dCommandList, 75.0f, 175.0f);
	CCubeMeshTextured* Gwang_front2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 2.5f, 15.0f);
	CCubeMeshTextured* Gwang_wall2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 5.0f, 20.0f);
	CLoadedMesh* Gwang_Screen1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_Screen_4.txt", NULL);
	CLoadedMesh* Gwang_Screen2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_Screen_4.txt", NULL);
	CLoadedMesh* Gwang_Screen3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_Screen_4.txt", NULL);
	CLoadedMesh* Gwang_Table1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_desk-1A1.txt", NULL);
	CLoadedMesh* Gwang_Table2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_desk-1A2.txt", NULL);
	CLoadedMesh* Gwang_Chair = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_MetalChair.txt", NULL);
	PillarMesh* Receps_Karo1 = new PillarMesh(pd3dDevice, pd3dCommandList, 20, 1, 3);
	CLoadedMesh* Gwang_Cabinet = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_1/vtx_Cabinets.txt", NULL);

	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;
		RectMesh* shadow = NULL;
		CGameObject* shd = NULL;

		if (data[i].type == Gwanja_wall1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[88]);
			obj->SetMesh(Gwang_wall1);
		}
		else if (data[i].type == Gwanja_floor)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[91]);
			obj->SetMesh(Gwang_floor1);
		}
		else if (data[i].type == Gwanja_front)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[89]);
			obj->SetMesh(Gwang_front1);
		}
		else if (data[i].type == Gwanja_celing)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[95]);
			obj->SetMesh(Gwang_Cheons1);
		}
		else if (data[i].type == Gwanja_floor2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[88]);
			obj->SetMesh(Gwang_floor2);
		}
		else if (data[i].type == Gwanja_wall2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[90]);
			obj->SetMesh(Gwang_front2);
		}
		else if (data[i].type == Gwanja_wall3)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[89]);
			obj->SetMesh(Gwang_wall2);
		}
		else if (data[i].type == Gwanja_Screen)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[110]);
			obj->SetMesh(Gwang_Screen1);


			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[340]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x +2.0f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Gwanja_Screen2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[110]);
			obj->SetMesh(Gwang_Screen2);
		}
		else if (data[i].type == Gwanja_Screen3)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[110]);
			obj->SetMesh(Gwang_Screen3);
		}
		else if (data[i].type == Gwanja_tables)
		{
			obj = new (std::nothrow) CGameObject(1);
			obj->SetMaterial(0, rm->materials[97]);
			obj->SetMesh(Gwang_Table1);
			obj->shadowHeight = 2.0f;


			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[341]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 1.7f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Gwanja_tablesA)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[97]);
			obj->SetMesh(Gwang_Table2);

			obj->shadowHeight = 1.3f;

			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[343]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 1.7f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Gwanja_Chair)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[82]);
			obj->SetMesh(Gwang_Chair);
			obj->shadowHeight = 1.3f;

			//원본 물체 크기의 x,y 길이
			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[342]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 1.7f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_garomak)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[100]);
			obj->SetMesh(Receps_Karo1);
		}
		else if (data[i].type == Gwanja_Cabinet)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[112]);
			obj->SetMesh(Gwang_Cabinet);

			obj->shadowHeight = 3.0f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[344]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 0.1f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}

		obj->SetPosition(data[i].position);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		objects.push_back(obj);
	}


}
void TerrainShader2_1::ReleaseObjects()
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
void TerrainShader2_1::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader2_1::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader2_1::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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
			/*
			if (objects[i]->type >= 21000 && objects[i]->type <= 21007)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				objects[i]->Render(pd3dCommandList, pCamera);
			}
			else
			{
				if (dist <= 20.0f)
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
			*/
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			objects[i]->Render(pd3dCommandList, pCamera);
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
			if (dist <= 20.0f)
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

D3D12_INPUT_LAYOUT_DESC TerrainShader2_1::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader2_1::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader2_1::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader2_1::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}