#include "Somethings.h"
int FontLoad(void) {
	//飴鞭シンデレラ
	LPCSTR Amemuchi = "res/font/amemuchi.ttf";
	if (AddFontResourceEx(Amemuchi, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	//UglyQua
	LPCSTR UglyQua = "res/font/UglyQua.ttf";
	if (AddFontResourceEx(UglyQua, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	//明朝體​
	LPCSTR Mutsuki = "res/font/Mutsuki.ttf";
	if (AddFontResourceEx(Mutsuki, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	//源明朝
	LPCSTR Minamoto = "res/font/Minamoto.otf";
	if (AddFontResourceEx(Minamoto, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	//モナー
	LPCSTR Mona = "res/font/Mona.ttf";
	if (AddFontResourceEx(Mona, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	//小瑠璃ゴシック
	LPCSTR Koruri = "res/font/Koruri.ttf";
	if (AddFontResourceEx(Koruri, FR_PRIVATE, NULL) > 0) {
	}
	else {
		MessageBox(NULL, "フォント読み込み失敗", "", MB_OK);
		return 0;
	}
	return 1;
}