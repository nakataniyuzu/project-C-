//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjWindBlock.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjWindBlock::CObjWindBlock(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjWindBlock::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_WINDBLOCK, 1);
}

//�A�N�V����
void CObjWindBlock::Action()
{
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//WIND�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_WIND) != nullptr)//�������Ă����瓖���蔻��������A�`���ς���
	{
		Audio::Start(11);		//�G�t�F�N�g����炷
		this->SetStatus(false);		//���g���폜
		Hits::DeleteHitBox(this);
	}
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)//�������Ă����瓖���蔻��������A�`���ς���
	{
		m_time = 100;
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
void CObjWindBlock::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	//���b�Z�[�W�̏��������Ă���
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

	if (m_time > 0)
	{
		m_time--;
		pm->BackDraw(195.0f, 195.0f, 370.0f, 225.0f, a);
		Font::StrDraw(L"�傫�ȗ͂��K�v...", 200, 200, 20, g);//���Ԃ�0�ɂȂ�ƕ\�����I��
		if (m_time <= 0)
		{
			m_time = 0;
		}
	}
	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 200.0f;
	src.m_right = 300.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left = 0.0f + m_px + block->GetScrollX();
	dst.m_right = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//�`��
	Draw::Draw(4, &src, &dst, g, 0.0f);
}


