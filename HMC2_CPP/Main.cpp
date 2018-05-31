#include "Somethings.h"

int GameScene = 0;
int bright = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("Murder Girl's Fantasy");

	//起動時質問
	/*if (MessageBox(NULL, "フルスクリーンで起動しますか？\nはい(フルスクリーン)いいえ(ウインドウ)",
		"しつもん！", MB_YESNO) == IDYES) {
		ChangeWindowMode(FALSE);//全画面にセット
		SetGraphMode(800, 600, 32);//画面サイズ指定
	}
	else {*/
		ChangeWindowMode(TRUE);//非全画面にセット
		SetGraphMode(800, 600, 32);//画面サイズ指定
	//}

	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーを吐かせて終了

	//フォント読み込み
	if (!FontLoad()) {
		DxLib_End();
		return 0;
	}

	//初期化でもしておこう
	InitTitle();
	InitOption();
	GameInit();


	while (ProcessMessage() == 0 && gpUpdateKey()==0)
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		switch (GameScene) {
		case 0:
			//タイトル画面
			TitleMain();
			break;
		case 5:
			//装備選択画面
			OptionMain();
			break;
		case 10:
			//ゲーム画面(予定)
			GameMain();
			break;
		case 99:
			//強制終了
			goto EndbyAdmin;
			break;
		}
		

		ScreenFlip();//裏画面を表画面にコピー
	}
	EndbyAdmin:
	DxLib_End();
	return 0;
}