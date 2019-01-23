//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjHero.h"
//#include "ObjBlock.h"

float g_px;
float g_py;

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	m_speed_power = 3.0f;	//�ʏ푬�x
	m_posture = 2.0f;	// 0.0f = ��	1.0f = �E	2.0f = ��	3.0f = ��

	m_max_hp = 10 + g_hero_max_hp_mp;	//�ő�HP
	m_max_mp = 10 + g_hero_max_hp_mp;	//�ő�MP
	m_hp = m_max_hp;	//����HP
	m_mp = m_max_mp;	//����MP
	m_magic = 0;	//�������@

	m_key = 0;	//���̏��

	//�t���O�̏�����
	mes.gate = false;
	mes.water = false;
	mes.key = false;
	mes.ice = false;
	mes.wind = false;
	mes.switchblock = false;
	mes.switchgate = false;
	mes.heal = false;
	mes.allkill = false;

	m_death_flag = false;
	m_next_flag = false;
	m_battle_flag = true;
	m_ene_battle_flag = false;
	m_boss_battle_flag = false;
	m_fade_flag = false;
	m_allkill_flag1 = false;
	m_allkill_flag2 = false;
	m_allkill_flag3 = false;

	m_ani_time = 0;
	m_ani_frame = 0;	//�Î~�t���[���������ɂ���
	m_ani_max_time = 8;		//�A�j���[�V�����Ԋu��(���₹�Βx��

	m_fire_flag = true;		//�΁F0
	m_ice_flag = false;		//�X�F1
	m_wind_flag = false;	//���F2
	m_thunder_flag = false;	//���F3


	if (g_map_change >= 1) {
		m_ice_flag = true;
	}
	if (g_map_change >= 2) {
		m_wind_flag = true;
	}
	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up    = false;
	m_hit_down  = false;
	m_hit_left  = false;
	m_hit_right = false;

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	m_and = 0.0f;
	m_andf = true;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, g_px + 8, g_py + 1, 35, 47, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//�A�N�V����
