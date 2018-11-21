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

	float GetX() { return g_enemy_px; }
	float GetY() { return g_enemy_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetBT() { return m_block_type; }

	void SetX(float x) { g_enemy_px = x; }
	void SetY(float y) { g_enemy_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	void SetBT(int t) { m_block_type = t; }

private:
	float g_enemy_px;//�ʒu
	float g_enemy_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int   m_ani_frame;	//�`��t���[��
	int   m_enemy_hp;   //�G�̗̑�

	float m_speed_power;	//�X�s�[�h�p���[
	float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

	//����ł���block�̎�ނ��m�F�p
	int m_block_type;

	//�e�X�g�p
	float px, py;		//��_

	//�ړ��̌�������p
	bool m_move;
};
