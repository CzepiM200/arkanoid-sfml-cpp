#include "GameObject.h"


GameObject::GameObject(int SizeX, int SizeY)
{
	SetWindowSize(SizeX, SizeY);
}

void GameObject::SetWindowSize(int SizeX, int SizeY)
{
	this->windowSizeX = SizeX;
	this->windowSizeY = SizeY;
}

