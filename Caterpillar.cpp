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
bool Caterpillar::checkHit(int objectLeft, int objectRight, int objectTop, int objectButtom) {
	int caterpillarSizeX, caterpillerSizeY;
	GetGraphSize(imageHandle_, &caterpillarSizeX, &caterpillerSizeY);
	int caterpillarLeft = posX_;
	int caterpillarRight = posX_ + caterpillarSizeX;
	int caterpillarLeftButtom = posY_ + caterpillerSizeY;

	bool hit = false;
	//�I�u�W�F�N�g�̉E�[�����[���E���A�I�u�W�F�N�g�̍��[���E�[��荶
	if (objectRight > caterpillarLeft && objectLeft < caterpillarRight) {
		int caterpillarTop = posY_;
		int caterpillarButtom = posY_ + caterpillerSizeY;
		
		//��̔������[�A���[�œ����悤�ɍs��
		if (caterpillarTop > objectButtom && caterpillarButtom < objectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::randomSpawn(int windowSizeX) {
	int imageWidth = 66;
	//TODO:���v���C�@�\��t���邽�߁A�����̏����l��ۑ����悤
	posX_ = GetRand(windowSizeX - imageWidth);

	DrawGraph(posX_, posY_, imageHandle_, TRUE);
}

void Caterpillar::deleteAllInstances() {
	for (Caterpillar* caterpillar : caterpillerList_) {
		delete caterpillar;
	}
}