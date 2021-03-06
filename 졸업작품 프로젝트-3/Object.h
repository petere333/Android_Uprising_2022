//------------------------------------------------------- ----------------------
// File: Object.h
//-----------------------------------------------------------------------------

#pragma once

#include "Mesh.h"
#include "Camera.h"
#include "Game_Data.h"
#include "PlayerInfoManager.h"
#include "../AUSERVER/AUSERVER/protocol.h"

#include "LevelLoader.h"

#define DIR_FORWARD					0x01
#define DIR_BACKWARD				0x02
#define DIR_LEFT					0x04
#define DIR_RIGHT					0x08
#define DIR_UP						0x10
#define DIR_DOWN					0x20

struct CB_GAMEOBJECT_INFO
{
	XMFLOAT4X4						m_xmf4x4World;
	UINT							m_nMaterialID;
};

class CShader;
class CStandardShader;

struct BionicState;
struct KineticState;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#define RESOURCE_TEXTURE2D			0x01
#define RESOURCE_TEXTURE2D_ARRAY	0x02	//[]
#define RESOURCE_TEXTURE2DARRAY		0x03
#define RESOURCE_TEXTURE_CUBE		0x04
#define RESOURCE_BUFFER				0x05

struct SRVROOTARGUMENTINFO
{
	int								m_nRootParameterIndex = 0;
	D3D12_GPU_DESCRIPTOR_HANDLE		m_d3dSrvGpuDescriptorHandle;
};

void initShader(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* pd3dGraphicsRootSignature);

class CTexture
{
public:
	CTexture(int nTextureResources, UINT nResourceType, int nSamplers, int nRootParameters);
	virtual ~CTexture();
	int								m_nTextures = 1;

private:
	int								m_nReferences = 0;

	UINT							m_nTextureType;

	
	ID3D12Resource** m_ppd3dTextures = NULL;
	ID3D12Resource** m_ppd3dTextureUploadBuffers;

	UINT* m_pnResourceTypes = NULL;

	_TCHAR(*m_ppstrTextureNames)[64] = NULL;

	DXGI_FORMAT* m_pdxgiBufferFormats = NULL;
	int* m_pnBufferElements = NULL;

	int								m_nRootParameters = 0;
	int* m_pnRootParameterIndices = NULL;
	D3D12_GPU_DESCRIPTOR_HANDLE* m_pd3dSrvGpuDescriptorHandles = NULL;

	int								m_nSamplers = 0;
	D3D12_GPU_DESCRIPTOR_HANDLE* m_pd3dSamplerGpuDescriptorHandles = NULL;

public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }

	void SetSampler(int nIndex, D3D12_GPU_DESCRIPTOR_HANDLE d3dSamplerGpuDescriptorHandle);

	void UpdateShaderVariable(ID3D12GraphicsCommandList* pd3dCommandList, int nParameterIndex, int nTextureIndex);
	void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	void ReleaseShaderVariables();

	void LoadTextureFromDDSFile(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, wchar_t* pszFileName, UINT nResourceType, UINT nIndex);

	void SetRootParameterIndex(int nIndex, UINT nRootParameterIndex);
	void SetGpuDescriptorHandle(int nIndex, D3D12_GPU_DESCRIPTOR_HANDLE d3dSrvGpuDescriptorHandle);

	int GetRootParameters() { return(m_nRootParameters); }
	int GetTextures() { return(m_nTextures); }
	_TCHAR* GetTextureName(int nIndex) { return(m_ppstrTextureNames[nIndex]); }
	ID3D12Resource* GetResource(int nIndex) { return(m_ppd3dTextures[nIndex]); }
	D3D12_GPU_DESCRIPTOR_HANDLE GetGpuDescriptorHandle(int nIndex) { return(m_pd3dSrvGpuDescriptorHandles[nIndex]); }
	int GetRootParameter(int nIndex) { return(m_pnRootParameterIndices[nIndex]); }

	UINT GetTextureType() { return(m_nTextureType); }
	UINT GetTextureType(int nIndex) { return(m_pnResourceTypes[nIndex]); }
	DXGI_FORMAT GetBufferFormat(int nIndex) { return(m_pdxgiBufferFormats[nIndex]); }
	int GetBufferElements(int nIndex) { return(m_pnBufferElements[nIndex]); }

	D3D12_SHADER_RESOURCE_VIEW_DESC GetShaderResourceViewDesc(int nIndex);

	void ReleaseUploadBuffers();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#define MATERIAL_ALBEDO_MAP			0x01
