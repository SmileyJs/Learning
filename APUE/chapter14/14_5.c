#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <poll.h>

int
sleep_us(int us)
{
	struct timeval tval;

	tval.tv_sec = us / 1000000;
	tval.tv_usec = us % 1000000;

	return select(0, NULL, NULL, NULL, &tval);
}

int
sleep_us2(int us)
{

	return poll(NULL, 0, us/1000);
}

int
main(int argc, char const *argv[])
{
	sleep_us(2000000);

	printf("sleep1\n");

	sleep_us2(2000000);

	printf("sleep2\n");

	return 0;
}