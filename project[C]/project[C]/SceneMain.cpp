//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[���^�C�g���̏��������\�b�h
void CSceneMain::InitScene()
{
	m_f = true;
	//�O���f�[�^�ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p;	//�X�e�[�W���|�C���^�[
	int size;				//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"map1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[27][55];
	int count = 1;
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 1;
			}
			count += 2;
		}
	}

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Hero.png", 0, TEX_SIZE_256_128);
	Draw::LoadImageW(L"floor1.png", FLOOR1, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Block.png", BLOCK1, TEX_SIZE_800_600);
	Draw::LoadImageW(L"image.png", 3, TEX_SIZE_100);
	Draw::LoadImageW(L"nazotoki.png", 4, TEX_SIZE_100);
	Draw::LoadImageW(L"healkey.png", HEALKEY, TEX_SIZE_100);
	Draw::LoadImageW(L"Water.png", 6, TEX_SIZE_200);
	Draw::LoadImageW(L"Enemy1.png", 7, TEX_SIZE_200_100);
	Draw::LoadImageW(L"Magic.png", 8, TEX_SIZE_100);
	Draw::LoadImageW(L"Candle.png", 9, TEX_SIZE_200_100);
	Draw::LoadImageW(L"magicitem.png", ITEM, TEX_SIZE_256);
	Draw::LoadImageW(L"Hero2.png", 11, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor1_Enemy.png", 12, TEX_SIZE_100);



	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 115);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 109);

	CObjTopback* objtb = new CObjTopback();
	Objs::InsertObj(objtb, OBJ_TOPBACK, 119);

	CObjMain* objm = new CObjMain();
	Objs::InsertObj(objm, OBJ_MAIN, 120);

	CObjMessage* objmessa = new CObjMessage();
	Objs::InsertObj(objmessa, OBJ_MESSAGE, 120);

	
	//��l���I�u�W�F�N�g�쐬
	CObjHeroBattle* bobj = new CObjHeroBattle();
	Objs::InsertObj(bobj, OBJ_HERO_BATTLE, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlockBattle* bobjb = new CObjBlockBattle();
	Objs::InsertObj(bobjb, OBJ_BLOCK_BATTLE, 9);

	//�G(�퓬)�I�u�W�F�N�g�쐬
	CObjEnemyBattle* bobje = new CObjEnemyBattle();
	Objs::InsertObj(bobje, OBJ_ENEMY_BATTLE, 10);

	//�w�i(�퓬)�I�u�W�F�N�g�쐬
	CObjBackgroundBattle* bobjbackb = new CObjBackgroundBattle();
	Objs::InsertObj(bobjbackb, OBJ_BACKGROUND_BATTLE,8);
}

//�Q�[���^�C�g���̎��s�����\�b�h
void CSceneMain::Scene()
{
	
}
