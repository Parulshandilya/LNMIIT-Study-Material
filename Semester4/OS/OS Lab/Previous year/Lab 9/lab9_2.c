#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>

void handler(int signum)	//current instruction in CPU
{
	printf("\nENCOUNTERED-Segementation fault(core dumped)\n\n");
	exit(0);	//if not mentioned-infinite loop ; called multiple times
}

int main()
{
	pid_t pid;
	pid=getpid();
	printf("\n%d\n",pid);	//externally
	signal(SIGSEGV,handler);
	printf("\nYou can use other terminal to kill the process or Wait\n");
	sleep(10);		//wait-so as to kill using other terminal
	*(int*)0 = 0;		//internally
	return 0;
}
