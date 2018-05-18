#include "Somethings.h"

void TitleKey(void);

int TitleLogo;
int CursorY;
int MenuFont,MenuFont2;

//タイトル画面初期化
void InitTitle(void) {
	TitleLogo = LoadGraph("res/img/title.bmp");
	MenuFont = CreateFontToHandle("UglyQua", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	MenuFont2 = CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	CursorY = 0;
}

//タイトルメイン
void TitleMain(void) {
	//gpUpdateKey();
	//ロゴ描画
	DrawGraph(350,200,TitleLogo,TRUE);

	//選択肢
	DrawStringToHandle(100, 400, "START", GetColor(255,255,255),MenuFont);
	DrawStringToHandle(100, 425, "EXTRA START", GetColor(255, 255, 255), MenuFont);
	DrawStringToHandle(100, 450, "MUSIC ROOM", GetColor(255, 255, 255), MenuFont);
	DrawStringToHandle(100, 475, "SETTING", GetColor(255, 255, 255), MenuFont);
	DrawStringToHandle(100, 500, "EXIT", GetColor(255, 255, 255), MenuFont);

	//カーソル
	DrawStringToHandle(70, 400+CursorY, ">", GetColor(255, 255, 255), MenuFont2);

	//説明文
	switch (CursorY) {
	case 0:
		DrawStringToHandle(450,575,"殺戮を開始します",GetColor(255,255,255), MenuFont2);
		break;
	case 25:
		DrawStringToHandle(450, 575, "激しく殺戮を開始します", GetColor(255, 255, 255), MenuFont2);
		break;
	case 50:
		DrawStringToHandle(450, 575, "音楽に酔います", GetColor(255, 255, 255), MenuFont2);
		break;
	case 75:
		DrawStringToHandle(450, 575, "世界を改変します", GetColor(255, 255, 255), MenuFont2);
		break;
	case 100:
		DrawStringToHandle(450, 575, "この世界にさよならします", GetColor(255, 255, 255), MenuFont2);
		break;
	}

	TitleKey();
}

void TitleKey(void) {
	//カーソル移動
	if (Key[KEY_INPUT_UP] == 1)CursorY -= 25;
	if (Key[KEY_INPUT_DOWN] == 1)CursorY += 25;
	if (Key[KEY_INPUT_ESCAPE] == 1)CursorY = 100;
	if (CursorY > 100)CursorY = 0;
	if (CursorY < 0)CursorY = 100;

	if (Key[KEY_INPUT_Z] == 1|| Key[KEY_INPUT_RETURN] == 1) {
		switch (CursorY) {
		case 0:
			//START
			GameScene = 10;
			break;
		case 100:
			//EXIT
			GameScene = 99;
			break;
		}
	}
}