//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjMysteryblock.h"


//使用するネームスペース
using namespace GameL;


CObjMysteryblock::CObjMysteryblock(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjMysteryblock::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f

	m_move = true;			//true=右 false=左

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_MYSTERY, OBJ_MYSTERYBLOCK, 1);

}

//アクション
void CObjMysteryblock::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//MOVEBLOCKと当たっているか確認
	if (hit->CheckObjNameHit(OBJ_MOVEBLOCK) != nullptr)
	{
		this->SetStatus(false);		//当たっていたらMYSTERYBLOCKを消去
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
void CObjMysteryblock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公がミステリーブロックと当たった場合、m_timeに時間をセット
	{
		m_time = 100;
	}
	if (m_time > 0) {
		m_time--;
		Font::StrDraw(L"鍵が必要です。", 200, 200, 20, c);//時間が0になると表示を終了
		if (m_time <= 0){
			m_time = 0;
		}
	}
	


	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   = 200.0f;
	src.m_right  = 300.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    =     0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   =     0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}


