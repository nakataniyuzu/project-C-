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

	float GetX() { return m_px; }		//��l����X�ʒu���擾
	float GetY() { return m_py; }		//��l����Y�ʒu���擾
	float GetPOS() { return m_posture; }//��l���̌������擾
	float GetVY() { return m_vy; }		
	float GetVX() { return m_vx; }		
	bool GetBATTLER() { return m_battle_flag; }

	bool GetINPUTF() { return m_inputf; }			//inputf�̏����擾
	int GetBATTLEHP() { return m_battle_hp; }		//��l����HP���擾
	int GetBATTLEMP() { return m_battle_mp; }		//��l����MP���擾
	int GetBATTLEMAGIC() { return m_battle_magic; }	//��l���̐ݒ薂�@���擾

	void SetSPEED(float s) { m_speed_power = s; }
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
	float m_directionx; //���@���˗pX����
	float m_directiony; //���@���˗pY����
	float hero_posture;	//�}�b�v��̃q�[���[�̌���
	float m_swordwidth; //�\�[�h��


	int m_battle_hp;	//�̗�(�퓬)
	int m_battle_mp;	//���@�g�p��(�퓬)
	int m_battle_magic;	//���@�؂�ւ�(�퓬)

	int m_damage;		//��l�����󂯂�_���[�W�p

	int m_time;		//���G���ԗp
	int m_dtime;	//���S����
	int m_sword_delay;	//���U���Ԋu�p

	int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
	int   m_ani_frame;	//�`��t���[��

	float m_speed_power;	//�X�s�[�h�p���[
	float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

	bool  m_inputf;	//�L�[���͐���p
	bool  m_f;		//�L�[�i�������j����p
	bool  m_mf;		//�L�[�i�������j����p
	bool  m_delete;	//�G���ŗp�t���O
	bool m_dtime_f;//���S�p�t���O

	bool m_pos_flag;	//��l�������p�̃t���O
	bool m_battle_flag;	//�}�b�v�ɖ߂�t���O
	bool m_boss_battle_f;	//�{�X��p�t���O
	bool m_hit_down; //�G�̓��̔���p

	//���@�g�p�\�t���O
	bool m_fire_flag;
	bool m_ice_flag;
	bool m_thunder_flag;
	bool m_wind_flag;

	//�e�X�g�p
	float px, py;		//��_
};

