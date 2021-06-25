#include <iostream>
#include <cstring>
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


