
#include"Clubs.h"
#include <iostream>

int main()
{
	std::cout<<"Hello world";
	Clubs club;
	club.addFolkClub("Plaza", 30, 45, "Preslava");
	club.addRockClub("Underground", 40, 45);
	club.addHouseClub("Ultra", 35, 40, 2);

	User user("Stefan",19,100,1,1,"Folk");
	User user1("Petur", 25, 80, 0, 1, "Rock");
	User user2("Boris", 19, 120, 0, 1, "House");

	club.addToClub(user, "Underground");
	club.addToClub(user1, "Ultra");
	club.addToClub(user2, "Plaza");

	club.removeFromClub("Stefan", "Underground");
}
