#include "User.h"
#include <iostream>

void User::CopyFrom(const User& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	this->age = other.age;
	this->budget = other.budget;
	this->whiskeyCount = other.whiskeyCount;
	this->vodkaCount = other.vodkaCount;
	this->music = new char[strlen(other.music) + 1];
	strcpy(music, other.music);
}
void User::Free()
{
	delete[] name;
	age = budget = whiskeyCount = vodkaCount =0;
	delete[] music;
}
User::User() : User("Unkown",0,0,0, 0, "Unknown"){}
User::User(const char* name, int age, int budget, int whiskeyCount, int vodkaCount, const char* music)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->budget = budget;
	this->whiskeyCount = whiskeyCount;
	this->vodkaCount = vodkaCount;
	this->music = new char[strlen(music) + 1];
	strcpy(this->music,music);
}
User::User(const User& other)
{
	CopyFrom(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this; 
}
User::~User()
{
	Free();
}
void User::printUser()
{
	std::cout << name << " " << age << " "<<vodkaCount<<" " << whiskeyCount <<" " << music;
}
int User::getAge()
{
	return this->age;
}
int User::getBudget()
{
	return this-> budget;
}
int User::getWhiskeyCount()
{
	return this->whiskeyCount;
}
int User::getVodkaCount()
{
	return this->vodkaCount;
}
const char* User::getName()
{
	return this->name;
}
const char* User::getMusic()
{
	return this->music;
}