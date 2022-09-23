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

	CTexture* tex241; CTexture* tex242; CTexture* tex243; CTexture* tex244; CTexture* tex245; CTexture* tex246; CTexture* tex247; CTexture* tex248; CTexture* tex249; CTexture* tex250;
	CTexture* tex251; CTexture* tex252; CTexture* tex253; CTexture* tex254; CTexture* tex255; CTexture* tex256; CTexture* tex257; CTexture* tex258; CTexture* tex259; CTexture* tex260;
	CTexture* tex261; CTexture* tex262; CTexture* tex263; CTexture* tex264; CTexture* tex265; CTexture* tex266; CTexture* tex267; CTexture* tex268; CTexture* tex269; CTexture* tex270;
	CTexture* tex271; CTexture* tex272; CTexture* tex273; CTexture* tex274; CTexture* tex275; CTexture* tex276; CTexture* tex277; CTexture* tex278; CTexture* tex279; CTexture* tex280;
	CTexture* tex281; CTexture* tex282; CTexture* tex283; CTexture* tex284; CTexture* tex285; CTexture* tex286; CTexture* tex287; CTexture* tex288; CTexture* tex289; CTexture* tex290;
	CTexture* tex291; CTexture* tex292; CTexture* tex293; CTexture* tex294; CTexture* tex295; CTexture* tex296; CTexture* tex297; CTexture* tex298; CTexture* tex299; CTexture* tex300;
	
	CTexture* tex301; CTexture* tex302; CTexture* tex303; CTexture* tex304; CTexture* tex305; CTexture* tex306; CTexture* tex307; CTexture* tex308; CTexture* tex309; CTexture* tex310;
	CTexture* tex311; CTexture* tex312; CTexture* tex313; CTexture* tex314; CTexture* tex315; CTexture* tex316; CTexture* tex317; CTexture* tex318; CTexture* tex319; CTexture* tex320;
	CTexture* tex321; CTexture* tex322; CTexture* tex323; CTexture* tex324; CTexture* tex325; CTexture* tex326; CTexture* tex327; CTexture* tex328; CTexture* tex329; CTexture* tex330;
	CTexture* tex331; CTexture* tex332; CTexture* tex333; CTexture* tex334; CTexture* tex335; CTexture* tex336; CTexture* tex337; CTexture* tex338; CTexture* tex339; CTexture* tex340;



	CTexture* tex341; CTexture* tex342; CTexture* tex343; CTexture* tex344; CTexture* tex345; CTexture* tex346; CTexture* tex347; CTexture* tex348; CTexture* tex349; CTexture* tex350;
	CTexture* tex351; CTexture* tex352; CTexture* tex353; CTexture* tex354; CTexture* tex355; CTexture* tex356; CTexture* tex357; CTexture* tex358; CTexture* tex359; CTexture* tex360;
	CTexture* tex361; CTexture* tex362; CTexture* tex363; CTexture* tex364; CTexture* tex365; CTexture* tex366; CTexture* tex367; CTexture* tex368; CTexture* tex369; CTexture* tex370;
	CTexture* tex371; CTexture* tex372; CTexture* tex373; CTexture* tex374; CTexture* tex375; CTexture* tex376; CTexture* tex377; CTexture* tex378; CTexture* tex379; CTexture* tex380;
	CTexture* tex381; CTexture* tex382; CTexture* tex383; CTexture* tex384; CTexture* tex385; CTexture* tex386; CTexture* tex387; CTexture* tex388; CTexture* tex389; CTexture* tex390;
	CTexture* tex391; CTexture* tex392; CTexture* tex393; CTexture* tex394; CTexture* tex395; CTexture* tex396; CTexture* tex397; CTexture* tex398; CTexture* tex399; CTexture* tex400;

	CTexture* tex401; CTexture* tex402; CTexture* tex403; CTexture* tex404; CTexture* tex405; CTexture* tex406; CTexture* tex407; CTexture* tex408; CTexture* tex409; CTexture* tex410;
	CTexture* tex411; CTexture* tex412; CTexture* tex413; CTexture* tex414; CTexture* tex415; CTexture* tex416; CTexture* tex417; CTexture* tex418; CTexture* tex419; CTexture* tex420;
	CTexture* tex421; CTexture* tex422; CTexture* tex423; CTexture* tex424; CTexture* tex425; CTexture* tex426; CTexture* tex427; CTexture* tex428; CTexture* tex429; CTexture* tex430;
	CTexture* tex431; CTexture* tex432; CTexture* tex433; CTexture* tex434; CTexture* tex435; CTexture* tex436; CTexture* tex437; CTexture* tex438; CTexture* tex439; CTexture* tex440;
	CTexture* tex441; CTexture* tex442; CTexture* tex443; CTexture* tex444; CTexture* tex445; CTexture* tex446; CTexture* tex447; CTexture* tex448; CTexture* tex449; CTexture* tex450;
	CTexture* tex451; CTexture* tex452; CTexture* tex453; CTexture* tex454; CTexture* tex455; CTexture* tex456; CTexture* tex457; CTexture* tex458; CTexture* tex459; CTexture* tex460;
	CTexture* tex461; CTexture* tex462; CTexture* tex463; CTexture* tex464; CTexture* tex465; CTexture* tex466; CTexture* tex467; CTexture* tex468; CTexture* tex469; CTexture* tex470;
	CTexture* tex471; CTexture* tex472; CTexture* tex473; CTexture* tex474; CTexture* tex475; CTexture* tex476; CTexture* tex477; CTexture* tex478; CTexture* tex479; CTexture* tex480;
	CTexture* tex481; CTexture* tex482; CTexture* tex483; CTexture* tex484; CTexture* tex485; CTexture* tex486; CTexture* tex487; CTexture* tex488; CTexture* tex489; CTexture* tex490;
	CTexture* tex491; CTexture* tex492; CTexture* tex493; CTexture* tex494; CTexture* tex495; CTexture* tex496; CTexture* tex497; CTexture* tex498; CTexture* tex499; CTexture* tex500;

	CTexture* tex501; CTexture* tex502; CTexture* tex503; CTexture* tex504; CTexture* tex505; CTexture* tex506; CTexture* tex507; CTexture* tex508; CTexture* tex509; CTexture* tex510;
	CTexture* tex511; CTexture* tex512; CTexture* tex513; CTexture* tex514; CTexture* tex515; CTexture* tex516; CTexture* tex517; CTexture* tex518; CTexture* tex519; CTexture* tex520;
	CTexture* tex521; CTexture* tex522; CTexture* tex523; CTexture* tex524; CTexture* tex525; CTexture* tex526; CTexture* tex527; CTexture* tex528; CTexture* tex529; CTexture* tex530;
	CTexture* tex531; CTexture* tex532; CTexture* tex533; CTexture* tex534; CTexture* tex535; CTexture* tex536; CTexture* tex537; CTexture* tex538; CTexture* tex539; CTexture* tex540;
	CTexture* tex541; CTexture* tex542; CTexture* tex543; CTexture* tex544; CTexture* tex545; CTexture* tex546; CTexture* tex547; CTexture* tex548; CTexture* tex549; CTexture* tex550;
	CTexture* tex551; CTexture* tex552; CTexture* tex553; CTexture* tex554; CTexture* tex555; CTexture* tex556; CTexture* tex557; CTexture* tex558; CTexture* tex559; CTexture* tex560;
	CTexture* tex561; CTexture* tex562; CTexture* tex563; CTexture* tex564; CTexture* tex565; CTexture* tex566; CTexture* tex567; CTexture* tex568; CTexture* tex569; CTexture* tex570;
	CTexture* tex571; CTexture* tex572; CTexture* tex573; CTexture* tex574; CTexture* tex575; CTexture* tex576; CTexture* tex577; CTexture* tex578; CTexture* tex579; CTexture* tex580;
	CTexture* tex581; CTexture* tex582; CTexture* tex583; CTexture* tex584; CTexture* tex585; CTexture* tex586; CTexture* tex587; CTexture* tex588; CTexture* tex589; CTexture* tex590;
	CTexture* tex591; CTexture* tex592; CTexture* tex593; CTexture* tex594; CTexture* tex595; CTexture* tex596; CTexture* tex597; CTexture* tex598; CTexture* tex599; CTexture* tex600;

	CTexture* tex601; CTexture* tex602; CTexture* tex603; CTexture* tex604; CTexture* tex605; CTexture* tex606; CTexture* tex607; CTexture* tex608; CTexture* tex609; CTexture* tex610;
	CTexture* tex611; CTexture* tex612; CTexture* tex613; CTexture* tex614; CTexture* tex615; CTexture* tex616; CTexture* tex617; CTexture* tex618; CTexture* tex619; CTexture* tex620;
	CTexture* tex621; CTexture* tex622; CTexture* tex623; CTexture* tex624; CTexture* tex625; CTexture* tex626; CTexture* tex627; CTexture* tex628; CTexture* tex629; CTexture* tex630;
	CTexture* tex631; CTexture* tex632; CTexture* tex633; CTexture* tex634; CTexture* tex635; CTexture* tex636; CTexture* tex637; CTexture* tex638; CTexture* tex639; CTexture* tex640;
	CTexture* tex641; CTexture* tex642; CTexture* tex643; CTexture* tex644; CTexture* tex645; CTexture* tex646; CTexture* tex647; CTexture* tex648; CTexture* tex649; CTexture* tex650;
	CTexture* tex651; CTexture* tex652; CTexture* tex653; CTexture* tex654; CTexture* tex655; CTexture* tex656; CTexture* tex657; CTexture* tex658; CTexture* tex659; CTexture* tex660;
	CTexture* tex661; CTexture* tex662; CTexture* tex663; CTexture* tex664; CTexture* tex665; CTexture* tex666; CTexture* tex667; CTexture* tex668; CTexture* tex669; CTexture* tex670;
	CTexture* tex671; CTexture* tex672; CTexture* tex673; CTexture* tex674; CTexture* tex675; CTexture* tex676; CTexture* tex677; CTexture* tex678; CTexture* tex679; CTexture* tex680;
	CTexture* tex681; CTexture* tex682; CTexture* tex683; CTexture* tex684; CTexture* tex685; CTexture* tex686; CTexture* tex687; CTexture* tex688; CTexture* tex689; CTexture* tex690;
	CTexture* tex691; CTexture* tex692; CTexture* tex693; CTexture* tex694; CTexture* tex695; CTexture* tex696; CTexture* tex697; CTexture* tex698; CTexture* tex699; CTexture* tex700;

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
	tex116->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards1_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex116);

	tex117 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex117->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards2_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex117);
	tex118 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex118->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards3_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex118);
	tex119 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex119->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_cardboards4_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex119);
	tex120 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex120->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_Cement1_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex120);
	tex121 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex121->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_Cement2_front.dds", RESOURCE_TEXTURE2D, 0);
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

	//1-2 shadow

	tex160 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex160->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_airfan_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex160);
	tex161 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex161->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_banner_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex161);
	tex162 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex162->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_bigshield_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex162);
	tex163 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex163->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_bottle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex163);
	tex164 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex164->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_box_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex164);
	tex165 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex165->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_bucket.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex165);
	tex166 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex166->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_chon_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex166);
	tex167 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex167->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_container_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex167);
	tex168 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex168->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_control1_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex168);
	tex169 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex169->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_control2_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex169);

	tex170 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex170->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_control4_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex170);

	tex171 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex171->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_drill_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex171);
	tex172 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex172->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_energyshield_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex172);
	tex173 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex173->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_fence_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex173);
	tex174 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex174->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_fence_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex174);
	tex175 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex175->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_furniture1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex175);
	tex176 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex176->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_furniture2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex176);
	tex177 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex177->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_glue.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex177);
	tex178 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex178->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_hammer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex178);
	tex179 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex179->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_heater_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex179);

	tex180 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex180->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_kilnclose_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex180);
	tex181 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex181->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_kilnopen_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex181);
	tex182 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex182->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_log1_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex182);
	tex183 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex183->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_log2_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex183);
	tex184 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex184->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_longtank_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex184);
	tex185 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex185->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_machine1_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex185);																		  
	tex186 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);												  
	tex186->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_machine3_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex186);																		  
	tex187 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);												  
	tex187->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_machine4_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex187);																		  
	tex188 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);												  
	tex188->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_machine6_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex188);																		  
	tex189 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);												  
	tex189->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_machine7_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex189);

	tex190 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex190->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_robotarm_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex190);
	tex191 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex191->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_saw.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex191);
	tex192 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex192->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_sewer.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex192);
	tex193 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex193->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_shelf_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex193);
	tex194 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex194->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_shield_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex194);
	tex195 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex195->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_table_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex195);
	tex196 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex196->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_toolbox_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex196);
	tex197 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex197->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex197);
	tex198 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex198->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex198);
	tex199 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex199->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex199);

	tex200 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex200->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex200);
	tex201 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex201->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex201);
	tex202 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex202->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex202);
	tex203 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex203->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex203);
	tex204 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex204->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex204);
	tex205 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex205->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex205);
	tex206 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex206->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex206);
	tex207 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex207->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex207);
	tex208 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex208->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex208);
	tex209 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex209->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex209);

	tex210 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex210->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex210);
	tex211 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex211->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_vase15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex211);
	tex212 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex212->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_wheel_up.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex212);
	tex213 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex213->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_whiteboard_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex213);
	tex214 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex214->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_2/sdw_woods_right.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex214);

	//여기까지 1-1, 1-2구역 그림자. 이제부터 메인화면 인터페이스

	tex215 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex215->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/lobby.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex215);
	tex216 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex216->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_out_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex216);
	tex217 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex217->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_out_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex217);
	tex218 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex218->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_out_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex218);
	tex219 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex219->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_shop_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex219);
	tex220 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex220->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_shop_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex220);
	tex221 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex221->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_shop_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex221);
	tex222 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex222->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_stage_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex222);
	tex223 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex223->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_stage_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex223);
	tex224 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex224->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_stage_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex224);
	tex225 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex225->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_stats_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex225);
	tex226 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex226->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_stats_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex226);
	tex227 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex227->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/btn_stats_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex227);

	//여기서부터 플레이어 정보창 인터페이스

	tex228 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex228->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/profile.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex228);
	tex229 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex229->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_storage_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex229);
	tex230 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex230->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_storage_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex230);
	tex231 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex231->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_storage_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex231);
	tex232 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex232->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_minus_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex232);
	tex233 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex233->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_minus_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex233);
	tex234 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex234->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_plus_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex234);
	tex235 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex235->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_plus_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex235);
	tex236 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex236->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_main_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex236);
	tex237 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex237->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_main_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex237);
	tex238 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex238->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_main_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex238);

	//여기서부터 스테이지 선택 화면
	tex239 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex239->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/stage.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex239);
	tex240 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex240->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/main_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex240);
	tex241 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex241->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/main_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex241);
	tex242 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex242->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/main_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex242);

	tex243 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex243->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cosend_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex243);
	tex244 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex244->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cosend_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex244);
	tex245 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex245->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cosend_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex245);
	tex246 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex246->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cowork_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex246);
	tex247 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex247->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cowork_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex247);
	tex248 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex248->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cowork_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex248);
	tex249 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex249->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/enter_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex249);
	tex250 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex250->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/enter_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex250);
	tex251 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex251->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/enter_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex251);
	
	tex252 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex252->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/modes_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex252);

	//여기서부터 숫자 텍스처
	tex253 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex253->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex253);
	tex254 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex254->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex254);
	tex255 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex255->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex255);
	tex256 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex256->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex256);
	tex257 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex257->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex257);
	tex258 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex258->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex258);
	tex259 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex259->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex259);
	tex260 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex260->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex260);
	tex261 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex261->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex261);
	tex262 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex262->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex262);

	//여기서부터 인게임 인터페이스

	tex263 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex263->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/ingame.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex263);

	tex264 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex264->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mode1_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex264);
	tex265 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex265->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mode1_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex265);

	tex266 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex266->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mode2_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex266);
	tex267 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex267->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mode2_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex267);

	tex268 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex268->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mode3_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex268);
	tex269 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex269->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mode3_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex269);

	tex270 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex270->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/hp.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex270);
	tex271 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex271->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/exp_melee.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex271);
	tex272 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex272->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/exp_ranged.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex272);
	tex273 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex273->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/exp_micro.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex273);

	//여기서부터 숫자 텍스처
	tex274 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex274->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex274);
	tex275 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex275->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex275);
	tex276 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex276->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex276);
	tex277 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex277->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex277);
	tex278 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex278->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex278);
	tex279 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex279->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex279);
	tex280 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex280->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex280);
	tex281 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex281->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex281);
	tex282 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex282->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex282);
	tex283 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex283->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/digit/white/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex283);

	//여기서부터 대기실 인터페이스

	tex284= new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex284->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/room.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex284);

	tex285 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex285->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_main_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex285);
	tex286 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex286->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_main_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex286);
	tex287 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex287->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_main_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex287);

	tex288 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex288->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_ready_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex288);
	tex289 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex289->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_ready_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex289);
	tex290 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex290->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_ready_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex290);

	tex291 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex291->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_start_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex291);
	tex292 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex292->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_start_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex292);
	tex293 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex293->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/btn_start_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex293);
	tex294 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex294->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/preview1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex294);
	tex295 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex295->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/preview2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex295);
	tex296 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex296->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/preview3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex296);
	tex297 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex297->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/melee.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex297);
	tex298 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex298->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/ranged.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex298);
	tex299 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex299->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/radio.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex299);

	tex300 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex300->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/stage1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex300);
	tex301 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex301->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/stage2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex301);


	//추가된 인게임 인터페이스 텍스처
	tex302 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex302->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/success.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex302);
	tex303 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex303->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/retry_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex303);
	tex304 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex304->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/retry_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex304);
	tex305 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex305->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/back_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex305);
	tex306 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex306->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/back_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex306);

	tex307 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex307->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/storage.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex307);
	tex308 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex308->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_x_on.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex308);
	tex309 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex309->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stats/btn_x_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex309);

	tex310 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex310->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/mode1_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex310);
	tex311 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex311->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/mode2_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex311);
	tex312 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex312->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/mode3_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex312);
	tex313 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex313->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/mode4_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex313);
	tex314 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex314->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/mode_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex314);


	//동료 인터페이스

	tex315 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex315->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/cowork.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex315);

	tex316 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex316->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/member1_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex316);
	tex317 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex317->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/member1_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex317);

	tex318 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex318->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/member2_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex318);
	tex319 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex319->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/member2_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex319);

	tex320 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex320->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/member3_base.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex320);
	tex321 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex321->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/stage/member3_press.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex321);
	tex322 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex322->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area1_1/sdw_truck_front.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex322);

	tex323 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex323->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/main/stage1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex323);
	tex324 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex324->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/blunt.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex324);

	tex325 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex325->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/bazuka.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex325);
	
	//여기서부터 인게임 미션 인터페이스
	tex326 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex326->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/fail.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex326);

	tex327 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex327->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/progress.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex327);

	tex328 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex328->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/time.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex328);

	tex329 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex329->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex329);
	
	tex330 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex330->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex330);

	tex331 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex331->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex331);

	tex332 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex332->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex332);

	tex333 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex333->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex333);

	tex334 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex334->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex334);

	tex335 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex335->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex335);

	tex336 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex336->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex336);

	tex337 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex337->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex337);

	tex338 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex338->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/m1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex338);

	tex339 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex339->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/failMsg.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex339);




	tex340 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex340->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/wait/readytogo.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex340);

	tex341 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex341->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_1/vtx_Screen.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex341);


	tex342 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex342->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_1/vtx_desk-1A1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex342);

	tex343 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex343->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m1-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex343);
	tex344 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex344->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m1-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex344);
	tex345 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex345->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m1-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex345);

	tex346 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex346->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m1c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex346);
	tex347 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex347->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m1c-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex347);
	tex348 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex348->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m1c-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex348);

	tex349 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex349->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex349);

	tex350 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex350->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex350);
	tex351 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex351->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex351);

	tex352 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex352->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex352);
	tex353 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex353->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2c-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex353);
	tex354 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex354->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2c-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex354);

	tex355 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex355->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2c-4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex355);
	tex356 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex356->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2c-5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex356);
	tex357 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex357->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m2c-6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex357);


	tex358 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex358->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m3-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex358);
	tex359 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex359->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m3-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex359);
	tex360 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex360->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m3-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex360);

	tex361 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex361->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m3c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex361);
	tex362 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex362->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m3c-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex362);
	tex363 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex363->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m3c-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex363);

	tex364 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex364->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m4-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex364);
	tex365 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex365->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m4-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex365);
	tex366 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex366->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m4-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex366);
	tex367 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex367->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m4-4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex367);
	tex368 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex368->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m4c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex368);
	tex369 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex369->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m4c-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex369);

	tex370 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex370->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m5-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex370);
	tex371 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex371->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m5-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex371);
	tex372 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex372->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m5-3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex372);
	
	tex373 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex373->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m5c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex373);
	tex374 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex374->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m5c-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex374);

	tex375 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex375->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m6-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex375);
	tex376 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex376->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m6c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex376);

	tex377 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex377->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m7-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex377);
	tex378 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex378->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m7c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex378);

	tex379 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex379->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m8-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex379);
	tex380 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex380->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m8-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex380);

	tex381 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex381->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m9-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex381);
	tex382 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex382->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m9-2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex382);

	tex383 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex383->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m9c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex383);
	tex384 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex384->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m10-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex384);
	tex385 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex385->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/UI/ingame/mission/narration/m10c-1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex385);



	tex386 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex386->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_1/vtx_MetalChair.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex386);

	tex387 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex387->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_1/vtx_desk-1A2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex387);

	tex388 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex388->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_1/vtx_Cabinets.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex388);

	tex389 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex389->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_2/vtx_Couch.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex389);

	tex390 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex390->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_2/vtx_Table.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex390);

	tex391 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex391->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_2/vtx_Vending.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex391);

	tex392 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex392->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_2/vtx_Counters.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex392);

	tex393 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex393->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_2/vtx_Counters2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex393);

	tex394 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex394->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_2/vtx_Dongsang.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex394);

	tex395 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex395->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/effect/part2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex395);

	tex396 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex396->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/player_shadow.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex396);

	tex397 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex397->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/item/capacity.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex397);

	tex398 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex398->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/item/boost.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex398);

	tex399 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex399->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/item/hard.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex399);

	tex400 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex400->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/item/power.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex400);

	tex401 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex401->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/item/precision.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex401);

	tex402 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex402->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/area2_1/vtx_MetalChair2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex402);

	tex403 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex403->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex403);

	tex404 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex404->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex404);

	tex405 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex405->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex405);

	tex406 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex406->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex406);

	tex407 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex407->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex407);

	tex408 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex408->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex408);

	tex409 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex409->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex409);

	tex410 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex410->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex410);

	tex411 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex411->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex411);

	tex412 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex412->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex412);

	tex413 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex413->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex413);

	tex414 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex414->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex414);
	tex415 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex415->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex415);
	tex416 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex416->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex416);
	tex417 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex417->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex417);
	tex418 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex418->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex418);
	tex419 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex419->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex419);
	tex420 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex420->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/17.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex420);
	tex421 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex421->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex421);
	tex422 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex422->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/gun/run/19.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex422);

	tex423 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex423->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex423);
	tex424 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex424->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex424);
	tex425 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex425->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex425);
	tex426 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex426->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex426);
	tex427 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex427->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex427);
	tex428 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex428->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex428);
	tex429 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex429->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex429);
	tex430 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex430->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex430);
	tex431 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex431->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex431);
	tex432 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex432->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex432);
	tex433 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex433->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex433);
	tex434 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex434->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex434);
	tex435 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex435->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex435);
	tex436 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex436->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex436);
	tex437 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex437->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex437);
	tex438 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex438->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex438);
	tex439 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex439->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex439);
	tex440 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex440->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/17.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex440);
	tex441 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex441->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex441);
	tex442 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex442->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka/run/19.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex442);

	tex443 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex443->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex443);
	tex444 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex444->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex444);
	tex445 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex445->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex445);
	tex446 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex446->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex446);
	tex447 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex447->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex447);
	tex448 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex448->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex448);
	tex449 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex449->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex449);
	tex450 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex450->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex450);
	tex451 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex451->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex451);
	tex452 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex452->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex452);
	tex453 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex453->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex453);
	tex454 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex454->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex454);
	tex455 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex455->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex455);
	tex456 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex456->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex456);
	tex457 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex457->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex457);
	tex458 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex458->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex458);
	tex459 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex459->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex459);
	tex460 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex460->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/17.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex460);
	tex461 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex461->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex461);
	tex462 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex462->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/run/19.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex462);

	tex463 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex463->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex463);
	tex464 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex464->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex464);
	tex465 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex465->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex465);
	tex466 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex466->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex466);
	tex467 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex467->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex467);
	tex468 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex468->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex468);
	tex469 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex469->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex469);
	tex470 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex470->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex470);
	tex471 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex471->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex471);
	tex472 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex472->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex472);
	tex473 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex473->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex473);
	tex474 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex474->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex474);
	tex475 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex475->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex475);
	tex476 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex476->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex476);
	tex477 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex477->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex477);
	tex478 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex478->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex478);
	tex479 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex479->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex479);
	tex480 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex480->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/17.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex480);
	tex481 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex481->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex481);
	tex482 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex482->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blunt/run/19.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex482);

	tex483 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex483->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex483);
	tex484 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex484->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex484);
	tex485 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex485->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex485);
	tex486 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex486->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex486);
	tex487 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex487->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex487);
	tex488 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex488->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex488);
	tex489 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex489->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex489);
	tex490 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex490->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex490);
	tex491 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex491->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex491);
	tex492 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex492->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex492);
	tex493 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex493->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex493);
	tex494 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex494->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex494);
	tex495 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex495->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex495);
	tex496 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex496->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex496);
	tex497 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex497->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex497);
	tex498 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex498->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex498);
	tex499 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex499->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex499);
	tex500 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex500->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/17.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex500);
	tex501 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex501->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex501);
	tex502 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex502->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio/run/19.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex502);

	tex503 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex503->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/bazuka_idle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex503);																 
	tex504 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);										 
	tex504->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade_idle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex504);																 
	tex505 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);										 
	tex505->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/radio_idle.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex505);

	tex506 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex506->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex506);
	tex507 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex507->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex507);
	tex508 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex508->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex508);
	tex509 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex509->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex509);
	tex510 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex510->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex510);
	tex511 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex511->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex511);
	tex512 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex512->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex512);
	tex513 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex513->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex513);
	tex514 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex514->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex514);
	tex515 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex515->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex515);
	tex516 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex516->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex516);
	tex517 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex517->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex517);
	tex518 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex518->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex518);
	tex519 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex519->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex519);
	tex520 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex520->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex520);
	tex521 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex521->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex521);
	tex522 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex522->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex522);
	tex523 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex523->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/17.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex523);
	tex524 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex524->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex524);
	tex525 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex525->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/19.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex525);
	tex526 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex526->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/20.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex526);
	tex527 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex527->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/21.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex527);
	tex528 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex528->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/22.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex528);
	tex529 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex529->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/23.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex529);
	tex530 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex530->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/attack/24.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex530);

	tex531 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex531->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex531);
	tex532 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex532->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex532);
	tex533 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex533->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex533);
	tex534 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex534->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex534);
	tex535 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex535->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex535);
	tex536 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex536->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex536);
	tex537 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex537->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex537);
	tex538 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex538->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex538);
	tex539 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex539->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex539);
	tex540 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex540->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex540);
	tex541 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex541->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/20.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex541);
	tex542 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex542->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/22.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex542);
	tex543 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex543->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/24.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex543);
	tex544 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex544->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/26.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex544);
	tex545 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex545->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/28.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex545);
	tex546 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex546->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/30.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex546);
	tex547 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex547->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/32.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex547);
	tex548 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex548->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/34.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex548);
	tex549 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex549->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/36.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex549);
	tex550 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex550->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/run/38.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex550);

	tex551 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex551->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex551);
	tex552 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex552->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex552);
	tex553 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex553->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex553);
	tex554 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex554->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex554);
	tex555 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex555->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex555);
	tex556 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex556->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/15.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex556);
	tex557 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex557->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/18.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex557);
	tex558 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex558->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/21.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex558);
	tex559 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex559->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/24.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex559);
	tex560 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex560->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/27.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex560);
	tex561 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex561->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/30.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex561);
	tex562 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex562->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/33.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex562);
	tex563 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex563->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/36.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex563);
	tex564 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex564->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/39.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex564);
	tex565 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex565->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/enemy/blunt/walk/42.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex565);

	tex566 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex566->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex566);
	tex567 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex567->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex567);
	tex568 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex568->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex568);
	tex569 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex569->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex569);
	tex570 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex570->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/16.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex570);

	tex571 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex571->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/20.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex571);
	tex572 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex572->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/24.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex572);
	tex573 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex573->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/28.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex573);
	tex574 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex574->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/32.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex574);
	tex575 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex575->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/36.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex575);
	tex576 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex576->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/40.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex576);
	tex577 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex577->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/44.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex577);
	tex578 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex578->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/48.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex578);
	tex579 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex579->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/52.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex579);
	tex580 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex580->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/idle/56.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex580);

	tex581 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex581->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex581);
	tex582 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex582->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex582);
	tex583 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex583->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex583);
	tex584 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex584->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex584);
	tex585 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex585->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex585);
	tex586 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex586->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex586);
	tex587 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex587->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex587);
	tex588 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex588->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex588);
	tex589 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex589->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex589);
	tex590 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex590->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex590);
	tex591 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex591->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex591);
	tex592 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex592->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex592);
	tex593 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex593->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex593);
	tex594 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex594->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex594);
	tex595 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex595->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack1/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex595);

	tex596 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex596->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/0.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex596);
	tex597 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex597->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/1.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex597);
	tex598 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex598->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/2.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex598);
	tex599 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex599->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/3.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex599);
	tex600 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex600->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/4.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex600);

	tex601 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex601->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/5.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex601);
	tex602 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex602->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/6.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex602);
	tex603 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex603->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/7.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex603);
	tex604 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex604->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/8.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex604);
	tex605 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex605->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/9.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex605);
	tex606 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex606->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/10.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex606);
	tex607 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex607->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/11.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex607);
	tex608 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex608->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/12.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex608);
	tex609 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex609->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/13.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex609);
	tex610 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	tex610->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/shadow/char/player/blade/attack2/14.dds", RESOURCE_TEXTURE2D, 0);
	textures.push_back(tex610);

	CTexture* norm1; CTexture* norm2; CTexture* norm3; CTexture* norm4; CTexture* norm5; CTexture* norm6; CTexture* norm7; CTexture* norm8; CTexture* norm9; CTexture* norm10;
	CTexture* norm11; CTexture* norm12; CTexture* norm13; CTexture* norm14; CTexture* norm15; CTexture* norm16; CTexture* norm17; CTexture* norm18; CTexture* norm19; CTexture* norm20;
	CTexture* norm21; CTexture* norm22; CTexture* norm23; CTexture* norm24; CTexture* norm25; CTexture* norm26; CTexture* norm27; CTexture* norm28; CTexture* norm29; CTexture* norm30;
	CTexture* norm31; CTexture* norm32; CTexture* norm33; CTexture* norm34; CTexture* norm35; CTexture* norm36; CTexture* norm37; CTexture* norm38; CTexture* norm39; CTexture* norm40;

	CTexture* norm41; CTexture* norm42; CTexture* norm43; CTexture* norm44; CTexture* norm45; CTexture* norm46; CTexture* norm47; CTexture* norm48; CTexture* norm49; CTexture* norm50;
	CTexture* norm51; CTexture* norm52; CTexture* norm53; CTexture* norm54; CTexture* norm55; CTexture* norm56; CTexture* norm57; CTexture* norm58; CTexture* norm59; CTexture* norm60;
	CTexture* norm61; CTexture* norm62; CTexture* norm63; CTexture* norm64; CTexture* norm65; CTexture* norm66; CTexture* norm67; CTexture* norm68; CTexture* norm69; CTexture* norm70;
	CTexture* norm71; CTexture* norm72; CTexture* norm73; CTexture* norm74; CTexture* norm75; CTexture* norm76; CTexture* norm77; CTexture* norm78; CTexture* norm79; CTexture* norm80;
	CTexture* norm81; CTexture* norm82; CTexture* norm83; CTexture* norm84; CTexture* norm85; CTexture* norm86; CTexture* norm87; CTexture* norm88; CTexture* norm89; CTexture* norm90;
	CTexture* norm91; CTexture* norm92; CTexture* norm93; CTexture* norm94; CTexture* norm95; CTexture* norm96; CTexture* norm97; CTexture* norm98; CTexture* norm99; CTexture* norm100;
	CTexture* norm101; CTexture* norm102; CTexture* norm103; CTexture* norm104; CTexture* norm105; CTexture* norm106; CTexture* norm107; CTexture* norm108; CTexture* norm109; CTexture* norm110;

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
	

	norm35 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm35->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/airfan.dds", RESOURCE_TEXTURE2D, 0);
	norm36 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm36->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/banner.dds", RESOURCE_TEXTURE2D, 0);
	norm37 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm37->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/bigshield.dds", RESOURCE_TEXTURE2D, 0);
	norm38 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm38->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/bottle.dds", RESOURCE_TEXTURE2D, 0);
	norm39 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm39->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/brick1.dds", RESOURCE_TEXTURE2D, 0);
	norm40 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm40->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/brick2.dds", RESOURCE_TEXTURE2D, 0);

	norm41 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm41->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/brick3.dds", RESOURCE_TEXTURE2D, 0);
	norm42 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm42->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/bucket.dds", RESOURCE_TEXTURE2D, 0);
	norm43 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm43->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	norm44 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm44->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/cont.dds", RESOURCE_TEXTURE2D, 0);
	norm45 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm45->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/dooropen.dds", RESOURCE_TEXTURE2D, 0);
	norm46 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm46->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/drill.dds", RESOURCE_TEXTURE2D, 0);
	norm47 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm47->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/floor.dds", RESOURCE_TEXTURE2D, 0);
	norm48 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm48->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/floorconvey.dds", RESOURCE_TEXTURE2D, 0);
	norm49 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm49->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/furniture1.dds", RESOURCE_TEXTURE2D, 0);
	norm50 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm50->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/furniture2.dds", RESOURCE_TEXTURE2D, 0);

	norm51 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm51->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/glue.dds", RESOURCE_TEXTURE2D, 0);
	norm52 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm52->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/hammer.dds", RESOURCE_TEXTURE2D, 0);
	norm53 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm53->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/klin.dds", RESOURCE_TEXTURE2D, 0);
	norm54 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm54->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/log1.dds", RESOURCE_TEXTURE2D, 0);
	norm55 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm55->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/log2.dds", RESOURCE_TEXTURE2D, 0);
	norm56 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm56->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/longtank.dds", RESOURCE_TEXTURE2D, 0);
	norm57 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm57->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/machine1.dds", RESOURCE_TEXTURE2D, 0);
	norm58 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm58->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/machine3.dds", RESOURCE_TEXTURE2D, 0);
	norm59 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm59->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/machine4.dds", RESOURCE_TEXTURE2D, 0);
	norm60 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm60->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/machine6.dds", RESOURCE_TEXTURE2D, 0);

	norm61 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm61->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/machine7.dds", RESOURCE_TEXTURE2D, 0);
	norm62 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm62->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/robotarm.dds", RESOURCE_TEXTURE2D, 0);
	norm63 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm63->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/saw.dds", RESOURCE_TEXTURE2D, 0);
	norm64 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm64->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/sewer.dds", RESOURCE_TEXTURE2D, 0);
	norm65 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm65->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/shield.dds", RESOURCE_TEXTURE2D, 0);
	norm66 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm66->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/table1.dds", RESOURCE_TEXTURE2D, 0);
	norm67 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm67->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/toolbox.dds", RESOURCE_TEXTURE2D, 0);
	norm68 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm68->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/wall.dds", RESOURCE_TEXTURE2D, 0);
	norm69 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm69->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/wheel.dds", RESOURCE_TEXTURE2D, 0);
	norm70 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm70->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/whiteboard.dds", RESOURCE_TEXTURE2D, 0);

	norm71 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm71->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/norm/wireframe.dds", RESOURCE_TEXTURE2D, 0);


	// 2-1

	norm72 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm72->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwangjae1.dds", RESOURCE_TEXTURE2D, 0);

	norm73 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm73->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanja_hwalls.dds", RESOURCE_TEXTURE2D, 0);

	norm74 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm74->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanja_Tabe.dds", RESOURCE_TEXTURE2D, 0);

	norm75 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm75->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanja_walls.dds", RESOURCE_TEXTURE2D, 0);

	norm76 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm76->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_badak1.dds", RESOURCE_TEXTURE2D, 0);

	norm77 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm77->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_badak2.dds", RESOURCE_TEXTURE2D, 0);

	norm78 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm78->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_beok1.dds", RESOURCE_TEXTURE2D, 0);

	norm79 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm79->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_CheonJang1.dds", RESOURCE_TEXTURE2D, 0);

	norm80 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm80->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_Screen.dds", RESOURCE_TEXTURE2D, 0);

	norm81 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm81->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_Screen2.dds", RESOURCE_TEXTURE2D, 0);

	norm82 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm82->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_Takza.dds", RESOURCE_TEXTURE2D, 0);

	norm83 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm83->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanjae_Chair.dds", RESOURCE_TEXTURE2D, 0);

	norm84 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm84->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/norm/Gwanja_Cabinet.dds", RESOURCE_TEXTURE2D, 0);


	// 2=2
	norm85 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm85->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/airfan.dds", RESOURCE_TEXTURE2D, 0);

	norm86 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm86->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_1000jang.dds", RESOURCE_TEXTURE2D, 0);

	norm87 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm87->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_badak1.dds", RESOURCE_TEXTURE2D, 0);

	norm88 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm88->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_couch.dds", RESOURCE_TEXTURE2D, 0);

	norm89 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm89->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_Counter.dds", RESOURCE_TEXTURE2D, 0);

	norm90 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm90->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_desk4.dds", RESOURCE_TEXTURE2D, 0);

	norm91 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm91->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_Dol.dds", RESOURCE_TEXTURE2D, 0);

	norm92 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm92->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_Doorlock.dds", RESOURCE_TEXTURE2D, 0);

	norm93 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm93->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_front.dds", RESOURCE_TEXTURE2D, 0);

	norm94 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm94->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_garomak1.dds", RESOURCE_TEXTURE2D, 0);

	norm95 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm95->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_gidung.dds", RESOURCE_TEXTURE2D, 0);

	norm96 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm96->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_hwall1.dds", RESOURCE_TEXTURE2D, 0);

	norm97 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm97->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_lamp.dds", RESOURCE_TEXTURE2D, 0);

	norm98 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm98->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_takja.dds", RESOURCE_TEXTURE2D, 0);

	norm99 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm99->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_TV.dds", RESOURCE_TEXTURE2D, 0);

	norm100 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm100->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_Vending.dds", RESOURCE_TEXTURE2D, 0);

	norm101 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm101->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/norm/Receps_wall1.dds", RESOURCE_TEXTURE2D, 0);

	norm102 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm102->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/item/capacity.dds", RESOURCE_TEXTURE2D, 0);

	norm103 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm103->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/item/boost.dds", RESOURCE_TEXTURE2D, 0);

	norm104 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	norm104->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/item/stat.dds", RESOURCE_TEXTURE2D, 0);




	normals.push_back(norm35);
	normals.push_back(norm36);
	normals.push_back(norm37);
	normals.push_back(norm38);
	normals.push_back(norm39);
	normals.push_back(norm40);

	normals.push_back(norm41);
	normals.push_back(norm42);
	normals.push_back(norm43);
	normals.push_back(norm44);
	normals.push_back(norm45);
	normals.push_back(norm46);
	normals.push_back(norm47);
	normals.push_back(norm48);
	normals.push_back(norm49);
	normals.push_back(norm50);

	normals.push_back(norm51);
	normals.push_back(norm52);
	normals.push_back(norm53);
	normals.push_back(norm54);
	normals.push_back(norm55);
	normals.push_back(norm56);
	normals.push_back(norm57);
	normals.push_back(norm58);
	normals.push_back(norm59);
	normals.push_back(norm60);

	normals.push_back(norm61);
	normals.push_back(norm62);
	normals.push_back(norm63);
	normals.push_back(norm64);
	normals.push_back(norm65);
	normals.push_back(norm66);
	normals.push_back(norm67);
	normals.push_back(norm68);
	normals.push_back(norm69);
	normals.push_back(norm70);

	normals.push_back(norm71);
	normals.push_back(norm72);
	normals.push_back(norm73);
	normals.push_back(norm74);
	normals.push_back(norm75);
	normals.push_back(norm76);
	normals.push_back(norm77);
	normals.push_back(norm78);
	normals.push_back(norm79);
	normals.push_back(norm80);

	normals.push_back(norm81);
	normals.push_back(norm82);
	normals.push_back(norm83);
	normals.push_back(norm84);
	normals.push_back(norm85);
	normals.push_back(norm86);
	normals.push_back(norm87);
	normals.push_back(norm88);
	normals.push_back(norm89);
	normals.push_back(norm90);

	normals.push_back(norm91);
	normals.push_back(norm92);
	normals.push_back(norm93);
	normals.push_back(norm94);
	normals.push_back(norm95);
	normals.push_back(norm96);
	normals.push_back(norm97);
	normals.push_back(norm98);
	normals.push_back(norm99);
	normals.push_back(norm100);

	normals.push_back(norm101);
	normals.push_back(norm102);
	normals.push_back(norm103);
	normals.push_back(norm104);


	CTexture* spc1; CTexture* spc2; CTexture* spc3; CTexture* spc4; CTexture* spc5; CTexture* spc6; CTexture* spc7; CTexture* spc8; CTexture* spc9; CTexture* spc10;
	CTexture* spc11; CTexture* spc12; CTexture* spc13; CTexture* spc14; CTexture* spc15; CTexture* spc16; CTexture* spc17; CTexture* spc18; CTexture* spc19; CTexture* spc20;
	CTexture* spc21; CTexture* spc22; CTexture* spc23; CTexture* spc24; CTexture* spc25; CTexture* spc26; CTexture* spc27; CTexture* spc28; CTexture* spc29; CTexture* spc30;
	CTexture* spc31; CTexture* spc32; CTexture* spc33; CTexture* spc34; CTexture* spc35; CTexture* spc36; CTexture* spc37; CTexture* spc38; CTexture* spc39; CTexture* spc40;
	CTexture* spc41; CTexture* spc42; CTexture* spc43; CTexture* spc44; CTexture* spc45; CTexture* spc46; CTexture* spc47; CTexture* spc48; CTexture* spc49; CTexture* spc50;
	CTexture* spc51; CTexture* spc52; CTexture* spc53; CTexture* spc54; CTexture* spc55; CTexture* spc56; CTexture* spc57; CTexture* spc58; CTexture* spc59; CTexture* spc60;
	CTexture* spc61; CTexture* spc62; CTexture* spc63; CTexture* spc64; CTexture* spc65; CTexture* spc66; CTexture* spc67; CTexture* spc68; CTexture* spc69; CTexture* spc70;
	CTexture* spc71; CTexture* spc72; CTexture* spc73; CTexture* spc74; CTexture* spc75; CTexture* spc76; CTexture* spc77; CTexture* spc78; CTexture* spc79; CTexture* spc80;
	
	CTexture* spc81; CTexture* spc82; CTexture* spc83; CTexture* spc84; CTexture* spc85; CTexture* spc86; CTexture* spc87; CTexture* spc88; CTexture* spc89; CTexture* spc90;
	CTexture* spc91; CTexture* spc92; CTexture* spc93; CTexture* spc94; CTexture* spc95; CTexture* spc96; CTexture* spc97; CTexture* spc98; CTexture* spc99; CTexture* spc100;
	CTexture* spc101; CTexture* spc102; CTexture* spc103; CTexture* spc104; CTexture* spc105; CTexture* spc106; CTexture* spc107; CTexture* spc108; CTexture* spc109; CTexture* spc110;


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

	spc33 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc33->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/airfan.dds", RESOURCE_TEXTURE2D, 0);
	spc34 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc34->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/banner.dds", RESOURCE_TEXTURE2D, 0);
	spc35 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc35->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/bigshield.dds", RESOURCE_TEXTURE2D, 0);
	spc36 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc36->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/bottle.dds", RESOURCE_TEXTURE2D, 0);
	spc37 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc37->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/brick1.dds", RESOURCE_TEXTURE2D, 0);
	spc38 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc38->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/brick2.dds", RESOURCE_TEXTURE2D, 0);
	spc39 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc39->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/brick3.dds", RESOURCE_TEXTURE2D, 0);
	spc40 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc40->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/bucket.dds", RESOURCE_TEXTURE2D, 0);
	spc41 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc41->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/ceiling.dds", RESOURCE_TEXTURE2D, 0);
	spc42 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc42->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/cont.dds", RESOURCE_TEXTURE2D, 0);
	spc43 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc43->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/dooropen.dds", RESOURCE_TEXTURE2D, 0);
	spc44 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc44->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/drill.dds", RESOURCE_TEXTURE2D, 0);
	spc45 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc45->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/floor.dds", RESOURCE_TEXTURE2D, 0);
	spc46 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc46->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/floorconvey.dds", RESOURCE_TEXTURE2D, 0);
	spc47 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc47->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/furniture1.dds", RESOURCE_TEXTURE2D, 0);
	spc48 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc48->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/furniture2.dds", RESOURCE_TEXTURE2D, 0);
	spc49 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc49->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/glue.dds", RESOURCE_TEXTURE2D, 0);
	spc50 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc50->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/hammer.dds", RESOURCE_TEXTURE2D, 0);
	spc51 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc51->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/klin.dds", RESOURCE_TEXTURE2D, 0);
	spc52 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc52->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/log1.dds", RESOURCE_TEXTURE2D, 0);
	spc53 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc53->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/log2.dds", RESOURCE_TEXTURE2D, 0);
	spc54 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc54->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/longtank.dds", RESOURCE_TEXTURE2D, 0);
	spc55 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc55->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/machine1.dds", RESOURCE_TEXTURE2D, 0);
	spc56 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc56->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/machine3.dds", RESOURCE_TEXTURE2D, 0);
	spc57 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc57->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/machine4.dds", RESOURCE_TEXTURE2D, 0);
	spc58 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc58->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/machine6.dds", RESOURCE_TEXTURE2D, 0);
	spc59 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc59->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/machine7.dds", RESOURCE_TEXTURE2D, 0);
	spc60 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc60->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/robotarm.dds", RESOURCE_TEXTURE2D, 0);
	spc61 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc61->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/saw.dds", RESOURCE_TEXTURE2D, 0);
	spc62 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc62->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/sewer.dds", RESOURCE_TEXTURE2D, 0);
	spc63 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc63->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/shield.dds", RESOURCE_TEXTURE2D, 0);
	spc64 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc64->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/table1.dds", RESOURCE_TEXTURE2D, 0);
	spc65 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc65->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/toolbox.dds", RESOURCE_TEXTURE2D, 0);
	spc66 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc66->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/wall.dds", RESOURCE_TEXTURE2D, 0);
	spc67 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc67->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/wheel.dds", RESOURCE_TEXTURE2D, 0);
	spc68 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc68->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/whiteboard.dds", RESOURCE_TEXTURE2D, 0);
	spc69 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc69->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area1_2/spec/wireframe.dds", RESOURCE_TEXTURE2D, 0);

	// 2-1

	spc70 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc70->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwangjae1.dds", RESOURCE_TEXTURE2D, 0);

	spc71 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc71->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanja_hwalls.dds", RESOURCE_TEXTURE2D, 0);

	spc72 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc72->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanja_Tabe.dds", RESOURCE_TEXTURE2D, 0);

	spc73 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc73->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanja_walls.dds", RESOURCE_TEXTURE2D, 0);

	spc74 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc74->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_badak1.dds", RESOURCE_TEXTURE2D, 0);

	spc75 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc75->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_badak2.dds", RESOURCE_TEXTURE2D, 0);

	spc76 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc76->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_beok1.dds", RESOURCE_TEXTURE2D, 0);

	spc77 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc77->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_CheonJang1.dds", RESOURCE_TEXTURE2D, 0);

	spc78 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc78->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_Screen.dds", RESOURCE_TEXTURE2D, 0);

	spc79 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc79->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_Screen2.dds", RESOURCE_TEXTURE2D, 0);

	spc80 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc80->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_Takza.dds", RESOURCE_TEXTURE2D, 0);

	spc81 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc81->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanjae_Chair.dds", RESOURCE_TEXTURE2D, 0);

	spc82 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc82->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-1/spec/Gwanja_Cabinet.dds", RESOURCE_TEXTURE2D, 0);


	// 2=2
	spc83 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc83->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/airfan.dds", RESOURCE_TEXTURE2D, 0);

	spc84 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc84->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_1000jang.dds", RESOURCE_TEXTURE2D, 0);

	spc85 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc85->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_badak1.dds", RESOURCE_TEXTURE2D, 0);

	spc86 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc86->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_couch.dds", RESOURCE_TEXTURE2D, 0);

	spc87 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc87->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_Counter.dds", RESOURCE_TEXTURE2D, 0);

	spc88 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc88->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_desk4.dds", RESOURCE_TEXTURE2D, 0);

	spc89 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc89->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_Dol.dds", RESOURCE_TEXTURE2D, 0);

	spc90 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc90->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_Doorlock.dds", RESOURCE_TEXTURE2D, 0);

	spc91 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc91->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_front.dds", RESOURCE_TEXTURE2D, 0);

	spc92 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc92->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_garomak1.dds", RESOURCE_TEXTURE2D, 0);

	spc93 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc93->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_gidung.dds", RESOURCE_TEXTURE2D, 0);

	spc94 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc94->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_hwall1.dds", RESOURCE_TEXTURE2D, 0);

	spc95 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc95->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_lamp.dds", RESOURCE_TEXTURE2D, 0);

	spc96 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc96->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_takja.dds", RESOURCE_TEXTURE2D, 0);

	spc97 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc97->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_TV.dds", RESOURCE_TEXTURE2D, 0);

	spc98 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc98->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_Vending.dds", RESOURCE_TEXTURE2D, 0);

	spc99 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc99->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/area2-2/spec/Receps_wall1.dds", RESOURCE_TEXTURE2D, 0);

	spc100 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);
	spc100->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/item/spec_capacity.dds", RESOURCE_TEXTURE2D, 0);
	spc101 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);					  
	spc101->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/item/spec_boost.dds", RESOURCE_TEXTURE2D, 0);
	spc102 = new CTexture(1, RESOURCE_TEXTURE2D, 0, 1);					  
	spc102->LoadTextureFromDDSFile(pd3dDevice, pd3dCommandList, L"res/dds/normal/item/spec_stat.dds", RESOURCE_TEXTURE2D, 0);


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
	specs.push_back(spc33);
	specs.push_back(spc34);
	specs.push_back(spc35);
	specs.push_back(spc36);
	specs.push_back(spc37);
	specs.push_back(spc38);
	specs.push_back(spc39);
	specs.push_back(spc40);

	specs.push_back(spc41);
	specs.push_back(spc42);
	specs.push_back(spc43);
	specs.push_back(spc44);
	specs.push_back(spc45);
	specs.push_back(spc46);
	specs.push_back(spc47);
	specs.push_back(spc48);
	specs.push_back(spc49);
	specs.push_back(spc50);

	specs.push_back(spc51);
	specs.push_back(spc52);
	specs.push_back(spc53);
	specs.push_back(spc54);
	specs.push_back(spc55);
	specs.push_back(spc56);
	specs.push_back(spc57);
	specs.push_back(spc58);
	specs.push_back(spc59);
	specs.push_back(spc60);

	specs.push_back(spc61);
	specs.push_back(spc62);
	specs.push_back(spc63);
	specs.push_back(spc64);
	specs.push_back(spc65);
	specs.push_back(spc66);
	specs.push_back(spc67);
	specs.push_back(spc68);
	specs.push_back(spc69);
	specs.push_back(spc70);

	specs.push_back(spc71);
	specs.push_back(spc72);
	specs.push_back(spc73);
	specs.push_back(spc74);
	specs.push_back(spc75);
	specs.push_back(spc76);
	specs.push_back(spc77);
	specs.push_back(spc78);
	specs.push_back(spc79);
	specs.push_back(spc80);

	specs.push_back(spc81);
	specs.push_back(spc82);
	specs.push_back(spc83);
	specs.push_back(spc84);
	specs.push_back(spc85);
	specs.push_back(spc86);
	specs.push_back(spc87);
	specs.push_back(spc88);
	specs.push_back(spc89);
	specs.push_back(spc90);

	specs.push_back(spc91);
	specs.push_back(spc92);
	specs.push_back(spc93);
	specs.push_back(spc94);
	specs.push_back(spc95);
	specs.push_back(spc96);
	specs.push_back(spc97);
	specs.push_back(spc98);
	specs.push_back(spc99);

	specs.push_back(spc100);
	specs.push_back(spc101);
	specs.push_back(spc102);

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

	
	materials[7]->SetNormalTex(normals[2]);
	materials[8]->SetNormalTex(normals[3]);
	materials[15]->SetNormalTex(normals[4]);
	materials[28]->SetNormalTex(normals[5]);
	materials[30]->SetNormalTex(normals[6]);
	materials[23]->SetNormalTex(normals[7]);
	materials[16]->SetNormalTex(normals[8]);
	materials[26]->SetNormalTex(normals[9]);
	materials[31]->SetNormalTex(normals[10]);
	materials[12]->SetNormalTex(normals[11]);
	materials[10]->SetNormalTex(normals[12]);
	materials[11]->SetNormalTex(normals[14]);
	materials[27]->SetNormalTex(normals[16]);
	materials[13]->SetNormalTex(normals[17]);
	materials[17]->SetNormalTex(normals[19]);
	materials[18]->SetNormalTex(normals[20]);
	materials[32]->SetNormalTex(normals[21]);
	materials[33]->SetNormalTex(normals[22]);
	materials[14]->SetNormalTex(normals[23]);
	materials[6]->SetNormalTex(normals[24]);
	materials[34]->SetNormalTex(normals[26]);
	materials[21]->SetNormalTex(normals[27]);
	materials[35]->SetNormalTex(normals[28]);
	materials[25]->SetNormalTex(normals[29]);
	materials[29]->SetNormalTex(normals[30]);
	materials[24]->SetNormalTex(normals[31]);
	materials[19]->SetNormalTex(normals[32]);
	materials[22]->SetNormalTex(normals[33]);

	
	//노말은 여기서부터 문제
	
	materials[47]->SetNormalTex(normals[34]);
	//materials[78]->SetNormalTex(normals[35]);
	materials[45]->SetNormalTex(normals[36]);
	materials[72]->SetNormalTex(normals[37]);
	//materials[66]->SetNormalTex(normals[41]);
	materials[56]->SetNormalTex(normals[42]);
	
	
	//여기서부터 괜찮

	materials[59]->SetNormalTex(normals[43]);
	materials[76]->SetNormalTex(normals[44]);
	materials[61]->SetNormalTex(normals[45]);
	materials[57]->SetNormalTex(normals[46]);
	//materials[77]->SetNormalTex(normals[47]);
	materials[63]->SetNormalTex(normals[48]);
	materials[64]->SetNormalTex(normals[49]);
	materials[70]->SetNormalTex(normals[50]);

	materials[71]->SetNormalTex(normals[51]);
	materials[79]->SetNormalTex(normals[52]);
	materials[67]->SetNormalTex(normals[53]);
	materials[68]->SetNormalTex(normals[54]);
	materials[46]->SetNormalTex(normals[55]);


	materials[53]->SetNormalTex(normals[61]);
	materials[62]->SetNormalTex(normals[62]);
	materials[54]->SetNormalTex(normals[63]);
	materials[44]->SetNormalTex(normals[64]);
	materials[66]->SetNormalTex(normals[65]);
	materials[69]->SetNormalTex(normals[66]);
	materials[55]->SetNormalTex(normals[67]);
	//materials[80]->SetNormalTex(normals[68]);
	//materials[81]->SetNormalTex(normals[69]);
	materials[58]->SetNormalTex(normals[70]);

	
	materials[73]->SetNormalTex(normals[38]);
	materials[74]->SetNormalTex(normals[39]);
	materials[75]->SetNormalTex(normals[40]);
	


	materials[0]->SetSpecTex(specs[0]);
	materials[1]->SetSpecTex(specs[0]);
	materials[3]->SetSpecTex(specs[0]);

	materials[7]->SetSpecTex(specs[2]);
	materials[8]->SetSpecTex(specs[3]);
	materials[15]->SetSpecTex(specs[4]);
	materials[28]->SetSpecTex(specs[5]);
	materials[30]->SetSpecTex(specs[6]);
	materials[23]->SetSpecTex(specs[7]);
	materials[16]->SetSpecTex(specs[8]);
	materials[26]->SetSpecTex(specs[9]);
	materials[31]->SetSpecTex(specs[10]);
	materials[12]->SetSpecTex(specs[11]);
	materials[10]->SetSpecTex(specs[12]);
	materials[11]->SetSpecTex(specs[14]);
	materials[27]->SetSpecTex(specs[15]);
	materials[13]->SetSpecTex(specs[16]);
	materials[17]->SetSpecTex(specs[18]);
	materials[18]->SetSpecTex(specs[19]);
	materials[32]->SetSpecTex(specs[20]);
	materials[33]->SetSpecTex(specs[21]);
	materials[14]->SetSpecTex(specs[22]);
	materials[6]->SetSpecTex(specs[23]);
	materials[34]->SetSpecTex(specs[24]);
	materials[21]->SetSpecTex(specs[25]);
	materials[35]->SetSpecTex(specs[26]);
	materials[25]->SetSpecTex(specs[27]);
	materials[24]->SetSpecTex(specs[28]);
	materials[29]->SetSpecTex(specs[29]);
	materials[19]->SetSpecTex(specs[30]);
	materials[12]->SetSpecTex(specs[31]);
	
	//스페큘러는 여기서부터 문제

	
	materials[47]->SetSpecTex(specs[32]);
	//materials[78]->SetSpecTex(specs[33]);
	materials[45]->SetSpecTex(specs[34]);
	materials[72]->SetSpecTex(specs[35]);
	//materials[66]->SetSpecTex(specs[39]);
	materials[56]->SetSpecTex(specs[40]);
	
	//여기서부터 문제없음

	materials[31]->SetSpecTex(specs[41]);
	//materials[76]->SetSpecTex(specs[42]);
	materials[61]->SetSpecTex(specs[43]);
	materials[57]->SetSpecTex(specs[44]);
	//materials[77]->SetSpecTex(specs[45]);
	materials[63]->SetSpecTex(specs[46]);
	materials[64]->SetSpecTex(specs[47]);
	materials[70]->SetSpecTex(specs[48]);



	materials[71]->SetSpecTex(specs[49]);
	materials[79]->SetSpecTex(specs[50]);
	materials[67]->SetSpecTex(specs[51]);
	materials[68]->SetSpecTex(specs[52]);
	materials[46]->SetSpecTex(specs[53]);
	materials[53]->SetSpecTex(specs[59]);
	materials[62]->SetSpecTex(specs[60]);


	materials[54]->SetSpecTex(specs[61]);
	materials[44]->SetSpecTex(specs[62]);
	materials[66]->SetSpecTex(specs[63]);
	materials[69]->SetSpecTex(specs[64]);
	materials[55]->SetSpecTex(specs[65]);
	//materials[80]->SetSpecTex(specs[66]);
	//materials[81]->SetSpecTex(specs[67]);
	materials[58]->SetSpecTex(specs[68]);
	

	materials[73]->SetSpecTex(specs[36]);
	materials[74]->SetSpecTex(specs[37]);
	materials[75]->SetSpecTex(specs[38]);
	
	
	//2-1
	materials[88]->SetSpecTex(normals[71]);
	materials[89]->SetSpecTex(normals[72]);
	materials[111]->SetSpecTex(normals[73]);
	materials[90]->SetSpecTex(normals[74]);
	materials[91]->SetSpecTex(normals[75]);
	materials[92]->SetSpecTex(normals[76]);
	materials[93]->SetSpecTex(normals[77]);
	materials[95]->SetSpecTex(normals[78]);
	materials[96]->SetSpecTex(normals[79]);
	materials[110]->SetSpecTex(normals[80]);
	materials[85]->SetSpecTex(normals[81]);
	materials[112]->SetSpecTex(normals[83]);
	materials[82]->SetSpecTex(normals[82]);


	// 2=2
	materials[106]->SetSpecTex(normals[84]);
	materials[103]->SetSpecTex(normals[85]);
	materials[102]->SetSpecTex(normals[86]);
	materials[83]->SetSpecTex(normals[87]);
	materials[86]->SetSpecTex(normals[88]);
	materials[105]->SetSpecTex(normals[89]);
	materials[107]->SetSpecTex(normals[90]);
	materials[109]->SetSpecTex(normals[91]);
	materials[100]->SetSpecTex(normals[93]);
	materials[101]->SetSpecTex(normals[94]);
	materials[108]->SetSpecTex(normals[96]);
	materials[87]->SetSpecTex(normals[98]);
	materials[84]->SetSpecTex(normals[99]);
	materials[104]->SetSpecTex(normals[100]);


	// 2-1
	materials[88]->SetNormalTex(specs[69]);
	materials[89]->SetNormalTex(specs[70]);
	materials[111]->SetNormalTex(specs[71]);
	materials[90]->SetNormalTex(specs[72]);
	materials[91]->SetNormalTex(specs[73]);
	materials[92]->SetNormalTex(specs[74]);
	materials[93]->SetNormalTex(specs[75]);
	materials[95]->SetNormalTex(specs[76]);
	materials[96]->SetNormalTex(specs[77]);
	materials[110]->SetNormalTex(specs[78]);
	materials[85]->SetNormalTex(specs[79]);
	materials[112]->SetNormalTex(specs[81]);
	materials[82]->SetNormalTex(specs[80]);


	//2-2

	materials[106]->SetNormalTex(specs[82]);
	materials[103]->SetNormalTex(specs[83]);
	materials[102]->SetNormalTex(specs[84]);
	materials[83]->SetNormalTex(specs[85]);
	materials[86]->SetNormalTex(specs[86]);
	materials[105]->SetNormalTex(specs[87]);
	materials[107]->SetNormalTex(specs[88]);
	materials[109]->SetNormalTex(specs[89]);
	materials[100]->SetNormalTex(specs[91]);
	materials[101]->SetNormalTex(specs[92]);
	materials[108]->SetNormalTex(specs[94]);
	materials[87]->SetNormalTex(specs[96]);
	materials[84]->SetNormalTex(specs[97]);
	materials[104]->SetNormalTex(specs[98]);


	materials[396]->SetNormalTex(normals[101]);
	materials[397]->SetNormalTex(normals[102]);
	materials[398]->SetNormalTex(normals[103]);
	materials[399]->SetNormalTex(normals[103]);
	materials[400]->SetNormalTex(normals[103]);

	materials[396]->SetSpecTex(specs[99]);
	materials[397]->SetSpecTex(specs[100]);
	materials[398]->SetSpecTex(specs[101]);
	materials[399]->SetSpecTex(specs[101]);
	materials[400]->SetSpecTex(specs[101]);

}

