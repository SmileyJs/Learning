#include "Singleton.h"

int
main(int argc, char const *argv[])
{
	Singleton::getInstance()->test();
	Singleton::destoryInstance();

	return 0;
}