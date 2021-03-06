#pragma once

#include "../../졸업작품 프로젝트-3/PlayerInfoManager.h"

constexpr int MAX_PLAYER = 50;
//constexpr int SERVERPORT = 49664;
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
	int isIntelligent=false;
	int stateID = 1;
	int attackID = 2;
	int hp;
	int attacking=0;
	//PlayerInfoManager* manager;
};

enum class PACKET_TYPE : short
{
	//client to server
	CS_LOGIN = 0,
	CS_KEYDOWN,
	CS_KEYUP,
	CS_MOUSE,
	CS_CAMERA_CHANGE,
	CS_ATTACK,
	CS_POSITION,
	CS_STATE,
	CS_READY,
	CS_POWER,
	CS_PARTICLE,
	CS_MISSION,
	CS_LOCATION,
	//server to client
	SC_LOGIN_INFO,
	SC_ADD_PLAYER,
	SC_REMOVE_PLAYER,
	SC_MOVE_PLAYER,
	SC_KINETIC_CHANGE,
	SC_BIONIC_CHANGE,
	SC_CAMERA_CHANGE,
	SC_ATTACK,
	SC_JUMP,
	SC_TELEPORT,
	SC_POSITION,
	SC_READY,
	SC_STATE,
	SC_POWER,
	SC_PARTICLE,
	SC_MISSION,
	SC_LOCATION,
};

// client to server packet
#pragma pack (push, 1)

struct CS_LOCATION_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	float x;
	float z;
};


struct CS_MISSION_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	int number;
	int progress;
	int target;
};
struct SC_MISSION_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	int number;
	int progress;
	int target;
};

struct CS_PARTICLE_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	int count;
	float xdir;
	float zdir;
	float x;
	float y;
	float z;

	int particleType;
};
struct SC_PARTICLE_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	int count;
	float x;
	float y;
	float z;

	float xdir;
	float zdir;

	int particleType;
};


struct CS_KEYDOWN_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	UINT key;
	short c_id;
};

struct CS_POWER_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short c_id;

	Stats stats;
	int mAttack;
	int rAttack;

	int mWeapon;
	int rWeapon;
};

struct SC_POWER_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short c_id;

	Stats stats;
	int m;
	int r;
	int mw;
	int rw;

};

struct CS_KEYUP_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	UINT key;
	short c_id;
};

struct CS_MOUSE_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	bool down;
	short c_id;

	int attackID;
};



struct CS_CAMERA_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	float camAngle;
	float camUp;
	short c_id;
};

struct SC_CAMERA_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	float camAngle;
	float camUp;
	short c_id;
};

struct SC_KINETIC_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short c_id;
	KineticState kState;
};

struct SC_BIONIC_PACKET
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

struct CS_ATTACK_PACKET
{
	unsigned char size;
	PACKET_TYPE	type;
	short id;
	int target;
	int damage;
	float stuntime;
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
	float camAngle;
	float camUp;
	XMFLOAT3 pos;
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
	float cx, cy, cz; //camera

	//weaponType
	UINT key;
};
struct SC_KEYUP_PACKET {
	unsigned char size;
	PACKET_TYPE	type;
	short	id;
	UINT key;
};


struct SC_UPDATE_PACKET { // 수정중
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

struct SC_ATTACK_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;
	
	int target;
	int damage;
	float stuntime;
};

struct SC_JUMP_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;
};
struct SC_TELEPORT_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;
	float x, y, z;
};

struct CS_POSITION_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short c_id;
	float angle;
	float x;
	float y;
	float z;


};
struct CS_STATE_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	int stateID;
	int attackID;
};
struct SC_STATE_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	int stateID;
	int attackID;
};

struct SC_POSITION_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;
	float angle;
	float x, y, z;

	int attackid;
};
struct CS_READY_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	bool ready;
};
struct SC_READY_PACKET
{
	unsigned char size;
	PACKET_TYPE type;
	short id;

	bool ready;
};

#pragma pack (pop)

