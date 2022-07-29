#pragma once

#include "Shader.h"
#include "ResourceManager.h"
#include "LevelLoader.h"
#include "ParticleShader.h"
#include "PlayerShader.h"
#include "DyingEnemyShader.h"
class EnemyShader : public CShader
{
public:
	EnemyShader(ResourceManager* r, float**, float**, float**, float**, float**, float**);
	virtual ~EnemyShader();
	
	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, ID3D12RootSignature* sig);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, float t, ID3D12DescriptorHeap* heap);

	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	int mhp = 20;
	int rhp = 10;
	float mdur = 0.833333f;
	float mrange = 1.0f;
	float rrange = 12.0f;
	float rdur = 0.2f;
	
	float** height11, **height12, **height13, **height21, **height22, **height23;


public:
	std::vector<EnemyObject*>	objects;
	

	ResourceManager* rm;



public:
	std::vector<XMFLOAT3> getEnemyPosition();
	std::vector<int> getHealthRate();

	void animate(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList, float elapsed, vector<XMFLOAT3>, PlayerShader*, ParticleShader*, DyingEnemyShader*, ID3D12RootSignature* sig);

	void restart();
};

typedef struct Line
{
	XMFLOAT3 start, end;
}Line;

typedef struct XYZPlane
{
	XMFLOAT3 normal;
	float pos;
}XYZPlane;

XMFLOAT3 getIntersectPoint(Line line, XYZPlane plane);