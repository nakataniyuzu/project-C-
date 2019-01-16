#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_TITLE,
	OBJ_GAMEOVER,
	OBJ_MENU,
	OBJ_MAIN,
	OBJ_CLEAR,
	OBJ_MESSAGE,
	OBJ_NEXT_FLOOR,

	OBJ_SWORD_BATTLE,

	ITEM_ICE,
	ITEM_WIND,

	OBJ_FIRE,
	OBJ_ICE,
	OBJ_WIND,
	OBJ_THUNDER,

	OBJ_FIRE_BATTLE,
	OBJ_ICE_BATTLE,
	OBJ_THUNDER_BATTLE,
	OBJ_ENEMY_MAGIC_BATTLE,

	OBJ_FIREBLOCK,
	OBJ_FIREGATE,

	OBJ_HERO,
	OBJ_SISTER,
	OBJ_BLOCK,
	OBJ_TOPBACK,
	OBJ_ENEMY,
	OBJ_ENEMY_FIRST,
	OBJ_ENEMY_SECOND,
	OBJ_ENEMY_THIRD,

	OBJ_HERO_BATTLE,
	OBJ_BOSS,
	OBJ_BOSS_BATTLE,
	OBJ_BOSS_BATTLE_FIRST,
	OBJ_BOSS_BATTLE_SECOND,
	OBJ_BOSS_BATTLE_THIRD,
	OBJ_BOSS_BATTLE_FINAL,

	OBJ_BLOCK_BATTLE,
	OBJ_BACKGROUND_BATTLE,

	OBJ_BATTLE_MAIN,
	OBJ_ENEMY_BATTLE,
	OBJ_ENEMY_BATTLE_FIRST,
	OBJ_ENEMY_BATTLE_SECOND,
	OBJ_ENEMY_BATTLE_THIRD,

	OBJ_HEAL,
	OBJ_KEY,
	OBJ_GATE,
	OBJ_WATER,
	OBJ_RESETBLOCK,
	OBJ_SWITCH,
	OBJ_SWITCHGATE,
	OBJ_DUMMYSWITCH,
	OBJ_CHANGESWITCH,
	OBJ_CHANGEGATE,
	OBJ_BOSSSWITCH,
	OBJ_BOSSGATE,
	OBJ_STAIRS,

	OBJ_FADEIN,
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
	ELEMENT_BOSS,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_SWORD,
	ELEMENT_ATTACK,

	ELEMENT_ENEMY_BATTLE,
	ELEMENT_BOSS_BATTLE,
	ELEMENT_MAGIC_BATTLE,


	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,

	ELEMENT_SISTER,
	ELEMENT_HEAL,
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

#define ALL_SIZE 50.0f		//�u���b�N���̃T�C�Y
extern int g_map_change;	//�}�b�v�ύX�p�ϐ�
extern bool g_battle_flag;	//�o�g����ʕύX�p�̃t���O
extern bool g_key_flag;		//�L�[���͐���p�t���O
extern int g_enemy_kills;	//�G�̌��j��

//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjTitle.h"
#include "ObjHero.h"
#include "ObjSister.h"
#include "ObjMenu.h"
#include "ObjMain.h"
#include "ObjClear.h"
#include "ObjGameover.h"
#include "ObjNextfloor.h"

//Item�֌W
#include "ItemIce.h"
#include "ItemWind.h"

#include "ObjHeal.h"

//���֌W
#include "CObjSwordBattle.h"

//Magic
#include "CObjFire.h"
#include "CObjIce.h"
#include "CObjWind.h"
#include "CObjThunder.h"

#include "CObjFireBattle.h"
#include "CObjIceBattle.h"
#include "CObjThunderBattle.h"
#include "CObjEnemyMagicBattle.h"

//Magic�֌W
#include "ObjFireblock.h"
#include "ObjFireGate.h"

//Enemy�֌W
#include "ObjBoss.h"
#include "ObjBoss1Battle.h"
#include "ObjBoss2Battle.h"
#include "ObjBoss3Battle.h"
#include "ObjEnemyboss1.h"
#include "ObjEnemy1.h"
#include "ObjEnemy2.h"


#include "ObjBlock.h"
#include "ObjTopback.h"

//Battle�֌W
#include "ObjHeroBattle.h"
#include "ObjEnemy1Battle.h"
#include "ObjEnemy2Battle.h"
#include "ObjEnemy3Battle.h"
#include "ObjBlockBattle.h"
#include "ObjBackgroundBattle.h"

//������֌W
#include "ObjKey.h"
#include "ObjGate.h"
#include "ObjWater.h"
#include "ObjResetblock.h"
#include "ObjSwitch.h"
#include "ObjSwitchGate.h"
#include "ObjStairs.h"
#include "ObjDummySwitch.h"
#include "ObjChangeSwitch.h"
#include "ObjChangeGate1.h"
#include "ObjChangeGate2.h"
#include "ObjBossSwitch.h"
#include "ObjBossGate.h"

#include "ObjMessage.h"
#include "ObjFadein.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMenu.h"
#include "SceneBattle.h"
#include "SceneGameover.h"
#include "SceneClear.h"
#include "SceneNextfloor.h"

//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------