#include "stdafx.h"
#include "Camera.h"

CCamera::CCamera()
{
	m_xmf4x4View = Matrix4x4::Identity();
	m_xmf4x4Projection = Matrix4x4::Identity();
	m_d3dViewport = { 0, 0, FRAME_BUFFER_WIDTH , FRAME_BUFFER_HEIGHT, 0.0f, 1.0f };
	m_d3dScissorRect = { 0, 0, FRAME_BUFFER_WIDTH , FRAME_BUFFER_HEIGHT };
	//m_xmf3Position = XMFLOAT3(3.0f, 2.85f, 1.0f);
	m_xmf3Position = XMFLOAT3(100.0f, 2.85f, 98.0f);


	lookVec = XMFLOAT3(0.0f, -2.0f, 2.0f);


	dist = 2.0f;
	rightVec = XMFLOAT3(1.0f, 0.0f, 0.0f);
	lx = 100.0f;
	ly = 0.85f;
	lz = 100.0f;

	angle = 270.0f;
}
CCamera::~CCamera()
{}
void CCamera::SetViewport(int xTopLeft, int yTopLeft, int nWidth, int nHeight, float
	fMinZ, float fMaxZ)
{
	m_d3dViewport.TopLeftX = float(xTopLeft);
	m_d3dViewport.TopLeftY = float(yTopLeft);
	m_d3dViewport.Width = float(nWidth);
	m_d3dViewport.Height = float(nHeight);
	m_d3dViewport.MinDepth = fMinZ;
	m_d3dViewport.MaxDepth = fMaxZ;
}
void CCamera::SetScissorRect(LONG xLeft, LONG yTop, LONG xRight, LONG yBottom)
{
	m_d3dScissorRect.left = xLeft;
	m_d3dScissorRect.top = yTop;
	m_d3dScissorRect.right = xRight;
	m_d3dScissorRect.bottom = yBottom;
}
void CCamera::GenerateProjectionMatrix(float fNearPlaneDistance, float fFarPlaneDistance,
	float fAspectRatio, float fFOVAngle)
{
	m_xmf4x4Projection = Matrix4x4::PerspectiveFovLH(XMConvertToRadians(fFOVAngle),
		fAspectRatio, fNearPlaneDistance, fFarPlaneDistance);
}
void CCamera::GenerateViewMatrix()
{
	m_xmf4x4View = Matrix4x4::LookAtLH(m_xmf3Position, XMFLOAT3(lx, ly, lz), XMFLOAT3(0.0f, 1.0f, 0.0f));
}
void CCamera::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(VS_CB_CAMERA_INFO) + 255) & ~255); //256?? ????
	m_pd3dcbCamera = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
	m_pd3dcbCamera->Map(0, NULL, (void**)&m_pcbMappedCamera);
}
void CCamera::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	XMStoreFloat4x4(&m_pcbMappedCamera->m_xmf4x4View, XMMatrixTranspose(XMLoadFloat4x4(&m_xmf4x4View)));
	XMStoreFloat4x4(&m_pcbMappedCamera->m_xmf4x4Projection, XMMatrixTranspose(XMLoadFloat4x4(&m_xmf4x4Projection)));
	::memcpy(&m_pcbMappedCamera->m_xmf3Position, &m_xmf3Position, sizeof(XMFLOAT3));

	D3D12_GPU_VIRTUAL_ADDRESS d3dGpuVirtualAddress = m_pd3dcbCamera->GetGPUVirtualAddress();
	pd3dCommandList->SetGraphicsRootConstantBufferView(0, d3dGpuVirtualAddress);
}
void CCamera::ReleaseShaderVariables()
{
	if (m_pd3dcbCamera)
	{
		m_pd3dcbCamera->Unmap(0, NULL);
		m_pd3dcbCamera->Release();
	}
}
void CCamera::SetViewportsAndScissorRects(ID3D12GraphicsCommandList* pd3dCommandList)
{
	pd3dCommandList->RSSetViewports(1, &m_d3dViewport);
	pd3dCommandList->RSSetScissorRects(1, &m_d3dScissorRect);
}

void CCamera::move(float mx, float my, float mz)
{
	float rad = XMConvertToRadians(angle);

	m_xmf3Position.x = mx + static_cast<float>(cos(rad)) * dist;
	m_xmf3Position.y = my+2.0f;
	m_xmf3Position.z = mz + static_cast<float>(sin(rad)) * dist;

	

	
	lx = mx;
	ly = m_xmf3Position.y;
	lz = mz;
	rotateUp();
	GenerateViewMatrix();
}
void CCamera::moveRelative(float mx, float my, float mz)
{
	m_xmf3Position.x += mx;
	m_xmf3Position.y += my;
	m_xmf3Position.z += mz;

	lx += mx;
	ly += my;
	lz += mz;
	GenerateViewMatrix();
}

void CCamera::rotate(float originX, float originZ)
{
	float rad = XMConvertToRadians(angle);
	m_xmf3Position.x = static_cast<float>(cos(rad)) * dist+originX;
	m_xmf3Position.z = static_cast<float>(sin(rad)) * dist+originZ;
	
}

XMFLOAT3 CCamera::getLook() 
{ 
	XMFLOAT3 look = XMFLOAT3(lx - m_xmf3Position.x, ly - m_xmf3Position.y, lz - m_xmf3Position.z); 
	look = Vector3::Normalize(look);
	return look; 
}

XMFLOAT3 CCamera::getRight()
{
	XMFLOAT3 look = getLook();

	XMFLOAT3 right = XMFLOAT3(look.y, -look.x, -look.z);
	return right;
}
XMFLOAT3 CCamera::getUp()
{
	XMFLOAT3 look = getLook();
	XMFLOAT3 right = getRight();
	XMFLOAT3 up = Vector3::CrossProduct(look, right);
	up = Vector3::Normalize(up);

	return up;
}