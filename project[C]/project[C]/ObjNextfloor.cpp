//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjNextfloor.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjNextfloor::Init()
{
	
}

//アクション
void CObjNextfloor::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		g_map_change += 1;

	}
}

//ドロー
void CObjNextfloor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//Gameに移行場所
	Font::StrDraw(L"", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);

}
