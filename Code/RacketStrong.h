#pragma once
#include "Racket.h"

class RacketStrong : public Racket
{
public:
	RacketStrong(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	~RacketStrong() = default;
	void SetApperance() override;
};

