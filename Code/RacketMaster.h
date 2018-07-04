#pragma once
#include "Racket.h"

class RacketMaster : public Racket
{
public:
	RacketMaster(int x, int y, int SizeX, int SizeY, int LenghtX, int LenghtY);
	~RacketMaster() = default;
	void SetApperance() override;
};

