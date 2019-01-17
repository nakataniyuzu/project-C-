#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g
class CObjEnemyMagicBattle : public CObj
{
	public:
		CObjEnemyMagicBattle(float x, float y);		//�R���X�g���N�^
		~CObjEnemyMagicBattle() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
		int GetDMG() { return m_damage; }//�U���͂��擾
		int GetHP() { return m_boss_hp; }//�̗͂��擾
		float GetPOS() { return m_posture; }//�{�X�̌������擾
	private:
		float m_x;		//X�����̈ʒu�p�ϐ�
		float m_y;		//Y�����̈ʒu�p�ϐ�
		float m_vx;		//X�����̑��x�p�ϐ�
		float m_vy;		//Y�����̑��x�p�ϐ�

		float m_hit;	//�Փ˔���
		float m_posture;	//����
		int m_time;		//���@�������鎞��
		int m_damage;
		int m_boss_hp;

		float m_bboss3_pos; //�{�X��������

		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_left;
		bool m_hit_right;

		int    m_ani;		//���e�A�j���[�V�����p
		int    m_ani_time;	//���e�A�j���[�V�����Ԋu�^�C��
		bool   m_del;		//�폜�`�F�b�N
		RECT_F m_eff;		//���e�G�t�F�N�g�`��p
};
