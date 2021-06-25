
class User
{
	private:
		char* name;
		int age, budget, whiskeyCount, vodkaCount;
		char* music;

		void CopyFrom(const User& other);
		void Free();
	public:
		User();
		User(const char* name, int age, int budget, int whiskeyCount, int vodkaCount, const char* music);
		User(const User& other);
		User& operator=(const User& other);
		~User();

		void printUser();
		int getAge();
		int getBudget();
		int getWhiskeyCount();
		int getVodkaCount();
		const char* getName();
		const char* getMusic();
};

