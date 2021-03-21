#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	int status = 0;
	pid = fork();
	uid_t getuid(), ruid, euid, geteuid();
	gid_t getgid(), getegid(), rgid, egid;
	pid_t getpid(), getppid(), rpid, ppid;
	
	if (pid == 0) {
		printf("Child Process\n");
    		//execlp ("/bin/ls", "ls", NULL);
		ruid = getuid();
		euid = geteuid();
		rgid = getgid();
		egid = getegid();
		rpid = getpid();
		ppid = getppid();
		printf("Real UID-%d\n",ruid);
		printf("Effective UID-%d\n",euid);
		printf("Real GID-%d\n",rgid);
		printf("Effective GID-%d\n",egid);
		printf("Real PID-%d\n",rpid);
		printf("Process PID-%d\n",ppid);
		exit(status);
	}

	else if (pid<0) {
		printf("Fork failed\n");
		status = -1;
		exit(status);
	}

	else {
		printf("Parent Process\nWaiting for child process\n");
		waitpid(-1, &status, 0); //wait for the child process
		printf("Child complete\n");
		status = -1;
		exit(status);
	}


}			
