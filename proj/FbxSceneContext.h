#pragma once

#include "Mesh.h"
#include "Shader.h"

class CShader;

#define SKINNED_ANIMATION_BONES		128

class CFbxRenderInfo
{
public:
	CFbxRenderInfo();
	~CFbxRenderInfo();

public:
	static CShader 					*m_pFbxModelShader;
	static CShader 					*m_pFbxSkinnedModelShader;

	CMeshFromFbx					*m_pMesh = NULL;

	int								m_nLinkNodes = 0; //Skinning Bones
	int								m_nInstances = 0;

	ID3D12Resource					**m_ppd3dcbLinkNodeTransforms = NULL; //Bone Transforms
	XMFLOAT4X4						**m_ppcbxmf4x4MappedLinkNodeTransforms = NULL;

public:
	static void CreateFbxModelShader(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, ID3D12RootSignature *pd3dGraphicsRootSignature);
	static void ReleaseFbxModelShader();
	static void ReleaseUploadBuffers();
};

extern void RenderFbxNodeHierarchy(ID3D12GraphicsCommandList *pd3dCommandList, FbxNode *pfbxNode, FbxTime& fbxCurrentTime, FbxAMatrix& fbxmtxWorld, int nInstance);

extern void CreateMeshFromFbxNodeHierarchy(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, FbxNode *pfbxNode, int nInstances);
extern void ReleaseRenderInfoFromFbxNodeHierarchy(FbxNode *pfbxNode);
extern void ReleaseUploadBufferFromFbxNodeHierarchy(FbxNode *pfbxNode);

extern FbxScene *LoadFbxSceneFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, FbxManager *pfbxSdkManager, const char *pstrFbxFileName);

extern XMFLOAT4X4 FbxMatrixToXmFloat4x4Matrix(FbxAMatrix *pfbxmtxSource);
extern FbxAMatrix XmFloat4x4MatrixToFbxMatrix(XMFLOAT4X4& xmf4x4Source);

