#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(float _x, float _y) {
	x = _x;
	y = _y;
	Sprite.clear();
	Sprite.shrink_to_fit();

}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(float _x, float _y) {
	x = _x;
	y = _y;
}

void GameObject::SetSprite(std::vector<ALLEGRO_BITMAP*> _Sprite) {
	Sprite.reserve(_Sprite.size());
	Sprite = _Sprite;
}
void GameObject::DrawObject() {
	ObjAnimator.Animate();
	al_draw_bitmap(ObjAnimator.Draw(Sprite), x, y, 0);
}

void GameObject::AddAnimation(bool _Loop, std::string _AnimationName, std::vector<int> _AnimationFrames) {
	ObjAnimator.NewAnimation(_Loop, _AnimationName, _AnimationFrames);
}

void GameObject::ActiveAnimation(std::string _AnimationName) {
	ObjAnimator.SetAnimation(_AnimationName);
}

//Here goes everithing the object does every frame

void GameObject::Check() {
	DrawObject();
}
