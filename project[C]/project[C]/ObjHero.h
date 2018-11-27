#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero : public CObj
{
	public:
		CObjHero() {};
		~CObjHero() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		float GetX() { return m_px; }	//��l����X�ʒu���擾
		float GetY() { return m_py; }	//��l����Y�ʒu���擾
		float GetPOS() { return m_posture; }	//��l���̌������擾

		int GetMAXHP() { return m_max_hp; }	//��l����MAXHP���擾
		int GetMAXMP() { return m_max_mp; }	//��l����MAXMP���擾
		int GetHP() { return m_hp; }	//��l����HP���擾
		int GetMP() { return m_mp; }	//��l����MP���擾
		int GetMAGIC() { return m_magic; }	//��l���̐ݒ薂�@���擾
		int GetKEY() { return m_key; }	//���̏����擾
		bool GetBATTLE() { return m_battle_flag; }	//�o�g���ڍs�p�̃t���O���擾
		void SetBATTLE(bool x) { m_battle_flag = x; }

		void SetMAXHP(float x) { m_max_hp = x; }	//��l����MAXHP�ɒl���Z�b�g
		void SetMAXMP(float x) { m_max_mp = x; }	//��l����MAXMP�ɒl���Z�b�g
		void SetHP(float x) { m_hp = x; }	//��l����HP�ɒl���Z�b�g
		void SetMP(float x) { m_mp = x; }	//��l����MP�ɒl���Z�b�g
		void SetMAGIC(float x) { m_magic = x; }	//��l���̖��@�̎�ނ��Z�b�g

		bool GetKEYF() { return m_key_mf; }	//KEY�̏����擾
		bool GetGATEF() { return m_gate_mf; }	//GATE�̏����擾
		bool GetWATERF() { return m_water_mf; }	//WATER�̏����擾
		bool GetMICE() { return m_ice_mf; }	//ICE�̏����擾

		bool GetFIREF() { return m_fire_flag; }
		bool GetICEF() { return m_ice_flag; }
		bool GetTHUNDERF(){return m_thunder_flag;}
		bool GetWINDF() { return m_wind_flag; }

		void SetKEYF(float x) { m_key_mf = x; }
		void SetGATEF(float x) { m_gate_mf = x; }
		void SetWATERF(float x) { m_water_mf = x; }
		void SetMICE(float x) { m_ice_mf = x; }

		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }
		int GetBT() { return m_block_type; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetBT(int t) { m_block_type = t; }

		void SetUp(bool b) { m_hit_up = b; }
		void SetDown(bool b) { m_hit_down = b; }
		void SetLeft(bool b) { m_hit_left = b; }
		void SetRight(bool b) { m_hit_right = b; }
	private:
		float m_px;			//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;
		float m_posture;	//�p��
		float m_directionx; //���@���˗pX����
		float m_directiony; //���@���˗pY����

		int m_max_hp;		//HP�̍ő�l
		int m_max_mp;		//MP�̍ő�l
		int m_hp;			//�̗�
		int m_mp;			//���@�g�p��
		int m_magic;		//���@�؂�ւ�
		int m_key;			//��

		float m_scrollx;		//���E�X�N���[���p
		float m_scrolly;		//�㉺�X�N���[���p
		bool  m_f;		//�L�[�i�������j����p
		bool  m_mf;		//�L�[�i�������j����p

		bool m_battle_flag;	//�o�g���ڍs�p
		bool m_map_flag; //�}�b�v�ڍs�p

		//���b�Z�[�W�p�t���O
		bool m_gate_mf;
		bool m_water_mf;
		bool m_key_mf;
		bool m_ice_mf;

		//���@�g�p�\�t���O
		bool m_fire_flag;
		bool m_ice_flag;
		bool m_thunder_flag;
		bool m_wind_flag;

		int   m_gate_time;			
		int   m_ice_time;			//�\�����鎞��
		int   m_water_time;
		int   m_key_time;

		int	  m_ani_time;	//�A�j���[�V�����t���[������Ԋu
		int   m_ani_frame;	//�`��t���[��

		float m_speed_power;	//�X�s�[�h�p���[
		float m_ani_max_time;	//�A�j���[�V��������Ԋu�ő�l

		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		//����ł���block�̎�ނ��m�F�p
		int m_block_type;
};
