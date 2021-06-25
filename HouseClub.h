#include "ClubsBase.h"

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