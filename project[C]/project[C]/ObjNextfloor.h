#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjNextfloor :public CObj
{
public:
	CObjNextfloor() {};
	~CObjNextfloor() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

private:
	int m_floor;		//���w�ڂ��𕪂���ϐ�
	float m_time;			//n�w�ڂ̕\���A�j���[�V�����p
	int m_next_time;	//���֐i�ނ܂ł̑ҋ@����
	float m_and;		//�����x�����p
	bool m_andf;		//�����x�����p�t���O
	bool m_keyf;		//�L�[����t���O
};