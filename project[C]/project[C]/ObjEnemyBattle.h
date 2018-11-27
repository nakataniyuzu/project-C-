#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G(�퓬)
class CObjEnemyBattle : public CObj
{
public:
	CObjEnemyBattle() {};
	~CObjEnemyBattle() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	

private:
	float m_px;//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int   m_ani_frame;	//�`��t���[��
	int   m_enemy_hp;   //�G�̗̑�

	float m_speed_power;	//�X�s�[�h�p���[
	float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l
	float hero_posture;

	//����ł���block�̎�ނ��m�F�p
	int m_block_type;

	bool m_battle_flag;

	//�ړ��̌�������p
	bool m_move;
};
