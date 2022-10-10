#pragma once

#include "Shader.h"
#include "ResourceManager.h"


class PlayerShader : public CShader
{
public:
	PlayerShader(ResourceManager* r);
	virtual ~PlayerShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, float t, ID3D12DescriptorHeap* heap);

	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	void addPlayer(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, XMFLOAT3 pos, ID3D12RootSignature* sig);


public:
	
	std::vector<PlayerObject*>	objects;
	ResourceManager* rm;
public:
	std::vector<XMFLOAT3> getPlayerLocation();
};