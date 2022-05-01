//-----------------------------------------------------------------------------
// File: CScene.cpp
//-----------------------------------------------------------------------------
#pragma once

#include "stdafx.h"
#include "Scene.h"



CScene::CScene()
{
}

CScene::~CScene()
{
	
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

	m_pLights[0].m_bEnable = true;
	m_pLights[0].m_nType = DIRECTIONAL_LIGHT;
	m_pLights[0].m_xmf4Ambient = XMFLOAT4(0.4f, 0.4f, 0.4f, 1.0f);
	m_pLights[0].m_xmf4Diffuse = XMFLOAT4(0.7f, 0.7f, 0.7f, 1.0f);
	m_pLights[0].m_xmf4Specular = XMFLOAT4(0.4f, 0.4f, 0.4f, 0.0f);
	m_pLights[0].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	
	/*
	m_pLights[1].m_bEnable = true;
	m_pLights[1].m_nType = SPOT_LIGHT;
	m_pLights[1].m_fRange = 600.0f;
	m_pLights[1].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[1].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[1].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
	m_pLights[1].m_xmf3Position = XMFLOAT3(300.0f, 20.0f, 300.0f);
	m_pLights[1].m_xmf3Direction = XMFLOAT3(0.0f, -1.0f, 0.0f);
	m_pLights[1].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
	m_pLights[1].m_fFalloff = 10.0f;
	m_pLights[1].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[1].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	*/
	m_pMaterials = new MATERIALS;
	::ZeroMemory(m_pMaterials, sizeof(MATERIALS));

	m_pMaterials->m_pReflections[0] = { XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 5.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[1] = { XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 10.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[2] = { XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 15.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[3] = { XMFLOAT4(0.5f, 0.0f, 1.0f, 1.0f), XMFLOAT4(0.0f, 0.5f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 20.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[4] = { XMFLOAT4(0.0f, 0.5f, 1.0f, 1.0f), XMFLOAT4(0.5f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 25.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[5] = { XMFLOAT4(0.0f, 0.5f, 0.5f, 1.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 30.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[6] = { XMFLOAT4(0.5f, 0.5f, 1.0f, 1.0f), XMFLOAT4(0.5f, 0.5f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 35.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	m_pMaterials->m_pReflections[7] = { XMFLOAT4(1.0f, 0.5f, 1.0f, 1.0f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 40.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) };
	/*
	shadowMtx = new XMMATRIX[m_nLights];

	for (int i = 0; i < m_nLights; ++i)
	{
		if (m_pLights[i].m_nType == DIRECTIONAL_LIGHT)
		{
			XMFLOAT4 light = XMFLOAT4(-m_pLights[i].m_xmf3Direction.x, -m_pLights[i].m_xmf3Direction.y, -m_pLights[i].m_xmf3Direction.z, 0.0f);
			XMFLOAT4 plane = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
			shadowMtx[i] = XMMatrixShadow(XMLoadFloat4(&plane), XMLoadFloat4(&light));
		}
		else if (m_pLights[i].m_nType == POINT_LIGHT)
		{
			XMFLOAT4 light = XMFLOAT4(m_pLights[i].m_xmf3Position.x, m_pLights[i].m_xmf3Position.y, m_pLights[i].m_xmf3Position.z, 1.0f);
			XMFLOAT4 plane = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
			shadowMtx[i] = XMMatrixShadow(XMLoadFloat4(&plane), XMLoadFloat4(&light));
		}
	}
	*/

}

void CScene::createTextureData(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	
	textures[0] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[0]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/cont2.dds", RESOURCE_TEXTURE2D, 0);
	textures[1] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[1]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/chons.dds", RESOURCE_TEXTURE2D, 0);
	textures[2] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[2]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/WhitePaint.dds", RESOURCE_TEXTURE2D, 0);
	textures[3] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[3]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/GreenPaint.dds", RESOURCE_TEXTURE2D, 0);
	textures[4] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[4]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	textures[5] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[5]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/box.dds", RESOURCE_TEXTURE2D, 0);
	textures[6] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[6]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/table.dds", RESOURCE_TEXTURE2D, 0);
	textures[7] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[7]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PalletTruck.dds", RESOURCE_TEXTURE2D, 0);
	textures[8] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[8]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/bin.dds", RESOURCE_TEXTURE2D, 0);
	textures[9] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[9]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/barrel.dds", RESOURCE_TEXTURE2D, 0);
	textures[10] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[10]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/truck.dds", RESOURCE_TEXTURE2D, 0);
	textures[11] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[11]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/상단.dds", RESOURCE_TEXTURE2D, 0);
	textures[12] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[12]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/상단벽1.dds", RESOURCE_TEXTURE2D, 0);
	textures[13] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[13]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/wood.dds", RESOURCE_TEXTURE2D, 0);
	textures[14] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[14]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Cont3.dds", RESOURCE_TEXTURE2D, 0);
	textures[15] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[15]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/녹슨컨테이너.dds", RESOURCE_TEXTURE2D, 0);
	textures[16] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[16]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Real_Contain.dds", RESOURCE_TEXTURE2D, 0);
	textures[17] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[17]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PlateTexture.dds", RESOURCE_TEXTURE2D, 0);
	textures[18] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[18]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	textures[19] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[19]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/blockTexture.dds", RESOURCE_TEXTURE2D, 0);
	textures[20] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[20]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Stair_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[21] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[21]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Heater_Texture.dds", RESOURCE_TEXTURE2D, 0);
	textures[22] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[22]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/BaseColor_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[23] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[23]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Metal_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[24] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[24]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/상자커버.dds", RESOURCE_TEXTURE2D, 0);
	textures[25] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[25]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Convels.dds", RESOURCE_TEXTURE2D, 0);
	textures[26] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[26]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Paperbox.dds", RESOURCE_TEXTURE2D, 0);
	textures[27] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[27]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Machine_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[28] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[28]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Conl.dds", RESOURCE_TEXTURE2D, 0);
	textures[29] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[29]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Tank.dds", RESOURCE_TEXTURE2D, 0);
	textures[30] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[30]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/drum_t.dds", RESOURCE_TEXTURE2D, 0);
	textures[31] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[31]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/짐덩이_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[32] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[32]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample.dds", RESOURCE_TEXTURE2D, 0);
	textures[33] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[33]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/effect/particle.dds", RESOURCE_TEXTURE2D, 0);
	textures[34] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[34]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/enemy.dds", RESOURCE_TEXTURE2D, 0);
	textures[35] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[35]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/선반.dds", RESOURCE_TEXTURE2D, 0);
	textures[36] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[36]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/플라스틱빈.dds", RESOURCE_TEXTURE2D, 0);
	textures[37] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[37]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/창살.dds", RESOURCE_TEXTURE2D, 0);
	textures[38] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[38]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/감옥창살.dds", RESOURCE_TEXTURE2D, 0);
	textures[39] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[39]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/감옥창살2.dds", RESOURCE_TEXTURE2D, 0);
	textures[40] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[40]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/돌기둥받침.dds", RESOURCE_TEXTURE2D, 0);
	textures[41] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[41]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/기둥본체.dds", RESOURCE_TEXTURE2D, 0);




	normalTex[0]=new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	normalTex[0]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/none.dds", RESOURCE_TEXTURE2D, 0);

	CreateCbvSrvDescriptorHeaps(pd3dDevice, 0, nTex+nNormal);

	for (int i = 0; i < nTex; ++i)
	{
		CreateShaderResourceViews(pd3dDevice, textures[i], 0, 3);
	}
	
	for (int i = 0; i < nNormal; ++i)
	{
		CreateShaderResourceViews(pd3dDevice, normalTex[i], 0, 6);
	}
	/*
	for (int i = 0; i < nDirt; ++i)
	{
		CreateShaderResourceViews(pd3dDevice, dirtTex[i], 0, 3);
	}
	for (int i = 0; i < nShadows; ++i)
	{
		CreateShaderResourceViews(pd3dDevice, shadowTex[i], 0, 3);
	}*/

	for (int i = 0; i < nTex; ++i)
	{
		ppMaterials[i] = new CMaterial(1);
		ppMaterials[i]->SetTexture(textures[i], 0);
		ppMaterials[i]->SetNormalTex(normalTex[0]);
	}
	/*
	for (int i = 0; i < 9; ++i)
	{
		dirtMaterials[i] = new CMaterial(1);
		dirtMaterials[i]->SetTexture(dirtTex[i], 0);
		dirtMaterials[i]->SetNormalTex(normalTex[11]);
	}
	for (int i = 0; i < nShadows; ++i)
	{
		shadowMats[i] = new CMaterial(1);
		shadowMats[i]->SetTexture(shadowTex[i], 0);
		shadowMats[i]->SetNormalTex(normalTex[11]);
	}
	*/
}



void CScene::BuildObjects(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList)
{
	m_pd3dGraphicsRootSignature = CreateGraphicsRootSignature(pd3dDevice);

	createTextureData(pd3dDevice, pd3dCommandList);
	createSounds();
	partMesh = new ParticleMesh(pd3dDevice, pd3dCommandList);
	


	CMaterial::PrepareShaders(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature); 

	BuildDefaultLightsAndMaterials();
	createPlayers(pd3dDevice, pd3dCommandList);
	createEnemies(pd3dDevice, pd3dCommandList);

	std::vector<Obj> data = LoadObjects("res/map/objects.txt");
	boxesWorld = LoadBoxes("res/map/box.txt", &nBox);
	stairsWorld = LoadStairs("res/map/stair.txt", &nStairs);
	m_nGameObjects = data.size();
	m_ppGameObjects = new CGameObject*[m_nGameObjects];

	CCubeMeshTextured* pPlayerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 1.7f, 1.0f);
	CCubeMeshTextured* ContMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 100.0f, 25.0f, 50.0f);
	CCubeMeshTextured* J_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 50.0f, 7.5f, 120.0f);
	CCubeMeshTextured* T_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 5.0f, 200.0f);
	CCubeMeshTextured* B_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 260.0f, 12.5f, 320.0f);
   // CCubeMeshTextured* ChonJang = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 620.0f, 3.0f, 620.0f);
	CCubeMeshTextured* Add_block1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 7.5f, 25.0f);
	CCubeMeshTextured* Add_block2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 5.0f, 2.5f);
	CCubeMeshTextured* Pan1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 8.0f, 3.0f, 1.0f);
	CCubeMeshTextured* Pan2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 120.0f, 2.0f, 60.0f);
	CCubeMeshTextured* Pan3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 20.0f, 1.3f, 20.0f);
	CCubeMeshTextured* Pan4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 16.0f, 19.9f, 16.0f);
	//CCubeMeshTextured* pContainerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 2.5f, 6.0f);
	//CCubeMeshTextured* Contain1_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 25.0f, 20.0f);




	//CRectMeshTextured* pTileMesh = new CRectMeshTextured(pd3dDevice, pd3dCommandList, 2.5f, 2.5f);

	GridMesh* pGrid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);
	GridMesh* t_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 20.0f);
	GridMesh* Se_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);
	GridMesh* ChonJang = new GridMesh(pd3dDevice, pd3dCommandList, 670.0f, 640.0f);




	WallMeshHorizontal* hWall = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* hWall_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* vWall = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* vWall_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* vWall_S = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* vWall_SM = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* vWall_1S = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshVertical* vWall_1SM = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshVertical* vWall_H = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshHorizontal* hWall_H = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshVertical* frooms = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 2.5f);
	WallMeshVertical* frooms_H = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshHorizontal* loadwall1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshHorizontal* loadwall2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshHorizontal* loadwall3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 7.5f);
	WallMeshVertical* Se_room_l1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* Se_room_l2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* Se_room_l3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 7.5f);
	WallMeshVertical* Se_room_r1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* Se_room_r2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* Se_room_r3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 7.5f);
	WallMeshVertical* Se_rs1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* Se_rs2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* Se_rs3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshHorizontal* Se_fb1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* Se_fb2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* Se_fb3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshVertical* Se_BS1_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 2.5f);
	WallMeshVertical* Se_BS1_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 2.5f);
	WallMeshVertical* Se_BS1_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 7.5f);
	WallMeshVertical* Se_BS2_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshVertical* Se_BS2_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshVertical* Se_BS2_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 7.5f);
	WallMeshVertical* Se_BS3_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 2.5f);
	WallMeshVertical* Se_BS3_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 2.5f);
	WallMeshVertical* Se_BS3_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 7.5f);
	WallMeshHorizontal* Se_BS4_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshHorizontal* Se_BS4_2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshHorizontal* Se_BS4_3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 7.5f);
	WallMeshVertical* Frst_lh = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);

	WallMeshVertical* Bated_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* Bated_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* Bat_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshVertical* Bat_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 20.0f, 200.0f);
	WallMeshVertical* Bat_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshHorizontal* Bat_FB1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB_11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB_12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBated_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBated_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBat_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshVertical* SeBat_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 20.0f, 200.0f);
	WallMeshVertical* SeBat_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB_11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB_12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* add_wall1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 5.0f);
	WallMeshVertical* add_wall2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);

	WallMeshHorizontal* Add_Bak1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 150.0f, 5.0f);
	WallMeshHorizontal* Add_Bak2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 150.0f, 7.5f);
	WallMeshHorizontal* SeAdders1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 100.0f, 5.0f);
	WallMeshHorizontal* SeAdders2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 100.0f, 7.5f);

	WallMeshHorizontal* Walz1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 97.5f, 5.0f);
	WallMeshHorizontal* Walz2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 97.5f, 7.5f);
	WallMeshHorizontal* Walz3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshVertical* Walz4 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 5.0f);
	WallMeshVertical* Walz5 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshHorizontal* Walz6 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 155.0f, 5.0f);
	WallMeshHorizontal* Walz7 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 155.0f, 7.5f);
	WallMeshHorizontal* Walz8 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 65.0f, 5.0f);
	WallMeshHorizontal* Walz9 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 65.0f, 7.5f);
	WallMeshHorizontal* Walz10 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshHorizontal* Walz11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 30.0f, 12.5f);
	WallMeshHorizontal* Walz12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshHorizontal* Walz13 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 120.0f, 12.5f); // 감옥창살
	WallMeshVertical* Walz14 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 60.0f, 12.5f);
	WallMeshVertical* Walz15 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 145.0f, 5.0f);
	WallMeshVertical* Walz16 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 145.0f, 7.5f);
	WallMeshHorizontal* Walz17 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 5.0f); // 시작지점 근처 벽
	WallMeshHorizontal* Walz18 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshVertical* Walz19 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 115.0f, 5.0f);
	WallMeshVertical* Walz20 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 115.0f, 7.5f);
	WallMeshHorizontal* Walz21 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 5.0f); // 시작지점 근처 벽
	WallMeshHorizontal* Walz22 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshHorizontal* Walz23 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 75.0f, 5.0f); // 시작지점 근처 벽
	WallMeshHorizontal* Walz24 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 75.0f, 7.5f);
	WallMeshVertical* Walz25 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 7.5f, 5.0f);
	WallMeshVertical* Walz26 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 7.5f, 7.5f);


	WallMeshVertical* Walz27 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 5.0f, 5.0f);
	WallMeshVertical* Walz28 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 5.0f, 7.5f);
	WallMeshVertical* Walz29 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz30 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz31 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 315.0f, 5.0f);
	WallMeshVertical* Walz32 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 315.0f, 7.5f);
	WallMeshHorizontal* Walz33 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 12.5f, 5.0f);
	WallMeshHorizontal* Walz34 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 12.5f, 7.5f);
	WallMeshHorizontal* Walz35 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 250.0f, 5.0f);
	WallMeshHorizontal* Walz36 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 250.0f, 7.5f);
	WallMeshVertical* Walz37 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 15.0f, 5.0f);
	WallMeshVertical* Walz38 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 15.0f, 7.5f);
	WallMeshVertical* Walz39 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 90.0f, 5.0f);
	WallMeshVertical* Walz40 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 90.0f, 7.5f);
	WallMeshHorizontal* Walz41 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshHorizontal* Walz42 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz43 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz44 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);

	WallMeshVertical* Walz45 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz46 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);
	WallMeshVertical* Walz47 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 5.0f);
	WallMeshVertical* Walz48 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 10.0f, 7.5f);


	CLoadedMesh* container = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_container2.txt", NULL);
	CLoadedMesh* box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_box.txt", NULL);
	CLoadedMesh* tableMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_table.txt", "res/idx_table.txt");
	CLoadedMesh* chairMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_chair3.txt", "res/idx_chair3.txt");
	CLoadedMesh* cartMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_pallet.txt", "res/idx_pallet.txt");
	CLoadedMesh* binMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_bin.txt", "res/idx_bin.txt");
	CLoadedMesh* barrelMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_barrel.txt", "res/idx_barrel.txt");
	CLoadedMesh* truckMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_truck.txt", "res/idx_truck.txt");

	CLoadedMesh* Container1_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Cont1_1.txt", "res/idx_Cont1_1.txt");
	CLoadedMesh* GyeDan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_신계단1.txt", NULL);
	CLoadedMesh* GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_신계단1.txt", NULL);
	CLoadedMesh* R_GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_신계단2.txt", NULL);
	CLoadedMesh* P_Doors = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Doors.txt", NULL);
	CLoadedMesh* H_Heat = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_공장_히터.txt", NULL);
	CLoadedMesh* B_box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_1Stage_Box.txt", NULL);
	CLoadedMesh* Gongjang_tool1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Covers.txt", NULL);
	CLoadedMesh* Gongjang_tool2 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Convel.txt", NULL);
	CLoadedMesh* Gongjang_tool3 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_종이박스.txt", NULL);
	CLoadedMesh* Gongjang_tool4 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_발전기.txt", NULL);
	CLoadedMesh* Gongjang_tool5 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_케비넷.txt", NULL);
	CLoadedMesh* Gongjang_tool6 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_어느기계.txt", NULL);
	CLoadedMesh* Gongjang_tool7 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_드럼통.txt", NULL);
	CLoadedMesh* Gongjang_tool8 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_짐덩이.txt", NULL);
	CLoadedMesh* Gongjang_tool9 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_어느선반.txt", NULL);
	CLoadedMesh* Gongjang_tool10 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_그냥화물1.txt", NULL);
	CLoadedMesh* Gongjang_tool11 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_쓰레기봉투.txt", NULL);

	/*
	RectMesh** shadowRect = new RectMesh * [nShadows];
	m_ppShadows = new CGameObject * [m_nGameObjects];

	for (int i = 0; i < nShadows; ++i)
	{
		shadowRect[i] = NULL;
	}
	for (int i = 0; i < m_nGameObjects; ++i)
	{
		m_ppShadows[i] = NULL;
	}
	*/
	

	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj;

		if (data[i].type == PLAYER)//player
		{
			obj = new CGameObject(1);
			obj->SetMesh(barrelMesh);
			obj->SetMaterial(0, ppMaterials[9]);

		}
		else if (data[i].type == CONTAINER)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(container);
			obj->SetMaterial(0, ppMaterials[0]);

		}
		else if (data[i].type == floor)
		{
			obj = new CGameObject(1);
			obj->SetMesh(pGrid);
			obj->SetMaterial(0, ppMaterials[17]);
		}
		else if (data[i].type == vWalls)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == hWalls)
		{
			obj = new CGameObject(1);
			obj->SetMesh(hWall);
			obj->SetMaterial(0, ppMaterials[12]);

		}
		else if (data[i].type == BOX)
		{
			obj = new CGameObject(1);
			obj->SetMesh(box);
			obj->SetMaterial(0, ppMaterials[5]);
		}
		else if (data[i].type == PALLET)
		{
			obj = new CGameObject(1);
			obj->SetMesh(cartMesh);
			obj->SetMaterial(0, ppMaterials[7]);
		}
		else if (data[i].type == TRASH)
		{
			obj = new CGameObject(1);
			obj->SetMesh(binMesh);
			obj->SetMaterial(0, ppMaterials[8]);
		}
		else if (data[i].type == BARREL)
		{
			obj = new CGameObject(1);
			obj->SetMesh(barrelMesh);
			obj->SetMaterial(0, ppMaterials[9]);
		}
		else if (data[i].type == TRUCK)
		{
			obj = new CGameObject(1);
			obj->SetMesh(truckMesh);
			obj->SetMaterial(0, ppMaterials[10]);
		}
		else if (data[i].type == TABLE)
		{
			obj = new CGameObject(1);
			obj->SetMesh(tableMesh);
			obj->SetMaterial(0, ppMaterials[6]);
		}
		else if (data[i].type == CHAIR)
		{
			obj = new CGameObject(1);
			obj->SetMesh(chairMesh);
			obj->SetMaterial(0, ppMaterials[1]);
		}
		else if (data[i].type == vWalls_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_1);
			obj->SetMaterial(0, ppMaterials[2]);
		}
		else if (data[i].type == hWalls_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(hWall_1);
			obj->SetMaterial(0, ppMaterials[2]);
		}
		else if (data[i].type == vWalls_S)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_S);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == vWalls_SM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_SM);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == vWalls_1S)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_1S);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == vWalls_1SM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_1SM);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == vWalls_H)
		{
			obj = new CGameObject(1);
			obj->SetMesh(vWall_H);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == hWalls_H)
		{
			obj = new CGameObject(1);
			obj->SetMesh(hWall_H);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == froom_set)
		{
			obj = new CGameObject(1);
			obj->SetMesh(frooms);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == froom_set_H)
		{
			obj = new CGameObject(1);
			obj->SetMesh(frooms_H);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == floor_T)
		{
			obj = new CGameObject(1);
			obj->SetMesh(t_Grid);
			obj->SetMaterial(0, ppMaterials[17]);
		}
		else if (data[i].type == loadwall_l)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(loadwall1);
			obj->SetMaterial(0, ppMaterials[12]);

		}
		else if (data[i].type == loadwall_m)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(loadwall2);
			obj->SetMaterial(0, ppMaterials[12]);

		}
		else if (data[i].type == loadwall_h)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(loadwall3);
			obj->SetMaterial(0, ppMaterials[11]);

		}
		else if (data[i].type == floor_Se)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_Grid);
			obj->SetMaterial(0, ppMaterials[17]);
		}
		else if (data[i].type == Se_room_L1_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_l1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_L1_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_l2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_L1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_l3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_room_R1_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_r1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_R1_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_r2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_R1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_room_r3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_room_RSL)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_rs1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_RSM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_rs2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_RSH)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_rs3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_room_FBL)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_fb1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_FBM)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_fb2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_room_FBH)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_fb3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok1_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS1_1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok1_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS1_2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok1_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS1_3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok2_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS2_1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok2_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS2_2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok2_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS2_3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok3_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS3_1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok3_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS3_2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok3_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS3_3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok4_1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS4_1);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok4_2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS4_2);
			obj->SetMaterial(0, ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok4_3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Se_BS4_3);
			obj->SetMaterial(0, ppMaterials[11]);
		}
		else if (data[i].type == Cont1_1)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(Container1_1);
			obj->Rotate(0.0f, 90.0f, 0.0f);
			obj->SetMaterial(0, ppMaterials[0]);

		}
		else if (data[i].type == Frs_H)//container
		{
			obj = new CGameObject(1);
			obj->SetMesh(Frst_lh);
			obj->SetMaterial(0, ppMaterials[11]);

		}
		else if (data[i].type == BatSet1)//지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_1);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == BatSet2)//지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_2);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == BatSet3)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_3);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_set1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB1);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_set2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB2);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == BatSet_1)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bated_1);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == BatSet_2)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bated_2);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_101)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB_11);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_102)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Bat_FB_12);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet1)//지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_1);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet3)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_3);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_set1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB1);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_set2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB2);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet_1)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBated_1);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet_2)// 지붕
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBated_2);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_101)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB_11);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_102)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeBat_FB_12);
			obj->SetMaterial(0, ppMaterials[1]);

		}
		else if (data[i].type == M_Contain)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(ContMesh1);
			obj->SetMaterial(0, ppMaterials[0]);

		}
		else if (data[i].type == J_Contain)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(J_ConMesh1);
			obj->SetMaterial(0, ppMaterials[14]);

		}
		else if (data[i].type == T_Contains)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(T_ConMesh1);
			obj->SetMaterial(0, ppMaterials[15]);

		}
		else if (data[i].type == B_Contain)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(B_ConMesh1);
			obj->SetMaterial(0, ppMaterials[16]);

		}
		else if (data[i].type == Shell)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(ChonJang);
			obj->SetMaterial(0, ppMaterials[18]);

		}
		else if (data[i].type == GyeDans1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(GyeDan);
			//obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, ppMaterials[20]);
		}
		else if (data[i].type == Frs_Pons1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(add_wall1);
			obj->SetMaterial(0, ppMaterials[12]);

		}
		else if (data[i].type == Frs_Pons2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(add_wall2);
			obj->SetMaterial(0, ppMaterials[11]);

		}
		else if (data[i].type == GyeDans2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(GyeDan_1);
			//	obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, ppMaterials[20]);

		}
		else if (data[i].type == R_GyeDan1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(R_GyeDan_1);
			//	obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, ppMaterials[20]);

		}
		else if (data[i].type == adds_beok1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_Bak1);
			obj->SetMaterial(0, ppMaterials[12]);

		}
		else if (data[i].type == adds_beok2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_Bak2);
			obj->SetMaterial(0, ppMaterials[11]);

		}
		else if (data[i].type == B_Door)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(P_Doors);
			//	obj->SetMaterial(0, ppMaterials[1]);
			obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Add_squre1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_block1);
			obj->SetMaterial(0, ppMaterials[19]);

		}
		else if (data[i].type == Add_squre2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(Add_block2);
			obj->SetMaterial(0, ppMaterials[19]);

		}
		else if (data[i].type == SeAddings1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeAdders1);
			obj->SetMaterial(0, ppMaterials[12]);

		}
		else if (data[i].type == SeAddings2)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(SeAdders2);
			obj->SetMaterial(0, ppMaterials[11]);

		}
		else if (data[i].type == Heaters1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(H_Heat);
			obj->SetMaterial(0, ppMaterials[21]);

		}
		else if (data[i].type == F_Stages)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(B_box);
			obj->SetMaterial(0, ppMaterials[22]);
			//obj->SetMaterial(0, ppMaterials[23]);
		}
		else if (data[i].type == Factory_tool1)// 여기서부터 새로 만든거
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool1);
			obj->SetMaterial(0, ppMaterials[24]);
			obj->Rotate(270.0f, 0.0f, 0.0f);
		}
		else if (data[i].type == Factory_tool2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool2);
			obj->SetMaterial(0, ppMaterials[25]);

		}
		else if (data[i].type == Factory_tool3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool3);
			obj->SetMaterial(0, ppMaterials[26]);

		}
		else if (data[i].type == Factory_tool4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool4);
			obj->SetMaterial(0, ppMaterials[27]);

		}
		else if (data[i].type == Factory_tool5)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool5);
			obj->SetMaterial(0, ppMaterials[28]);
			obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool6)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool6);
			obj->SetMaterial(0, ppMaterials[29]);
			obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool7)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool7);
			obj->SetMaterial(0, ppMaterials[30]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool8)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Gongjang_tool8);
			obj->SetMaterial(0, ppMaterials[31]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool9)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Gongjang_tool9);
		obj->SetMaterial(0, ppMaterials[35]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool10)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Gongjang_tool10);
		obj->SetMaterial(0, ppMaterials[36]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Factory_tool11)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Gongjang_tool11);
		obj->SetMaterial(0, ppMaterials[36]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz1)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz1);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz2)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz2);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz3)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz3);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz4)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz4);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz5)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz5);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz6)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz6);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz7)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz7);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz8)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz8);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz9)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz9);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz10)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz10);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Chagsal1)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz11);
		obj->SetMaterial(0, ppMaterials[37]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Chagsal2)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz12);
		obj->SetMaterial(0, ppMaterials[37]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Pyo)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Pan1);
		obj->SetMaterial(0, ppMaterials[13]);
	//	obj->Rotate(0.0f, 0.0f, 90.0f);

		}
		else if (data[i].type == GamOk)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz13);
		obj->SetMaterial(0, ppMaterials[38]);
		//	obj->Rotate(0.0f, 0.0f, 90.0f);

		}
		else if (data[i].type == GamOk2)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz14);
		obj->SetMaterial(0, ppMaterials[39]);
		//obj->Rotate(0.0f, 90.0f, 0.0f);

		}
		else if (data[i].type == GamOk_Shell)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Pan2);
		obj->SetMaterial(0, ppMaterials[36]);
		//obj->Rotate(0.0f, 90.0f, 0.0f);

		}
		else if (data[i].type == Wallz11)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz15);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz12)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz16);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz13)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz17);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz14)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz18);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz15)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz19);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
	   
		if (data[i].type == Wallz16)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz20);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz17)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz21);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz18)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz22);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Kidong)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Pan3);
			obj->SetMaterial(0, ppMaterials[40]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == KidongMom)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Pan4);
			obj->SetMaterial(0, ppMaterials[41]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz19)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz23);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		if (data[i].type == Wallz20)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz24);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz21)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz25);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Wallz22)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz26);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz27);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz28);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz29);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == A_Wallz4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz30);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz1)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz31);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz2)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz32);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz3)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz33);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz4)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz34);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz5)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz35);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz6)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz36);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz7)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz37);
			obj->SetMaterial(0, ppMaterials[12]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz8)
		{
			obj = new CGameObject(1);
			obj->SetMesh(Walz38);
			obj->SetMaterial(0, ppMaterials[11]);
			//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz9)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz39);
		obj->SetMaterial(0, ppMaterials[12]); // 바꿀 예정
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz10)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz40);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz11)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz41);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz12)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz42);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz13)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz43);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz14)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz44);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		else if (data[i].type == S_Wallz15)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz45);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz16)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz46);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz17)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz47);
		obj->SetMaterial(0, ppMaterials[12]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == S_Wallz18)
		{
		obj = new CGameObject(1);
		obj->SetMesh(Walz48);
		obj->SetMaterial(0, ppMaterials[11]);
		//obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		obj->type = data[i].type;
		obj->SetPosition(data[i].position.x, data[i].position.y, data[i].position.z);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		//obj->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * i));
		m_ppGameObjects[i] = obj;
	}
	/*
	WallDecorationMesh* floor_paint = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 3.0f, 3.0f, 800.0f, 600.0f, 1, 300, true);
	WallDecorationMesh* floor_crack1 = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 4.0f, 4.0f, 800.0f, 600.0f, 1, 300, true);
	WallDecorationMesh* floor_old2 = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 2.0f, 2.0f, 800.0f, 600.0f, 1, 1000, true);

	/*
	WallDecorationMesh* horizonWallDeco = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 800.0f, 3.0f, 2, 50, true);
	WallDecorationMesh* horizonWallDeco2 = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 800.0f, 3.0f, 2, 50, false);
	WallDecorationMesh* verticalWallDeco = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 600.0f, 2.0f, 3, 50, true);
	WallDecorationMesh* verticalWallDeco2 = new WallDecorationMesh(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 600.0f, 3.0f, 3, 50, false);
	*/
	/*
	m_nDecos = 5;
	m_nDecos = 1;
	m_ppDecos = new CGameObject * [1];
	 
	
	m_ppDecos[0] = new CGameObject(1);
	m_ppDecos[0]->SetMesh(floor_crack1);
	m_ppDecos[0]->SetMaterial(0, dirtMaterials[7]);
	m_ppDecos[0]->SetPosition(0.0f, 0.0f, 0.0f);
	/*
	m_ppDecos[1] = new CGameObject(1);
	m_ppDecos[1]->bgTransparent = true;
	m_ppDecos[1]->SetMesh(floor_crack1);
	m_ppDecos[1]->SetMaterial(0, dirtMaterials[0]);
	m_ppDecos[1]->SetPosition(0.0f, 0.0f, 0.0f);

	m_ppDecos[2] = new CGameObject(1);
	m_ppDecos[2]->bgTransparent = true;
	m_ppDecos[2]->SetMesh(floor_old2);
	m_ppDecos[2]->SetMaterial(0, dirtMaterials[5]);
	m_ppDecos[2]->SetPosition(0.0f, 0.0f, 0.0f);
	*/
	/*
	m_ppDecos[1] = new CGameObject(1);
	m_ppDecos[1]->objType = 0;
	m_ppDecos[1]->SetMesh(horizonWallDeco);
	m_ppDecos[1]->SetMaterial(0, ppMaterials[4]);
	m_ppDecos[1]->SetPosition(0.0f, 0.0f, 0.0f);

	m_ppDecos[2] = new CGameObject(1);
	m_ppDecos[2]->objType = 0;
	m_ppDecos[2]->SetMesh(horizonWallDeco2);
	m_ppDecos[2]->SetMaterial(0, ppMaterials[4]);
	m_ppDecos[2]->SetPosition(0.0f, 0.0f, 600.0f);

	m_ppDecos[3] = new CGameObject(1);
	m_ppDecos[3]->objType = 0;
	m_ppDecos[3]->SetMesh(verticalWallDeco);
	m_ppDecos[3]->SetMaterial(0, ppMaterials[4]);
	m_ppDecos[3]->SetPosition(0.0f, 0.0f, 0.0f);

	m_ppDecos[4] = new CGameObject(1);
	m_ppDecos[4]->objType = 0;
	m_ppDecos[4]->SetMesh(verticalWallDeco2);
	m_ppDecos[4]->SetMaterial(0, ppMaterials[4]);
	m_ppDecos[4]->SetPosition(800.0f, 0.0f, 0.0f);
	*/
	
	





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

	D3D12_DESCRIPTOR_RANGE pd3dDescriptorRanges[2];

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
	

	D3D12_ROOT_PARAMETER pd3dRootParameters[9];

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

