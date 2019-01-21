//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "CObjFire.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjFire::CObjFire(float x, float y)
{
	m_x = x;
	m_y = y;

}
//�C�j�V�����C�Y
void CObjFire::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_hit = false;

	//��l���̈ʌ������擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_posture = hero->GetPOS();

	m_time = 50;	//���@�������鎞��

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x + 15, m_y + 10, 25.0f, 30.0f, ELEMENT_MAGIC, OBJ_FIRE, 1);
}

//�A�N�V����
void CObjFire::Action()
{
	if (m_hit_up == true)	//��
		m_hit = true;
	if (m_hit_down == true)	//��
		m_hit = true;
	if (m_hit_left == true)	//��
		m_hit = true;
	if (m_hit_right == true)//�E
		m_hit = true;

	if (m_posture == 0.0f) {
		m_vy = -5.0f;
		m_y += m_vy;
	}
	if (m_posture == 1.0f) {
		m_vx = 5.0f;
		m_x += m_vx;
	}
	if (m_posture == 2.0f) {
		m_vy = 5.0f;
		m_y += m_vy;
	}
	if (m_posture == 3.0f) {
		m_vx = -5.0f;
		m_x += m_vx;
	}
	
	//HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + 15, m_y+ 10);

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_x, &m_y, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//FIREBLOCK�ƏՓ˂�������ł�����
	if (hit->CheckObjNameHit(OBJ_FIREBLOCK) != nullptr || 
		hit->CheckObjNameHit(OBJ_GATE) != nullptr || 
		hit->CheckObjNameHit(OBJ_BOSS) != nullptr)
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
void CObjFire::Draw()
{
	//�`��J���[���@R=RED  G=Green  B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 100.0f;
	src.m_right  = 150.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_y;
	dst.m_left   = 0.0f + m_x;
	dst.m_right  = ALL_SIZE + m_x;
	dst.m_bottom = ALL_SIZE + m_y;

	if (m_posture == 0.0f)
		Draw::Draw(13, &src, &dst, c, 90.0f);
	else if (m_posture == 1.0f)
		Draw::Draw(13, &src, &dst, c, 0.0f);
	else if (m_posture == 2.0f)
		Draw::Draw(13, &src, &dst, c, 270.0f);
	else
		Draw::Draw(13, &src, &dst, c, 180.0f);
}