//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy1Battle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjEnemy1Battle::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_enemy_hp = 3;     //�G�̃q�b�g�|�C���g(�ő�3)
	m_damage = 1;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_move = true;  //true=�E false=��
	enemy_delete_flag = false;	//�G���Ńt���O
	m_pop_flag = true;	//�G�����p�t���O

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	m_eff.m_top    =  0;
	m_eff.m_left   =  0;
	m_eff.m_right  = 50;
	m_eff.m_bottom = 50;

	m_ani = 0;
	m_ani_time_d = 0;
	m_del = false;
	
	m_eff_flag = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_ENEMY_BATTLE, OBJ_ENEMY_BATTLE_FIRST, 1);
}

//�A�N�V����
void CObjEnemy1Battle::Action()
{
	//OBJ_MAIN�̏��������Ă���
	CObjMain* main = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero_posture = hero->GetPOS();

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

	if (enemy_delete_flag == true)
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
			m_px = 700.0f;
			m_py = 500.0f;		//�o���ʒu
			m_move = true;	//����
		}
		if (hero_posture == 2.0f || hero_posture == 3.0f)
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

	//��ʒ[�Փ˂Ō����ύX
	if (m_px + 75 >= 800)
	{
		m_move = true;
	}
	if (m_px  <= 0)
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
	{/*
		//��l�����u���b�N�Ƃǂ̊p�x�œ������Ă���̂����m�F
		HIT_DATA** hit_date;							//�����������ׂ̍��ȏ������邽�߂̍\����
		hit_date = hit->SearchElementHit(ELEMENT_ATTACK);	//hit_date�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)
		{
			float r = hit_date[i]->r;
			//�p�x�ŏ㉺���E�𔻒�
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
			
		}*/
		//�m�b�N�o�b�N����
		if (m_posture == 1.0f)
		{
			m_vy = -10;
			m_vx -= 25;
		}
		else if (m_posture == 0.0f)
		{
			m_vy = -10;
			m_vx += 25;
		}

		m_enemy_hp -= 1;
	}

	
	//�G�̗̑͂�0�ɂȂ�����j��CObjMain
	if (m_enemy_hp <= 0)
	{
		hero->SetFADEF(false);	//�t�F�C�h�t���O���I�t
		m_eff_flag = true;
		m_del = true;
		main->SetENEMYKILLS(1);
		/*this->SetStatus(false);
		Hits::DeleteHitBox(this);*/
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

	//�G���ŏ���------	
	if (m_eff_flag == true)
	{
		if (m_del == true)
		{
			//���S�A�j���[�V����RECT���
			RECT_F ani_src[3] =
			{
				{ 0,  0, 50, 50 },
				{ 0, 50,100, 50 },
				{ 0,100,150, 50 },
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
				m_eff_flag = false;
			}
			return;
		}
	}
	

	//�����蔻����s���I�u�W�F�N�g���
	/*int data_base[1] =
	{
		OBJ_SWORD_BATTLE,
	};

	//�I�u�W�F�N�g���Q�Ɠ����蔻��s���B�������Ă���΍폜
	for (int i = 0; i < 1; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			m_del = true;
			hit->SetInvincibility(true);
		}
	}*/
}

//�h���[
void CObjEnemy1Battle::Draw()
{


	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top    =   0.0f + m_py;
	dst.m_left   = (75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//�G�̏�Ԃŕ`���ύX
	if (m_del == true)
	{
		//���S�A�j���[�V�����`��
		Draw::Draw(23, &m_eff, &dst, c, 0.0f);
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 50.0f;
		src.m_right = 0.0f;
		src.m_bottom = 50.0f;
		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
}