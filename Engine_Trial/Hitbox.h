#pragma once
#include "GameObject.h"

class Hitbox
{
public:
	float x;
	float y;

	float Width;
	float Height;

	bool PhisycsType;

	bool Init;

	Hitbox();

	~Hitbox();

	void HitboxInit(float _x, float _y, float _Width, float _Height, std::string _PhysicsType);

};

