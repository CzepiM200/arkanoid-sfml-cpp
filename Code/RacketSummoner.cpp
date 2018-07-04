#include "RacketSummoner.h"



RacketSummoner::RacketSummoner(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
	: Racket(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}


void RacketSummoner::SetApperance()
{
	rectangleShape.setFillColor(Color::Blue);
	LenghtX += 50.0f;
	rectangleShape.setSize(Vector2f(LenghtX, LenghtY));
	rectangleShape.setOrigin(Vector2f((LenghtX) / 2, LenghtY / 2));
	racketVelocity += 5.0f;
}