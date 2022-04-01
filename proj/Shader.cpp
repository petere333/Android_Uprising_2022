#include "Shader.h"


CTexture* ppTextures[5];
CMaterial* ppMaterials[5];

CShader::CShader()
{
	m_d3dSrvCPUDescriptorStartHandle.ptr = NULL;
	m_d3dSrvGPUDescriptorStartHandle.ptr = NULL;
}

CShader::~CShader()
{
	if (m_ppd3dPipelineState)
	{
		m_ppd3dPipelineState->Release();
		delete[] m_ppd3dPipelineState;
	}
}
//래스터라이저 상태를 설정하기 위한 구조체를 반환한다.
D3D12_RASTERIZER_DESC CShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
	return(d3dRasterizerDesc);
}

//깊이-스텐실 검사를 위한 상태를 설정하기 위한 구조체를 반환한다. 
D3D12_DEPTH_STENCIL_DESC CShader::CreateDepthStencilState()
{
	D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc;
	::ZeroMemory(&d3dDepthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));
	d3dDepthStencilDesc.DepthEnable = TRUE;
	d3dDepthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	d3dDepthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
	d3dDepthStencilDesc.StencilEnable = FALSE;
	d3dDepthStencilDesc.StencilReadMask = 0x00;
	d3dDepthStencilDesc.StencilWriteMask = 0x00;
	d3dDepthStencilDesc.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	d3dDepthStencilDesc.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	return(d3dDepthStencilDesc);
}

//블렌딩 상태를 설정하기 위한 구조체를 반환한다.
D3D12_BLEND_DESC CShader::CreateBlendState()
{
	D3D12_BLEND_DESC d3dBlendDesc;
	::ZeroMemory(&d3dBlendDesc, sizeof(D3D12_BLEND_DESC));
	d3dBlendDesc.AlphaToCoverageEnable = FALSE;
	d3dBlendDesc.IndependentBlendEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].BlendEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].LogicOpEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].SrcBlend = D3D12_BLEND_ONE;
	d3dBlendDesc.RenderTarget[0].DestBlend = D3D12_BLEND_ZERO;
	d3dBlendDesc.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;
	d3dBlendDesc.RenderTarget[0].SrcBlendAlpha = D3D12_BLEND_ONE;
	d3dBlendDesc.RenderTarget[0].DestBlendAlpha = D3D12_BLEND_ZERO;
	d3dBlendDesc.RenderTarget[0].BlendOpAlpha = D3D12_BLEND_OP_ADD;
	d3dBlendDesc.RenderTarget[0].LogicOp = D3D12_LOGIC_OP_NOOP;
	d3dBlendDesc.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	return(d3dBlendDesc);
}

//입력 조립기에게 정점 버퍼의 구조를 알려주기 위한 구조체를 반환한다. 
D3D12_INPUT_LAYOUT_DESC CShader::CreateInputLayout()
{
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = NULL;
	d3dInputLayoutDesc.NumElements = 0;
	return(d3dInputLayoutDesc);
}

D3D12_SHADER_BYTECODE CShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	D3D12_SHADER_BYTECODE d3dShaderByteCode;
	d3dShaderByteCode.BytecodeLength = 0;
	d3dShaderByteCode.pShaderBytecode = NULL;
	return(d3dShaderByteCode);
}
D3D12_SHADER_BYTECODE CShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	D3D12_SHADER_BYTECODE d3dShaderByteCode;
	d3dShaderByteCode.BytecodeLength = 0;
	d3dShaderByteCode.pShaderBytecode = NULL;
	return(d3dShaderByteCode);
}

//셰이더 소스 코드를 컴파일하여 바이트 코드 구조체를 반환한다.
D3D12_SHADER_BYTECODE CShader::CompileShaderFromFile(WCHAR *pszFileName, LPCSTR
pszShaderName, LPCSTR pszShaderProfile, ID3DBlob** ppd3dShaderBlob)
{
UINT nCompileFlags = 0;
#if defined(_DEBUG)
nCompileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif
::D3DCompileFromFile(pszFileName, NULL, NULL, pszShaderName, pszShaderProfile,
	nCompileFlags, 0, ppd3dShaderBlob, NULL);
D3D12_SHADER_BYTECODE d3dShaderByteCode;
d3dShaderByteCode.BytecodeLength = (*ppd3dShaderBlob)->GetBufferSize();
d3dShaderByteCode.pShaderBytecode = (*ppd3dShaderBlob)->GetBufferPointer();
return(d3dShaderByteCode);
}


//그래픽스 파이프라인 상태 객체를 생성한다. 
void CShader::CreateShader(ID3D12Device *pd3dDevice, ID3D12RootSignature
*pd3dGraphicsRootSignature)
{
ID3DBlob* pd3dVertexShaderBlob = NULL, * pd3dPixelShaderBlob = NULL;

D3D12_GRAPHICS_PIPELINE_STATE_DESC d3dPipelineStateDesc;
::ZeroMemory(&d3dPipelineStateDesc, sizeof(D3D12_GRAPHICS_PIPELINE_STATE_DESC));
d3dPipelineStateDesc.pRootSignature = pd3dGraphicsRootSignature;
d3dPipelineStateDesc.VS = CreateVertexShader(&pd3dVertexShaderBlob);
d3dPipelineStateDesc.PS = CreatePixelShader(&pd3dPixelShaderBlob);
d3dPipelineStateDesc.RasterizerState = CreateRasterizerState();
d3dPipelineStateDesc.BlendState = CreateBlendState();
d3dPipelineStateDesc.DepthStencilState = CreateDepthStencilState();
d3dPipelineStateDesc.InputLayout = CreateInputLayout();
d3dPipelineStateDesc.SampleMask = UINT_MAX;
d3dPipelineStateDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
d3dPipelineStateDesc.NumRenderTargets = 1;
d3dPipelineStateDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
d3dPipelineStateDesc.DSVFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
d3dPipelineStateDesc.SampleDesc.Count = 1;
d3dPipelineStateDesc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;
pd3dDevice->CreateGraphicsPipelineState(&d3dPipelineStateDesc,__uuidof(ID3D12PipelineState), (void**)&m_ppd3dPipelineState);
if (pd3dVertexShaderBlob) pd3dVertexShaderBlob->Release();
if (pd3dPixelShaderBlob) pd3dPixelShaderBlob->Release();
if (d3dPipelineStateDesc.InputLayout.pInputElementDescs) delete[]
d3dPipelineStateDesc.InputLayout.pInputElementDescs;
}

void CShader::CreateCbvSrvDescriptorHeaps(ID3D12Device* pd3dDevice, int nConstantBufferViews, int nShaderResourceViews)
{
	D3D12_DESCRIPTOR_HEAP_DESC d3dDescriptorHeapDesc;
	d3dDescriptorHeapDesc.NumDescriptors = nConstantBufferViews + nShaderResourceViews; //CBVs + SRVs 
	d3dDescriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	d3dDescriptorHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
	d3dDescriptorHeapDesc.NodeMask = 0;
	pd3dDevice->CreateDescriptorHeap(&d3dDescriptorHeapDesc, __uuidof(ID3D12DescriptorHeap), (void**)&m_pd3dCbvSrvDescriptorHeap);

	m_d3dCbvCPUDescriptorStartHandle = m_pd3dCbvSrvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	m_d3dCbvGPUDescriptorStartHandle = m_pd3dCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart();
	m_d3dSrvCPUDescriptorStartHandle.ptr = m_d3dCbvCPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * nConstantBufferViews);
	m_d3dSrvGPUDescriptorStartHandle.ptr = m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * nConstantBufferViews);

	m_d3dSrvCPUDescriptorNextHandle = m_d3dSrvCPUDescriptorStartHandle;
	m_d3dSrvGPUDescriptorNextHandle = m_d3dSrvGPUDescriptorStartHandle;
}

