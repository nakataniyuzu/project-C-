#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g
class CObjFire : public CObj
{
	public:
		CObjFire(float x, float y);		//�R���X�g���N�^
		~CObjFire() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		float m_x;		//X�����̈ʒu�p�ϐ�
		float m_y;		//Y�����̈ʒu�p�ϐ�
		float m_vx;		//X�����̑��x�p�ϐ�
		float m_vy;		//Y�����̑��x�p�ϐ�

		float m_hit;	//�Փ˔���
		float m_posture;	//����
		int m_time;		//���@�������鎞��
		int m_draw_time;	//�\�����鎞��

		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

};