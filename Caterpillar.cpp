#include "Caterpillar.h"

vector<Caterpillar*>* Caterpillar::caterpillerList_;
int Caterpillar::fallingLeftImageHandle_;
int Caterpillar::fallingRightImageHandle_;
int Caterpillar::landingLeftImageHandle_;
int Caterpillar::landingRightImageHandle_;

Caterpillar::Caterpillar(int spawnXPos) {
	imageHandle_ = fallingLeftImageHandle_;
	xPos_ = spawnXPos;
	yPos_ = 0;
	landing_ = false;
	caterpillerList_->push_back(this);
}

//矩形の当たり判定
bool Caterpillar::checkHit(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int width, height;
	GetGraphSize(imageHandle_, &width, &height);
	int caterpillarLeft = xPos_;
	int caterpillarRight = xPos_ + width;
	int caterpillarLeftButtom = yPos_ + height;

	bool hit = false;
	//オブジェクトの右端が左端より右かつ、オブジェクトの左端が右端より左
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = yPos_;
		int caterpillarButtom = yPos_ + height;
		
		//上の判定を上端、下端で同じように行う
		if (caterpillarTop > hitObjectButtom && caterpillarButtom < hitObjectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::move() {
	if (landing_) {
		//左右決められた方向に移動
		xPos_ += moveLandingVec_;
	} else {
		yPos_++;
		DrawGraph(xPos_, yPos_, imageHandle_, TRUE);
	}
}

void Caterpillar::initStaticField() {
	caterpillerList_ = new vector<Caterpillar*>();

	fallingLeftImageHandle_ = LoadGraph("./Image/Caterpillar_Falling_Left.png");
	fallingRightImageHandle_ = LoadGraph("./Image/Caterpillar_Falling_Right.png");
	landingLeftImageHandle_ = LoadGraph("./Image/Caterpillar_Landing_Left.png");
	landingRightImageHandle_ = LoadGraph("./Image/Caterpillar_Landing_Right.png");
}

void Caterpillar::randomSpawn(int windowSizeX) {
	int width = 66;
	//TODO:リプレイ機能を付けるため、乱数の初期値を保存しよう
	int spawnXPos = GetRand(windowSizeX - width);
	int yPos = 0;

	DrawGraph(spawnXPos, yPos, fallingLeftImageHandle_, TRUE);
	new Caterpillar(spawnXPos);
}

void Caterpillar::moveCaterpillars() {
	for (Caterpillar* caterpillar : *caterpillerList_) {
		caterpillar->move();
	}
}

void Caterpillar::deleteAllInstances() {
	for (Caterpillar* caterpillar : *caterpillerList_) {
		delete caterpillar;
	}
	delete caterpillerList_;
}