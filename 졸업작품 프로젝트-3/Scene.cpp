//-----------------------------------------------------------------------------
// File: CScene.cpp
//-----------------------------------------------------------------------------
#pragma once

#include "stdafx.h"
#include "Scene.h"
#include "GameFramework.h"

#include "CNet.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	
}
void CScene::CreateRM(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	rm = new ResourceManager();
	rm->Init(pd3dDevice, pd3dCommandList);
	rm->BuildData(m_pd3dGraphicsRootSignature);
	
}
void CScene::BuildDefaultLightsAndMaterials()
{
	m_nLights = 4;
	m_pLights = new LIGHT[m_nLights];
	::ZeroMemory(m_pLights, sizeof(LIGHT) * m_nLights);

	m_xmf4GlobalAmbient = XMFLOAT4(0.05f, 0.05f, 0.05f, 1.0f);
	
	m_pLights[3].m_bEnable = true;
	m_pLights[3].m_nType = SPOT_LIGHT;
	m_pLights[3].m_fRange = 100.0f;
	m_pLights[3].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[3].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.2f, 0.1f, 1.0f);
	m_pLights[3].m_xmf4Specular = XMFLOAT4(0.1f, 0.2f, 0.3f, 0.0f);
	m_pLights[3].m_xmf3Position = XMFLOAT3(300.0f, 25.0f, 300.0f);
	m_pLights[3].m_xmf3Direction = XMFLOAT3(0.0f, -1.0f, 0.0f);
	m_pLights[3].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.00001f);
	m_pLights[3].m_fFalloff = 15.0f;
	m_pLights[3].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[3].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	

	m_pLights[2].m_bEnable = true;
	m_pLights[2].m_nType = SPOT_LIGHT;
	m_pLights[2].m_fRange = 100.0f;
	m_pLights[2].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[2].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.2f, 0.1f, 1.0f);
	m_pLights[2].m_xmf4Specular = XMFLOAT4(0.1f, 0.2f, 0.3f, 0.0f);
	m_pLights[2].m_xmf3Position = XMFLOAT3(0.0f, 2.0f, 250.0f);
	m_pLights[2].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_pLights[2].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.00001f);
	m_pLights[2].m_fFalloff = 15.0f;
	m_pLights[2].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[2].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	

	m_pLights[1].m_bEnable = true;
	m_pLights[1].m_nType = SPOT_LIGHT;
	m_pLights[1].m_fRange = 30.0f;
	m_pLights[1].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[1].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.2f, 0.1f, 1.0f);
	m_pLights[1].m_xmf4Specular = XMFLOAT4(0.1f, 0.2f, 0.3f, 0.0f);
	m_pLights[1].m_xmf3Position = XMFLOAT3(100.0f, 25.0f, 100.0f);
	m_pLights[1].m_xmf3Direction = XMFLOAT3(0.0f, -1.0f, 0.0f);
	m_pLights[1].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.00001f);
	m_pLights[1].m_fFalloff = 15.0f;
	m_pLights[1].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[1].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	

	m_pLights[0].m_bEnable = false;
	m_pLights[0].m_nType = DIRECTIONAL_LIGHT;
	m_pLights[0].m_xmf4Ambient = XMFLOAT4(0.4f, 0.4f, 0.4f, 1.0f);
	m_pLights[0].m_xmf4Diffuse = XMFLOAT4(0.7f, 0.7f, 0.7f, 1.0f);
	m_pLights[0].m_xmf4Specular = XMFLOAT4(0.4f, 0.4f, 0.4f, 1.0f);
	m_pLights[0].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	


	m_pMaterials = new MATERIALS;
	::ZeroMemory(m_pMaterials, sizeof(MATERIALS));

	m_pMaterials->m_pReflections[0] = { XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[1] = { XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 10.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[2] = { XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 15.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[3] = { XMFLOAT4(0.5f, 0.0f, 1.0f, 1.0f), XMFLOAT4(0.0f, 0.5f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 20.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[4] = { XMFLOAT4(0.0f, 0.5f, 1.0f, 1.0f), XMFLOAT4(0.5f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 25.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[5] = { XMFLOAT4(0.0f, 0.5f, 0.5f, 1.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 30.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[6] = { XMFLOAT4(0.5f, 0.5f, 1.0f, 1.0f), XMFLOAT4(0.5f, 0.5f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 35.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[7] = { XMFLOAT4(1.0f, 0.5f, 1.0f, 1.0f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 40.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	

}


void CScene::BuildObjects(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList)
{
	m_pd3dGraphicsRootSignature = CreateGraphicsRootSignature(pd3dDevice);

	initShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	createSounds();
	CreateRM(pd3dDevice, pd3dCommandList);

	boomMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx/vtx_boom.txt", NULL);

	height11 = new float*[x11];
	height12 = new float*[x12];
	height13 = new float*[x13];
	height21 = new float*[x21];
	height22 = new float*[x22];
	height23 = new float*[x23];

	for (int i = 0; i < x11; ++i)
	{
		height11[i] = new float[z11];
	}
	for (int i = 0; i < x12; ++i)
	{
		height12[i] = new float[z12];
	}
	for (int i = 0; i < x13; ++i)
	{
		height13[i] = new float[z13];
	}

	for (int i = 0; i < x21; ++i)
	{
		height21[i] = new float[z21];
	}
	for (int i = 0; i < x22; ++i)
	{
		height22[i] = new float[z22];
	}
	for (int i = 0; i < x23; ++i)
	{
		height23[i] = new float[z23];
	}

	for (int i = 0; i < x11; ++i)
	{
		for (int j = 0; j < z11; ++j)
		{
			height11[i][j] = 0.0f;
		}
	}
	for (int i = 0; i < x12; ++i)
	{
		for (int j = 0; j < z12; ++j)
		{
			height12[i][j] = 0.0f;
		}
	}
	for (int i = 0; i < x13; ++i)
	{
		for (int j = 0; j < z13; ++j)
		{
			height13[i][j] = 0.0f;
		}
	}

	for (int i = 0; i < x21; ++i)
	{
		for (int j = 0; j < z21; ++j)
		{
			height21[i][j] = 0.0f;
		}
	}
	for (int i = 0; i < x22; ++i)
	{
		for (int j = 0; j < z22; ++j)
		{
			height22[i][j] = 0.0f;
		}
	}
	for (int i = 0; i < x23; ++i)
	{
		for (int j = 0; j < z23; ++j)
		{
			height23[i][j] = 0.0f;
		}
	}


	LoadHeight("res/map/area1_1/height1-1.txt", height11);
	LoadHeight("res/map/area1_2/height1-2.txt", height12);
	LoadHeight("res/map/area2-1/height2-1.txt", height21);
	LoadHeight("res/map/area2-2/height2-2.txt", height22);

	partMesh = new ParticleMesh(pd3dDevice, pd3dCommandList);
	
	
	//CMaterial::PrepareShaders(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature); 
	interShader = new InterfaceShader(rm);
	interShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	interShader->BuildObjects(pd3dDevice, pd3dCommandList);

	

	playerShader = new PlayerShader(rm);
	playerShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	playerShader->BuildObjects(pd3dDevice, pd3dCommandList);

	

	terrain1_1 = new TerrainShader1_1(rm);
	terrain1_1->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrain1_1->BuildObjects(pd3dDevice, pd3dCommandList);

	terrain1_2 = new TerrainShader1_2(rm);
	terrain1_2->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrain1_2->BuildObjects(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);


	terrain1_3 = new TerrainShader1_3(rm);
	terrain1_3->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrain1_3->BuildObjects(pd3dDevice, pd3dCommandList);

	terrain2_1 = new TerrainShader2_1(rm);
	terrain2_1->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrain2_1->BuildObjects(pd3dDevice, pd3dCommandList);

	terrain2_2 = new TerrainShader2_2(rm);
	terrain2_2->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrain2_2->BuildObjects(pd3dDevice, pd3dCommandList);

	terrain2_3 = new TerrainShader2_3(rm);
	terrain2_3->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrain2_3->BuildObjects(pd3dDevice, pd3dCommandList);

	enemyShader = new EnemyShader(rm, height11, height12, height13, height21, height22, height23);
	enemyShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	enemyShader->BuildObjects(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);

	enemyDying = new DyingEnemyShader(rm);
	enemyDying->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	enemyDying->BuildObjects(pd3dDevice, pd3dCommandList);

	std::vector<XMFLOAT3> ep = enemyShader->getEnemyPosition();
	std::vector<int> ehp = enemyShader->getHealthRate();

	barShader = new HealthBarShader(rm);
	barShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	barShader->BuildObjects(pd3dDevice, pd3dCommandList, ep, ehp);

	partShader = new ParticleShader(rm, pd3dDevice, pd3dCommandList);
	partShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	partShader->BuildObjects();
	
	boomShader = new BoomShader(rm, partShader, enemyShader);
	boomShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	boomShader->BuildObjects(pd3dDevice, pd3dCommandList);

	sdwShader = new ShadowShader(rm);
	sdwShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	sdwShader->BuildObjects(pd3dDevice,pd3dCommandList);

	charShd = new CharShadow(rm);
	charShd->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	charShd->BuildObjects(pd3dDevice, pd3dCommandList);

	lobbyInter = new LobbyInterfaceShader(rm);
	lobbyInter->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	lobbyInter->BuildObjects(pd3dDevice, pd3dCommandList);

	mainInter = new MainInterfaceShader(rm);
	mainInter->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	mainInter->BuildObjects(pd3dDevice, pd3dCommandList);

	profileInter = new ProfileShader(rm);
	profileInter->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	profileInter->BuildObjects(pd3dDevice, pd3dCommandList);

	stageInter = new StageSelectShader(rm);
	stageInter->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	stageInter->BuildObjects(pd3dDevice, pd3dCommandList);

	waitInter = new WaitShader(rm);
	waitInter->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	waitInter->BuildObjects(pd3dDevice, pd3dCommandList);



	BuildDefaultLightsAndMaterials();
	//createenemyShader->objects(pd3dDevice, pd3dCommandList);

	std::vector<Obj> data = LoadObjects("res/map/objects.txt");

	programStarted = chrono::system_clock::now();

	CreateShaderVariables(pd3dDevice, pd3dCommandList);

	rm->bgm[1]->play();
	rm->bgm[1]->Update();
}

void CScene::ReleaseObjects()
{
	delSounds();
	if (m_pd3dGraphicsRootSignature) m_pd3dGraphicsRootSignature->Release();
	

	if (m_ppShaders)
	{
		for (int i = 0; i < m_nShaders; i++)
		{
			m_ppShaders[i]->ReleaseShaderVariables();
			m_ppShaders[i]->ReleaseObjects();
			m_ppShaders[i]->Release();
		}
		delete[] m_ppShaders;
	}

	if (terrain1_1)
	{
		terrain1_1->ReleaseShaderVariables();
		terrain1_1->ReleaseObjects();
		terrain1_1->Release();
	}
	if (terrain1_2)
	{
		terrain1_2->ReleaseShaderVariables();
		terrain1_2->ReleaseObjects();
		terrain1_2->Release();
	}
	if (terrain1_3)
	{
		terrain1_3->ReleaseShaderVariables();
		terrain1_3->ReleaseObjects();
		terrain1_3->Release();
	}

	if (terrain2_1)
	{
		terrain2_1->ReleaseShaderVariables();
		terrain2_1->ReleaseObjects();
		terrain2_1->Release();
	}
	if (terrain2_2)
	{
		terrain2_2->ReleaseShaderVariables();
		terrain2_2->ReleaseObjects();
		terrain2_2->Release();
	}
	if (terrain2_3)
	{
		terrain2_3->ReleaseShaderVariables();
		terrain2_3->ReleaseObjects();
		terrain2_3->Release();
	}

	if (m_ppGameObjects)
	{
		for (int i = 0; i < m_nGameObjects; i++) if (m_ppGameObjects[i]) m_ppGameObjects[i]->Release();
		delete[] m_ppGameObjects;
	}

	ReleaseShaderVariables();

	if (m_pLights) delete[] m_pLights;
}

ID3D12RootSignature *CScene::CreateGraphicsRootSignature(ID3D12Device *pd3dDevice)
{
	ID3D12RootSignature *pd3dGraphicsRootSignature = NULL;

	D3D12_DESCRIPTOR_RANGE pd3dDescriptorRanges[3];

	pd3dDescriptorRanges[0].RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	pd3dDescriptorRanges[0].NumDescriptors = 1;
	pd3dDescriptorRanges[0].BaseShaderRegister = 0; //t0: gtxtTexture
	pd3dDescriptorRanges[0].RegisterSpace = 0;
	pd3dDescriptorRanges[0].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

	pd3dDescriptorRanges[1].RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	pd3dDescriptorRanges[1].NumDescriptors = 1;
	pd3dDescriptorRanges[1].BaseShaderRegister = 1; //t1: normal
	pd3dDescriptorRanges[1].RegisterSpace = 0;
	pd3dDescriptorRanges[1].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
	
	pd3dDescriptorRanges[2].RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	pd3dDescriptorRanges[2].NumDescriptors = 1;
	pd3dDescriptorRanges[2].BaseShaderRegister = 2; //t2: spec
	pd3dDescriptorRanges[2].RegisterSpace = 0;
	pd3dDescriptorRanges[2].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;


	D3D12_ROOT_PARAMETER pd3dRootParameters[10];

	pd3dRootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[0].Descriptor.ShaderRegister = 1; //Camera
	pd3dRootParameters[0].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
	pd3dRootParameters[1].Constants.Num32BitValues = 17;
	pd3dRootParameters[1].Constants.ShaderRegister = 2; //GameObject
	pd3dRootParameters[1].Constants.RegisterSpace = 0;
	pd3dRootParameters[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[2].Descriptor.ShaderRegister = 4; //Lights
	pd3dRootParameters[2].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[3].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
	pd3dRootParameters[3].DescriptorTable.NumDescriptorRanges = 1;
	pd3dRootParameters[3].DescriptorTable.pDescriptorRanges = &(pd3dDescriptorRanges[0]);//gtxttexture t0
	pd3dRootParameters[3].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

	

	pd3dRootParameters[4].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[4].Descriptor.ShaderRegister = 7; //Skinned Bone Offsets
	pd3dRootParameters[4].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[4].ShaderVisibility = D3D12_SHADER_VISIBILITY_VERTEX;

	pd3dRootParameters[5].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[5].Descriptor.ShaderRegister = 8; //Skinned Bone Transforms
	pd3dRootParameters[5].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[5].ShaderVisibility = D3D12_SHADER_VISIBILITY_VERTEX;


	pd3dRootParameters[6].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
	pd3dRootParameters[6].DescriptorTable.NumDescriptorRanges = 1;
	pd3dRootParameters[6].DescriptorTable.pDescriptorRanges = &(pd3dDescriptorRanges[1]);// normal t1
	pd3dRootParameters[6].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

	pd3dRootParameters[7].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[7].Descriptor.ShaderRegister = 3; //material
	pd3dRootParameters[7].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[7].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[8].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
	pd3dRootParameters[8].Constants.Num32BitValues = 1;
	pd3dRootParameters[8].Constants.ShaderRegister = 6; //alpha
	pd3dRootParameters[8].Constants.RegisterSpace = 0;
	pd3dRootParameters[8].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[9].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
	pd3dRootParameters[9].DescriptorTable.NumDescriptorRanges = 1;
	pd3dRootParameters[9].DescriptorTable.pDescriptorRanges = &(pd3dDescriptorRanges[2]);//specTex t2
	pd3dRootParameters[9].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;




	D3D12_STATIC_SAMPLER_DESC d3dSamplerDesc; // gSamplerState
	::ZeroMemory(&d3dSamplerDesc, sizeof(D3D12_STATIC_SAMPLER_DESC));
	d3dSamplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
	d3dSamplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
	d3dSamplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
	d3dSamplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
	d3dSamplerDesc.MipLODBias = 0;
	d3dSamplerDesc.MaxAnisotropy = 1;
	d3dSamplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS;
	d3dSamplerDesc.MinLOD = 0;
	d3dSamplerDesc.MaxLOD = D3D12_FLOAT32_MAX;
	d3dSamplerDesc.ShaderRegister = 0;
	d3dSamplerDesc.RegisterSpace = 0;
	d3dSamplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

	D3D12_ROOT_SIGNATURE_FLAGS d3dRootSignatureFlags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT | D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
	D3D12_ROOT_SIGNATURE_DESC d3dRootSignatureDesc;
	::ZeroMemory(&d3dRootSignatureDesc, sizeof(D3D12_ROOT_SIGNATURE_DESC));
	d3dRootSignatureDesc.NumParameters = _countof(pd3dRootParameters);
	d3dRootSignatureDesc.pParameters = pd3dRootParameters;
	d3dRootSignatureDesc.NumStaticSamplers = 1;
	d3dRootSignatureDesc.pStaticSamplers = &d3dSamplerDesc;
	d3dRootSignatureDesc.Flags = d3dRootSignatureFlags;

	ID3DBlob *pd3dSignatureBlob = NULL;
	ID3DBlob *pd3dErrorBlob = NULL;
	D3D12SerializeRootSignature(&d3dRootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &pd3dSignatureBlob, &pd3dErrorBlob);
	pd3dDevice->CreateRootSignature(0, pd3dSignatureBlob->GetBufferPointer(), pd3dSignatureBlob->GetBufferSize(), __uuidof(ID3D12RootSignature), (void **)&pd3dGraphicsRootSignature);
	if (pd3dSignatureBlob) pd3dSignatureBlob->Release();
	if (pd3dErrorBlob) pd3dErrorBlob->Release();

	return(pd3dGraphicsRootSignature);
}

void CScene::CreateShaderVariables(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(LIGHTS) + 255) & ~255); //256의 배수
	m_pd3dcbLights = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);

	m_pd3dcbLights->Map(0, NULL, (void **)&m_pcbMappedLights);

	UINT ncbMaterialBytes = ((sizeof(MATERIALS) + 255) & ~255); //256의 배수
	m_pd3dcbMaterials = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbMaterialBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);

	m_pd3dcbMaterials->Map(0, NULL, (void**)&m_pcbMappedMaterials);
}

void CScene::UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList)
{
	::memcpy(m_pcbMappedLights->m_pLights, m_pLights, sizeof(LIGHT) * m_nLights);
	::memcpy(&m_pcbMappedLights->m_xmf4GlobalAmbient, &m_xmf4GlobalAmbient, sizeof(XMFLOAT4));
	::memcpy(&m_pcbMappedLights->m_nLights, &m_nLights, sizeof(int));

	::memcpy(m_pcbMappedMaterials, m_pMaterials, sizeof(MATERIALS));
}

void CScene::ReleaseShaderVariables()
{
	if (m_pd3dcbLights)
	{
		m_pd3dcbLights->Unmap(0, NULL);
		m_pd3dcbLights->Release();
	}
	if (m_pd3dcbMaterials)
	{
		m_pd3dcbMaterials->Unmap(0, NULL);
		m_pd3dcbMaterials->Release();
	}
	
}

void CScene::ReleaseUploadBuffers()
{
	for (int i = 0; i < m_nShaders; i++) m_ppShaders[i]->ReleaseUploadBuffers();
	for (int i = 0; i < m_nGameObjects; i++) m_ppGameObjects[i]->ReleaseUploadBuffers();
	if (terrain1_1)
	{
		terrain1_1->ReleaseUploadBuffers();
	}
	if (terrain1_2)
	{
		terrain1_2->ReleaseUploadBuffers();
	}
	if (terrain1_3)
	{
		terrain1_3->ReleaseUploadBuffers();
	}


	if (terrain2_1)
	{
		terrain2_1->ReleaseUploadBuffers();
	}
	if (terrain2_2)
	{
		terrain2_2->ReleaseUploadBuffers();
	}
	if (terrain2_3)
	{
		terrain2_3->ReleaseUploadBuffers();
	}
}






bool CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	return(false);
}

bool CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
			/*
		case 'W': m_ppGameObjects[0]->MoveForward(+3.0f); break;
		case 'S': m_ppGameObjects[0]->MoveForward(-3.0f); break;
		case 'A': m_ppGameObjects[0]->MoveStrafe(-3.0f); break;
		case 'D': m_ppGameObjects[0]->MoveStrafe(+3.0f); break;
		case 'Q': m_ppGameObjects[0]->MoveUp(+3.0f); break;
		case 'R': m_ppGameObjects[0]->MoveUp(-3.0f); break;
			*/
		default:
			break;
		}
		break;
	default:
		break;
	}
	return(false);
}

bool CScene::ProcessInput(UCHAR *pKeysBuffer)
{
	return(false);
}

void CScene::AnimateObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float fTimeElapsed, CCamera* cam)
{
	bool posChange = false;
	if (currentScreen == IN_GAME_STATE)
	{
		cam->move(playerShader->objects[pID]->GetPosition());
		m_fElapsedTime = fTimeElapsed;
		//for (int i = 0; i < m_nShaders; i++) if (m_ppShaders[i]) m_ppShaders[i]->AnimateObjects(fTimeElapsed);
		interShader->Animate(cam, playerShader->objects[pID]->info);

		if (playerShader->objects[pID]->bState.attackID == TYPE_RANGED)
		{
			interShader->objects[1]->m_ppMaterials[0] = rm->materials[interShader->objects[1]->defaultMesh];
			interShader->objects[2]->m_ppMaterials[0] = rm->materials[interShader->objects[2]->defaultMesh + 1];
			interShader->objects[3]->m_ppMaterials[0] = rm->materials[interShader->objects[3]->defaultMesh];
		}
		else if (playerShader->objects[pID]->bState.attackID == TYPE_MELEE)
		{
			interShader->objects[1]->m_ppMaterials[0] = rm->materials[interShader->objects[1]->defaultMesh + 1];
			interShader->objects[2]->m_ppMaterials[0] = rm->materials[interShader->objects[2]->defaultMesh];
			interShader->objects[3]->m_ppMaterials[0] = rm->materials[interShader->objects[3]->defaultMesh];
		}
		if (playerShader->objects[pID]->bState.attackID == TYPE_MICROWAVE)
		{
			interShader->objects[1]->m_ppMaterials[0] = rm->materials[interShader->objects[1]->defaultMesh];
			interShader->objects[2]->m_ppMaterials[0] = rm->materials[interShader->objects[2]->defaultMesh];
			interShader->objects[3]->m_ppMaterials[0] = rm->materials[interShader->objects[3]->defaultMesh + 1];
		}


		if (terrain1_2)
		{
			terrain1_2->animate(pd3dDevice, pd3dCommandList, fTimeElapsed);
		}
		if (enemyShader)
		{
			vector<XMFLOAT3> ppos = playerShader->getPlayerLocation();
			enemyShader->animate(pd3dDevice, pd3dCommandList, fTimeElapsed,ppos, playerShader, partShader, enemyDying, m_pd3dGraphicsRootSignature);
		}

		if (enemyDying)
		{
			enemyDying->animate();
		}

		charShd->animate(playerShader, enemyShader);

		for (int i = 0; i < playerShader->objects.size(); ++i)
		{

			if (playerShader->objects[i]->bState.stateID == IDLE_STATE)
			{
				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{

					if (playerShader->objects[i]->info->slot.rangedWeapon->type == RIFLE)
					{

						if (playerShader->objects[i]->m_pChild != rm->playerModels[0]->m_pModelRootObject)
						{
							


							
							
							playerShader->objects[i]->setRoot(rm->playerModels[0]->m_pModelRootObject, true);
							playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[0]);
						}
						playerShader->objects[i]->SetTrackAnimationSet(0, 0);
						
						if (playerShader->objects[i]->kState.yspeed != 0.0f)
						{
							posChange = moveObject(i, cam);
						}
						setObjectLastMove(i);
					}

					else if (playerShader->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
					{
						std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
						float df = static_cast<float>(dt.count());

						if (df >= 0.5f)
						{
						
							if (playerShader->objects[i]->m_pChild != rm->playerModels[11]->m_pModelRootObject)
							{
								

								
								
								
								playerShader->objects[i]->setRoot(rm->playerModels[11]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[11]);
								playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							}
							
							
						}
						if (playerShader->objects[i]->kState.yspeed != 0.0f)
						{
							posChange = moveObject(i, cam);
						}
						setObjectLastMove(i);
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{
					if (playerShader->objects[i]->info->slot.meleeWeapon->type == BLUNT)
					{

						std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
						float df = static_cast<float>(dt.count());
						if (df >= 0.833333f)
						{
							if (playerShader->objects[i]->m_pChild != rm->playerModels[2]->m_pModelRootObject)
							{
								

								
								
								playerShader->objects[i]->setRoot(rm->playerModels[2]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[2]);
								playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							}
							
							
						}
						if (playerShader->objects[i]->kState.yspeed != 0.0f)
						{
							posChange = moveObject(i, cam);
						}
						setObjectLastMove(i);
					}
					else if (playerShader->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
					{
						std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
						float df = static_cast<float>(dt.count());
						if (df >= 0.833333f)
						{
							if (playerShader->objects[i]->m_pChild != rm->playerModels[12]->m_pModelRootObject)
							{
								
								
								
								playerShader->objects[i]->setRoot(rm->playerModels[12]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[12]);
							}
							playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							
						}
						if (playerShader->objects[i]->kState.yspeed != 0.0f)
						{
							posChange = moveObject(i, cam);
						}
						setObjectLastMove(i);
					}

				}

				else if (playerShader->objects[i]->bState.attackID == TYPE_MICROWAVE)
				{
					std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastWave;
					float df = static_cast<float>(dt.count());

					//마지막 공격으로부터 공격애니메이션 재생 시간 이상 경과한 경우에만 애니메이션 변경.
					//즉, 이미 진행중인 공격은 애니메이션을 모두 재생할 것.
					if (df >= 1.0f)
					{

						if (playerShader->objects[i]->m_pChild != rm->playerModels[9]->m_pModelRootObject)
						{
							
							

							

							playerShader->objects[i]->setRoot(rm->playerModels[9]->m_pModelRootObject, true);
							playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[9]);
						}
						playerShader->objects[i]->SetTrackAnimationSet(0, 0);
						
					}
					if (playerShader->objects[i]->kState.yspeed != 0.0f)
					{
						posChange = moveObject(i, cam);
					}
					setObjectLastMove(i);
				}

				
				
				if (moving == 1)
				{
					
					playerShader->objects[i]->Rotate(0.0f, playerShader->objects[i]->kState.rotation+90.0f, 0.0f);
				}
				else if (moving == 2)
				{
					
					playerShader->objects[i]->Rotate(0.0f, playerShader->objects[i]->kState.rotation+90.0f, 0.0f);
				}
				else if (moving == 3)
				{
					
					playerShader->objects[i]->Rotate(0.0f, playerShader->objects[i]->kState.rotation+90.0f, 0.0f);
				}
				else if (moving == 4)
				{
					
					playerShader->objects[i]->Rotate(0.0f, playerShader->objects[i]->kState.rotation+90.0f, 0.0f);
				}
				
			}

			else if (playerShader->objects[i]->bState.stateID == JUMP_STATE)
			{

				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{
					if (playerShader->objects[i]->info->slot.rangedWeapon->type == RIFLE)
					{
						
						if (playerShader->objects[i]->m_pChild != rm->playerModels[18]->m_pModelRootObject)
						{
							
							

							

							playerShader->objects[i]->setRoot(rm->playerModels[18]->m_pModelRootObject, true);
							playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[18]);
						}
						playerShader->objects[i]->SetTrackAnimationSet(0, 0);
						

						posChange = moveObject(i, cam);
						setObjectLastMove(i);
					}
					else if (playerShader->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
					{



						if (playerShader->objects[i]->m_pChild != rm->playerModels[6]->m_pModelRootObject)
						{
							
							

						

							playerShader->objects[i]->setRoot(rm->playerModels[6]->m_pModelRootObject, true);
							playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[6]);
						}
						playerShader->objects[i]->SetTrackAnimationSet(0, 0);
						

						posChange = moveObject(i, cam);
						setObjectLastMove(i);
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{
					if (playerShader->objects[i]->info->slot.meleeWeapon->type == BLUNT)
					{
						std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
						float df = static_cast<float>(dt.count());
						if (df >= 1.0f)
						{
							if (playerShader->objects[i]->m_pChild != rm->playerModels[1]->m_pModelRootObject)
							{
								
								

								

								playerShader->objects[i]->setRoot(rm->playerModels[1]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[1]);
							}
							playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							
						}
						posChange = moveObject(i, cam);
						setObjectLastMove(i);
					}

					else if (playerShader->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
					{
						std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
						float df = static_cast<float>(dt.count());
						if (df >= 1.0f)
						{
							if (playerShader->objects[i]->m_pChild != rm->playerModels[12]->m_pModelRootObject)
							{
								
								

								

								playerShader->objects[i]->setRoot(rm->playerModels[12]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[12]);
							}
							playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							
						}
						posChange = moveObject(i, cam);
						setObjectLastMove(i);
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MICROWAVE)
				{
					if (playerShader->objects[i]->m_pChild != rm->playerModels[7]->m_pModelRootObject)
					{
						
						playerShader->objects[i]->setRoot(rm->playerModels[7]->m_pModelRootObject, true);
						playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[7]);
					}
					playerShader->objects[i]->SetTrackAnimationSet(0, 0);
					
					posChange = moveObject(i, cam);
					setObjectLastMove(i);


				}
			}

			else if (playerShader->objects[i]->bState.stateID == MOVE_STATE)
			{
				
				if (playerShader->objects[i]->bState.attacking == 0)
				{
					if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
					{

						if (playerShader->objects[i]->info->slot.rangedWeapon->type == RIFLE)
						{

							if (playerShader->objects[i]->m_pChild != rm->playerModels[18]->m_pModelRootObject)
							{
								playerShader->objects[i]->setRoot(rm->playerModels[18]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[18]);
							}
							playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							
							chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
							chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

							if (dt.count() > 0.2)
							{
								posChange = moveObject(i, cam);
								setObjectLastMove(i);
							}
						}

						else if (playerShader->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
						{
							//속도가 0이 아닌 경우, 즉 공격애니메이션 재생중이 아닌 때만 이동애니메이션.
							if (playerShader->objects[i]->kState.xzspeed != 0.0f)
							{
								if (playerShader->objects[i]->m_pChild != rm->playerModels[6]->m_pModelRootObject)
								{
									playerShader->objects[i]->setRoot(rm->playerModels[6]->m_pModelRootObject, true);
									playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[6]);
								}
								playerShader->objects[i]->SetTrackAnimationSet(0, 0);

								chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
								chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

								if (dt.count() > 0.5)
								{
									posChange = moveObject(i, cam);
									setObjectLastMove(i);
								}
							}
						}
					}
					else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
					{
						if (playerShader->objects[i]->info->slot.meleeWeapon->type == BLUNT)
						{
							std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
							float df = static_cast<float>(dt.count());
							if (df >= 1.0f)
							{
								if (playerShader->objects[i]->m_pChild != rm->playerModels[1]->m_pModelRootObject)
								{
									playerShader->objects[i]->setRoot(rm->playerModels[1]->m_pModelRootObject, true);
									playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[1]);
								}
								playerShader->objects[i]->SetTrackAnimationSet(0, 0);

								posChange = moveObject(i, cam);
								setObjectLastMove(i);
								
							}

						}

						else if (playerShader->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
						{
							std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
							float df = static_cast<float>(dt.count());
							if (df >= 1.0f)
							{
								if (playerShader->objects[i]->m_pChild != rm->playerModels[21]->m_pModelRootObject)
								{
									playerShader->objects[i]->setRoot(rm->playerModels[21]->m_pModelRootObject, true);
									playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[21]);
								}
								playerShader->objects[i]->SetTrackAnimationSet(0, 0);
								posChange = moveObject(i, cam);
								setObjectLastMove(i);
							}

						}
					}
					else if (playerShader->objects[i]->bState.attackID == TYPE_MICROWAVE)
					{

						//속도가 0이 아닌 경우, 즉 공격애니메이션 재생중이 아닌 때만 이동애니메이션.
						if (playerShader->objects[i]->kState.xzspeed != 0.0f)
						{
							if (playerShader->objects[i]->m_pChild != rm->playerModels[7]->m_pModelRootObject)
							{
								playerShader->objects[i]->setRoot(rm->playerModels[7]->m_pModelRootObject, true);
								playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[7]);
							}
							playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							posChange = moveObject(i, cam);
							setObjectLastMove(i);

						}
					}

				}

			}
			//여기까지 이동관련
			//마우스 클릭중이니 공격하라고 명령을 받은 경우
			if (playerShader->objects[i]->bState.attacking == 1)
			{
				//실제로 플레이어를 공격중이게 설정
				playerShader->objects[i]->attack = true;
			}
			// 마우스가 떼어져 공격을 중지하라고 받은 경우, 혹은 초기 상태일 경우
			else
			{
				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{
					//총기로 공격중인데 중지명령 떨어진 경우
					
					if (playerShader->objects[i]->info->slot.rangedWeapon->type == RIFLE)
					{
						chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
						chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

						//마지막 총알은 마저 다 발사하고 나서 공격 중지.
						if ((float)dt.count() >= 0.166666f)
						{
							playerShader->objects[i]->attack = false;
						}
					}
					else if (playerShader->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
					{
						chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
						chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

						//마지막 총알은 마저 다 발사하고 나서 공격 중지.
						if ((float)dt.count() >= 0.5f)
						{
							playerShader->objects[i]->attack = false;
						}
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{
					if (playerShader->objects[i]->info->slot.meleeWeapon->type == BLUNT)
					{
						chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
						chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

						//마지막 공격은 마저 수행하고서 중지.
						if ((float)dt.count() >= 1.0f)
						{
							playerShader->objects[i]->attack = false;
						}
					}

					else if (playerShader->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
					{
						chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
						chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

						//마지막 공격은 마저 수행하고서 중지.
						if ((float)dt.count() >= 1.0f)
						{
							playerShader->objects[i]->attack = false;
						}
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MICROWAVE)
				{
					chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
					chrono::duration<double> dt = moment - playerShader->objects[i]->lastAttack;

					//마지막 총알은 마저 다 발사하고 나서 공격 중지.
					if ((float)dt.count() >= 0.5f)
					{
						playerShader->objects[i]->attack = false;
					}
				}
			}
			
			if (playerShader->objects[i]->attack==true)
			{
				if (playerShader->objects[i]->bState.attackID < 0)
				{
					playerShader->objects[i]->bState.attackID = TYPE_RANGED;
				}

				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{
					if (playerShader->objects[i]->info->slot.rangedWeapon->type == RIFLE)
					{

						if (playerShader->objects[i]->m_pChild != rm->playerModels[19]->m_pModelRootObject)
						{
							
							

						

							playerShader->objects[i]->setRoot(rm->playerModels[19]->m_pModelRootObject, true);
							playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[19]);

						}

						playerShader->objects[i]->SetTrackAnimationSet(0, 0);
							
						

						cam->rotateUp();
						attack(i, pd3dDevice, pd3dCommandList, cam);
					}

					else if (playerShader->objects[i]->info->slot.rangedWeapon->type == BAZUKA)
					{
						cam->rotateUp();
						playerShader->objects[i]->bState.stateID = IDLE_STATE;
						playerShader->objects[i]->kState.xzspeed = 0.0f;
						shootBazuka(i, pd3dDevice, pd3dCommandList);
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{

					if (playerShader->objects[i]->info->slot.meleeWeapon->type == BLUNT)
					{
						cam->rotateUp();
						playerShader->objects[i]->bState.stateID = IDLE_STATE;
						playerShader->objects[i]->kState.xzspeed = 0.0f;
						swingHammer(i, pd3dDevice, pd3dCommandList);
					}
					else if (playerShader->objects[i]->info->slot.meleeWeapon->type == DUALBLADE)
					{
						cam->rotateUp();
						playerShader->objects[i]->bState.stateID = IDLE_STATE;
						playerShader->objects[i]->kState.xzspeed = 0.0f;
						swingBlade(i, pd3dDevice, pd3dCommandList);
					}
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MICROWAVE)
				{
					cam->rotateUp();
					useRadio(i, pd3dDevice, pd3dCommandList);
				}
				setObjectLastMove(i);
				for (int j = 0; j < playerShader->objects.size(); ++j)
				{
					if (pID != j)
						setObjectLastMove(j);
				}
			}

			if (playerShader->objects[i]->info->stats.capacity <= 0)
			{

				//죽는 애니메이션으로 변경
				// 플레이어 조작 비활성화
			}
		}
		//실제로 상태 변경이 발생한 경우에만 서버에 알리기.
		if (playerShader->objects[pID]->stateChanged == true)
		{
			CS_STATE_PACKET p;
			p.id = pID;
			p.size = sizeof(CS_STATE_PACKET);
			p.type = PACKET_TYPE::CS_STATE;
			p.attackID = playerShader->objects[pID]->bState.attackID;
			p.stateID = playerShader->objects[pID]->bState.stateID;
			SendPacket(&p);
			playerShader->objects[pID]->stateChanged = false;
		}
		//실제로 위치가 변경된 경우
		if (playerShader->objects[pID]->bState.stateID==MOVE_STATE || playerShader->objects[pID]->bState.stateID == JUMP_STATE)
		{

			CS_POSITION_PACKET pac;
			pac.c_id = pID;
			pac.size = sizeof(CS_POSITION_PACKET);
			pac.type = PACKET_TYPE::CS_POSITION;

			pac.angle = playerShader->objects[pID]->kState.rotation;
			pac.x = playerShader->objects[pID]->GetPosition().x;
			pac.y = playerShader->objects[pID]->GetPosition().y;
			pac.z = playerShader->objects[pID]->GetPosition().z;

			SendPacket(&pac);
			
		}

		chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
		
		for (int i = 0; i < partShader->objects.size(); ++i)
		{
			chrono::duration<double> fromCreated = moment - partShader->objects[i]->timeCreated;
			float fTime = static_cast<float>(fromCreated.count());
			if (fTime > 0.5f)
			{
				partShader->objects.erase(partShader->objects.begin() + i);
				i -= 1;
			}
			else
			{
				XMFLOAT3 tmp = partShader->objects[i]->GetPosition();
				partShader->objects[i]->SetPosition(tmp.x + partShader->objects[i]->direction.x * partShader->objects[i]->speed * fTime,
					tmp.y + partShader->objects[i]->direction.y * partShader->objects[i]->speed * fTime,
					tmp.z + partShader->objects[i]->direction.z * partShader->objects[i]->speed * fTime);
			}
		}
		
		if (boomShader)
			boomShader->animate(pd3dDevice, pd3dCommandList, partShader, playerShader, interShader, pID);

		std::vector<XMFLOAT3> ep = enemyShader->getEnemyPosition();
		std::vector<int> ehp = enemyShader->getHealthRate();

		barShader->Animate(cam, ep, ehp);

		XMFLOAT3 cl = Vector3::Normalize(cam->getLook());


		XMFLOAT3 cp = cam->getPosition();

		bool cleared = false;



		if (interShader->missionFail == false)
		{
			if (interShader->stageClear == false)
			{
				for (int i = 0; i < playerShader->objects.size(); ++i)
				{
					XMFLOAT3 pp = playerShader->objects[i]->GetPosition();

					if (waitInter->selectedStage == 1)
					{
						if (interShader->mission == 1)
						{
							//미션 조건 만족시
							if (interShader->m1_kill >= 1)
							{
								//다음 미션 구역에 아직 못갔으면
								if (interShader->nextPos == false)
								{
									if (rm->briefPlayed[4] == false)
									{
										rm->brief[0]->stop();
										rm->brief[1]->stop();
										rm->brief[2]->stop();
										rm->brief[3]->stop();


										rm->briefPlayed[4] = true;
										rm->timePlayed[4] = chrono::system_clock::now();
										rm->brief[4]->play();
										rm->brief[4]->Update();
										interShader->ShowNarration(345, 6.0);
									}
									else if (rm->briefPlayed[5] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[4]);
										if (dt.count() > 6.0)
										{
											rm->briefPlayed[5] = true;
											rm->timePlayed[5] = chrono::system_clock::now();
											rm->brief[5]->play();
											rm->brief[5]->Update();
											interShader->ShowNarration(346, 8.0);
										}
									}
									else if (rm->briefPlayed[6] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[5]);
										if (dt.count() > 8.0)
										{
											rm->briefPlayed[6] = true;
											rm->timePlayed[6] = chrono::system_clock::now();
											rm->brief[6]->play();
											rm->brief[6]->Update();
											interShader->ShowNarration(347, 10.0);
										}
									}
									for (int p = 0; p < playerShader->objects.size(); ++p)
									{
										float px = playerShader->objects[p]->GetPosition().x;
										float pz = playerShader->objects[p]->GetPosition().z;
										if ((px >= 000.0f && px <= 100.0f && pz >= 0.0f && pz <= 100.0f)
											|| (px >= 100.0f && px <= 200.0f && pz >= 0.0f && pz <= 50.0f))

										{
											interShader->nextPos = true;
											
											break;
										}
									}
								}
								if (interShader->nextPos == true)
								{
									interShader->nextPos = false;
									interShader->mission += 1;
									interShader->missionShow = true;
									interShader->missionChangedTime = chrono::system_clock::now();
									
									playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
								}
							}
							else
							{
								if (rm->briefPlayed[0] == false)
								{
									rm->briefPlayed[0] = true;
									rm->timePlayed[0] = chrono::system_clock::now();
									rm->brief[0]->play();
									rm->brief[0]->Update();
									interShader->ShowNarration(342, 8.0);
								}
								else  if (rm->briefPlayed[1] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[0]);
									if (dt.count() > 8.0)
									{
										rm->briefPlayed[1] = true;
										rm->timePlayed[1] = chrono::system_clock::now();
										rm->brief[1]->play();
										rm->brief[1]->Update();
										interShader->ShowNarration(342, 5.0);
									}
								}
								else  if (rm->briefPlayed[2] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[1]);
									if (dt.count() > 5.0)
									{
										rm->briefPlayed[2] = true;
										rm->timePlayed[2] = chrono::system_clock::now();
										rm->brief[2]->play();
										rm->brief[2]->Update();
										interShader->ShowNarration(343, 7.0);
									}
								}
								else  if (rm->briefPlayed[3] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[2]);
									if (dt.count() > 7.0)
									{
										rm->briefPlayed[3] = true;
										rm->timePlayed[3] = chrono::system_clock::now();
										rm->brief[3]->play();
										rm->brief[3]->Update();
										interShader->ShowNarration(344, 8.0);
									}
								}
							}
						}
						else if (interShader->mission == 2)
						{
							if (interShader->m2_stun >= 1)
							{
								if (interShader->nextPos == false)
								{
									if (rm->briefPlayed[10] == false)
									{
										rm->brief[7]->stop();
										rm->brief[8]->stop();
										rm->brief[9]->stop();
										


										rm->briefPlayed[10] = true;
										rm->timePlayed[10] = chrono::system_clock::now();
										rm->brief[10]->play();
										rm->brief[10]->Update();
										interShader->ShowNarration(351, 7.0);
									}
									else if (rm->briefPlayed[11] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[10]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[11] = true;
											rm->timePlayed[11] = chrono::system_clock::now();
											rm->brief[11]->play();
											rm->brief[11]->Update();
											interShader->ShowNarration(352, 7.0);
										}
									}
									else if (rm->briefPlayed[12] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[11]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[12] = true;
											rm->timePlayed[12] = chrono::system_clock::now();
											rm->brief[12]->play();
											rm->brief[12]->Update();
											interShader->ShowNarration(353, 8.0);
										}
									}
									else if (rm->briefPlayed[13] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[12]);
										if (dt.count() > 8.0)
										{
											rm->briefPlayed[13] = true;
											rm->timePlayed[13] = chrono::system_clock::now();
											rm->brief[13]->play();
											rm->brief[13]->Update();
											interShader->ShowNarration(354, 7.0);
										}
									}
									else if (rm->briefPlayed[14] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[13]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[14] = true;
											rm->timePlayed[14] = chrono::system_clock::now();
											rm->brief[14]->play();
											rm->brief[14]->Update();
											interShader->ShowNarration(355, 7.0);
										}
									}
									else if (rm->briefPlayed[15] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[14]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[15] = true;
											rm->timePlayed[15] = chrono::system_clock::now();
											rm->brief[15]->play();
											rm->brief[15]->Update();
											interShader->ShowNarration(356, 6.0);
										}
									}

							
									for (int p = 0; p < playerShader->objects.size(); ++p)
									{
										float px = playerShader->objects[p]->GetPosition().x;
										float pz = playerShader->objects[p]->GetPosition().z;
										if (px >= 100.0f && px <= 200.0f && pz >= 150.0f && pz <= 200.0f)
										{
											interShader->nextPos = true;
											break;
										}
									}
								}
								if (interShader->nextPos == true)
								{
									interShader->nextPos = false;
									interShader->mission += 1;
									interShader->missionShow = true;
									interShader->missionChangedTime = chrono::system_clock::now();
									playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
								}
							}


							else
							{
								if (rm->briefPlayed[7] == false)
								{
									rm->brief[4]->stop();
									rm->brief[5]->stop();
									rm->brief[6]->stop();

									rm->briefPlayed[7] = true;
									rm->timePlayed[7] = chrono::system_clock::now();
									rm->brief[7]->play();
									rm->brief[7]->Update();

									interShader->ShowNarration(348, 7.0);
								}
								else  if (rm->briefPlayed[8] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[7]);
									if (dt.count() > 7.0)
									{
										rm->briefPlayed[8] = true;
										rm->timePlayed[8] = chrono::system_clock::now();
										rm->brief[8]->play();
										rm->brief[8]->Update();
										interShader->ShowNarration(349, 8.0);
									}
								}
								else  if (rm->briefPlayed[9] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[8]);
									if (dt.count() > 8.0)
									{
										rm->briefPlayed[9] = true;
										rm->timePlayed[9] = chrono::system_clock::now();
										rm->brief[9]->play();
										rm->brief[9]->Update();
										interShader->ShowNarration(350, 5.0);
									}
								}
							}
						}
						else if (interShader->mission == 3)
						{
							if (interShader->m3_bother >= 1)
							{
								if (interShader->nextPos == false)
								{
									if (rm->briefPlayed[19] == false)
									{
										rm->brief[16]->stop();
										rm->brief[17]->stop();
										rm->brief[18]->stop();



										rm->briefPlayed[19] = true;
										rm->timePlayed[19] = chrono::system_clock::now();
										rm->brief[19]->play();
										rm->brief[19]->Update();
										interShader->ShowNarration(360, 7.0);
									}
									else if (rm->briefPlayed[20] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[19]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[20] = true;
											rm->timePlayed[20] = chrono::system_clock::now();
											rm->brief[20]->play();
											rm->brief[20]->Update();
											interShader->ShowNarration(361, 6.0);
										}
									}
									else if (rm->briefPlayed[21] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[20]);
										if (dt.count() > 6.0)
										{
											rm->briefPlayed[21] = true;
											rm->timePlayed[21] = chrono::system_clock::now();
											rm->brief[21]->play();
											rm->brief[21]->Update();
											interShader->ShowNarration(362, 6.0);
										}
									}


									for (int p = 0; p < playerShader->objects.size(); ++p)
									{
										float px = playerShader->objects[p]->GetPosition().x;
										float pz = playerShader->objects[p]->GetPosition().z;
										if (px >= 200.0f && px <= 300.0f && pz >= 100.0f && pz <= 200.0f)
										{
											interShader->nextPos = true;
											break;
										}
									}
								}
								if (interShader->nextPos == true)
								{
									interShader->nextPos = false;
									interShader->mission += 1;
									interShader->missionShow = true;
									interShader->missionChangedTime = chrono::system_clock::now();
									playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
								}
							}


							else
							{
								if (rm->briefPlayed[16] == false)
								{
									rm->brief[10]->stop();
									rm->brief[11]->stop();
									rm->brief[12]->stop();
									rm->brief[13]->stop();
									rm->brief[14]->stop();
									rm->brief[15]->stop();


									rm->briefPlayed[16] = true;
									rm->timePlayed[16] = chrono::system_clock::now();
									rm->brief[16]->play();
									rm->brief[16]->Update();

									interShader->ShowNarration(357, 8.0);
								}
								else  if (rm->briefPlayed[17] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[16]);
									if (dt.count() > 8.0)
									{
										rm->briefPlayed[17] = true;
										rm->timePlayed[17] = chrono::system_clock::now();
										rm->brief[17]->play();
										rm->brief[17]->Update();
										interShader->ShowNarration(358, 8.0);
									}
								}
								else  if (rm->briefPlayed[18] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[17]);
									if (dt.count() > 8.0)
									{
										rm->briefPlayed[18] = true;
										rm->timePlayed[18] = chrono::system_clock::now();
										rm->brief[18]->play();
										rm->brief[18]->Update();
										interShader->ShowNarration(359, 7.0);
									}
								}
							}
						}
						else if (interShader->mission == 4)
						{
							chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
							chrono::duration<double> dt = mm - interShader->missionChangedTime;

							if (dt.count() < 100.0)
							{

								if (interShader->m4_kill >= 1)
								{
									//다음위치에 아군 단 한명이라도 도달할 경우
									if (interShader->nextPos == false)
									{
										if (rm->briefPlayed[26] == false)
										{
											rm->brief[22]->stop();
											rm->brief[23]->stop();
											rm->brief[24]->stop();
											rm->brief[25]->stop();


											rm->briefPlayed[26] = true;
											rm->timePlayed[26] = chrono::system_clock::now();
											rm->brief[26]->play();
											rm->brief[26]->Update();
											interShader->ShowNarration(367, 5.0);
										}
										else if (rm->briefPlayed[27] == false)
										{
											chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[26]);
											if (dt.count() > 5.0)
											{
												rm->briefPlayed[27] = true;
												rm->timePlayed[27] = chrono::system_clock::now();
												rm->brief[27]->play();
												rm->brief[27]->Update();
												interShader->ShowNarration(368, 7.0);
											}
										}


										for (int p = 0; p < playerShader->objects.size(); ++p)
										{
											float px = playerShader->objects[p]->GetPosition().x;
											float pz = playerShader->objects[p]->GetPosition().z;
											if (px >= 200.0f && px <= 300.0f && pz >= 0.0f && pz <= 100.0f)
											{
												interShader->nextPos = true;
												break;
											}
										}
									}

									if (interShader->nextPos == true)
									{
										interShader->nextPos = false;
										interShader->mission += 1;
										interShader->missionShow = true;
										interShader->missionChangedTime = chrono::system_clock::now();
										playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
									}
								}
								else
								{
									if (rm->briefPlayed[22] == false)
									{
										rm->brief[19]->stop();
										rm->brief[20]->stop();
										rm->brief[21]->stop();

										rm->briefPlayed[22] = true;
										rm->timePlayed[22] = chrono::system_clock::now();
										rm->brief[22]->play();
										rm->brief[22]->Update();
										interShader->ShowNarration(363, 7.0);
									}
									else  if (rm->briefPlayed[23] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[22]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[23] = true;
											rm->timePlayed[23] = chrono::system_clock::now();
											rm->brief[23]->play();
											rm->brief[23]->Update();
											interShader->ShowNarration(364, 8.0);
										}
									}
									else  if (rm->briefPlayed[24] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[23]);
										if (dt.count() > 8.0)
										{
											rm->briefPlayed[24] = true;
											rm->timePlayed[24] = chrono::system_clock::now();
											rm->brief[24]->play();
											rm->brief[24]->Update();
											interShader->ShowNarration(365, 7.0);
										}
									}
									else  if (rm->briefPlayed[25] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[24]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[25] = true;
											rm->timePlayed[25] = chrono::system_clock::now();
											rm->brief[25]->play();
											rm->brief[25]->Update();
											interShader->ShowNarration(366, 6.0);
										}
									}
								}
							}
							else
							{
								interShader->missionFail = true;
								interShader->timeFailed = chrono::system_clock::now();
							}
						}
						else if (interShader->mission == 5)
						{
							chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
							chrono::duration<double> dt = mm - interShader->missionChangedTime;

							if (dt.count() > 25.0f)
							{
								if (interShader->nextPos == false)
								{
									if (rm->briefPlayed[31] == false)
									{
										rm->brief[28]->stop();
										rm->brief[29]->stop();
										rm->brief[30]->stop();

										rm->briefPlayed[31] = true;
										rm->timePlayed[31] = chrono::system_clock::now();
										rm->brief[31]->play();
										rm->brief[31]->Update();
										interShader->ShowNarration(372, 8.0);
									}
									else if (rm->briefPlayed[32] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[31]);
										if (dt.count() > 8.0)
										{
											rm->briefPlayed[32] = true;
											rm->timePlayed[32] = chrono::system_clock::now();
											rm->brief[32]->play();
											rm->brief[32]->Update();
											interShader->ShowNarration(373, 10.0);
										}
									}


									for (int p = 0; p < playerShader->objects.size(); ++p)
									{
										float px = playerShader->objects[p]->GetPosition().x;
										float pz = playerShader->objects[p]->GetPosition().z;
										if (px >= 300.0f && px <= 400.0f && pz >= 0.0f && pz <= 100.0f)
										{
											interShader->nextPos = true;
											break;
										}
									}
								}

								if (interShader->nextPos == true)
								{
									interShader->nextPos = false;
									interShader->mission += 1;
									interShader->missionShow = true;
									interShader->missionChangedTime = chrono::system_clock::now();
									playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
								}

							}
							else
							{
								if (rm->briefPlayed[28] == false)
								{
									rm->brief[26]->stop();
									rm->brief[27]->stop();

									rm->briefPlayed[28] = true;
									rm->timePlayed[28] = chrono::system_clock::now();
									rm->brief[28]->play();
									rm->brief[28]->Update();
									interShader->ShowNarration(369, 8.0);
								}
								else  if (rm->briefPlayed[29] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[28]);
									if (dt.count() > 8.0)
									{
										rm->briefPlayed[29] = true;
										rm->timePlayed[29] = chrono::system_clock::now();
										rm->brief[29]->play();
										rm->brief[29]->Update();
										interShader->ShowNarration(370, 6.0);
									}
								}
								else  if (rm->briefPlayed[30] == false)
								{
									chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[29]);
									if (dt.count() > 6.0)
									{
										rm->briefPlayed[30] = true;
										rm->timePlayed[30] = chrono::system_clock::now();
										rm->brief[30]->play();
										rm->brief[30]->Update();
										interShader->ShowNarration(371, 6.0);
									}
								}
							}
						}
						else if (interShader->mission == 6)
						{
							chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
							chrono::duration<double> dt = mm - interShader->missionChangedTime;
							if (dt.count() > 25.0f)
							{
								if (interShader->nextPos == false)
								{

									if (rm->briefPlayed[34] == false)
									{
										rm->brief[33]->stop();

										rm->briefPlayed[34] = true;
										rm->timePlayed[34] = chrono::system_clock::now();
										rm->brief[34]->play();
										rm->brief[34]->Update();
										interShader->ShowNarration(376, 7.0);
									}
									else if (rm->briefPlayed[35] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[34]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[35] = true;
											rm->timePlayed[35] = chrono::system_clock::now();
											rm->brief[35]->play();
											rm->brief[35]->Update();
											interShader->ShowNarration(376, 6.0);
										}
									}

									for (int p = 0; p < playerShader->objects.size(); ++p)
									{
										float px = playerShader->objects[p]->GetPosition().x;
										float pz = playerShader->objects[p]->GetPosition().z;
										if (px >= 300.0f && px <= 400.0f && pz >= 100.0f && pz <= 200.0f)
										{
											interShader->nextPos = true;
											break;
										}
									}
								}

								if (interShader->nextPos == true)
								{
									interShader->nextPos = false;
									interShader->mission += 1;
									interShader->missionShow = true;
									interShader->missionChangedTime = chrono::system_clock::now();
									playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;

								}

							}
							else
							{
								if (rm->briefPlayed[33] == false)
								{
									rm->brief[31]->stop();
									rm->brief[32]->stop();

									rm->briefPlayed[33] = true;
									rm->timePlayed[33] = chrono::system_clock::now();
									rm->brief[33]->play();
									rm->brief[33]->Update();
									interShader->ShowNarration(374, 11.0);
								}
							}
						}
						else if (interShader->mission == 7)
						{
							chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
							chrono::duration<double> dt = mm - interShader->missionChangedTime;
							if (dt.count() < 80.0)
							{
								if (interShader->m7_kill >= 1)
								{
									//다음위치에 아군 단 한명이라도 도달할 경우
									if (interShader->nextPos == false)
									{

										if (rm->briefPlayed[38] == false)
										{
											rm->brief[36]->stop();
											rm->brief[37]->stop();

											rm->briefPlayed[38] = true;
											rm->timePlayed[38] = chrono::system_clock::now();
											rm->brief[38]->play();
											rm->brief[38]->Update();
											interShader->ShowNarration(377, 10.0);
										}


										for (int p = 0; p < playerShader->objects.size(); ++p)
										{
											float px = playerShader->objects[p]->GetPosition().x;
											float pz = playerShader->objects[p]->GetPosition().z;
											if (px >= 400.0f && px <= 450.0f && pz >= 100.0f && pz <= 200.0f)
											{
												interShader->nextPos = true;
												break;
											}
										}
									}

									if (interShader->nextPos == true)
									{
										interShader->nextPos = false;
										interShader->mission += 1;
										interShader->missionShow = true;
										interShader->missionChangedTime = chrono::system_clock::now();
										playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
									}
								}
								else
								{
									if (rm->briefPlayed[36] == false)
									{
										rm->brief[34]->stop();
										rm->brief[35]->stop();

										rm->briefPlayed[36] = true;
										rm->timePlayed[36] = chrono::system_clock::now();
										rm->brief[36]->play();
										rm->brief[36]->Update();
										interShader->ShowNarration(376, 10.0);
									}
									else  if (rm->briefPlayed[37] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[36]);
										if (dt.count() > 10.0)
										{
											rm->briefPlayed[37] = true;
											rm->timePlayed[37] = chrono::system_clock::now();
											rm->brief[37]->play();
											rm->brief[37]->Update();
											interShader->ShowNarration(376, 9.0);
										}
									}
								}
							}
							else
							{
								interShader->missionFail = true;
								interShader->timeFailed = chrono::system_clock::now();
							}

						}
						else if (interShader->mission == 8)
						{
							chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
							chrono::duration<double> dt = mm - interShader->missionChangedTime;
							if (dt.count() < 80.0)
							{
								if (interShader->m8_kill < 3)
								{
									if (interShader->nextPos == false)
									{

										if (rm->briefPlayed[39] == false)
										{
											rm->brief[38]->stop();
											

											rm->briefPlayed[39] = true;
											rm->timePlayed[39] = chrono::system_clock::now();
											rm->brief[39]->play();
											rm->brief[39]->Update();

											interShader->ShowNarration(378, 8.0);
										}
										else  if (rm->briefPlayed[40] == false)
										{
											chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[39]);
											if (dt.count() > 8.0)
											{
												rm->briefPlayed[40] = true;
												rm->timePlayed[40] = chrono::system_clock::now();
												rm->brief[40]->play();
												rm->brief[40]->Update();
												interShader->ShowNarration(378, 7.0);
											}
										}
										else  if (rm->briefPlayed[41] == false)
										{
											chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[40]);
											if (dt.count() > 7.0)
											{
												rm->briefPlayed[41] = true;
												rm->timePlayed[41] = chrono::system_clock::now();
												rm->brief[41]->play();
												rm->brief[41]->Update();
												interShader->ShowNarration(379, 7.0);
											}
										}

										for (int p = 0; p < playerShader->objects.size(); ++p)
										{
											float px = playerShader->objects[p]->GetPosition().x;
											float pz = playerShader->objects[p]->GetPosition().z;
											if (px >= 470.0f && px <= 540.0f && pz >= 60.0f && pz <= 150.0f)
											{
												interShader->nextPos = true;
												break;
											}

										}
									}
									if (interShader->nextPos == true)
									{
										interShader->nextPos = false;
										interShader->mission += 1;
										interShader->missionShow = true;
										interShader->missionChangedTime = chrono::system_clock::now();
										playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
									}
								}
								else
								{
									interShader->missionFail = true;
									interShader->timeFailed = chrono::system_clock::now();
								}
							}
							else
							{
								interShader->missionFail = true;
								interShader->timeFailed = chrono::system_clock::now();
							}

						}
						else if (interShader->mission == 9)
						{
							if (interShader->m9_stun == 0)
							{
								//if (interShader->m9_search >= 10)
								if (interShader->m9_search >= 1)
								{
									if (interShader->nextPos == false)
									{

										if (rm->briefPlayed[46] == false)
										{
											rm->brief[42]->stop();
											rm->brief[43]->stop();
											rm->brief[44]->stop();
											rm->brief[45]->stop();


											rm->briefPlayed[46] = true;
											rm->timePlayed[46] = chrono::system_clock::now();
											rm->brief[46]->play();
											rm->brief[46]->Update();
											interShader->ShowNarration(382, 8.0);
										}

										for (int p = 0; p < playerShader->objects.size(); ++p)
										{
											float px = playerShader->objects[p]->GetPosition().x;
											float pz = playerShader->objects[p]->GetPosition().z;
											if (px >= 470.0f && px <= 540.0f && pz >= 150.0f && pz <= 200.0f)
											{
												interShader->nextPos = true;
												break;
											}

										}
									}
									if (interShader->nextPos == true)
									{
										interShader->nextPos = false;
										interShader->mission += 1;
										interShader->missionShow = true;
										interShader->missionChangedTime = chrono::system_clock::now();
										playerShader->objects[pID]->info->stats.capacity = playerShader->objects[pID]->info->stats.maxhp;
									}
								}

								else
								{
									if (rm->briefPlayed[42] == false)
									{
										rm->brief[39]->stop();
										rm->brief[40]->stop();
										rm->brief[41]->stop();


										rm->briefPlayed[42] = true;
										rm->timePlayed[42] = chrono::system_clock::now();
										rm->brief[42]->play();
										rm->brief[42]->Update();

										interShader->ShowNarration(380, 5.0);
									}
									else  if (rm->briefPlayed[43] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[42]);
										if (dt.count() > 5.0)
										{
											rm->briefPlayed[43] = true;
											rm->timePlayed[43] = chrono::system_clock::now();
											rm->brief[43]->play();
											rm->brief[43]->Update();
											interShader->ShowNarration(380, 6.0);
										}
									}
									else  if (rm->briefPlayed[44] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[43]);
										if (dt.count() > 6.0)
										{
											rm->briefPlayed[44] = true;
											rm->timePlayed[44] = chrono::system_clock::now();
											rm->brief[44]->play();
											rm->brief[44]->Update();
											interShader->ShowNarration(380, 7.0);
										}
									}
									else  if (rm->briefPlayed[45] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[44]);
										if (dt.count() > 7.0)
										{
											rm->briefPlayed[45] = true;
											rm->timePlayed[45] = chrono::system_clock::now();
											rm->brief[45]->play();
											rm->brief[45]->Update();
											interShader->ShowNarration(381, 10.0);
										}
									}
								}
							}
							else
							{
								interShader->missionFail = true;
								interShader->timeFailed = chrono::system_clock::now();
							}
						}
						else if (interShader->mission == 10)
						{
							chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
							chrono::duration<double> dt = mm - interShader->missionChangedTime;
							if (dt.count() < 30.0)
							{
								if (interShader->m10_gain >= 1)
								{
									if (rm->briefPlayed[50] == false)
									{
										rm->brief[47]->stop();
										rm->brief[48]->stop();
										rm->brief[49]->stop();
										


										rm->briefPlayed[50] = true;
										rm->timePlayed[50] = chrono::system_clock::now();
										rm->brief[50]->play();
										rm->brief[50]->Update();
										interShader->ShowNarration(384, 8.0);
									}

									cleared = true;

								}
								else
								{
									if (rm->briefPlayed[47] == false)
									{
										rm->brief[46]->stop();


										rm->briefPlayed[47] = true;
										rm->timePlayed[47] = chrono::system_clock::now();
										rm->brief[47]->play();
										rm->brief[47]->Update();

										interShader->ShowNarration(383, 5.0);
									}
									else  if (rm->briefPlayed[48] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[47]);
										if (dt.count() > 5.0)
										{
											rm->briefPlayed[48] = true;
											rm->timePlayed[48] = chrono::system_clock::now();
											rm->brief[48]->play();
											rm->brief[48]->Update();
											interShader->ShowNarration(383, 6.0);
										}
									}
									else  if (rm->briefPlayed[49] == false)
									{
										chrono::duration<double> dt = (chrono::system_clock::now() - rm->timePlayed[48]);
										if (dt.count() > 6.0)
										{
											rm->briefPlayed[49] = true;
											rm->timePlayed[49] = chrono::system_clock::now();
											rm->brief[49]->play();
											rm->brief[49]->Update();
											interShader->ShowNarration(383, 5.0);
										}
									}
								}
							}
							else
							{
								interShader->missionFail = true;
								interShader->timeFailed = chrono::system_clock::now();
							}
						}
					}
					else if (waitInter->selectedStage == 2)
					{
					
					
						if (interShader->mission == 1)
						{
							if (interShader->m1_kill >= 20)
							{
								cleared = true;
							}
						}
					}
				}

				//if (enemyShader->objects.size() > 10)
				//{
					//cleared = false;
				//}
				if (cleared == true)
				{
					interShader->stageClear = true;
					interShader->clearTime = chrono::system_clock::now();

					interShader->objects[11]->m_ppMaterials[0] = rm->materials[276];
					interShader->objects[12]->m_ppMaterials[0] = rm->materials[273];
					interShader->objects[13]->m_ppMaterials[0] = rm->materials[273];

					interShader->objects[14]->m_ppMaterials[0] = rm->materials[276];
					interShader->objects[15]->m_ppMaterials[0] = rm->materials[273];
					interShader->objects[16]->m_ppMaterials[0] = rm->materials[273];

					interShader->objects[17]->m_ppMaterials[0] = rm->materials[276];
					interShader->objects[18]->m_ppMaterials[0] = rm->materials[273];
					interShader->objects[19]->m_ppMaterials[0] = rm->materials[273];

					interShader->objects[20]->m_ppMaterials[0] = rm->materials[278];
					interShader->objects[21]->m_ppMaterials[0] = rm->materials[273];
					interShader->objects[22]->m_ppMaterials[0] = rm->materials[273];



					//경험치 제공
					for (int i = 0; i < playerShader->objects.size(); ++i)
					{
						playerShader->objects[i]->amp_melee = 1.0f;
						playerShader->objects[i]->amp_ranged = 1.0f;
						playerShader->objects[i]->amp_radio = 1.0f;

						playerShader->objects[i]->info->growth.melee.exp += 300;
						playerShader->objects[i]->info->growth.ranged.exp += 300;
						playerShader->objects[i]->info->growth.radio.exp += 300;

						playerShader->objects[i]->info->growth.total.exp += 1500;

						playerShader->objects[i]->info->gold += 500;

						//경험치가 최대치를 넘어서면 레벨 업
						while (playerShader->objects[i]->info->growth.melee.exp >= expNeed[playerShader->objects[i]->info->growth.melee.level - 1])
						{
							playerShader->objects[i]->info->growth.melee.exp -= expNeed[playerShader->objects[i]->info->growth.melee.level - 1];
							playerShader->objects[i]->info->growth.melee.level += 1;
							playerShader->objects[i]->info->stats.maxhp += 3;
							playerShader->objects[i]->info->stats.capacity += 3;
							playerShader->objects[i]->info->stats.power += 2;
						}
						while (playerShader->objects[i]->info->growth.ranged.exp >= expNeed[playerShader->objects[i]->info->growth.ranged.level - 1])
						{
							playerShader->objects[i]->info->growth.ranged.exp -= expNeed[playerShader->objects[i]->info->growth.ranged.level - 1];
							playerShader->objects[i]->info->growth.ranged.level += 1;
							playerShader->objects[i]->info->stats.precision += 3;
							playerShader->objects[i]->info->stats.hardness += 2;
						}
						while (playerShader->objects[i]->info->growth.radio.exp >= expNeed[playerShader->objects[i]->info->growth.radio.level - 1])
						{
							playerShader->objects[i]->info->growth.radio.exp -= expNeed[playerShader->objects[i]->info->growth.radio.level - 1];
							playerShader->objects[i]->info->growth.radio.level += 1;
							playerShader->objects[i]->info->stats.entrophy += 1;
						}
						while (playerShader->objects[i]->info->growth.total.exp >= totalExpNeed[playerShader->objects[i]->info->growth.total.level - 1])
						{
							playerShader->objects[i]->info->growth.total.exp -= totalExpNeed[playerShader->objects[i]->info->growth.total.level - 1];
							playerShader->objects[i]->info->growth.total.level += 1;
							playerShader->objects[i]->info->extraPoint += 10;
						}

						//동료 지급
						playerShader->objects[i]->info->co_melee += 5;
						playerShader->objects[i]->info->co_ranged += 5;
						playerShader->objects[i]->info->co_radio += 3;
					}

				}


			}


			else if (interShader->stageClear == true)
			{
				chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
				chrono::duration<double> dt = moment - interShader->clearTime;

				if ((float)dt.count() > 15.0f)
				{

					//플레이어의 상태 초기화
					for (int k = 0; k < playerShader->objects.size(); ++k)
					{
						playerShader->objects[k]->amp_melee = 1.0f;
						playerShader->objects[k]->amp_ranged = 1.0f;
						playerShader->objects[k]->amp_radio = 1.0f;
						playerShader->objects[k]->bState.attacking = false;
						playerShader->objects[k]->info->stats.capacity = playerShader->objects[k]->info->stats.maxhp;
						playerShader->objects[k]->bState.attackID = TYPE_RANGED;
						playerShader->objects[k]->bState.stateID = IDLE_STATE;

						playerShader->objects[k]->kState.isInAir = 0;
						playerShader->objects[k]->kState.isMobile = 0;
						playerShader->objects[k]->kState.rotation = 0.0f;
						playerShader->objects[k]->kState.xzspeed = 0.0f;
						playerShader->objects[k]->kState.yspeed = 0.0f;
						playerShader->objects[k]->readyToGo = false;
					}



					//enemyShader->objects.clear();
					//enemyShader->BuildObjects(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
					enemyShader->restart();

					rm->bgm[0]->stop();
					rm->bgm[0]->Update();
					rm->bgm[1]->play();
					rm->bgm[1]->Update();

					//선택된 스테이지에 관한 정보 초기화.
					interShader->stageClear = false;
					interShader->missionFail = false;

					for (int i = 0; i < rm->briefPlayed.size(); ++i)
					{
						rm->brief[i]->stop();
						rm->brief[i]->Update();
						rm->briefPlayed[i] = false;
						
					}
					interShader->narrationShow = false;
					interShader->lastNarrated = chrono::system_clock::now();
					interShader->nDuration = 0.0;

					interShader->m10_gain = 0;
					interShader->m10_miss = 0;
					interShader->m1_kill = 0;
					interShader->m2_stun = 0;
					interShader->m3_bother = 0;
					interShader->m4_kill = 0;
					interShader->m5_broken = 0;
					interShader->m6_broken = 0;
					interShader->m7_kill = 0;
					interShader->m8_kill = 0;
					interShader->m9_stun = 0;
					interShader->m9_search = 0;
					interShader->mission = 1;


					waitInter->selectedStage = -1;

					cam->m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
					cam->lx = 0.0f;
					cam->ly = 0.0f;
					cam->lz = 1.0f;
					cam->GenerateViewMatrix();
					cam->UpdateShaderVariables(pd3dCommandList);

					currentScreen = LOBBY_STATE;
					//스테이지 클리어 완료

					//플레이어 정보 서버로 전송하여 저장하도록 하기
				}
			}
		}
		else if (interShader->missionFail == true)
		{
			

			chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
			chrono::duration<double> dt = mm - interShader->timeFailed;

			if (dt.count() > 5.0)
			{
				//플레이어의 상태 초기화
				for (int k = 0; k < playerShader->objects.size(); ++k)
				{
					playerShader->objects[k]->amp_melee = 1.0f;
					playerShader->objects[k]->amp_ranged = 1.0f;
					playerShader->objects[k]->amp_radio = 1.0f;

					playerShader->objects[k]->bState.attacking = false;
					playerShader->objects[k]->info->stats.capacity = playerShader->objects[k]->info->stats.maxhp;
					playerShader->objects[k]->bState.attackID = TYPE_RANGED;
					playerShader->objects[k]->bState.stateID = IDLE_STATE;

					playerShader->objects[k]->kState.isInAir = 0;
					playerShader->objects[k]->kState.isMobile = 0;
					playerShader->objects[k]->kState.rotation = 0.0f;
					playerShader->objects[k]->kState.xzspeed = 0.0f;
					playerShader->objects[k]->kState.yspeed = 0.0f;
				}
				enemyShader->restart();
				//선택된 스테이지에 관한 정보 초기화.
				rm->bgm[0]->stop();
				rm->bgm[0]->Update();
				rm->bgm[1]->play();
				rm->bgm[1]->Update();
				interShader->stageClear = false;
				waitInter->selectedStage = -1;
				interShader->missionFail = false;

				for (int i = 0; i < rm->briefPlayed.size(); ++i)
				{
					rm->brief[i]->stop();
					rm->brief[i]->Update();
					rm->briefPlayed[i] = false;

				}
				interShader->narrationShow = false;
				interShader->lastNarrated = chrono::system_clock::now();
				interShader->nDuration = 0.0;

				interShader->m10_gain = 0;
				interShader->m10_miss = 0;
				interShader->m1_kill = 0;
				interShader->m2_stun = 0;
				interShader->m3_bother = 0;
				interShader->m4_kill = 0;
				interShader->m5_broken = 0;
				interShader->m6_broken = 0;
				interShader->m7_kill = 0;
				interShader->m8_kill = 0;
				interShader->m9_stun = 0;
				interShader->m9_search = 0;
				interShader->mission = 1;

				cam->m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
				cam->lx = 0.0f;
				cam->ly = 0.0f;
				cam->lz = 1.0f;
				cam->GenerateViewMatrix();
				cam->UpdateShaderVariables(pd3dCommandList);
			   
				currentScreen = LOBBY_STATE;
			}
		}

		m_pLights[1].m_xmf3Position = XMFLOAT3(cp.x, cp.y, cp.z);
		m_pLights[1].m_xmf3Direction = Vector3::Normalize(XMFLOAT3(cl.x, cl.y, cl.z));
		
		UpdateShaderVariables(pd3dCommandList);
	}
	else if (currentScreen == LOGIN_STATE)
	{
		lobbyInter->Animate(cam);
	}
	else if (currentScreen == LOBBY_STATE)
	{
		mainInter->Animate(cam);
	}
	else if (currentScreen == PROFILE_STATE)
	{
		profileInter->Animate(cam, playerShader->objects[pID]->info);
	}
	else if (currentScreen == STAGE_SELECT_STATE)
	{
		stageInter->Animate(cam);
	}
	else if (currentScreen == WAIT_STATE)
	{
		// 모든 플레이어가 시작버튼을 눌렀을 때 비로소 시작.
		waitInter->Animate(cam, playerShader->objects[pID]->info);
		bool ready = true;

		for (int i = playerShader->objects.size(); i < 3; ++i)
		{
			waitInter->objects[24 + i * 5]->SetMesh(NULL);
			waitInter->objects[25 + i * 5]->SetMesh(NULL);
			waitInter->objects[26 + i * 5]->SetMesh(NULL);
			waitInter->objects[27 + i * 5]->SetMesh(NULL);
			waitInter->objects[28 + i * 5]->SetMesh(NULL);
		}
		for (int i = 0; i < playerShader->objects.size(); ++i)
		{
			if (playerShader->objects[i]->readyToGo == false)
			{
				waitInter->objects[28+i*5]->SetMesh(NULL);
			}
			else
			{
				waitInter->objects[28+i*5]->SetMesh(waitInter->meshes[28+i*5]);
				waitInter->objects[28 + i * 5]->m_ppMaterials[0] = rm->materials[339];
			}
		}

		if (waitInter->selectedStage == 1)
		{
			waitInter->objects[23]->m_ppMaterials[0] = rm->materials[299];
		}
		else if (waitInter->selectedStage == 2)
		{
			waitInter->objects[23]->m_ppMaterials[0] = rm->materials[300];
		}


		for (int i = 0; i < playerShader->objects.size(); ++i)
		{
			if (playerShader->objects[i]->readyToGo == false)
			{
				ready = false;
			}
		}
		if (ready == true)
		{
			currentScreen = IN_GAME_STATE;

			CS_POWER_PACKET pac;
			pac.size = sizeof(CS_POWER_PACKET);
			pac.type = PACKET_TYPE::CS_POWER;
			pac.c_id = pID;

			
			

			pac.stats.capacity = playerShader->objects[pID]->info->getCapacity();
			pac.stats.maxhp = playerShader->objects[pID]->info->getCapacity();
			pac.stats.power = playerShader->objects[pID]->info->getPower();
			pac.stats.hardness = playerShader->objects[pID]->info->getHardness();
			pac.stats.precision = playerShader->objects[pID]->info->getPrecision();
			pac.stats.entrophy = playerShader->objects[pID]->info->getEntrophy();
			pac.rAttack = playerShader->objects[pID]->info->slot.rangedWeapon->stats.attack;
			pac.mAttack = playerShader->objects[pID]->info->slot.meleeWeapon->stats.attack;

			pac.mWeapon = playerShader->objects[pID]->info->slot.meleeWeapon->type;
			pac.rWeapon = playerShader->objects[pID]->info->slot.rangedWeapon->type;

			SendPacket(&pac);

			rm->bgm[1]->stop();
			rm->bgm[1]->Update();
			rm->bgm[0]->play();
			rm->bgm[0]->Update();


			for (int e = 0; e < enemyShader->objects.size(); ++e)
			{
				
				enemyShader->objects[e]->maxHP *= waitInter->selectedMode;
				enemyShader->objects[e]->bState.hp *= waitInter->selectedMode;
			}

			for (int idx = 0; idx < playerShader->objects.size(); ++idx)
			{
				//1-1스테이지
				if (waitInter->selectedStage == 1)
				{
					playerShader->objects[idx]->SetPosition(20.0f + idx * 5.0f, 0.0f, 175.0f);
					//playerShader->objects[idx]->SetPosition(198.0f + idx * 5.0f, 0.0f, 198.0f);
					if (idx == pID)
					{
						cam->move(playerShader->objects[idx]->GetPosition());
						interShader->missionChangedTime = chrono::system_clock::now();
						interShader->Animate(cam, playerShader->objects[pID]->info);
					}
				}
				else if (waitInter->selectedStage == 2)
				{
					//1-2스테이지인경우 2-1
					playerShader->objects[idx]->SetPosition(830.0f, 0.0f, 580.0f - idx * 5.0f);

					charShd->oe.clear();
					
					if (idx == pID)
					{
						cam->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(cam, playerShader->objects[pID]->info);
					}

					enemyShader->objects.clear();
				}
				playerShader->objects[idx]->readyToGo = false;
			}
		}
		
	}
}

