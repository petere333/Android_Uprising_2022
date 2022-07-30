//-----------------------------------------------------------------------------
// File: CGameFramework.cpp
//-----------------------------------------------------------------------------
#pragma once 

#include "stdafx.h"
#include "GameFramework.h"
#include "CNet.h"

CGameFramework::CGameFramework()
{
	m_pdxgiFactory = NULL;
	m_pdxgiSwapChain = NULL;
	m_pd3dDevice = NULL;

	for (int i = 0; i < m_nSwapChainBuffers; i++) m_ppd3dSwapChainBackBuffers[i] = NULL;
	m_nSwapChainBufferIndex = 0;

	m_pd3dCommandAllocator = NULL;
	m_pd3dCommandQueue = NULL;
	m_pd3dCommandList = NULL;

	m_pd3dRtvDescriptorHeap = NULL;
	m_pd3dDsvDescriptorHeap = NULL;

	m_nRtvDescriptorIncrementSize = 0;
	m_nDsvDescriptorIncrementSize = 0;

	m_hFenceEvent = NULL;
	m_pd3dFence = NULL;
	for (int i = 0; i < m_nSwapChainBuffers; i++) m_nFenceValues[i] = 0;

	m_nWndClientWidth = FRAME_BUFFER_WIDTH;
	m_nWndClientHeight = FRAME_BUFFER_HEIGHT;

	m_pScene = NULL;
	

	_tcscpy_s(m_pszFrameRate, _T("�ȵ���̵� ������¡ ("));
}

CGameFramework::~CGameFramework()
{
}



bool CGameFramework::OnCreate(HINSTANCE hInstance, HWND hMainWnd)
{
	
	m_hInstance = hInstance;
	m_hWnd = hMainWnd;
	
	CreateDirect3DDevice();
	CreateCommandQueueAndList();
	CreateRtvAndDsvDescriptorHeaps();
	CreateSwapChain();
	CreateDepthStencilView();
	CoInitialize(NULL);
	
	CSound::Init();

	SetCursorPos(500, 500);
	prevX = 500;
	prevY = 500;
	

	BuildObjects();

	Connection();
	LoginServer();

	

	return(true);
}

void CGameFramework::CreateSwapChain()
{
	RECT rcClient;
	::GetClientRect(m_hWnd, &rcClient);
	m_nWndClientWidth = rcClient.right - rcClient.left;
	m_nWndClientHeight = rcClient.bottom - rcClient.top;

#ifdef _WITH_CREATE_SWAPCHAIN_FOR_HWND
	DXGI_SWAP_CHAIN_DESC1 dxgiSwapChainDesc;
	::ZeroMemory(&dxgiSwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC1));
	dxgiSwapChainDesc.Width = m_nWndClientWidth;
	dxgiSwapChainDesc.Height = m_nWndClientHeight;
	dxgiSwapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiSwapChainDesc.SampleDesc.Count = (m_bMsaa4xEnable) ? 4 : 1;
	dxgiSwapChainDesc.SampleDesc.Quality = (m_bMsaa4xEnable) ? (m_nMsaa4xQualityLevels - 1) : 0;
	dxgiSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxgiSwapChainDesc.BufferCount = m_nSwapChainBuffers;
	dxgiSwapChainDesc.Scaling = DXGI_SCALING_NONE;
	dxgiSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	dxgiSwapChainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
	dxgiSwapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	DXGI_SWAP_CHAIN_FULLSCREEN_DESC dxgiSwapChainFullScreenDesc;
	::ZeroMemory(&dxgiSwapChainFullScreenDesc, sizeof(DXGI_SWAP_CHAIN_FULLSCREEN_DESC));
	dxgiSwapChainFullScreenDesc.RefreshRate.Numerator = 60;
	dxgiSwapChainFullScreenDesc.RefreshRate.Denominator = 1;
	dxgiSwapChainFullScreenDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	dxgiSwapChainFullScreenDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	dxgiSwapChainFullScreenDesc.Windowed = TRUE;

	HRESULT hResult = m_pdxgiFactory->CreateSwapChainForHwnd(m_pd3dCommandQueue, m_hWnd, &dxgiSwapChainDesc, &dxgiSwapChainFullScreenDesc, NULL, (IDXGISwapChain1 **)&m_pdxgiSwapChain);
#else
	DXGI_SWAP_CHAIN_DESC dxgiSwapChainDesc;
	::ZeroMemory(&dxgiSwapChainDesc, sizeof(dxgiSwapChainDesc));
	dxgiSwapChainDesc.BufferCount = m_nSwapChainBuffers;
	dxgiSwapChainDesc.BufferDesc.Width = m_nWndClientWidth;
	dxgiSwapChainDesc.BufferDesc.Height = m_nWndClientHeight;
	dxgiSwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiSwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	dxgiSwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	dxgiSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxgiSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	dxgiSwapChainDesc.OutputWindow = m_hWnd;
	dxgiSwapChainDesc.SampleDesc.Count = (m_bMsaa4xEnable) ? 4 : 1;
	dxgiSwapChainDesc.SampleDesc.Quality = (m_bMsaa4xEnable) ? (m_nMsaa4xQualityLevels - 1) : 0;
	dxgiSwapChainDesc.Windowed = TRUE;
	dxgiSwapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	HRESULT hResult = m_pdxgiFactory->CreateSwapChain(m_pd3dCommandQueue, &dxgiSwapChainDesc, (IDXGISwapChain **)&m_pdxgiSwapChain);
#endif
	m_nSwapChainBufferIndex = m_pdxgiSwapChain->GetCurrentBackBufferIndex();

	hResult = m_pdxgiFactory->MakeWindowAssociation(m_hWnd, DXGI_MWA_NO_ALT_ENTER);

#ifndef _WITH_SWAPCHAIN_FULLSCREEN_STATE
	CreateRenderTargetViews();
#endif
}

void CGameFramework::CreateDirect3DDevice()
{
	HRESULT hResult;

	UINT nDXGIFactoryFlags = 0;
#if defined(_DEBUG)
	ID3D12Debug *pd3dDebugController = NULL;
	hResult = D3D12GetDebugInterface(__uuidof(ID3D12Debug), (void **)&pd3dDebugController);
	if (pd3dDebugController)
	{
		pd3dDebugController->EnableDebugLayer();
		pd3dDebugController->Release();
	}
	nDXGIFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
#endif

	hResult = ::CreateDXGIFactory2(nDXGIFactoryFlags, __uuidof(IDXGIFactory4), (void **)&m_pdxgiFactory);

	IDXGIAdapter1 *pd3dAdapter = NULL;

	for (UINT i = 0; DXGI_ERROR_NOT_FOUND != m_pdxgiFactory->EnumAdapters1(i, &pd3dAdapter); i++)
	{
		DXGI_ADAPTER_DESC1 dxgiAdapterDesc;
		pd3dAdapter->GetDesc1(&dxgiAdapterDesc);
		if (dxgiAdapterDesc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;
		if (SUCCEEDED(D3D12CreateDevice(pd3dAdapter, D3D_FEATURE_LEVEL_12_0, _uuidof(ID3D12Device), (void **)&m_pd3dDevice))) break;
	}

	if (!pd3dAdapter)
	{
		m_pdxgiFactory->EnumWarpAdapter(_uuidof(IDXGIFactory4), (void **)&pd3dAdapter);
		hResult = D3D12CreateDevice(pd3dAdapter, D3D_FEATURE_LEVEL_12_0, _uuidof(ID3D12Device), (void **)&m_pd3dDevice);
	}

	D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS d3dMsaaQualityLevels;
	d3dMsaaQualityLevels.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	d3dMsaaQualityLevels.SampleCount = 4;
	d3dMsaaQualityLevels.Flags = D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE;
	d3dMsaaQualityLevels.NumQualityLevels = 0;
	hResult = m_pd3dDevice->CheckFeatureSupport(D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &d3dMsaaQualityLevels, sizeof(D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS));
	m_nMsaa4xQualityLevels = d3dMsaaQualityLevels.NumQualityLevels;
	m_bMsaa4xEnable = (m_nMsaa4xQualityLevels > 1) ? true : false;

	hResult = m_pd3dDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, __uuidof(ID3D12Fence), (void **)&m_pd3dFence);
	for (UINT i = 0; i < m_nSwapChainBuffers; i++) m_nFenceValues[i] = 0;

	m_hFenceEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);

	if (pd3dAdapter) pd3dAdapter->Release();
}

void CGameFramework::CreateCommandQueueAndList()
{
	HRESULT hResult;

	D3D12_COMMAND_QUEUE_DESC d3dCommandQueueDesc;
	::ZeroMemory(&d3dCommandQueueDesc, sizeof(D3D12_COMMAND_QUEUE_DESC));
	d3dCommandQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	d3dCommandQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	hResult = m_pd3dDevice->CreateCommandQueue(&d3dCommandQueueDesc, _uuidof(ID3D12CommandQueue), (void **)&m_pd3dCommandQueue);

	hResult = m_pd3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator), (void **)&m_pd3dCommandAllocator);

	hResult = m_pd3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_pd3dCommandAllocator, NULL, __uuidof(ID3D12GraphicsCommandList), (void **)&m_pd3dCommandList);
	hResult = m_pd3dCommandList->Close();
}

