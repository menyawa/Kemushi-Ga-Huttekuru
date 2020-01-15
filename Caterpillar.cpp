#include "DxLib.h"
#include "Caterpillar.h"
#include "string"

vector<Caterpillar*> Caterpillar::caterpillerList_;

Caterpillar::Caterpillar(int windowSizeX) {
	caterpillerList_.push_back(this);
	imageHandle_ = LoadGraph("./Image/Caterpillar_Resize_Rotate.png");
	posY_ = 0;
	randomSpawn(windowSizeX);
}

//��`�̓����蔻��
bool Caterpillar::checkHit(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int width, height;
	GetGraphSize(imageHandle_, &width, &height);
	int caterpillarLeft = posX_;
	int caterpillarRight = posX_ + width;
	int caterpillarLeftButtom = posY_ + height;

	bool hit = false;
	//�I�u�W�F�N�g�̉E�[�����[���E���A�I�u�W�F�N�g�̍��[���E�[��荶
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = posY_;
		int caterpillarButtom = posY_ + height;
		
		//��̔������[�A���[�œ����悤�ɍs��
		if (caterpillarTop > hitObjectButtom && caterpillarButtom < hitObjectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::randomSpawn(int windowSizeX) {
	int width = 66;
	//TODO:���v���C�@�\��t���邽�߁A�����̏����l��ۑ����悤
	posX_ = GetRand(windowSizeX - width);

	DrawGraph(posX_, posY_, imageHandle_, TRUE);
}

void Caterpillar::deleteAllInstances() {
	for (Caterpillar* caterpillar : caterpillerList_) {
		delete caterpillar;
	}
}