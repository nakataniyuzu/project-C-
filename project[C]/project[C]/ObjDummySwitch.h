#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjDummySwitch : public CObj
{
public:
	CObjDummySwitch(float x, float y);
	~CObjDummySwitch() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	bool GetCHANGE() { return m_change; }

private:
	float m_px;			//�ʒu
	float m_py;
	bool m_change;		//�摜�؂�ւ��p
	int m_time;		//���b�Z�[�W�\���p
};
