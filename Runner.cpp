#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) : xPos_(0), yPos_(groundPosY - height_), moveLandingVec_(1), canJump_(true), jumpSpeed_(0), turningBackTheWay_(false), boostRunner_(100) {
	imageHandle_ = LoadGraph("./Image/Runner.png");
	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Runner::move(int windowWidth, BackgroundController& backgroundController) {
	run();
	jump(backgroundController.isLandingGround(yPos_, height_), backgroundController.groundYPos_);
	
	//画面端で引き返す
	if (isReachedOppositeEdge(windowWidth)) {
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

//走る(横方向の移動)
void Runner::run() {
	int speed = 1;
	speed = boostRunner_.boostSpeed(speed);
	xPos_ += speed * moveLandingVec_;
}

//ジャンプする(縦方向の移動)
void Runner::jump(bool isLandingGround, int groundPosY) {
	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	//	if (isLandingGround && canJump_) {
	//		canJump_ = false; //ジャンプできるかどうかをとっておかないと、キーを押しながら着地した場合即ジャンプしてしまう
	//		jumpSpeed_ = 20;
	//	}
	//} else {
	//	if (isLandingGround) canJump_ = true;
	//}

	//if (isLandingGround) yPos_ = groundPosY - height_; //着地しているのなら、めり込まないよう位置を補正する
}