#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�`��֌W�̒萔
#define CLEAR_POS_X		(120)
#define	CLEAR_POS_Y		(80)
#define CLEAR_FONT_SIZE	(100)
#define CLEAR_ADV_POS_X		(480)
#define	CLEAR_ADV_POS_Y		(200)
#define CLEAR_ADV_FONT_SIZE	(80)


#define GAME_START_POS_X		(300)
#define GAME_START_POS_Y		(390)
#define GAME_START_FONT_SIZE	(30)
#define GAME_END_POS_X			(300)
#define GAME_END_POS_Y			(440)
#define GAME_END_FONT_SIZE		(30)

//�I�u�W�F�N�g�F�^�C�g��
class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

private:
	int choice;
	int m_time;		//�L�[�̓��͎��ԊԊu
	bool m_key_flag;
};

