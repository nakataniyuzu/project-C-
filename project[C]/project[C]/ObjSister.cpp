//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjSister.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjSister::CObjSister(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjSister::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_SISTER, OBJ_SISTER, 1);
}

//�A�N�V����
void CObjSister::Action()
{
	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	battle_flag = hero->GetBATTLE();
	boss_battle_flag = hero->GetBOSSBATTLE();

	if (battle_flag == false || boss_battle_flag == false)
	{
		return;
	}



	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjSister::Draw()
{
	if (battle_flag == false)
	{
		return;
	}
	

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 96.0f;
	src.m_left   = 240.0f;
	src.m_right  = 264.0f;
	src.m_bottom = 128.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	Draw::Draw(15, &src, &dst, c, 0.0f);

}
