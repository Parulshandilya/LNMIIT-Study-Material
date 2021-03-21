#include <sys/types.h>
#include <sys/socket.h>
 #include <stdio.h>
 #include <errno.h>
 #include <netinet/in.h> 
#include <string.h>
#include <unistd.h>

int main() {
int socketfd, client_fd;
struct sockaddr_storage client_addr;
struct sockaddr_in server_addr;

socklen_t addrlen;

printf("create server socket\n");
socketfd = socket(AF_INET, SOCK_STREAM, 0);
if(socketfd == -1) {
	fprintf(stderr, "socket failed [%d]\n", errno);
         return -1;
}

server_addr.sin_family = AF_INET;
// port on which server is to be binded
server_addr.sin_port = htons(9000);
server_addr.sin_addr.s_addr = INADDR_ANY;

printf("bind server socket\n");
if(bind(socketfd, (struct sockaddr *)&server_addr, sizeof server_addr) != 0) {
	fprintf(stderr, "bind failed [%d]\n", errno);
         close(socketfd);
         return -1;
}

if(listen(socketfd, 20) == -1) {
	perror("listen");
	return -1;
}
printf("listen successful!\n");
addrlen = sizeof client_addr;

// get new socket fd to send/recv messages to client
client_fd = accept(socketfd, (struct sockaddr *)&client_addr, &addrlen);
printf("accept successful!\n");

char *file_list = "1. file1.c\n2. file2.c\n";
// send file list
int bytes_sent = send(client_fd, file_list, 100, 0);
printf("send successful! %d bytes sent\n", bytes_sent);

// receive file number
int file_num;
int recv_file_num = recv(client_fd, &file_num, 4, 0);
if(recv_file_num > 0) {
    printf("Received file no: %d\n", file_num);
} else {
    printf("FILE NUM message not received\n");
    return -1;
}

// send file pointer
FILE *fp;
int c;
fp = fopen("file1.c","r");
printf("%lu", sizeof(fp));
int send_fp = send(client_fd, &fp, 8, 0);
printf("send File pointer successful! %d bytes sent\n", send_fp);


close(socketfd);
close(client_fd);
return 0;
}
