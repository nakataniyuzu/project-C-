//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBoss.h"

//使用するネームスペース
using namespace GameL;

CObjBoss::CObjBoss(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjBoss::Init()
{
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 100.0f, 100.0f, ELEMENT_BOSS, OBJ_BOSS, 1);
}

//アクション
void CObjBoss::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_battle_flag = hero->GetBATTLE();
	m_boss_battle_f = hero->GetBOSSBATTLE();

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	if (m_battle_flag == false || m_boss_battle_f == false)
	{
		return;
	}

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjBoss::Draw()
{
	if (m_battle_flag == false || m_boss_battle_f == false)
	{
		return;
	}
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = 100.0f + m_px + block->GetScrollX();
	dst.m_bottom = 100.0f + m_py + block->GetScrollY();

	Draw::Draw(14, &src, &dst, c, 0.0f);
	

}
