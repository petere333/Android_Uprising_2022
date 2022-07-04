#include "TerrainShader1_3.h"

TerrainShader1_3::TerrainShader1_3(ResourceManager* r)
{
	rm = r;
}
TerrainShader1_3::~TerrainShader1_3() {}

void TerrainShader1_3::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	data = LoadObjects("res/map/area1_3/objects1-3.txt");
	boxesWorld = LoadBoxes("res/map/area1_3/box1-3.txt", &nBox);
	CLoadedMesh* Container = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Container.txt", NULL);
	CLoadedMesh* shelf2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Shelf2.txt", NULL);
	CLoadedMesh* box01 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Box.txt", NULL);
	CLoadedMesh* box02 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Box_ZaxisUp.txt", NULL);
	CLoadedMesh* cardBoard = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_cardboardboxes.txt", NULL);
	CLoadedMesh* cont01 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_container_YaxisUp.txt", NULL);
	CLoadedMesh* cont02 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_container_ZaxisUp.txt", NULL);
	CLoadedMesh* crane = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Crane.txt", NULL);
	CLoadedMesh* electCar = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_ec1_01.txt", NULL);
	CLoadedMesh* machine = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_FactoryMachine.txt", NULL);
	CLoadedMesh* lamp01 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Lamp02.txt", NULL);
	CLoadedMesh* metalLadder = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Metalladder.txt", NULL);
	CLoadedMesh* overHead = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_OverHead.txt", NULL);
	CLoadedMesh* pallet01 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_palletjack.txt", NULL);
	CLoadedMesh* waterPipe = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_WaterPipe1.txt", NULL);
	CLoadedMesh* wWindow = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_WiredWindow.txt", NULL);
	CLoadedMesh* powerBox = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_POWERBOX.txt", NULL);
	CLoadedMesh* pipe01 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_pipes.txt", NULL);
	CLoadedMesh* fan01 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_Fan.txt", NULL);
	CLoadedMesh* metalSup = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_MetalSupport.txt", NULL);
	CLoadedMesh* gasTank = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_GasTank.txt", NULL);
	CLoadedMesh* pallet02 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/area1_3/vtx_transpallet.txt", NULL);


	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj = NULL;

		if (data[i].type == Container13)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[187]);
			obj->SetMesh(Container);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}

		else if (data[i].type == Shelf02)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[184]);
			obj->SetMesh(shelf2);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}

		else if (data[i].type == Box1301)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[100]);
			obj->SetMesh(box01);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Box1302)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[201]);
			obj->SetMesh(box02);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == CardBoard13)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[188]);
			obj->SetMesh(cardBoard);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Cont1301)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[199]);
			obj->SetMesh(cont01);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Cont1302)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[200]);
			obj->SetMesh(cont02);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Crane)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[203]);
			obj->SetMesh(crane);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == ElecCar)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[196]);
			obj->SetMesh(electCar);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == FMachine)
		{

			obj = new CGameObject(1);
			obj->SetMaterial(0, rm->materials[189]);
			obj->SetMesh(machine);
			obj->shadowHeight = 0.0f;
			obj->shadowX = 0.0f;
			obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Lamp13)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[194]);
		obj->SetMesh(lamp01);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Metalladder)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[184]);
		obj->SetMesh(metalLadder);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == OverHead)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[184]);
		obj->SetMesh(overHead);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Palletjack)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[192]);
		obj->SetMesh(pallet01);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WaterPipe)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[195]);
		obj->SetMesh(waterPipe);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == WiredWindow)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[204]);
		obj->SetMesh(wWindow);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == PowerBox)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[193]);
		obj->SetMesh(powerBox);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == Pipe13)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[198]);
		obj->SetMesh(pipe01);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == AirFan13)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[205]);
		obj->SetMesh(fan01);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == MetalSup)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[202]);
		obj->SetMesh(metalSup);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}
		else if (data[i].type == GasTank)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[190]);
		obj->SetMesh(gasTank);
		obj->shadowHeight = 0.0f;
		obj->shadowX = 0.0f;
		obj->shadowZ = 0.0f;
		}

		else if (data[i].type == TransPallet)
		{

		obj = new CGameObject(1);
		obj->SetMaterial(0, rm->materials[197]);
		obj->SetMesh(pallet02);
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

void TerrainShader1_3::ReleaseObjects()
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
void TerrainShader1_3::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}
void TerrainShader1_3::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void TerrainShader1_3::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
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

D3D12_INPUT_LAYOUT_DESC TerrainShader1_3::CreateInputLayout()
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

D3D12_RASTERIZER_DESC TerrainShader1_3::CreateRasterizerState()
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

D3D12_SHADER_BYTECODE TerrainShader1_3::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "vsTerrain", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE TerrainShader1_3::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"Terrain.hlsl", "psTerrain", "ps_5_1", &m_pd3dPixelShaderBlob));
}