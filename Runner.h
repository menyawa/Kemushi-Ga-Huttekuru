#ifndef Runner_Included
#define Runner_Included

#include "BackgroundController.h"
#include "BoostRunner.h"

class Runner {
private:
	int imageHandle_;
	const int width_ = 100;
	const int height_ = 100;
	int xPos_;
	int yPos_;
	int moveLandingVec_; //���E�A�ǂ���̕����ɑ��邩
	BoostRunner boostRunner_;
	bool canJump_;
	int jumpSpeed_;
	bool turningBackTheWay_; //�����Ԃ��Ă���r����

	void run();
	void jump(bool isLandingGround, int groundPosY);

	//�X�^�[�g�n�_���甽�Α��̒[�ɓ��B���Ă��邩
	inline bool isReachedOppositeEdge(int windowWidth) {
		return (xPos_ + width_) >= windowWidth;
	}

public:
	Runner(int groundPosY);
	void move(int windowWidth, BackgroundController& backgroundController);

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