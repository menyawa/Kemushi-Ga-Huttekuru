#include "BoostRunner.h"

BoostRunner::BoostRunner(int maxPower) : boostPower_(maxPower) {
	boostGaugeImageHandle_ = LoadGraph("./File/Image/BoostGauge_Gauge.png");
	boostGaugeBackgroundImageHandle_ = LoadGraph("./File/Image/BoostGauge_Background.png");
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
		if(canPlusPower()) plusPower();
	}

	return runningSpeed;
}

void BoostRunner::displayGauge() {
	int gaugeBackgroundWidth, gaugeBackgroundHeight;
	GetGraphSize(boostGaugeBackgroundImageHandle_, &gaugeBackgroundWidth, &gaugeBackgroundHeight);
	gaugeBackgroundWidth /= 20;
	gaugeBackgroundHeight /= 20;

	//�`�揇���Q�[�W�w�i���Q�[�W�ƂȂ�悤����
	const int gaugeBackgroundXPos = 1000;
	const int gaugeBackgroundYPos = 70;
	DrawExtendGraph(gaugeBackgroundXPos, gaugeBackgroundYPos, gaugeBackgroundXPos + gaugeBackgroundWidth, gaugeBackgroundYPos + gaugeBackgroundHeight, boostGaugeBackgroundImageHandle_, TRUE);
	//�Q�[�W�Ƙg�̊Ԃɂ̓}�[�W�������邱�Ƃɒ���
	const int gaugeXPos = gaugeBackgroundXPos + 5;
	const int gaugeYPos = gaugeBackgroundYPos + 5;
	int gaugeWidth, gaugeHeight;
	GetGraphSize(boostGaugeImageHandle_, &gaugeWidth, &gaugeHeight);
	gaugeWidth /= 20;
	gaugeHeight /= 20;
	gaugeWidth = gaugeWidth * boostPower_ / 100.0;
	DrawExtendGraph(gaugeXPos, gaugeYPos, gaugeXPos + gaugeWidth, gaugeYPos + gaugeHeight, boostGaugeImageHandle_, TRUE);
}