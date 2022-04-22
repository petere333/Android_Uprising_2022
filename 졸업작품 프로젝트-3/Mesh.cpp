//-----------------------------------------------------------------------------
// File: CGameObject.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "Mesh.h"
#include "Object.h"

CMesh::CMesh(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList)
{
}

CMesh::~CMesh()
{
	if (m_pd3dPositionBuffer) m_pd3dPositionBuffer->Release();
	if (m_pd3dTextureBuffer) m_pd3dTextureBuffer->Release();

	if (m_nSubMeshes > 0)
	{
		for (int i = 0; i < m_nSubMeshes; i++)
		{
			if (m_ppd3dSubSetIndexBuffers[i]) m_ppd3dSubSetIndexBuffers[i]->Release();
			if (m_ppnSubSetIndices[i]) delete[] m_ppnSubSetIndices[i];
		}
		if (m_ppd3dSubSetIndexBuffers) delete[] m_ppd3dSubSetIndexBuffers;
		if (m_pd3dSubSetIndexBufferViews) delete[] m_pd3dSubSetIndexBufferViews;

		if (m_pnSubSetIndices) delete[] m_pnSubSetIndices;
		if (m_ppnSubSetIndices) delete[] m_ppnSubSetIndices;
	}

	if (m_pxmf3Positions) delete[] m_pxmf3Positions;
	if (m_pxmf2UVs) delete[] m_pxmf2UVs;
}

void CMesh::ReleaseUploadBuffers()
{
	if (m_pd3dPositionUploadBuffer) m_pd3dPositionUploadBuffer->Release();
	m_pd3dPositionUploadBuffer = NULL;

	if ((m_nSubMeshes > 0) && m_ppd3dSubSetIndexUploadBuffers)
	{
		for (int i = 0; i < m_nSubMeshes; i++)
		{
			if (m_ppd3dSubSetIndexUploadBuffers[i])
			{
				m_ppd3dSubSetIndexUploadBuffers[i]->Release();
				m_ppd3dSubSetIndexUploadBuffers[i] = NULL;
			}
		}
		if (m_ppd3dSubSetIndexUploadBuffers) delete[] m_ppd3dSubSetIndexUploadBuffers;
		m_ppd3dSubSetIndexUploadBuffers = NULL;
	}
}

void CMesh::OnPreRender(ID3D12GraphicsCommandList *pd3dCommandList, void *pContext)
{
	D3D12_VERTEX_BUFFER_VIEW pVertexBufferViews[2] = { m_d3dPositionBufferView,  m_d3dTextureBufferView };
	pd3dCommandList->IASetVertexBuffers(m_nSlot, 2, pVertexBufferViews);
}

void CMesh::Render(ID3D12GraphicsCommandList *pd3dCommandList, int nSubSet)
{
	UpdateShaderVariables(pd3dCommandList);

	OnPreRender(pd3dCommandList, NULL);

	pd3dCommandList->IASetPrimitiveTopology(m_d3dPrimitiveTopology);
	
	if ((m_nSubMeshes > 0) && (nSubSet < m_nSubMeshes))
	{
		pd3dCommandList->IASetIndexBuffer(&(m_pd3dSubSetIndexBufferViews[nSubSet]));
		pd3dCommandList->DrawIndexedInstanced(m_pnSubSetIndices[nSubSet], 1, 0, 0, 0);
	}
	else
	{
		pd3dCommandList->DrawInstanced(m_nVertices, 1, m_nOffset, 0);
	}
}

void CMesh::OnPostRender(ID3D12GraphicsCommandList *pd3dCommandList, void *pContext)
{
}

