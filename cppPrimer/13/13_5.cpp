#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &cp) : ps(new string(*cp.ps)), i(cp.i) {}
	HasPtr &operator=(const HasPtr &cp) {
		string *newPs = new string(*cp.ps);
		// need to delete the orgin string
		delete ps;
		ps = newPs;
		i = cp.i;

		return *this;
	}

private:
	string *ps;
	int i;
};