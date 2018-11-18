﻿//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjTitle.h"
//#include "SceneMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	choice = 0;
	m_key_flag = true;
}

//アクション
void CObjTitle::Action()
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
				Scene::SetScene(new CSceneMain());
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

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置
	//背景切り取り
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 800.0f;
	src.m_bottom = 600.0f;

	//背景の描画
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//タイトル
	Font::StrDraw(L"○○", TITLE_POS_X, TITLE_POS_Y, TITLE_FONT_SIZE, c);
	Font::StrDraw(L"の冒険", TITLE_ADV_POS_X, TITLE_ADV_POS_Y, TITLE_ADV_FONT_SIZE, c);

	//Gameに移行場所
	Font::StrDraw(L"ゲームスタート", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, c);
	Font::StrDraw(L"ゲーム終了", GAME_END_POS_X, GAME_END_POS_Y, GAME_END_FONT_SIZE, c);

	if (choice == 0){
		Font::StrDraw(L"◆", GAME_START_POS_X - 30, GAME_START_POS_Y, GAME_START_FONT_SIZE, c);
	}
	if (choice == 1){
		Font::StrDraw(L"◆", GAME_END_POS_X - 30, GAME_END_POS_Y, GAME_END_FONT_SIZE, c);
	}
	
}
