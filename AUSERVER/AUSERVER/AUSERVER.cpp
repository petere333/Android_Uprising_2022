#include "stdafx.h"
#include "Func.h"

SOCKET client_s;
WSABUF c_buf[1];
CHAR c_pack[BUFSIZE];

WSAOVERLAPPED c_over;

int main(int argc, char* argv[])
{
	std::wcout.imbue(std::locale("korean"));
	
	int retval;

	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return 1;

	//socket()
	SOCKET listen_s = WSASocket(AF_INET, SOCK_STREAM, 0, 0, 0, WSA_FLAG_OVERLAPPED);
	if (listen_s == INVALID_SOCKET) error_quit("socket()");

	//bind()
	SOCKADDR_IN ServerAddr;
	ZeroMemory(&ServerAddr, sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	ServerAddr.sin_port = htons(SERVERPORT);
	retval = bind(listen_s, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
	if (retval == SOCKET_ERROR) error_quit("bind()");

	//listen()
	retval = listen(listen_s, SOMAXCONN);
	if (retval == SOCKET_ERROR) error_quit("listen()");

	cout << "Listening .. ";

	SOCKADDR_IN ClientAddr;
	HANDLE hThread;
	int len;
	int client_id;

	while (1)
	{
		//accept()
		len = sizeof(ClientAddr);
		client_s = accept(listen_s, (sockaddr*)&ClientAddr, &len);

		if (client_s == INVALID_SOCKET)
		{
			error_display("accept()");
			break;
		}

		cout << "\n[SERVER] 클라이언트 접속 : IP주소 = " << inet_ntoa(ClientAddr.sin_addr)
			<< ", 포트 번호 = " << ntohs(ClientAddr.sin_port) << endl;


	}

	closesocket(client_s);
	closesocket(listen_s);

	WSACleanup();
	return 0;
}

void error_display(const char* msg)
{
	WCHAR* lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	std::cout << msg;
	std::wcout << L"에러 " << lpMsgBuf << std::endl;
	while (true);
	LocalFree(lpMsgBuf);
}

void error_quit(const char* msg)
{
	wchar_t wMsg[20];
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);

	MessageBox(NULL, (LPCTSTR)lpMsgBuf, wMsg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);

}

int recvn(SOCKET s, char* buf, int len, int flags)
{
	int received;
	char* ptr = buf;
	int left = len;

	while (left > 0) {
		received = recv(s, ptr, left, flags);

		if (received == SOCKET_ERROR) { return SOCKET_ERROR; }
		else if (received == 0) { break; }

		left -= received;
		ptr += received;
	}

	return (len - left);
}

void recvPacket()
{
	c_buf[0].buf = c_pack;
	c_buf[0].len = BUFSIZE;
	DWORD recvflag = 0;
	ZeroMemory(&c_over, 0, sizeof(c_over));
	WSARecv(client_s, c_buf, 1, 0, &recvflag, &c_over, recv_callback);
}

void CALLBACK send_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED over, DWORD flags)
{
	recvPacket();
}

void CALLBACK recv_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED over, DWORD flags)
{
	if (0 == num_bytes) return;
	cout << "Client sent: " << c_pack << endl;
	c_buf[0].len = num_bytes;
	memset(&c_over, 0, sizeof(c_over));
	WSASend(client_s, c_buf, 1, 0, 0, &c_over, send_callback);
}