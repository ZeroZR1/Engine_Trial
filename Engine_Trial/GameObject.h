#pragma once
#include "stdafx.h"
#include "Animator.h"

class GameObject
{public:
	//Position
	float x;
	float y;

	std::vector<ALLEGRO_BITMAP*> Sprite;
	Animator ObjAnimator;
	
	GameObject(float _x, float _y);

	~GameObject();

	void SetPosition(float _x, float _y);

	void SetSprite(std::vector <ALLEGRO_BITMAP*> _Sprite);

	void DrawObject();

	void AddAnimation(bool _Loop, std::string _AnimationName, std::vector<int> _AnimationFrames);

	void ActiveAnimation(std::string _AnimationName);


	void Check();;

};

