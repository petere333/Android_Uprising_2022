#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"

class TerrainShader2_2 : public CShader
{
public:
	TerrainShader2_2(ResourceManager* r);
	virtual ~TerrainShader2_2();

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


public:
	std::vector<Obj> data;

	int nBox;
	int nStairs;
	BoundBox* stairsWorld;
	BoundBox* boxesWorld;

	std::vector<CGameObject*>	objects;

	ResourceManager* rm;
};