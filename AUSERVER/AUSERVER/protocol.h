#pragma once

constexpr int MAX_PLAYER = 50;
constexpr int SERVERPORT = 9000;
constexpr int BUFSIZE = 1024;
constexpr int NAMESIZE = 20;

constexpr int W_WIDTH = 100;
constexpr int W_HEIGHT = 100;

// Packet Type


struct KineticState
{
	int isMobile;
	float rotation;
	float yspeed;
	float xzspeed;
	int isInAir;
	std::chrono::system_clock::time_point lastMove;
};

struct BionicState
{
	int isIntelligent;
	int stateID;
	int attackID;
	int hp;
};

enum class PACKET_TYPE : short
{
	//client to server
	CS_LOGIN = 0,
	CS_KEYDOWN = 1,
	CS_KEYUP = 2,
	CS_MOUSE = 3,

	//server to client
	SC_LOGIN_INFO = 4,
	SC_ADD_PLAYER = 5,
	SC_REMOVE_PLAYER = 6,
	SC_KINETIC_CHANGE = 7,
	SC_BIONIC_CHANGE=8,
	
};

// client to server packet
#pragma pack (push, 1)

struct KEYDOWN_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	UINT key;
	short c_id;
};
struct KEYUP_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	UINT key;
	short c_id;
};

struct MOUSE_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	bool down;
	short c_id;
};
struct KINETIC_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short c_id;
	KineticState kState;
};

struct BIONIC_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short c_id;
	BionicState bState;
};

struct CS_LOGIN_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	char	name[NAMESIZE];
};

struct CS_MOVE_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	float tx, ty, tz;
	short direction;  // 0 : UP, 1 : DOWN, 2 : LEFT, 3 : RIGHT
	bool isKey;
	short c_id;

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
	char	name[NAMESIZE];
	KineticState kState;
	BionicState bState;
	float cam;
};

struct SC_REMOVE_PLAYER_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
};

struct SC_KEYDOWN_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	float x, y, z;

	//float cx, cy, cz; //camera

	//weaponType
	UINT key;
};
struct SC_KEYUP_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	UINT key;
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