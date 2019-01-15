#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G(�퓬�F3�w��)
class CObjEnemy3Battle : public CObj
{
	public:
		CObjEnemy3Battle() {};
		~CObjEnemy3Battle() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		int GetDMG() { return m_damage; }//�U���͂��擾
		int GetPOS() { return m_posture; }//�����擾��

	private:
		float m_px;//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;
		float m_posture;	//�p��

		int m_ani_time;	//�A�j���[�V�����t���[������Ԋu
		int m_ani_frame;	//�`��t���[��
		int m_enemy_hp;   //�G�̗̑�
		int m_damage;		//�G�̍U����

		float m_speed_power;	//�X�s�[�h�p���[
		float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l
		float m_hero_posture;

		int m_subtract;			//���e�X�g
		int m_hero_position;	//���e�X�g2

		float m_time_j;		//�W�����v�e�X�g

		//����ł���block�̎�ނ��m�F�p
		int m_block_type;

		bool m_battle_flag;
		bool m_boss_flag;

		//�ړ��̌�������p
		bool m_move;
};


