#include "WindowSizeController.h"

WindowSizeController::WindowSizeController() {
	ChangeWindowMode(TRUE);
	const int selectColorBit = 32;
	SetGraphMode(width_, height_, selectColorBit);
	SetWindowText("���ނ����~��ӂ�t�`��");
	SetDrawScreen(DX_SCREEN_BACK);
}