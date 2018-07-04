#include "ChoseRacket.h"



ChoseRacket::ChoseRacket(int sizeX, int sizeY, Font defaultFont, GameStatus status)
	: Menu(sizeX, sizeY, defaultFont, status)
{
	SetApperance();
}

void ChoseRacket::SetApperance()
{
	amountOfOptions = 6;
	firstColor = Color::White;
	secoundColor = Color::Magenta;
	SetTexts();
	SetFontStyle();
}

// Ustawia nazwy rakiet
void ChoseRacket::SetTexts()
{
	options[0].setString("Long Racket");
	options[1].setString("Fast Racket");
	options[2].setString("Strong Racket");
	options[3].setString("Lucky Racket");
	options[4].setString("Summoner Racket");
	options[5].setString("Master Racket");
}


void ChoseRacket::SetFontStyle()
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