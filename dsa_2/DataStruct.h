#include <vector>

class Ans_Click
{
	public:
		int ad;
		int query;
};

class Line
{
	public:
		int click;
		int impression;
		char URL[21];
		int ad;
		int advertiser;
		int depth;
		int position;
		int query;
		int keyword;
		int title;
		int description;
		int user;
};

class User
{
	public:
		User();

		int line_start;
		int line_end;
};

class Ad
{
	public:
		Ad();

		std::vector<int> users;
};

class Data
{
	public:
		Data();
		~Data();

		Line *line;
		User *user;
		Ad *ad;

		void get(int&, int&, int&, int&, int&);
		void clicked(int&);
		void impressed(int&, int&);
		void profit(int&, double&);
};

int cmp(const void*, const void*);
