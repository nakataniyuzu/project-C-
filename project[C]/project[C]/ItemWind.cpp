//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ItemWind.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjItemWind::CObjItemWind(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjItemWind::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_ITEM, ITEM_WIND, 1);
}

//�A�N�V����
void CObjItemWind::Action()
{
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//��l���ƏՓ˂��������
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjItemWind::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   = 100.0f;
	src.m_right  = 150.0f;
	src.m_bottom =  50.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left = 0.0f + m_px + block->GetScrollX();
	dst.m_right = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//�`��
	Draw::Draw(ITEM, &src, &dst, c, 0.0f);
}


