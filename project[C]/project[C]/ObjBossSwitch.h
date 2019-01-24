#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBossSwitch : public CObj
{
	public:
		CObjBossSwitch(float x, float y);
		~CObjBossSwitch() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

		bool GetCHANGE() { return m_change; }

	private:
		float m_px;			//位置
		float m_py;
		bool m_change;		//画像切り替え用
		int m_time;		
};
