#include "Vec.h"

int
main(int argc, char const *argv[])
{
	Vec<string> v{"11", "22", "4", "5"};
	v.emplace_back("haha");

	for (auto i : v) {
		cout << i << endl;
	}

	return 0;
}