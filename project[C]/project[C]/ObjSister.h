#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define TIME_INTERVAL 1000

//�I�u�W�F�N�g�F��l��
class CObjSister : public CObj
{
public:
	CObjSister(float x, float y);
	~CObjSister() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	float GetVx() { return m_vx; }
	float GetVy() { return m_vy; }

private:
	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	bool battle_flag;	//�o�g���؂�ւ��p
	bool boss_battle_flag; //�{�X��؂�ւ��p
};
