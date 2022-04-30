#include "stdafx.h"
#include "SNet.h"
#include "protocol.h"

constexpr int MAXUSER = 5; //최대 접속 유저

enum COMP_TYPE { PL_ACCEPT, PL_RECV, PL_SEND };

class OVER_EXP {
public:
	WSAOVERLAPPED _over;
	int _s_id;
	WSABUF _wsabuf;
	char _send_buf[BUFSIZE];
	COMP_TYPE _comp_type;

	OVER_EXP()
	{
		_wsabuf.len = BUFSIZE;
		_wsabuf.buf = _send_buf;
		_comp_type = PL_RECV;
		ZeroMemory(&_over, sizeof(_over));
	}
	OVER_EXP(char* packet)
	{
		_wsabuf.len = packet[0];
		_wsabuf.buf = _send_buf;
		ZeroMemory(&_over, sizeof(_over));
		_comp_type = PL_SEND;
		memcpy(_send_buf, packet, packet[0]);
	}
};

class SESSION {

public:
	OVER_EXP _recv_over;
	bool _use;
	int _id;
	SOCKET _socket;
	XMFLOAT3 set;
	char	_name[NAMESIZE];
	int		_prev_remain;

public:
	SESSION()
	{
		_id = -1;
		_socket = 0;
		set.x = 0;
		set.y = 0;
		set.z = 0;
		_name[0] = 0;
		_use = false;
		_prev_remain = 0;
	}

	~SESSION() {}

	void do_recv()
	{
		DWORD recv_flag = 0;
		memset(&_recv_over._over, 0, sizeof(_recv_over._over));
		_recv_over._wsabuf.len = BUFSIZE - _prev_remain;
		_recv_over._wsabuf.buf = _recv_over._send_buf + _prev_remain;
		WSARecv(_socket, &_recv_over._wsabuf, 1, 0, &recv_flag,
			&_recv_over._over, 0);
	}

	void do_send(void* packet)
	{
		OVER_EXP* s_data = new OVER_EXP{ reinterpret_cast<char*>(packet) };
		WSASend(_socket, &s_data->_wsabuf, 1, 0, 0, &s_data->_over, 0);
	}

	void send_login_info()
	{
		//Server to Client
		SC_LOGIN_INFO_PACKET info;
		PACKET_TYPE pt;
		info.id = _id; //client id
		info.size = sizeof(SC_LOGIN_INFO_PACKET); //packet size
		info.type = PACKET_TYPE::SC_LOGIN_INFO; //packet type
		info.x = set.x;
		info.y = set.y;
		info.z = set.z;
		do_send(&info);
	}
	void send_move_info(int c_id); //send client move info
};

array<SESSION, MAXUSER> clients;

void SESSION::send_move_info(int c_id)
{
	SC_MOVE_PLAYER_PACKET pl;
	pl.id = c_id;
	pl.size = sizeof(SC_MOVE_PLAYER_PACKET);
	pl.type = PACKET_TYPE::SC_MOVE_PLAYER;
	pl.x = clients[c_id].set.x;
	pl.y = clients[c_id].set.y;
	pl.z = clients[c_id].set.z;
	do_send(&pl);

}

int get_new_player_id()
{
	for (int i = 0; i < MAXUSER; ++i)
		if (clients[i]._use == false)
			return i;
	return -1;
}

void process_packet(int c_id, char* packet)
{
	switch ((PACKET_TYPE)packet[1]) {
	case PACKET_TYPE::CS_LOGIN: {
		CS_LOGIN_PACKET* p = reinterpret_cast<CS_LOGIN_PACKET*>(packet);
		strcpy_s(clients[c_id]._name, p->name);
		clients[c_id].send_login_info();

		for (auto pl : clients) { //새 클라이언트의 정보 전송
			if (pl._use == false) continue;
			if (pl._id == c_id) continue;

			SC_ADD_PLAYER_PACKET add_packet;
			PACKET_TYPE pt;
			add_packet.id = c_id;
			strcpy_s(add_packet.name, p->name);
			add_packet.size = sizeof(add_packet);
			add_packet.type = PACKET_TYPE::SC_ADD_PLAYER;
			add_packet.x = clients[c_id].set.x;
			add_packet.y = clients[c_id].set.y;
			add_packet.z = clients[c_id].set.z;
			pl.do_send(&add_packet);
		}

		for (auto pl : clients) { //기존 클라이언트의 정보 전송 (수정중)
			if (pl._use == false) continue;
			if (pl._id == c_id) continue;

			SC_ADD_PLAYER_PACKET add_packet;
			add_packet.id = pl._id;
			strcpy_s(add_packet.name, p->name);
			add_packet.size = sizeof(add_packet);
			add_packet.type = PACKET_TYPE::SC_ADD_PLAYER;
			add_packet.x = pl.set.x;
			add_packet.y = pl.set.y;
			add_packet.z = pl.set.z;
			clients[c_id].do_send(&add_packet);
		}
		break;
	}
	case PACKET_TYPE::CS_MOVE: {
		CS_MOVE_PACKET* p_move = reinterpret_cast<CS_MOVE_PACKET*>(packet);
		//XMFLOAT3 pos = clients[c_id].GetPosition();
		if (p_move->isKey) {
			switch (p_move->direction) {
			case VK_W:
				break;
			case VK_S:
				break;
			case VK_A:
				break;
			case VK_D:
				break;
			}

			//SC_MOVE_PLAYER_PACKET m_packet;
			//m_packet.id = c_id;
			//m_packet.size = sizeof(m_packet);
			//m_packet.x = pos.x;
			//m_packet.y = pos.y;
			//m_packet.z = pos.z;

			for (auto& pl : clients)
				if (true == pl._use)
					pl.send_move_info(c_id);
		}
			break;
	}
	}
}

