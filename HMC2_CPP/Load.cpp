#include "Somethings.h"

int LoadImg;

void LoadInit(void) {
	LoadImg = LoadGraph("res/img/Loading.png");
}

void LoadMain(int Next) {
	DrawGraph(500, 500, LoadImg, TRUE);
	if (GetASyncLoadNum() == 0)GameScene = Next;
}