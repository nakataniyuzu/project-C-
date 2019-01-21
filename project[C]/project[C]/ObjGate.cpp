//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjGate.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjGate::CObjGate(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjGate::Init()
{
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_GATE, 1);

}

//�A�N�V����
void CObjGate::Action()
{
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	key = hero->GetKEY();

	//��l���Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		if (key == 1) {
			this->SetStatus(false);		//������������Ԃœ������Ă�����MYSTERYBLOCK������
			Hits::DeleteHitBox(this);
		}
	}

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjGate::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	CHitBox* hit = Hits::GetHitBox(this);
	
	if (key == 0)
	{
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//��l�����~�X�e���[�u���b�N�Ɠ��������ꍇ�Am_time�Ɏ��Ԃ��Z�b�g
		{
			m_time = 100;
		}
		if (m_time > 0) {
			m_time--;

			Font::StrDraw(L"�����K�v�ł�", 200, 200, 20, c);//���Ԃ�0�ɂȂ�ƕ\�����I��		
			if (m_time <= 0) {
				m_time = 0;
			}
		}
	}
	
	


	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =   0.0f;
	src.m_left   = 100.0f;
	src.m_right  = 200.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top    =     0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left   =     0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}


