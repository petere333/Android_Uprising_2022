#include "TerrainShader2_3.h"

TerrainShader2_3::TerrainShader2_3(ResourceManager* r)
{
	rm = r;
}
TerrainShader2_3::~TerrainShader2_3() {}

void TerrainShader2_3::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/area2-3/objects2-3.txt");
	boxesWorld = LoadBoxes("res/map/area2-3/box2-3.txt", &nBox);


	GridMesh* Parkingarea = new GridMesh(pd3dDevice, pd3dCommandList, 325.0f, 90.0f);
	PillarMesh* Parkingwall = new PillarMesh(pd3dDevice, pd3dCommandList, 325, 4, 10);
	PillarMesh* Parkingfwall = new PillarMesh(pd3dDevice, pd3dCommandList, 2, 67, 10);
	CLoadedMesh* Parkingfence = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area2_3/vtx_fence.txt", NULL);
	PillarMesh* Parkingareas = new PillarMesh(pd3dDevice, pd3dCommandList, 2, 32, 2);
	PillarMesh* Parkingareas2 = new PillarMesh(pd3dDevice, pd3dCommandList, 10, 2, 2);


	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;

		if (data[i].type == Parking_floor1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[293]);
			obj->SetMesh(Parkingarea);
		}
		else if (data[i].type == Parking_Wall1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[294]);
			obj->SetMesh(Parkingwall);
		}
		else if (data[i].type == Parking_FWall1)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[294]);
			obj->SetMesh(Parkingfwall);
		}
		else if (data[i].type == Parking_Fence)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[295]);
			obj->SetMesh(Parkingfence);
		}
		else if (data[i].type == Parking_Area)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[295]);
			obj->SetMesh(Parkingareas);
		}
		else if (data[i].type == Parking_Area2)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[295]);
			obj->SetMesh(Parkingareas2);
		}


	
		obj->SetPosition(data[i].position);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		objects.push_back(obj);
	}


}

void TerrainShader2_3::ReleaseObjects()
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
void TerrainShader2_3::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader2_3::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader2_3::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

D3D12_INPUT_LAYOUT_DESC TerrainShader2_3::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader2_3::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader2_3::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader2_3::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}