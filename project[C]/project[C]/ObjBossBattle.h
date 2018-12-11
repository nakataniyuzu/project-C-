#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G(�퓬)
class CObjBossBattle : public CObj
{
public:
	CObjBossBattle() {};
	~CObjBossBattle() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void SetBOSSDELETE(bool x) { boss_delete_flag = x; }

private:	
	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int   m_ani_frame;	//�`��t���[��
	int   m_boss_hp;   //�G�̗̑�

	float m_speed_power;	//�X�s�[�h�p���[
	float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l
	float hero_posture;

	int m_time;	//�ːi����
	//����ł���block�̎�ނ��m�F�p
	int m_block_type;

	bool m_boss_flag;	//�{�X�퓬�p�t���O
	bool enemy_flag;	//�G�폜�p
	bool boss_delete_flag;	//�{�X�폜�p
	bool m_pop_flag;	//�{�X�̏o���ʒu�p
	//�ړ��̌�������p
	bool m_move;
};