void CScene::AnimateObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float fTimeElapsed)
{
	m_fElapsedTime = fTimeElapsed;
	for (int i = 0; i < m_nShaders; i++) if (m_ppShaders[i]) m_ppShaders[i]->AnimateObjects(fTimeElapsed);


	for (int i = 0; i < players.size(); ++i)
	{

		if (players[i]->bState.stateID == IDLE_STATE)
		{
			if (players[i]->m_pChild != binModels[0]->m_pModelRootObject)
			{
				players[i]->setRoot(binModels[0]->m_pModelRootObject, true);
				players[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[0]);
				players[i]->SetTrackAnimationSet(0, 11);
			}
		}
		else if (players[i]->bState.stateID == MOVE_STATE)
		{
			if (players[i]->m_pChild != binModels[0]->m_pModelRootObject)
			{
				players[i]->setRoot(binModels[0]->m_pModelRootObject, true);
				players[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[0]);
				players[i]->SetTrackAnimationSet(0, 20);
				moveObject(i);
			}
		}
		else if (players[i]->bState.stateID == ATTACK_STATE)
		{
			if (players[i]->m_pChild != binModels[0]->m_pModelRootObject)
			{
				players[i]->setRoot(binModels[0]->m_pModelRootObject, true);
				players[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[0]);
				players[i]->SetTrackAnimationSet(0, 2);
				moveObject(i);
			}
		}
		/*
		if (mouseDown == true)
		{
			players[i]->pState.id = ATTACK_STATE;
		}
		else
		{
			std::chrono::duration<double> d = std::chrono::system_clock::now() - players[i]->lastAttack;
			float ft = static_cast<float>(d.count());
			if (ft >= 0.833333f && players[i]->pState.attType == TYPE_MELEE && players[i]->speed==0.0f)
			{
				players[i]->pState.id = IDLE_STATE;
			}
		}
		if (players[i]->pState.attType == TYPE_RANGED)
		{
			if (players[i]->pState.id == ATTACK_STATE)
			{
				players[i]->speed = 0.0f;
				if (currentPlayerAnim != 2)
				{

					setPlayerAnimation(2);
				}
				// 이 클라이언트의 플레이어가 어느 방향으로 총을 쐈는지 서버로 전송하는 기능을 이곳에 추가해야 함.

				attack(i);// 캐릭터가 당시 바라봤던 방향으로 3km이내의 직선상에 총알이 발사됨. 이걸 서버가 처리.
			}
			else if (players[i]->pState.id == IDLE_STATE)
			{
				if (currentPlayerAnim != 11)
				{

					setPlayerAnimation(11);
				}
			}
		}
		else if (players[i]->pState.attType == TYPE_MELEE)
		{
			if (players[i]->pState.id == IDLE_STATE)
			{
				if (players[0]->m_pChild != binModels[2]->m_pModelRootObject)
				{

					players[0]->setRoot(binModels[2]->m_pModelRootObject, true);
					players[0]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[2]);

					setPlayerAnimation(0);
				}
			}
			else if (players[i]->pState.id == MOVE_STATE)
			{
				if (players[0]->m_pChild != binModels[1]->m_pModelRootObject)
				{
					players[0]->setRoot(binModels[1]->m_pModelRootObject, true);
					players[0]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[1]);
					setPlayerAnimation(0);
				}
			}
			else if (players[i]->pState.id == ATTACK_STATE)
			{
				players[i]->speed = 0.0f;
				swingHammer(i, pd3dDevice,pd3dCommandList);

			}
		}
		*/
	}
	chrono::time_point<chrono::system_clock> moment = chrono::system_clock::now();
	for (int i = 0; i < particles.size(); ++i)
	{
		chrono::duration<double> fromCreated = moment - particles[i]->timeCreated;
		float fTime = static_cast<float>(fromCreated.count());
		if (fTime > 0.5f)
		{
			//delete particles[i];
			particles.erase(particles.begin() + i);
			i -= 1;
		}
		else
		{
			XMFLOAT3 tmp = particles[i]->GetPosition();
			particles[i]->SetPosition(tmp.x + particles[i]->direction.x * particles[i]->speed * fTime,
				tmp.y + particles[i]->direction.y * particles[i]->speed * fTime,
				tmp.z + particles[i]->direction.z * particles[i]->speed * fTime);
		}
	}

	//각 적의 상태 변화와 그에 따라 적이 취하는 행동들을 나타낸다. 클라는 적이 현재 어떤 상태인지만 알면 되므로
	//서버는 적의 eState 구조체에 들어있는 변수들만 클라로 전달하면 된다.
	for (int i = 0; i < enemies.size(); ++i)
	{

		if (enemies[i]->eState.currHP <= 0)
		{
			enemies[i]->eState.id = DEATH_STATE;
		}
		if (enemies[i]->eState.id == IDLE_STATE)
		{
			if (enemies[i]->m_pChild != enemyModels[0]->m_pModelRootObject)
			{
				enemies[i]->setRoot(enemyModels[0]->m_pModelRootObject, true);
				enemies[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[0]);
				enemies[i]->SetTrackAnimationSet(0, 0);
			}
		}
		else if (enemies[i]->eState.id == DEATH_STATE)
		{

			if (enemies[i]->isDead == false)
			{
				if (enemies[i]->m_pChild != enemyModels[1]->m_pModelRootObject)
				{
					enemies[i]->setRoot(enemyModels[1]->m_pModelRootObject, true);
					enemies[i]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[1]);
					enemies[i]->SetTrackAnimationSet(0, 0);
					enemies[i]->timeFromDie = chrono::system_clock::now();
					enemies[i]->isDead = true;
				}
			}
			else
			{
				chrono::duration<double> fromDie = chrono::system_clock::now() - enemies[i]->timeFromDie;
				float fTime = static_cast<float>(fromDie.count());

				if (fTime >= 0.8f)
				{
					enemies.erase(enemies.begin() + i);
					enemyBoxes.erase(enemyBoxes.begin() + i);
				}
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

	pd3dCommandList->SetGraphicsRoot32BitConstants(8, 1, &alpha, 0);
	for (int i = 0; i < players.size(); ++i)
	{
		players[i]->Animate(m_fElapsedTime);
		if (players[i]->m_pSkinnedAnimationController)
		{
			players[i]->UpdateTransform(NULL);
		}
		if (m_pd3dCbvSrvDescriptorHeap)
		{
			pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
		}
		ppMaterials[32]->UpdateShaderVariable(pd3dCommandList);
		players[i]->Render(pd3dCommandList, pCamera);
	}

	for (int i = 0; i < m_nGameObjects; i++)
	{
		if (m_ppGameObjects[i])
		{
			XMFLOAT3 pos = m_ppGameObjects[i]->GetPosition();
			XMFLOAT3 camPos = pCamera->getPosition();

			XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);
			XMFLOAT3 look = pCamera->getLook();
			
			float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

			float dist = Vector3::Length(fromCamera);
			/* 
			//	1. 객체의 유형이 벽인 경우 그냥 그린다.
			//	2. 객체의 유형이 xyz 크기가 3m 이상인 대형 물체인 경우 카메라의 방향 벡터로부터 양쪽 70도 내에 있는 경우에만 그린다.
			//	3. 객체의 유형이 소형 물체, 혹은 움직이는 캐릭터인 경우 양쪽 55도 내에 있는 경우에만 그린다.
			*/
			int tp = m_ppGameObjects[i]->type;

			if (tp == 50000)
			{
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				m_ppGameObjects[i]->Render(pd3dCommandList, pCamera);
			}

			else if ((tp >= 2000 && tp < 3000) || (tp >= 10000) || (tp<6000 && tp>=5000))
			{
				//m_ppGameObjects[i]->Animate(m_fElapsedTime);
				//if (!m_ppGameObjects[i]->m_pSkinnedAnimationController) m_ppGameObjects[i]->UpdateTransform(NULL);
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				m_ppGameObjects[i]->Render(pd3dCommandList, pCamera);
			}
			
				
			else if ((cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(60.0f))&& dist<=300.0f) || (dist<=50.0f && cosAngle <= 1.0f && cosAngle >= cos(XMConvertToRadians(120.0f))))
			{

				m_ppGameObjects[i]->Animate(m_fElapsedTime);
				if (!m_ppGameObjects[i]->m_pSkinnedAnimationController) m_ppGameObjects[i]->UpdateTransform(NULL);
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}

				m_ppGameObjects[i]->Render(pd3dCommandList, pCamera);
			}
		}
	}
	/*
	for (int i = 0; i < m_nDecos; ++i)
	{
		if (m_ppDecos[i])
		{
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			m_ppDecos[i]->Render(pd3dCommandList, pCamera);
		}
	}
	alpha = 0.5f;
	pd3dCommandList->SetGraphicsRoot32BitConstants(8, 1, &alpha, 0);

	for (int i = 0; i < m_nGameObjects; ++i)
	{
		if (m_ppShadows[i]!=NULL)
		{
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			m_ppShadows[i]->Render(pd3dCommandList, pCamera);
		}
	}
	*/

	for (int i = 0; i < particles.size(); ++i)
	{
		XMFLOAT3 pos = particles[i]->GetPosition();
		XMFLOAT3 camPos = pCamera->getPosition();
		XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);
		XMFLOAT3 look = pCamera->getLook();

		float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

		if (cosAngle >= cos(XMConvertToRadians(45.0f)) && cosAngle <= 1.0f)
		{
			particles[i]->Render(pd3dCommandList, pCamera);
		}
		
	}

	//적 그리기
	for (int i = 0; i < enemies.size(); ++i)
	{
		XMFLOAT3 pos = enemies[i]->GetPosition();
		XMFLOAT3 camPos = pCamera->getPosition();
		
		XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);

		float dist = Vector3::Length(fromCamera);

		XMFLOAT3 look = pCamera->getLook();

		float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));

		if (cosAngle <= 1.0f && cosAngle >= 0.0f && dist<=150.0f)
		{

			enemies[i]->Animate(m_fElapsedTime);
			if (enemies[i]->m_pSkinnedAnimationController)
			{
				enemies[i]->UpdateTransform(NULL);
			}
			if (m_pd3dCbvSrvDescriptorHeap)
			{
				pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
			}
			ppMaterials[34]->UpdateShaderVariable(pd3dCommandList);
			enemies[i]->Render(pd3dCommandList, pCamera);
		}
	}

	//for (int i = 0; i < m_nShaders; i++) if (m_ppShaders[i]) m_ppShaders[i]->Render(pd3dCommandList, pCamera);

	
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
	players[0]->SetTrackAnimationSet(0, a);
	currentPlayerAnim = a;
}



