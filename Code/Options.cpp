#include "Options.h"



Options::Options(int sizeX, int  sizeY, Font defaultFont, GameStatus status)
	: Menu(sizeX, sizeY, defaultFont, status)
{
	SetApperance();
}

void Options::SetApperance()
{
	amountOfOptions = 4;
	firstColor = Color::White;
	secoundColor = Color::Green;
	SetTexts();
	SetFontStyle();
}

// Ustawia nazwy rakiet
void Options::SetTexts()
{
	options[0].setString("Load from file");
	options[1].setString("Save data");
	options[2].setString("Restart all game data !!!");
	options[3].setString("Add 10000 coins");
}


void Options::SetFontStyle()
{
	for (int i = 0; i < amountOfOptions; i++)
	{
		options[i].setFont(font);
		if (i != 0)options[i].setFillColor(firstColor);
		else options[i].setFillColor(secoundColor);
		options[i].setCharacterSize(defalutFontSize / 2);
		options[i].setPosition(50.f, 30.f + i * (windowSizeY * 0.2f));
	}
}