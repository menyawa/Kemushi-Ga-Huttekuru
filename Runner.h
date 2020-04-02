#ifndef Runner_Included
#define Runner_Included

class Runner {
private:
	int imageHandle_;
	const int width_ = 100;
	const int height_ = 100;
	int xPos_;
	int yPos_;
	int moveLandingVec_; //左右、どちらの方向に走るか
	bool turningBackTheWay_; //引き返している途中か
	int boostPower_;

	inline bool canBoost() {
		return boostPower_ > 0;
	}

	//スタート地点から反対側の端に到達したら
	inline bool checkReachOppositeEdge(int windowWidth) {
		return (xPos_ + width_) >= windowWidth;
	}

public:
	Runner(int groundPosY);
	void run(int windowWidth);

	inline int getWidth() {
		return width_;
	}

	inline int getHeight() {
		return height_;
	}
};

#endif