void CScene::moveObject(int idx)
{
	
	chrono::duration<double> fromLastMove = chrono::system_clock::now() - players[idx]->lastMove;
	double time = fromLastMove.count();
	float fTime = static_cast<float>(time);
	bool crash=false;
	float tx, ty, tz;
	bool stepOn;
	


		if (players[idx]->speed > 0.0f || players[idx]->yspeed != 0.0f)
		{

			tx = players[idx]->GetPosition().x + fTime * players[idx]->speed * players[idx]->direction.x;
			ty = players[idx]->GetPosition().y + fTime * players[idx]->yspeed;
			tz = players[idx]->GetPosition().z + fTime * players[idx]->speed * players[idx]->direction.z;
			// 물체가 있는곳에 이동했는가?
			for (int i = 0; i < nBox; ++i)
			{
				if (tx > boxesWorld[i].start.x - 0.4f && ty > boxesWorld[i].start.y - 1.7f && tz > boxesWorld[i].start.z - 0.4f
					&& tx < boxesWorld[i].end.x + 0.4f && ty < boxesWorld[i].end.y - 0.0f && tz < boxesWorld[i].end.z + 0.4f)
				{


					if (players[idx]->GetPosition().x > boxesWorld[i].end.x || players[idx]->GetPosition().x < boxesWorld[i].start.x)
					{
						if (players[idx]->direction.x > 0.0f)
						{
							players[idx]->SetPosition(boxesWorld[i].start.x - 0.5f, players[idx]->GetPosition().y, players[idx]->GetPosition().z);
							players[idx]->direction.x = 0.0f;

						}
						else if (players[idx]->direction.x < 0.0f)
						{
							players[idx]->SetPosition(boxesWorld[i].end.x + 0.5f, players[idx]->GetPosition().y, players[idx]->GetPosition().z);
							players[idx]->direction.x = 0.0f;

						}
						crash = true;

					}
					else if (players[idx]->GetPosition().z > boxesWorld[i].end.z || players[idx]->GetPosition().z < boxesWorld[i].start.z)
					{
						if (players[idx]->direction.z > 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, players[idx]->GetPosition().y, boxesWorld[i].start.z - 0.5f);
							players[idx]->direction.z = 0.0f;

						}
						else if (players[idx]->direction.z < 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, players[idx]->GetPosition().y, boxesWorld[i].end.z + 0.5f);
							players[idx]->direction.z = 0.0f;

						}
						crash = true;

					}
					else if (players[idx]->yspeed != 0.0f)
					{
						if (players[idx]->yspeed > 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, boxesWorld[i].start.y - 1.7f, players[idx]->GetPosition().z);
							players[idx]->yspeed = 0.0f;
						}
						else if (players[idx]->yspeed < 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, boxesWorld[i].end.y, players[idx]->GetPosition().z);
							players[idx]->yspeed = 0.0f;
							players[idx]->isInAir = false;
						}

						crash = true;
					}

				}

				else if (tx > boxesWorld[i].start.x - 0.5f && tz > boxesWorld[i].start.z - 0.5f
					&& tx < boxesWorld[i].end.x + 0.5f && tz < boxesWorld[i].end.z + 0.5f && ty>boxesWorld[i].end.y)
				{
					players[idx]->isInAir = true;
					players[idx]->yspeed -= 0.1f;
					stepOn = false;
					crash = false;

				}


			}
			// 적이 있는곳에 이동했는가?
			for (int i = 0; i < enemies.size(); ++i)
			{
				if (tx > enemyBoxes[i].start.x - 0.4f && ty > enemyBoxes[i].start.y - 1.7f && tz > enemyBoxes[i].start.z - 0.4f
					&& tx < enemyBoxes[i].end.x + 0.4f && ty < enemyBoxes[i].end.y + 0.0f && tz < enemyBoxes[i].end.z + 0.4f)
				{


					if (players[idx]->GetPosition().x > enemyBoxes[i].end.x || players[idx]->GetPosition().x < enemyBoxes[i].start.x)
					{
						if (players[idx]->direction.x > 0.0f)
						{
							players[idx]->SetPosition(enemyBoxes[i].start.x - 0.5f, players[idx]->GetPosition().y, players[idx]->GetPosition().z);
							players[idx]->direction.x = 0.0f;

						}
						else if (players[idx]->direction.x < 0.0f)
						{
							players[idx]->SetPosition(enemyBoxes[i].end.x + 0.5f, players[idx]->GetPosition().y, players[idx]->GetPosition().z);
							players[idx]->direction.x = 0.0f;

						}
						crash = true;

					}
					else if (players[idx]->GetPosition().z > enemyBoxes[i].end.z || players[idx]->GetPosition().z < enemyBoxes[i].start.z)
					{
						if (players[idx]->direction.z > 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, players[idx]->GetPosition().y, enemyBoxes[i].start.z - 0.5f);
							players[idx]->direction.z = 0.0f;

						}
						else if (players[idx]->direction.z < 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, players[idx]->GetPosition().y, enemyBoxes[i].end.z + 0.5f);
							players[idx]->direction.z = 0.0f;

						}
						crash = true;

					}
					else if (players[idx]->yspeed != 0.0f)
					{
						if (players[idx]->yspeed > 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, enemyBoxes[i].start.y - 1.7f, players[idx]->GetPosition().z);
							players[idx]->yspeed = 0.0f;
						}
						else if (players[idx]->yspeed < 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, enemyBoxes[i].end.y, players[idx]->GetPosition().z);
							players[idx]->yspeed = 0.0f;
							players[idx]->isInAir = false;
						}

						crash = true;
					}

				}

			}

			//계단이 있는 곳에 갔는가?
			for (int i = 0; i < nStairs; ++i)
			{
				if (tx > stairsWorld[i].start.x - 0.4f && ty > stairsWorld[i].start.y - 1.7f && tz > stairsWorld[i].start.z - 0.4f
					&& tx < stairsWorld[i].end.x + 0.4f && ty < stairsWorld[i].end.y - 0.3f && tz < stairsWorld[i].end.z + 0.4f)
				{


					if (players[idx]->GetPosition().x > stairsWorld[i].end.x || players[idx]->GetPosition().x < stairsWorld[i].start.x)
					{
						if (players[idx]->direction.x > 0.0f)
						{
							players[idx]->SetPosition(stairsWorld[i].start.x - 0.5f, players[idx]->GetPosition().y, players[idx]->GetPosition().z);
							players[idx]->direction.x = 0.0f;

						}
						else if (players[idx]->direction.x < 0.0f)
						{
							players[idx]->SetPosition(stairsWorld[i].end.x + 0.5f, players[idx]->GetPosition().y, players[idx]->GetPosition().z);
							players[idx]->direction.x = 0.0f;

						}
						crash = true;

					}
					else if (players[idx]->GetPosition().z > stairsWorld[i].end.z || players[idx]->GetPosition().z < stairsWorld[i].start.z)
					{
						if (players[idx]->direction.z > 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, players[idx]->GetPosition().y, stairsWorld[i].start.z - 0.5f);
							players[idx]->direction.z = 0.0f;

						}
						else if (players[idx]->direction.z < 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, players[idx]->GetPosition().y, stairsWorld[i].end.z + 0.5f);
							players[idx]->direction.z = 0.0f;

						}
						crash = true;

					}
					else if (players[idx]->isInAir == true)
					{
						if (players[idx]->yspeed > 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, boxesWorld[i].start.y - 1.7f, players[idx]->GetPosition().z);
							players[idx]->yspeed = 0.0f;
						}
						else if (players[idx]->yspeed < 0.0f)
						{
							players[idx]->SetPosition(players[idx]->GetPosition().x, boxesWorld[i].end.y, players[idx]->GetPosition().z);
							players[idx]->yspeed = 0.0f;
							players[idx]->isInAir = false;
						}

						crash = true;
					}
					stepOn = false;
				}

				else if (tx > stairsWorld[i].start.x - 0.5f && ty >= stairsWorld[i].start.y - 0.3f && tz > stairsWorld[i].start.z - 0.5f
					&& tx < stairsWorld[i].end.x + 0.5f && ty <= stairsWorld[i].end.y && tz < stairsWorld[i].end.z + 0.5f)
				{
					ty = stairsWorld[i].end.y;
					players[idx]->yspeed = 0.0f;
					players[idx]->isInAir = false;
					crash = false;
					stepOn = true;
				}
				else if (tx > stairsWorld[i].start.x - 0.5f && tz > stairsWorld[i].start.z - 0.5f
					&& tx < stairsWorld[i].end.x + 0.5f && tz < stairsWorld[i].end.z + 0.5f && ty > stairsWorld[i].end.y)
				{
					players[idx]->isInAir = true;
					players[idx]->yspeed -= 0.1f;
					stepOn = false;
					crash = false;
				}

			}

			if (crash == false)
			{
				players[idx]->SetPosition(tx, ty, tz);
				//m_ppShadows[idx]->SetPosition(tx, -0.01f, tz);
				players[idx]->lastMoveSuccess = true;

				// y축 이동이 존재할 경우 중력가속도 적용
				if (players[idx]->isInAir == true)
				{
					players[idx]->yspeed -= 9.8f * fTime * 5.0f;
				}
			}

			else
			{
				players[idx]->lastMoveSuccess = false;
				if (players[idx]->isInAir == true)
				{
					players[idx]->SetPosition(players[idx]->GetPosition().x, ty, players[idx]->GetPosition().z);
					players[idx]->lastMoveSuccess = true;

					//if (players[idx]->yspeed != 0.0f)
					//{
					players[idx]->yspeed -= 9.8f * fTime * 5.0f;
					//}
				}

			}

		}
	

	// 여기까지 완료한 후, 몇번째 클라이언트의 플레이어인지 나타내는 idx값, 
	// 변경 완료된 위치 값을 클라로 전송.
	// moveObject 함수는 매 프레임마다 호출되므로 서버에서도 약 0.016초(초당 60프레임 기준)마다 전송해주는게 좋음.
}



