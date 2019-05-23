#include "stdafx.h"
#include "Animator.h"

/*Animation Definition*****************************************************************************************************/

Animation::Animation(std::string AnimationName, std::vector<int> _AnimationFrames)
{
	AnimationFrames.resize(_AnimationFrames.size());
	AnimationFrames = _AnimationFrames;
	Name = AnimationName;
}

/*Animator Definition******************************************************************************************************/

Animator::Animator(int TargetSpeed)
{
	CurrentFrame = 0;
	Speed = TargetSpeed;
	BuildUp = 0;
	AnimationBuffer.reserve(3);
	CurrentAnimation = 0;
}


Animator::~Animator()
{
}

/*Loads the sprite from a Package to be used, the size of the 
vector should be already set hence the resize*/
void Animator::LoadPackage(std::vector<ALLEGRO_BITMAP*> Package){
	Sprite.resize(Package.size());
	Sprite = Package;
	CurrentFrame = 0;
}

void Animator::SetCurrentFrame(int Index) {
	CurrentFrame = Index;
}

ALLEGRO_BITMAP* Animator::Draw() {
	return(Sprite[CurrentFrame]);
}

ALLEGRO_BITMAP * Animator::Draw(int TargetState)
{
	return(Sprite[TargetState]);
}

void Animator::Reset() {
	CurrentFrame = 0;
	BuildUp = 0;
}

void Animator::SetAnimationSpeed(int TargetSpeed){
	Speed = TargetSpeed;
}

/*WORKING******************************************************************************************************************/
void Animator::NewAnimation(std::string AnimationName, std::vector<int> _AnimationFrames) {
	AnimationList.push_back(Animation(AnimationName, _AnimationFrames));
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

void Animator::AnimateTo(bool Backward) {

	if (BuildUp <= 10) {
		BuildUp += 1 * Speed;
	}
	else {
		if (!Backward && AnimationSubIndex < AnimationList[CurrentAnimation].AnimationFrames.size()-1) {
			/*Ok, something is got to be done about this IF, likely we'l make a 
			function to return sizes in nested vectors because... Look at that MESS!*/
			AnimationSubIndex++;
			CurrentFrame = AnimationList[ CurrentAnimation ].AnimationFrames[ AnimationSubIndex ];
			BuildUp = 0;
		}
		else if (Backward && AnimationSubIndex > 0) {
			AnimationSubIndex--;
			CurrentFrame = AnimationList[CurrentAnimation].AnimationFrames[AnimationSubIndex];
			BuildUp = 0;
		}

	}
}

void Animator::AnimateLoop(bool Backward){
	if (BuildUp <= 10) {
		BuildUp += 1 * Speed;
	}
	else {
		if (!Backward) {
			/*Ok, something is got to be done about this IF, likely we'l make a
			function to return sizes in nested vectors because... Look at that MESS!*/
			AnimationSubIndex++;
			CurrentFrame = AnimationList[CurrentAnimation].AnimationFrames[AnimationSubIndex];
			BuildUp = 0;
			if (AnimationSubIndex >= AnimationList[CurrentAnimation].AnimationFrames.size() - 1) {
				AnimationSubIndex = 0;
			}
		}
		else if (Backward && AnimationSubIndex > 0) {
			AnimationSubIndex--;
			CurrentFrame = AnimationList[CurrentAnimation].AnimationFrames[AnimationSubIndex];
			BuildUp = 0;
			if (AnimationSubIndex < 0) {
				AnimationSubIndex = AnimationList[CurrentAnimation].AnimationFrames.size() - 1;
			}
		}

	}
}


/*WORKING******************************************************************************************************************/


/*About Animate to and AnimateLoop, I'm itching to 
split the core logic into sub functions, yet I also think it would be unnecessary
Also considered using the two into one function

PD they will likely become Obsolete with the new Animate and AnimateLoop(String)*/
