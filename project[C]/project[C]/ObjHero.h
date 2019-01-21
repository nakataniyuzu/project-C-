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
		bool GetKEY() { return m_key; }		//鍵の情報を取得

		bool GetBATTLE() { return m_battle_flag; }	//バトル移行用のフラグを取得
		bool GetBOSSBATTLE() { return m_boss_battle_flag; }	//ボスバトル移行用のフラグを取得
		
		bool GetDELETE() { return m_delete; }	//敵消滅用のフラグを取得
		void SetDELETE(bool x) { m_delete = x; }//敵消滅用フラグをセット

		void SetBOSSBATTLE(bool x) { m_boss_battle_flag = x; }
		void SetBATTLE(bool x) { m_battle_flag = x; }

		void SetMAXHP(float x) { m_max_hp += x; }	//主人公のMAXHPに値を加算
		void SetMAXMP(float x) { m_max_mp += x; }	//主人公のMAXMPに値を加算

		void SetHP(float x) { m_hp = x; }	//主人公のHPに値をセット
		void SetMP(float x) { m_mp = x; }	//主人公のMPに値をセット
		void SetMAGIC(float x) { m_magic = x; }	//主人公の魔法の種類をセット
		
		bool GetENEMYF() { return m_ene_battle_flag; }		//敵出現用フラグを取得
		bool GetBOSSF() { return m_boss_battle_flag; }		//ボス出現用フラグを取得
		bool GetFADEF() { return m_fade_flag; }			//フェイドフラグを取得	
		bool GetNEXTF() { return m_next_flag; }			//ネクストフラグを取得
		bool GetDEATHF() { return m_death_flag; }	//死亡用フラグを取得
		bool GetCLEAR() { return m_clear_flag; }	//ゲームクリアフラグを取得

		void SetDEATHF(bool x) { m_death_flag = x; }	//ゲームオーバーシーンへの移行用フラグを取得
		void SerCLEARF(bool x) { m_clear_flag = x; }	//ゲームクリアシーンへの移行用フラグを取得

		void SetENEMYF(bool x) { m_ene_battle_flag = x; }	//敵出現用フラグをセット
		void SetBOSSF(bool x) { m_boss_battle_flag = x; }		//ボス出現用フラグをセット
		void SetFADEF(bool x) { m_fade_flag = x; }		//フェイドフラグをセット
		void SetNEXTF(bool x) { m_next_flag = x; }		//ネクストフラグをセット

		bool GetALLKILL() { return mes.allkill; }//敵全滅用
		void SetALLKILL(bool x) { mes.allkill = x; }	//敵全滅用セット関数

		bool GetKEYF() { return mes.key; }		//KEYの情報を取得
		bool GetGATEF() { return mes.gate; }	//GATEの情報を取得
		bool GetWATERF() { return mes.water; }	//WATERの情報を取得
		bool GetMICE() { return mes.ice; }		//ICEの情報を取得
		bool GetMWIND() { return mes.wind; }	//WINDの情報を取得

		bool GetSGATE() { return mes.switchgate; }	//SWITCHGATEの情報を取得
		bool GetSBLOCK() { return mes.switchblock; }//SWITCHBLOCKの情報を取得
		bool GetHEAL() { return mes.heal; }		//HEALの情報を取得

		bool GetFIREF() { return m_fire_flag; }		//Fireが使えるかどうか
		bool GetICEF() { return m_ice_flag; }		//Iceが使えるかどうか
		bool GetTHUNDERF(){return m_thunder_flag;}	//THUNDERが使えるかどうか
		bool GetWINDF() { return m_wind_flag; }		//WINDが使えるかどうか

		void SetKEYF(bool x) { mes.key = x; }		//KEYに情報をセット
		void SetGATEF(bool x) { mes.gate = x; }		//GATEに情報をセット
		void SetWATERF(bool x) { mes.water = x; }	//WATERに情報をセット
		void SetMICE(bool x) { mes.ice = x; }		//ICEに情報をセット
		void SetMWIND(bool x) { mes.wind = x; }		//WINDに情報をセット
		void SetSGATE(bool x) { mes.switchgate = x; }	//SWITCHGATEに情報をセット
		void SetSBLOCK(bool x) { mes.switchblock = x; }	//SWITCHBLOCKに情報をセット
		void SetHEAL(bool x) { mes.heal = x; }		//HEALに情報をセット

		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetSPEED(float x) { m_speed_power = x; }
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

		bool m_clear_flag;		//ゲームクリア用のフラグ
		bool m_death_flag;		//主人公死亡用フラグ
		bool m_next_flag;		//次の階層への移行用
		bool m_fade_flag;		//フェイドイン,アウト用
		bool m_battle_flag;		//バトル移行用
		bool m_ene_battle_flag;	//雑魚出現用
		bool m_boss_battle_flag;//ボス出現用
		bool m_map_flag; //マップ移行用
		bool m_allkill_flag;	//ALLKILLフラグ
		//メッセージ用フラグ
		struct Message {
			bool gate;		//ゲート用
			bool water;		//水用
			bool key;		//鍵用
			bool ice;		//氷魔法用
			bool wind;		//風魔法用
			bool switchblock;	//スイッチブロック用
			bool switchgate;	//スイッチゲート用
			bool heal;		//ヒールブロック用
			bool dswitch;	//ダミースイッチ用
			bool allkill;	//敵全滅用

		};
		Message mes;

		//魔法使用可能フラグ
		bool m_fire_flag;
		bool m_ice_flag;
		bool m_thunder_flag;
		bool m_wind_flag;

		bool m_delete;	//敵消滅用

		int	  m_ani_time;	//アニメーションフレーム動作間隔
		int   m_ani_frame;	//描画フレーム

		float m_and;		//透明度処理用
		bool m_andf;		//透明度処理用フラグ

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
