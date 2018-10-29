#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[27][55]);
	~CObjBlock() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	//ブロックとの当たり判定
	void BlockHit(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);

	//主人公と壁の交差判定
	bool HeroBlckCrossPoint(
		float x, float y, float vx, float vy,
		float *out_px, float *out_py, float* out_len
	);


private:
	int m_map[27][55];	//マップ情報

	float m_scroll;		//左右スクロール用

};