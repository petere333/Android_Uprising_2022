//-----------------------------------------------------------------------------
// File: CGameObject.cpp
//-----------------------------------------------------------------------------
#pragma once

#include "stdafx.h"

#include "Object.h"
#include "Shader.h"
#include "Scene.h"

CWireFrameShader* wireShader;
CSkinnedAnimationWireFrameShader* skinShader;

void initShader(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* pd3dGraphicsRootSignature)
{
	wireShader = new CWireFrameShader();
	wireShader->CreateShader(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature);
	wireShader->CreateShaderVariables(pd3dDevice, pd3dCommandList);

	skinShader = new CSkinnedAnimationWireFrameShader();
	skinShader->CreateShader(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature);
	skinShader->CreateShaderVariables(pd3dDevice, pd3dCommandList);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CTexture::CTexture(int nTextures, UINT nTextureType, int nSamplers, int nRootParameters)
{
	m_nTextureType = nTextureType;

	m_nTextures = nTextures;
	if (m_nTextures > 0)
	{
		m_ppd3dTextureUploadBuffers = new ID3D12Resource * [m_nTextures];
		m_ppd3dTextures = new ID3D12Resource * [m_nTextures];
		for (int i = 0; i < m_nTextures; i++) m_ppd3dTextureUploadBuffers[i] = m_ppd3dTextures[i] = NULL;

		m_ppstrTextureNames = new _TCHAR[m_nTextures][64];
		for (int i = 0; i < m_nTextures; i++) m_ppstrTextureNames[i][0] = '\0';

		m_pd3dSrvGpuDescriptorHandles = new D3D12_GPU_DESCRIPTOR_HANDLE[m_nTextures];
		for (int i = 0; i < m_nTextures; i++) m_pd3dSrvGpuDescriptorHandles[i].ptr = NULL;

		m_pnResourceTypes = new UINT[m_nTextures];
		m_pdxgiBufferFormats = new DXGI_FORMAT[m_nTextures];
		m_pnBufferElements = new int[m_nTextures];
	}
	m_nRootParameters = nRootParameters;
	if (nRootParameters > 0) m_pnRootParameterIndices = new int[nRootParameters];
	for (int i = 0; i < m_nRootParameters; i++) m_pnRootParameterIndices[i] = -1;

	m_nSamplers = nSamplers;
	if (m_nSamplers > 0) m_pd3dSamplerGpuDescriptorHandles = new D3D12_GPU_DESCRIPTOR_HANDLE[m_nSamplers];
}

CTexture::~CTexture()
{
	if (m_ppd3dTextures)
	{
		for (int i = 0; i < m_nTextures; i++) if (m_ppd3dTextures[i]) m_ppd3dTextures[i]->Release();
		delete[] m_ppd3dTextures;
	}

	if (m_ppstrTextureNames) delete[] m_ppstrTextureNames;

	if (m_pnResourceTypes) delete[] m_pnResourceTypes;
	if (m_pdxgiBufferFormats) delete[] m_pdxgiBufferFormats;
	if (m_pnBufferElements) delete[] m_pnBufferElements;

	if (m_pnRootParameterIndices) delete[] m_pnRootParameterIndices;
	if (m_pd3dSrvGpuDescriptorHandles) delete[] m_pd3dSrvGpuDescriptorHandles;

	if (m_pd3dSamplerGpuDescriptorHandles) delete[] m_pd3dSamplerGpuDescriptorHandles;
}

void CTexture::SetRootParameterIndex(int nIndex, UINT nRootParameterIndex)
{
	m_pnRootParameterIndices[nIndex] = nRootParameterIndex;
}

void CTexture::SetGpuDescriptorHandle(int nIndex, D3D12_GPU_DESCRIPTOR_HANDLE d3dSrvGpuDescriptorHandle)
{
	m_pd3dSrvGpuDescriptorHandles[nIndex] = d3dSrvGpuDescriptorHandle;
}

void CTexture::SetSampler(int nIndex, D3D12_GPU_DESCRIPTOR_HANDLE d3dSamplerGpuDescriptorHandle)
{
	m_pd3dSamplerGpuDescriptorHandles[nIndex] = d3dSamplerGpuDescriptorHandle;
}

void CTexture::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	if (m_nRootParameters == m_nTextures)
	{
		for (int i = 0; i < m_nRootParameters; i++)
		{
			if (m_pd3dSrvGpuDescriptorHandles[i].ptr && (m_pnRootParameterIndices[i] != -1)) pd3dCommandList->SetGraphicsRootDescriptorTable(m_pnRootParameterIndices[i], m_pd3dSrvGpuDescriptorHandles[i]);
		}
	}
	else
	{
		if (m_pd3dSrvGpuDescriptorHandles[0].ptr) pd3dCommandList->SetGraphicsRootDescriptorTable(m_pnRootParameterIndices[0], m_pd3dSrvGpuDescriptorHandles[0]);
	}
}

void CTexture::UpdateShaderVariable(ID3D12GraphicsCommandList* pd3dCommandList, int nParameterIndex, int nTextureIndex)
{
	pd3dCommandList->SetGraphicsRootDescriptorTable(m_pnRootParameterIndices[nParameterIndex], m_pd3dSrvGpuDescriptorHandles[nTextureIndex]);
}

void CTexture::ReleaseShaderVariables()
{
}

void CTexture::ReleaseUploadBuffers()
{
	if (m_ppd3dTextureUploadBuffers)
	{
		for (int i = 0; i < m_nTextures; i++) if (m_ppd3dTextureUploadBuffers[i]) m_ppd3dTextureUploadBuffers[i]->Release();
		delete[] m_ppd3dTextureUploadBuffers;
		m_ppd3dTextureUploadBuffers = NULL;
	}
}

void CTexture::LoadTextureFromDDSFile(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, wchar_t* pszFileName, UINT nResourceType, UINT nIndex)
{
	m_pnResourceTypes[nIndex] = nResourceType;
	m_ppd3dTextures[nIndex] = ::CreateTextureResourceFromDDSFile(pd3dDevice, pd3dCommandList, pszFileName, &m_ppd3dTextureUploadBuffers[nIndex], D3D12_RESOURCE_STATE_GENERIC_READ/*D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE*/);
}

