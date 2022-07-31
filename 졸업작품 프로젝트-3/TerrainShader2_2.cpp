#include "TerrainShader2_2.h"

TerrainShader2_2::TerrainShader2_2(ResourceManager* r)
{
	rm = r;
}
TerrainShader2_2::~TerrainShader2_2() {}

void TerrainShader2_2::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

	data = LoadObjects("res/map/area2-2/objects2-2.txt");
	boxesWorld = LoadBoxes("res/map/area2-2/box2-2.txt", &nBox);

	GridMesh* Receps_Cheons1 = new GridMesh(pd3dDevice, pd3dCommandList, 75.0f, 365.0f);
	GridMesh* Receps_floor1 = new GridMesh(pd3dDevice, pd3dCommandList, 75.0f, 365.0f);
	CCubeMeshTextured* Receps_wall1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 7.5f, 20.0f);
	CCubeMeshTextured* Receps_wall2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 5.0f, 20.0f);
	CCubeMeshTextured* Receps_front1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 10.0f, 20.833f);
	CCubeMeshTextured* Receps_front2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 2.5f, 15.0f);
	CCubeMeshTextured* Receps_Lipgu = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 8.0f, 25.0f);
	CCubeMeshTextured* Receps_Lipgu2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 4.5f, 18.125f);
	CCubeMeshTextured* Receps_Lipgu3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 4.5f, 25.0f); // 벽 하단
	CCubeMeshTextured* Receps_Lipgu4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2.0f, 4.5f, 17.125f);
	CCubeMeshTextured* Receps_kidoo1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 2.5f, 10.0f);

	CCubeMeshTextured* Receps_Gan1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 6.0f, 10.0f);
	CLoadedMesh* Recep_Takja1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Table.txt", NULL);
	CLoadedMesh* Recep_Cow1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Couch.txt", NULL);
	CLoadedMesh* Recep_Bending1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Vending.txt", NULL);
	CLoadedMesh* Recep_blackcow = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Counters.txt", NULL);
	CLoadedMesh* Recep_CCTV = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Screen2.txt", NULL);
	CCubeMeshTextured* Receps_MedWal1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 12.5f, 4.0f);
	CLoadedMesh* Recep_TwoCounter = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Counters2.txt", NULL);
	PillarMesh* Recep_Gonggi = new PillarMesh(pd3dDevice, pd3dCommandList, 8, 8, 15);
	CLoadedMesh* Recep_MalDong = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Dongsang.txt", NULL);
	CCubeMeshTextured* Receps_MisulWall1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 12.5f, 16.0f);
	CLoadedMesh* Recep_lamped = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_lamp.txt", NULL);
	CLoadedMesh* Recep_Door_B = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Door_1.txt", NULL);
	CLoadedMesh* Recep_Door_L = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Door_L.txt", NULL);
	CLoadedMesh* Recep_Door_R = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_2/vtx_Door_R.txt", NULL);

	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;
		CGameObject* shd = NULL;
		RectMesh* shadow = NULL;

		if (data[i].type == Recep_celing)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[95]);
			obj->SetMesh(Receps_Cheons1);
		}
		else if (data[i].type == Recep_floor)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[102]);
			obj->SetMesh(Receps_floor1);
		}
		else if (data[i].type == Recep_wall1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[104]);
			obj->SetMesh(Receps_wall1);
		}
		else if (data[i].type == Recep_wall2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[104]);
			obj->SetMesh(Receps_wall2);
		}
		else if (data[i].type == Recep_front)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_front1);
		}
		else if (data[i].type == Recep_front2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_front2);
		}
		else if (data[i].type == Recep_wall3)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_Lipgu);
		}
		else if (data[i].type == Recep_wall4)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_Lipgu2);
		}
		else if (data[i].type == Recep_wall5)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_Lipgu3);
		}
		else if (data[i].type == Recep_kidung)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[101]);
			obj->SetMesh(Receps_kidoo1);
		}
		else if (data[i].type == Recep_Kanmak)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[104]);
			obj->SetMesh(Receps_Gan1);
		}
		else if (data[i].type == Recep_Tables)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[111]);
			obj->SetMesh(Recep_Takja1);

			obj->shadowHeight = 1.4f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[389]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 4.0f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_Couch)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[83]);
			obj->SetMesh(Recep_Cow1);

			obj->shadowHeight = 1.3f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[388]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 1.0f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_Vending)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[84]);
			obj->SetMesh(Recep_Bending1);

			obj->shadowHeight = 3.0f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[390]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , 0.0f, data[i].position.z + 1.0f * h - data[i].position.y);
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_Counter1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[86]);
			obj->SetMesh(Recep_blackcow);
			obj->shadowHeight = 2.7f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[391]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 1.4f * h - data[i].position.y, 0.0f, data[i].position.z );
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_Screened1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[87]);
			obj->SetMesh(Recep_CCTV);
		}
		else if (data[i].type == Recep_MidWal)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_MedWal1);
		}
		else if (data[i].type == Recep_Counter2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[105]);
			obj->SetMesh(Recep_TwoCounter);

			obj->shadowHeight = 14.0f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[392]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x , 0.0f, data[i].position.z + 1.0f * h - data[i].position.y);
			shd->Rotate(0.0f, data[i].rotation.y + 180.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_Air)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Recep_Gonggi);
		}
		else if (data[i].type == Recep_DongSSang1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[107]);
			obj->SetMesh(Recep_MalDong);

			obj->shadowHeight = 9.0f;

			float w = boxesWorld[i].end.z - boxesWorld[i].start.z;
			float h = boxesWorld[i].end.y - boxesWorld[i].start.y;
			float dx = boxesWorld[i].end.x - boxesWorld[i].start.x;
			//그림자의 가로 길이는, 원본 물체의 x너비의 절반
			shadow = new (std::nothrow) RectMesh(pd3dDevice, pd3dCommandList, w, h);
			shd = new (std::nothrow) CGameObject(1);
			shd->SetMaterial(0, rm->materials[393]);
			shd->SetMesh(shadow);

			//그림자의 위치는 어지간해서는 땅. 그러나 컨테이너 등의 위에 있는 일부 예외 물체는 그 물체와 동일한 높이.

			//x방향으로 높이만큼 이동. 즉, 해가 동쪽에서 수평면으로부터 약 45도 각도로 떠있음
			shd->SetPosition(data[i].position.x + 1.0f * h - data[i].position.y, 0.0f, data[i].position.z);
			shd->Rotate(0.0f, data[i].rotation.y + 270.0f, 0.0f);

			shadows.push_back(shd);
		}
		else if (data[i].type == Recep_Misul)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_MisulWall1);
		}
		else if (data[i].type == Recep_Lamps)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[108]);
			obj->SetMesh(Recep_lamped);
		}
		else if (data[i].type == Recep_Door1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[109]);
			obj->SetMesh(Recep_Door_B);
		}
		else if (data[i].type == Recep_DoorL)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[109]);
			obj->SetMesh(Recep_Door_L);
		}
		else if (data[i].type == Recep_DoorR)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[109]);
			obj->SetMesh(Recep_Door_R);
		}
		else if (data[i].type == Recep_wall4_F)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[57]);
			obj->SetMesh(Receps_Lipgu4);
		}


		obj->SetPosition(data[i].position);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		objects.push_back(obj);
	}

}

void TerrainShader2_2::ReleaseObjects()
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
void TerrainShader2_2::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader2_2::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader2_2::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

D3D12_INPUT_LAYOUT_DESC TerrainShader2_2::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader2_2::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader2_2::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader2_2::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}