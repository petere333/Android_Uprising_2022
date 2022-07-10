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
	d3dDescriptorHeapDesc.NumDescriptors = nConstantBufferViews+nShaderResourceViews; //CBVs + SRVs 
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
	
	

	tex1= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex1->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/cont2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex1);

	tex2= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex2->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/chons.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex2);

	tex3= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex3->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/WhitePaint.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex3);

	tex4= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex4->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/GreenPaint.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex4);

	tex5= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex5->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex5);

	tex6= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex6->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/box.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex6);

	tex7= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex7->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/table.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex7);

	tex8= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex8->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PalletTruck.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex8);

	tex9= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex9->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/bin.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex9);

	tex10= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex10->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/barrel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex10);

	tex11 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex11->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/truck.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex11);

	tex12 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex12->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/���.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex12);

	tex13 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex13->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/��ܺ�1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex13);

	tex14 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex14->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/wood.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex14);

	tex15 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex15->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Cont3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex15);

	tex16 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex16->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�콼�����̳�.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex16);

	tex17 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex17->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Real_Contain.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex17);

	tex18 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex18->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PlateTexture.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex18);

	tex19 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex19->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex19);

	tex20 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex20->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/blockTexture.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex20);
	tex21 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex21->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Stair_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex21);
	tex22 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex22->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Heater_Texture.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex22);
	tex23 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex23->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/BaseColor_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex23);
	tex24 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex24->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Metal_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex24);
	tex25 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex25->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����Ŀ��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex25);

	tex26 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex26->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Convels.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex26);
	tex27 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex27->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Paperbox.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex27);
	tex28 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex28->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Machine_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex28);

	tex29 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex29->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Conl.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex29);


	tex30 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex30->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Tank.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex30);
	tex31 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex31->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/drum_t.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex31);
	tex32 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex32->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������_txt.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex32);
	tex33 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex33->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex33);
	tex34 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex34->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex34);

	tex35 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex35->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/enemy.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex35);
	tex36 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex36->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex36);
	tex37 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex37->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�ö�ƽ��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex37);
	tex38 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex38->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/â��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex38);
	tex39 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex39->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����â��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex39);
	tex40 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex40->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����â��2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex40);

	tex41 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex41->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����չ�ħ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex41);
	tex42 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex42->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/��պ�ü.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex42);
	tex43 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex43->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ö��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex43);
	tex44 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex44->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex44);
	tex45 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex45->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex45);
	tex46 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex46->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����ؽ���.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex46);
	tex47 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex47->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����ũ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex47);
	tex48 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex48->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex48);
	tex49 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex49->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�ױ���.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex49);
	tex50 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex50->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex50);

	tex51 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex51->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�Ծ��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex51);
	tex52 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex52->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Toblock.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex52);
	tex53 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex53->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/���ؾ�.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex53);
	tex54 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex54->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex54);
	tex55 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex55->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex55);
	tex56 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex56->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex56);
	tex57 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex57->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex57);
	tex58 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex58->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�鳯�ܰ�.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex58);
	tex59 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex59->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/����ؽ�.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex59);
	tex60 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex60->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/��Ʈ��.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex60);
	tex61 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex61->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/���º�.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex61);
	tex62 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex62->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�����.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex62);
	tex63 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex63->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�˹̴�.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex63);
	tex64 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex64->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/���ؽ�1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex64);
	tex65 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex65->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/���ؽ�2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex65);
	tex66 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex66->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample3.dds", RESOURCE_TEXTURE2D, 0); /// 32~34
	textures.push_back(tex66);
	tex67 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex67->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/effect/particle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex67);
	tex68 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex68->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/�����ؽ���.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex68);
	tex69 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex69->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/������.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex69);
	tex70 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex70->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PTSD.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex70);
	tex71 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex71->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ö����.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex71);
	tex72 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex72->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/���۵���.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex72);
	tex73 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex73->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Ʈ����.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex73);

	tex74 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex74->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sdw_anim2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex74);
	tex75 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex75->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sdw_�鳯�ܰ�2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex75);
	tex76 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex76->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/btn_start.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex76);
	tex77 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex77->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyMetalPlate.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex77);
	tex78 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex78->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/Rusty_barrel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex78);
	tex79 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex79->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/metal_box.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex79);
	tex80 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex80->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyMetalWall.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex80);

	tex81 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex81->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyFence.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex81);
	
	tex82 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex82->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/foodbin.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex82);

	tex83 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex83->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/envelope.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex83);

	tex84 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex84->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/ladder.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex84);

	tex85 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex85->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/rail.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex85);

	tex86 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex86->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/brick.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex86);

	tex87 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex87->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/ceramic.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex87);

	tex88 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex88->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/mix1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex88);

	tex89 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex89->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/mix2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex89);

	tex90 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex90->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/wood.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex90);

	tex91 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex91->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/RustyStair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex91);
	tex92 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex92->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashCan.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex92);

	tex93 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex93->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/woodenPallet.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex93);

	tex94 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex94->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/cementBag.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex94);

	tex95 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex95->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/radiationWarn.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex95);

	tex96 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex96->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/truck.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex96);
	
	tex97 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex97->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/chon.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex97);

	tex98 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex98->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/guardrail.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex98);

	tex99 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex99->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/carbody.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex99);

	tex100 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex100->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/wheel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex100);

	tex101 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex101->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/Cardboards.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex101);

	tex102 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex102->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/control.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex102);

	tex103 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex103->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/paperWaste.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex103);

	tex104 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex104->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/pizzaBox.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex104);

	tex105 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex105->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/speedBump.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex105);

	tex106 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex106->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex106);

	tex107 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex107->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex107);

	tex108 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex108->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex108);

	tex109 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex109->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex109);

	tex110 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex110->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex110);

	tex111 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex111->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex111);

	tex112 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex112->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex112);

	tex113 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex113->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex113);

	tex114 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex114->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_1/TrashContainer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex114);

	tex115 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex115->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Energy Shield.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex115);
	tex116 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex116->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Big Energy Shield.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex116);
	tex117 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex117->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/LongTank.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex117);
	tex118 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex118->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/airfan.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex118);

	tex119 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex119->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex119);
	tex120 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex120->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex120);
	tex121 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex121->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex121);
	tex122 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex122->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex122);
	tex123 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex123->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/Machine_7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex123);
	tex124 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex124->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/robotArm.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex124);
	tex125 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex125->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/sewer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex125);

	tex126 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex126->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wall.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex126);
	tex127 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex127->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex127);
	tex128 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex128->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/floor.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex128);

	tex129 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex129->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wireframe.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex129);

	tex130 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex130->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/cont2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex130);

	tex131 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex131->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wireframe.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex131);

	tex132 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex132->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/drill.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex132);

	tex133 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex133->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/saw.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex133);

	tex134 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex134->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/furniture1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex134);

	tex135 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex135->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/furniture2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex135);

	tex136 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex136->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/table1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex136);

	tex137 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex137->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/table2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex137);

	tex138 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex138->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/log1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex138);

	tex139 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex139->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/log2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex139);
	
	tex140 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex140->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/toolbox.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex140);
	tex141 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex141->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/glue.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex141);
	tex142 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex142->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/hammer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex142);
	tex143 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex143->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/bottle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex143);

	tex144 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex144->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/brick1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex144);
	tex145 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex145->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/brick2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex145);
	tex146 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex146->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/brick3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex146);

	tex147 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex147->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/ManufactureDoor_open.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex147);
	tex148 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex148->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/FloorConveyor.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex148);

	tex149 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex149->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/banner.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex149);
	tex150 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex150->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/klin.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex150);
	tex151 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex151->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/wheel.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex151);
	tex152 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex152->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/whiteboard.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex152);

	tex153 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex153->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Chair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex153);

	tex154 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex154->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_couch.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex154); 

	tex155 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex155->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Vending.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex155); 

	tex156 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex156->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Takza.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex156);

	tex157 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex157->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Counter.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex157); 

	tex158 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex158->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_TV.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex158);


	tex159 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex159->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwangjae1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex159);

	tex160 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex160->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_hwalls.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex160);

	tex161 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex161->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_walls.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex161);

	tex162 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex162->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_badak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex162);

	tex163 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex163->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_badak2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex163);

	tex164 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex164->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_beok1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex164);

	tex165 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex165->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Chair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex165);

	tex166 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex166->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_CheonJang1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex166);

	tex167 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex167->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Screen.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex167);

	tex168 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex168->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Takza.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex168);

	tex169 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex169->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_couch.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex169);

	tex170 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex170->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Vending.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex170);

	tex171 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex171->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_garomak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex171);

	tex172 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex172->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_gidung.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex172); 

	tex173 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex173->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_badak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex173);

	tex174 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex174->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_1000Jang.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex174);

	tex175 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex175->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_wall1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex175);

	tex176 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex176->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_desk4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex176);

	tex177 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex177->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/airfan.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex177);

	tex178 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex178->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Dol.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex178);

	tex179 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex179->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_lamp.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex179);

	tex180 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex180->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_Doorlock.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex180);

	tex181 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex181->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_Screen2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex181);

	tex182 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex182->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_Tabe.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex182);

	tex183 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex183->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_Cabinet.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex183);

	tex184 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex184->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_barrel_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex184);

	tex185 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex185->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_box_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex185);

	tex186 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex186->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex186);

	tex187 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex187->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex187);
	tex188 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex188->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex188);
	tex189 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex189->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards4_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex189);
	tex190 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex190->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_Cement1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex190);
	tex191 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex191->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_Cement2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex191);
	tex192 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex192->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_chon_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex192);
	tex193 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex193->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_control1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex193);
	tex194 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex194->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_control2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex194);
	tex195 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex195->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_control4_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex195);
	tex196 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex196->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_foodBin_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex196);
	tex197 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex197->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_envelope1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex197);
	tex198 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex198->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_envelope2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex198);
	tex199 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex199->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_envelope3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex199);
	tex200 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex200->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_fence_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex200);
	tex201 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex201->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_fence_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex201);

	tex202 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex202->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_garbageCan_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex202);
	tex203 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex203->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_guardrail_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex203);
	tex204 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex204->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_leverbody_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex204);
	tex205 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex205->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_leverhandle_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex205);
	tex206 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex206->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_papers_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex206);
	tex207 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex207->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_pizzabox_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex207);
	tex208 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex208->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_radSign_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex208);
	tex209 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex209->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex209);
	tex210 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex210->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex210);

	tex211 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex211->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex211);
	tex212 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex212->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick4_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex212);
	tex213 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex213->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick5_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex213);
	tex214 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex214->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinBrick6_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex214);

	tex215 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex215->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinCeramic1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex215);
	tex216 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex216->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinCeramic2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex216);
	tex217 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex217->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinCeramic3_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex217);
	tex218 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex218->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinMix1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex218);
	tex219 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex219->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinMix2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex219);

	tex220 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex220->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinWood1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex220);
	tex221 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex221->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_ruinWood2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex221);
	tex222 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex222->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_speedbump_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex222);
	tex223 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex223->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_trashContainer_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex223);
	tex224 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex224->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truck_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex224);
	tex225 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex225->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truckbody_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex225);
	tex226 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex226->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truckwheel_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex226);
	tex227 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex227->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_woodenPallet_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex227);
	tex228 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex228->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_woodenPalletLayer_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex228);
	tex229 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex229->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_trashContainer_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex229);
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
	norm3->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/area1_1/box.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm3);
	norm4 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm4->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/area1_1/truck.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm4);
	norm5 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm5->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/area1_1/barrel.dds", RESOURCE_TEXTURE2D, 0);
	normals.push_back(norm5);


	CTexture* spc1; CTexture* spc2;

	spc1 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc1->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample_spec2.dds", RESOURCE_TEXTURE2D, 0);

	spc2 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc2->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/none.dds", RESOURCE_TEXTURE2D, 0);

	specs.push_back(spc1);
	specs.push_back(spc2);

	



	

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
	materials[33]->SetSpecTex(specs[0]);
	materials[33]->SetNormalTex(normals[1]);
	materials[77]->SetNormalTex(normals[4]);
	materials[78]->SetNormalTex(normals[2]);
	materials[95]->SetNormalTex(normals[3]);

	
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