//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"

#include "ObjBackgroundBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackgroundBattle::Init()
{

}

//�A�N�V����
void CObjBackgroundBattle::Action()
{

}

//�h���[
void CObjBackgroundBattle::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu


	//�w�i�؂���
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 200.0f;
	src.m_bottom =  90.0f;

	//�`��
	dst.m_top    =  50.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 550.0f;
	Draw::Draw(FLOOR1_WALL, &src, &dst, c, 0.0f);
}

