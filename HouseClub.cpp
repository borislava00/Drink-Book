#include "HouseClub.h"

HouseClub::HouseClub() :HouseClub("Unknown", 0, 0,0)
{
	this->count = 0;
	this->DJs = 0;
}
HouseClub::HouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int DJs) : ClubBase(name, whiskeyPrice, vodkaPrice, 2, 10)
{
	if (vodkaPrice >= 30)
	{
		this->vodkaPrice = vodkaPrice;
	}
	else
	{
		std::cout << "Vodka is too cheap. Must be >= 20!" << '\n';
	}
	if (whiskeyPrice >= 40)
	{
		this->whiskeyPrice = whiskeyPrice;
	}
	else
	{
		std::cout << "Whiskey is too cheap. Must be >= 35!" << '\n';
	}
	this->count = count;
}

bool HouseClub::addToHouseClub(User& user)
{
	int budget = user.getBudget();
	if (user.getAge() < 18)
	{
		budget -= 20;
	}
	int sum = user.getVodkaCount() * vodkaPrice + user.getWhiskeyCount() * whiskeyPrice;

	if (budget - sum < 0)
	{
		std::cout << "Not enough cash!" << '\n';
		return false;
	}
	if (strcmp(user.getMusic(), "Rock") == 0 || strcmp(user.getMusic(), "House") == 0  || strcmp(user.getMusic(), "Everything") == 0)
	{
		add(user);
		return true;
	}
	std::cout << "Will not fit in this club!" << '\n';
	return false;
}
char* HouseClub::getClubName()
{
	return this->clubName;
}
int HouseClub::getID()
{
	return this->ID;
}
void HouseClub::add(User& currentUser)
{
	if (count == capacity)
	{
		resize();
	}
	users[count++] = currentUser;
}
void HouseClub::printUser()
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << users[i].getName() << " " << users[i].getAge() << " " << users[i].getBudget() << " " << '\n';
	}
}
ClubBase* HouseClub::clone()
{
	HouseClub* newHouseClub = new HouseClub(*this);
	return newHouseClub;
}
void HouseClub::resize()
{
	User* temp = new User[capacity * 2];
	capacity *= 2;
	for (int i = 0; i < count; i++)
		temp[i] = users[i];
	delete[] users;
	users = temp;
}
void HouseClub::remove(const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if ((strcmp(users[i].getName(), name) == 0))
		{
			users[i] = User();
			count--;
			std::cout << name << " removed from the club!\n";
			return;
		}
	}
	std::cout << "No " << name << " in this club!\n";
}