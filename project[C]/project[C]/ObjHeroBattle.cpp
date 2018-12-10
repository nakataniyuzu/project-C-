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
	m_battle_magic = 0;

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
	//�G�̏��������Ă���
	CObjEnemy1Battle* benemy1 = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);
	CObjEnemy2Battle* benemy2 = (CObjEnemy2Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_SECOND);
	CObjBoss1Battle* bboss1 = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);

	//��l���̏��������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_hp = hero->GetHP();	//��l������HP�̏����擾
	m_battle_mp = hero->GetMP();	//��l������MP�̏����擾
	m_battle_magic = hero->GetMAGIC();	//��l������MAGIC�̏����擾

	m_battle_flag = hero->GetBATTLE();
	m_boss_battle_f = hero->GetBOSSBATTLE();
	hero_posture = hero->GetPOS();	//�}�b�v��̎�l���̌������擾
	m_delete = hero->GetDELETE();

	m_fire_flag    = hero->GetFIREF();
	m_ice_flag     = hero->GetICEF();
	m_thunder_flag = hero->GetTHUNDERF();
	m_wind_flag    = hero->GetWINDF();


	if (m_battle_flag == true)
	{
		if (hero_posture == 0.0f || hero_posture == 1.0f)
		{
			m_px = 100.0f;
			m_py = 500.0f;		//�ʒu
			m_posture = 0.0f;
		}
		else if (hero_posture == 2.0f || hero_posture == 3.0f)
		{
			m_px = 600.0f;
			m_py = 500.0f;		//�ʒu
			m_posture = 1.0f;
		}

		m_vx = 0.0f;
		m_vy = 0.0f;
		return;
	}

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
		//Scene::SetScene(new CSceneMenu());
		
	}

	//A�L�[�ŋߐ�(��)�U��
	if (Input::GetVKey('A') == true)
	{
		if (m_sword_delay == 0)
		{
			//��l���̌����ɂ���čU�����������ݒ�
			if (m_posture == 0.0f) {
				m_swordwidth = 55.0f;
			}
			else if (m_posture == 1.0f) {
				m_swordwidth = -55.0f;
			}

			//���ōU��
			CObjSwordBattle* objsb = new CObjSwordBattle(m_px + m_swordwidth, m_py + 32.0f);//���I�u�W�F�N�g(�퓬)�쐬
			Objs::InsertObj(objsb, OBJ_SWORD_BATTLE, 100);		//��������I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			
			m_sword_delay = 10;
		}	
	}
	if (m_sword_delay > 0)
	{
		m_sword_delay--;
		if (m_sword_delay <= 0)
			m_sword_delay = 0;
	}
	//X�L�[�Ŗ��@��؂�ւ���
	if (Input::GetVKey('X') == true)
	{
		if (m_mf == true) {	//�L�[����p
			m_mf = false;
			m_battle_magic += 2;
		}
		if (m_battle_magic == 1 && m_ice_flag == false) {	//�X���@���擾���Ȃ��Ɣ��������Ȃ�
			m_battle_magic = 0;
		}
		if (m_battle_magic == 2 && m_wind_flag == false) {	//�����@���擾���Ȃ��Ɣ��������Ȃ�
			m_battle_magic = 0;
		}
		if (m_battle_magic == 3 && m_thunder_flag == false) {//�����@���擾���Ȃ��Ɣ��������Ȃ�
			m_battle_magic = 0;
		}
		if (m_battle_magic >= 4) {
			m_battle_magic = 0;
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

				if (m_battle_magic == 0)	//�΂̖��@
				{
					CObjFireBattle* objfb = new CObjFireBattle(m_px + m_directionx, m_py + m_directiony);//Ice�I�u�W�F�N�g(�퓬)�쐬
					Objs::InsertObj(objfb, OBJ_FIRE_BATTLE, 100);		//�����Ice�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
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

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);

	//�U�����󂯂���̗͂����炷
	if (hit->CheckElementHit(ELEMENT_ENEMY_BATTLE) == true
		|| hit->CheckElementHit(ELEMENT_BOSS_BATTLE) == true)
	{
		//�m�b�N�o�b�N����
		if (m_posture == 0.0f)
		{
			m_vy = -15;
			m_vx -= 20;
		}
		else if (m_posture == 1.0f)
		{
			m_vy = -15;
			m_vx += 20;
		}
		m_time = 80;		//���G���Ԃ��Z�b�g
		hit->SetInvincibility(true);	//���G�I��

		//�G(1�w��)
		if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_FIRST) != nullptr)
		{
			CObjEnemy1Battle* e1b = (CObjEnemy1Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_FIRST);
			m_damage = e1b ->GetDMG();
			m_battle_hp -= m_damage;
		}
		//�G(2�w��)
		if (hit->CheckObjNameHit(OBJ_ENEMY_BATTLE_SECOND) != nullptr)
		{
			CObjEnemy2Battle* e2b = (CObjEnemy2Battle*)Objs::GetObj(OBJ_ENEMY_BATTLE_SECOND);
			m_damage = e2b ->GetDMG();
			m_battle_hp -= m_damage;
		}
		//�{�X(1�w��)
		if (hit->CheckObjNameHit(OBJ_BOSS_BATTLE_FIRST) != nullptr)
		{
			CObjBoss1Battle* bs1b = (CObjBoss1Battle*)Objs::GetObj(OBJ_BOSS_BATTLE_FIRST);
			m_damage = bs1b ->GetDMG();
			m_battle_hp -= m_damage;
		}
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
		if (hero_posture == 0.0f || hero_posture == 1.0f) {

			hero->SetFADEF(false);	//�t�F�C�h�t���O���I�t
			CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
			Objs::InsertObj(fade, OBJ_FADEIN, 200);

			if (m_delete == true){
				if (benemy1 != nullptr) {
					benemy1->SetENEMYDELETE(true);
				}
			}
			else {
				if (benemy1 != nullptr) {
					bboss1->SetBOSSDELETE(true);
				}
			}

		}
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
		if (hero_posture == 2.0f || hero_posture == 3.0f) {

			hero->SetFADEF(false);	//�t�F�C�h�t���O���I�t
			CObjFadein* fade = new CObjFadein();	//�t�F�C�h�C���̍쐬
			Objs::InsertObj(fade, OBJ_FADEIN, 200);

			if (m_delete == true) {
				if (benemy1 != nullptr) {
					benemy1->SetENEMYDELETE(true);
				}
			}
			else {
				if (benemy1 != nullptr) {
					bboss1->SetBOSSDELETE(true);
				}
			}
		}
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0f - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}

	hero->SetHP(m_battle_hp);
	hero->SetMP(m_battle_mp);
	hero->SetMAGIC(m_battle_magic);
}

//�h���[
void CObjHeroBattle::Draw()
{
	if (m_battle_flag == true)
	{
		return;
	}

	int AniData[4] =
	{
		0,1,2,3,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   = 60.0f + AniData[m_ani_frame] *60;
	src.m_right  =  0.0f + AniData[m_ani_frame] *60;
	src.m_bottom = 60.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//�`��
	if (m_time > 0){
		Draw::Draw(11, &src, &dst, a, 0.0f);
	}
	else {
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}

}