void CMesh::LoadMeshFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, FILE *pInFile)
{
	char pstrToken[64] = { '\0' };
	BYTE nStrLength = 0;
	UINT nReads = 0;

	::ReadStringFromFile(pInFile, m_pstrMeshName);
	
	while(1)
	{
		::ReadStringFromFile(pInFile, pstrToken);

		if (!strcmp(pstrToken, "<Bounds>:"))
		{
			nReads = (UINT)::fread(&m_xmf3AABBCenter, sizeof(XMFLOAT3), 1, pInFile);
			nReads = (UINT)::fread(&m_xmf3AABBExtents, sizeof(XMFLOAT3), 1, pInFile);
		}
		else if (!strcmp(pstrToken, "<ControlPoints>:"))
		{
			m_nVertices = ::ReadUnsignedIntegerFromFile(pInFile);
			if (m_nVertices > 0)
			{
				m_nType |= VERTEXT_POSITION;
				m_pxmf3Positions = new XMFLOAT3[m_nVertices];

				
				nReads = (UINT)::fread(m_pxmf3Positions, sizeof(XMFLOAT3), m_nVertices, pInFile);

				m_pd3dPositionBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_pxmf3Positions, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

				m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
				m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
				m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;
				
			}
			
			
		}
		else if (!strcmp(pstrToken, "<UVs>:"))
		{
			int nuv = ::ReadUnsignedIntegerFromFile(pInFile);
			int n2 = ::ReadUnsignedIntegerFromFile(pInFile);
			char s1[30] = {'\0'};

			for (int i = 0; i < n2; ++i)
			{
				int n4 = ::ReadStringFromFile(pInFile, s1);
				int n3 = ::ReadUnsignedIntegerFromFile(pInFile);
				m_nType |= VERTEXT_TEXTURE;
				m_pxmf2UVs = new XMFLOAT2[nuv];
				nReads = (UINT)::fread(m_pxmf2UVs, sizeof(XMFLOAT2), nuv, pInFile);

				if (i == 0 && nuv > 0)
				{
					m_pd3dTextureBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_pxmf2UVs, sizeof(XMFLOAT2) * nuv, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

					m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
					m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
					m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * nuv;
				}
			}
		}
		else if (!strcmp(pstrToken, "<Normals>:"))
		{
			int nuv = ::ReadUnsignedIntegerFromFile(pInFile);
			int n2 = ::ReadUnsignedIntegerFromFile(pInFile);
			char s1[30] = { '\0' };
			n2 = ::ReadStringFromFile(pInFile, s1);
			n2 = ::ReadUnsignedIntegerFromFile(pInFile);
			if (nuv > 0)
			{
				m_nType |= VERTEXT_NORMAL;
				m_pxmf3Normals = new XMFLOAT3[nuv];
				nReads = (UINT)::fread(m_pxmf3Normals, sizeof(XMFLOAT3), nuv, pInFile);
				m_pd3dNormalBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_pxmf3Normals, sizeof(XMFLOAT3) * nuv, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dNormalUploadBuffer);

				m_d3dNormalBufferView.BufferLocation = m_pd3dNormalBuffer->GetGPUVirtualAddress();
				m_d3dNormalBufferView.StrideInBytes = sizeof(XMFLOAT3);
				m_d3dNormalBufferView.SizeInBytes = sizeof(XMFLOAT3) * nuv;
			}
		}
		else if (!strcmp(pstrToken, "<Tangents>:"))
		{
			int n = ::ReadUnsignedIntegerFromFile(pInFile);
			tangent = ::ReadUnsignedIntegerFromFile(pInFile);
		}
		else if (!strcmp(pstrToken, "<BiTangents>:"))
		{
			int n = ::ReadUnsignedIntegerFromFile(pInFile);
			bitangent = ::ReadUnsignedIntegerFromFile(pInFile);
		}
		else if (!strcmp(pstrToken, "<Polygons>:"))
		{
			int nPolygons = ::ReadIntegerFromFile(pInFile);
			for ( ; ; )
			{
				::ReadStringFromFile(pInFile, pstrToken);

				if (!strcmp(pstrToken, "<SubIndices>:"))
				{
					int nIndices = ::ReadIntegerFromFile(pInFile);
					m_nSubMeshes = ::ReadIntegerFromFile(pInFile);
					if (m_nSubMeshes == 0) m_nSubMeshes = 1;

					m_pnSubSetIndices = new int[m_nSubMeshes];
					m_ppnSubSetIndices = new UINT*[m_nSubMeshes];

					m_ppd3dSubSetIndexBuffers = new ID3D12Resource*[m_nSubMeshes];
					m_ppd3dSubSetIndexUploadBuffers = new ID3D12Resource*[m_nSubMeshes];
					m_pd3dSubSetIndexBufferViews = new D3D12_INDEX_BUFFER_VIEW[m_nSubMeshes];

					for (int i = 0; i < m_nSubMeshes; i++)
					{
						m_pnSubSetIndices[i] = 0;
						m_ppnSubSetIndices[i] = NULL;
						m_ppd3dSubSetIndexBuffers[i] = NULL;
						m_ppd3dSubSetIndexUploadBuffers[i] = NULL;

						::ReadStringFromFile(pInFile, pstrToken);

						if (!strcmp(pstrToken, "<SubIndex>:"))
						{
							int nIndex = ::ReadIntegerFromFile(pInFile);
							m_pnSubSetIndices[i] = ::ReadIntegerFromFile(pInFile);
							if (m_pnSubSetIndices[i] > 0)
							{
								m_ppnSubSetIndices[i] = new UINT[m_pnSubSetIndices[i]];
								nReads = (UINT)::fread(m_ppnSubSetIndices[i], sizeof(UINT), m_pnSubSetIndices[i], pInFile);

								m_ppd3dSubSetIndexBuffers[i] = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_ppnSubSetIndices[i], sizeof(UINT) * m_pnSubSetIndices[i], D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_INDEX_BUFFER, &m_ppd3dSubSetIndexUploadBuffers[i]);

								m_pd3dSubSetIndexBufferViews[i].BufferLocation = m_ppd3dSubSetIndexBuffers[i]->GetGPUVirtualAddress();
								m_pd3dSubSetIndexBufferViews[i].Format = DXGI_FORMAT_R32_UINT;
								m_pd3dSubSetIndexBufferViews[i].SizeInBytes = sizeof(UINT) * m_pnSubSetIndices[i];
							}
						}
					}
				}
				else if (!strcmp(pstrToken, "</Polygons>"))
				{
					break;
				}
			}
		}
		else if (!strcmp(pstrToken, "</Mesh>"))
		{
			break;
		}
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////
//
CSkinnedMesh::CSkinnedMesh(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList) : CMesh(pd3dDevice, pd3dCommandList)
{
	m_d3dPrimitiveTopology = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

CSkinnedMesh::~CSkinnedMesh()
{
	if (m_pxmn4BoneIndices) delete[] m_pxmn4BoneIndices;
	if (m_pxmf4BoneWeights) delete[] m_pxmf4BoneWeights;

	if (m_pxmf4x4BindPoseBoneOffsets) delete[] m_pxmf4x4BindPoseBoneOffsets;
	if (m_pd3dcbBindPoseBoneOffsets) m_pd3dcbBindPoseBoneOffsets->Release();

	if (m_ppstrSkinningBoneNames) delete[] m_ppstrSkinningBoneNames;

	if (m_pd3dBoneIndexBuffer) m_pd3dBoneIndexBuffer->Release();
	if (m_pd3dBoneWeightBuffer) m_pd3dBoneWeightBuffer->Release();

	ReleaseShaderVariables();
}

void CSkinnedMesh::CreateShaderVariables(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList)
{
}

void CSkinnedMesh::UpdateShaderVariables(ID3D12GraphicsCommandList *pd3dCommandList)
{
	if (m_pd3dcbBindPoseBoneOffsets)
	{
		D3D12_GPU_VIRTUAL_ADDRESS d3dcbBoneOffsetsGpuVirtualAddress = m_pd3dcbBindPoseBoneOffsets->GetGPUVirtualAddress();
		pd3dCommandList->SetGraphicsRootConstantBufferView(4, d3dcbBoneOffsetsGpuVirtualAddress); //Skinned Bone Offsets
	}

	if (m_pd3dcbSkinningBoneTransforms)
	{
		D3D12_GPU_VIRTUAL_ADDRESS d3dcbBoneTransformsGpuVirtualAddress = m_pd3dcbSkinningBoneTransforms->GetGPUVirtualAddress();
		pd3dCommandList->SetGraphicsRootConstantBufferView(5, d3dcbBoneTransformsGpuVirtualAddress); //Skinned Bone Transforms

		for (int j = 0; j < m_nSkinningBones; j++)
		{
			XMStoreFloat4x4(&m_pcbxmf4x4MappedSkinningBoneTransforms[j], XMMatrixTranspose(XMLoadFloat4x4(&m_ppSkinningBoneFrameCaches[j]->m_xmf4x4World)));
		}
	}
}

void CSkinnedMesh::ReleaseShaderVariables()
{
}

void CSkinnedMesh::ReleaseUploadBuffers()
{
	CMesh::ReleaseUploadBuffers();

	if (m_pd3dBoneIndexUploadBuffer) m_pd3dBoneIndexUploadBuffer->Release();
	m_pd3dBoneIndexUploadBuffer = NULL;

	if (m_pd3dBoneWeightUploadBuffer) m_pd3dBoneWeightUploadBuffer->Release();
	m_pd3dBoneWeightUploadBuffer = NULL;
}

void CSkinnedMesh::PrepareSkinning(CGameObject *pModelRootObject)
{
//	m_ppSkinningBoneFrameCaches = new CGameObject*[m_nSkinningBones];
	for (int i = 0; i < m_nSkinningBones; i++)
	{
		m_ppSkinningBoneFrameCaches[i] = pModelRootObject->FindFrame(m_ppstrSkinningBoneNames[i]);
	}
}

void CSkinnedMesh::LoadSkinDeformationsFromFile(ID3D12Device *pd3dDevice, ID3D12GraphicsCommandList *pd3dCommandList, FILE *pInFile)
{
	char pstrToken[64] = { '\0' };
	BYTE nStrLength = 0;
	UINT nReads = 0;

	for ( ; ; )
	{
		::ReadStringFromFile(pInFile, pstrToken);
		if (!strcmp(pstrToken, "<BonesPerVertex>:"))
		{
			m_nBonesPerVertex = ::ReadIntegerFromFile(pInFile);
		}
		else if (!strcmp(pstrToken, "<Bounds>:"))
		{
			nReads = (UINT)::fread(&m_xmf3AABBCenter, sizeof(XMFLOAT3), 1, pInFile);
			nReads = (UINT)::fread(&m_xmf3AABBExtents, sizeof(XMFLOAT3), 1, pInFile);
		}
		else if (!strcmp(pstrToken, "<BoneNames>:"))
		{
			m_nSkinningBones = ::ReadIntegerFromFile(pInFile);
			if (m_nSkinningBones > 0)
			{
				m_ppstrSkinningBoneNames = new char[m_nSkinningBones][64];
				m_ppSkinningBoneFrameCaches = new CGameObject*[m_nSkinningBones];
				for (int i = 0; i < m_nSkinningBones; i++)
				{
					::ReadStringFromFile(pInFile, m_ppstrSkinningBoneNames[i]);
					m_ppSkinningBoneFrameCaches[i] = NULL;
				}
			}
		}
		else if (!strcmp(pstrToken, "<BoneOffsets>:"))
		{
			m_nSkinningBones = ::ReadIntegerFromFile(pInFile);
			if (m_nSkinningBones > 0)
			{
				m_pxmf4x4BindPoseBoneOffsets = new XMFLOAT4X4[m_nSkinningBones];
				nReads = (UINT)::fread(m_pxmf4x4BindPoseBoneOffsets, sizeof(XMFLOAT4X4), m_nSkinningBones, pInFile);

				UINT ncbElementBytes = (((sizeof(XMFLOAT4X4) * SKINNED_ANIMATION_BONES) + 255) & ~255); //256의 배수
				m_pd3dcbBindPoseBoneOffsets = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
				m_pd3dcbBindPoseBoneOffsets->Map(0, NULL, (void **)&m_pcbxmf4x4MappedBindPoseBoneOffsets);

				for (int i = 0; i < m_nSkinningBones; i++)
				{
					XMStoreFloat4x4(&m_pcbxmf4x4MappedBindPoseBoneOffsets[i], XMMatrixTranspose(XMLoadFloat4x4(&m_pxmf4x4BindPoseBoneOffsets[i])));
				}
			}
		}
		else if (!strcmp(pstrToken, "<BoneIndices>:"))
		{
			m_nType |= VERTEXT_BONE_INDEX_WEIGHT;

			m_nVertices = ::ReadIntegerFromFile(pInFile);
			if (m_nVertices > 0)
			{
				m_pxmn4BoneIndices = new XMINT4[m_nVertices];

				nReads = (UINT)::fread(m_pxmn4BoneIndices, sizeof(XMINT4), m_nVertices, pInFile);
				m_pd3dBoneIndexBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_pxmn4BoneIndices, sizeof(XMINT4) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dBoneIndexUploadBuffer);

				m_d3dBoneIndexBufferView.BufferLocation = m_pd3dBoneIndexBuffer->GetGPUVirtualAddress();
				m_d3dBoneIndexBufferView.StrideInBytes = sizeof(XMINT4);
				m_d3dBoneIndexBufferView.SizeInBytes = sizeof(XMINT4) * m_nVertices;
			}
		}
		else if (!strcmp(pstrToken, "<BoneWeights>:"))
		{
			m_nType |= VERTEXT_BONE_INDEX_WEIGHT;

			m_nVertices = ::ReadIntegerFromFile(pInFile);
			if (m_nVertices > 0)
			{
				m_pxmf4BoneWeights = new XMFLOAT4[m_nVertices];

				nReads = (UINT)::fread(m_pxmf4BoneWeights, sizeof(XMFLOAT4), m_nVertices, pInFile);
				m_pd3dBoneWeightBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_pxmf4BoneWeights, sizeof(XMFLOAT4) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dBoneWeightUploadBuffer);

				m_d3dBoneWeightBufferView.BufferLocation = m_pd3dBoneWeightBuffer->GetGPUVirtualAddress();
				m_d3dBoneWeightBufferView.StrideInBytes = sizeof(XMFLOAT4);
				m_d3dBoneWeightBufferView.SizeInBytes = sizeof(XMFLOAT4) * m_nVertices;
			}
		}
		else if (!strcmp(pstrToken, "</SkinDeformations>"))
		{
			break;
		}
	}
}

