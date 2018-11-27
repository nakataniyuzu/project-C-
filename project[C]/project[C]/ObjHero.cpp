//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjBlock.h"

float g_px = 375.0f;
float g_py = 300.0f;

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	m_speed_power = 0.2f;	//�ʏ푬�x
	m_posture = 2.0f;
	
	m_max_hp = 10;
	m_max_mp = 5;
	m_hp = 10;	//����HP
	m_mp = 5;	//����MP
	m_magic = 0;	//�������@
	m_key = 0;

	//�t���O�̏�����
	m_gate_mf = false;
	m_water_mf = false;
	m_key_mf = false;
	m_ice_mf = false;

	m_battle_flag = true;

	m_ani_time = 0;
	m_ani_frame = 0;	//�Î~�t���[���������ɂ���
	m_ani_max_time = 8;		//�A�j���[�V�����Ԋu��(���₹�Βx��

	m_fire_flag = true;		//�΁F0
	m_ice_flag = false;		//�X�F1
	m_wind_flag = false;	//���F2
	m_thunder_flag = false;	//���F3

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up    = false;
	m_hit_down  = false;
	m_hit_left  = false;
	m_hit_right = false;

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, g_px, g_py, ALL_SIZE, ALL_SIZE, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//�A�N�V����
void CObjHero::Action()
{
	if (m_battle_flag == false)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;
		return;
	}
	
	//E�L�[�Ń��j���[���J��
	if (Input::GetVKey('E') == true)
	{
		//Scene::SetScene(new CSceneMenu());
		m_battle_flag = false;
	}

	//X�L�[�Ŗ��@��؂�ւ���
	if (Input::GetVKey('X') == true)
	{
		if (m_mf == true) {	//�L�[����p
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
				}
				else if (m_magic == 1)	//�X�̖��@
				{
					CObjIce* obji = new CObjIce(g_px + m_directionx, g_py + m_directiony);//Ice�I�u�W�F�N�g�쐬
					Objs::InsertObj(obji, OBJ_ICE, 120);		//�����Ice�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
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
				}
				m_f = false;
				m_mp -= 1;		//MP�����炷
				m_hp -= 3;		//HP�����炷�i�f�o�b�O�j
			}
		}
		else
		{
			m_f = true;
		}
	}

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= m_speed_power;
		m_posture = 0.0f;	//��
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;	//�E
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += m_speed_power;
		m_posture = 2.0f;	//��
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 3.0f;	//��
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

	//�G��ڐG������BATTLESCENE�Ɉڍs
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		m_battle_flag = false;
		//Scene::SetScene(new CSceneBattle());
	}
	if (hit->CheckObjNameHit(OBJ_KEY) != nullptr)	//�L�[���擾
	{
		m_key = 1;
		m_key_mf = true;
	}
	if (hit->CheckObjNameHit(OBJ_GATE) != nullptr)
	{
		if (m_key == 1)		//���������Ă���ꍇ
		{
			m_key = 0;		//���������
			m_gate_mf = true;//���̃t���O���I���ɂ���
		}
	}
	if (hit->CheckObjNameHit(ITEM_ICE) != nullptr)
	{
		m_ice_mf = true;
		m_ice_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_WATER) != nullptr)
	{
		m_water_mf = true;
	}
	if (hit->CheckObjNameHit(OBJ_HEAL) != nullptr)	//��l����HEAL�Ɠ��������ꍇ
	{
		m_hp = m_max_hp;		//HP���ő�܂ŉ�
		m_mp = m_max_mp;		//MP���ő�܂ŉ�
	}

	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&g_px, &g_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//�ʒu�̍X�V
	g_px += m_vx;
	g_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(g_px, g_py);
	
	
}

//�h���[
void CObjHero::Draw()
{
	if (m_battle_flag == false)
	{
		return;
	}

	int AniDate[4] =
	{
		1 , 2 , 1 , 0 ,
	};	

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 32.0f * m_posture;
	src.m_left   =  0.0f + AniDate[m_ani_frame] * 24;
	src.m_right  = 24.0f + AniDate[m_ani_frame] * 24;
	src.m_bottom = 32.0f + (32.0f * m_posture);

	//�\���ʒu�̐ݒ�
	dst.m_top    =  0.0f + g_py;
	dst.m_left   =  0.0f + g_px;
	dst.m_right  = ALL_SIZE + g_px;
	dst.m_bottom = ALL_SIZE + g_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
	
}