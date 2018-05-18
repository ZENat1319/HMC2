#include "Somethings.h"

void GameKey(void);

void GameInit(void) {
	PlayerInit();
	ShotInit();
	ScoreInit();
	ScoreAdd(2, 5);
}

void GameMain() {
	PlayerDo();

	ScoreDraw();

	GameKey();
}

void GameKey(void) {
	
}