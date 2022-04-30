#pragma once

constexpr int MAX_PLAYER = 50;
constexpr int SERVERPORT = 9000;
constexpr int BUFSIZE = 1024;
constexpr int NAMESIZE = 20;

constexpr int W_WIDTH = 100;
constexpr int W_HEIGHT = 100;

// Packet Type

enum class PACKET_TYPE : short
{
	//client to server
	CS_LOGIN = 0,
	CS_MOVE = 1,

	//server to client
	SC_LOGIN_INFO = 2,
	SC_ADD_PLAYER = 3,
	SC_REMOVE_PLAYER = 4,
	SC_MOVE_PLAYER = 5,
};

// client to server packet
#pragma pack (push, 1)

struct CS_LOGIN_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	char	name[NAMESIZE];
};

struct CS_MOVE_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short direction;  // 0 : UP, 1 : DOWN, 2 : LEFT, 3 : RIGHT
	bool isKey;
	short c_id;
	//int tx;
	//int ty;
	//int tz;

};

//server to client packet
struct SC_LOGIN_INFO_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	bool isLogin;
	float x, y, z;
};

struct SC_ADD_PLAYER_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	float x, y, z;
	char	name[NAMESIZE];
};

struct SC_REMOVE_PLAYER_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
};

struct SC_MOVE_PLAYER_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	float x, y, z;

	//float cx, cy, cz; //camera

	//weaponType
};

struct SC_MOUSE_PACKET {
	unsigned char size;
	PACKET_TYPE type;

	int p_RotateY;
	int C_RotateY;
	int CameraOffset;
};


struct SC_UPDATE_PACKET { // ������
	unsigned char size;
	PACKET_TYPE type;
	int player;
	short id[MAX_PLAYER];
	
	int X[MAX_PLAYER];
	int Y[MAX_PLAYER];
	int Z[MAX_PLAYER];
	
	int CX[MAX_PLAYER];
	int CY[MAX_PLAYER];
	int CZ[MAX_PLAYER];
};

#pragma pack (pop)