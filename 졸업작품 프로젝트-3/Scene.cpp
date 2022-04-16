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
	m_nLights = 2;
	m_pLights = new LIGHT[m_nLights];
	::ZeroMemory(m_pLights, sizeof(LIGHT) * m_nLights);

	m_xmf4GlobalAmbient = XMFLOAT4(0.15f, 0.15f, 0.15f, 1.0f);
	/*
	m_pLights[1].m_bEnable = true;
	m_pLights[1].m_nType = POINT_LIGHT;
	m_pLights[1].m_fRange = 500.0f;
	m_pLights[1].m_xmf4Ambient = XMFLOAT4(0.1f, 0.0f, 0.0f, 1.0f);
	m_pLights[1].m_xmf4Diffuse = XMFLOAT4(0.4f, 0.4f, 0.4f, 1.0f);
	m_pLights[1].m_xmf4Specular = XMFLOAT4(0.7f, 0.7f, 0.7f, 0.0f);
	m_pLights[1].m_xmf3Position = XMFLOAT3(0.0f, 2.0f, 0.0f);
	m_pLights[1].m_xmf3Direction = XMFLOAT3(0.0f, -1.0f, 0.0f);
	m_pLights[1].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.001f);
	*/
	m_pLights[0].m_bEnable = true;
	m_pLights[0].m_nType = DIRECTIONAL_LIGHT;
	m_pLights[0].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[0].m_xmf4Diffuse = XMFLOAT4(0.7f, 0.7f, 0.7f, 1.0f);
	m_pLights[0].m_xmf4Specular = XMFLOAT4(0.4f, 0.4f, 0.4f, 0.0f);
	m_pLights[0].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	
	
	m_pLights[1].m_bEnable = true;
	m_pLights[1].m_nType = SPOT_LIGHT;
	m_pLights[1].m_fRange = 600.0f;
	m_pLights[1].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[1].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[1].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
	m_pLights[1].m_xmf3Position = XMFLOAT3(10.0f, 20.0f, 10.0f);
	m_pLights[1].m_xmf3Direction = XMFLOAT3(0.0f, -1.0f, 0.0f);
	m_pLights[1].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
	m_pLights[1].m_fFalloff = 10.0f;
	m_pLights[1].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[1].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	
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
	textures[20]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/GyeDanTexture.dds", RESOURCE_TEXTURE2D, 0);
	textures[21] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[21]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Heater_Texture.dds", RESOURCE_TEXTURE2D, 0);
	textures[22] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[22]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/BaseColor_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[23] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[23]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Metal_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures[24] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	textures[24]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample.dds", RESOURCE_TEXTURE2D, 0);





	CreateCbvSrvDescriptorHeaps(pd3dDevice, 0, nTex);

	for (int i = 0; i < nTex; ++i)
	{
		CreateShaderResourceViews(pd3dDevice, textures[i], 0, 3);
	}
	/*
	for (int i = 0; i < nNormal; ++i)
	{
		CreateShaderResourceViews(pd3dDevice, normalTex[i], 0, 6);
	}
	
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
		//ppMaterials[i]->SetNormalTex(normalTex[i]);
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

	


	CMaterial::PrepareShaders(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature); 

	BuildDefaultLightsAndMaterials();


	std::vector<Obj> data = LoadObjects("res/map/objects.txt");
	boxesWorld = LoadBoxes("res/map/box.txt", &nBox);
	m_nGameObjects = data.size();
	m_ppGameObjects = new CGameObject*[m_nGameObjects];

	CCubeMeshTextured* pPlayerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 1.7f, 1.0f);
	CCubeMeshTextured* ContMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 100.0f, 25.0f, 50.0f);
	CCubeMeshTextured* J_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 50.0f, 7.5f, 120.0f);
	CCubeMeshTextured* T_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 5.0f, 200.0f);
	CCubeMeshTextured* B_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 260.0f, 12.5f, 320.0f);
	CCubeMeshTextured* ChonJang = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 620.0f, 3.0f, 620.0f);
	CCubeMeshTextured* Add_block1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 7.5f, 25.0f);
	CCubeMeshTextured* Add_block2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 5.0f, 2.5f);
	//CCubeMeshTextured* pContainerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 2.5f, 6.0f);
	//CCubeMeshTextured* Contain1_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 25.0f, 20.0f);



	//CRectMeshTextured* pTileMesh = new CRectMeshTextured(pd3dDevice, pd3dCommandList, 2.5f, 2.5f);

	GridMesh* pGrid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);
	GridMesh* t_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 20.0f);
	GridMesh* Se_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);

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

	CLoadedMesh* container = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_container2.txt", NULL);
	CLoadedMesh* box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_box.txt", NULL);
	CLoadedMesh* tableMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_table.txt", "res/idx_table.txt");
	CLoadedMesh* chairMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_chair3.txt", "res/idx_chair3.txt");
	CLoadedMesh* cartMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_pallet.txt", "res/idx_pallet.txt");
	CLoadedMesh* binMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_bin.txt", "res/idx_bin.txt");
	CLoadedMesh* barrelMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_barrel.txt", "res/idx_barrel.txt");
	CLoadedMesh* truckMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_truck.txt", "res/idx_truck.txt");

	CLoadedMesh* Container1_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Cont1_1.txt", "res/idx_Cont1_1.txt");
	CLoadedMesh* GyeDan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_GyeDan1.txt", NULL);
	CLoadedMesh* GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_GyeDan1.txt", NULL);
	CLoadedMesh* R_GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_GyeDan2.txt", NULL);
	CLoadedMesh* P_Doors = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Doors.txt", NULL);
	CLoadedMesh* H_Heat = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_공장_히터.txt", NULL);
	CLoadedMesh* B_box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_1Stage_Box.txt", NULL);

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
		CGameObject* obj = NULL;
		//CGameObject *shd = NULL;
		float shadowMove = 0.0f;
		float shadowUp = 0.0f;
		if (data[i].type == PLAYER)//player
		{
			CLoadedModelInfo* model=CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "sample.bin", NULL);
			
			obj = new CLionObject(pd3dDevice,pd3dCommandList, m_pd3dGraphicsRootSignature, model, 1);
			obj->type = 1;
			obj->objType = 1;

			obj->pState.currHP = 100;
			obj->pState.id = IDLE_STATE;
			obj->pState.timeElapsed = 0.0f;
			int sets = rand() % 22;

			obj->SetTrackAnimationSet(0, sets);
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
			obj->SetMaterial(0, ppMaterials[24]);
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
			obj->Rotate(270.0f, 0.0f, 0.0f);
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
			obj->Rotate(270.0f, 0.0f, 0.0f);
			obj->SetMaterial(0, ppMaterials[20]);

		}
		else if (data[i].type == R_GyeDan1)// 지붕의 시작점
		{
			obj = new CGameObject(1);
			obj->SetMesh(R_GyeDan_1);
			obj->Rotate(270.0f, 0.0f, 0.0f);
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
			//obj->SetMaterial(ppMaterials[23]);
		}

		
		obj->SetPosition(data[i].position.x, data[i].position.y, data[i].position.z);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		obj->currentRotation = data[i].rotation;
		obj->type = data[i].type;
		obj->speed = 0.0f;
		obj->direction = XMFLOAT3(0.0f, 0.0f, 0.0f);
		obj->lastMove = chrono::system_clock::now();
		m_ppGameObjects[i] = obj;

		/*
		if (shd != NULL)
		{
			shadowMove += data[i].position.y;
			shd->SetPosition(data[i].position.x+shadowMove, 0.0f, data[i].position.z+shadowUp);
			shd->Rotate(0.0f, data[i].rotation.y, 0.0f);
			shd->currentRotation = XMFLOAT3(0.0f, data[i].rotation.y, 0.0f);
			if (data[i].type == PLAYER)
			{
				shd->SetPosition(data[i].position.x + shadowMove, -0.01f, data[i].position.z + shadowUp);
			}
			m_ppShadows[i] = shd;
		}
		*/
		
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

