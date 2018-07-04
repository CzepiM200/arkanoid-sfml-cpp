#include "RacketLucky.h"



RacketLucky::RacketLucky(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
	: Racket(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}


void RacketLucky::SetApperance()
{
	rectangleShape.setFillColor(Color::Green);
	LenghtX += 30.0f;
	rectangleShape.setSize(Vector2f(LenghtX, LenghtY));
	rectangleShape.setOrigin(Vector2f((LenghtX) / 2, LenghtY / 2));
	racketVelocity += 3.0f;
}