#include "Caterpillar.h"

vector<unique_ptr<Caterpillar>> Caterpillar::caterpillerList_;
mt19937_64 Caterpillar::mtRand_;
int Caterpillar::fallingLeftImageHandle_;
int Caterpillar::fallingRightImageHandle_;
int Caterpillar::landingLeftImageHandle_;
int Caterpillar::landingRightImageHandle_;


Caterpillar::Caterpillar(int spawnXPos) {
	imageHandle_ = fallingLeftImageHandle_;
	xPos_ = spawnXPos;
	yPos_ = 0;
	landing_ = false;
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

void Caterpillar::move() {
	if (landing_) {
		//���E���߂�ꂽ�����Ɉړ�
		xPos_ += moveLandingVec_;
	} else {
		yPos_++;
		DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	}
}


void Caterpillar::initStaticField() {
	//�񌈒�I�ȗ��������ŏ����l�����߁A�ȍ~�͋[�������Ő�������
	//�Z���Ԋu�ŗ����𐶐�����\��������̂ŁA�p�t�H�[�}���X�̊֌W�㗐������������̂��ѐ�������̂ł͂Ȃ��A�t�B�[���h�ɕێ����Ă���
	random_device randomDevice;
	mtRand_.seed(randomDevice());

	//�R���p�C�����l���m�肵�Ȃ����߁Aconst�ł̎w��͎g���Ȃ����Ƃɒ���
	fallingLeftImageHandle_ = LoadGraph("./Image/Caterpillar_Falling_Left.png");
	fallingRightImageHandle_ = LoadGraph("./Image/Caterpillar_Falling_Right.png");
	landingLeftImageHandle_ = LoadGraph("./Image/Caterpillar_Landing_Left.png");
	landingRightImageHandle_ = LoadGraph("./Image/Caterpillar_Landing_Right.png");
}

//�V�����ђ��������_���Ȉʒu�ɃX�|�[��������
void Caterpillar::randomSpawn(int windowSizeX) {
	int width = 66;
	//��l���z��������������A���̌セ��ɗ����������n���ăX�|�[���ʒu�����߂�
	//TODO:���v���C�@�\��t���邽�߁A�����̏����l��ۑ����悤
	uniform_int_distribution<> randDistribution(0, windowSizeX - width);
	int spawnXPos = randDistribution(mtRand_);
	int yPos = 0;

	DrawGraph(spawnXPos, yPos, fallingLeftImageHandle_, TRUE);
	caterpillerList_.push_back(unique_ptr<Caterpillar>(new Caterpillar(spawnXPos)));
}

void Caterpillar::moveCaterpillars() {
	for (int index = 0; index < caterpillerList_.size(); index++) {
		caterpillerList_[index]->move();
	}
}
