#include "WindowSizeController.h"

WindowSizeController::WindowSizeController() {
	ChangeWindowMode(TRUE);
	const int selectColorBit = 32;
	SetGraphMode(width_, height_, selectColorBit);
	SetWindowText("けむしが降るふるフ〜ル");
	SetDrawScreen(DX_SCREEN_BACK);
}