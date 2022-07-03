#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"

class TerrainShader1_2 : public CShader
{
public:
	TerrainShader1_2(ResourceManager* r);
	virtual ~TerrainShader1_2();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* sig);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, float elapsed);

	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

	void animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float elapsed);

public:


public:
	std::vector<Obj> data;
	
	int nBox;
	int nStairs;
	BoundBox* stairsWorld;
	BoundBox* boxesWorld;

	std::vector<CGameObject*>	objects;

	ResourceManager* rm;

	bool animStart = false;

	chrono::time_point<chrono::system_clock> productCreated[5];

	CLoadedMesh* goodsMesh = NULL;

	std::vector<CGameObject*> products;
	std::vector<BoundBox*> boxGoods;
	std::vector<chrono::time_point<chrono::system_clock>> lastMove;
};