void CScene::Render(ID3D12GraphicsCommandList *pd3dCommandList, CCamera *pCamera)
{
	if (m_pd3dGraphicsRootSignature) pd3dCommandList->SetGraphicsRootSignature(m_pd3dGraphicsRootSignature);

	pCamera->SetViewportsAndScissorRects(pd3dCommandList);
	pCamera->UpdateShaderVariables(pd3dCommandList);

	UpdateShaderVariables(pd3dCommandList);

	D3D12_GPU_VIRTUAL_ADDRESS d3dcbLightsGpuVirtualAddress = m_pd3dcbLights->GetGPUVirtualAddress();
	pd3dCommandList->SetGraphicsRootConstantBufferView(2, d3dcbLightsGpuVirtualAddress); //Lights

	D3D12_GPU_VIRTUAL_ADDRESS d3dcbMat = m_pd3dcbMaterials->GetGPUVirtualAddress();
	pd3dCommandList->SetGraphicsRootConstantBufferView(7, d3dcbMat); // Materials


	float alpha = 1.0f;
	
	if (pID < playerShader->objects.size())
	{
		XMFLOAT3 cp = playerShader->objects[pID]->GetPosition();

		pd3dCommandList->SetGraphicsRoot32BitConstants(8, 1, &alpha, 0);
		if (currentScreen == IN_GAME_STATE)
		{

			if (playerShader)
			{
				playerShader->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}
				playerShader->Render(pd3dCommandList, pCamera, m_fElapsedTime, rm->m_pd3dCbvSrvDescriptorHeap);


			}






			//1-1
			if (((cp.x >= 0.0f && cp.x <= 200.0f) && (cp.z >= 0.0f && cp.z <= 150.0f)) || ((cp.x >= 0.0f && cp.x <= 190.0f) && (cp.z >= 150.0f && cp.z <= 200.0f)))
			{
				if (terrain1_1)
				{
					terrain1_1->OnPrepareRender(pd3dCommandList);
					terrain1_1->Render(pd3dCommandList, pCamera);
				}
			}
			//1-1, 1-2 이어지는 문 사이
			else if ((cp.x >= 190.0f && cp.x <= 230.0f) && (cp.z >= 150.0f && cp.z <= 200.0f))
			{
				if (terrain1_1)
				{
					terrain1_1->OnPrepareRender(pd3dCommandList);
					terrain1_1->Render(pd3dCommandList, pCamera);
				}
				if (terrain1_2)
				{
					terrain1_2->OnPrepareRender(pd3dCommandList);
					terrain1_2->Render(pd3dCommandList, pCamera, m_fElapsedTime);
				}
			}

			//1-2
			else if ((cp.x >= 200.0f && cp.x <= 600.0f) && cp.z >= 0.0f && cp.z <= 200.0f)
			{
				if (terrain1_2)
				{
					terrain1_2->OnPrepareRender(pd3dCommandList);
					terrain1_2->Render(pd3dCommandList, pCamera, m_fElapsedTime);

				}

			}

			//1-3
			else if ((cp.x >= 400.0f && cp.x <= 600.0f) && cp.z >= 200.0f && cp.z <= 600.0f)
			{
				if (terrain1_3)
				{
					terrain1_3->OnPrepareRender(pd3dCommandList);
					terrain1_3->Render(pd3dCommandList, pCamera);
				}
			}


			//2-1
			else if ((cp.x >= 800.0f && cp.x <= 900.0f) && cp.z >= 375.0f && cp.z <= 600.0f)
			{
				if (terrain2_1)
				{
					terrain2_1->OnPrepareRender(pd3dCommandList);
					terrain2_1->Render(pd3dCommandList, pCamera);
				}
			}

			else if ((cp.x >= 800.0f && cp.x <= 900.0f) && cp.z >= 213.0f && cp.z <= 375.0f)
			{
				if (terrain2_1)
				{
					terrain2_1->OnPrepareRender(pd3dCommandList);
					terrain2_1->Render(pd3dCommandList, pCamera);
				}
				if (terrain2_2)
				{
					terrain2_2->OnPrepareRender(pd3dCommandList);
					terrain2_2->Render(pd3dCommandList, pCamera);
				}
			}
			//2-2
			else if ((cp.x >= 800.0f && cp.x <= 900.0f) && cp.z >= 60.0f && cp.z <= 213.0f)
			{
				if (terrain2_2)
				{
					terrain2_2->OnPrepareRender(pd3dCommandList);
					terrain2_2->Render(pd3dCommandList, pCamera);
				}
			}

			//2-3
			else if ((cp.x >= 900.0f && cp.x <= 1200.0f) && cp.z >= 60.0f && cp.z <= 150.0f)
			{
				if (terrain2_3)
				{
					terrain2_3->OnPrepareRender(pd3dCommandList);
					terrain2_3->Render(pd3dCommandList, pCamera);
				}
			}

			if (enemyShader)
			{
				enemyShader->OnPrepareRender(pd3dCommandList);
				enemyShader->Render(pd3dCommandList, pCamera, m_fElapsedTime, rm->m_pd3dCbvSrvDescriptorHeap);
			}

			if (enemyDying)
			{
				enemyDying->OnPrepareRender(pd3dCommandList);
				enemyDying->Render(pd3dCommandList, pCamera);
			}

			if (partShader)
			{
				partShader->OnPrepareRender(pd3dCommandList);
				partShader->Render(pd3dCommandList, pCamera);
			}
			if (boomShader)
			{
				boomShader->OnPrepareRender(pd3dCommandList);
				boomShader->Render(pd3dCommandList, pCamera);
			}
			if (sdwShader)
			{
				sdwShader->OnPrepareRender(pd3dCommandList);
				sdwShader->Render(pd3dCommandList, pCamera);
			}
			if (charShd)
			{
				charShd->OnPrepareRender(pd3dCommandList);
				charShd->Render(pd3dCommandList, pCamera);
			}
			if (barShader)
			{
				barShader->OnPrepareRender(pd3dCommandList);
				barShader->Render(pd3dCommandList, pCamera);
			}

			//UI는 무조건적으로 그려져야 하므로 깊이 검사를 해제하고 맨마지막에 그린다.
			if (interShader)
			{
				interShader->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}
				interShader->Render(pd3dCommandList, pCamera);
			}
		}

		else if (currentScreen == LOGIN_STATE)
		{
			if (lobbyInter)
			{
				lobbyInter->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}

				lobbyInter->Render(pd3dCommandList, pCamera);
			}
		}
		else if (currentScreen == LOBBY_STATE)
		{
			if (mainInter)
			{
				mainInter->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}

				mainInter->Render(pd3dCommandList, pCamera);
			}
		}
		else if (currentScreen == PROFILE_STATE)
		{
			if (profileInter)
			{
				profileInter->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}

				profileInter->Render(pd3dCommandList, pCamera);
			}
		}
		else if (currentScreen == STAGE_SELECT_STATE)
		{
			if (stageInter)
			{
				stageInter->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}

				stageInter->Render(pd3dCommandList, pCamera);
			}
		}
		else if (currentScreen == WAIT_STATE)
		{
			if (waitInter)
			{
				waitInter->OnPrepareRender(pd3dCommandList);
				if (rm->m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &rm->m_pd3dCbvSrvDescriptorHeap);
				}

				waitInter->Render(pd3dCommandList, pCamera);
			}
		}
	}
}




