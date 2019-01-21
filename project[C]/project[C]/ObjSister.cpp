//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

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
	m_change = false;	
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_SISTER, OBJ_SISTER, 1);
}

//�A�N�V����
void CObjSister::Action()
{
	//��l���̏����擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)//��l���Ƃ̓����蔻��
	{
		hit->SetInvincibility(true);	//���G�ɂ���(hit���������)
		m_change = true;		//�摜��؂�ւ���
		m_drawt1 = 100;	//�h���[�^�C�����Z�b�g
		g_mhit_enemy_flag = true;
	}
	if (m_change == true)
	{
		hero->SetSPEED(0.0f);	//�X�s�[�h���O�ɂ���
		hero->SetVX(0.0f);		//�x�N�g�����O�ɂ���
		hero->SetVY(0.0f);
	}

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjSister::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	//���b�Z�[�W�̏��������Ă���
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);


	if (m_drawt1 > 0) {
		m_drawt1--;		//�h���[�^�C�������炷(���炵�Ă���Ԃɕ\��)
		pm->BackDraw(195.0f, 195.0f, 360.0f, 225.0f, a);
		Font::StrDraw(L"���Ă��ꂽ�̂ˁI", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_drawt1 <= 0) {
			m_drawt1 = 0;
			m_drawt2 = 100;
		}
	}
	if (m_drawt2 > 0) {
		m_drawt2--;		//�h���[�^�C�������炷(���炵�Ă���Ԃɕ\��)
		pm->BackDraw(195.0f, 195.0f, 445.0f, 225.0f, a);
		Font::StrDraw(L"�����Ă���Ă��肪�Ƃ��I", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_drawt2 <= 0) {
			m_drawt2 = 0;
			hero->SerCLEARF(true);	//�N���A�t���O���I��
			CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
			Objs::InsertObj(fade, OBJ_FADEIN, 200);
		}
	}


	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	if (m_change == false)	//�摜��؂�ւ���ʒu�̒���
	{
		src.m_top    =  97.0f;
		src.m_left   = 240.0f;
		src.m_right  = 264.0f;
		src.m_bottom = 129.0f;
	}
	else
	{
		src.m_top    =  33.0f;
		src.m_left   = 240.0f;
		src.m_right  = 264.0f;
		src.m_bottom =  65.0f;
	}
	//�u���b�N�̏��������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();
	//�`��
	Draw::Draw(15, &src, &dst, c, 0.0f);

}
