#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjGate : public CObj
{
public:
	CObjGate(float x, float y);
	~CObjGate() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:
	float m_px;			//�ʒu
	float m_py;

	float m_f;		//�����J�������̔���
	int m_time;			//�\�����鎞��
	int m_draw_time;
	int key;	//��
};

