#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjMessage :public CObj
{
	public:
		CObjMessage() {};
		~CObjMessage() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

	private:
		bool water_flag;	//WATERBLOCKのメッセージフラグ
		bool key_flag;		//KEYのメッセージフラグ
		bool gate_flag;		//GATEのメッセージフラグ
		bool ice_flag;//ICEMAGICのメッセージフラグ

		int   m_gate_time;
		int   m_water_time;			//表示する時間
		int   m_key_time;
		int   m_ice_time;

};

