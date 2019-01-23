#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F
class CObjMessage :public CObj
{
	public:
		CObjMessage() {};
		~CObjMessage() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[

		void BackDraw(float top, float left, float right, float bottom, float c[]);

	private:

		struct Flag {
			bool gate;		//GATE�̃��b�Z�[�W�t���O
			bool key;		//KEY�̃��b�Z�[�W�t���O
			bool water;		//WATERBLOCK�̃��b�Z�[�W�t���O
			bool ice;		//ICEMAGIC�̃��b�Z�[�W�t���O
			bool wind;		//WINDMAGIC�̃��b�Z�[�W�t���O
			bool sblock;	//SWITCHBLOCK�̃��b�Z�[�W�t���O
			bool sgate;		//SWITCHGATE�̃��b�Z�[�W�t���O
			bool heal;		//HEAL�̃��b�Z�[�W�t���O
			bool allkill;	//ALLKILL�̃��b�Z�[�W�t���O
			bool windb;		//WIND�u���b�N�̃��b�Z�[�W�t���O
		};
		Flag f;

		//�\�����鎞��
		struct Time {
			int gate;		//GATE�p�̎���
			int water;		//WATER�p�̎���
			int key;		//KEY�p�̎���
			int ice;		//ICE�p�̎���
			int wind;		//wind�p�̎���
			int sblock;		//SWITCHBLOCK�p�̎���
			int sgate;		//SWITCHGATE�p�̎���
			int heal;		//HEAL�̎���
			int allkill;	//ALLKILL�̎���
			int windb;		//WIND�u���b�N�̎���
		};
		Time t;
		

};