D3D12_SHADER_RESOURCE_VIEW_DESC CTexture::GetShaderResourceViewDesc(int nIndex)
{
	ID3D12Resource* pShaderResource = GetResource(nIndex);
	D3D12_RESOURCE_DESC d3dResourceDesc = pShaderResource->GetDesc();

	D3D12_SHADER_RESOURCE_VIEW_DESC d3dShaderResourceViewDesc;
	d3dShaderResourceViewDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;

	int nTextureType = GetTextureType(nIndex);
	switch (nTextureType)
	{
	case RESOURCE_TEXTURE2D: //(d3dResourceDesc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D)(d3dResourceDesc.DepthOrArraySize == 1)
	case RESOURCE_TEXTURE2D_ARRAY: //[]
		d3dShaderResourceViewDesc.Format = d3dResourceDesc.Format;
		d3dShaderResourceViewDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
		d3dShaderResourceViewDesc.Texture2D.MipLevels = -1;
		d3dShaderResourceViewDesc.Texture2D.MostDetailedMip = 0;
		d3dShaderResourceViewDesc.Texture2D.PlaneSlice = 0;
		d3dShaderResourceViewDesc.Texture2D.ResourceMinLODClamp = 0.0f;
		break;
	case RESOURCE_TEXTURE2DARRAY: //(d3dResourceDesc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D)(d3dResourceDesc.DepthOrArraySize != 1)
		d3dShaderResourceViewDesc.Format = d3dResourceDesc.Format;
		d3dShaderResourceViewDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2DARRAY;
		d3dShaderResourceViewDesc.Texture2DArray.MipLevels = -1;
		d3dShaderResourceViewDesc.Texture2DArray.MostDetailedMip = 0;
		d3dShaderResourceViewDesc.Texture2DArray.PlaneSlice = 0;
		d3dShaderResourceViewDesc.Texture2DArray.ResourceMinLODClamp = 0.0f;
		d3dShaderResourceViewDesc.Texture2DArray.FirstArraySlice = 0;
		d3dShaderResourceViewDesc.Texture2DArray.ArraySize = d3dResourceDesc.DepthOrArraySize;
		break;
	case RESOURCE_TEXTURE_CUBE: //(d3dResourceDesc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D)(d3dResourceDesc.DepthOrArraySize == 6)
		d3dShaderResourceViewDesc.Format = d3dResourceDesc.Format;
		d3dShaderResourceViewDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURECUBE;
		d3dShaderResourceViewDesc.TextureCube.MipLevels = 1;
		d3dShaderResourceViewDesc.TextureCube.MostDetailedMip = 0;
		d3dShaderResourceViewDesc.TextureCube.ResourceMinLODClamp = 0.0f;
		break;
	case RESOURCE_BUFFER: //(d3dResourceDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
		d3dShaderResourceViewDesc.Format = m_pdxgiBufferFormats[nIndex];
		d3dShaderResourceViewDesc.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;
		d3dShaderResourceViewDesc.Buffer.FirstElement = 0;
		d3dShaderResourceViewDesc.Buffer.NumElements = m_pnBufferElements[nIndex];
		d3dShaderResourceViewDesc.Buffer.StructureByteStride = 0;
		d3dShaderResourceViewDesc.Buffer.Flags = D3D12_BUFFER_SRV_FLAG_NONE;
		break;
	}
	return(d3dShaderResourceViewDesc);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CMaterial::CMaterial(int nTextures)
{
	m_nTextures = nTextures;

	m_ppTextures = new CTexture*[m_nTextures];
	m_ppstrTextureNames = new _TCHAR[m_nTextures][64];
	for (int i = 0; i < m_nTextures; i++) m_ppTextures[i] = NULL;
	for (int i = 0; i < m_nTextures; i++) m_ppstrTextureNames[i][0] = '\0';
}

CMaterial::~CMaterial()
{
	if (m_pShader) m_pShader->Release();

	if (m_nTextures > 0)
	{
		for (int i = 0; i < m_nTextures; i++) if (m_ppTextures[i]) m_ppTextures[i]->Release();
		delete[] m_ppTextures;

		if (m_ppstrTextureNames) delete[] m_ppstrTextureNames;
	}
}

void CMaterial::SetShader(CShader *pShader)
{
	if (m_pShader) m_pShader->Release();
	m_pShader = pShader;
	if (m_pShader) m_pShader->AddRef();
}

void CMaterial::SetTexture(CTexture *pTexture, UINT nTexture) 
{ 
	if (m_ppTextures[nTexture]) m_ppTextures[nTexture]->Release();
	m_ppTextures[nTexture] = pTexture; 
	if (m_ppTextures[nTexture]) m_ppTextures[nTexture]->AddRef();  
}
void CMaterial::SetNormalTex(CTexture* pTexture)
{
	if (normalTex) normalTex->Release();
	normalTex = pTexture;
	if (normalTex) normalTex->AddRef();
}
void CMaterial::SetSpecTex(CTexture* tex)
{
	if (specTex) specTex->Release();
	specTex = tex;
	if (specTex) specTex->AddRef();
}
void CMaterial::ReleaseUploadBuffers()
{
	for (int i = 0; i < m_nTextures; i++)
	{
		if (m_ppTextures[i]) m_ppTextures[i]->ReleaseUploadBuffers();
	}
}

CShader *CMaterial::m_pWireFrameShader = NULL;
CShader *CMaterial::m_pSkinnedAnimationWireFrameShader = NULL;

void CMaterial::PrepareShaders(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature)
{
	m_pWireFrameShader = new CWireFrameShader();
	m_pWireFrameShader->CreateShader(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature);
	m_pWireFrameShader->CreateShaderVariables(pd3dDevice, pd3dCommandList);

	m_pSkinnedAnimationWireFrameShader = new CSkinnedAnimationWireFrameShader();
	m_pSkinnedAnimationWireFrameShader->CreateShader(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature);
	m_pSkinnedAnimationWireFrameShader->CreateShaderVariables(pd3dDevice, pd3dCommandList);
}

void CMaterial::UpdateShaderVariable(ID3D12GraphicsCommandList *pd3dCommandList)
{
	for (int i = 0; i < m_nTextures; i++)
	{
		if (m_ppTextures[i]) m_ppTextures[i]->UpdateShaderVariables(pd3dCommandList);
	}
	if (normalTex)
	{
		normalTex->UpdateShaderVariables(pd3dCommandList);
	}
	if (specTex)
	{
		specTex->UpdateShaderVariables(pd3dCommandList);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CAnimationCurve::CAnimationCurve(int nKeys)
{
	m_nKeys = nKeys;
	m_pfKeyTimes = new float[nKeys];
	m_pfKeyValues = new float[nKeys];
}

CAnimationCurve::~CAnimationCurve()
{
	if (m_pfKeyTimes) delete[] m_pfKeyTimes;
	if (m_pfKeyValues) delete[] m_pfKeyValues;
}

float CAnimationCurve::GetValueByLinearInterpolation(float fPosition)
{
	for (int k = 0; k < (m_nKeys - 1); k++)
	{
		if ((m_pfKeyTimes[k] <= fPosition) && (fPosition < m_pfKeyTimes[k+1]))
		{
			float t = (fPosition - m_pfKeyTimes[k]) / (m_pfKeyTimes[k+1] - m_pfKeyTimes[k]);
			return(m_pfKeyValues[k] * (1.0f - t) + m_pfKeyValues[k+1] * t);
		}
	}
	return(m_pfKeyValues[m_nKeys-1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CAnimationLayer::CAnimationLayer() 
{ 
}

CAnimationLayer::~CAnimationLayer()
{
	for (int i = 0; i < m_nAnimatedBoneFrames; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (m_ppAnimationCurves[i][j]) delete m_ppAnimationCurves[i][j];
		}
	}
	if (m_ppAnimationCurves) delete[] m_ppAnimationCurves;

	if (m_ppAnimatedBoneFrameCaches) delete[] m_ppAnimatedBoneFrameCaches;
}

void CAnimationLayer::LoadAnimationKeyValues(int nBoneFrame, int nCurve, FILE *pInFile)
{
	int nAnimationKeys = ::ReadIntegerFromFile(pInFile);

	m_ppAnimationCurves[nBoneFrame][nCurve] = new CAnimationCurve(nAnimationKeys);

	::fread(m_ppAnimationCurves[nBoneFrame][nCurve]->m_pfKeyTimes, sizeof(float), nAnimationKeys, pInFile);
	::fread(m_ppAnimationCurves[nBoneFrame][nCurve]->m_pfKeyValues, sizeof(float), nAnimationKeys, pInFile);
}

XMFLOAT4X4 CAnimationLayer::GetSRT(int nBoneFrame, float fPosition, float fTrackWeight) 
{ 
	CGameObject *pBoneFrame = m_ppAnimatedBoneFrameCaches[nBoneFrame];
	XMFLOAT3 xmf3S = pBoneFrame->m_xmf3Scale;
	XMFLOAT3 xmf3R = pBoneFrame->m_xmf3Rotation;
	XMFLOAT3 xmf3T = pBoneFrame->m_xmf3Translation;

	if (m_ppAnimationCurves[nBoneFrame][0]) xmf3T.x = m_ppAnimationCurves[nBoneFrame][0]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][1]) xmf3T.y = m_ppAnimationCurves[nBoneFrame][1]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][2]) xmf3T.z = m_ppAnimationCurves[nBoneFrame][2]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][3]) xmf3R.x = m_ppAnimationCurves[nBoneFrame][3]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][4]) xmf3R.y = m_ppAnimationCurves[nBoneFrame][4]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][5]) xmf3R.z = m_ppAnimationCurves[nBoneFrame][5]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][6]) xmf3S.x = m_ppAnimationCurves[nBoneFrame][6]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][7]) xmf3S.y = m_ppAnimationCurves[nBoneFrame][7]->GetValueByLinearInterpolation(fPosition);
	if (m_ppAnimationCurves[nBoneFrame][8]) xmf3S.z = m_ppAnimationCurves[nBoneFrame][8]->GetValueByLinearInterpolation(fPosition);

	float fWeight = m_fWeight * fTrackWeight;
	XMMATRIX S = XMMatrixScaling(xmf3S.x * fWeight, xmf3S.y * fWeight, xmf3S.z * fWeight);
//	XMMATRIX R = XMMatrixRotationRollPitchYaw(xmf3R.x * fWeight, xmf3R.y * fWeight, xmf3R.z * fWeight);
	XMMATRIX R = XMMatrixMultiply(XMMatrixMultiply(XMMatrixRotationX(xmf3R.x * fWeight), XMMatrixRotationY(xmf3R.y * fWeight)), XMMatrixRotationZ(xmf3R.z * fWeight));
	XMMATRIX T = XMMatrixTranslation(xmf3T.x * fWeight, xmf3T.y * fWeight, xmf3T.z * fWeight);

	XMFLOAT4X4 xmf4x4Transform;
	XMStoreFloat4x4(&xmf4x4Transform, XMMatrixMultiply(XMMatrixMultiply(S, R), T));

	return(xmf4x4Transform);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CAnimationSet::CAnimationSet(float fStartTime, float fEndTime, char *pstrName)
{
	m_fStartTime = fStartTime;
	m_fEndTime = fEndTime;
	m_fLength = fEndTime - fStartTime;

	strcpy_s(m_pstrAnimationSetName, 64, pstrName);
}

CAnimationSet::~CAnimationSet()
{
	if (m_pAnimationLayers) delete[] m_pAnimationLayers;

	if (m_pCallbackKeys) delete[] m_pCallbackKeys;
	if (m_pAnimationCallbackHandler) delete m_pAnimationCallbackHandler;
}

void CAnimationSet::HandleCallback()
{
	if (m_pAnimationCallbackHandler)
	{
		for (int i = 0; i < m_nCallbackKeys; i++)
		{
			if (::IsEqual(m_pCallbackKeys[i].m_fTime, m_fPosition, ANIMATION_CALLBACK_EPSILON))
			{
				if (m_pCallbackKeys[i].m_pCallbackData) m_pAnimationCallbackHandler->HandleCallback(m_pCallbackKeys[i].m_pCallbackData, m_fPosition);
				break;
			}
		}
	}
}

