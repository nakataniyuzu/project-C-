#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�`��֌W�̒萔
#define GAME_HP_POS_X     (0)
#define GAME_HP_POS_Y     (0)
#define GAME_HP_FONT_SIZE (25)

#define GAME_MP_POS_X     (0)
#define GAME_MP_POS_Y     (25)
#define GAME_MP_FONT_SIZE (25)

#define GAME_MESSAGE_POS_X     (200)
#define GAME_MESSAGE_POS_Y     (0)
#define GAME_MESSAGE_FONT_SIZE (20)

#define GAME_MESSAGE2_POS_X     (200)
#define GAME_MESSAGE2_POS_Y     (25)
#define GAME_MESSAGE2_FONT_SIZE (20)

#define GAME_ENEMY_KILLS_POS_X     (610)
#define GAME_ENEMY_KILLS_POS_Y     (15)
#define GAME_ENEMY_KILLS_FONT_SIZE (25)


//�I�u�W�F�N�g�F���j���[
class CObjMain :public CObj
{
	public:
		CObjMain() {};
		~CObjMain() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
		
	private:
		int hero_max_hp;	//HP�ő�l
		int hero_max_mp;	//MP�ő�l

		int hero_hp;	//HP
		int hero_mp;	//MP
		int magic_type;	//���@�̎��
		int key;		//�����������Ă��邩
		bool battle_flag;	//�o�g����ʂ��ǂ���

		float m_and;		//�����x�����p
		bool m_andf;		//�����x�����p�t���O
};