void CScene::CreateCbvSrvDescriptorHeaps(ID3D12Device* pd3dDevice, int nConstantBufferViews, int nShaderResourceViews)
{
	D3D12_DESCRIPTOR_HEAP_DESC d3dDescriptorHeapDesc;
	d3dDescriptorHeapDesc.NumDescriptors = nConstantBufferViews + nShaderResourceViews; //CBVs + SRVs 
	d3dDescriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	d3dDescriptorHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
	d3dDescriptorHeapDesc.NodeMask = 0;
	pd3dDevice->CreateDescriptorHeap(&d3dDescriptorHeapDesc, __uuidof(ID3D12DescriptorHeap), (void**)&m_pd3dCbvSrvDescriptorHeap);

	m_d3dCbvCPUDescriptorStartHandle = m_pd3dCbvSrvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	m_d3dCbvGPUDescriptorStartHandle = m_pd3dCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart();
	m_d3dSrvCPUDescriptorStartHandle.ptr = m_d3dCbvCPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * nConstantBufferViews);
	m_d3dSrvGPUDescriptorStartHandle.ptr = m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * nConstantBufferViews);

	m_d3dSrvCPUDescriptorNextHandle = m_d3dSrvCPUDescriptorStartHandle;
	m_d3dSrvGPUDescriptorNextHandle = m_d3dSrvGPUDescriptorStartHandle;
}