float CAnimationSet::SetPosition(float fElapsedTime, float fTrackStartTime, float fTrackEndTime)
{
	switch (m_nType)
	{
		case ANIMATION_TYPE_LOOP:
		{
			m_fPosition += fElapsedTime;
			if (m_fPosition < fTrackStartTime) m_fPosition = fTrackStartTime;
			if (m_fPosition >= fTrackEndTime) m_fPosition = fTrackStartTime;
//			m_fPosition = fmod(fTrackPosition, m_pfKeyFrameTimes[m_nKeyFrames-1]); // m_fPosition = fTrackPosition - int(fTrackPosition / m_pfKeyFrameTimes[m_nKeyFrames-1]) * m_pfKeyFrameTimes[m_nKeyFrames-1];
//			m_fPosition = fmod(fTrackPosition, m_fLength); //if (m_fPosition < 0) m_fPosition += m_fLength;
//			m_fPosition = fTrackPosition - int(fTrackPosition / m_fLength) * m_fLength;
			break;
		}
		case ANIMATION_TYPE_ONCE:
			break;
		case ANIMATION_TYPE_PINGPONG:
			break;
	}

	return(m_fPosition);
}

void CAnimationSet::Animate(float fElapsedTime, float fTrackWeight, float fTrackStartTime, float fTrackEndTime)
{
	float fPosition = SetPosition(fElapsedTime, fTrackStartTime, fTrackEndTime);

	for (int i = 0; i < m_nAnimationLayers; i++)
	{
		for (int j = 0; j < m_pAnimationLayers[i].m_nAnimatedBoneFrames; j++) 
		{
			m_pAnimationLayers[i].m_ppAnimatedBoneFrameCaches[j]->m_xmf4x4ToParent = m_pAnimationLayers[i].GetSRT(j, fPosition, fTrackWeight);
		}
	}
}

void CAnimationSet::SetCallbackKeys(int nCallbackKeys)
{
	m_nCallbackKeys = nCallbackKeys;
	m_pCallbackKeys = new CALLBACKKEY[nCallbackKeys];
}

void CAnimationSet::SetCallbackKey(int nKeyIndex, float fKeyTime, void *pData)
{
	m_pCallbackKeys[nKeyIndex].m_fTime = fKeyTime;
	m_pCallbackKeys[nKeyIndex].m_pCallbackData = pData;
}

