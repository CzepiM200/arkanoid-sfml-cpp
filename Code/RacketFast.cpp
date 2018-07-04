#include "RacketFast.h"


RacketFast::RacketFast(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
	: Racket(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}


void RacketFast::SetApperance()
{
	rectangleShape.setFillColor(Color::Magenta);
	racketVelocity += 10.0f;
}