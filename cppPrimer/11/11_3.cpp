#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>

// using namespace std;
// it's better dont add namespace code when we need to  use c_type funtion(ispunct). otherwise, compile error.
//	candidate template ignored: couldn't infer template argument '_Predicate'
// for more infomation refer to http://stackoverflow.com/questions/20019636/c-count-if-function-couldnt-infer-template 

// stl-erase-remove-idiom

int
main(int argc, char const *argv[])
{
	std::map<std::string, size_t> word_count;
	std::string word;

	while (std::cin >> word) {
		for (auto &i : word) {
			i = tolower(i);
		}

		// stl erese remove idiom,
		// word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());


		// custom delete optation
		for (auto u = find_if(word.begin(), word.end(), ispunct); u != word.end(); u = find_if(word.begin(), word.end(), ispunct)) {
			word.erase(u);
		}

		word_count[word] ++;
	}

	for (auto &i : word_count) {
		std::cout << i.first << " occurs " << i.second << (i.second > 1 ? " times " : " time.") << std::endl;
	}

	return 0;
}