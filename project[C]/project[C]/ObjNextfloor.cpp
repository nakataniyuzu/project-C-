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
	g_map_change += 1;
}

//アクション
void CObjNextfloor::Action()
{

	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain());	//ゲームメインシーンに移行
	}
}

//ドロー
void CObjNextfloor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	wchar_t NEXT[128];

	//n層目への移行用タイトル
	swprintf_s(NEXT, L"%d層目",g_map_change + 1);		
	Font::StrDraw(NEXT, 300, 200, 100, c);

}
