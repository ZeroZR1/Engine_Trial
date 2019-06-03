#pragma once
#include "PackageManager.h"

/*All things concerning the sprite animation should be handled here
This will be reconsidered if it gets too messy*/

/*Animation Declaration****************************************************************************************************/

class Sprite {
public:
	int x;
	int y;
	int Width;
	int Height;

	Sprite(int _x, int _y, int _Width, int _Height) {
		x = _x;
		y = _y;
		Width = _Width;
		Height = _Height;
	}

};

class Animation {
public:
	bool Looped;
	std::vector<int> AnimationFrames;
	std::string Name;

	Animation(bool _Looped, std::string AnimationName, std::vector<int> _AnimationFrames);
};

/*Animator Declaration*****************************************************************************************************/

class Animator{
public:
/*-------------------------------------*/
	std::vector<Animation> AnimationList;

	std::vector <std::string> AnimationBuffer;//I got plans for this, in the animation transitioning
	int CurrentAnimation;
	int AnimationSubIndex;/*Used to difentiate from the local coordinates 
	used to navigate AnimationList from CurrentFrame wich is the global index to navigate Sprite*/
	int CurrentFrame;

	int BuildUp;
	int Speed;
/*-------------------------------------*/
	Animator();

	~Animator();

	void SetCurrentFrame(int Index);

	ALLEGRO_BITMAP* Draw(std::vector<ALLEGRO_BITMAP*> _Sprite);

	ALLEGRO_BITMAP* Draw(int TargetState, std::vector<ALLEGRO_BITMAP*> _Sprite);

	void Reset();

	void SetAnimationSpeed(int TargetSpeed);

	void NewAnimation(bool _Loop, std::string AnimationName, std::vector<int> _AnimationFrames);

	void SetAnimation(std::string AnimationName);

	void AnimateTo();

	void AnimateLoop();

	void Animate();
};

/**************************************************************************************************************************/


