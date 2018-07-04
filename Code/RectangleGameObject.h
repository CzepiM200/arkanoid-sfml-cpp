#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

using namespace sf;
using namespace std;

class RectangleGameObject : public GameObject
{
public:
	RectangleGameObject(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	RectangleGameObject() = delete;
	~RectangleGameObject() = default;


	int LenghtX;
	int LenghtY;
	RectangleShape rectangleShape;
	float getSidePosition(char side) const;
	void draw(RenderTarget& target, RenderStates state) const override
	{
		target.draw(this->rectangleShape, state);
	}
};

