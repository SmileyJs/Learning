#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 0;
void* runner(void*);

int
main(int argc, char const *argv[])
{
	int pid;
	pthread_t tid;
	pthread_attr_t attr;

	pid = fork();

	if (0 == pid) {
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, runner, NULL);
		pthread_join(tid, NULL);
		std::cout << "child value: " << value << std::endl;	
	}
	else if (0 < pid) {
		wait(NULL);
		std::cout << "parent value: " << value << std::endl;	
	}

	return 0;
}

void* runner(void* param)
{
	value = 10;	
	pthread_exit(0);
}


#if 0
接下来介绍采用Pthread和Win32两种线程库来创建基本的线程。作为一个说明性的例子，设计一个多线程程序，在独立的线程中完成非负数整数的加法功能:

例如，如果N为5 ，此函数表示从0~5 的数相加起来，为15 。三个程序都要求在命令行输入加法的上限。例如，如果用户输入8 ，将会输出从0~8的整数值的和。

#endif