#include "BoostRunner.h"

BoostRunner::BoostRunner(int maxPower) : boostPower_(maxPower) {
	boostGaugeImageHandle_ = LoadGraph("./Image/BoostGauge_Gauge.png");
	boostGaugeBackgroundImageHandle_ = LoadGraph("./Image/BoostGauge_Background.png");
	boostGaugeFrameImageHandle_ = LoadGraph("./Image/BoostGauge_Frame.png");
}

//キーを押した場合パワーを消費してスピードを上げる
int BoostRunner::boostSpeed(int nomalSpeed) {
	int runningSpeed = nomalSpeed;
	if (CheckHitKey(KEY_INPUT_D)) {
		if (canBoost()) {
			runningSpeed *= 3;
			minusPower();
		}
	} else { //キーを離している時に貯まるようにしないと、即座にブースト→通常→ブースト→通常→…と繰り返してしまう
		plusPower();
	}

	return runningSpeed;
}

void BoostRunner::displayGauge(int xPos, int yPos) {
	DrawGraph(xPos, yPos, boostGaugeFrameImageHandle_, TRUE);
	DrawGraph(xPos, yPos, boostGaugeBackgroundImageHandle_, TRUE);

	const int maxGaugeWidth = 4100;
	const int maxGaugeHeight = 1200;
	const int gaugeWidth = maxGaugeWidth * boostPower_ / 100;
	DrawExtendGraph(xPos, yPos, xPos + gaugeWidth, yPos + maxGaugeHeight, boostGaugeImageHandle_, TRUE);
}