#define MATERIAL_SPECULAR_MAP		0x02
#define MATERIAL_NORMAL_MAP			0x04
#define MATERIAL_METALLIC_MAP		0x08
#define MATERIAL_EMISSION_MAP		0x10
#define MATERIAL_DETAIL_ALBEDO_MAP	0x20
#define MATERIAL_DETAIL_NORMAL_MAP	0x40

class CGameObject;

class CMaterial
{
public:
	CMaterial(int nTextures);
	CMaterial() {}
	virtual ~CMaterial();

private:
	int								m_nReferences = 0;

public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }

public:
	CShader							*m_pShader = NULL;

	XMFLOAT4						m_xmf4AlbedoColor = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	XMFLOAT4						m_xmf4EmissiveColor = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	XMFLOAT4						m_xmf4SpecularColor = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	XMFLOAT4						m_xmf4AmbientColor = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);

	void SetShader(CShader *pShader);
	void SetMaterialType(UINT nType) { m_nType |= nType; }
	void SetTexture(CTexture *pTexture, UINT nTexture = 0);
	void SetSpecTex(CTexture* tex);
	void SetNormalTex(CTexture* tex);

	virtual void UpdateShaderVariable(ID3D12GraphicsCommandList *pd3dCommandList);

	virtual void ReleaseUploadBuffers();

public:
	UINT							m_nType = 0x00;

	float							m_fGlossiness = 0.0f;
	float							m_fSmoothness = 0.0f;
	float							m_fSpecularHighlight = 0.0f;
	float							m_fMetallic = 0.0f;
	float							m_fGlossyReflection = 0.0f;

public:
	int 							m_nTextures = 0;
	_TCHAR							(*m_ppstrTextureNames)[64] = NULL;
	CTexture						**m_ppTextures = NULL; //0:Albedo, 1:Specular, 2:Metallic, 3:Normal, 4:Emission, 5:DetailAlbedo, 6:DetailNormal

	CTexture* normalTex = NULL;
	CTexture* specTex = NULL;

	void LoadTextureFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, UINT nType, UINT nRootParameter, _TCHAR *pwstrTextureName, CTexture **ppTexture, CGameObject *pParent, FILE *pInFile, CShader *pShader);

public:
	static CShader					*m_pWireFrameShader;
	static CShader					*m_pSkinnedAnimationWireFrameShader;

	static void CMaterial::PrepareShaders(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature);

	void SetWireFrameShader() 
	{ 
		CMaterial::SetShader(m_pWireFrameShader); 
		SetShader(CMaterial::m_pWireFrameShader);
	}
	void SetSkinnedAnimationWireFrameShader()
	{ 
		CMaterial::SetShader(m_pSkinnedAnimationWireFrameShader);
		SetShader(CMaterial::m_pSkinnedAnimationWireFrameShader);
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
struct CALLBACKKEY
{
   float  							m_fTime = 0.0f;
   void  							*m_pCallbackData = NULL;
};

#define _WITH_ANIMATION_INTERPOLATION

class CAnimationCallbackHandler
{
public:
	CAnimationCallbackHandler() { }
	~CAnimationCallbackHandler() { }

public:
   virtual void HandleCallback(void *pCallbackData, float fTrackPosition) { }
};

class CAnimationCurve
{
public:
	CAnimationCurve(int nKeys);
	~CAnimationCurve();

public:
	int								m_nKeys = 0;

	float							*m_pfKeyTimes = NULL;
	float							*m_pfKeyValues = NULL;

public:
	float GetValueByLinearInterpolation(float fPosition);
};

class CAnimationLayer
{
public:
	CAnimationLayer();
	~CAnimationLayer();

public:
	float							m_fWeight = 1.0f;

	int								m_nAnimatedBoneFrames = 0; 
	CGameObject						**m_ppAnimatedBoneFrameCaches = NULL; //[m_nAnimatedBoneFrames]

	CAnimationCurve					*(*m_ppAnimationCurves)[9] = NULL;

public:
	void LoadAnimationKeyValues(int nBoneFrame, int nCurve, FILE *pInFile);

	XMFLOAT4X4 GetSRT(int nBoneFrame, float fPosition, float fTrackWeight);
};

class CAnimationSet
{
public:
	CAnimationSet(float fStartTime, float fEndTime, char *pstrName);
	~CAnimationSet();

public:
	char							m_pstrAnimationSetName[64];

	int								m_nAnimationLayers = 0;
	CAnimationLayer					*m_pAnimationLayers = NULL;

	float							m_fStartTime = 0.0f;
	float							m_fEndTime = 0.0f;
	float							m_fLength = 0.0f;

	float 							m_fPosition = 0.0f;
    int 							m_nType = ANIMATION_TYPE_LOOP; //Once, Loop, PingPong

	int 							m_nCallbackKeys = 0;
	CALLBACKKEY 					*m_pCallbackKeys = NULL;

	CAnimationCallbackHandler 		*m_pAnimationCallbackHandler = NULL;

public:
	float SetPosition(float fElapsedTime, float fStartTime, float fEndTime);

	void Animate(float fTrackPosition, float fTrackWeight, float fStartTime, float fEndTime);

	void SetCallbackKeys(int nCallbackKeys);
	void SetCallbackKey(int nKeyIndex, float fTime, void *pData);
	void SetAnimationCallbackHandler(CAnimationCallbackHandler *pCallbackHandler);

	void *GetCallbackData();
	void HandleCallback();
};

class CAnimationSets
{
private:
	int								m_nReferences = 0;

public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }

public:
	CAnimationSets(int nAnimationSets);
	~CAnimationSets();

public:
	int								m_nAnimationSets = 0;
	CAnimationSet					**m_ppAnimationSets = NULL;

public:
	void SetCallbackKeys(int nAnimationSet, int nCallbackKeys);
	void SetCallbackKey(int nAnimationSet, int nKeyIndex, float fTime, void *pData);
	void SetAnimationCallbackHandler(int nAnimationSet, CAnimationCallbackHandler *pCallbackHandler);
};

