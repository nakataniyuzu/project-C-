#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
#include "ObjMessage.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjFireblock : public CObj
{
public:
	CObjFireblock(float x, float y);
	~CObjFireblock() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	float GetSWITCH(){ return m_switch; }

private:
	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��
	
	int m_time;			//�\�����鎞��
	int m_draw_time;
	//�`��؂�ւ��p
	int m_switch;

	bool m_battle_flag;
};


