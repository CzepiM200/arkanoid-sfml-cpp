#pragma once
#include "Racket.h"

class RacketLong : public Racket
{
public:
	RacketLong(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	~RacketLong() = default;
	void SetApperance() override;
};