void ResourceManager::createSound()
{
	
	CSound* bgm1 = new CSound("res/sound/bgm/electric2.mp3", true);
	bgm.push_back(bgm1);
	CSound* bgm2 = new CSound("res/sound/bgm/electric1.mp3", true);
	bgm.push_back(bgm2);
	

	CSound* ef1 = new CSound("res/sound/effect/rifle_shot.mp3", false);
	CSound* ef2 = new CSound("res/sound/effect/rifle_crash.ogg", false);
	CSound* ef3 = new CSound("res/sound/effect/step_steel.mp3", true);
	CSound* ef4 = new CSound("res/sound/effect/hammer_swing2.mp3", false);
	CSound* ef5 = new CSound("res/sound/effect/hammer_hit2.mp3", false);

	CSound* ef6 = new CSound("res/sound/effect/blade_swing.mp3", false);
	CSound* ef7 = new CSound("res/sound/effect/blade_hit.mp3", false);
	CSound* ef8 = new CSound("res/sound/effect/bazuka_shot.mp3", false);
	CSound* ef9 = new CSound("res/sound/effect/boom.mp3", false);
	CSound* ef10 = new CSound("res/sound/effect/radio_attack.mp3", false);
	CSound* ef11 = new CSound("res/sound/effect/die1.mp3", false);
	CSound* ef12 = new CSound("res/sound/effect/die2.mp3", false);
	
	effect.push_back(ef1);
	effect.push_back(ef2);
	effect.push_back(ef3);
	effect.push_back(ef4);
	effect.push_back(ef5);

	effect.push_back(ef6);
	effect.push_back(ef7);
	effect.push_back(ef8);
	effect.push_back(ef9);
	effect.push_back(ef10);

	effect.push_back(ef11);
	effect.push_back(ef12);

	//briefing

	CSound* m1x1 = new CSound("res/sound/effect/stage1/mission1/m1-1.mp3", false);
	CSound* m1x2 = new CSound("res/sound/effect/stage1/mission1/m1-2.mp3", false);
	CSound* m1x3 = new CSound("res/sound/effect/stage1/mission1/m1-3.mp3", false);
	CSound* m1x4 = new CSound("res/sound/effect/stage1/mission1/m1-4.mp3", false);

	CSound* mc1x1 = new CSound("res/sound/effect/stage1/mission1/m1c-1.mp3", false);
	CSound* mc1x2 = new CSound("res/sound/effect/stage1/mission1/m1c-2.mp3", false);
	CSound* mc1x3 = new CSound("res/sound/effect/stage1/mission1/m1c-3.mp3", false);

	CSound* m2x1 = new CSound("res/sound/effect/stage1/mission2/m2-1.mp3", false);
	CSound* m2x2 = new CSound("res/sound/effect/stage1/mission2/m2-2.mp3", false);
	CSound* m2x3 = new CSound("res/sound/effect/stage1/mission2/m2-3.mp3", false);

	CSound* mc2x1 = new CSound("res/sound/effect/stage1/mission2/m2c-1.mp3", false);
	CSound* mc2x2 = new CSound("res/sound/effect/stage1/mission2/m2c-2.mp3", false);
	CSound* mc2x3 = new CSound("res/sound/effect/stage1/mission2/m2c-3.mp3", false);
	CSound* mc2x4 = new CSound("res/sound/effect/stage1/mission2/m2c-4.mp3", false);
	CSound* mc2x5 = new CSound("res/sound/effect/stage1/mission2/m2c-5.mp3", false);
	CSound* mc2x6 = new CSound("res/sound/effect/stage1/mission2/m2c-6.mp3", false);

	CSound* m3x1 = new CSound("res/sound/effect/stage1/mission3/m3-1.mp3", false);
	CSound* m3x2 = new CSound("res/sound/effect/stage1/mission3/m3-2.mp3", false);
	CSound* m3x3 = new CSound("res/sound/effect/stage1/mission3/m3-3.mp3", false);

	CSound* mc3x1 = new CSound("res/sound/effect/stage1/mission3/m3c-1.mp3", false);
	CSound* mc3x2 = new CSound("res/sound/effect/stage1/mission3/m3c-2.mp3", false);
	CSound* mc3x3 = new CSound("res/sound/effect/stage1/mission3/m3c-3.mp3", false);

	CSound* m4x1 = new CSound("res/sound/effect/stage1/mission4/m4-1.mp3", false);
	CSound* m4x2 = new CSound("res/sound/effect/stage1/mission4/m4-2.mp3", false);
	CSound* m4x3 = new CSound("res/sound/effect/stage1/mission4/m4-3.mp3", false);
	CSound* m4x4 = new CSound("res/sound/effect/stage1/mission4/m4-4.mp3", false);

	CSound* mc4x1 = new CSound("res/sound/effect/stage1/mission4/m4c-1.mp3", false);
	CSound* mc4x2 = new CSound("res/sound/effect/stage1/mission4/m4c-2.mp3", false);

	CSound* m5x1 = new CSound("res/sound/effect/stage1/mission5/m5-1.mp3", false);
	CSound* m5x2 = new CSound("res/sound/effect/stage1/mission5/m5-2.mp3", false);
	CSound* m5x3 = new CSound("res/sound/effect/stage1/mission5/m5-3.mp3", false);

	CSound* mc5x1 = new CSound("res/sound/effect/stage1/mission5/m5c-1.mp3", false);
	CSound* mc5x2 = new CSound("res/sound/effect/stage1/mission5/m5c-2.mp3", false);

	CSound* m6x1 = new CSound("res/sound/effect/stage1/mission6/m6-1.mp3", false);

	CSound* mc6x1 = new CSound("res/sound/effect/stage1/mission6/m6c-1.mp3", false);
	CSound* mc6x2 = new CSound("res/sound/effect/stage1/mission6/m6c-2.mp3", false);

	CSound* m7x1 = new CSound("res/sound/effect/stage1/mission7/m7-1.mp3", false);
	CSound* m7x2 = new CSound("res/sound/effect/stage1/mission7/m7-2.mp3", false);

	CSound* mc7x1 = new CSound("res/sound/effect/stage1/mission7/m7c-1.mp3", false);

	CSound* m8x1 = new CSound("res/sound/effect/stage1/mission8/m8-1.mp3", false);
	CSound* m8x2 = new CSound("res/sound/effect/stage1/mission8/m8-2.mp3", false);
	CSound* m8x3 = new CSound("res/sound/effect/stage1/mission8/m8-3.mp3", false);

	CSound* m9x1 = new CSound("res/sound/effect/stage1/mission9/m9-1.mp3", false);
	CSound* m9x2 = new CSound("res/sound/effect/stage1/mission9/m9-2.mp3", false);
	CSound* m9x3 = new CSound("res/sound/effect/stage1/mission9/m9-3.mp3", false);
	CSound* m9x4 = new CSound("res/sound/effect/stage1/mission9/m9-4.mp3", false);

	CSound* mc9x1 = new CSound("res/sound/effect/stage1/mission9/m9c-1.mp3", false);

	CSound* m10x1 = new CSound("res/sound/effect/stage1/mission10/m10-1.mp3", false);
	CSound* m10x2 = new CSound("res/sound/effect/stage1/mission10/m10-2.mp3", false);
	CSound* m10x3 = new CSound("res/sound/effect/stage1/mission10/m10-3.mp3", false);

	CSound* mc10x1 = new CSound("res/sound/effect/stage1/mission10/m10c-1.mp3", false);

	//0~3 brief 1
	brief.push_back(m1x1);
	brief.push_back(m1x2);
	brief.push_back(m1x3);
	brief.push_back(m1x4);
	//4~6 clear 1
	brief.push_back(mc1x1);
	brief.push_back(mc1x2);
	brief.push_back(mc1x3);
	//7~9 brief 2

	brief.push_back(m2x1);
	brief.push_back(m2x2);
	brief.push_back(m2x3);

	//10~15 clear 2
	brief.push_back(mc2x1);
	brief.push_back(mc2x2);
	brief.push_back(mc2x3);
	brief.push_back(mc2x4);
	brief.push_back(mc2x5);
	brief.push_back(mc2x6);

	//16~18 brief 3
	brief.push_back(m3x1);
	brief.push_back(m3x2);
	brief.push_back(m3x3);

	//19~21 clear 3
	brief.push_back(mc3x1);
	brief.push_back(mc3x2);
	brief.push_back(mc3x3);

	//22~25 brief 4
	brief.push_back(m4x1);
	brief.push_back(m4x2);
	brief.push_back(m4x3);
	brief.push_back(m4x4);

	//26~27 clear 4
	brief.push_back(mc4x1);
	brief.push_back(mc4x2);

	//28~30 brief 5
	brief.push_back(m5x1);
	brief.push_back(m5x2);
	brief.push_back(m5x3);

	//31~32 clear 5
	brief.push_back(mc5x1);
	brief.push_back(mc5x2);

	//33 brief 6
	brief.push_back(m6x1);

	//34~35 clear 6
	brief.push_back(mc6x1);
	brief.push_back(mc6x2);

	//36~37 brief 7
	brief.push_back(m7x1);
	brief.push_back(m7x2);

	//38 clear 7
	brief.push_back(mc7x1);

	//39~41 brief 8
	brief.push_back(m8x1);
	brief.push_back(m8x2);
	brief.push_back(m8x3);

	//42~45 brief 9
	brief.push_back(m9x1);
	brief.push_back(m9x2);
	brief.push_back(m9x3);
	brief.push_back(m9x4);

	//46 clear 9
	brief.push_back(mc9x1);

	//47~49 brief 10
	brief.push_back(m10x1);
	brief.push_back(m10x2);
	brief.push_back(m10x3);

	//50 clear 10
	brief.push_back(mc10x1);


	bgm[0]->setVolume(0.1f);
	bgm[0]->Update();
	bgm[1]->setVolume(0.1f);
	bgm[1]->Update();
	for (int i = 0; i < effect.size(); ++i)
	{
		effect[i]->setVolume(0.75f);
		effect[i]->Update();
	}

	for (int i = 0; i < brief.size(); ++i)
	{
		brief[i]->setVolume(0.8f);
		brief[i]->Update();
		briefPlayed.push_back(false);
		timePlayed.push_back(chrono::system_clock::now());
	}
}

