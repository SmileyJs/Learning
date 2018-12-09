#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int
main(int argc, char const *argv[])
{
	
	openlog("testAAA", LOG_PID, 0);

	syslog(LOG_ERR, "syslog test");

	// var/log/syslog

	return 0;
}