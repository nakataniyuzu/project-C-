//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjMessage.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMessage::Init()
{
	//フラグの初期化
	f.gate = false;		//GATEのメッセージフラグ
	f.key = false;		//KEYのメッセージフラグ
	f.water = false;		//WATERBLOCKのメッセージフラグ
	f.ice = false;		//ICEMAGICのメッセージフラグ
	f.wind = false;		//WINDMAGICのメッセージフラグ
	f.sblock = false;	//SWITCHBLOCKのメッセージフラグ
	f.sgate = false;		//SWITCHGATEのメッセージフラグ
	f.heal = false;		//HEALのメッセージフラグ
	f.allkill = false;	//ALLKILLのメッセージフラグ
	f.windb = false;	//WINDブロックのメッセージフラグ
	f.escape = false;	//escape用のメッセージフラグ
	//タイムの初期化
	t.gate = 0;		//GATE用の時間
	t.water = 0;		//WATER用の時間
	t.key = 0;		//KEY用の時間
	t.ice = 0;		//ICE用の時間
	t.wind = 0;		//wind用の時間
	t.sblock = 0;		//SWITCHBLOCK用の時間
	t.sgate = 0;		//SWITCHGATE用の時間
	t.heal = 0;		//HEALの時間
	t.allkill = 0;	//ALLKILLの時間
	t.windb = 0;	//WINDブロックの時間
	t.xp = 0;		//HP/MP増加用の時間
	t.escape = 0;	//escape用の時間
}

//アクション
void CObjMessage::Action()
{
	
}

