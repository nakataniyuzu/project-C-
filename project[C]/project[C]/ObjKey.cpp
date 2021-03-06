//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjKey.h"


//使用するネームスペース
using namespace GameL;


CObjKey::CObjKey(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjKey::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px + 10, m_py, 30, ALL_SIZE, ELEMENT_FIELD, OBJ_KEY, 1);
}

//アクション
void CObjKey::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//主人公と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//キーを取得
	{
		Audio::Start(14);
		this->SetStatus(false);		//自身を削除
		Hits::DeleteHitBox(this);
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	hit->SetPos(m_px + block->GetScrollX() + 10, m_py + block->GetScrollY());

}

//ドロー
void CObjKey::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top	 =   0.0f;
	src.m_left	 =  50.0f;
	src.m_right  = 100.0f;
	src.m_bottom =  50.0f;
	
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top    =  0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   =  0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(HEALKEY, &src, &dst, c, 0.0f);
}


