//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBattle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjEnemyBattle::Init()
{
	g_enemy_px = 600.0f;//�ʒu
	g_enemy_py = 580.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0f ������1.0f
	m_enemy_hp = 3;     //�G�̃q�b�g�|�C���g(�ő�3)

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_move = true;  //true=�E false=��

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, g_enemy_px, g_enemy_py, 75, 100, ELEMENT_ENEMY, OBJ_ENEMY_BATTLE, 1);

}

//�A�N�V����
void CObjEnemyBattle::Action()
{
	//�ʏ푬�x
	m_speed_power = 0.4f;
	m_ani_max_time = 4;

	//��ʒ[�Փ˂Ō����ύX
	if (g_enemy_px + 75 >= 800)
	{
		m_move = true;
	}

	if (g_enemy_px  <= 0)
	{
		m_move = false;
	}

	//����
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//���R�����^��
	//m_vy += 15.8 / (16.0f);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�ʒu�̍X�V
	g_enemy_px += m_vx;
	g_enemy_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(g_enemy_px, g_enemy_py);

	//�U�����󂯂���̗͂����炷
	if (hit->CheckObjNameHit(OBJ_ICE_BATTLE) != nullptr)
	{
		m_enemy_hp -= 1;
	}
	if (hit->CheckObjNameHit(OBJ_THUNDER_BATTLE) != nullptr)
	{
		m_enemy_hp -= 1;
	}

	//�G�̗̑͂�0�ɂȂ�����j��
	if (m_enemy_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�G���̈�O�ɍs���Ȃ��悤�ɂ���
	if (g_enemy_px + 75 >= 800)
	{
		g_enemy_px = 800.0 - 75.0f;
	}

	if (g_enemy_px < 0)
	{
		g_enemy_px = 0.0f;
	}

	if (g_enemy_py + 100 >= 580)
	{
		g_enemy_py = 580.0 - 100.0f;
	}

	if (g_enemy_py <50)
	{
		g_enemy_py = 50.0f;
	}
}

//�h���[
void CObjEnemyBattle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   = 50.0f;
	src.m_right  =  0.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    =   0.0f + g_enemy_py;
	dst.m_left   = (75.0f * m_posture) + g_enemy_px;
	dst.m_right  = (75 - 75.0f * m_posture) + g_enemy_px;
	dst.m_bottom = 100.0f + g_enemy_py;

	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);

}