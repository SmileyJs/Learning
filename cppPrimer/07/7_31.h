#include <cstdlib>

class Y;

class X {
	Y *a = nullptr;
};

class Y {
	X a;
};

typedef double Money;
int bal;
typedef int pos;

class Account {
public:
	Money balance() {return bal;}
	pos get();
	// typedef int pos;
	
private:
	// typedef double Money;
	Money bal;
};