void CSkinnedMesh::OnPreRender(ID3D12GraphicsCommandList *pd3dCommandList, void *pContext)
{
	D3D12_VERTEX_BUFFER_VIEW pVertexBufferViews[4] = { m_d3dPositionBufferView, m_d3dBoneIndexBufferView, m_d3dBoneWeightBufferView,  m_d3dTextureBufferView };
	pd3dCommandList->IASetVertexBuffers(m_nSlot, 4, pVertexBufferViews);
}

CLoadedMesh::CLoadedMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, const char* vfile, const char* ifile) : CMesh(pd3dDevice, pd3dCommandList)
{
	if (ifile != NULL)
	{
		FILE* pf2 = fopen(ifile, "r");
		std::vector<int> indices;

		while (!feof(pf2))
		{
			int idx;
			fscanf(pf2, "%d, ", &idx);
			indices.push_back(idx);
		}
		m_pnSubSetIndices = new int[1];
		m_ppnSubSetIndices = new UINT*[1];
		m_ppnSubSetIndices[0] = new UINT[indices.size()];

		for (int i = 0; i < indices.size(); ++i)
		{
			m_ppnSubSetIndices[0][i] = indices[i];
		}

		m_pnSubSetIndices[0] = indices.size();
		m_nSubMeshes = 1;
		m_ppd3dSubSetIndexBuffers = new ID3D12Resource*[1];
		m_ppd3dSubSetIndexUploadBuffers = new ID3D12Resource * [1];
		m_ppd3dSubSetIndexUploadBuffers[0] = NULL;
		m_ppd3dSubSetIndexBuffers[0] = ::CreateBufferResource(pd3dDevice, pd3dCommandList, m_ppnSubSetIndices[0], sizeof(UINT) * m_pnSubSetIndices[0], D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_INDEX_BUFFER, &m_ppd3dSubSetIndexUploadBuffers[0]);

		m_pd3dSubSetIndexBufferViews = new D3D12_INDEX_BUFFER_VIEW[1];

		m_pd3dSubSetIndexBufferViews[0].BufferLocation = m_ppd3dSubSetIndexBuffers[0]->GetGPUVirtualAddress();
		m_pd3dSubSetIndexBufferViews[0].Format = DXGI_FORMAT_R32_UINT;
		m_pd3dSubSetIndexBufferViews[0].SizeInBytes = sizeof(UINT) * m_pnSubSetIndices[0];

		fclose(pf2);
	}

	FILE* pf = fopen(vfile, "r");


	std::vector<XMFLOAT3> pos;
	std::vector<XMFLOAT2> uv;

	while (!feof(pf))
	{
		float x, y, z;
		float u, v;
		fscanf(pf, "(%f,  %f,  %f),  (%f,  %f)\n", &x, &y, &z, &u, &v);
		pos.push_back(XMFLOAT3(x, y, z));
		uv.push_back(XMFLOAT2(u, v));
	}

	XMFLOAT3* posData = new XMFLOAT3[pos.size()];
	XMFLOAT2* uvData = new XMFLOAT2[pos.size()];
	for (int i = 0; i < pos.size(); ++i)
	{
		posData[i] = pos[i];
		uvData[i] = uv[i];
	}


	m_nVertices = pos.size();

	int posStride = sizeof(XMFLOAT3);
	int uvStride = sizeof(XMFLOAT2);
	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_pd3dPositionBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, posData, posStride * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = posStride;
	m_d3dPositionBufferView.SizeInBytes = posStride * m_nVertices;

	m_pd3dTextureBuffer = ::CreateBufferResource(pd3dDevice, pd3dCommandList, uvData, uvStride * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = uvStride;
	m_d3dTextureBufferView.SizeInBytes = uvStride * m_nVertices;



	fclose(pf);

}

CLoadedMesh::~CLoadedMesh() {}

GridMesh::GridMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float width, float height) : CMesh(pd3dDevice, pd3dCommandList)
{


	int size = static_cast<int>((width / 2.5f) * (height / 2.5f)) * 6;
	XMFLOAT3* pos = new XMFLOAT3[size];
	XMFLOAT2* uv = new XMFLOAT2[size];

	int x = static_cast<int>(width / 2.5f);
	int y = static_cast<int>(height / 2.5f);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y * 6; j += 6)
		{
			pos[i * y * 6 + j] = XMFLOAT3(i * 2.5f, 0.0f, j / 6 * 2.5f);
			uv[i * y * 6 + j] = XMFLOAT2(0.0f, 0.0f);

			pos[i * y * 6 + j + 1] = XMFLOAT3(i * 2.5f, 0.0f, j / 6 * 2.5f + 2.5f);
			uv[i * y * 6 + j + 1]= XMFLOAT2(0.0f, 1.0f);
			pos[i * y * 6 + j + 2] = XMFLOAT3(i * 2.5f + 2.5f, 0.0f, j / 6 * 2.5f + 2.5f);
			uv[i * y * 6 + j + 2] = XMFLOAT2(1.0f, 1.0f);

			pos[i * y * 6 + j + 3] = XMFLOAT3(i * 2.5f, 0.0f, j / 6 * 2.5f);
			uv[i * y * 6 + j + 3] = XMFLOAT2(0.0f, 0.0f);
			pos[i * y * 6 + j + 4] = XMFLOAT3(i * 2.5f + 2.5f, 0.0f, j / 6 * 2.5f + 2.5f);
			uv[i * y * 6 + j + 4] = XMFLOAT2(1.0f, 1.0f);
			pos[i * y * 6 + j + 5] = XMFLOAT3(i * 2.5f + 2.5f, 0.0f, j / 6 * 2.5f);
			uv[i * y * 6 + j + 5]= XMFLOAT2(1.0f, 0.0f);
		}
	}




	m_nVertices = size;
	
	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3)* m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;


	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}

