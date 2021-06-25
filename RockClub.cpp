#include "RockClub.h"

RockClub::RockClub()
{
	this->count = 0;
}
RockClub::RockClub(const char* clubName, int whiskeyPrice, int vodkaPrice) :ClubBase(clubName, whiskeyPrice, vodkaPrice,3,30)
{
	if (vodkaPrice >= 40)
	{
		this->vodkaPrice = vodkaPrice;
	}
	else 
	{
		std::cout << "Vodka is too cheap. Must be >= 40!" << '\n';
	}

	if (whiskeyPrice >= 30)
	{
		this->whiskeyPrice = whiskeyPrice;
	}
	else
	{
		std::cout << "Whiskey is too cheap. Must be >= 30!" << '\n';
	}
	this->count = count;
}
bool RockClub::addToRockClub(User& user)
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
	if (strcmp(user.getMusic(), "Rock") == 0 || strcmp(user.getMusic(), "Folk") == 0 || strcmp(user.getMusic(), "Everything") == 0)
	{
		add(user);
		return true;
	}
	std::cout << "Will not fit in this club!" << '\n';
	return false;
}
char* RockClub::getClubName() 
{
	return this->clubName;
}
int RockClub::getID()
{
	return this->ID;
}
void RockClub::add(User& user)
{
	if (count == capacity)
	{
		std::cout << "No space in the club!" << '\n';
		return;
	}
	users[count++] = user;
}
void RockClub::printUser()
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << users[i].getName() << " " << users[i].getAge() << " " << users[i].getBudget() << " " << '\n';
	}
}
ClubBase* RockClub::clone()
{
	RockClub* newRockClub = new RockClub(*this);
	return newRockClub;
}
void RockClub::remove(const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if ((strcmp(users[i].getName(), name) == 0))
		{
			users[i] = User();
			std::cout << name << " removed from the club!\n";
			count--;
			return;
		}
	}
	std::cout << "No " << name << " in this club!\n";
}