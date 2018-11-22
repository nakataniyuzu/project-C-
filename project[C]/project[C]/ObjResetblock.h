#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjResetblock : public CObj
{
public:
	CObjResetblock(float x, float y);
	~CObjResetblock() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	int m_map[27][55];	//�}�b�v���

	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	int	m_ani_time;
	int m_ani_frame;
	int m_time;			//�\�����鎞��

			//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�ړ��̌�������p
	bool m_move;

	int m_block_type;


};