void CGameFramework::CreateRtvAndDsvDescriptorHeaps()
{
	D3D12_DESCRIPTOR_HEAP_DESC d3dDescriptorHeapDesc;
	::ZeroMemory(&d3dDescriptorHeapDesc, sizeof(D3D12_DESCRIPTOR_HEAP_DESC));
	d3dDescriptorHeapDesc.NumDescriptors = m_nSwapChainBuffers;
	d3dDescriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	d3dDescriptorHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	d3dDescriptorHeapDesc.NodeMask = 0;
	HRESULT hResult = m_pd3dDevice->CreateDescriptorHeap(&d3dDescriptorHeapDesc, __uuidof(ID3D12DescriptorHeap), (void **)&m_pd3dRtvDescriptorHeap);
	m_nRtvDescriptorIncrementSize = m_pd3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

	d3dDescriptorHeapDesc.NumDescriptors = 1;
	d3dDescriptorHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
	hResult = m_pd3dDevice->CreateDescriptorHeap(&d3dDescriptorHeapDesc, __uuidof(ID3D12DescriptorHeap), (void **)&m_pd3dDsvDescriptorHeap);
	m_nDsvDescriptorIncrementSize = m_pd3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);

	::gnCbvSrvDescriptorIncrementSize = m_pd3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

void CGameFramework::CreateRenderTargetViews()
{
	D3D12_CPU_DESCRIPTOR_HANDLE d3dRtvCPUDescriptorHandle = m_pd3dRtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	for (UINT i = 0; i < m_nSwapChainBuffers; i++)
	{
		m_pdxgiSwapChain->GetBuffer(i, __uuidof(ID3D12Resource), (void **)&m_ppd3dSwapChainBackBuffers[i]);
		m_pd3dDevice->CreateRenderTargetView(m_ppd3dSwapChainBackBuffers[i], NULL, d3dRtvCPUDescriptorHandle);
		d3dRtvCPUDescriptorHandle.ptr += m_nRtvDescriptorIncrementSize;
	}
}

void CGameFramework::CreateDepthStencilView()
{
	D3D12_RESOURCE_DESC d3dResourceDesc;
	d3dResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
	d3dResourceDesc.Alignment = 0;
	d3dResourceDesc.Width = m_nWndClientWidth;
	d3dResourceDesc.Height = m_nWndClientHeight;
	d3dResourceDesc.DepthOrArraySize = 1;
	d3dResourceDesc.MipLevels = 1;
	d3dResourceDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	d3dResourceDesc.SampleDesc.Count = (m_bMsaa4xEnable) ? 4 : 1;
	d3dResourceDesc.SampleDesc.Quality = (m_bMsaa4xEnable) ? (m_nMsaa4xQualityLevels - 1) : 0;
	d3dResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
	d3dResourceDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

	D3D12_HEAP_PROPERTIES d3dHeapProperties;
	::ZeroMemory(&d3dHeapProperties, sizeof(D3D12_HEAP_PROPERTIES));
	d3dHeapProperties.Type = D3D12_HEAP_TYPE_DEFAULT;
	d3dHeapProperties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	d3dHeapProperties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	d3dHeapProperties.CreationNodeMask = 1;
	d3dHeapProperties.VisibleNodeMask = 1;

	D3D12_CLEAR_VALUE d3dClearValue;
	d3dClearValue.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	d3dClearValue.DepthStencil.Depth = 1.0f;
	d3dClearValue.DepthStencil.Stencil = 0;

	m_pd3dDevice->CreateCommittedResource(&d3dHeapProperties, D3D12_HEAP_FLAG_NONE, &d3dResourceDesc, D3D12_RESOURCE_STATE_DEPTH_WRITE, &d3dClearValue, __uuidof(ID3D12Resource), (void **)&m_pd3dDepthStencilBuffer);

	D3D12_DEPTH_STENCIL_VIEW_DESC d3dDepthStencilViewDesc;
	::ZeroMemory(&d3dDepthStencilViewDesc, sizeof(D3D12_DEPTH_STENCIL_VIEW_DESC));
	d3dDepthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	d3dDepthStencilViewDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
	d3dDepthStencilViewDesc.Flags = D3D12_DSV_FLAG_NONE;

	D3D12_CPU_DESCRIPTOR_HANDLE d3dDsvCPUDescriptorHandle = m_pd3dDsvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	m_pd3dDevice->CreateDepthStencilView(m_pd3dDepthStencilBuffer, &d3dDepthStencilViewDesc, d3dDsvCPUDescriptorHandle);
}

void CGameFramework::ChangeSwapChainState()
{
	WaitForGpuComplete();

	BOOL bFullScreenState = FALSE;
	m_pdxgiSwapChain->GetFullscreenState(&bFullScreenState, NULL);
	m_pdxgiSwapChain->SetFullscreenState(!bFullScreenState, NULL);

	DXGI_MODE_DESC dxgiTargetParameters;
	dxgiTargetParameters.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiTargetParameters.Width = m_nWndClientWidth;
	dxgiTargetParameters.Height = m_nWndClientHeight;
	dxgiTargetParameters.RefreshRate.Numerator = 60;
	dxgiTargetParameters.RefreshRate.Denominator = 1;
	dxgiTargetParameters.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	dxgiTargetParameters.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	m_pdxgiSwapChain->ResizeTarget(&dxgiTargetParameters);

	for (int i = 0; i < m_nSwapChainBuffers; i++) if (m_ppd3dSwapChainBackBuffers[i]) m_ppd3dSwapChainBackBuffers[i]->Release();

	DXGI_SWAP_CHAIN_DESC dxgiSwapChainDesc;
	m_pdxgiSwapChain->GetDesc(&dxgiSwapChainDesc);
	m_pdxgiSwapChain->ResizeBuffers(m_nSwapChainBuffers, m_nWndClientWidth, m_nWndClientHeight, dxgiSwapChainDesc.BufferDesc.Format, dxgiSwapChainDesc.Flags);

	m_nSwapChainBufferIndex = m_pdxgiSwapChain->GetCurrentBackBufferIndex();

	CreateRenderTargetViews();
}