void CObjHero::Action()
{
	m_max_hp = 10 + g_hero_max_hp_mp;	//�ő�HP
	m_max_mp = 10 + g_hero_max_hp_mp;	//�ő�MP

	if (g_mhit_enemy_flag == false)
	{
		m_speed_power = 1.0f;		//�ʏ푬�x


		if (m_andf == true)		//�t�F�[�h�C��
		{
			m_and += 0.01f;
			if (m_and >= 1.0f)
			{
				m_and = 1.0f;
				m_andf = false;
			}
		}
		else {		//�t�F�[�h�C�����͓��͂��󂯕t���Ȃ�
			//�o�g���t���O�A�܂��͓��͐���t���O���I���̏ꍇ�A�N�V�����𐧌䂷��
			if (g_battle_flag == true || g_key_flag == true)
			{
				m_vx = 0.0f;
				m_vy = 0.0f;
				return;
			}

			//�G���S�ł����ۂ̃��b�Z�[�W�p
			if (g_map_change == 0 && g_enemy_kills >= 5 && m_allkill_flag1 == false)
			{
				mes.allkill = true;
				m_allkill_flag1 = true;
			}
			if (g_map_change == 1 && g_enemy_kills >= 11 && m_allkill_flag2 == false)
			{
				mes.allkill = true;
				m_allkill_flag2 = true;
			}
			if (g_map_change == 2 && g_enemy_kills >= 17 && m_allkill_flag3 == false)
			{
				mes.allkill = true;
				m_allkill_flag3 = true;
			}

			//X�L�[�Ŗ��@��؂�ւ���
			if (Input::GetVKey('X') == true)
			{
				if (m_mf == true) {	//�L�[����p
					Audio::Start(15);	//�G�t�F�N�g����炷
					m_mf = false;
					m_magic += 1;
				}
				if (m_magic == 1 && m_ice_flag == false) {	//�X���@���擾���Ȃ��Ɣ��������Ȃ�
					m_magic = 0;
				}
				if (m_magic == 2 && m_wind_flag == false) {	//�����@���擾���Ȃ��Ɣ��������Ȃ�
					m_magic = 0;
				}
				if (m_magic == 3 && m_thunder_flag == false) {//�����@���擾���Ȃ��Ɣ��������Ȃ�
					m_magic = 0;
				}
				if (m_magic >= 4) {
					m_magic = 0;
				}
			}
			else
			{
				m_mf = true;
			}

			//HP��0�ȉ��̎��ɃQ�[���I�[�o�[�ɂ���
			if (m_hp <= 0)
			{
				Scene::SetScene(new CSceneGameover());
			}

			//MP��0�ȏ�̎��͖��@�����
			if (m_mp > 0) {
				if (Input::GetVKey('Z') == true)	//���@����
				{
					if (m_f == true) {	//���@����p

						//��l���̌����ɂ���Ĕ��˂��������ݒ�
						if (m_posture == 0.0f) {
							m_directionx = 0.0f;
							m_directiony = -50.0f;
						}
						else if (m_posture == 1.0f) {
							m_directionx = 50.0f;
							m_directiony = 0.0f;
						}
						else if (m_posture == 2.0f) {
							m_directionx = 0.0f;
							m_directiony = 50.0f;
						}
						else if (m_posture == 3.0f) {
							m_directionx = -50.0f;
							m_directiony = 0.0f;
						}

						if (m_magic == 0)	//�΂̖��@
						{
							CObjFire* objf = new CObjFire(g_px + m_directionx, g_py + m_directiony);//Fire�I�u�W�F�N�g�쐬
							Objs::InsertObj(objf, OBJ_FIRE, 120);		//�����Fire�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
							Audio::Start(7);
						}
						else if (m_magic == 1)	//�X�̖��@
						{
							CObjIce* obji = new CObjIce(g_px + m_directionx, g_py + m_directiony);//Ice�I�u�W�F�N�g�쐬
							Objs::InsertObj(obji, OBJ_ICE, 120);		//�����Ice�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
							Audio::Start(8);
						}
						else if (m_magic == 2)	//���̖��@
						{
							CObjWind* objw = new CObjWind(g_px + m_directionx, g_py + m_directiony);//Wind�I�u�W�F�N�g�쐬
							Objs::InsertObj(objw, OBJ_WIND, 120);		//�����Wind�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
						}
						else if (m_magic == 3)	//���̖��@
						{
							CObjThunder* objt = new CObjThunder(g_px + m_directionx, g_py + m_directiony);//Thunder�I�u�W�F�N�g�쐬
							Objs::InsertObj(objt, OBJ_THUNDER, 120);		//�����Thunder�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
							Audio::Start(9);
						}
						m_f = false;
						m_mp -= 1;		//MP�����炷
					}
				}
				else
				{
					m_f = true;
				}
			}

			//�L�[�̓��͕���
			if (Input::GetVKey(VK_LEFT) == true)
			{
				m_px -= m_speed_power;
				m_vx -= m_speed_power;
				m_posture = 3.0f;	//��
				m_ani_time += 1;
			}
			else if (Input::GetVKey(VK_RIGHT) == true)
			{
				m_px += m_speed_power;
				m_vx += m_speed_power;
				m_posture = 1.0f;	//�E
				m_ani_time += 1;
			}
			else if (Input::GetVKey(VK_UP) == true)
			{
				m_py -= m_speed_power;
				m_vy -= m_speed_power;
				m_posture = 0.0f;	//��
				m_ani_time += 1;

			}
			else if (Input::GetVKey(VK_DOWN) == true)
			{
				m_py += m_speed_power;
				m_vy += m_speed_power;
				m_posture = 2.0f;	//��
				m_ani_time += 1;
			}
			else   //�A�j���[�V��������
			{
				m_ani_frame = 0;	//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[���ɂ���
				m_ani_time = 0;
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
		}

	}
	CObjBoss1Battle* bboss1 = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);
	CObjEnemy1Battle* benemy1 = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);

	CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//���̃X�N���[�����C��
	{
		g_px = 0;
		b->SetScrollX(b->GetScrollX());
	}
	//�E�̃X�N���[�����C��
	{
		g_px = 400;
		b->SetScrollX(b->GetScrollX());
	}
	//��̃X�N���[�����C��
	{
		g_py = 0;
		b->SetScrollY(b->GetScrollY());
	}
	//���̃X�N���[�����C��
	{
		g_py = 300;
		b->SetScrollY(b->GetScrollY());
	}

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);
	//��l����MYSTTERY�n���Ƃ̓����蔻��
	if (hit->CheckElementHit(ELEMENT_MYSTERY) == true)
	{
		//��l�����u���b�N�Ƃǂ̊p�x�œ������Ă���̂����m�F
		HIT_DATA** hit_date;							//�����������ׂ̍��ȏ������邽�߂̍\����
		hit_date = hit->SearchElementHit(ELEMENT_MYSTERY);	//hit_date�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������
		for (int i = 0; i < hit->GetCount(); i++)
		{
			float r = hit_date[i]->r;
			//�p�x�ŏ㉺���E�𔻒�
			if ((r < 45 && r >= 0) || r > 315)
			{
				m_vx = -0.15f; //�E
			}
			if (r > 45 && r < 135)
			{
				m_vy = 0.15f;//��
			}
			if (r > 135 && r < 225)
			{
				m_vx = 0.15f;//��
			}
			if (r > 225 && r < 315)
			{
				m_vy = -0.15f; //��
			}
		}
	}

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)	//�G�ƐڐG������BATTLESCENE�Ɉڍs
	{
		Audio::Start(1);

		m_fade_flag = true;		//�t�F�C�h�t���O���I��
		m_ene_battle_flag = true;	//�G�o���t���O���I���ɂ���
		m_delete = true;			//�G�폜�t���O���I���ɂ���

		CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
		Objs::InsertObj(fade, OBJ_FADEIN, 200);
	}
	//�G��ڐG������BATTLESCENE�Ɉڍs(BOSS)
	if (hit->CheckElementHit(ELEMENT_BOSS) == true)
	{
		Audio::Start(1);

		m_fade_flag = true;		//�t�F�C�h�t���O���I��
		m_boss_battle_flag = true;	//�G�o���t���O���I���ɂ���
		m_delete = false;			//�G�폜�t���O���I���ɂ���

		CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
		Objs::InsertObj(fade, OBJ_FADEIN, 200);
	}
	if (hit->CheckObjNameHit(OBJ_KEY) != nullptr)	//�L�[���擾
	{
		m_key = 1;
		mes.key = true;
	}
	if (hit->CheckObjNameHit(OBJ_GATE) != nullptr)
	{
		if (m_key == 1)		//���������Ă���ꍇ
		{
			m_key = 0;		//���������
			mes.gate = true;//���̃t���O���I���ɂ���
			Audio::Start(11);     //���y�X�^�[�g
		}
	}
	if (hit->CheckObjNameHit(ITEM_ICE) != nullptr)	//��l�����X�̌����Ɠ��������ꍇ
	{
		mes.ice = true;			//�t���O���I���ɂ���
		m_ice_flag = true;
	}
	if (hit->CheckObjNameHit(ITEM_WIND) != nullptr)	//��l�������̌����Ɠ��������ꍇ
	{
		mes.wind = true;			//�t���O���I���ɂ���
		m_wind_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_WATER) != nullptr)			//��l�������Ɠ��������ꍇ
	{
		mes.water = true;		//�t���O���I���ɂ���
	}
	if (hit->CheckObjNameHit(OBJ_SWITCH) != nullptr || 
		hit->CheckObjNameHit(OBJ_BOSSSWITCH) != nullptr)	//��l�����X�C�b�`�ɐG�ꂽ�ꍇ
	{
		mes.switchblock = true;	//�t���O���I���ɂ���
	}
	if (hit->CheckObjNameHit(OBJ_SWITCHGATE) != nullptr || 
		hit->CheckObjNameHit(OBJ_BOSSGATE) != nullptr)	//��l�����Q�[�g�Ɠ��������ꍇ
	{
		mes.switchgate = true;	//�t���O���I���ɂ���
	}
	if (hit->CheckObjNameHit(OBJ_HEAL) != nullptr)	//��l����HEAL�Ɠ��������ꍇ
	{
		m_hp = m_max_hp;		//HP���ő�܂ŉ�
		m_mp = m_max_mp;		//MP���ő�܂ŉ�
		mes.heal = true;		//�t���O���I���ɂ���
		Audio::Start(10);
	}
	if (hit->CheckObjNameHit(OBJ_WINDBLOCK) != nullptr)			//��l����WIND�u���b�N�Ɠ��������ꍇ
	{
		mes.windb = true;		//�t���O���I���ɂ���
	}
	if (hit->CheckObjNameHit(OBJ_STAIRS) != nullptr)	//��l����STAIRS�Ɠ��������ꍇ
	{
		m_next_flag = true;		//�t���O���I���ɂ���
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//�u���b�N�Ƃ̓����蔻����s
	//CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//pb->BlockHit(&g_px, &g_py, true,
	//	&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
	//	&m_block_type
	//);

	//�ʒu�̍X�V
	g_px += m_vx;
	g_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(g_px + 8, g_py + 1);
	
	
}

//�h���[
void CObjHero::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}

	int AniDate[4] =
	{
		1 , 2 , 1 , 0 ,
	};	

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 64.0f * m_posture;
	src.m_left   =  0.0f + AniDate[m_ani_frame] * 64;
	src.m_right  = 64.0f + AniDate[m_ani_frame] * 64;
	src.m_bottom = 64.0f + (64.0f * m_posture);

	//�\���ʒu�̐ݒ�
	dst.m_top    =  0.0f + g_py;
	dst.m_left   =  0.0f + g_px;
	dst.m_right  = ALL_SIZE + g_px;
	dst.m_bottom = ALL_SIZE + g_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
	
}