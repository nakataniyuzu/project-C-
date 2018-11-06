//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBattle.h"

//使用するネームスペース
using namespace GameL;

float g_enemy_px = 600.0f;
float g_enemy_py = 450.0f;

//イニシャライズ
void CObjEnemyBattle::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;	//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;		//踏んでいるblockの種類を確認用

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_ENEMY, OBJ_ENEMY_BATTLE, 1);

}

//アクション
void CObjEnemyBattle::Action()
{
	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//位置の更新
	g_enemy_px += m_vx;
	g_enemy_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(g_enemy_px, g_enemy_py);

}

//ドロー
void CObjEnemyBattle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	//表示位置の設定
	dst.m_top = 0.0f + g_enemy_py;
	dst.m_left = 0.0f + g_enemy_px;
	dst.m_right = 75.0f + g_enemy_px;
	dst.m_bottom = 100.0f + g_enemy_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}