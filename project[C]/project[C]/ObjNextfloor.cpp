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
	
}

//�A�N�V����
void CObjNextfloor::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		g_map_change += 1;

	}
}

//�h���[
void CObjNextfloor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//Game�Ɉڍs�ꏊ
	Font::StrDraw(L"", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);

}