void CScene::CreateConstantBufferViews(ID3D12Device* pd3dDevice, int nConstantBufferViews, ID3D12Resource* pd3dConstantBuffers, UINT nStride)
{
	D3D12_GPU_VIRTUAL_ADDRESS d3dGpuVirtualAddress = pd3dConstantBuffers->GetGPUVirtualAddress();
	D3D12_CONSTANT_BUFFER_VIEW_DESC d3dCBVDesc;
	d3dCBVDesc.SizeInBytes = nStride;
	for (int j = 0; j < nConstantBufferViews; j++)
	{
		d3dCBVDesc.BufferLocation = d3dGpuVirtualAddress + (nStride * j);
		D3D12_CPU_DESCRIPTOR_HANDLE d3dCbvCPUDescriptorHandle;
		d3dCbvCPUDescriptorHandle.ptr = m_d3dCbvCPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * j);
		pd3dDevice->CreateConstantBufferView(&d3dCBVDesc, d3dCbvCPUDescriptorHandle);
	}
}

void CScene::CreateShaderResourceViews(ID3D12Device* pd3dDevice, CTexture* pTexture, UINT nDescriptorHeapIndex, UINT nRootParameterStartIndex)
{
	m_d3dSrvCPUDescriptorNextHandle.ptr += (::gnCbvSrvDescriptorIncrementSize * nDescriptorHeapIndex);
	m_d3dSrvGPUDescriptorNextHandle.ptr += (::gnCbvSrvDescriptorIncrementSize * nDescriptorHeapIndex);

	int nTextures = pTexture->GetTextures();
	for (int i = 0; i < nTextures; i++)
	{
		ID3D12Resource* pShaderResource = pTexture->GetResource(i);
		D3D12_SHADER_RESOURCE_VIEW_DESC d3dShaderResourceViewDesc = pTexture->GetShaderResourceViewDesc(i);
		pd3dDevice->CreateShaderResourceView(pShaderResource, &d3dShaderResourceViewDesc, m_d3dSrvCPUDescriptorNextHandle);
		m_d3dSrvCPUDescriptorNextHandle.ptr += ::gnCbvSrvDescriptorIncrementSize;
		pTexture->SetGpuDescriptorHandle(i, m_d3dSrvGPUDescriptorNextHandle);
		m_d3dSrvGPUDescriptorNextHandle.ptr += ::gnCbvSrvDescriptorIncrementSize;
	}
	int nRootParameters = pTexture->GetRootParameters();
	for (int i = 0; i < nRootParameters; i++) pTexture->SetRootParameterIndex(i, nRootParameterStartIndex + i);
}

