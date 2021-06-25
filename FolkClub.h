#include "ClubsBase.h"

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