void CScene::AnimateObjects(float fTimeElapsed)
{
	m_fElapsedTime = fTimeElapsed;
	for (int i = 0; i < m_nShaders; i++) if (m_ppShaders[i]) m_ppShaders[i]->AnimateObjects(fTimeElapsed);
	setObjectLastMove(0);
	
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
	for (int i = 0; i < m_nGameObjects; i++)
	{
		if (m_ppGameObjects[i])
		{
			XMFLOAT3 pos = m_ppGameObjects[i]->GetPosition();
			XMFLOAT3 camPos = pCamera->getPosition();

			XMFLOAT3 fromCamera = XMFLOAT3(pos.x - camPos.x, pos.y - camPos.y, pos.z - camPos.z);
			XMFLOAT3 look = pCamera->getLook();
			
			float cosAngle = Vector3::DotProduct(Vector3::Normalize(fromCamera), Vector3::Normalize(look));
			/* 
			//	1. 객체의 유형이 벽인 경우 그냥 그린다.
			//	2. 객체의 유형이 xyz 크기가 3m 이상인 대형 물체인 경우 카메라의 방향 벡터로부터 양쪽 70도 내에 있는 경우에만 그린다.
			//	3. 객체의 유형이 소형 물체, 혹은 움직이는 캐릭터인 경우 양쪽 55도 내에 있는 경우에만 그린다.
			*/

			// 일단은 타입에 관계없이 카메라의 방향으로부터 55도 안쪽에 위치한 물체만 그린다.
			if (cosAngle <= 1 && cosAngle >= cos(XMConvertToRadians(55.0f)))
			{

				m_ppGameObjects[i]->Animate(m_fElapsedTime);
				if (!m_ppGameObjects[i]->m_pSkinnedAnimationController) m_ppGameObjects[i]->UpdateTransform(NULL);
				if (m_pd3dCbvSrvDescriptorHeap)
				{
					pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
				}
				if (m_ppGameObjects[i]->type == 1)
				{
					ppMaterials[24]->UpdateShaderVariable(pd3dCommandList);
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
	for (int i = 0; i < m_nShaders; i++) if (m_ppShaders[i]) m_ppShaders[i]->Render(pd3dCommandList, pCamera);

	
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
	m_ppGameObjects[0]->SetTrackAnimationSet(0, a);
	currentPlayerAnim = a;
}



void CScene::moveObject(int idx)
{
	
	chrono::duration<double> fromLastMove = chrono::system_clock::now() - m_ppGameObjects[idx]->lastMove;
	double time = fromLastMove.count();
	float fTime = static_cast<float>(time);
	bool crash=false;
	float tx, ty, tz;

	
	if (m_ppGameObjects[idx]->speed > 0.0f|| m_ppGameObjects[idx]->yspeed!=0.0f)
	{
		tx = m_ppGameObjects[idx]->GetPosition().x + fTime * m_ppGameObjects[idx]->speed * m_ppGameObjects[idx]->direction.x;
		ty = m_ppGameObjects[idx]->GetPosition().y + fTime * m_ppGameObjects[idx]->yspeed;
		tz = m_ppGameObjects[idx]->GetPosition().z + fTime * m_ppGameObjects[idx]->speed * m_ppGameObjects[idx]->direction.z;

		for (int i = 0; i < nBox; ++i)
		{
			if (tx > boxesWorld[i].start.x - 0.5f && ty > boxesWorld[i].start.y - 1.7f && tz > boxesWorld[i].start.z - 0.5f
				&& tx < boxesWorld[i].end.x + 0.5f && ty < boxesWorld[i].end.y + 0.0f && tz < boxesWorld[i].end.z + 0.5f)
			{
				
				
				if (m_ppGameObjects[idx]->GetPosition().x > boxesWorld[i].end.x || m_ppGameObjects[idx]->GetPosition().x < boxesWorld[i].start.x)
				{
					if (m_ppGameObjects[idx]->direction.x > 0.0f)
					{
						m_ppGameObjects[idx]->SetPosition(boxesWorld[i].start.x - 0.5f, m_ppGameObjects[idx]->GetPosition().y, m_ppGameObjects[idx]->GetPosition().z);
						m_ppGameObjects[idx]->direction.x = 0.0f;
						m_ppGameObjects[idx]->direction.z = 0.0f;
					}
					else if (m_ppGameObjects[idx]->direction.x < 0.0f)
					{
						m_ppGameObjects[idx]->SetPosition(boxesWorld[i].end.x + 0.5f, m_ppGameObjects[idx]->GetPosition().y, m_ppGameObjects[idx]->GetPosition().z);
						m_ppGameObjects[idx]->direction.x = 0.0f;
						m_ppGameObjects[idx]->direction.z = 0.0f;
					}
					crash = true;
					
				}
				else if (m_ppGameObjects[idx]->GetPosition().z > boxesWorld[i].end.z || m_ppGameObjects[idx]->GetPosition().z < boxesWorld[i].start.z)
				{
					if (m_ppGameObjects[idx]->direction.z > 0.0f)
					{
						m_ppGameObjects[idx]->SetPosition(m_ppGameObjects[idx]->GetPosition().x, m_ppGameObjects[idx]->GetPosition().y, boxesWorld[i].start.z - 0.5f);
						m_ppGameObjects[idx]->direction.z = 0.0f;
						m_ppGameObjects[idx]->direction.x = 0.0f;
					}
					else if (m_ppGameObjects[idx]->direction.z < 0.0f)
					{
						m_ppGameObjects[idx]->SetPosition(m_ppGameObjects[idx]->GetPosition().x, m_ppGameObjects[idx]->GetPosition().y, boxesWorld[i].end.z + 0.5f);
						m_ppGameObjects[idx]->direction.z = 0.0f;
						m_ppGameObjects[idx]->direction.x = 0.0f;
					}
					crash = true;
				
				}
				else if (m_ppGameObjects[idx]->isInAir == true)
				{
					if (m_ppGameObjects[idx]->yspeed > 0.0f)
					{
						m_ppGameObjects[idx]->SetPosition(m_ppGameObjects[idx]->GetPosition().x, boxesWorld[i].start.y - 1.7f, m_ppGameObjects[idx]->GetPosition().z);
						m_ppGameObjects[idx]->yspeed = 0.0f;
					}
					else if (m_ppGameObjects[idx]->yspeed < 0.0f)
					{
						m_ppGameObjects[idx]->SetPosition(m_ppGameObjects[idx]->GetPosition().x, boxesWorld[i].end.y, m_ppGameObjects[idx]->GetPosition().z);
						m_ppGameObjects[idx]->yspeed = 0.0f;
						m_ppGameObjects[idx]->isInAir = false;
					}
					
					crash = true;
				}

			}
			
		}



		if (crash == false)
		{
			m_ppGameObjects[idx]->SetPosition(tx, ty, tz);
			//m_ppShadows[idx]->SetPosition(tx, -0.01f, tz);
			m_ppGameObjects[idx]->lastMoveSuccess = true;

			// y축 이동이 존재할 경우 중력가속도 적용
			if (m_ppGameObjects[idx]->yspeed != 0.0f)
			{
				m_ppGameObjects[idx]->yspeed -= 9.8f * fTime;
			}
		}
		else
		{
			m_ppGameObjects[idx]->lastMoveSuccess = false;
			if (m_ppGameObjects[idx]->isInAir == true)
			{
				m_ppGameObjects[idx]->SetPosition(m_ppGameObjects[idx]->GetPosition().x, ty, m_ppGameObjects[idx]->GetPosition().z);
				m_ppGameObjects[idx]->lastMoveSuccess = true;
				
				if (m_ppGameObjects[idx]->yspeed != 0.0f)
				{
					m_ppGameObjects[idx]->yspeed -= 9.8f * fTime;
				}
			}

		}
	}
	
}



void CScene::setObjectSpeed(int idx, float size)
{
	m_ppGameObjects[idx]->speed = size;

	float rad = XMConvertToRadians(m_ppGameObjects[idx]->currentRotation.y);

	m_ppGameObjects[idx]->direction = Vector3::Normalize(XMFLOAT3(sin(rad), 0.0f, cos(rad)));
}

void CScene::setObjectState(int index, int state)
{
	if (m_ppGameObjects[index]->objType == TYPE_PLAYER)
	{
		if (m_ppGameObjects[index]->pState.id != state)
		{
			m_ppGameObjects[index]->pState.id = state;
			m_ppGameObjects[index]->pState.timeElapsed = 0.0f;
		}
	}
	else if (m_ppGameObjects[index]->objType == TYPE_ENEMY)
	{
		if (m_ppGameObjects[index]->eState.id != state)
		{
			m_ppGameObjects[index]->eState.id = state;
			m_ppGameObjects[index]->eState.timeElapsed = 0.0f;
		}
	}
}

bool CScene::moveSuccessed(int idx)
{
	return m_ppGameObjects[idx]->lastMoveSuccess;
}

void CScene::rotateObject(int idx, float x, float y, float z)
{
	m_ppGameObjects[idx]->Rotate(x, y, z);
	m_ppGameObjects[idx]->currentRotation.x += x;
	m_ppGameObjects[idx]->currentRotation.y += y;
	m_ppGameObjects[idx]->currentRotation.z += z;

	if (m_ppGameObjects[idx]->currentRotation.x >= 360.0f)
	{
		m_ppGameObjects[idx]->currentRotation.x -= 360.0f;
	}
	if (m_ppGameObjects[idx]->currentRotation.y >= 360.0f)
	{
		m_ppGameObjects[idx]->currentRotation.y -= 360.0f;
	}
	if (m_ppGameObjects[idx]->currentRotation.z >= 360.0f)
	{
		m_ppGameObjects[idx]->currentRotation.z -= 360.0f;
	}

	if (m_ppGameObjects[idx]->currentRotation.x < 0.0f)

	{
		m_ppGameObjects[idx]->currentRotation.x += 360.0f;
	}
	if (m_ppGameObjects[idx]->currentRotation.y < 0.0f)
	{
		m_ppGameObjects[idx]->currentRotation.y += 360.0f;
	}
	if (m_ppGameObjects[idx]->currentRotation.z < 0.0f)
	{
		m_ppGameObjects[idx]->currentRotation.z += 360.0f;
	}

}
void CScene::setPlayerDirection(float dx, float dy, float dz)
{
	if (m_ppGameObjects[0]->currentRotation.y != dy)
	{
		m_ppGameObjects[0]->Rotate(0.0f, dy - m_ppGameObjects[0]->currentRotation.y, 0.0f);
		m_ppGameObjects[0]->currentRotation.y = dy;
	}
}

//client to server (received)
void CScene::recv_packet()
{
	g_client.m_recv_over.m_wsabuf.buf = reinterpret_cast<char*>(g_client.m_recv_over.m_sendbuf) + g_client.m_prev_size;
	g_client.m_recv_over.m_wsabuf.len = BUFSIZE - g_client.m_prev_size;

	memset(&g_client.m_recv_over.m_over, 0, sizeof(g_client.m_recv_over.m_over));

	DWORD iobyte, ioflag = 0;
	int ret = WSARecv(g_client.m_sock, &g_client.m_recv_over.m_wsabuf, 1,
		&iobyte, &ioflag, NULL, NULL);
	if (0 != ret) {
		auto errcode = WSAGetLastError();
		if (WSA_IO_PENDING != errcode)
			err_display("Error in RecvPacket: ");
	}

	char* packet_ptr = g_client.m_recv_over.m_sendbuf; //unsigned ?
	int num_data = iobyte + g_client.m_prev_size;
	int packet_size = packet_ptr[0];

	while (num_data >= packet_size) {
		//
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