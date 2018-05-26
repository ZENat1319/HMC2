#include "Somethings.h"

int WideShotImg;
int SearchShotImg;
int LaserShotImg;
int OptionFont,OptionFont2;
int SelectOption=0;

void InitOption(void) {
	WideShotImg = LoadGraph("res/img/Option/wide_shot.png");
	SearchShotImg = LoadGraph("res/img/Option/search_shot.png");
	LaserShotImg = LoadGraph("res/img/Option/laser_shot.png");
	OptionFont = CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	OptionFont2 = CreateFontToHandle("Source Han Serif", 44, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void OptionMain(void) {
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);
	if (!SelectOption == 0) {
		DrawBox(13, 69, 13 + 252, 69 + 189, GetColor(255 / 2, 255 / 2, 255 / 2), true);
		SetDrawBlendMode(DX_BLENDMODE_MUL, 128);
	}
	DrawGraph(13, 69, WideShotImg, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);

	if (!(SelectOption == 1)) {
		DrawBox(274, 206, 274 + 252, 206 + 189, GetColor(255 / 2, 255 / 2, 255 / 2), true);
		SetDrawBlendMode(DX_BLENDMODE_MUL, 128);
	}
	DrawGraph(274, 206, SearchShotImg, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);

	if (!(SelectOption == 2)) {
		DrawBox(535, 342, 535 + 252, 342 + 189, GetColor(255 / 2, 255 / 2, 255 / 2), true);
		SetDrawBlendMode(DX_BLENDMODE_MUL, 128);
	}
	DrawGraph(535, 342, LaserShotImg, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);

	DrawStringToHandle(575, 10, "‘•”õ‘I‘ð", GetColor(255, 255, 255), OptionFont2);
	DrawStringToHandle(13, 69 + 189, "WIDE SHOT", GetColor(255, 255, 255), OptionFont);
	DrawStringToHandle(274, 206 + 189, "SEARCH SHOT", GetColor(255, 255, 255), OptionFont);
	DrawStringToHandle(535, 342 + 189, "LASER SHOT", GetColor(255, 255, 255), OptionFont);
}