void CShader::CreateConstantBufferViews(ID3D12Device* pd3dDevice, int nConstantBufferViews, ID3D12Resource* pd3dConstantBuffers, UINT nStride)
{
	D3D12_GPU_VIRTUAL_ADDRESS d3dGpuVirtualAddress = pd3dConstantBuffers->GetGPUVirtualAddress();
	D3D12_CONSTANT_BUFFER_VIEW_DESC d3dCBVDesc;
	d3dCBVDesc.SizeInBytes = nStride;
	for (int j = 0; j < nConstantBufferViews; j++)
	{
		d3dCBVDesc.BufferLocation = d3dGpuVirtualAddress + (nStride * j);
		D3D12_CPU_DESCRIPTOR_HANDLE d3dCbvCPUDescriptorHandle;
		d3dCbvCPUDescriptorHandle.ptr = m_d3dCbvCPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * j);
		pd3dDevice->CreateConstantBufferView(&d3dCBVDesc, d3dCbvCPUDescriptorHandle);
	}
}

void CShader::CreateShaderResourceViews(ID3D12Device* pd3dDevice, CTexture* pTexture, UINT nDescriptorHeapIndex, UINT nRootParameterStartIndex)
{
	m_d3dSrvCPUDescriptorNextHandle.ptr += (::gnCbvSrvDescriptorIncrementSize * nDescriptorHeapIndex);
	m_d3dSrvGPUDescriptorNextHandle.ptr += (::gnCbvSrvDescriptorIncrementSize * nDescriptorHeapIndex);

	int nTextures = pTexture->GetTextures();
	for (int i = 0; i < nTextures; i++)
	{
		ID3D12Resource* pShaderResource = pTexture->GetResource(i);
		D3D12_SHADER_RESOURCE_VIEW_DESC d3dShaderResourceViewDesc = pTexture->GetShaderResourceViewDesc(i);
		pd3dDevice->CreateShaderResourceView(pShaderResource, &d3dShaderResourceViewDesc, m_d3dSrvCPUDescriptorNextHandle);
		m_d3dSrvCPUDescriptorNextHandle.ptr += ::gnCbvSrvDescriptorIncrementSize;
		pTexture->SetGpuDescriptorHandle(i, m_d3dSrvGPUDescriptorNextHandle);
		m_d3dSrvGPUDescriptorNextHandle.ptr += ::gnCbvSrvDescriptorIncrementSize;
	}
	int nRootParameters = pTexture->GetRootParameters();
	for (int i = 0; i < nRootParameters; i++) pTexture->SetRootParameterIndex(i, nRootParameterStartIndex + i);
}

void CShader::OnPrepareRender(ID3D12GraphicsCommandList* pd3dCommandList)
{
	//파이프라인에 그래픽스 상태 객체를 설정한다. 
	if (m_pd3dCbvSrvDescriptorHeap) pd3dCommandList->SetDescriptorHeaps(1, &m_pd3dCbvSrvDescriptorHeap);
	pd3dCommandList->SetPipelineState(m_ppd3dPipelineState);
}
void CShader::Render(ID3D12GraphicsCommandList* pd3dCommandList)
{
	OnPrepareRender(pd3dCommandList);
	
}


void CShader::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList)
{
}
void CShader::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
}
void CShader::UpdateShaderVariable(ID3D12GraphicsCommandList* pd3dCommandList, XMFLOAT4X4* pxmf4x4World)
{

}
void CShader::ReleaseShaderVariables()
{
	if (m_pd3dCbvSrvDescriptorHeap) m_pd3dCbvSrvDescriptorHeap->Release();
}
void CShader::ReleaseUploadBuffers()
{
}
////////////////////////////////////////////////////////////////////////////////
CPlayerShader::CPlayerShader()
{
}
CPlayerShader::~CPlayerShader()
{
}
D3D12_INPUT_LAYOUT_DESC CPlayerShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new
		D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];
	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;
	return(d3dInputLayoutDesc);
}
D3D12_SHADER_BYTECODE CPlayerShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSDiffused", "vs_5_1",
		ppd3dShaderBlob));
}
D3D12_SHADER_BYTECODE CPlayerShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSDiffused", "ps_5_1",
		ppd3dShaderBlob));
}
void CPlayerShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature
	* pd3dGraphicsRootSignature)
{
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

/////////////////////////////////////////////////////////////////////

CObjectsShader::CObjectsShader(int nobjects)
{
	m_nObjects = nobjects;
}
CObjectsShader::~CObjectsShader()
{
}

/////////////////////////////////////////////////////////////////////////

CTexturedShader::CTexturedShader()
{
}

CTexturedShader::~CTexturedShader()
{
}

D3D12_INPUT_LAYOUT_DESC CTexturedShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

////////////////////////////////////////////////////////////////////////////

CGroundShader::CGroundShader(int nobj) : CObjectsShader(nobj)
{
	m_nObjects = nobj;
}
CGroundShader::~CGroundShader()
{
}

/**/
void CGroundShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature* pd3dGraphicsRootSignature)
{
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

#define TEXTURES		5

D3D12_SHADER_BYTECODE CGroundShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSTextured", "vs_5_1", ppd3dShaderBlob));
}

D3D12_SHADER_BYTECODE CGroundShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSTextured", "ps_5_1", ppd3dShaderBlob));
}

void CGroundShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList, void* pContext)
{
	//텍스처 생성

	
		CTexture* ppTextures[TEXTURES];
		ppTextures[0] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[0]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Metal02.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[1] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[1]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"wall_text.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[2] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[2]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"DoorTexture.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[3] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[3]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"하단부품.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[4] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[4]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"상단벽.dds", RESOURCE_TEXTURE2D, 0);


		/*
		ppTextures[1] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[1]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Stone01.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[2] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[2]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Metal01.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[3] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[3]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Metal02.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[4] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[4]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Rock01.dds", RESOURCE_TEXTURE2D, 0);
		ppTextures[5] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
		ppTextures[5]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Lava(Emissive).dds", RESOURCE_TEXTURE2D, 0);
		*/

		// 뷰 생성
		m_nObjects = 72;

		CMaterial* ppMaterials[TEXTURES];
		for (int i = 0; i < TEXTURES; i++)
		{
			ppMaterials[i] = new CMaterial();
			ppMaterials[i]->SetTexture(ppTextures[i]);
		}

		CreateCbvSrvDescriptorHeaps(pd3dDevice, m_nObjects, TEXTURES);
		CreateShaderVariables(pd3dDevice, pd3dCommandList);
		CreateConstantBufferViews(pd3dDevice, m_nObjects, m_pd3dcbGameObjects, ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255));
		/**/
		for (int i = 0; i < TEXTURES; i++)
		{
			CreateShaderResourceViews(pd3dDevice, ppTextures[i], 0, 2);
		}

		//실질적으로 객체 넣기

		ImageFile* heights = new ImageFile(L"HeightMap.raw", 257, 257, true);
		ImageFile* objects = new ImageFile(L"ObjectsMap.raw", 257, 257, true);
		CCubeMeshTextured* pCubeMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
		GridMesh* pGrid = new GridMesh(pd3dDevice, pd3dCommandList, 0, 0, 257, 257, XMFLOAT3(1.0f, 1.0f, 1.0f), heights);


		std::vector<CGameObject*> objList;
		for (int z = 2; z <= 254; ++z)
		{
			for (int x = 2; x < 254; ++x)
			{
				byte b = objects->GetPixelInRaw(x, z);
				if (b == 204)
				{
					CGameObject* temp = new CGameObject(1);
					temp->SetMesh(0, pCubeMesh);
					temp->SetMaterial(ppMaterials[0]);
					temp->SetPosition(x, pGrid->getData(x, z), z);
					temp->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * (objList.size() + 1)));
					objList.push_back(temp);
				}
			}
		}

		// 시작지역 바닥
		CCubeMeshTextured* terrain = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 0.0f, 0.0f, 0.0f);
		CCubeMeshTextured* terrain_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 2000.0f, 0.0f, 0.0f);
		CCubeMeshTextured* terrain_2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 0.0f, 0.0f, 2000.0f);
		CCubeMeshTextured* terrain_3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 2000.0f, 0.0f, 2000.0f);


		// 오른쪽 지역 바닥
		CCubeMeshTextured* terrain_2_Plate1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 5200.0f, 0.0f, 0.0f);
		CCubeMeshTextured* terrain_2_Plate2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 7200.0f, 0.0f, 0.0f);
		CCubeMeshTextured* terrain_2_Plate3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 5200.0f, 0.0f, 2000.0f);
		CCubeMeshTextured* terrain_2_Plate4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 20.0f, 2000.0f, 7200.0f, 0.0f, 2000.0f);



		// 시작지역 사방에 배치된 벽(하단)

		CCubeMeshTextured* terrain2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 3550.0f, 3000.0f, 0.0f, 775.0f);
		CCubeMeshTextured* s_terrain2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 350.0f, 3000.0f, 0.0f, 2825.0f);

		CCubeMeshTextured* terrain3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, -4000.0f, -1000.0f, 0.0f, 1000.0f);
		CCubeMeshTextured* terrain4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 4000.0f, 100.0f, 30.0f, 1000.0f, 0.0f, 3000.0f);
		CCubeMeshTextured* terrain5 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, -4000.0f, 100.0f, 30.0f, 1000.0f, 0.0f, -1000.0f);
		// 중단
		CCubeMeshTextured* terrain2_middle = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 50.0f, 3550.0f, 3000.0f, 75.0f, 775.0f);
		CCubeMeshTextured* s_terrain2_middle = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 50.0f, 350.0f, 3000.0f, 75.0f, 2825.0f); // 오른쪽


		CCubeMeshTextured* terrain2_middle2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 50.0f, -4000.0f, -1000.0f, 75.0f, 1000.0f);
		CCubeMeshTextured* terrain2_middle3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 4000.0f, 50.0f, 30.0f, 1000.0f, 75.0f, 3000.0f);
		CCubeMeshTextured* terrain2_middle4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, -4000.0f, 50.0f, 30.0f, 1000.0f, 75.0f, -1000.0f);


		// 상단 시작지역 오른쪽 벽
		CCubeMeshTextured* terrain2_High = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 3550.0f, 3000.0f, 550.0f, 775.0f);
		CCubeMeshTextured* s_terrain2_High = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 350.0f, 3000.0f, 550.0f, 2825.0f);

		CCubeMeshTextured* d_terrain2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 600.0f, 100.0f, 3000.0f, 750.0f, 2600.0f);


		// 상단 _ 왼쪽 벽 _ 1, 2, 3

		CCubeMeshTextured* Sang_start_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 516.5f, -1000.0f, 550.0f, -741.75f);
		CCubeMeshTextured* Sang_windows_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 300.0f, 300.0f, -1000.0f, 250.0f, -333.5f);
		CCubeMeshTextured* Sang_windows_1_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 300.0f, 300.0f, -1000.0f, 850.0f, -333.5f);
		CCubeMeshTextured* Sang_end_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 516.5f, -1000.0f, 550.0f, 74.75f);

		CCubeMeshTextured* Sang_start_2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 516.5f, -1000.0f, 550.0f, 591.25f);
		CCubeMeshTextured* Sang_windows_2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 300.0f, 300.0f, -1000.0f, 250.0f, 999.5f);
		CCubeMeshTextured* Sang_windows_2_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 300.0f, 300.0f, -1000.0f, 850.0f, 999.5f);
		CCubeMeshTextured* Sang_end_2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 516.5f, -1000.0f, 550.0f, 1407.75f);

		CCubeMeshTextured* Sang_start_3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 516.5f, -1000.0f, 550.0f, 1924.25f);
		CCubeMeshTextured* Sang_windows_3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 300.0f, 300.0f, -1000.0f, 250.0f, 2332.5f);
		CCubeMeshTextured* Sang_windows_3_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 300.0f, 300.0f, -1000.0f, 850.0f, 2332.5f);
		CCubeMeshTextured* Sang_end_3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 516.5f, -1000.0f, 550.0f, 2740.75f);

		// 상단 _ 하단 벽 (4, 5, 6)
		
		CCubeMeshTextured* Sang_start_4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, -741.75f, 550.0f, -1000.0f);
		CCubeMeshTextured* Sang_windows_4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 300.0f, 300.0f, 30.0f, -333.5f, 250.0f, -1000.0f);
		CCubeMeshTextured* Sang_end_4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 74.75f, 550.0f, -1000.0f);

		CCubeMeshTextured* Sang_start_5 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 591.25f, 550.0f, -1000.0f);
		CCubeMeshTextured* Sang_windows_5 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 300.0f, 300.0f, 30.0f, 999.5f, 250.0f, -1000.0f);
		CCubeMeshTextured* Sang_end_5 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 1407.75f, 550.0f, -1000.0f);

		CCubeMeshTextured* Sang_start_6 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 1924.25f, 550.0f, -1000.0f);
		CCubeMeshTextured* Sang_windows_6 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 300.0f, 300.0f, 30.0f, 2332.5f, 250.0f, -1000.0f);
		CCubeMeshTextured* Sang_end_6 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 2740.75f, 550.0f, -1000.0f);

		// 상단 _ 위쪽 벽 7,8,9


		CCubeMeshTextured* Sang_start_7 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, -741.75f, 550.0f, 3000.0f);
		CCubeMeshTextured* Sang_windows_7 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 300.0f, 300.0f, 30.0f, -333.5f, 250.0f, 3000.0f);
		CCubeMeshTextured* Sang_end_7 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 74.75f, 550.0f, 3000.0f);

		CCubeMeshTextured* Sang_start_8 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 591.25f, 550.0f, 3000.0f);
		CCubeMeshTextured* Sang_windows_8 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 300.0f, 300.0f, 30.0f, 999.5f, 250.0f, 3000.0f);
		CCubeMeshTextured* Sang_end_8 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 1407.75f, 550.0f, 3000.0f);

		CCubeMeshTextured* Sang_start_9 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 1924.25f, 550.0f, 3000.0f);
		CCubeMeshTextured* Sang_windows_9 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 300.0f, 300.0f, 30.0f, 2332.5f, 250.0f, 3000.0f);
		CCubeMeshTextured* Sang_end_9 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 516.5f, 900.0f, 30.0f, 2740.75f, 550.0f, 3000.0f);


		///////////////////////////////////////////////

		// 시작지역 부속 벽(하단)
		CCubeMeshTextured* terrain6 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 3000.0f, 2500.0f, 0.0f, 1500.0f);
		CCubeMeshTextured* terrain7 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 3000.0f, 2500.0f, 0.0f, 1500.0f);
		CCubeMeshTextured* terrain8 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 0.001f, 0.001f, 0.001f, 0.0f, 0.0f, 0.0f);

		// 중단
		CCubeMeshTextured* M_errain1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 50.0f, 3000.0f, 2500.0f, 75.0f, 1500.0f);

		// 상단

		CCubeMeshTextured* H_errain1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 900.0f, 3000.0f, 2500.0f, 550.0f, 1500.0f);


		/////////////////////////////

		// 오른쪽 지역 부속 벽(하단)
		CCubeMeshTextured* Terrain_Right_Wall_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 3000.0f, 4700.0f, 0.0f, 1500.0f);
		CCubeMeshTextured* Terrain_Right_Wall_2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 2700.0f, 6500.0f, 0.0f, 1650.0f);
		CCubeMeshTextured* Terrain_Right_Wall_3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 800.0f, 5600.0f, 0.0f, 400.0f);
		CCubeMeshTextured* Terrain_Right_Wall_4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2600.0f, 100.0f, 30.0f, 6915.0f, 0.0f, 15.0f);


		// 시작지역 문
		CCubeMeshTextured* terrain_door = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 200.0f, 450.0f, 100.0f, 2900.0f, 0.0f, 2600.0f);

		// 통로 벽(하단)
		CCubeMeshTextured* terrain_tonglo_wall1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1200.0f, 100.0f, 30.0f, 3600.0f, 0.0f, 3000.0f);
		CCubeMeshTextured* terrain_tonglo_wall2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1200.0f, 100.0f, 30.0f, 3600.0f, 0.0f, 2400.0f);

		// 통로 벽 (중단)

		CCubeMeshTextured* Merrain_tonglo_wall1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1200.0f, 50.0f, 30.0f, 3600.0f, 75.0f, 3000.0f);
		CCubeMeshTextured* Merrain_tonglo_wall2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1200.0f, 50.0f, 30.0f, 3600.0f, 75.0f, 2400.0f);

		/////////////////////////////////////

		// 통로 바닥
		CCubeMeshTextured* terrain_tonglo_plate = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1200.0f, 20.0f, 600.0f, 3600.0f, 0.0f, 2700.0f);

		// 오른쪽으로 향하는 문
		CCubeMeshTextured* terrain_tonglo_door = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 200.0f, 450.0f, 100.0f, 4100.0f, 0.0f, 2600.0f);
		CCubeMeshTextured* terrain_tonglo_door2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 200.0f, 450.0f, 100.0f, 4300.0f, 0.0f, 2600.0f);


		// 오른쪽 지역 사방에 배치된 벽(하단)
		CCubeMeshTextured* terrain_Second_room_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 4000.0f, 8200.0f, 0.0f, 1000.0f);
		CCubeMeshTextured* terrain_Second_room_2 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 30.0f, 100.0f, 4000.0f, 4200.0f, 0.0f, 1000.0f);
		CCubeMeshTextured* terrain_Second_room_3 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 4000.0f, 100.0f, 30.0f, 6200.0f, 0.0f, -1000.0f);
		CCubeMeshTextured* terrain_Second_room_4 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 4000.0f, 100.0f, 30.0f, 6200.0f, 0.0f, 3000.0f);




		m_ppObjects = new CGameObject * [m_nObjects];


		CGameObject* pRotatingObject = NULL;

		pRotatingObject = new CGameObject(1);
		pRotatingObject->SetMesh(0, terrain);
		pRotatingObject->SetMaterial(ppMaterials[0]);
		pRotatingObject->SetPosition(0.0f, 0.0f, 0.0f);
		pRotatingObject->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[0] = pRotatingObject;



		CGameObject* Wall_Obj = NULL;
		Wall_Obj = new CGameObject(2);
		Wall_Obj->SetMesh(0, terrain2);
		Wall_Obj->SetMaterial(ppMaterials[1]);
		Wall_Obj->SetPosition(0.0f, 0.0f, 0.0f);
		Wall_Obj->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[1] = Wall_Obj;



		CGameObject* Wall_Obj2 = NULL;
		Wall_Obj2 = new CGameObject(3);
		Wall_Obj2->SetMesh(0, terrain3);
		Wall_Obj2->SetMaterial(ppMaterials[1]);
		Wall_Obj2->SetPosition(XMFLOAT3(0.0f, 0.0f, 0.0f));
		Wall_Obj2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[2] = Wall_Obj2;




		CGameObject* Wall_Obj3 = NULL;
		Wall_Obj3 = new CGameObject(4);
		Wall_Obj3->SetMesh(0, terrain4);
		Wall_Obj3->SetMaterial(ppMaterials[1]);
		Wall_Obj3->GetPosition();
		Wall_Obj3->SetPosition(XMFLOAT3(0.0f, 0.0f, 0.0f));
		Wall_Obj3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[3] = Wall_Obj3;


		CGameObject* Wall_Obj4 = NULL;
		Wall_Obj4 = new CGameObject(5);
		Wall_Obj4->SetMesh(0, terrain5);
		Wall_Obj4->SetMaterial(ppMaterials[1]);
		Wall_Obj4->GetPosition();
		Wall_Obj4->SetPosition(XMFLOAT3(0.0f, 0.0f, 0.0f));
		Wall_Obj4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[4] = Wall_Obj4;


		CGameObject* Wall_Obj5 = NULL;
		Wall_Obj5 = new CGameObject(6);
		Wall_Obj5->SetMesh(0, terrain6);
		Wall_Obj5->SetMaterial(ppMaterials[1]);
		Wall_Obj5->GetPosition();
		Wall_Obj5->SetPosition(0.0f, 0.0f, 0.0f);
		Wall_Obj5->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[5] = Wall_Obj5;

		CGameObject* Wall_Obj6 = NULL;
		Wall_Obj6 = new CGameObject(7);
		Wall_Obj6->SetMesh(0, terrain7);
		Wall_Obj6->SetMaterial(ppMaterials[1]);
		Wall_Obj6->GetPosition();
		Wall_Obj6->SetPosition(0.0f, 0.0f, 0.0f);
		Wall_Obj6->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[6] = Wall_Obj6;

		CGameObject* Wall_Obj7 = NULL;
		Wall_Obj7 = new CGameObject(8);
		Wall_Obj7->SetMesh(0, terrain8);
		Wall_Obj7->SetMaterial(ppMaterials[1]);
		Wall_Obj7->GetPosition();
		Wall_Obj7->SetPosition(0.0f, 0.0f, 0.0f);
		Wall_Obj7->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[7] = Wall_Obj7;

		// 바닥들
		CGameObject* Plate_1 = new CGameObject(9);
		Plate_1->SetMesh(0, terrain_1);
		Plate_1->SetMaterial(ppMaterials[0]);
		Plate_1->SetPosition(0.0f, 0.0f, 0.0f);
		Plate_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[8] = Plate_1;

		CGameObject* Plate_2 = new CGameObject(10);
		Plate_2->SetMesh(0, terrain_2);
		Plate_2->SetMaterial(ppMaterials[0]);
		Plate_2->SetPosition(0.0f, 0.0f, 0.0f);
		Plate_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[9] = Plate_2;

		CGameObject* Plate_3 = new CGameObject(11);
		Plate_3->SetMesh(0, terrain_3);
		Plate_3->SetMaterial(ppMaterials[0]);
		Plate_3->SetPosition(0.0f, 0.0f, 0.0f);
		Plate_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[10] = Plate_3;

		CGameObject* Door = new CGameObject(11);
		Door->SetMesh(0, terrain_door);
		Door->SetMaterial(ppMaterials[2]);
		Door->SetPosition(0.0f, 0.0f, 0.0f);
		Door->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[11] = Door;

		CGameObject* Tonglo_Wall1 = new CGameObject(11);
		Tonglo_Wall1->SetMesh(0, terrain_tonglo_wall1);
		Tonglo_Wall1->SetMaterial(ppMaterials[1]);
		Tonglo_Wall1->SetPosition(0.0f, 0.0f, 0.0f);
		Tonglo_Wall1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[12] = Tonglo_Wall1;

		CGameObject* Tonglo_Wall2 = new CGameObject(11);
		Tonglo_Wall2->SetMesh(0, terrain_tonglo_wall2);
		Tonglo_Wall2->SetMaterial(ppMaterials[1]);
		Tonglo_Wall2->SetPosition(0.0f, 0.0f, 0.0f);
		Tonglo_Wall2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[13] = Tonglo_Wall2;

		CGameObject* Second_Room_1 = new CGameObject(11);
		Second_Room_1->SetMesh(0, terrain_Second_room_1);
		Second_Room_1->SetMaterial(ppMaterials[1]);
		Second_Room_1->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Room_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[14] = Second_Room_1;

		CGameObject* Second_Room_2 = new CGameObject(11);
		Second_Room_2->SetMesh(0, terrain_Second_room_2);
		Second_Room_2->SetMaterial(ppMaterials[1]);
		Second_Room_2->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Room_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[15] = Second_Room_2;

		CGameObject* Second_Room_3 = new CGameObject(11);
		Second_Room_3->SetMesh(0, terrain_Second_room_3);
		Second_Room_3->SetMaterial(ppMaterials[1]);
		Second_Room_3->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Room_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[16] = Second_Room_3;

		CGameObject* Second_Room_4 = new CGameObject(11);
		Second_Room_4->SetMesh(0, terrain_Second_room_4);
		Second_Room_4->SetMaterial(ppMaterials[1]);
		Second_Room_4->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Room_4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[17] = Second_Room_4;

		CGameObject* Second_Plate_1 = new CGameObject(11);
		Second_Plate_1->SetMesh(0, terrain_2_Plate1);
		Second_Plate_1->SetMaterial(ppMaterials[0]);
		Second_Plate_1->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Plate_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[18] = Second_Plate_1;

		CGameObject* Second_Plate_2 = new CGameObject(11);
		Second_Plate_2->SetMesh(0, terrain_2_Plate2);
		Second_Plate_2->SetMaterial(ppMaterials[0]);
		Second_Plate_2->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Plate_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[19] = Second_Plate_2;

		CGameObject* Second_Plate_3 = new CGameObject(11);
		Second_Plate_3->SetMesh(0, terrain_2_Plate3);
		Second_Plate_3->SetMaterial(ppMaterials[0]);
		Second_Plate_3->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Plate_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[20] = Second_Plate_3;

		CGameObject* Second_Plate_4 = new CGameObject(11);
		Second_Plate_4->SetMesh(0, terrain_2_Plate4);
		Second_Plate_4->SetMaterial(ppMaterials[0]);
		Second_Plate_4->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Plate_4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[21] = Second_Plate_4;

		CGameObject* Tonglo_Plate = new CGameObject(11);
		Tonglo_Plate->SetMesh(0, terrain_tonglo_plate);
		Tonglo_Plate->SetMaterial(ppMaterials[0]);
		Tonglo_Plate->SetPosition(0.0f, 0.0f, 0.0f);
		Tonglo_Plate->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[22] = Tonglo_Plate;

		CGameObject* Tonglo_door = new CGameObject(11);
		Tonglo_door->SetMesh(0, terrain_tonglo_door);
		Tonglo_door->SetMaterial(ppMaterials[2]);
		Tonglo_door->SetPosition(0.0f, 0.0f, 0.0f);
		Tonglo_door->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[23] = Tonglo_door;

		CGameObject* Second_Place_Wall_1 = new CGameObject(11);
		Second_Place_Wall_1->SetMesh(0, Terrain_Right_Wall_1);
		Second_Place_Wall_1->SetMaterial(ppMaterials[1]);
		Second_Place_Wall_1->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Place_Wall_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[24] = Second_Place_Wall_1;

		CGameObject* Second_Place_Wall_2 = new CGameObject(11);
		Second_Place_Wall_2->SetMesh(0, Terrain_Right_Wall_2);
		Second_Place_Wall_2->SetMaterial(ppMaterials[1]);
		Second_Place_Wall_2->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Place_Wall_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[25] = Second_Place_Wall_2;

		CGameObject* Second_Place_Wall_3 = new CGameObject(11);
		Second_Place_Wall_3->SetMesh(0, Terrain_Right_Wall_3);
		Second_Place_Wall_3->SetMaterial(ppMaterials[1]);
		Second_Place_Wall_3->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Place_Wall_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[26] = Second_Place_Wall_3;

		CGameObject* Second_Place_Wall_4 = new CGameObject(11);
		Second_Place_Wall_4->SetMesh(0, Terrain_Right_Wall_4);
		Second_Place_Wall_4->SetMaterial(ppMaterials[1]);
		Second_Place_Wall_4->SetPosition(0.0f, 0.0f, 0.0f);
		Second_Place_Wall_4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[27] = Second_Place_Wall_4;

		CGameObject* Tonglo_door2 = new CGameObject(11);
		Tonglo_door2->SetMesh(0, terrain_tonglo_door2);
		Tonglo_door2->SetMaterial(ppMaterials[2]);
		Tonglo_door2->SetPosition(0.0f, 0.0f, 0.0f);
		Tonglo_door2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[28] = Tonglo_door2;


		CGameObject* M_Hadan1 = new CGameObject(11);
		M_Hadan1->SetMesh(0, terrain2_middle);
		M_Hadan1->SetMaterial(ppMaterials[3]);
		M_Hadan1->SetPosition(0.0f, 0.0f, 0.0f);
		M_Hadan1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[29] = M_Hadan1;


		CGameObject* M_Hadan2 = new CGameObject(11);
		M_Hadan2->SetMesh(0, terrain2_middle2);
		M_Hadan2->SetMaterial(ppMaterials[3]);
		M_Hadan2->SetPosition(0.0f, 0.0f, 0.0f);
		M_Hadan2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[30] = M_Hadan2;


		CGameObject* M_Hadan3 = new CGameObject(11);
		M_Hadan3->SetMesh(0, terrain2_middle3);
		M_Hadan3->SetMaterial(ppMaterials[3]);
		M_Hadan3->SetPosition(0.0f, 0.0f, 0.0f);
		M_Hadan3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[31] = M_Hadan3;


		CGameObject* M_Hadan4 = new CGameObject(11);
		M_Hadan4->SetMesh(0, terrain2_middle4);
		M_Hadan4->SetMaterial(ppMaterials[3]);
		M_Hadan4->SetPosition(0.0f, 0.0f, 0.0f);
		M_Hadan4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[32] = M_Hadan4;

		CGameObject* S_Start_1 = new CGameObject(11);
		S_Start_1->SetMesh(0, Sang_start_1);
		S_Start_1->SetMaterial(ppMaterials[4]);
		S_Start_1->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[33] = S_Start_1;

		CGameObject* S_Windows_1 = new CGameObject(11);
		S_Windows_1->SetMesh(0, Sang_windows_1);
		S_Windows_1->SetMaterial(ppMaterials[4]);
		S_Windows_1->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[34] = S_Windows_1;

		CGameObject* S_end_1 = new CGameObject(11);
		S_end_1->SetMesh(0, Sang_end_1);
		S_end_1->SetMaterial(ppMaterials[4]);
		S_end_1->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[35] = S_end_1;


		CGameObject* S_Start_2 = new CGameObject(11);
		S_Start_2->SetMesh(0, Sang_start_2);
		S_Start_2->SetMaterial(ppMaterials[4]);
		S_Start_2->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[36] = S_Start_2;

		CGameObject* S_Windows_2 = new CGameObject(11);
		S_Windows_2->SetMesh(0, Sang_windows_2);
		S_Windows_2->SetMaterial(ppMaterials[4]);
		S_Windows_2->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[37] = S_Windows_2;

		CGameObject* S_end_2 = new CGameObject(11);
		S_end_2->SetMesh(0, Sang_end_2);
		S_end_2->SetMaterial(ppMaterials[4]);
		S_end_2->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[38] = S_end_2;
		

		CGameObject* S_Start_3 = new CGameObject(11);
		S_Start_3->SetMesh(0, Sang_start_3);
		S_Start_3->SetMaterial(ppMaterials[4]);
		S_Start_3->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[39] = S_Start_3;

		CGameObject* S_Windows_3 = new CGameObject(11);
		S_Windows_3->SetMesh(0, Sang_windows_3);
		S_Windows_3->SetMaterial(ppMaterials[4]);
		S_Windows_3->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[40] = S_Windows_3;

		CGameObject* S_end_3 = new CGameObject(11);
		S_end_3->SetMesh(0, Sang_end_3);
		S_end_3->SetMaterial(ppMaterials[4]);
		S_end_3->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_3->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[41] = S_end_3;


		CGameObject* S_Start_4 = new CGameObject(11);
		S_Start_4->SetMesh(0, Sang_start_4);
		S_Start_4->SetMaterial(ppMaterials[4]);
		S_Start_4->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[42] = S_Start_4;

		CGameObject* S_Windows_4 = new CGameObject(11);
		S_Windows_4->SetMesh(0, Sang_windows_4);
		S_Windows_4->SetMaterial(ppMaterials[4]);
		S_Windows_4->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[43] = S_Windows_4;

		CGameObject* S_end_4 = new CGameObject(11);
		S_end_4->SetMesh(0, Sang_end_4);
		S_end_4->SetMaterial(ppMaterials[4]);
		S_end_4->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_4->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[44] = S_end_4;


		CGameObject* S_Start_5 = new CGameObject(11);
		S_Start_5->SetMesh(0, Sang_start_5);
		S_Start_5->SetMaterial(ppMaterials[4]);
		S_Start_5->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_5->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[45] = S_Start_5;

		CGameObject* S_Windows_5 = new CGameObject(11);
		S_Windows_5->SetMesh(0, Sang_windows_5);
		S_Windows_5->SetMaterial(ppMaterials[4]);
		S_Windows_5->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_5->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[46] = S_Windows_5;

		CGameObject* S_end_5 = new CGameObject(11);
		S_end_5->SetMesh(0, Sang_end_5);
		S_end_5->SetMaterial(ppMaterials[4]);
		S_end_5->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_5->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[47] = S_end_5;


		CGameObject* S_Start_6 = new CGameObject(11);
		S_Start_6->SetMesh(0, Sang_start_6);
		S_Start_6->SetMaterial(ppMaterials[4]);
		S_Start_6->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_6->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[48] = S_Start_6;

		CGameObject* S_Windows_6 = new CGameObject(11);
		S_Windows_6->SetMesh(0, Sang_windows_6);
		S_Windows_6->SetMaterial(ppMaterials[4]);
		S_Windows_6->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_6->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[49] = S_Windows_6;

		CGameObject* S_end_6 = new CGameObject(11);
		S_end_6->SetMesh(0, Sang_end_6);
		S_end_6->SetMaterial(ppMaterials[4]);
		S_end_6->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_6->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[50] = S_end_6;

		CGameObject* S_Start_7 = new CGameObject(11);
		S_Start_7->SetMesh(0, Sang_start_7);
		S_Start_7->SetMaterial(ppMaterials[4]);
		S_Start_7->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_7->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[51] = S_Start_7;

		CGameObject* S_Windows_7 = new CGameObject(11);
		S_Windows_7->SetMesh(0, Sang_windows_7);
		S_Windows_7->SetMaterial(ppMaterials[4]);
		S_Windows_7->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_7->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[52] = S_Windows_7;

		CGameObject* S_end_7 = new CGameObject(11);
		S_end_7->SetMesh(0, Sang_end_7);
		S_end_7->SetMaterial(ppMaterials[4]);
		S_end_7->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_7->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[53] = S_end_7;


		CGameObject* S_Start_8 = new CGameObject(11);
		S_Start_8->SetMesh(0, Sang_start_8);
		S_Start_8->SetMaterial(ppMaterials[4]);
		S_Start_8->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_8->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[54] = S_Start_8;

		CGameObject* S_Windows_8 = new CGameObject(11);
		S_Windows_8->SetMesh(0, Sang_windows_8);
		S_Windows_8->SetMaterial(ppMaterials[4]);
		S_Windows_8->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_8->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[55] = S_Windows_8;

		CGameObject* S_end_8 = new CGameObject(11);
		S_end_8->SetMesh(0, Sang_end_8);
		S_end_8->SetMaterial(ppMaterials[4]);
		S_end_8->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_8->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[56] = S_end_8;


		CGameObject* S_Start_9 = new CGameObject(11);
		S_Start_9->SetMesh(0, Sang_start_9);
		S_Start_9->SetMaterial(ppMaterials[4]);
		S_Start_9->SetPosition(0.0f, 0.0f, 0.0f);
		S_Start_9->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[57] = S_Start_9;

		CGameObject* S_Windows_9 = new CGameObject(11);
		S_Windows_9->SetMesh(0, Sang_windows_9);
		S_Windows_9->SetMaterial(ppMaterials[4]);
		S_Windows_9->SetPosition(0.0f, 0.0f, 0.0f);
		S_Windows_9->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[58] = S_Windows_9;

		CGameObject* S_end_9 = new CGameObject(11);
		S_end_9->SetMesh(0, Sang_end_9);
		S_end_9->SetMaterial(ppMaterials[4]);
		S_end_9->SetPosition(0.0f, 0.0f, 0.0f);
		S_end_9->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[59] = S_end_9;


		CGameObject* S_Terrain2 = new CGameObject(11);
		S_Terrain2->SetMesh(0, s_terrain2);
		S_Terrain2->SetMaterial(ppMaterials[1]);
		S_Terrain2->SetPosition(0.0f, 0.0f, 0.0f);
		S_Terrain2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[60] = S_Terrain2;

		CGameObject* S_Terrain2_Middle = new CGameObject(11);
		S_Terrain2_Middle->SetMesh(0, s_terrain2_middle);
		S_Terrain2_Middle->SetMaterial(ppMaterials[3]);
		S_Terrain2_Middle->SetPosition(0.0f, 0.0f, 0.0f);
		S_Terrain2_Middle->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[61] = S_Terrain2_Middle;

		CGameObject* Sang_Windows_1_1 = new CGameObject(11);
		Sang_Windows_1_1->SetMesh(0, Sang_windows_1_1);
		Sang_Windows_1_1->SetMaterial(ppMaterials[4]);
		Sang_Windows_1_1->SetPosition(0.0f, 0.0f, 0.0f);
		Sang_Windows_1_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[62] = Sang_Windows_1_1;


		CGameObject* Sang_Windows_2_1 = new CGameObject(11);
		Sang_Windows_2_1->SetMesh(0, Sang_windows_2_1);
		Sang_Windows_2_1->SetMaterial(ppMaterials[4]);
		Sang_Windows_2_1->SetPosition(0.0f, 0.0f, 0.0f);
		Sang_Windows_2_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[63] = Sang_Windows_2_1;

		CGameObject* Sang_Windows_3_1 = new CGameObject(11);
		Sang_Windows_3_1->SetMesh(0, Sang_windows_3_1);
		Sang_Windows_3_1->SetMaterial(ppMaterials[4]);
		Sang_Windows_3_1->SetPosition(0.0f, 0.0f, 0.0f);
		Sang_Windows_3_1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[64] = Sang_Windows_3_1;

		CGameObject* M_Errain1 = new CGameObject(11);
		M_Errain1->SetMesh(0, M_errain1);
		M_Errain1->SetMaterial(ppMaterials[3]);
		M_Errain1->SetPosition(0.0f, 0.0f, 0.0f);
		M_Errain1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[65] = M_Errain1;


		CGameObject* H_Errain1 = new CGameObject(11);
		H_Errain1->SetMesh(0, H_errain1);
		H_Errain1->SetMaterial(ppMaterials[4]);
		H_Errain1->SetPosition(0.0f, 0.0f, 0.0f);
		H_Errain1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[66] = H_Errain1;

		CGameObject* Terrain2_High = new CGameObject(11);
		Terrain2_High->SetMesh(0, terrain2_High);
		Terrain2_High->SetMaterial(ppMaterials[4]);
		Terrain2_High->SetPosition(0.0f, 0.0f, 0.0f);
		Terrain2_High->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[67] = Terrain2_High;


		CGameObject* S_Terrain2_High = new CGameObject(11);
		S_Terrain2_High->SetMesh(0, s_terrain2_High);
		S_Terrain2_High->SetMaterial(ppMaterials[4]);
		S_Terrain2_High->SetPosition(0.0f, 0.0f, 0.0f);
		S_Terrain2_High->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[68] = S_Terrain2_High;

		CGameObject* M_Tonglo_Wall1 = new CGameObject(11);
		M_Tonglo_Wall1->SetMesh(0, Merrain_tonglo_wall1);
		M_Tonglo_Wall1->SetMaterial(ppMaterials[3]);
		M_Tonglo_Wall1->SetPosition(0.0f, 0.0f, 0.0f);
		M_Tonglo_Wall1->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[69] = M_Tonglo_Wall1;

		CGameObject* M_Tonglo_Wall2 = new CGameObject(11);
		M_Tonglo_Wall2->SetMesh(0, Merrain_tonglo_wall2);
		M_Tonglo_Wall2->SetMaterial(ppMaterials[3]);
		M_Tonglo_Wall2->SetPosition(0.0f, 0.0f, 0.0f);
		M_Tonglo_Wall2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[70] = M_Tonglo_Wall2;


		CGameObject* D_terrain2 = new CGameObject(11);
		D_terrain2->SetMesh(0, d_terrain2);
		D_terrain2->SetMaterial(ppMaterials[4]);
		D_terrain2->SetPosition(0.0f, 0.0f, 0.0f);
		D_terrain2->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
		m_ppObjects[71] = D_terrain2;

		/*
		for (int i = 0; i < objList.size(); ++i)
		{
			m_ppObjects[i + 1] = objList[i];
		}
		*/
	
	
}

