//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjFireblock.h"
#include "ObjMessage.h"


//使用するネームスペース
using namespace GameL;


CObjFireblock::CObjFireblock(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjFireblock::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_switch = 0.0f;	//描画切り替え

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_FIREBLOCK, 1);

}

//アクション
void CObjFireblock::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//Fire（魔法）と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_FIRE) != nullptr)
	{
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
void CObjFireblock::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公がミステリーブロックと当たった場合、m_timeに時間をセット
	{
		m_time = 100;
	}
	if (m_time > 0) {
		m_time--;
		if (m_switch == 0.0f) {
			pm->BackDraw(195.0f, 195.0f, 330.0f, 225.0f, a);
			Font::StrDraw(L"火を灯そう...", 200, 200, 20, r);//時間が0になると表示を終了
		}
		else if (m_switch == 1.0f) {
			pm->BackDraw(195.0f, 195.0f, 355.0f, 225.0f, a);
			Font::StrDraw(L"火が灯っている。", 200, 200, 20, r);
		}
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	if (hit->CheckObjNameHit(OBJ_FIRE) != nullptr)	//FireがFireblockと当たった場合、m_timeに時間をセット
	{
		m_draw_time = 100;
	}
	if (m_draw_time > 0) {
		m_draw_time--;
		pm->BackDraw(195.0f, 195.0f, 420.0f, 225.0f, a);
		Font::StrDraw(L"どこかが開いたようだ。", 200, 200, 20, y);//時間が0になると表示を終了	
		if (m_draw_time <= 0) {
			m_draw_time = 0;
		}
	}


	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   =  0.0f + (50.0f * m_switch);
	src.m_right  = 50.0f + (50.0f * m_switch);
	src.m_bottom = 50.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}


