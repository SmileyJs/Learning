#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cout << "argument error!" << std::endl;
		return -1;
	}

	std::vector<std::string> vec{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};

	sort(vec.begin(), vec.end());

	auto flag = unique(vec.begin(), vec.end());

	vec.erase(flag, vec.end());

	auto new_end = stable_partition(vec.begin(), vec.end(), [argv](const std::string &s) -> bool 
		{ return s.size() > atoi(argv[1]); });

	std::cout << "there are " << new_end - vec.begin() << " words of length " 
		<< argv[1] << " or longer." << std::endl; 

	for (auto i = vec.begin(); i != new_end; ++i) {
		std::cout << *i << std::endl;
	}

	return 0;
}