#include "UserData.h"
#include <cstdlib>

using namespace std;

UserData::UserData()
{
	LoadEqFromFile();
	LoadStatFromFile();
	equipment[0] = true;
}

bool UserData::RemoveCoins(int amount)
{
	try
	{
		coins -= amount;
		return true;
	}
	catch (exception)
	{
		return false;
	}
}

bool UserData::AddCoins(int amount)
{
	try
	{
		coins += amount;
		return true;
	}
	catch(exception)
	{
		return false;
	}
}

int UserData::ChechAmountOfCoins() const
{
	return coins;
}

bool UserData::AddPoints(int amount)
{
	try
	{
		points += amount;
		return true;
	}
	catch(exception)
	{
		return false;
	}
}

int UserData::ChechAmountOfPoints() const
{
	return points;
}

bool UserData::SaveEqToFile()
{
	string data[8];
	fstream plik;
	plik.open("data.txt", ios::out  | ios::trunc);
	if (plik.good())
	{
		plik << points << endl;
		plik << coins << endl;
		for(auto eq : equipment)
		{
			if (eq) plik << "1" << endl;
			else plik << "0" << endl;
		}
		plik.close();
		return true;
	}
	return false;
}

bool UserData::LoadEqFromFile()
{
	string linia;
	fstream plik;
	string tab[8];
	int i = 0;
	plik.open("data.txt", ios::in);
	if (plik.good())
	{
		while (!plik.eof() && i<=7)
		{
			getline(plik, linia);
			tab[i] = linia;
			i++;
		}
		plik.close();
	}
	points = stoi(tab[0]);
	coins = stoi(tab[1]);
	for (int i = 0; i < 6; i++) equipment[i] = (stoi(tab[i + 2]));
	return true;
}

bool UserData::AddToEquipment(Rackets type)
{
	if(!CheckEquipment(type))
	switch (type)
	{
	case LONG:
		if(coins >= 10)
		{
			RemoveCoins(10);
			equipment[0] = true;
			return true;
		}
	case FAST:
		if (coins >= 20)
		{
			RemoveCoins(20);
			equipment[1] = true;
			return true;
		}
		break;
	case STRONG:
		if (coins >= 50)
		{
			RemoveCoins(50);
			equipment[2] = true;
			return true;
		}
	case LUCKY:
		if (coins >= 100)
		{
			RemoveCoins(100);
			equipment[3] = true;
			return true;
		}
	case SUMMONER:
		if (coins >= 200)
		{
			RemoveCoins(200);
			equipment[4] = true;
			return true;
		}
	case MASTER:
		if (coins >= 1000)
		{
			RemoveCoins(1000);
			equipment[5] = true;
			return true;
		}
	
	}
	return false;
}

bool UserData::CheckEquipment(Rackets type)
{
	switch (type)
	{
	case LONG:
		return equipment[0];
	case FAST:
		return equipment[1];
	case STRONG:
		return equipment[2];
	case LUCKY:
		return equipment[3];
	case SUMMONER:
		return equipment[4];
	case MASTER:
		return equipment[5];
	default:
		return false;
	}
}

void UserData::SetToDefault()
{
	for(int i=1 ; i<6 ; i++)
	{
		equipment[i] = false;
	}
	equipment[0] = true;
	coins = 100;
	points = 0;
	SaveEqToFile();
}

int UserData::GetStat(int i)
{
	if (i >= 0 && i <= 9) return stats[i];
	else throw exception("Blad w odczycie statystyk");
}

void UserData::AddStat(int points)
{
	if (points < 0) throw exception("Punkty mniejsze od zera !");
	int i = 0;
	while (i < 10)
	{
		if (points > stats[i])
		{
			stats[i] = points;
			break;
		}
		i++;
	}
}

bool UserData::SaveStatToFile()
{
	fstream plik;
	plik.open("stats.txt", ios::out | ios::trunc);
	if (plik.good())
	{
		for (auto stat : stats)
		{
			plik << stat << endl;
		}
		plik.close();
		return true;
	}
	return false;
}

bool UserData::LoadStatFromFile()
{
	try
	{
		string line;
		fstream plik;
		int i = 0;
		plik.open("stats.txt", ios::in);
		if (plik.good())
		{
			while (!plik.eof() && i < 10)
			{
				getline(plik, line);
				if (line == "") stats[i] = 0;
				else stats[i] = stoi(line);
				i++;
			}
			plik.close();
		}
		return true;
	}
	catch (...)
	{
		for(auto stat : stats)
		{
			stat = 0;
		}
		return false;
	}
}