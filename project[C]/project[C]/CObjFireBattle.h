#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g
class CObjFireBattle : public CObj
{
	public:
		CObjFireBattle(float x, float y);		//�R���X�g���N�^
		~CObjFireBattle() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		float m_x;		//X�����̈ʒu�p�ϐ�
		float m_y;		//Y�����̈ʒu�p�ϐ�
		float m_vx;		//X�����̑��x�p�ϐ�
		float m_vy;		//Y�����̑��x�p�ϐ�

		float m_hit;	//�Փ˔���
		float posture;	//����
		int m_time;		//���@�������鎞��

		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_left;
		bool m_hit_right;

		int    m_ani;		//���e�A�j���[�V�����p
		int    m_ani_time;	//���e�A�j���[�V�����Ԋu�^�C��
		bool   m_del;		//�폜�`�F�b�N
		RECT_F m_eff;		//���e�G�t�F�N�g�`��p
};