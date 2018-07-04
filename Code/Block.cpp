#include "Block.h"

Block::Block(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY, int type)
	: RectangleGameObject(x, y, SizeX, SizeY, LenghtX, LenghtY)
{
	SetColor(type);
	this->typeOfBlock = type;
}

int Block::CheckType()
{
	return this->typeOfBlock;
}


void Block::SetColor(int type)
{
	if (type == 0)rectangleShape.setFillColor(Color::Green);
	else if (type == 1)rectangleShape.setFillColor(Color::Blue);
	else if (type == 2)rectangleShape.setFillColor(Color::Red);
	else if (type == 3)rectangleShape.setFillColor(Color::Yellow);
}
