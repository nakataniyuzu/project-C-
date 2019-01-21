//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

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
	m_change = false;	
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_SISTER, OBJ_SISTER, 1);
}

//アクション
void CObjSister::Action()
{
	//主人公の情報を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)//主人公との当たり判定
	{
		hit->SetInvincibility(true);	//無敵にする(hit判定を消す)
		m_change = true;		//画像を切り替える
		m_drawt1 = 100;	//ドロータイムをセット
		g_mhit_enemy_flag = true;
	}
	if (m_change == true)
	{
		hero->SetSPEED(0.0f);	//スピードを０にする
		hero->SetVX(0.0f);		//ベクトルを０にする
		hero->SetVY(0.0f);
	}

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());
}

//ドロー
void CObjSister::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	//メッセージの情報を持ってくる
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);


	if (m_drawt1 > 0) {
		m_drawt1--;		//ドロータイムを減らす(減らしている間に表示)
		pm->BackDraw(195.0f, 195.0f, 360.0f, 225.0f, a);
		Font::StrDraw(L"来てくれたのね！", 200, 200, 20, y);//時間が0になると表示を終了
		if (m_drawt1 <= 0) {
			m_drawt1 = 0;
			m_drawt2 = 100;
		}
	}
	if (m_drawt2 > 0) {
		m_drawt2--;		//ドロータイムを減らす(減らしている間に表示)
		pm->BackDraw(195.0f, 195.0f, 445.0f, 225.0f, a);
		Font::StrDraw(L"助けてくれてありがとう！", 200, 200, 20, y);//時間が0になると表示を終了
		if (m_drawt2 <= 0) {
			m_drawt2 = 0;
			hero->SerCLEARF(true);	//クリアフラグをオン
			CObjFadein* fade = new CObjFadein();	//フェイドインの作成
			Objs::InsertObj(fade, OBJ_FADEIN, 200);
		}
	}


	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	if (m_change == false)	//画像を切り替える位置の調整
	{
		src.m_top    =  97.0f;
		src.m_left   = 240.0f;
		src.m_right  = 264.0f;
		src.m_bottom = 129.0f;
	}
	else
	{
		src.m_top    =  33.0f;
		src.m_left   = 240.0f;
		src.m_right  = 264.0f;
		src.m_bottom =  65.0f;
	}
	//ブロックの情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();
	//描画
	Draw::Draw(15, &src, &dst, c, 0.0f);

}