GridMesh::~GridMesh()
{}

WallMeshVertical::WallMeshVertical(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float width, float height) : CMesh(pd3dDevice, pd3dCommandList)
{
	int size = static_cast<int>((width / 2.5f) * (height / 2.5f)) * 6;

	XMFLOAT3* pos = new XMFLOAT3[size];
	XMFLOAT2* uv = new XMFLOAT2[size];

	int y = static_cast<int>(width / 2.5f);
	int x = static_cast<int>(height / 2.5f);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y * 6; j += 6)
		{
			pos[i * y * 6 + j] = XMFLOAT3(0.0f, i * 2.5f, j / 6 * 2.5f);
			uv[i * y * 6 + j] = XMFLOAT2(0.0f, 0.0f);
			pos[i * y * 6 + j + 1] = XMFLOAT3(0.0f, i * 2.5f, j / 6 * 2.5f + 2.5f);
			uv[i * y * 6 + j + 1] = XMFLOAT2(0.0f, 1.0f);
			pos[i * y * 6 + j + 2] = XMFLOAT3(0.0f, i * 2.5f + 2.5f, j / 6 * 2.5f + 2.5f); 
			uv[i * y * 6 + j + 2] = XMFLOAT2(1.0f, 1.0f);
			 
			pos[i * y * 6 + j + 3] = XMFLOAT3(0.0f, i * 2.5f, j / 6 * 2.5f); 
			uv[i * y * 6 + j + 3] = XMFLOAT2(0.0f, 0.0f);
			pos[i * y * 6 + j + 4] = XMFLOAT3(0.0f, i * 2.5f + 2.5f, j / 6 * 2.5f + 2.5f); 
			uv[i * y * 6 + j + 4] = XMFLOAT2(1.0f, 1.0f);
			pos[i * y * 6 + j + 5] = XMFLOAT3(0.0f, i * 2.5f + 2.5f, j / 6 * 2.5f); 
			uv[i * y * 6 + j + 5] = XMFLOAT2(1.0f, 0.0f);
		}
	}
	m_nVertices = size;
	
	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;


	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;


	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}
