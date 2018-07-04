#include "Racket.h"

Racket::Racket(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
		: RectangleGameObject(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}

// Funkcja sk³adowa wykonywana przy ka¿dej klatce gry
void Racket::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		if (getSidePosition('L') >= racketVelocity)
		{
			rectangleShape.move(racketVelocityVector*-1.0f);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		if (getSidePosition('R') <= windowSizeX)
		{
			rectangleShape.move(racketVelocityVector);
		}
	}
}

// Funkcja sk³adowa zwracaj¹ca pozycjê prostok¹tu
Vector2f Racket::GetPosition() const
{
	return this->rectangleShape.getPosition();
}

void Racket::SetApperance()
{
	rectangleShape.setFillColor(Color::White);
}

