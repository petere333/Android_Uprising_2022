#pragma once





//���� ������Ʈ ���̵�. ���� ������Ʈ�� ���� ��� �� ����� ������ �޶�����.
#define LOGIN_STATE 1
#define LOBBY_STATE 2
#define STAGE_SELECT_STATE 3
#define PROFILE_STATE 4
#define WAIT_STATE 5
#define IN_GAME_STATE 10




//�÷��̾��� ���� ���̵�.
#define IDLE_STATE 1
#define MOVE_STATE 2

#define MOVE_ATTACK_STATE 4
#define JUMP_STATE 5
#define DEATH_STATE 6

//���� ���� ���̵�.
#define PATROL_STATE 1
#define CHASE_STATE 2
#define BATTLE_STATE 4
#define DEAD_STATE 3
#define STUN_STATE 5

//��, �÷��̾��� ���� ���� ���̵�.
#define TYPE_MELEE 1
#define TYPE_RANGED 2
#define TYPE_MICROWAVE 3

// �� ������ �ɷ�ġ ��꿡 Ȱ��Ǵ� ���.
#define MELEE_HP 1.0f
#define MELEE_DAMAGE 1.1f
#define RANGED_HP 0.8f
#define RANGED_DAMAGE 1.3f
#define MICROWAVE_HP 1.2f
#define MICROWAVE_ATTACK 0.0f

// �� �ɷ�ġ ��꿡 ���Ǵ� ���̵��� ����ġ��.
#define EASY 150
#define NORMAL 200
#define HARD 300
#define EXTREME 500


// ��ü�� ����, ������ ��ü�� 0, �÷��̾� 1, �� 2
#define TYPE_NONE 0
#define TYPE_PLAYER 1
#define TYPE_ENEMY 2



//�÷��̾� �̵��ӵ�
//#define PLAYER_SPEED 3.55f
#define PLAYER_SPEED 3.55f

//���� IP ����


#define SERVERIP "127.0.0.1" // ����
//#define SERVERIP "192.168.35.85" // �� ��Ʈ��
//#define SERVERIP "192.168.35.197" // �� ��ž
//#define SERVERIP "172.20.10.5" // HOTSPOT

/*
	�÷��̾� �������� �ڷᱸ��.
	���� �ɷ�ġ�� ����ġ�� �����Ǿ� �ִ�.
	�� �ڷḦ ���� ���� ������ �������� ��� �͵��� ���ȴ�.

	������, ����, ���� �ӵ� ���� ������ ���� ����Ǵ� 
	���� ��Ʈ����Ʈ�̹Ƿ� �������� �ʴ´�.
*/



typedef struct PlayerData
{
	std::string nickname; // �г���

	int capacity;	//������
	int hardness;	//�浵
	int power;		//���
	int precision;	//���е�
	int entrophy;	//��������

	int melee_exp;	//���� ����ġ
	int ranged_exp;	//���� ����ġ
	int micro_exp;	//���� ����ġ

	int money;		//�������� ���ӸӴ�, �ٸ� �÷��̾��� ��� �ʿ���� �����̹Ƿ� -1
} PlayerData;


/* 
	�÷��̾� ���� ����. �� �����Ӹ��� �����ϹǷ� 
	�÷��̾ ��Ÿ���� �� �ʿ��� �ּ����� ���븸 �־���.
*/
typedef struct PlayerState
{

	int id = -1;								// ���� ���̵�
	int currHP;									// ���� ������
	int attType;								// ���� ���� ����
	float timeElapsed=0.0f;						// �� ���·� ����� �� �󸶳� ������?
	

}PlayerState;

/*
	����ġǥ. �÷��̾� ������ ����� �� for���� ������ ����Ѵ�.
	���� �ε������� ���� ������ ����ġ �ʿ䷮�� ����.
	��, 0��° �ε������� 1�������� 2������ ������ �ϴ� �� �ʿ��� ����ġ�� ����ȴ�.
*/
static int mode_exp_table[29];		// �� ��庰 ����ġǥ, ������ 30
static int total_exp_table[49];	// �÷��̾� ����ġǥ, ������ 50

typedef struct EnemyData
{
public:
	int hp;		//���� ������.
	int damage;	//���ط�
	int type;	//���� ����. TYPE_MELEE, RANGED, MICROWAVE�� ����.
}EnemyData;

typedef struct EnemyState
{
public:
	int id=-1;					// ���� ���� ���̵�.
	int currHP = -1;			// ���� ������.

	float timeElapsed = 0.0f;	// �� ���·� ����� �� �󸶳� ������?
}EnemyState;


static std::vector<PlayerState> players_states_list;	// �Բ� ������ �÷��̾���� ���� ���� ����.
												// �� �����Ӹ��� �������� ���۹޾� �����Ѵ�.
												

static std::vector<PlayerData> players_datas_list;		// �Բ� ������ �÷��̾���� ���� ����
												// ó�� ���� ���ӽÿ� �����Ѵ�.


/*
	ȸ�� ���� �ڷᱸ��. �α��� �� ����Ѵ�.
	�ùٸ� ���̵� �н������ �α����ϸ�
	�ش��ϴ� �÷��̾��� ������ ���� �� �ִ�.
*/
typedef struct MemberData
{
	std::string id, password; //���̵� ���
	PlayerData pData;
}MemberData;