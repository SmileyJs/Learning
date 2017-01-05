#include <iostream>

using std::istream;

istream& read(istream &);

int
main(int argc, char const *argv[])
{
	istream &is = read(std::cin);

	std::cout << is.rdstate() << std::endl;
	return 0;
}

istream
&read(istream &is) {
	std::string str;

	while(is >> str) {
		std::cout << str << std::endl;
	}

	is.clear();
	return is;
}