class CAnimationTrack
{
public:
	CAnimationTrack() { }
	~CAnimationTrack() { }

public:
    BOOL 							m_bEnable = true;
    float 							m_fSpeed = 1.0f;
    float 							m_fPosition = 0.0f;
    float 							m_fWeight = 1.0f;

	int 							m_nAnimationSet = 0;

	float							m_fStartTime = 0.0f;
	float							m_fEndTime = 0.0f;
	float							m_fLength = 0.0f;

public:
	void SetAnimationSet(int nAnimationSet) { m_nAnimationSet = nAnimationSet; }

	void SetEnable(bool bEnable) { m_bEnable = bEnable; }
	void SetSpeed(float fSpeed) { m_fSpeed = fSpeed; }
	void SetWeight(float fWeight) { m_fWeight = fWeight; }
	void SetPosition(float fPosition) { m_fPosition = fPosition; }

	void SetStartEndTime(float fTrackStartTime, float fTrackEndTime) { m_fStartTime = fTrackStartTime; m_fEndTime = fTrackEndTime; m_fLength = m_fEndTime - m_fStartTime; }
};

class CLoadedModelInfo
{
public:
	CLoadedModelInfo() { }
	~CLoadedModelInfo();

public:
    CGameObject						*m_pModelRootObject = NULL;

	CAnimationSets					*m_pAnimationSets = NULL;

	int 							m_nSkinnedMeshes = 0;
	CSkinnedMesh					**m_ppSkinnedMeshes = NULL; //[SkinnedMeshes], Skinned Mesh Cache

public:
	void PrepareSkinning();
};

class CAnimationController 
{
public:
	CAnimationController(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, int nAnimationTracks, CLoadedModelInfo *pModel, bool m_bApplyRootMotion = false);
	~CAnimationController();

public:
    float 							m_fTime = 0.0f;
	bool							m_bApplyRootMotion = false;

    int 							m_nAnimationTracks = 0;
    CAnimationTrack 				*m_pAnimationTracks = NULL;

	CAnimationSets					*m_pAnimationSets = NULL;

	int 							m_nSkinnedMeshes = 0;
	CSkinnedMesh					**m_ppSkinnedMeshes = NULL; //[SkinnedMeshes], Skinned Mesh Cache