void CScene::setObjectSpeed(int idx, float size)
{
	//플레이어의 속도 크기 및 방향 벡터를 서버가 계산해줘야 한다.
	players[idx]->speed = size;

	float rad = XMConvertToRadians(players[idx]->currentRotation.y);

	players[idx]->direction = Vector3::Normalize(XMFLOAT3(sin(rad), 0.0f, cos(rad)));
	// speed, direction값을 클라에게 전달하자.
}

void CScene::setObjectState(int index, int state)
{
	// 플레이어의 상태가 변하면 서버가 id값, 몇 번째 플레이어인지 index값을 전해준다.
	// 어차피 timeElapsed는 클라가 상태 변화를 나타내는 패킷을 수신받은
	// 시점을 기준으로 시간을 측정하면 되므로 서버가 전해줄 필요가 없다.
	if (players[index]->objType == TYPE_PLAYER)
	{
		if (players[index]->pState.id != state)
		{
			players[index]->pState.id = state;
			players[index]->pState.timeElapsed = 0.0f;
		}
	}
	// 적의 경우에도 id, index값만 전해주면 된다.
	else if (players[index]->objType == TYPE_ENEMY)
	{
		if (players[index]->eState.id != state)
		{
			players[index]->eState.id = state;
			players[index]->eState.timeElapsed = 0.0f;
		}
	}
}

