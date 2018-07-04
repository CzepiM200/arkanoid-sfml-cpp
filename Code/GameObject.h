#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class GameObject : public Drawable
{
public:
	GameObject(int SizeX, int SizeY);
	~GameObject() = default;

	void SetWindowSize(int SizeX, int SizeY);

protected:
	int windowSizeX;
	int windowSizeY;
	
};
