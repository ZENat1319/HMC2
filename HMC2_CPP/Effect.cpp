#include "Somethings.h"

//フェードするやつ
bool FadeIn(int WIwin, int HEwin, int num) {
	for (static int i = 0;i < num; i+=5) {
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 10);
		SetDrawBright(255-i,255-i,255-i);
		//DrawBox(0, 0, WIwin, HEwin, 0, true);
		if (i < 255)return true;
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);
	return false;
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