void CGroundShader::ReleaseObjects()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++)
			if (m_ppObjects[j])
				delete m_ppObjects[j];
		delete[] m_ppObjects;
	}
}
void CGroundShader::AnimateObjects(float fTimeElapsed)
{
	for (int j = 0; j < m_nObjects; j++)
	{
		m_ppObjects[j]->Animate(fTimeElapsed);
	}
}
void CGroundShader::ReleaseUploadBuffers()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++) m_ppObjects[j]->ReleaseUploadBuffers();
	}
}
void CGroundShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	CTexturedShader::Render(pd3dCommandList);
	/**/
	UpdateShaderVariables(pd3dCommandList);

	for (int j = 0; j < m_nObjects; j++)
	{
		if (m_ppObjects[j])
		{
			m_ppObjects[j]->Render(pd3dCommandList, 1);
		}
	}
}
void CGroundShader::movePlayer(float x, float y, float z)
{
	m_ppObjects[m_nObjects - 1]->MoveForward(z);
	m_ppObjects[m_nObjects - 1]->MoveStrafe(x);
	m_ppObjects[m_nObjects - 1]->MoveUp(y);
}
void CGroundShader::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255); //256의 배수
	m_pd3dcbGameObjects = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes * m_nObjects, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);

	m_pd3dcbGameObjects->Map(0, NULL, (void**)&m_pcbMappedGameObjects);
}
	 
