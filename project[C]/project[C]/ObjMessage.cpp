//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMessage.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMessage::Init()
{

}

//�A�N�V����
void CObjMessage::Action()
{
	
}

//�h���[
void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.5f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	
	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu

	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	f.water = hero->GetWATERF();
	f.key = hero->GetKEYF();
	f.gate = hero->GetGATEF();
	f.ice = hero->GetMICE();
	f.wind = hero->GetMWIND();
	f.sgate = hero->GetSGATE();
	f.sblock = hero->GetSBLOCK();
	f.heal = hero->GetHEAL();

	CObjEnemy1* enemy1 = (CObjEnemy1*)Objs::GetObj(OBJ_ENEMY_FIRST);
	CObjEnemy2* enemy2 = (CObjEnemy2*)Objs::GetObj(OBJ_ENEMY_SECOND);
	CObjEnemy3* enemy3 = (CObjEnemy3*)Objs::GetObj(OBJ_ENEMY_THIRD);

	if (g_map_change == 0)
		f.allkill = enemy1->GetALLKILL();
	else if(g_map_change == 1)
		f.allkill = enemy2->GetALLKILL();
	else if (g_map_change == 2)
		f.allkill = enemy3->GetALLKILL();
	if (f.allkill == true)	//�G���S�ł����Ƃ��Ƀt���O���Z�b�g
	{
		t.allkill = 100;
	}
	if (t.allkill > 0) {
		t.allkill--;
		f.allkill = false;		//�t���O���I�t
		if (g_map_change == 0)
			enemy1->SetALLKILL(f.allkill);
		else if (g_map_change == 1)
			enemy2->SetALLKILL(f.allkill);
		else if (g_map_change == 2)
			enemy3->SetALLKILL(f.allkill);

		BackDraw(225.0f, 175.0f, 370.0f, 255.0f, a);
		Font::StrDraw(L"�G���S�ł����悤��", 180, 230, 20, c);//���Ԃ�0�ɂȂ�ƕ\�����I��

		if (t.allkill <= 0) {
			t.allkill = 0;
		}
	}

	if (f.water == true)	//��l����WATER�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		t.water = 100;
	}
	if (t.water > 0) {
		t.water--;
		f.water = false;		//�t���O���I�t
		hero->SetWATERF(f.water);
		BackDraw(225.0f, 175.0f, 415.0f, 255.0f, a);
		Font::StrDraw(L"���点��Γn��邩...�H", 180, 230, 20, b);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.water <= 0) {
			t.water = 0;
		}
	}

	if (f.key == true)	//��l����KEY�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		t.key = 100;
	}
	if (t.key > 0) {
		t.key--;
		f.key = false;		//�t���O���I�t
		hero->SetKEYF(f.key);
		BackDraw(195.0f, 195.0f, 348.0f, 225.0f, a);
		Font::StrDraw(L"������ɓ��ꂽ", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.key <= 0) {
			t.key = 0;
		}
	}

	if (f.gate == true)		//���̃t���O���I���ɂȂ����玞�Ԃ��Z�b�g
	{
		t.gate = 100;
	}
	if (t.gate > 0) {
		t.gate--;
		f.gate = false;		//�t���O���I�t
		hero->SetGATEF(f.gate);
		BackDraw(165.0f, 200.0f, 320.0f, 195.0f, a);
		Font::StrDraw(L"�����J����", 210, 170, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.gate <= 0) {
			t.gate = 0;
		}
	}
	if (f.ice == true)		//���̃t���O���I���ɂȂ����玞�Ԃ��Z�b�g
	{
		t.ice = 100;
	}
	if (t.ice > 0) {
		t.ice--;
		f.ice = false;		//�t���O���I�t
		hero->SetMICE(f.ice);
		BackDraw(165.0f, 195.0f, 540.0f, 195.0f, a);
		Font::StrDraw(L"�X���@���o�����I�iX�L�[�Ő؂�ւ�", 200, 170, 20, b);//���Ԃ�0�ɂȂ�ƕ\�����I��

		if (t.ice <= 0) {
			t.ice = 0;
		}
	}
	if (f.wind == true)		//���̃t���O���I���ɂȂ����玞�Ԃ��Z�b�g
	{
		t.wind = 100;
	}
	if (t.wind > 0) {
		t.wind--;
		f.wind = false;		//�t���O���I�t
		hero->SetMWIND(f.wind);
		BackDraw(165.0f, 195.0f, 540.0f, 195.0f, a);
		Font::StrDraw(L"�����@���o�����I�iX�L�[�Ő؂�ւ�", 210, 170, 20, g);//���Ԃ�0�ɂȂ�ƕ\�����I��

		if (t.wind <= 0) {
			t.wind = 0;
		}
	}
	if (f.sgate == true)	//�t���O���I���̎��^�C�����Z�b�g
	{
		t.sgate = 100;
	}
	if (t.sgate > 0) {
		t.sgate--;
		f.sgate = false;	//�t���O���I�t
		hero->SetSGATE(f.sgate);
		BackDraw(195.0f, 195.0f, 315.0f, 225.0f, a);
		Font::StrDraw(L"�J���Ȃ�...", 200, 200, 20, c);//���Ԃ�0�ɂȂ�ƕ\�����I��		
		if (t.sgate <= 0) {
			t.sgate = 0;
		}
	}
	if (f.sblock == true)	//�t���O���I���̎��^�C�����Z�b�g
	{
		t.sblock = 100;
	}
	if (t.sblock > 0) {
		t.sblock--;
		f.sblock = false;
		hero->SetSBLOCK(f.sblock);
		//�`��
		BackDraw(195.0f, 195.0f, 450.0f, 225.0f, a);
		Font::StrDraw(L"�ǂ����Ŕ����J�����������B", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.sblock <= 0) {
			t.sblock = 0;
		}	
	}

	if (f.heal == true)		//�t���O���I���̎��^�C�����Z�b�g
	{
		t.heal = 100;
	}
	if (t.heal > 0) {
		t.heal--;
		f.heal = false;
		hero->SetHEAL(f.heal);
		BackDraw(195.0f, 300.0f, 480.0f, 225.0f, a);
		Font::StrDraw(L"HP/MP���񕜂����I", 300, 200, 20, g);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.heal <= 0) {
			t.heal = 0;
		}
	}
}

//BackDrawMethod�֐�
//����1 float	top		:���\�[�X�\���ʒutop
//����2 float	left	:���\�[�X�\���ʒuleft
//����3 float	right	:���\�[�X�\���ʒuright
//����4 float	bottom	:���\�[�X�\���ʒubottom
//����5 float	c[]	:�J���[�ݒ�
void CObjMessage::BackDraw(float top, float left, float right,float bottom, float c[])
{
	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	//�`��
	dst.m_top    = top;	
	dst.m_left   = left;
	dst.m_right  = right;
	dst.m_bottom = bottom;
	Draw::Draw(3, &src, &dst, c, 0.0f);
}
