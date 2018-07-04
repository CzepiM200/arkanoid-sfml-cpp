#pragma once
#include "Menu.h"
class ChoseRacket : public Menu
{
public:
	ChoseRacket(int sizeX, int sizeY, Font defaultFont, GameStatus status);
	~ChoseRacket() = default;

private:
	void SetApperance();
	void SetTexts();
	void SetFontStyle();
};

