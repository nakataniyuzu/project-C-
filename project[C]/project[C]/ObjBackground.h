#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjBackground : public CObj
{
	public:
		CObjBackground() {};
		~CObjBackground() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_x1;	//背景１の位置情報
		float m_x2; //背景２の位置情報
		float m_x3; //背景３の位置情報
		float m_scroll;
		float m_scroll_map;
};



