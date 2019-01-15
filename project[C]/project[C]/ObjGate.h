#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjGate : public CObj
{
public:
	CObjGate(float x, float y);
	~CObjGate() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

private:
	float m_px;			//位置
	float m_py;

	float m_f;		//鍵が開いたかの判定
	int m_time;			//表示する時間
	int m_draw_time;
	int key;	//鍵
};

