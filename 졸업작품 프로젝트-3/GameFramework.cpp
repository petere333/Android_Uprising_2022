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
	

	_tcscpy_s(m_pszFrameRate, _T("LabProject ("));
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
	
	// CSound::Init();

	SetCursorPos(500, 500);

	BuildObjects();

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
	switch (nMessageID)
	{
		case WM_LBUTTONDOWN:
			// 마우스 좌클릭 시 공격 상태로 변화.
			if (mousedown == false)
			{
				MOUSE_PACKET p;
				p.c_id = 1;
				p.size = sizeof(MOUSE_PACKET);
				p.down = true;
				p.type = PACKET_TYPE::CS_MOUSE;
				SendPacket(&p);
				mousedown = true;
			}
			break;
		case WM_RBUTTONDOWN:
			
			//::SetCapture(hWnd);
			//::GetCursorPos(&m_ptOldCursorPos);
			
			break;
		case WM_LBUTTONUP:
		{

			if (mousedown == true)
			{
				MOUSE_PACKET p;
				p.c_id = 1;
				p.size = sizeof(MOUSE_PACKET);
				p.down = false;
				p.type = PACKET_TYPE::CS_MOUSE;
				SendPacket(&p);
				mousedown = false;
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

void CGameFramework::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{

	if (m_pScene) m_pScene->OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
	

	// 패킷 전송 예시
	


	KEYDOWN_PACKET packet;
	packet.c_id = 1;
	packet.size = sizeof(KEYDOWN_PACKET);
	packet.type = PACKET_TYPE::CS_KEYDOWN;
	
	KEYUP_PACKET uppac;
	uppac.c_id = 1;
	uppac.size = sizeof(KEYUP_PACKET);
	uppac.type = PACKET_TYPE::CS_KEYUP;
	// lastOrder::마지막으로 이동했던 방향이 어느 방향인가?
	// 값은 위, 아래, 왼쪽, 오른쪽 각각 1,2,3,4

	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
		{
			if (m_pScene->players[0]->pState.id == ATTACK_STATE)
			{
				break;
			}
			/*
			if (lastOrder == 1)
			{
				// 플레이어를 카메라 시선 기준 상하좌우 방향으로 회전.
				m_pScene->rotateObject(0, 0.0f, 180.0f, 0.0f);
			}
			else if(lastOrder == 2)
			{
				// 플레이어를 카메라 시선 기준 상하좌우 방향으로 회전.
				m_pScene->rotateObject(0, 0.0f, 90.0f, 0.0f);
			}
			else if (lastOrder == 3)
			{
				// 플레이어를 카메라 시선 기준 상하좌우 방향으로 회전.
				m_pScene->rotateObject(0, 0.0f, 270.0f, 0.0f);
			}
			lastOrder = 0;
			// 플레이어의 속도, 상태 설정
			
			if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
			{
				m_pScene->setObjectSpeed(0, PLAYER_SPEED);
				m_pScene->setObjectState(0, MOVE_STATE);
				
			}
			*/
			packet.key = VK_UP;
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
		}
		break;
		case VK_DOWN:
		{
			if (m_pScene->players[0]->pState.id == ATTACK_STATE)
			{
				break;
			}
			/*
			if (lastOrder == 0)
			{
				m_pScene->rotateObject(0, 0.0f, 180.0f, 0.0f);
			}
			else if (lastOrder == 2)
			{
				m_pScene->rotateObject(0, 0.0f, 270.0f, 0.0f);
			}
			else if (lastOrder == 3)
			{
				m_pScene->rotateObject(0, 0.0f, 90.0f, 0.0f);
			}
			lastOrder = 1;
			
			if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
			{
				m_pScene->setObjectSpeed(0, PLAYER_SPEED);
				m_pScene->setObjectState(0, MOVE_STATE);
			}
			*/
			packet.key = VK_DOWN;
			
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
		}
		break;
		case VK_LEFT:
		{
			if (m_pScene->players[0]->pState.id == ATTACK_STATE)
			{
				break;
			}
			/*
			if (lastOrder == 0)
			{
				m_pScene->rotateObject(0, 0.0f, 270.0f, 0.0f);
			}
			else if (lastOrder == 1)
			{
				m_pScene->rotateObject(0, 0.0f, 90.0f, 0.0f);
			}
			else if (lastOrder == 3)
			{
				m_pScene->rotateObject(0, 0.0f, 180.0f, 0.0f);
			}
			lastOrder = 2;
			if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
			{
				m_pScene->setObjectSpeed(0, PLAYER_SPEED);
				m_pScene->setObjectState(0, MOVE_STATE);
			}
			*/
			packet.key = VK_LEFT;
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
		}
		break;
		case VK_RIGHT:
		{
			if (m_pScene->players[0]->pState.id == ATTACK_STATE)
			{
				break;
			}
			/*
			if (lastOrder == 0)
			{
				m_pScene->rotateObject(0, 0.0f, 90.0f, 0.0f);
			}
			else if (lastOrder == 1)
			{
				m_pScene->rotateObject(0, 0.0f, 270.0f, 0.0f);
			}
			else if (lastOrder == 2)
			{
				m_pScene->rotateObject(0, 0.0f, 180.0f, 0.0f);
			}
			lastOrder = 3;
			if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
			{
				m_pScene->setObjectSpeed(0, PLAYER_SPEED);
				m_pScene->setObjectState(0, MOVE_STATE);
			}
			*/
			packet.key = VK_RIGHT;
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
		}
			break;
		case VK_SPACE:
		{
			
			if (m_pScene->players[0]->pState.id == ATTACK_STATE)
			{
				break;
			}
			// 플레이어에 대한 점프 명령
			//m_pScene->jumpObject(0);
			packet.key = VK_SPACE;
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
			break;
		}
		case '2':
		{
			/*
			PlayerState state = m_pScene->getPlayerState(0);

			XMFLOAT3 pos = m_pScene->getPos(0);
			PlayerState pstate = m_pScene->players[0]->pState;
			float spd = m_pScene->players[0]->speed;
			XMFLOAT3 di = m_pScene->players[0]->direction;
			float yspd = m_pScene->players[0]->yspeed;
			XMFLOAT3 rot = m_pScene->players[0]->currentRotation;
			//원거리 공격하는 상태가 아닌 경우 총기든 모델 객체로 변경
			if (state.attType != TYPE_RANGED)
			{

				//m_pScene->players[0] = m_pScene->playerTypes[0];

				m_pScene->players[0]->setRoot(m_pScene->binModels[0]->m_pModelRootObject, true);
				m_pScene->players[0]->m_pSkinnedAnimationController = new CAnimationController(m_pd3dDevice, m_pd3dCommandList, 1, m_pScene->binModels[0]);

				m_pScene->players[0]->pState.attType = TYPE_RANGED;
			}
			*/
			packet.key = '2';
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
			break;
		}
		case '1':
		{
			/*
			PlayerState state = m_pScene->getPlayerState(0);

		
			if (state.attType != TYPE_MELEE)
			{
				if (state.id == IDLE_STATE)
				{
					m_pScene->players[0]->setRoot(m_pScene->binModels[2]->m_pModelRootObject, true);
					m_pScene->players[0]->m_pSkinnedAnimationController = new CAnimationController(m_pd3dDevice, m_pd3dCommandList, 1, m_pScene->binModels[2]);
					m_pScene->players[0]->pState.attType = TYPE_MELEE;
				}
				else if (state.id == MOVE_STATE)
				{
					m_pScene->players[0]->setRoot(m_pScene->binModels[1]->m_pModelRootObject, true);
					m_pScene->players[0]->m_pSkinnedAnimationController = new CAnimationController(m_pd3dDevice, m_pd3dCommandList, 1, m_pScene->binModels[1]);
					m_pScene->players[0]->pState.attType = TYPE_MELEE;
				}
				
			}
			*/
			packet.key = '1';
			if (keydown == false)
			{
				SendPacket(&packet);
				keydown = true;
			}
		}

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
				case VK_F1:
				case VK_F2:
				case VK_F3:
				case VK_F9:
					ChangeSwapChainState();
					break;
				// 상하좌우 키가 떼어진 경우 정지 상태로 변경, 속도를 0으로 변경.
				case VK_UP:
					/*
					if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
					{
						m_pScene->setObjectSpeed(0, 0.0f);
						m_pScene->setObjectState(0, IDLE_STATE);
					}
					*/
					uppac.key = VK_UP;
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				case VK_DOWN:
					/*
					if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
					{
						m_pScene->setObjectSpeed(0, 0.0f);
						m_pScene->setObjectState(0, IDLE_STATE);
					}
					*/
					uppac.key = VK_DOWN;
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				case VK_LEFT:
					/*
					if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
					{
						m_pScene->setObjectSpeed(0, 0.0f);
						m_pScene->setObjectState(0, IDLE_STATE);
					}
					*/
					uppac.key = VK_LEFT;
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
					break;
				case VK_RIGHT:
					/*
					if (m_pScene->getPlayerState(0).id != ATTACK_STATE)
					{
						m_pScene->setObjectSpeed(0, 0.0f);
						m_pScene->setObjectState(0, IDLE_STATE);
					}
					*/
					uppac.key = VK_RIGHT;
					if (keydown == true)
					{
						SendPacket(&uppac);
						keydown = false;
					}
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
					break;
				default:
					break;
			}
			break;
		default:
			break;
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
	//마우스 이동 시 플레이어의 위치 변경.
	POINT pnt;
	GetCursorPos(&pnt);

	XMFLOAT3 offset = m_pScene->getPos(0);
	float deltaX = static_cast<float>(pnt.x - prevX) / 5.0f;
	float deltaY = static_cast<float>(pnt.y - prevY) / 100.0f;


	//여기서부터 서버에서 처리
	m_pCamera->rotate(-deltaX, offset.x, offset.z);
	m_pCamera->rotateUp(-deltaY);
	m_pScene->rotateObject(0, 0.0f, deltaX, 0.0f);
	


	SetCursorPos(500, 500);
	prevX = 500;
	prevY = 500;
	//서버 처리 끝

}


void CGameFramework::AnimateObjects()
{
	float fTimeElapsed = m_GameTimer.GetTimeElapsed();

	//m_pScene->moveObject(0);

	
	// 이 이후로는 클라가 처리

	/*
	if (m_pScene->getSpeed(0) > 0.0f || m_pScene->players[0]->yspeed != 0.0f)//실질적으로 이동을 시도한 경우=속도의 값이 0보다 큰 경우
	{
		if (m_pScene->moveSuccessed(0))//실제로 이동에 성공한 경우 = 충돌이 없는 경우
		{
			if (m_pScene->isWalking == false)
			{
				m_pScene->soundEffect[2]->play();
				m_pScene->isWalking = true;
			}
			float angle = XMConvertToRadians(m_pCamera->angle);
			XMFLOAT3 pos = m_pScene->getPos(0);
			float spd = m_pScene->getSpeed(0);
			m_pCamera->move(cos(angle) * 2.0f + pos.x, pos.y+2.85f, sin(angle) * 2.0f + pos.z);

			if (m_pScene->players[0]->pState.attType == TYPE_RANGED)
			{
				if (m_pScene->currentPlayerAnim != 20)
				{
					m_pScene->players[0]->setRoot(m_pScene->binModels[0]->m_pModelRootObject, true);
					m_pScene->players[0]->m_pSkinnedAnimationController = new CAnimationController(m_pd3dDevice, m_pd3dCommandList, 1, m_pScene->binModels[0]);
					m_pScene->setPlayerAnimation(20);
				}
			}
			else if (m_pScene->players[0]->pState.attType == TYPE_MELEE)
			{
				m_pScene->players[0]->setRoot(m_pScene->binModels[1]->m_pModelRootObject, true);
				m_pScene->players[0]->m_pSkinnedAnimationController = new CAnimationController(m_pd3dDevice, m_pd3dCommandList, 1, m_pScene->binModels[1]);
				m_pScene->setPlayerAnimation(0);
			}
		}
		else
		{
			if (m_pScene->isWalking == true)
			{
				m_pScene->soundEffect[2]->stop();
				m_pScene->isWalking = false;
			}
		}
	}
	else
	{
		if (m_pScene->isWalking == true)
		{
			m_pScene->soundEffect[2]->stop();
			m_pScene->isWalking = false;
		}
		if (m_pScene->players[0]->pState.attType == TYPE_RANGED)
		{
			if (m_pScene->currentPlayerAnim != 11)
			{
				m_pScene->setPlayerAnimation(11);
			}
		}
		else if (m_pScene->players[0]->pState.attType == TYPE_MELEE)
		{
			m_pScene->setPlayerAnimation(0);
		}
	}
	*/
	

	if (m_pScene) m_pScene->AnimateObjects(m_pd3dDevice, m_pd3dCommandList, fTimeElapsed);

	
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
	m_GameTimer.Tick(0.0f);
	
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


void CGameFramework::OnSocketHandel(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETASYNCERROR(lParam)) {
		closesocket((SOCKET)wParam);
		err_display("WSAGETSELECTERROR");
	}

	switch (WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
		m_pScene->recv_packet();
		m_pScene->process_packet();
		break;
	
	case FD_CLOSE:
		closesocket((SOCKET)wParam);
		err_display("CLOSE SOCKET");
	}

}

void CGameFramework::Connection()
{
	int retval = 0;
	UINT c_id = 1234;
	// 윈속 초기화
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
	
	retval = connect(m_socket, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	
	WSAAsyncSelect(m_socket, m_hWnd, WM_SOCKET, FD_CLOSE | FD_READ);

	g_client.m_sock = m_socket;
	if (retval == SOCKET_ERROR)
	{
		int errorcode = WSAGetLastError();
		if (errorcode != WSAEWOULDBLOCK) {
			err_display("connect() failed");
			cout << "서버 연결 실패\n";
			return;
		}
	}

	else {
		cout << "서버 연결 성공\n";
		cout << "Server IP : " << SERVERIP << "\nServer Port : " << SERVERPORT << "\nClient ID : " << c_id;
	}

}

void CGameFramework::ClientNet()
{
	if (m_pScene) m_pScene->ClientNet(m_socket);
}