void CGameFramework::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	if (m_pScene) m_pScene->OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
	if (m_pScene->currentScreen == IN_GAME_STATE)
	{
		
		switch (nMessageID)
		{
		case WM_LBUTTONDOWN:
			// ���콺 ��Ŭ�� �� ���� ���·� ��ȭ.
			if (mousedown == false)
			{
				CS_MOUSE_PACKET p;
				p.c_id = GetPlayerid();
				p.size = sizeof(CS_MOUSE_PACKET);
				p.down = true;
				p.type = PACKET_TYPE::CS_MOUSE;
				p.attackID = m_pScene->playerShader->objects[m_pScene->pID]->bState.attackID;
				SendPacket(&p);
				m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
				mousedown = true;
			}

			
			break;
		case WM_RBUTTONDOWN:

			//::SetCapture(hWnd);
			//::GetCursorPos(&m_ptOldCursorPos);

			break;
		case WM_LBUTTONUP:
		{
			if (m_pScene->interShader->stageClear == false)
			{
				if (mousedown == true)
				{
					CS_MOUSE_PACKET p;
					p.c_id = m_pScene->pID; //GetPlayerid();
					p.size = sizeof(CS_MOUSE_PACKET);
					p.down = false;
					p.type = PACKET_TYPE::CS_MOUSE;
					p.attackID = m_pScene->playerShader->objects[m_pScene->pID]->bState.attackID;
					SendPacket(&p);
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
					mousedown = false;
				}
				//��ư Ŭ�� �� ó��
			}
			else
			{
				POINT pnt;
				GetCursorPos(&pnt);
				RECT rect;
				GetWindowRect(hWnd, &rect);
				int wx = rect.left;
				int wy = rect.top;
				//retry
				if ((pnt.x >= 656 + wx && pnt.x <= 786 + wx) && (pnt.y >= 559 + wy && pnt.y <= 625 + wy))
				{
					//�÷��̾��� ���� �ʱ�ȭ
					for (int k = 0; k < m_pScene->playerShader->objects.size(); ++k)
					{
						m_pScene->playerShader->objects[k]->amp_melee = 1.0f;
						m_pScene->playerShader->objects[k]->amp_ranged = 1.0f;
						m_pScene->playerShader->objects[k]->amp_radio = 1.0f;

						m_pScene->playerShader->objects[k]->bState.attacking = false;
						m_pScene->playerShader->objects[k]->info->stats.capacity = m_pScene->playerShader->objects[k]->info->stats.maxhp;
						m_pScene->playerShader->objects[k]->bState.attackID = TYPE_RANGED;
						m_pScene->playerShader->objects[k]->bState.stateID = IDLE_STATE;
						
						m_pScene->playerShader->objects[k]->kState.isInAir = 0;
						m_pScene->playerShader->objects[k]->kState.isMobile = 0;
						m_pScene->playerShader->objects[k]->kState.rotation = 0.0f;
						m_pScene->playerShader->objects[k]->kState.xzspeed = 0.0f;
						m_pScene->playerShader->objects[k]->kState.yspeed = 0.0f;
					}
					m_pScene->enemyShader->restart();
					//���õ� ���������� ���� ���� �ʱ�ȭ.

					m_pScene->interShader->stageClear = false;
					m_pScene->waitInter->selectedStage = -1;
					m_pScene->interShader->missionFail = false;
					
					for (int i = 0; i < m_pScene->rm->briefPlayed.size(); ++i)
					{
						m_pScene->rm->brief[i]->stop();
						m_pScene->rm->brief[i]->Update();
						m_pScene->rm->briefPlayed[i] = false;

					}
					m_pScene->interShader->narrationShow = false;
					m_pScene->interShader->lastNarrated = chrono::system_clock::now();
					m_pScene->interShader->nDuration = 0.0;

					m_pScene->interShader->m10_gain = 0;
					m_pScene->interShader->m10_miss = 0;
					m_pScene->interShader->m1_kill = 0;
					m_pScene->interShader->m2_stun = 0;
					m_pScene->interShader->m3_bother = 0;
					m_pScene->interShader->m4_kill = 0;
					m_pScene->interShader->m5_broken = 0;
					m_pScene->interShader->m6_broken = 0;
					m_pScene->interShader->m7_kill = 0;
					m_pScene->interShader->m8_kill = 0;
					m_pScene->interShader->m9_stun = 0;
					m_pScene->interShader->m9_search = 0;
					m_pScene->interShader->mission = 1;

					m_pCamera->m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
					m_pCamera->lx = 0.0f;
					m_pCamera->ly = 0.0f;
					m_pCamera->lz = 1.0f;
					m_pCamera->GenerateViewMatrix();
					m_pCamera->UpdateShaderVariables(m_pd3dCommandList);
					m_pScene->currentScreen = STAGE_SELECT_STATE;


				}
				else if ((pnt.x >= 801 + wx && pnt.x <= 931 + wx) && (pnt.y >= 559 + wy && pnt.y <= 625 + wy))
				{
					//�÷��̾��� ���� �ʱ�ȭ
					for (int k = 0; k < m_pScene->playerShader->objects.size(); ++k)
					{
						m_pScene->playerShader->objects[k]->amp_melee = 1.0f;
						m_pScene->playerShader->objects[k]->amp_ranged = 1.0f;
						m_pScene->playerShader->objects[k]->amp_radio = 1.0f;
						m_pScene->playerShader->objects[k]->bState.attacking = false;
						m_pScene->playerShader->objects[k]->info->stats.capacity = m_pScene->playerShader->objects[k]->info->stats.maxhp;
						m_pScene->playerShader->objects[k]->bState.attackID = TYPE_RANGED;
						m_pScene->playerShader->objects[k]->bState.stateID = IDLE_STATE;

						m_pScene->playerShader->objects[k]->kState.isInAir = 0;
						m_pScene->playerShader->objects[k]->kState.isMobile = 0;
						m_pScene->playerShader->objects[k]->kState.rotation = 0.0f;
						m_pScene->playerShader->objects[k]->kState.xzspeed = 0.0f;
						m_pScene->playerShader->objects[k]->kState.yspeed = 0.0f;
					}
					m_pScene->enemyShader->restart();

					//���õ� ���������� ���� ���� �ʱ�ȭ.
					m_pScene->interShader->stageClear = false;
					m_pScene->interShader->missionFail = false;

					for (int i = 0; i < m_pScene->rm->briefPlayed.size(); ++i)
					{
						m_pScene->rm->brief[i]->stop();
						m_pScene->rm->brief[i]->Update();
						m_pScene->rm->briefPlayed[i] = false;

					}
					m_pScene->interShader->narrationShow = false;
					m_pScene->interShader->lastNarrated = chrono::system_clock::now();
					m_pScene->interShader->nDuration = 0.0;

					m_pScene->interShader->m10_gain = 0;
					m_pScene->interShader->m10_miss = 0;
					m_pScene->interShader->m1_kill = 0;
					m_pScene->interShader->m2_stun = 0;
					m_pScene->interShader->m3_bother = 0;
					m_pScene->interShader->m4_kill = 0;
					m_pScene->interShader->m5_broken = 0;
					m_pScene->interShader->m6_broken = 0;
					m_pScene->interShader->m7_kill = 0;
					m_pScene->interShader->m8_kill = 0;
					m_pScene->interShader->m9_stun = 0;
					m_pScene->interShader->m9_search = 0;
					m_pScene->interShader->mission = 1;

					m_pScene->waitInter->selectedStage = -1;

					m_pCamera->m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
					m_pCamera->lx = 0.0f;
					m_pCamera->ly = 0.0f;
					m_pCamera->lz = 1.0f;
					m_pCamera->GenerateViewMatrix();
					m_pCamera->UpdateShaderVariables(m_pd3dCommandList);
					m_pScene->currentScreen = LOBBY_STATE;

				}
			}
			break;
		}
		case WM_RBUTTONUP:
			/*
			::ReleaseCapture();
			*/
			break;
		case WM_MOUSEMOVE:
			break;
		default:
			break;
		}
	}
	else if (m_pScene->currentScreen == LOGIN_STATE)
	{
		
		switch (nMessageID)
		{
		case WM_LBUTTONDOWN:
		
			break;
		case WM_LBUTTONUP:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;
			if ((pnt.x >= 0+wx && pnt.x <= 1200+wx) && (pnt.y >= 0+wy && pnt.y <= 900+wy))
			{
				m_pScene->currentScreen = LOBBY_STATE;
			}
			break;
		}
		default:
			break;
		}
	}
	else if (m_pScene->currentScreen == LOBBY_STATE)
	{
		switch (nMessageID)
		{
		case WM_LBUTTONUP:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;
			int px1 = m_pScene->mainInter->objects[5]->x1;
			int px2 = m_pScene->mainInter->objects[5]->x2;
			int py1 = m_pScene->mainInter->objects[5]->y1;
			int py2 = m_pScene->mainInter->objects[5]->y2;

			int x1 = m_pScene->mainInter->objects[3]->x1;
			int x2 = m_pScene->mainInter->objects[3]->x2;
			int y1 = m_pScene->mainInter->objects[3]->y1;
			int y2 = m_pScene->mainInter->objects[3]->y2;

			int xx1 = m_pScene->mainInter->objects[2]->x1;
			int xx2 = m_pScene->mainInter->objects[2]->x2;
			int yy1 = m_pScene->mainInter->objects[2]->y1;
			int yy2 = m_pScene->mainInter->objects[2]->y2;



			if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
			{
				m_pScene->mainInter->objects[5]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[5]->defaultMesh];
				m_pScene->currentScreen = STAGE_SELECT_STATE;
			}
			else if ((pnt.x >= x1 + wx && pnt.x <= x2 + wx) && (pnt.y >= y1 + wy && pnt.y <= y2 + wy))
			{
				m_pScene->mainInter->objects[3]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[3]->defaultMesh];
				m_pScene->currentScreen = PROFILE_STATE;
			}
			else if ((pnt.x >= xx1 + wx && pnt.x <= xx2 + wx) && (pnt.y >= yy1 + wy && pnt.y <= yy2 + wy))
			{
				m_pScene->mainInter->objects[2]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[2]->defaultMesh];
				m_pScene->currentScreen = LOGIN_STATE;
			}
			break;
		}
		case WM_LBUTTONDOWN:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;
			int px1 = m_pScene->mainInter->objects[4]->x1;
			int px2 = m_pScene->mainInter->objects[4]->x2;
			int py1 = m_pScene->mainInter->objects[4]->y1;
			int py2 = m_pScene->mainInter->objects[4]->y2;

			int x1 = m_pScene->mainInter->objects[2]->x1;
			int x2 = m_pScene->mainInter->objects[2]->x2;
			int y1 = m_pScene->mainInter->objects[2]->y1;
			int y2 = m_pScene->mainInter->objects[2]->y2;

			int xx1 = m_pScene->mainInter->objects[1]->x1;
			int xx2 = m_pScene->mainInter->objects[1]->x2;
			int yy1 = m_pScene->mainInter->objects[1]->y1;
			int yy2 = m_pScene->mainInter->objects[1]->y2;

			if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
			{
				m_pScene->mainInter->objects[4]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[4]->defaultMesh + 2];
			}
			else if ((pnt.x >= x1 + wx && pnt.x <= x2 + wx) && (pnt.y >= y1 + wy && pnt.y <= y2 + wy))
			{
				m_pScene->mainInter->objects[2]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[2]->defaultMesh + 2];
			}
			else if ((pnt.x >= xx1 + wx && pnt.x <= xx2 + wx) && (pnt.y >= yy1 + wy && pnt.y <= yy2 + wy))
			{
				m_pScene->mainInter->objects[1]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[1]->defaultMesh + 2];
				
			}
			break;

		}
		default:
			break;
		}
	}
	else if (m_pScene->currentScreen == WAIT_STATE)
	{
		switch (nMessageID)
		{
		case WM_LBUTTONUP:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;

			int mx = pnt.x;
			int my = pnt.y;

			for (int i = 0; i < m_pScene->waitInter->objects.size(); ++i)
			{
				if (m_pScene->waitInter->objects[i]->defaultMesh != -1)
				{
					int px1 = m_pScene->waitInter->objects[i]->x1;
					int px2 = m_pScene->waitInter->objects[i]->x2;
					int py1 = m_pScene->waitInter->objects[i]->y1;
					int py2 = m_pScene->waitInter->objects[i]->y2;

					if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
					{
						m_pScene->waitInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->waitInter->objects[i]->defaultMesh];
						if (i == 1)
						{
							m_pScene->currentScreen = STAGE_SELECT_STATE;
						}
						else if (i == 2)
						{
							CS_READY_PACKET pac;
							pac.size = sizeof(CS_READY_PACKET);
							pac.type = PACKET_TYPE::CS_READY;
							pac.id = m_pScene->pID;
							pac.ready = true;
							SendPacket(&pac);
							
						}
					}
				}
			}

			break;
		}
		case WM_LBUTTONDOWN:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;

			int mx = pnt.x;
			int my = pnt.y;

			for (int i = 0; i < m_pScene->waitInter->objects.size(); ++i)
			{
				if (m_pScene->waitInter->objects[i]->defaultMesh != -1)
				{
					int px1 = m_pScene->waitInter->objects[i]->x1;
					int px2 = m_pScene->waitInter->objects[i]->x2;
					int py1 = m_pScene->waitInter->objects[i]->y1;
					int py2 = m_pScene->waitInter->objects[i]->y2;

					if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
					{
						m_pScene->waitInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->waitInter->objects[i]->defaultMesh + 2];

					}
				}
			}

			break;
		}

		}
	}

	else if (m_pScene->currentScreen == PROFILE_STATE)
	{
		switch (nMessageID)
		{
		case WM_LBUTTONUP:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;

			int mx = pnt.x;
			int my = pnt.y;

			if (m_pScene->profileInter->storageShow == false)
			{

				//�������� ��ư
				if ((mx >= 92 + wx && mx <= 296 + wx) && (my >= 167 + wy && my <= 213 + wy))
				{
					m_pScene->profileInter->objects[2]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->profileInter->objects[2]->defaultMesh];
					m_pScene->currentScreen = LOBBY_STATE;
				}
				//storage
				else if ((mx >= 100 + wx && mx <= 304 + wx) && (my >= 707 + wy && my <= 763 + wy))
				{
					m_pScene->profileInter->storageShow = true;
				}
				else
				{
					for (int i = 55; i < 73; i += 4)
					{
						int x1 = m_pScene->profileInter->objects[i]->x1;
						int x2 = m_pScene->profileInter->objects[i]->x2;
						int y1 = m_pScene->profileInter->objects[i]->y1;
						int y2 = m_pScene->profileInter->objects[i]->y2;

						int px1 = m_pScene->profileInter->objects[i + 1]->x1;
						int px2 = m_pScene->profileInter->objects[i + 1]->x2;
						int py1 = m_pScene->profileInter->objects[i + 1]->y1;
						int py2 = m_pScene->profileInter->objects[i + 1]->y2;

						//plus��ư
						if ((mx >= x1 + wx && mx <= x2 + wx) && (my >= y1 + wy && my <= y2 + wy))
						{
							//�ܿ� ����Ʈ�� ������ ��쿡�� ���� �߰�.
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint > 0)
							{
								if (i == 55)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint -= 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.maxhp += 1;
								}
								else if (i == 59)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint -= 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.hardness += 1;
								}
								else if (i == 63)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint -= 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.power += 1;
								}
								else if (i == 67)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint -= 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.precision += 1;
								}
								else if (i == 71)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint -= 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.entrophy += 1;
								}
							}
						}
						else if ((mx >= px1 + wx && mx <= px2 + wx) && (my >= py1 + wy && my <= py2 + wy))
						{
							//���� �������� �־��� �� ����Ʈ���� �ܿ�����Ʈ�� ������쿡�� ���� ȸ��.
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint < (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1) * 5)
							{
								if (i == 55)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.maxhp -= 1;
								}
								else if (i == 59)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.hardness -= 1;
								}
								else if (i == 63)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.power -= 1;
								}
								else if (i == 67)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.precision -= 1;
								}
								else if (i == 71)
								{
									m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 1;
									m_pScene->playerShader->objects[m_pScene->pID]->info->stats.entrophy -= 1;
								}
							}
						}
					}
				}
			}
			else
			{
				if ((mx >= 854 + wx && mx <= 894 + wx) && (my >= 249 + wy && my <= 289 + wy))
				{
					m_pScene->profileInter->storageShow = false;
				}
				else if (mx >= 346 + wx && mx <= 464 + wx && my >= 330 + wy && my <= 412 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 1)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[0] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}

				}
				else if (mx >= 542 + wx && mx <= 660 + wx && my >= 330 + wy && my <= 412 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 2)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[1] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}
				else if (mx >= 737 + wx && mx <= 855 + wx && my >= 330 + wy && my <= 412 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 3)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[2] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}

				else if (mx >= 346 + wx && mx <= 464 + wx && my >= 446 + wy && my <= 528 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 4)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[3] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}
				else if (mx >= 542 + wx && mx <= 660 + wx && my >= 446 + wy && my <= 528 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 5)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[4] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}
				else if (mx >= 737 + wx && mx <= 855 + wx && my >= 446 + wy && my <= 528 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 6)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[5] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}

				else if (mx >= 346 + wx && mx <= 464 + wx && my >= 562 + wy && my <= 644 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 7)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[6] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}
				else if (mx >= 542 + wx && mx <= 660 + wx && my >= 562 + wy && my <= 644 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 8)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}
				else if (mx >= 737 + wx && mx <= 855 + wx && my >= 562 + wy && my <= 644 + wy)
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory.size() >= 9)
					{
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8].type == BLUNT ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8].type == DUALBLADE)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.meleeWeapon = t;
						}
						else if (m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[7].type == RIFLE ||
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8].type == BAZUKA)
						{
							EquipItem t = m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8];
							m_pScene->playerShader->objects[m_pScene->pID]->info->inventory[8] = *m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon;
							*m_pScene->playerShader->objects[m_pScene->pID]->info->slot.rangedWeapon = t;
						}
					}
				}
			}
			break;
		}
		case WM_LBUTTONDOWN:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;

			if ((pnt.x >= 92 + wx && pnt.x <= 296 + wx) && (pnt.y >= 134 + wy && pnt.y <= 180 + wy))
			{
				m_pScene->profileInter->objects[2]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->profileInter->objects[2]->defaultMesh + 2];
			}
			break;
		}
		default:
			break;
		}
	}
	else if (m_pScene->currentScreen == STAGE_SELECT_STATE)
	{
		switch (nMessageID)
		{
		case WM_LBUTTONUP:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;



			if (m_pScene->stageInter->coworkShow == false)
			{

				if (m_pScene->stageInter->list1Show == true)
				{
					//easy	x 818~918	y 354~393
					//normal			y 393~432
					//hard				y 432~471
					//extreme			y 471~510
					if ((pnt.x >= 818 + wx && pnt.y <= 918 + wx) && (pnt.y >= 374 + wy && pnt.y <= 413 + wy))
					{
						m_pScene->stageInter->mode1 = 1;
					}
					else if ((pnt.x >= 818 + wx && pnt.y <= 918 + wx) && (pnt.y >= 413 + wy && pnt.y <= 452 + wy))
					{
						m_pScene->stageInter->mode1 = 2;
					}
					else if ((pnt.x >= 818 + wx && pnt.y <= 918 + wx) && (pnt.y >= 452 + wy && pnt.y <= 491 + wy))
					{
						m_pScene->stageInter->mode1 = 3;
					}
					else if ((pnt.x >= 818 + wx && pnt.y <= 918 + wx) && (pnt.y >= 491 + wy && pnt.y <= 530 + wy))
					{
						m_pScene->stageInter->mode1 = 4;
					}
					m_pScene->stageInter->list1Show = false;
				}
				else if (m_pScene->stageInter->list2Show == true)
				{
					//easy	x 820~920	y 599~638
					//normal			y 638~677
					//hard				y 677~716
					//extreme			y 716~755

					if ((pnt.x >= 820 + wx && pnt.y <= 920 + wx) && (pnt.y >= 619 + wy && pnt.y <= 658 + wy))
					{
						m_pScene->stageInter->mode2 = 1;
					}
					else if ((pnt.x >= 820 + wx && pnt.y <= 920 + wx) && (pnt.y >= 658 + wy && pnt.y <= 697 + wy))
					{
						m_pScene->stageInter->mode2 = 2;
					}
					else if ((pnt.x >= 820 + wx && pnt.y <= 920 + wx) && (pnt.y >= 697 + wy && pnt.y <= 736 + wy))
					{
						m_pScene->stageInter->mode2 = 3;
					}
					else if ((pnt.x >= 820 + wx && pnt.y <= 920 + wx) && (pnt.y >= 736 + wy && pnt.y <= 775 + wy))
					{
						m_pScene->stageInter->mode2 = 4;
					}
					m_pScene->stageInter->list2Show = false;
				}
				else
				{
					//stage1 list open
					if ((pnt.x >= 917 + wx && pnt.y <= 951 + wx) && (pnt.y >= 334 + wy && pnt.y <= 374 + wy))
					{
						if (m_pScene->stageInter->list1Show == false)
						{
							m_pScene->stageInter->list1Show = true;
						}
						else
						{
							m_pScene->stageInter->list1Show = false;
						}
					}
					//stage2 list open
					else if ((pnt.x >= 919 + wx && pnt.y <= 953 + wx) && (pnt.y >= 579 + wy && pnt.y <= 619 + wy))
					{
						if (m_pScene->stageInter->list2Show == false)
						{
							m_pScene->stageInter->list2Show = true;
						}
						else
						{
							m_pScene->stageInter->list2Show = false;
						}
					}
					else
					{
						for (int i = 0; i < m_pScene->stageInter->objects.size(); ++i)
						{
							if (m_pScene->stageInter->objects[i]->defaultMesh != -1)
							{
								int px1 = m_pScene->stageInter->objects[i]->x1;
								int px2 = m_pScene->stageInter->objects[i]->x2;
								int py1 = m_pScene->stageInter->objects[i]->y1;
								int py2 = m_pScene->stageInter->objects[i]->y2;

								if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
								{
									m_pScene->stageInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[i]->defaultMesh];
									if (i == 2)
									{
										m_pScene->currentScreen = WAIT_STATE;
										//1-1�������� ���õ�
										m_pScene->stageInter->coworkShow = false;
										m_pScene->stageInter->together = false;
										m_pScene->waitInter->selectedStage = 1;
										m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
									}
									else if (i == 1)
									{
										m_pScene->currentScreen = LOBBY_STATE;
										m_pScene->stageInter->coworkShow = false;
										m_pScene->stageInter->together = false;
									}
									else if (i == 3)
									{
										m_pScene->stageInter->coworkShow = true;
										m_pScene->stageInter->together = true;
										m_pScene->stageInter->select = 1;
									}
									else if (i == 4)
									{
										m_pScene->stageInter->coworkShow = true;
										m_pScene->stageInter->together = false;
									}
									else if (i == 5)
									{
										m_pScene->currentScreen = WAIT_STATE;
										//1-2�������� ���õ�
										m_pScene->waitInter->selectedStage = 2;
										m_pScene->stageInter->coworkShow = false;
										m_pScene->stageInter->together = false;
										m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode2;
									}
									else if (i == 6)
									{
										m_pScene->stageInter->coworkShow = true;
										m_pScene->stageInter->together = true;
										m_pScene->stageInter-> select = 2;
									}
									else if (i == 7)
									{
										m_pScene->stageInter->coworkShow = true;
										m_pScene->stageInter->together = false;

									}
								}
							}
						}

					}
				}
			}
			else
			{
				if ((pnt.x >= 261 + wx && pnt.x <= 1139 + wx) && (pnt.y >= 304 + wy && pnt.y <= 596 + wy))
				{
					if (m_pScene->stageInter->together == false)
					{
						if (pnt.x >= 320 + wx && pnt.x <= 360 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp += 30;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level += 1;

								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.capacity += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.maxhp += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.power += 2;
							}

							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 30;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
							}
							m_pScene->stageInter->coworkShow = false;
						}
						else if (pnt.x >= 377 + wx && pnt.x <= 417 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp += 60;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.capacity += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.maxhp += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.power += 2;
							}

							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 60;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
							}
							m_pScene->stageInter->coworkShow = false;
						}
						else if (pnt.x >= 434 + wx && pnt.x <= 474 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp += 100;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.melee.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.capacity += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.maxhp += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.power += 2;
							}

							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 100;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
							}
							m_pScene->stageInter->coworkShow = false;
						}

						else if (pnt.x >= 534 + wx && pnt.x <= 574 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp += 30;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.precision += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.hardness += 2;
							}

							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 30;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
							}
							m_pScene->stageInter->coworkShow = false;
						}
						else if (pnt.x >= 591 + wx && pnt.x <= 631 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp += 60;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.precision += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.hardness += 2;
							}

							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 60;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
							}
							m_pScene->stageInter->coworkShow = false;
						}
						else if (pnt.x >= 648 + wx && pnt.x <= 688 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp += 100;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.ranged.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.precision += 3;
								m_pScene->playerShader->objects[m_pScene->pID]->info->stats.hardness += 2;
							}

							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 100;
							if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
							{
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
								m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
								m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
							}
							m_pScene->stageInter->coworkShow = false;
						}

						else if (pnt.x >= 738 + wx && pnt.x <= 778 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
						m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp += 30;
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level - 1])
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level - 1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level += 1;
						}

						m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 30;
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
							m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
						}
						m_pScene->stageInter->coworkShow = false;
						}
						else if (pnt.x >= 795 + wx && pnt.x <= 835 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
						m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp += 60;
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level - 1])
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level - 1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level += 1;
						}

						m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 60;
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
							m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
						}
						m_pScene->stageInter->coworkShow = false;
						}
						else if (pnt.x >= 852 + wx && pnt.x <= 892 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
						{
						m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp += 100;
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp >= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level - 1])
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.exp -= expNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level - 1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.radio.level += 1;
						}

						m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp += 100;
						if (m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp >= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1])
						{
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.exp -= totalExpNeed[m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level - 1];
							m_pScene->playerShader->objects[m_pScene->pID]->info->growth.total.level += 1;
							m_pScene->playerShader->objects[m_pScene->pID]->info->extraPoint += 3;
						}
						m_pScene->stageInter->coworkShow = false;
						}
					}
					else
					{
					if (pnt.x >= 320 + wx && pnt.x <= 360 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;
						
						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_melee = 1.5f;
						
						
					}
					else if (pnt.x >= 377 + wx && pnt.x <= 417 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_melee = 2.0f;
					}
					else if (pnt.x >= 434 + wx && pnt.x <= 474 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_melee = 2.5f;
						
					}

					else if (pnt.x >= 534 + wx && pnt.x <= 574 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_ranged = 1.5f;
					}
					else if (pnt.x >= 591 + wx && pnt.x <= 631 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_ranged = 2.0f;
					}
					else if (pnt.x >= 648 + wx && pnt.x <= 688 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_ranged = 2.5f;
					}

					else if (pnt.x >= 738 + wx && pnt.x <= 778 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_radio = 1.5f;
					}
					else if (pnt.x >= 795 + wx && pnt.x <= 835 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_radio = 2.0f;
					}
					else if (pnt.x >= 852 + wx && pnt.x <= 892 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
					{
						m_pScene->currentScreen = WAIT_STATE;
						//1-1�������� ���õ�
						m_pScene->stageInter->coworkShow = false;
						m_pScene->stageInter->together = false;

						m_pScene->waitInter->selectedStage = m_pScene->stageInter->select;
						m_pScene->waitInter->selectedMode = m_pScene->stageInter->mode1;
						m_pScene->playerShader->objects[m_pScene->pID]->amp_radio = 2.5f;
						
					}
					}
				}
				else
				{
					m_pScene->stageInter->coworkShow = false;
				}
			}
			break;
		}
		case WM_LBUTTONDOWN:
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;
			for (int i = 0; i < m_pScene->stageInter->objects.size(); ++i)
			{
				if (m_pScene->stageInter->objects[i]->defaultMesh != -1)
				{
					int px1 = m_pScene->stageInter->objects[i]->x1;
					int px2 = m_pScene->stageInter->objects[i]->x2;
					int py1 = m_pScene->stageInter->objects[i]->y1;
					int py2 = m_pScene->stageInter->objects[i]->y2;

					if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
					{
						m_pScene->stageInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[i]->defaultMesh + 2];

					}
				}
			}
			break;
		}
		}
	}

}

