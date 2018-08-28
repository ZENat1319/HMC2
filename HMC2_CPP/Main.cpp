#include "Somethings.h"

int GameScene = 0,LdNextScene=0;
int bright = 255;
int GrobalSceneChage = false;
int ProgramInit(void);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("Murder Girl's Fantasy");
	//起動時スクリーンサイズ質問
#ifdef _DEBUG
	//DEBUG時ウインドウモード
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(800, 600, 32);//画面サイズ指定
#else
	if (MessageBox(NULL, "フルスクリーンで起動しますか？\nはい(フルスクリーン)いいえ(ウインドウ)",
	"しつもん！", MB_YESNO) == IDYES) {
		ChangeWindowMode(FALSE);//全画面にセット
		SetGraphMode(800, 600, 32);//画面サイズ指定
	}
	else {
		ChangeWindowMode(TRUE);//非全画面にセット
		SetGraphMode(800, 600, 32);//画面サイズ指定
	}
#endif

	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーを吐かせて終了
	SetUseASyncLoadFlag(TRUE);
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定　※生成したほうが良くね？
	//フォント読み込み									 
	if (!FontLoad()) {
		DxLib_End();
		return 0;
	}
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

	//初期化でもしておこう
	LoadInit();
	ProgramInit();

	GameScene = SC_INIT;
	LdNextScene = SC_TITLE;

	//めいんるうぷ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && gpUpdateKey() == 0)
	{
		ClearDrawScreen();	//こいつだけは単体でしか動かない

		switch (GameScene) {
		case SC_INIT:
			//ロード画面
			LoadMain(LdNextScene);
			break;
		case SC_TITLE:
			//タイトル画面
			TitleMain();
			break;
		case SC_OPTION:
			//装備選択画面
			OptionMain();
			break;
		case SC_GAME:
			//ゲーム画面(予定)
			GameMain();
			break;
		case SC_ENDFUCK:
			//強制終了
			goto EndbyAdmin;
			break;
		}
		DrawFps();
	}
EndbyAdmin:
	DxLib_End();
	return 0;
}

int ProgramInit(void) {
	//初期化でもしておこう
	InitTitle();
	InitOption();
	GameInit();
	return 0;
}