#pragma once
#include "Racket.h"

class RacketFast : public Racket
{
public:
	RacketFast(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	~RacketFast() = default;
	void SetApperance() override;
};

