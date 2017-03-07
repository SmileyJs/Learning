#include <iostream>
#include <memory>

using namespace std;

void
process(shared_ptr<int> p)
{
	cout << p.use_count() << endl;
}

int
main(int argc, char const *argv[])
{
	shared_ptr<int> p(new int(42));

	cout << p.use_count() << endl;

	process(shared_ptr<int>(p));

	cout << p.use_count() << endl;

	return 0;
}