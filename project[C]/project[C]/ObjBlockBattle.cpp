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
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	m_boss_battle_f = hero->GetBOSSBATTLE();

	if (m_battle_flag == true || m_boss_battle_f ==true)
	{
		return;
	}
	//��l���̈ʒu���擾
	float hx = hero->GetX();
	float hy = hero->GetY();
}

//�h���[
void CObjBlockBattle::Draw()
{
	if (m_battle_flag == true || m_boss_battle_f == true)
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
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);
		

}