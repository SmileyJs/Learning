#include <iostream>
#include <algorithm>
#include <set>

int
main(int argc, char const *argv[])
{
	std::set<int> s;
	std::set<int>::iterator i;
	int j;

	while (std::cin >> j)
		s.insert(j);

	for (int a : s)
		std::cout << a << std::endl;

	return 0;
}