#include "WindowSizeController.h"

WindowSizeController::WindowSizeController() {
	ChangeWindowMode(TRUE);
	const int selectColorBit = 32;
	SetGraphMode(width_, height_, selectColorBit);
	SetWindowText("ÇØÇﬁÇµÇ™ç~ÇÈÇ”ÇÈÉtÅ`Éã");
	SetDrawScreen(DX_SCREEN_BACK);
}