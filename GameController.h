#ifndef GameController_Included
#define GaemController_Included

#include "DxLib.h"
#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "Title.h"
#include "Fps.h"
#include "PlayerScore.h"
#include "Runner.h"
#include "Caterpillar.h"
#include "GameEnd.h"

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
	Title title;
	Fps fps;
	PlayerScore playerScore;
	Caterpillar::initStaticField();
	Runner runner(backgroundController.groundYPos_);

	int counter = 0;
	while (ProcessMessage() != error) {
		//�^�C�g����ʂ��܂����Ă��Ȃ�(�Q�[���J�n��)�E�^�C�g���ɖ߂����ہA�^�C�g����\��
		if (title.canSeenTitle()) {
			title.drawTitle();
		}

		//��������Q�[�����
		backgroundController.drawStageBackGround();
		runner.move(windowSizeController, backgroundController);
		Caterpillar::moveAllCaterpillars(backgroundController);
		Caterpillar::randomSpawn(windowSizeController.width_);

		//���̈ʒu�ŕ\�����Ȃ��ƁA�\�����̊֌W��ђ��ŉB��Ă��܂�
		playerScore.plusScore();
		playerScore.printScore();
		runner.boostRunner_.displayGauge(); 

		ScreenFlip();

		//60FPS�ɓ�������킹�Ă���
		fps.update();
		fps.wait();

		//�Q�[���N���A������(�X�^�[�g�n�_��ʊO�܂œ����؂�����)����
		if (windowSizeController.isReachedWindowEdge(runner.getRight())) {
			if (runner.getLeft() <= 0) {
				GameEnd gameEnd;
				if (gameEnd.selectPlayingNextStage()) {
					Caterpillar::resetCaterpillarsList();	
					runner.startRunning(backgroundController.groundYPos_);
				} else {
					title.switchHasSeenTitleFlag();
				}
				continue;
			}
		}

		//�Q�[���N���A�����ɍs��Ȃ��ƁA�����؂肪�s���Ȃ��̂Œ���
		//��ʂ��X�V�������Ƃɔ�����s��Ȃ��Ɓu�������ĂȂ��̂ɓ������Ă���v�Ƃ������ƂɂȂ�̂Œ���
		if (Caterpillar::caterpillarHittingRunnerIsExists(runner.getLeft(), runner.getRight(), runner.getTop(), runner.getButtom())) break;

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
