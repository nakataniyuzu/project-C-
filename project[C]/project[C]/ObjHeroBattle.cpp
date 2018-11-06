//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHeroBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHeroBattle::Init()
{
	m_px = 100.0f;
	m_py = 450.0f;		//�ʒu
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0f ������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	//�����蔻��p��HitBox���쐬
 	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
}

//�A�N�V����
void CObjHeroBattle::Action()
{
	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 2.0f;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 2.0f;
	}

	//Space�L�[�ŃW�����v
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (1)
		{
			m_vy = -20;
		}
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);

	//�G�@�I�u�W�F�N�g�ƐڐG�������l���폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
	}

	if (m_px < 0)
	{
		m_px = 0.0f;
	}

	if (m_py + 100 >= 550)
	{
		m_py = 550.0 - 100.0f;
	}

	if (m_py < 0)
	{
		m_py = 0.0f;
	}
}

//�h���[
void CObjHeroBattle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 75.0f + m_px;
	dst.m_bottom = 100.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}