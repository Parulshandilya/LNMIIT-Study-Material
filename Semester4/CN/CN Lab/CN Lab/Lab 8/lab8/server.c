#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <math.h>

int main() {
    int SOCKET;
    int DATA[100];
    struct sockaddr_in addressOfServer, addressOfClient;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;
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

    bind(SOCKET, (struct sockaddr *) &addressOfServer, sizeof(addressOfServer));

    addr_size = sizeof serverStorage;

    for(;;) 
{
        int Z = recvfrom(SOCKET,DATA,100,0,(struct sockaddr *)&serverStorage, &addr_size);
        if(DATA[2]==0) {
            DATA[0] += DATA[1];	
        }
	else if(DATA[2]==1) {
	    DATA[0] -= DATA[1];
	}
	else if(DATA[2]==2) {
	    DATA[0] /= DATA[1];
	}
	else if(DATA[2]==3) {
	    DATA[0] *= DATA[1];
	}
        sendto(SOCKET,DATA,100,0,(struct sockaddr *)&serverStorage,addr_size);
        printf("Value : %d\n",DATA[0]);
    }
    return 0;
}

