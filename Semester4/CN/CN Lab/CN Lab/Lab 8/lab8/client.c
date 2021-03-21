#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
    int SOCKET, portNum, nBytes;
    int DATA[100];
    int op;
    struct sockaddr_in addressOfServer;
    socklen_t addr_size;

    SOCKET = socket(PF_INET, SOCK_DGRAM, 0);

    if(SOCKET==-1)
    {
	printf("Socket connection failed.\n");
	return 0;
    }
    else
    {
	printf("Socket successfully created.\n");
    }


    addressOfServer.sin_family = AF_INET;
    addressOfServer.sin_port = htons(8888);
    addressOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(addressOfServer.sin_zero, '\0', sizeof addressOfServer.sin_zero); 
    addr_size = sizeof addressOfServer;
    

    for(;;) {
	printf("Enter two numbers:\n");
      	scanf("%d%d",&DATA[0],&DATA[1]);
	printf("Enter operation you wish to perform:\n1)Addition.\n2)Subtraction.\n3)Division.\n4)Multiplication.\n5)Exit.\n");
	scanf("%d", &op);
	
	switch(op) {
		case 1: DATA[2]=0;
			break;
		case 2: DATA[2]=1;
			break;
		case 3: DATA[2]=2;
			break;
		case 4: DATA[2]=3;
			break;
		case 5: DATA[2]==4;
			return 0;
			break;
		default: printf("Enter valid option.\n");
			break;
	}
       	sendto(SOCKET,DATA,100,0,(struct sockaddr *)&addressOfServer,addr_size);
        int Z = recvfrom(SOCKET,DATA,100,0,NULL, NULL);
        printf("Answer: %d\n",DATA[0]);
    }
    return 0;
}
