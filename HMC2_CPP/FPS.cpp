#include "Somethings.h"
void DrawFps() {
	/*DrawFormatString(730, 584, GetColor(255, 255, 255),
		"FPS:%f", GetFPS);*/
	static int FpsTime[2] = { 0, }, FpsTime_i = 0;
	static double Fps = 0.0;
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//���肵���l����fps���v�Z
		FpsTime_i = 0;//�J�E���g��������
	}
	else
		FpsTime_i++;//���݉����ڂ��J�E���g
	if (Fps != 0)
		DrawFormatString(765, 568, GetColor(255, 255, 255)
			, "\n%.1f", Fps); //fps��\��
	return;
}
//Hello