//ドロー
void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.5f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float a[4] = { 1.0f,1.0f,1.0f,0.5f };

	
	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置

	//主人公の情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	f.water = hero->GetWATERF();
	f.key = hero->GetKEYF();
	f.gate = hero->GetGATEF();
	f.ice = hero->GetMICE();
	f.wind = hero->GetMWIND();
	f.sgate = hero->GetSGATE();
	f.sblock = hero->GetSBLOCK();
	f.heal = hero->GetHEAL();
	f.allkill = hero->GetALLKILL();
	f.windb = hero->GetWINDB();

	if (g_escape == true)
		f.escape = false;

	if (g_escape == false && f.escape == false)
	{
		t.escape = 200;
		f.escape = true;
	}
	if (t.escape > 0) {
		t.escape--;
		BackDraw(145.0f, 195.0f, 445.0f, 175.0f, a);
		Font::StrDraw(L"この戦闘は逃げられない！", 200, 150, 20, r);//時間が0になると表示を終了
		if (t.escape <= 150) {
		}
		if (t.escape <= 0) {
			t.escape = 0;
		}
	}

	if (g_xpup_flag == true)
	{
		t.xp = 160;
		g_xpup_flag = false;
	}
	if (t.xp > 0) {
		t.xp--;
		BackDraw(145.0f, 195.0f, 370.0f, 175.0f, a);
		Font::StrDraw(L"HP/MPが上がった！", 200, 150, 20, y);//時間が0になると表示を終了
		if (t.xp <= 0) {
			t.xp = 0;
		}
	}

	if (f.windb == true)	//敵が全滅したときにフラグをセット
	{
		t.windb = 100;
	}
	if (t.windb > 0) {
		t.windb--;
		f.windb = false;		//フラグをオフ
		hero->SetWINDB(f.windb);
		BackDraw(195.0f, 195.0f, 370.0f, 225.0f, a);
		Font::StrDraw(L"大きな力が必要...", 200, 200, 20, g);//時間が0になると表示を終了
		if (t.windb <= 0) {
			t.windb = 0;
		}
	}
	if (f.allkill == true)	//敵が全滅したときにフラグをセット
	{
		t.allkill = 130;
	}
	if (t.allkill > 0) {
		t.allkill--;
		f.allkill = false;		//フラグをオフ
		hero->SetALLKILL(f.allkill);
		BackDraw(225.0f, 175.0f, 370.0f, 255.0f, a);
		Font::StrDraw(L"敵の気配が消えた...", 180, 230, 20, c);//時間が0になると表示を終了
		if (t.allkill <= 0) {
			t.allkill = 0;
		}
	}

	if (f.water == true)	//主人公がWATERブロックと当たった場合、m_timeに時間をセット
	{
		t.water = 100;
	}
	if (t.water > 0) {
		t.water--;
		f.water = false;		//フラグをオフ
		hero->SetWATERF(f.water);
		BackDraw(225.0f, 175.0f, 415.0f, 255.0f, a);
		Font::StrDraw(L"凍らせれば渡れるか...？", 180, 230, 20, b);//時間が0になると表示を終了
		if (t.water <= 0) {
			t.water = 0;
		}
	}

	if (f.key == true)	//主人公がKEYブロックと当たった場合、m_timeに時間をセット
	{
		t.key = 100;
	}
	if (t.key > 0) {
		t.key--;
		f.key = false;		//フラグをオフ
		hero->SetKEYF(f.key);
		BackDraw(195.0f, 195.0f, 348.0f, 225.0f, a);
		Font::StrDraw(L"鍵を手に入れた", 200, 200, 20, y);//時間が0になると表示を終了
		if (t.key <= 0) {
			t.key = 0;
		}
	}

	if (f.gate == true)		//鍵のフラグがオンになったら時間をセット
	{
		t.gate = 100;
	}
	if (t.gate > 0) {
		t.gate--;
		f.gate = false;		//フラグをオフ
		hero->SetGATEF(f.gate);
		BackDraw(165.0f, 200.0f, 320.0f, 195.0f, a);
		Font::StrDraw(L"鍵を開けた", 210, 170, 20, y);//時間が0になると表示を終了
		if (t.gate <= 0) {
			t.gate = 0;
		}
	}
	if (f.ice == true)		//鍵のフラグがオンになったら時間をセット
	{
		t.ice = 100;
	}
	if (t.ice > 0) {
		t.ice--;
		f.ice = false;		//フラグをオフ
		hero->SetMICE(f.ice);
		BackDraw(165.0f, 195.0f, 540.0f, 195.0f, a);
		Font::StrDraw(L"氷魔法を覚えた！（Xキーで切り替え", 200, 170, 20, b);//時間が0になると表示を終了

		if (t.ice <= 0) {
			t.ice = 0;
		}
	}
	if (f.wind == true)		//鍵のフラグがオンになったら時間をセット
	{
		t.wind = 100;
	}
	if (t.wind > 0) {
		t.wind--;
		f.wind = false;		//フラグをオフ
		hero->SetMWIND(f.wind);
		BackDraw(165.0f, 195.0f, 540.0f, 195.0f, a);
		Font::StrDraw(L"風魔法を覚えた！（Xキーで切り替え", 210, 170, 20, g);//時間が0になると表示を終了

		if (t.wind <= 0) {
			t.wind = 0;
		}
	}
	if (f.sgate == true)	//フラグがオンの時タイムをセット
	{
		t.sgate = 100;
	}
	if (t.sgate > 0) {
		t.sgate--;
		f.sgate = false;	//フラグをオフ
		hero->SetSGATE(f.sgate);
		BackDraw(195.0f, 195.0f, 315.0f, 225.0f, a);
		Font::StrDraw(L"開かない...", 200, 200, 20, c);//時間が0になると表示を終了		
		if (t.sgate <= 0) {
			t.sgate = 0;
		}
	}
	if (f.sblock == true)	//フラグがオンの時タイムをセット
	{
		t.sblock = 100;
	}
	if (t.sblock > 0) {
		t.sblock--;
		f.sblock = false;
		hero->SetSBLOCK(f.sblock);
		//描画
		BackDraw(195.0f, 195.0f, 450.0f, 225.0f, a);
		Font::StrDraw(L"どこかで扉が開く音がした。", 200, 200, 20, y);//時間が0になると表示を終了
		if (t.sblock <= 0) {
			t.sblock = 0;
		}	
	}

	if (f.heal == true)		//フラグがオンの時タイムをセット
	{
		t.heal = 100;
	}
	if (t.heal > 0) {
		t.heal--;
		f.heal = false;
		hero->SetHEAL(f.heal);
		BackDraw(195.0f, 300.0f, 480.0f, 225.0f, a);
		Font::StrDraw(L"HP/MPが回復した！", 300, 200, 20, g);//時間が0になると表示を終了
		if (t.heal <= 0) {
			t.heal = 0;
		}
	}
}

//BackDrawMethod関数
//引数1 float	top		:リソース表示位置top
//引数2 float	left	:リソース表示位置left
//引数3 float	right	:リソース表示位置right
//引数4 float	bottom	:リソース表示位置bottom
//引数5 float	c[]	:カラー設定
void CObjMessage::BackDraw(float top, float left, float right,float bottom, float c[])
{
	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	//描画
	dst.m_top    = top;	
	dst.m_left   = left;
	dst.m_right  = right;
	dst.m_bottom = bottom;
	Draw::Draw(3, &src, &dst, c, 0.0f);
}
