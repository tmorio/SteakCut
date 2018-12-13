#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "MenuArea.h"
#include "AreaCheck.h"
#include "Debug.h"
#include <stdio.h>

//�O���[�o���ϐ��̒�`
int counter = 0;
int steakX[4] = { 406, 648, 890 };
int steakY[4] = { 380, 380, 380 };
int MouseX, MouseY;
int Handle1;
int AudioCounter = 0;
bool AudioPlay = false;
static bool loadStatus = false;
static 	int image, imgBack, Handle;
static int imgmiddle[4];
static int SoundCounter = 0;
char Key[256];

extern int Scene;
extern int ASFont;

void AppStart() {
	if (loadStatus == false) {
		image = LoadGraph("./img/Knife_a.png");
		imgBack = LoadGraph("./img/Main.png");
		Handle = LoadSoundMem("./snd/Start.mp3");
		Handle1 = LoadSoundMem("./snd/Center.mp3");
		LoadDivGraph("./img/meet_main.png", 3, 3, 1, 268, 412, imgmiddle);

		loadStatus = true;
	}

	SetMouseDispFlag(TRUE);

	//���ʕύX
	ChangeVolumeSoundMem(255 * 30 / 100, Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, Handle1);


	while (!ProcessMessage() && !ClearDrawScreen() && !GetHitKeyStateAll(Key) && !Key[KEY_INPUT_ESCAPE]) {
		//�����b�Z�[�W���� ����ʂ��N���A ���L�[�{�[�h���͏�Ԏ擾 ��ESC��������Ă��Ȃ�

		if (Key[KEY_INPUT_LSHIFT] || Key[KEY_INPUT_RSHIFT]) { ResetArea(); }
		if (Key[KEY_INPUT_M]) { 
			StopSoundMem(Handle);
			StopSoundMem(Handle1);
			ResetArea();
			MenuOn();
		}

		GetMousePoint(&MouseX, &MouseY);

		//�e��摜�̓ǂݍ���
		DrawRotaGraph(650, 450, 1.0, 0.0, imgBack, TRUE);
		DrawRotaGraph(steakX[0], steakY[0], 0.9, 0.0, imgmiddle[0], TRUE);
		DrawRotaGraph(steakX[1], steakY[1], 0.9, 0.0, imgmiddle[1], TRUE);
		DrawRotaGraph(steakX[2], steakY[2], 0.9, 0.0, imgmiddle[2], TRUE);
		DrawRotaGraph(MouseX, MouseY, 0.6, 0.0, image, TRUE);

		DrawStringToHandle(1120, 0, "Shift�L�[�Ń��Z�b�g", GetColor(255, 255, 255), ASFont);
		DrawStringToHandle(940, 0, "M�L�[�Ń^�C�g���ɖ߂�", GetColor(255, 255, 255), ASFont);


		//�f�o�b�O�p
		OutXYData();
		FPSPrint();

		ScreenFlip();//����ʂ�\��ʂɔ��f

		//10�b�̉����̂���10�b��1��Đ�
		if (SoundCounter % 600 == 0) {
			PlaySoundMem(Handle, DX_PLAYTYPE_BACK, FALSE); // ���ʉ����Đ�����
		}
		AudioCheck();	//�}�E�X�����̌��ʉ��Đ���ԃ`�F�b�N
		AreaCheck(550, 505, 420, 310, 0, true);		//���̓��𓮂������`�F�b�N
		AreaCheck(805, 745, 420, 310, 2, false);	//�E�̓��𓮂������`�F�b�N
	}

	DxLib_End();
}