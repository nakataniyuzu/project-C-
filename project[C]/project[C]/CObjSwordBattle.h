#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g
class CObjSwordBattle : public CObj
{
public:
	CObjSwordBattle(float x, float y);		//�R���X�g���N�^
	~CObjSwordBattle() {};
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

	int m_ani_frame_x;	//�A�j���[�V�����p�ϐ�
	int m_ani_frame_y;

	int m_sword_time;		//���������鎞��

	int m_time;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_left;
	bool m_hit_right;
};
