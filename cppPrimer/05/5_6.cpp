#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int
main(int argc, char const *argv[])
{
	string letterGrade("");

	vector<string> score = {"E", "D", "C", "B", "A", "A++"};

	int i = 0;

	while (cin >> i && i <= 100 && i >= 0) {
		letterGrade = i < 60 ? score[0] : score[(i - 50) / 10];

		letterGrade += (i < 60 || i == 100) ? "" : (i%10 > 7) ?
												"+" : (i%10 < 3) ? 
													"-" : "";

		// letterGrade = i < 60 ? "F" : i < 70 ?
		// 						    "D" : i < 80 ?
		// 						    	"C" : i < 90 ?
		// 						    		"B" : i < 100 ?
		// 						    			"A" : "A++";

		// letterGrade += (i % 10) > 7 ? "+" : (i % 10) < 3 ?
		// 								   "-" : "";

		cout << letterGrade << endl;
	}
	return 0;
}