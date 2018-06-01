#include "Somethings.h"

int WideShotImg;
int SearchShotImg;
int LaserShotImg;
int OptionFont,OptionFont2;
int SelectOption=0;
int PadOn2 = 10;

void OptionKey(void);

void InitOption(void) {
	//�摜�ǂݍ���
	WideShotImg = LoadGraph("res/img/Option/wide_shot.png");
	SearchShotImg = LoadGraph("res/img/Option/search_shot.png");
	LaserShotImg = LoadGraph("res/img/Option/laser_shot.png");
	//�t�H���g�n���h���̓o�^
	OptionFont = CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	OptionFont2 = CreateFontToHandle("Source Han Serif", 44, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void OptionMain(void) {
	//�t�F�[�h�C������
	SetDrawBright(bright, bright, bright);
	DrawBox(0, 0, 800, 600, 0, true);
	if(bright<256)bright+=5;

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);
	//���C�h�V���b�g
	if (!SelectOption == 0) {
		DrawBox(13, 69, 13 + 252, 69 + 189, GetColor(255 / 2, 255 / 2, 255 / 2), true);
		SetDrawBlendMode(DX_BLENDMODE_MUL, 128);
	}
	DrawGraph(13, 69, WideShotImg, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);
	//�T�[�`�V���b�g
	if (!(SelectOption == 1)) {
		DrawBox(274, 206, 274 + 252, 206 + 189, GetColor(255 / 2, 255 / 2, 255 / 2), true);
		SetDrawBlendMode(DX_BLENDMODE_MUL, 128);
	}
	DrawGraph(274, 206, SearchShotImg, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);
	//���[�U�[�V���b�g
	if (!(SelectOption == 2)) {
		DrawBox(535, 342, 535 + 252, 342 + 189, GetColor(255 / 2, 255 / 2, 255 / 2), true);
		SetDrawBlendMode(DX_BLENDMODE_MUL, 128);
	}
	DrawGraph(535, 342, LaserShotImg, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);

	//���ƂȂ񂩕�����`��
	DrawStringToHandle(575, 10, "�����I��", GetColor(255, 255, 255), OptionFont2);
	DrawStringToHandle(13, 69 + 189, "WIDE SHOT", GetColor(255, 255, 255), OptionFont);
	DrawStringToHandle(274, 206 + 189, "SEARCH SHOT", GetColor(255, 255, 255), OptionFont);
	DrawStringToHandle(535, 342 + 189, "LASER SHOT", GetColor(255, 255, 255), OptionFont);

	OptionKey();
}

void OptionKey(void) {
	int Pad;
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�J�[�\���ړ�
	if (PadOn2 == 0 && (Pad & PAD_INPUT_UP || Pad & PAD_INPUT_LEFT))SelectOption--;
	if (PadOn2 == 0 && (Pad & PAD_INPUT_DOWN || Pad & PAD_INPUT_RIGHT))SelectOption++;
	if (PadOn2 == 0 && Key[KEY_INPUT_ESCAPE] == 1) { 
		FadeIn(800,600,20);	//���܂肫�ꂢ�Ƃ͌����Ȃ��t�F�[�h�A�E�g
		bright = 0;
		GameScene = 0; 
	}
	if (SelectOption < 0)SelectOption = 2;
	if (SelectOption > 2)SelectOption = 0;

	if (PadOn2 == 0 && Pad&PAD_INPUT_A || Key[KEY_INPUT_RETURN] == 1) {
		//START
		GameScene = 10;
	}

	if (Pad != 0)PadOn2++;
	if (Pad == 0)PadOn2 = 0;
}