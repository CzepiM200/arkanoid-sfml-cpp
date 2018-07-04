#pragma once
#include "Racket.h"

class RacketSummoner : public Racket
{
public:
	RacketSummoner(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	~RacketSummoner() = default;
	void SetApperance() override;
};

