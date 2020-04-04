#include "GameEnd.h"

GameEnd::GameEnd() {
	clearMenuImageHandle_ = LoadGraph("./File/Image/ClearMenu.png");
	bonusScoreImageHandle_ = LoadGraph("./File/Image/ClearMenu_BonusScore.png");
	gameOverImageHandle_ = LoadGraph("./File/Image/GameOverMenu.png");
}

void GameEnd::drawClearMenu() {
	DrawGraph(0, 0, clearMenuImageHandle_, TRUE);
	ScreenFlip();
}

void GameEnd::drawGameOverMenu() {
	DrawGraph(0, 0, gameOverImageHandle_, TRUE);
	ScreenFlip();
}

//�����邩�ǂ�����Ԃ�
bool GameEnd::selectPlayingNextStage() {
	//�����邩�I���A�ǂ��炩��I������܂ő҂�
	while (CheckHitKey(KEY_INPUT_R) == false && CheckHitKey(KEY_INPUT_E) == false) WaitKey();

	return CheckHitKey(KEY_INPUT_R);
}

void GameEnd::retryGame(int groundPosY, Runner& runner) {
	Caterpillar::resetCaterpillarsList();
	runner.startRunning(groundPosY);
}
