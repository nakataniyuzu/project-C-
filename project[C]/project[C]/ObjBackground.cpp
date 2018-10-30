//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"


#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground::Init()
{
	

}

//アクション
void CObjBackground::Action()
{
	
}

//ドロー
void CObjBackground::Draw()
{
	//描画カラー情報　R=RED  G=Green  B=Blue A=alpha(透過情報)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;		//描画元切り取り位置
	RECT_F dst;		//描画先表示位置

	//切り取り位置の設定
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 100.0f;
	src.m_bottom = 100.0f;

	//描画
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 50.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

}

