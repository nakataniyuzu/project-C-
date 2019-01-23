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

}

//�A�N�V����
void CObjBlockBattle::Action()
{

}

//�h���[
void CObjBlockBattle::Draw()
{
	if (g_battle_flag == false)
	{
		return;
	}

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   =  0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	
	//�\���ʒu�̐ݒ�
	dst.m_top    = 550.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;

	//�`��
	Draw::Draw(FLOOR, &src, &dst, c, 0.0f);
}