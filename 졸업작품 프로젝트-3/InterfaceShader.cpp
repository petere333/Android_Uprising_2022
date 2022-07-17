#include "InterfaceShader.h"


InterfaceShader::InterfaceShader(ResourceManager* r) 
{ 
	rm = r; 
}
InterfaceShader::~InterfaceShader() {}

void InterfaceShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	CubeMeshOffset* mesh = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f/450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* meshr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);

	CubeMeshOffset* melee = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(50.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* meleer = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (50.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);
	
	CubeMeshOffset* range = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(90.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ranger = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (90.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* micro = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, -(130.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* micror = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 30.0f / 450.0f, 30.0f / 450.0f, 0.02f, (130.0f - 600.0f) / 450.0f, -(50.0f - 450.0f) / 450.0f, true);



	

	meshes.push_back(mesh);
	revmeshes.push_back(meshr);

	meshes.push_back(melee);
	revmeshes.push_back(meleer);
	meshes.push_back(range);
	revmeshes.push_back(ranger);
	meshes.push_back(micro);
	revmeshes.push_back(micror);

	//플레이어 체력바
	for (float i = 0.0f; i < 20.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(0.0f + 5.0f * (20.0f - i + 1.0f)) / 450.0f, -(500.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (0.0f + 5.0f * (20.0f - i + 1.0f)) / 450.0f, -(500.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}

	//근접경험치
	for (float i = 0.0f; i < 10.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(500.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(500.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}
	//원거리경험치
	for (float i = 0.0f; i < 10.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(515.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(515.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}
	//전파경험치
	for (float i = 0.0f; i < 10.0f; i += 1.0f)
	{
		CubeMeshOffset* hp = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, (50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(530.0f - 450.0f) / 450.0f, false);
		CubeMeshOffset* hpr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 10.0f * (i + 1.0f) / 450.0f, 15.0f / 450.0f, 0.02f, -(50.0f + 5.0f * (10.0f - i + 1.0f) - 600.0f) / 450.0f, -(530.0f - 450.0f) / 450.0f, true);

		meshes.push_back(hp);
		revmeshes.push_back(hpr);
	}

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, -1, -1, -1, -1, 263);
	UIObject* obj3 = new UIObject(1, -1, -1, -1, -1, 265);
	UIObject* obj4 = new UIObject(1, -1, -1, -1, -1, 267);
	
	UIObject* obj5 = new UIObject(1, -1, -1, -1, -1, 269);
	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, 270);
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, 271);
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, 272);

	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[262]);
	obj->SetPosition(100.0f, 2.0f, 105.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[263]);
	obj2->SetPosition(100.0f, 2.0f, 105.0f);

	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[265]);
	obj3->SetPosition(100.0f, 2.0f, 105.0f);

	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[267]);
	obj4->SetPosition(100.0f, 2.0f, 105.0f);

	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[269]);
	obj5->SetPosition(100.0f, 2.0f, 105.0f);

	obj6->SetMesh(meshes[24]);
	obj6->SetMaterial(0, rm->materials[270]);
	obj6->SetPosition(100.0f, 2.0f, 105.0f);

	obj7->SetMesh(meshes[34]);
	obj7->SetMaterial(0, rm->materials[271]);
	obj7->SetPosition(100.0f, 2.0f, 105.0f);

	obj8->SetMesh(meshes[44]);
	obj8->SetMaterial(0, rm->materials[272]);
	obj8->SetPosition(100.0f, 2.0f, 105.0f);


	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
	objects.push_back(obj4);
	objects.push_back(obj5);
	objects.push_back(obj6);
	objects.push_back(obj7);
	objects.push_back(obj8);
	
}

void InterfaceShader::ReleaseObjects()
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
void InterfaceShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void InterfaceShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void InterfaceShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC InterfaceShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC InterfaceShader::CreateRasterizerState()
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

D3D12_DEPTH_STENCIL_DESC InterfaceShader::CreateDepthStencilState()
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

D3D12_SHADER_BYTECODE InterfaceShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE InterfaceShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void InterfaceShader::Animate(CCamera* cam, PlayerInfoManager* in)
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
		//수치 막대가 아닌 경우
		if (i < 4)
		{
			if (cl.z < 0.0f)
			{
				objects[i]->SetMesh(revmeshes[i]);
			}
			else
			{
				objects[i]->SetMesh(meshes[i]);
			}
		}
		else
		{
			int cap = (info->stats.capacity * 100 / info->stats.maxhp - 2) / 5; //백분율로 나타낸 뒤 5로 나눔. 20분율

			int melee = (info->growth.melee.exp * 100 / expNeed[info->growth.melee.level-1] - 5) / 10; // 최대량 대비 현재량을 10분율로
			int ranged = (info->growth.ranged.exp * 100 / expNeed[info->growth.ranged.level - 1]-5) / 10; // 최대량 대비 현재량을 10분율로
			int radio = (info->growth.radio.exp * 100 / expNeed[info->growth.radio.level - 1]-5) / 10; // 최대량 대비 현재량을 10분율로

			if (cap < 0)
				cap = 0;

			if (melee < 0)
				melee = 0;

			if (ranged < 0)
				ranged = 0;

			if (radio < 0)
				radio = 0;

			if (i == 4)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[4 + cap]);
				}
				else
				{
					objects[i]->SetMesh(meshes[4 + cap]);
				}
			}
			else if (i == 5)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[24 + melee]);
				}
				else
				{
					objects[i]->SetMesh(meshes[24 + melee]);
				}
			}
			else if (i == 6)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[34 + ranged]);
				}
				else
				{
					objects[i]->SetMesh(meshes[34 + ranged]);
				}
			}
			else if (i == 7)
			{
				if (cl.z < 0.0f)
				{
					objects[i]->SetMesh(revmeshes[44 + radio]);
				}
				else
				{
					objects[i]->SetMesh(meshes[44 + radio]);
				}
			}
		}
		objects[i]->Rotate(-pitch, yaw, 0.0f);
		objects[i]->SetPosition(cp.x + cl.x, cp.y+cl.y, cp.z+cl.z);
	}



	//	XMFLOAT3 p = objects[1]->GetPosition();
	//objects[1]->SetPosition(p.x+ cu.x, p.y+cu.y, p.z+cu.z);
}