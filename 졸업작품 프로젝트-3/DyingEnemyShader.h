#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"

class DyingEnemyShader : public CShader
{
public:
	DyingEnemyShader(ResourceManager* r);
	virtual ~DyingEnemyShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);
	void animate();
	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:

	std::vector<CLoadedMesh*> enemyBluntDie;
	std::vector<CLoadedMesh*> enemyGunDie;
public:
	
	std::vector<int> type;
	std::vector<chrono::time_point<chrono::system_clock>> created;
	std::vector<CGameObject*>	objects;
	std::vector<CGameObject*> shadows;
	ResourceManager* rm;
};