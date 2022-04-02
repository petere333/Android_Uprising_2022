#pragma once

#include "stdafx.h"

#define ASPECT_RATIO (float(FRAME_BUFFER_WIDTH) / float(FRAME_BUFFER_HEIGHT))

struct VS_CB_CAMERA_INFO
{
	XMFLOAT4X4 m_xmf4x4View;
	XMFLOAT4X4 m_xmf4x4Projection;
	XMFLOAT3 m_xmf3Position;
};

class CCamera
{
protected:
	//카메라 변환 행렬
	XMFLOAT4X4 m_xmf4x4View;
	//투영 변환 행렬
	XMFLOAT4X4 m_xmf4x4Projection;
	//뷰포트와 씨저 사각형
	D3D12_VIEWPORT m_d3dViewport;
	D3D12_RECT m_d3dScissorRect;

	ID3D12Resource* m_pd3dcbCamera = NULL;
	VS_CB_CAMERA_INFO* m_pcbMappedCamera = NULL;
private:
	float x, y, z;
	XMFLOAT3 m_xmf3Position;
	float lx, ly, lz;
public:
	CCamera();
	virtual ~CCamera();
	virtual void CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
		* pd3dCommandList);
	virtual void ReleaseShaderVariables();
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	void GenerateViewMatrix();
	void GenerateProjectionMatrix(float fNearPlaneDistance, float fFarPlaneDistance, float
		fAspectRatio, float fFOVAngle);
	void SetViewport(int xTopLeft, int yTopLeft, int nWidth, int nHeight, float fMinZ =
		0.0f, float fMaxZ = 1.0f);
	void SetScissorRect(LONG xLeft, LONG yTop, LONG xRight, LONG yBottom);
	virtual void SetViewportsAndScissorRects(ID3D12GraphicsCommandList* pd3dCommandList);
	void move(float, float, float);
};
