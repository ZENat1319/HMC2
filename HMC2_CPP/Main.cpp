#include "Somethings.h"

int GameScene = 0;
int bright = 255;
int GrobalSceneChage = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("Murder Girl's Fantasy");

	//�N��������
	/*if (MessageBox(NULL, "�t���X�N���[���ŋN�����܂����H\n�͂�(�t���X�N���[��)������(�E�C���h�E)",
	"������I", MB_YESNO) == IDYES) {
	ChangeWindowMode(FALSE);//�S��ʂɃZ�b�g
	SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
	}
	else {*/
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
							   //}

	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��

										 //�t�H���g�ǂݍ���
	if (!FontLoad()) {
		DxLib_End();
		return 0;
	}
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

	//�������ł����Ă�����
	InitTitle();
	InitOption();
	GameInit();

	GameScene = SC_TITLE;

	//�߂���邤��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && gpUpdateKey() == 0)
	{
		ClearDrawScreen();	//���������͒P�̂ł��������Ȃ�

		switch (GameScene) {
		case SC_TITLE:
			//�^�C�g�����
			TitleMain();
			break;
		case SC_OPTION:
			//�����I�����
			OptionMain();
			break;
		case SC_GAME:
			//�Q�[�����(�\��)
			GameMain();
			break;
		case SC_ENDFUCK:
			//�����I��
			goto EndbyAdmin;
			break;
		}
		DrawFps();
	}
EndbyAdmin:
	DxLib_End();
	return 0;
}

int ProgramInit(void) {
	//�t�H���g�ǂݍ���
	if (!FontLoad()) {
		DxLib_End();
		return -1;
	}

	//�������ł����Ă�����
	InitTitle();
	InitOption();
	GameInit();
	return 0;
}

void LoadMain(int Next) {
	if (GetASyncLoadNum() == 0)GameScene = Next;
}