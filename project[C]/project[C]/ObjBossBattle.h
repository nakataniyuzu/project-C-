#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵(戦闘)
class CObjBossBattle : public CObj
{
public:
	CObjBossBattle() {};
	~CObjBossBattle() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	void SetBOSSDELETE(bool x) { boss_delete_flag = x; }

private:	
	float m_px;			//位置
	float m_py;
	float m_vx;			//移動ベクトル
	float m_vy;
	float m_posture;	//姿勢

	int	  m_ani_time;	//アニメーションフレーム動作間隔
	int   m_ani_frame;	//描画フレーム
	int   m_boss_hp;   //敵の体力

	float m_speed_power;	//スピードパワー
	float m_ani_max_time;	//アニメーション動作間隔最大値
	float hero_posture;

	int m_time;	//突進時間
	//踏んでいるblockの種類を確認用
	int m_block_type;

	bool m_boss_flag;	//ボス戦闘用フラグ
	bool enemy_flag;	//敵削除用
	bool boss_delete_flag;	//ボス削除用
	bool m_pop_flag;	//ボスの出現位置用
	//移動の向き制御用
	bool m_move;
};

