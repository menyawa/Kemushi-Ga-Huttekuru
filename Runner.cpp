#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");

	xPos_ = 0;
	yPos_ = groundPosY - height_;
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	moveLandingVec_ = 1;
	turningBackTheWay_ = false;
	boostPower_ = 100;
}

void Runner::run(int windowWidth) {
	int movingLength = 1;
	if (CheckHitKey(KEY_INPUT_SPACE) && canBoost()) {
		movingLength *= 3;
		boostPower_--;
	} else if(CheckHitKey(KEY_INPUT_SPACE) == false){ //キーを離している時に貯まるようにしないと、即座にブースト→通常→ブースト→通常→…と繰り返してしまう
		boostPower_++;
	}
		
	xPos_ += movingLength * moveLandingVec_;
	
	if (checkReachOppositeEdge(windowWidth)) {
		turningBackTheWay_ = true;
		imageHandle_ = LoadGraph("./Image/TurningBack_TheWay_Runner.png");
		//ブーストの関係で画面端からはみ出ている可能性もあるので、押し戻す
		//その際、多少跳ね返るような挙動をすることに注意(はみ出ている分更に戻るので、画面端ピッタリの位置にはならないことがある)
		int widthOfOutSideFromEdge = width_ - (windowWidth - xPos_);
		xPos_ = windowWidth - width_ - widthOfOutSideFromEdge; 
		moveLandingVec_ *= -1;
	}

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}