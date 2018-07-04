#include "GameController.h" 
#include "RacketLucky.h"
#include "RacketSummoner.h"
#include "RacketMaster.h"


// Konstruktor GameController
GameController::GameController()
{
	window.create(VideoMode(windowSizeX, windowSizeY), "Arkanoid");
	if (!defaultFont.loadFromFile("Fonts/Zelta-Six.otf")) throw exception("B³¹d w trakcie ³adowania czcionki");
	data = new UserData();
}

/////////////////////////////////////////////////////////////////////////////////
void GameController::CheckGameStatus()
{
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		switch (gameStatus)
		{
		case MENU:
			OpenMenu();
			break;
		case SHOP:
			OpenShop();
			break;
		case OPTIONS:
			OpenOptions();
			break;
		case GAME:
			StartGame();
			break;
		case STATS:
			OpenStats();
			break;
		case EXIT:
			window.close();
			break;
		}
	}
}

// Funkcja sk³adowa zamyka aplikacje
void GameController::Close()
{
	window.close();
}

// Wzór okreœlaj¹cy czy zasz³a kolizja miêdzy dwoma obiektami
template <class Object1, class Object2> bool GameController::CheckeColision(Object1& obj1, Object2& obj2)
{
	return (obj1.getSidePosition('R') >= obj2.getSidePosition('L') &&
		obj1.getSidePosition('L') <= obj2.getSidePosition('R') &&
		obj1.getSidePosition('B') >= obj2.getSidePosition('T') &&
		obj1.getSidePosition('T') <= obj2.getSidePosition('B'));
}

// Sterowanie kolizj¹ Pi³ki z Paletk¹
void GameController::BallAndRacketCollisions(Racket &racket, Ball &ball)
{
	if (CheckeColision(racket, ball))
	{
		if (CheckeColision(racket, ball))
		{
			ball.RevertVelocityVecctor(false, true);
			ball.ChangeVelocityVector(CheckHitAngle(racket, ball));
		}
	}
}

// Funkcja sk³adowa okreslajaca kat odbicia pilki od paletki
float GameController::CheckHitAngle(Racket &racket, Ball &ball)
{
	return  (2 * (ball.GetPosition().x - racket.GetPosition().x)) / racket.LenghtX;

}

// Sterowanie kolizj¹ Pi³ki z Blokiem
bool GameController::BlockAndBallCollisins(Block &block, Ball &ball)
{
	
	if(CheckeColision(block, ball))
	{
		block.DestroyBlock();
		const float leftDifference{ abs(ball.getSidePosition('R') - block.getSidePosition('L')) };
		const float rigthDifference{ abs(ball.getSidePosition('L') - block.getSidePosition('R')) };
		const float bottomDifference{ abs(ball.getSidePosition('T') - block.getSidePosition('B')) };
		const float topDifference{ abs(ball.getSidePosition('B') - block.getSidePosition('T')) };

		if(leftDifference > rigthDifference)
		{
			if(bottomDifference > topDifference)
			{
				if (rigthDifference > topDifference) ball.RevertVelocityVecctor(false, true);
				else if (rigthDifference < topDifference) ball.RevertVelocityVecctor(true, false);
				else if (rigthDifference == topDifference) ball.RevertVelocityVecctor(true, true);
			}
			else if (bottomDifference < topDifference)
			{
				if (rigthDifference > bottomDifference) ball.RevertVelocityVecctor(false, true);
				else if (rigthDifference < bottomDifference) ball.RevertVelocityVecctor(true, false);
				else if (rigthDifference == bottomDifference) ball.RevertVelocityVecctor(true, true);
			}
		}
		else
		{
			if (bottomDifference > topDifference)
			{
				if (leftDifference > topDifference) ball.RevertVelocityVecctor(false, true);
				else if (leftDifference < topDifference) ball.RevertVelocityVecctor(true, false);
				else if (leftDifference == topDifference) ball.RevertVelocityVecctor(true, true);
			}
			else if(bottomDifference < topDifference)
			{
				if (leftDifference > bottomDifference) ball.RevertVelocityVecctor(false, true);
				else if (leftDifference < bottomDifference) ball.RevertVelocityVecctor(true, false);
				else if (leftDifference == bottomDifference) ball.RevertVelocityVecctor(true, true);
			}
		}
		return true;
	}
	return false;
}

