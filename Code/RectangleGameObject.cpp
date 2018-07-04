#include "RectangleGameObject.h"

RectangleGameObject::RectangleGameObject(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
		: GameObject(SizeX, SizeY)
{
	this->LenghtX = LenghtX;
	this->LenghtY = LenghtY;
	rectangleShape.setPosition(x, y);
	rectangleShape.setSize(Vector2f(LenghtX, LenghtY));
	rectangleShape.setOrigin(LenghtX / 2.0f, LenghtY / 2.0f);
}

// Metoda zwraca wspó³rzêdn¹ wybranego boku rakiety
float RectangleGameObject::getSidePosition(char side) const
{
	if (side == 'R') return this->rectangleShape.getPosition().x + LenghtX / 2;
	else if (side == 'L') return this->rectangleShape.getPosition().x - LenghtX / 2;
	else if (side == 'T') return this->rectangleShape.getPosition().y - LenghtY / 2;
	else if (side == 'B') return this->rectangleShape.getPosition().y + LenghtY / 2;
	else throw exception("Litera z poza zakresu");
}