	ID3D12Resource					**m_ppd3dcbSkinningBoneTransforms = NULL; //[SkinnedMeshes]
	XMFLOAT4X4						**m_ppcbxmf4x4MappedSkinningBoneTransforms = NULL;

public:
	void UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList);

	void SetAnimationSets(CAnimationSets *pAnimationSets);

	void SetTrackAnimationSet(int nAnimationTrack, int nAnimationSet);
	void SetTrackEnable(int nAnimationTrack, bool bEnable);
	void SetTrackPosition(int nAnimationTrack, float fPosition);
	void SetTrackSpeed(int nAnimationTrack, float fSpeed);
	void SetTrackWeight(int nAnimationTrack, float fWeight);
	void SetTrackStartEndTime(int nAnimationTrack, float fStartTime, float fEndTime);

	void SetCallbackKeys(int nAnimationSet, int nCallbackKeys);
	void SetCallbackKey(int nAnimationSet, int nKeyIndex, float fTime, void *pData);
	void SetAnimationCallbackHandler(int nAnimationSet, CAnimationCallbackHandler *pCallbackHandler);

	void AdvanceTime(float fElapsedTime, CGameObject *pRootGameObject);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CGameObject
{
private:
	int								m_nReferences = 0;
	int matID = 0;
	bool dynamic = false;
public:
	void AddRef();
	void Release();

public:
	CGameObject();
	CGameObject(int nMaterials);
	CGameObject(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* pd3dGraphicsRootSignature, CLoadedModelInfo* pModel, int nAnimationTracks);
    virtual ~CGameObject();

public:
	int type = 0;
	int broke = 4;
	bool							m_bActive = true;

	char							m_pstrFrameName[64];

	CMesh							*m_pMesh = NULL;

	int								m_nMaterials = 0;
	CMaterial						**m_ppMaterials = NULL;

	XMFLOAT4X4						m_xmf4x4ToParent;
	XMFLOAT4X4						m_xmf4x4World;

	XMFLOAT3						m_xmf3Scale;
	XMFLOAT3						m_xmf3Rotation;
	XMFLOAT3						m_xmf3Translation;

	CGameObject 					*m_pParent = NULL;
	CGameObject 					*m_pChild = NULL;
	CGameObject 					*m_pSibling = NULL;

	void SetMesh(CMesh *pMesh);
	void SetShader(CShader *pShader);
	void SetShader(int nMaterial, CShader *pShader);
	void SetWireFrameShader();
	void SetSkinnedAnimationWireFrameShader();
	void SetMaterial(int nMaterial, CMaterial *pMaterial);

	void SetChild(CGameObject *pChild, bool bReferenceUpdate=false);
	void setRoot(CGameObject* root, bool update = false);
	virtual void BuildMaterials(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList) { }

	virtual void OnPrepareAnimate() { }
	virtual void Animate(float fTimeElapsed);

	virtual void OnPrepareRender() { }
	virtual void Render(ID3D12GraphicsCommandList *pd3dCommandList, CCamera *pCamera=NULL);

	virtual void CreateShaderVariables(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList);
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList);
	virtual void ReleaseShaderVariables();

	virtual void UpdateShaderVariable(ID3D12GraphicsCommandList *pd3dCommandList, XMFLOAT4X4 *pxmf4x4World);
	virtual void UpdateShaderVariable(ID3D12GraphicsCommandList *pd3dCommandList, CMaterial *pMaterial);

	virtual void ReleaseUploadBuffers();

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetLook();
	XMFLOAT3 GetUp();
	XMFLOAT3 GetRight();

	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3 xmf3Position);
	void SetScale(float x, float y, float z);

	void MoveStrafe(float fDistance = 1.0f);
	void MoveUp(float fDistance = 1.0f);
	void MoveForward(float fDistance = 1.0f);

	void Rotate(float fPitch = 10.0f, float fYaw = 10.0f, float fRoll = 10.0f);
	void Rotate(XMFLOAT3 *pxmf3Axis, float fAngle);
	void Rotate(XMFLOAT4 *pxmf4Quaternion);

	CGameObject *GetParent() { return(m_pParent); }
	void UpdateTransform(XMFLOAT4X4 *pxmf4x4Parent=NULL);

	CGameObject *FindFrame(char *pstrFrameName);
	void SetActive(char *pstrFrameName, bool bActive);

	UINT GetMeshType() { return((m_pMesh) ? m_pMesh->GetType() : 0x00); }

