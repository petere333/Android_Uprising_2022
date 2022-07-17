#include "ProfileShader.h"


ProfileShader::ProfileShader(ResourceManager* r)
{
	rm = r;
	
}
ProfileShader::~ProfileShader() {}

void ProfileShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

	//윈도우 크기 450픽셀당 1.0f로 환산.

	// 메쉬 생성자 인자 : x크기, y크기, z크기, x중점, y중점

	//크기는 픽셀수/450, x중점은 (위치-600)/450, y중점은 크기 -(위치-450)/450

	//UI 개체 생성자 인자 : 1, x1, y1, x2, y2, idx

	// x1, y1, x2, y2는 클릭 영역의 시작점과 끝점 픽셀
	// idx는 버튼의 기본상태 텍스처 번호
	// 버튼이 아닌 객체들은 전부 -1로 설정
	
	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* mainr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* storage = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (202.0f - 600.0f) / 450.0f, -(697.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* storager = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (202.0f - 600.0f) / 450.0f, -(697.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* back = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (194.0f - 600.0f) / 450.0f, -(157.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* backr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 203.0f / 450.0f, 46.0f / 450.0f, 0.01f, (194.0f - 600.0f) / 450.0f, -(157.0f - 450.0f) / 450.0f, true);


	meshes.push_back(main);
	meshesRev.push_back(mainr);

	meshes.push_back(storage);
	meshesRev.push_back(storager);

	meshes.push_back(back);
	meshesRev.push_back(backr);


	

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, 100, 674,  304, 720, 228);
	UIObject* obj3 = new UIObject(1, 92, 134, 296, 180, 235);
	
	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[227]);
	obj->SetPosition(0.0f, 0.0f, 0.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[228]);
	obj2->SetPosition(0.0f, 0.0f, 0.0f);

	obj3->SetMesh(meshes[1]);
	obj3->SetMaterial(0, rm->materials[235]);
	obj3->SetPosition(0.0f, 0.0f, 0.0f);

	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
}

void ProfileShader::ReleaseObjects()
{

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Release();
			objects.erase(objects.begin() + i);
		}
	}
	objects.clear();
}
void ProfileShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void ProfileShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void ProfileShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC ProfileShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];

	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 1, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//pd3dInputElementDescs[2] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 2, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;

	return(d3dInputLayoutDesc);
}

D3D12_RASTERIZER_DESC ProfileShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
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

D3D12_DEPTH_STENCIL_DESC ProfileShader::CreateDepthStencilState()
{
	D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc;
	::ZeroMemory(&d3dDepthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));
	d3dDepthStencilDesc.DepthEnable = TRUE;
	d3dDepthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	d3dDepthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
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

D3D12_SHADER_BYTECODE ProfileShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE ProfileShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void ProfileShader::Animate(CCamera* cam, PlayerInfoManager* in)
{
	info = in;
	XMFLOAT3 cp = cam->getPosition();
	XMFLOAT3 cl = cam->getLook();
	XMFLOAT3 cr = cam->getRight();
	XMFLOAT3 cu = cam->getUp();
	float pitch = XMConvertToDegrees(atan(cl.y / sqrt(cl.x * cl.x + cl.z * cl.z)));

	float yaw = XMConvertToDegrees(atan(cl.x / cl.z));
	float roll = XMConvertToDegrees(atan(cl.x / cl.y));

	if (cl.z < 0)
	{
		pitch = -pitch;

	}

	for (int i = 0; i < objects.size(); ++i)
	{
		if (cl.z < 0)
		{
			objects[i]->SetMesh(meshesRev[i]);
		}
		else
		{
			objects[i]->SetMesh(meshes[i]);
		}
		
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y + cl.y, cp.z + cl.z);
	}
	
}