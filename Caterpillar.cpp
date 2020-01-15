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

//矩形の当たり判定
bool Caterpillar::checkHit(int hitObjectLeft, int hitObjectRight, int hitObjectTop, int hitObjectButtom) {
	int width, height;
	GetGraphSize(imageHandle_, &width, &height);
	int caterpillarLeft = posX_;
	int caterpillarRight = posX_ + width;
	int caterpillarLeftButtom = posY_ + height;

	bool hit = false;
	//オブジェクトの右端が左端より右かつ、オブジェクトの左端が右端より左
	if (hitObjectRight > caterpillarLeft && hitObjectLeft < caterpillarRight) {
		int caterpillarTop = posY_;
		int caterpillarButtom = posY_ + height;
		
		//上の判定を上端、下端で同じように行う
		if (caterpillarTop > hitObjectButtom && caterpillarButtom < hitObjectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::randomSpawn(int windowSizeX) {
	int width = 66;
	//TODO:リプレイ機能を付けるため、乱数の初期値を保存しよう
	posX_ = GetRand(windowSizeX - width);

	DrawGraph(posX_, posY_, imageHandle_, TRUE);
}

void Caterpillar::deleteAllInstances() {
	for (Caterpillar* caterpillar : caterpillerList_) {
		delete caterpillar;
	}
}