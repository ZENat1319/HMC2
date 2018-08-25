#include "Somethings.h"
void DrawFps() {
	/*DrawFormatString(730, 584, GetColor(255, 255, 255),
		"FPS:%f", GetFPS);*/
	static int FpsTime[2] = { 0, }, FpsTime_i = 0;
	static double Fps = 0.0;
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(765, 568, GetColor(255, 255, 255)
			, "\n%.1f", Fps); //fpsを表示
	return;
}
//Hello