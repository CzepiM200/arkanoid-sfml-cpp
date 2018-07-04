#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RectangleGameObject.h"

using namespace sf;
using namespace std;

class Racket : public RectangleGameObject
{
public:
	virtual void SetApperance() = 0;


	Racket(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	Racket() = delete;
	~Racket() = default;
	void Update();
	Vector2f GetPosition() const;
protected:
	float racketVelocity{ 10.0f };

private:
	Vector2f racketVelocityVector{ racketVelocity, 0.0f };
};