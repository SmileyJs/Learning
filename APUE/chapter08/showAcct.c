#include <stdio.h>
#include <stdlib.h>
#include <sys/acct.h>

#define FMT "%-*.*s e = %6ld, chars = %7ld, %c %c %c %c\n"

static unsigned long compt2ul(comp_t time)
{
	unsigned long val;
	int exp;

	val = time & 0x1fff;
	exp = (time >> 13) & 7;
	while (exp-- > 0)
		val *= 8;

	return val;
}

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		printf("argument failed!\n");
		exit(-1);
	}

	struct acct acData;
	FILE *fp;

	if (NULL == (fp = fopen(argv[1], "r"))) {
		printf("fread failed\n");
		return -1;
	}

	while (1 == fread(&acData, sizeof(acData), 1, fp)) {
		printf(FMT, (int)sizeof(acData.ac_comm), (int)sizeof(acData.ac_comm), acData.ac_comm,
				compt2ul(acData.ac_etime),
				compt2ul(acData.ac_io),
				acData.ac_flag & ACORE ? 'D' : ' ',
				acData.ac_flag & AXSIG ? 'X' : ' ',
				acData.ac_flag & AFORK ? 'F' : ' ',
				acData.ac_flag & ASU   ? 'S' : ' ');
	}

	if (ferror(fp))
		printf("fread faield!\n");

	return 0;
}