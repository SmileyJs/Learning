#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;

int
main(int argc, char *argv[])
{
	vector<string> score = {"F", "E", "D", "C", "B", "A"};

	int i = 0;

	while (cin >> i) {
		if (i < 60) {
			cout << score[0];
		}
		else{
			if (i % 10 > 7)
				cout << score[(i - 50) / 10] << "+";
			else if (i % 10 < 3) 
				cout << score[(i - 50) / 10] << "-";
		}
	}
	return 0;
}