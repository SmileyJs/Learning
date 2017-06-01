#include <iostream>
#include <vector>

using namespace std;

class PrintString
{
public:
	// PrintString();
	// ~PrintString();
	
	const string operator()(istream&);
};

const string
PrintString::operator()(istream& is)
{
	string str("");

	if (is) {
		getline(is, str);
	}

	return str;
}

int
main(int argc, char const *argv[])
{
	PrintString a;

	vector<string> v;
	
	for (int i = 5; i > 0; --i) {
		string str = a(cin);
		if (!str.empty())
			v.push_back(str);		
	}	

	for (auto i : v) {
		cout << i << endl;
	}

	return 0;
}