void CGameFramework::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{

	if (m_pScene) m_pScene->OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
	
	CS_KEYDOWN_PACKET packet;
	packet.c_id = m_pScene->pID; //GetPlayerid();
	packet.size = sizeof(CS_KEYDOWN_PACKET);
	packet.type = PACKET_TYPE::CS_KEYDOWN;
	
	CS_KEYUP_PACKET uppac;
	uppac.c_id = m_pScene->pID; //GetPlayerid();
	uppac.size = sizeof(CS_KEYUP_PACKET);
	uppac.type = PACKET_TYPE::CS_KEYUP;

	CS_POSITION_PACKET ppac;
	ppac.c_id = m_pScene->pID;
	ppac.size = sizeof(CS_POSITION_PACKET);
	ppac.type = PACKET_TYPE::CS_POSITION;

	// lastOrder::���������� �̵��ߴ� ������ ��� �����ΰ�?
	// ���� ��, �Ʒ�, ����, ������ ���� 1,2,3,4
	if (m_pScene->currentScreen == IN_GAME_STATE)
	{

			switch (nMessageID)
			{
			case WM_KEYDOWN:
				switch (wParam)
				{
				case 'P':
				{
					
					m_pScene->interShader->missionShow = false;
					break;
				}
				case 'L':
				{
					CS_LOCATION_PACKET pc;
					pc.size = sizeof(CS_LOCATION_PACKET);
					pc.type = PACKET_TYPE::CS_LOCATION;
					pc.id = m_pScene->pID;
					pc.x = m_pScene->playerShader->objects[m_pScene->pID]->GetPosition().x;
					pc.z = m_pScene->playerShader->objects[m_pScene->pID]->GetPosition().z;
					SendPacket(&pc);
					break;
				}

				case VK_F12:
				{
					if (m_pScene->m_pLights[0].m_bEnable == false)
					{
						m_pScene->m_pLights[0].m_bEnable = true;
						m_pScene->m_pLights[1].m_bEnable = false;
					}
					else
					{
						m_pScene->m_pLights[0].m_bEnable = false;
						m_pScene->m_pLights[1].m_bEnable = true;
					}
					m_pScene->UpdateShaderVariables(m_pd3dCommandList);
					break;
				}

				case 'W':
				{

					m_pScene->moving = 1;
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = MOVE_STATE;

					XMFLOAT3 lk = m_pCamera->getLook();
					float ag = atan2f(lk.x, lk.z);
					ag = ag / 3.141592f * 180.0f;
					ag = ag + 270.0f;
					if (ag >= 360.0f)
						ag -= 360.0f;
					else if (ag < 0.0f)
						ag += 360.0f;

					m_pScene->playerShader->objects[m_pScene->pID]->Rotate(0.0f, ag + 90.0f, 0.0f);
					m_pScene->playerShader->objects[m_pScene->pID]->kState.rotation = ag;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = PLAYER_SPEED;
					
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
				}
				break;

				case 'S':
				{
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = MOVE_STATE;
					m_pScene->moving = 2;
					XMFLOAT3 lk = m_pCamera->getLook();
					float ag = atan2f(lk.x, lk.z);
					ag = ag / 3.141592f * 180.0f;
					ag = ag + 90.0f;
					if (ag >= 360.0f)
						ag -= 360.0f;
					else if (ag < 0.0f)
						ag += 360.0f;
					m_pScene->playerShader->objects[m_pScene->pID]->Rotate(0.0f, ag + 90.0f, 0.0f);
					m_pScene->playerShader->objects[m_pScene->pID]->kState.rotation = ag;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = PLAYER_SPEED;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
				}
				break;

				case 'A':
				{
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = MOVE_STATE;
					m_pScene->moving = 3;
					XMFLOAT3 lk = m_pCamera->getLook();
					float ag = atan2f(lk.x, lk.z);
					ag = ag / 3.141592f * 180.0f;
					ag = ag + 180.0f;
					if (ag >= 360.0f)
						ag -= 360.0f;
					else if (ag < 0.0f)
						ag += 360.0f;

					m_pScene->playerShader->objects[m_pScene->pID]->Rotate(0.0f, ag + 90.0f, 0.0f);
					m_pScene->playerShader->objects[m_pScene->pID]->kState.rotation = ag;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = PLAYER_SPEED;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
				}
				break;

				case 'D':
				{
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = MOVE_STATE;
					m_pScene->moving = 4;
					XMFLOAT3 lk = m_pCamera->getLook();
					float ag = atan2f(lk.x, lk.z);
					ag = ag / 3.141592f * 180.0f;
					ag = ag + 0.0f;
					if (ag >= 360.0f)
						ag -= 360.0f;
					else if (ag < 0.0f)
						ag += 360.0f;
					m_pScene->playerShader->objects[m_pScene->pID]->Rotate(0.0f, ag + 90.0f, 0.0f);
					m_pScene->playerShader->objects[m_pScene->pID]->kState.rotation = ag;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = PLAYER_SPEED;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
				}
				break;
				case VK_SPACE:
				{
					if (m_pScene->playerShader->objects[m_pScene->pID]->kState.yspeed == 0.0f)
					{
						m_pScene->playerShader->objects[m_pScene->pID]->kState.yspeed = 15.0f;
						m_pScene->playerShader->objects[m_pScene->pID]->kState.isInAir = 1;
						m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = JUMP_STATE;
						m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
					}

					break;
				}


				case '2':
				{
					packet.key = '2';
					SendPacket(&packet);
					break;
				}
				case '3':
				{
					packet.key = '3';
					SendPacket(&packet);
					break;
				}
				case '1':
				{
					packet.key = '1';
					SendPacket(&packet);
					break;
				}
				case VK_F1:
					packet.key = VK_F1;
					SendPacket(&packet);
					break;
				case VK_F2:
					packet.key = VK_F2;
					SendPacket(&packet);
					break;
				case VK_F3:
					packet.key = VK_F3;
					SendPacket(&packet);

					break;
				case VK_F4:
					packet.key = VK_F4;
					SendPacket(&packet);
					break;
				case VK_F5:
					packet.key = VK_F5;
					SendPacket(&packet);
					break;
				case VK_F6:
					packet.key = VK_F6;
					SendPacket(&packet);
					break;
				case VK_F7:
					packet.key = VK_F7;
					SendPacket(&packet);
					break;

				}
				break;
			case WM_KEYUP:
				switch (wParam)
				{
				case VK_ESCAPE:
					::PostQuitMessage(0);
					break;
				case VK_RETURN:
					break;

					// �����¿� Ű�� ������ ��� ���� ���·� ����, �ӵ��� 0���� ����.

				case VK_F5:
				{
					ppac.x = m_pScene->playerShader->objects[m_pScene->pID]->GetPosition().x;
					ppac.z = m_pScene->playerShader->objects[m_pScene->pID]->GetPosition().z;
					SendPacket(&ppac);
					break;
				}
				case 'W':
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = IDLE_STATE;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = 0.0f;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
					m_pScene->moving = 1;
					break;
				case 'S':
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = IDLE_STATE;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = 0.0f;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
					m_pScene->moving = 2;
					break;
				case 'A':
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = IDLE_STATE;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = 0.0f;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
					m_pScene->moving = 3;
					break;
				case 'D':
					m_pScene->playerShader->objects[m_pScene->pID]->bState.stateID = IDLE_STATE;
					m_pScene->playerShader->objects[m_pScene->pID]->kState.xzspeed = 0.0f;
					m_pScene->playerShader->objects[m_pScene->pID]->stateChanged = true;
					m_pScene->moving = 4;
					break;
				case '1':
				{
					uppac.key = '1';
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				}
				case '2':
				{
					uppac.key = '2';
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				}

				case '3':
				{
					uppac.key = '3';
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				}
				/*
				case VK_SPACE:
				{

					uppac.key = VK_SPACE;
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				}
				*/
				default:
					break;
				}
				break;
			default:
				break;
			}
		
		
	}
}

