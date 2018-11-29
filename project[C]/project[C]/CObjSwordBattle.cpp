//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "CObjSwordBattle.h"
#include "ObjHeroBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSwordBattle::CObjSwordBattle(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjSwordBattle::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	posture = 0.0f;	//�E����0.0f ������1.0f

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//��l���̈ʌ������擾
	CObjHeroBattle* hero = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	posture = hero->GetPOS();

	m_time = 0;

	m_sword_time = 10;	//���������鎞��

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x + 25, m_y, 35, 50, ELEMENT_ATTACK, OBJ_SWORD_BATTLE, 1);
}

//�A�N�V����
void CObjSwordBattle::Action()
{
	if (m_hit_left == true)	//��
		m_hit = true;
	if (m_hit_right == true)//�E
		m_hit = true;

	if (posture == 0.0f) {
		m_vx = 4.0f;
		m_x += m_vx;
	}
	if (posture == 1.0f) {
		m_vx = -4.0f;
		m_x += m_vx;
	}

	//HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�G�ƐڐG�����猕�폜
	if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�ǂɓ�������������鏈��
	if (m_hit == true) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//���̎��Ԃŏ����鏈��
	if (m_sword_time > 0) {
		m_sword_time--;
		if (m_sword_time <= 0) {
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	

}

//�h���[
void CObjSwordBattle::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	if (posture == 0.0f)
	{
		src.m_top = 11.0f;
		src.m_left = 65.0f;
		src.m_right = 116.0f;
		src.m_bottom = 61.0f;
	}
	if (posture == 1.0f)
	{
		src.m_top = 12.0f;
		src.m_left = 10.0f;
		src.m_right = 61.0f;
		src.m_bottom = 61.0f;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_y;
	dst.m_left   = 0.0f + m_x;
	dst.m_right  = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	Draw::Draw(16, &src, &dst, c, 0.0f);
}