// Funkcja sk³adowa odpowiada za przebieg gry
void GameController::StartGame()
{
	Ball ball(windowSizeX / 2, windowSizeY / 2, windowSizeX, windowSizeY);
	const Rackets selectedRacket = SelectRacket();
	Racket* racket = nullptr;
	while (racket == nullptr)
	{
		switch (selectedRacket)
		{
		case LONG:
			racket = new RacketLong(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
			break;
		case FAST:
			racket = new RacketFast(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
			break;
		case STRONG:
			racket = new RacketStrong(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
			ball.AddBallVelocity(5.0f);
			break;
		case LUCKY:
			racket = new RacketLucky(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
			ball.AddBallVelocity(3.0f);
			break;
		case SUMMONER:
			racket = new RacketSummoner(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
			ball.AddBallVelocity(2.0f);
			break;
		case MASTER:
			racket = new RacketMaster(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
			ball.AddBallVelocity(5.0f);
			break;
		default:
			racket = new RacketLong(windowSizeX / 2, windowSizeY - 20, windowSizeX, windowSizeY, racketWidth, racketHeight);
		}
	}

	racket->SetApperance();
	vector<Block> blocks;
	bool pom = false;
	int points = 0, coins = 0, maxPoints = 60;

	srand(time(nullptr));
	const unsigned int amountOfBlockInOY = 7;
	for (int i = frameSize + blockWidth / 2; i <= windowSizeX - frameSize - blockWidth / 2; i += blockWidth + separatingSpace)
	{
		for (int j = frameSize + blockHeight / 2, k = 0; j <= windowSizeY - frameSize - blockHeight / 2 && k < amountOfBlockInOY; j += blockHeight + separatingSpace, k++)
		{
			blocks.emplace_back(i, j, window.getSize().x, window.getSize().y, blockWidth, blockHeight, rand() % 4);
			maxPoints++;
		}
	}

	Texture texture1;
	Texture texture2;
	Texture texture3;
	Texture texture4;
	texture1.loadFromFile("Blocks/Block1.png");
	texture2.loadFromFile("Blocks/Block2.png");
	texture3.loadFromFile("Blocks/Block3.png");
	texture4.loadFromFile("Blocks/Block4.png");

	for (auto& block : blocks)
	{
		switch (block.CheckType())
		{
		case 0:
			block.sprite.setTexture(texture1);
			break;
		case 1:
			block.sprite.setTexture(texture2);
			break;
		case 2:
			block.sprite.setTexture(texture3);
			break;
		case 3:
			block.sprite.setTexture(texture4);
			break;
		}
		block.sprite.setPosition(block.rectangleShape.getPosition());
		block.sprite.setOrigin(block.rectangleShape.getOrigin());
	}
	window.setFramerateLimit(60);
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			else if (event.type == Event::KeyReleased)
			{
				if(event.key.code == Keyboard::Escape)
				{
					gameStatus = MENU;
					loop = false;
				}
			}

		}

		ball.Update();
		racket->Update();
		BallAndRacketCollisions(*racket, ball);

		pom = false;
		for (auto& block : blocks)
		{
			if (block.CheckStatus())
			{
				pom = true;
				if (BlockAndBallCollisins(block, ball))
				{

					break;
				}
			}
		}
		window.clear();
		if(pom)
		{
			DrawFrame(ball, racket, blocks);
		}
		else
		{
			for (auto& block : blocks)
			{
				if (!block.CheckStatus()) points++;
			}
			loop = false;
			gameStatus = GAMESUMATION;
			OpenGameSumation(WIN, points, points/5);
		}
		if (ball.GetPosition().y >= racket->getSidePosition('B'))
		{
			for (auto& block : blocks)
			{
				if (!block.CheckStatus()) points++;
			}
			loop = false;
			gameStatus = GAMESUMATION;
			OpenGameSumation(LOSE, points, points/10);
		}
	}
}

// Funkcja sk³adowa wybierajaca paletke
Rackets GameController::SelectRacket()
{
	ChoseRacket* menu = new ChoseRacket(window.getSize().x, window.getSize().y, defaultFont, MENU);
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event) && loop)
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu->MoveUp();
					break;
				case Keyboard::Down:
					menu->MoveDown();
					break;
				case Keyboard::Return:
					if (data->CheckEquipment((Rackets)menu->GetOptionNumber()))
					{
					if (menu->GetOptionNumber() == 0) return LONG;
					if (menu->GetOptionNumber() == 1) return FAST;
					if (menu->GetOptionNumber() == 2) return STRONG;
					if (menu->GetOptionNumber() == 3) return LUCKY;
					if (menu->GetOptionNumber() == 4) return SUMMONER;
					if (menu->GetOptionNumber() == 5) return MASTER;
					if (menu->GetOptionNumber() == 6) return DEFAULT;
					}	
					break;
				case Keyboard::Escape:
					return DEFAULT;
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		if (menu != nullptr) menu->draw(window);
		window.display();
	}
	delete menu;
	menu = nullptr;
	return DEFAULT;
}

// Funkcja pokazuje 10 najlepszych
void GameController::OpenStats()
{
	Text texts[10];
	for(int i=0 ; i<10 ; i++)
	{
		texts[i].setString(std::to_string(data->GetStat(i)));
		texts[i].setFillColor(Color::White);
		texts[i].setFont(defaultFont);
		texts[i].setCharacterSize(30);
		texts[i].setPosition(50.0f, 30.0f + i * 40);
	}
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event) && loop)
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Escape:
					gameStatus = MENU;
					loop = false;
					break;
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		for(auto text : texts) window.draw(text);
		window.display();
	}
}

