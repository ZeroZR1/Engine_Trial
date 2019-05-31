#include "stdafx.h"
#include "HitBox.h"


Hitbox::Hitbox(){
	x = float();
	y = float();
	Width = float();
	Height = float();
	Init = false;
}

Hitbox::~Hitbox(){
}

void Hitbox::HitboxInit(float _x, float _y, float _Width, float _Height, std::string _PhysicsType) {
	x = _x;
	y = _y;
	Width = _Width;
	Height = _Height;
	Init = true;

	if(_PhysicsType == "Dinamic") {
		PhisycsType = true;
	}else{
		PhisycsType = false;
	}
}

