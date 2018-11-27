#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjMessage :public CObj
{
	public:
		CObjMessage() {};
		~CObjMessage() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[

	private:
		bool water_flag;	//WATERBLOCK�̃��b�Z�[�W�t���O
		bool key_flag;		//KEY�̃��b�Z�[�W�t���O
		bool gate_flag;		//GATE�̃��b�Z�[�W�t���O
		bool ice_flag;		//ICEMAGIC�̃��b�Z�[�W�t���O
		bool switch_flag;	//SWITCHGATE�̃��b�Z�[�W�t���O

		//�\�����鎞��
		int   m_gate_time;
		int   m_water_time;			
		int   m_key_time;
		int   m_ice_time;
		int   m_switch_time;

};

