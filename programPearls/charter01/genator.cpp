#include <iostream>
#include <fstream>

#include <stdlib.h>

int
main(int argc, char const *argv[])
{
	std::fstream file("numbers.txt");

	if (!file)
		std::cout << "file open failed!" << std::endl;

	int i, j = 0;
	for (i = 0; i != 1000; ++i) {
		 do {
		 	j = random();
		 } 
		 while (j > 1000000);

		 file << j << std::endl;
	}
	
	return 0;
}