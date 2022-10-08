#pragma once

#define FRAME_BUFFER_WIDTH		1200
#define FRAME_BUFFER_HEIGHT		900

#include "Timer.h"
#include "Game_Data.h"
#include "Scene.h"





class CGameFramework
{
public:
	CGameFramework();
	~CGameFramework();

	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);
	void OnDestroy();

	void CreateSwapChain();
	void CreateDirect3DDevice();
	void CreateCommandQueueAndList();

	void CreateRtvAndDsvDescriptorHeaps();

	void CreateRenderTargetViews();
	void CreateDepthStencilView();

	void ChangeSwapChainState();

    void BuildObjects();
    void ReleaseObjects();

    void ProcessInput();
    void AnimateObjects();
    void FrameAdvance();

	void WaitForGpuComplete();
	void MoveToNextFrame();

	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	bool fullscr = false;

public: // to server
	void OnSocketHandel(WPARAM wParam, LPARAM lParam);
	void OnSocket(WPARAM wParam, LPARAM lParam);
	void Connection();
	void LoginServer();
	//void Disconnection();
	void ClientNet();
	int GetPlayerid() { return m_Playerid; }
	void SetPlayerid(int id) { m_Playerid = id; }
	static CGameFramework& Instance() 
	{
		static CGameFramework _instance;
		return _instance;
	}



private:
	WSADATA						m_WSA;
	SOCKET						m_socket;
	SOCKADDR					m_serveraddr;

	CRITICAL_SECTION			m_cs;
	//static CGameFramework		_instance;

private:
	string						m_PlayerName;
	int							m_Playerid;

private:
	HINSTANCE					m_hInstance;
	HWND						m_hWnd; 

	int							m_nWndClientWidth;
	int							m_nWndClientHeight;
        
	IDXGIFactory4				*m_pdxgiFactory = NULL;
	IDXGISwapChain3				*m_pdxgiSwapChain = NULL;
	ID3D12Device				*m_pd3dDevice = NULL;

	bool						m_bMsaa4xEnable = false;
	UINT						m_nMsaa4xQualityLevels = 0;

	static const UINT			m_nSwapChainBuffers = 2;
	UINT						m_nSwapChainBufferIndex;

	ID3D12Resource				*m_ppd3dSwapChainBackBuffers[m_nSwapChainBuffers];
	ID3D12DescriptorHeap		*m_pd3dRtvDescriptorHeap = NULL;
	UINT						m_nRtvDescriptorIncrementSize;

	ID3D12Resource				*m_pd3dDepthStencilBuffer = NULL;
	ID3D12DescriptorHeap		*m_pd3dDsvDescriptorHeap = NULL;
	UINT						m_nDsvDescriptorIncrementSize;

	ID3D12CommandAllocator		*m_pd3dCommandAllocator = NULL;
	ID3D12CommandQueue			*m_pd3dCommandQueue = NULL;
	ID3D12GraphicsCommandList	*m_pd3dCommandList = NULL;

	ID3D12Fence					*m_pd3dFence = NULL;
	UINT64						m_nFenceValues[m_nSwapChainBuffers];
	HANDLE						m_hFenceEvent;

#if defined(_DEBUG)
	ID3D12Debug					*m_pd3dDebugController;
#endif

	CGameTimer					m_GameTimer;

	CScene						*m_pScene = NULL;
	
	CCamera						*m_pCamera = NULL;

	POINT						m_ptOldCursorPos;

	_TCHAR						m_pszFrameRate[70];
	
public:
	bool keydown=false;
	bool mousedown = false;
	float dx=0.0f, dy=0.0f, dz=0.0f;
	int prevX=500, prevY=500;

	int lastOrder = 0;
	// 0 :up	 1 : down	 2 : left	3 : right
	CLoadedModelInfo** models;
};

char* getIP(FILE*);