LRESULT CALLBACK CGameFramework::OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{

	switch (nMessageID)
	{
		case WM_ACTIVATE:
		{
			if (LOWORD(wParam) == WA_INACTIVE)
				m_GameTimer.Stop();
			else
				m_GameTimer.Start();
			break;
		}
		case WM_SIZE:
			break;
		case WM_LBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MOUSEMOVE:
			OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
            break;
        case WM_KEYDOWN:
        case WM_KEYUP:
			OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);

			break;
	}
	return(0);
}

void CGameFramework::OnDestroy()
{
    ReleaseObjects();
	CSound::Release();
	::CloseHandle(m_hFenceEvent);

	if (m_pd3dDepthStencilBuffer) m_pd3dDepthStencilBuffer->Release();
	if (m_pd3dDsvDescriptorHeap) m_pd3dDsvDescriptorHeap->Release();

	for (int i = 0; i < m_nSwapChainBuffers; i++) if (m_ppd3dSwapChainBackBuffers[i]) m_ppd3dSwapChainBackBuffers[i]->Release();
	if (m_pd3dRtvDescriptorHeap) m_pd3dRtvDescriptorHeap->Release();

	if (m_pd3dCommandAllocator) m_pd3dCommandAllocator->Release();
	if (m_pd3dCommandQueue) m_pd3dCommandQueue->Release();
	if (m_pd3dCommandList) m_pd3dCommandList->Release();

	if (m_pd3dFence) m_pd3dFence->Release();

	m_pdxgiSwapChain->SetFullscreenState(FALSE, NULL);
	if (m_pdxgiSwapChain) m_pdxgiSwapChain->Release();
    if (m_pd3dDevice) m_pd3dDevice->Release();
	if (m_pdxgiFactory) m_pdxgiFactory->Release();

#if defined(_DEBUG)
	IDXGIDebug1	*pdxgiDebug = NULL;
	DXGIGetDebugInterface1(0, __uuidof(IDXGIDebug1), (void **)&pdxgiDebug);
	HRESULT hResult = pdxgiDebug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_DETAIL);
	pdxgiDebug->Release();