void CScene::setPlayerAnimation(int a)
{
	playerShader->objects[0]->SetTrackAnimationSet(0, a);
	currentPlayerAnim = a;
}



bool CScene::moveObject(int idx,CCamera* pCamera)
{
	if (idx == pID)
	{
		chrono::duration<double> fromLastMove = chrono::system_clock::now() - playerShader->objects[idx]->lastMove;
		double time = fromLastMove.count();
		float fTime = static_cast<float>(time);

		//cout << "from last move " << fTime << endl;
		bool crash = false;
		float tx, ty, tz;
		bool stepOn;

		XMFLOAT3 lk = pCamera->getLook();
		float ag = atan2f(lk.x, lk.z);
		ag = ag / 3.141592f * 180.0f;




		if (playerShader->objects[idx]->kState.xzspeed > 0.0f || playerShader->objects[idx]->kState.yspeed != 0.0f)
		{

			float rd = XMConvertToRadians(playerShader->objects[idx]->kState.rotation);
			XMFLOAT3 dir = XMFLOAT3(cos(rd), 0.0f, sin(rd));

			tx = playerShader->objects[idx]->GetPosition().x + fTime * playerShader->objects[idx]->kState.xzspeed * dir.x;
			ty = playerShader->objects[idx]->GetPosition().y + fTime * playerShader->objects[idx]->kState.yspeed;
			tz = playerShader->objects[idx]->GetPosition().z + fTime * playerShader->objects[idx]->kState.xzspeed * -dir.z;



			float ox = playerShader->objects[idx]->GetPosition().x;
			float oz = playerShader->objects[idx]->GetPosition().z;
			float oy = playerShader->objects[idx]->GetPosition().y;



			float px = playerShader->objects[idx]->GetPosition().x;
			float pz = playerShader->objects[idx]->GetPosition().z;

			for (int i = 0; i < enemyShader->objects.size(); ++i)
			{
				XMFLOAT3 ep = enemyShader->objects[i]->GetPosition();
				float dx = ep.x - tx;
				float dz = ep.z - tz;
				float de = sqrt(dx * dx + dz * dz);
				if (de < 0.5f && enemyShader->objects[i]->erased==false)
				{
					tx = ox;
					ty = oy;
					tz = oz;
					
				}
			}
			for (int i = 0; i < playerShader->objects.size(); ++i)
			{
				XMFLOAT3 ep = playerShader->objects[i]->GetPosition();
				float dx = ep.x - tx;
				float dz = ep.z - tz;
				float de = sqrt(dx * dx + dz * dz);
				if (de < 0.8f && i!=pID)
				{
					tx = ox;
					ty = oy;
					tz = oz;
					
				}
			}

			//1-1구역에 있는가?
			if (tx >= 0.0f && tx <= 200.0f && tz >= 0.0f && tz <= 200.0f)
			{

				int oix = (int)(ox / 0.5f);
				int oiz = (int)(oz / 0.5f);

				int ix = (int)(tx / 0.5f);
				int iz = (int)(tz / 0.5f);

				if (playerShader->objects[idx]->kState.yspeed == 0.0f)
				{
					//다음위치의 높이가 저장된 높이맵의 해당위치 높이보다 낮은 경우 위치는 불변

					if (ty < height11[ix][iz])
					{
						crash = true;
					}
					//동일한경우 땅에 붙어서 쭈욱 이동
					else if (ty == height11[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 0;
						playerShader->objects[idx]->kState.yspeed = 0.0f;
						crash = false;
					}
					//더 위인경우 공중에 뜸
					else if (ty > height11[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
				}
				else if (playerShader->objects[idx]->kState.yspeed > 0.0f)
				{
					if (ty < height11[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;

						crash = true;
					}
					else if (ty > height11[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					else if (ty == height11[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}

				}
				else if (playerShader->objects[idx]->kState.yspeed < 0.0f)
				{

					//더 높은 곳을 향해 가는 경우
					if (height11[ix][iz] > height11[oix][oiz])
					{
						if (ty <= height11[ix][iz] && ty >= height11[ix][iz] - 0.3f)
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height11[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
							cout << "착지 높이" << height11[ix][iz] << endl;
						}
						else if (ty < height11[ix][iz] - 0.3f && ty >= height11[oix][oiz] + 0.3f)
						{

							crash = true;
						}
						else if (ty < height11[oix][oiz] + 0.3f && ty >= height11[oix][oiz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(ox, height11[oix][oiz], oz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else if (ty > height11[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;

						}
					}
					//지대가 낮은 곳으로 갈 경우
					else if (height11[ix][iz] < height11[oix][oiz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					//등고도인경우
					else if (height11[ix][iz] == height11[oix][oiz])
					{
						if (ty <= height11[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height11[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;
						}
					}
				}
			}

			//1-2	
			else if (tx > 200.0f && tx <= 600.0f && tz >= 0.0f && tz <= 200.0f)
			{


				// ix = (tx - 현재구역의 원점x좌표) / 0.5
				// iz = (tz - 현재구역의 원점z좌표) / 0.5
				//oix, oiz도 마찬가지.

				//그밑의 height 데이터 배열을 전부 해당 구역에 맞게 변경.
				// 인덱스도 x12 말고 자신의 구역에 맞게 변경.


				int oix = (int)((ox - 200.0f) / 0.5f);
				int oiz = (int)((oz - 0.0f) / 0.5f);

				int ix = (int)((tx - 200.0f) / 0.5f);

				int iz = (int)((tz - 0.0f) / 0.5f);

				if (playerShader->objects[idx]->kState.yspeed == 0.0f)
				{
					//다음위치의 높이가 저장된 높이맵의 해당위치 높이보다 낮은 경우 위치는 불변

					if (ty < height12[ix][iz])
					{
						crash = true;
					}
					//동일한경우 땅에 붙어서 쭈욱 이동
					else if (ty == height12[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 0;
						playerShader->objects[idx]->kState.yspeed = 0.0f;
						crash = false;
					}
					//더 위인경우 공중에 뜸
					else if (ty > height12[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
				}
				else if (playerShader->objects[idx]->kState.yspeed > 0.0f)
				{
					if (ty < height12[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;

						crash = true;
					}
					else if (ty > height12[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					else if (ty == height12[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}

				}
				else if (playerShader->objects[idx]->kState.yspeed < 0.0f)
				{

					//더 높은 곳을 향해 가는 경우
					if (height12[ix][iz] > height12[oix][oiz])
					{
						if (ty <= height12[ix][iz] && ty >= height12[ix][iz] - 0.3f)
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height12[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
							cout << "착지 높이" << height12[ix][iz] << endl;
						}
						else if (ty < height12[ix][iz] - 0.3f && ty >= height12[oix][oiz] + 0.3f)
						{

							crash = true;
						}
						else if (ty < height12[ix][iz] + 0.3f && ty >= height12[oix][oiz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(ox, height12[oix][oiz], oz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else if (ty > height12[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;

						}
					}
					//지대가 낮은 곳으로 갈 경우
					else if (height12[ix][iz] < height12[oix][oiz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					//등고도인경우
					else if (height12[ix][iz] == height12[oix][oiz])
					{
						if (ty <= height12[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height12[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;
						}
					}
				}
			}

			//2-1
			else if (tx > 800.0f && tx <= 900.0f && tz >= 363.0f && tz <= 600.0f)
			{


				// ix = (tx - 현재구역의 원점x좌표) / 0.5
				// iz = (tz - 현재구역의 원점z좌표) / 0.5
				//oix, oiz도 마찬가지.

				//그밑의 height 데이터 배열을 전부 해당 구역에 맞게 변경.
				// 인덱스도 x12 말고 자신의 구역에 맞게 변경.


				int oix = (int)((ox - 800.0f) / 0.5f);
				int oiz = (int)((oz - 363.0f) / 0.5f);

				int ix = (int)((tx - 800.0f) / 0.5f);

				int iz = (int)((tz - 363.0f) / 0.5f);

				if (playerShader->objects[idx]->kState.yspeed == 0.0f)
				{
					//다음위치의 높이가 저장된 높이맵의 해당위치 높이보다 낮은 경우 위치는 불변

					if (ty < height21[ix][iz])
					{
						crash = true;
					}
					//동일한경우 땅에 붙어서 쭈욱 이동
					else if (ty == height21[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 0;
						playerShader->objects[idx]->kState.yspeed = 0.0f;
						crash = false;
					}
					//더 위인경우 공중에 뜸
					else if (ty > height21[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
				}
				else if (playerShader->objects[idx]->kState.yspeed > 0.0f)
				{
					if (ty < height21[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;

						crash = true;
					}
					else if (ty > height21[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					else if (ty == height21[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}

				}
				else if (playerShader->objects[idx]->kState.yspeed < 0.0f)
				{

					//더 높은 곳을 향해 가는 경우
					if (height21[ix][iz] > height21[oix][oiz])
					{
						if (ty <= height21[ix][iz] && ty >= height21[ix][iz] - 0.3f)
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height21[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
							cout << "착지 높이" << height21[ix][iz] << endl;
						}
						else if (ty < height21[ix][iz] - 0.3f && ty >= height21[oix][oiz] + 0.3f)
						{

							crash = true;
						}
						else if (ty < height21[ix][iz] + 0.3f && ty >= height21[oix][oiz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(ox, height21[oix][oiz], oz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else if (ty > height21[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;

						}
					}
					//지대가 낮은 곳으로 갈 경우
					else if (height21[ix][iz] < height21[oix][oiz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					//등고도인경우
					else if (height21[ix][iz] == height21[oix][oiz])
					{
						if (ty <= height21[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height21[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;
						}
					}
				}
			}

			//2-2
			else if (tx > 800.0f && tx <= 900.0f && tz >= 60.0f && tz <= 363.0f)
			{


				// ix = (tx - 현재구역의 원점x좌표) / 0.5
				// iz = (tz - 현재구역의 원점z좌표) / 0.5
				//oix, oiz도 마찬가지.

				//그밑의 height 데이터 배열을 전부 해당 구역에 맞게 변경.
				// 인덱스도 x12 말고 자신의 구역에 맞게 변경.


				int oix = (int)((ox - 800.0f) / 0.5f);
				int oiz = (int)((oz - 60.0f) / 0.5f);

				int ix = (int)((tx - 800.0f) / 0.5f);

				int iz = (int)((tz - 60.0f) / 0.5f);

				if (playerShader->objects[idx]->kState.yspeed == 0.0f)
				{
					//다음위치의 높이가 저장된 높이맵의 해당위치 높이보다 낮은 경우 위치는 불변

					if (ty < height22[ix][iz])
					{
						crash = true;
					}
					//동일한경우 땅에 붙어서 쭈욱 이동
					else if (ty == height22[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 0;
						playerShader->objects[idx]->kState.yspeed = 0.0f;
						crash = false;
					}
					//더 위인경우 공중에 뜸
					else if (ty > height22[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
				}
				else if (playerShader->objects[idx]->kState.yspeed > 0.0f)
				{
					if (ty < height22[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;

						crash = true;
					}
					else if (ty > height22[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					else if (ty == height22[ix][iz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}

				}
				else if (playerShader->objects[idx]->kState.yspeed < 0.0f)
				{

					//더 높은 곳을 향해 가는 경우
					if (height22[ix][iz] > height22[oix][oiz])
					{
						if (ty <= height22[ix][iz] && ty >= height22[ix][iz] - 0.3f)
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height22[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
							cout << "착지 높이" << height22[ix][iz] << endl;
						}
						else if (ty < height22[ix][iz] - 0.3f && ty >= height22[oix][oiz] + 0.3f)
						{

							crash = true;
						}
						else if (ty < height22[ix][iz] + 0.3f && ty >= height22[oix][oiz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(ox, height22[oix][oiz], oz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else if (ty > height22[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;

						}
					}
					//지대가 낮은 곳으로 갈 경우
					else if (height22[ix][iz] < height22[oix][oiz])
					{
						playerShader->objects[idx]->kState.isInAir = 1;
						crash = false;
					}
					//등고도인경우
					else if (height22[ix][iz] == height22[oix][oiz])
					{
						if (ty <= height22[ix][iz])
						{
							playerShader->objects[idx]->kState.isInAir = 0;
							playerShader->objects[idx]->kState.yspeed = 0.0f;
							if (playerShader->objects[idx]->bState.stateID == JUMP_STATE)
							{
								playerShader->objects[idx]->bState.stateID = IDLE_STATE;
								playerShader->objects[idx]->stateChanged = true;
							}
							playerShader->objects[idx]->SetPosition(tx, height22[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera, playerShader->objects[pID]->info);
							}
							crash = true;
						}
						else
						{
							playerShader->objects[idx]->kState.isInAir = 1;
							crash = false;
						}
					}
				}
			}

			//===================================================================================//


			if (crash == false)
			{
				XMFLOAT3 og = playerShader->objects[idx]->GetPosition();
				playerShader->objects[idx]->SetPosition(tx, ty, tz);
				if (idx == pID)
				{
					pCamera->move(playerShader->objects[idx]->GetPosition());
					interShader->Animate(pCamera, playerShader->objects[pID]->info);
				}
				//m_ppShadows[idx]->SetPosition(tx, -0.01f, tz);
				playerShader->objects[idx]->lastMoveSuccess = true;

				// y축 이동이 존재할 경우 중력가속도 적용
				if (playerShader->objects[idx]->kState.isInAir == 1)
				{
					playerShader->objects[idx]->kState.yspeed -= 9.8f * fTime * 5.0f;
				}
			}

			else
			{
				playerShader->objects[idx]->lastMoveSuccess = false;
				if (playerShader->objects[idx]->kState.isInAir == 1)
				{
					playerShader->objects[idx]->SetPosition(playerShader->objects[idx]->GetPosition().x, ty, playerShader->objects[idx]->GetPosition().z);
					pCamera->move(playerShader->objects[idx]->GetPosition().x, ty, playerShader->objects[idx]->GetPosition().z);
					interShader->Animate(pCamera, playerShader->objects[pID]->info);
					playerShader->objects[idx]->lastMoveSuccess = true;


					playerShader->objects[idx]->kState.yspeed -= 9.8f * fTime * 5.0f;

				}

			}
			return true;

		}
		else
		{
			playerShader->objects[idx]->bState.stateID = IDLE_STATE;
			playerShader->objects[idx]->kState.isInAir = 0;
			
			return false;
		}

	}

	
	

	// 여기까지 완료한 후, 몇번째 클라이언트의 플레이어인지 나타내는 idx값, 
	// 변경 완료된 위치 값을 클라로 전송.
	// moveObject 함수는 매 프레임마다 호출되므로 서버에서도 약 0.016초(초당 60프레임 기준)마다 전송해주는게 좋음.
}






bool CScene::moveSuccessed(int idx)
{
	return playerShader->objects[idx]->lastMoveSuccess;
}

void CScene::rotateObject(int idx, float x, float y, float z)
{
	//플레이어가 현재 바라보는 방향을 계산한다.
	//이걸 서버가 해야 된다.
	playerShader->objects[idx]->Rotate(x, y, z);
	playerShader->objects[idx]->currentRotation.x += x;
	playerShader->objects[idx]->currentRotation.y += y;
	playerShader->objects[idx]->currentRotation.z += z;

	if (playerShader->objects[idx]->currentRotation.x >= 360.0f)
	{
		playerShader->objects[idx]->currentRotation.x -= 360.0f;
	}
	if (playerShader->objects[idx]->currentRotation.y >= 360.0f)
	{
		playerShader->objects[idx]->currentRotation.y -= 360.0f;
	}
	if (playerShader->objects[idx]->currentRotation.z >= 360.0f)
	{
		playerShader->objects[idx]->currentRotation.z -= 360.0f;
	}

	if (playerShader->objects[idx]->currentRotation.x < 0.0f)

	{
		playerShader->objects[idx]->currentRotation.x += 360.0f;
	}
	if (playerShader->objects[idx]->currentRotation.y < 0.0f)
	{
		playerShader->objects[idx]->currentRotation.y += 360.0f;
	}
	if (playerShader->objects[idx]->currentRotation.z < 0.0f)
	{
		playerShader->objects[idx]->currentRotation.z += 360.0f;
	}
	//이런 다음, currentRotation값을 클라에 넘겨주면 된다.
}
void CScene::setPlayerDirection(float dx, float dy, float dz)
{
	if (playerShader->objects[pID]->kState.rotation != dy)
	{
		playerShader->objects[0]->Rotate(0.0f, dy - playerShader->objects[0]->kState.rotation, 0.0f);
		playerShader->objects[0]->kState.rotation = dy;
	}
}

//client to server (received)
//client to server (received)
void CScene::recv_packet(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	g_client.m_recv_over.m_wsabuf.buf = reinterpret_cast<char*>(g_client.m_recv_over.m_sendbuf) + g_client.m_prev_size;
	g_client.m_recv_over.m_wsabuf.len = BUFSIZE - g_client.m_prev_size;

	memset(&g_client.m_recv_over.m_over, 0, sizeof(g_client.m_recv_over.m_over));

	DWORD iobyte, flag = 0;
	int ret = WSARecv(g_client.m_sock, &g_client.m_recv_over.m_wsabuf, 1,
		&iobyte, &flag, NULL, NULL);
	if (0 != ret) {
		auto errcode = WSAGetLastError();
		if (WSA_IO_PENDING != errcode)
			err_display("Error in RecvPacket: ");
		else if (WSA_IO_PENDING == errcode)
			cout << "received..\n";
	}

	unsigned char* packet_ptr = g_client.m_recv_over.m_sendbuf;
	int num_data = iobyte + g_client.m_prev_size;
	int packet_size = packet_ptr[0];

	while (num_data >= packet_size) {
		ProcessPacket(packet_ptr, pd3dDevice, pd3dCommandList, pCamera);
		num_data -= packet_size;
		packet_ptr += packet_size;
		if (0 >= num_data) break;
		packet_size = packet_ptr[0];
	}
	g_client.m_prev_size = num_data;
	if (0 != num_data) {
		memcpy(g_client.m_recv_over.m_sendbuf, packet_ptr, num_data);
	}

}



void CScene::ProcessPacket(unsigned char* p_buf, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	char buf[10000];
	PACKET_TYPE type = (PACKET_TYPE)p_buf[1];

	//buf[0] = packet size
	//buf[1] = packet type

	switch (type)
	{
	case PACKET_TYPE::SC_MISSION:
	{
		SC_MISSION_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);

		if (p.number == 3)
		{
			terrain1_1->objects[p.target]->broke -= 1;
			if (terrain1_1->objects[p.target]->broke <= 0)
			{

				interShader->m3_bother += p.progress;
				terrain1_1->objects[p.target]->SetPosition(-100.0f, -100.0f, -100.0f);
				terrain1_1->boxesWorld[p.target].start = XMFLOAT3(-1000.0f, -1000.0f, -1000.0f);
				terrain1_1->boxesWorld[p.target].end = XMFLOAT3(-100.0f, -100.0f, -100.0f);
			}
		}
		else if (p.number == 5)
		{
			chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
			chrono::duration<double> dt = mm - interShader->missionChangedTime;
			if (dt.count() <= 25.0)
			{
				terrain1_2->objects[p.target]->broke -= 1;
				if (terrain1_2->objects[p.target]->broke <= 0)
				{
					interShader->m5_broken += p.progress;
					terrain1_2->objects[p.target]->SetPosition(-100.0f, -100.0f, -100.0f);
					terrain1_2->boxesWorld[p.target].start = XMFLOAT3(-1000.0f, -1000.0f, -1000.0f);
					terrain1_2->boxesWorld[p.target].end = XMFLOAT3(-100.0f, -100.0f, -100.0f);
				}
			}
		}
		else if (p.number == 6)
		{
			chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
			chrono::duration<double> dt = mm - interShader->missionChangedTime;
			if (dt.count() <= 25.0)
			{
				terrain1_2->objects[p.target]->broke -= 1;
				if (terrain1_2->objects[p.target]->broke <= 0)
				{
					interShader->m6_broken += p.progress;
					terrain1_2->objects[p.target]->SetPosition(-100.0f, -100.0f, -100.0f);
					terrain1_2->boxesWorld[p.target].start = XMFLOAT3(-1000.0f, -1000.0f, -1000.0f);
					terrain1_2->boxesWorld[p.target].end = XMFLOAT3(-100.0f, -100.0f, -100.0f);
				}
			}
		}
		else if (p.number == 9)
		{
			interShader->m9_search += p.progress;
			
		}
		break;
	}

	case PACKET_TYPE::SC_PARTICLE:
	{
		SC_PARTICLE_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);


		


		if (p.particleType == 1)
		{
			partShader->createParticles(p.particleType, p.count, XMFLOAT3(p.x, p.y, p.z), pd3dDevice, pd3dCommandList, p.xdir, p.zdir);
		}
		else
		{
			partShader->createParticles(p.particleType, p.count, XMFLOAT3(p.x, p.y, p.z), pd3dDevice, pd3dCommandList, p.xdir, p.zdir);
		}
		break;
	}
	case PACKET_TYPE::SC_POWER:
	{
		SC_POWER_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);

		playerShader->objects[p.c_id]->info->stats = p.stats;
		playerShader->objects[p.c_id]->info->slot.meleeWeapon->stats.attack = p.m;
		playerShader->objects[p.c_id]->info->slot.rangedWeapon->stats.attack = p.r;
		playerShader->objects[p.c_id]->info->slot.meleeWeapon->type = p.mw;
		playerShader->objects[p.c_id]->info->slot.rangedWeapon->type = p.rw;
		break;
	}

	case PACKET_TYPE::SC_READY:
	{
		SC_READY_PACKET pac;
		memcpy(&pac, p_buf, p_buf[0]);

		playerShader->objects[pac.id]->readyToGo = pac.ready;
		break;
	}
	case PACKET_TYPE::SC_STATE:
	{
		SC_STATE_PACKET pac;
		memcpy(&pac, p_buf, p_buf[0]);

		playerShader->objects[pac.id]->bState.attackID = pac.attackID;
		playerShader->objects[pac.id]->bState.stateID = pac.stateID;
		break;
	}
	case PACKET_TYPE::SC_POSITION:
	{
		SC_POSITION_PACKET pac;
		memcpy(&pac, p_buf, p_buf[0]);
		
		if (pac.id != pID)
		{
			playerShader->objects[pac.id]->SetPosition(pac.x, pac.y, pac.z);
			playerShader->objects[pac.id]->Rotate(0.0f, pac.angle + 90.0f, 0.0f);
			playerShader->objects[pac.id]->kState.rotation = pac.angle;
		}
		
		break;

	}
	case PACKET_TYPE::SC_LOGIN_INFO:
	{
		SC_LOGIN_INFO_PACKET p_login;
		memcpy(&p_login, p_buf, p_buf[0]);
		if (p_login.isLogin)
		{
			XMFLOAT3 pos = XMFLOAT3{ p_login.x, p_login.y, p_login.z };
			playerShader->addPlayer(pd3dDevice, pd3dCommandList, pos, m_pd3dGraphicsRootSignature);

			pID = p_login.id;
			
			
			
			cout << "\nPlayer ID : " << p_login.id << "\n" << endl;
			cout << "x,y,z = " << p_login.x << p_login.y << p_login.z << "\n" << endl;
		}
		break; 
	}

	case PACKET_TYPE::SC_ADD_PLAYER:
	{
		cout << "New Player Connected.\n";
		SC_ADD_PLAYER_PACKET p_new;
		memcpy(&p_new, p_buf, p_buf[0]);
		XMFLOAT3 pos = XMFLOAT3(p_new.pos.x, p_new.pos.y, p_new.pos.z);
		KineticState k = p_new.kState;
		BionicState b = p_new.bState;
		
		playerShader->objects[p_new.id]->kState = k;
		playerShader->objects[p_new.id]->bState = b;
		pCamera->angle = p_new.camAngle;
		pCamera->currentUp = p_new.camUp;
		//XMFLOAT3 pos = XMFLOAT3{ p_new.x, p_new.y, p_new.z };
		//playerShader->objects[p_new.id]->SetPosition(pos);
		break;
	}
	case PACKET_TYPE::SC_REMOVE_PLAYER:
	{
		SC_REMOVE_PLAYER_PACKET p_remove;
		memcpy(&p_remove, p_buf, p_buf[0]);
		cout << p_remove.id << "Player REMOVED.\n";
		playerShader->objects[p_remove.id]->m_bActive = false;
		//player remove
		break;
		
	}
	case PACKET_TYPE::SC_KINETIC_CHANGE:
	{
		SC_KINETIC_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);

		int ID = p.c_id;
		if (p.kState.isInAir != -9999)
		{
			playerShader->objects[ID]->kState.isInAir = p.kState.isInAir;
		}
		if (p.kState.isMobile != -9999)
		{
			playerShader->objects[ID]->kState.isMobile = p.kState.isMobile;
		}
		if (p.kState.rotation != -9999.0f)
		{
			float tangle = -p.kState.rotation + (playerShader->objects[ID]->kState.rotation);
			playerShader->objects[ID]->kState.rotation = -p.kState.rotation;

			
			
			//playerShader->objects[ID]->Rotate(0.0f, -p.kState.rotation+90.0f, 0.0f);
		}
		if (p.kState.yspeed != -9999.0f)
		{
			playerShader->objects[ID]->kState.yspeed = p.kState.yspeed;
		}
		if (p.kState.xzspeed != -9999.0f)
		{
			playerShader->objects[ID]->kState.xzspeed = p.kState.xzspeed;
		}
		
		printf("client player kinetic state change complete\n");
		break;
	}
	case PACKET_TYPE::SC_BIONIC_CHANGE:
	{
		SC_BIONIC_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);

		int id = p.c_id;

		if (p.bState.attackID != -9999)
		{
			playerShader->objects[id]->bState.attackID = p.bState.attackID;
		}
		if (p.bState.stateID != -9999)
		{
			playerShader->objects[id]->bState.stateID = p.bState.stateID;
		}
		if (p.bState.isIntelligent != -9999)
		{
			playerShader->objects[id]->bState.isIntelligent = p.bState.isIntelligent;
		}
		if (p.bState.hp != -9999)
		{
			playerShader->objects[id]->bState.hp = p.bState.hp;
		}
		if (p.bState.attacking != -9999)
		{
			playerShader->objects[id]->bState.attacking = p.bState.attacking;
		}
		printf("client player bionic state change complete\n");
		break;
	}
	case PACKET_TYPE::SC_CAMERA_CHANGE:
	{
		SC_CAMERA_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);
		if (p.c_id == pID)
		{
			pCamera->angle = p.camAngle;
			pCamera->currentUp = p.camUp;

			XMFLOAT3 og = playerShader->objects[pID]->GetPosition();
			float r = playerShader->objects[pID]->kState.rotation;

			float dangle = (p.camAngle - 270.0f) - r;
			pCamera->rotate(og.x, og.z);
			pCamera->rotateUp();
			pCamera->GenerateViewMatrix();
			
			
			

			printf("client player camera transform complete\n");
		}
		break;
	}
	case PACKET_TYPE::SC_ATTACK:
	{
		SC_ATTACK_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);
		enemyShader->objects[p.target]->bState.hp -= p.damage;

		if (enemyShader->objects[p.target]->bState.hp <= 0)
		{
			if (interShader->mission == 1)
			{
				interShader->m1_kill += 1;
				
			}
			else if (interShader->mission == 4)
			{
				interShader->m4_kill += 1;
			}
			else if (interShader->mission == 7)
			{
				interShader->m7_kill += 1;
				
			}
			else if (interShader->mission == 8)
			{
				interShader->m8_kill += 1;
			}
			else if (interShader->mission == 9)

			{
				interShader->m9_stun += 1;
			}
			else if (interShader->mission == 10)
			{
				interShader->m10_gain += 1;
			}
			int rd = rand() % 2;
			if (rd == 0)
			{
				rm->effect[10]->play();
				rm->effect[10]->Update();
			}
			else
			{
				rm->effect[11]->play();
				rm->effect[11]->Update();
			}
		}
		else
		{
			if (p.stuntime > 3.0f)
			{
				enemyShader->objects[p.target]->stunned = true;
				enemyShader->objects[p.target]->stunDuration = p.stuntime;
				enemyShader->objects[p.target]->lastStun = chrono::system_clock::now();
				if (interShader->mission == 2 || interShader->mission == 8)
				{
					enemyShader->objects[p.target]->stunDuration = 300.0f;
				}
			}
		}
		
		break;
	}
	case PACKET_TYPE::SC_MOVE_PLAYER:
		//수정중
		break;
		//case PACKET_TYPE::SC_KEYBOARD_INPUT:

	case PACKET_TYPE::SC_JUMP:
	{
		SC_JUMP_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);
		cout << "jump player" << endl;
		playerShader->objects[p.id]->jump();
		break;
	}
	case PACKET_TYPE::SC_TELEPORT:
		SC_TELEPORT_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);
		cout << "teleport player" << endl;
		playerShader->objects[p.id]->SetPosition(p.x, p.y, p.z);
		if (p.id == pID)
		{
			pCamera->move(playerShader->objects[pID]->GetPosition());
			interShader->Animate(pCamera, playerShader->objects[pID]->info);
		}
		break;

	default:
		cout << "Unknown PACKET type [" << +p_buf[1] << "]" << endl;
		break;
	}

}

void CScene::attack(int idx, ID3D12Device* device, ID3D12GraphicsCommandList* list, CCamera* cam)
{
	chrono::duration<double> fromLastAttack = chrono::system_clock::now() - playerShader->objects[idx]->lastAttack;
	float fTime = static_cast<float>(fromLastAttack.count());


		if (fTime >= 1.0f / 6.0f)
		{
			rm->effect[0]->play();
			rm->effect[0]->Update();
			printf("time elapsed from last shot : %f\n", fTime);
			setObjectLastAttack(idx);


			XMFLOAT3 lk = cam->getLook();

			//printf("발사 각도 %f  ", playerShader->objects[idx]->currentRotation.y);
			XMFLOAT3 dir;

			float a = playerShader->objects[idx]->kState.rotation;

			dir = XMFLOAT3(cos(XMConvertToRadians(a)), 0.0f, -sin(XMConvertToRadians(a)));






			Line line;
			line.start = playerShader->objects[idx]->GetPosition(); // 사격 위치
			line.start.y += 1.0f;
			line.end = XMFLOAT3(line.start.x + dir.x * 3000.0f, line.start.y + dir.y * 3000.0f, line.start.z + dir.z * 3000.0f); // 사격 위치로부터 최대 사거리 1km에 도달한 지점

			printf("(%f, %f, %f) - (%f, %f, %f)\n", line.start.x, line.start.y, line.start.z, line.end.x, line.end.y, line.end.z);

			float minDist = 3000.0f; // 현재까지 구해진 타격 대상과의 거리, 초기값은 최대 사거리 100미터

			XMFLOAT3 d;
			float dist;
			XMFLOAT3 temp;

			int target = -1;  // 대상 객체
			XMFLOAT3 targetPos; // 타격 발생 지점
			int type = 0;
			XMFLOAT3 n = XMFLOAT3(line.end.x - line.start.x, line.end.y - line.start.y, line.end.z - line.start.z); // 사격 방향 노말벡터
			//printf("발사 방향 : %f, %f, %f\n", n.x, n.y, n.z);



			float px = playerShader->objects[idx]->GetPosition().x;
			float pz = playerShader->objects[idx]->GetPosition().z;

			//1-1구역인 경우
			if (px >= 0.0f && px <= 200.0f && pz >= 0.0f && pz <= 200.0f)
			{
				for (int i = 0; i < terrain1_1->nBox; ++i)
				{
					// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

					std::vector<XYZPlane> checkList;


					if (n.x > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain1_1->boxesWorld[i].start.x;
						checkList.push_back(p);
					}
					else if (n.x < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain1_1->boxesWorld[i].end.x;
						checkList.push_back(p);
					}

					if (n.z > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain1_1->boxesWorld[i].start.z;
						checkList.push_back(p);
					}
					else if (n.z < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain1_1->boxesWorld[i].end.z;
						checkList.push_back(p);
					}

					if (n.y > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain1_1->boxesWorld[i].start.y;
						checkList.push_back(p);
					}
					else if (n.y < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain1_1->boxesWorld[i].end.y;
						checkList.push_back(p);
					}


					//체크리스트에 들어있는 모든 평면들에 대해

					for (int j = 0; j < checkList.size(); ++j)
					{
						// 충돌 지점을 확보한다.
						temp = getIntersectPoint(line, checkList[j]);


						//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
						if ((temp.x <= terrain1_1->boxesWorld[i].end.x + 0.001f && temp.x >= terrain1_1->boxesWorld[i].start.x - 0.001f) &&
							(temp.y <= terrain1_1->boxesWorld[i].end.y + 0.001f && temp.y >= terrain1_1->boxesWorld[i].start.y - 0.001f) &&
							(temp.z <= terrain1_1->boxesWorld[i].end.z + 0.001f && temp.z >= terrain1_1->boxesWorld[i].start.z - 0.001f))
						{
							if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
							{
								//그 지점과의 거리를 구한 후,
								// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
								d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
								dist = Vector3::Length(d);
								printf("사거리 내에 위치, 거리 %f\n", dist);
								break;
							}
							else
							{
								printf("직선 앞 혹은 뒤에 위치\n");
								dist = 3000.0f;
							}
						}
						else
						{
							dist = 3000.0f;
						}
					}
					/*
					if (dist != 3000.0f)
					{
						printf("%d번째 박스와 타격 지점 (%f, %f, %f)\n", i, temp.x, temp.y, temp.z);
						printf("%d번째 박스와 거리 %f\n", i, dist);
					}
					*/
					// 총알은 관통 기능이 없다. 즉,
					// 충돌 지점의 거리가 기존에 계산했던 지점보다 짧은 경우 
					// 그 지점이 새로운 충돌지점이다.

					if (dist < minDist)
					{
						minDist = dist;
						targetPos = temp;
						target = i;
						type = 1;
					}

				}
			}
			//1-2
			if (px >= 200.0f && px <= 600.0f && pz >= 0.0f && pz <= 200.0f)
			{
				for (int i = 0; i < terrain1_2->nBox; ++i)
				{
					// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

					std::vector<XYZPlane> checkList;


					if (n.x > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain1_2->boxesWorld[i].start.x;
						checkList.push_back(p);
					}
					else if (n.x < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain1_2->boxesWorld[i].end.x;
						checkList.push_back(p);
					}

					if (n.z > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain1_2->boxesWorld[i].start.z;
						checkList.push_back(p);
					}
					else if (n.z < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain1_2->boxesWorld[i].end.z;
						checkList.push_back(p);
					}

					if (n.y > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain1_2->boxesWorld[i].start.y;
						checkList.push_back(p);
					}
					else if (n.y < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain1_2->boxesWorld[i].end.y;
						checkList.push_back(p);
					}


					//체크리스트에 들어있는 모든 평면들에 대해

					for (int j = 0; j < checkList.size(); ++j)
					{
						// 충돌 지점을 확보한다.
						temp = getIntersectPoint(line, checkList[j]);


						//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
						if ((temp.x <= terrain1_2->boxesWorld[i].end.x + 0.001f && temp.x >= terrain1_2->boxesWorld[i].start.x - 0.001f) &&
							(temp.y <= terrain1_2->boxesWorld[i].end.y + 0.001f && temp.y >= terrain1_2->boxesWorld[i].start.y - 0.001f) &&
							(temp.z <= terrain1_2->boxesWorld[i].end.z + 0.001f && temp.z >= terrain1_2->boxesWorld[i].start.z - 0.001f))
						{
							if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
							{
								//그 지점과의 거리를 구한 후,
								// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
								d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
								dist = Vector3::Length(d);
								printf("사거리 내에 위치, 거리 %f\n", dist);
								break;
							}
							else
							{
								printf("직선 앞 혹은 뒤에 위치\n");
								dist = 3000.0f;
							}
						}
						else
						{
							dist = 3000.0f;
						}
					}
					/*
					if (dist != 3000.0f)
					{
						printf("%d번째 박스와 타격 지점 (%f, %f, %f)\n", i, temp.x, temp.y, temp.z);
						printf("%d번째 박스와 거리 %f\n", i, dist);
					}
					*/
					// 총알은 관통 기능이 없다. 즉,
					// 충돌 지점의 거리가 기존에 계산했던 지점보다 짧은 경우 
					// 그 지점이 새로운 충돌지점이다.

					if (dist < minDist)
					{
						minDist = dist;
						targetPos = temp;
						target = i;
						type = 1;
					}

				}
			}

			//1-3
			if (px >= 400.0f && px <= 600.0f && pz >= 200.0f && pz <= 600.0f)
			{
				for (int i = 0; i < terrain1_3->nBox; ++i)
				{
					// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

					std::vector<XYZPlane> checkList;


					if (n.x > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain1_3->boxesWorld[i].start.x;
						checkList.push_back(p);
					}
					else if (n.x < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain1_3->boxesWorld[i].end.x;
						checkList.push_back(p);
					}

					if (n.z > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain1_3->boxesWorld[i].start.z;
						checkList.push_back(p);
					}
					else if (n.z < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain1_3->boxesWorld[i].end.z;
						checkList.push_back(p);
					}

					if (n.y > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain1_3->boxesWorld[i].start.y;
						checkList.push_back(p);
					}
					else if (n.y < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain1_3->boxesWorld[i].end.y;
						checkList.push_back(p);
					}


					//체크리스트에 들어있는 모든 평면들에 대해

					for (int j = 0; j < checkList.size(); ++j)
					{
						// 충돌 지점을 확보한다.
						temp = getIntersectPoint(line, checkList[j]);


						//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
						if ((temp.x <= terrain1_3->boxesWorld[i].end.x + 0.001f && temp.x >= terrain1_3->boxesWorld[i].start.x - 0.001f) &&
							(temp.y <= terrain1_3->boxesWorld[i].end.y + 0.001f && temp.y >= terrain1_3->boxesWorld[i].start.y - 0.001f) &&
							(temp.z <= terrain1_3->boxesWorld[i].end.z + 0.001f && temp.z >= terrain1_3->boxesWorld[i].start.z - 0.001f))
						{
							if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
							{
								//그 지점과의 거리를 구한 후,
								// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
								d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
								dist = Vector3::Length(d);
								printf("사거리 내에 위치, 거리 %f\n", dist);
								break;
							}
							else
							{
								printf("직선 앞 혹은 뒤에 위치\n");
								dist = 3000.0f;
							}
						}
						else
						{
							dist = 3000.0f;
						}
					}
					/*
					if (dist != 3000.0f)
					{
						printf("%d번째 박스와 타격 지점 (%f, %f, %f)\n", i, temp.x, temp.y, temp.z);
						printf("%d번째 박스와 거리 %f\n", i, dist);
					}
					*/
					// 총알은 관통 기능이 없다. 즉,
					// 충돌 지점의 거리가 기존에 계산했던 지점보다 짧은 경우 
					// 그 지점이 새로운 충돌지점이다.

					if (dist < minDist)
					{
						minDist = dist;
						targetPos = temp;
						target = i;
						type = 1;
					}

				}
			}

			//2-1
			if (px >= 800.0f && px <= 900.0f && pz >= 363.0f && pz <= 600.0f)
			{
				for (int i = 0; i < terrain2_1->nBox; ++i)
				{
					// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

					std::vector<XYZPlane> checkList;


					if (n.x > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain2_1->boxesWorld[i].start.x;
						checkList.push_back(p);
					}
					else if (n.x < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain2_1->boxesWorld[i].end.x;
						checkList.push_back(p);
					}

					if (n.z > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain2_1->boxesWorld[i].start.z;
						checkList.push_back(p);
					}
					else if (n.z < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain2_1->boxesWorld[i].end.z;
						checkList.push_back(p);
					}

					if (n.y > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain2_1->boxesWorld[i].start.y;
						checkList.push_back(p);
					}
					else if (n.y < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain2_1->boxesWorld[i].end.y;
						checkList.push_back(p);
					}


					//체크리스트에 들어있는 모든 평면들에 대해

					for (int j = 0; j < checkList.size(); ++j)
					{
						// 충돌 지점을 확보한다.
						temp = getIntersectPoint(line, checkList[j]);


						//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
						if ((temp.x <= terrain2_1->boxesWorld[i].end.x + 0.001f && temp.x >= terrain2_1->boxesWorld[i].start.x - 0.001f) &&
							(temp.y <= terrain2_1->boxesWorld[i].end.y + 0.001f && temp.y >= terrain2_1->boxesWorld[i].start.y - 0.001f) &&
							(temp.z <= terrain2_1->boxesWorld[i].end.z + 0.001f && temp.z >= terrain2_1->boxesWorld[i].start.z - 0.001f))
						{
							if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
							{
								//그 지점과의 거리를 구한 후,
								// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
								d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
								dist = Vector3::Length(d);
								printf("사거리 내에 위치, 거리 %f\n", dist);
								break;
							}
							else
							{
								printf("직선 앞 혹은 뒤에 위치\n");
								dist = 3000.0f;
							}
						}
						else
						{
							dist = 3000.0f;
						}
					}
					/*
					if (dist != 3000.0f)
					{
						printf("%d번째 박스와 타격 지점 (%f, %f, %f)\n", i, temp.x, temp.y, temp.z);
						printf("%d번째 박스와 거리 %f\n", i, dist);
					}
					*/
					// 총알은 관통 기능이 없다. 즉,
					// 충돌 지점의 거리가 기존에 계산했던 지점보다 짧은 경우 
					// 그 지점이 새로운 충돌지점이다.

					if (dist < minDist)
					{
						minDist = dist;
						targetPos = temp;
						target = i;
						type = 1;
					}

				}
			}

			//2-2
			if (px >= 800.0f && px <= 900.0f && pz >= 60.0f && pz <= 363.0f)
			{
				for (int i = 0; i < terrain2_2->nBox; ++i)
				{
					// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

					std::vector<XYZPlane> checkList;


					if (n.x > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain2_2->boxesWorld[i].start.x;
						checkList.push_back(p);
					}
					else if (n.x < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain2_2->boxesWorld[i].end.x;
						checkList.push_back(p);
					}

					if (n.z > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain2_2->boxesWorld[i].start.z;
						checkList.push_back(p);
					}
					else if (n.z < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain2_2->boxesWorld[i].end.z;
						checkList.push_back(p);
					}

					if (n.y > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain2_2->boxesWorld[i].start.y;
						checkList.push_back(p);
					}
					else if (n.y < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain2_2->boxesWorld[i].end.y;
						checkList.push_back(p);
					}


					//체크리스트에 들어있는 모든 평면들에 대해

					for (int j = 0; j < checkList.size(); ++j)
					{
						// 충돌 지점을 확보한다.
						temp = getIntersectPoint(line, checkList[j]);


						//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
						if ((temp.x <= terrain2_2->boxesWorld[i].end.x + 0.001f && temp.x >= terrain2_2->boxesWorld[i].start.x - 0.001f) &&
							(temp.y <= terrain2_2->boxesWorld[i].end.y + 0.001f && temp.y >= terrain2_2->boxesWorld[i].start.y - 0.001f) &&
							(temp.z <= terrain2_2->boxesWorld[i].end.z + 0.001f && temp.z >= terrain2_2->boxesWorld[i].start.z - 0.001f))
						{
							if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
							{
								//그 지점과의 거리를 구한 후,
								// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
								d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
								dist = Vector3::Length(d);
								printf("사거리 내에 위치, 거리 %f\n", dist);
								break;
							}
							else
							{
								printf("직선 앞 혹은 뒤에 위치\n");
								dist = 3000.0f;
							}
						}
						else
						{
							dist = 3000.0f;
						}
					}
					/*
					if (dist != 3000.0f)
					{
						printf("%d번째 박스와 타격 지점 (%f, %f, %f)\n", i, temp.x, temp.y, temp.z);
						printf("%d번째 박스와 거리 %f\n", i, dist);
					}
					*/
					// 총알은 관통 기능이 없다. 즉,
					// 충돌 지점의 거리가 기존에 계산했던 지점보다 짧은 경우 
					// 그 지점이 새로운 충돌지점이다.

					if (dist < minDist)
					{
						minDist = dist;
						targetPos = temp;
						target = i;
						type = 1;
					}

				}
			}

			//2-3
			if (px >= 900.0f && px <= 1200.0f && pz >= 60.0f && pz <= 150.0f)
			{
				for (int i = 0; i < terrain2_3->nBox; ++i)
				{
					// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

					std::vector<XYZPlane> checkList;


					if (n.x > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain2_3->boxesWorld[i].start.x;
						checkList.push_back(p);
					}
					else if (n.x < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
						p.pos = terrain2_3->boxesWorld[i].end.x;
						checkList.push_back(p);
					}

					if (n.z > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain2_3->boxesWorld[i].start.z;
						checkList.push_back(p);
					}
					else if (n.z < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
						p.pos = terrain2_3->boxesWorld[i].end.z;
						checkList.push_back(p);
					}

					if (n.y > 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain2_3->boxesWorld[i].start.y;
						checkList.push_back(p);
					}
					else if (n.y < 0.0f)
					{
						XYZPlane p;
						p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
						p.pos = terrain2_3->boxesWorld[i].end.y;
						checkList.push_back(p);
					}


					//체크리스트에 들어있는 모든 평면들에 대해

					for (int j = 0; j < checkList.size(); ++j)
					{
						// 충돌 지점을 확보한다.
						temp = getIntersectPoint(line, checkList[j]);


						//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
						if ((temp.x <= terrain2_3->boxesWorld[i].end.x + 0.001f && temp.x >= terrain2_3->boxesWorld[i].start.x - 0.001f) &&
							(temp.y <= terrain2_3->boxesWorld[i].end.y + 0.001f && temp.y >= terrain2_3->boxesWorld[i].start.y - 0.001f) &&
							(temp.z <= terrain2_3->boxesWorld[i].end.z + 0.001f && temp.z >= terrain2_3->boxesWorld[i].start.z - 0.001f))
						{
							if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
							{
								//그 지점과의 거리를 구한 후,
								// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
								d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
								dist = Vector3::Length(d);
								printf("사거리 내에 위치, 거리 %f\n", dist);
								break;
							}
							else
							{
								printf("직선 앞 혹은 뒤에 위치\n");
								dist = 3000.0f;
							}
						}
						else
						{
							dist = 3000.0f;
						}
					}
					/*
					if (dist != 3000.0f)
					{
						printf("%d번째 박스와 타격 지점 (%f, %f, %f)\n", i, temp.x, temp.y, temp.z);
						printf("%d번째 박스와 거리 %f\n", i, dist);
					}
					*/
					// 총알은 관통 기능이 없다. 즉,
					// 충돌 지점의 거리가 기존에 계산했던 지점보다 짧은 경우 
					// 그 지점이 새로운 충돌지점이다.

					if (dist < minDist)
					{
						minDist = dist;
						targetPos = temp;
						target = i;
						type = 1;
					}

				}
			}

			//===============================================================================//

			rm->effect[1]->play();
			rm->effect[1]->Update();
			// 적한테 총알이 박혔나?
			for (int i = 0; i < enemyShader->objects.size(); ++i)
			{
				// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

				std::vector<XYZPlane> checkList;


				if (n.x > 0.0f)
				{
					XYZPlane p;
					p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
					p.pos = enemyShader->objects[i]->mbox->start.x;
					checkList.push_back(p);
				}
				else if (n.x < 0.0f)
				{
					XYZPlane p;
					p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
					p.pos = enemyShader->objects[i]->mbox->end.x;
					checkList.push_back(p);
				}

				if (n.z > 0.0f)
				{
					XYZPlane p;
					p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
					p.pos = enemyShader->objects[i]->mbox->start.z;
					checkList.push_back(p);
				}
				else if (n.z < 0.0f)
				{
					XYZPlane p;
					p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
					p.pos = enemyShader->objects[i]->mbox->end.z;
					checkList.push_back(p);
				}

				if (n.y > 0.0f)
				{
					XYZPlane p;
					p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
					p.pos = enemyShader->objects[i]->mbox->start.y;
					checkList.push_back(p);
				}
				else if (n.y < 0.0f)
				{
					XYZPlane p;
					p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
					p.pos = enemyShader->objects[i]->mbox->end.y;
					checkList.push_back(p);
				}


				//체크리스트에 들어있는 모든 평면들에 대해

				for (int j = 0; j < checkList.size(); ++j)
				{
					// 충돌 지점을 확보한다.
					temp = getIntersectPoint(line, checkList[j]);


					//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
					if ((temp.x <= enemyShader->objects[i]->mbox->end.x + 0.001f && temp.x >= enemyShader->objects[i]->mbox->start.x - 0.001f) &&
						(temp.y <= enemyShader->objects[i]->mbox->end.y + 0.001f && temp.y >= enemyShader->objects[i]->mbox->start.y - 0.001f) &&
						(temp.z <= enemyShader->objects[i]->mbox->end.z + 0.001f && temp.z >= enemyShader->objects[i]->mbox->start.z - 0.001f))
					{
						if (temp.x != -9999.0f && temp.y != -9999.0f && temp.z != -9999.0f)
						{
							//그 지점과의 거리를 구한 후,
							// 어차피 실제 충돌 지점은 한 곳 뿐이므로 루프를 빠져나온다.
							d = XMFLOAT3(temp.x - line.start.x, temp.y - line.start.y, temp.z - line.start.z);
							dist = Vector3::Length(d);
							printf("사거리 내에 위치, 거리 %f\n", dist);
							break;
						}
						else
						{
							printf("직선 앞 혹은 뒤에 위치\n");
							dist = 3000.0f;
						}
					}
					else
					{
						dist = 3000.0f;
					}
				}

				if (dist < minDist)
				{
					minDist = dist;
					targetPos = temp;
					target = i;
					type = 2;
				}

			}
			if (type == 2)
			{
				if (idx == pID)
				{
					CS_ATTACK_PACKET p;
					p.type = PACKET_TYPE::CS_ATTACK;
					p.size = sizeof(CS_ATTACK_PACKET);
					p.target = target;
					p.id = pID;
					p.stuntime = 0.0f;
					p.damage = playerShader->objects[idx]->info->getRangedDamage() * playerShader->objects[idx]->amp_ranged;

					SendPacket(&p);
				}
				
			}
			else
			{
				if (interShader->mission == 3)
				{
					//3번째 미션 도중 제어단말을 맞힐 경우
					if (px >= 0.0f && px <= 200.0f && pz >= 0.0f && pz <= 200.0f)
					{
						if (terrain1_1->objects[target]->type == Controller1 || terrain1_1->objects[target]->type == Controller2 || terrain1_1->objects[target]->type == Controller4)
						{
							if (idx == pID)
							{
								CS_MISSION_PACKET pac;
								pac.id = pID;
								pac.size = sizeof(CS_MISSION_PACKET);
								pac.type = PACKET_TYPE::CS_MISSION;

								pac.number = 3;
								pac.progress = 1;
								pac.target = target;
								SendPacket(&pac);
							}

						}
					}
				}
				//5번 미션 도중 충전실을 맞힌때
				else if (interShader->mission == 5)
				{
					chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
					chrono::duration<double> dt = mm - interShader->missionChangedTime;


					if (px >= 200.0f && px <= 300.0f && pz >= 0.0f && pz <= 100.0f && dt.count()<30.0)
					{
						if (terrain1_2->objects[target]->type == ChargeSlot)
						{
							if (idx == pID)
							{
								CS_MISSION_PACKET pac;
								pac.id = pID;
								pac.size = sizeof(CS_MISSION_PACKET);
								pac.type = PACKET_TYPE::CS_MISSION;

								pac.number = 5;
								pac.progress = 1;
								pac.target = target;
								SendPacket(&pac);
							}
						}
					}
				}
				else if (interShader->mission == 6)
				{
					chrono::time_point<chrono::system_clock> mm = chrono::system_clock::now();
					chrono::duration<double> dt = mm - interShader->missionChangedTime;
					if (px >= 300.0f && px <= 400.0f && pz >= 0.0f && pz <= 100.0f && dt.count()<30.0)
					{
						if (terrain1_2->objects[target]->type == ChargeSlot)
						{
							if (idx == pID)
							{
								CS_MISSION_PACKET pac;
								pac.id = pID;
								pac.size = sizeof(CS_MISSION_PACKET);
								pac.type = PACKET_TYPE::CS_MISSION;

								pac.number = 6;
								pac.progress = 1;
								pac.target = target;
								SendPacket(&pac);
							}
						}
					}
				}
			}
			

			// type, target, targetPos 3개의 값이 전송되면, 클라는 그3개의 값을 받아서
			// 해당 위치에 불꽃이 튀는 듯한 파티클을 생성한다. 
			//partShader->createParticles(50, targetPos, device, list);
			if (idx == pID)
			{



				

				CS_PARTICLE_PACKET part;
				part.size = sizeof(CS_PARTICLE_PACKET);
				part.type = PACKET_TYPE::CS_PARTICLE;
				part.id = pID;

				//플레이어가 바라보는 방향과 정반대 방향
				float rd = XMConvertToRadians(-playerShader->objects[idx]->kState.rotation);
				XMFLOAT3 dir = XMFLOAT3(-cos(rd), 0.0f, -sin(rd));

				part.xdir = dir.x;
				part.zdir = dir.z;

				part.count = 100;
				part.x = targetPos.x;
				part.y = targetPos.y;
				part.z = targetPos.z;
				if (type == 2)
				{
					part.particleType = 2;
				}
				else
				{
					part.particleType = 1;
				}
				SendPacket(&part);
			}

			// 그니까, partShader->createParticles 함수는 서버의 전담이 아니다.
		}
	

}


void CScene::swingHammer(int idx, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

		chrono::duration<double> fromLastAttack = chrono::system_clock::now() - playerShader->objects[idx]->lastAttack;
		float fTime = static_cast<float>(fromLastAttack.count());

		if (fTime >= 1.0f)
		{
			//이동속도 원래대로
			if (playerShader->objects[idx]->bState.attacking == false)
			{
				playerShader->objects[idx]->kState.xzspeed = PLAYER_SPEED;
			}
			else
			{
				playerShader->objects[idx]->kState.xzspeed = 0.0f;
			}

			printf("Time elapsed from last swing : %f\n", fTime);
			setObjectLastAttack(idx);
			playerShader->objects[idx]->hammerHit = false;
			rm->effect[3]->play();
			rm->effect[3]->Update();

			int r = rand() % 2;

			if (r)
			{
				if (playerShader->objects[idx]->m_pChild != rm->playerModels[3]->m_pModelRootObject)
				{
					playerShader->objects[idx]->setRoot(rm->playerModels[3]->m_pModelRootObject, true);
					playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[3]);
					playerShader->objects[idx]->SetTrackAnimationSet(0, 0);					
				}
			}
			else
			{
				if (playerShader->objects[idx]->m_pChild != rm->playerModels[4]->m_pModelRootObject)
				{
					playerShader->objects[idx]->setRoot(rm->playerModels[4]->m_pModelRootObject, true);
					playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[4]);
					playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
				}
			}
		}

		else if (fTime >= 0.233333f && fTime <= 0.266666f)
		{

			BoundBox bx;
			XMFLOAT3 ps = playerShader->objects[idx]->GetPosition();

			float rad = XMConvertToRadians(playerShader->objects[idx]->kState.rotation - 270.0f);

			float dx = sin(rad);
			float dz = cos(rad);
			XMFLOAT3 look = XMFLOAT3(dx, 0.0f, dz);

			for (int i = 0; i < enemyShader->objects.size(); ++i)
			{

				XMFLOAT3 es = enemyShader->objects[i]->GetPosition();

				XMFLOAT3 vec = XMFLOAT3(es.x - ps.x, 0.0f, es.z - ps.z);

				float dist = Vector3::Length(vec);
				float cosAngle = Vector3::DotProduct(Vector3::Normalize(vec), look);

				//공격 범위 내에 적이 있으면
				if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(45.0f)) && dist <= 2.0f && playerShader->objects[idx]->hammerHit == false)
				{
					//사운드 및 파티클 이펙트 발생
					printf("Enemy [%d] hit\n", i);
					rm->effect[4]->play();
					rm->effect[4]->Update();
					playerShader->objects[idx]->hammerHit = true;
					
					
					if (idx == pID)
					{
						CS_ATTACK_PACKET ap;
						ap.size = sizeof(CS_ATTACK_PACKET);
						ap.type = PACKET_TYPE::CS_ATTACK;
						ap.id = pID;

						ap.target = i;
						ap.damage = playerShader->objects[idx]->info->getMeleeDamage() * playerShader->objects[idx]->amp_melee;
						ap.stuntime = 0.2f;
						SendPacket(&ap);

						CS_PARTICLE_PACKET p;
						p.size = sizeof(CS_PARTICLE_PACKET);
						p.type = PACKET_TYPE::CS_PARTICLE;
						p.id = pID;
						p.count = 100;


						//플레이어가 바라보는 방향과 정반대 방향
						float rd = XMConvertToRadians(-playerShader->objects[idx]->kState.rotation);
						XMFLOAT3 dir = XMFLOAT3(-cos(rd), 0.0f, -sin(rd));

						p.xdir = dir.x;
						p.zdir = dir.z;

						p.x = enemyShader->objects[i]->GetPosition().x;
						p.y = enemyShader->objects[i]->GetPosition().y;
						p.z = enemyShader->objects[i]->GetPosition().z;
						p.particleType = 2;
						SendPacket(&p);
					}
				}
				

			}

			//


		}
		else if (fTime >= 0.833333f && fTime < 1.0f)
		{

			if (playerShader->objects[idx]->kState.xzspeed == 0.0f)
			{
				if (playerShader->objects[idx]->m_pChild != rm->playerModels[2]->m_pModelRootObject)
				{
					
					playerShader->objects[idx]->setRoot(rm->playerModels[2]->m_pModelRootObject, true);
					playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[2]);
					playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
					

				}
			}
			else
			{
				if (playerShader->objects[idx]->m_pChild != rm->playerModels[1]->m_pModelRootObject)
				{
					


					playerShader->objects[idx]->setRoot(rm->playerModels[1]->m_pModelRootObject, true);
					playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[1]);
					playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
				
				}
			}
		}
	
}

void CScene::swingBlade(int idx, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	
	chrono::duration<double> fromLastAttack = chrono::system_clock::now() - playerShader->objects[idx]->lastAttack;
	float fTime = static_cast<float>(fromLastAttack.count());
	//이동속도 원래대로
	if (fTime >= 1.0f)
	{
		//이동속도 원래대로
		if (playerShader->objects[idx]->bState.attacking == false)
		{
			playerShader->objects[idx]->kState.xzspeed = PLAYER_SPEED;
		}
		else
		{
			playerShader->objects[idx]->kState.xzspeed = 0.0f;
		}


		printf("Time elapsed from last swing : %f\n", fTime);
		setObjectLastAttack(idx);
		playerShader->objects[idx]->hammerHit = false;
		rm->effect[5]->play();
		rm->effect[5]->Update();

		int r = rand() % 2;

		if (r)
		{
			if (playerShader->objects[idx]->m_pChild != rm->playerModels[13]->m_pModelRootObject)
			{
				

				playerShader->objects[idx]->setRoot(rm->playerModels[13]->m_pModelRootObject, true);
				playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[13]);
				playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
				
			}
		}
		else
		{
			if (playerShader->objects[idx]->m_pChild != rm->playerModels[14]->m_pModelRootObject)
			{
			
				

				playerShader->objects[idx]->setRoot(rm->playerModels[14]->m_pModelRootObject, true);
				playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[14]);
				playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
				
			}
		}
	}

	else if (fTime >= 0.233333f && fTime <= 0.266666f)
	{

		BoundBox bx;
		XMFLOAT3 ps = playerShader->objects[idx]->GetPosition();

		float rad = XMConvertToRadians(playerShader->objects[idx]->kState.rotation - 270.0f);

		float dx = sin(rad);
		float dz = cos(rad);
		XMFLOAT3 look = XMFLOAT3(dx, 0.0f, dz);



		for (int i = 0; i < enemyShader->objects.size(); ++i)
		{

			XMFLOAT3 es = enemyShader->objects[i]->GetPosition();

			XMFLOAT3 vec = XMFLOAT3(es.x - ps.x, 0.0f, es.z - ps.z);

			float dist = Vector3::Length(vec);
			float cosAngle = Vector3::DotProduct(Vector3::Normalize(vec), look);

			//공격 범위 내에 적이 있으면
			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(45.0f)) && dist <= 1.5f && playerShader->objects[idx]->hammerHit == false)
			{
				//사운드 및 파티클 이펙트 발생
				printf("Enemy [%d] hit\n", i);
				rm->effect[6]->play();
				rm->effect[6]->Update();
				playerShader->objects[idx]->hammerHit = true;
				
				if (idx == pID)
				{
					CS_PARTICLE_PACKET p;
					p.size = sizeof(CS_PARTICLE_PACKET);
					p.type = PACKET_TYPE::CS_PARTICLE;
					p.id = pID;
					p.particleType = 2;
					p.count = 100;
					p.x = enemyShader->objects[i]->GetPosition().x;
					p.y = enemyShader->objects[i]->GetPosition().y;
					p.z = enemyShader->objects[i]->GetPosition().z;


					//플레이어가 바라보는 방향과 정반대 방향
					float rd = XMConvertToRadians(-playerShader->objects[idx]->kState.rotation);
					XMFLOAT3 dir = XMFLOAT3(-cos(rd), 0.0f, -sin(rd));

					p.xdir = dir.x;
					p.zdir = dir.z;

					SendPacket(&p);

					CS_ATTACK_PACKET ap;
					ap.size = sizeof(CS_ATTACK_PACKET);
					ap.type = PACKET_TYPE::CS_ATTACK;
					ap.id = pID;
					ap.target = i;
					ap.damage = playerShader->objects[idx]->info->getMeleeDamage() * playerShader->objects[idx]->amp_melee;
					ap.stuntime = 0.0f;

					SendPacket(&ap);

				}

				
			}


		}


	}
	else if (fTime >= 0.833333f && fTime < 1.0f)
	{
		if (playerShader->objects[idx]->m_pChild != rm->playerModels[12]->m_pModelRootObject)
		{
			

			playerShader->objects[idx]->setRoot(rm->playerModels[12]->m_pModelRootObject, true);
			playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[12]);
			playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
		
		}
	}
}



void CScene::createParticles(int n, XMFLOAT3 pos)
{
	
	//랜덤한 방향으로 나아가는 조그마한 입자를 해당 위치에 n개 생성
	for (int i = 0; i < n; ++i)
	{
		float x = static_cast<float>(rand() % 10000)/10000.0f-0.5f;
		float y = static_cast<float>(rand() % 10000)/10000.0f-0.5f;
		float z = static_cast<float>(rand() % 10000)/10000.0f-0.5f;


		XMFLOAT3 direct = XMFLOAT3(x, y, z);
		direct = Vector3::Normalize(direct);
		
		ParticleObject* obj = new ParticleObject(1);
		obj->timeCreated = std::chrono::system_clock::now();
		obj->SetMaterial(0, rm->materials[66]);
		obj->speed = 0.1f;
		obj->direction = direct;
		obj->SetPosition(pos);
		obj->SetMesh(partMesh);
		particles.push_back(obj);
	}
}

// 적 만드는 함수


void CScene::createSounds()
{

}
void CScene::delSounds()
{

}

XMFLOAT3 getBoxOverlapPoint(BoundBox b1, BoundBox b2, float angle)
{
	bool crash = false;
	std::vector<XMFLOAT3> vec;

	XMFLOAT3 result;

	vec.push_back(XMFLOAT3(b1.start.x, b1.start.y, b1.start.z));
	vec.push_back(XMFLOAT3(b1.start.x, b1.start.y, b1.end.z));
	vec.push_back(XMFLOAT3(b1.end.x, b1.start.y, b1.start.z));
	vec.push_back(XMFLOAT3(b1.end.x, b1.start.y, b1.end.z));

	vec.push_back(XMFLOAT3(b1.start.x, b1.end.y, b1.start.z));
	vec.push_back(XMFLOAT3(b1.start.x, b1.end.y, b1.end.z));
	vec.push_back(XMFLOAT3(b1.end.x, b1.end.y, b1.start.z));
	vec.push_back(XMFLOAT3(b1.end.x, b1.end.y, b1.end.z));

	for (int i = 0; i < 8; ++i)
	{
		if ((vec[i].x > b2.start.x && vec[i].x < b2.end.x) &&
			(vec[i].y > b2.start.y && vec[i].y < b2.end.y) &&
			(vec[i].z > b2.start.z && vec[i].z < b2.end.z))
		{
			crash = true;
		}
	}
	if (crash == true)
	{
		if (angle <= 45.0f || angle > 315.0f)//전방 - 후면 반환
		{
			result = XMFLOAT3((b2.end.x - b2.start.x) * 0.5f + b2.start.x, (b2.end.y - b2.start.y) * 0.5f + b2.start.y, b2.start.z);
		}
		else if (angle > 45.0f && angle <= 135.0f)//오른쪽 방향 - 왼면 반환
		{
			result = XMFLOAT3(b2.start.x, (b2.end.y - b2.start.y) * 0.5f + b2.start.y, (b2.end.z - b2.start.z) * 0.5f + b2.start.z);
		}
		else if (angle > 135.0f && angle <= 225.0f)//후방 - 전면 반환
		{
			result = XMFLOAT3((b2.end.x - b2.start.x) * 0.5f + b2.start.x, (b2.end.y - b2.start.y) * 0.5f + b2.start.y, b2.end.z);
		}
		else if (angle > 225.0f && angle <= 315.0f)
		{
			result = XMFLOAT3(b2.end.x, (b2.end.y - b2.start.y) * 0.5f + b2.start.y, (b2.end.z - b2.start.z) * 0.5f + b2.start.z);
		}
	}
	else
	{
		result = XMFLOAT3(-9999.0f, -9999.0f, -9999.0f);
	}
	return result;

}

void CScene::shootBazuka(int idx, ID3D12Device* device, ID3D12GraphicsCommandList* list)
{
	chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
	chrono::duration<double> dur = moment - playerShader->objects[idx]->lastAttack;
	float dt = (float)dur.count();
	//공격 후 애니메이션 재생이 끝난 경우
	if (dt > 0.5f && dt < 2.0f)
	{
		//다시 공격중이지 않은 애니메이션으로.
		if (playerShader->objects[idx]->m_pChild != rm->playerModels[11]->m_pModelRootObject)
		{


		

			playerShader->objects[idx]->setRoot(rm->playerModels[11]->m_pModelRootObject, true);
			playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(device, list, 1, rm->playerModels[11]);
			playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
			

		}
		//이동속도 원래대로
		if (playerShader->objects[idx]->bState.attacking==false)
		{
			playerShader->objects[idx]->kState.xzspeed = PLAYER_SPEED;
		}
		else
		{
			playerShader->objects[idx]->kState.xzspeed = 0.0f;
		}
	}

	//공격 쿨타임이 남아있지 않은 경우
	else if (dt >= 2.0f)
	{
		//공격 애니메이션 전환
		if (playerShader->objects[idx]->m_pChild != rm->playerModels[5]->m_pModelRootObject)
		{


		

			playerShader->objects[idx]->setRoot(rm->playerModels[5]->m_pModelRootObject, true);
			playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(device, list, 1, rm->playerModels[5]);
			playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
			

		}
		playerShader->objects[idx]->kState.xzspeed = 0.0f;
		//직선으로 나아가는 바주카 탄환 생성
		float rot = playerShader->objects[idx]->kState.rotation;

		float dx = cos(rot / 180.0f * 3.141592f);
		float dz = sin(rot / 180.0f * 3.141592f);

		XMFLOAT3 ppos = playerShader->objects[idx]->GetPosition();
		XMFLOAT3 pr = Vector3::Normalize(playerShader->objects[idx]->GetRight());
		float rx = pr.x*0.15f;
		float rz = pr.z*0.15f;



		BoomObject* boom = new BoomObject(1, XMFLOAT3(ppos.x+dx+rx, ppos.y+1.5f, ppos.z+rz - dz), XMFLOAT3(dx, 0.0f, -dz), 10.0f, moment);
		boom->lastMove = chrono::system_clock::now();
		boom->owner = idx;
		boom->SetMesh(boomMesh);
		boom->SetMaterial(0, rm->materials[4]);
		boomShader->objects.push_back(boom);
		setObjectLastAttack(idx);

		rm->effect[7]->play();
		rm->effect[7]->Update();

	}
}
void CScene::useRadio(int idx, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
	chrono::duration<double> dur = moment - playerShader->objects[idx]->lastWave;
	float dt = (float)dur.count();

	//전파무기의 쿨타임은 10초, 공격시 애니메이션 동작 시간은 0.5초

	//그전 사용으로부터 애니메이션 완료 시간까지 경과한 경우 대기 모션으로 전환.


	if (dt > 1.0f && dt < 10.0f)
	{
		if (playerShader->objects[idx]->m_pChild != rm->playerModels[9]->m_pModelRootObject)
		{
			playerShader->objects[idx]->setRoot(rm->playerModels[9]->m_pModelRootObject, true);
			playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[9]);
			playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
			

		}
		//이동속도 원래대로
		if (playerShader->objects[idx]->bState.attacking == false)
		{
			playerShader->objects[idx]->kState.xzspeed = PLAYER_SPEED;
		}
		else
		{
			playerShader->objects[idx]->kState.xzspeed = 0.0f;
		}
	}
	//
	else if (dt >= 10.0f)
	{
		//공격 애니메이션 전환
		if (playerShader->objects[idx]->m_pChild != rm->playerModels[8]->m_pModelRootObject)
		{
			playerShader->objects[idx]->setRoot(rm->playerModels[8]->m_pModelRootObject, true);
			playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[8]);
			playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
			

		}

		rm->effect[9]->play();
		rm->effect[9]->Update();
		playerShader->objects[idx]->kState.xzspeed = 0.0f;

		XMFLOAT3 ppos = playerShader->objects[idx]->GetPosition();

		for (int p = 0; p < enemyShader->objects.size(); ++p)
		{
			XMFLOAT3 ep = enemyShader->objects[p]->GetPosition();

			XMFLOAT3 dp = XMFLOAT3(ep.x - ppos.x, ep.y - ppos.y, ep.z - ppos.z);
			if (Vector3::Length(dp) <= 5.0f)
			{
				if (idx == pID)
				{
					CS_ATTACK_PACKET pac;
					pac.id = pID;
					pac.size = sizeof(CS_ATTACK_PACKET);
					pac.type = PACKET_TYPE::CS_ATTACK;

					pac.damage = 0;
					pac.stuntime = 5.0f * playerShader->objects[idx]->amp_radio;
					pac.target = p;
					SendPacket(&pac);
				}
				if (interShader->mission == 2)
				{
					interShader->m2_stun += 1;
				}
				else if (interShader->mission == 9)
				{
				//	interShader->m9_stun += 1;
				}
			}
		}
		if (interShader->mission == 3)
		{
			for (int p = 0; p < terrain1_1->objects.size(); ++p)
			{
				if (terrain1_1->objects[p]->type == Controller1 || terrain1_1->objects[p]->type == Controller2 || terrain1_1->objects[p]->type == Controller4)
				{
					XMFLOAT3 pp = terrain1_1->objects[p]->GetPosition();
					float dx = ppos.x - pp.x;
					float dz = ppos.z - pp.z;
					float dst = sqrt(dx * dx + dz * dz);
					if (dst < 5.0f)
					{
						if (idx == pID)
						{
							CS_MISSION_PACKET pac;
							pac.id = pID;
							pac.size = sizeof(CS_MISSION_PACKET);
							pac.type = PACKET_TYPE::CS_MISSION;
							pac.number = 3;
							pac.progress = 1;
							pac.target = p;
							SendPacket(&pac);
						}
					}
				}
			}
		}
		else if (interShader->mission == 9)
		{
			for (int p = 0; p < terrain1_2->objects.size(); ++p)
			{
				if (terrain1_2->objects[p]->type == PotteryKlinOpen || terrain1_2->objects[p]->type == PotteryKlinClose || terrain1_2->objects[p]->type == PotteryWheel)
				{
					XMFLOAT3 pp = terrain1_2->objects[p]->GetPosition();
					float dx = ppos.x - pp.x;
					float dz = ppos.z - pp.z;
					float dst = sqrt(dx * dx + dz * dz);
					if (dst < 8.0f)
					{
						if (idx == pID)
						{
							CS_MISSION_PACKET pac;
							pac.id = pID;
							pac.size = sizeof(CS_MISSION_PACKET);
							pac.type = PACKET_TYPE::CS_MISSION;
							pac.number = 9;
							pac.progress = 1;
							pac.target = p;
							SendPacket(&pac);
						}
					}
				}
			}
		}
	
		playerShader->objects[idx]->lastWave = chrono::system_clock::now();
	}
}