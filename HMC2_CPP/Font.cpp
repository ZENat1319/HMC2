#include "Somethings.h"
int FontLoad(void) {
	//UglyQua
	LPCSTR UglyQua = "res/font/UglyQua.ttf";
	if (AddFontResourceEx(UglyQua, FR_PRIVATE, NULL) <= 0) {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	//源明朝
	LPCSTR Minamoto = "res/font/Minamoto.otf";
	if (AddFontResourceEx(Minamoto, FR_PRIVATE, NULL) <= 0) {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}

	return 1;
}