void CAnimationSet::SetAnimationCallbackHandler(CAnimationCallbackHandler *pCallbackHandler)
{
	m_pAnimationCallbackHandler = pCallbackHandler;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CAnimationSets::CAnimationSets(int nAnimationSets)
{
	m_nAnimationSets = nAnimationSets;
	m_ppAnimationSets = new CAnimationSet*[nAnimationSets];
	for (int i = 0; i < m_nAnimationSets; i++) m_ppAnimationSets[i] = NULL;
}

CAnimationSets::~CAnimationSets()
{
	for (int i = 0; i < m_nAnimationSets; i++) if (m_ppAnimationSets[i]) delete m_ppAnimationSets[i];
	if (m_ppAnimationSets) delete[] m_ppAnimationSets;
}

void CAnimationSets::SetCallbackKeys(int nAnimationSet, int nCallbackKeys)
{
	m_ppAnimationSets[nAnimationSet]->m_nCallbackKeys = nCallbackKeys;
	m_ppAnimationSets[nAnimationSet]->m_pCallbackKeys = new CALLBACKKEY[nCallbackKeys];
}

void CAnimationSets::SetCallbackKey(int nAnimationSet, int nKeyIndex, float fKeyTime, void *pData)
{
	m_ppAnimationSets[nAnimationSet]->m_pCallbackKeys[nKeyIndex].m_fTime = fKeyTime;
	m_ppAnimationSets[nAnimationSet]->m_pCallbackKeys[nKeyIndex].m_pCallbackData = pData;
}

void CAnimationSets::SetAnimationCallbackHandler(int nAnimationSet, CAnimationCallbackHandler *pCallbackHandler)
{
	m_ppAnimationSets[nAnimationSet]->SetAnimationCallbackHandler(pCallbackHandler);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CAnimationController::CAnimationController(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, int nAnimationTracks, CLoadedModelInfo *pModel, bool bApplyRootMotion)
{
	m_nAnimationTracks = nAnimationTracks;
    m_pAnimationTracks = new CAnimationTrack[nAnimationTracks];

	m_bApplyRootMotion = bApplyRootMotion;

	SetAnimationSets(pModel->m_pAnimationSets);

	m_nSkinnedMeshes = pModel->m_nSkinnedMeshes;
	m_ppSkinnedMeshes = new CSkinnedMesh*[m_nSkinnedMeshes];
	for (int i = 0; i < m_nSkinnedMeshes; i++) m_ppSkinnedMeshes[i] = pModel->m_ppSkinnedMeshes[i];

	m_ppd3dcbSkinningBoneTransforms = new ID3D12Resource*[m_nSkinnedMeshes];
	m_ppcbxmf4x4MappedSkinningBoneTransforms = new XMFLOAT4X4*[m_nSkinnedMeshes];

	UINT ncbElementBytes = (((sizeof(XMFLOAT4X4) * SKINNED_ANIMATION_BONES) + 255) & ~255); //256의 배수
	for (int i = 0; i < m_nSkinnedMeshes; i++)
	{
		m_ppd3dcbSkinningBoneTransforms[i] = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
		m_ppd3dcbSkinningBoneTransforms[i]->Map(0, NULL, (void **)&m_ppcbxmf4x4MappedSkinningBoneTransforms[i]);
	}
}

CAnimationController::~CAnimationController()
{
	if (m_pAnimationTracks) delete[] m_pAnimationTracks;

	if (m_pAnimationSets) m_pAnimationSets->Release();

	for (int i = 0; i < m_nSkinnedMeshes; i++)
	{
		m_ppd3dcbSkinningBoneTransforms[i]->Unmap(0, NULL);
		m_ppd3dcbSkinningBoneTransforms[i]->Release();
	}
	if (m_ppd3dcbSkinningBoneTransforms) delete[] m_ppd3dcbSkinningBoneTransforms;
	if (m_ppcbxmf4x4MappedSkinningBoneTransforms) delete[] m_ppcbxmf4x4MappedSkinningBoneTransforms;

	if (m_ppSkinnedMeshes) delete[] m_ppSkinnedMeshes;
}

void CAnimationController::SetAnimationSets(CAnimationSets *pAnimationSets)
{
	if (m_pAnimationSets) m_pAnimationSets->Release();

	m_pAnimationSets = pAnimationSets;
	if (m_pAnimationSets) m_pAnimationSets->AddRef();
}

void CAnimationController::SetCallbackKeys(int nAnimationSet, int nCallbackKeys)
{
	if (m_pAnimationSets) m_pAnimationSets->SetCallbackKeys(nAnimationSet, nCallbackKeys);
}

void CAnimationController::SetCallbackKey(int nAnimationSet, int nKeyIndex, float fKeyTime, void *pData)
{
	if (m_pAnimationSets) m_pAnimationSets->SetCallbackKey(nAnimationSet, nKeyIndex, fKeyTime, pData);
}

void CAnimationController::SetAnimationCallbackHandler(int nAnimationSet, CAnimationCallbackHandler *pCallbackHandler)
{
	if (m_pAnimationSets) m_pAnimationSets->SetAnimationCallbackHandler(nAnimationSet, pCallbackHandler);
}

void CAnimationController::SetTrackAnimationSet(int nAnimationTrack, int nAnimationSet)
{
	if (m_pAnimationTracks)
	{
		m_pAnimationTracks[nAnimationTrack].SetAnimationSet(nAnimationSet);
		m_pAnimationTracks[nAnimationTrack].SetStartEndTime(m_pAnimationSets->m_ppAnimationSets[nAnimationSet]->m_fStartTime, m_pAnimationSets->m_ppAnimationSets[nAnimationSet]->m_fEndTime);
	}
}

void CAnimationController::SetTrackEnable(int nAnimationTrack, bool bEnable)
{
	if (m_pAnimationTracks) m_pAnimationTracks[nAnimationTrack].SetEnable(bEnable);
}

void CAnimationController::SetTrackPosition(int nAnimationTrack, float fPosition)
{
	if (m_pAnimationTracks) m_pAnimationTracks[nAnimationTrack].SetPosition(fPosition);
}

void CAnimationController::SetTrackSpeed(int nAnimationTrack, float fSpeed)
{
	if (m_pAnimationTracks) m_pAnimationTracks[nAnimationTrack].SetSpeed(fSpeed);
}

void CAnimationController::SetTrackWeight(int nAnimationTrack, float fWeight)
{
	if (m_pAnimationTracks) m_pAnimationTracks[nAnimationTrack].SetWeight(fWeight);
}

void CAnimationController::SetTrackStartEndTime(int nAnimationTrack, float fStartTime, float fEndTime)
{
	if (m_pAnimationTracks) m_pAnimationTracks[nAnimationTrack].SetStartEndTime(fStartTime, fEndTime);
}

void CAnimationController::UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList)
{
	for (int i = 0; i < m_nSkinnedMeshes; i++)
	{
		m_ppSkinnedMeshes[i]->m_pd3dcbSkinningBoneTransforms = m_ppd3dcbSkinningBoneTransforms[i];
		m_ppSkinnedMeshes[i]->m_pcbxmf4x4MappedSkinningBoneTransforms = m_ppcbxmf4x4MappedSkinningBoneTransforms[i];
	}
}

void CAnimationController::AdvanceTime(float fTimeElapsed, CGameObject *pRootGameObject) 
{
	m_fTime += fTimeElapsed; 
	if (m_pAnimationTracks)
	{
		for (int i = 0; i < m_nAnimationTracks; i++)
		{
			if (m_pAnimationTracks[i].m_bEnable)
			{				
				CAnimationSet *pAnimationSet = m_pAnimationSets->m_ppAnimationSets[m_pAnimationTracks[i].m_nAnimationSet];
				pAnimationSet->Animate(fTimeElapsed * m_pAnimationTracks[i].m_fSpeed, m_pAnimationTracks[i].m_fWeight, m_pAnimationTracks[i].m_fStartTime, m_pAnimationTracks[i].m_fEndTime);
			}
		}

		pRootGameObject->UpdateTransform(NULL);

		for (int k = 0; k < m_nAnimationTracks; k++)
		{
			if (m_pAnimationTracks[k].m_bEnable) m_pAnimationSets->m_ppAnimationSets[m_pAnimationTracks[k].m_nAnimationSet]->HandleCallback();
		}
	}
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CLoadedModelInfo::~CLoadedModelInfo()
{
	if (m_ppSkinnedMeshes) delete[] m_ppSkinnedMeshes;
}

void CLoadedModelInfo::PrepareSkinning()
{
	int nSkinnedMesh = 0;
	m_ppSkinnedMeshes = new CSkinnedMesh*[m_nSkinnedMeshes];
	m_pModelRootObject->FindAndSetSkinnedMesh(m_ppSkinnedMeshes, &nSkinnedMesh);

	for (int i = 0; i < m_nSkinnedMeshes; i++) m_ppSkinnedMeshes[i]->PrepareSkinning(m_pModelRootObject);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CGameObject::CGameObject(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* pd3dGraphicsRootSignature, CLoadedModelInfo* pModel, int nAnimationTracks)
{
	CLoadedModelInfo* pLionModel = pModel;
	if (!pLionModel) pLionModel = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature, "Model/Lion.bin", NULL);

	SetChild(pLionModel->m_pModelRootObject, true);
	m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, nAnimationTracks, pLionModel);

	strcpy_s(m_pstrFrameName, "Lion");

	m_nMaterials = 1;

	m_ppMaterials = new CMaterial * [m_nMaterials];
	m_ppMaterials[0] = NULL;
}

CGameObject::CGameObject()
{
	m_xmf4x4ToParent = Matrix4x4::Identity();
	m_xmf4x4World = Matrix4x4::Identity();
	
	timeCreated = chrono::system_clock::now();
}

CGameObject::CGameObject(int nMaterials) : CGameObject()
{
	m_nMaterials = nMaterials;
	if (m_nMaterials > 0)
	{
		m_ppMaterials = new CMaterial*[m_nMaterials];
		for (int i = 0; i < m_nMaterials; i++) m_ppMaterials[i] = NULL;
	}
}

CGameObject::~CGameObject()
{
	if (m_pMesh)
	{
		if (m_pMesh->m_nReferences >= 0)
		{
			m_pMesh->Release();
		}
	}

	if (m_nMaterials > 0)
	{
		for (int i = 0; i < m_nMaterials; i++)
		{
			if (m_ppMaterials[i]) m_ppMaterials[i]->Release();
		}
	}
	if (m_ppMaterials) delete[] m_ppMaterials;

	if (m_pSkinnedAnimationController) delete m_pSkinnedAnimationController;
}

void CGameObject::AddRef() 
{ 
	m_nReferences++; 

	if (m_pSibling) m_pSibling->AddRef();
	if (m_pChild) m_pChild->AddRef();
}

void CGameObject::Release() 
{ 
	if (m_pChild) m_pChild->Release();
	if (m_pSibling) m_pSibling->Release();

	if (--m_nReferences <= 0) delete this; 
}

void CGameObject::SetChild(CGameObject *pChild, bool bReferenceUpdate)
{
	if (pChild)
	{
		pChild->m_pParent = this;
		if (bReferenceUpdate) pChild->AddRef();
	}
	if (m_pChild)
	{
		if (pChild) pChild->m_pSibling = m_pChild->m_pSibling;
		m_pChild->m_pSibling = pChild;
	}
	else
	{
		m_pChild = pChild;
	}
}
void CGameObject::setRoot(CGameObject* pChild, bool update)
{
	if (pChild)
	{
		pChild->m_pParent = this;
		if (update) pChild->AddRef();
	}
	//if (m_pChild)
		//m_pChild->Release();
	m_pChild = pChild;
}

void CGameObject::SetMesh(CMesh *pMesh)
{
	//if (m_pMesh) m_pMesh->Release();
	m_pMesh = pMesh;
	if (m_pMesh) m_pMesh->AddRef();
}

void CGameObject::SetShader(CShader *pShader)
{
	m_nMaterials = 1;
	m_ppMaterials = new CMaterial*[m_nMaterials];
	m_ppMaterials[0] = new CMaterial(0);
	m_ppMaterials[0]->SetShader(pShader);
}

void CGameObject::SetShader(int nMaterial, CShader *pShader)
{
	if (m_ppMaterials[nMaterial]) m_ppMaterials[nMaterial]->SetShader(pShader);
}

void CGameObject::SetWireFrameShader()
{
	m_nMaterials = 1;
	m_ppMaterials = new CMaterial*[m_nMaterials];
	m_ppMaterials[0] = NULL;
	CMaterial *pMaterial = new CMaterial(0);
	pMaterial->SetWireFrameShader();
	pMaterial->SetShader(wireShader);
	SetMaterial(0, pMaterial);
}

void CGameObject::SetSkinnedAnimationWireFrameShader()
{
	m_nMaterials = 1;
	m_ppMaterials = new CMaterial*[m_nMaterials];
	m_ppMaterials[0] = NULL;
	CMaterial *pMaterial = new CMaterial(0);
	pMaterial->SetSkinnedAnimationWireFrameShader();
	pMaterial->SetShader(skinShader);
	SetMaterial(0, pMaterial);
}

void CGameObject::SetMaterial(int nMaterial, CMaterial *pMaterial)
{
	CMaterial *t = pMaterial;
	if (m_ppMaterials[nMaterial]) m_ppMaterials[nMaterial]->Release();
	m_ppMaterials[nMaterial] = t;
	if (m_ppMaterials[nMaterial]) m_ppMaterials[nMaterial]->AddRef();
}

CSkinnedMesh *CGameObject::FindSkinnedMesh(char *pstrSkinnedMeshName)
{
	CSkinnedMesh *pSkinnedMesh = NULL;
	if (m_pMesh && (m_pMesh->GetType() & VERTEXT_BONE_INDEX_WEIGHT)) 
	{
		pSkinnedMesh = (CSkinnedMesh *)m_pMesh;
		if(!strcmp(pSkinnedMesh->m_pstrMeshName, pstrSkinnedMeshName)) return(pSkinnedMesh);
	}

	if (m_pSibling) if (pSkinnedMesh = m_pSibling->FindSkinnedMesh(pstrSkinnedMeshName)) return(pSkinnedMesh);
	if (m_pChild) if (pSkinnedMesh = m_pChild->FindSkinnedMesh(pstrSkinnedMeshName)) return(pSkinnedMesh);

	return(NULL);
}

void CGameObject::FindAndSetSkinnedMesh(CSkinnedMesh **ppSkinnedMeshes, int *pnSkinnedMesh)
{
	if (m_pMesh && (m_pMesh->GetType() & VERTEXT_BONE_INDEX_WEIGHT)) ppSkinnedMeshes[(*pnSkinnedMesh)++] = (CSkinnedMesh *)m_pMesh;

	if (m_pSibling) m_pSibling->FindAndSetSkinnedMesh(ppSkinnedMeshes, pnSkinnedMesh);
	if (m_pChild) m_pChild->FindAndSetSkinnedMesh(ppSkinnedMeshes, pnSkinnedMesh);
}

CGameObject *CGameObject::FindFrame(char *pstrFrameName)
{
	CGameObject *pFrameObject = NULL;

	if (!strcmp(m_pstrFrameName, pstrFrameName)) return(this);

	if (m_pSibling) if (pFrameObject = m_pSibling->FindFrame(pstrFrameName)) return(pFrameObject);
	if (m_pChild) if (pFrameObject = m_pChild->FindFrame(pstrFrameName)) return(pFrameObject);

	return(NULL);
}

void CGameObject::SetActive(char *pstrFrameName, bool bActive)
{
	CGameObject *pFrameObject = FindFrame(pstrFrameName);
	if (pFrameObject) pFrameObject->m_bActive = bActive;
}

void CGameObject::UpdateTransform(XMFLOAT4X4 *pxmf4x4Parent)
{
	m_xmf4x4World = (pxmf4x4Parent) ? Matrix4x4::Multiply(m_xmf4x4ToParent, *pxmf4x4Parent) : m_xmf4x4ToParent;

	if (m_pSibling) m_pSibling->UpdateTransform(pxmf4x4Parent);
	if (m_pChild) m_pChild->UpdateTransform(&m_xmf4x4World);
}

void CGameObject::SetTrackAnimationSet(int nAnimationTrack, int nAnimationSet)
{
	if (m_pSkinnedAnimationController) m_pSkinnedAnimationController->SetTrackAnimationSet(nAnimationTrack, nAnimationSet);
}

void CGameObject::SetTrackAnimationPosition(int nAnimationTrack, float fPosition)
{
	if (m_pSkinnedAnimationController) m_pSkinnedAnimationController->SetTrackPosition(nAnimationTrack, fPosition);
}

void CGameObject::Animate(float fTimeElapsed)
{
	OnPrepareRender();

	if (m_pSkinnedAnimationController) m_pSkinnedAnimationController->AdvanceTime(fTimeElapsed, this);

	if (m_pSibling) m_pSibling->Animate(fTimeElapsed);
	if (m_pChild) m_pChild->Animate(fTimeElapsed);
}

void CGameObject::Render(ID3D12GraphicsCommandList *pd3dCommandList, CCamera *pCamera)
{
	if (m_bActive)
	{
		if (m_pSkinnedAnimationController) m_pSkinnedAnimationController->UpdateShaderVariables(pd3dCommandList);

		if (m_pMesh)
		{
			UpdateShaderVariable(pd3dCommandList, &m_xmf4x4World);

			if (m_nMaterials > 0)
			{
				for (int i = 0; i < m_nMaterials; i++)
				{
					if (m_ppMaterials[i])
					{
						if (m_ppMaterials[i]->m_pShader) m_ppMaterials[i]->m_pShader->Render(pd3dCommandList, pCamera);
						m_ppMaterials[i]->UpdateShaderVariable(pd3dCommandList);
					}
					m_pMesh->Render(pd3dCommandList, i);
				}
			}
		}
	}

	if (m_pSibling) m_pSibling->Render(pd3dCommandList, pCamera);
	if (m_pChild) m_pChild->Render(pd3dCommandList, pCamera);
}

void CGameObject::CreateShaderVariables(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList)
{
}

void CGameObject::UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList)
{
}

