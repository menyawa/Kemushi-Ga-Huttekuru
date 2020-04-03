#include "BoostRunner.h"

BoostRunner::BoostRunner(int maxPower) : boostPower_(maxPower) {
	boostGaugeImageHandle_ = LoadGraph("./File/Image/BoostGauge_Gauge.png");
	boostGaugeBackgroundImageHandle_ = LoadGraph("./File/Image/BoostGauge_Background.png");
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
		if(canPlusPower()) plusPower();
	}

	return runningSpeed;
}

void BoostRunner::displayGauge() {
	int gaugeBackgroundWidth, gaugeBackgroundHeight;
	GetGraphSize(boostGaugeBackgroundImageHandle_, &gaugeBackgroundWidth, &gaugeBackgroundHeight);
	gaugeBackgroundWidth /= 20;
	gaugeBackgroundHeight /= 20;

	//描画順がゲージ背景→ゲージとなるよう注意
	const int gaugeBackgroundXPos = 1000;
	const int gaugeBackgroundYPos = 70;
	DrawExtendGraph(gaugeBackgroundXPos, gaugeBackgroundYPos, gaugeBackgroundXPos + gaugeBackgroundWidth, gaugeBackgroundYPos + gaugeBackgroundHeight, boostGaugeBackgroundImageHandle_, TRUE);
	//ゲージと枠の間にはマージンがあることに注意
	const int gaugeXPos = gaugeBackgroundXPos + 5;
	const int gaugeYPos = gaugeBackgroundYPos + 5;
	int gaugeWidth, gaugeHeight;
	GetGraphSize(boostGaugeImageHandle_, &gaugeWidth, &gaugeHeight);
	gaugeWidth /= 20;
	gaugeHeight /= 20;
	gaugeWidth = gaugeWidth * boostPower_ / 100.0;
	DrawExtendGraph(gaugeXPos, gaugeYPos, gaugeXPos + gaugeWidth, gaugeYPos + gaugeHeight, boostGaugeImageHandle_, TRUE);
}