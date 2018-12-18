//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjHeal.h"


//使用するネームスペース
using namespace GameL;


CObjHeal::CObjHeal(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjHeal::Init()
{

	m_and = 0.0f;
	m_andf = true;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_HEAL, OBJ_HEAL, 1);

}

//アクション
void CObjHeal::Action()
{
	if (m_andf == true)
	{
		m_and += 0.01f;
		if (m_and >= 1.0f)
		{
			m_and = 1.0f;
			m_andf = false;
		}
	}



	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//主人公がHEALと当たった場合
	{
		hit->SetInvincibility(true);	//無敵オン
		m_time = 100;
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
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjHeal::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,m_and };
	

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =  0.0f;
	src.m_left   =  0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	Draw::Draw(HEALKEY, &src, &dst, c, 0.0f);
}


