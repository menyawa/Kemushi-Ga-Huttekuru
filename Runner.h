#ifndef Runner_Included
#define Runner_Included

class Runner {
private:
	int imageHandle_;
	const int width_ = 100;
	const int height_ = 100;
	int xPos_;
	int yPos_;
	int movingVec_; //左右、どちらの方向に走るか
	int boostPower_;

	bool checkReachEdge();

	inline bool canBoost() {
		return boostPower_ > 0;
	}

public:
	Runner(int groundPosY);
	void run();

	inline int getWidth() {
		return width_;
	}

	inline int getHeight() {
		return height_;
	}
};

#endif