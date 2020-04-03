#ifndef BoostRunner_Included
#define BoostRunner_Included

#include "DxLib.h"

class BoostRunner {
private:
	int boostPower_;
	int boostGaugeImageHandle_;
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

	inline bool canPlusPower() {
		return boostPower_ < 100;
	}

public:
	BoostRunner(int maxPower);

	int boostSpeed(int nomalSpeed);
	void displayGauge();
};

#endif
