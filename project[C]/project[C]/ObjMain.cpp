//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMain::Init()
{

}

//�A�N�V����
void CObjMain::Action()
{
	
}

//�h���[
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//��ʏ㕔�̃��j���[���
	Font::StrDraw(L"LEVEL�F", GAME_LEVEL_POS_X, GAME_LEVEL_POS_X, GAME_LEVEL_FONT_SIZE, c);

	Font::StrDraw(L"[NAME]", GAME_NAME_POS_X, GAME_NAME_POS_Y, GAME_NAME_FONT_SIZE, c);

	Font::StrDraw(L"HP", GAME_HP_POS_X, GAME_HP_POS_Y, GAME_HP_FONT_SIZE, c);

	Font::StrDraw(L"���@/�g�p��", GAME_MP_POS_X, GAME_MP_POS_Y, GAME_MP_FONT_SIZE, c);

	Font::StrDraw(L"Inventory   �FI�L�[", GAME_INVENTORY_POS_X, GAME_INVENTORY_POS_Y, GAME_INVENTORY_FONT_SIZE, c);

	Font::StrDraw(L"���j���[��ʁFE�L�[", GAME_MENU_POS_X, GAME_MENU_POS_Y, GAME_MENU_FONT_SIZE, c);

	Font::StrDraw(L"�G�̌��j���~��", GAME_ENEMY_KILLS_POS_X, GAME_ENEMY_KILLS_POS_Y, GAME_ENEMY_KILLS_FONT_SIZE, c);
}