void CGameObject::UpdateShaderVariable(ID3D12GraphicsCommandList *pd3dCommandList, XMFLOAT4X4 *pxmf4x4World)
{
	XMFLOAT4X4 xmf4x4World;
	XMStoreFloat4x4(&xmf4x4World, XMMatrixTranspose(XMLoadFloat4x4(pxmf4x4World)));
	pd3dCommandList->SetGraphicsRoot32BitConstants(1, 16, &xmf4x4World, 0);
	
	pd3dCommandList->SetGraphicsRoot32BitConstants(1, 1, &matID, 16);
}

void CGameObject::UpdateShaderVariable(ID3D12GraphicsCommandList *pd3dCommandList, CMaterial *pMaterial)
{
}

void CGameObject::ReleaseShaderVariables()
{
}

void CGameObject::ReleaseUploadBuffers()
{
	if (m_pMesh) m_pMesh->ReleaseUploadBuffers();

	for (int i = 0; i < m_nMaterials; i++)
	{
		if (m_ppMaterials[i]) m_ppMaterials[i]->ReleaseUploadBuffers();
	}

	if (m_pSibling) m_pSibling->ReleaseUploadBuffers();
	if (m_pChild) m_pChild->ReleaseUploadBuffers();
}

void CGameObject::SetPosition(float x, float y, float z)
{
	m_xmf4x4ToParent._41 = x;
	m_xmf4x4ToParent._42 = y;
	m_xmf4x4ToParent._43 = z;

	UpdateTransform(NULL);
}

void CGameObject::SetPosition(XMFLOAT3 xmf3Position)
{
	SetPosition(xmf3Position.x, xmf3Position.y, xmf3Position.z);
}

void CGameObject::SetScale(float x, float y, float z)
{
	XMMATRIX mtxScale = XMMatrixScaling(x, y, z);
	m_xmf4x4ToParent = Matrix4x4::Multiply(mtxScale, m_xmf4x4ToParent);

	UpdateTransform(NULL);
}

XMFLOAT3 CGameObject::GetPosition()
{
	return(XMFLOAT3(m_xmf4x4World._41, m_xmf4x4World._42, m_xmf4x4World._43));
}

XMFLOAT3 CGameObject::GetLook()
{
	return(Vector3::Normalize(XMFLOAT3(m_xmf4x4World._31, m_xmf4x4World._32, m_xmf4x4World._33)));
}

XMFLOAT3 CGameObject::GetUp()
{
	return(Vector3::Normalize(XMFLOAT3(m_xmf4x4World._21, m_xmf4x4World._22, m_xmf4x4World._23)));
}

XMFLOAT3 CGameObject::GetRight()
{
	return(Vector3::Normalize(XMFLOAT3(m_xmf4x4World._11, m_xmf4x4World._12, m_xmf4x4World._13)));
}

void CGameObject::MoveStrafe(float fDistance)
{
	XMFLOAT3 xmf3Position = GetPosition();
	XMFLOAT3 xmf3Right = GetRight();
	xmf3Position = Vector3::Add(xmf3Position, xmf3Right, fDistance);
	CGameObject::SetPosition(xmf3Position);
}

void CGameObject::MoveUp(float fDistance)
{
	XMFLOAT3 xmf3Position = GetPosition();
	XMFLOAT3 xmf3Up = GetUp();
	xmf3Position = Vector3::Add(xmf3Position, xmf3Up, fDistance);
	CGameObject::SetPosition(xmf3Position);
}

void CGameObject::MoveForward(float fDistance)
{
	XMFLOAT3 xmf3Position = GetPosition();
	XMFLOAT3 xmf3Look = GetLook();
	xmf3Position = Vector3::Add(xmf3Position, xmf3Look, fDistance);
	CGameObject::SetPosition(xmf3Position);
}

void CGameObject::Rotate(float fPitch, float fYaw, float fRoll)
{
	XMMATRIX mtxRotate = XMMatrixRotationRollPitchYaw(XMConvertToRadians(fPitch), XMConvertToRadians(fYaw), XMConvertToRadians(fRoll));
	
	XMFLOAT4X4 mat = Matrix4x4::Identity();
	mat._41 = GetPosition().x;
	mat._42 = GetPosition().y;
	mat._43 = GetPosition().z;
	m_xmf4x4ToParent = Matrix4x4::Multiply(mtxRotate, mat);

	UpdateTransform(NULL);
}

void CGameObject::Rotate(XMFLOAT3 *pxmf3Axis, float fAngle)
{
	XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(pxmf3Axis), XMConvertToRadians(fAngle));
	m_xmf4x4ToParent = Matrix4x4::Multiply(mtxRotate, m_xmf4x4ToParent);

	UpdateTransform(NULL);
}

void CGameObject::Rotate(XMFLOAT4 *pxmf4Quaternion)
{
	XMMATRIX mtxRotate = XMMatrixRotationQuaternion(XMLoadFloat4(pxmf4Quaternion));
	m_xmf4x4ToParent = Matrix4x4::Multiply(mtxRotate, m_xmf4x4ToParent);

	UpdateTransform(NULL);
}

//#define _WITH_DEBUG_FRAME_HIERARCHY

UINT ReadUnsignedIntegerFromFile(FILE *pInFile)
{
	UINT nValue = 0;
	UINT nReads = (UINT)::fread(&nValue, sizeof(UINT), 1, pInFile); 
	return(nValue);
}

int ReadIntegerFromFile(FILE *pInFile)
{
	int nValue = 0;
	UINT nReads = (UINT)::fread(&nValue, sizeof(int), 1, pInFile); 
	return(nValue);
}

float ReadFloatFromFile(FILE *pInFile)
{
	float fValue = 0;
	UINT nReads = (UINT)::fread(&fValue, sizeof(float), 1, pInFile); 
	return(fValue);
}

int ReadStringFromFile(FILE *pInFile, char *pstrToken)
{
	int nStrLength = 0;
	UINT nReads = 0;
	nReads = (UINT)::fread(&nStrLength, sizeof(int), 1, pInFile);
	nReads = (UINT)::fread(pstrToken, sizeof(char), nStrLength, pInFile); 
	pstrToken[nStrLength] = '\0';

	return(nStrLength);
}

