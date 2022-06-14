#include "TerrainShader1_1.h"

/*
--	1-1 Æó±â¹° Ã³¸®Àå¿¡ ÀÖ´Â ¹°Ã¼µé¸¸ ´ã´çÇÏ´Â ½¦ÀÌ´õ ÄÚµå.
--	
--
*/


TerrainShader1_1::TerrainShader1_1(ResourceManager* r)
{
	rm = r;
}
TerrainShader1_1::~TerrainShader1_1() {}

void TerrainShader1_1::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/area1_1/objects1-1.txt");
	boxesWorld = LoadBoxes("res/map/area1_1/box1-1.txt", &nBox);

	GridMesh* RustyFloor = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 200.0f);
	WallMeshHorizontal* RustyWallFront = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshHorizontal* RustyWallBack = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshVertical* RustyWallLeft = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);
	WallMeshVertical* RustyWallRight = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 10.0f);

	WallMeshVertical* RustyWallLeft100m = new WallMeshVertical(pd3dDevice, pd3dCommandList, 100.0f, 10.0f);
	WallMeshVertical* RustyWallCenter50m = new WallMeshVertical(pd3dDevice, pd3dCommandList, 50.0f, 10.0f);

	WallMeshHorizontal* RustyWallHCenter50m = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 50.0f, 10.0f);
	WallMeshHorizontal* RustyWallBottom50m = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 50.0f, 10.0f);
	WallMeshHorizontal* RustyWallTop100m = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 100.0f, 10.0f);


	CLoadedMesh* Metal_Box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_box.txt", NULL);
	CLoadedMesh* RustyBarrel = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_barrel.txt", NULL);

	CLoadedMesh* Pipe_Wall = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_wallpipe.txt", NULL);
	CLoadedMesh* Pipe_Floor = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_1/vtx_floorpipe.txt", NULL);

	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;

		if (data[i].type == RustyMetal_Floor)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[76]);
			obj->SetMesh(RustyFloor);
		}
		else if (data[i].type == RustyMetal_Ceiling)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[76]);
			obj->SetMesh(RustyFloor);
		}
		else if (data[i].type == RustyMetal_Wall_Front)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallFront);
		}
		else if (data[i].type == RustyMetal_Wall_Back)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallBack);
		}
		else if (data[i].type == RustyMetal_Wall_Left)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallLeft);
		}
		else if (data[i].type == RustyMetal_Wall_Right)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallRight);
		}
		else if (data[i].type == RustyMetal_Wall_Left_100m)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallLeft100m);
		}

		else if (data[i].type == RustyMetal_Wall_Center_50m)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallCenter50m);
		}
		else if (data[i].type == RustyMetal_Wall_HCenter_50m)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallHCenter50m);
		}
		else if (data[i].type == RustyMetal_Wall_Bottom_50m)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallBottom50m);
		}
		else if (data[i].type == RustyMetal_Wall_Top_100m)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallTop100m);
		}


		else if (data[i].type == RustyMetal_Wall_Right)
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[79]);
			obj->SetMesh(RustyWallRight);
		}

		else if (data[i].type == RustyMetal_Box) // ¹Ø¸é -0.75f
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[78]);
			obj->SetMesh(Metal_Box);
			obj->shadowHeight = 0.75f;
		}
		else if (data[i].type == RustyMetal_Barrel) // ¹Ø¸é - 1.125f
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[77]);
			obj->SetMesh(RustyBarrel);
			obj->shadowHeight = 1.125f;
		}
		else if (data[i].type == WallPipe)//¹Ø¸é 1.25
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[77]);
			obj->SetMesh(Pipe_Wall);
			obj->shadowHeight = 1.25f;
		}
		else if (data[i].type == FloorPipe)//¹Ø¸é 0.375
		{
			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[77]);
			obj->SetMesh(Pipe_Floor);
			obj->shadowHeight = 0.375f;
		}

		obj->SetPosition(data[i].position);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		objects.push_back(obj);
	}
	
	

}

void TerrainShader1_1::ReleaseObjects()
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
void TerrainShader1_1::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader1_1::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader1_1::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

D3D12_INPUT_LAYOUT_DESC TerrainShader1_1::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader1_1::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader1_1::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader1_1::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}