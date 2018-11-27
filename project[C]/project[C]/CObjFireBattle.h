#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト
class CObjFireBattle : public CObj
{
	public:
		CObjFireBattle(float x, float y);		//コンストラクタ
		~CObjFireBattle() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_x;		//X方向の位置用変数
		float m_y;		//Y方向の位置用変数
		float m_vx;		//X方向の速度用変数
		float m_vy;		//Y方向の速度用変数

		float m_hit;	//衝突判定
		float posture;	//向き
		int m_time;		//魔法が消える時間

		//blockとの衝突状態確認用
		bool m_hit_left;
		bool m_hit_right;

		int    m_ani;		//着弾アニメーション用
		int    m_ani_time;	//着弾アニメーション間隔タイム
		bool   m_del;		//削除チェック
		RECT_F m_eff;		//着弾エフェクト描画用
};