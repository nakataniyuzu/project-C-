
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
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 100.0f, 100.0f, ELEMENT_BOSS, OBJ_BOSS, 1);
}

//�A�N�V����
void CObjEnemyboss1::Action()
{
	if (g_boss_kills >= 1)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	battle_flag = hero->GetBATTLE();

	if (g_battle_flag == true)
	{
		m_time = 100;
//		hit->SetInvincibility(true);	//���G�I��
		return;
	}

	if (m_time > 0)
	{
		m_time--;
		if (m_time <= 0)
		{
			m_time = 0;
			hit->SetInvincibility(false);	//���G�I�t
		}
	}
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//��l�����G�ꂽ��
	{
		hit->SetInvincibility(true);	//�����蔻�������
	}
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjEnemyboss1::Draw()
{
	if (g_boss_kills >= 1)
		return;
	if (g_battle_flag == true)
	{
		return;
	}
	int AniDate[4] =
	{
		0 , 1 ,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = 100.0f + m_px + block->GetScrollX();
	dst.m_bottom = 100.0f + m_py + block->GetScrollY();

	if (g_map_change == 0) {
		Draw::Draw(14, &src, &dst, c, 0.0f);
	}
	else if(g_map_change == 1){
		Draw::Draw(14, &src, &dst, c, 0.0f);

	}
}
