#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//定数
//描画関係の定数
#define MENU_RETURN_POS_X     (240)
#define MENU_RETURN_POS_Y     (200)
#define MENU_RETURN_FONT_SIZE (45)

#define MENU_END_POS_X		(260)
#define MENU_END_POS_Y      (310)
#define MENU_END_FONT_SIZE  (45)


//オブジェクト：メニュー
class CObjMenu :public CObj
{
	public:
		CObjMenu() {};
		~CObjMenu() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		int choice;
		bool m_key_flag;

};