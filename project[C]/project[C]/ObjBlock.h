#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock : public CObj
{
	public:
		CObjBlock(int map[38][65]);
		~CObjBlock() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[

		void SetScrollX(float sx) { m_scrollx = sx; }
		float GetScrollX() { return m_scrollx; }
		void SetScrollY(float sy) { m_scrolly = sy; }
		float GetScrollY() { return m_scrolly; }

		//�u���b�N�Ƃ̓����蔻��
		void BlockHit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool* left, bool* right,
			float* vx, float*vy, int* bt
		);

	private:
		int m_map[38][65];	//�}�b�v���

		bool m_battle_flag;	//�o�g���ڍs�p�t���O
		bool m_boss_flag;	//�{�X�o�g���ڍs�p�t���O

		float m_scrollx;		//���E�X�N���[���p
		float m_scrolly;

};