WallMeshVertical::~WallMeshVertical() {}

WallMeshHorizontal::WallMeshHorizontal(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float width, float height) :CMesh(pd3dDevice, pd3dCommandList)
{
	int size = static_cast<int>((width / 2.5f) * (height / 2.5f)) * 6;
	
	XMFLOAT3* pos = new XMFLOAT3[size];
	XMFLOAT2* uv = new XMFLOAT2[size];

	int x = static_cast<int>(width / 2.5f);
	int y = static_cast<int>(height / 2.5f);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y * 6; j += 6)
		{
			pos[i * y * 6 + j] = XMFLOAT3(i * 2.5f, j / 6 * 2.5f, 0.0f);
			uv[i * y * 6 + j] = XMFLOAT2(0.0f, 0.0f);

			pos[i * y * 6 + j + 1] = XMFLOAT3(i * 2.5f, j / 6 * 2.5f + 2.5f, 0.0f);
			uv[i * y * 6 + j + 1] = XMFLOAT2(0.0f, 1.0f);

			pos[i * y * 6 + j + 2] = XMFLOAT3(i * 2.5f + 2.5f, j / 6 * 2.5f + 2.5f, 0.0f); 
			uv[i * y * 6 + j + 2] = XMFLOAT2(1.0f, 1.0f);

			 
			pos[i * y * 6 + j + 3] = XMFLOAT3(i * 2.5f, j / 6 * 2.5f, 0.0f); 
			uv[i * y * 6 + j + 3] = XMFLOAT2(0.0f, 0.0f);

			pos[i * y * 6 + j + 4] = XMFLOAT3(i * 2.5f + 2.5f, j / 6 * 2.5f + 2.5f, 0.0f);
			uv[i * y * 6 + j + 4] = XMFLOAT2(1.0f, 1.0f);

			pos[i * y * 6 + j + 5] = XMFLOAT3(i * 2.5f + 2.5f, j / 6 * 2.5f, 0.0f);
			uv[i * y * 6 + j + 5] = XMFLOAT2(1.0f, 0.0f);
		}
	}
	m_nVertices = size;
	
	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;


	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}
