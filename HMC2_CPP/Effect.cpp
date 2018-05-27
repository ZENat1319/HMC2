#include "Somethings.h"

//フェードするやつ
bool FadeIO(int WIwin, int HEwin, int num) {
	for (int i = 0; ScreenFlip() == 0 && ProcessMessage() == 0 && i < num; i++) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 10);
		DrawBox(0, 0, WIwin, HEwin, 0, true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	return true;
};