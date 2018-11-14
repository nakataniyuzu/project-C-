//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjBattleMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBattleMain::Init()
{

}

//�A�N�V����
void CObjBattleMain::Action()
{

}

//�h���[
void CObjBattleMain::Draw()
{
	CObjHeroBattle* hero = (CObjHeroBattle*)Objs::GetObj(OBJ_HERO_BATTLE);
	hero_hp = hero->GetBATTLEHP();	//��l������HP�̏����擾
	hero_mp = hero->GetBATTLEMP();	//��l������MP�̏����擾
	magic_type = hero->GetBATTLEMAGIC();	//��l������MAGIC�̏����擾


	float c[4] = { 1,1,1,1 };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	wchar_t HP[128];
	wchar_t MP[128];

	//��ʏ㕔�̃��j���[���
	Font::StrDraw(L"LEVEL�F", GAME_LEVEL_POS_X, GAME_LEVEL_POS_X, GAME_LEVEL_FONT_SIZE, c);

	Font::StrDraw(L"[NAME]", GAME_NAME_POS_X, GAME_NAME_POS_Y, GAME_NAME_FONT_SIZE, c);

	swprintf_s(HP, L"HP %d/%d", hero_hp, 15);
	Font::StrDraw(HP, GAME_HP_POS_X, GAME_HP_POS_Y, GAME_HP_FONT_SIZE, c);//HP��\��


	 //�؂���ʒu�̐ݒ�
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + (50.0f * magic_type);
	src.m_right  = 50.0f + (50.0f * magic_type);
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    =  20.0f;
	dst.m_left   = 130.0f;
	dst.m_right  = 160.0f;
	dst.m_bottom =  50.0f;
	Draw::Draw(10, &src, &dst, c, 0.0f);

	swprintf_s(MP, L"%d/%d", hero_mp, 5);
	Font::StrDraw(MP, GAME_MP_POS_X, GAME_MP_POS_Y, GAME_MP_FONT_SIZE, c);

	//Font::StrDraw(L"Inventory   �FI�L�[", GAME_INVENTORY_POS_X, GAME_INVENTORY_POS_Y, GAME_INVENTORY_FONT_SIZE, c);

	Font::StrDraw(L"���j���[��ʁFE�L�[", GAME_MENU_POS_X, GAME_MENU_POS_Y, GAME_MENU_FONT_SIZE, c);

	Font::StrDraw(L"�G�̌��j���~��", GAME_ENEMY_KILLS_POS_X, GAME_ENEMY_KILLS_POS_Y, GAME_ENEMY_KILLS_FONT_SIZE, c);
}