#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G(�퓬)
class CObjBoss3Battle : public CObj
{
	public:
		CObjBoss3Battle() {};
		~CObjBoss3Battle() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		void SetBOSSDELETE(bool x) { boss_delete_flag = x; }
		int GetDMG() { return m_damage; }//�U���͂��擾
		float GetPOS() { return m_posture; }//�{�X�̌������擾

	private:
		float m_px;			//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;
		float m_posture;	//�p��

		int m_ani_time;	//�A�j���[�V�����t���[������Ԋu
		int m_ani_frame;	//�`��t���[��
		int m_boss_hp;   //�G�̗̑�
		int m_damage;

		float m_speed_power;	//�X�s�[�h�p���[
		float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l
		float hero_posture;
		float m_directionx; //���@���˗pX����
		float m_directiony; //���@���˗pY����

		int m_time;	//�ːi����
		int m_delay;

					//����ł���block�̎�ނ��m�F�p
		int m_block_type;

		bool m_boss_flag;	//�{�X�퓬�p�t���O
		bool enemy_flag;	//�G�폜�p
		bool boss_delete_flag;	//�{�X�폜�p
		bool m_pop_flag;	//�{�X�̏o���ʒu�p
							//�ړ��̌�������p
		bool m_move;
};


