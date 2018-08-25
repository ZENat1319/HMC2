#include "Somethings.h"

void TitleKey(void);

int TitleLogo;
int CursorY;
int PadOn = 0;
int MenuFont,MenuFont2;

//�^�C�g����ʏ�����
void InitTitle(void) {
	TitleLogo = LoadGraph("res/img/title.png");
	MenuFont = CreateFontToHandle("UglyQua", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	MenuFont2 = CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	CursorY = 0;
}

//�^�C�g�����C��
void TitleMain(void) {
	////�V�[���`�F���W��̃t�F�[�h�΍�
	//if (GrobalSceneChange) {
	//	GrobalSceneChange = false;
	//	FadeEnd = false;
	//	FadeIO = true;
	//}
	////�t�F�[�h�C���A�E�g����
	//if (FadeIO) {
	//	//���邭�Ȃ��
	//	/*if (!FadeEnd)*/FadeEnd = FadeIn(800, 600, 10);
	//}
	//else {
	//	//�Â��Ȃ��
	//	/*if (!FadeEnd)*/FadeEnd = FadeOut(800, 600, 10);
	//}

	//���S�`��
	DrawGraph(350,200,TitleLogo,TRUE);

	//�I����
	DrawStringToHandle(100, 400, "START", GetColor(255,255,255),MenuFont);
	DrawStringToHandle(100, 425, "EXTRA START", GetColor(255, 255, 255), MenuFont);
	DrawStringToHandle(100, 450, "MUSIC ROOM", GetColor(255, 255, 255), MenuFont);
	DrawStringToHandle(100, 475, "SETTING", GetColor(255, 255, 255), MenuFont);
	DrawStringToHandle(100, 500, "EXIT", GetColor(255, 255, 255), MenuFont);

	//�J�[�\��
	DrawStringToHandle(70, 400+CursorY, ">", GetColor(255, 255, 255), MenuFont2);

	//������
	switch (CursorY) {
	case 0:
		DrawStringToHandle(450,575,"�E�C���J�n���܂�",GetColor(255,255,255), MenuFont2);
		break;
	case 25:
		DrawStringToHandle(450, 575, "�������E�C���J�n���܂�", GetColor(255, 255, 255), MenuFont2);
		break;
	case 50:
		DrawStringToHandle(450, 575, "���y�ɐ����܂�", GetColor(255, 255, 255), MenuFont2);
		break;
	case 75:
		DrawStringToHandle(450, 575, "���E�����ς��܂�", GetColor(255, 255, 255), MenuFont2);
		break;
	case 100:
		DrawStringToHandle(450, 575, "���̐��E�ɂ���Ȃ炵�܂�", GetColor(255, 255, 255), MenuFont2);
		break;
	}

	TitleKey();
}

void TitleKey(void) {
	int Pad;
	static int NextScene;
	static bool SceneChange = false;
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//�J�[�\���ړ� 
	//if (FadeEnd) {
		if (PadOn == 0 && Pad & PAD_INPUT_UP)CursorY -= 25;
		if (PadOn == 0 && Pad & PAD_INPUT_DOWN)CursorY += 25;
		if (PadOn == 0 && Key[KEY_INPUT_ESCAPE] == 1)CursorY = 100;
		if (CursorY > 100)CursorY = 0;
		if (CursorY < 0)CursorY = 100;
	//}

	if ((PadOn == 0 && Pad&PAD_INPUT_A) || (Key[KEY_INPUT_RETURN] == 1)) {
		switch (CursorY) {
		case 0:
			//START
			SceneChange = true;
			NextScene = SC_OPTION;
			break;
		case 100:
			//EXIT
			SceneChange = true;
			NextScene = SC_ENDFUCK;
			break;
		}
	}

	//�V�[���`�F���W
	if(SceneChange)GameScene = NextScene;

	if (Pad != 0)PadOn++;
	if (Pad == 0)PadOn = 0;
}