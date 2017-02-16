#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

void print(std::vector<std::string> &vec)
{
	for (auto i : vec) {
		std::cout << i << std::endl;
	}
}

void elimDup(std::vector<std::string> &vec)
{
	sort(vec.begin(), vec.end());

	auto new_end = unique(vec.begin(), vec.end());

	vec.erase(new_end, vec.end());
}

int main(int argc, char const *argv[])
{
	// 10_14
	// auto i = [] (int a, int b)->int	{ return a + b; };

	// 10_15
	// int i = 7;
	// auto j = [i] (int num) ->int { return num + i; };

	if (argc != 2) {
		std::cout << "argument error!" << std::endl;
		return -1;
	} 

	std::vector<std::string> vec{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};

	elimDup(vec);

	print(vec);

	stable_sort(vec.begin(), vec.end(), [](const std::string &s1, const std::string &s2) -> bool 
		{ return s1.size() < s2.size(); });

	print(vec);

	auto new_end = find_if(vec.begin(), vec.end(), [argv](const std::string &s) -> bool 
		{ return s.size() > atoi(argv[1]); });

	auto count = vec.end() - new_end;

	std::cout << "there are " << count << " words of length " 
		<< atoi(argv[1]) << " or longger." << std::endl; 

	for_each(new_end, vec.end(), [](const std::string &s){ std::cout << s << std::endl; });

	return 0;
}