//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStairs.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjStairs::CObjStairs(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjStairs::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_next_floor = 0;	//�}�b�v�ύX�p
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_FIELD, OBJ_STAIRS, 1);
}

//�A�N�V����
void CObjStairs::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	if (m_battle_flag == false)
	{
		return;
	}
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//��l���Ɠ������Ă��邩�m�F
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Scene::SetScene(new CSceneNextfloor());	//�Q�[���l�N�X�g�V�[���Ɉڍs
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
void CObjStairs::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//�`��ɑ΂��ăX�N���[���̉e����������
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//�`��
	Draw::Draw(18, &src, &dst, c, 90.0f);
}

