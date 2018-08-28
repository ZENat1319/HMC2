#include "Somethings.h"

int GameScene = 0,LdNextScene=0;
int bright = 255;
int GrobalSceneChage = false;
int ProgramInit(void);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("Murder Girl's Fantasy");
	//�N�����X�N���[���T�C�Y����
#ifdef _DEBUG
	//DEBUG���E�C���h�E���[�h
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
#else
	if (MessageBox(NULL, "�t���X�N���[���ŋN�����܂����H\n�͂�(�t���X�N���[��)������(�E�C���h�E)",
	"������I", MB_YESNO) == IDYES) {
		ChangeWindowMode(FALSE);//�S��ʂɃZ�b�g
		SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
	}
	else {
		ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
		SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
	}
#endif

	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��
	SetUseASyncLoadFlag(TRUE);
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�@�����������ق����ǂ��ˁH
	//�t�H���g�ǂݍ���									 
	if (!FontLoad()) {
		DxLib_End();
		return 0;
	}
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

	//�������ł����Ă�����
	LoadInit();
	ProgramInit();

	GameScene = SC_INIT;
	LdNextScene = SC_TITLE;

	//�߂���邤��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && gpUpdateKey() == 0)
	{
		ClearDrawScreen();	//���������͒P�̂ł��������Ȃ�

		switch (GameScene) {
		case SC_INIT:
			//���[�h���
			LoadMain(LdNextScene);
			break;
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
	//�������ł����Ă�����
	InitTitle();
	InitOption();
	GameInit();
	return 0;
}