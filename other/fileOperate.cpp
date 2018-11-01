#include <iostream>
#include "cstdio"
#include <fstream>
#include <string>
#include <sstream>

int
main(int argc, char const *argv[])
{
	std::ofstream output("fileTest.txt", std::ofstream::app);

	if(!output) {
		std::cout << "file open error!" << std::endl;
		return -1;
	}

	std::string strIn;
	while(std::getline(std::cin, strIn)) {
		output << strIn << std::endl;
	}

	std::ifstream input("fileTest.txt");

	if (!input) {
		std::cout << "file open errpr!" << std::endl;
		return -1;
	}

	std::string sline;
	while(getline(input, sline)) {
		std::cout << sline << std::endl;
	}	

	return 0;
}