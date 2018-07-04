#include "Shop.h"



Shop::Shop(int sizeX, int sizeY, Font defaultFont, GameStatus status)
		: Menu(sizeX, sizeY, defaultFont, status)
{
	SetApperance();
}

void Shop::SetApperance()
{
	amountOfOptions = 6;
	firstColor = Color::White;
	secoundColor = Color::Red;
	SetTexts();
	SetFontStyle();
}

// Ustawia nazwy rakiet
void Shop::SetTexts()
{
	options[0].setString("Long Racket  ( 10C )");
	options[1].setString("Fast Racket  ( 20C )");
	options[2].setString("Strong Racket  ( 50C )");
	options[3].setString("Lucky Racket  ( 100C )");
	options[4].setString("Summoner Racket  ( 200C )");
	options[5].setString("Master Racket  ( 1000C )");
}


void Shop::SetFontStyle()
{
	for (int i = 0; i < amountOfOptions; i++)
	{
		options[i].setFont(font);
		if (i != 0)options[i].setFillColor(firstColor);
		else options[i].setFillColor(secoundColor);
		options[i].setCharacterSize(defalutFontSize / 3);
		options[i].setPosition(50.f, 30.f + i * (windowSizeY * 0.15f));
	}
}