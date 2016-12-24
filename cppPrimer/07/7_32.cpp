#include "Screen.h"

int
main(int argc, char const *argv[])
{
	Window_mgr mgr;
	mgr.screens = {Screen(5, 5, 'a'), Screen(5, 5, 'b')};
	mgr.screens[0].display();
	cout << endl;
	mgr.clear(0);
	mgr.screens[0].display();
	cout << endl;
	return 0;
}