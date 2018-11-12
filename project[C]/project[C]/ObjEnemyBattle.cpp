//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

float g_enemy_px = 600.0f;
float g_enemy_py = 450.0f;

//�C�j�V�����C�Y
void CObjEnemyBattle::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;	//�E����0.0f ������1.0f

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
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_ENEMY, OBJ_ENEMY_BATTLE, 1);

}

//�A�N�V����
void CObjEnemyBattle::Action()
{
	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�ʒu�̍X�V
	g_enemy_px += m_vx;
	g_enemy_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(g_enemy_px, g_enemy_py);

}

//�h���[
void CObjEnemyBattle::Draw()
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
	dst.m_top = 0.0f + g_enemy_py;
	dst.m_left = 0.0f + g_enemy_px;
	dst.m_right = 75.0f + g_enemy_px;
	dst.m_bottom = 100.0f + g_enemy_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}