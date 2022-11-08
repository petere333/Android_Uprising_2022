#include "MainInterfaceShader.h"


MainInterfaceShader::MainInterfaceShader(ResourceManager* r)
{
	rm = r;
	lastNotify = chrono::system_clock::now();
}
MainInterfaceShader::~MainInterfaceShader() {}

void MainInterfaceShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	
	//윈도우 크기 450픽셀당 1.0f로 환산.

	CubeMeshOffset* bg = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* bg2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.02f, 0.0f, 0.0f, false);
	CubeMeshOffset* main2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.02f, 0.0f, 0.0f, true);
	

	//로그아웃 버튼 위치 184, 152 클릭 범위 = 111, 86
	//즉 위치 = -(184-600)/450, -(152-450)/450
	//범위 = (111*2)/450, 86/450
	CubeMeshOffset* logout = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 222.0f/450.0f, 86.0f/450.0f, 0.02f, 416.0f/450.0f, 298.0f/450.0f, false);
	CubeMeshOffset* logoutr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 222.0f / 450.0f, 86.0f / 450.0f, 0.02f, 416.0f/450.0f, 298.0f/450.0f, true);

	CubeMeshOffset* info = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (236.0f-600.0f) / 450.0f, -(745.0f-450.0f) / 450.0f, false);
	CubeMeshOffset* infor = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (236.0f - 600.0f) / 450.0f, -(745.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* shop = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (604.0f - 600.0f) / 450.0f, -(2000.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* shopr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (604.0f - 600.0f) / 450.0f, -(2000.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* stage = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (972.0f - 600.0f) / 450.0f, -(750.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* stager = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 274.0f / 450.0f, 86.0f / 450.0f, 0.02f, (972.0f - 600.0f) / 450.0f, -(750.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* exit = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 600.0f / 450.0f, 450.0f / 450.0f, 0.03f, -(600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* yes = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 141.0f / 450.0f, 48.0f / 450.0f, 0.03f, -(512.0f - 600.0f) / 450.0f, -(546.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* no = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 141.0f / 450.0f, 48.0f / 450.0f, 0.03f, -(698.0f - 600.0f) / 450.0f, -(546.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* exitr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 600.0f / 450.0f, 450.0f / 450.0f, 0.03f, -(600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* yesr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 141.0f / 450.0f, 48.0f / 450.0f, 0.03f, -(512.0f - 600.0f) / 450.0f, -(546.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* nor = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 141.0f / 450.0f, 48.0f / 450.0f, 0.03f, -(698.0f - 600.0f) / 450.0f, -(546.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* notify = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 399.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(604.0f - 600.0f) / 450.0f, -(316.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* playernum = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(814.0f - 600.0f) / 450.0f, -(316.0f - 450.0f) / 450.0f, false);

	CubeMeshOffset* notifyr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 399.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(604.0f - 600.0f) / 450.0f, -(316.0f - 450.0f) / 450.0f, true);
	CubeMeshOffset* playernumr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 20.0f / 450.0f, 30.0f / 450.0f, 0.03f, -(814.0f - 600.0f) / 450.0f, -(316.0f - 450.0f) / 450.0f, true);

	meshes.push_back(bg);
	meshesRev.push_back(bg2);


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

	//6~8 나가기창
	meshes.push_back(exit);
	meshes.push_back(yes);
	meshes.push_back(no);

	meshesRev.push_back(exitr);
	meshesRev.push_back(yesr);
	meshesRev.push_back(nor);

	//9~10 알림문구
	meshes.push_back(notify);
	meshes.push_back(playernum);
	
	meshesRev.push_back(notifyr);
	meshesRev.push_back(playernumr);

	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj = new UIObject(1, -1,-1,-1,-1,-1);
	UIObject* obj2 = new UIObject(1, 905, 132, 1127, 218, 215);
	UIObject* obj3 = new UIObject(1, 99, 725, 373, 811, 224);
	UIObject* obj4 = new UIObject(1, 467, 727, 741, 813, 218);
	UIObject* obj5 = new UIObject(1, 835, 730, 1109, 816, 221);
	
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj9 = new UIObject(1, -1, -1, -1, -1, -1);

	UIObject* obj10 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj11 = new UIObject(1, -1, -1, -1, -1, -1);
	

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

	obj6->SetMesh(meshes[5]);
	obj6->SetMaterial(0, rm->materials[322]);
	obj6->SetPosition(0.0f, 0.0f, 0.0f);

	obj7->SetMesh(meshes[6]);
	obj7->SetMaterial(0, rm->materials[670]);
	obj7->SetPosition(0.0f, 0.0f, 0.0f);

	obj8->SetMesh(meshes[7]);
	obj8->SetMaterial(0, rm->materials[666]);
	obj8->SetPosition(0.0f, 0.0f, 0.0f);

	obj9->SetMesh(meshes[8]);
	obj9->SetMaterial(0, rm->materials[668]);
	obj9->SetPosition(0.0f, 0.0f, 0.0f);

	obj10->SetMesh(meshes[9]);
	obj10->SetMaterial(0, rm->materials[671]);
	obj10->SetPosition(0.0f, 0.0f, 0.0f);

	obj11->SetMesh(meshes[10]);
	obj11->SetMaterial(0, rm->materials[252]);
	obj11->SetPosition(0.0f, 0.0f, 0.0f);

	objects.push_back(obj6);
	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
	objects.push_back(obj4);
	objects.push_back(obj5);

	objects.push_back(obj7);
	objects.push_back(obj9);
	objects.push_back(obj8);

	objects.push_back(obj10);
	objects.push_back(obj11);
	
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
	d3dRasterizerDesc.FrontCounterockwise = FALSE;
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

	if (quit == false)
	{
		objects[6]->SetMesh(NULL);
		objects[7]->SetMesh(NULL);
		objects[8]->SetMesh(NULL);
	}
	else
	{
		if (cl.z < 0)
		{
			objects[6]->SetMesh(meshesRev[6]);
			objects[7]->SetMesh(meshesRev[7]);
			objects[8]->SetMesh(meshesRev[8]);
		}
		else
		{
			objects[6]->SetMesh(meshes[6]);
			objects[7]->SetMesh(meshes[7]);
			objects[8]->SetMesh(meshes[8]);
		}
	}

	//접속/종료 알림 뜬 지 4초 경과 시 지우기
	chrono::duration<double> elapsed = chrono::system_clock::now() - lastNotify;
	if (elapsed.count() > 4.0)
	{
		objects[9]->SetMesh(NULL);
		objects[10]->SetMesh(NULL);
		
	}
	else
	{
		if (cl.z < 0.0f)
		{
			objects[9]->SetMesh(meshes[9]);
			objects[10]->SetMesh(meshes[10]);
			
		}
		else
		{
			objects[9]->SetMesh(meshes[9]);
			objects[10]->SetMesh(meshes[10]);
		
		}
	}
	

	//	XMFLOAT3 p = objects[1]->GetPosition();
	//objects[1]->SetPosition(p.x+ cu.x, p.y+cu.y, p.z+cu.z);
}