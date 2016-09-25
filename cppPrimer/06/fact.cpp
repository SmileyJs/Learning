#include "chapter6.h"

int 
fact(int val)
{
	if (val > 1)
		return val * fact(val - 1);
	else 
		return 1;
}