#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjBoss : public CObj
{
	public:
		CObjBoss(float x, float y);
		~CObjBoss() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

	private:
		float m_px;			//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;
		bool m_battle_flag;	//�o�g���؂�ւ��p
		bool m_boss_battle_f;	//�{�X��p�t���O

};
