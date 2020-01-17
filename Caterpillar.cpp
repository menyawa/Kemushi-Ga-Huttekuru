#include "DxLib.h"
#include "Caterpillar.h"
#include "string"

vector<Caterpillar*> Caterpillar::caterpillerList_;

Caterpillar::Caterpillar(int windowSizeX) {
	caterpillerList_.push_back(this);
	imageHandle_ = LoadGraph("./Image/Caterpillar_Resize_Rotate.png");
	yPos_ = 0;
	randomSpawn(windowSizeX);
}

//��`�̓����蔻��
bool Caterpillar::checkHit(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int width, height;
	GetGraphSize(imageHandle_, &width, &height);
	int caterpillarLeft = xPos_;
	int caterpillarRight = xPos_ + width;
	int caterpillarLeftButtom = yPos_ + height;

	bool hit = false;
	//�I�u�W�F�N�g�̉E�[�����[���E���A�I�u�W�F�N�g�̍��[���E�[��荶
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = yPos_;
		int caterpillarButtom = yPos_ + height;
		
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
	xPos_ = GetRand(windowSizeX - width);

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Caterpillar::deleteAllInstances() {
	for (Caterpillar* caterpillar : caterpillerList_) {
		delete caterpillar;
	}
}