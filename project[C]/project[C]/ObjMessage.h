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
		bool ice_flag;		//ICEMAGICのメッセージフラグ
		bool switch_flag;	//SWITCHGATEのメッセージフラグ

		//表示する時間
		int   m_gate_time;
		int   m_water_time;			
		int   m_key_time;
		int   m_ice_time;
		int   m_switch_time;

};

