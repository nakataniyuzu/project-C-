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
	
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_hp = hero->GetHP();	//��l������HP�̏����擾
	m_battle_mp = hero->GetMP();	//��l������MP�̏����擾
	m_battle_magic = hero->GetMAGIC();	//��l������MAGIC�̏����擾
	
	m_px = 100.0f;
	m_py = 450.0f;		//�ʒu
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;	//�E����0.0f ������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.7f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��


	//�����蔻��p��HitBox���쐬
 	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
}

//�A�N�V����
void CObjHeroBattle::Action()
{
	//�ړ��x�N�g���̔j��
	//m_vy = 0.0f;

	//�L�[�̓��͕��� 
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 0; //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;
	}
	if (m_ani_time > 8)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//Space�L�[�ŃW�����v
	if (m_py + 100 >= 549)
	{
		if (Input::GetVKey(VK_SPACE) == true)
		{
			if (1)
			{
				m_vy = -40;
			}
		}
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//���R�����^��
	m_vy += 15.8 / (16.0f);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);

	//�G�@�I�u�W�F�N�g�ƐڐG�������l���폜
	/*if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/

	//��l�����̈�O�ɍs���Ȃ��悤�ɂ���
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		Scene::SetScene(new CSceneMain());
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0f - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}
}

//�h���[
void CObjHeroBattle::Draw()
{
	int AniData[4] =
	{
		0,1,2,3,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   = 60.0f + AniData[m_ani_frame] *60;
	src.m_right  =  0.0f + AniData[m_ani_frame] *60;
	src.m_bottom = 60.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}