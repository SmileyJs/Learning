#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	Date() = default;
	Date(const string&);

	void print();

private:
	unsigned year = 0;
	unsigned month = 0;
	unsigned day = 0;
};

int
main(int argc, char const *argv[])
{
	Date d1("December 24, 1990");
	d1.print();
	Date d2("12/24/1990");
	d2.print();
	Date d3("Dec 24 1990"); 
	d3.print();
	Date d4;
	d4.print();

	return 0;
}

void Date::print()
{
	cout << "year: " << year << "\n" << "month: " << month <<  "\n" << "day: " << day << endl;
}

Date::Date(const string &s)
{
	string::size_type pos = 0;
	string number("0123456789");

	if (string::npos != s.find_first_of("/")) {
		month = stoi(s.substr(0));
		day = stoi(s.substr(s.find_first_of("/") + 1));
		year = stoi(s.substr(s.find_last_of("/") + 1));
	}
	else {
		if (string::npos != s.find("Jan")) month = 1;
		if (string::npos != s.find("Feb")) month = 2;
		if (string::npos != s.find("Mar")) month = 3;
		if (string::npos != s.find("Api")) month = 4;
		if (string::npos != s.find("May")) month = 5;
		if (string::npos != s.find("Jun")) month = 6;
		if (string::npos != s.find("Jul")) month = 7;
		if (string::npos != s.find("Aug")) month = 8;
		if (string::npos != s.find("Sep")) month = 9;
		if (string::npos != s.find("Oct")) month = 10;
		if (string::npos != s.find("Nov")) month = 11;
		if (string::npos != s.find("Dec")) month = 12;

		day = stoi(s.substr(s.find_first_of(number)));
		year = stoi(s.substr(s.find_last_of(" ") + 1));
 	}


}