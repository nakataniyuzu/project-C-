#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjHeal : public CObj
{
public:
	CObjHeal(float x, float y);
	~CObjHeal() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

private:
	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;

	int m_time;			//�\�����鎞��

	bool m_battle_flag;

	float fire;	//�΂������Ă��邩�̔���p

};
