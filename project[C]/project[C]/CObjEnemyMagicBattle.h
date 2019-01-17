#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト
class CObjEnemyMagicBattle : public CObj
{
	public:
		CObjEnemyMagicBattle(float x, float y);		//コンストラクタ
		~CObjEnemyMagicBattle() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
		int GetDMG() { return m_damage; }//攻撃力を取得
		int GetHP() { return m_boss_hp; }//体力を取得
		float GetPOS() { return m_posture; }//ボスの向きを取得
	private:
		float m_x;		//X方向の位置用変数
		float m_y;		//Y方向の位置用変数
		float m_vx;		//X方向の速度用変数
		float m_vy;		//Y方向の速度用変数

		float m_hit;	//衝突判定
		float m_posture;	//向き
		int m_time;		//魔法が消える時間
		int m_damage;
		int m_boss_hp;

		float m_bboss3_pos; //ボス向く向き

		//blockとの衝突状態確認用
		bool m_hit_left;
		bool m_hit_right;

		int    m_ani;		//着弾アニメーション用
		int    m_ani_time;	//着弾アニメーション間隔タイム
		bool   m_del;		//削除チェック
		RECT_F m_eff;		//着弾エフェクト描画用
};
