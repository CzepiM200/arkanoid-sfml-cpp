#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class MainMenu : public Menu
{
public:
	~MainMenu() = default;
	MainMenu(int sizeX, int sizeY, Font defaultFont, GameStatus status);

private:
	void SetApperance();
	void SetTexts();
	void SetFontStyle();
};

