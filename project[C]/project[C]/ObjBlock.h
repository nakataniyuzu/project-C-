#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define ALL_SIZE 50.0f

//オブジェクト：ブロック＆背景
class CObjBlock : public CObj
{
	public:
		CObjBlock(int map[27][55]);
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
		//int m_map[27][55];	//マップ情報

		float m_scrollx;		//左右スクロール用
		float m_scrolly;

};