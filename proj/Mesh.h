#pragma once
#include "stdafx.h"


class CMesh
{
public:
	CMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~CMesh();
private:
	int m_nReferences = 0;
public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }
	void ReleaseUploadBuffers();
protected:
	ID3D12Resource* m_pd3dVertexBuffer = NULL;
	ID3D12Resource* m_pd3dVertexUploadBuffer = NULL;
	D3D12_VERTEX_BUFFER_VIEW m_d3dVertexBufferView;
	D3D12_PRIMITIVE_TOPOLOGY m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT m_nSlot = 0;
	UINT m_nVertices = 0;
	UINT m_nStride = 0;
	UINT m_nOffset = 0;


protected:
	ID3D12Resource* m_pd3dIndexBuffer = NULL;
	ID3D12Resource* m_pd3dIndexUploadBuffer = NULL;
	/*인덱스 버퍼(인덱스의 배열)와 인덱스 버퍼를 위한 업로드 버퍼에 대한 인터페이스 포인터이다. 인덱스 버퍼는 정점
	버퍼(배열)에 대한 인덱스를 가진다.*/
	D3D12_INDEX_BUFFER_VIEW m_d3dIndexBufferView;
	UINT m_nIndices = 0;
	//인덱스 버퍼에 포함되는 인덱스의 개수이다.
	UINT m_nStartIndex = 0;
	//인덱스 버퍼에서 메쉬를 그리기 위해 사용되는 시작 인덱스이다.
	int m_nBaseVertex = 0;
	//인덱스 버퍼의 인덱스에 더해질 인덱스이다.


public:
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList);
};

class CTriangleMesh : public CMesh
{
public:
	CTriangleMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~CTriangleMesh() { }
};



//정점을 표현하기 위한 클래스를 선언한다. 
class CVertex
{
public:
	//정점의 위치 벡터이다(모든 정점은 최소한 위치 벡터를 가져야 한다). 
	XMFLOAT3 m_xmf3Position;
public:
	CVertex() { m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f); }
	CVertex(XMFLOAT3 xmf3Position) { m_xmf3Position = xmf3Position; }
	~CVertex() { }
};
class CDiffusedVertex : public CVertex
{
public:
	//정점의 색상이다. 
	XMFLOAT4 m_xmf4Diffuse;
public:
	CDiffusedVertex() {
		m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f); m_xmf4Diffuse =
			XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);
	}
	CDiffusedVertex(float x, float y, float z, XMFLOAT4 xmf4Diffuse) {
		m_xmf3Position =
			XMFLOAT3(x, y, z); m_xmf4Diffuse = xmf4Diffuse;
	}
	CDiffusedVertex(XMFLOAT3 xmf3Position, XMFLOAT4 xmf4Diffuse) {
		m_xmf3Position =
			xmf3Position; m_xmf4Diffuse = xmf4Diffuse;
	}
	~CDiffusedVertex() { }
};
class CTexturedVertex : public CVertex
{
public:
	XMFLOAT2						m_xmf2TexCoord;

public:
	CTexturedVertex() { m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f); m_xmf2TexCoord = XMFLOAT2(0.0f, 0.0f); }
	CTexturedVertex(float x, float y, float z, XMFLOAT2 xmf2TexCoord) { m_xmf3Position = XMFLOAT3(x, y, z); m_xmf2TexCoord = xmf2TexCoord; }
	CTexturedVertex(XMFLOAT3 xmf3Position, XMFLOAT2 xmf2TexCoord = XMFLOAT2(0.0f, 0.0f)) { m_xmf3Position = xmf3Position; m_xmf2TexCoord = xmf2TexCoord; }
	~CTexturedVertex() { }
};

class CDiffusedTexturedVertex : public CDiffusedVertex
{
public:
	XMFLOAT2						m_xmf2TexCoord;

public:
	CDiffusedTexturedVertex() { m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f); m_xmf4Diffuse = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f); m_xmf2TexCoord = XMFLOAT2(0.0f, 0.0f); }
	CDiffusedTexturedVertex(float x, float y, float z, XMFLOAT4 xmf4Diffuse, XMFLOAT2 xmf2TexCoord) { m_xmf3Position = XMFLOAT3(x, y, z); m_xmf4Diffuse = xmf4Diffuse; m_xmf2TexCoord = xmf2TexCoord; }
	CDiffusedTexturedVertex(XMFLOAT3 xmf3Position, XMFLOAT4 xmf4Diffuse = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f), XMFLOAT2 xmf2TexCoord = XMFLOAT2(0.0f, 0.0f)) { m_xmf3Position = xmf3Position; m_xmf4Diffuse = xmf4Diffuse; m_xmf2TexCoord = xmf2TexCoord; }
	~CDiffusedTexturedVertex() { }
};


class CCubeMeshDiffused : public CMesh
{

	
public:
	
	//직육면체의 가로, 세로, 깊이의 길이를 지정하여 직육면체 메쉬를 생성한다. 
	CCubeMeshDiffused(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, float fWidth = 2.0f, float fHeight = 2.0f, float fDepth = 2.0f);
	virtual ~CCubeMeshDiffused();
};


#define OBJECTS 1

