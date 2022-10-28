#pragma once



#include "Shader.h"
#include "ResourceManager.h"
#include "PlayerShader.h"

class StageSelectShader : public CShader
{
public:
	StageSelectShader(ResourceManager* r, PlayerShader* ps);
	virtual ~StageSelectShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);
	virtual void Animate(CCamera* cam);
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

	PlayerShader* ps;


	bool coworkShow = false;
	bool together = false;


	

};