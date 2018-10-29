#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//定数
//描画関係の定数
#define TITLE_POS_X		(150)
#define	TITLE_POS_Y		(100)
#define TITLE_FONT_SIZE	(80)
#define TITLE_ADV_POS_X		(480)
#define	TITLE_ADV_POS_Y		(200)
#define TITLE_ADV_FONT_SIZE	(60)


#define GAME_START_POS_X		(300)
#define GAME_START_POS_Y		(400)
#define GAME_START_FONT_SIZE	(30)
#define GAME_END_POS_X			(300)
#define GAME_END_POS_Y			(450)
#define GAME_END_FONT_SIZE		(30)

//オブジェクト：タイトル
class CObjTitle :public CObj
{
	public:
		CObjTitle() {};
		~CObjTitle() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

	private:
		int choice;
		bool m_key_flag;
};

