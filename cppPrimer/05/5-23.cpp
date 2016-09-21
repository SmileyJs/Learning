#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	int i, j;

	cout << "Please input two number!" << endl;

	while (cin >> i >> j) {
		try {
			if (0 == j) {
				// cerr << "The divisor is 0" << endl;
				// break;
				throw runtime_error("The divisor is 0.");
			}	
			
			cout << i/j;
		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "Try again.(Y/N)" << endl;
			char rsp;
			cin >> rsp;
			if (!cin || rsp != 'Y') break;
		}


	}

	return 0;
}