bool CScene::moveSuccessed(int idx)
{
	return players[idx]->lastMoveSuccess;
}

void CScene::rotateObject(int idx, float x, float y, float z)
{
	//플레이어가 현재 바라보는 방향을 계산한다.
	//이걸 서버가 해야 된다.
	players[idx]->Rotate(x, y, z);
	players[idx]->currentRotation.x += x;
	players[idx]->currentRotation.y += y;
	players[idx]->currentRotation.z += z;

	if (players[idx]->currentRotation.x >= 360.0f)
	{
		players[idx]->currentRotation.x -= 360.0f;
	}
	if (players[idx]->currentRotation.y >= 360.0f)
	{
		players[idx]->currentRotation.y -= 360.0f;
	}
	if (players[idx]->currentRotation.z >= 360.0f)
	{
		players[idx]->currentRotation.z -= 360.0f;
	}

	if (players[idx]->currentRotation.x < 0.0f)

	{
		players[idx]->currentRotation.x += 360.0f;
	}
	if (players[idx]->currentRotation.y < 0.0f)
	{
		players[idx]->currentRotation.y += 360.0f;
	}
	if (players[idx]->currentRotation.z < 0.0f)
	{
		players[idx]->currentRotation.z += 360.0f;
	}
	//이런 다음, currentRotation값을 클라에 넘겨주면 된다.
}
void CScene::setPlayerDirection(float dx, float dy, float dz)
{
	if (players[0]->currentRotation.y != dy)
	{
		players[0]->Rotate(0.0f, dy - players[0]->currentRotation.y, 0.0f);
		players[0]->currentRotation.y = dy;
	}
}