#endif
}

#define _WITH_TERRAIN_PLAYER

void CGameFramework::BuildObjects()
{
	m_pd3dCommandList->Reset(m_pd3dCommandAllocator, NULL);

	models = new CLoadedModelInfo * [2];

	

	m_pScene = new CScene();
	if (m_pScene) m_pScene->BuildObjects(m_pd3dDevice, m_pd3dCommandList);
	

	//models[0] = CGameObject::LoadGeometryAndAnimationFromFile(m_pd3dDevice, m_pd3dCommandList, m_pScene->m_pd3dGraphicsRootSignature, "res/bin/sample.bin", NULL);
	//models[1] = CGameObject::LoadGeometryAndAnimationFromFile(m_pd3dDevice, m_pd3dCommandList, m_pScene->m_pd3dGraphicsRootSignature, "res/bin/bluntIdle.bin", NULL);
	
	
	m_pCamera = new CCamera();
	m_pCamera->SetViewport(0, 0, m_nWndClientWidth, m_nWndClientHeight, 0.0f, 1.0f);
	m_pCamera->SetScissorRect(0, 0, m_nWndClientWidth, m_nWndClientHeight);
	m_pCamera->GenerateProjectionMatrix(1.0f, 500.0f, float(m_nWndClientWidth) /
		float(m_nWndClientHeight), 90.0f);
	m_pCamera->GenerateViewMatrix();

	m_pCamera->CreateShaderVariables(m_pd3dDevice, m_pd3dCommandList);

	m_pd3dCommandList->Close();
	ID3D12CommandList *ppd3dCommandLists[] = { m_pd3dCommandList };
	m_pd3dCommandQueue->ExecuteCommandLists(1, ppd3dCommandLists);

	WaitForGpuComplete();

	if (m_pScene) m_pScene->ReleaseUploadBuffers();
	//if (m_pPlayer) m_pPlayer->ReleaseUploadBuffers();

	m_GameTimer.Reset();
}

void CGameFramework::ReleaseObjects()
{
	

	if (m_pScene) m_pScene->ReleaseObjects();
	if (m_pScene) delete m_pScene;
}

