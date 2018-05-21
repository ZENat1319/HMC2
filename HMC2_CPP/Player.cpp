#include "Somethings.h"
#define ShotMAX 256
#define PSIZE_X 50
#define PSIZE_Y 26

Chara Hina;
int speed=8;	//���@�̈ړ����x
int ShotDelay=6;	//�V���b�g�̊Ԋu(PlayerShot�ɂ������)
int Anm = 0;
Shots Shot[ShotMAX];

void PlayerDraw(void);
void PlayerMove(void);
void PlayerShot(void);
void PShotMove(void);
void PShotDraw(void);

//�Q�[�����C�����̂��낢��֐�
void PlayerDo(void) {
	PShotMove();
	PShotDraw();
	PlayerMove();
	PlayerDraw();
}

//���@���̏�����
void PlayerInit(void) {
	for (int i = 0; i < 4; i++) {
		Hina.img[i] = LoadGraph(((std::string)"res/img/hinas/hinas" + std::to_string(i) + ".bmp").c_str());
	}
	Hina.x = 5;
	Hina.y = 295;
	Hina.hp = 100;	//�Ȃ�ƂȂ�100�ɂ���
	Hina.power = 128;
	Hina.live = true;
}
//�V���b�g�̏�����
void ShotInit(void) {
	for (int i = 0; i < ShotMAX; i++) {
		Shot[i].x = 0, Shot[i].y = 0;
		Shot[i].live = false;
		Shot[i].img = LoadGraph("res/img/nife.png");
	}
}

//���@�̕`��
void PlayerDraw(void) {
	DrawGraph(Hina.x, Hina.y, Hina.img[Anm], TRUE);
	(Anm < 3) ? Anm++ : Anm = 0;
	DrawFormatString(0, 554, GetColor(255, 255, 255), "%-3d", ShotDelay);
	DrawFormatString(0, 577, GetColor(255, 255, 255), "%-3d,%-3d", Hina.x,Hina.y);
}
//�V���b�g�̕`��
void PShotDraw(void) {
	for (int i = 0; i < ShotMAX; i++) {
		if (Shot[i].live) {
			DrawRotaGraph(Shot[i].x, Shot[i].y, 1.0, Shot[i].angle, Shot[i].img, TRUE);
		}
	}
}

//���@�̈ړ�
void PlayerMove(void) {
	//�Q�[���p�b�h�̂��낢��
	int Pad;
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�ړ�
	/*if (Key[KEY_INPUT_UP] >= 1)Hina.y -= speed;
	if (Key[KEY_INPUT_DOWN] >= 1)Hina.y += speed;
	if (Key[KEY_INPUT_LEFT] >= 1)Hina.x -= speed;
	if (Key[KEY_INPUT_RIGHT] >= 1)Hina.x += speed;*/
	if (Pad&PAD_INPUT_UP)Hina.y -= speed;
	if (Pad&PAD_INPUT_DOWN)Hina.y += speed;
	if (Pad&PAD_INPUT_LEFT)Hina.x -= speed;
	if (Pad&PAD_INPUT_RIGHT)Hina.x += speed;
	//�ړ��͈�
	if (Hina.x < 0)Hina.x = 0;
	if (Hina.x > 800 - PSIZE_X)Hina.x = 800 - PSIZE_X;
	if (Hina.y < 50)Hina.y = 50;
	if (Hina.y > 600 - PSIZE_Y)Hina.y = 600 - PSIZE_Y;

	//�ᑬ
	if (Key[KEY_INPUT_LSHIFT] >= 1)speed = 4;
	else speed = 8;

	//�V���b�g
	//if(Key[KEY_INPUT_Z]>=1)PlayerShot();
	if (Pad&PAD_INPUT_A)PlayerShot();
}
//�V���b�g�̈ړ�
void PShotMove(void) {
	//�V���b�g�̍ő吔�J��Ԃ�
	for (int i = 0; i < ShotMAX; i++) {
		/*//5way�Ԃ�J��Ԃ�
		for (int n = 0; n < 5; n++) {
			if (Shot[i][n].live) {
				Shot[i][n].x += 50;	//�ړ���
				if (Shot[i][n].x > 800) {
					Shot[i][n].live = false;
				}
			}
		}
		//3way�Ԃ�J��Ԃ�
		for (int n = 0; n < 3; n++) {
			if (Shot[i][n].live) {
				Shot[i][n].x += 50;	//�ړ���
				if (Shot[i][n].x > 800) {
					Shot[i][n].live = false;
				}
			}
		*/
		if (Shot[i].live) {
			Shot[i].x += cos(Shot[i].angle) * 50;	//�ړ���
			Shot[i].y += sin(Shot[i].angle) * 50;
			if (Shot[i].x > 800) {
				Shot[i].live = false;
			}
		}
	}
}

//�V���b�g�̐���
void PlayerShot(void) {
	ShotDelay -= 1;
	if (ShotDelay > 0)return;
	ShotDelay = 6;
	int n = 0;
	if (Hina.power >= 85) {	//MAX
		//5way�e
		for (int i = 0; i < ShotMAX; i++) {
			if (!Shot[i].live) {
				Shot[i].live = true;
				Shot[i].x = Hina.x;
				Shot[i].y = Hina.y + 5;
				Shot[i].angle = (i - 1) * 10 * PI / 180.0;
				(n < 4) ? n++ : n = 0;
			}
		}
	}
	else if (Hina.power >= 43) {	//HALF
		//3way�e
		for (int i = 0; i < ShotMAX; i++) {
			for (int n = 0; n < 3; n++) {
				if (Shot[i].live == false) {
					Shot[i].live = true;
					Shot[i].x = Hina.x;
					Shot[i].y = Hina.y + 5;
				}
			}
		}
	}
	else {	//MIN
		//1way�e
		for (int i = 0; i < ShotMAX; i++) {
			if (Shot[i].live == false) {
				Shot[i].live = true;
				Shot[i].x = Hina.x;
				Shot[i].y = Hina.y+5;
			}
		}
	}
}

//���@���𑼂̃\�[�X�Ŏg�����߂̊֐�
int GetPlayerInfo(int index) {
	int result;
	switch (index) {
	case 0:
		//X���W
		result = Hina.x;
		break;
	case 1:
		//Y���W
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