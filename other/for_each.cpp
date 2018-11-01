#include <iostream>
#include <algorithm>
#include <vector>

void print(int a)
{
	std::cout << a << std::endl; 
}

bool cmp(int a, int b)
{
	return a > b;
}

int
main(int argc, char const *argv[])
{
	std::vector<int> vecInt = {1, 2, 3, 4, 5};

	for_each(vecInt.begin(), vecInt.end(), print);

	sort(vecInt.begin(), vecInt.end(), cmp);

	int i = 10;

	for_each(vecInt.begin(), vecInt.end(), [&i](int &n) {
		std::cout << n + i << std::endl;
	});

	sort(vecInt.begin(), vecInt.end(), [](int &a, int &b)->bool {
		return a < b;
	});

	for_each(vecInt.begin(), vecInt.end(), print);

	auto it = find_if(vecInt.begin(), vecInt.end(), [](int a) {
		return a == 3;
	});

	vecInt.erase(it);

	for(int i : vecInt) {
		std::cout << i << std::endl;
	}

	return 0;
}