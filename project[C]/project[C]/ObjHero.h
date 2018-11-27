#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero : public CObj
{
	public:
		CObjHero() {};
		~CObjHero() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー

		float GetX() { return m_px; }	//主人公のX位置を取得
		float GetY() { return m_py; }	//主人公のY位置を取得
		float GetPOS() { return m_posture; }	//主人公の向きを取得

		int GetMAXHP() { return m_max_hp; }	//主人公のMAXHPを取得
		int GetMAXMP() { return m_max_mp; }	//主人公のMAXMPを取得
		int GetHP() { return m_hp; }	//主人公のHPを取得
		int GetMP() { return m_mp; }	//主人公のMPを取得
		int GetMAGIC() { return m_magic; }	//主人公の設定魔法を取得
		int GetKEY() { return m_key; }	//鍵の情報を取得
		bool GetBATTLE() { return m_battle_flag; }	//バトル移行用のフラグを取得
		void SetBATTLE(bool x) { m_battle_flag = x; }

		void SetMAXHP(float x) { m_max_hp = x; }	//主人公のMAXHPに値をセット
		void SetMAXMP(float x) { m_max_mp = x; }	//主人公のMAXMPに値をセット
		void SetHP(float x) { m_hp = x; }	//主人公のHPに値をセット
		void SetMP(float x) { m_mp = x; }	//主人公のMPに値をセット
		void SetMAGIC(float x) { m_magic = x; }	//主人公の魔法の種類をセット

		bool GetKEYF() { return m_key_mf; }	//KEYの情報を取得
		bool GetGATEF() { return m_gate_mf; }	//GATEの情報を取得
		bool GetWATERF() { return m_water_mf; }	//WATERの情報を取得
		bool GetMICE() { return m_ice_mf; }	//ICEの情報を取得

		bool GetFIREF() { return m_fire_flag; }
		bool GetICEF() { return m_ice_flag; }
		bool GetTHUNDERF(){return m_thunder_flag;}
		bool GetWINDF() { return m_wind_flag; }

		void SetKEYF(float x) { m_key_mf = x; }
		void SetGATEF(float x) { m_gate_mf = x; }
		void SetWATERF(float x) { m_water_mf = x; }
		void SetMICE(float x) { m_ice_mf = x; }

		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }
		int GetBT() { return m_block_type; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetBT(int t) { m_block_type = t; }

		void SetUp(bool b) { m_hit_up = b; }
		void SetDown(bool b) { m_hit_down = b; }
		void SetLeft(bool b) { m_hit_left = b; }
		void SetRight(bool b) { m_hit_right = b; }
	private:
		float m_px;			//位置
		float m_py;
		float m_vx;			//移動ベクトル
		float m_vy;
		float m_posture;	//姿勢
		float m_directionx; //魔法発射用X方向
		float m_directiony; //魔法発射用Y方向

		int m_max_hp;		//HPの最大値
		int m_max_mp;		//MPの最大値
		int m_hp;			//体力
		int m_mp;			//魔法使用回数
		int m_magic;		//魔法切り替え
		int m_key;			//鍵

		float m_scrollx;		//左右スクロール用
		float m_scrolly;		//上下スクロール用
		bool  m_f;		//キー（長押し）制御用
		bool  m_mf;		//キー（長押し）制御用

		bool m_battle_flag;	//バトル移行用
		bool m_map_flag; //マップ移行用

		//メッセージ用フラグ
		bool m_gate_mf;
		bool m_water_mf;
		bool m_key_mf;
		bool m_ice_mf;

		//魔法使用可能フラグ
		bool m_fire_flag;
		bool m_ice_flag;
		bool m_thunder_flag;
		bool m_wind_flag;

		int   m_gate_time;			
		int   m_ice_time;			//表示する時間
		int   m_water_time;
		int   m_key_time;

		int	  m_ani_time;	//アニメーションフレーム動作間隔
		int   m_ani_frame;	//描画フレーム

		float m_speed_power;	//スピードパワー
		float m_ani_max_time;	//アニメーション動作間隔最大値

		//blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		//踏んでいるblockの種類を確認用
		int m_block_type;
};
