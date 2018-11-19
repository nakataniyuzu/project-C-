//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBattle.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjEnemyBattle::Init()
{
	g_enemy_px = 600.0f;//位置
	g_enemy_py = 580.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f
	m_enemy_hp = 3;     //敵のヒットポイント(最大3)

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = true;  //true=右 false=左

	m_block_type = 0;		//踏んでいるblockの種類を確認用

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, g_enemy_px, g_enemy_py, 75, 100, ELEMENT_ENEMY, OBJ_ENEMY_BATTLE, 1);

}

//アクション
void CObjEnemyBattle::Action()
{
	//通常速度
	m_speed_power = 0.4f;
	m_ani_max_time = 4;

	//画面端衝突で向き変更
	if (g_enemy_px + 75 >= 800)
	{
		m_move = true;
	}

	if (g_enemy_px  <= 0)
	{
		m_move = false;
	}

	//方向
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//自由落下運動
	//m_vy += 15.8 / (16.0f);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//位置の更新
	g_enemy_px += m_vx;
	g_enemy_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(g_enemy_px, g_enemy_py);

	//攻撃を受けたら体力を減らす
	if (hit->CheckObjNameHit(OBJ_ICE_BATTLE) != nullptr)
	{
		m_enemy_hp -= 1;
	}
	if (hit->CheckObjNameHit(OBJ_THUNDER_BATTLE) != nullptr)
	{
		m_enemy_hp -= 1;
	}

	//敵の体力が0になったら破棄
	if (m_enemy_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//敵が領域外に行かないようにする
	if (g_enemy_px + 75 >= 800)
	{
		g_enemy_px = 800.0 - 75.0f;
	}

	if (g_enemy_px < 0)
	{
		g_enemy_px = 0.0f;
	}

	if (g_enemy_py + 100 >= 580)
	{
		g_enemy_py = 580.0 - 100.0f;
	}

	if (g_enemy_py <50)
	{
		g_enemy_py = 50.0f;
	}
}

//ドロー
void CObjEnemyBattle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   = 50.0f;
	src.m_right  =  0.0f;
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top    =   0.0f + g_enemy_py;
	dst.m_left   = (75.0f * m_posture) + g_enemy_px;
	dst.m_right  = (75 - 75.0f * m_posture) + g_enemy_px;
	dst.m_bottom = 100.0f + g_enemy_py;

	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);

}