//client to server (received)
//client to server (received)
void CScene::recv_packet()
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
		ProcessPacket(packet_ptr);
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

void CScene::process_packet()
{
	
	unsigned char* packet = g_client.m_recv_over.m_sendbuf;
	const int type_kinetic = static_cast<int>(PACKET_TYPE::SC_KINETIC_CHANGE);
	const int type_bionic = static_cast<int>(PACKET_TYPE::SC_BIONIC_CHANGE);
	switch (packet[1])
	{
	case type_kinetic:
	{
		SC_KINETIC_PACKET* p = reinterpret_cast<SC_KINETIC_PACKET*>(packet);
		if (p->kState.isInAir != -9999)
		{
			players[0]->kState.isInAir = p->kState.isInAir;
		}
		if (p->kState.isMobile != -9999)
		{
			players[0]->kState.isMobile = p->kState.isMobile;
		}
		if (p->kState.rotation != -9999.0f)
		{
			players[0]->kState.rotation = p->kState.rotation;
		}
		if (p->kState.yspeed != -9999.0f)
		{
			players[0]->kState.yspeed = p->kState.yspeed;
		}
		if (p->kState.xzspeed != -9999.0f)
		{
			players[0]->kState.xzspeed = p->kState.xzspeed;
		}
		printf("client player kinetic state change complete\n");
		break;
	}
	case type_bionic:
	{
		SC_BIONIC_PACKET* p = reinterpret_cast<SC_BIONIC_PACKET*>(packet);
		if (p->bState.attackID != -9999)
		{
			players[0]->bState.attackID = p->bState.attackID;
		}
		if (p->bState.stateID != -9999)
		{
			players[0]->bState.stateID = p->bState.stateID;
		}
		if (p->bState.isIntelligent != -9999)
		{
			players[0]->bState.isIntelligent = p->bState.isIntelligent;
		}
		if (p->bState.hp != -9999)
		{
			players[0]->bState.hp = p->bState.hp;
		}
	}
	}
}

