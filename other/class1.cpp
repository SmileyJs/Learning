#include <stdio.h>
#include <cstring>

struct X {
	char* p;
	X() {
		p = new char [100];
		strcpy(p, "hello world!");
	} 

	X(const X &x) {
		p = new char [strlen(x.p) + 1];
		strcpy(p, x.p);
	}

	X& operator=(X &x) {
		if (&x != this) {
			delete [] p;
			p = new char [strlen(x.p) + 1];
			strcpy(p, x.p);
		}

		return *this;	
	}

	~X() { delete [] p;}
};

void g(X& x1, X& x2) { x1 = x2;}

int
main(int argc, char const *argv[])
{
	X a;

	g(a, a);

	printf("%s\n", a.p);

	return 0;
}