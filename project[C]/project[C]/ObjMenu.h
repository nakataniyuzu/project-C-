#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�`��֌W�̒萔
#define MENU_RETURN_POS_X     (240)
#define MENU_RETURN_POS_Y     (200)
#define MENU_RETURN_FONT_SIZE (45)

#define MENU_END_POS_X		(260)
#define MENU_END_POS_Y      (310)
#define MENU_END_FONT_SIZE  (45)


//�I�u�W�F�N�g�F���j���[
class CObjMenu :public CObj
{
	public:
		CObjMenu() {};
		~CObjMenu() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		int choice;
		bool m_key_flag;

};