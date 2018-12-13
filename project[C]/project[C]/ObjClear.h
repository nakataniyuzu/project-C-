#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//定数
//描画関係の定数
#define CLEAR_POS_X		(120)
#define	CLEAR_POS_Y		(80)
#define CLEAR_FONT_SIZE	(100)
#define CLEAR_ADV_POS_X		(480)
#define	CLEAR_ADV_POS_Y		(200)
#define CLEAR_ADV_FONT_SIZE	(80)


#define GAME_START_POS_X		(300)
#define GAME_START_POS_Y		(390)
#define GAME_START_FONT_SIZE	(30)
#define GAME_END_POS_X			(300)
#define GAME_END_POS_Y			(440)
#define GAME_END_FONT_SIZE		(30)

//オブジェクト：タイトル
class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

private:
	int choice;
	int m_time;		//キーの入力時間間隔
	bool m_key_flag;
};

