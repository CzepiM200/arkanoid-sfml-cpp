#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enums.h"

using namespace std;
using namespace sf;

const unsigned int MaxAmountOfOptions = 10;

class Menu
{
public:
	Menu(int sizeX, int  sizeY, Font defaultFont, GameStatus status);
	Menu() = delete;
	~Menu() = default;
	void draw(RenderWindow& window) const;
	int GetOptionNumber() const;
	void MoveDown();
	void MoveUp();

protected:
	unsigned int defalutFontSize{ 25 };
	Font font;
	int windowSizeX;
	int windowSizeY;
	Color firstColor{ Color::White };
	Color secoundColor{ Color::Red };
	GameStatus status;
	unsigned int selectedOption{ 0 };
	unsigned int amountOfOptions;
	Text options[MaxAmountOfOptions];

private:
	void SetWindowSize(int sizeX, int sizeY);
};
