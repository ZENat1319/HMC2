#include "Somethings.h"

void TitleKey(void);

int TitleLogo;
int CursorY;
int PadOn = 0;
int MenuFont,MenuFont2;
int Next = 0;

//タイトル画面初期化
void InitTitle(void) {
	TitleLogo = LoadGraph("res/img/title.png");
	MenuFont = CreateFontToHandle("UglyQua", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	MenuFont2 = CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	CursorY = 0;
}

//タイトルメイン
void TitleMain(void) {
	SetDrawBright(bright, bright, bright);
	DrawBox(0, 0, 800, 600, 0, true);
	if (bright<256)bright += 5;
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
	int Pad;
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//カーソル移動
	if (PadOn == 0 && Pad & PAD_INPUT_UP)CursorY -= 25;
	if (PadOn == 0 && Pad & PAD_INPUT_DOWN)CursorY += 25;
	if (PadOn == 0 && Key[KEY_INPUT_ESCAPE] == 1)CursorY = 100;
	if (CursorY > 100)CursorY = 0;
	if (CursorY < 0)CursorY = 100;

	if (PadOn == 0 && Pad&PAD_INPUT_A|| Key[KEY_INPUT_RETURN] == 1) {
		switch (CursorY) {
		case 0:
			//START
			FadeIn(800, 600, 20);
			bright = 0;
			GameScene = 5;
			break;
		case 100:
			//EXIT
			GameScene = 99;
			break;
		}
	}
	if (Pad != 0)PadOn++;
	if (Pad == 0)PadOn = 0;
}