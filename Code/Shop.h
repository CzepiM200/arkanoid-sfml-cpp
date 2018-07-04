#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Shop : public Menu
{
public:
	Shop(int sizeX, int sizeY, Font defaultFont, GameStatus status);
	~Shop() = default;

private:
	void SetApperance();
	void SetTexts();
	void SetFontStyle();
};