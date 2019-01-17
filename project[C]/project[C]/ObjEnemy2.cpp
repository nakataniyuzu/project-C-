//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_px = x;		//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjEnemy2::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�����0.0f �E����1.0f ������2.0f ������3.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_move = false;

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_ENEMY, OBJ_ENEMY_SECOND, 1);
}

//�A�N�V����
void CObjEnemy2::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	battle_flag = hero->GetBATTLE();

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);


	if (g_battle_flag == true)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;	//�������~�߂�
		m_time = 100;	//m_time�Ɏ��Ԃ��Z�b�g
		return;
	}

	if (m_time > 0)
	{
		m_speed_power = 0.0f;	//�X�s�[�h��0�ɂ���
		m_time--;
		if (m_time <= 0)
		{
			m_speed_power = 0.5f;	//�X�s�[�h�����ɖ߂�
			m_time = 0;				//m_time��0�ɖ߂�
			hit->SetInvincibility(false);	//���G�I�t
		}
	}

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//��l����G�ꂽ��
	{
		m_speed_power = 0.0f;		//�X�s�[�h���O�ɂ���
		m_vx = 0.0f;
		m_vy = 0.0f;
		hit->SetInvincibility(true);	//�����蔻�������
	}
	if (hit->CheckObjNameHit(OBJ_FIRE) != nullptr)	//���@�U��(Fire)�ɐG�ꂽ��
	{
		m_speed_power = 2.0f;	//�X�s�[�h���グ��
	}
	if (hit->CheckObjNameHit(OBJ_ICE) != nullptr)	//���@�U��(Ice)�ɐG�ꂽ��
	{
		m_speed_power = 0.0f;	//�X�s�[�h���~�߂�
	}
	if (m_hit_up == true)	//��
		m_move = false;
	if (m_hit_down == true)	//��
		m_move = true;

	//����
	if (m_move == false)
	{
		m_vy += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vy -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//�h���[
void CObjEnemy2::Draw()
{
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
	float r[4] = { 0.6f,0.0f,0.0f,0.8f };
	float b[4] = { 0.0f,0.0f,0.6f,0.8f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = ALL_SIZE * m_posture;
	src.m_left = 0.0f + AniDate[m_ani_frame] * ALL_SIZE;
	src.m_right = ALL_SIZE + AniDate[m_ani_frame] * ALL_SIZE;
	src.m_bottom = ALL_SIZE + (ALL_SIZE * m_posture);

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + block->GetScrollY();
	dst.m_left = 0.0f + m_px + block->GetScrollX();
	dst.m_right = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	if (m_speed_power >= 2.0f) {
		Draw::Draw(7, &src, &dst, r, 0.0f);
	}
	else if (m_speed_power == 0.0f) {
		Draw::Draw(7, &src, &dst, b, 0.0f);
	}
	else {
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}

}
