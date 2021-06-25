#include "FolkClub.h"

void FolkClub::CopyFrom(const FolkClub& other)
{
	this->performer = new char[strlen(other.performer) + 1];
	strcpy(performer, other.performer);
}
void FolkClub::Free()
{
	delete[] performer;
}
FolkClub::FolkClub():FolkClub("Unknown",0,0,"Unknown")
{
	this->count = 0;
}
FolkClub::FolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* performer) : ClubBase(name, whiskeyPrice, vodkaPrice,1,70)
{
	if (vodkaPrice >= 20)
	{
		this->vodkaPrice = vodkaPrice;
	}
	else
	{
		std::cout << "Vodka is too cheap. Must be >= 20!" << '\n';
	}
	if (whiskeyPrice >= 35)
	{
		this->whiskeyPrice = whiskeyPrice;
	}
	else
	{
		std::cout << "Whiskey is too cheap. Must be >= 35!" << '\n';
	}
	this->performer = new char[strlen(performer) + 1];
	strcpy(this->performer, performer);
	this->count = count;
}
FolkClub& FolkClub:: operator=(const FolkClub& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
FolkClub::FolkClub(const FolkClub& other)
{
	CopyFrom(other);
}
FolkClub::~FolkClub()
{
	Free();
}
bool FolkClub::addToFolkClub(User& user)
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
	if (strcmp(user.getMusic(), "Folk") == 0 || strcmp(user.getMusic(), "House") == 0  || strcmp(user.getMusic(), "Everything") == 0)
	{
		add(user);
		return true;
	}
	std::cout << "Will not fit in this club!" << '\n';
	return false;
}
char* FolkClub::getClubName()
{
	return this->clubName;
}
int FolkClub::getID()
{
	return this->ID;
}
void FolkClub::add(User& currentUser)
{
	if (count == capacity)
	{
		std::cout << "No space in the club!" << '\n';
		return;
	}
	users[count++] = currentUser;
}
void FolkClub::printUser()
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << users[i].getName() << " " << users[i].getAge() << " " << users[i].getBudget() << " " << '\n';
	}
}
ClubBase* FolkClub::clone()
{
	FolkClub* newFolkClub = new FolkClub(*this);
	return newFolkClub;
}
void FolkClub::remove(const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if ((strcmp(users[i].getName(), name) == 0)) {
			users[i] = User();

			for (int j = i; j < count - 1; j++)
			{
				users[j] = users[j + 1];
			}
			count--;
			std::cout << name << " removed from the club!\n";
			return;
		}
	}
	std::cout << "No " << name << " in this club!\n";
}
