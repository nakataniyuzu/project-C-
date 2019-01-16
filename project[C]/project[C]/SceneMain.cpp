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

	if (g_map_change == 0) {
		p = Save::ExternalDataOpen(L"map1.csv", &size);//�O���f�[�^�ǂݍ���
	}
	else if (g_map_change == 1) {
		p = Save::ExternalDataOpen(L"map2.csv", &size);//�O���f�[�^�ǂݍ���
	}

	int map[38][65];
	int count = 1;
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 65; j++)
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

	m_time = 0;

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Hero.png", 0, TEX_SIZE_256);
	if (g_map_change == 0) {
		Draw::LoadImageW(L"Floor1.png", FLOOR, TEX_SIZE_800_600);	//�P�w�ڂ̏�
		Draw::LoadImageW(L"Floor1Block.png", BLOCK, TEX_SIZE_800_600);	//1�w�ڂ̃u���b�N
	}
	else if (g_map_change == 1) {
		Draw::LoadImageW(L"Floor2.png", FLOOR, TEX_SIZE_800_600);	//�Q�w�ڂ̏�
		Draw::LoadImageW(L"Floor2Block.png", BLOCK, TEX_SIZE_800_600);	//2�w�ڂ̃u���b�N
	}

	Draw::LoadImageW(L"image.png", 3, TEX_SIZE_100);
	//Draw::LoadImageW(L"nazotoki.png", 4, TEX_SIZE_100);
	Draw::LoadImageW(L"healkey.png", HEALKEY, TEX_SIZE_100);
	Draw::LoadImageW(L"Water.png", 6, TEX_SIZE_200);
	Draw::LoadImageW(L"Enemy1.png", 7, TEX_SIZE_200_100);
	Draw::LoadImageW(L"Magic.png", 8, TEX_SIZE_100);
	Draw::LoadImageW(L"Candle.png", 9, TEX_SIZE_200_100);
	Draw::LoadImageW(L"magicitem.png", ITEM, TEX_SIZE_256);
	Draw::LoadImageW(L"Hero2.png", 11, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor1_Enemy.png", 12, TEX_SIZE_100);
	Draw::LoadImageW(L"MagicBattle.png", 13, TEX_SIZE_256);
	Draw::LoadImageW(L"ENEMYBOSS1.png", 14, TEX_SIZE_800_600);
	Draw::LoadImageW(L"sister.png", 15, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Sword.png", 16, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Fadein.png", 17, TEX_SIZE_16000_600);
	Draw::LoadImageW(L"Stairs.png", 18, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor2_Enemy.png", 19, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor3_Enemy.png", 20, TEX_SIZE_100);
	Draw::LoadImageW(L"ENEMYBOSS2.png", 21, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Floor1~2.png", 50, TEX_SIZE_800_600);
	Draw::LoadImageW(L"ENEMYBOSS3.png", 22, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Floor1_Enemy_Death.png", 23, TEX_SIZE_100);
	Draw::LoadImageW(L"ENEMYBOSS3_MAGIC.png", 24, TEX_SIZE_100);
	Draw::LoadImageW(L"ENEMYBOSS1_DEATH.png", 25, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor2_Enemy_Death.png", 26, TEX_SIZE_100);
	Draw::LoadImageW(L"ENEMYBOSS2_DEATH.png", 27, TEX_SIZE_100);
	Draw::LoadImageW(L"Floor3_Enemy_Death.png", 28, TEX_SIZE_100);
	Draw::LoadImageW(L"ENEMYBOSS3_DEATH.png", 29, TEX_SIZE_100);

	Draw::LoadImageW(L"AllFloorBlock.png", 4, TEX_SIZE_200_100);

	
	//�I�[�f�B�I�ǂݍ���
	Audio::LoadAudio(0, L"ATTACK.WAV", EFFECT);
	Audio::LoadAudio(1, L"BATTLE-START.wav", EFFECT);
	Audio::LoadAudio(2, L"BATTLE-WIN.wav", EFFECT);
	Audio::LoadAudio(3, L"DAMAGE.WAV", EFFECT);
	Audio::LoadAudio(4, L"DOOR-OPEN.wav", EFFECT);
	Audio::LoadAudio(5, L"ENE-MAGIC.wav", EFFECT);
	Audio::LoadAudio(6, L"ENE-RANGE-ATTACK.wav", EFFECT);
	Audio::LoadAudio(7, L"FIRE.WAV", EFFECT);
	Audio::LoadAudio(8, L"ICE.WAV", EFFECT);
	Audio::LoadAudio(9, L"THUNDER.WAV", EFFECT);
	Audio::LoadAudio(10, L"HEAL.WAV", EFFECT);
	Audio::LoadAudio(11, L"ZELDA.WAV", EFFECT);

	Audio::LoadAudio(14, L"ENTER.wav", EFFECT);

	Audio::LoadAudio(12, L"STAGEBGM���1.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(13, L"BATTLE-BGM.wav", SOUND_TYPE::BACK_MUSIC);

	//BGM�X�^�[�g
	float Volume = Audio::Volume(1.0,12);//�{�����[��������
	Audio::Start(12);
	
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
	CObjHeroBattle* bhero = new CObjHeroBattle();
	Objs::InsertObj(bhero, OBJ_HERO_BATTLE, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlockBattle* bobjb = new CObjBlockBattle();
	Objs::InsertObj(bobjb, OBJ_BLOCK_BATTLE, 9);
	
	
	//�G(1�w��)�I�u�W�F�N�g�쐬
	//CObjEnemy1Battle* bobje1 = new CObjEnemy1Battle();
	//Objs::InsertObj(bobje1, OBJ_ENEMY_BATTLE_FIRST, 10);

	//�G(2�w��)�I�u�W�F�N�g�쐬
	/*CObjEnemy2Battle* bobje2 = new CObjEnemy2Battle();
	Objs::InsertObj(bobje2, OBJ_ENEMY_BATTLE_SECOND, 10);*/

	//�G(3�w��)�I�u�W�F�N�g�쐬
	/*CObjEnemy3Battle* bobje3 = new CObjEnemy3Battle();
	Objs::InsertObj(bobje3, OBJ_ENEMY_BATTLE_THIRD, 10);*/
	
	//�w�i(�퓬)�I�u�W�F�N�g�쐬
	CObjBackgroundBattle* bobjbackb = new CObjBackgroundBattle();
	Objs::InsertObj(bobjbackb, OBJ_BACKGROUND_BATTLE,8);
}

//�Q�[���^�C�g���̎��s�����\�b�h
void CSceneMain::Scene()
{
	

	m_time++;

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_enemy_flag = hero->GetENEMYF();
	m_boss_flag = hero->GetBOSSF();

	//1�w�ڎG��
	/*if (m_enemy_flag == true)		//�t���O���I���̎��A�G�o��
	{
		Audio::Stop(12);
		Audio::Start(13);
		CObjEnemy1Battle* bobje = new CObjEnemy1Battle();
		Objs::InsertObj(bobje, OBJ_ENEMY_BATTLE_FIRST, 10);
		m_enemy_flag = false;
		hero->SetENEMYF(m_enemy_flag);
	}*/
	//1�w�ڃ{�X
	/*if (m_boss_flag == true)		//�t���O���I���̎��A�{�X�o��
	{
		CObjBoss1Battle* bobjb = new CObjBoss1Battle();
		Objs::InsertObj(bobjb, OBJ_BOSS_BATTLE_FIRST, 10);
		m_boss_flag = false;
		hero->SetBOSSF(m_boss_flag);
	}*/

	//2�w�ڎG��
	/*if (m_enemy_flag == true)		//�t���O���I���̎��A�G�o��
	{
	CObjEnemy2Battle* bobje = new CObjEnemy2Battle();
	Objs::InsertObj(bobje, OBJ_ENEMY_BATTLE_SECOND, 10);
	m_enemy_flag = false;
	hero->SetENEMYF(m_enemy_flag);
	}*/
	//2�w�ڃ{�X
	/*if (m_boss_flag == true)		//�t���O���I���̎��A�{�X�o��
	{
		CObjBoss2Battle* bobjb = new CObjBoss2Battle();
		Objs::InsertObj(bobjb, OBJ_BOSS_BATTLE_SECOND, 10);
		m_boss_flag = false;
		hero->SetBOSSF(m_boss_flag);
	}*/

	//3�w�ڎG��
	/*if (m_enemy_flag == true || m_time == 400)		//�t���O���I���̎��A�G�o��
	{
		CObjEnemy3Battle* bobje = new CObjEnemy3Battle();
		Objs::InsertObj(bobje, OBJ_ENEMY_BATTLE_THIRD, 10);
		m_enemy_flag = false;
		hero->SetENEMYF(m_enemy_flag);
	}*/
	//3�w�ڃ{�X
	if (m_boss_flag == true)		//�t���O���I���̎��A�{�X�o��
	{
	CObjBoss3Battle* bobjb = new CObjBoss3Battle();
	Objs::InsertObj(bobjb, OBJ_BOSS_BATTLE_THIRD, 10);
	m_boss_flag = false;
	hero->SetBOSSF(m_boss_flag);
	}
}
