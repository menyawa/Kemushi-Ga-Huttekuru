#include "Fps.h"

Fps::Fps() {
	startTime_ = GetNowCount();
	count_ = 0;
	trueFps_ = 0;
}

void Fps::update() {
	if (count_ == 0) { //1�t���[���ڂȂ玞�����L��
		startTime_ = GetNowCount();
	}
	const int sampleCount = 60;
	if (count_ == sampleCount) { //60�t���[���ڂȂ畽�ς��v�Z����
		int endTime = GetNowCount();
		//�ꉞ�A���ۂ�FPS�𕽋ς��Ď���Ă���
		trueFps_ = 1000.f / ((endTime - startTime_) / (float)sampleCount);
		count_ = 0;
		startTime_ = endTime;
	}
	count_++;
}

void Fps::wait() {
	const int sampleFps = 60;
	int tookTime = GetNowCount() - startTime_;	//���ۂɌo�߂�������
	//�u�z��o�ߎ��� - ���ۂɌo�߂������ԁv���t���[�����ƂɌv�Z���A�]�莞�ԑ҂��Ƃőz�肵��FPS�ɍ��킹��
	int waitTime = count_ * 1000 / sampleFps - tookTime;
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}