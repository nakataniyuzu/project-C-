#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjDummySwitch : public CObj
{
public:
	CObjDummySwitch(float x, float y);
	~CObjDummySwitch() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	bool GetCHANGE() { return m_change; }

private:
	float m_px;			//位置
	float m_py;
	bool m_change;		//画像切り替え用
	int m_time;		//メッセージ表示用
};
