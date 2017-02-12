#include <iostream>
#include <string>

using namespace std;

const string &format(string &s, const string &pre, const string &post) 
{
	s.insert(s.begin(), pre.begin(), pre.end());
	s.append(post);
	
	return s;
}

int
main(int argc, char const *argv[])
{
	string str("W.Wiliams");

	cout << format(str, "Mr.", "III") << endl;

	return 0;
}