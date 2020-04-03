#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "Fps.h"
#include "Runner.h"
#include "Caterpillar.h"

class GameController {

};

#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//����ȑO��DX���C�u�����֘A�̏��������s���Ɛ���Ɏ��s����Ȃ��̂Œ���
	const int error = -1;
	if (DxLib_Init() == error) {
		return error;
	}
	WindowSizeController windowSizeController;
	BackgroundController backgroundController;
	Fps fps;
	Caterpillar::initStaticField();
	Runner runner(backgroundController.groundYPos_);

	int counter = 0;
	while (ProcessMessage() != error) {
		backgroundController.drawStageBackGround();
		runner.move(windowSizeController, backgroundController);
		Caterpillar::moveAllCaterpillars(backgroundController);
		Caterpillar::randomSpawn(backgroundController.highLightWidth_, windowSizeController.width_);
		runner.boostRunner_.displayGauge(1000, 100); //���̈ʒu�ŕ\�����Ȃ��ƁA�\�����̊֌W��ђ��ŉB��Ă��܂�
		backgroundController.highLightStartPos();

		ScreenFlip();

		//60FPS�ɓ�������킹�Ă���
		fps.update();
		fps.wait();

		int runnerRight = runner.getXPos() + runner.getWidth();
		int runnerButtom = runner.getYPos() + runner.getHeight();

		if (Caterpillar::caterpillarHittingRunnerIsExists(runner.getXPos(), runnerRight, runner.getYPos(), runnerButtom)) break;

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