// Funkcja sk³adowa rysuje i wyœwitla na ekranie elementy gry
void GameController::DrawFrame(Ball ball, Racket* racket, vector<Block> blocks)
{
	window.draw(ball);
	window.draw(*racket);
	for (auto& block : blocks)
	{
		if (block.CheckStatus())
		{
			window.draw(block.sprite);
		}
	}
	window.display();
}

/////////////////////////////////////////////////////////////////////////////////

// Funkcja sk³adowa obs³uguje slkep
void GameController::OpenShop()
{
	Text infoTop;
	infoTop.setString("ENTER - buy racket,   ESC - back to menu,   |   Coins: " + std::to_string(data->ChechAmountOfCoins()) );
	infoTop.setFillColor(Color::White);
	infoTop.setCharacterSize(10);
	infoTop.setPosition(5.f, 5.f);
	infoTop.setFont(defaultFont);

	Shop* shop = new Shop(window.getSize().x, window.getSize().y, defaultFont, SHOP);
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event) && loop)
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					shop->MoveUp();
					break;
				case Keyboard::Down:
					shop->MoveDown();
					break;
				case Keyboard::Return:
					if (shop->GetOptionNumber() == 0) data->AddToEquipment(LONG);
					else if (shop->GetOptionNumber() == 1) data->AddToEquipment(FAST);
					else if (shop->GetOptionNumber() == 2) data->AddToEquipment(STRONG);
					else if (shop->GetOptionNumber() == 3) data->AddToEquipment(LUCKY);
					else if (shop->GetOptionNumber() == 4) data->AddToEquipment(SUMMONER);
					else if (shop->GetOptionNumber() == 5) data->AddToEquipment(MASTER);
					infoTop.setString("ENTER - buy racket,   ESC - back to menu,   |   Coins: " + std::to_string(data->ChechAmountOfCoins()));
					break;
				case Keyboard::Escape:
					gameStatus = MENU;
					loop = false;
					break;	
				}
				break;

			case Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		if (shop != nullptr) shop->draw(window);
		window.draw(infoTop);
		window.display();
	}
	delete shop;
	shop = nullptr;
}

