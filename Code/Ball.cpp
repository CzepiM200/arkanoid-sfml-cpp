#include "Ball.h"

Ball::Ball(int x, int y, int SizeX, int SizeY)
{
	this->windowSizeX = SizeX;
	this->windowSizeY = SizeY;
	circle.setPosition(x, y);	// Ustawiamy pozycjê kulki
	circle.setRadius(this->lenghtOfBallRay); // ustawiamy d³ugoœæ jej promienia
	circle.setFillColor(Color::White); // Ustawiamy kolor kulki
	circle.setOrigin(this->lenghtOfBallRay, this->lenghtOfBallRay); // Ustawianie œrodka kulki
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->circle, state);
}

void Ball::Update()
{
	circle.move(this->ballVelocityVector);
	if (getSidePosition('L') <= 0)
	{
		ballVelocityVector.x *= -1;
	}
	else if (getSidePosition('R') >= windowSizeX)
	{
		ballVelocityVector.x *= -1;
	}
	else if (getSidePosition('T') <= 0)
	{
		ballVelocityVector.y *= -1;
	}
	else if (getSidePosition('B') >= windowSizeY)
	{
		ballVelocityVector.y *= -1;
	}
}

// Funkcja sk³adowa zwraca pozycjê jednej z 4 krawêdzi
float Ball::getSidePosition(char side) const
{
	if (side == 'R') return this->circle.getPosition().x + circle.getRadius();
	else if (side == 'L') return this->circle.getPosition().x - circle.getRadius();
	else if (side == 'T') return this->circle.getPosition().y - circle.getRadius();
	else if (side == 'B') return this->circle.getPosition().y + circle.getRadius();
	else throw std::exception("Litera z poza zakresu");
}

// Funkcja sk³adowa zmienia kierunek vektora pi³ki
void Ball::ChangeVelocityVector(short x, short y) 
{
	if (x < 0) this->ballVelocityVector.x = -ballVelocity;
	else if (x > 0) this->ballVelocityVector.x = ballVelocity;
	if (y < 0) this->ballVelocityVector.y = ballVelocity;
	else if (y > 0) this->ballVelocityVector.y = -ballVelocity;
}

// Metoda zmiania kierunki poruszania siê w plaszczyznie x i y
void Ball::RevertVelocityVecctor(bool x, bool y)
{
	if (x)   this->ballVelocityVector.x *= -1;
	if (y)	this->ballVelocityVector.y *= -1;
}

// Funkcja sk³adowa zwraca pozycje pilki
Vector2f Ball::GetPosition() const
{
	return this->circle.getPosition();
}

// Funkcja sk³adowa przyspiesza pi³kê
void Ball::AddBallVelocity(int i)
{
	if(i > 0)
	{
		ballVelocity += i;
		ballVelocityVector.x += i;
		ballVelocityVector.y += i;
	}	
}

//zmiana vektorow w plaszczyznach x,y wstawiac wartosci od (0;1)
void Ball::ChangeVelocityVector(float x)
{
	this->ballVelocityVector.x = ballVelocity * x;
}
