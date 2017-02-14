#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

bool compareSize(const std::string &str)
{
	return str.size() > 5;
}

int
main(int argc, char const *argv[])
{
	std::string s1("111111"), s2("222"), s3("3"), s4("44444444444"),
		s5("5555555555"), s6("66"), s7("77777777"), s8("8888"), s9("99999"); 	
	
	std::vector<std::string> vec{s1, s2, s3, s4, s5, s6, s7, s8, s9};

	auto new_end = partition(vec.begin(), vec.end(), compareSize);

	for (auto i : vec) {
		std::cout << i << std::endl;
	}

	vec.erase(new_end, vec.end());

	for (auto i : vec) {
		std::cout << i << std::endl;
	}

	return 0;
}