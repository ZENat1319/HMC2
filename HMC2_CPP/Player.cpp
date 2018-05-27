#include "Somethings.h"
#define ShotMAX 256
#define PSIZE_X 50
#define PSIZE_Y 26

Chara Hina;
int speed=8;	//自機の移動速度
int ShotDelay=6;	//ショットの間隔(PlayerShotにもあるよ)
int ShotSum = 0;
int Anm = 0;
Shots Shot[ShotMAX];

void PlayerDraw(void);
void PlayerMove(void);
void PlayerShot(void);
void PShotMove(void);
void PShotDraw(void);

//ゲームメイン時のいろいろ関数
void PlayerDo(void) {
	PShotMove();	//自機弾の移動
	PShotDraw();	//自機弾の描画
	PlayerMove();	//自機の移動
	PlayerDraw();	//自機の描画
}

//自機情報の初期化
void PlayerInit(void) {
	//画像読み込み
	for (int i = 0; i < 4; i++) {
		Hina.img[i] = LoadGraph(((std::string)"res/img/hinas/hinas" + std::to_string(i) + ".bmp").c_str());
	}
	//初期座標
	Hina.x = 5;
	Hina.y = 295;
	//体力
	Hina.hp = 100;	//なんとなく100にした
	//パワー
	Hina.power = 90;
	Hina.live = true;
}
//ショットの初期化
void ShotInit(void) {
	//画像読み込み
	for (int i = 0; i < ShotMAX; i++) {
		Shot[i].x = 0, Shot[i].y = 0;
		Shot[i].live = false;
		Shot[i].img = LoadGraph("res/img/nife.png");
	}
}

//自機の描画
void PlayerDraw(void) {
	DrawGraph(Hina.x, Hina.y, Hina.img[Anm], TRUE);
	(Anm < 3) ? Anm++ : Anm = 0;	//アニメ切り替え
	//デバッグ用文字列
	DrawFormatString(0, 554, GetColor(255, 255, 255), "%-3d", ShotSum);
	DrawFormatString(0, 577, GetColor(255, 255, 255), "%-3d,%-3d", Hina.x,Hina.y);
}
//ショットの描画
void PShotDraw(void) {
	//最大数繰り返す
	for (int i = 0; i < ShotMAX; i++) {
		if (Shot[i].live) {
			DrawRotaGraph(Shot[i].x, Shot[i].y, 1.0, Shot[i].angle, Shot[i].img, TRUE);
		}
	}
}

//自機の移動
void PlayerMove(void) {
	//ゲームパッドのいろいろ
	int Pad;
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//移動
	if (Pad&PAD_INPUT_UP)Hina.y -= speed;
	if (Pad&PAD_INPUT_DOWN)Hina.y += speed;
	if (Pad&PAD_INPUT_LEFT)Hina.x -= speed;
	if (Pad&PAD_INPUT_RIGHT)Hina.x += speed;
	//移動範囲
	if (Hina.x < 0)Hina.x = 0;
	if (Hina.x > 800 - PSIZE_X)Hina.x = 800 - PSIZE_X;
	if (Hina.y < 50)Hina.y = 50;
	if (Hina.y > 600 - PSIZE_Y)Hina.y = 600 - PSIZE_Y;

	//低速
	if (Key[KEY_INPUT_LSHIFT] >= 1)speed = 4;
	else speed = 8;

	//ショット
	if (Pad&PAD_INPUT_A)PlayerShot();
	if (!(Pad&PAD_INPUT_A))ShotDelay = 0;
}
//ショットの移動
void PShotMove(void) {
	//ショットの最大数繰り返す
	for (int i = 0; i < ShotMAX; i++) {
		if (Shot[i].live) {
			Shot[i].x += cos(Shot[i].angle) * 50;	//移動量
			Shot[i].y += sin(Shot[i].angle) * 50;
			if (Shot[i].x > 800||Shot[i].y<50 || Shot[i].y>600) {
				//消す
				Shot[i].live = false;
				ShotSum--;
			}
		}
	}
}

//ショットの生成
void PlayerShot(void) {
	//ショットディレイ
	ShotDelay -= 1;
	if (ShotDelay > 0)return;
	ShotDelay = 6;

	int n = 0;
	if (Hina.power >= 85) {	//MAX
		//5way弾
		for (int i = 0; i < ShotMAX; i++) {
			if (!Shot[i].live) {
				ShotSum++;
				Shot[i].live = true;
				Shot[i].x = Hina.x;
				Shot[i].y = Hina.y + 15;
				Shot[i].angle = (n - 2) * 5 * PI / 180.0;
				n++;
			}
			if (n >= 5)break;
		}
	}
	else if (Hina.power >= 43) {	//HALF
		//3way弾
		for (int i = 0; i < ShotMAX; i++) {
			if (!Shot[i].live) {
				ShotSum++;
				Shot[i].live = true;
				Shot[i].x = Hina.x;
				Shot[i].y = Hina.y + 15;
				Shot[i].angle = (n - 1) * 5 * PI / 180.0;
				n++;
			}
			if (n >= 3)break;
		}
	}
	else {	//MIN
		//1way弾
		for (int i = 0; i < ShotMAX; i++) {
			if (!Shot[i].live) {
				ShotSum++;
				Shot[i].live = true;
				Shot[i].x = Hina.x;
				Shot[i].y = Hina.y + 15;
				Shot[i].angle = n * 5 * PI / 180.0;
				n++;
			}
			if (n >= 1)break;
		}
	}
}

//自機情報を他のソースで使うための関数
int GetPlayerInfo(int index) {
	int result;
	switch (index) {
	case 0:
		//X座標
		result = Hina.x;
		break;
	case 1:
		//Y座標
		result = Hina.y;
		break;
	case 2:
		//Power
		result = Hina.power;
		break;
	case 3:
		//HP
		result = Hina.hp;
		break;
	}
	return result;
}