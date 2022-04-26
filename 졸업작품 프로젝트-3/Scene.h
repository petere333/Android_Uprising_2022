//-----------------------------------------------------------------------------
// File: Scene.h
//-----------------------------------------------------------------------------

#pragma once

#include "Shader.h"
#include "LevelLoader.h"
#include "stdafx.h"
#include "Game_Data.h"
#include "CNet.h"

#define MAX_LIGHTS						16 

#define POINT_LIGHT						1
#define SPOT_LIGHT						2
#define DIRECTIONAL_LIGHT				3

struct LIGHT
{
	XMFLOAT4							m_xmf4Ambient;
	XMFLOAT4							m_xmf4Diffuse;
	XMFLOAT4							m_xmf4Specular;
	XMFLOAT3							m_xmf3Position;
	float 								m_fFalloff;
	XMFLOAT3							m_xmf3Direction;
	float 								m_fTheta; //cos(m_fTheta)
	XMFLOAT3							m_xmf3Attenuation;
	float								m_fPhi; //cos(m_fPhi)
	bool								m_bEnable;
	int									m_nType;
	float								m_fRange;
	float								padding;
};										
										
struct LIGHTS							
{										
	LIGHT								m_pLights[MAX_LIGHTS];
	XMFLOAT4							m_xmf4GlobalAmbient;
	int									m_nLights;
};
struct MATERIAL
{
	XMFLOAT4				m_xmf4Ambient;
	XMFLOAT4				m_xmf4Diffuse;
	XMFLOAT4				m_xmf4Specular; //(r,g,b,a=power)
	XMFLOAT4				m_xmf4Emissive;
};

struct MATERIALS
{
	MATERIAL				m_pReflections[8];
};
class CScene
{
public:

    CScene();
    ~CScene();

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	virtual void CreateShaderVariables(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList);
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList);
	virtual void ReleaseShaderVariables();

	void BuildDefaultLightsAndMaterials();
	void BuildObjects(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList);
	void ReleaseObjects();

	ID3D12RootSignature *CreateGraphicsRootSignature(ID3D12Device *pd3dDevice);
	ID3D12RootSignature *GetGraphicsRootSignature() { return(m_pd3dGraphicsRootSignature); }

	bool ProcessInput(UCHAR *pKeysBuffer);
    void AnimateObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float fTimeElapsed);
    void Render(ID3D12GraphicsCommandList *pd3dCommandList, CCamera *pCamera=NULL);

	void ReleaseUploadBuffers();

	void CreateCbvSrvDescriptorHeaps(ID3D12Device* pd3dDevice, int nConstantBufferViews, int nShaderResourceViews);
	void CreateConstantBufferViews(ID3D12Device* pd3dDevice, int nConstantBufferViews, ID3D12Resource* pd3dConstantBuffers, UINT nStride);
	void CreateShaderResourceViews(ID3D12Device* pd3dDevice, CTexture* pTexture, UINT nDescriptorHeapIndex, UINT nRootParameterStartIndex);
	

public:
	ID3D12RootSignature					*m_pd3dGraphicsRootSignature = NULL;

	ID3D12DescriptorHeap* m_pd3dCbvSrvDescriptorHeap = NULL;

	D3D12_CPU_DESCRIPTOR_HANDLE			m_d3dCbvCPUDescriptorStartHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE			m_d3dCbvGPUDescriptorStartHandle;
	D3D12_CPU_DESCRIPTOR_HANDLE			m_d3dSrvCPUDescriptorStartHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE			m_d3dSrvGPUDescriptorStartHandle;

	D3D12_CPU_DESCRIPTOR_HANDLE			m_d3dSrvCPUDescriptorNextHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE			m_d3dSrvGPUDescriptorNextHandle;

	#define nTex  37
	#define nNormal  1
	
	#define nDirt  9
	
	#define nMat 37
	#define nDirMat 9

