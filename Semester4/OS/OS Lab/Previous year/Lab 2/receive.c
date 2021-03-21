#include<stdio.h>
#include<unistd.h>
#include <sys/msg.h>
#include<string.h>

struct message
{
	long mtype;
	char s[256];
	
}mess;

main ()
{
	int recieveid;
	ssize_t size;
	
	recieveid= msgget(202, 0);
	printf("Message recieved.\n");
	size=msgrcv(recieveid, &mess,256,1,0);
	if(strcmp(mess.s,"END")==0)
		exit(0);	
	else
		printf("%s\n",mess.s);

	

}
