//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjGate.h"

//使用するネームスペース
using namespace GameL;


CObjGate::CObjGate(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjGate::Init()
{
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_GATE, 1);

}

//アクション
void CObjGate::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	key = hero->GetKEY();

	//主人公と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		if (key == 1) {
			this->SetStatus(false);		//鍵を持った状態で当たっていたらMYSTERYBLOCKを消去
			Hits::DeleteHitBox(this);
		}
	}

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjGate::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	CHitBox* hit = Hits::GetHitBox(this);
	
	if (key == 0)
	{
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公がミステリーブロックと当たった場合、m_timeに時間をセット
		{
			m_time = 100;
		}
		if (m_time > 0) {
			m_time--;

			Font::StrDraw(L"鍵が必要です", 200, 200, 20, c);//時間が0になると表示を終了		
			if (m_time <= 0) {
				m_time = 0;
			}
		}
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
	dst.m_top    =     0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   =     0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}


