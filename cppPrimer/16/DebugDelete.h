#include <iostream>

using namespace std;

class DebugDelete
{
public:
	DebugDelete(ostream& a = std::cout) : os(a) {}
	
	template <typename T> void operator()(T* p) {
		os << "delete pointer" << endl;
		delete p;
	}
	
private:
	ostream& os;
};