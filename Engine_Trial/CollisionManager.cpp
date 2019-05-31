#include "stdafx.h"
#include "CollisionManager.h"


Collision::Collision(int HitboxA, int HitboxB) {
	CollidingPair.reserve(2);
	CollidingPair.push_back(HitboxA);
	CollidingPair.push_back(HitboxB);
	CollidingPair.shrink_to_fit();
}

Collision::~Collision() {}


CollisionManager::CollisionManager(){}


CollisionManager::~CollisionManager(){}

void CollisionManager::CheckCollisions(std::vector<GameObject> ObjectList) {

	if (ObjectList.size() > 1) {
		for (size_t i = 0; i < ObjectList.size() - 1; i++) {
			for (size_t j = 0; j < ObjectList.size() - 1; j++) {

				if (ObjectList[i].ObjHitbox.Init || ObjectList[j].ObjHitbox.Init) {
					if (ObjectList[i].ObjHitbox.x  <  ObjectList[j].ObjHitbox.x + ObjectList[j].ObjHitbox.Width   &&
						ObjectList[i].ObjHitbox.x + ObjectList[i].ObjHitbox.Width  >  ObjectList[j].ObjHitbox.x       &&
						ObjectList[i].ObjHitbox.y  <  ObjectList[j].ObjHitbox.y + ObjectList[j].ObjHitbox.Height  &&
						ObjectList[i].ObjHitbox.y + ObjectList[i].ObjHitbox.Height >  ObjectList[j].ObjHitbox.y) {

						CollisionList.push_back(Collision(i, j));
					}
				}
			}
		}
	}
}

std::vector<Collision> CollisionManager::GetCollisions() {
	return(CollisionList);
}
