#include "Somethings.h"

int BootFont;

void InitOp(void) {
	BootFont= CreateFontToHandle("Source Han Serif", 24, 3, DX_FONTTYPE_NORMAL);
}

void OpMain(void) {
	static int clock = 0;
	DrawStringToHandle(0, 0, "AngelHead PC-Q800 Series Personal Computer", GetColor(255, 255, 255), BootFont);
	if (clock > 120) {
		DrawStringToHandle(0, 16, 
			"��ݼ Hina's Memory Collection �ް�ޮ� 2.00\nCopyright 2018 Bloody Angel's Head / dorin"
			, GetColor(255, 255, 255), BootFont);
	}
	clock++;
}

/*
AngelHead PC-Q800 Series Personal Computer

��ݼ Hina's Memory Collection �ް�ޮ� 2.00
Copyright 2018 Bloody Angel's Head / dorin

�������`�F�b�N...[����OK]
���\�[�X�t�@�C���`�F�b�N...[OK]

Opening �ް�ޮ� 2.nn
A:\>game
A:\>CHKAUDIO
�T�E���h�f�o�C�X (device name) ���g�p�\�ł�
INT 5�ő����풓���܂���

A:\>DORCOM /1 /M:WF(�E�C���h�E���t���X�N���[��)
�풓���܂�(����)�B
�Q�[���I���܂ł�낵�����˂������܂��B

A:\>OP /1

*/