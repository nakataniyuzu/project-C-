#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


//オブジェクト：ブロック＆背景
class CObjBlock : public CObj
{
	public:
		CObjBlock(int map[38][65]);
		~CObjBlock() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

		void SetScrollX(float sx) { m_scrollx = sx; }
		float GetScrollX() { return m_scrollx; }
		void SetScrollY(float sy) { m_scrolly = sy; }
		float GetScrollY() { return m_scrolly; }

		//ブロックとの当たり判定
		void BlockHit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool* left, bool* right,
			float* vx, float*vy, int* bt
		);

	private:
		int m_map[38][65];	//マップ情報

		float m_scrollx;		//左右スクロール用
		float m_scrolly;

		float m_and;		//透明度処理用
		bool m_andf;		//透明度処理用フラグ

};