#pragma once
#pragma once
#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "PlayerShader.h"
#include "EnemyShader.h"

class CharShadow : public CShader
{
public:
	CharShadow(ResourceManager* r);
	virtual ~CharShadow();

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
	RectMesh* mesh=NULL;
	RectMesh* mBlunt = NULL;
	RectMesh* mBazuka = NULL;
	RectMesh* mIdle = NULL;
	RectMesh* mRadioIdle = NULL;
	std::vector<XMFLOAT3> pp;
	std::vector<XMFLOAT3> ep;
	
	void animate(PlayerShader* ps, EnemyShader* es, int);
	

	std::vector<CGameObject*>	op;
	std::vector<float> pRot;
	std::vector<float> pElapsed;
	std::vector<CGameObject*>	oe;
	std::vector<bool> erased;
	ResourceManager* rm;
};