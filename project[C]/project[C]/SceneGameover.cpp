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
#include "SceneGameover.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameover::CSceneGameover()
{

}

//�f�X�g���N�^
CSceneGameover::~CSceneGameover()
{

}

//�Q�[���^�C�g���̏��������\�b�h
void CSceneGameover::InitScene()
{
	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_800_600);


	CObjGameover* p = new CObjGameover();
	Objs::InsertObj(p, OBJ_GAMEOVER, 1);

}

//�Q�[���^�C�g���̎��s�����\�b�h
void CSceneGameover::Scene()
{

}
