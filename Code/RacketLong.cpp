#include "RacketLong.h"



RacketLong::RacketLong(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
		: Racket(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}


void RacketLong::SetApperance()
{
	rectangleShape.setFillColor(Color::Yellow);
	LenghtX += 100.0f;
	rectangleShape.setSize(Vector2f(LenghtX, LenghtY));
	rectangleShape.setOrigin(Vector2f((LenghtX)/2, LenghtY/2));
}
