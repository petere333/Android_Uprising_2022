#include "stdafx.h"
#include "SNet.h"
#include "protocol.h"


#include "../../졸업작품 프로젝트-3/Game_Data.h"

constexpr int MAXUSER = 10; //최대 접속 유저
enum COMP_TYPE { PL_ACCEPT, PL_RECV, PL_SEND };
chrono::time_point<chrono::system_clock> started;

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
	OVER_EXP _recv_over;

public:
	bool _use;
	int _id;
	SOCKET _socket;
	XMFLOAT3 set;
	KineticState kState;
	BionicState bState;
	float cameraAngle;
	float cameraUp;
	char	_name[NAMESIZE];
	int		_prev_remain;

public:
	SESSION()
	{
		_id = -1;
		_socket = 0;
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

	void send_login_info(int cid, int pid)
	{
		
		//Server to Client
		SC_LOGIN_INFO_PACKET info;
		PACKET_TYPE pt;
		info.id = cid; //client id
		//info.id = nplayer;
		info.size = sizeof(SC_LOGIN_INFO_PACKET); //packet size
		info.type = PACKET_TYPE::SC_LOGIN_INFO; //packet type
		info.x = 20.0f+ pid*5.0f;
		info.y = 0.0f;
		info.z = 175.0f;
		info.isLogin = true;

		kState.xzspeed = 0.0f;
		kState.yspeed = 0.0f;		
		kState.isMobile = true;
		kState.isInAir = false;	
		kState.rotation = 0.0f;	
		kState.lastMove = std::chrono::system_clock::now();

		bState.attackID = TYPE_RANGED;
		bState.hp = 10;
		bState.isIntelligent = true;
		bState.stateID = IDLE_STATE;

		cameraAngle = 270.0f;
		cameraUp = 0.0f;

		do_send(&info);
		
	}

	void send_kinetic_change(int c_id, KineticState kState);
	void send_bionic_change(int c_id, BionicState state);
	void send_camera_change(int c_id, float, float);
	void send_attack_info(int c_id, float x, float, float, int);
	void send_jump(int c_id);
	void send_teleport(int c_id, float x, float y, float z);
	void send_move(int c_id, float x, float y, float z, float a);
	void send_ready(int c_id, bool ready);
	void send_stats(int c_id, Stats s, int,int, int, int);
	void send_particle(int c_id, int count, float x, float y, float z, int type);

	void send_damage(int c_id, int target, int damage, float stun);
};

 array<SESSION, MAXUSER> clients;
 void SESSION::send_particle(int c_id, int count, float x, float y, float z, int type)
 {
	 SC_PARTICLE_PACKET p;
	 p.id = c_id;
	 p.type = PACKET_TYPE::SC_PARTICLE;
	 p.size = sizeof(SC_PARTICLE_PACKET);

	 p.x = x;
	 p.y = y;
	 p.z = z;
	 p.particleType = type;
	 p.count = count;
	 do_send(&p);

 }

 void SESSION::send_damage(int id, int target, int damage, float stun)
 {
	 SC_ATTACK_PACKET p;
	 p.id = id;
	 p.type = PACKET_TYPE::SC_ATTACK;
	 p.size = sizeof(SC_ATTACK_PACKET);
	 p.stuntime = stun;
	 p.damage = damage;
	 p.target = target;

	 do_send(&p);
 }

 void SESSION::send_stats(int c_id, Stats s, int m, int r, int mw, int rw)
 {
	 SC_POWER_PACKET pac;
	 pac.c_id = c_id;
	 pac.type = PACKET_TYPE::SC_POWER;
	 pac.size = sizeof(SC_POWER_PACKET);
	 pac.stats = s;
	 pac.m = m;
	 pac.r = r;
	 pac.mw = mw;
	 pac.rw = rw;
	 do_send(&pac);
 }

 void SESSION::send_ready(int cid, bool rd)
 {
	 SC_READY_PACKET pac;
	 pac.size = sizeof(SC_READY_PACKET);
	 pac.type = PACKET_TYPE::SC_READY;
	 pac.id = cid;
	 pac.ready = rd;

	 do_send(&pac);
 }

 void SESSION::send_move(int c_id, float x, float y, float z, float a)
 {
	 SC_POSITION_PACKET pac;
	 pac.id = c_id;
	 pac.size = sizeof(SC_POSITION_PACKET);
	 pac.type = PACKET_TYPE::SC_POSITION;
	 pac.angle = a;
	 pac.x = x;
	 pac.y = y;
	 pac.z = z;

	 
	 do_send(&pac);
 }

 void SESSION::send_kinetic_change(int c_id, KineticState state)
 {
	SC_KINETIC_PACKET pl;
	pl.c_id = c_id;
	pl.size = sizeof(SC_KINETIC_PACKET);
	pl.type = PACKET_TYPE::SC_KINETIC_CHANGE;
	pl.kState = state;
	

	do_send(&pl);

}
 void SESSION::send_bionic_change(int c_id, BionicState state)
 {
	 SC_BIONIC_PACKET p;
	 p.c_id = c_id;
	 p.size = sizeof(SC_BIONIC_PACKET);
	 p.type = PACKET_TYPE::SC_BIONIC_CHANGE;
	 p.bState = state;

	 do_send(&p);
}
 void SESSION::send_camera_change(int c_id, float angle, float up)
 {
	 SC_CAMERA_PACKET p;
	 p.c_id = c_id;
	 p.size = sizeof(SC_CAMERA_PACKET);
	 p.type = PACKET_TYPE::SC_CAMERA_CHANGE;
	 p.camAngle = angle;
	 p.camUp = up;

	 do_send(&p);
 }



 void SESSION::send_jump(int c_id)
 {
	 SC_JUMP_PACKET p;
	 p.size = sizeof(SC_JUMP_PACKET);
	 p.type = PACKET_TYPE::SC_JUMP;
	 p.id = c_id;

	 do_send(&p);
 }

 void SESSION::send_teleport(int c_id, float x, float y, float z)
 {
	 SC_TELEPORT_PACKET p;
	 p.id = c_id;
	 p.size = sizeof(SC_TELEPORT_PACKET);
	 p.type = PACKET_TYPE::SC_TELEPORT;
	 
	 p.x = x;
	 p.y = y;
	 p.z = z;

	 do_send(&p);
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
	case PACKET_TYPE::CS_LOGIN:
	{
		CS_LOGIN_PACKET* p = reinterpret_cast<CS_LOGIN_PACKET*>(packet);
		strcpy_s(clients[c_id]._name, p->name);



		if (c_id < 3)
		{
			//새로 접속한 플레이어에 현재 접속한 총 인원만큼 플레이어 객체 생성.
			for (int i = 0; i <= c_id; ++i)
			{
				clients[c_id].send_login_info(c_id, i);
			}
			cout << "client add order received" << endl;

			//새로 접속한 플레이어에게만 기존 접속자들+본인의 로그인 패킷 전송
			for (int i = 0; i <= c_id; ++i) // 모든 접속자의 정보 전달
			{
				if (clients[i]._use == false)
				{
					continue;
				}
				SC_ADD_PLAYER_PACKET pc;

				pc.id = c_id;
				strcpy_s(pc.name, p->name);
				pc.size = sizeof(pc);
				pc.type = PACKET_TYPE::SC_ADD_PLAYER;
				pc.kState = clients[i].kState;
				pc.bState = clients[i].bState;
				pc.camAngle = clients[i].cameraAngle;
				pc.camUp = clients[i].cameraUp;
				pc.pos = XMFLOAT3(100.0f + 5.0f * i, 0.0f, 100.0f);

				clients[c_id].do_send(&pc);
			}


			//기존 플레이어에게 새 플레이어 추가를 명령하는 패킷 전송,
			for (int i = 0; i <= c_id - 1; ++i)
			{

				if (clients[i]._use == false)
				{
					continue;
				}
				clients[i].send_login_info(i, c_id);
				SC_ADD_PLAYER_PACKET pc;
				//pc.id = clients[i]._id;
				pc.id = i;
				strcpy_s(pc.name, p->name);
				pc.size = sizeof(pc);
				pc.type = PACKET_TYPE::SC_ADD_PLAYER;
				clients[c_id].kState.xzspeed = 0.0f;
				clients[c_id].kState.yspeed = 0.0f;
				clients[c_id].kState.isMobile = true;
				clients[c_id].kState.isInAir = false;
				clients[c_id].kState.rotation = 0.0f;
				clients[c_id].kState.lastMove = std::chrono::system_clock::now();

				clients[c_id].bState.attackID = TYPE_RANGED;
				clients[c_id].bState.hp = 10;
				clients[c_id].bState.isIntelligent = true;
				clients[c_id].bState.stateID = IDLE_STATE;
				clients[c_id].bState.attacking = 0;
				clients[c_id].cameraAngle = 270.0f;
				clients[c_id].cameraUp = 0.0f;

				pc.kState = clients[c_id].kState;
				pc.bState = clients[c_id].bState;
				pc.camAngle = clients[c_id].cameraAngle;
				pc.camUp = clients[c_id].cameraUp;

				pc.pos = XMFLOAT3(100.0f + 5.0f * c_id, 0.0f, 100.0f);
				clients[i].do_send(&pc);
			}

		}
		break;
	}

	case PACKET_TYPE::CS_PARTICLE:
	{
		CS_PARTICLE_PACKET* p = reinterpret_cast<CS_PARTICLE_PACKET*>(packet);
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_particle(c_id, p->count, p->x,p->y,p->z, p->particleType);
				
			}
		}
		break;
	}

	case PACKET_TYPE::CS_POWER:
	{
		CS_POWER_PACKET* p = reinterpret_cast<CS_POWER_PACKET*>(packet);
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_stats(c_id, p->stats, p->mAttack, p->rAttack, p->mWeapon, p->rWeapon);
			}
		}
		break;
		
	}

	case PACKET_TYPE::CS_READY:
	{
		CS_READY_PACKET* p = reinterpret_cast<CS_READY_PACKET*>(packet);
		bool ready = p->ready;
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_ready(c_id, ready);
			}
		}
		break;
	}
	case PACKET_TYPE::CS_STATE:
	{
		CS_STATE_PACKET* p = reinterpret_cast<CS_STATE_PACKET*>(packet);
		

		BionicState b;
		b.attackID = p->attackID;
		b.stateID = p->stateID;
		b.attacking = -9999;
		b.hp = -9999;
		b.isIntelligent = -9999;

		for (auto& pl : clients)
		{
			if (pl._use == true)
			{	
				pl.send_bionic_change(c_id, b);	
			}
		}
		break;
	}
	case PACKET_TYPE::CS_POSITION:
	{
		CS_POSITION_PACKET* p = reinterpret_cast<CS_POSITION_PACKET*>(packet);
		float pa = p->angle;
		float px = p->x;
		float py = p->y;
		float pz = p->z;

		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_move(c_id, px, py, pz, pa);

			}
		}
		break;

		break;
	}

	case PACKET_TYPE::CS_KEYDOWN: 
	{
		//cout << "Key down received from " <<c_id<< endl;

		CS_KEYDOWN_PACKET* p = reinterpret_cast<CS_KEYDOWN_PACKET*>(packet);
		
		KineticState ks=clients[c_id].kState;
		BionicState bs=clients[c_id].bState;
		/*
		ks.yspeed = -9999.0f;
		ks.isInAir = -9999;
		ks.isMobile = -9999;
		ks.lastMove = chrono::system_clock::now();
		bs.hp = -9999;
		bs.attackID = -9999;
		bs.isIntelligent = -9999;
		*/


		if (p->key == VK_UP)
		{
			ks.rotation = clients[c_id].cameraAngle+180.0f;
			ks.xzspeed = PLAYER_SPEED;
			
			bs.stateID = MOVE_STATE;

			clients[c_id].kState.rotation = ks.rotation;
			clients[c_id].kState.xzspeed = PLAYER_SPEED;
			clients[c_id].bState.stateID = MOVE_STATE;


			

		}
		else if (p->key == VK_DOWN)
		{
			ks.rotation = clients[c_id].cameraAngle +0.0f;
			ks.xzspeed = PLAYER_SPEED;
			bs.stateID = MOVE_STATE;

			clients[c_id].kState.rotation = ks.rotation;
			clients[c_id].kState.xzspeed = PLAYER_SPEED;
			clients[c_id].bState.stateID = MOVE_STATE;
		}
		else if (p->key == VK_LEFT)
		{
			ks.rotation = clients[c_id].cameraAngle + 270.0f;
			ks.xzspeed = PLAYER_SPEED;
			bs.stateID = MOVE_STATE;

			clients[c_id].kState.rotation = ks.rotation;
			clients[c_id].kState.xzspeed = PLAYER_SPEED;
			clients[c_id].bState.stateID = MOVE_STATE;
		}
		else if (p->key == VK_RIGHT)
		{
			ks.rotation = clients[c_id].cameraAngle + 90.0f;
			ks.xzspeed = PLAYER_SPEED;
			bs.stateID = MOVE_STATE;

			clients[c_id].kState.rotation = ks.rotation;
			clients[c_id].kState.xzspeed = PLAYER_SPEED;
			clients[c_id].bState.stateID = MOVE_STATE;
		}

		else if (p->key == VK_SPACE)
		{
			for (auto& pl : clients)
			{
				if (pl._use == true)
				{
					pl.send_jump(c_id);
				}
			}
			break;
		}

		else if (p->key == '1')
		{
			if (bs.attackID != TYPE_MELEE && ks.isInAir==0)
			{
				bs.attackID = TYPE_MELEE;
				bs.stateID = IDLE_STATE;
				ks.xzspeed = 0.0f;
			}
		}
		else if (p->key == '2')
		{
			if (bs.attackID != TYPE_RANGED && ks.isInAir == 0)
			{
				bs.attackID = TYPE_RANGED;
				bs.stateID = IDLE_STATE;
				ks.xzspeed = 0.0f;
			}
		}
		else if (p->key == '3')
		{
			if (bs.attackID != TYPE_MICROWAVE && ks.isInAir == 0)
			{
				bs.attackID = TYPE_MICROWAVE;
				bs.stateID = IDLE_STATE;
				ks.xzspeed = 0.0f;
			}
		}
		else if (p->key == VK_F1)
		{
			for (auto& pl : clients)
			{
				if (pl._use == true)
				{
					pl.send_teleport(c_id, 175.0f,0.0f,25.0f);
				}
			}
			break;
		}
		else if (p->key == VK_F2)
		{
			for (auto& pl : clients)
			{
				if (pl._use == true)
				{
					pl.send_teleport(c_id, 210.0f, 0.0f, 190.0f);
				}
			}
			break;
		}
		else if (p->key == VK_F3)
		{
			for (auto& pl : clients)
			{
				if (pl._use == true)
				{
					pl.send_move(c_id, 297.0f, 6.0f, 25.0f, 0.0f);
					
				}
			}
			break;
		}
		else if (p->key == VK_F4)
		{
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_teleport(c_id, 850.0f, 0.0f, 550.0f);
			}
		}
		break;
		}

		if (ks.rotation >= 360.0f)
		{
			ks.rotation -= 360.0f;
		}
		if (ks.rotation < 0.0f)
		{
			ks.rotation += 360.0f;
		}
		
		clients[c_id].kState = ks;
		clients[c_id].bState = bs;

		KineticState ks2 = ks;
		//ks2.isInAir = -9999;
		//ks2.isMobile = -9999;
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_kinetic_change(c_id, ks2);
				pl.send_bionic_change(c_id, bs);
			}
		}
		break;
	}
	case PACKET_TYPE::CS_KEYUP:
	{
		
		CS_KEYUP_PACKET* p = reinterpret_cast<CS_KEYUP_PACKET*>(packet);

		KineticState ks=clients[c_id].kState;
		BionicState bs=clients[c_id].bState;


	//	cout << "Key up received: from "<<c_id;
		


		if (p->key == VK_UP)
		{
		//	cout << " Code: " << p->key << endl;
			ks.xzspeed = 0.0f;
			ks.yspeed = -9999.0f;
			bs.stateID = IDLE_STATE;

			clients[c_id].kState.xzspeed = 0.0f;
			clients[c_id].bState.stateID = IDLE_STATE;
		}
		else if (p->key == VK_DOWN)
		{
		//	cout << "Code: " << p->key << endl;
			ks.xzspeed = 0.0f;
			ks.yspeed = -9999.0f;
			bs.stateID = IDLE_STATE;

			clients[c_id].kState.xzspeed = 0.0f;
			clients[c_id].bState.stateID = IDLE_STATE;
		}
		else if (p->key == VK_LEFT)
		{
		//	cout << "Code: " << p->key << endl;
			ks.xzspeed = 0.0f;
			ks.yspeed = -9999.0f;
			bs.stateID = IDLE_STATE;

			clients[c_id].kState.xzspeed = 0.0f;
			clients[c_id].bState.stateID = IDLE_STATE;
		}
		else if (p->key == VK_RIGHT)
		{
			//cout << "Code: " << p->key << endl;
			ks.xzspeed = 0.0f;
			ks.yspeed = -9999.0f;
			bs.stateID = IDLE_STATE;

			clients[c_id].kState.xzspeed = 0.0f;
			clients[c_id].bState.stateID = IDLE_STATE;
		}
		else if (p->key == '2')
		{
		//	cout << "Code: " << p->key << endl;

			bs.attackID = TYPE_RANGED;
			clients[c_id].bState.attackID = TYPE_RANGED;
		}
		else if (p->key == '1')
		{
			//cout << "Code: " << p->key << endl;

			bs.attackID = TYPE_MELEE;
			clients[c_id].bState.attackID = TYPE_MELEE;
		}
		else if (p->key == '3')
		{
			//cout << "Code: " << p->key << endl;

			bs.attackID = TYPE_MICROWAVE;
			clients[c_id].bState.attackID = TYPE_MICROWAVE;
		}

		else if (p->key == VK_SPACE)
		{
			
		}
		KineticState ks2;
		BionicState bs2;
		bs2 = bs;
		ks2 = ks;
		ks2.isInAir = -9999;
		ks2.xzspeed = -9999.0f;
		ks2.yspeed = -9999.0f;
		ks2.isMobile = -9999;
		ks2.rotation = -9999.0f;



		clients[c_id].kState = ks;
		clients[c_id].bState = bs;
		

		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_kinetic_change(c_id, ks);
				pl.send_bionic_change(c_id, bs);
			}
		}
		break;
	}
	case PACKET_TYPE::CS_MOUSE:
	{
		//cout << "mouse msg received" << endl;
		CS_MOUSE_PACKET* p = reinterpret_cast<CS_MOUSE_PACKET*>(packet);
		
		BionicState bs=clients[c_id].bState;
		bs.hp = -9999;
		bs.attackID = -9999;
		bs.isIntelligent = -9999;
		bs.attacking = -9999;
		if (p->down == true)
		{
			//bs.stateID = ATTACK_STATE;
			//clients[c_id].bState.attackID = ATTACK_STATE;
			bs.attacking = 1;
		}
		else
		{
			//bs.stateID = IDLE_STATE;
			//clients[c_id].bState.attackID = IDLE_STATE;
			bs.attacking = 0;
		}
		clients[c_id].bState = bs;
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_bionic_change(c_id, bs);
			}
		}
		break;
	}
	case PACKET_TYPE::CS_CAMERA_CHANGE:
	{
		//cout << "mouse msg received" << endl;
		CS_CAMERA_PACKET* p = reinterpret_cast<CS_CAMERA_PACKET*>(packet);

		float tly = clients[c_id].cameraUp - p->camUp;
		if (tly <= 3.0f && tly >= -3.0f)
		{
			clients[c_id].cameraUp = tly;
		}
		float tangle = clients[c_id].cameraAngle - p->camAngle;
		if (tangle >= 360.0f)
		{
			tangle -= 360.0f;
		}
		if (tangle < 0.0f)
		{
			tangle += 360.0f;
		}
		clients[c_id].cameraAngle = tangle;
		KineticState ks = clients[c_id].kState;

		ks.rotation = clients[c_id].kState.rotation - p->camAngle;
		if (ks.rotation < 0.0f)
		{
			ks.rotation += 360.0f;
		}
		if (ks.rotation >= 360.0f)
		{
			ks.rotation -= 360.0f;
		}


		clients[c_id].kState = ks;
		KineticState ks2 = ks;
		ks2.xzspeed = -9999.0f;
		ks2.yspeed = -9999.0f;
		ks2.isInAir = -9999;
		ks2.isMobile = -9999;
		
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_camera_change(c_id, clients[c_id].cameraAngle, clients[c_id].cameraUp);
				ks2.rotation = -9999.0f;
				pl.send_kinetic_change(c_id, ks2);
			}
		}
		break;
	}
	case PACKET_TYPE::CS_ATTACK:
	{
		CS_ATTACK_PACKET* p = reinterpret_cast<CS_ATTACK_PACKET*>(packet);
		chrono::duration<double> dt = chrono::system_clock::now() - started;
		printf("%d번 적 : %d의 피해, %f초 기절 (%f 초)\n", p->target, p->damage, p->stuntime, dt.count());
		
		for (auto& pl : clients)
		{
			if (pl._use == true)
			{
				pl.send_damage(c_id, p->target, p->damage, p->stuntime);
			}
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

//void CALLBACK send_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED send_over,
//	DWORD f)
//{
//	EXP_OVER* ex_over = reinterpret_cast<EXP_OVER*>(send_over);
//	delete ex_over;
//}

//void CALLBACK recv_callback(DWORD err, DWORD num_bytes, LPWSAOVERLAPPED over, DWORD flags)
//{
//	auto client = reinterpret_cast<SESSION*>(over);
//	int client_id = client->_id;
//	SOCKET client_s = client->_socket;
//	auto ex_over = &client->_recv_over;
//
//	if (num_bytes == 0) {
//		cout << "Client disconnected\n";
//		clients.erase(client_id);
//		over_to_session.erase(over);
//		return;
//	};
//	cout << "Client " << client_id << " sent: " << clients[client_id]._c_mess << endl;
//	for (auto& cl : clients)
//		cl.second.do_send(num_bytes, clients[client_id]._c_mess, client_id);
//	clients[client_id].do_recv();
//}

int main(int argc, char* argv[])
{
	started = chrono::system_clock::now();
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
	CreateIoCompletionPort(reinterpret_cast<HANDLE>(server), h_iocp, 0, 0); //핸들 초기화

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
			int remain_data = num_bytes + clients[key]._prev_remain;
			char* p = ex_over->_send_buf;
			while (remain_data > 0) {
				int packet_size = p[0];
				if (packet_size <= remain_data) {
					process_packet(static_cast<int>(key), p);
					p = p + packet_size;
					remain_data = remain_data - packet_size;
				}
				else break;
			}
			clients[key]._prev_remain = remain_data;
			if (remain_data > 0) {
				memcpy(ex_over->_send_buf, p, remain_data);
			}
			clients[key].do_recv();
			//cout << "Recv Success.\n";

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
