#include "StageSelectShader.h"


StageSelectShader::StageSelectShader(ResourceManager* r, PlayerShader* p)
{
	rm = r;
	ps = p;
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

	//메인으로 돌아가기 버튼
	CubeMeshOffset* main = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 178.0f / 450.0f, 59.0f / 450.0f, 0.02f, (178.0f - 600.0f) / 450.0f, -(175.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* mainr = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 178.0f / 450.0f, 59.0f / 450.0f, 0.02f, (178.0f - 600.0f) / 450.0f, -(175.0f - 450.0f) / 450.0f, true);

	//채널 박스 1~5
	CubeMeshOffset* ch1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (237.5f - 600.0f) / 450.0f, -(356.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ch1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (237.5f - 600.0f) / 450.0f, -(356.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* ch2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (608.5f - 600.0f) / 450.0f, -(356.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ch2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (608.5f - 600.0f) / 450.0f, -(356.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* ch3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (974.5f - 600.0f) / 450.0f, -(356.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ch3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (974.5f - 600.0f) / 450.0f, -(356.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* ch4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (402.5f - 600.0f) / 450.0f, -(626.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ch4r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (402.5f - 600.0f) / 450.0f, -(626.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* ch5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (836.5f - 600.0f) / 450.0f, -(626.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* ch5r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 276.0f / 450.0f, 216.0f / 450.0f, 0.02f, (836.5f - 600.0f) / 450.0f, -(626.0f - 450.0f) / 450.0f, true);

	//인원수 표기 구간 1~5

	CubeMeshOffset* count1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (288.0f - 600.0f) / 450.0f, -(361.7f - 450.0f) / 450.0f, false);
	CubeMeshOffset* count1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (288.0f - 600.0f) / 450.0f, -(361.7f - 450.0f) / 450.0f, true);

	CubeMeshOffset* count2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (659.0f - 600.0f) / 450.0f, -(361.7f - 450.0f) / 450.0f, false);
	CubeMeshOffset* count2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (659.0f - 600.0f) / 450.0f, -(361.7f - 450.0f) / 450.0f, true);

	CubeMeshOffset* count3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (1030.0f - 600.0f) / 450.0f, -(361.7f - 450.0f) / 450.0f, false);
	CubeMeshOffset* count3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (1030.0f - 600.0f) / 450.0f, -(361.7f - 450.0f) / 450.0f, true);

	CubeMeshOffset* count4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (453.0f - 600.0f) / 450.0f, -(631.0f - 450.0f) / 450.0f, false);
	CubeMeshOffset* count4r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (453.0f - 600.0f) / 450.0f, -(631.0f - 450.0f) / 450.0f, true);

	CubeMeshOffset* count5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (887.0f - 600.0f) / 450.0f, -(631.7f - 450.0f) / 450.0f, false);
	CubeMeshOffset* count5r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 12.0f / 450.0f, 32.5f / 450.0f, 0.02f, (887.0f - 600.0f) / 450.0f, -(631.7f - 450.0f) / 450.0f, true);

	// 방 입장하기 버튼 1~5

	CubeMeshOffset* join1 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (305.0f - 600.0f) / 450.0f, -(418.5f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join1r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (305.0f - 600.0f) / 450.0f, -(418.5f - 450.0f) / 450.0f, true);

	CubeMeshOffset* join2 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (686.0f - 600.0f) / 450.0f, -(418.5f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join2r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (686.0f - 600.0f) / 450.0f, -(418.5f - 450.0f) / 450.0f, true);

	CubeMeshOffset* join3 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (1057.0f - 600.0f) / 450.0f, -(418.5f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join3r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (1057.0f - 600.0f) / 450.0f, -(418.5f - 450.0f) / 450.0f, true);

	CubeMeshOffset* join4 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (470.0f - 600.0f) / 450.0f, -(688.5f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join4r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (470.0f - 600.0f) / 450.0f, -(688.5f - 450.0f) / 450.0f, true);

	CubeMeshOffset* join5 = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (904.0f - 600.0f) / 450.0f, -(688.5f - 450.0f) / 450.0f, false);
	CubeMeshOffset* join5r = new CubeMeshOffset(pd3dDevice, pd3dCommandList, 99.0f / 450.0f, 34.0f / 450.0f, 0.02f, (904.0f - 600.0f) / 450.0f, -(688.5f - 450.0f) / 450.0f, true);
	/*
	인덱스 0 : 배경
	1=뒤로가기 버튼

	2~6=채널 박스
	7~11= 1~5채널의 인원수 표기 숫자
	12~16= 1~5채널의 입장하기 버튼


	*/


	meshes.push_back(inter);
	meshesRev.push_back(inter2);
	meshes.push_back(main);
	meshesRev.push_back(mainr);

	meshes.push_back(ch1);
	meshes.push_back(ch2);
	meshes.push_back(ch3);
	meshes.push_back(ch4);
	meshes.push_back(ch5);
	meshes.push_back(count1);
	meshes.push_back(count2);
	meshes.push_back(count3);
	meshes.push_back(count4);
	meshes.push_back(count5);
	meshes.push_back(join1);
	meshes.push_back(join2);
	meshes.push_back(join3);
	meshes.push_back(join4);
	meshes.push_back(join5);

	meshesRev.push_back(ch1r);
	meshesRev.push_back(ch2r);
	meshesRev.push_back(ch3r);
	meshesRev.push_back(ch4r);
	meshesRev.push_back(ch5r);
	meshesRev.push_back(count1r);
	meshesRev.push_back(count2r);
	meshesRev.push_back(count3r);
	meshesRev.push_back(count4r);
	meshesRev.push_back(count5r);
	meshesRev.push_back(join1r);
	meshesRev.push_back(join2r);
	meshesRev.push_back(join3r);
	meshesRev.push_back(join4r);
	meshesRev.push_back(join5r);
	

	

	UIObject* obj = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj2 = new UIObject(1, 81, 175, 259, 234, 239);
	
	//채널 박스
	UIObject* obj3 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj4 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj5 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj6 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj7 = new UIObject(1, -1, -1, -1, -1, -1);
	//인원수
	UIObject* obj8 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj9 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj10 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj11 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj12 = new UIObject(1, -1, -1, -1, -1, -1);
	//입장버튼
	UIObject* obj13 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj14 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj15 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj16 = new UIObject(1, -1, -1, -1, -1, -1);
	UIObject* obj17 = new UIObject(1, -1, -1, -1, -1, -1);

	//배경
	obj->SetMesh(meshes[0]);
	obj->SetMaterial(0, rm->materials[238]);
	obj->SetPosition(0.0f, 0.0f, 0.0f);

	//돌아가기 버튼
	obj2->SetMesh(meshes[1]);
	obj2->SetMaterial(0, rm->materials[239]);
	obj2->SetPosition(0.0f, 0.0f, 0.0f);

	//채널 박스
	obj3->SetMesh(meshes[2]);
	obj3->SetMaterial(0, rm->materials[658]);
	obj3->SetPosition(0.0f, 0.0f, 0.0f);
	obj4->SetMesh(meshes[3]);
	obj4->SetMaterial(0, rm->materials[659]);
	obj4->SetPosition(0.0f, 0.0f, 0.0f);
	obj5->SetMesh(meshes[4]);
	obj5->SetMaterial(0, rm->materials[660]);
	obj5->SetPosition(0.0f, 0.0f, 0.0f);
	obj6->SetMesh(meshes[5]);
	obj6->SetMaterial(0, rm->materials[661]);
	obj6->SetPosition(0.0f, 0.0f, 0.0f);
	obj7->SetMesh(meshes[6]);
	obj7->SetMaterial(0, rm->materials[662]);
	obj7->SetPosition(0.0f, 0.0f, 0.0f);

	//인원 숫자
	obj8->SetMesh(meshes[7]);
	obj8->SetMaterial(0, rm->materials[273]);
	obj8->SetPosition(0.0f, 0.0f, 0.0f);
	obj9->SetMesh(meshes[8]);
	obj9->SetMaterial(0, rm->materials[273]);
	obj9->SetPosition(0.0f, 0.0f, 0.0f);
	obj10->SetMesh(meshes[9]);
	obj10->SetMaterial(0, rm->materials[273]);
	obj10->SetPosition(0.0f, 0.0f, 0.0f);
	obj11->SetMesh(meshes[10]);
	obj11->SetMaterial(0, rm->materials[273]);
	obj11->SetPosition(0.0f, 0.0f, 0.0f);
	obj12->SetMesh(meshes[11]);
	obj12->SetMaterial(0, rm->materials[273]);
	obj12->SetPosition(0.0f, 0.0f, 0.0f);

	//입장버튼
	obj13->SetMesh(meshes[12]);
	obj13->SetMaterial(0, rm->materials[663]);
	obj13->SetPosition(0.0f, 0.0f, 0.0f);
	obj14->SetMesh(meshes[13]);
	obj14->SetMaterial(0, rm->materials[663]);
	obj14->SetPosition(0.0f, 0.0f, 0.0f);
	obj15->SetMesh(meshes[14]);
	obj15->SetMaterial(0, rm->materials[663]);
	obj15->SetPosition(0.0f, 0.0f, 0.0f);
	obj16->SetMesh(meshes[15]);
	obj16->SetMaterial(0, rm->materials[663]);
	obj16->SetPosition(0.0f, 0.0f, 0.0f);
	obj17->SetMesh(meshes[16]);
	obj17->SetMaterial(0, rm->materials[663]);
	obj17->SetPosition(0.0f, 0.0f, 0.0f);

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

	objects.push_back(obj16);
	objects.push_back(obj17);
	
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

	//각 상자의 현재 인원 숫자를 갱신함
	for (int c = 1; c <= 5; ++c)
	{
		int room_cnt = 0;
		for (int i = 0; i < ps->room.size(); ++i)
		{
			if (ps->room[i] == c)
			{
				room_cnt += 1;
			}
		}
		objects[6 + c]->m_ppMaterials[0] = rm->materials[273 + room_cnt];
	}

	


}
