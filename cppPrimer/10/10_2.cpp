#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<string> lst{"haha", "what", "numeric", "===", "haha"};

	auto i = count(lst.begin(), lst.end(), "haha");

	cout << "haha appears " << i << " times" << endl;

	return 0;
}