void CGameFramework::ProcessInput()
{
	//���콺 �̵� �� �÷��̾��� ��ġ ����.
	if (m_pScene->currentScreen == IN_GAME_STATE)
	{
		if (m_pScene->interShader->stageClear == false)
		{
			POINT pnt;
			GetCursorPos(&pnt);

			XMFLOAT3 offset = m_pScene->getPos(m_pScene->pID);
			float deltaX = static_cast<float>(pnt.x - prevX) / 5.0f;
			float deltaY = static_cast<float>(pnt.y - prevY) / 100.0f;
			if (deltaX != 0.0f || deltaY != 0.0f)
			{
				CS_CAMERA_PACKET p;
				p.size = sizeof(CS_CAMERA_PACKET);
				p.type = PACKET_TYPE::CS_CAMERA_CHANGE;
				p.c_id = m_pScene->pID;
				p.camAngle = deltaX;
				p.camUp = deltaY;

				SendPacket(&p);
			}

			
			
				prevX = pnt.x;
				prevY = pnt.y;

				SetCursorPos(500, 500);
				prevX = 500;
				prevY = 500;
		}
		else
		{
			POINT pnt;
			GetCursorPos(&pnt);
			RECT rect;
			GetWindowRect(m_hWnd, &rect);
			int wx = rect.left;
			int wy = rect.top;

			//�絵�� ��ư ���� ������
			if ((pnt.x >= 656+wx && pnt.x <= 786+wx) && (pnt.y >= 559+wy && pnt.y <= 625+wy))
			{
				m_pScene->interShader->objects[9]->m_ppMaterials[0] = m_pScene->rm->materials[303];
			}
			else
			{
				m_pScene->interShader->objects[9]->m_ppMaterials[0] = m_pScene->rm->materials[302];
			}

			//���ư��� ��ư ���� ������
			if ((pnt.x >= 801+wx && pnt.x <= 931+wx) && (pnt.y >= 559+wy && pnt.y <= 625+wy))
			{
				m_pScene->interShader->objects[10]->m_ppMaterials[0] = m_pScene->rm->materials[305];
				m_pScene->interShader->objects[10]->mouseOn = true;
				m_pScene->interShader->objects[10]->meshChanged = false;
			}
			else
			{
				m_pScene->interShader->objects[10]->m_ppMaterials[0] = m_pScene->rm->materials[304];
				m_pScene->interShader->objects[10]->mouseOn = false;
				m_pScene->interShader->objects[10]->meshChanged = false;
			}
		}
		
	}
	else if (m_pScene->currentScreen == LOBBY_STATE)
	{
		POINT pnt;
		GetCursorPos(&pnt);
		RECT rect;
		GetWindowRect(m_hWnd, &rect);
		int wx = rect.left;
		int wy = rect.top;
		for (int i = 0; i < m_pScene->mainInter->objects.size(); ++i)
		{
			int px1 = m_pScene->mainInter->objects[i]->x1;
			int px2 = m_pScene->mainInter->objects[i]->x2;
			int py1 = m_pScene->mainInter->objects[i]->y1;
			int py2 = m_pScene->mainInter->objects[i]->y2;

			if (m_pScene->mainInter->objects[i]->defaultMesh != -1)
			{
				//Ŭ�� ���� �ȿ� ���콺�� �ִ� ��� �ؽ�ó ����
				if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
				{
					m_pScene->mainInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[i]->defaultMesh + 1];

					m_pScene->mainInter->objects[i]->mouseOn = true;
					m_pScene->mainInter->objects[i]->meshChanged = false;
				}
				else
				{
					m_pScene->mainInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->mainInter->objects[i]->defaultMesh];
					m_pScene->mainInter->objects[i]->mouseOn = false;
					m_pScene->mainInter->objects[i]->meshChanged = false;

				}
			}
		}
	}
	else if (m_pScene->currentScreen == PROFILE_STATE)
	{
		POINT pnt;
		GetCursorPos(&pnt);
		RECT rect;
		GetWindowRect(m_hWnd, &rect);
		int wx = rect.left;
		int wy = rect.top;
		for (int i = 0; i < m_pScene->profileInter->objects.size(); ++i)
		{
			int px1 = m_pScene->profileInter->objects[i]->x1;
			int px2 = m_pScene->profileInter->objects[i]->x2;
			int py1 = m_pScene->profileInter->objects[i]->y1;
			int py2 = m_pScene->profileInter->objects[i]->y2;

			if (m_pScene->profileInter->objects[i]->defaultMesh != -1)
			{
				//Ŭ�� ���� �ȿ� ���콺�� �ִ� ��� �ؽ�ó ����
				if (i < 53)
				{
					if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy+33 && pnt.y <= py2 + wy+33))
					{
						m_pScene->profileInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->profileInter->objects[i]->defaultMesh + 1];
						m_pScene->profileInter->objects[i]->mouseOn = true;
						m_pScene->profileInter->objects[i]->meshChanged = false;
					}
					else
					{
						m_pScene->profileInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->profileInter->objects[i]->defaultMesh];
						m_pScene->profileInter->objects[i]->mouseOn = false;
						m_pScene->profileInter->objects[i]->meshChanged = false;

					}
				}
				else
				{
					if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
					{
						m_pScene->profileInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->profileInter->objects[i]->defaultMesh + 1];
						m_pScene->profileInter->objects[i]->mouseOn = true;
						m_pScene->profileInter->objects[i]->meshChanged = false;
					}
					else
					{
						m_pScene->profileInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->profileInter->objects[i]->defaultMesh];
						m_pScene->profileInter->objects[i]->mouseOn = false;
						m_pScene->profileInter->objects[i]->meshChanged = false;

					}
				}
			}
		}
	}
	else if (m_pScene->currentScreen == STAGE_SELECT_STATE)
	{
		POINT pnt;
		GetCursorPos(&pnt);
		RECT rect;
		GetWindowRect(m_hWnd, &rect);
		int wx = rect.left;
		int wy = rect.top;
		if (m_pScene->stageInter->coworkShow == false)
		{
			for (int i = 0; i < m_pScene->stageInter->objects.size(); ++i)
			{
				int px1 = m_pScene->stageInter->objects[i]->x1;
				int px2 = m_pScene->stageInter->objects[i]->x2;
				int py1 = m_pScene->stageInter->objects[i]->y1;
				int py2 = m_pScene->stageInter->objects[i]->y2;

				if (m_pScene->stageInter->objects[i]->defaultMesh != -1)
				{
					//Ŭ�� ���� �ȿ� ���콺�� �ִ� ��� �ؽ�ó ����
					if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
					{
						m_pScene->stageInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[i]->defaultMesh + 1];
						m_pScene->stageInter->objects[i]->mouseOn = true;
						m_pScene->stageInter->objects[i]->meshChanged = false;
					}


					else
					{
						m_pScene->stageInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[i]->defaultMesh];
						m_pScene->stageInter->objects[i]->mouseOn = false;
						m_pScene->stageInter->objects[i]->meshChanged = false;

					}
				}
			}
		}
		else
		{
			if (pnt.x >= 320+wx && pnt.x <= 360 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[15]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[15]->defaultMesh + 1];
				m_pScene->stageInter->objects[15]->mouseOn = true;
				m_pScene->stageInter->objects[15]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[15]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[15]->defaultMesh];
				m_pScene->stageInter->objects[15]->mouseOn = false;
				m_pScene->stageInter->objects[15]->meshChanged = false;
			}

			if (pnt.x >= 377 + wx && pnt.x <= 417 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[16]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[16]->defaultMesh + 1];
				m_pScene->stageInter->objects[16]->mouseOn = true;
				m_pScene->stageInter->objects[16]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[16]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[16]->defaultMesh];
				m_pScene->stageInter->objects[16]->mouseOn = false;
				m_pScene->stageInter->objects[16]->meshChanged = false;
			}

			if (pnt.x >= 434 + wx && pnt.x <= 474 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[17]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[17]->defaultMesh + 1];
				m_pScene->stageInter->objects[17]->mouseOn = true;
				m_pScene->stageInter->objects[17]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[17]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[17]->defaultMesh];
				m_pScene->stageInter->objects[17]->mouseOn = false;
				m_pScene->stageInter->objects[17]->meshChanged = false;
			}

			if (pnt.x >= 534 + wx && pnt.x <= 574 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[18]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[18]->defaultMesh + 1];
				m_pScene->stageInter->objects[18]->mouseOn = true;
				m_pScene->stageInter->objects[18]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[18]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[18]->defaultMesh];
				m_pScene->stageInter->objects[18]->mouseOn = false;
				m_pScene->stageInter->objects[18]->meshChanged = false;
			}

			if (pnt.x >= 591 + wx && pnt.x <= 631 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[19]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[19]->defaultMesh + 1];
				m_pScene->stageInter->objects[19]->mouseOn = true;
				m_pScene->stageInter->objects[19]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[19]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[19]->defaultMesh];
				m_pScene->stageInter->objects[19]->mouseOn = false;
				m_pScene->stageInter->objects[19]->meshChanged = false;
			}

			if (pnt.x >= 648 + wx && pnt.x <= 688 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[20]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[20]->defaultMesh + 1];
				m_pScene->stageInter->objects[20]->mouseOn = true;
				m_pScene->stageInter->objects[20]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[20]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[20]->defaultMesh];
				m_pScene->stageInter->objects[20]->mouseOn = false;
				m_pScene->stageInter->objects[20]->meshChanged = false;
			}

			if (pnt.x >= 738 + wx && pnt.x <= 778 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[21]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[21]->defaultMesh + 1];
				m_pScene->stageInter->objects[21]->mouseOn = true;
				m_pScene->stageInter->objects[21]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[21]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[21]->defaultMesh];
				m_pScene->stageInter->objects[21]->mouseOn = false;
				m_pScene->stageInter->objects[21]->meshChanged = false;
			}

			if (pnt.x >= 795 + wx && pnt.x <= 835 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[22]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[22]->defaultMesh + 1];
				m_pScene->stageInter->objects[22]->mouseOn = true;
				m_pScene->stageInter->objects[22]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[22]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[22]->defaultMesh];
				m_pScene->stageInter->objects[22]->mouseOn = false;
				m_pScene->stageInter->objects[22]->meshChanged = false;
			}
			if (pnt.x >= 852 + wx && pnt.x <= 892 + wx && pnt.y >= 497 + wy && pnt.y <= 537 + wy)
			{
				m_pScene->stageInter->objects[23]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[23]->defaultMesh + 1];
				m_pScene->stageInter->objects[23]->mouseOn = true;
				m_pScene->stageInter->objects[23]->meshChanged = false;
			}
			else
			{
				m_pScene->stageInter->objects[23]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->stageInter->objects[23]->defaultMesh];
				m_pScene->stageInter->objects[23]->mouseOn = false;
				m_pScene->stageInter->objects[23]->meshChanged = false;
			}
		}
	}
	else if (m_pScene->currentScreen == WAIT_STATE)
	{
		POINT pnt;
		GetCursorPos(&pnt);
		RECT rect;
		GetWindowRect(m_hWnd, &rect);
		int wx = rect.left;
		int wy = rect.top;

		for (int i = 0; i < m_pScene->waitInter->objects.size(); ++i)
		{
			int px1 = m_pScene->waitInter->objects[i]->x1;
			int px2 = m_pScene->waitInter->objects[i]->x2;
			int py1 = m_pScene->waitInter->objects[i]->y1;
			int py2 = m_pScene->waitInter->objects[i]->y2;

			if (m_pScene->waitInter->objects[i]->defaultMesh != -1)
			{
				//Ŭ�� ���� �ȿ� ���콺�� �ִ� ��� �ؽ�ó ����
				if ((pnt.x >= px1 + wx && pnt.x <= px2 + wx) && (pnt.y >= py1 + wy && pnt.y <= py2 + wy))
				{
					m_pScene->waitInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->waitInter->objects[i]->defaultMesh + 1];
					m_pScene->waitInter->objects[i]->mouseOn = true;
					m_pScene->waitInter->objects[i]->meshChanged = false;
				}
				else
				{
					m_pScene->waitInter->objects[i]->m_ppMaterials[0] = m_pScene->rm->materials[m_pScene->waitInter->objects[i]->defaultMesh];
					m_pScene->waitInter->objects[i]->mouseOn = false;
					m_pScene->waitInter->objects[i]->meshChanged = false;

					
				}
			}
		}
	}
}


