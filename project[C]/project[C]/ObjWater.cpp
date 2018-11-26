//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjWater.h"


//使用するネームスペース
using namespace GameL;


CObjWater::CObjWater(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjWater::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f

	m_switch = 0.0f;	//画像切り替え用
	m_move = true;			//true=右 false=左

	m_ani_time = 0;
	m_ani_frame = 0;	//静止フレームを初期にする

	m_ani_max_time = 6;		//アニメーション間隔幅

	//blockとの衝突状態確認
	m_hit_up    = false;
	m_hit_down  = false;
	m_hit_left  = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_WATER, 1);

}

//アクション
void CObjWater::Action()
{
		
	m_ani_time += 1;
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//ICEと当たっているか確認
	if (hit->CheckObjNameHit(OBJ_ICE) != nullptr)//当たっていたら当たり判定を消し、描画を変える
	{
		hit->SetInvincibility(true);
		m_switch = 1.0f;
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());

}

//ドロー
void CObjWater::Draw()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	if (m_battle_flag == false)
	{
		return;
	}
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	int AniDate[2] =
	{
		0, 1,
	};


	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f + m_switch * 100.0f;
	src.m_left   =   0.0f + AniDate[m_ani_frame] * 100.0f;
	src.m_right  = 100.0f + AniDate[m_ani_frame] * 100.0f;
	src.m_bottom = 100.0f + m_switch * 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(6, &src, &dst, c, 0.0f);

}


