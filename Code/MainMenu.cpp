#include "MainMenu.h"

MainMenu::MainMenu(int sizeX, int sizeY, Font defaultFont, GameStatus status)
		: Menu(sizeX, sizeY, defaultFont, status)
{
	SetApperance();
}

void MainMenu::SetApperance()
{
	amountOfOptions = 5;
	firstColor = Color::White;
	secoundColor = Color::Blue;
	SetTexts();
	SetFontStyle();
}

// Funkcja sk³adowa ustawia tekst, który bêdzie wyœwietlany w menu
void MainMenu::SetTexts()
{
	options[0].setString("PLAY");
	options[1].setString("Shop");
	options[2].setString("Options");
	options[3].setString("Statistics");
	options[4].setString("Exit");
}

void MainMenu::SetFontStyle()
{
	for (int i = 0; i < amountOfOptions; i++)
	{
		options[i].setFont(font);
		if (i != 0)options[i].setFillColor(firstColor);
		else options[i].setFillColor(secoundColor);
		options[i].setCharacterSize(defalutFontSize - 6);
		options[i].setPosition(50.f, 15.f + i * (windowSizeY * 0.18f));
	}
}