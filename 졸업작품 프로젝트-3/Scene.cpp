//-----------------------------------------------------------------------------
// File: CScene.cpp
//-----------------------------------------------------------------------------
#pragma once

#include "stdafx.h"
#include "Scene.h"
#include "GameFramework.h"



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
	m_pLights[3].m_fRange = 200.0f;
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
	m_pLights[2].m_fRange = 200.0f;
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
	m_pLights[1].m_fRange = 200.0f;
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

	terrainShader = new TerrainShader(rm);
	terrainShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	terrainShader->BuildObjects(pd3dDevice, pd3dCommandList);

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

	enemyShader = new EnemyShader(rm);
	enemyShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	enemyShader->BuildObjects(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);

	std::vector<XMFLOAT3> ep = enemyShader->getEnemyPosition();
	std::vector<int> ehp = enemyShader->getHealthRate();

	barShader = new HealthBarShader(rm);
	barShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	barShader->BuildObjects(pd3dDevice, pd3dCommandList, ep, ehp);

	partShader = new ParticleShader(rm, pd3dDevice, pd3dCommandList);
	partShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	partShader->BuildObjects();
	
	sdwShader = new ShadowShader(rm);
	sdwShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	sdwShader->BuildObjects(pd3dDevice,pd3dCommandList);

	lobbyInter = new LobbyInterfaceShader(rm);
	lobbyInter->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	lobbyInter->BuildObjects(pd3dDevice, pd3dCommandList);

	BuildDefaultLightsAndMaterials();
	//createenemyShader->objects(pd3dDevice, pd3dCommandList);

	std::vector<Obj> data = LoadObjects("res/map/objects.txt");

	CreateShaderVariables(pd3dDevice, pd3dCommandList);
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
	if (currentScreen == IN_GAME_STATE)
	{
		cam->move(playerShader->objects[pID]->GetPosition());
		m_fElapsedTime = fTimeElapsed;
		//for (int i = 0; i < m_nShaders; i++) if (m_ppShaders[i]) m_ppShaders[i]->AnimateObjects(fTimeElapsed);
		interShader->Animate(cam);




		for (int i = 0; i < playerShader->objects.size(); ++i)
		{

			if (playerShader->objects[i]->bState.stateID == IDLE_STATE)
			{
				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{
					if (playerShader->objects[i]->m_pChild != rm->playerModels[0]->m_pModelRootObject)
					{
						playerShader->objects[i]->setRoot(rm->playerModels[0]->m_pModelRootObject, true);
						playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[0]);
					}
					playerShader->objects[i]->SetTrackAnimationSet(0, 11);
					if (playerShader->objects[i]->kState.yspeed != 0.0f)
					{
						moveObject(i, cam);
					}
					setObjectLastMove(i);
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{
					std::chrono::duration<double> dt = std::chrono::system_clock::now() - playerShader->objects[i]->lastAttack;
					float df = static_cast<float>(dt.count());
					if (df >= 0.833333f)
					{
						if (playerShader->objects[i]->m_pChild != rm->playerModels[2]->m_pModelRootObject)
						{
							playerShader->objects[i]->setRoot(rm->playerModels[2]->m_pModelRootObject, true);
							playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[2]);
						}
						playerShader->objects[i]->SetTrackAnimationSet(0, 0);
					}
					if (playerShader->objects[i]->kState.yspeed != 0.0f)
					{
						moveObject(i, cam);
					}
					setObjectLastMove(i);
				}
			}
			else if (playerShader->objects[i]->bState.stateID == JUMP_STATE)
			{
				if (playerShader->objects[i]->m_pChild != rm->playerModels[0]->m_pModelRootObject)
				{
					playerShader->objects[i]->setRoot(rm->playerModels[0]->m_pModelRootObject, true);
					playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[0]);
				}
				playerShader->objects[i]->SetTrackAnimationSet(0, 20);

				moveObject(i, cam);
				setObjectLastMove(i);
			}
			else if (playerShader->objects[i]->bState.stateID == MOVE_STATE)
			{
				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{
					if (playerShader->objects[i]->m_pChild != rm->playerModels[0]->m_pModelRootObject)
					{
						playerShader->objects[i]->setRoot(rm->playerModels[0]->m_pModelRootObject, true);
						playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[0]);
					}
					playerShader->objects[i]->SetTrackAnimationSet(0, 20);
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{
					if (playerShader->objects[i]->m_pChild != rm->playerModels[1]->m_pModelRootObject)
					{
						playerShader->objects[i]->setRoot(rm->playerModels[1]->m_pModelRootObject, true);
						playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[1]);
					}
					playerShader->objects[i]->SetTrackAnimationSet(0, 0);
				}
				moveObject(i, cam);
				setObjectLastMove(i);

			}
			else if (playerShader->objects[i]->bState.stateID == ATTACK_STATE)
			{
				if (playerShader->objects[i]->bState.attackID == TYPE_RANGED)
				{
					if (playerShader->objects[i]->m_pChild != rm->playerModels[0]->m_pModelRootObject)
					{
						playerShader->objects[i]->setRoot(rm->playerModels[0]->m_pModelRootObject, true);
						playerShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[0]);

					}

					playerShader->objects[i]->SetTrackAnimationSet(0, 2);
					cam->rotateUp();
					attack(i, pd3dDevice, pd3dCommandList);
				}
				else if (playerShader->objects[i]->bState.attackID == TYPE_MELEE)
				{
					cam->rotateUp();
					swingHammer(i, pd3dDevice, pd3dCommandList);
				}
				setObjectLastMove(i);
				for (int j = 0; j < playerShader->objects.size(); ++j)
				{
					if (pID != j)
						setObjectLastMove(j);
				}
			}

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

		//각 적의 상태 변화와 그에 따라 적이 취하는 행동들을 나타낸다. 클라는 적이 현재 어떤 상태인지만 알면 되므로
		//서버는 적의 eState 구조체에 들어있는 변수들만 클라로 전달하면 된다.
		for (int i = 0; i < enemyShader->objects.size(); ++i)
		{

			if (enemyShader->objects[i]->bState.hp <= 0)
			{
				enemyShader->objects[i]->bState.stateID = DEATH_STATE;
			}
			if (enemyShader->objects[i]->bState.stateID == IDLE_STATE)
			{
				if (enemyShader->objects[i]->m_pChild != rm->enemyModels[0]->m_pModelRootObject)
				{
					enemyShader->objects[i]->setRoot(rm->enemyModels[0]->m_pModelRootObject, true);
					enemyShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[0]);
					enemyShader->objects[i]->SetTrackAnimationSet(0, 0);
				}
			}
			else if (enemyShader->objects[i]->bState.stateID == DEATH_STATE)
			{

				if (enemyShader->objects[i]->isDead == false)
				{
					if (enemyShader->objects[i]->m_pChild != rm->enemyModels[1]->m_pModelRootObject)
					{
						enemyShader->objects[i]->setRoot(rm->enemyModels[1]->m_pModelRootObject, true);
						enemyShader->objects[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->enemyModels[1]);
						enemyShader->objects[i]->SetTrackAnimationSet(0, 0);
						enemyShader->objects[i]->m_pSkinnedAnimationController->m_fTime = 0.0f;
						enemyShader->objects[i]->timeFromDie = chrono::system_clock::now();
						enemyShader->objects[i]->isDead = true;
					}
				}
				else
				{
					chrono::duration<double> fromDie = chrono::system_clock::now() - enemyShader->objects[i]->timeFromDie;
					float fTime = static_cast<float>(fromDie.count());

					if (fTime >= 1.971666f)
					{
						enemyShader->objects.erase(enemyShader->objects.begin() + i);
						enemyShader->enemyBoxes.erase(enemyShader->enemyBoxes.begin() + i);
						barShader->objects.erase(barShader->objects.begin() + i);
						
					}
				}
			}
		}

		std::vector<XMFLOAT3> ep = enemyShader->getEnemyPosition();
		std::vector<int> ehp = enemyShader->getHealthRate();

		barShader->Animate(cam, ep, ehp);

		m_pLights[1].m_xmf3Position = playerShader->objects[pID]->GetPosition();
		m_pLights[1].m_xmf3Position.y = 50.0f;
		UpdateShaderVariables(pd3dCommandList);
	}
	else if (currentScreen == LOBBY_STATE)
	{
		lobbyInter->Animate(cam);
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



		if (terrainShader)
		{
			terrainShader->OnPrepareRender(pd3dCommandList);
			terrainShader->Render(pd3dCommandList, pCamera);
		}
		if ((cp.x >= 0.0f && cp.x <= 200.0f) && cp.z >= 0.0f && cp.z <= 200.0f)
		{
			if (terrain1_1)
			{
				terrain1_1->OnPrepareRender(pd3dCommandList);
				terrain1_1->Render(pd3dCommandList, pCamera);
			}
		}
		else if ((cp.x >= 200.0f && cp.x <= 600.0f) && cp.z >= 0.0f && cp.z <= 200.0f)
		{
			if (terrain1_2)
			{
				terrain1_2->OnPrepareRender(pd3dCommandList);
				terrain1_2->Render(pd3dCommandList, pCamera, m_fElapsedTime);

			}

		}
		else if ((cp.x >= 400.0f && cp.x <= 600.0f) && cp.z >= 200.0f && cp.z <= 600.0f)
		{
			if (terrain1_3)
			{
				terrain1_3->OnPrepareRender(pd3dCommandList);
				terrain1_3->Render(pd3dCommandList, pCamera);
			}
		}

		else if ((cp.x >= 800.0f && cp.x <= 900.0f) && cp.z >= 363.0f && cp.z <= 600.0f)
		{
			if (terrain2_1)
			{
				terrain2_1->OnPrepareRender(pd3dCommandList);
				terrain2_1->Render(pd3dCommandList, pCamera);
			}
		}
		else if ((cp.x >= 800.0f && cp.x <= 900.0f) && cp.z >= 60.0f && cp.z <= 363.0f)
		{
			if (terrain2_2)
			{
				terrain2_2->OnPrepareRender(pd3dCommandList);
				terrain2_2->Render(pd3dCommandList, pCamera);
			}
		}
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
		if (partShader)
		{
			partShader->OnPrepareRender(pd3dCommandList);
			partShader->Render(pd3dCommandList, pCamera);
		}

		if (sdwShader)
		{
			sdwShader->OnPrepareRender(pd3dCommandList);
			sdwShader->Render(pd3dCommandList, pCamera);
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
	
	else if (currentScreen == LOBBY_STATE)
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



void CScene::moveObject(int idx,CCamera* pCamera)
{
	
	chrono::duration<double> fromLastMove = chrono::system_clock::now() - playerShader->objects[idx]->lastMove;
	double time = fromLastMove.count();
	float fTime = static_cast<float>(time);
	if (fTime > 0.02f)
	{
		fTime = 1.0f/60.0f;
	}
	//cout << "from last move " << fTime << endl;
	bool crash=false;
	float tx, ty, tz;
	bool stepOn;
	

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
			//1-1구역에 있는가?
			if (px >= 0.0f && px <= 200.0f && pz >= 0.0f && pz <= 200.0f)
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
							playerShader->objects[idx]->SetPosition(tx, height11[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera);
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
							playerShader->objects[idx]->SetPosition(ox, height11[oix][oiz], oz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera);
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
							playerShader->objects[idx]->SetPosition(tx, height11[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera);
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
			else if (px >= 200.0f && px <= 600.0f && pz >= 0.0f && pz <= 200.0f)
			{


				// ix = (tx - 현재구역의 원점x좌표) / 0.5
				// iz = (tz - 현재구역의 원점z좌표) / 0.5
				//oix, oiz도 마찬가지.

				//그밑의 height 데이터 배열을 전부 해당 구역에 맞게 변경.
				// 인덱스도 x12 말고 자신의 구역에 맞게 변경.


				int oix = (int)((ox-200.0f) / 0.5f);
				int oiz = (int)((oz-0.0f) / 0.5f);

				int ix = (int)((tx - 200.0f) / 0.5f);
				
				int iz = (int)((tz-0.0f) / 0.5f);

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
							playerShader->objects[idx]->SetPosition(tx, height12[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera);
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
							playerShader->objects[idx]->SetPosition(ox, height12[oix][oiz], oz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera);
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
							playerShader->objects[idx]->SetPosition(tx, height12[ix][iz], tz);
							if (idx == pID)
							{
								pCamera->move(playerShader->objects[idx]->GetPosition());
								interShader->Animate(pCamera);
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
			else if (px >= 800.0f && px <= 900.0f && pz >= 363.0f && pz <= 600.0f)
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
					playerShader->objects[idx]->SetPosition(tx, height21[ix][iz], tz);
					if (idx == pID)
					{
						pCamera->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(pCamera);
					}
					crash = true;
					cout << "착지 높이" << height21[ix][iz] << endl;
				}
				else if (ty < height21[ix][iz] - 0.3f && ty >= height21[oix][oiz] + 0.3f)
				{

					crash = true;
				}
				else if (ty < height21[oix][oiz] + 0.3f && ty >= height21[oix][oiz])
				{
					playerShader->objects[idx]->kState.isInAir = 0;
					playerShader->objects[idx]->kState.yspeed = 0.0f;
					playerShader->objects[idx]->SetPosition(ox, height21[oix][oiz], oz);
					if (idx == pID)
					{
						pCamera->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(pCamera);
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
					playerShader->objects[idx]->SetPosition(tx, height21[ix][iz], tz);
					if (idx == pID)
					{
						pCamera->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(pCamera);
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
			else if (px >= 800.0f && px <= 900.0f && pz >= 60.0f && pz <= 363.0f)
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
					playerShader->objects[idx]->SetPosition(tx, height22[ix][iz], tz);
					if (idx == pID)
					{
						pCamera->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(pCamera);
					}
					crash = true;
					cout << "착지 높이" << height22[ix][iz] << endl;
				}
				else if (ty < height22[ix][iz] - 0.3f && ty >= height22[oix][oiz] + 0.3f)
				{

					crash = true;
				}
				else if (ty < height22[oix][oiz] + 0.3f && ty >= height22[oix][oiz])
				{
					playerShader->objects[idx]->kState.isInAir = 0;
					playerShader->objects[idx]->kState.yspeed = 0.0f;
					playerShader->objects[idx]->SetPosition(ox, height22[oix][oiz], oz);
					if (idx == pID)
					{
						pCamera->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(pCamera);
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
					playerShader->objects[idx]->SetPosition(tx, height22[ix][iz], tz);
					if (idx == pID)
					{
						pCamera->move(playerShader->objects[idx]->GetPosition());
						interShader->Animate(pCamera);
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
					interShader->Animate(pCamera);
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
					interShader->Animate(pCamera);
					playerShader->objects[idx]->lastMoveSuccess = true;


					playerShader->objects[idx]->kState.yspeed -= 9.8f * fTime * 5.0f;
					
				}

			}

		}
		else
		{
			playerShader->objects[idx]->bState.stateID = IDLE_STATE;
			playerShader->objects[idx]->kState.isInAir = 0;
		}
	cout << "(" << playerShader->objects[idx]->GetPosition().x << ", " << playerShader->objects[idx]->GetPosition().y << ", " << playerShader->objects[idx]->GetPosition().z << ")" << endl;
	cout << "yspeed : " << playerShader->objects[pID]->kState.yspeed << endl;
	
	
	// 여기까지 완료한 후, 몇번째 클라이언트의 플레이어인지 나타내는 idx값, 
	// 변경 완료된 위치 값을 클라로 전송.
	// moveObject 함수는 매 프레임마다 호출되므로 서버에서도 약 0.016초(초당 60프레임 기준)마다 전송해주는게 좋음.
}



void CScene::setObjectSpeed(int idx, float size)
{
	//플레이어의 속도 크기 및 방향 벡터를 서버가 계산해줘야 한다.
	playerShader->objects[idx]->speed = size;

	float rad = XMConvertToRadians(playerShader->objects[idx]->currentRotation.y);

	//dir = Vector3::Normalize(XMFLOAT3(sin(rad), 0.0f, cos(rad)));
	// speed, direction값을 클라에게 전달하자.
}

void CScene::setObjectState(int index, int state)
{
	// 플레이어의 상태가 변하면 서버가 id값, 몇 번째 플레이어인지 index값을 전해준다.
	// 어차피 timeElapsed는 클라가 상태 변화를 나타내는 패킷을 수신받은
	// 시점을 기준으로 시간을 측정하면 되므로 서버가 전해줄 필요가 없다.
	if (playerShader->objects[index]->objType == TYPE_PLAYER)
	{
		if (playerShader->objects[index]->pState.id != state)
		{
			playerShader->objects[index]->pState.id = state;
			playerShader->objects[index]->pState.timeElapsed = 0.0f;
		}
	}
	// 적의 경우에도 id, index값만 전해주면 된다.
	else if (playerShader->objects[index]->objType == TYPE_ENEMY)
	{
		if (playerShader->objects[index]->eState.id != state)
		{
			playerShader->objects[index]->eState.id = state;
			playerShader->objects[index]->eState.timeElapsed = 0.0f;
		}
	}
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

			
			
			playerShader->objects[ID]->Rotate(0.0f, -p.kState.rotation+90.0f, 0.0f);
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
			//playerShader->objects[pID]->Rotate(0.0f, -dangle, 0.0f);

			printf("client player camera transform complete\n");
		}
		break;
	}
	case PACKET_TYPE::SC_ATTACK:
	{
		SC_ATTACK_PACKET p;
		memcpy(&p, p_buf, p_buf[0]);
		cout << "attack to target" << endl;
		partShader->createParticles(100, XMFLOAT3(p.x, p.y, p.z), pd3dDevice, pd3dCommandList);
		if (p.target != -1)
		{
			//enemyShader->objects[p.target]->bState.hp -= playerShader;
		}
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
		playerShader->objects[p.id]->SetPosition(p.x+p.id*5.0f, p.y, p.z);
		playerShader->objects[p.id]->bState.stateID = IDLE_STATE;
		break;

	default:
		cout << "Unknown PACKET type [" << +p_buf[1] << "]" << endl;
		break;
	}

}

void CScene::attack(int idx, ID3D12Device* device, ID3D12GraphicsCommandList* list)
{
	chrono::duration<double> fromLastAttack = chrono::system_clock::now() - playerShader->objects[idx]->lastAttack;
	float fTime = static_cast<float>(fromLastAttack.count());
	
	if (fTime >= 1.0f / 6.0f)
	{
		soundEffect[0]->play();
		soundEffect[0]->Update();
		printf("time elapsed from last shot : %f\n", fTime);
		setObjectLastAttack(idx);

		float rad = XMConvertToRadians(playerShader->objects[idx]->kState.rotation-270.0f);
		//printf("발사 각도 %f  ", playerShader->objects[idx]->currentRotation.y);
		XMFLOAT3 dir = XMFLOAT3(sin(rad), 0.0f, cos(rad)); // 사격 방향

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


		// 고정된 물체에 총알이 박혔나?
		for (int i = 0; i < terrainShader->nBox; ++i)
		{
			// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

			std::vector<XYZPlane> checkList;


			if (n.x > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = terrainShader->boxesWorld[i].start.x;
				checkList.push_back(p);
			}
			else if (n.x < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = terrainShader->boxesWorld[i].end.x;
				checkList.push_back(p);
			}

			if (n.z > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = terrainShader->boxesWorld[i].start.z;
				checkList.push_back(p);
			}
			else if (n.z < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = terrainShader->boxesWorld[i].end.z;
				checkList.push_back(p);
			}

			if (n.y > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = terrainShader->boxesWorld[i].start.y;
				checkList.push_back(p);
			}
			else if (n.y < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = terrainShader->boxesWorld[i].end.y;
				checkList.push_back(p);
			}

			
			//체크리스트에 들어있는 모든 평면들에 대해

			for (int j = 0; j < checkList.size(); ++j)
			{
				// 충돌 지점을 확보한다.
				temp = getIntersectPoint(line, checkList[j]);
				

				//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
				if ((temp.x <= terrainShader->boxesWorld[i].end.x+0.001f && temp.x >= terrainShader->boxesWorld[i].start.x-0.001f) &&
					(temp.y <= terrainShader->boxesWorld[i].end.y + 0.001f && temp.y >= terrainShader->boxesWorld[i].start.y-0.001f) &&
					(temp.z <= terrainShader->boxesWorld[i].end.z + 0.001f && temp.z >= terrainShader->boxesWorld[i].start.z-0.001f))
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

		soundEffect[1]->play();
		soundEffect[1]->Update();
		// 적한테 총알이 박혔나?
		for (int i = 0; i < enemyShader->objects.size(); ++i)
		{
			// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

			std::vector<XYZPlane> checkList;


			if (n.x > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = enemyShader->enemyBoxes[i]->start.x;
				checkList.push_back(p);
			}
			else if (n.x < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = enemyShader->enemyBoxes[i]->end.x;
				checkList.push_back(p);
			}

			if (n.z > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = enemyShader->enemyBoxes[i]->start.z;
				checkList.push_back(p);
			}
			else if (n.z < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = enemyShader->enemyBoxes[i]->end.z;
				checkList.push_back(p);
			}

			if (n.y > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = enemyShader->enemyBoxes[i]->start.y;
				checkList.push_back(p);
			}
			else if (n.y < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = enemyShader->enemyBoxes[i]->end.y;
				checkList.push_back(p);
			}


			//체크리스트에 들어있는 모든 평면들에 대해

			for (int j = 0; j < checkList.size(); ++j)
			{
				// 충돌 지점을 확보한다.
				temp = getIntersectPoint(line, checkList[j]);


				//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
				if ((temp.x <= enemyShader->enemyBoxes[i]->end.x + 0.001f && temp.x >= enemyShader->enemyBoxes[i]->start.x - 0.001f) &&
					(temp.y <= enemyShader->enemyBoxes[i]->end.y + 0.001f && temp.y >= enemyShader->enemyBoxes[i]->start.y - 0.001f) &&
					(temp.z <= enemyShader->enemyBoxes[i]->end.z + 0.001f && temp.z >= enemyShader->enemyBoxes[i]->start.z - 0.001f))
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
				type = 2;
			}

		}

		for (int i = 0; i < terrainShader->nStairs; ++i)
		{
			// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

			std::vector<XYZPlane> checkList;


			if (n.x > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = terrainShader->stairsWorld[i].start.x;
				checkList.push_back(p);
			}
			else if (n.x < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = terrainShader->stairsWorld[i].end.x;
				checkList.push_back(p);
			}

			if (n.z > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = terrainShader->stairsWorld[i].start.z;
				checkList.push_back(p);
			}
			else if (n.z < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = terrainShader->stairsWorld[i].end.z;
				checkList.push_back(p);
			}

			if (n.y > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = terrainShader->stairsWorld[i].start.y;
				checkList.push_back(p);
			}
			else if (n.y < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = terrainShader->stairsWorld[i].end.y;
				checkList.push_back(p);
			}


			//체크리스트에 들어있는 모든 평면들에 대해

			for (int j = 0; j < checkList.size(); ++j)
			{
				// 충돌 지점을 확보한다.
				temp = getIntersectPoint(line, checkList[j]);


				//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
				if ((temp.x <= terrainShader->stairsWorld[i].end.x + 0.001f && temp.x >= terrainShader->stairsWorld[i].start.x - 0.001f) &&
					(temp.y <= terrainShader->stairsWorld[i].end.y + 0.001f && temp.y >= terrainShader->stairsWorld[i].start.y - 0.001f) &&
					(temp.z <= terrainShader->stairsWorld[i].end.z + 0.001f && temp.z >= terrainShader->stairsWorld[i].start.z - 0.001f))
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

		// 모든 충돌 박스들에 대해 처리할 경우 가장 가까운 곳이 targetPos에 저장되므로 
		// targetPos는 총알이 맞는 지점이 된다. target은 맞은 물체의 인덱스값이다.

		// 이제, 서버는  총알의 충돌 지점을 나타내는 targetPos, 맞은 객체의 유형을 나타내는 type, 몇 번째 객체에 맞았는지 나타내는 target값을 전송해야 한다.
	
		if (type == 1)
		{


			printf("Target position (%f, %f, %f) - object[%d] attacked.   ", targetPos.x, targetPos.y, targetPos.z, target);
			/*
			if (terrainShader->objects[target]->type == 21217)
			{
				float ox = terrainShader->objects[target]->GetPosition().x;
				float oy = terrainShader->objects[target]->GetPosition().y;
				float oz = terrainShader->objects[target]->GetPosition().z;

				terrainShader->objects[target] = NULL;
				terrainShader->boxesWorld[target].start=XMFLOAT3(-1.0f,-1.0f, -1.0f);
				terrainShader->boxesWorld[target].end = XMFLOAT3(-1.0f, -1.0f, -1.0f);



				for (float x = ox - 15.0f; x < ox + 15.0f; x += 1.5f)
				{
					for (float y = oy - 4.5f; y < oy + 5.0f; y += 1.5f)
					{
						for (float z = oz - 0.5f; z < oz + 1.0f; z += 0.6f)
						{
							XMFLOAT3 tmp = XMFLOAT3(x, y, z);
							partShader->createParticles(10, tmp, device, list);
						}
					}
				}
			}
			*/
		}

		CS_ATTACK_PACKET p;
		p.type = PACKET_TYPE::CS_ATTACK;
		p.size = sizeof(CS_ATTACK_PACKET);
		p.target = target;
		p.x = targetPos.x;
		p.y = targetPos.y;
		p.z = targetPos.z;
		if (type == 2)
		{
			p.isAlive = true;
			enemyShader->objects[target]->bState.hp -= playerShader->objects[idx]->info->getRangedDamage();
		}
		else if (type == 1)
		{
			p.isAlive = false;
		}
		SendPacket(&p);

		// type, target, targetPos 3개의 값이 전송되면, 클라는 그3개의 값을 받아서
		// 해당 위치에 불꽃이 튀는 듯한 파티클을 생성한다. 
		partShader->createParticles(50, targetPos, device, list);
		// 그니까, partShader->createParticles 함수는 서버의 전담이 아니다.
	}


}


void CScene::swingHammer(int idx, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	chrono::duration<double> fromLastAttack = chrono::system_clock::now() - playerShader->objects[idx]->lastAttack;
	float fTime = static_cast<float>(fromLastAttack.count());

	if (fTime >= 1.0f)
	{
		

		printf("Time elapsed from last swing : %f\n", fTime);
		setObjectLastAttack(idx);
		playerShader->objects[idx]->hammerHit = false;
		soundEffect[3]->play();
		soundEffect[3]->Update();

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

			if (cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(45.0f)) && dist <= 1.5f && playerShader->objects[idx]->hammerHit==false)
			{
				printf("Enemy [%d] hit\n", i);
				soundEffect[4]->play();
				soundEffect[4]->Update();
				playerShader->objects[idx]->hammerHit = true;
				partShader->createParticles(50, enemyShader->objects[i]->GetPosition(), pd3dDevice, pd3dCommandList);
				enemyShader->objects[i]->bState.hp -= playerShader->objects[idx]->info->getMeleeDamage();
				break;
			}
			

		}


	}
	else if (fTime >= 0.833333f && fTime < 1.0f)
	{
		if (playerShader->objects[idx]->m_pChild != rm->playerModels[2]->m_pModelRootObject)
		{
			playerShader->objects[idx]->setRoot(rm->playerModels[2]->m_pModelRootObject, true);
			playerShader->objects[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, rm->playerModels[2]);
			playerShader->objects[idx]->SetTrackAnimationSet(0, 0);
			
		}
		
	}
}
// 서버 프로그램에 구현해야 할 함수이다.
// 바운딩박스의 한 평면과 총알의 진행 경로의 직선이 겹치는 부분을 찾아냄으로써, 총알이 맞은 지점을 알아내는 함수이다.
XMFLOAT3 getIntersectPoint(Line line, XYZPlane plane)
{
	float u1 = plane.normal.x * line.start.x + plane.normal.y * line.start.y + plane.normal.z * line.start.z - plane.pos;

	float u2 = plane.normal.x * (line.start.x - line.end.x) + plane.normal.y * (line.start.y - line.end.y) + plane.normal.z * (line.start.z - line.end.z);

	if (u1 / u2 < 1.0f && u1 / u2 > 0.0f)
	{

		XMFLOAT3 lineNorm = XMFLOAT3(line.end.x - line.start.x, line.end.y - line.start.y, line.end.z - line.start.z);
		lineNorm.x *= u1 / u2;
		lineNorm.y *= u1 / u2;
		lineNorm.z *= u1 / u2;

		lineNorm.x += line.start.x;
		lineNorm.y += line.start.y;
		lineNorm.z += line.start.z;

		return lineNorm;
	}
	else
	{
		return XMFLOAT3(-9999.0f, -9999.0f, -9999.0f);
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
		
		CGameObject* obj = new CGameObject(1);
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
	bgm = new CSound * [nBGM];
	bgm[0] = new CSound("res/sound/bgm/yugioh.mp3", true);
	
	soundEffect = new CSound * [nSoundEffect];

	soundEffect[0] = new CSound("res/sound/effect/rifle_shot.mp3", false);
	soundEffect[1] = new CSound("res/sound/effect/rifle_crash.ogg", false);
	soundEffect[2] = new CSound("res/sound/effect/step_steel.mp3", true);
	soundEffect[3] = new CSound("res/sound/effect/hammer_swing.mp3", false);
	soundEffect[4] = new CSound("res/sound/effect/hammer_hit.mp3", false);
	bgm[0]->setVolume(0.1f);
	bgm[0]->play();
	bgm[0]->Update();

	for (int i = 0; i < nSoundEffect; ++i)
	{
		soundEffect[i]->setVolume(0.8f);
		soundEffect[i]->Update();
	}
}
void CScene::delSounds()
{
	for (int i = 0; i < nBGM; ++i)
	{
		delete bgm[i];
	}
	for (int i = 0; i < nSoundEffect; ++i)
	{
		delete soundEffect[i];
	}
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