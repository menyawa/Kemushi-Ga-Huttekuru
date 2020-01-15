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
bool Caterpillar::checkHit(int objectLeft, int objectRight, int objectTop, int objectButtom) {
	int caterpillarSizeX, caterpillerSizeY;
	GetGraphSize(imageHandle_, &caterpillarSizeX, &caterpillerSizeY);
	int caterpillarLeft = posX_;
	int caterpillarRight = posX_ + caterpillarSizeX;
	int caterpillarLeftButtom = posY_ + caterpillerSizeY;

	bool hit = false;
	//オブジェクトの右端が左端より右かつ、オブジェクトの左端が右端より左
	if (objectRight > caterpillarLeft && objectLeft < caterpillarRight) {
		int caterpillarTop = posY_;
		int caterpillarButtom = posY_ + caterpillerSizeY;
		
		//上の判定を上端、下端で同じように行う
		if (caterpillarTop > objectButtom && caterpillarButtom < objectTop) {
			hit = true;
		}
	}

	return hit;
}

void Caterpillar::randomSpawn(int windowSizeX) {
	int imageWidth = 66;
	//TODO:リプレイ機能を付けるため、乱数の初期値を保存しよう
	posX_ = GetRand(windowSizeX - imageWidth);

	DrawGraph(posX_, posY_, imageHandle_, TRUE);
}

void Caterpillar::deleteAllInstances() {
	for (Caterpillar* caterpillar : caterpillerList_) {
		delete caterpillar;
	}
}