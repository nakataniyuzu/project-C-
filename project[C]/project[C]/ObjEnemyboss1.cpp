
//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyboss1.h"

//使用するネームスペース
using namespace GameL;

CObjEnemyboss1::CObjEnemyboss1(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjEnemyboss1::Init()
{
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 100.0f, 100.0f, ELEMENT_BOSS, OBJ_BOSS, 1);
}

//アクション
void CObjEnemyboss1::Action()
{
	if (g_boss_kills >= 1)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	battle_flag = hero->GetBATTLE();

	if (g_battle_flag == true)
	{
		m_time = 100;
//		hit->SetInvincibility(true);	//無敵オン
		return;
	}

	if (m_time > 0)
	{
		m_time--;
		if (m_time <= 0)
		{
			m_time = 0;
			hit->SetInvincibility(false);	//無敵オフ
		}
	}
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公が触れたら
	{
		hit->SetInvincibility(true);	//当たり判定を消す
	}
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjEnemyboss1::Draw()
{
	if (g_boss_kills >= 1)
		return;
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

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = 100.0f + m_px + block->GetScrollX();
	dst.m_bottom = 100.0f + m_py + block->GetScrollY();

	if (g_map_change == 0) {
		Draw::Draw(14, &src, &dst, c, 0.0f);
	}
	else if(g_map_change == 1){
		Draw::Draw(14, &src, &dst, c, 0.0f);

	}
}
