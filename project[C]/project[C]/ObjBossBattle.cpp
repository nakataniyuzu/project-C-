//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBossBattle.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjBossBattle::Init()
{
	m_px = 100.0f;//位置
	m_py = 500.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f
	m_boss_hp = 15;     //敵のヒットポイント(最大3)

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = true;  //true=右 false=左


	m_time = 0;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 75, 100, ELEMENT_BOSS, OBJ_BOSS_BATTLE, 1);
}

//アクション
void CObjBossBattle::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_boss_flag = hero->GetBATTLE();
	hero_posture = hero->GetPOS();
	enemy_flag = hero->GetENEMYF();


	if (m_boss_flag == true)
	{
		
		m_vx = 0.0f;
		m_vy = 0.0f;
		return;
	}

	//画面端衝突で向き変更
	if (m_px + 75 >= 800)
	{
		m_move = true;
	}
	if (m_px <= 0)
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

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);


	//攻撃を受けたら体力を減らす
	//主人公とATTACK系統との当たり判定
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		m_boss_hp -= 1;
	}
	//敵の体力が0になったら破棄
	if (m_boss_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//敵が領域外に行かないようにする
	if (m_px + 75 >= 800)
	{
		m_px = 800.0 - 75.0f;
		m_speed_power = 0.5f;
	}
	if (m_px < 0)
	{
		m_px = 0.0f;
		m_speed_power = 0.5f;
	}
	if (m_py + 100 >= 580)
	{
		m_py = 580.0 - 100.0f;
	}
	if (m_py <50)
	{
		m_py = 50.0f;
	}

	//突進
	if (m_time >= 0)
	{
		m_time++;
		
		if (m_time >= 80)
		{
			m_speed_power = 0.0f;

			if (m_time >= 120)
			{
				m_speed_power = 20.0f;
				m_time = 0;
			}
		}
	}
}

//ドロー
void CObjBossBattle::Draw()
{
	if (m_boss_flag == true)
	{
		return;
	}

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   = 200.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//描画
	Draw::Draw(14, &src, &dst, c, 0.0f);

}