void disconnect(int c_id)
{
	for (auto& pl : clients) 
	{
		if (pl._use == false) continue;
		if (pl._id == c_id) continue;
		SC_REMOVE_PLAYER_PACKET rm;
		rm.id = c_id;
		rm.size = sizeof(rm);
		rm.type = PACKET_TYPE::SC_REMOVE_PLAYER;
		clients[c_id].do_send(&rm);
	}
	closesocket(clients[c_id]._socket);
	clients[c_id]._use = false;
}
//
//void CALLBACK send_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED send_over, DWORD flag)
//{
//	OVER_EXP* ex_over = reinterpret_cast<OVER_EXP*>(send_over);
//	delete ex_over;
//}
//
//void CALLBACK recv_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED over, DWORD flags)
//{
//	auto client = reinterpret_cast<SESSION*>(over);
//	int client_id = client->_id;
//	SOCKET client_s = client->_socket;
//	auto ex_over = &client->_recv_over;
//
//	if (num_bytes == 0) {
//		cout << "Client disconnected\n";
//		disconnect(client_id);
//		return;
//	};
//	cout << "Client " << client_id << " sent: " << clients[client_id]._c_mess << endl;
//	for (auto& cl : clients)
//		cl.second.do_send(num_bytes, clients[client_id]._c_mess, client_id);
//	clients[client_id].do_recv();
//}

int main(int argc, char* argv[])
{
	std::wcout.imbue(std::locale("korean")); //오류 출력을 한국어로

	WSADATA WSAData;

	//윈속 초기화
	WSAStartup(MAKEWORD(2, 2), &WSAData); 

	//서버소켓생성
	SOCKET server = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED); 
	SOCKADDR_IN server_addr;
	memset(&server_addr, 0, sizeof(server_addr)); 
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVERPORT);
	server_addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(server, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)); //bind
	listen(server, SOMAXCONN); //서버소켓 listening 상태
	cout << "Listening..";
	SOCKADDR_IN cl_addr; //클라이언트 주소
	int addr_size = sizeof(cl_addr);
	int client_id = 0; //클라이언트 아이디 초기화

	HANDLE h_iocp;
	h_iocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0); //IOCP 핸들 생성
	CreateIoCompletionPort(reinterpret_cast<HANDLE>(server), h_iocp, 1234, 0); //핸들 초기화

	SOCKET c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED); //통신 소켓 생성
	OVER_EXP a_over;
	a_over._comp_type = PL_ACCEPT;
	AcceptEx(server, c_socket, a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &a_over._over);


	while (true) {
		DWORD num_bytes;
		ULONG_PTR key;
		WSAOVERLAPPED* over = nullptr;
		BOOL ret = GetQueuedCompletionStatus(h_iocp, &num_bytes, &key, &over, INFINITE);
		OVER_EXP* ex_over = reinterpret_cast<OVER_EXP*>(over);
		if (FALSE == ret) {
			if (ex_over->_comp_type == PL_ACCEPT) cout << "ACCEPT ERROR";
			else {
				cout << "GQCS Error on clients[" << key << "]\n";
				disconnect(key);
				if (ex_over->_comp_type == PL_SEND) delete ex_over;
			}
		}

		switch (ex_over->_comp_type) {
		case PL_ACCEPT: {
			cout << "\nclient ID [" << key << "] connected.\n";
			int client_id = get_new_player_id();
			if (client_id != -1) {
				clients[client_id]._use = true;
				clients[client_id].set.x = 0;
				clients[client_id].set.y = 0;
				clients[client_id].set.z = 0;
				clients[client_id]._id = client_id;
				clients[client_id]._name[0] = 0;
				clients[client_id]._prev_remain = 0;
				clients[client_id]._socket = c_socket;
				CreateIoCompletionPort(reinterpret_cast<HANDLE>(c_socket),
					h_iocp, client_id, 0);
				clients[client_id].do_recv();
				cout << "ACCEPT SUCCESS.\n";

				c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

			}
			else {
				cout << "Max user exceeded.\n";
			}
			ZeroMemory(&a_over._over, sizeof(a_over._over));
			AcceptEx(server, c_socket, a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &a_over._over);
			break;
		}
		case PL_RECV: {
			int remain_data = num_bytes + clients[client_id]._prev_remain;
			char* p = ex_over->_send_buf;
			while (remain_data > 0) {
				int packet_size = p[0];
				if (packet_size <= remain_data) {
					process_packet(client_id, p);
					p = p + packet_size;
					remain_data = remain_data - packet_size;
				}
				else break;
			}
			clients[client_id]._prev_remain = remain_data;
			if (remain_data > 0) {
				memcpy(ex_over->_send_buf, p, remain_data);
			}
			clients[client_id].do_recv();
			cout << "Recv Success.\n";
			cout << clients[client_id].set.x << "\n";
			cout << clients[client_id].set.y << "\n";

			break;
		}
		case PL_SEND:
			delete ex_over;
			break;
		}
	}
	closesocket(server);
	WSACleanup();

}
