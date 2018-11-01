#include <stdio.h>
#include <stdlib.h>

int
is_unbuffered(FILE *fp)
{
	return (fp->_flags & _IO_UNBUFFERED);
}

int 
is_linebuffered(FILE *fp)
{
	return (fp->_flags & _IO_LINE_BUF);
}

int
buffer_size(FILE *fp)
{
	return (fp->_IO_buf_end - fp->_IO_buf_base);
}

void
show_stdio(const char *name, FILE *fp)
{
	printf("stream = %s, ", name);

	if (is_unbuffered(fp))
		printf("unbuffered");
	else if (is_linebuffered(fp))
		printf("linebuffered");
	else 
		printf("fullbuffered");

	printf(", buffer size = %d\n", buffer_size(fp));
}

int
main(int argc, char const *argv[])
{
	FILE *fp;

	fputs("test: stdout\n", stdout);
	if (fgetc(stdin) == EOF)
		printf("test: stdin failed!\n");
	fputs("test: stderr\n", stderr);

	show_stdio("stdin", stdin);
	show_stdio("stdout", stdout);
	show_stdio("stderr", stderr);

	if (NULL == (fp = fopen("/etc/passwd", "r")))
		printf("fopen failed!\n");

	if (fgetc(fp) == EOF)
		printf("fgetc failed!\n");

	show_stdio("/etc/passwd", fp);

	return 0;
}