WallMeshHorizontal::~WallMeshHorizontal() {}

WallDecorationMesh::WallDecorationMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float width, float height, float wallW, float wallH, int direction, int nDecos, bool upper) : CMesh(pd3dDevice, pd3dCommandList)
{
	float ws = width * -0.5f;
	float we = width * 0.5f;

	float hs = height * -0.5f;
	float he = height * 0.5f;

	float weight;
	if (upper == true)
	{
		weight = 0.001;
	}
	else
	{
		weight = -0.001;
	}
	m_nVertices = nDecos*6;

	XMFLOAT3* pos = new XMFLOAT3[m_nVertices];
	XMFLOAT2* uv = new XMFLOAT2[m_nVertices];

	for (int i = 0; i < m_nVertices; i+=6)
	{
		float hor = static_cast<float>(rand() % 100) / 100.0f * wallW;
		float ver = static_cast<float>(rand() % 100) / 100.0f * wallH;
		float wstart = ws + hor;
		float wend = we + hor;
		float hstart = hs + ver;
		float hend = he + ver;

		if (direction == 1)//xz평면, 게임 시작 시 캐릭터 위치 기준 바닥면
		{
			
			pos[i] = XMFLOAT3(wstart, weight, hstart);
			pos[i + 1] = XMFLOAT3(wstart, weight, hend);
			pos[i + 2] = XMFLOAT3(wend, weight, hend);

			pos[i + 3] = XMFLOAT3(wstart, weight, hstart);
			pos[i + 4] = XMFLOAT3(wend, weight, hend);
			pos[i + 5] = XMFLOAT3(wend, weight, hstart);
		}
		else if (direction == 2)//xy평면, 게임 시작 시 캐릭터 위치 기준 앞뒷면
		{
			pos[i] = XMFLOAT3(wstart, hstart, weight);
			pos[i + 1] = XMFLOAT3(wstart, hend, weight);
			pos[i + 2] = XMFLOAT3(wend, hend, weight);

			pos[i + 3] = XMFLOAT3(wstart, hstart, weight);
			pos[i + 4] = XMFLOAT3(wend, hend, weight);
			pos[i + 5] = XMFLOAT3(wend, hstart, weight);
		}
		else if (direction == 3) //yz평면, 게임 시작 시 캐릭터 위치 기준 옆면
		{
			pos[i] = XMFLOAT3(weight, wstart, hstart);
			pos[i + 1] = XMFLOAT3(weight, wstart, hend);
			pos[i + 2] = XMFLOAT3(weight, wend, hend);

			pos[i + 3] = XMFLOAT3(weight, wstart, hstart);
			pos[i + 4] = XMFLOAT3(weight, wend, hend);
			pos[i + 5] = XMFLOAT3(weight, wend, hstart);
		}
		uv[i] = XMFLOAT2(0.0f, 0.0f);
		uv[i + 1] = XMFLOAT2(0.0f, 1.0f);
		uv[i + 2] = XMFLOAT2(1.0f, 1.0f);

		uv[i + 3] = XMFLOAT2(0.0f, 0.0f);
		uv[i + 4] = XMFLOAT2(1.0f, 1.0f);
		uv[i + 5] = XMFLOAT2(1.0f, 0.0f);
	}

	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;

	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}
