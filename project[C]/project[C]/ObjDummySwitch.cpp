//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjSwitch.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjDummySwitch::CObjDummySwitch(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjDummySwitch::Init()
{
	m_change = false;	//�摜�؂�ւ�
	m_time = 0;
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_FIELD, OBJ_DUMMYSWITCH, 1);
}

//�A�N�V����
void CObjDummySwitch::Action()
{
	//��l���̏����擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (g_battle_flag == true)
	{
		return;
	}
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	if (m_change == false)
	{
		//��l���Ɠ������Ă��邩�m�F
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			m_time = 50;
			g_key_flag = true;
			m_change = true;	//�������Ă�����\���J���[��ς���
			
			hit->SetInvincibility(true);	//�����蔻�������
		}
	}
	
	if (m_time == 1) {
		hero->SetENEMYF(true);	//�G�o���t���O���I��
		hero->SetFADEF(true);	//�t�F�C�h�t���O���I��
		hero->SetDELETE(true);	//�O�G�폜�t���O���I��

		CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
		Objs::InsertObj(fade, OBJ_FADEIN, 200);
		Audio::Start(1);
	}

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());

}

//�h���[
void CObjDummySwitch::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//���b�Z�[�W�̏��������Ă���
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 1.0f,1.0f,2.0f,0.7f };
	float r[4] = { 3.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	CHitBox* hit = Hits::GetHitBox(this);
	if (m_change == true)
	{
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//Fire��Fireblock�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
		{
			m_time = 100;
		}
	}
	if (m_time > 0) {
		m_time--;
		pm->BackDraw(195.0f, 195.0f, 265.0f, 225.0f, a);
		Font::StrDraw(L"�G��!!", 200, 200, 20, c);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//�`��
	if (m_change == false) {
		Draw::Draw(4, &src, &dst, b, 0.0f);
	}
	else if (m_change == true) {
		Draw::Draw(4, &src, &dst, r, 0.0f);
	}
}


