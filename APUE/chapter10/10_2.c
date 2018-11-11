#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#define NUMNAME(name) {SIG##name, #name}

struct SigName {
	int signo;
	char name[8];
} table[]  = {
    NUMNAME (HUP),
    NUMNAME (INT),
    NUMNAME (QUIT),
    NUMNAME (ILL),
    NUMNAME (TRAP),
    NUMNAME (ABRT),
    NUMNAME (FPE),
    NUMNAME (KILL),
    NUMNAME (SEGV),
    NUMNAME (BUS),
    NUMNAME (PIPE),
    NUMNAME (ALRM),
    NUMNAME (TERM),
    NUMNAME (USR1),
    NUMNAME (USR2),
    NUMNAME (CHLD),
    NUMNAME (URG),
    NUMNAME (STOP),
    NUMNAME (TSTP),
    NUMNAME (CONT),
    NUMNAME (TTIN),
    NUMNAME (TTOU),
    NUMNAME (SYS),
    NUMNAME (POLL),
    NUMNAME (VTALRM),
    NUMNAME (PROF),
    NUMNAME (XCPU),
    NUMNAME (XFSZ),
    NUMNAME (IOT),      /* Older name for ABRT.  */
    NUMNAME (CLD),
    NUMNAME (PWR),
    NUMNAME (WINCH),
    NUMNAME (IO),
    NUMNAME (STKFLT),
    { 0, "EXIT" }
};

#define SIGNUM sizeof(table)/sizeof(table[0])

void my_sig2str(int signo, char *str)
{
	if (0 > signal)
		printf("argument error!\n");

	for (int i = 0; i != SIGNUM; ++i) {
		if (signo == table[i].signo) {
			strcpy(str, table[i].name);
			break;
		}
	}
}

int
main(int argc, char const *argv[])
{
	char str[16] = {0};
	my_sig2str(10, str);
	printf("%s\n", str);

	// for (int i = 0; i < _NSIG; ++i) {
	// 	printf("%s\n", sys_siglist[i]);
	// }

	return 0;
}