#include "Title.h"

Title::Title() : isSeen_(false){

}

void Title::drawTitle() {
	AudioController audioController;
	int titleImageHandle = LoadGraph("./File/Image/Title.png");
	DrawGraph(0, 0, titleImageHandle, TRUE);
	audioController.playBGM();
	ScreenFlip();
	WaitKey();
	switchHasSeenTitleFlag();
	audioController.playBGM(); //ゲーム画面に移行するため、BGMをもう一度リプレイする
}