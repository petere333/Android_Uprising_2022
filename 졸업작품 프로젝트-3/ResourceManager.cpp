#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

void ResourceManager::Init(ID3D12Device* device, ID3D12GraphicsCommandList* commandList)
{
	pd3dDevice = device;
	pd3dCommandList = commandList;
}

void ResourceManager::BuildData(ID3D12RootSignature* m_pd3dGraphicsRootSignature)
{
	createSound();
	createTextures();
	createModels(m_pd3dGraphicsRootSignature);
}


void ResourceManager::createSRV(ID3D12Device* pd3dDevice, int nConstantBufferViews, int nShaderResourceViews)
{
	D3D12_DESCRIPTOR_HEAP_DESC d3dDescriptorHeapDesc;
	d3dDescriptorHeapDesc.NumDescriptors = nShaderResourceViews; //CBVs + SRVs 
	
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

void ResourceManager::CreateShaderResourceViews(ID3D12Device* pd3dDevice, CTexture* pTexture, UINT nDescriptorHeapIndex, UINT nRootParameterStartIndex)
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

void ResourceManager::createTextures()
{
	CTexture* tex1; CTexture* tex2; CTexture* tex3; CTexture* tex4; CTexture* tex5; CTexture* tex6; CTexture* tex7; CTexture* tex8; CTexture* tex9; CTexture* tex10;
	CTexture* tex11; CTexture* tex12; CTexture* tex13; CTexture* tex14; CTexture* tex15; CTexture* tex16; CTexture* tex17; CTexture* tex18; CTexture* tex19; CTexture* tex20;
	CTexture* tex21; CTexture* tex22; CTexture* tex23; CTexture* tex24; CTexture* tex25; CTexture* tex26; CTexture* tex27; CTexture* tex28; CTexture* tex29; CTexture* tex30;
	CTexture* tex31; CTexture* tex32; CTexture* tex33; CTexture* tex34; CTexture* tex35; CTexture* tex36; CTexture* tex37; CTexture* tex38; CTexture* tex39; CTexture* tex40;
	CTexture* tex41; CTexture* tex42; CTexture* tex43; CTexture* tex44; CTexture* tex45; CTexture* tex46; CTexture* tex47; CTexture* tex48; CTexture* tex49; CTexture* tex50;
	CTexture* tex51; CTexture* tex52; CTexture* tex53; CTexture* tex54; CTexture* tex55; CTexture* tex56; CTexture* tex57; CTexture* tex58; CTexture* tex59; CTexture* tex60;
	CTexture* tex61; CTexture* tex62; CTexture* tex63; CTexture* tex64; CTexture* tex65; CTexture* tex66; CTexture* tex67; CTexture* tex68; CTexture* tex69; CTexture* tex70;
	CTexture* tex71; CTexture* tex72; CTexture* tex73; CTexture* tex74; CTexture* tex75; CTexture* tex76; CTexture* tex77; CTexture* tex78; CTexture* tex79; CTexture* tex80;
	CTexture* tex81; CTexture* tex82; CTexture* tex83; CTexture* tex84; CTexture* tex85; CTexture* tex86; CTexture* tex87; CTexture* tex88; CTexture* tex89; CTexture* tex90;
	CTexture* tex91; CTexture* tex92; CTexture* tex93; CTexture* tex94; CTexture* tex95; CTexture* tex96; CTexture* tex97; CTexture* tex98; CTexture* tex99; CTexture* tex100;

	CTexture* tex101; CTexture* tex102; CTexture* tex103; CTexture* tex104; CTexture* tex105; CTexture* tex106; CTexture* tex107; CTexture* tex108; CTexture* tex109; CTexture* tex110;
	CTexture* tex111; CTexture* tex112; CTexture* tex113; CTexture* tex114; CTexture* tex115; CTexture* tex116; CTexture* tex117; CTexture* tex118; CTexture* tex119; CTexture* tex120;
	CTexture* tex121; CTexture* tex122; CTexture* tex123; CTexture* tex124; CTexture* tex125; CTexture* tex126; CTexture* tex127; CTexture* tex128; CTexture* tex129; CTexture* tex130;
	CTexture* tex131; CTexture* tex132; CTexture* tex133; CTexture* tex134; CTexture* tex135; CTexture* tex136; CTexture* tex137; CTexture* tex138; CTexture* tex139; CTexture* tex140;
	CTexture* tex141; CTexture* tex142; CTexture* tex143; CTexture* tex144; CTexture* tex145; CTexture* tex146; CTexture* tex147; CTexture* tex148; CTexture* tex149; CTexture* tex150;
	CTexture* tex151; CTexture* tex152; CTexture* tex153; CTexture* tex154; CTexture* tex155; CTexture* tex156; CTexture* tex157; CTexture* tex158; CTexture* tex159; CTexture* tex160;
	CTexture* tex161; CTexture* tex162; CTexture* tex163; CTexture* tex164; CTexture* tex165; CTexture* tex166; CTexture* tex167; CTexture* tex168; CTexture* tex169; CTexture* tex170;
	CTexture* tex171; CTexture* tex172; CTexture* tex173; CTexture* tex174; CTexture* tex175; CTexture* tex176; CTexture* tex177; CTexture* tex178; CTexture* tex179; CTexture* tex180;
	CTexture* tex181; CTexture* tex182; CTexture* tex183; CTexture* tex184; CTexture* tex185; CTexture* tex186; CTexture* tex187; CTexture* tex188; CTexture* tex189; CTexture* tex190;
	CTexture* tex191; CTexture* tex192; CTexture* tex193; CTexture* tex194; CTexture* tex195; CTexture* tex196; CTexture* tex197; CTexture* tex198; CTexture* tex199; CTexture* tex200;

	CTexture* tex201; CTexture* tex202; CTexture* tex203; CTexture* tex204; CTexture* tex205; CTexture* tex206; CTexture* tex207; CTexture* tex208; CTexture* tex209; CTexture* tex210;
	CTexture* tex211; CTexture* tex212; CTexture* tex213; CTexture* tex214; CTexture* tex215; CTexture* tex216; CTexture* tex217; CTexture* tex218; CTexture* tex219; CTexture* tex220;
	CTexture* tex221; CTexture* tex222; CTexture* tex223; CTexture* tex224; CTexture* tex225; CTexture* tex226; CTexture* tex227; CTexture* tex228; CTexture* tex229; CTexture* tex230;
	CTexture* tex231; CTexture* tex232; CTexture* tex233; CTexture* tex234; CTexture* tex235; CTexture* tex236; CTexture* tex237; CTexture* tex238; CTexture* tex239; CTexture* tex240;
	
	
	
	tex1 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex1->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex1);
	tex2 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex2->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex2);
	tex3 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex3->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/enemy.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex3);
	tex4 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex4->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample3.dds", RESOURCE_TEXTURE2D, 0); /// 32~34
	textures.push_back(tex4);
	tex5 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex5->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/effect/particle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex5);


	tex6 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex6->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/btn_start.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex6);
	tex7 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex7->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyMetalPlate.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex7);
	tex8 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex8->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/Rusty_barrel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex8);
	tex9 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex9->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/metal_box.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex9);
	tex10 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex10->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyMetalWall.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex10);

	tex11 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex11->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyFence.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex11);
	
	tex12 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex12->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/foodbin.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex12);

	tex13 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex13->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/envelope.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex13);

	tex14 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex14->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/ladder.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex14);

	tex15 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex15->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/rail.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex15);

	tex16 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex16->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/brick.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex16);

	tex17 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex17->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/ceramic.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex17);

	tex18 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex18->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/mix1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex18);

	tex19 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex19->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/mix2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex19);

	tex20 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex20->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/wood.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex20);

	tex21 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex21->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyStair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex21);
	tex22 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex22->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashCan.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex22);

	tex23 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex23->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/woodenPallet.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex23);

	tex24 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex24->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/cementBag.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex24);

	tex25 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex25->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/radiationWarn.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex25);

	tex26 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex26->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/truck.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex26);
	
	tex27 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex27->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/chon.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex27);

	tex28 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex28->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/guardrail.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex28);

	tex29 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex29->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/carbody.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex29);

	tex30 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex30->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/wheel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex30);

	tex31 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex31->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/Cardboards.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex31);

	tex32 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex32->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/control.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex32);

	tex33 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex33->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/paperWaste.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex33);

	tex34 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex34->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/pizzaBox.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex34);

	tex35 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex35->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/speedBump.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex35);

	tex36 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex36->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex36);

	tex37 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex37->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex37);

	tex38 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex38->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex38);

	tex39 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex39->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex39);

	tex40 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex40->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex40);

	tex41 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex41->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex41);

	tex42 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex42->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex42);

	tex43 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex43->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex43);

	tex44 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex44->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex44);

	tex45 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex45->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Energy Shield.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex45);
	tex46 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex46->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Big Energy Shield.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex46);
	tex47 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex47->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/LongTank.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex47);
	tex48 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex48->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/airfan.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex48);

	tex49 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex49->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex49);
	tex50 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex50->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex50);
	tex51 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex51->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex51);
	tex52 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex52->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex52);
	tex53 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex53->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex53);
	tex54 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex54->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/robotArm.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex54);
	tex55 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex55->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/sewer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex55);

	tex56 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex56->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wall.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex56);
	tex57 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex57->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex57);
	tex58 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex58->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/floor.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex58);

	tex59 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex59->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wireframe.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex59);

	tex60 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex60->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/cont2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex60);

	tex61 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex61->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wireframe.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex61);

	tex62 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex62->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/drill.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex62);

	tex63 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex63->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/saw.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex63);

	tex64 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex64->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/furniture1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex64);

	tex65 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex65->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/furniture2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex65);

	tex66 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex66->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/table1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex66);

	tex67 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex67->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/table2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex67);

	tex68 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex68->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/log1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex68);

	tex69 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex69->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/log2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex69);
	
	tex70 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex70->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/toolbox.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex70);
	tex71 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex71->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/glue.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex71);
	tex72 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex72->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/hammer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex72);
	tex73 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex73->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/bottle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex73);

	tex74 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex74->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/brick1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex74);
	tex75 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex75->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/brick2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex75);
	tex76 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex76->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/brick3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex76);

	tex77 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex77->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/ManufactureDoor_open.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex77);
	tex78 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex78->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/FloorConveyor.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex78);

	tex79 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex79->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/banner.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex79);
	tex80 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex80->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/klin.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex80);
	tex81 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex81->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wheel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex81);
	tex82 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex82->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/whiteboard.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex82);

	tex83 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex83->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Chair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex83);

	tex84 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex84->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_couch.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex84); 

	tex85 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex85->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Vending.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex85); 

	tex86 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex86->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Takza.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex86);

	tex87 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex87->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Counter.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex87); 

	tex88 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex88->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_TV.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex88);


	tex89 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex89->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwangjae1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex89);

	tex90 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex90->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_hwalls.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex90);

	tex91 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex91->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_walls.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex91);

	tex92 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex92->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_badak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex92);

	tex93 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex93->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_badak2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex93);

	tex94 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex94->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_beok1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex94);

	tex95 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex95->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Chair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex95);

	tex96 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex96->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_CheonJang1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex96);

	tex97 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex97->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Screen.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex97);

	tex98 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex98->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Takza.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex98);

	tex99 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex99->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_couch.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex99);

	tex100 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex100->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Vending.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex100);

	tex101 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex101->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_garomak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex101);

	tex102 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex102->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_gidung.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex102); 

	tex103 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex103->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_badak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex103);

	tex104 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex104->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_1000Jang.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex104);

	tex105 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex105->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_wall1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex105);

	tex106 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex106->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_desk4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex106);

	tex107 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex107->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/airfan.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex107);

	tex108 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex108->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Dol.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex108);

	tex109 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex109->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_lamp.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex109);

	tex110 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex110->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Doorlock.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex110);

	tex111 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex111->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Screen2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex111);

	tex112 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex112->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_Tabe.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex112);

	tex113 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex113->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_Cabinet.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex113);

	tex114 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex114->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_barrel_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex114);

	tex115 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex115->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_box_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex115);

	tex116 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex116->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex116);

	tex117 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex117->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex117);
	tex118 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex118->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex118);
	tex119 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex119->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards4_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex119);
	tex120 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex120->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_Cement1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex120);
	tex121 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex121->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_Cement2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex121);
	tex122 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex122->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_chon_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex122);
	tex123 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex123->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_control1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex123);
	tex124 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex124->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_control2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex124);
	tex125 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex125->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_control4_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex125);
	tex126 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex126->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_foodBin_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex126);
	tex127 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex127->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_envelope1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex127);
	tex128 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex128->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_envelope2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex128);
	tex129 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex129->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_envelope3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex129);
	tex130 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex130->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_fence_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex130);
	tex131 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex131->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_fence_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex131);

	tex132 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex132->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_garbageCan_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex132);
	tex133 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex133->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_guardrail_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex133);
	tex134 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex134->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_leverbody_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex134);
	tex135 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex135->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_leverhandle_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex135);
	tex136 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex136->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_papers_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex136);
	tex137 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex137->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_pizzabox_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex137);
	tex138 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex138->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_radSign_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex138);
	tex139 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex139->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex139);
	tex140 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex140->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex140);

	tex141 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex141->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex141);
	tex142 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex142->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick4_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex142);
	tex143 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex143->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick5_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex143);
	tex144 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex144->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick6_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex144);

	tex145 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex145->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinCeramic1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex145);
	tex146 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex146->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinCeramic2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex146);
	tex147 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex147->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinCeramic3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex147);
	tex148 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex148->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinMix1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex148);
	tex149 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex149->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinMix2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex149);

	tex150 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex150->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinWood1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex150);
	tex151 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex151->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinWood2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex151);
	tex152 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex152->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_speedbump_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex152);
	tex153 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex153->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_trashContainer_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex153);
	tex154 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex154->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truck_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex154);
	tex155 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex155->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truckbody_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex155);
	tex156 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex156->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truckwheel_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex156);
	tex157 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex157->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_woodenPallet_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex157);
	tex158 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex158->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_woodenPalletLayer_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex158);
	tex159 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex159->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_trashContainer_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex159);
	CTexture* norm1; CTexture* norm2; CTexture* norm3; CTexture* norm4; CTexture* norm5; CTexture* norm6; CTexture* norm7; CTexture* norm8; CTexture* norm9; CTexture* norm10;
	CTexture* norm11; CTexture* norm12; CTexture* norm13; CTexture* norm14; CTexture* norm15; CTexture* norm16; CTexture* norm17; CTexture* norm18; CTexture* norm19; CTexture* norm20;
	CTexture* norm21; CTexture* norm22; CTexture* norm23; CTexture* norm24; CTexture* norm25; CTexture* norm26; CTexture* norm27; CTexture* norm28; CTexture* norm29; CTexture* norm30;
	CTexture* norm31; CTexture* norm32; CTexture* norm33; CTexture* norm34; CTexture* norm35; CTexture* norm36; CTexture* norm37; CTexture* norm38; CTexture* norm39; CTexture* norm40;

	norm1 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm1->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/none.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm1);
	norm2 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm2->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/player_sharp.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm2);
	norm3 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm3->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/barrel.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm3);
	norm4 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm4->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/box.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm4);
	norm5 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm5->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/brick.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm5);
	norm6 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm6->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/carbody.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm6);
	norm7 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm7->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/cardboards.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm7);
	norm8 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm8->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/cementbag.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm8);
	norm9 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm9->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/ceramic.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm9);
	norm10 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm10->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/chon.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm10);
	norm11 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm11->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/control.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm11);
	norm12 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm12->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/envelope.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm12);
	norm13 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm13->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/fence.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm13);
	norm14 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm14->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/floorconvey.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm14);
	norm15 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm15->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/foodbin.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm15);
	norm16 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm16->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/foodbin.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm16);
	norm17 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm17->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/guardrail.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm17);
	norm18 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm18->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/ladder.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm18);
	norm19 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm19->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/manudoor.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm19);
	norm20 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm20->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/mix1.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm20);
	norm21 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm21->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/mix2.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm21);
	norm22 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm22->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/papers.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm22);
	norm23 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm23->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/pizzabox.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm23);
	norm24 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm24->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/rail.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm24);
	norm25 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm25->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/rustyMetal.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm25);
	norm26 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm26->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/rustyMetal.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm26);
	norm27 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm27->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/speedbump.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm27);
	norm28 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm28->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/trashcan.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm28);
	norm29 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm29->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/trashcont.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm29);
	norm30 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm30->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/truck.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm30);
	norm31 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm31->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/wheel.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm31);
	norm32 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm32->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/warnsign.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm32);
	norm33 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm33->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/wood.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm33);
	norm34 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm34->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/norm/woodenPallet.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm34);
	

	CTexture* spc1; CTexture* spc2; CTexture* spc3; CTexture* spc4; CTexture* spc5; CTexture* spc6; CTexture* spc7; CTexture* spc8; CTexture* spc9; CTexture* spc10;
	CTexture* spc11; CTexture* spc12; CTexture* spc13; CTexture* spc14; CTexture* spc15; CTexture* spc16; CTexture* spc17; CTexture* spc18; CTexture* spc19; CTexture* spc20;
	CTexture* spc21; CTexture* spc22; CTexture* spc23; CTexture* spc24; CTexture* spc25; CTexture* spc26; CTexture* spc27; CTexture* spc28; CTexture* spc29; CTexture* spc30;
	CTexture* spc31; CTexture* spc32; CTexture* spc33; CTexture* spc34; CTexture* spc35; CTexture* spc36; CTexture* spc37; CTexture* spc38; CTexture* spc39; CTexture* spc40;

	spc1 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc1->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample_spec2.dds", RESOURCE_TEXTURE2D, 0);

	spc2 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc2->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/none.dds", RESOURCE_TEXTURE2D, 0);

	spc3 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc3->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/barrel.dds", RESOURCE_TEXTURE2D, 0);
	spc4 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc4->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/box.dds", RESOURCE_TEXTURE2D, 0);
	spc5 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc5->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/brick.dds", RESOURCE_TEXTURE2D, 0);
	spc6 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc6->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/carbody.dds", RESOURCE_TEXTURE2D, 0);
	spc7 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc7->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/cardboards.dds", RESOURCE_TEXTURE2D, 0);
	spc8 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc8->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/cementbag.dds", RESOURCE_TEXTURE2D, 0);
	spc9 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc9->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/ceramic.dds", RESOURCE_TEXTURE2D, 0); 
	spc10 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc10->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/chon.dds", RESOURCE_TEXTURE2D, 0);

	spc11 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc11->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/control.dds", RESOURCE_TEXTURE2D, 0);
	spc12 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc12->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/envelope.dds", RESOURCE_TEXTURE2D, 0);
	spc13 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc13->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/fence.dds", RESOURCE_TEXTURE2D, 0);
	spc14 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc14->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/floorconvey.dds", RESOURCE_TEXTURE2D, 0);
	spc15 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc15->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/foodbin.dds", RESOURCE_TEXTURE2D, 0);
	spc16 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc16->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/guardrail.dds", RESOURCE_TEXTURE2D, 0);
	spc17 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc17->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/ladder.dds", RESOURCE_TEXTURE2D, 0);
	spc18 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc18->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/manudoor.dds", RESOURCE_TEXTURE2D, 0);
	spc19 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc19->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/mix1.dds", RESOURCE_TEXTURE2D, 0);
	spc20 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc20->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/mix2.dds", RESOURCE_TEXTURE2D, 0);

	spc21 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc21->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/papers.dds", RESOURCE_TEXTURE2D, 0);
	spc22 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc22->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/pizzabox.dds", RESOURCE_TEXTURE2D, 0);
	spc23 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc23->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/rail.dds", RESOURCE_TEXTURE2D, 0);
	spc24 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc24->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/rustymetal.dds", RESOURCE_TEXTURE2D, 0);
	spc25 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc25->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/speedbump.dds", RESOURCE_TEXTURE2D, 0);
	spc26 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc26->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/trashcan.dds", RESOURCE_TEXTURE2D, 0);
	spc27 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc27->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/trashcont.dds", RESOURCE_TEXTURE2D, 0);
	spc28 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc28->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/truck.dds", RESOURCE_TEXTURE2D, 0);
	spc29 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc29->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/warnsign.dds", RESOURCE_TEXTURE2D, 0);
	spc30 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc30->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/wheel.dds", RESOURCE_TEXTURE2D, 0);

	spc31 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc31->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/wood.dds", RESOURCE_TEXTURE2D, 0);
	spc32 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc32->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/spec/woodenPallet.dds", RESOURCE_TEXTURE2D, 0);

	specs.push_back(spc1);
	specs.push_back(spc2);
	specs.push_back(spc3);
	specs.push_back(spc4);
	specs.push_back(spc5);
	specs.push_back(spc6);
	specs.push_back(spc7);
	specs.push_back(spc8);
	specs.push_back(spc9);
	specs.push_back(spc10);
	specs.push_back(spc11);
	specs.push_back(spc12);
	specs.push_back(spc13);
	specs.push_back(spc14);
	specs.push_back(spc15);
	specs.push_back(spc16);
	specs.push_back(spc17);
	specs.push_back(spc18);
	specs.push_back(spc19);
	specs.push_back(spc20);

	specs.push_back(spc21);
	specs.push_back(spc22);
	specs.push_back(spc23);
	specs.push_back(spc24);
	specs.push_back(spc25);
	specs.push_back(spc26);
	specs.push_back(spc27);
	specs.push_back(spc28);
	specs.push_back(spc29);
	specs.push_back(spc30);

	specs.push_back(spc31);
	specs.push_back(spc32);

	

	createSRV(pd3dDevice, 0, textures.size() + normals.size() + specs.size());

	for (int i = 0; i < textures.size(); ++i)
	{
		CreateShaderResourceViews(pd3dDevice, textures[i], 0, 3);
	}
	for (int i = 0; i < normals.size(); ++i)
	{
		CreateShaderResourceViews(pd3dDevice, normals[i], 0, 6);
	}

	for (int i = 0; i < specs.size(); ++i)
	{
		CreateShaderResourceViews(pd3dDevice, specs[i], 0, 9);
	}

	for (int i = 0; i < textures.size(); ++i)
	{
		CMaterial* mat = new CMaterial(1);
		mat->SetTexture(textures[i], 0);
		mat->SetNormalTex(normals[0]);
		mat->SetSpecTex(specs[1]);
		materials.push_back(mat);
	}
	


	materials[0]->SetNormalTex(normals[1]);		
	materials[1]->SetNormalTex(normals[1]);
	materials[3]->SetNormalTex(normals[1]);


	materials[77]->SetNormalTex(normals[2]);
	materials[78]->SetNormalTex(normals[3]);
	materials[85]->SetNormalTex(normals[4]);
	materials[98]->SetNormalTex(normals[5]);
	materials[100]->SetNormalTex(normals[6]);
	materials[93]->SetNormalTex(normals[7]);
	materials[86]->SetNormalTex(normals[8]);
	materials[96]->SetNormalTex(normals[9]);
	materials[101]->SetNormalTex(normals[10]);
	materials[82]->SetNormalTex(normals[11]);
	materials[80]->SetNormalTex(normals[12]);
	materials[81]->SetNormalTex(normals[14]);
	materials[97]->SetNormalTex(normals[16]);
	materials[83]->SetNormalTex(normals[17]);
	materials[87]->SetNormalTex(normals[19]);
	materials[88]->SetNormalTex(normals[20]);
	materials[102]->SetNormalTex(normals[21]);
	materials[103]->SetNormalTex(normals[22]);
	materials[84]->SetNormalTex(normals[23]);
	materials[76]->SetNormalTex(normals[24]);
	materials[104]->SetNormalTex(normals[26]);
	materials[91]->SetNormalTex(normals[27]);
	materials[105]->SetNormalTex(normals[28]);
	materials[95]->SetNormalTex(normals[29]);
	materials[99]->SetNormalTex(normals[30]);
	materials[94]->SetNormalTex(normals[31]);
	materials[89]->SetNormalTex(normals[32]);
	materials[92]->SetNormalTex(normals[33]);

	materials[0]->SetSpecTex(specs[0]);
	materials[1]->SetSpecTex(specs[0]);
	materials[3]->SetSpecTex(specs[0]);

	materials[77]->SetSpecTex(specs[2]);
	materials[78]->SetSpecTex(specs[3]);
	materials[85]->SetSpecTex(specs[4]);
	materials[98]->SetSpecTex(specs[5]);
	materials[100]->SetSpecTex(specs[6]);
	materials[93]->SetSpecTex(specs[7]);
	materials[86]->SetSpecTex(specs[8]);
	materials[96]->SetSpecTex(specs[9]);
	materials[101]->SetSpecTex(specs[10]);
	materials[82]->SetSpecTex(specs[11]);
	materials[80]->SetSpecTex(specs[12]);
	materials[81]->SetSpecTex(specs[14]);
	materials[97]->SetSpecTex(specs[15]);
	materials[83]->SetSpecTex(specs[16]);
	materials[87]->SetSpecTex(specs[18]);
	materials[88]->SetSpecTex(specs[19]);
	materials[102]->SetSpecTex(specs[20]);
	materials[103]->SetSpecTex(specs[21]);
	materials[84]->SetSpecTex(specs[22]);
	materials[76]->SetSpecTex(specs[23]);
	materials[104]->SetSpecTex(specs[24]);
	materials[91]->SetSpecTex(specs[25]);
	materials[105]->SetSpecTex(specs[26]);
	materials[95]->SetSpecTex(specs[27]);
	materials[94]->SetSpecTex(specs[28]);
	materials[99]->SetSpecTex(specs[29]);
	materials[89]->SetSpecTex(specs[30]);
	materials[92]->SetSpecTex(specs[31]);

}

