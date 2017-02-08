#include <iostream>
#include <forward_list>

using namespace std;

int
main(int argc, char const *argv[])
{
	forward_list<int> flst{0, 1, 2, 3, 4, 5};

	for (auto cur = flst.begin(), pre = flst.before_begin(); cur != flst.end();) {
		if (*cur%2) {
			cur = flst.insert_after(cur, *cur);
			advance(cur, 1);
			advance(pre, 2);
		}
		else {
			cur = flst.erase_after(pre);
		}
	}

	for (auto i : flst) {
		cout << i << endl;
	}

	return 0;
}