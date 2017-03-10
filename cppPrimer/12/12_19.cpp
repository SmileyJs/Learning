#include <iostream>
#include <memory>

using namespace std;

int
main(int argc, char const *argv[])
{
	shared_ptr<int> p(new int(34));

	cout << p.use_count() << endl;

	weak_ptr<int> wp(p);

	if (shared_ptr<int> np = wp.lock()) {
		cout << *np << endl;
		cout << np.use_count() << endl;
	}

	cout << wp.use_count() << endl;

	return 0;
}