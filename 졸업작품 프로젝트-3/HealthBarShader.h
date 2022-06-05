#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"

class HealthBarShader : public CShader
{
public:
	HealthBarShader(ResourceManager* r);
	virtual ~HealthBarShader();
	
	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, std::vector<XMFLOAT3> pos, std::vector<int>);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);
	virtual void Animate(CCamera* cam, std::vector<XMFLOAT3> pos, std::vector<int>);
	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();
	virtual D3D12_DEPTH_STENCIL_DESC CreateDepthStencilState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	std::vector<CGameObject*>	objects;
	ResourceManager* rm;
	std::vector<XMFLOAT3> enemyPos;
	std::vector<int> enemyHealth;

	UIMesh** hp = NULL;
	UIMesh** hpReversed = NULL;

		
};