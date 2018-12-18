//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBoss3Battle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBoss3Battle::Init()
{
	m_px = 300.0f;
	m_py = 500.0f;		//�o���ʒu

	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_boss_hp = 50;     //�G�̃q�b�g�|�C���g(�ő�50)
	m_damage = 5;
	m_delay = 5;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���
	m_posture = 0.0f;	//�E����0.0f ������1.0f

	m_speed_power = 1.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��
	m_pop_flag = true;
	m_move = true;  //true=�E false=��

	m_time = 0;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_BOSS_BATTLE, OBJ_BOSS_BATTLE_THIRD, 1);
}

//�A�N�V����
void CObjBoss3Battle::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_boss_flag = hero->GetBATTLE();
	hero_posture = hero->GetPOS();
	enemy_flag = hero->GetENEMYF();

	if (boss_delete_flag == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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

	if (g_battle_flag == false)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;
		m_pop_flag = true;
		return;
	}

	
	//�{�X�̌����ɂ���Ĕ��˂��������ݒ�
	if (m_posture == 0.0f) {
		m_directionx = 50.0f;
		m_directiony = 0.0f;
	}
	else if (m_posture == 1.0f) {
		m_directionx = -50.0f;
		m_directiony = 0.0f;
	}

	//��ʒ[�Փ˂Ō����ύX�����@����
	if (m_delay <= 0)
	{
		if (m_px + 75 >= 800)
		{
			m_move = true;
			CObjEnemyMagicBattle* objemb = new CObjEnemyMagicBattle(m_px - m_directionx, m_py + m_directiony);
			Objs::InsertObj(objemb, OBJ_ENEMY_MAGIC_BATTLE, 100);
			m_delay = 2;
			Audio::Start(5);
		}
		else if (m_px <= 0)
		{
			m_move = false;
			CObjEnemyMagicBattle* objemb = new CObjEnemyMagicBattle(m_px + m_directionx, m_py + m_directiony);
			Objs::InsertObj(objemb, OBJ_ENEMY_MAGIC_BATTLE, 100);
			m_delay = 2;
			Audio::Start(5);
		}
	}
	else
	{
		m_delay--;
	}

	/*CObjEnemyMagicBattle* objemb = new CObjEnemyMagicBattle(m_px + m_directionx, m_py + m_directiony);
	Objs::InsertObj(objemb, OBJ_ENEMY_MAGIC_BATTLE, 100);*/	

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

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);


	//�U�����󂯂���̗͂����炷
	//��l����ATTACK�n���Ƃ̓����蔻��
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		//�m�b�N�o�b�N����
		if (m_posture == 1.0f)
		{
			m_vy = -10;
			m_vx -= 5;
		}
		else if (m_posture == 0.0f)
		{
			m_vy = -10;
			m_vx += 5;
		}
		m_time = 80;		//���G���Ԃ��Z�b�g
		hit->SetInvincibility(true);	//���G�I��
		m_boss_hp -= 1;
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
	//�G�̗̑͂�0�ɂȂ�����j��
	if (m_boss_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�G���̈�O�ɍs���Ȃ��悤�ɂ���
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		m_speed_power = 1.0f;
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
		m_speed_power = 1.0f;
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
	/*if (m_time >= 0)
	{
		m_time++;

		if (m_time >= 80)
		{
			m_speed_power = 0.0f;

			if (m_time >= 120)
			{
				m_speed_power = 20.0f;
				m_time = 0;
			}
		}
	}*/
}

//�h���[
void CObjBoss3Battle::Draw()
{
	if (m_boss_flag == true)
	{
		return;
	}

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	if (m_move == true)//������
	{
		src.m_top = 0.0f;
		src.m_left = 265.0f;
		src.m_right = 500.0f;
		src.m_bottom = 250.0f;
	}
	if (m_move == false)//�E����
	{
		m_posture = 0.0f;
		src.m_top = 0.0f;
		src.m_left = 770.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 250.0f;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (75.0f * m_posture) + m_px;
	dst.m_right = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//�`��
	if (m_time > 0) {
		Draw::Draw(22, &src, &dst, a, 0.0f);
	}
	else {
		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
}