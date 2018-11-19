#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define ALL_SIZE 50.0f

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock : public CObj
{
	public:
		CObjBlock(int map[27][55]);
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
		//int m_map[27][55];	//�}�b�v���

		float m_scrollx;		//���E�X�N���[���p
		float m_scrolly;

};