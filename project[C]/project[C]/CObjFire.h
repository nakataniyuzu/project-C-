#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト
class CObjFire : public CObj
{
	public:
		CObjFire(float x, float y);		//コンストラクタ
		~CObjFire() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_x;		//X方向の位置用変数
		float m_y;		//Y方向の位置用変数
		float m_vx;		//X方向の速度用変数
		float m_vy;		//Y方向の速度用変数

		float m_hit;	//衝突判定
		float m_posture;	//向き
		int m_time;		//魔法が消える時間
		int m_draw_time;	//表示する時間

		//blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

};