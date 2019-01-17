//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy2.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjEnemy2::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//上向き0.0f 右向き1.0f 下向き2.0f 左向き3.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = false;

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_ENEMY, OBJ_ENEMY_SECOND, 1);
}

//アクション
void CObjEnemy2::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	battle_flag = hero->GetBATTLE();

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);


	if (g_battle_flag == true)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;	//動きを止める
		m_time = 100;	//m_timeに時間をセット
		return;
	}

	if (m_time > 0)
	{
		m_speed_power = 0.0f;	//スピードを0にする
		m_time--;
		if (m_time <= 0)
		{
			m_speed_power = 0.5f;	//スピードを元に戻す
			m_time = 0;				//m_timeを0に戻す
			hit->SetInvincibility(false);	//無敵オフ
		}
	}

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公を触れたら
	{
		m_speed_power = 0.0f;		//スピードを０にする
		m_vx = 0.0f;
		m_vy = 0.0f;
		hit->SetInvincibility(true);	//当たり判定を消す
	}
	if (hit->CheckObjNameHit(OBJ_FIRE) != nullptr)	//魔法攻撃(Fire)に触れたら
	{
		m_speed_power = 2.0f;	//スピードを上げる
	}
	if (hit->CheckObjNameHit(OBJ_ICE) != nullptr)	//魔法攻撃(Ice)に触れたら
	{
		m_speed_power = 0.0f;	//スピードを止める
	}
	if (m_hit_up == true)	//上
		m_move = false;
	if (m_hit_down == true)	//下
		m_move = true;

	//方向
	if (m_move == false)
	{
		m_vy += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vy -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjEnemy2::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	int AniDate[4] =
	{
		0 , 1 ,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 0.6f,0.0f,0.0f,0.8f };
	float b[4] = { 0.0f,0.0f,0.6f,0.8f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = ALL_SIZE * m_posture;
	src.m_left = 0.0f + AniDate[m_ani_frame] * ALL_SIZE;
	src.m_right = ALL_SIZE + AniDate[m_ani_frame] * ALL_SIZE;
	src.m_bottom = ALL_SIZE + (ALL_SIZE * m_posture);

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top = 0.0f + m_py + block->GetScrollY();
	dst.m_left = 0.0f + m_px + block->GetScrollX();
	dst.m_right = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	if (m_speed_power >= 2.0f) {
		Draw::Draw(7, &src, &dst, r, 0.0f);
	}
	else if (m_speed_power == 0.0f) {
		Draw::Draw(7, &src, &dst, b, 0.0f);
	}
	else {
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}

}
