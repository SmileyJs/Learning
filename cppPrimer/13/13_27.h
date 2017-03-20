#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) 
		: ps(new string(s)), i(0), use(new size_t(1)) {}

	HasPtr(const HasPtr &cp)
		: ps(cp.ps), i(cp.i), use(cp.use) {
			use++;
		}

	HasPtr &operator=(const HasPtr &cp) {
		++*cp.use;
		if (--*use == 0) {
			delete ps;
			delete use;
		}
		ps = cp.ps;
		use = cp.use;
		i = cp.i;

		return *this;
	}

	~HasPtr() {
		if (--*use == 0) {
			delete ps;
			delete use;
		}
	}

private:
	string *ps;
	int i;
	size_t *use;
};