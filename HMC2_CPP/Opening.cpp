#include "Somethings.h"

int BootFont;

void InitOp(void) {
	BootFont= CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_NORMAL);
}

void OpMain(void) {
	static int clock = 0;
	DrawStringToHandle(0, 0, "AngelHead PC-Q800 Series Personal Computer", GetColor(255, 255, 255), BootFont);
	if (clock > 120) {
		DrawStringToHandle(0, 16, 
			"ﾁﾃﾝｼ Hina's Memory Collection ﾊﾞｰｼﾞｮﾝ 2.00\nCopyright 2018 Bloody Angel's Head / dorin"
			, GetColor(255, 255, 255), BootFont);
	}
	clock++;
}

/*
AngelHead PC-Q800 Series Personal Computer

ﾁﾃﾝｼ Hina's Memory Collection ﾊﾞｰｼﾞｮﾝ 2.00
Copyright 2018 Bloody Angel's Head / dorin

メモリチェック...[多分OK]
リソースファイルチェック...[OK]

Opening ﾊﾞｰｼﾞｮﾝ 2.nn
A:\>game
A:\>CHKAUDIO
サウンドデバイス (device name) が使用可能です
INT 5で多分常駐しません

A:\>DORCOM /1 /M:WF(ウインドウかフルスクリーン)
常駐します(うそ)。
ゲーム終了までよろしくおねがいします。

A:\>OP /1

*/