//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjFireGate.h"


//使用するネームスペース
using namespace GameL;


CObjFireGate::CObjFireGate(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjFireGate::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_time = 0;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_FIREGATE, 1);

}

//アクション
void CObjFireGate::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	CObjFireblock* f = (CObjFireblock*)Objs::GetObj(OBJ_FIREBLOCK);
	m_fire = f->GetSWITCH();

	//Fireblockに火が灯っていたら消滅
	if (m_fire == 1.0f)
	{
		this->SetStatus(false);		
		Hits::DeleteHitBox(this);
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
void CObjFireGate::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//描画カラー情報
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公がミステリーブロックと当たった場合、m_timeに時間をセット
	{
		m_time = 100;
	}
	

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   = 100.0f;
	src.m_right  = 200.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(4, &src, &dst, r, 0.0f);

	if (m_time > 0) {
		m_time--;
		pm->BackDraw(195.0f, 195.0f, 330.0f, 225.0f, a);
		Font::StrDraw(L"火を灯せ...?", 200, 200, 20, r);//時間が0になると表示を終了
		if (m_time <= 0) {
			m_time = 0;
		}
	}
}


