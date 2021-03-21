#include <sys/types.h>
#include <sys/socket.h>
 #include <stdio.h>
 #include <errno.h>
 #include <netinet/in.h> 
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
int socketfd;
struct sockaddr_in client_addr, server_addr;
socklen_t addrlen;

printf("create client socket\n");
socketfd = socket(AF_INET, SOCK_STREAM, 0);
if(socketfd == -1) {
	fprintf(stderr, "socket failed [%d]\n", errno);
         return -1;
}

server_addr.sin_family = AF_INET;
// port on which client is to be binded
server_addr.sin_port = htons(9000);
server_addr.sin_addr.s_addr = INADDR_ANY;
if(connect(socketfd, (struct sockaddr *)&server_addr, sizeof server_addr) == -1) {
	perror("connect!");
	exit(1);
}
printf("connect successful!\n");
char file_list[100];
char list[50][50];
strcpy(list[0], "file1.c");
strcpy(list[1], "file2.c");
int counter = 0;
if(recv(socketfd, file_list, 100, 0) > 0) {
	printf("Received message: \n%s\n", file_list);
	printf("Select your file: \n");
	int file_num;
	scanf("%d", &file_num);
	printf("You selected : %d\n", file_num);

	// send file num:
	int send_file_num = send(socketfd, (void *)&file_num, 4, 0);
	printf("Sent file number: %d\n", send_file_num);

	FILE *fp;
	int c;
	if(recv(socketfd, &fp, 8, 0) > 0) {
		printf("Received File successfully: %lu\n", sizeof(fp));

		FILE *fp1 = fopen(list[file_num - 1], "r");

		while(1) {
		    c = fgetc(fp1);
		    if(feof(fp1)) {
		        break;
		    }
		    printf("%c", c);
		}
		printf("\nEOF!\n");
		fclose(fp1);
	}
}
else {
	printf("message not received\n");
}

close(socketfd);
return 0;
}
