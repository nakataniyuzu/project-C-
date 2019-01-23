#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：
class CObjMessage :public CObj
{
	public:
		CObjMessage() {};
		~CObjMessage() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

		void BackDraw(float top, float left, float right, float bottom, float c[]);

	private:

		struct Flag {
			bool gate;		//GATEのメッセージフラグ
			bool key;		//KEYのメッセージフラグ
			bool water;		//WATERBLOCKのメッセージフラグ
			bool ice;		//ICEMAGICのメッセージフラグ
			bool wind;		//WINDMAGICのメッセージフラグ
			bool sblock;	//SWITCHBLOCKのメッセージフラグ
			bool sgate;		//SWITCHGATEのメッセージフラグ
			bool heal;		//HEALのメッセージフラグ
			bool allkill;	//ALLKILLのメッセージフラグ
			bool windb;		//WINDブロックのメッセージフラグ
		};
		Flag f;

		//表示する時間
		struct Time {
			int gate;		//GATE用の時間
			int water;		//WATER用の時間
			int key;		//KEY用の時間
			int ice;		//ICE用の時間
			int wind;		//wind用の時間
			int sblock;		//SWITCHBLOCK用の時間
			int sgate;		//SWITCHGATE用の時間
			int heal;		//HEALの時間
			int allkill;	//ALLKILLの時間
			int windb;		//WINDブロックの時間
		};
		Time t;
		

};

