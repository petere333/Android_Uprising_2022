

#include "Shader.h"
CShader::CShader()
{
	m_d3dSrvCPUDescriptorStartHandle.ptr = NULL;
	m_d3dSrvGPUDescriptorStartHandle.ptr = NULL;
}

CShader::~CShader()
{
	if (m_ppd3dPipelineStates)
	{
		for (int i = 0; i < m_nPipelineStates; i++) if (m_ppd3dPipelineStates[i])
			m_ppd3dPipelineStates[i]->Release();
		delete[] m_ppd3dPipelineStates;
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
D3D12_SHADER_BYTECODE CShader::CompileShaderFromFile(WCHAR* pszFileName, LPCSTR
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
void CShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature
	* pd3dGraphicsRootSignature)
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
	pd3dDevice->CreateGraphicsPipelineState(&d3dPipelineStateDesc,
		__uuidof(ID3D12PipelineState), (void**)&m_ppd3dPipelineStates[0]);
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
	pd3dCommandList->SetPipelineState(m_ppd3dPipelineStates[0]);
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
void CShader::UpdateShaderVariable(ID3D12GraphicsCommandList* pd3dCommandList, XMFLOAT4X4
	* pxmf4x4World)
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
	m_nPipelineStates = 1;
	m_ppd3dPipelineStates = new ID3D12PipelineState * [m_nPipelineStates];
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

/////////////////////////////////////////////////////////////////////

CObjectsShader::CObjectsShader()
{
}
CObjectsShader::~CObjectsShader()
{
}

/**/
void CObjectsShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature* pd3dGraphicsRootSignature)
{
	m_nPipelineStates = 1;
	m_ppd3dPipelineStates = new ID3D12PipelineState * [m_nPipelineStates];
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

void CObjectsShader::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255); //256의 배수
	m_pd3dcbGameObjects = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes * m_nObjects, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);

	m_pd3dcbGameObjects->Map(0, NULL, (void**)&m_pcbMappedGameObjects);
}

void CObjectsShader::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255);
	for (int j = 0; j < m_nObjects; j++)
	{
		CB_GAMEOBJECT_INFO* pbMappedcbGameObject = (CB_GAMEOBJECT_INFO*)((UINT8*)m_pcbMappedGameObjects + (j * ncbElementBytes));
		XMStoreFloat4x4(&pbMappedcbGameObject->m_xmf4x4World, XMMatrixTranspose(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World)));
	}
}

void CObjectsShader::ReleaseShaderVariables()
{
	if (m_pd3dcbGameObjects)
	{
		m_pd3dcbGameObjects->Unmap(0, NULL);
		m_pd3dcbGameObjects->Release();
	}

	CTexturedShader::ReleaseShaderVariables();
}

#define TEXTURES		19

void CObjectsShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList, void* pContext)
{

	CTexture* ppTextures[TEXTURES];
	ppTextures[0] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[0]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/cont2.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[1] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[1]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/chons.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[2] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[2]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/WhitePaint.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[3] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[3]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/GreenPaint.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[4] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[4]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[5] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[5]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/box.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[6] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[6]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/table.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[7] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[7]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PalletTruck.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[8] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[8]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/bin.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[9] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[9]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/barrel.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[10] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[10]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/truck.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[11] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[11]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/상단.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[12] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[12]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/상단벽2.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[13] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[13]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/wood.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[14] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[14]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Cont3.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[15] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[15]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/녹슨컨테이너.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[16] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[16]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Real_Contain.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[17] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[17]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PlateTexture.dds", RESOURCE_TEXTURE2D, 0);
	ppTextures[18] = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	ppTextures[18]->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	std::vector<Obj> data = LoadObjects("res/map/objects.txt");

	m_nObjects = data.size();

	CreateCbvSrvDescriptorHeaps(pd3dDevice, m_nObjects, TEXTURES);
	CreateShaderVariables(pd3dDevice, pd3dCommandList);
	CreateConstantBufferViews(pd3dDevice, m_nObjects, m_pd3dcbGameObjects, ((sizeof(CB_GAMEOBJECT_INFO) + 255) & ~255));
	/**/
	for (int i = 0; i < TEXTURES; i++) CreateShaderResourceViews(pd3dDevice, ppTextures[i], 0, 2);

	CMaterial* ppMaterials[TEXTURES];
	for (int i = 0; i < TEXTURES; i++)
	{
		ppMaterials[i] = new CMaterial();
		ppMaterials[i]->SetTexture(ppTextures[i]);
	}

	CCubeMeshTextured* pPlayerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 1.7f, 1.0f);
	CCubeMeshTextured* ContMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 100.0f, 25.0f, 50.0f);
	CCubeMeshTextured* J_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 50.0f, 7.5f, 120.0f);
	CCubeMeshTextured* T_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 40.0f, 5.0f, 200.0f);
	CCubeMeshTextured* B_ConMesh1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 260.0f, 12.5f, 320.0f);
	CCubeMeshTextured* ChonJang = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 620.0f, 3.0f, 620.0f);
	//CCubeMeshTextured* pContainerMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 2.5f, 6.0f);
	//CCubeMeshTextured* Contain1_1 = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 10.0f, 25.0f, 20.0f);



	//CRectMeshTextured* pTileMesh = new CRectMeshTextured(pd3dDevice, pd3dCommandList, 2.5f, 2.5f);

	GridMesh* pGrid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);
	GridMesh* t_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 200.0f, 20.0f);
	GridMesh* Se_Grid = new GridMesh(pd3dDevice, pd3dCommandList, 600.0f, 600.0f);

	WallMeshHorizontal* hWall = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* hWall_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* vWall = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* vWall_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* vWall_S = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* vWall_SM = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* vWall_1S = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshVertical* vWall_1SM = new WallMeshVertical(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshVertical* vWall_H = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshHorizontal* hWall_H = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshVertical* frooms = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 2.5f);
	WallMeshVertical* frooms_H = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);
	WallMeshHorizontal* loadwall1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshHorizontal* loadwall2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 2.5f);
	WallMeshHorizontal* loadwall3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 200.0f, 7.5f);
	WallMeshVertical* Se_room_l1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* Se_room_l2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 2.5f);
	WallMeshVertical* Se_room_l3= new WallMeshVertical(pd3dDevice, pd3dCommandList, 550.0f, 7.5f);
	WallMeshVertical* Se_room_r1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* Se_room_r2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 2.5f);
	WallMeshVertical* Se_room_r3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 30.0f, 7.5f);
	WallMeshVertical* Se_rs1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* Se_rs2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshVertical* Se_rs3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshHorizontal* Se_fb1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* Se_fb2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 2.5f);
	WallMeshHorizontal* Se_fb3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);
	WallMeshVertical* Se_BS1_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 2.5f);
	WallMeshVertical* Se_BS1_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 2.5f);
	WallMeshVertical* Se_BS1_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 450.0f, 7.5f);
	WallMeshVertical* Se_BS2_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshVertical* Se_BS2_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshVertical* Se_BS2_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 390.0f, 7.5f);
	WallMeshVertical* Se_BS3_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 2.5f);
	WallMeshVertical* Se_BS3_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 2.5f);
	WallMeshVertical* Se_BS3_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 120.0f, 7.5f);
	WallMeshHorizontal* Se_BS4_1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshHorizontal* Se_BS4_2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 2.5f);
	WallMeshHorizontal* Se_BS4_3 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 390.0f, 7.5f);
	WallMeshVertical* Frst_lh = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 7.5f);

	WallMeshVertical* Bated_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* Bated_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* Bat_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshVertical* Bat_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 20.0f, 200.0f);
	WallMeshVertical* Bat_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshHorizontal* Bat_FB1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB_11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* Bat_FB_12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBated_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBated_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* SeBat_1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshVertical* SeBat_2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 20.0f, 200.0f);
	WallMeshVertical* SeBat_3 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 600.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB_11 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshHorizontal* SeBat_FB_12 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 620.0f, 10.0f);
	WallMeshVertical* add_wall1 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 5.0f);
	WallMeshVertical* add_wall2 = new WallMeshVertical(pd3dDevice, pd3dCommandList, 400.0f, 7.5f);

	WallMeshHorizontal* Add_Bak1 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 150.0f, 5.0f);
	WallMeshHorizontal* Add_Bak2 = new WallMeshHorizontal(pd3dDevice, pd3dCommandList, 150.0f, 7.5f);

	CLoadedMesh* container = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_container2.txt", NULL);
	CLoadedMesh* box = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_box.txt", NULL);
	CLoadedMesh* tableMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_table.txt", "res/idx_table.txt");
	CLoadedMesh* chairMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_chair3.txt", "res/idx_chair3.txt");
	CLoadedMesh* cartMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_pallet.txt", "res/idx_pallet.txt");
	CLoadedMesh* binMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_bin.txt", "res/idx_bin.txt");
	CLoadedMesh* barrelMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_barrel.txt", "res/idx_barrel.txt");
	CLoadedMesh* truckMesh = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_truck.txt", "res/idx_truck.txt");

	CLoadedMesh* Container1_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Cont1_1.txt", "res/idx_Cont1_1.txt");
	CLoadedMesh* GyeDan = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_GyeDan1.txt", NULL);
	CLoadedMesh* GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_GyeDan1.txt", NULL);
	CLoadedMesh* R_GyeDan_1 = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_GyeDan2.txt", NULL);
	CLoadedMesh* P_Doors = new CLoadedMesh(pd3dDevice, pd3dCommandList, "res/vtx_Doors.txt", NULL);
	boxesWorld = LoadBoxes("res/map/box.txt");


	m_ppObjects = new CGameObject * [m_nObjects];




	for (int i = 0; i < data.size(); ++i)
	{
		CGameObject* obj;

		if (data[i].type == PLAYER)//player
		{
			obj = new CPlayerObject(1);
			obj->SetMesh(0, barrelMesh);
			obj->SetMaterial(ppMaterials[9]);

		}
		else if (data[i].type == CONTAINER)//container
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, container);
			obj->SetMaterial(ppMaterials[0]);

		}
		else if (data[i].type == floor)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, pGrid);
			obj->SetMaterial(ppMaterials[17]);
		}
		else if (data[i].type == vWalls)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, vWall);
			obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == hWalls)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, hWall);
			obj->SetMaterial(ppMaterials[12]);
		
		}
		else if (data[i].type == BOX)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, box);
			obj->SetMaterial(ppMaterials[5]);
		}
		else if (data[i].type == PALLET)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, cartMesh);
			obj->SetMaterial(ppMaterials[7]);
		}
		else if (data[i].type == TRASH)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, binMesh);
			obj->SetMaterial(ppMaterials[8]);
		}
		else if (data[i].type == BARREL)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, barrelMesh);
			obj->SetMaterial(ppMaterials[9]);
		}
		else if (data[i].type == TRUCK)
		{
			obj = new CEnemyObject(1);
			obj->SetMesh(0, truckMesh);
			obj->SetMaterial(ppMaterials[10]);
		}
		else if (data[i].type == TABLE)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, tableMesh);
			obj->SetMaterial(ppMaterials[6]);
		}
		else if (data[i].type == CHAIR)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, chairMesh);
			obj->SetMaterial(ppMaterials[1]);
		}
		else if (data[i].type == vWalls_1)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, vWall_1);
			obj->SetMaterial(ppMaterials[2]);
		}
		else if (data[i].type == hWalls_1)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, hWall_1);
			obj->SetMaterial(ppMaterials[2]);
		}
		else if (data[i].type == vWalls_S)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, vWall_S);
			obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == vWalls_SM)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, vWall_SM);
			obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == vWalls_1S)
		{
			obj = new CTerrainObject(1);
			obj->SetMesh(0, vWall_1S);
			obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == vWalls_1SM)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, vWall_1SM);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == vWalls_H)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, vWall_H);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == hWalls_H)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, hWall_H);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == froom_set)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, frooms);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == froom_set_H)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, frooms_H);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == floor_T)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, t_Grid);
		obj->SetMaterial(ppMaterials[17]);
		}
		else if (data[i].type == loadwall_l)//container
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, loadwall1);
		obj->SetMaterial(ppMaterials[12]);

		}
		else if (data[i].type == loadwall_m)//container
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, loadwall2);
		obj->SetMaterial(ppMaterials[12]);

		}
		else if (data[i].type == loadwall_h)//container
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, loadwall3);
		obj->SetMaterial(ppMaterials[11]);

		}
		else if (data[i].type == floor_Se)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_Grid);
		obj->SetMaterial(ppMaterials[17]);
		}
		else if (data[i].type == Se_room_L1_1)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_room_l1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_L1_2)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_room_l2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_L1_3)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_room_l3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_room_R1_1)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_room_r1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_R1_2)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_room_r2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_R1_3)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_room_r3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_room_RSL)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_rs1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_RSM)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_rs2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_RSH)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_rs3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_room_FBL)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_fb1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_FBM)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_fb2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_room_FBH)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_fb3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok1_1)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS1_1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok1_2)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS1_2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok1_3)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS1_3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok2_1)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS2_1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok2_2)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS2_2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok2_3)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS2_3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok3_1)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS3_1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok3_2)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS3_2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok3_3)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS3_3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Se_Busok4_1)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS4_1);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok4_2)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS4_2);
		obj->SetMaterial(ppMaterials[12]);
		}
		else if (data[i].type == Se_Busok4_3)
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Se_BS4_3);
		obj->SetMaterial(ppMaterials[11]);
		}
		else if (data[i].type == Cont1_1)//container
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Container1_1);
		obj->Rotate(0.0f, 90.0f, 0.0f);
		obj->SetMaterial(ppMaterials[0]);

		}
		else if (data[i].type == Frs_H)//container
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Frst_lh);
		obj->SetMaterial(ppMaterials[11]);

		}
		else if (data[i].type == BatSet1)//지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_1);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == BatSet2)//지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_2);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == BatSet3)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_3);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_set1)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_FB1);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_set2)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_FB2);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == BatSet_1)// 지붕
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bated_1);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == BatSet_2)// 지붕
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bated_2);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_101)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_FB_11);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == Bat_FB_102)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Bat_FB_12);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet1)//지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBat_1);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet3)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBat_3);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_set1)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBat_FB1);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_set2)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBat_FB2);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet_1)// 지붕
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBated_1);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBatSet_2)// 지붕
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBated_2);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_101)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBat_FB_11);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == SeBat_FB_102)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, SeBat_FB_12);
		obj->SetMaterial(ppMaterials[1]);

		}
		else if (data[i].type == M_Contain)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, ContMesh1);
		obj->SetMaterial(ppMaterials[0]);

		}
		else if (data[i].type == J_Contain)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, J_ConMesh1);
		obj->SetMaterial(ppMaterials[14]);

		}
		else if (data[i].type == T_Contains)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, T_ConMesh1);
		obj->SetMaterial(ppMaterials[15]);

		}
		else if (data[i].type == B_Contain)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, B_ConMesh1);
		obj->SetMaterial(ppMaterials[16]);

		}
		else if (data[i].type == Shell)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, ChonJang);
		obj->SetMaterial(ppMaterials[18]);

		}
		else if (data[i].type == GyeDans1)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, GyeDan);
		obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == Frs_Pons1)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, add_wall1);
		obj->SetMaterial(ppMaterials[12]);

		}
		else if (data[i].type == Frs_Pons2)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, add_wall2);
		obj->SetMaterial(ppMaterials[11]);

		}
		else if (data[i].type == GyeDans2)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, GyeDan_1);
		 obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == R_GyeDan1)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, R_GyeDan_1);
		obj->Rotate(270.0f, 0.0f, 0.0f);

		}
		else if (data[i].type == adds_beok1)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Add_Bak1);
		obj->SetMaterial(ppMaterials[12]);

		}
		else if (data[i].type == adds_beok2)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, Add_Bak2);
		obj->SetMaterial(ppMaterials[11]);

		}
		else if (data[i].type == B_Door)// 지붕의 시작점
		{
		obj = new CTerrainObject(1);
		obj->SetMesh(0, P_Doors);
	//	obj->SetMaterial(ppMaterials[1]);
		obj->Rotate(270.0f, 0.0f, 0.0f);

		}

		obj->SetPosition(data[i].position.x, data[i].position.y, data[i].position.z);
		obj->Rotate(data[i].rotation.x, data[i].rotation.y, data[i].rotation.z);
		obj->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * i));
		m_ppObjects[i] = obj;
	}

}
void CObjectsShader::ReleaseObjects()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++)
			if (m_ppObjects[j])
				delete m_ppObjects[j];
		delete[] m_ppObjects;
	}
}
void CObjectsShader::AnimateObjects(float fTimeElapsed)
{
	XMFLOAT3 pos = m_ppObjects[0]->GetPosition();
	//위로 가속중인 경우 그냥 위로 이동
	if (m_ppObjects[0]->yspeed > 0.0f)
	{
		m_ppObjects[0]->SetPosition(pos.x, pos.y + m_ppObjects[0]->yspeed, pos.z);
		m_ppObjects[0]->isAir = true;
		addPlayerYSpeed(-0.1f);
	}
	//떨어지는 중인 경우
	else if (m_ppObjects[0]->yspeed < 0.0f)
	{
		//개체가 공중에 뜬 경우
		if (pos.y > 0.85f)
		{
			m_ppObjects[0]->isAir = true;
		}
		else
		{
			m_ppObjects[0]->isAir = false;
		}
		//공중에 뜬경우 프레임마다 밑 방향으로 가속
		if (playerInAir() == true)
		{
			addPlayerYSpeed(-0.1f);


			// 속도만큼 y축 이동 시 땅에 닿을 경우 강제로 땅 높이에 고정

			if (pos.y + m_ppObjects[0]->yspeed <= 0.85f)
			{
				m_ppObjects[0]->SetPosition(pos.x, 0.85f, pos.z);
				m_ppObjects[0]->yspeed = 0.0f;
				m_ppObjects[0]->isAir = false;
			}
			//안 닿을 경우 그대로 하강.
			else
			{
				m_ppObjects[0]->SetPosition(pos.x, pos.y + m_ppObjects[0]->yspeed, pos.z);
			}
		}
	}




	for (int j = 0; j < m_nObjects; j++)
	{

		m_ppObjects[j]->Animate(fTimeElapsed);
	}
}
void CObjectsShader::ReleaseUploadBuffers()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++) m_ppObjects[j]->ReleaseUploadBuffers();
	}
}
void CObjectsShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	CTexturedShader::Render(pd3dCommandList);
	/**/
	UpdateShaderVariables(pd3dCommandList);

	for (int j = 0; j < m_nObjects; j++)
	{
		if (m_ppObjects[j])
		{
			if (m_ppObjects[j]->isAlive == true)
			{
				m_ppObjects[j]->Render(pd3dCommandList);
			}
		}
	}
}
XMFLOAT3 CObjectsShader::getPlayerPosition()
{
	return m_ppObjects[0]->GetPosition();
}
bool CObjectsShader::movePlayer(float x, float y, float z)
{
	float tx = m_ppObjects[0]->GetPosition().x + x;
	float ty = m_ppObjects[0]->GetPosition().y + y;
	float tz = m_ppObjects[0]->GetPosition().z + z;
	bool crash = false;
	for (int i = 0; i < boxesWorld.size(); ++i)
	{
		if (tx > boxesWorld[i].start.x - 0.5f && ty > boxesWorld[i].start.y - 0.85f && tz > boxesWorld[i].start.z - 0.5f
			&& tx < boxesWorld[i].end.x + 0.5f && ty < boxesWorld[i].end.y + 0.85f && tz < boxesWorld[i].end.z + 0.5f)
		{
			crash = true;
		}
	}
	if (crash == false)
	{
		m_ppObjects[0]->SetPosition(tx, ty, tz);
		return true;
	}
	else
	{
		printf("cannot move\n");
		return false;
	}
}
void CObjectsShader::setAir(bool air)
{
	m_ppObjects[0]->isAir = air;
}
void CObjectsShader::addPlayerYSpeed(float delta)
{
	m_ppObjects[0]->yspeed += delta;
}