class CAngrybotMeshDiffused : public CMesh
{
public:
	CDiffusedVertex* result;
	int* indices;
	CAngrybotMeshDiffused(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void loadmesh(FbxNode* node, ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);

	void InitScene(FbxManager* mngr, FbxScene* scene);
	bool SetCurrentAnimStack(int n, FbxArray<FbxString*> arr);

	void CAngrybotMeshDiffused::Render(ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~CAngrybotMeshDiffused();
public:
	unsigned int GetFrameTimeByMilliSeconds() { return((unsigned int)m_fbxFrameTime.GetMilliSeconds()); }

	FbxManager* m_pfbxSdkManager = NULL;
	FbxScene* m_pfbxScene = NULL;
	FbxImporter* m_pfbxImporter = NULL;
	FbxAnimLayer* m_pfbxCurrentAnimLayer = NULL;

	FbxArray<FbxString*> m_fbxAnimationStackNameArray;

	FbxTime m_pfbxStartTimes[OBJECTS];
	FbxTime m_pfbxStopTimes[OBJECTS];
	FbxTime m_pfbxCurrentTimes[OBJECTS];
	FbxTime m_fbxFrameTime;

	int m_xPreviousMousePos;
	int m_yPreviousMousePos;
	FbxVector4 m_fbxv4CameraPosition;
	FbxVector4 m_fbxv4CameraCenter;
	double m_fCameraRoll;
	int m_nCameraStatus = 1;
	int m_nCameraZoomMode = 0;
};

class CTrifordMeshDiffused :public CMesh
{
public:
	CTrifordMeshDiffused(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float fWidth = 2.0f, float fHeight = 2.0f, float fDepth = 2.0f);
	virtual ~CTrifordMeshDiffused();
};

class CCubeMeshTextured : public CMesh
{
public:
	CCubeMeshTextured(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float fWidth = 2.0f, float fHeight = 2.0f, float fDepth = 2.0f);
	virtual ~CCubeMeshTextured();
};

class ImageFile
{
private:
	int		m_nWidth;
	int		m_nHeight;
	BYTE* m_pData = NULL;
	

public:
	
	ImageFile(LPCTSTR name, int width, int height, bool flipY);
	~ImageFile(void);

	float GetPixel(int x, int z) { 
		return((float)m_pData[x + (z * m_nWidth)]); 
		//return((float)m_pData[x + ((m_nHeight - 1 - z) * m_nWidth)]);
	}
	BYTE GetPixelInRaw(int x, int z) {
		return m_pData[x + (z * m_nWidth)]; 
		//return m_pData[x + ((m_nHeight - 1 - z) * m_nWidth)];
	}
	void SetPixel(int x, int z, BYTE nPixel) { m_pData[x + (z * m_nWidth)] = nPixel; }
	BYTE* GetData() { return(m_pData); }
	int GetWidth() { return(m_nWidth); }
	int GetHeight() { return(m_nHeight); }
};

class GridMesh : public CMesh
{
protected:
	int xlength, zlength;
	float* mheights = NULL;
	XMFLOAT3 size = XMFLOAT3(1.0f, 1.0f, 1.0f);
public:
	float getData(int x, int z) { return mheights[x * zlength + z]; }
	GridMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, int xStart, int zStart, int xlen, int zlen, XMFLOAT3 scale, ImageFile* file);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CMeshFromFbx
{
public:
	CMeshFromFbx(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, int nVertices, XMFLOAT4* pPositions, int nIndices, int* pnIndices, int(*pnSkinningIndices)[4], float(*pfSkinningWeights)[4], int nLinkNodes, XMFLOAT4X4* pxmf4x4VertextToLinkNodes);
	virtual ~CMeshFromFbx();

private:
	int								m_nReferences = 0;

public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }

protected:
	D3D12_PRIMITIVE_TOPOLOGY		m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT							m_nSlot = 0;
	UINT							m_nOffset = 0;

protected:
	int								m_nVertices = 0;

	ID3D12Resource* m_pd3dPositionBuffer = NULL;
	ID3D12Resource* m_pd3dPositionUploadBuffer = NULL;
	D3D12_VERTEX_BUFFER_VIEW		m_d3dPositionBufferView;

	ID3D12Resource* m_pd3dBoneIndexBuffer = NULL;
	ID3D12Resource* m_pd3dBoneIndexUploadBuffer = NULL;
	D3D12_VERTEX_BUFFER_VIEW		m_d3dBoneIndexBufferView;

	ID3D12Resource* m_pd3dBoneWeightBuffer = NULL;
	ID3D12Resource* m_pd3dBoneWeightUploadBuffer = NULL;
	D3D12_VERTEX_BUFFER_VIEW		m_d3dBoneWeightBufferView;

	int								m_nIndices = 0;

	ID3D12Resource* m_pd3dIndexBuffer = NULL;
	ID3D12Resource* m_pd3dIndexUploadBuffer = NULL;
	D3D12_INDEX_BUFFER_VIEW			m_d3dIndexBufferView;

public:
	int								m_nLinkNodes = 0; //Skinning Bones
	XMFLOAT4X4* m_pxmf4x4VertextToLinkNodes = NULL;
	ID3D12Resource* m_pd3dcbVertextToLinkNodes = NULL; //Bone Offset Transforms
	XMFLOAT4X4* m_pcbxmf4x4MappedVertextToLinkNodes = NULL;

public:
	virtual void ReleaseUploadBuffers();
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList);
};
