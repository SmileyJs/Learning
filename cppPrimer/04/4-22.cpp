#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main(int argc, char* argv[])
{

	int score;
	string grade;

	while (cin >> score) {
		// grade = (score > 90) ? "highPass"
		// 					 : (score < 60) ? "fail" 
		// 									: (score < 75) ? "lowPass"
		// 				   				    			   : "pass";

	    if (score > 90) {
	    	grade = "highPass";
	    } 
	    else if (score < 60) {
	    	grade = "fail";
	    }
	    else if (score < 75) {
	    	grade = "lowPass";
	    }
	    else {
	    	grade = "pass";
	    }

	    cout << grade << endl;
	}

	return 0;
}