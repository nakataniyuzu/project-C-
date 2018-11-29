//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjSister.h"

//使用するネームスペース
using namespace GameL;

CObjSister::CObjSister(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjSister::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_SISTER, OBJ_SISTER, 1);
}

//アクション
void CObjSister::Action()
{
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	battle_flag = hero->GetBATTLE();
	boss_battle_flag = hero->GetBOSSBATTLE();

	if (battle_flag == false || boss_battle_flag == false)
	{
		return;
	}



	//摩擦
	m_vx += -(m_vx * 0.098);
	m_vy += -(m_vy * 0.098);

	

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjSister::Draw()
{
	if (battle_flag == false)
	{
		return;
	}
	

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 96.0f;
	src.m_left   = 240.0f;
	src.m_right  = 264.0f;
	src.m_bottom = 128.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	Draw::Draw(15, &src, &dst, c, 0.0f);

}
