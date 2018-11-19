//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMenu.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMenu::Init()
{
	choice = 1;
}

//�A�N�V����
void CObjMenu::Action()
{
	if (Input::GetVKey(VK_UP) == true)
	{
		choice = 1;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		choice = 0;	
	}

	if (choice == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{

			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneMain());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choice == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			exit(1);
		}
	}
}

//�h���[
void CObjMenu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�Q�[���ɖ߂�ꏊ
	Font::StrDraw(L"�Q�[���ɖ߂�", MENU_RETURN_POS_X, MENU_RETURN_POS_Y, MENU_RETURN_FONT_SIZE, c);

	Font::StrDraw(L"�Q�[���I��", MENU_END_POS_X, MENU_END_POS_Y, MENU_END_FONT_SIZE, c);

	if (choice == 1) {
		Font::StrDraw(L"��", MENU_RETURN_POS_X - 45, MENU_RETURN_POS_Y, MENU_RETURN_FONT_SIZE, c);
	}
	if (choice == 0) {
		Font::StrDraw(L"��", MENU_END_POS_X -45, MENU_END_POS_Y, MENU_END_FONT_SIZE, c);
	}
}