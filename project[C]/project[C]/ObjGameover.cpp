//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "GameL\Audio.h"

#include "ObjGameover.h"
//#include "SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameover::Init()
{
	m_time = 0;
	choice = 0;
	m_key_flag = true;
	m_and = 1.0f;
	m_andf = false;
}

//�A�N�V����
void CObjGameover::Action()
{
	if (choice == 1 && m_time <= 0 && Input::GetVKey(VK_UP) == true)
	{
		m_time = 5;
		choice = 0;
		Audio::Start(0);
	}
	if (choice == 0 && m_time <= 0 && Input::GetVKey(VK_DOWN) == true)
	{
		m_time = 5;
		choice = 1;
		Audio::Start(0);
	}

	if (choice == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				m_andf = true;
				Audio::Start(1);
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
			Audio::Start(2);
			exit(1);
		}

	}
	if (m_andf == true)
	{
		m_and -= 0.03f;
		if (m_and <= 0.0f)
		{
			m_and = 0.0f;
			m_andf = false;
			Scene::SetScene(new CSceneMain());
		}
	}

	if (m_time >= 0)
		m_time--;
}

//�h���[
void CObjGameover::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//�`�挳�؂���ʒu
	RECT_F dst;		//�`���\���ʒu
	//�w�i�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//�w�i�̕`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�^�C�g��
	Font::StrDraw(L"GAME", TITLE_POS_X, TITLE_POS_Y, TITLE_FONT_SIZE, c);
	Font::StrDraw(L"OVER", TITLE_ADV_POS_X, TITLE_ADV_POS_Y, TITLE_ADV_FONT_SIZE, c);

	//Game�Ɉڍs�ꏊ
	Font::StrDraw(L"��蒼��", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, c);
	Font::StrDraw(L"�Q�[���I��", GAME_END_POS_X, GAME_END_POS_Y, GAME_END_FONT_SIZE, c);

	if (choice == 0) {
		Font::StrDraw(L"��", GAME_START_POS_X - 30, GAME_START_POS_Y, GAME_START_FONT_SIZE, c);
	}
	if (choice == 1) {
		Font::StrDraw(L"��", GAME_END_POS_X - 30, GAME_END_POS_Y, GAME_END_FONT_SIZE, c);
	}

}
