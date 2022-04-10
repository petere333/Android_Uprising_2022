#pragma once
#include "stdafx.h"


//���� ������Ʈ ���̵�. ���� ������Ʈ�� ���� ��� �� ����� ������ �޶�����.
#define LOGIN_STATE 1
#define IN_GAME_STATE 10


//�÷��̾��� ���� ���̵�.
#define IDLE_STATE 1
#define MOVE_STATE 2
#define ATTACK_STATE 3
#define MOVE_ATTACK_STATE 4
#define DEATH_STATE 5

//���� ���� ���̵�.
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


/*
	ȸ�� ���� �ڷᱸ��. �α��� �� ����Ѵ�.
	�ùٸ� ���̵� �н������ �α����ϸ� 
	�ش��ϴ� �÷��̾��� ������ ���� �� �ִ�.
*/
class MemberData
{
public:
	std::string id, password; //���̵� ���
	PlayerData pData;
};



/*
	�÷��̾� �������� �ڷᱸ��.
	���� �ɷ�ġ�� ����ġ�� �����Ǿ� �ִ�.
	�� �ڷḦ ���� ���� ������ �������� ��� �͵��� ���ȴ�.

	������, ����, ���� �ӵ� ���� ������ ���� ����Ǵ� 
	���� ��Ʈ����Ʈ�̹Ƿ� �������� �ʴ´�.
*/
class PlayerData
{
public:
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
};


/* 
	�÷��̾� ���� ����. �� �����Ӹ��� �����ϹǷ� 
	�÷��̾ ��Ÿ���� �� �ʿ��� �ּ����� ���븸 �־���.
*/
class PlayerState
{
public:
	int id = -1;								// ���� ���̵�
	int currHP;									// ���� ������
	float currX=0.0f, currY=0.0f, currZ=0.0f;	// ���� ��ġ
	float timeElapsed=0.0f;						// �� ���·� ����� �� �󸶳� ������?

};

/*
	����ġǥ. �÷��̾� ������ ����� �� for���� ������ ����Ѵ�.
	���� �ε������� ���� ������ ����ġ �ʿ䷮�� ����.
	��, 0��° �ε������� 1�������� 2������ ������ �ϴ� �� �ʿ��� ����ġ�� ����ȴ�.
*/
int mode_exp_table[29];		// �� ��庰 ����ġǥ, ������ 30
int total_exp_table[49];	// �÷��̾� ����ġǥ, ������ 50


class EnemyData
{
public:
	int hp;		//���� ������.
	int damage;	//���ط�
	int type;	//���� ����. TYPE_MELEE, RANGED, MICROWAVE�� ����.
};

class EnemyState
{
public:
	int id=-1;					// ���� ���� ���̵�.
	int currHP = -1;			// ���� ������.
	float currX = 0.0f;			// ���� ��ġ X.
	float currY = 0.0f;			// ���� ��ġ Y.
	float currZ = 0.0f;			// ���� ��ġ Z.
	float timeElapsed = 0.0f;	// �� ���·� ����� �� �󸶳� ������?
};


std::vector<PlayerState> players_states_list;	// �Բ� ������ �÷��̾���� ���� ���� ����.
												// �� �����Ӹ��� �������� ���۹޾� �����Ѵ�.
												

std::vector<PlayerData> players_datas_list;		// �Բ� ������ �÷��̾���� ���� ����
												// ó�� ���� ���ӽÿ� �����Ѵ�.