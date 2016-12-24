#include "Screen.h"

int
main(int argc, char const *argv[])
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display();
	cout << "\n";
	myScreen.display();
	cout << "\n";

	return 0;
}