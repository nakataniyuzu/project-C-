#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjSister : public CObj
{
public:
	CObjSister(float x, float y);
	~CObjSister() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:
	float m_px;			//�ʒu
	float m_py;
	
	int m_drawt1;	//�����\������
	int m_drawt2;
	bool m_change;//�摜�؂�ւ��p
};
