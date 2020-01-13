#include "DxLib.h"
#include "Caterpillar.h"

vector<Caterpillar*> Caterpillar::caterpillers_;

Caterpillar::Caterpillar() {
	caterpillers_.push_back(this);

	posY_ = 0;
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