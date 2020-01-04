#include "DxLib.h"
#include <string>

void initImage();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	const int windowSizeX = 1280;
	const int windowSizeY = 720;
	const int selectColorBit = 32;
	SetGraphMode(windowSizeX, windowSizeY, selectColorBit);
	SetWindowText("Kemushi Ga Huttekuru");
	const int error = -1;
	if (DxLib_Init() == error) {
		return error;
	}

	initImage();

	WaitKey();

	DxLib_End();

	return 0;
}

void initImage() {
	const int backGroundImageHandle = LoadGraph("./Image/Background.png");
	DrawGraph(0, 0, backGroundImageHandle, TRUE);
	const int groundImageHandle = LoadGraph("./Image/Ground.png");
	DrawGraph(0, 600, groundImageHandle, TRUE);
}