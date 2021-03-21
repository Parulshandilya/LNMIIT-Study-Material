#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int count = -1;

void sigint(int signum)
{
	count++;
	if(count==0)
		printf("\nWill not terminate! Press Ctr+C\n");
	else if(count==1)
		printf("\nTry once more! Press Ctr+C\n");
	else if(count==2)
	{
		printf("\nYeah, finally succeeded!\n\n");
		exit(0);
	}
}

int main()
{
	printf("\nPress Ctr+C\n");
	while(1)
		signal(SIGINT, sigint);
	return 0;
}
