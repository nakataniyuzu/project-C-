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

	//�������̖��@�Ő퓬�ɓ���Ȃ��悤�ɂ��邽�߂̏���
	if (m_battle_magic == 0 || m_battle_magic == 2)
	{
		m_battle_magic = 1;
	}
	
	m_px = 100.0f;
	m_py = 450.0f;		//�ʒu
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;	//�E����0.0f ������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.7f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_sword_delay = 0;

	m_swordwidth = 0.0f; //�\�[�h��


	//�����蔻��p��HitBox���쐬
 	Hits::SetHitBox(this, m_px , m_py , 60, 100, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
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

	//E�L�[�Ń��j���[���J��
	if (Input::GetVKey('E') == true)
	{
		Scene::SetScene(new CSceneMenu());
	}

	//A�L�[�ŋߐ�(��)�U��
	if (Input::GetVKey('A') == true)
	{
		if (m_sword_delay == 0)
		{
			//��l���̌����ɂ���čU�����������ݒ�
			if (m_posture == 0.0f) {
				m_directionx = 7.0f;
				m_directiony = 0.0f;
				m_swordwidth = 50.0f;
			}
			else if (m_posture == 1.0f) {
				m_directionx = -7.0f;
				m_directiony = 0.0f;
				m_swordwidth = -30.0f;
			}

			//���ōU��
			CObjSwordBattle* objsb = new CObjSwordBattle(m_px + m_directionx+ m_swordwidth, m_py + m_directiony+35.0f);//���I�u�W�F�N�g(�퓬)�쐬
			Objs::InsertObj(objsb, OBJ_SWORD_BATTLE, 100);		//��������I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			
			m_sword_delay = 10;
		}
		else if (m_sword_delay > 0)
		{
			m_sword_delay--;
			if (m_sword_delay <= 0)
				m_sword_delay = 0;
		}
	}


	//X�L�[�Ŗ��@��؂�ւ���
	if (Input::GetVKey('X') == true)
	{
		if (m_mf == true) {	//�L�[����p
			m_mf = false;
			m_battle_magic += 2;
		}
		if (m_battle_magic >= 4) {
			m_battle_magic = 1;
		}
	}
	else
	{
		m_mf = true;
	}
	if (m_battle_mp > 0) {
		if (Input::GetVKey('Z') == true)	//���@����
		{
			if (m_f == true) {	//���@����p

				//��l���̌����ɂ���Ĕ��˂��������ݒ�
				if (m_posture == 0.0f) {
					m_directionx = 50.0f;
					m_directiony = 0.0f;
				}
				else if (m_posture == 1.0f) {
					m_directionx = -50.0f;
					m_directiony = 0.0f;
				}

				if (m_battle_magic == 1)	//�X�̖��@
				{
					CObjIceBattle* objib = new CObjIceBattle(m_px + m_directionx, m_py + m_directiony);//Ice�I�u�W�F�N�g(�퓬)�쐬
					Objs::InsertObj(objib, OBJ_ICE_BATTLE, 100);		//�����Ice�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
				}
				else if (m_battle_magic == 3)	//���̖��@
				{
					CObjThunderBattle* objtb = new CObjThunderBattle(m_px + m_directionx, m_py + m_directiony);//Thunder�I�u�W�F�N�g(�퓬)�쐬
					Objs::InsertObj(objtb, OBJ_THUNDER_BATTLE, 100);		//�����Thunder�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
				}
				m_f = false;
				m_battle_mp -= 1;		//MP�����炷
			}
		}
		else
		{
			m_f = true;
		}
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//���R�����^��
	m_vy += 15.8 / (16.0f);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�œ������Ă��邩���m�F
		HIT_DATA** hit_data;	//�����������ׂ̍��ȏ������邽�߂̍\����
		hit_data = hit->SearchObjNameHit(OBJ_ENEMY_BATTLE);//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//�G�̍��E�ɓ���������
			//�ۗ���
			/*if ()
			{*/

			float r = hit_data[i]->r;

				if ((r < 45 && r >= 0) || r > 315)
				{
					m_vx = -5.0f;//���Ɉړ�������
				}
				if (r > 135 && r < 225)
				{
					m_vx = +5.0f;//�E�Ɉړ�������
				}
				if (r > 225 && r < 315)
				{
					//�G�̈ړ���������l���̈ʒu�ɉ��Z
					/*m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();

					CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);*/

					//���ɏ悹�鏈��
					if (m_vy < -1.0f)
					{
						//�W�����v���Ă�ꍇ�͉��L�̉e�����o�Ȃ��悤�ɂ���
					}
					else
					{
						//��l�����G�̓��ɏ���Ă���̂ŁAYvec��0�ɂ��ė��������Ȃ�
						//�܂��A�n�ʂɓ������Ă��锻��ɂ���
						m_vy = 0.0f;
						m_hit_down = true;
					}
				}
			//}
		}
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);

	//�U�����󂯂���̗͂����炷
	if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE) != nullptr)
	{
		//�m�b�N�o�b�N����
		if (m_posture == 0.0f)
		{
			m_vy = -15;
			m_vx -= 10;
		}
		else if (m_posture == 1.0f)
		{
			m_vy = -15;
			m_vx += 10;
		}
		m_battle_hp -= 1;
		m_time = 60;		//���G���Ԃ��Z�b�g
		hit->SetInvincibility(true);	//���G�I��
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

	//��l���̗̑͂�0�ɂȂ�����Q�[���I�[�o�[�V�[���Ɉڍs
	if (m_battle_hp <= 0)
	{
		Scene::SetScene(new CSceneGameover());
	}

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