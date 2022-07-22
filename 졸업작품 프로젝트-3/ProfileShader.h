#pragma once
#pragma once


#include "Shader.h"
#include "ResourceManager.h"

class ProfileShader : public CShader
{
public:
	ProfileShader(ResourceManager* r);
	virtual ~ProfileShader();

	virtual void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseObjects();
	virtual void ReleaseUploadBuffers();
	virtual void ReleaseShaderVariables();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);
	virtual void Animate(CCamera* cam, PlayerInfoManager* in);
	virtual D3D12_INPUT_LAYOUT_DESC CreateInputLayout();
	virtual D3D12_RASTERIZER_DESC CreateRasterizerState();
	virtual D3D12_DEPTH_STENCIL_DESC CreateDepthStencilState();

	virtual D3D12_SHADER_BYTECODE CreateVertexShader();
	virtual D3D12_SHADER_BYTECODE CreatePixelShader();

public:
	PlayerInfoManager* info;

	std::vector<UIObject*>	objects;
	std::vector<CubeMeshOffset*> meshes;
	std::vector<CubeMeshOffset*> meshesRev;
	ResourceManager* rm;

	bool storageShow = false;

	int items = 0;
};