CGameObject *CGameObject::LoadFrameHierarchyFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, CGameObject *pParent, FILE *pInFile, CShader *pShader, int *pnSkinnedMeshes)
{
	char pstrToken[64] = { '\0' };
	UINT nReads = 0;

	int nFrame = ::ReadIntegerFromFile(pInFile);

	CGameObject *pGameObject = new CGameObject();
	::ReadStringFromFile(pInFile, pGameObject->m_pstrFrameName);

	for ( ; ; )
	{
		::ReadStringFromFile(pInFile, pstrToken);
		if (!strcmp(pstrToken, "<Transform>:"))
		{
			nReads = (UINT)::fread(&pGameObject->m_xmf4x4ToParent, sizeof(XMFLOAT4X4), 1, pInFile);

			nReads = (UINT)::fread(&pGameObject->m_xmf3Scale, sizeof(XMFLOAT3), 1, pInFile);
			nReads = (UINT)::fread(&pGameObject->m_xmf3Rotation, sizeof(XMFLOAT3), 1, pInFile);
			nReads = (UINT)::fread(&pGameObject->m_xmf3Translation, sizeof(XMFLOAT3), 1, pInFile);
			 
	}
		else if (!strcmp(pstrToken, "<Mesh>:"))
		{
			CMesh *pMesh = new CMesh(pd3dDevice, pd3dCommandList);
			pMesh->LoadMeshFromFile(pd3dDevice, pd3dCommandList, pInFile);
			pGameObject->SetMesh(pMesh);

			/**/pGameObject->SetWireFrameShader();
		}
		else if (!strcmp(pstrToken, "<SkinDeformations>:"))
		{
			if (pnSkinnedMeshes) (*pnSkinnedMeshes)++;

			CSkinnedMesh *pSkinnedMesh = new CSkinnedMesh(pd3dDevice, pd3dCommandList);
			pSkinnedMesh->LoadSkinDeformationsFromFile(pd3dDevice, pd3dCommandList, pInFile);
			pSkinnedMesh->CreateShaderVariables(pd3dDevice, pd3dCommandList);

			::ReadStringFromFile(pInFile, pstrToken); //<Mesh>:
			if (!strcmp(pstrToken, "<Mesh>:")) pSkinnedMesh->LoadMeshFromFile(pd3dDevice, pd3dCommandList, pInFile);

			pGameObject->SetMesh(pSkinnedMesh);
			pGameObject->dynamic = true;
			/**/pGameObject->SetSkinnedAnimationWireFrameShader();
		}
		else if (!strcmp(pstrToken, "<Children>:"))
		{
			int nChilds = ::ReadIntegerFromFile(pInFile);
			if (nChilds > 0)
			{
				for (int i = 0; i < nChilds; i++)
				{
					::ReadStringFromFile(pInFile, pstrToken);
					if (!strcmp(pstrToken, "<Frame>:"))
					{
						CGameObject *pChild = CGameObject::LoadFrameHierarchyFromFile(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature, pGameObject, pInFile, pShader, pnSkinnedMeshes);
						if(pChild) pGameObject->SetChild(pChild);
#ifdef _WITH_DEBUG_FRAME_HIERARCHY
						TCHAR pstrDebug[256] = { 0 };
						_stprintf_s(pstrDebug, 256, _T("(Frame: %p) (Parent: %p)\n"), pChild, pGameObject);
						OutputDebugString(pstrDebug);
#endif
					}
				}
			}
		}
		else if (!strcmp(pstrToken, "</Frame>"))
		{
			break;
		}
	}
	return(pGameObject);
}

void CGameObject::PrintFrameInfo(CGameObject *pGameObject, CGameObject *pParent)
{
	TCHAR pstrDebug[256] = { 0 };

	_stprintf_s(pstrDebug, 256, _T("(Frame: %p) (Parent: %p)\n"), pGameObject, pParent);
	OutputDebugString(pstrDebug);

	if (pGameObject->m_pSibling) CGameObject::PrintFrameInfo(pGameObject->m_pSibling, pParent);
	if (pGameObject->m_pChild) CGameObject::PrintFrameInfo(pGameObject->m_pChild, pGameObject);
}

void CGameObject::LoadAnimationFromFile(FILE *pInFile, CLoadedModelInfo *pLoadedModel)
{
	char pstrToken[64] = { '\0' };
	UINT nReads = 0;

	int nAnimationSets = 0;

	for ( ; ; )
	{
		::ReadStringFromFile(pInFile, pstrToken);
		if (!strcmp(pstrToken, "<AnimationSets>:"))
		{
			nAnimationSets = ::ReadIntegerFromFile(pInFile);
			pLoadedModel->m_pAnimationSets = new CAnimationSets(nAnimationSets);
		}
		else if (!strcmp(pstrToken, "<AnimationSet>:"))
		{
			int nAnimationSet = ::ReadIntegerFromFile(pInFile);

			::ReadStringFromFile(pInFile, pstrToken); //Animation Set Name

			float fStartTime = ::ReadFloatFromFile(pInFile);
			float fEndTime = ::ReadFloatFromFile(pInFile);

			pLoadedModel->m_pAnimationSets->m_ppAnimationSets[nAnimationSet] = new CAnimationSet(fStartTime, fEndTime, pstrToken);
			CAnimationSet *pAnimationSet = pLoadedModel->m_pAnimationSets->m_ppAnimationSets[nAnimationSet];

			::ReadStringFromFile(pInFile, pstrToken);
			if (!strcmp(pstrToken, "<AnimationLayers>:"))
			{
				pAnimationSet->m_nAnimationLayers = ::ReadIntegerFromFile(pInFile);
				pAnimationSet->m_pAnimationLayers = new CAnimationLayer[pAnimationSet->m_nAnimationLayers];

				for (int i = 0; i < pAnimationSet->m_nAnimationLayers; i++)
				{
					::ReadStringFromFile(pInFile, pstrToken);
					if (!strcmp(pstrToken, "<AnimationLayer>:"))
					{
						int nAnimationLayer = ::ReadIntegerFromFile(pInFile);
						CAnimationLayer *pAnimationLayer = &pAnimationSet->m_pAnimationLayers[nAnimationLayer];

						pAnimationLayer->m_nAnimatedBoneFrames = ::ReadIntegerFromFile(pInFile);

						pAnimationLayer->m_ppAnimatedBoneFrameCaches = new CGameObject *[pAnimationLayer->m_nAnimatedBoneFrames];
						pAnimationLayer->m_ppAnimationCurves = new CAnimationCurve *[pAnimationLayer->m_nAnimatedBoneFrames][9];

						pAnimationLayer->m_fWeight = ::ReadFloatFromFile(pInFile);

						for (int j = 0; j < pAnimationLayer->m_nAnimatedBoneFrames; j++)
						{
							::ReadStringFromFile(pInFile, pstrToken);
							if (!strcmp(pstrToken, "<AnimationCurve>:"))
							{
								int nCurveNode = ::ReadIntegerFromFile(pInFile); //j

								for (int k = 0; k < 9; k++) pAnimationLayer->m_ppAnimationCurves[j][k] = NULL;

								::ReadStringFromFile(pInFile, pstrToken);
								pAnimationLayer->m_ppAnimatedBoneFrameCaches[j] = pLoadedModel->m_pModelRootObject->FindFrame(pstrToken);

								for ( ; ; )
								{
									::ReadStringFromFile(pInFile, pstrToken);
									if (!strcmp(pstrToken, "<TX>:")) pAnimationLayer->LoadAnimationKeyValues(j, 0, pInFile);
									else if(!strcmp(pstrToken, "<TY>:")) pAnimationLayer->LoadAnimationKeyValues(j, 1, pInFile);
									else if(!strcmp(pstrToken, "<TZ>:")) pAnimationLayer->LoadAnimationKeyValues(j, 2, pInFile);
									else if(!strcmp(pstrToken, "<RX>:")) pAnimationLayer->LoadAnimationKeyValues(j, 3, pInFile);
									else if(!strcmp(pstrToken, "<RY>:")) pAnimationLayer->LoadAnimationKeyValues(j, 4, pInFile);
									else if(!strcmp(pstrToken, "<RZ>:")) pAnimationLayer->LoadAnimationKeyValues(j, 5, pInFile);
									else if(!strcmp(pstrToken, "<SX>:")) pAnimationLayer->LoadAnimationKeyValues(j, 6, pInFile);
									else if(!strcmp(pstrToken, "<SY>:")) pAnimationLayer->LoadAnimationKeyValues(j, 7, pInFile);
									else if(!strcmp(pstrToken, "<SZ>:")) pAnimationLayer->LoadAnimationKeyValues(j, 8, pInFile);
									else if(!strcmp(pstrToken, "</AnimationCurve>"))
									{
										break;
									}
								}
							}
						}
						::ReadStringFromFile(pInFile, pstrToken); //</AnimationLayer>
					}
				}
				::ReadStringFromFile(pInFile, pstrToken); //</AnimationLayers>
			}
			::ReadStringFromFile(pInFile, pstrToken); //</AnimationSet>
		}
		else if (!strcmp(pstrToken, "</AnimationSets>"))
		{
			break;
		}
	}
}

