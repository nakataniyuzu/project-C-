//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBoss.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBoss::CObjBoss(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 100.0f, 100.0f, ELEMENT_BOSS, OBJ_BOSS, 1);
}

//�A�N�V����
void CObjBoss::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	m_boss_battle_f = hero->GetBOSSBATTLE();

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	if (m_battle_flag == false || m_boss_battle_f == false)
	{
		return;
	}

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjBoss::Draw()
{
	if (m_battle_flag == false || m_boss_battle_f == false)
	{
		return;
	}
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = 100.0f + m_px + block->GetScrollX();
	dst.m_bottom = 100.0f + m_py + block->GetScrollY();

	Draw::Draw(14, &src, &dst, c, 0.0f);
	

}
