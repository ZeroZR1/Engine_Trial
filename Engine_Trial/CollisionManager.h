#pragma once
#include "stdafx.h"
#include "GameObject.h"


class Collision {
public:

	std::vector<int> CollidingPair;

	Collision(int HitboxA, int HitboxB);

	~Collision();

};

class CollisionManager{
public:
	
	std::vector<Collision> CollisionList;

	CollisionManager();
	~CollisionManager();

	void CheckCollisions(std::vector<GameObject> ObjectList);

	std::vector<Collision> GetCollisions();

};

