#include <forward_list>
#include <iostream>

using namespace std;

void
insertString(forward_list<string> &flst, const string &s1, const string &s2)
{
	auto pre = flst.cbefore_begin();

	for (auto i = flst.cbegin(); i != flst.cend(); ++i) {
		if (*i == s1) {
			flst.insert_after(i, s2);
			return;
		}

		pre = i;
	}

	flst.insert_after(pre, s2);
}

int
main(int argc, char const *argv[])
{
	forward_list<string> fList{"1", "2", "3", "4", "5"};

	if (3 != argc) {
		cout << "argument error! retry!" << endl;
		return -1;
	}

	insertString(fList, argv[1], argv[2]);

	for (auto i : fList) {
		cout << i << endl;
	}

	return 0;
}