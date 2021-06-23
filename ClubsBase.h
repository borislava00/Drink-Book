#include<iostream>
#include "User.h"


class ClubBase
{
protected:
	User* users;
	char* clubName;
	int whiskeyPrice, vodkaPrice, ID, capacity;

private:
	void CopyFrom(const ClubBase& other);
	void Free();
public:
	ClubBase();
	ClubBase(const char* clubName, int whiskeyPrice, int vodkaPrice, int ID, int capacity);
	ClubBase& operator=(const ClubBase& other);
	ClubBase(const ClubBase& other);
	virtual ~ClubBase();

	virtual bool addToFolkClub(User& user) { return true; }
	virtual bool addToHouseClub(User& user) { return true; }
	virtual bool addToRockClub(User& user) { return true; }
	virtual char* getClubName() = 0;
	virtual int getID() = 0;
	virtual void add(User& user) = 0;
	virtual void printUser() = 0;
	virtual ClubBase* clone() = 0;
	virtual void remove(const char* name) = 0;
};

void ClubBase::CopyFrom(const ClubBase& other)
{
	this->clubName = new char[strlen(other.clubName) + 1];
	strcpy(clubName, other.clubName);
	whiskeyPrice = other.whiskeyPrice;
	vodkaPrice = other.vodkaPrice;
	ID = other.ID;

	capacity = other.capacity;
	this->users = new User[other.capacity];
}
void ClubBase::Free()
{
	delete[] clubName;
	delete[] users;
	whiskeyPrice = vodkaPrice = ID  = capacity = 0;
}
ClubBase::ClubBase():ClubBase("Unkown",0,0,0,0){}
ClubBase::ClubBase(const char* clubName, int whiskeyPrice, int vodkaPrice, int ID, int capacity)
{
	this->clubName = new char[strlen(clubName) + 1];
	strcpy(this->clubName, clubName);
	this->whiskeyPrice = whiskeyPrice;
	this->vodkaPrice = vodkaPrice;
	this->capacity = capacity;
	this->ID = ID;
	this->users = new User[this->capacity];
}
ClubBase& ClubBase::operator=(const ClubBase& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
ClubBase::ClubBase(const ClubBase& other)
{
	CopyFrom(other);
}
ClubBase::~ClubBase()
{
	Free();
}


class FolkClub:public ClubBase
{
private:
	char* performer;
	int count;

	void CopyFrom(const FolkClub& other);
	void Free();
public:
	FolkClub();
	FolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* performer);
	FolkClub& operator=(const FolkClub& other);
	FolkClub(const FolkClub& other);
	~FolkClub();

	bool addToFolkClub(User& user)override;
	char* getClubName()override;
	int getID()override;
	void add(User& currentUser)override;
	ClubBase* clone()override;
	void remove(const char* name)override;

	void printUser();

};
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

/******************************************************/
class HouseClub :public ClubBase
{
private:
	int DJs,count;

	void resize();
public:
	HouseClub();
	HouseClub(const char* clubName, int whiskeyPrice, int vodkaPrice, int djs);

	bool addToHouseClub(User& user)override;
	char* getClubName()override;
	int getID()override;

	void add(User& user);
	ClubBase* clone()override;
	void printUser()override;
	void remove(const char* name)override;
};

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
/*********************************************************************************/
class RockClub :public ClubBase
{
private:
	int count;
public:
	RockClub();
	RockClub(const char* clubName, int whiskeyPrice, int vodkaPrice);

	bool addToRockClub(User& user)override;
	char* getClubName()override;
	int getID()override;
	void add(User& user);

	ClubBase* clone()override;
	void printUser()override;
	void remove(const char* name)override;
};
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