void ResourceManager::createModels(ID3D12RootSignature* m_pd3dGraphicsRootSignature)
{
	CLoadedModelInfo* model1;
	CLoadedModelInfo* model2;
	CLoadedModelInfo* model3;
	CLoadedModelInfo* model4;
	CLoadedModelInfo* model5;
	CLoadedModelInfo* model6;
	CLoadedModelInfo* model7;
	CLoadedModelInfo* model8;
	CLoadedModelInfo* model9;
	CLoadedModelInfo* model10;
	CLoadedModelInfo* model11;
	CLoadedModelInfo* model12;
	CLoadedModelInfo* model13;
	CLoadedModelInfo* model14;
	CLoadedModelInfo* model15;
	CLoadedModelInfo* model16;
	CLoadedModelInfo* model17;
	CLoadedModelInfo* model18;
	CLoadedModelInfo* model19;
	CLoadedModelInfo* model20;
	
	CLoadedModelInfo* model21;
	CLoadedModelInfo* model22;
	CLoadedModelInfo* model23;
	CLoadedModelInfo* model24;
	CLoadedModelInfo* model25;
	CLoadedModelInfo* model26;
	CLoadedModelInfo* model27;
	CLoadedModelInfo* model28;
	CLoadedModelInfo* model29;
	CLoadedModelInfo* model30;

	model1 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rifle_idle.bin", NULL);
	playerModels.push_back(model1);
	model2 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_run.bin", NULL);
	playerModels.push_back(model2);
	model3 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rescale4.bin", NULL);
	playerModels.push_back(model3);
	model4 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_attack1.bin", NULL);
	playerModels.push_back(model4);
	model5 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_attack2.bin", NULL);
	playerModels.push_back(model5);
	model6 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/bazuka_attack.bin", NULL);
	playerModels.push_back(model6);
	model7 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/bazuka_run.bin", NULL);
	playerModels.push_back(model7);

	model8 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/radio_run.bin", NULL);
	playerModels.push_back(model8);
	model9 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/radio_attack.bin", NULL);
	playerModels.push_back(model9);
	model10 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/radio_idle.bin", NULL);
	playerModels.push_back(model10);

	model11 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/radio_idle.bin", NULL);
	playerModels.push_back(model11);
	model12 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/bazuka_idle.bin", NULL);
	playerModels.push_back(model12);
	model13 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blade_idle.bin", NULL);
	playerModels.push_back(model13);
	model14 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blade_swing_left.bin", NULL);
	playerModels.push_back(model14);
	model15 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blade_swing_right.bin", NULL);
	playerModels.push_back(model15);

	model16 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rifle_run.bin", NULL);
	playerModels.push_back(model16);

	model17 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rifle_attack_run.bin", NULL);
	playerModels.push_back(model17);
	model18 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blunt_run_attack.bin", NULL);
	playerModels.push_back(model18);

	model19 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rifle_run.bin", NULL);
	playerModels.push_back(model19);

	model20 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rifle_attack.bin", NULL);
	playerModels.push_back(model20);

	model21 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/rifle_idle.bin", NULL);
	playerModels.push_back(model21);
	model22 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/blade_run.bin", NULL);
	playerModels.push_back(model22);

	CLoadedModelInfo* e1;
	CLoadedModelInfo* e2;
	CLoadedModelInfo* e3;
	CLoadedModelInfo* e4;
	CLoadedModelInfo* e5;
	CLoadedModelInfo* e6;
	CLoadedModelInfo* e7;
	CLoadedModelInfo* e8;
	CLoadedModelInfo* e9;
	CLoadedModelInfo* e10;
	CLoadedModelInfo* e11;
	CLoadedModelInfo* e12;
	
	e1 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_idle.bin", NULL);
	enemyModels.push_back(e1);
	e2 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/1/enemy_gun_die.bin", NULL);
	enemyModels.push_back(e2);
	e3 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_walk.bin", NULL);
	enemyModels.push_back(e3);
	e4 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_run.bin", NULL);
	enemyModels.push_back(e4);
	e5 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_gun_attack.bin", NULL);
	enemyModels.push_back(e5);

	e6 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_stun.bin", NULL);
	enemyModels.push_back(e6);
	e7 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_blunt_stun.bin", NULL);
	enemyModels.push_back(e7);

	e8 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_blunt_attack.bin", NULL);
	enemyModels.push_back(e8);
	e9 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/1/enemy_blunt_die.bin", NULL);
	enemyModels.push_back(e9);
	e10 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_blunt_walk.bin", NULL);
	enemyModels.push_back(e10);
	e11 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_blunt_idle.bin", NULL);
	enemyModels.push_back(e11);
	e12 = CGameObject::LoadGeometryAndAnimationFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "res/bin/enemy_blunt_run.bin", NULL);
	enemyModels.push_back(e12);
	
	CAnimationController* cont1 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[0]);
	CAnimationController* cont2 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[1]);
	CAnimationController* cont3 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[2]);
	CAnimationController* cont4 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[3]);
	CAnimationController* cont5 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[4]);
	CAnimationController* cont6 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[5]);
	CAnimationController* cont7 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[6]);
	CAnimationController* cont8 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[7]);
	CAnimationController* cont9 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[8]);
	CAnimationController* cont10 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[9]);
	CAnimationController* cont11 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[10]);
	CAnimationController* cont12 = new CAnimationController(pd3dDevice, pd3dCommandList, 1, enemyModels[11]);

	conts.push_back(cont1);
	conts.push_back(cont2);
	conts.push_back(cont3);
	conts.push_back(cont4);
	conts.push_back(cont5);
	conts.push_back(cont6);
	conts.push_back(cont7);
	conts.push_back(cont8);
	conts.push_back(cont9);
	conts.push_back(cont10);
	conts.push_back(cont11);
	conts.push_back(cont12);
	



}