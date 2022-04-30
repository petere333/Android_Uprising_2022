#pragma once

constexpr int MAX_PLAYER = 50;
constexpr int SERVERPORT = 9000;
constexpr int BUFSIZE = 1024;
constexpr int NAMESIZE = 20;

constexpr int W_WIDTH = 8;
constexpr int W_HEIGHT = 8;

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
	bool isKey;
	short c_id;

};

//server to client packet
struct SC_LOGIN_INFO_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	int x, y, z;
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
	UINT key;
};
struct SC_KEYUP_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	UINT key;
};


#pragma pack (pop)