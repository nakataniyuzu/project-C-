#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�`��֌W�̒萔
#define TITLE_POS_X		(120)
#define	TITLE_POS_Y		(80)
#define TITLE_FONT_SIZE	(100)
#define TITLE_ADV_POS_X		(480)
#define	TITLE_ADV_POS_Y		(200)
#define TITLE_ADV_FONT_SIZE	(80)


#define GAME_START_POS_X		(300)
#define GAME_START_POS_Y		(390)
#define GAME_START_FONT_SIZE	(30)
#define GAME_END_POS_X			(300)
#define GAME_END_POS_Y			(440)
#define GAME_END_FONT_SIZE		(30)

//�I�u�W�F�N�g�F�^�C�g��
class CObjTitle :public CObj
{
	public:
		CObjTitle() {};
		~CObjTitle() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[

	private:
		int choice;
		bool m_key_flag;
};

