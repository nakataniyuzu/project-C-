#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//ITEM�FICE
class CObjItemWind : public CObj
{
public:
	CObjItemWind(float x, float y);
	~CObjItemWind() {};
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
};
