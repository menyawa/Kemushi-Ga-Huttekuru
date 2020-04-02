#ifndef BoostRunner_Included
#define BoostRunner_Included

#include "DxLib.h"

class BoostRunner {
private:
	int boostPower_;

	int boostGaugeImageHandle_;
	int boostGaugeFrameImageHandle_;
	int boostGaugeBackgroundImageHandle_;

	inline void plusPower() {
		boostPower_++;
	}

	inline void minusPower() {
		boostPower_--;
	}

	inline bool canBoost() {
		return boostPower_ > 0;
	}

public:
	BoostRunner(int maxPower);

	int boostSpeed(int nomalSpeed);
	void displayGauge(int xPos, int yPos);
};

#endif
