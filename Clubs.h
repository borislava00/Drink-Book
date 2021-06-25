#include "ClubsBase.h"
#include "FolkClub.h"
#include "HouseClub.h"
#include "RockClub.h"

class Clubs
{
private:
	ClubBase** clubs;
	int count;
	int capacity;
	
	void resize();
	void add(ClubBase* currentClub);

	void Free();
	void CopyFrom(const Clubs& other);
public:
	Clubs();
	Clubs& operator=(const Clubs& other);
	Clubs(const Clubs& other);
	~Clubs();

	void addFolkClub(const char* clubName, int whisleyPrice, int vodkaPrice, const char* performer);
	void addHouseClub(const char* clubName, int whiskeyPrice, int vodkaPrice, int djs);
	void addRockClub(const char* clubName, int whiskeyPrice, int vodkaPrice);

	void print();

	void addToClub(User& user, const char* clubName);
	void removeFromClub(const char* name, const char* clubName);
};

void Clubs::resize()
{
	ClubBase** temp = new ClubBase*[capacity * 2];
	for (int i = 0; i < count; i++)
	{
		temp[i] = clubs[i];
	}
	delete[] clubs;
	capacity *= 2;
}

void Clubs::add(ClubBase* currentClub)
{
	if (count == capacity)
	{
		resize();
	}
	else 
	{
		clubs[this->count] = currentClub;
		this->count++;
	}
}

void Clubs::Free()
{
	for (int i = 0; i < this->count; i++)
	{
		delete clubs[i];
	}
	delete[] clubs;
	count = capacity = 0;  
}

void Clubs::CopyFrom(const Clubs& other)
{
	clubs = new ClubBase * [other.count];
	count = other.count;
	capacity = other.capacity;
	for (int i = 0; i < other.count; i++)
	{
		clubs[i] = other.clubs[i]->clone();
	}
}

Clubs::Clubs()
{
	capacity = 10;
	count = 0;
	clubs = new ClubBase*[this->capacity];
}

Clubs& Clubs::operator=(const Clubs& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Clubs::Clubs(const Clubs& other)
{
	CopyFrom(other);
}

Clubs::~Clubs()
{
	Free();
}

void Clubs::addFolkClub(const char* clubName, int whisleyPrice, int vodkaPrice, const char* performer)
{
	FolkClub* currentClub = new FolkClub(clubName,whisleyPrice,vodkaPrice,performer);
	add(currentClub);
}

void Clubs::addHouseClub(const char* clubName, int whiskeyPrice, int vodkaPrice, int djs)
{
	HouseClub* currentClub = new HouseClub(clubName, whiskeyPrice, vodkaPrice, djs);
	add(currentClub);
}

void Clubs::addRockClub(const char* clubName, int whiskeyPrice, int vodkaPrice)
{
	RockClub* currentClub = new RockClub(clubName, whiskeyPrice, vodkaPrice);
	add(currentClub);
}

void Clubs::print()
{
	for (int i = 0; i < count; i++)
	{
		this->clubs[i]->printUser();
	}
}

void Clubs::addToClub(User& user, const char* clubName)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(clubName, clubs[i]->getClubName())==0)
		{
			if (clubs[i]->getID() == 1)
			{
				if (clubs[i]->addToFolkClub(user))
				{
					std::cout <<  "Added in the club!\n";
					return;
				}
			}
			else if (clubs[i]->getID() == 2)
			{
				if (clubs[i]->addToHouseClub(user))
				{
					std::cout << "Added in the club!\n";
					return;
				}
			}
			else if (clubs[i]->getID() == 3)
			{
				if (clubs[i]->addToRockClub(user))
				{
					std::cout << "Added in the club!\n";
					return;
				}
			}
			
		}
	}
}
void Clubs::removeFromClub(const char* name, const char* clubName)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(clubName, clubs[i]->getClubName()) == 0)
		{
			clubs[i]->remove(name);
			return;
		}
	}


}
