#include "Somethings.h"
#define ShotMAX 256
#define PSIZE_X 50
#define PSIZE_Y 26

Chara Hina;
int speed=8;	//自機の移動速度
int ShotDelay=6;	//ショットの間隔(PlayerShotにもあるよ)
int Anm = 0;
Chara Shot[ShotMAX][5];

void PlayerDraw(void);
void PlayerMove(void);
void PlayerShot(void);
void PShotMove(void);
void PShotDraw(void);

//ゲームメイン時のいろいろ関数
void PlayerDo(void) {
	PShotMove();
	PShotDraw();
	PlayerMove();
	PlayerDraw();
}

//自機情報の初期化
void PlayerInit(void) {
	for (int i = 0; i < 4; i++) {
		Hina.img[i] = LoadGraph(((std::string)"res/img/hinas/hinas" + std::to_string(i) + ".bmp").c_str());
	}
	Hina.x = 5;
	Hina.y = 295;
	Hina.hp = 100;	//なんとなく100にした
	Hina.power = 85;
	Hina.live = true;
}
//ショットの初期化
void ShotInit(void) {
	for (int i = 0; i < ShotMAX; i++) {
		for (int n = 0; n < 5; n++) {
			Shot[i][n].live = false;
			Shot[i][n].img[0] = LoadGraph("res/img/nife.png");
		}
	}
}

//自機の描画
void PlayerDraw(void) {
	DrawGraph(Hina.x, Hina.y, Hina.img[Anm/2], TRUE);
	(Anm < 8) ? Anm++ : Anm = 0;
	DrawFormatString(0, 554, GetColor(255, 255, 255), "%-3d", ShotDelay);
	DrawFormatString(0, 577, GetColor(255, 255, 255), "%-3d,%-3d", Hina.x,Hina.y);
}
//ショットの描画
void PShotDraw(void) {
	for (int i = 0; i < ShotMAX; i++) {
		for (int n = 0; n < 5; n++) {
			if (Shot[i][n].live) {
				DrawGraph(Shot[i][n].x, Shot[i][n].y, Shot[i][n].img[0], TRUE);
			}
		}
	}
}

//自機の移動
void PlayerMove(void) {
	//移動
	if (Key[KEY_INPUT_UP] >= 1)Hina.y -= speed;
	if (Key[KEY_INPUT_DOWN] >= 1)Hina.y += speed;
	if (Key[KEY_INPUT_LEFT] >= 1)Hina.x -= speed;
	if (Key[KEY_INPUT_RIGHT] >= 1)Hina.x += speed;
	//移動範囲
	if (Hina.x < 0)Hina.x = 0;
	if (Hina.x > 800 - PSIZE_X)Hina.x = 800 - PSIZE_X;
	if (Hina.y < 50)Hina.y = 50;
	if (Hina.y > 600 - PSIZE_Y)Hina.y = 600 - PSIZE_Y;

	//低速
	if (Key[KEY_INPUT_LSHIFT] >= 1)speed = 4;
	else speed = 8;

	//ショット
	if(Key[KEY_INPUT_Z]>=1)PlayerShot();
}
//ショットの移動
void PShotMove(void) {
	//ショットの最大数繰り返す
	for (int i = 0; i < ShotMAX; i++) {
		/*//5wayぶん繰り返す
		for (int n = 0; n < 5; n++) {
			if (Shot[i][n].live) {
				Shot[i][n].x += 50;	//移動量
				if (Shot[i][n].x > 800) {
					Shot[i][n].live = false;
				}
			}
		}
		//5wayぶん繰り返す
		for (int n = 0; n < 3; n++) {
			if (Shot[i][n].live) {
				Shot[i][n].x += 50;	//移動量
				if (Shot[i][n].x > 800) {
					Shot[i][n].live = false;
				}
			}
		*/
		//5wayぶん繰り返す
		for (int n = 0; n < 5; n++) {
			if (Shot[i][n].live) {
				Shot[i][n].x += cos(n*10*PI/180.0)*50;	//移動量
				Shot[i][n].y += sin(n*10*PI / 180.0) * 50;
				if (Shot[i][n].x > 800) {
					Shot[i][n].live = false;
				}
			}
		}
	}
}

//ショットの生成
void PlayerShot(void) {
	ShotDelay -= 1;
	if (ShotDelay > 0)return;
	ShotDelay = 6;
	if (Hina.power >= 85) {	//MAX
		//5way弾
		for (int i = 0; i < ShotMAX; i++) {
			for (int n = 0; n < 5; n++) {
				if (Shot[i][n].live == false) {
					Shot[i][n].live = true;
					Shot[i][n].x = Hina.x;
					Shot[i][n].y = Hina.y + 5;
					return;
				}
			}
		}
	}
	else if (Hina.power >= 43) {	//HALF
		//3way弾
		for (int i = 0; i < ShotMAX; i++) {
			for (int n = 0; n < 3; n++) {
				if (Shot[i][n].live == false) {
					Shot[i][n].live = true;
					Shot[i][n].x = Hina.x;
					Shot[i][n].y = Hina.y + 5;
					return;
				}
			}
		}
	}
	else {	//MIN
		//1way弾
		for (int i = 0; i < ShotMAX; i++) {
			if (Shot[i][0].live == false) {
				Shot[i][0].live = true;
				Shot[i][0].x = Hina.x;
				Shot[i][0].y = Hina.y+5;
				return;
			}
		}
	}
}