#pragma once

#include "stdafx.h"

class CGameObject
{
private:
	int								m_nReferences = 0;
	int matID = 0;
public:
	void AddRef();
	void Release();

public:
	CGameObject();
	virtual ~CGameObject();

public:
	int type = 0;

	bool							m_bActive = true;

	char							m_pstrFrameName[64];

	int								m_nMaterials = 0;

	XMFLOAT4X4						m_xmf4x4ToParent;
	XMFLOAT4X4						m_xmf4x4World;

	XMFLOAT3						m_xmf3Scale;
	XMFLOAT3						m_xmf3Rotation;
	XMFLOAT3						m_xmf3Translation;

	CGameObject* m_pParent = NULL;
	CGameObject* m_pChild = NULL;
	CGameObject* m_pSibling = NULL;

	void SetChild(CGameObject* pChild, bool bReferenceUpdate = false);
	void setRoot(CGameObject* root, bool update = false);
	
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
	void Rotate(XMFLOAT3* pxmf3Axis, float fAngle);
	void Rotate(XMFLOAT4* pxmf4Quaternion);

	CGameObject* GetParent() { return(m_pParent); }
	void UpdateTransform(XMFLOAT4X4* pxmf4x4Parent = NULL);

	CGameObject* FindFrame(char* pstrFrameName);
	void SetActive(char* pstrFrameName, bool bActive);


public:

	void SetTrackAnimationSet(int nAnimationTrack, int nAnimationSet);
	void SetTrackAnimationPosition(int nAnimationTrack, float fPosition);

public:

	XMFLOAT3 currentRotation;
	int objType;
	/*PlayerState pState;
	EnemyState eState;*/
	float speed = 0.0f;
	float yspeed = 0.0f;
	XMFLOAT3 direction = XMFLOAT3(0.0f, 0.0f, 0.0f);


	chrono::time_point<chrono::system_clock> lastMove;
	bool lastMoveSuccess;

	bool hammerHit = false;

	bool isInAir = false;

	chrono::time_point<chrono::system_clock> lastAttack = chrono::system_clock::now();
	chrono::time_point<chrono::system_clock> timeCreated;
	chrono::time_point<chrono::system_clock> timeFromDie;
	bool isDead = false;

public:
	void jump() { if (yspeed == 0.0f) { yspeed = 15.0f; isInAir = true; } }


};