void CGroundShader::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255);
	for (int j = 0; j < m_nObjects; j++)
	{
		CB_GAMEOBJECT_INFO* pbMappedcbGameObject = (CB_GAMEOBJECT_INFO*)((UINT8*)m_pcbMappedGameObjects + (j * ncbElementBytes));
		XMStoreFloat4x4(&pbMappedcbGameObject->m_xmf4x4World, XMMatrixTranspose(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World)));
	}
}
	 
void CGroundShader::ReleaseShaderVariables()
{
	if (m_pd3dcbGameObjects)
	{
		m_pd3dcbGameObjects->Unmap(0, NULL);
		m_pd3dcbGameObjects->Release();
	}

	CTexturedShader::ReleaseShaderVariables();
}

//////////////////////////////////////////////////////////////////////////////


CBillboardShader::CBillboardShader(int nobj, FbxManager* m) : CObjectsShader(nobj)
{
	m_nObjects = nobj;
	manager = m;
}
CBillboardShader::~CBillboardShader()
{
}

/**/
void CBillboardShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature* pd3dGraphicsRootSignature)
{

	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

#define TEXTURESBILL		5

D3D12_SHADER_BYTECODE CBillboardShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSBill", "vs_5_1", ppd3dShaderBlob));
}

D3D12_SHADER_BYTECODE CBillboardShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSBill", "ps_5_1", ppd3dShaderBlob));
}

void CBillboardShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList, void* pContext)
{
	//텍스처 생성
	//CTexture* ppTextures[TEXTURESBILL];

	ppTextures[0] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[0]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"sample.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[1] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[1]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Metal01.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[2] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[2]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Metal02.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[3] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[3]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Rock01.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[4] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[4]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"Lava(Emissive).dds", RESOURCE_TEXTURE2D, 0);

	// 뷰 생성
	m_nObjects = 1;

	CMaterial* ppMaterials[TEXTURESBILL];
	for (int i = 0; i < TEXTURESBILL; i++)
	{
		ppMaterials[i] = new CMaterial();
		ppMaterials[i]->SetTexture(ppTextures[i]);
	}

	CreateCbvSrvDescriptorHeaps(pd3dDevice, m_nObjects, TEXTURESBILL);
	CreateShaderVariables(pd3dDevice, pd3dCommandList);
	CreateConstantBufferViews(pd3dDevice, m_nObjects, m_pd3dcbGameObjects, ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255));
	/**/
	for (int i = 0; i < TEXTURESBILL; i++)
	{
		CreateShaderResourceViews(pd3dDevice, ppTextures[i], 0, 4);
	}

	
	m_ppObjects = new CGameObject * [m_nObjects];
	
	FbxScene* pfbxMonsterModel = ::LoadFbxSceneFromFile(pd3dDevice, pd3dCommandList, manager, "sample.fbx");
	CreateMeshFromFbxNodeHierarchy(pd3dDevice, pd3dCommandList, pfbxMonsterModel->GetRootNode(), 3);



	//애니메이션 정보 불러오는 방법

	CFbxScene* pFbxMonsterModel = new CFbxScene(pfbxMonsterModel);



	// 이 게임 객체에 fbx 씬과 애니메이션 컨트롤러 객체가 들어감.
	m_ppObjects[0] = new CMonsterObject(pd3dDevice, pd3dCommandList, manager, pFbxMonsterModel, 0, m_d3dSrvGPUDescriptorNextHandle);
	m_ppObjects[0]->SetMaterial(ppMaterials[0]);
	m_ppObjects[0]->currentMaterial = 0;
	m_ppObjects[0]->SetAnimationStack(11);
	//11이 서있기, 20이 걷기.
	m_ppObjects[0]->m_pAnimationController->SetPosition(11, 0.0f);
	m_ppObjects[0]->SetPosition(0.0f, 0.0f, 0.0f);   
	m_ppObjects[0]->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * (m_nObjects - 1)));



	
}

