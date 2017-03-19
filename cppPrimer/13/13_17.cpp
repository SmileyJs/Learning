#include <iostream>

using namespace std;

class numbered {
public:
	numbered() {
		static int unique = 0;
		mysn = unique++;
	}

	numbered(numbered &c) {
		mysn = c.mysn + 1;
	}

	int mysn;
};

void
f (const numbered &x)
{
	// if the argument is not reference, here will call copy_constructor.
	cout << x.mysn << endl;
}

int
main(int argc, char const *argv[])
{
	numbered a, b = a, c = b; 
	// b = a call copy_constructor. If b has been created before, 
	// then will call copy_assignment operator.

	f(a);
	f(b);
	f(c);

	return 0;
}