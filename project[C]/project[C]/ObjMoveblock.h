#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjMoveblock : public CObj
	{
	public:
		CObjMoveblock(float x, float y);
		~CObjMoveblock() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }

	private:
		float m_px;			//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;
		float m_posture;	//�p��

		int key;	//���p�ϐ�

		int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
		int   m_ani_frame;	//�`��t���[��

		float m_speed_power;	//�X�s�[�h�p���[
		float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		//�ړ��̌�������p
		bool m_move;

};