public:
	CAnimationController 			*m_pSkinnedAnimationController = NULL;

	CSkinnedMesh *FindSkinnedMesh(char *pstrSkinnedMeshName);
	void FindAndSetSkinnedMesh(CSkinnedMesh **ppSkinnedMeshes, int *pnSkinnedMesh);

	void SetTrackAnimationSet(int nAnimationTrack, int nAnimationSet);
	void SetTrackAnimationPosition(int nAnimationTrack, float fPosition);

	static void LoadAnimationFromFile(FILE *pInFile, CLoadedModelInfo *pLoadedModel);
	static CGameObject *LoadFrameHierarchyFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, CGameObject *pParent, FILE *pInFile, CShader *pShader, int *pnSkinnedMeshes);

	static CLoadedModelInfo *LoadGeometryAndAnimationFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, char *pstrFileName, CShader *pShader);

	static void PrintFrameInfo(CGameObject *pGameObject, CGameObject *pParent);
	chrono::time_point<chrono::system_clock> timeCreated;


	float shadowHeight;
	float shadowX = 0.0f;
	float shadowZ = 0.0f;


};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class PlayerObject : public CGameObject
{
public:
	PlayerObject(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, CLoadedModelInfo *pModel, int nAnimationTracks);
	virtual ~PlayerObject();

	PlayerInfoManager* info = NULL;
	BionicState bState;
	KineticState kState;
	int maxHP;
	XMFLOAT3 currentRotation;
	int objType;
	PlayerState pState;
	
	bool stateChanged = false;

	bool attack = false;

	char key = 0;

	chrono::time_point<chrono::system_clock> lastMove;
	bool lastMoveSuccess;

	bool hammerHit = false;

	bool isInAir = false;

	chrono::time_point<chrono::system_clock> lastAttack = chrono::system_clock::now();
	chrono::time_point<chrono::system_clock> lastWave = chrono::system_clock::now();
	chrono::time_point<chrono::system_clock> timeFromDie;

	chrono::time_point<chrono::system_clock> lastDamaged;
	bool isDead = false;

	int comboCount = 0;

	bool readyToGo = false;
	float amp_melee = 1.0f;
	float amp_ranged = 1.0f;
	float amp_radio = 1.0f;

public:
	void jump() { if (kState.yspeed == 0.0f) { kState.yspeed = 15.0f; kState.isInAir = 1; bState.stateID = JUMP_STATE; } }



};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class EnemyObject : public CGameObject
{
public:
	EnemyObject(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, CLoadedModelInfo *pModel, int nAnimationTracks, float** height, float, float);
	virtual ~EnemyObject();
	XMFLOAT3 origin;
	float** heightmap;
	float areaX, areaZ;
	BionicState bState;
	KineticState kState;
	int maxHP;
	chrono::time_point<chrono::system_clock> deathMoment;
	chrono::time_point<chrono::system_clock> lastSearch = chrono::system_clock::now();
	chrono::time_point<chrono::system_clock> lastMove=chrono::system_clock::now();

	bool isDead = false;
	bool expGiven = false;
	//chrono::time_point<chrono::system_clock> lastMove;
	
	int weapon;
	BoundBox* mbox;

public:
	std::vector<XMFLOAT2> NavigateMovement(float x, float z);
	void moveByRoute(vector<XMFLOAT2> route, vector<EnemyObject*>);
	

public:
	//AI ?????? ?????? ??????
	std::vector<XMFLOAT2> route;
	std::vector<XMFLOAT2> seekPoint;
	int currentPoint = 0;
	int routeIdx=0;


	// ?????? ???? ????
	int hitPlayerID = -1;
	XMFLOAT3 chaseTargetPos;
	int chaseTarget = -1;
	float attackRange;
	int attackTarget = -1;

	chrono::time_point<chrono::system_clock> lastAttack;
	float attackDuration;

	//?????? ???? ????
	bool stunned = false;
	bool erased = false;
	chrono::time_point<chrono::system_clock> lastStun;
	float stunDuration=0.0f;
};

class ParticleObject : public CGameObject
{
public:
	ParticleObject(int n);
	virtual ~ParticleObject();
	float speed = 0.0f;
	float yspeed = 0.0f;
	XMFLOAT3 direction = XMFLOAT3(0.0f, 0.0f, 0.0f);

	int type;
};

class BoomObject : public CGameObject
{
public:
	BoomObject(int n, XMFLOAT3, XMFLOAT3 dir, float spd, chrono::time_point<chrono::system_clock>);
	virtual ~BoomObject();
	float speed = 0.0f;
	XMFLOAT3 direction = XMFLOAT3(0.0f, 0.0f, 0.0f);
	XMFLOAT3 origin = XMFLOAT3(0.0f, 0.0f, 0.0f);
	chrono::time_point<chrono::system_clock> created;
	chrono::time_point<chrono::system_clock> lastMove;

	int owner;
};

class UIObject : public CGameObject
{
public:
	UIObject(int n, int,int,int,int, int);
	virtual ~UIObject();
	
	bool mouseOn = false;
	bool meshChanged = true;
	int x1;
	int y1; 
	int x2; 
	int y2;
	int defaultMesh;

};