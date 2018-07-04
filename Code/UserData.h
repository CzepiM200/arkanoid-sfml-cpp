#pragma once
#include "Enums.h"
#include <fstream>
#include <conio.h>
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class UserData
{
public:
	UserData();
	~UserData() = default;

	bool RemoveCoins(int amount);
	bool AddCoins(int amount);
	int ChechAmountOfCoins() const;

	bool AddPoints(int amount);
	int ChechAmountOfPoints() const;

	bool SaveEqToFile(); 
	bool LoadEqFromFile(); 


	bool AddToEquipment(Rackets type);
	bool CheckEquipment(Rackets type);

	void SetToDefault();

	int GetStat(int i);
	void AddStat(int points);
	bool SaveStatToFile();
	bool LoadStatFromFile();

private:
	int coins{ 500 };
	int points{ 5000 };
	bool equipment[6] = {};
	int stats[10] = {};
};

