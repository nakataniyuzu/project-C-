//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "GameL\Audio.h"

#include "ObjMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMain::Init()
{
	m_and = 0.0f;
	m_andf = true;
}

//�A�N�V����
void CObjMain::Action()
{
	if (m_andf == true)
	{
		m_and += 0.01f;
		if (m_and >= 1.0f)
		{
			m_and = 1.0f;
			m_andf = false;
		}
	}
}

//�h���[
void CObjMain::Draw()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	hero_max_hp = hero->GetMAXHP();	//��l������MAXHP�̏����擾
	hero_max_mp = hero->GetMAXMP();	//��l������MAXMP�̏����擾
	hero_hp = hero->GetHP();	//��l������HP�̏����擾
	hero_mp = hero->GetMP();	//��l������MP�̏����擾
	magic_type = hero->GetMAGIC();	//��l������MAGIC�̏����擾
	key = hero->GetKEY();
	battle_flag = hero->GetBATTLE();

	float c[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	wchar_t HP[128];
	wchar_t MP[128];
	wchar_t KILLS[128];

	//��ʏ㕔�̃��j���[���

	swprintf_s(HP, L"HP %d/%d", hero_hp, hero_max_hp);
	Font::StrDraw(HP, GAME_HP_POS_X, GAME_HP_POS_Y, GAME_HP_FONT_SIZE, c);//HP��\��
	
	//�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + (50.0f * magic_type);
	src.m_right  = 50.0f + (50.0f * magic_type);
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 5.0f;
	dst.m_left   = 125.0f;
	dst.m_right  = 165.0f;
	dst.m_bottom = 45.0f;
	Draw::Draw(10, &src, &dst, c, 0.0f);

	swprintf_s(MP, L"MP %d/%d",  hero_mp, hero_max_mp);
	Font::StrDraw(MP, GAME_MP_POS_X, GAME_MP_POS_Y, GAME_MP_FONT_SIZE, c);

	if (key == 1 && g_battle_flag == false)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top    =  0.0f;
		src.m_left   =  50.0f;
		src.m_right  = 100.0f;
		src.m_bottom =  50.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top    =   0.0f;
		dst.m_left   = 500.0f;
		dst.m_right  = 530.0f;
		dst.m_bottom =  30.0f;
		Draw::Draw(HEALKEY, &src, &dst, c, 0.0f);
	}

	if (g_battle_flag == true)
	{
		Font::StrDraw(L"X�L�[�Ŗ��@�U��", GAME_MESSAGE_POS_X, GAME_MESSAGE_POS_Y, GAME_MESSAGE_FONT_SIZE, c);

		Font::StrDraw(L"���L�[�Ő؂�ւ�", GAME_MESSAGE2_POS_X, GAME_MESSAGE2_POS_Y, GAME_MESSAGE2_FONT_SIZE, c);

		Font::StrDraw(L"Z�L�[�Œʏ�U��", 400, GAME_MESSAGE_POS_Y, GAME_MESSAGE_FONT_SIZE, c);

		Font::StrDraw(L"��L�[�ŃW�����v", 400, GAME_MESSAGE2_POS_Y, GAME_MESSAGE2_FONT_SIZE, c);

	}
	else
	{
		Font::StrDraw(L"Z�L�[�Ŗ��@", GAME_MESSAGE_POS_X, GAME_MESSAGE_POS_Y, GAME_MESSAGE_FONT_SIZE, c);

		Font::StrDraw(L"X�L�[�Ő؂�ւ�", GAME_MESSAGE2_POS_X, GAME_MESSAGE2_POS_Y, GAME_MESSAGE2_FONT_SIZE, c);
	}
	
	swprintf_s(KILLS, L"�G�̌��j���~%d", g_enemy_kills);
	Font::StrDraw(KILLS, GAME_ENEMY_KILLS_POS_X, GAME_ENEMY_KILLS_POS_Y, GAME_ENEMY_KILLS_FONT_SIZE, c);

}