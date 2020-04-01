#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	imageHandle_ = LoadGraph("./Image/Runner.png");

	xPos_ = 0;
	yPos_ = groundPosY - height_;
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	movingVec_ = 1;
}

void Runner::move() {
	int drawAreaWidth = xPos_ + width_;
	int drawAreaHeight = yPos_ + height_;

	if (checkReachEdge()) {

	}

	int movingLength = 1;

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		movingLength *= 3;
	}
		
	xPos_ += movingLength * movingVec_;

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

bool Runner::checkReachEdge() {
	return false;
}