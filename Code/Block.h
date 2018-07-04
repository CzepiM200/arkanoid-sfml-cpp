#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RectangleGameObject.h"

using namespace sf;
using namespace std;

class Block : public RectangleGameObject
{
public:
	void SetColor(int type);
	Block(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY, int type);
	Block() = delete;
	~Block() = default;
	Sprite sprite;
	bool blockStatus;
	Color blockColor;
	int CheckType();

	void DestroyBlock()
	{
		status = false;
	}
	bool CheckStatus() const
	{
		return status;
	}
	void draw(RenderTarget& target, RenderStates state) const override
	{
		target.draw(this->sprite, state);
	}

protected:
	bool status = true;
	int typeOfBlock;
};