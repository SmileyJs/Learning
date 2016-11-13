#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << make_plural(1, "success", "es") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;

	return 0;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return ctr > 1 ? word + ending : word;
}