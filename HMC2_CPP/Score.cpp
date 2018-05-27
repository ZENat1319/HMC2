#define _CRT_SECURE_NO_WARNINGS
#include "Somethings.h"

int ScorebarImg;
int BombIcon;
int Score = 0;
int HighScore = 0;
int Graze = 0;
int Power = 0;
int Lifes;
int Bombs=3;
int ScorebarFont;

void ScoreInit(void) {
	//画像読み込み
	ScorebarImg = LoadGraph("res/img/scorebar.bmp");
	BombIcon = LoadGraph("res/img/bomb_icon.bmp");
	//フォントハンドルの登録
	ScorebarFont = CreateFontToHandle("Source Han Serif", 14.5, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void ScoreDraw(void) {
	DrawGraph(0, 0, ScorebarImg, TRUE);
	DrawLine(0, 50, 800, 50, GetColor(255, 0, 0));

	char scorebar[256];

	//ハイスコア
	sprintf(scorebar, "%08d", HighScore);
	DrawStringToHandle(73,3,scorebar, GetColor(255, 255, 255),ScorebarFont);
	//スコア
	sprintf(scorebar, "%08d", Score);
	DrawStringToHandle(73, 30, scorebar, GetColor(255, 255, 255), ScorebarFont);
	//グレイズ
	sprintf(scorebar, "%08d", Graze);
	DrawStringToHandle(211, 30, scorebar, GetColor(255, 255, 255), ScorebarFont);
	//パワー
	sprintf(scorebar, "%-d", GetPlayerInfo(2));
	DrawStringToHandle(447, 3, scorebar, GetColor(255, 255, 255), ScorebarFont);
	//ボム
	if (Bombs < 5) {
		//ボムが４個以下
		for (int i = 0; i < Bombs; i++) {
			DrawGraph((383+i*16)+5,30,BombIcon,TRUE);
		}
	}
	else {
		//ボムが5個以上
		DrawGraph(383, 30, BombIcon, TRUE);
		DrawFormatString(399,30,GetColor(255,255,255)," x %d",Bombs,ScorebarFont);
	}
}

void ScoreAdd(int index,int increment) {
	switch (index) {
	case 0:
		//パワー
		Power += increment;
		break;
	case 1:
		//ボム
		Bombs += increment;
		break;
	case 2:
		//残機
		Lifes += increment;
		break;
	}
}

void ScoreSub(int index, int decrement) {
	switch (index) {
	case 0:
		//パワー
		Power -= decrement;
		break;
	case 1:
		//ボム
		Bombs -= decrement;
		break;
	case 2:
		//残機
		Lifes -= decrement;
		break;
	}
}