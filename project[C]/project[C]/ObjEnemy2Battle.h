#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵(戦闘：2層目)
class CObjEnemy2Battle : public CObj
{
	public:
		CObjEnemy2Battle() {};
		~CObjEnemy2Battle() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

		void SetENEMYDELETE(bool x) { enemy_delete_flag = x; }	//敵消滅用
		int GetDMG() {  return m_damage; }//攻撃力を取得

	private:
		float m_px;//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;
		float m_posture;	//姿勢
		bool m_pop_flag;	//リス位置の初期化用

		int m_ani_time;	//アニメーションフレーム動作間隔
		int m_ani_frame;	//描画フレーム
		int m_enemy_hp;   //敵の体力
		int m_damage;		//敵の攻撃力

		float m_speed_power;	//スピードパワー
		float m_ani_max_time;	//アニメーション動作間隔最大値
		float m_hero_posture;
		
		int m_time;		//敵死亡時のフェイドイン移行用間隔幅
		int m_ani;			//死亡アニメーション用
		int m_ani_time_d;	//死亡アニメーション間隔タイム
		bool m_del;			//削除チェック
		RECT_F m_eff;		//死亡エフェクト描画用

		int m_subtract;			//おテスト
		int m_hero_position;	//おテスト2

		//踏んでいるblockの種類を確認用
		int m_block_type;

		bool m_battle_flag;
		bool m_boss_flag;

		bool m_eff_flag;	//エフェクト用フラグ

		bool enemy_delete_flag;	//敵消滅用

		//移動の向き制御用
		bool m_move;
};

