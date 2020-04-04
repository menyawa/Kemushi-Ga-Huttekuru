#ifndef Runner_Included
#define Runner_Included

#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "BoostRunner.h"

class Runner {
private:
	int imageHandle_;
	int xPos_;
	int yPos_;
	const int margin_ = 10;
	int runningVec_; //左右、どちらの方向に走るか
	bool canJump_;
	int jumpSpeed_;

	void run();
	void jump(bool isLandingGround, int groundPosY);

public:
	//画像サイズそのままだと、余白の分当たり判定が広がってしまうので注意
	const int width_ = 90;
	const int height_ = 90;
	BoostRunner boostRunner_;

	Runner(int groundPosY);
	void startRunning(int groundPosY);
	void move(WindowSizeController& windowSizeController, BackgroundController& backgroundController);

	//当たり判定と座標が余白がある関係で違うので、左右・上下の当たり判定開始位置を取得するメソッドを用意
	inline int getLeft() {
		return xPos_ + margin_;
	}

	inline int getRight() {
		return getLeft() + width_;
	}

	inline int getTop() {
		return yPos_ + margin_;
	}

	inline int getButtom() {
		return getTop() + height_;
	}
};

#endif