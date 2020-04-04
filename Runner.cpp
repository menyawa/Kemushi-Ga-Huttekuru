#include "Dxlib.h"
#include "Runner.h"

Runner::Runner(int groundPosY) {
	startRunning(groundPosY);
}

//スタートする
//一回クリアした後のリスタート時も使い回せるようメソッド化
void Runner::startRunning(int groundPosY) {
	imageHandle_ = LoadGraph("./File/Image/Runner.png");
	xPos_ = width_ * -1 - margin_; //画面外からスタート
	yPos_ = groundPosY - height_ - margin_;
	
	runningVec_ = 1;
	canJump_ = true;
	jumpSpeed_ = 0;
	boostRunner_.resetPower();
}

void Runner::move(WindowSizeController& windowSizeController, BackgroundController& backgroundController) {
	run();
	jump(backgroundController, backgroundController.groundYPos_);
	
	//画面端にたどり着いたら
	if (windowSizeController.isReachedEdge(getRight())) {
		if (xPos_ > 0) {
			//スタート地点から反対側の端で引き返す
			imageHandle_ = LoadGraph("./File/Image/TurningBack_TheWay_Runner.png");
			//ブーストの関係で画面端からはみ出ている可能性もあるので、押し戻す
			//その際、多少跳ね返るような挙動をすることに注意(はみ出ている分更に戻るので、画面端ピッタリの位置にはならないことがある)
			int widthOfOutSideFromEdge = getRight() - windowSizeController.width_;
			xPos_ = windowSizeController.width_ - width_ - widthOfOutSideFromEdge;
		}
		runningVec_ *= -1;
	}

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

//走る(横方向の移動)
void Runner::run() {
	int speed = 1;
	speed = boostRunner_.boostSpeed(speed);
	xPos_ += speed * runningVec_;
}

//ジャンプする(縦方向の移動)
void Runner::jump(BackgroundController& backgroundController, int groundPosY) {
	bool isLandingGround = backgroundController.isLandingGround(getTop(), height_);
	int acc = 0; 
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (isLandingGround && canJump_) {
			canJump_ = false; 
			jumpSpeed_ = -25;
		} else {
			acc--; //空中で押している間は上に加速度をかけることで、押している長さで高さの調整ができるようにする
			//TODO:空中で離したあとまた押したら加速度がかかってしまうので直す
		}
	} else {
		if (isLandingGround) canJump_ = true; //ジャンプできるかどうかをとっておかないと、キーを押しながら着地した場合即ジャンプしてしまう
	}

	const int g = 2;
	jumpSpeed_ += acc + g;
	yPos_ += jumpSpeed_;

	isLandingGround = backgroundController.isLandingGround(getTop(), height_);
	//更新後の座標で着地しているか見ないと、更新前の段階で地面に設置していたらジャンプできなくなる
	if (isLandingGround) {
		yPos_ = groundPosY - height_ - margin_; //着地しているのなら、めり込まないよう位置を補正する
	}
}