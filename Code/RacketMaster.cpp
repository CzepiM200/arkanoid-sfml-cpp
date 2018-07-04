#include "RacketMaster.h"



RacketMaster::RacketMaster(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
	: Racket(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}

void RacketMaster::SetApperance()
{
	rectangleShape.setFillColor(Color::Cyan);
	LenghtX += 100.0f;
	rectangleShape.setSize(Vector2f(LenghtX, LenghtY));
	rectangleShape.setOrigin(Vector2f((LenghtX) / 2, LenghtY / 2));
	racketVelocity += 10.0f;
}