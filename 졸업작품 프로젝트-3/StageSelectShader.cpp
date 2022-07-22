#include "StageSelectShader.h"


StageSelectShader::StageSelectShader(ResourceManager* r)
{
	rm = r;
}
StageSelectShader::~StageSelectShader() {}

void StageSelectShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{

	//윈도우 크기 450픽셀당 1.0f로 환산.

	CubeMeshOffset* inter = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, false);
	CubeMeshOffset* inter2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 1200.0f / 450.0f, 2.0f, 0.01f, 0.0f, 0.0f, true);


	//로그아웃 버튼 위치 184, 152 클릭 범위 = 111, 86
	//즉 위치 = -(184-600)/450, -(152-450)/450
	//범위 = (111*2)/450, 86/450
	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 178.0f / 450.0f, 59.0f / 450.0f, 0.02f, (178.0f - 600.0f) / 450.0f, -(175.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* mainr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 178.0f / 450.0f, 59.0f / 450.0f, 0.02f, (178.0f - 600.0f) / 450.0f, -(175.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* join1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 153.0f / 450.0f, 56.0f / 450.0f, 0.02f, (410.0f - 600.0f) / 450.0f, -(410.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 153.0f / 450.0f, 56.0f / 450.0f, 0.02f, (410.0f - 600.0f) / 450.0f, -(410.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* cowork1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 145.0f / 450.0f, 54.0f / 450.0f, 0.02f, (624.0f - 600.0f) / 450.0f, -(410.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cowork1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 145.0f / 450.0f, 54.0f / 450.0f, 0.02f, (624.0f - 600.0f) / 450.0f, -(410.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* cosend1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 150.0f / 450.0f, 53.0f / 450.0f, 0.02f, (847.0f - 600.0f) / 450.0f, -(409.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cosend1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 150.0f / 450.0f, 53.0f / 450.0f, 0.02f, (847.0f - 600.0f) / 450.0f, -(409.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* join2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 150.0f / 450.0f, 52.0f / 450.0f, 0.02f, (410.0f - 600.0f) / 450.0f, -(653.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 150.0f / 450.0f, 52.0f / 450.0f, 0.02f, (410.0f - 600.0f) / 450.0f, -(653.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* cowork2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 145.0f / 450.0f, 54.0f / 450.0f, 0.02f, (625.0f - 600.0f) / 450.0f, -(654.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cowork2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 145.0f / 450.0f, 54.0f / 450.0f, 0.02f, (625.0f - 600.0f) / 450.0f, -(654.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* cosend2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 150.0f / 450.0f, 53.0f / 450.0f, 0.02f, (848.0f - 600.0f) / 450.0f, -(654.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cosend2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 150.0f / 450.0f, 53.0f / 450.0f, 0.02f, (848.0f - 600.0f) / 450.0f, -(654.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* select1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 33.0f / 450.0f, 39.0f / 450.0f, 0.02f, (934.0f - 600.0f) / 450.0f, -(334.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* select1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 33.0f / 450.0f, 39.0f / 450.0f, 0.02f, (934.0f - 600.0f) / 450.0f, -(334.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* select2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 33.0f / 450.0f, 39.0f / 450.0f, 0.02f, (936.0f - 600.0f) / 450.0f, -(579.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* select2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 33.0f / 450.0f, 39.0f / 450.0f, 0.02f, (936.0f - 600.0f) / 450.0f, -(579.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* mode1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 39.0f / 450.0f, 0.02f, (868.0f - 600.0f) / 450.0f, -(334.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* mode1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 39.0f / 450.0f, 0.02f, (868.0f - 600.0f) / 450.0f, -(334.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* mode2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 39.0f / 450.0f, 0.02f, (870.0f - 600.0f) / 450.0f, -(579.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* mode2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 39.0f / 450.0f, 0.02f, (870.0f - 600.0f) / 450.0f, -(579.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* list1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 156.0f / 450.0f, 0.03f, (868.0f - 600.0f) / 450.0f, -(432.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* list1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 156.0f / 450.0f, 0.03f, (868.0f - 600.0f) / 450.0f, -(432.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* list2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 156.0f / 450.0f, 0.03f, (870.0f - 600.0f) / 450.0f, -(677.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* list2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 100.0f / 450.0f, 156.0f / 450.0f, 0.03f, (870.0f - 600.0f) / 450.0f, -(677.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* cointer = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 677.0f / 450.0f, 291.0f / 450.0f, 0.03f, (600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* cointerr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 677.0f / 450.0f, 291.0f / 450.0f, 0.03f, (600.0f - 600.0f) / 450.0f, -(450.0f - 450.0f) / 450.0f, true);



	meshes.push_back(inter);
	meshesRev.push_back(inter2);
	meshes.push_back(main);
	meshesRev.push_back(mainr);
	meshes.push_back(join1);
	meshesRev.push_back(join1r);
	meshes.push_back(cowork1);
	meshesRev.push_back(cowork1r);
	meshes.push_back(cosend1);
	meshesRev.push_back(cosend1r);

	meshes.push_back(join2);
	meshesRev.push_back(join2r);
	meshes.push_back(cowork2);
	meshesRev.push_back(cowork2r);
	meshes.push_back(cosend2);
	meshesRev.push_back(cosend2r);

	meshes.push_back(select1);
	meshesRev.push_back(select1r);
	meshes.push_back(select2);
	meshesRev.push_back(select2r);
	
	meshes.push_back(mode1);
	meshesRev.push_back(mode1r);
	meshes.push_back(mode2);
	meshesRev.push_back(mode2r);

	meshes.push_back(list1);
	meshesRev.push_back(list1r);
	meshes.push_back(list2);
	meshesRev.push_back(list2r);

	meshes.push_back(cointer);
	meshesRev.push_back(cointerr);


	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, 81, 175, 259, 234, 239);
	UIObject* obj3 = new UIObject(1, 333, 410, 487, 466, 248);
	UIObject* obj4 = new UIObject(1, 551, 410, 697, 464, 245);
	UIObject* obj5 = new UIObject(1, 772, 409, 922, 463, 242);

	UIObject* obj6 = new UIObject(1, 335, 653, 485, 705, 248);
	UIObject* obj7 = new UIObject(1, 552, 654, 698, 708, 245);
	UIObject* obj8 = new UIObject(1, 773, 654, 923, 707, 242);

	UIObject* obj9 = new UIObject(1, 917, 334, 951, 373, -1);
	UIObject* obj10 = new UIObject(1, 919, 579, 953, 618, -1);

	//mode
	UIObject* obj11 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj12 = new UIObject(1, -1, -1, -1, -1, -1);
	//list
	UIObject* obj13 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj14 = new UIObject(1, -1, -1, -1, -1, -1);

	//coworker
	UIObject* obj15 = new UIObject(1, -1, -1, -1, -1, -1);

	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[238]);
	obj->SetPosition(0.0f, 0.0f, 0.0f);

	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[239]);
	obj2->SetPosition(0.0f, 0.0f, 0.0f);

	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[248]);
	obj3->SetPosition(0.0f, 0.0f, 0.0f);

	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[245]);
	obj4->SetPosition(0.0f, 0.0f, 0.0f);

	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[242]);
	obj5->SetPosition(0.0f, 0.0f, 0.0f);

	obj6->SetMesh(meshes[5]);
	obj6->SetMaterial(0, rm->materials[248]);
	obj6->SetPosition(0.0f, 0.0f, 0.0f);

	obj7->SetMesh(meshes[6]);
	obj7->SetMaterial(0, rm->materials[245]);
	obj7->SetPosition(0.0f, 0.0f, 0.0f);

	obj8->SetMesh(meshes[7]);
	obj8->SetMaterial(0, rm->materials[242]);
	obj8->SetPosition(0.0f, 0.0f, 0.0f);

	obj9->SetMesh(meshes[8]);
	obj9->SetMaterial(0, rm->materials[251]);
	obj9->SetPosition(0.0f, 0.0f, 0.0f);

	obj10->SetMesh(meshes[9]);
	obj10->SetMaterial(0, rm->materials[251]);
	obj10->SetPosition(0.0f, 0.0f, 0.0f);

	obj11->SetMesh(meshes[10]);
	obj11->SetMaterial(0, rm->materials[309]);
	obj11->SetPosition(0.0f, 0.0f, 0.0f);

	obj12->SetMesh(meshes[11]);
	obj12->SetMaterial(0, rm->materials[309]);
	obj12->SetPosition(0.0f, 0.0f, 0.0f);

	obj13->SetMesh(meshes[12]);
	obj13->SetMaterial(0, rm->materials[313]);
	obj13->SetPosition(0.0f, 0.0f, 0.0f);

	obj14->SetMesh(meshes[13]);
	obj14->SetMaterial(0, rm->materials[313]);
	obj14->SetPosition(0.0f, 0.0f, 0.0f);

	obj15->SetMesh(meshes[14]);
	obj15->SetMaterial(0, rm->materials[314]);
	obj15->SetPosition(0.0f, 0.0f, 0.0f);

	objects.push_back(obj);
	objects.push_back(obj2);
	objects.push_back(obj3);
	objects.push_back(obj4);
	objects.push_back(obj5);
	objects.push_back(obj6);
	objects.push_back(obj7);
	objects.push_back(obj8);
	objects.push_back(obj9);
	objects.push_back(obj10);

	objects.push_back(obj11);
	objects.push_back(obj12);
	objects.push_back(obj13);
	objects.push_back(obj14);
	objects.push_back(obj15);
}

void StageSelectShader::ReleaseObjects()
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
void StageSelectShader::ReleaseUploadBuffers()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseUploadBuffers();
		}
	}
}

void StageSelectShader::ReleaseShaderVariables()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->ReleaseShaderVariables();
		}
	}
}

void StageSelectShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i])
		{
			objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}

D3D12_INPUT_LAYOUT_DESC StageSelectShader::CreateInputLayout()
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

D3D12_RASTERIZER_DESC StageSelectShader::CreateRasterizerState()
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

D3D12_DEPTH_STENCIL_DESC StageSelectShader::CreateDepthStencilState()
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

D3D12_SHADER_BYTECODE StageSelectShader::CreateVertexShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "vsInterface", "vs_5_1", &m_pd3dVertexShaderBlob));
}

D3D12_SHADER_BYTECODE StageSelectShader::CreatePixelShader()
{
	return(CShader::CompileShaderFromFile(L"interface.hlsl", "psInterface", "ps_5_1", &m_pd3dPixelShaderBlob));
}

void StageSelectShader::Animate(CCamera* cam)
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

	if (list1Show == false)
	{
		objects[12]->SetMesh(NULL);
	}
	else
	{
		objects[12]->SetMesh(meshes[12]);
	}
	
	if (list2Show == false)
	{
		objects[13]->SetMesh(NULL);
	}
	else
	{
		objects[13]->SetMesh(meshes[13]);
	}

	
	objects[10]->m_ppMaterials[0] = rm->materials[309 + mode1 - 1];
	objects[11]->m_ppMaterials[0] = rm->materials[309 + mode2 - 1];
	
	if (coworkShow == false)
	{
		objects[14]->SetMesh(NULL);
	}
	else
	{
		objects[14]->SetMesh(meshes[14]);
	}

}