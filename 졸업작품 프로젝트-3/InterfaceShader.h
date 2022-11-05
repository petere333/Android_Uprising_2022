#pragma once

#include "Shader.h"
#include "ResourceManager.h"

class InterfaceShader : public CShader
{
public:
	InterfaceShader(ResourceManager* r);
	virtual ~InterfaceShader();

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

	void ShowNarration(int index, double dur);

public:
	PlayerInfoManager* info;
	std::vector<UIObject*>	objects;
	std::vector<CMesh*>	meshes;
	std::vector<CMesh*>	revmeshes;
	ResourceManager* rm;

	bool stageClear = false;
	chrono::time_point<chrono::system_clock> clearTime;

	chrono::time_point<chrono::system_clock> missionChangedTime;
	int mission = 1;
	
	
	bool failed = false;

	int m1_kill = 0;
	int m2_stun = 0;
	int m3_bother=0;
	int m4_kill = 0;
	int m5_broken = 0;
	int m6_broken = 0;
	int m7_kill=0;
	int m8_kill=0;
	int m9_stun = 0;
	int m9_search = 0;
	int m10_gain = 0;
	int m10_miss = 0;

	bool exiting = false;

	bool missionFail = false;

	bool nextPos = false;
	bool missionShow = true;
	chrono::time_point<chrono::system_clock> timeFailed;

	bool narrationShow = false;
	chrono::time_point<chrono::system_clock> lastNarrated;
	double nDuration;
};