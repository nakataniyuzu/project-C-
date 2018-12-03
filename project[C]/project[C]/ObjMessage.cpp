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

}

//アクション
void CObjMessage::Action()
{
	
}

//ドロー
void CObjMessage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };


	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置


	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	f.water = hero->GetWATERF();
	f.key = hero->GetKEYF();
	f.gate = hero->GetGATEF();
	f.ice = hero->GetMICE();
	f.sgate = hero->GetSGATE();
	f.sblock = hero->GetSBLOCK();
	f.heal = hero->GetHEAL();

	if (f.water == true)	//主人公がWATERブロックと当たった場合、m_timeに時間をセット
	{
		t.water = 100;
	}
	if (t.water > 0) {
		t.water--;
		f.water = false;		//フラグをオフ
		hero->SetWATERF(f.water);
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
		Font::StrDraw(L"氷魔法を覚えた！（Xキーで切り替え", 200, 200, 20, c);//時間が0になると表示を終了
		if (t.ice <= 0) {
			t.ice = 0;
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
		Font::StrDraw(L"HP/MPが回復した！", 200, 200, 20, g);//時間が0になると表示を終了
		if (t.heal <= 0) {
			t.heal = 0;
		}
	}
}
