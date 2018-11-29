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
		bool GetKEY() { return m_key; }		//���̏����擾

		bool GetBATTLE() { return m_battle_flag; }	//�o�g���ڍs�p�̃t���O���擾
		bool GetBOSSBATTLE() { return m_boss_battle_flag; }	//�{�X�o�g���ڍs�p�̃t���O���擾
		
		void SetBOSSBATTLE(bool x) { m_boss_battle_flag = x; }
		void SetBATTLE(bool x) { m_battle_flag = x; }

		void SetMAXHP(float x) { m_max_hp = x; }	//��l����MAXHP�ɒl���Z�b�g
		void SetMAXMP(float x) { m_max_mp = x; }	//��l����MAXMP�ɒl���Z�b�g
		void SetHP(float x) { m_hp = x; }	//��l����HP�ɒl���Z�b�g
		void SetMP(float x) { m_mp = x; }	//��l����MP�ɒl���Z�b�g
		void SetMAGIC(float x) { m_magic = x; }	//��l���̖��@�̎�ނ��Z�b�g

		bool GetENEMYF() { return m_enemy_flag; }	//�G�o���p�t���O���擾
		bool GetBOSSF() { return m_boss_flag; }		//�{�X�o���p�t���O���擾

		void SetENEMYF(bool x) { m_enemy_flag = x; }	//�G�o���p�t���O���Z�b�g
		void SetBOSSF(bool x) { m_boss_flag = x; }		//�{�X�o���p�t���O���Z�b�g

		bool GetKEYF() { return mes.key; }		//KEY�̏����擾
		bool GetGATEF() { return mes.gate; }	//GATE�̏����擾
		bool GetWATERF() { return mes.water; }	//WATER�̏����擾
		bool GetMICE() { return mes.ice; }		//ICE�̏����擾
		bool GetSGATE() { return mes.switchgate; }	//SWITCHGATE�̏����擾
		bool GetSBLOCK() { return mes.switchblock; }//SWITCHBLOCK�̏����擾
		bool GetHEAL() { return mes.heal; }		//HEAL�̏����擾

		bool GetFIREF() { return m_fire_flag; }		//Fire���g���邩�ǂ���
		bool GetICEF() { return m_ice_flag; }		//Ice���g���邩�ǂ���
		bool GetTHUNDERF(){return m_thunder_flag;}	//THUNDER���g���邩�ǂ���
		bool GetWINDF() { return m_wind_flag; }		//WIND���g���邩�ǂ���

		void SetKEYF(bool x) { mes.key = x; }		//KEY�ɏ����Z�b�g
		void SetGATEF(bool x) { mes.gate = x; }		//GATE�ɏ����Z�b�g
		void SetWATERF(bool x) { mes.water = x; }	//WATER�ɏ����Z�b�g
		void SetMICE(bool x) { mes.ice = x; }		//ICE�ɏ����Z�b�g
		void SetSGATE(bool x) { mes.switchgate = x; }	//SWITCHGATE�ɏ����Z�b�g
		void SetSBLOCK(bool x) { mes.switchblock = x; }	//SWITCHBLOCK�ɏ����Z�b�g
		void SetHEAL(bool x) { mes.heal = x; }		//HEAL�ɏ����Z�b�g

		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }

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

		bool m_battle_flag;
		bool m_ene_battle_flag;	//�G���o�g���ڍs�p
		bool m_boss_battle_flag;//�{�X�o�g���p
		bool m_map_flag; //�}�b�v�ڍs�p

		//���b�Z�[�W�p�t���O
		struct Message {
			bool gate;		//�Q�[�g�p
			bool water;		//���p
			bool key;		//���p
			bool ice;		//�X���@�p
			bool switchblock;	//�X�C�b�`�u���b�N�p
			bool switchgate;	//�X�C�b�`�Q�[�g�p
			bool heal;		//�q�[���u���b�N�p
		};
		Message mes;

		//���@�g�p�\�t���O
		bool m_fire_flag;
		bool m_ice_flag;
		bool m_thunder_flag;
		bool m_wind_flag;

		bool   m_gate_time;
		bool   m_ice_time;			//�\�����鎞��
		bool   m_water_time;
		bool   m_key_time;

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
