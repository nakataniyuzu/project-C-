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
#include "SceneTitle.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[���^�C�g���̏��������\�b�h
void CSceneTitle::InitScene()
{
	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_800_600);

	//�I�[�f�B�I�ǂݍ���
	Audio::LoadAudio(1, L"SERECT.wav", EFFECT);
	Audio::LoadAudio(2, L"ENTER.wav", EFFECT);
	Audio::LoadAudio(100, L"TITLE-BGM.WAV", SOUND_TYPE::BACK_MUSIC);


	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 1);

}

//�Q�[���^�C�g���̎��s�����\�b�h
void CSceneTitle::Scene()
{

}
