#include "TerrainShader1_2.h"

TerrainShader1_2::TerrainShader1_2(ResourceManager* r)
{
	rm = r;
}
TerrainShader1_2::~TerrainShader1_2() {}

void TerrainShader1_2::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/area1_2/objects1-2.txt");
	boxesWorld = LoadBoxes("res/map/area1_2/box1-2.txt", &nBox);

	CLoadedMesh* shield = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_shield.txt", NULL);
	CLoadedMesh* bigshield = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_bigshield.txt", NULL);
	CLoadedMesh* longtank = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_longtank.txt", NULL);
	CLoadedMesh* fan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_airfan.txt", NULL);

	CLoadedMesh* m1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine1.txt", NULL);
	CLoadedMesh* m3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine3.txt", NULL);
	CLoadedMesh* m4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine4.txt", NULL);
	CLoadedMesh* m6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine6.txt", NULL);
	CLoadedMesh* m7 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_machine7.txt", NULL);

	CLoadedMesh* arm = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_robotarm.txt", NULL);
	CLoadedMesh* sewer = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_2/vtx_sewer.txt", NULL);

	WallMeshHorizontal* front = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshHorizontal* back = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);

	WallMeshVertical* left1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 195.0f, 10.0f);
	WallMeshVertical* left2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 5.0f);
	WallMeshVertical* left3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 10.0f);

	WallMeshVertical* right1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 195.0f, 10.0f);
	WallMeshVertical* right2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 5.0f);
	WallMeshVertical* right3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 2.5f, 10.0f);

	PillarMesh* center1 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 150, 10);
	PillarMesh* center2 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 4, 5);
	PillarMesh* center3 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 43, 5);
	PillarMesh* center4 = new PillarMesh(pd3dDevice, pd3dCommandList, 1, 3, 2);

	PillarMesh* hcenter1 = new PillarMesh(pd3dDevice, pd3dCommandList, 10, 1, 10);
	PillarMesh* hcenter2 = new PillarMesh(pd3dDevice, pd3dCommandList, 92, 1, 10);
	PillarMesh* hcenter3 = new PillarMesh(pd3dDevice, pd3dCommandList, 92, 1, 10);
	PillarMesh* hcenter4 = new PillarMesh(pd3dDevice, pd3dCommandList, 3, 1, 5);
	PillarMesh* hcenter5 = new PillarMesh(pd3dDevice, pd3dCommandList, 3, 1, 5);

	PillarMesh* wire = new PillarMesh(pd3dDevice, pd3dCommandList, 100, 50, 5);


	GridMesh* basefloor = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 200.0f);
	GridMesh* upperfloor = new GridMesh(pd3dDevice, pd3dCommandList, 100.0f, 50.0f);
	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;

		if (data[i].type == Shield)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[114]);
			obj->SetMesh(shield);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == BigShield)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[115]);
			obj->SetMesh(bigshield);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == AirFan)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[117]);
			obj->SetMesh(fan);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == LongTank)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[116]);
			obj->SetMesh(longtank);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Machine1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[118]);
			obj->SetMesh(m1);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Machine3)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[119]);
			obj->SetMesh(m3);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Machine4)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[120]);
			obj->SetMesh(m4);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Machine6)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[121]);
			obj->SetMesh(m6);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Machine7)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[122]);
			obj->SetMesh(m7);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == RobotArm)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[123]);
			obj->SetMesh(arm);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Sewer)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[124]);
			obj->SetMesh(sewer);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}

		else if (data[i].type == Wall12_Left1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[125]);
			obj->SetMesh(left1);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Left2)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(left2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Left3)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(left3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Right1)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(right1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Right2)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(right2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Right3)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(right3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Front)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(front);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Back)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(back);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Floor)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[127]);
		obj->SetMesh(basefloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Ceiling)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[126]);
		obj->SetMesh(basefloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_UpperFloor)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[127]);
		obj->SetMesh(upperfloor);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center1)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(center1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center2)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(center2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center3)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(center3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_Center4)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(center4);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter1)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(hcenter1);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter2)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(hcenter2);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter3)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(hcenter3);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter4)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(hcenter4);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Wall12_HCenter5)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[125]);
		obj->SetMesh(hcenter5);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WireFrame)
		{
		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[128]);
		obj->SetMesh(wire);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}

		obj->type = data[i].type;
		obj->SetPosition(data[i].position);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		objects.push_back(obj);
	}
}

void TerrainShader1_2::ReleaseObjects()
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
void TerrainShader1_2::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader1_2::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader1_2::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC TerrainShader1_2::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader1_2::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader1_2::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader1_2::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}