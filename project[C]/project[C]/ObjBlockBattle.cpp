//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBlockBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlockBattle::CObjBlockBattle()
{

}

//�C�j�V�����C�Y
void CObjBlockBattle::Init()
{
	//�u���b�N���
	int block_data[12][16]
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};
	//�R�s�[
	memcpy(m_map, block_data, sizeof(int)*(12 * 16));
}

//�A�N�V����
void CObjBlockBattle::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO_BATTLE);
	float hx = hero->GetX();
	float hy = hero->GetY();
}

//�h���[
void CObjBlockBattle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*50.0f;
				dst.m_left = j*50.0f;
				dst.m_right = dst.m_left + 50.0;
				dst.m_bottom = dst.m_top + 50.0;

				//�`��
				Draw::Draw(2, &src, &dst, c, 0.0f);
			}
		}
	}

}