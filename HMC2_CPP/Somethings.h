//色々するヘッダファイル
#ifndef HMC2_2_MAIN_HEADER
#define HMC2_2_MAIN_HEADER

#include <DxLib.h>
#include <stdio.h>
#include <string>
#include "Scenes.h"

#define PI 3.141592653589793

extern int GameScene;
//static bool GrobalSceneChange;
extern int Key[256];
extern int Score;
extern int HighScore;
extern int Graze;
extern int bright;
//static bool FadeIO = true;	//true:fade in, false:fade out
//static bool FadeEnd = false;

extern struct Chara
{
	int img[10];	//ハンドル
	int x,y;	//座標
	int hp;		//体力
	bool live;	//生存フラグ
	int power;	//パワー
	int other = 0;	//その他
};
extern struct Shots {
	int img;
	int x, y;
	double angle;	//角度
	bool live;
	int power;
	int other;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

int FontLoad(void);

int gpUpdateKey();
bool FadeIn(int, int, int);
bool FadeOut(int, int, int);

void DrawFps(void);

void LoadInit(void);
void LoadMain(int);

void InitTitle(void);
void TitleMain(void);

void InitOption(void);
void OptionMain(void);

void GameInit(void);
void GameMain(void);

void StageInit(int);
void StageMain(void);

void PlayerInit(void);
void ShotInit(void);
void PlayerDo(void);
int GetPlayerInfo(int);

void ScoreInit(void);
void ScoreDraw(void);
void ScoreAdd(int,int);
void ScoreSub(int, int);

#endif
