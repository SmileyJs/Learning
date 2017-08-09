#include <iostream>

using namespace std;

#define TEST_DECLARE_FACTORY(T)\
class T##Factory\
{\
public:\
	T##Factory() {\
		cout << __PRETTY_FUNCTION__ << endl;\
	}\
};

#define TEST_DEFINE_FACTORY(T)\
T##Factory& get##T##Factory()\
{\
	cout << __PRETTY_FUNCTION__ << endl;\
	static T##Factory s_factory;\
	return s_factory;\
}

#define TEST_FACTORY(T) (get##T##Factory())

TEST_DECLARE_FACTORY(AA);
TEST_DEFINE_FACTORY(AA);

TEST_DECLARE_FACTORY(BB);
TEST_DEFINE_FACTORY(BB);

int
main(int argc, char const *argv[])
{
	TEST_FACTORY(AA);
	TEST_FACTORY(BB);

	return 0;
}