bool CObjectsShader::playerInAir()
{
	return m_ppObjects[0]->isAir;
}

void CObjectsShader::playerMeleeAttack()
{
	BoundBox bx;//공격 범위의 충돌 박스
	XMFLOAT3 pos = m_ppObjects[0]->GetPosition();
	bx.start = XMFLOAT3(pos.x - 0.5f, pos.y, pos.z + 0.2f);
	bx.end = XMFLOAT3(pos.x + 0.5f, pos.y + 0.5, pos.z + 1.0f);

	for (int i = 0; i < boxesWorld.size(); ++i)
	{
		if (isOverlapped(bx, boxesWorld[i]) == true)
		{
			if (m_ppObjects[i + 1]->isEnemy == true)
			{
				m_ppObjects[i + 1]->hp -= 1;
				if (m_ppObjects[i + 1]->hp <= 0)
				{
					m_ppObjects[i + 1]->isAlive = false;
					m_ppObjects[i + 1]->SetMesh(0, NULL);
					boxesWorld[i].start = XMFLOAT3(-99.99f, -99.99f, -99.99f);
					boxesWorld[i].end = XMFLOAT3(-99.9f, -99.9f, -99.9f);
				}
			}
		}
	}


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

D3D12_SHADER_BYTECODE CTexturedShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSTextured", "vs_5_1", ppd3dShaderBlob));
}

