#include "Somethings.h"

//フェードするやつ

//明るくなるほう
bool FadeIn(int WIwin, int HEwin, int num) {
	static int i = 0;
	SetDrawBright(i, i, i);
	i += num;
	if(i>=255)return true;
	return false;
}

//暗くなるほう
bool FadeOut(int WIwin, int HEwin, int num) {
	static int i = 255;
	SetDrawBright(i, i, i);
	i -= num;
	if (i <= 0)return true;
	return false;
}