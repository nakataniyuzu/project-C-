#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G(�퓬�F2�w��)
class CObjEnemy2Battle : public CObj
{
	public:
		CObjEnemy2Battle() {};
		~CObjEnemy2Battle() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		void SetENEMYDELETE(bool x) { enemy_delete_flag = x; }	//�G���ŗp
		int GetDMG() {  return m_damage; }//�U���͂��擾

	private:
		float m_px;//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;
		float m_posture;	//�p��
		bool m_pop_flag;	//���X�ʒu�̏������p

		int m_ani_time;	//�A�j���[�V�����t���[������Ԋu
		int m_ani_frame;	//�`��t���[��
		int m_enemy_hp;   //�G�̗̑�
		int m_damage;		//�G�̍U����

		float m_speed_power;	//�X�s�[�h�p���[
		float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l
		float m_hero_posture;
		
		int m_time;		//�G���S���̃t�F�C�h�C���ڍs�p�Ԋu��
		int m_ani;			//���S�A�j���[�V�����p
		int m_ani_time_d;	//���S�A�j���[�V�����Ԋu�^�C��
		bool m_del;			//�폜�`�F�b�N
		RECT_F m_eff;		//���S�G�t�F�N�g�`��p

		int m_subtract;			//���e�X�g
		int m_hero_position;	//���e�X�g2

		//����ł���block�̎�ނ��m�F�p
		int m_block_type;

		bool m_battle_flag;
		bool m_boss_flag;

		bool m_eff_flag;	//�G�t�F�N�g�p�t���O

		bool enemy_delete_flag;	//�G���ŗp

		//�ړ��̌�������p
		bool m_move;
};

