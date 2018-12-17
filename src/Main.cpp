#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "DxLib.h"
#include "MenuArea.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetGraphMode(1280, 800, 32);
	SetWindowSize(1280, 800);
	SetMainWindowText("SteakCut - Ver 1.6");
	SetWindowIconID(101);

	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK || DxLib_Init() == -1) return -1;

	LoadGraphScreen(240, 220, "./img/Devlogo.png", TRUE);
	DrawString(450, 480, "�N���� :", GetColor(255, 255, 255));
	DrawBoxAA(550, 480, 720, 495, GetColor(255, 255, 255), FALSE);

	LoadMem();
	MenuOn();

	return 0;
}