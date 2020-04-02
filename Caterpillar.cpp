#include "Caterpillar.h"

vector<unique_ptr<Caterpillar>> Caterpillar::caterpillerList_;
mt19937_64 Caterpillar::mtRand_;
int Caterpillar::fallingImageHandles_[2];
int Caterpillar::landingImageHandles_[2];


Caterpillar::Caterpillar(int spawnXPos, int imageHandleIndex) {
	imageHandle_ = fallingImageHandles_[imageHandleIndex];
	ditectionImageHandleIndex_ = imageHandleIndex;
	xPos_ = spawnXPos;
	yPos_ = 0;
	GetGraphSize(imageHandle_, &width_, &height_);
	DrawGraph(spawnXPos, yPos_, fallingImageHandles_[imageHandleIndex], TRUE);
	moveLandingVec_ = ditectionImageHandleIndex_ == 0 ? -1 : 1; //���������E�������Œ��n��̈ړ��������ς��
	landing_ = false;
}

//��`�̓����蔻��Ńv���C���[�ɓ����������m�F����
bool Caterpillar::checkHitPlayer(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int caterpillarLeft = xPos_;
	int caterpillarRight = xPos_ + width_;
	int caterpillarLeftButtom = yPos_ + height_;

	bool hit = false;
	//�I�u�W�F�N�g�̉E�[�����[���E���A�I�u�W�F�N�g�̍��[���E�[��荶
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = yPos_;
		int caterpillarButtom = yPos_ + height_;
		
		//��̔������[�A���[�œ����悤�ɍs��
		if (caterpillarTop > hitObjectButtom && caterpillarButtom < hitObjectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::move(BackgroundController& backgroundController) {
	if (landing_) {
		//���E���߂�ꂽ�����Ɉړ�
		xPos_ += moveLandingVec_;
	} else {
		yPos_++;
	}

	//���n�����ꍇ�A�����Ă����������������܂܉������ɂ���
	if (backgroundController.checkLandingGround(yPos_, height_)) {
		landing_ = true;
		imageHandle_ = landingImageHandles_[ditectionImageHandleIndex_];
		swap(width_, height_); //���n����̂ŁA���̒����Əc�̒���������ւ��
		yPos_ = backgroundController.groundPosY_ - height_;
	}

	DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
}

void Caterpillar::initStaticField() {
	//�񌈒�I�ȗ��������ŏ����l�����߁A�ȍ~�͋[�������Ő�������
	//�Z���Ԋu�ŗ����𐶐�����\��������̂ŁA�p�t�H�[�}���X�̊֌W�㗐������������̂��ѐ�������̂ł͂Ȃ��A�t�B�[���h�ɕێ����Ă���
	random_device randomDevice;
	mtRand_.seed(randomDevice());

	//�R���p�C�����l���m�肵�Ȃ����߁Aconst�ł̎w��͎g���Ȃ����Ƃɒ���
	fallingImageHandles_[0] = LoadGraph("./Image/Caterpillar_Falling_Left.png");
	fallingImageHandles_[1] = LoadGraph("./Image/Caterpillar_Falling_Right.png");
	landingImageHandles_[0] = LoadGraph("./Image/Caterpillar_Landing_Left.png");
	landingImageHandles_[1] = LoadGraph("./Image/Caterpillar_Landing_Right.png");
}

//�V�����ђ��������_���Ȉʒu�ɃX�|�[��������
void Caterpillar::randomSpawn(int windowSizeX) {
	int fallingCaterpillarWidth = 66;
	//��l���z��������������A���̌セ��ɗ����������n���ăX�|�[���ʒu�����߂�
	uniform_int_distribution<> spawnPosRandDistribution(0, windowSizeX - fallingCaterpillarWidth);
	int spawnXPos = spawnPosRandDistribution(mtRand_);
	//���l�ɁA���E�ǂ�����������̃C���f�b�N�X�����߂�
	uniform_int_distribution<> fallingRandDistribution(0, 1);
	caterpillerList_.push_back(unique_ptr<Caterpillar>(new Caterpillar(spawnXPos, fallingRandDistribution(mtRand_))));
}

//����BackgroundController�̃C���X�^���X�𐶐�����ƕ��ׂɂȂ邱�Ƃ��\�z����邽�߁A�Q�ƂőΏ�
void Caterpillar::moveAllCaterpillars(BackgroundController& backgroundController) {
	for (int index = 0; index < caterpillerList_.size(); index++) {
		caterpillerList_[index]->move(backgroundController);
	}
}
