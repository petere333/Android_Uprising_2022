#include "MainInterfaceShader.h"


MainInterfaceShader::MainInterfaceShader(ResourceManager* r)
{
	rm = r;
}
MainInterfaceShader::~MainInterfaceShader() {}

void MainInterfaceShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	
	//윈도우 크기 450픽셀당 1.0f로 환산.

	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* main2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);
	

	//로그아웃 버튼 위치 184, 152 클릭 범위 = 111, 86
	//즉 위치 = (184-600)/450, (152-450)/450
	//범위 = (111*2)/450, 86/450
	CubeMeshOffset* logout = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 222.0f/450.0f, 86.0f/450.0f, 0.02f, -416.0f/450.0f, -298.0f/450.0f, false);
	CubeMeshOffset* logoutr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 222.0f / 450.0f, 86.0f / 450.0f, 0.02f, -416.0f/450.0f, -298.0f/450.0f, true);

	CubeMeshOffset* info = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (236.0f-600.0f) / 450.0f, (745.0f-450.0f) / 450.0f, false);
	CubeMeshOffset* infor = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (236.0f - 600.0f) / 450.0f, (745.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* shop = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (604.0f - 600.0f) / 450.0f, (747.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* shopr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (604.0f - 600.0f) / 450.0f, (747.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* stage = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (972.0f - 600.0f) / 450.0f, (750.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* stager = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (972.0f - 600.0f) / 450.0f, (750.0f - 450.0f) / 450.0f, true);

	meshes.push_back(main);
	meshesRev.push_back(main2);

	meshes.push_back(logout);
	meshesRev.push_back(logoutr);

	meshes.push_back(info);
	meshesRev.push_back(infor);
	meshes.push_back(shop);
	meshesRev.push_back(shopr);
	meshes.push_back(stage);
	meshesRev.push_back(stager);
	UIObject* obj = new UIObject(1, -1,-1,-1,-1,-1);
	UIObject* obj2 = new UIObject(1, 73, 109, 295, 195, 215);
	UIObject* obj3 = new UIObject(1, 99, 702, 373, 788, 224);
	UIObject* obj4 = new UIObject(1, 467, 704, 741, 790, 218);
	UIObject* obj5 = new UIObject(1, 835, 707, 1109, 793, 221);

	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[214]);
	obj->SetPosition(0.0f, 0.0f, 0.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[215]);
	obj2->SetPosition(0.0f, 0.0f, 0.0f);

	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[224]);
	obj3->SetPosition(0.0f, 0.0f, 0.0f);

	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[218]);
	obj4->SetPosition(0.0f, 0.0f, 0.0f);

	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[221]);
	obj5->SetPosition(0.0f, 0.0f, 0.0f);

	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
	objects.push_back(obj4);
	objects.push_back(obj5);
}

void MainInterfaceShader::ReleaseObjects()
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
void MainInterfaceShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void MainInterfaceShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void MainInterfaceShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC MainInterfaceShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC MainInterfaceShader::CreateRasterizerState()
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

D3D12_DEPTH_STENCIL_DESC MainInterfaceShader::CreateDepthStencilState()
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

D3D12_SHADER_BYTECODE MainInterfaceShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE MainInterfaceShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void MainInterfaceShader::Animate(CCamera* cam)
{
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
		/*
		if (objects[i]->defaultMesh != -1)
		{
			if (objects[i]->mouseOn == true)
			{
				if (objects[i]->meshChanged == false)
				{
					objects[i]->SetMaterial(0, rm->materials[objects[i]->defaultMesh + 1]);
					
					objects[i]->meshChanged = true;
				}
			}
			else
			{
				if (objects[i]->meshChanged == false)
				{
					objects[i]->SetMaterial(0, rm->materials[objects[i]->defaultMesh]);
					
					objects[i]->meshChanged = true;
				}
			}
		}
		*/
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y + cl.y, cp.z + cl.z);
	}
	//	XMFLOAT3 p = objects[1]->GetPosition();
	//objects[1]->SetPosition(p.x+ cu.x, p.y+cu.y, p.z+cu.z);
}