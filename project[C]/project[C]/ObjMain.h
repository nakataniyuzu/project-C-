#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�`��֌W�̒萔
#define GAME_LEVEL_POS_X     (0)
#define GAME_LEVEL_POS_Y     (0)
#define GAME_LEVEL_FONT_SIZE (25)

#define GAME_NAME_POS_X     (100)
#define GAME_NAME_POS_Y     (0)
#define GAME_NAME_FONT_SIZE (25)

#define GAME_HP_POS_X     (0)
#define GAME_HP_POS_Y     (25)
#define GAME_HP_FONT_SIZE (25)

#define GAME_MP_POS_X     (170)
#define GAME_MP_POS_Y     (25)
#define GAME_MP_FONT_SIZE (25)

#define GAME_INVENTORY_POS_X     (300)
#define GAME_INVENTORY_POS_Y     (0)
#define GAME_INVENTORY_FONT_SIZE (25)

#define GAME_MENU_POS_X     (300)
#define GAME_MENU_POS_Y     (25)
#define GAME_MENU_FONT_SIZE (25)

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
		
		void SetENEMYKILLS(int x) { enemy_kills += x; }	//�G�̌��j���̃J�E���g���擾

	private:
		int hero_max_hp;	//HP�ő�l
		int hero_max_mp;	//MP�ő�l

		int hero_hp;	//HP
		int hero_mp;	//MP
		int magic_type;	//���@�̎��
		int key;		//�����������Ă��邩

		int enemy_kills = 0;//�G�̌��j��
};