void CBillboardShader::ReleaseObjects()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++)
			if (m_ppObjects[j])
				delete m_ppObjects[j];
		delete[] m_ppObjects;
	}
}
void CBillboardShader::AnimateObjects(float fTimeElapsed)
{
	for (int j = 0; j < m_nObjects; j++)
	{
		m_ppObjects[j]->Animate(fTimeElapsed);
	}
}
void CBillboardShader::ReleaseUploadBuffers()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++) m_ppObjects[j]->ReleaseUploadBuffers();
	}
}
void CBillboardShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)//여기서부터 시작.
{
	CTexturedShader::Render(pd3dCommandList);
	/**/
	UpdateShaderVariables(pd3dCommandList);
	// 각 게임 개체의 변환 행렬을 hlsl로 보낸다.
	
	for (int j = 0; j < m_nObjects; j++)
	{
		if (m_ppObjects[j])
		{
			m_ppObjects[j]->Render(pd3dCommandList, 3);//CGameObject::Render() 함수 호출
		}
	}
}
void CBillboardShader::movePlayer(int dir, float dist)
{
	if (dir == 1) // UP
	{
		m_ppObjects[m_nObjects - 1]->SetPosition(m_ppObjects[m_nObjects - 1]->GetPosition().x , 0,
			m_ppObjects[m_nObjects - 1]->GetPosition().z + dist);

		m_ppObjects[m_nObjects - 1]->Rotate(0.0f, 0.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ, 0.0f);
		m_ppObjects[m_nObjects - 1]->currentRotationZ += 0.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ;
	}
	else if (dir == 2)//DOWN
	{
		m_ppObjects[m_nObjects - 1]->SetPosition(m_ppObjects[m_nObjects - 1]->GetPosition().x, 0,
			m_ppObjects[m_nObjects - 1]->GetPosition().z - dist);
		m_ppObjects[m_nObjects - 1]->Rotate(0.0f, 180.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ, 0.0f);
		m_ppObjects[m_nObjects - 1]->currentRotationZ += 180.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ;
	}
	else if (dir == 3)//LEFT
	{
		m_ppObjects[m_nObjects - 1]->SetPosition(m_ppObjects[m_nObjects - 1]->GetPosition().x - dist, 0,
			m_ppObjects[m_nObjects - 1]->GetPosition().z);
		m_ppObjects[m_nObjects - 1]->Rotate(0.0f, 270.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ, 0.0f);
		m_ppObjects[m_nObjects - 1]->currentRotationZ += 270.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ;
	}
	else if (dir == 4)//RIGHT
	{
		m_ppObjects[m_nObjects - 1]->SetPosition(m_ppObjects[m_nObjects - 1]->GetPosition().x + dist, 0,
			m_ppObjects[m_nObjects - 1]->GetPosition().z);
		m_ppObjects[m_nObjects - 1]->Rotate(0.0f, 90.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ, 0.0f);
		m_ppObjects[m_nObjects - 1]->currentRotationZ += 90.0f - m_ppObjects[m_nObjects - 1]->currentRotationZ;
	}
	CMaterial* ppMaterials[TEXTURESBILL];
	for (int i = 0; i < TEXTURESBILL; i++)
	{
		ppMaterials[i] = new CMaterial();
		ppMaterials[i]->SetTexture(ppTextures[i]);
	}
	m_ppObjects[m_nObjects - 1]->SetAnimationStack(20);
	if (m_ppObjects[0]->currentMaterial == 0)
	{
		m_ppObjects[0]->SetMaterial(ppMaterials[1]);
		m_ppObjects[0]->currentMaterial = 1;
	}
}
void CBillboardShader::StopPlayer()
{

	CMaterial* ppMaterials[TEXTURESBILL];
	for (int i = 0; i < TEXTURESBILL; i++)
	{
		ppMaterials[i] = new CMaterial();
		ppMaterials[i]->SetTexture(ppTextures[i]);

	}

	m_ppObjects[m_nObjects - 1]->SetAnimationStack(11);
	m_ppObjects[0]->m_pAnimationController->SetPosition(11, 0.0f);

	if (m_ppObjects[0]->currentMaterial == 1)
	{
		m_ppObjects[0]->SetMaterial(ppMaterials[0]);
		m_ppObjects[0]->currentMaterial = 0;
	}
	
}
void CBillboardShader::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255); //256의 배수
	m_pd3dcbGameObjects = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes * m_nObjects, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);

	m_pd3dcbGameObjects->Map(0, NULL, (void**)&m_pcbMappedGameObjects);
}
void CBillboardShader::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255);
	for (int j = 0; j < m_nObjects; j++)
	{
		CB_GAMEOBJECT_INFO* pbMappedcbGameObject = (CB_GAMEOBJECT_INFO*)((UINT8*)m_pcbMappedGameObjects + (j * ncbElementBytes));
		XMStoreFloat4x4(&pbMappedcbGameObject->m_xmf4x4World, XMMatrixTranspose(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World)));
	}
}
void CBillboardShader::ReleaseShaderVariables()
{
	if (m_pd3dcbGameObjects)
	{
		m_pd3dcbGameObjects->Unmap(0, NULL);
		m_pd3dcbGameObjects->Release();
	}

	CTexturedShader::ReleaseShaderVariables();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CFbxModelShader::CFbxModelShader()
{
}

CFbxModelShader::~CFbxModelShader()
{
}

D3D12_INPUT_LAYOUT_DESC CFbxModelShader::CreateInputLayout()
{
	UINT nInputElementDescs = 1;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC CFbxModelShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	//	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_BACK;
#ifdef _WITH_LEFT_HAND_COORDINATES
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
#else
	d3dRasterizerDesc.FrontCounterClockwise = TRUE;
#endif
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return(d3dRasterizerDesc);
}

D3D12_SHADER_BYTECODE CFbxModelShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSFbxModel", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE CFbxModelShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSFbxModel", "ps_5_1", &m_pd3dPixelShaderBlob));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CFbxSkinnedModelShader::CFbxSkinnedModelShader(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{


}

CFbxSkinnedModelShader::~CFbxSkinnedModelShader()
{
}

D3D12_INPUT_LAYOUT_DESC CFbxSkinnedModelShader::CreateInputLayout()
{
	UINT nInputElementDescs = 4;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "BONEINDEX", 0, DXGI_FORMAT_R32G32B32A32_UINT, 1, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[2] = { "BONEWEIGHT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 2, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[3] = { "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 3, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC CFbxSkinnedModelShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	//	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
#ifdef _WITH_LEFT_HAND_COORDINATES
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
#else
	d3dRasterizerDesc.FrontCounterClockwise = TRUE;
#endif
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return(d3dRasterizerDesc);
}

D3D12_SHADER_BYTECODE CFbxSkinnedModelShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSFbxSkinnedModel", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE CFbxSkinnedModelShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSFbxSkinnedModel", "ps_5_1", &m_pd3dPixelShaderBlob));
}





//////////////////////////
///////////////////////////////////



