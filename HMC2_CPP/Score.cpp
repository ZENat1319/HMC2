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
	//�摜�ǂݍ���
	ScorebarImg = LoadGraph("res/img/scorebar.bmp");
	BombIcon = LoadGraph("res/img/bomb_icon.bmp");
	//�t�H���g�n���h���̓o�^
	ScorebarFont = CreateFontToHandle("Source Han Serif", 14.5, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}

void ScoreDraw(void) {
	DrawGraph(0, 0, ScorebarImg, TRUE);
	DrawLine(0, 50, 800, 50, GetColor(255, 0, 0));

	char scorebar[256];

	//�n�C�X�R�A
	sprintf(scorebar, "%08d", HighScore);
	DrawStringToHandle(73,3,scorebar, GetColor(255, 255, 255),ScorebarFont);
	//�X�R�A
	sprintf(scorebar, "%08d", Score);
	DrawStringToHandle(73, 30, scorebar, GetColor(255, 255, 255), ScorebarFont);
	//�O���C�Y
	sprintf(scorebar, "%08d", Graze);
	DrawStringToHandle(211, 30, scorebar, GetColor(255, 255, 255), ScorebarFont);
	//�p���[
	sprintf(scorebar, "%-d", GetPlayerInfo(2));
	DrawStringToHandle(447, 3, scorebar, GetColor(255, 255, 255), ScorebarFont);
	//�{��
	if (Bombs < 5) {
		//�{�����S�ȉ�
		for (int i = 0; i < Bombs; i++) {
			DrawGraph((383+i*16)+5,30,BombIcon,TRUE);
		}
	}
	else {
		//�{����5�ȏ�
		DrawGraph(383, 30, BombIcon, TRUE);
		DrawFormatString(399,30,GetColor(255,255,255)," x %d",Bombs,ScorebarFont);
	}
}

void ScoreAdd(int index,int increment) {
	switch (index) {
	case 0:
		//�p���[
		Power += increment;
		break;
	case 1:
		//�{��
		Bombs += increment;
		break;
	case 2:
		//�c�@
		Lifes += increment;
		break;
	}
}

void ScoreSub(int index, int decrement) {
	switch (index) {
	case 0:
		//�p���[
		Power -= decrement;
		break;
	case 1:
		//�{��
		Bombs -= decrement;
		break;
	case 2:
		//�c�@
		Lifes -= decrement;
		break;
	}
}