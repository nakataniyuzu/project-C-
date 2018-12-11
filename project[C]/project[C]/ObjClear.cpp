//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjClear.h"
//#include "SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	choice = 0;
	m_key_flag = true;
}

//�A�N�V����
void CObjClear::Action()
{

	if (Input::GetVKey(VK_UP) == true)
	{
		choice = 0;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		choice = 1;
	}

	if (choice == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneTitle());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}

	if (choice == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			exit(1);
		}

	}
}

//�h���[
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu
					//�w�i�؂���
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 800.0f;
	src.m_bottom = 600.0f;

	//�w�i�̕`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�^�C�g��
	//Font::StrDraw(L"�����̖`��", CLEAR_POS_X, CLEAR_POS_Y, CLEAR_FONT_SIZE, c);
	//Font::StrDraw(L"�����", CLEAR_ADV_POS_X, CLEAR_ADV_POS_Y, CLEAR_ADV_FONT_SIZE, c);

	//Game�Ɉڍs�ꏊ
	Font::StrDraw(L"�^�C�g���֖߂�", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
	Font::StrDraw(L"�Q�[���I��", GAME_END_POS_X, GAME_END_POS_Y, GAME_END_FONT_SIZE, b);

	if (choice == 0) {
		Font::StrDraw(L"��", GAME_START_POS_X - 30, GAME_START_POS_Y, GAME_START_FONT_SIZE, c);
	}
	if (choice == 1) {
		Font::StrDraw(L"��", GAME_END_POS_X - 30, GAME_END_POS_Y, GAME_END_FONT_SIZE, c);
	}

}
