#include "Somethings.h"

//フェードするやつ
bool FadeIn(int WIwin, int HEwin, int num) {
	for (int i = 0; ScreenFlip() == 0 && ProcessMessage() == 0 && i < num; i+=5) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 10);
		DrawBox(0, 0, WIwin, HEwin, 0, true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	return true;
}

bool FadeOut(int WIwin, int HEwin, int num) {
	static int bright = 0;
	for (static int i = 0; i < num; i++) {
		SetDrawBright(bright, bright, bright);
		DrawBox(0, 0, WIwin, HEwin, 0, true);
		bright++;
		if (i < 255)return true;
	}
	SetDrawBright(255, 255, 255);
	return false;
}