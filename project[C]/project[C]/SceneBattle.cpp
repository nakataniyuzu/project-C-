//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneBattle.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneBattle::CSceneBattle()
{

}

//�f�X�g���N�^
CSceneBattle::~CSceneBattle()
{

}

//�Q�[���퓬���������\�b�h
void CSceneBattle::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Hero2.png", 0, TEX_SIZE_100);
	Draw::LoadImageW(L"Battlefloor.png", 1, TEX_SIZE_100);
	Draw::LoadImageW(L"Wall.png", FLOOR1_WALL,TEX_SIZE_100);
	Draw::LoadImageW(L"Floor1_Enemy.png", 3, TEX_SIZE_100);
	Draw::LoadImageW(L"MagicBattle.png", 4, TEX_SIZE_100);
	Draw::LoadImageW(L"magicitem.png", 10, TEX_SIZE_256);

	//��l���I�u�W�F�N�g�쐬
	CObjHeroBattle* obj = new CObjHeroBattle();
	Objs::InsertObj(obj, OBJ_HERO_BATTLE, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlockBattle* objb = new CObjBlockBattle();
	Objs::InsertObj(objb, OBJ_BLOCK_BATTLE, 9);

	//�G(�퓬)�I�u�W�F�N�g�쐬
	CObjEnemyBattle* obje = new CObjEnemyBattle();
	Objs::InsertObj(obje, OBJ_ENEMY_BATTLE, 10);

	//�w�i(�퓬)�I�u�W�F�N�g�쐬
	CObjBackgroundBattle* objbackb = new CObjBackgroundBattle();
	Objs::InsertObj(objbackb, OBJ_BACKGROUND_BATTLE, 8);

	CObjBattleMain* p = new CObjBattleMain();
	Objs::InsertObj(p, OBJ_MAIN, 20);
}

//�Q�[���퓬���s�����\�b�h
void CSceneBattle::Scene()
{

}