void CScene::ProcessPacket(unsigned char* p_buf)
{
	char buf[10000];
	PACKET_TYPE type = (PACKET_TYPE)p_buf[1];

	switch (type)
	{
	case PACKET_TYPE::SC_LOGIN_INFO:
		SC_LOGIN_INFO_PACKET p_login;
		memcpy(&p_login, p_buf, p_buf[0]);
		if (p_login.isLogin)
		{
			XMFLOAT3 pos = XMFLOAT3{ p_login.x, p_login.y, p_login.z };

			//SetplayerID(p_login.id);

			cout << "\nPlayer ID : " << p_login.id << "\n" << endl;
			cout << "x,y,z = " << p_login.x << p_login.y << p_login.z << "\n" << endl;
		}
		break;

	case PACKET_TYPE::SC_ADD_PLAYER:
	{
		cout << "New Player Connected.\n";
		SC_ADD_PLAYER_PACKET p_new;
		memcpy(&p_new, p_buf, p_buf[0]);

		XMFLOAT3 pos = XMFLOAT3{ p_login.x, p_login.y, p_login.z };
		players[p_new.id]->SetPosition(pos);
		break;
	}
	case PACKET_TYPE::SC_REMOVE_PLAYER:
		SC_REMOVE_PLAYER_PACKET p_remove;
		memcpy(&p_remove, p_buf, p_buf[0]);
		cout << p_remove.id << "Player REMOVED.\n";
		
		//player remove
		break;
		//case PACKET_TYPE::SC_KEYBOARD_INPUT:

	}

}


