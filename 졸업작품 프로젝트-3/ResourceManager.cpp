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

	// 2-1 2-2 ÅØ½ºÃÄ 
	CTexture* tex101; CTexture* tex102; CTexture* tex103; CTexture* tex104; CTexture* tex105; CTexture* tex106; CTexture* tex107; CTexture* tex108; CTexture* tex109; CTexture* tex110;
	CTexture* tex111; CTexture* tex112; CTexture* tex113; CTexture* tex114;


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
	tex12->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/»ó´Ü.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex12);

	tex13 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex13->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/»ó´Üº®1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex13);

	tex14 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex14->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/wood.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex14);

	tex15 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex15->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Cont3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex15);

	tex16 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex16->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/³ì½¼ÄÁÅ×ÀÌ³Ê.dds", RESOURCE_TEXTURE2D, 0);
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
	tex25->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/»óÀÚÄ¿¹ö.dds", RESOURCE_TEXTURE2D, 0);
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
	tex32->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Áüµ¢ÀÌ_txt.dds", RESOURCE_TEXTURE2D, 0);
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
	tex36->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¼±¹Ý.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex36);
	tex37 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex37->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ÇÃ¶ó½ºÆ½ºó.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex37);
	tex38 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex38->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Ã¢»ì.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex38);
	tex39 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex39->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/°¨¿ÁÃ¢»ì.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex39);
	tex40 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex40->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/°¨¿ÁÃ¢»ì2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex40);

	tex41 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex41->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/µ¹±âµÕ¹ÞÄ§.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex41);
	tex42 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex42->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/±âµÕº»Ã¼.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex42);
	tex43 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex43->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Ã¶º®.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex43);
	tex44 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex44->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¹ßÀü¼Ò.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex44);
	tex45 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex45->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¹ßÀü¼Ò2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex45);
	tex46 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex46->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/±âµÕÅØ½º«Œ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex46);
	tex47 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex47->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/·ÕÅÊÅ©.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex47);
	tex48 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex48->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/³°Àºº®.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex48);
	tex49 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex49->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¶×±ÛÀÌ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex49);
	tex50 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex50->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¸ø¶ÔÀ½.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex50);

	tex51 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex51->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¶Ô¾î¶ó.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex51);
	tex52 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex52->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Toblock.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex52);
	tex53 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex53->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ÀÜÇØ¾².dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex53);
	tex54 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex54->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/µÎÀÜÇØ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex54);
	tex55 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex55->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¼¼ÀÜÇØ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex55);
	tex56 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex56->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/³×ÀÜÇØ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex56);
	tex57 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex57->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/´ÙÀÜÇØ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex57);
	tex58 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex58->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Åé³¯´Ü°Ë.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex58);
	tex59 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex59->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/±â°èÅØ½º.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex59);
	tex60 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex60->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/ÆÈÆ®·°.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex60);
	tex61 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex61->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¼û´Âº®.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex61);
	tex62 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex62->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/µé¾öÅë.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex62);
	tex63 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex63->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¾Ë¹Ì´½.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex63);
	tex64 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex64->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¹®ÅØ½º1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex64);
	tex65 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex65->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¹®ÅØ½º2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex65);
	tex66 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex66->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample3.dds", RESOURCE_TEXTURE2D, 0); /// 32~34
	textures.push_back(tex66);
	tex67 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex67->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/effect/particle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex67);
	tex68 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex68->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/¹ßÀüÅØ½ºÃÄ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex68);
	tex69 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex69->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/µ¹»çÁø.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex69);
	tex70 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex70->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/PTSD.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex70);
	tex71 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex71->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Ã¶º®Áî.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex71);
	tex72 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex72->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/µ¿±Ûµ¿±Û.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex72);
	tex73 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex73->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/Æ®·¡ºñ.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex73);

	tex74 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex74->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sdw_anim2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex74);
	tex75 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex75->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sdw_Åé³¯´Ü°Ë2.dds", RESOURCE_TEXTURE2D, 0);
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
	tex93->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwangjae1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex93);

	tex94 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex94->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_badak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex94);

	tex95 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex95->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_beok1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex95);

	tex96 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex96->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_CheonJang1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex96);

	tex97 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex97->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanjae_badak2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex97);

	tex98 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex98->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_walls.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex98);

	tex99 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex99->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/Gwanja_hwalls.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex99);


	tex100 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex100->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_1000jang.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex100);


	tex101 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex101->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_badak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex101);

	tex102 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex102->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_wall1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex102);

	tex103 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex103->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_hwall1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex103);

	tex104 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex104->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex104);

	tex105 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex105->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_garomak1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex105);

	tex106 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex106->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/Receps_gidung.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex106);

	CTexture* norm;

	norm = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/none.dds", RESOURCE_TEXTURE2D, 0);



	normals.push_back(norm);

	CTexture* spc; CTexture* spc2;

	spc = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/sample_spec2.dds", RESOURCE_TEXTURE2D, 0);

	spc2 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc2->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/none.dds", RESOURCE_TEXTURE2D, 0);

	specs.push_back(spc);
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
	
	e1 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_idle.bin", NULL);
	enemyModels.push_back(e1);
	e2 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_die.bin", NULL);
	enemyModels.push_back(e2);
	
}