#include "Somethings.h"

void GameKey(void);

void GameInit(void) {
	PlayerInit();
	ShotInit();
	ScoreInit();
	ScoreAdd(2, 5);
}

void GameMain() {
	SetDrawBright(255, 255, 255);
	PlayerDo();

	ScoreDraw();

	GameKey();
}

void GameKey(void) {
	
}