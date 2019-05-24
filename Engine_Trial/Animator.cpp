#include "stdafx.h"
#include "Animator.h"

/*Animation Definition*****************************************************************************************************/

Animation::Animation(bool _Looped, std::string AnimationName, std::vector<int> _AnimationFrames)
{
	AnimationFrames.reserve(_AnimationFrames.size());
	AnimationFrames = _AnimationFrames;
	Name = AnimationName;
	Looped = _Looped;
}

/*Animator Definition******************************************************************************************************/

Animator::Animator()
{
	CurrentFrame = 0;
	Speed = 1;
	BuildUp = 0;
	CurrentAnimation = 0;
	AnimationList.clear();
	AnimationList.shrink_to_fit();

	AnimationBuffer.reserve(3);
}


Animator::~Animator()
{
}

void Animator::SetCurrentFrame(int Index) {
	CurrentFrame = Index;
}

ALLEGRO_BITMAP* Animator::Draw(std::vector<ALLEGRO_BITMAP*> _Sprite) {
	return(_Sprite[CurrentFrame]);
}

ALLEGRO_BITMAP * Animator::Draw(int TargetState, std::vector<ALLEGRO_BITMAP*> _Sprite)
{
	return(_Sprite[TargetState]);
}

void Animator::Reset() {
	CurrentFrame = 0;
	BuildUp = 0;
}

void Animator::SetAnimationSpeed(int TargetSpeed){
	Speed = TargetSpeed;
}


void Animator::NewAnimation(bool _Loop,std::string AnimationName, std::vector<int> _AnimationFrames) {
	AnimationList.push_back(Animation(_Loop, AnimationName, _AnimationFrames));
}

void Animator::SetAnimation(std::string AnimationName)
{
	for (size_t i = 0; i < AnimationList.size(); i++)
	{
		if (AnimationList[i].Name == AnimationName) {
			CurrentAnimation = i;
			CurrentFrame = AnimationList[i].AnimationFrames[0];
		}
	}
}


/*Just realized Animation moving backwards is dumb, I mean you could just create anoter animation
going backwards and thats it*/

void Animator::AnimateTo() {

	if (BuildUp <= 10) {
		BuildUp += 1 +(1* Speed);
	}
	else {
		if (AnimationSubIndex < AnimationList[CurrentAnimation].AnimationFrames.size()-1) {
			/*Ok, something is got to be done about this IF, likely we'l make a 
			function to return sizes in nested vectors because... Look at that MESS!
			Also it give signed unsigned mismatch because .size() return a size_t which is an usingned int*/
			AnimationSubIndex++;
			CurrentFrame = AnimationList[ CurrentAnimation ].AnimationFrames[ AnimationSubIndex ];
			BuildUp = 0;
		}

	}
}


void Animator::AnimateLoop(){
	if (BuildUp <= 10) {
		BuildUp += 1 * Speed;
	}
	else {
			/*Ok, something is got to be done about this IF, likely we'l make a
			function to return sizes in nested vectors because... Look at that MESS!*/
			AnimationSubIndex++;
			BuildUp = 0;
			if (AnimationSubIndex > AnimationList[CurrentAnimation].AnimationFrames.size() - 1) {
				AnimationSubIndex = 0;
			}
			CurrentFrame = AnimationList[CurrentAnimation].AnimationFrames[AnimationSubIndex];
	}
}


void Animator::Animate() {
	if (AnimationList[CurrentAnimation].Looped) {
		AnimateLoop();
	}
	else {
		AnimateTo();
	}
}


/*About Animate to and AnimateLoop, I'm itching to 
split the core logic into sub functions, yet I also think it would be unnecessary

*/
