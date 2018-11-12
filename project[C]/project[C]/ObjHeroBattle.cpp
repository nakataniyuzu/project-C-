//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHeroBattle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeroBattle::Init()
{
	m_px = 100.0f;
	m_py = 450.0f;		//位置
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f

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
 	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_PLAYER, OBJ_HERO_BATTLE, 1);
}

//アクション
void CObjHeroBattle::Action()
{
	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 2.0f;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 2.0f;
	}

	//Spaceキーでジャンプ
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (1)
		{
			m_vy = -20;
		}
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);

	//敵機オブジェクトと接触したら主人公削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
	}

	if (m_px < 0)
	{
		m_px = 0.0f;
	}

	if (m_py + 100 >= 550)
	{
		m_py = 550.0 - 100.0f;
	}

	if (m_py < 0)
	{
		m_py = 0.0f;
	}
}

//ドロー
void CObjHeroBattle::Draw()
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
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 75.0f + m_px;
	dst.m_bottom = 100.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}