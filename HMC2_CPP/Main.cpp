#include "Somethings.h"

int GameScene = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("Murder Girl's Fantasy");

	//�N��������
	if (MessageBox(NULL, "�t���X�N���[���ŋN�����܂����H\n�͂�(�t���X�N���[��)������(�E�C���h�E)",
		"������I", MB_YESNO) == IDYES) {
		ChangeWindowMode(FALSE);//�S��ʂɃZ�b�g
		SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
	}
	else {
		ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
		SetGraphMode(800, 600, 32);//��ʃT�C�Y�w��
	}

	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��

	//�摜�ǂݍ���
	int Hina = LoadGraph("res/img/hinas.bmp");	
	//�t�H���g�ǂݍ���
	if (!FontLoad()) {
		DxLib_End();
		return 0;
	}

	//�������ł����Ă�����
	InitTitle();
	GameInit();

	while (ProcessMessage() == 0 && gpUpdateKey()==0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		switch (GameScene) {
		case 0:
			//�^�C�g�����
			TitleMain();
			break;
		case 10:
			//�Q�[�����(�\��)
			GameMain();
			break;
		case 99:
			//�����I��
			goto EndbyAdmin;
			break;
		}
		

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}
	EndbyAdmin:
	DxLib_End();
	return 0;
}