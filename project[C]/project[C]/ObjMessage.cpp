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
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };


	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu


	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	f.water = hero->GetWATERF();
	f.key = hero->GetKEYF();
	f.gate = hero->GetGATEF();
	f.ice = hero->GetMICE();
	f.sgate = hero->GetSGATE();
	f.sblock = hero->GetSBLOCK();
	f.heal = hero->GetHEAL();

	if (f.water == true)	//��l����WATER�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
	{
		t.water = 100;
	}
	if (t.water > 0) {
		t.water--;
		f.water = false;		//�t���O���I�t
		hero->SetWATERF(f.water);
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
		Font::StrDraw(L"�X���@���o�����I�iX�L�[�Ő؂�ւ�", 200, 200, 20, c);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.ice <= 0) {
			t.ice = 0;
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
		Font::StrDraw(L"HP/MP���񕜂����I", 200, 200, 20, g);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (t.heal <= 0) {
			t.heal = 0;
		}
	}
}