D3D12_SHADER_BYTECODE CTexturedShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSTextured", "ps_5_1", ppd3dShaderBlob));
}
void CTexturedShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature* pd3dGraphicsRootSignature)
{
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}


std::vector<Obj> LoadObjects(const char* filename)
{
	FILE* f = fopen(filename, "r");
	std::vector<Obj> list;

	while (!feof(f))
	{
		float f1, f2, f3;
		float r1, r2, r3;
		int t;
		fscanf(f, "position : (%f,  %f,  %f)  rotation : (%f,  %f,  %f)  type : %d\n", &f1, &f2, &f3, &r1, &r2, &r3, &t);

		Obj o;
		o.position = XMFLOAT3(f1, f2, f3);
		o.rotation = XMFLOAT3(r1, r2, r3);
		o.type = t;

		list.push_back(o);
	}
	return list;

}


std::vector<BoundBox> CObjectsShader::LoadBoxes(const char* filename)
{
	std::vector<BoundBox> result;
	FILE* f = fopen(filename, "r");
	while (!feof(f))
	{
		float x1, y1, z1, x2, y2, z2;
		BoundBox box;
		fscanf(f, "start : (%f,  %f,  %f)  end : (%f,  %f,  %f)\n", &x1, &y1, &z1, &x2, &y2, &z2);
		box.start = XMFLOAT3(x1, y1, z1);
		box.end = XMFLOAT3(x2, y2, z2);
		result.push_back(box);
	}
	return result;
}

