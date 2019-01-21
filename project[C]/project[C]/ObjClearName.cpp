//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "GameL\Audio.h"

#include "ObjClearName.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClearName::Init()
{
	m_time = 0;
	choice = 0;
	m_key_flag = true;

	Audio::Start(100);
}

//アクション
void CObjClearName::Action()
{
	
}

//ドロー
void CObjClearName::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.0f,0.0f,1.0f };

	wchar_t NAME[128];

	swprintf_s(NAME, L"%c", m_name_key[2][4]);
	Font::StrDraw(NAME, 200, 300, 25, c);

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置
	////背景切り取り
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 800.0f;
	//src.m_bottom = 600.0f;

	////背景の描画
	//dst.m_top = 0.0f;
	//dst.m_left = 0.0f;
	//dst.m_right = 800.0f;
	//dst.m_bottom = 600.0f;
	//Draw::Draw(0, &src, &dst, c, 0.0f);

	//タイトル
	//Font::StrDraw(L"○○の冒険", CLEAR_POS_X, CLEAR_POS_Y, CLEAR_FONT_SIZE, c);
	//Font::StrDraw(L"おわり", CLEAR_ADV_POS_X, CLEAR_ADV_POS_Y, CLEAR_ADV_FONT_SIZE, c);

	//Gameに移行場所
	Font::StrDraw(L"タイトルへ戻る", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
	Font::StrDraw(L"ゲーム終了", GAME_END_POS_X, GAME_END_POS_Y, GAME_END_FONT_SIZE, b);

	if (choice == 0) {
		Font::StrDraw(L"◆", GAME_START_POS_X - 30, GAME_START_POS_Y, GAME_START_FONT_SIZE, c);
	}
	if (choice == 1) {
		Font::StrDraw(L"◆", GAME_END_POS_X - 30, GAME_END_POS_Y, GAME_END_FONT_SIZE, c);
	}

}
