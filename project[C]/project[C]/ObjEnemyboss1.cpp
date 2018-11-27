//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyboss1.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemyboss1::CObjEnemyboss1(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjEnemyboss1::Init()
{
	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 100.0f, 100.0f, ELEMENT_BOSS, OBJ_BOSS, 1);
}

//�A�N�V����
void CObjEnemyboss1::Action()
{
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());

}

//�h���[
void CObjEnemyboss1::Draw()
{
	int AniDate[4] =
	{
		0 , 1 ,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + block->GetScrollY();
	dst.m_left = 0.0f + m_px + block->GetScrollX();
	dst.m_right = 100.0f + m_px + block->GetScrollX();
	dst.m_bottom = 100.0f + m_py + block->GetScrollY();

	Draw::Draw(13, &src, &dst, c, 0.0f);
}
