#pragma once
#define _CRT_SECURE_NO_WARNINGS         // 최신 VC++ 컴파일 시 경고 방지
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 최신 VC++ 컴파일 시 경고 방지

#include "../AUSERVER/AUSERVER/protocol.h"

#pragma comment(lib, "ws2_32")
#include <WinSock2.h>  

#define	WM_SOCKET	WM_USER + 1

struct EX_OVER
{
	WSAOVERLAPPED	m_over;
	WSABUF			m_wsabuf;
	char			m_sendbuf[BUFSIZE];
};

struct SESSION
{
	EX_OVER			m_recv_over;
	SOCKET			m_sock;
	int				m_prev_size;
	char			m_name[NAMESIZE];
};

extern SESSION g_client;

void err_quit(const char* msg);
void err_display(const char* msg);
int recvn(SOCKET s, char* buf, int len, int flag);
void SendPacket(void* p);
bool SendPacket(SOCKET& sock, char* packet, int packetSize, int& retVal);
bool RecvPacket(SOCKET& sock, char* buf, int& retVal);

void Process_Packet(SOCKET& sock, char* packet, int packetSize, PACKET_TYPE packetType);

