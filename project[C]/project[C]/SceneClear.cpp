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
#include "SceneClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//�Q�[���^�C�g���̏��������\�b�h
void CSceneClear::InitScene()
{
	Draw::LoadImageW(L"��.png", 0, TEX_SIZE_800_600);


	CObjClear* p = new CObjClear();
	Objs::InsertObj(p, OBJ_CLEAR, 1);

}

//�Q�[���^�C�g���̎��s�����\�b�h
void CSceneClear::Scene()
{

}