void CGameFramework::AnimateObjects()
{
	float fTimeElapsed = m_GameTimer.GetTimeElapsed();


	

	if (m_pScene) m_pScene->AnimateObjects(m_pd3dDevice, m_pd3dCommandList, fTimeElapsed, m_pCamera);

	

}

void CGameFramework::WaitForGpuComplete()
{
	const UINT64 nFenceValue = ++m_nFenceValues[m_nSwapChainBufferIndex];
	HRESULT hResult = m_pd3dCommandQueue->Signal(m_pd3dFence, nFenceValue);

	if (m_pd3dFence->GetCompletedValue() < nFenceValue)
	{
		hResult = m_pd3dFence->SetEventOnCompletion(nFenceValue, m_hFenceEvent);
		::WaitForSingleObject(m_hFenceEvent, INFINITE);
	}
}

void CGameFramework::MoveToNextFrame()
{
	m_nSwapChainBufferIndex = m_pdxgiSwapChain->GetCurrentBackBufferIndex();
	//m_nSwapChainBufferIndex = (m_nSwapChainBufferIndex + 1) % m_nSwapChainBuffers;

	UINT64 nFenceValue = ++m_nFenceValues[m_nSwapChainBufferIndex];
	HRESULT hResult = m_pd3dCommandQueue->Signal(m_pd3dFence, nFenceValue);

	if (m_pd3dFence->GetCompletedValue() < nFenceValue)
	{
		hResult = m_pd3dFence->SetEventOnCompletion(nFenceValue, m_hFenceEvent);
		::WaitForSingleObject(m_hFenceEvent, INFINITE);
	}
}

//#define _WITH_PLAYER_TOP

void CGameFramework::FrameAdvance()
{    
	m_GameTimer.Tick(60.0f);
	
	ProcessInput();

    AnimateObjects();

	HRESULT hResult = m_pd3dCommandAllocator->Reset();
	hResult = m_pd3dCommandList->Reset(m_pd3dCommandAllocator, NULL);

	D3D12_RESOURCE_BARRIER d3dResourceBarrier;
	::ZeroMemory(&d3dResourceBarrier, sizeof(D3D12_RESOURCE_BARRIER));
	d3dResourceBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
	d3dResourceBarrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
	d3dResourceBarrier.Transition.pResource = m_ppd3dSwapChainBackBuffers[m_nSwapChainBufferIndex];
	d3dResourceBarrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
	d3dResourceBarrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
	d3dResourceBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
	m_pd3dCommandList->ResourceBarrier(1, &d3dResourceBarrier);

	D3D12_CPU_DESCRIPTOR_HANDLE d3dRtvCPUDescriptorHandle = m_pd3dRtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	d3dRtvCPUDescriptorHandle.ptr += (m_nSwapChainBufferIndex * m_nRtvDescriptorIncrementSize);

	float pfClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
	m_pd3dCommandList->ClearRenderTargetView(d3dRtvCPUDescriptorHandle, pfClearColor/*Colors::Azure*/, 0, NULL);

	D3D12_CPU_DESCRIPTOR_HANDLE d3dDsvCPUDescriptorHandle = m_pd3dDsvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();
	m_pd3dCommandList->ClearDepthStencilView(d3dDsvCPUDescriptorHandle, D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, 1.0f, 0, 0, NULL);

	m_pd3dCommandList->OMSetRenderTargets(1, &d3dRtvCPUDescriptorHandle, TRUE, &d3dDsvCPUDescriptorHandle);

	if (m_pScene) m_pScene->Render(m_pd3dCommandList, m_pCamera);

#ifdef _WITH_PLAYER_TOP
	m_pd3dCommandList->ClearDepthStencilView(d3dDsvCPUDescriptorHandle, D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, 1.0f, 0, 0, NULL);
#endif
	//if (m_pPlayer) m_pPlayer->Render(m_pd3dCommandList, m_pCamera);

	d3dResourceBarrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
	d3dResourceBarrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
	d3dResourceBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
	m_pd3dCommandList->ResourceBarrier(1, &d3dResourceBarrier);

	hResult = m_pd3dCommandList->Close();
	
	ID3D12CommandList *ppd3dCommandLists[] = { m_pd3dCommandList };
	m_pd3dCommandQueue->ExecuteCommandLists(1, ppd3dCommandLists);

	WaitForGpuComplete();

#ifdef _WITH_PRESENT_PARAMETERS
	DXGI_PRESENT_PARAMETERS dxgiPresentParameters;
	dxgiPresentParameters.DirtyRectsCount = 0;
	dxgiPresentParameters.pDirtyRects = NULL;
	dxgiPresentParameters.pScrollRect = NULL;
	dxgiPresentParameters.pScrollOffset = NULL;
	m_pdxgiSwapChain->Present1(1, 0, &dxgiPresentParameters);
#else
#ifdef _WITH_SYNCH_SWAPCHAIN
	m_pdxgiSwapChain->Present(1, 0);
#else
	m_pdxgiSwapChain->Present(0, 0);
#endif
#endif

//	m_nSwapChainBufferIndex = m_pdxgiSwapChain->GetCurrentBackBufferIndex();
	MoveToNextFrame();

	m_GameTimer.GetFrameRate(m_pszFrameRate + 12, 37);
	size_t nLength = _tcslen(m_pszFrameRate);
	//XMFLOAT3 xmf3Position = m_pPlayer->GetPosition();
	//_stprintf_s(m_pszFrameRate + nLength, 70 - nLength, _T("(%4f, %4f, %4f)"), xmf3Position.x, xmf3Position.y, xmf3Position.z);
	::SetWindowText(m_hWnd, m_pszFrameRate);

	
}


//void CGameFramework::OnSocketHandel(WPARAM wParam, LPARAM lParam)
//{
//	if (WSAGETASYNCERROR(lParam)) {
//		closesocket((SOCKET)wParam);
//		err_display("WSAGETSELECTERROR");
//	}
//
//	switch (WSAGETSELECTEVENT(lParam))
//	{
//	case FD_READ:
//		m_pScene->recv_packet();
//		//m_pScene->process_packet();
//		break;
//	
//	case FD_CLOSE:
//		closesocket((SOCKET)wParam);
//		err_display("CLOSE SOCKET");
//	case FD_WRITE:
//		break;
//	}
//
//}

void CGameFramework::OnSocket(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETASYNCERROR(lParam)) {
		closesocket((SOCKET)wParam);
		err_display("WSAGETSELECTERROR");
	}

	switch (WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
		m_pScene->recv_packet(m_pd3dDevice, m_pd3dCommandList, m_pCamera);
		break;

	case FD_CLOSE:
		closesocket((SOCKET)wParam);
		err_display("CLOSE SOCKET");
		break;
	}
}

void CGameFramework::Connection()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 999);

	int retval = 0;
	//UINT c_id = dis(gen);
	// ���� �ʱ�ȭ
	if (WSAStartup(MAKEWORD(2, 2), &m_WSA) != 0) err_quit((const char*)"connect()");

	// set serveraddr
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	//serveraddr.sin_addr.s_addr = inet_addr(SERVER_ROOP);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);

	// socket()
	m_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (m_socket == INVALID_SOCKET) err_quit((const char*)"socket()");
	
	retval = WSAConnect(m_socket, (SOCKADDR*)&serveraddr, sizeof(serveraddr),0,0,0,0);
	
	WSAAsyncSelect(m_socket, m_hWnd, WM_SOCKET, FD_READ | FD_CLOSE);
	if (retval == SOCKET_ERROR) err_quit("WSAAsyncSelect()");

	g_client.m_sock = m_socket;

	if (retval == SOCKET_ERROR)
	{
		int errorcode = WSAGetLastError();
		if (errorcode != WSAEWOULDBLOCK) {
			err_display("connect() failed\n");
			cout << "���� ���� ����\n";
			return;
		}
	}

	else {
		cout << "���� ���� ����\n";
		cout << "Server IP : " << SERVERIP << "\nServer Port : " << SERVERPORT << "\n";
	}

}

void CGameFramework::LoginServer()
{
	CS_LOGIN_PACKET p_login;
	p_login.size = sizeof(CS_LOGIN_PACKET);
	p_login.type = PACKET_TYPE::CS_LOGIN;
	strcpy_s(p_login.name, "PLAYER");

	SendPacket(&p_login);

	

}
