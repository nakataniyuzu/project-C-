//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBossSwitch.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjBossSwitch::CObjBossSwitch(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjBossSwitch::Init()
{
	m_change = false;	//�摜�؂�ւ�
	m_time = 0;
						//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_FIELD, OBJ_BOSSSWITCH, 1);
}

//�A�N�V����
void CObjBossSwitch::Action()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//��l���Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		Audio::Start(11);	//�G�t�F�N�g����炷
		m_time = 100;	//�^�C�����Z�b�g
		hit->SetInvincibility(true);	//���G���I���ɂ���
		m_change = true;
	}
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());

}

//�h���[
void CObjBossSwitch::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,2.0f,0.7f };
	float r[4] = { 3.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.7f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left = 0.0f + m_px + block->GetScrollX();
	dst.m_right = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();
	//���b�Z�[�W�̏��������Ă���
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

	//�`��
	if (m_change == false) {
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (m_change == true) {
		Draw::Draw(4, &src, &dst, r, 0.0f);
	}

	if (m_time > 0)
	{
		m_time--;
		pm->BackDraw(195.0f, 195.0f, 450.0f, 225.0f, a);
		Font::StrDraw(L"�{�X�֑��������J����", 200, 200, 20, y);//���Ԃ�0�ɂȂ�ƕ\�����I��
	}
}


