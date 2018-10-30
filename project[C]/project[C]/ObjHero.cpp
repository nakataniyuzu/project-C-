//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

float g_px = 50.0f;
float g_py = 100.0f;

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	m_speed_power = 0.3f;	//�ʏ푬�x

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;		//����ł���block�̎�ނ��m�F�p

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//�A�N�V����
void CObjHero::Action()
{

	//E�L�[�Ń��j���[���J��
	if (Input::GetVKey('E') == true)
	{
		Scene::SetScene(new CSceneMenu());
	}

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
	}

	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= m_speed_power;
	}

	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += m_speed_power;
	}


	//���C
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�ʒu�̍X�V
	g_px += m_vx;
	g_py += m_vy;
	
	
	//HitBox�̈ʒu�̕ύX
	hit->SetPos(g_px, g_py);

}

//�h���[
void CObjHero::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   =  0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    =  0.0f + g_py;
	dst.m_left   =  0.0f + g_px;
	dst.m_right  = 50.0f + g_px;
	dst.m_bottom = 50.0f + g_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}