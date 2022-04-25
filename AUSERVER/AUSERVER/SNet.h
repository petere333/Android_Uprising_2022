#pragma once
#include "stdafx.h"

// ���� �Լ� ���� ���
void error_display(const char* msg);
void error_quit(const char* msg);

// recv�� �̿��� ����� ���� �Լ�
int recvn(SOCKET s, char* buf, int len, int flags);
void SendPacket(SOCKET sock, void* p);
void RecvPacket(SOCKET sock, char* buf);
void CALLBACK recv_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED over, DWORD flags);
void CALLBACK send_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED over, DWORD flags);
DWORD WINAPI MainServerThread(LPVOID arg);
