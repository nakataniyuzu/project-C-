#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define TIME_INTERVAL 1000

//�I�u�W�F�N�g�F��l��
class CObjEnemyboss2 : public CObj
{
public:
	CObjEnemyboss2(float x, float y);
	~CObjEnemyboss2() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:
	float m_px;			//�ʒu
	float m_py;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool battle_flag;		//�o�g���ڍs�p
	bool hero_posture;		//��l���̌���

	int   m_time;

};
