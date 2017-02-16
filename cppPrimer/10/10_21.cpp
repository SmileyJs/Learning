#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

int
main(int argc, char const *argv[])
{
	int i = 10;

	auto dec = [&i]() ->bool { 
		if (i != 0) {
			--i;
			return false;		
		} 
		else {
			return true;
		}
	};

	while (!dec()) {
		std::cout << i << std::endl;
	}

	return 0;
}