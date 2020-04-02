#include "BoostRunner.h"

BoostRunner::BoostRunner(int maxPower) : boostPower_(maxPower) {
	boostGaugeImageHandle_ = LoadGraph("./Image/BoostGauge_Gauge.png");
	boostGaugeBackgroundImageHandle_ = LoadGraph("./Image/BoostGauge_Background.png");
	boostGaugeFrameImageHandle_ = LoadGraph("./Image/BoostGauge_Frame.png");
}

//�L�[���������ꍇ�p���[������ăX�s�[�h���グ��
int BoostRunner::boostSpeed(int nomalSpeed) {
	int runningSpeed = nomalSpeed;
	if (CheckHitKey(KEY_INPUT_D)) {
		if (canBoost()) {
			runningSpeed *= 3;
			minusPower();
		}
	} else { //�L�[�𗣂��Ă��鎞�ɒ��܂�悤�ɂ��Ȃ��ƁA�����Ƀu�[�X�g���ʏ큨�u�[�X�g���ʏ큨�c�ƌJ��Ԃ��Ă��܂�
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