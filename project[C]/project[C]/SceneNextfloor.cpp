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
#include "SceneNextfloor.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneNextfloor::CSceneNextfloor()
{

}

//�f�X�g���N�^
CSceneNextfloor::~CSceneNextfloor()
{

}

//�Q�[���^�C�g���̏��������\�b�h
void CSceneNextfloor::InitScene()
{
	Draw::LoadImageW(L"Floor1up2.png", 0, TEX_SIZE_800_600);
	Draw::LoadImageW(L"Floor2up3.png", 1, TEX_SIZE_800_600);

	
	CObjNextfloor* p = new CObjNextfloor();
	Objs::InsertObj(p, OBJ_CLEAR, 1);
}

//�Q�[���^�C�g���̎��s�����\�b�h
void CSceneNextfloor::Scene()
{

}