std::vector<BoundSphere> CObjectsShader::LoadSphere(const char* filename)
{
	std::vector<BoundSphere> result;
	FILE* f = fopen(filename, "r");
	while (!feof(f))
	{
		float x1, y1, z1, dist;
		BoundSphere sphere;
		fscanf(f, "center : (%f,  %f,  %f)  range : %f\n", &x1, &y1, &z1, &dist);
		sphere.center = XMFLOAT3(x1, y1, z1);
		sphere.dist = dist;
		result.push_back(sphere);
	}
	return result;
}

bool isOverlapped(BoundBox b1, BoundBox b2)
{
	XMFLOAT3 pos[8];
	bool result = false;

	pos[0] = XMFLOAT3(b1.start.x, b1.start.y, b1.start.z);
	pos[1] = XMFLOAT3(b1.start.x, b1.end.y, b1.start.z);
	pos[2] = XMFLOAT3(b1.start.x, b1.start.y, b1.end.z);
	pos[3] = XMFLOAT3(b1.start.x, b1.end.y, b1.end.z);

	pos[4] = XMFLOAT3(b1.end.x, b1.start.y, b1.start.z);
	pos[5] = XMFLOAT3(b1.end.x, b1.end.y, b1.start.z);
	pos[6] = XMFLOAT3(b1.end.x, b1.start.y, b1.end.z);
	pos[7] = XMFLOAT3(b1.end.x, b1.end.y, b1.end.z);

	for (int i = 0; i < 8; ++i)
	{
		if (pos[i].x > b2.start.x && pos[i].x<b2.end.x && pos[i].y>b2.start.y && pos[i].y<b2.end.y && pos[i].z>b2.start.z && pos[i].z < b2.end.z)
		{
			result = true;
		}
	}
	return result;
}
