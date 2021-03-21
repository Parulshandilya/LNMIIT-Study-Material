#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void ch1(int num)
{	
	if(num==SIGUSR1)
		printf("\nChild 1 called\nSIGUSR1\n");
	int i;
	printf("Printing numbers:\n");
	for(i=1;i<=10;i++)
		printf("%d ",i);
	printf("\n");
}
void ch2(int num)
{
	if(num==SIGUSR2)
		printf("\nChild 2 called\nSIGUSR2\n");
	printf("Hello world!-my first c program\n");
}
int main()
{
	int option;
	
	signal(SIGUSR2, ch2);
	signal(SIGUSR1, ch1);
	
	pid_t proc1 = fork();
	if(proc1==0)
	{
		printf("Child process of 1\n");
		sleep(10);	//time for entering option
	}
	else if(proc1>0)
	{
		pid_t proc2 = fork();
		
		if(proc2==0)
		{	
			printf("Child process of 2\n");
			sleep(10);	//time for entering option
		}
		
		else if(proc2>0)
		{
			printf("\n Enter your choice 1, 2 \n");
			scanf(" %d", &option);
			switch(option) {
				case 1: kill(proc1, SIGUSR1);
					break;
				case 2: kill(proc2, SIGUSR2);
					break;
				default: printf("\nInvalid option!\n");
					break;
			}
			wait();
		}
	}
	return 0;
}
