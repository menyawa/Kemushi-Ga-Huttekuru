#ifndef PlayerScore_Included
#define PlayerScore_Included

#include "DxLib.h"

class PlayerScore {
private:
	int score_;
	int fontHandle_;

public:
	PlayerScore();

	inline void plusScore() {
		score_++;
	}

	inline void resetScore() {
		score_ = 0;
	}

	void printScore();
};

#endif