WallDecorationMesh::~WallDecorationMesh() {}

RectMesh::RectMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float width, float height) : CMesh(pd3dDevice, pd3dCommandList)
{
	m_nVertices = 6;

	float ws = width * -0.5f;
	float we = width * 0.5f;

	float hs = height * -0.5f;
	float he = height * 0.5f;

	XMFLOAT3* pos = new XMFLOAT3[6];
	XMFLOAT2* uv = new XMFLOAT2[6];

	pos[0] = XMFLOAT3(ws, 0.02f, hs);
	pos[1] = XMFLOAT3(ws, 0.02f, he);
	pos[2] = XMFLOAT3(we, 0.02f, he);

	pos[3] = XMFLOAT3(ws, 0.02f, hs);
	pos[4] = XMFLOAT3(we, 0.02f, he);
	pos[5] = XMFLOAT3(we, 0.02f, hs);

	uv[0] = XMFLOAT2(0.0f, 0.0f);
	uv[1] = XMFLOAT2(0.0f, 1.0f);
	uv[2] = XMFLOAT2(1.0f, 1.0f);

	uv[3] = XMFLOAT2(0.0f, 0.0f);
	uv[4] = XMFLOAT2(1.0f, 1.0f);
	uv[5] = XMFLOAT2(1.0f, 0.0f);

	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;

	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}

RectMesh::~RectMesh(){}