CLoadedModelInfo *CGameObject::LoadGeometryAndAnimationFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, char *pstrFileName, CShader *pShader)
{
	FILE *pInFile = NULL;
	::fopen_s(&pInFile, pstrFileName, "rb");
	::rewind(pInFile);

	CLoadedModelInfo *pLoadedModel = new CLoadedModelInfo();
	pLoadedModel->m_pModelRootObject = new CGameObject();
	strcpy_s(pLoadedModel->m_pModelRootObject->m_pstrFrameName, "RootNode");

	char pstrToken[64] = { '\0' };

	for ( ; ; )
	{
		if (::ReadStringFromFile(pInFile, pstrToken))
		{
			if (!strcmp(pstrToken, "<Hierarchy>"))
			{
				for ( ; ; )
				{
					::ReadStringFromFile(pInFile, pstrToken);
					if (!strcmp(pstrToken, "<Frame>:"))
					{
						CGameObject *pChild = CGameObject::LoadFrameHierarchyFromFile(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature, NULL, pInFile, pShader, &pLoadedModel->m_nSkinnedMeshes);
						if (pChild) pLoadedModel->m_pModelRootObject->SetChild(pChild);
					}
					else if (!strcmp(pstrToken, "</Hierarchy>"))
					{
						break;
					}
				}
			}
			else if (!strcmp(pstrToken, "<Animation>"))
			{
				CGameObject::LoadAnimationFromFile(pInFile, pLoadedModel);
				pLoadedModel->PrepareSkinning();
			}
			else if (!strcmp(pstrToken, "</Animation>"))
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	
#ifdef _WITH_DEBUG_FRAME_HIERARCHY
	TCHAR pstrDebug[256] = { 0 };
	_stprintf_s(pstrDebug, 256, _T("Frame Hierarchy\n"));
	OutputDebugString(pstrDebug);

	CGameObject::PrintFrameInfo(pLoadedModel->m_pModelRootObject, NULL);
#endif

	::fclose(pInFile);

	return(pLoadedModel);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
PlayerObject::PlayerObject(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, CLoadedModelInfo *pModel, int nAnimationTracks):CGameObject(1)
{
	CLoadedModelInfo *pLionModel = pModel;
	if (!pLionModel) pLionModel = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature, "Model/Lion.bin", NULL);
	
	SetChild(pLionModel->m_pModelRootObject, true);
	m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, nAnimationTracks, pLionModel);

	strcpy_s(m_pstrFrameName, "Lion");

	
	
	
	

	

	SetActive("SK_Lion_LOD1", false);
	SetActive("SK_Lion_LOD2", false);
	SetActive("SK_Lion_LOD3", false);


	
	
}

PlayerObject::~PlayerObject()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
EnemyObject::EnemyObject(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature, CLoadedModelInfo *pModel, int nAnimationTracks, float** height, float areax, float areaz)
{
	CLoadedModelInfo *pEagleModel = pModel;
	if (!pEagleModel) pEagleModel = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, pd3dGraphicsRootSignature, "Model/Eagle.bin", NULL);

	SetChild(pEagleModel->m_pModelRootObject, true);
	m_pSkinnedAnimationController = new CAnimationController(pd3dDevice, pd3dCommandList, nAnimationTracks, pEagleModel);

	strcpy_s(m_pstrFrameName, "Eagle");

	heightmap = height;
	areaX = areax;
	areaZ = areaz;
}

EnemyObject::~EnemyObject()
{
}

