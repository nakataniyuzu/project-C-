#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_TITLE,
	OBJ_MENU,
	OBJ_MAIN,
	OBJ_MESSAGE,

	ITEM_ICE,

	OBJ_FIRE,
	OBJ_ICE,
	OBJ_WIND,
	OBJ_THUNDER,
	
	OBJ_FIREBLOCK,
	OBJ_FIREGATE,

	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_TOPBACK,
	OBJ_ENEMY,

	OBJ_HERO_BATTLE,
	OBJ_ENEMY_BATTLE,
	OBJ_BLOCK_BATTLE,
	OBJ_BACKGROUND_BATTLE,
	OBJ_BATTLE_MAIN,

	OBJ_KEY,
	OBJ_GATE,
	OBJ_WATER,
	OBJ_RESETBLOCK,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,

	ELEMENT_MYSTERY,
	ELEMENT_MYSTERY_BLOCK,
	ELEMENT_GATE_BLOCK,
	ELEMENT_WATER,
	ELEMENT_RESET,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjTitle.h"
#include "ObjHero.h"
#include "ObjMenu.h"
#include "ObjMain.h"

//Item�֌W
#include "ItemIce.h"


//Magic
#include "CObjFire.h"
#include "CObjIce.h"
#include "CObjWind.h"
#include "CObjThunder.h"

//Magic�֌W
#include "ObjFireblock.h"
#include "ObjFireGate.h"

#include "ObjEnemy.h"

#include "ObjBlock.h"
#include "ObjTopback.h"

//Battle�֌W
#include "ObjHeroBattle.h"
#include "ObjEnemyBattle.h"
#include "ObjBlockBattle.h"
#include "ObjBackgroundBattle.h"
#include "ObjBattleMain.h"

//������֌W
#include "ObjKey.h"
#include "ObjGate.h"
#include "ObjWater.h"
#include "ObjResetblock.h"

#include "ObjMessage.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMenu.h"
#include "SceneBattle.h"

//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneMain
//-----------------------------------------------