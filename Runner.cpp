#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");

	xPos_ = 0;
	yPos_ = groundPosY - height_;
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	movingVec_ = 1;
	boostPower_ = 100;
}

void Runner::run() {
	int drawAreaWidth = xPos_ + width_;
	int drawAreaHeight = yPos_ + height_;

	if (checkReachEdge()) {

	}

	int movingLength = 1;
	if (CheckHitKey(KEY_INPUT_SPACE) && canBoost()) {
		movingLength *= 3;
		boostPower_--;
	} else if(CheckHitKey(KEY_INPUT_SPACE) == false){ //キーを離している時に貯まるようにしないと、即座にブースト→通常→ブースト→通常→…と繰り返してしまう
		boostPower_++;
	}
		
	xPos_ += movingLength * movingVec_;

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

bool Runner::checkReachEdge() {
	return false;
}