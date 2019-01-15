//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjFireblock.h"
#include "ObjMessage.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjFireblock::CObjFireblock(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjFireblock::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_switch = 0.0f;	//�`��؂�ւ�

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_FIREBLOCK, 1);

}

//�A�N�V����
void CObjFireblock::Action()
{
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//Fire�i���@�j�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_FIRE) != nullptr)
	{
		m_switch = 1.0f;
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
void CObjFireblock::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//��l�����~�X�e���[�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		m_time = 100;
	}
	if (m_time > 0) {
		m_time--;
		if (m_switch == 0.0f) {
			pm->BackDraw(195.0f, 195.0f, 330.0f, 225.0f, a);
			Font::StrDraw(L"�΂𓔂���...", 200, 200, 20, r);//���Ԃ�0�ɂȂ�ƕ\�����I��
		}
		else if (m_switch == 1.0f) {
			pm->BackDraw(195.0f, 195.0f, 355.0f, 225.0f, a);
			Font::StrDraw(L"�΂������Ă���B", 200, 200, 20, r);
		}
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	if (hit->CheckObjNameHit(OBJ_FIRE) != nullptr)	//Fire��Fireblock�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		m_draw_time = 100;
	}
	if (m_draw_time > 0) {
		m_draw_time--;
		pm->BackDraw(195.0f, 195.0f, 420.0f, 225.0f, a);
		Font::StrDraw(L"�ǂ������J�����悤���B", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��	
		if (m_draw_time <= 0) {
			m_draw_time = 0;
		}
	}


	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + (50.0f * m_switch);
	src.m_right  = 50.0f + (50.0f * m_switch);
	src.m_bottom = 50.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//�`��
	Draw::Draw(9, &src, &dst, c, 0.0f);
}


