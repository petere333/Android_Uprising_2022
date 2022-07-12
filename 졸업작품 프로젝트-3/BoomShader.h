#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"
#include "ParticleShader.h"
#include "EnemyShader.h"

class BoomShader : public CShader
{
public:
	BoomShader(ResourceManager* r, ParticleShader* p, EnemyShader* e);
	virtual ~BoomShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);

	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	void animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ParticleShader* part);

public:

	CLoadedMesh* boomMesh = NULL;

	ParticleShader* part;
	EnemyShader* enemy;
	std::vector<BoomObject*>	objects;
	
	ResourceManager* rm;
};