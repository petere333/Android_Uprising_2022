#include "stdafx.h"
#include "CNet.h"

SESSION g_client = SESSION();

void Process_packet(SOCKET sock, char* packet, int packetSize, PACKET_TYPE packetType)
{
	switch (packetType)
	{
    //client to server
	case PACKET_TYPE::CS_LOGIN:
    case PACKET_TYPE::CS_KEYDOWN:
    case PACKET_TYPE::CS_KEYUP:

    //server to client
    case PACKET_TYPE::SC_ADD_PLAYER:
    case PACKET_TYPE::SC_LOGIN_INFO:
    case PACKET_TYPE::SC_KINETIC_CHANGE:
    case PACKET_TYPE::SC_BIONIC_CHANGE:
    case PACKET_TYPE::SC_REMOVE_PLAYER:
    default:
        break;
	}
}

void SendPacket(void* p)
{
    unsigned char p_size = reinterpret_cast<unsigned char*>(p)[0];
    unsigned char p_type = reinterpret_cast<unsigned char*>(p)[1];

    EX_OVER* s_over = new EX_OVER;
    memset(&s_over->m_over, 0, sizeof(s_over->m_over));
    memcpy(s_over->m_sendbuf, p, p_size);
    s_over->m_wsabuf.buf = reinterpret_cast<CHAR*>(s_over->m_sendbuf);
    s_over->m_wsabuf.len = p_size;

    auto ret = WSASend(g_client.m_sock, &s_over->m_wsabuf, 1, NULL, 0, &s_over->m_over, NULL);
    if (0 != ret) {
        auto err_no = WSAGetLastError();
        if (WSA_IO_PENDING != err_no) {
            cout << "로그아웃\n";
            //disconnect(p_id);
        }
    }
}

// 소켓 함수 오류 출력 후 종료
void err_quit(const char* msg)
{
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, WSAGetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);
    MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
    LocalFree(lpMsgBuf);
    exit(1);
}

// 소켓 함수 오류 출력
void err_display(const char* msg)
{
    WCHAR* lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, WSAGetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);
    cout << msg;
    wcout << lpMsgBuf << "\n";
    LocalFree(lpMsgBuf);
}