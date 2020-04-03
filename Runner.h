#ifndef Runner_Included
#define Runner_Included

#include "WindowSizeController.h"
#include "BackgroundController.h"
#include "BoostRunner.h"

class Runner {
private:
	int imageHandle_;
	const int width_ = 100;
	const int height_ = 100;
	int xPos_;
	int yPos_;
	int moveLandingVec_; //¶‰EA‚Ç‚¿‚ç‚Ì•ûŒü‚É‘–‚é‚©
	bool canJump_;
	int jumpSpeed_;

	void run();
	void jump(bool isLandingGround, int groundPosY);

public:
	BoostRunner boostRunner_;

	Runner(int groundPosY);
	void move(WindowSizeController& windowSizeController, BackgroundController& backgroundController);

	inline int getXPos() {
		return xPos_;
	}

	inline int getYPos() {
		return yPos_;
	}

	inline int getWidth() {
		return width_;
	}

	inline int getHeight() {
		return height_;
	}
};

#endif