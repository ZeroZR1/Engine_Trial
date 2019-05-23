#pragma once
#include "PackageManager.h"

/*All things concerning the sprite animation should be handled here
This will be reconsidered if it gets too messy*/

/*Animation Declaration****************************************************************************************************/

class Animation {
public:
	std::vector<int> AnimationFrames;
	std::string Name;

	Animation(std::string AnimationName, std::vector<int> _AnimationFrames);
};

/*Animator Declaration*****************************************************************************************************/

class Animator{
public:
/*-------------------------------------*/
	std::vector<ALLEGRO_BITMAP*> Sprite;
	std::vector<Animation> AnimationList;

	std::vector <std::string> AnimationBuffer;//I got plans for this, in the animation transitioning
	int CurrentAnimation;
	int AnimationSubIndex;/*Used to difentiate from the local coordinates 
	used to navigate AnimationList from CurrentFrame wich is the global index to navigate Sprite*/
	int CurrentFrame;

	int BuildUp;
	int Speed;
/*-------------------------------------*/
	Animator(int TargetSpeed);

	~Animator();

	void LoadPackage(std::vector<ALLEGRO_BITMAP*> Package);

	void SetCurrentFrame(int Index);

	ALLEGRO_BITMAP* Draw();

	ALLEGRO_BITMAP* Draw(int TargetState);

	void Reset();

	void SetAnimationSpeed(int TargetSpeed);

	void NewAnimation(std::string AnimationName, std::vector<int> _AnimationFrames);

	void SetAnimation(std::string AnimationName);

	void AnimateTo(bool Backward);

	void AnimateLoop(bool Backward);
};

/**************************************************************************************************************************/