// Funkcja sk³adowa obs³uguje opcje w menu
void GameController::OpenOptions()
{
	Options* options = new Options(window.getSize().x, window.getSize().y, defaultFont, SHOP);
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event) && loop)
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					options->MoveUp();
					break;
				case Keyboard::Down:
					options->MoveDown();
					break;
				case Keyboard::Return:
					if (options->GetOptionNumber() == 0) 
					{
						data->LoadEqFromFile();
						data->LoadStatFromFile();
					}
					else if(options->GetOptionNumber() == 1) 
					{
						data->SaveEqToFile();
						data->SaveStatToFile();
					}
					else if(options->GetOptionNumber() == 2) data->SetToDefault();
					else if (options->GetOptionNumber() == 3) data->AddCoins(10000);
					loop = false;
					break;
				case Keyboard::Escape:
					gameStatus = MENU;
					loop = false;
					break;
				}
				break;

			case Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		if (options != nullptr) options->draw(window);
		window.display();
	}
	delete options;
	options = nullptr;
}

// Funkcja sk³adowa obs³uguj¹ca podsumowanie gry
void GameController::OpenGameSumation(GameSolution gameSolution = WIN, int points = 0, int coins = 0)
{
	Text texts[5];
	Color color;

	data->AddPoints(points);
	data->AddCoins(coins);
	data->AddStat(points);
	data->SaveStatToFile();
	data->SaveEqToFile();

	if(gameSolution == WIN)
	{
		color = Color::Green;
		texts[0].setString("YOU WIN :D !");
	}
	else if(gameSolution == LOSE)
	{
		color = Color::Red;
		texts[0].setString("GAME OVER :'(");
	}
	
	for (int i = 0; i < 5; i++)
	{
		texts[i].setFont(defaultFont);
		if (i != 0) texts[i].setFillColor(Color::White);
		else texts[i].setFillColor(color);
		if(i != 0) texts[i].setCharacterSize(25);
		else texts[i].setCharacterSize(50);
		if(i != 0) texts[i].setPosition(50.f, i * (window.getSize().y / 7) + 100);
		else texts[0].setPosition(window.getSize().x / 2 - 350, 50);
	}

	texts[1].setString("YOU EARN");
	texts[2].setString("POINTS:  " + to_string(points) + "      TOTAL POINTS:  " + std::to_string(data->ChechAmountOfPoints()) + " PUNKTOW");
	texts[3].setString("COINS:  " + to_string(coins) +   "      TOTAL COINS:  " + std::to_string(data->ChechAmountOfCoins()) + " MONET");
	texts[4].setString("ECS - Back to menu");

	window.setFramerateLimit(30);
	
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event) && loop)
		{
			window.clear();
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Escape:
					loop = false;
					break;
				case Event::Closed:
					window.close();
					break;
				}
			}
			for (auto& text : texts)
			{
				window.draw(text);
			}
			window.display();
		}
	}
	gameStatus = MENU;
}

// Funkcja sk³adowa otwieraj¹ca Menu
void GameController::OpenMenu()
{
	MainMenu* menu = new MainMenu(window.getSize().x, window.getSize().y, defaultFont, MENU);
	bool loop = true;
	while (window.isOpen() && loop)
	{
		Event event;
		while (window.pollEvent(event) && loop)
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu->MoveUp();
					break;
				case Keyboard::Down:
					menu->MoveDown();				
					break;
				case Keyboard::Return:
					if(menu->GetOptionNumber() == 0) gameStatus = GAME;
					else if (menu->GetOptionNumber() == 1) gameStatus = SHOP;
					else if (menu->GetOptionNumber() == 2) gameStatus = OPTIONS;
					else if (menu->GetOptionNumber() == 3) gameStatus = STATS;
					else if (menu->GetOptionNumber() == 4) gameStatus = EXIT;
					loop = false;
					break;
				case Keyboard::Escape:
					gameStatus = EXIT;
					loop = false;
					break;
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		if (menu != nullptr) menu->draw(window);
		window.display();
	}
	delete menu;
	menu = nullptr;
}