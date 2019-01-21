//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "CObjWindBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjWindBattle::CObjWindBattle(float x, float y)
{
	m_x = x;
	m_y = y;

}
//�C�j�V�����C�Y
void CObjWindBattle::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//��l���̈ʌ������擾
	CObjHeroBattle* hero = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	m_posture = hero->GetPOS();

	m_time = 50;	//���@�������鎞��

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, ALL_SIZE, ALL_SIZE, ELEMENT_ATTACK, OBJ_WIND_BATTLE, 1);
}

//�A�N�V����
void CObjWindBattle::Action()
{
	if (m_hit_left == true)	//��
		m_hit = true;
	if (m_hit_right == true)//�E
		m_hit = true;

	if (m_posture == 0.0f) {
		m_vx = 5.0f;
		m_x += m_vx;
	}
	if (m_posture == 1.0f) {
		m_vx = -5.0f;
		m_x += m_vx;
	}

	//HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�G�ƐڐG�����疂�@�폜
	if (hit->CheckElementHit(ELEMENT_ENEMY_BATTLE) == true || hit->CheckElementHit(ELEMENT_BOSS_BATTLE) == true)
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
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}

//�h���[
void CObjWindBattle::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 150.0f;
	src.m_right  = 200.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	Draw::Draw(13, &src, &dst, c, 0.0f);
}