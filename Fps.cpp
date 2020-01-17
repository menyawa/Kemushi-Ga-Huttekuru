#include "Fps.h"

Fps::Fps() {
	startTime_ = GetNowCount();
	count_ = 0;
	trueFps_ = 0;
}

void Fps::update() {
	if (count_ == 0) { //1フレーム目なら時刻を記憶
		startTime_ = GetNowCount();
	}
	const int sampleCount = 60;
	if (count_ == sampleCount) { //60フレーム目なら平均を計算する
		int endTime = GetNowCount();
		//一応、実際のFPSを平均して取っておく
		trueFps_ = 1000.f / ((endTime - startTime_) / (float)sampleCount);
		count_ = 0;
		startTime_ = endTime;
	}
	count_++;
}

void Fps::wait() {
	const int sampleFps = 60;
	int tookTime = GetNowCount() - startTime_;	//実際に経過した時間
	//「想定経過時間 - 実際に経過した時間」をフレームごとに計算し、余剰時間待つことで想定したFPSに合わせる
	int waitTime = count_ * 1000 / sampleFps - tookTime;
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}