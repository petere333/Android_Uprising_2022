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

#define TEXTURES		1

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
	m_nObjects = 1;

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

	//ImageFile* heights = new ImageFile(L"HeightMap.raw", 257, 257, true);
	//ImageFile* objects = new ImageFile(L"ObjectsMap.raw", 257, 257, true);
	//CCubeMeshTextured* pCubeMesh = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 1.0f);
	//GridMesh* pGrid = new GridMesh(pd3dDevice, pd3dCommandList, 0, 0, 257, 257, XMFLOAT3(1.0f, 1.0f, 1.0f), heights);

	/*
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
				temp->SetMaterial(ppMaterials[1]);
				temp->SetPosition(x, pGrid->getData(x, z), z);
				temp->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * (objList.size() + 1)));
				objList.push_back(temp);
			}
		}
	}
	*/
	CCubeMeshTextured* terrain = new CCubeMeshTextured(pd3dDevice, pd3dCommandList, 2000.0f, 0.5f, 2000.0f);

	m_ppObjects = new CGameObject * [m_nObjects];


	CGameObject* pRotatingObject = NULL;

	pRotatingObject = new CGameObject(1);
	pRotatingObject->SetMesh(0, terrain);
	pRotatingObject->SetMaterial(ppMaterials[0]);
	pRotatingObject->SetPosition(0.0f, 0.0f, 0.0f);
	pRotatingObject->SetCbvGPUDescriptorHandlePtr(m_d3dCbvGPUDescriptorStartHandle.ptr + (::gnCbvSrvDescriptorIncrementSize * 0));
	m_ppObjects[0] = pRotatingObject;
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
void CBillboardShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	CTexturedShader::Render(pd3dCommandList);
	/**/
	UpdateShaderVariables(pd3dCommandList);
	
	for (int j = 0; j < m_nObjects; j++)
	{
		if (m_ppObjects[j])
		{
			m_ppObjects[j]->Render(pd3dCommandList, 3);
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