void CScene::attack(int idx)
{
	chrono::duration<double> fromLastAttack = chrono::system_clock::now() - players[idx]->lastAttack;
	float fTime = static_cast<float>(fromLastAttack.count());
	
	if (fTime >= 1.0f / 6.0f)
	{
		soundEffect[0]->play();
		soundEffect[0]->Update();
		printf("time elapsed from last shot : %f\n", fTime);
		setObjectLastAttack(idx);

		float rad = XMConvertToRadians(players[idx]->currentRotation.y);
		//printf("발사 각도 %f  ", players[idx]->currentRotation.y);
		XMFLOAT3 dir = XMFLOAT3(sin(rad), 0.0f, cos(rad)); // 사격 방향

		Line line;
		line.start = players[idx]->GetPosition(); // 사격 위치
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
		for (int i = 0; i < nBox; ++i)
		{
			// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

			std::vector<XYZPlane> checkList;


			if (n.x > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = boxesWorld[i].start.x;
				checkList.push_back(p);
			}
			else if (n.x < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = boxesWorld[i].end.x;
				checkList.push_back(p);
			}

			if (n.z > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = boxesWorld[i].start.z;
				checkList.push_back(p);
			}
			else if (n.z < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = boxesWorld[i].end.z;
				checkList.push_back(p);
			}

			if (n.y > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = boxesWorld[i].start.y;
				checkList.push_back(p);
			}
			else if (n.y < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = boxesWorld[i].end.y;
				checkList.push_back(p);
			}

			
			//체크리스트에 들어있는 모든 평면들에 대해

			for (int j = 0; j < checkList.size(); ++j)
			{
				// 충돌 지점을 확보한다.
				temp = getIntersectPoint(line, checkList[j]);
				

				//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
				if ((temp.x <= boxesWorld[i].end.x+0.001f && temp.x >= boxesWorld[i].start.x-0.001f) &&
					(temp.y <= boxesWorld[i].end.y + 0.001f && temp.y >= boxesWorld[i].start.y-0.001f) &&
					(temp.z <= boxesWorld[i].end.z + 0.001f && temp.z >= boxesWorld[i].start.z-0.001f))
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

		soundEffect[1]->play();
		soundEffect[1]->Update();
		// 적한테 총알이 박혔나?
		for (int i = 0; i < enemies.size(); ++i)
		{
			// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

			std::vector<XYZPlane> checkList;


			if (n.x > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = enemyBoxes[i].start.x;
				checkList.push_back(p);
			}
			else if (n.x < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = enemyBoxes[i].end.x;
				checkList.push_back(p);
			}

			if (n.z > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = enemyBoxes[i].start.z;
				checkList.push_back(p);
			}
			else if (n.z < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = enemyBoxes[i].end.z;
				checkList.push_back(p);
			}

			if (n.y > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = enemyBoxes[i].start.y;
				checkList.push_back(p);
			}
			else if (n.y < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = enemyBoxes[i].end.y;
				checkList.push_back(p);
			}


			//체크리스트에 들어있는 모든 평면들에 대해

			for (int j = 0; j < checkList.size(); ++j)
			{
				// 충돌 지점을 확보한다.
				temp = getIntersectPoint(line, checkList[j]);


				//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
				if ((temp.x <= enemyBoxes[i].end.x + 0.001f && temp.x >= enemyBoxes[i].start.x - 0.001f) &&
					(temp.y <= enemyBoxes[i].end.y + 0.001f && temp.y >= enemyBoxes[i].start.y - 0.001f) &&
					(temp.z <= enemyBoxes[i].end.z + 0.001f && temp.z >= enemyBoxes[i].start.z - 0.001f))
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

		for (int i = 0; i < nStairs; ++i)
		{
			// 사격 시 x,y,z 방향에 따라서 충돌 검사를 수행할 바운딩 박스의 평면들을 체크리스트에 작성. 1~3개까지 존재 가능.

			std::vector<XYZPlane> checkList;


			if (n.x > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = stairsWorld[i].start.x;
				checkList.push_back(p);
			}
			else if (n.x < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(1.0f, 0.0f, 0.0f);
				p.pos = stairsWorld[i].end.x;
				checkList.push_back(p);
			}

			if (n.z > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = stairsWorld[i].start.z;
				checkList.push_back(p);
			}
			else if (n.z < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 0.0f, 1.0f);
				p.pos = stairsWorld[i].end.z;
				checkList.push_back(p);
			}

			if (n.y > 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = stairsWorld[i].start.y;
				checkList.push_back(p);
			}
			else if (n.y < 0.0f)
			{
				XYZPlane p;
				p.normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
				p.pos = stairsWorld[i].end.y;
				checkList.push_back(p);
			}


			//체크리스트에 들어있는 모든 평면들에 대해

			for (int j = 0; j < checkList.size(); ++j)
			{
				// 충돌 지점을 확보한다.
				temp = getIntersectPoint(line, checkList[j]);


				//충돌 지점이 바운딩 박스 내에 존재하는 경우 (사실은 테두리에 있다.)
				if ((temp.x <= stairsWorld[i].end.x + 0.001f && temp.x >= stairsWorld[i].start.x - 0.001f) &&
					(temp.y <= stairsWorld[i].end.y + 0.001f && temp.y >= stairsWorld[i].start.y - 0.001f) &&
					(temp.z <= stairsWorld[i].end.z + 0.001f && temp.z >= stairsWorld[i].start.z - 0.001f))
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
			if ((m_ppGameObjects[target]->type < 3000 && m_ppGameObjects[target]->type >= 2000) || (m_ppGameObjects[target]->type < 13000 && m_ppGameObjects[target]->type >= 12000))
			{
				printf("(Building Wall)\n");
			}
			else if (m_ppGameObjects[target]->type < 6000 && m_ppGameObjects[target]->type >= 5000)
			{
				printf("(Container)\n");
			}

			else if (m_ppGameObjects[target]->type == 90000)
			{
				printf("(Heater)\n");
			}

			else
			{
				printf("(Something)\n");
			}*/
		}
		else if (type == 2)
		{
			//또한 서버는 총알이 적에 맞았을 경우 target번째 적의 체력이 n 만큼 감소했다고 클라한테 알려줘야한다.
			//여기서도 패킷 하나 더만들어 보내자.
			enemies[target]->eState.currHP -= 1;
		}

		// type, target, targetPos 3개의 값이 전송되면, 클라는 그3개의 값을 받아서
		// 해당 위치에 불꽃이 튀는 듯한 파티클을 생성한다. 
		createParticles(100, targetPos);
		// 그니까, createParticles 함수는 서버의 전담이 아니다.
	}


}


void CScene::swingHammer(int idx, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	chrono::duration<double> fromLastAttack = chrono::system_clock::now() - players[idx]->lastAttack;
	float fTime = static_cast<float>(fromLastAttack.count());

	if (fTime >= 1.0f)
	{
		

		printf("Time elapsed from last swing : %f\n", fTime);
		setObjectLastAttack(idx);
		players[idx]->hammerHit = false;
		soundEffect[3]->play();
		soundEffect[3]->Update();

		int r = rand() % 2;

		if (r)
		{
			if (players[idx]->m_pChild != binModels[3]->m_pModelRootObject)
			{
				players[idx]->setRoot(binModels[3]->m_pModelRootObject, true);
				players[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[3]);
				setPlayerAnimation(0);
			}
		}
		else
		{
			if (players[idx]->m_pChild != binModels[4]->m_pModelRootObject)
			{
				players[idx]->setRoot(binModels[4]->m_pModelRootObject, true);
				players[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[4]);
				setPlayerAnimation(0);
			}
		}
	}

	else if (fTime >= 0.233333f && fTime <= 0.266666f)
	{
		for (int i = 0; i < enemyBoxes.size(); ++i)
		{
			BoundBox bx;
			XMFLOAT3 ps = players[idx]->GetPosition();

			if (players[idx]->currentRotation.y <= 22.5f || players[idx]->currentRotation.y > 337.5f) //북향
			{
				bx.start = XMFLOAT3(ps.x - 0.3f, ps.y + 0.6f, ps.z + 0.4f);
				bx.end = XMFLOAT3(ps.x + 0.3f, ps.y + 1.0f, ps.z + 1.0f);
			}
			else if (players[idx]->currentRotation.y <= 67.5f && players[idx]->currentRotation.y > 22.5f)//동북향
			{
				bx.start = XMFLOAT3(ps.x + 0.2f, ps.y + 0.6f, ps.z+0.2f);
				bx.end = XMFLOAT3(ps.x + 0.8f, ps.y + 1.0f, ps.z + 0.8f);
			}
			else if (players[idx]->currentRotation.y <= 112.5f && players[idx]->currentRotation.y > 67.5f) //동향
			{
				bx.start = XMFLOAT3(ps.x + 0.4f, ps.y + 0.6f, ps.z - 0.3f);
				bx.end = XMFLOAT3(ps.x + 1.0f, ps.y + 1.0f, ps.z + 0.3f);
			}
			else if (players[idx]->currentRotation.y <= 157.5f && players[idx]->currentRotation.y > 112.5f) //동남향
			{
				bx.start = XMFLOAT3(ps.x+0.2f, ps.y + 0.6f, ps.z-0.8f);
				bx.end = XMFLOAT3(ps.x + 0.8f, ps.y + 1.0f, ps.z - 0.2f);
			}
			else if (players[idx]->currentRotation.y <= 202.5f && players[idx]->currentRotation.y > 157.5f) //남향
			{
				bx.start = XMFLOAT3(ps.x - 0.3f, ps.y + 0.6f, ps.z - 1.0f);
				bx.end = XMFLOAT3(ps.x + 0.3f, ps.y + 1.0f, ps.z - 0.4f);
			}
			else if (players[idx]->currentRotation.y <= 247.5f && players[idx]->currentRotation.y > 202.5f)//서남향
			{
				bx.start = XMFLOAT3(ps.x-0.8f, ps.y + 0.6f, ps.z-0.8f);
				bx.end = XMFLOAT3(ps.x - 0.2f, ps.y + 1.0f, ps.z - 0.2f);
			}
			else if (players[idx]->currentRotation.y <= 292.5f && players[idx]->currentRotation.y > 247.5f) //서향
			{
				bx.start = XMFLOAT3(ps.x - 1.0f, ps.y + 0.6f, ps.z - 0.3f);
				bx.end = XMFLOAT3(ps.x - 0.4f, ps.y + 1.0f, ps.z + 0.3f);
			}
			else if (players[idx]->currentRotation.y <= 337.5f && players[idx]->currentRotation.y > 292.5f) //북서향
			{
				bx.start = XMFLOAT3(ps.x-0.8f, ps.y + 0.6f, ps.z+0.2f);
				bx.end = XMFLOAT3(ps.x - 0.2f, ps.y + 1.0f, ps.z + 0.8f);
			}

			XMFLOAT3 pnt = getBoxOverlapPoint(bx, enemyBoxes[i], players[idx]->currentRotation.y);
			
			if (pnt.x != -9999.0f && pnt.y != -9999.0f && pnt.z != -9999.0f && players[idx]->hammerHit==false)
			{
				printf("Enemy [%d] hit\n", i);
				soundEffect[4]->play();
				soundEffect[4]->Update();
				players[idx]->hammerHit = true;
				createParticles(50, pnt);
				enemies[i]->eState.currHP -= 1.0f;
			}
		}
	}
	else if (fTime >= 0.833333f && fTime < 1.0f)
	{
		if (players[idx]->m_pChild != binModels[2]->m_pModelRootObject)
		{
			players[idx]->setRoot(binModels[2]->m_pModelRootObject, true);
			players[idx]->m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, 1, binModels[2]);
			setPlayerAnimation(0);
			
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
		obj->SetMaterial(0, ppMaterials[33]);
		obj->speed = 0.1f;
		obj->direction = direct;
		obj->SetPosition(pos);
		obj->SetMesh(partMesh);
		particles.push_back(obj);
	}
}

// 적 만드는 함수
void CScene::createEnemies(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	enemyModels = new CLoadedModelInfo * [nEnemyMesh];
	enemyModels[0] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_idle.bin", NULL);
	enemyModels[1] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_die.bin", NULL);


	CGameObject* obj = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj->SetPosition(160.0f, 0.0f, 280.0f);
	obj->type = -10;
	obj->SetTrackAnimationSet(0, 0);

	obj->eState.id = IDLE_STATE;
	obj->eState.currHP = 10;
	enemies.push_back(obj);

	CGameObject* obj2 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj2->SetPosition(160.0f, 0.0f, 320.0f);
	obj2->type = -10;
	obj2->SetTrackAnimationSet(0, 0);

	obj2->eState.id = IDLE_STATE;
	obj2->eState.currHP = 10;
	enemies.push_back(obj2);

	CGameObject* obj3 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj3->SetPosition(170.0f, 0.0f, 300.0f);
	obj3->type = -10;
	obj3->SetTrackAnimationSet(0, 0);

	obj3->eState.id = IDLE_STATE;
	obj3->eState.currHP = 10;
	enemies.push_back(obj3);

	CGameObject* obj4= new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj4->SetPosition(225.0f, 0.0f, 320.0f);
	obj4->type = -10;
	obj4->SetTrackAnimationSet(0, 0);
	   
	obj4->eState.id = IDLE_STATE;
	obj4->eState.currHP = 10;
	enemies.push_back(obj4);

	CGameObject* obj5 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj5->SetPosition(225.0f, 0.0f, 345.0f);
	obj5->type = -10;
	obj5->SetTrackAnimationSet(0, 0);

	obj5->eState.id = IDLE_STATE;
	obj5->eState.currHP = 10;
	enemies.push_back(obj5);

	CGameObject* obj6 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj6->SetPosition(240.0f, 0.0f, 320.0f);
	obj6->type = -10;
	obj6->SetTrackAnimationSet(0, 0);

	obj6->eState.id = IDLE_STATE;
	obj6->eState.currHP = 10;
	enemies.push_back(obj6);

	CGameObject* obj7 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj7->SetPosition(240.0f, 0.0f, 345.0f);
	obj7->type = -10;
	obj7->SetTrackAnimationSet(0, 0);

	obj7->eState.id = IDLE_STATE;
	obj7->eState.currHP = 10;
	enemies.push_back(obj7);


	CGameObject* obj8 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
	obj8->SetPosition(207.0f, 0.0f, 320.0f);
	obj8->type = -10;
	obj8->SetTrackAnimationSet(0, 0);
	obj8->eState.id = IDLE_STATE;
	obj8->eState.currHP = 10;
	enemies.push_back(obj8);

	for (int i = 0; i < 4; ++i)
	{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(450.0f+i*15.0f, 0.0f, 330.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);
	}
	for (int i = 0; i < 3; ++i)
	{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(450.0f + i * 15.0f, 0.0f, 80.0f+i*8.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);

		CGameObject* obj00 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj00->SetPosition(420.0f + i * 10.0f, 0.0f, 80.0f + i * 3.0f);
		obj00->type = -10;
		obj00->SetTrackAnimationSet(0, 0);
		obj00->eState.id = IDLE_STATE;
		obj00->eState.currHP = 10;
		enemies.push_back(obj00);
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(495.0f + i * -20.0f, 0.0f, 565.0f+j*-15.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(860.0f, 0.0f, 565.0f+ i * -15.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);
	}
	for (int i = 0; i < 5; ++i)
	{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(960.0f+i*5.0f, 0.0f, 65.0f + i * -5.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);
	}
	for (int i = 0; i < 5; ++i)
	{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(1160.0f+5.0f*i, 0.0f, 555+i*3.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);
	}
	for (int i = 0; i < 3; ++i)
	{
		CGameObject* obj0 = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, enemyModels[0], 1);
		obj0->SetPosition(1222.0f + 5.0f * i, 0.0f, 545 + i * -3.0f);
		obj0->type = -10;
		obj0->SetTrackAnimationSet(0, 0);
		obj0->eState.id = IDLE_STATE;
		obj0->eState.currHP = 10;
		enemies.push_back(obj0);
	}
	// 각 적들의 위치에 바운딩 박스 생성
	for (int i = 0; i < enemies.size(); ++i)
	{
		//x,y=-0.25~0.25 z=0.0~1.7

		XMFLOAT3 pos = enemies[i]->GetPosition();

		BoundBox box;
		box.start = XMFLOAT3(pos.x - 0.4f, pos.y, pos.z - 0.4f);
		box.end = XMFLOAT3(pos.x + 0.4f, pos.y + 1.7f, pos.z + 0.4f);

		enemyBoxes.push_back(box);
	}

}

void CScene::createPlayers(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	binModels = new CLoadedModelInfo*[nSkinMesh];
	playerTypes = new CGameObject * [nSkinMesh];

	binModels[0] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/sample.bin", NULL);
	binModels[1] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_walk.bin", NULL);
	binModels[2] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rescale4.bin", NULL);
	binModels[3] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_swing1.bin", NULL);
	binModels[4] = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_swing2.bin", NULL);
	CGameObject* obj = new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, binModels[0], 1);
	obj->type = 1;
	obj->objType = 1;

	obj->SetPosition(100.0f, 0.0f, 100.0f);
	obj->Rotate(0.0f, 0.0f, 0.0f);
	obj->currentRotation = XMFLOAT3(0.0f, 0.0f, 0.0f);
	
	obj->speed = 0.0f;
	obj->direction = XMFLOAT3(0.0f, 0.0f, 0.0f);
	obj->lastMove = chrono::system_clock::now();

	obj->pState.currHP = 100;
	obj->pState.id = IDLE_STATE;
	obj->pState.timeElapsed = 0.0f;
	obj->pState.attType = TYPE_RANGED;

	obj->SetTrackAnimationSet(0, 11);
	currentPlayerAnim = 11;
	
	


	/*
	if (shadowRect[0] == NULL)
	{
		shadowRect[0] = new RectMesh(pd3dDevice, pd3dCommandList, 0.7f, 0.7f);
	}
	shd = new CGameObject(1);
	shd->SetMesh(shadowRect[0]);
	shd->SetMaterial(0, shadowMats[0]);
	*/
	obj->SetMaterial(0, ppMaterials[32]);

	playerTypes[0] = obj;

	playerTypes[1]= new CLionObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, binModels[1], 1);
	playerTypes[1]->type = 1;
	playerTypes[1]->objType = 1;
	
	playerTypes[1]->speed = 0.0f;
	playerTypes[1]->direction = XMFLOAT3(0.0f, 0.0f, 0.0f);
	playerTypes[1]->lastMove = chrono::system_clock::now();
	
	playerTypes[1]->pState.currHP = 100;
	playerTypes[1]->pState.id = IDLE_STATE;
	playerTypes[1]->pState.timeElapsed = 0.0f;
	playerTypes[1]->pState.attType = TYPE_RANGED;

	players.push_back(playerTypes[0]);
}
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