void ResourceManager::createSound(){}

void ResourceManager::createModels(ID3D12RootSignature* m_pd3dGraphicsRootSignature)
{
	CLoadedModelInfo* model1;
	CLoadedModelInfo* model2;
	CLoadedModelInfo* model3;
	CLoadedModelInfo* model4;
	CLoadedModelInfo* model5;

	model1 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/sample.bin", NULL);
	playerModels.push_back(model1);
	model2 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_walk.bin", NULL);
	playerModels.push_back(model2);
	model3 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rescale4.bin", NULL);
	playerModels.push_back(model3);
	model4 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_swing1.bin", NULL);
	playerModels.push_back(model4);
	model5 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_swing2.bin", NULL);
	playerModels.push_back(model5);

	CLoadedModelInfo* e1;
	CLoadedModelInfo* e2;
	CLoadedModelInfo* e3;
	CLoadedModelInfo* e4;
	CLoadedModelInfo* e5;
	
	e1 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_idle.bin", NULL);
	enemyModels.push_back(e1);
	e2 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_die.bin", NULL);
	enemyModels.push_back(e2);
	e3 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_walk.bin", NULL);
	enemyModels.push_back(e3);
	e4 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_run.bin", NULL);
	enemyModels.push_back(e4);
	e5 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_attack.bin", NULL);
	enemyModels.push_back(e5);
}