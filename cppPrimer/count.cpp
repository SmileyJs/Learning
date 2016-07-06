#include <iostream>
#include <stdlib.h>
using namespace std;

namespace{
	int upper = 100;
	int lower = 1;
}

class Counter{
	int count;

public:
	Counter(int n) {
    		if (n < upper) {
	   		count = n;
		}
		else {
   		    	count = upper;
		}
	}
	
	void reset(int n) {
		if (n <= upper) {
			count = n;
		}
	}

	int run() {
		if (count > lower) {
			return count--;
		} 
		else {
			return lower;
		}
	}

};

int main(int argc, char* argv[]) {
	Counter obj(atoi(argv[1]));
	
	int i;
	do {
		i = obj.run();
		cout << i << endl;
	}
	while (i > lower);
//	cout << argc << endl;
//	cout << *argv[1] << endl;
}
