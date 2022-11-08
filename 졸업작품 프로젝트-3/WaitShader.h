#pragma once
#pragma once



#include "Shader.h"
#include "ResourceManager.h"

class WaitShader : public CShader
{
public:
	WaitShader(ResourceManager* r);
	virtual ~WaitShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);
	virtual void Animate(CCamera* cam, PlayerInfoManager* info);
	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();
	virtual D3D12_DEPTH_STENCIL_DESC CreateDepthStencilState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	std::vector<UIObject*>	objects;
	std::vector<CubeMeshOffset*> meshes;
	std::vector<CubeMeshOffset*> meshesRev;
	ResourceManager* rm;
	
	int selectedStage;
	int selectedMode;
	float amp_melee = 1.0f;
	float amp_ranged = 1.0f;
	float amp_radio = 1.0f;
	chrono::time_point<chrono::system_clock> lastNotify;
};