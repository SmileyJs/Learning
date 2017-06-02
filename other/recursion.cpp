#include <iostream>

using namespace std;

int
myStrLen(char *buf, int N)
{
	cout << buf << " " << N << endl;

	if (buf[0] == 'h' || N == 0) {
		return 0;
	}
	else if (N == 1) {
		return 1;
	}

	int t = myStrLen(buf, N/2);

	if (t < N/2) {
		return t;
	}
	else {
		return (t + myStrLen(buf + N/2, (N+1)/2));
	}
}

int
main(int argc, char const *argv[])
{
	char buf[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '\0'};

	cout << myStrLen(buf, 10) << endl;

	return 0;
}