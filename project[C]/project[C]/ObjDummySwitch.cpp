//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjSwitch.h"


//使用するネームスペース
using namespace GameL;


CObjDummySwitch::CObjDummySwitch(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void CObjDummySwitch::Init()
{
	m_change = false;	//画像切り替え
	m_time = 0;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, ALL_SIZE, ALL_SIZE, ELEMENT_FIELD, OBJ_DUMMYSWITCH, 1);
}

//アクション
void CObjDummySwitch::Action()
{
	//主人公の情報を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (g_battle_flag == true)
	{
		return;
	}
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	if (m_change == false)
	{
		//主人公と当たっているか確認
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			m_time = 50;
			g_key_flag = true;
			m_change = true;	//当たっていたら表示カラーを変える
			
			hit->SetInvincibility(true);	//当たり判定を消す
		}
	}
	
	if (m_time == 1) {
		hero->SetENEMYF(true);	//敵出現フラグをオン
		hero->SetFADEF(true);	//フェイドフラグをオン
		hero->SetDELETE(true);	//前敵削除フラグをオン

		CObjFadein* fade = new CObjFadein();	//フェイドインの作成
		Objs::InsertObj(fade, OBJ_FADEIN, 200);
		Audio::Start(1);
	}

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//HitBoxの位置の変更
	hit->SetPos(m_px + block->GetScrollX(), m_py + block->GetScrollY());

}

//ドロー
void CObjDummySwitch::Draw()
{
	if (g_battle_flag == true)
	{
		return;
	}
	//メッセージの情報を持ってくる
	CObjMessage* pm = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 1.0f,1.0f,2.0f,0.7f };
	float r[4] = { 3.0f,1.0f,1.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	CHitBox* hit = Hits::GetHitBox(this);
	if (m_change == true)
	{
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)	//FireがFireblockと当たった場合、m_timeに時間をセット
		{
			m_time = 100;
		}
	}
	if (m_time > 0) {
		m_time--;
		pm->BackDraw(195.0f, 195.0f, 265.0f, 225.0f, a);
		Font::StrDraw(L"敵だ!!", 200, 200, 20, c);//時間が0になると表示を終了
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top    = 0.0f + m_py + block->GetScrollY();	//描画に対してスクロールの影響を加える
	dst.m_left   = 0.0f + m_px + block->GetScrollX();
	dst.m_right  = ALL_SIZE + m_px + block->GetScrollX();
	dst.m_bottom = ALL_SIZE + m_py + block->GetScrollY();

	//描画
	if (m_change == false) {
		Draw::Draw(4, &src, &dst, b, 0.0f);
	}
	else if (m_change == true) {
		Draw::Draw(4, &src, &dst, r, 0.0f);
	}
}