CCubeMeshTextured::CCubeMeshTextured(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float fWidth, float fHeight, float fDepth) : CMesh(pd3dDevice, pd3dCommandList)
{
	m_nVertices = 36;
	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	float fx = fWidth * 0.5f, fy = fHeight * 0.5f, fz = fDepth * 0.5f;

	XMFLOAT3* pos = new XMFLOAT3[36];
	XMFLOAT2* uv = new XMFLOAT2[36];

	
	int i = 0;
	//앞면
	pos[i++]= XMFLOAT3(-fx, +fy, -fz);
	pos[i++]= XMFLOAT3(+fx, +fy, -fz);
	pos[i++]= XMFLOAT3(+fx, -fy, -fz);
						 
	pos[i++]= XMFLOAT3(-fx, +fy, -fz);
	pos[i++]= XMFLOAT3(+fx, -fy, -fz);
	pos[i++]= XMFLOAT3(-fx, -fy, -fz);
	
	pos[i++]= XMFLOAT3(-fx, +fy, +fz);
	pos[i++]= XMFLOAT3(+fx, +fy, +fz);
	pos[i++]= XMFLOAT3(+fx, +fy, -fz);
	
	pos[i++]= XMFLOAT3(-fx, +fy, +fz);
	pos[i++]= XMFLOAT3(+fx, +fy, -fz);
	pos[i++]= XMFLOAT3(-fx, +fy, -fz);
						 
	pos[i++]= XMFLOAT3(-fx, -fy, +fz);
	pos[i++]= XMFLOAT3(+fx, -fy, +fz);
	pos[i++]= XMFLOAT3(+fx, +fy, +fz);
	
	pos[i++]= XMFLOAT3(-fx, -fy, +fz);
	pos[i++]= XMFLOAT3(+fx, +fy, +fz);
	pos[i++]= XMFLOAT3(-fx, +fy, +fz);
	
	pos[i++]= XMFLOAT3(-fx, -fy, -fz);
	pos[i++]= XMFLOAT3(+fx, -fy, -fz);
	pos[i++]= XMFLOAT3(+fx, -fy, +fz);
	
	pos[i++]= XMFLOAT3(-fx, -fy, -fz);
	pos[i++]= XMFLOAT3(+fx, -fy, +fz);
	pos[i++]= XMFLOAT3(-fx, -fy, +fz);
	
	pos[i++]= XMFLOAT3(-fx, +fy, +fz);
	pos[i++]= XMFLOAT3(-fx, +fy, -fz);
	pos[i++]= XMFLOAT3(-fx, -fy, -fz);
	
	pos[i++]= XMFLOAT3(-fx, +fy, +fz);
	pos[i++]= XMFLOAT3(-fx, -fy, -fz);
	pos[i++]= XMFLOAT3(-fx, -fy, +fz);
	
	pos[i++]= XMFLOAT3(+fx, +fy, -fz);
	pos[i++]= XMFLOAT3(+fx, +fy, +fz);
	pos[i++]= XMFLOAT3(+fx, -fy, +fz);
	
	pos[i++]= XMFLOAT3(+fx, +fy, -fz);
	pos[i++]= XMFLOAT3(+fx, -fy, +fz);
	pos[i++]= XMFLOAT3(+fx, -fy, -fz);

	i = 0;

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	uv[i++] = XMFLOAT2(0.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	uv[i++] = XMFLOAT2(0.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	uv[i++] = XMFLOAT2(0.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	uv[i++] = XMFLOAT2(0.0f, 1.0f);

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	
	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	uv[i++] = XMFLOAT2(0.0f, 1.0f);
	
	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	

	uv[i++] = XMFLOAT2(0.0f, 0.0f);
	uv[i++] = XMFLOAT2(1.0f, 1.0f);
	uv[i++] = XMFLOAT2(0.0f, 1.0f);

	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;

	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}

CCubeMeshTextured::~CCubeMeshTextured()
{
}

ParticleMesh::ParticleMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList) : CMesh(pd3dDevice, pd3dCommandList)
{
	m_nVertices = 12;
	
	XMFLOAT3* pos = new XMFLOAT3[12];
	XMFLOAT2* uv = new XMFLOAT2[12];

	pos[0] = XMFLOAT3(-0.05f, -0.05f, -0.05f);
	pos[1] = XMFLOAT3(0.0f, -0.05f, 0.05f);
	pos[2] = XMFLOAT3(0.05f, -0.05f, -0.05f);
	uv[0] = XMFLOAT2(0.0f, 0.0f);
	uv[1] = XMFLOAT2(0.5f, 1.0f);
	uv[2] = XMFLOAT2(1.0f, 0.0f);

	pos[3] = XMFLOAT3(-0.05f, -0.05f, -0.05f);
	pos[4] = XMFLOAT3(0.0f, 0.05f, 0.0f);
	pos[5] = XMFLOAT3(0.0f, -0.05f, 0.05f);
	uv[3] = XMFLOAT2(0.0f, 0.0f);
	uv[4] = XMFLOAT2(0.5f, 1.0f);
	uv[5] = XMFLOAT2(1.0f, 0.0f);

	pos[6] = XMFLOAT3(0.0f, -0.05f, 0.05f);
	pos[7] = XMFLOAT3(0.0f, 0.05f, 0.0f);
	pos[8] = XMFLOAT3(0.05f, -0.05f, -0.05f);
	uv[6] = XMFLOAT2(0.0f, 0.0f);
	uv[7] = XMFLOAT2(0.5f, 1.0f);
	uv[8] = XMFLOAT2(1.0f, 0.0f);

	pos[9] = XMFLOAT3(0.05f, -0.05f, -0.05f);
	pos[10] = XMFLOAT3(0.0f, 0.05f, 0.0f);
	pos[11] = XMFLOAT3(-0.05f, -0.05f, -0.05f);
	uv[9] = XMFLOAT2(0.0f, 0.0f);
	uv[10] = XMFLOAT2(0.5f, 1.0f);
	uv[11] = XMFLOAT2(1.0f, 0.0f);

	m_nOffset = 0;
	m_nSlot = 0;
	m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_pd3dPositionBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, pos, sizeof(XMFLOAT3) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dPositionUploadBuffer);

	m_d3dPositionBufferView.BufferLocation = m_pd3dPositionBuffer->GetGPUVirtualAddress();
	m_d3dPositionBufferView.StrideInBytes = sizeof(XMFLOAT3);
	m_d3dPositionBufferView.SizeInBytes = sizeof(XMFLOAT3) * m_nVertices;

	m_pd3dTextureBuffer = CreateBufferResource(pd3dDevice, pd3dCommandList, uv, sizeof(XMFLOAT2) * m_nVertices, D3D12_HEAP_TYPE_DEFAULT, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, &m_pd3dTextureUploadBuffer);

	m_d3dTextureBufferView.BufferLocation = m_pd3dTextureBuffer->GetGPUVirtualAddress();
	m_d3dTextureBufferView.StrideInBytes = sizeof(XMFLOAT2);
	m_d3dTextureBufferView.SizeInBytes = sizeof(XMFLOAT2) * m_nVertices;
}
ParticleMesh::~ParticleMesh(){}