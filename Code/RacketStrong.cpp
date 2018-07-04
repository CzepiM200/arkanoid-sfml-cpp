#include "RacketStrong.h"



RacketStrong::RacketStrong(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY)
	: Racket(x, y, SizeX, SizeY, LenghtX, LenghtY)
{

}


void RacketStrong::SetApperance()
{
	rectangleShape.setFillColor(Color::Red);
}
