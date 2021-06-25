#include "ClubsBase.h"

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