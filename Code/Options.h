#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Options : public Menu
{
public:
	Options(int sizeX, int  sizeY, Font defaultFont, GameStatus status);
	~Options() = default;

private:
	void SetApperance();
	void SetTexts();
	void SetFontStyle();
};

