//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy2Battle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjEnemy2Battle::Init()
{
	m_px = 600.0f;//�ʒu
	m_py = 450.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	
	m_enemy_hp = 5;     //�G�̃q�b�g�|�C���g(�ő�10)
	m_damage = 2;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_posture = 1.0f;	//�E����0.0f ������1.0f
	m_move = true;  //true=�E false=��
	enemy_delete_flag = false;	//�G���Ńt���O
	m_pop_flag = true;	//�G�����p�t���O

	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 88;
	m_eff.m_bottom = 100;

	m_ani = 0;
	m_ani_time_d = 0;
	m_del = false;
	m_eff_flag = false;

	m_subtract = 0;		//HERO�Ƃ̋���
	m_hero_position = 0;//HERO�̈ʒu

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	m_time_d = 0;
	m_ice_time = 0;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_ENEMY_BATTLE, OBJ_ENEMY_BATTLE_SECOND, 1);
}

//�A�N�V����
void CObjEnemy2Battle::Action()
{
	//OBJ_MAIN�̏��������Ă���
	CObjMain* main = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	m_hero_posture = hero->GetPOS();
	m_boss_flag = hero->GetBOSSF();
	//�퓬���̎�l���̏��������Ă���
	CObjHeroBattle* herob = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	m_hero_position = herob->GetX();

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
	if (enemy_delete_flag == true)
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
		if (m_hero_posture == 0.0f || m_hero_posture == 1.0f)
		{
			m_px = 700.0f;
			m_py = 500.0f;		//�o���ʒu
			m_move = true;	//����
		}
		if (m_hero_posture == 2.0f || m_hero_posture == 3.0f)
		{
			m_px = 0.0f;
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

	//��l���Ƃ̈ʒu�֌W
	m_subtract = m_hero_position - m_px;
	if (m_subtract < 0)
	{
		m_move = true;
	}
	else 
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
		//��l�����u���b�N�Ƃǂ̊p�x�œ������Ă���̂����m�F
		HIT_DATA** hit_date;							//�����������ׂ̍��ȏ������邽�߂̍\����
		hit_date = hit->SearchElementHit(ELEMENT_ATTACK);	//hit_date�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		float r = 0;
		for (int i = 0; i < 10; i++) {
			if (hit_date[i] != nullptr) {
				r = hit_date[i]->r;
			}
		}
		//�m�b�N�o�b�N����
		if ((r < 45 && r >= 0) || r > 315)
		{
			m_vy = -10;
			m_vx -= 25;
		}
		if (r > 135 && r < 225)
		{
			m_vy = -10;
			m_vx += 25;
		}
		m_time_d = 30;
		m_enemy_hp -= 1;
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

	if (m_time_d > 0)
	{
		m_time_d--;
		if (m_time_d <= 0)
		{
			m_time_d = 0;
		}
	}

	//�G�̗̑͂�0�ɂȂ�������ŏ����Ɉڂ�
	if (m_del == false && m_enemy_hp <= 0)
	{
		if (g_xp_flag == true) {
			g_hero_max_hp_mp += 2;	//�G�̌��j����HP/MP����
			hero->SetMAXHP(2);		//HP/MP�𑝂₷
			hero->SetMAXMP(2);
			g_xpup_flag = true;	//�o���l�����t���O���I���ɂ���
		}
		hero->SetFADEF(false);	//�t�F�C�h�t���O���I�t
		g_battle_key = false;
		m_del = true;
		g_enemy_kills += 1;		//���j���𑝂₷		
	}

	//�G���̈�O�ɍs���Ȃ��悤�ɂ���
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0 - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}

	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
			Objs::InsertObj(fade, OBJ_FADEIN, 200);
			this->SetStatus(false);		//�摜�̍폜
			Hits::DeleteHitBox(this);	//�q�b�g�{�b�N�X�̍폜
			m_time = 0;
		}
	}

	//�G���ŏ���------		
	if (m_del == true)
	{
		//���S�A�j���[�V����RECT���
		RECT_F ani_src[3] =
		{
			{ 0,  0, 88, 100 },
			{ 0,105,205, 100 },
			{ 0,210,312, 100 },
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
			m_time = 20;		//�t�F�C�h�C���ڍs�p�̊Ԋu�ݒ�
		}
		return;
	}
}

//�h���[
void CObjEnemy2Battle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float a[4] = { 10.0f,0.6f,0.6f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top    =   0.0f + m_py;
	dst.m_left   = (        75.0f * m_posture) + m_px;
	dst.m_right  = (75.0f - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	if (m_del == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    = 0.0f;
		src.m_left   = 210.0f;
		src.m_right  = 312.0f;
		src.m_bottom = 100.0f;
		if (m_eff_flag == true)
			Draw::Draw(23, &src, &dst, c, 0.0f);
		else
			Draw::Draw(23, &m_eff, &dst, c, 0.0f);//���S�A�j���[�V�����`��
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    = 150.0f;
		src.m_left   =   0.0f;
		src.m_right  =  50.0f;
		src.m_bottom = 200.0f;
		//�`��
		if (m_time_d > 0) {
			Draw::Draw(7, &src, &dst, a, 0.0f);
		}
		else if (m_speed_power == 0.0f) {
			Draw::Draw(7, &src, &dst, b, 0.0f);
		}
		else {
			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}

}