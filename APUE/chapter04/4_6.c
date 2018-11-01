#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

const unsigned int SIZE = 4096;

int
my_cp(int input, int output)
{
	char buf_in[SIZE] = {0};
	char buf_out[SIZE] = {0};
	int byte_count = 0;
	int crt_count = 0;

	while (0 < read(input, buf_in, SIZE)) {
		for (crt_count = 0; crt_count != SIZE; crt_count++) {
			if (buf_in[crt_count] != 0) {
				printf("%c\n", buf_in[crt_count]);
				buf_out[byte_count++] = buf_in[crt_count];
			}
		}

		if (-1 == write(output, buf_out, byte_count)) {
			printf("write failed! %s\n", strerror(errno));
			return -1;
		}

		memset(buf_in, 0, SIZE);
		memset(buf_out, 0, SIZE);
	}

	return 0;
}

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument error!\n");
		return -1;
	}

	int fdIn, fdOut;

	if (-1 == (fdIn = open(argv[1], O_RDONLY))) {
		printf("open in failed! %s\n", strerror(errno));
		return -1;
	}

	if (-1 == (fdOut = open(argv[2], O_CREAT | O_RDWR | O_TRUNC))) {
		printf("open out failed! %s\n", strerror(errno));
		return -1;
	}

	if (0 > my_cp(fdIn, fdOut)) {
		printf("my_cp failed!\n");
	}

	return 0;
}