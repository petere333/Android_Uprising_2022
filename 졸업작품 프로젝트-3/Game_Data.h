#pragma once





//게임 스테이트 아이디값. 현재 스테이트에 따라 계산 및 출력할 내용이 달라진다.
#define LOGIN_STATE 1
#define LOBBY_STATE 2
#define STAGE_SELECT_STATE 3
#define PROFILE_STATE 4
#define WAIT_STATE 5
#define IN_GAME_STATE 10




//플레이어의 상태 아이디값.
#define IDLE_STATE 1
#define MOVE_STATE 2

#define MOVE_ATTACK_STATE 4
#define JUMP_STATE 5
#define DEATH_STATE 6

//적의 상태 아이디값.
#define PATROL_STATE 1
#define CHASE_STATE 2
#define BATTLE_STATE 4
#define DEAD_STATE 3
#define STUN_STATE 5

//적, 플레이어의 공격 유형 아이디값.
#define TYPE_MELEE 1
#define TYPE_RANGED 2
#define TYPE_MICROWAVE 3

// 적 유형별 능력치 계산에 활용되는 상수.
#define MELEE_HP 1.0f
#define MELEE_DAMAGE 1.1f
#define RANGED_HP 0.8f
#define RANGED_DAMAGE 1.3f
#define MICROWAVE_HP 1.2f
#define MICROWAVE_ATTACK 0.0f

// 적 능력치 계산에 사용되는 난이도별 가중치값.
#define EASY 150
#define NORMAL 200
#define HARD 300
#define EXTREME 500


// 객체의 유형, 고정된 물체는 0, 플레이어 1, 적 2
#define TYPE_NONE 0
#define TYPE_PLAYER 1
#define TYPE_ENEMY 2



//플레이어 이동속도
//#define PLAYER_SPEED 3.55f
#define PLAYER_SPEED 3.55f

//서버 IP 정보


#define SERVERIP "127.0.0.1" // 셀프
//#define SERVERIP "192.168.35.85" // 집 노트북
//#define SERVERIP "192.168.35.197" // 집 데탑
//#define SERVERIP "172.20.10.5" // HOTSPOT

/*
	플레이어 세부정보 자료구조.
	각종 능력치와 경험치로 구성되어 있다.
	이 자료를 통해 게임 내에서 벌어지는 모든 것들이 계산된다.

	데미지, 레벨, 공격 속도 등은 공식을 통해 산출되는 
	유도 애트리뷰트이므로 포함하지 않는다.
*/



typedef struct PlayerData
{
	std::string nickname; // 닉네임

	int capacity;	//내구도
	int hardness;	//경도
	int power;		//출력
	int precision;	//정밀도
	int entrophy;	//무질서도

	int melee_exp;	//돌격 경험치
	int ranged_exp;	//포격 경험치
	int micro_exp;	//전파 경험치

	int money;		//보유중인 게임머니, 다른 플레이어의 경우 필요없는 정보이므로 -1
} PlayerData;


/* 
	플레이어 상태 정보. 매 프레임마다 갱신하므로 
	플레이어를 나타내는 데 필요한 최소한의 내용만 넣었다.
*/
typedef struct PlayerState
{

	int id = -1;								// 상태 아이디값
	int currHP;									// 현재 내구도
	int attType;								// 현재 공격 유형
	float timeElapsed=0.0f;						// 이 상태로 변경된 지 얼마나 지났나?
	

}PlayerState;

/*
	경험치표. 플레이어 레벨을 계산할 때 for문을 돌려서 사용한다.
	낮은 인덱스에는 낮은 레벨의 경험치 필요량이 들어간다.
	즉, 0번째 인덱스에는 1레벨에서 2레벨로 레벨업 하는 데 필요한 경험치가 저장된다.
*/
static int mode_exp_table[29];		// 각 모드별 경험치표, 만렙은 30
static int total_exp_table[49];	// 플레이어 경험치표, 만렙은 50

typedef struct EnemyData
{
public:
	int hp;		//현재 내구도.
	int damage;	//피해량
	int type;	//적의 유형. TYPE_MELEE, RANGED, MICROWAVE로 구별.
}EnemyData;

typedef struct EnemyState
{
public:
	int id=-1;					// 현재 상태 아이디값.
	int currHP = -1;			// 현재 내구도.

	float timeElapsed = 0.0f;	// 이 상태로 변경된 지 얼마나 지났나?
}EnemyState;


static std::vector<PlayerState> players_states_list;	// 함께 입장한 플레이어들의 현재 상태 정보.
												// 매 프레임마다 서버에서 전송받아 갱신한다.
												

static std::vector<PlayerData> players_datas_list;		// 함께 입장한 플레이어들의 세부 정보
												// 처음 게임 접속시에 저장한다.


/*
	회원 정보 자료구조. 로그인 시 사용한다.
	올바른 아이디 패스워드로 로그인하면
	해당하는 플레이어의 정보를 얻을 수 있다.
*/
typedef struct MemberData
{
	std::string id, password; //아이디 비번
	PlayerData pData;
}MemberData;