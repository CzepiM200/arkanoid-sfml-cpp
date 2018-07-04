#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Ball.h"
#include "Racket.h"
#include "Block.h"
#include "Menu.h"
#include "Enums.h"
#include "UserData.h"
#include "MainMenu.h"
#include "Shop.h"
#include "Options.h"
#include "Racket.h"
#include "RacketLong.h"
#include "RacketFast.h"
#include "RacketStrong.h"
#include "ChoseRacket.h"

using namespace sf;
using namespace std;

class GameController
{
public:
	GameController();
	void Close();
	~GameController() = default;
	
	void ChoseOption(Menu* menu);
	void CheckGameStatus();
	void OpenShop();
	void OpenOptions();
	
	void GenerateRandomLevel(vector<Block> blocks);
	RenderWindow window;
	void StartGame();
	unsigned const int windowSizeX = 1010;
	unsigned const int windowSizeY = 600;
	template <class Object1, class Object2> bool CheckeColision(Object1& obj1, Object2& obj2);
	void BallAndRacketCollisions(Racket &racket, Ball &ball);
	static float CheckHitAngle(Racket & racket, Ball & ball);
	bool BlockAndBallCollisins(Block &block, Ball &ball);
	void DrawFrame(Ball ball, Racket* racket, vector<Block> blocks);
	void OpenMenu();
	void OpenGameSumation(GameSolution gameSolution, int points, int coins);

private:
	UserData* data;
	GameStatus gameStatus{MENU};
	Rackets SelectRacket();
	unsigned int selectedOption{ 0 };
	unsigned const int frameSize{ 10 };
	unsigned const int separatingSpace{ 2 };
	static unsigned const int blockWidth{ 60 };
	static unsigned const int blockHeight{ 30 };
	static unsigned const int racketWidth{ 200 };
	static unsigned const int racketHeight{ 20 };
	Font defaultFont;
	void OpenStats();
};

