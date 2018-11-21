//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"


#include "ObjBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackground::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;
	m_x3 = -800.0f;
	m_scroll = 0.0f;
	m_scroll_map = 0.0f;

}

//�A�N�V����
void CObjBackground::Action()
{

	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	m_scroll_map = hero->GetVX(); //�w�i�ɉ�����

	if (hero->GetVX() >= 0.0f)
	{
		//�L�����N�^�[���E�ɓ�������
		if (hx >350)
		{
			//�X�N���[�����C�������悤�Ƃ�����X�N���[��
			m_x1 -= hero->GetVX();
			if (m_x1 < -1600.0f)
				m_x1 = 800;
			m_x2 -= hero->GetVX();
			if (m_x2 < -1600.0f)
				m_x2 = 800;
			m_x3 -= hero->GetVX();
			if (m_x3 < -1600.0f)
				m_x3 = 800;
		}
	}
	else
	{
		//�L�����N�^�[�����ɓ�������
		if (hx < 100)
		{
			//�X�N���[�����C�������悤�Ƃ�����X�N���[��
			m_x1 -= hero->GetVX();
			if (m_x1 > 1600.0f)
				m_x1 = -800;
			m_x2 -= hero->GetVX();
			if (m_x2 > 1600.0f)
				m_x2 = -800;
			m_x3 -= hero->GetVX();
			if (m_x3 > 1600.0f)
				m_x3 = -800;
		}
	}
}

//�h���[
void CObjBackground::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu

	
	//�w�i�؂���
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 800.0f;
	src.m_bottom = 600.0f;

	//�`��
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f + m_x1;
	dst.m_right  = 820.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

	dst.m_top    =   0.0f;
	dst.m_left   = 820.0f + m_x2;
	dst.m_right  =   0.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

	dst.m_top    =   0.0f;
	dst.m_left   = 820.0f + m_x3;
	dst.m_right  =   0.0f + m_x3;
	dst.m_bottom = 600.0f;
	Draw::Draw(FLOOR1, &src, &dst, c, 0.0f);

}

