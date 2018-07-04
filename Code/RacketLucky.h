#pragma once
#include "Racket.h"

class RacketLucky : public Racket
{
public:
	RacketLucky(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	~RacketLucky() = default;
	void SetApperance() override;
};

