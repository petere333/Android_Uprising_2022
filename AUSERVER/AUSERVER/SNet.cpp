#include "stdafx.h"
#include "SNet.h"

void error_display(const char* msg)
{
	WCHAR* lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	std::cout << msg;
	std::wcout << L"¿¡·¯ " << lpMsgBuf << std::endl;
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
//
//int recvn(SOCKET s, char* buf, int len, int flags)
//{
//	int received;
//	char* ptr = buf;
//	int left = len;
//
//	while (left > 0) {
//		received = recv(s, ptr, left, flags);
//
//		if (received == SOCKET_ERROR) { return SOCKET_ERROR; }
//		else if (received == 0) { break; }
//
//		left -= received;
//		ptr += received;
//	}
//
//	return (len - left);
//}
