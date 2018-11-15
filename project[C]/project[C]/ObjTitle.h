#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//定数
//描画関係の定数
#define TITLE_POS_X		(120)
#define	TITLE_POS_Y		(80)
#define TITLE_FONT_SIZE	(100)
#define TITLE_ADV_POS_X		(480)
#define	TITLE_ADV_POS_Y		(200)
#define TITLE_ADV_FONT_SIZE	(80)


#define GAME_START_POS_X		(300)
#define GAME_START_POS_Y		(390)
#define GAME_START_FONT_SIZE	(30)
#define GAME_END_POS_X			(300)
#define GAME_END_POS_Y			(440)
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

