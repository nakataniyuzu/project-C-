#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjFireGate : public CObj
{
	public:
		CObjFireGate(float x, float y);
		~CObjFireGate() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }

	private:
		float m_px;			//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;

		int m_time;			//表示する時間

		float m_fire;	//火が灯っているかの判定用

};