std::vector<XMFLOAT2> EnemyObject::NavigateMovement(float x, float z)
{
	
	vector<bool> addOrNot; //각 경로에 대해 새로운 분기점이 만들어져서 경로를 새로 만들지 여부
	vector<vector<XMFLOAT2>> route; // 시도한 모든 경로

	vector<float> visitedx;//이미 방문한 지점
	vector<float> visitedz;//이미 방문한 지점

	XMFLOAT2 origin = XMFLOAT2(GetPosition().x, GetPosition().z);
	float ox = (float)((int)((origin.x - 0.25f) / 0.5f) + 1) * 0.5f;
	float oz = (float)((int)((origin.y - 0.25f) / 0.5f) + 1) * 0.5f;
	
	vector<XMFLOAT2> pos;
	pos.push_back(origin);

	int dist = 0;
	visitedx.push_back(pos[0].x);
	visitedz.push_back(pos[0].y);

	vector<XMFLOAT2> result;
	bool quit = false;

	int hix, hiz;


	if (ox >= 0.0f && ox < 200.0f && oz>=0.0f && oz < 200.0f)
	{
		hix = (int)(x / 0.5f);
		hiz = (int)(z / 0.5f);
		if (x < 0.5f || x >= 199.5f || oz < 0.5f || oz >= 199.5f)
		{
			return result;
		}
	}
	else if (ox >= 200.0f && ox < 600.0f && oz>=0.0f && oz < 200.0f)
	{
		hix = (int)((x -200.0f)/ 0.5f);
		if (hix < 0)
			hix = 0;
		hiz = (int)((z) / 0.5f);
		if (hiz < 0)
			hiz = 0;
		if (x < 200.5f || x >= 599.5f || oz < 0.5f || oz >= 199.5f)
		{
			return result;
		}
	}
	float dx = origin.x - x;
	float dz = origin.y - z;
	float dis = sqrt(dx * dx + dz * dz);
	if (heightmap[hix][hiz] > 0.0f)
		return result;
	if (dis < 0.5f)
		return result;
	while (quit==false)
	{
		dist += 1;
		//마지막으로 구했던 위치들로부터 경로 생성
		for (int k = 0; k < pos.size(); ++k)
		{
			//목적지에 도착하면 루프 종료
			

			if (quit == true)
				break;

			//현 위치에서 가로세로 한칸 떨어진 곳 중 갈 수 있는 곳을 구함
			vector<XMFLOAT2> available;
			//좌
			XMFLOAT2 p2 = XMFLOAT2(pos[k].x - 0.5f, pos[k].y);
			//우
			XMFLOAT2 p3 = XMFLOAT2(pos[k].x + 0.5f, pos[k].y);
			//상
			XMFLOAT2 p1 = XMFLOAT2(pos[k].x, pos[k].y + 0.5f);

			//하
			XMFLOAT2 p4 = XMFLOAT2(pos[k].x, pos[k].y - 0.5f);

			XMFLOAT2 p5 = XMFLOAT2(pos[k].x - 0.5f, pos[k].y - 0.5f);
			XMFLOAT2 p6 = XMFLOAT2(pos[k].x - 0.5f, pos[k].y + 0.5f);
			XMFLOAT2 p7 = XMFLOAT2(pos[k].x + 0.5f, pos[k].y - 0.5f);
			XMFLOAT2 p8 = XMFLOAT2(pos[k].x + 0.5f, pos[k].y + 0.5f);

			int hx1, hx2, hx3, hx4, hx5, hx6, hx7, hx8;
			int hy1, hy2, hy3, hy4, hy5, hy6, hy7, hy8;

			if (x > 0.0f && x < 200.0f && z>0.0f && z < 200.0f)
			{
				hx1 = (int)(p1.x / 0.5f);
				hx2 = (int)(p2.x / 0.5f);
				hx3 = (int)(p3.x / 0.5f);
				hx4 = (int)(p4.x / 0.5f);
				hx5 = (int)(p5.x / 0.5f);
				hx6 = (int)(p6.x / 0.5f);
				hx7 = (int)(p7.x / 0.5f);
				hx8 = (int)(p8.x / 0.5f);

				if (hx1 < 0)
					hx1 = 0;
				if (hx2 < 0)
					hx2 = 0;
				if (hx3 < 0)
					hx3 = 0;
				if (hx4 < 0)
					hx4 = 0;
				if (hx5 < 0)
					hx5 = 0;
				if (hx6 < 0)
					hx6 = 0;
				if (hx7 < 0)
					hx7 = 0;
				if (hx8 < 0)
					hx8 = 0;


				if (hx1 >= 400)
					hx1 = 399;
				if (hx2 >= 400)
					hx2 = 399;
				if (hx3 >= 400)
					hx3 = 399;
				if (hx4 >= 400)
					hx4 = 399;
				if (hx5 >= 400)
					hx5 = 399;
				if (hx6 >= 400)
					hx6 = 399;
				if (hx7 >= 400)
					hx7 = 399;
				if (hx8 >= 400)
					hx8 = 399;

				hy1 = (int)(p1.y / 0.5f);
				hy2 = (int)(p2.y / 0.5f);
				hy3 = (int)(p3.y / 0.5f);
				hy4 = (int)(p4.y / 0.5f);
				hy5 = (int)(p5.y / 0.5f);
				hy6 = (int)(p6.y / 0.5f);
				hy7 = (int)(p7.y / 0.5f);
				hy8 = (int)(p8.y / 0.5f);
				if (hy1 < 0)
					hy1 = 0;
				if (hy2 < 0)
					hy2 = 0;
				if (hy3 < 0)
					hy3 = 0;
				if (hy4 < 0)
					hy4 = 0;
				if (hy5 < 0)
					hy5 = 0;
				if (hy6 < 0)
					hy6 = 0;
				if (hy7 < 0)
					hy7 = 0;
				if (hy8 < 0)
					hy8 = 0;


				if (hy1 >= 400)
					hy1 = 399;
				if (hy2 >= 400)
					hy2 = 399;
				if (hy3 >= 400)
					hy3 = 399;
				if (hy4 >= 400)
					hy4 = 399;
				if (hy5 >= 400)
					hy5 = 399;
				if (hy6 >= 400)
					hy6 = 399;
				if (hy7 >= 400)
					hy7 = 399;
				if (hy8 >= 400)
					hy8 = 399;
			}
			else if (x > 200.0f && x < 600.0f && z>0.0f && z < 200.0f)
			{
				hx1 = (int)((p1.x -200.0f)/ 0.5f);
				
				hx2 = (int)((p2.x -200.0f)/ 0.5f);
				hx3 = (int)((p3.x -200.0f)/ 0.5f);
				hx4 = (int)((p4.x -200.0f)/ 0.5f);
				hx5 = (int)((p5.x -200.0f)/ 0.5f);
				hx6 = (int)((p6.x -200.0f)/ 0.5f);
				hx7 = (int)((p7.x -200.0f)/ 0.5f);
				hx8 = (int)((p8.x -200.0f)/ 0.5f);

				if (hx1 < 0)
					hx1 = 0;
				if (hx2 < 0)
					hx2 = 0;
				if (hx3 < 0)
					hx3 = 0;
				if (hx4 < 0)
					hx4 = 0;
				if (hx5 < 0)
					hx5 = 0;
				if (hx6 < 0)
					hx6 = 0;
				if (hx7 < 0)
					hx7 = 0;
				if (hx8 < 0)
					hx8 = 0;

				if (hx1 >= 800)
					hx1 = 799;
				if (hx2 >= 800)
					hx2 = 799;
				if (hx3 >= 800)
					hx3 = 799;
				if (hx4 >= 800)
					hx4 = 799;
				if (hx5 >= 800)
					hx5 = 799;
				if (hx6 >= 800)
					hx6 = 799;
				if (hx7 >= 800)
					hx7 = 799;
				if (hx8 >= 800)
					hx8 = 799;
				hy1 = (int)((p1.y )/ 0.5f);
				hy2 = (int)((p2.y )/ 0.5f);
				hy3 = (int)((p3.y )/ 0.5f);
				hy4 = (int)((p4.y )/ 0.5f);
				hy5 = (int)((p5.y )/ 0.5f);
				hy6 = (int)((p6.y )/ 0.5f);
				hy7 = (int)((p7.y )/ 0.5f);
				hy8 = (int)((p8.y )/ 0.5f);
				if (hy1 < 0)
					hy1 = 0;
				if (hy2 < 0)
					hy2 = 0;
				if (hy3 < 0)
					hy3 = 0;
				if (hy4 < 0)
					hy4 = 0;
				if (hy5 < 0)
					hy5 = 0;
				if (hy6 < 0)
					hy6 = 0;
				if (hy7 < 0)
					hy7 = 0;
				if (hy8 < 0)
					hy8 = 0;

				if (hy1 >= 400)
					hy1 = 399;
				if (hy2 >= 400)
					hy2 = 399;
				if (hy3 >= 400)
					hy3 = 399;
				if (hy4 >= 400)
					hy4 = 399;
				if (hy5 >= 400)
					hy5 = 399;
				if (hy6 >= 400)
					hy6 = 399;
				if (hy7 >= 400)
					hy7 = 399;
				if (hy8 >= 400)
					hy8 = 399;
			}
			bool v1 = false;
			bool v2 = false;
			bool v3 = false;
			bool v4 = false;
			bool v5 = false;
			bool v6 = false;
			bool v7 = false;
			bool v8 = false;

			//방문기록에 없고 높이가 균일한 좌표인경우 목록에 추가
			for (int i = 0; i < visitedx.size(); ++i)
			{
				if ((p1.x == visitedx[i] && p1.y == visitedz[i])|| heightmap[hx1][hy1] >0.0f)
					v1 = true;

				if ((p2.x == visitedx[i] && p2.y == visitedz[i]) || heightmap[hx2][hy2] > 0.0f)
					v2 = true;

				if ((p3.x == visitedx[i] && p3.y == visitedz[i]) || heightmap[hx3][hy3] > 0.0f)
					v3 = true;

				if ((p4.x == visitedx[i] && p4.y == visitedz[i]) || heightmap[hx4][hy4] > 0.0f)
					v4 = true;

				if ((p5.x == visitedx[i] && p5.y == visitedz[i]) || heightmap[hx5][hy5] > 0.0f)
					v5 = true;

				if ((p6.x == visitedx[i] && p6.y == visitedz[i]) || heightmap[hx6][hy6] > 0.0f)
					v6 = true;

				if ((p7.x == visitedx[i] && p7.y == visitedz[i]) || heightmap[hx7][hy7] > 0.0f)
					v7 = true;

				if ((p8.x == visitedx[i] && p8.y == visitedz[i]) || heightmap[hx8][hy8] > 0.0f)
					v8 = true;
			}
			if (v1 == false)
				available.push_back(p1);
			if (v2 == false)
				available.push_back(p2);
			if (v3 == false)
				available.push_back(p3);
			if (v4 == false)
				available.push_back(p4);
			if (v5 == false)
				available.push_back(p5);
			if (v6 == false)
				available.push_back(p6);
			if (v7 == false)
				available.push_back(p7);
			if (v8 == false)
				available.push_back(p8);

			//이동 가능한 좌표들에 대해 방문기록에 추가
			for (int i = 0; i < available.size(); ++i)
			{
				visitedx.push_back(available[i].x);
				visitedz.push_back(available[i].y);
			}

			//시작점에서 이동하는 경우 한칸짜리 경로 생성
			if (pos[k].x == origin.x && pos[k].y == origin.y)
			{

				for (int i = 0; i < available.size(); ++i)
				{
					vector<XMFLOAT2> road;
					road.push_back(origin);
					road.push_back(available[i]);

					route.push_back(road);
					addOrNot.push_back(false);

				}

			}
			//시작점이 아닌 경우
			else
			{
				//기존에 있던 모든 루트의 정보를 받음
				vector<XMFLOAT2> road;
				for (int j = 0; j < route[k].size(); ++j)
				{

					road.push_back(route[k][j]);
				}
				
				
				
				//경로에 추가할 다음 위치들에 대해
				for (int j = 0; j < available.size(); ++j)
				{
					//길이 갈라지지 않은 경우 해당 경로에 그대로 새 위치만 추가
					if (addOrNot[k] == false)
					{
						route[k].push_back(available[j]);
						addOrNot[k] = true;
					}

					//길이 갈라진 경우 경로를 추가로 생성하여 기존경로를 복사한 후 새 위치 추가
					else
					{

						route.push_back(road);
						route[route.size() - 1].push_back(available[j]);
						addOrNot.push_back(false);
					}
				}
				
			}
			//다음 번 루프를 처리하기 위해 초기화
			for (int i = 0; i < addOrNot.size(); ++i)
			{
				addOrNot[i] = false;
			}
			

		}
		//현재까지 생성한 모든 루트에 대해
		for (int i = 0; i < route.size(); ++i)
		{
			float desx = (float)((int)((route[i][route[i].size() - 1].x - 0.25f) / 0.5f) + 1) * 0.5f;
			float desz = (float)((int)((route[i][route[i].size() - 1].y - 0.25f) / 0.5f) + 1) * 0.5f;

			// 목표 지점에 도달한 경로가 존재할 경우 결과값 저장 후 루프 종료
			if (desx == x && desz == z)
			{
				result = route[i];
				quit = true;
				break;
			}

		}
		//루프 종료 후 최종 경로 반환.
		if (quit == true)
			break;

		//아닌 경우 현재까지 구한 경로들의 맨 마지막 이동지점들을 저장
		pos.clear();
		for (int i = 0; i < route.size(); ++i)
		{
			
			pos.push_back(route[i][route[i].size() - 1]);
			
		}
	}
	//최종 경로 반환.
	return result;
}
void EnemyObject::moveByRoute(vector<XMFLOAT2> route)
{
	
	if (route.size() > 0)
	{
		//기존 위치 구하기
		XMFLOAT3 origin = GetPosition();

		//기존위치-새위치 방향 벡터 및 거리
		XMFLOAT2 dir = XMFLOAT2(route[routeIdx].x - origin.x, route[routeIdx].y - origin.z);
		float length = sqrt(dir.x * dir.x + dir.y * dir.y);


		//거리가 10센티 밖인 경우, 즉 아직 더 가야 하는 경우
		if (length >= 0.1f)
		{
			XMFLOAT3 origin = GetPosition();
			XMFLOAT2 dir = XMFLOAT2(route[routeIdx].x - origin.x, route[routeIdx].y - origin.z);
			XMFLOAT2 ndir = XMFLOAT2(dir.x / length, dir.y / length);

			float angle = atan2f(ndir.x, ndir.y);
			angle = angle / 3.141592f * 180.0f;

			if (angle >= 360.0f)
				angle -= 360.0f;
			Rotate(0.0f, angle, 0.0f);

			float speed = 3.0f;
			//이동한다. 프레임레이트 60 기준, 초당 6미터를 이동한다.
			SetPosition(origin.x + ndir.x * speed / 60.0f, 0.0f, origin.z + ndir.y * speed/60.0f);
			mbox->start.x += ndir.x * speed/60.0f;
			mbox->end.x += ndir.x * speed / 60.0f;

			mbox->start.z += ndir.y * speed / 60.0f;
			mbox->end.z += ndir.y * speed / 60.0f;


		}
		//거리가 충분히 좁혀진 경우 경로에 저장된 다음 위치를 목적지로 설정
		else
		{
			routeIdx += 1;
		}
	}
}

ParticleObject::ParticleObject(int n) :CGameObject(n){}

ParticleObject::~ParticleObject()
{
	if (m_pMesh) m_pMesh->Release();

	if (m_nMaterials > 0)
	{
		for (int i = 0; i < m_nMaterials; i++)
		{
			if (m_ppMaterials[i]) m_ppMaterials[i]->Release();
		}
	}
	if (m_ppMaterials) delete[] m_ppMaterials;

	if (m_pSkinnedAnimationController) delete m_pSkinnedAnimationController;
}

BoomObject::BoomObject(int n, XMFLOAT3 ori, XMFLOAT3 dir, float spd, chrono::time_point<chrono::system_clock> time) : CGameObject(n)
{
	origin = ori;
	direction = dir;
	speed = spd;
	created = time;
	SetPosition(origin);
}
BoomObject::~BoomObject()
{

}


UIObject::UIObject(int n, int sx, int sy, int ex, int ey, int def) : CGameObject(n)
{
	x1 = sx;
	x2 = ex;
	y1 = sy;
	y2 = ey;
	defaultMesh = def;
}
UIObject::~UIObject(){}

