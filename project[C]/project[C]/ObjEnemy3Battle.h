#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵(戦闘：3層目)
class CObjEnemy3Battle : public CObj
{
	public:
		CObjEnemy3Battle() {};
		~CObjEnemy3Battle() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

		int GetDMG() { return m_damage; }//攻撃力を取得
		int GetPOS() { return m_posture; }//卍向き取得卍

	private:
		float m_px;//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;
		float m_posture;	//姿勢

		int m_ani_time;	//アニメーションフレーム動作間隔
		int m_ani_frame;	//描画フレーム
		int m_enemy_hp;   //敵の体力
		int m_damage;		//敵の攻撃力

		float m_speed_power;	//スピードパワー
		float m_ani_max_time;	//アニメーション動作間隔最大値
		float m_hero_posture;

		int m_subtract;			//おテスト
		int m_hero_position;	//おテスト2

		float m_time_j;		//ジャンプテスト

		//踏んでいるblockの種類を確認用
		int m_block_type;

		bool m_battle_flag;
		bool m_boss_flag;

		//移動の向き制御用
		bool m_move;
};


