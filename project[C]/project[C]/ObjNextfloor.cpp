//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"

#include "ObjNextfloor.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjNextfloor::Init()
{
	g_map_change += 1;
}

//�A�N�V����
void CObjNextfloor::Action()
{

	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain());	//�Q�[�����C���V�[���Ɉڍs
	}
}

//�h���[
void CObjNextfloor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	wchar_t NEXT[128];

	//n�w�ڂւ̈ڍs�p�^�C�g��
	swprintf_s(NEXT, L"%d�w��",g_map_change + 1);		
	Font::StrDraw(NEXT, 300, 200, 100, c);

}
