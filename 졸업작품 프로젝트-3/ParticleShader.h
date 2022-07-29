#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"

class ParticleShader : public CShader
{
public:
	ParticleShader(ResourceManager* r, ID3D12Device* device, ID3D12GraphicsCommandList* list);
	virtual ~ParticleShader();

	virtual void BuildObjects();
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);

	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	ID3D12Device* pd3dDevice; 
	ID3D12GraphicsCommandList* pd3dCommandList;

	void createParticles(int type, int count, XMFLOAT3 pos, ID3D12Device* device, ID3D12GraphicsCommandList* list, float, float);

public:
	ParticleMesh* partMesh = NULL;
	std::vector<ParticleObject*>	objects;

	ResourceManager* rm;
};