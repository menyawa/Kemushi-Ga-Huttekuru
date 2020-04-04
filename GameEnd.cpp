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

//‘±‚¯‚é‚©‚Ç‚¤‚©‚ğ•Ô‚·
bool GameEnd::selectPlayingNextStage() {
	//‘±‚¯‚é‚©I‚í‚éA‚Ç‚¿‚ç‚©‚ğ‘I‘ğ‚·‚é‚Ü‚Å‘Ò‚Â
	while (CheckHitKey(KEY_INPUT_R) == false && CheckHitKey(KEY_INPUT_E) == false) WaitKey();

	return CheckHitKey(KEY_INPUT_R);
}

void GameEnd::retryGame(int groundPosY, Runner& runner) {
	Caterpillar::resetCaterpillarsList();
	runner.startRunning(groundPosY);
}
