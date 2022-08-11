#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"
#include "PlayerShader.h"

class DropItemShader : public CShader
{
public:
	DropItemShader(ResourceManager* r);
	virtual ~DropItemShader();

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
	void animate(PlayerShader* ps);

	void addItem(int type, XMFLOAT3 pos);

public:
	CLoadedMesh* capacity = NULL;
	CLoadedMesh* booster = NULL;
	CLoadedMesh* power = NULL;
	CLoadedMesh* hard = NULL;
	CLoadedMesh* precision = NULL;
	std::vector<float> rotation;
	std::vector<CGameObject*>	objects;
	std::vector<int> type;
	ResourceManager* rm;

};