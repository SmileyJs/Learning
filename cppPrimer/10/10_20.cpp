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
	
	auto n = count_if(vec.begin(), vec.end(), [argv](const std::string &s) -> bool 
		{ return s.size() > atoi(argv[1]); } );

	std::cout << "there are " << n << " words of length " << argv[1] << " or longer." << std::endl;

	return 0;
}