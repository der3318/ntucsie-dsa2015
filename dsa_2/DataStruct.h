#include <vector>

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

		void find_properties(int&, int&, int&, int&, int&);
};

int cmp_line(const void*, const void*);
