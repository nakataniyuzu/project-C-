#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��(�퓬)
class CObjHeroBattle : public CObj
{
public:
	CObjHeroBattle() {};
	~CObjHeroBattle() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	int GetBATTLEHP() { return m_battle_hp; }
	int GetBATTLEMP() { return m_battle_mp; }
	int GetBATTLEMAGIC() { return m_battle_magic; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
private:
	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	int m_battle_hp;
	int m_battle_mp;
	int m_battle_magic;

	int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int   m_ani_frame;	//�`��t���[��

	float m_speed_power;	//�X�s�[�h�p���[
	float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

	//�e�X�g�p
	float px, py;		//��_
};

