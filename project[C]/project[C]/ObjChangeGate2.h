#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjChangeGate2 : public CObj
{
	public:
		CObjChangeGate2(float x, float y);
		~CObjChangeGate2() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

	private:
		float m_px;			//�ʒu
		float m_py;
		float m_vx;			//�ړ��x�N�g��
		float m_vy;

		int m_time;	//���b�Z�[�W���ԊǗ�
		bool m_change;	//�X�C�b�`�̃I���I�t
};

