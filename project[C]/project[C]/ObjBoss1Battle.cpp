//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBoss1Battle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBoss1Battle::Init()
{
	m_px = 300.0f;
	m_py = 500.0f;		//�o���ʒu

	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_boss_hp = 15;     //�G�̃q�b�g�|�C���g(�ő�15)
	m_damage = 2;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��
	
	m_posture = 0.0f;	//0.0f=�� 1.0f=�E
	m_move = true;  //true=�E false=��
	boss_delete_flag = false;	//�{�X���Ńt���O
	m_pop_flag = true;	//�{�X�����p�t���O
	m_ice_time = 0;

	m_eff.m_top    =   0;
	m_eff.m_left   =   0;
	m_eff.m_right  =  82;
	m_eff.m_bottom = 100;

	m_ani = 0;
	m_ani_time_d = 0;
	m_del = false;
	m_eff_flag = false;

	m_time = 0;
	m_time_f = 0;
	m_time_d = 0;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_BOSS_BATTLE, OBJ_BOSS_BATTLE_FIRST, 1);
}

//�A�N�V����
void CObjBoss1Battle::Action()
{
	//OBJ_MAIN�̏��������Ă���
	CObjMain* main = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero_posture = hero->GetPOS();
	//�퓬���̎�l���̏��������Ă���
	CObjHeroBattle* herob = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);

	//���C
	m_vx += -(m_vx * 0.098f);
	m_vy += -(m_vy * 0.098f);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//���R�����^��
	m_vy += 9.8f / (16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);
	//��l�����}�b�v��ʂɈڍs�����ꍇ�A������G���폜
	if (boss_delete_flag == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//�o�g�����̎�l�������S�����ꍇ�A�������~�߂�
	if (herob->GetINPUTF() == false)
	{
		return;
	}

	//�}�b�v��̎�l���̌����ɂ���ă��X�ʒu�A������ݒ�
	if (m_pop_flag == true)
	{
		if (hero_posture == 0.0f || hero_posture == 1.0f)
		{
			m_px = 600.0f;
			m_py = 500.0f;		//�o���ʒu
			m_move = true;	//����
		}
		else if (hero_posture == 2.0f || hero_posture == 3.0f)
		{
			m_px = 100.0f;
			m_py = 500.0f;		//�o���ʒu
			m_move = false;	//����
		}
		m_pop_flag = false;	//�����p�t���O
	}

	//�}�b�v�ւ̈ڍs
	if (g_battle_flag == false)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;
		m_pop_flag = true;
		return;
	}

	//��ʒ[�Փ˂Ō����ύX
	if (m_px + 75 >= 800)
	{
		m_move = true;
	}
	if (m_px <= 0)
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

	//�U�����󂯂���̗͂����炷
	//��l����ATTACK�n���Ƃ̓����蔻��
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		m_boss_hp -= 1;
		m_time_d = 30;
	}
	if (m_time_d > 0)
	{
		m_time_d--;
		if (m_time_d <= 0)
		{
			m_time_d = 0;
		}
	}
	if (hit->CheckObjNameHit(OBJ_ICE_BATTLE) != nullptr)	//���@�i�A�C�X�j�𓖂������ꍇ
	{
		m_ice_time = 100;	//icetime�Ɏ��Ԃ��Z�b�g
	}
	if (m_ice_time > 0)
	{
		m_ice_time--;		//�����𐧌�
		m_speed_power = 0.0f;
		if (m_ice_time <= 0) {
			m_ice_time = 0;
			m_speed_power = 0.4f;
		}
	}
	//�G�̗̑͂�0�ɂȂ�������ŏ����Ɉڂ�
	if (m_del == false && m_boss_hp <= 0)
	{
		hero->SetFADEF(false);
		g_hero_max_hp_mp += 2;	//�G�̌��j����HP/MP����
		hero->SetMAXHP(2);		//HP/MP�𑝂₷
		hero->SetMAXMP(2);
		g_xpup_flag = true;	//�o���l�����t���O���I���ɂ���
		m_del = true;
		g_enemy_kills += 1;
		g_boss_kills += 1;
		g_battle_key = false;
	}

	//�G���̈�O�ɍs���Ȃ��悤�ɂ���
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		m_speed_power = 0.5f;
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
		m_speed_power = 0.5f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0 - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}

	//�ːi
	if (m_time >= 0)
	{
		m_time++;

		if (m_time >= 80)
		{
			m_speed_power = 0.0f;

			if (m_time >= 120)
			{
				m_speed_power = 20.0f;
				m_time = 0;
				Audio::Start(6);
			}
		}
	}

	if (m_time_f > 0) {
		m_time_f--;
		if (m_time_f <= 0) {

			CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
			Objs::InsertObj(fade, OBJ_FADEIN, 200);
			m_time_f = 0;
			this->SetStatus(false);		//�摜�̍폜
			Hits::DeleteHitBox(this);	//�q�b�g�{�b�N�X�̍폜
		}
	}

	//�G���ŏ���------		
	if (m_del == true)
	{
		//���S�A�j���[�V����RECT���
		RECT_F ani_src[3] =
		{
			{ 0,  0, 82, 100 },
			{ 0, 96,195, 100 },
			{ 0,210,318,  79 },
		};

		//�A�j���[�V�����̃R�}�Ԋu����
		if (m_ani_time_d > 5)
		{
			m_ani++;	//�A�j���[�V�����̃R�}��1�i�߂�
			m_ani_time_d = 0;

			m_eff = ani_src[m_ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗڂ�RECT���擾
		}
		else
		{
			m_ani_time_d++;
		}

		//���S�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_ani == 3)
		{
			hit->SetInvincibility(true);	//���G�ɂ���
			m_speed_power = 0.0f;			//�������~�߂�
			m_eff_flag = true;			//�摜�؂�ւ��p�t���O
			m_time_f = 20;		//�t�F�C�h�C���ڍs�p�̊Ԋu�ݒ�
			m_time = 0;
		}
		return;
	}
	
}

//�h���[
void CObjBoss1Battle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 10.0f,0.6f,0.6f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//�G�̏�Ԃŕ`���ύX
	if (m_del == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    =   0.0f;
		src.m_left   = 210.0f;
		src.m_right  = 318.0f;
		src.m_bottom = 79.0f;
		if (m_eff_flag == true)
			Draw::Draw(25, &src, &dst, c, 0.0f);
		else
			Draw::Draw(25, &m_eff, &dst, c, 0.0f);//���S�A�j���[�V�����`��
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    =   0.0f;
		src.m_left   = 200.0f;
		src.m_right  = 100.0f;
		src.m_bottom = 100.0f;
		//�`��
		if (m_time_d > 0) {
			Draw::Draw(14, &src, &dst, a, 0.0f);
		}
		else if (m_ice_time > 0) {
			Draw::Draw(14, &src, &dst, b, 0.0f);
		}
		else {
			Draw::Draw(14, &src, &dst, c, 0.0f);
		}
	}
}