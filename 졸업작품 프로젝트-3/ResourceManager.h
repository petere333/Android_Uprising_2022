#pragma once

#include "Object.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void Init(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void BuildData(ID3D12RootSignature* m_pd3dGraphicsRootSignature);


	void createSound();
	void createTextures();
	void createModels(ID3D12RootSignature* m_pd3dGraphicsRootSignature);

	void createSRV(ID3D12Device* pd3dDevice, int nConstantBufferViews, int nShaderResourceViews);
	void CreateShaderResourceViews(ID3D12Device* pd3dDevice, CTexture* pTexture, UINT nDescriptorHeapIndex, UINT nRootParameterStartIndex);
	
public:
	ID3D12DescriptorHeap* m_pd3dCbvSrvDescriptorHeap = NULL;

	D3D12_CPU_DESCRIPTOR_HANDLE			m_d3dCbvCPUDescriptorStartHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE			m_d3dCbvGPUDescriptorStartHandle;
	D3D12_CPU_DESCRIPTOR_HANDLE			m_d3dSrvCPUDescriptorStartHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE			m_d3dSrvGPUDescriptorStartHandle;

	D3D12_CPU_DESCRIPTOR_HANDLE			m_d3dSrvCPUDescriptorNextHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE			m_d3dSrvGPUDescriptorNextHandle;

public:

	ID3D12Device* pd3dDevice; 
	ID3D12GraphicsCommandList* pd3dCommandList;


	std::vector<CTexture*> textures;
	std::vector<CTexture*> normals;

	std::vector<CMaterial*> materials;



	std::vector<CSound*> bgms;
	std::vector<CSound*> effects;

	std::vector<CLoadedModelInfo*> playerModels;
	std::vector<CLoadedModelInfo*> enemyModels;
};