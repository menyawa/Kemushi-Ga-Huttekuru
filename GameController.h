#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "BackgroundController.h"
#include "Fps.h"
#include "Runner.h"
#include "Caterpillar.h"

class GameController {
private:
	const int windowWidth = 1280;
	const int windowHeight = 720;

public:
	GameController();
	void initWindow();

	int getWindowWidth() {
		return windowWidth;
	}
	int getWindowHeight() {
		return windowHeight;
	}
};

#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//����ȑO��DX���C�u�����֘A�̏��������s���Ɛ���Ɏ��s����Ȃ��̂Œ���
	const int error = -1;
	if (DxLib_Init() == error) {
		return error;
	}
	GameController gameController;
	BackgroundController backgroundController;
	BackgroundController::initImageHandle();
	Fps fps;
	Caterpillar::initStaticField();
	Runner runner(backgroundController.groundPosY_);

	int counter = 0;
	while (ProcessMessage() != error) {
		backgroundController.drawBackGround();
		runner.move();
		Caterpillar::moveCaterpillars();
		Caterpillar::randomSpawn(gameController.getWindowWidth());

		ScreenFlip();

		//60FPS�ɓ�������킹�Ă���
		fps.update();
		fps.wait();

		if (counter == 1000) {
			break;
		} else {
			counter++;
		}
	}

	WaitKey();

	DxLib_End();

	return 0;
}