#define nSkinMesh 5
#define nEnemyMesh 2
#define nShadows 9



	CTexture* textures[nTex];
	CMaterial* ppMaterials[nMat];

	CTexture* normalTex[nNormal];
	CTexture* dirtTex[nDirt];
	CMaterial* dirtMaterials[nDirMat];

	ParticleMesh* partMesh=NULL;

	CTexture* shadowTex[nShadows];
	CMaterial* shadowMats[nShadows];

public:
#define nBGM 1
#define nSoundEffect 5

	CSound** bgm = NULL;
	CSound** soundEffect = NULL;

	bool isWalking = false;

public:

	BoundBox* boxesWorld;
	BoundBox* stairsWorld;
	int nStairs=0;


	std::vector<BoundBox> enemyBoxes;
	int nBox = 0;

	XMFLOAT3 playerSpeed = XMFLOAT3(0.0f, 0.0f, 0.0f);
	int currentPlayerAnim = 0;


	
	void moveObject(int);
	
	void setPlayerAnimation(int a);

	int									m_nGameObjects = 0;
	CGameObject							**m_ppGameObjects = NULL;
	std::vector<CGameObject*>			players;
	std::vector<CGameObject*>			particles;
	std::vector<CGameObject*>			enemies;

	int m_nDecos = 0;
	CGameObject** m_ppDecos = NULL;
	CGameObject** m_ppShadows = NULL;

	CLoadedModelInfo** binModels=NULL;
	CLoadedModelInfo** enemyModels = NULL;
	CGameObject** playerTypes = NULL;
	


	float								m_fElapsedTime = 0.0f;

	int									m_nShaders = 0;
	CShader								**m_ppShaders = NULL;



	LIGHT								*m_pLights = NULL;
	int									m_nLights = 0;

	XMFLOAT4							m_xmf4GlobalAmbient;

	ID3D12Resource						*m_pd3dcbLights = NULL;
	LIGHTS								*m_pcbMappedLights = NULL;

	MATERIALS* m_pMaterials = NULL;

	ID3D12Resource* m_pd3dcbMaterials = NULL;
	MATERIAL* m_pcbMappedMaterials = NULL;
public: 
	void setObjectSpeed(int idx, float size);
	void setObjectState(int index, int state);
	bool moveSuccessed(int idx);
	void jumpObject(int idx) { players[idx]->jump(); }


	float getSpeed(int idx) { return players[idx]->speed; }
	XMFLOAT3 getDirection(int idx) { return players[idx]->direction; }
	PlayerState getPlayerState(int idx) { return players[idx]->pState; }
	XMFLOAT3 getPos(int idx) { return players[idx]->GetPosition(); }
	void setObjectLastMove(int idx) 
	{ 
		players[idx]->lastMove = chrono::system_clock::now(); 
	}
	void setObjectLastAttack(int idx)
	{
		players[idx]->lastAttack = chrono::system_clock::now();
	}

	void rotateObject(int idx, float, float, float);

	void setPlayerDirection(float dx, float dy, float dz);

	XMFLOAT3 getObjectRotation(int idx) { return players[idx]->currentRotation; }

	void createTextureData(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);

	void attack(int idx);
	bool mouseDown = false;
	void createParticles(int n, XMFLOAT3 pos);
	void createPlayers(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void createEnemies(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void createSounds();
	void delSounds();
	void swingHammer(int idx, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
public: // client to server
	virtual void recv_packet(); // (receive packet);
	virtual void ClientNet(SOCKET& sock) {}

	virtual void process_packet();

public:
	void ProcessPacket(unsigned char* p_buf);
};
typedef struct Line
{
	XMFLOAT3 start, end;
}Line;

typedef struct XYZPlane
{
	XMFLOAT3 normal;
	float pos;
}XYZPlane;

XMFLOAT3 getIntersectPoint(Line line, XYZPlane plane);

XMFLOAT3 getBoxOverlapPoint(BoundBox b1, BoundBox b2, float angle);