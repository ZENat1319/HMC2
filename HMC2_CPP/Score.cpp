#include "Somethings.h"

int Scorebar;
int BombIcon;
int Score = 0;
int HighScore = 0;
int Graze = 0;
int Power = 0;
int Lifes;
int Bombs=3;
int ScorebarFont;

void ScoreInit(void) {
	Scorebar = LoadGraph("res/img/scorebar.bmp");
	BombIcon = LoadGraph("res/img/bomb_icon.bmp");
	ScorebarFont = CreateFontToHandle("Source Han Serif", 26, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void ScoreDraw(void) {
	DrawGraph(0, 0, Scorebar, TRUE);
	DrawLine(0, 50, 800, 50, GetColor(255, 0, 0));

	DrawFormatString(73, 3, GetColor(255,255,255), "%08d", HighScore, ScorebarFont);
	DrawFormatString(73, 30, GetColor(255, 255, 255), "%08d", Score, ScorebarFont);
	DrawFormatString(211, 30, GetColor(255, 255, 255), "%08d", Graze, ScorebarFont);
	DrawFormatString(447, 3, GetColor(255, 255, 255), "%-d", GetPlayerInfo(2), ScorebarFont);
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