#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<string.h>

typedef struct message_buffer{
	long mtype;
	char mchar[100];
}mbuf;

int main()
 {
	mbuf sbuf;
	int msgqid;
	int msgflag = IPC_CREAT | 0666;
	key_t key = 1234;
	msgqid = msgget( key , msgflag );
	
	printf("Enter the message:\n");

	if((msgqid = msgget(key,msgflag)) < 0) {
		printf("Message not sent\n");
		exit(1);
	}
	else {
		printf("Message successfully sent.\n");
	}

	while(1) {
		
		scanf("%s",sbuf.mchar);
		if( strcmp(sbuf.mchar,"END")==0) {
			exit(0);
		}
	
		else 
			msgsnd(msgqid,&sbuf,sizeof((sbuf.mchar)+1),0);	
	}
	return 0;
}
