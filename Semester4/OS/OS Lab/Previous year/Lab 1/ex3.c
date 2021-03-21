#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main() {
	pid_t pid;
	int array[10] = {1,2,34,95,5,6,7,8,91,10};
	int id;
	id = shmget(IPC_PRIVATE, 16, IPC_CREAT|0666);
	int *ptr;
	ptr = (int*)shmat(id,0,0);
	pid = fork();
	int Max, Min, mn1=1000, mn2=1000, mx1=0, mx2=0, i;
	

	if(pid == 0) {
		for(i=0;i<10;i++) {
			if (array[i] > mx1)
       				mx1  = array[i];
			if(array[i] < mn1)
				mn1 = array[i];
		}
		*ptr = mx1;
		*(ptr+1)=mn1;
	}
	
	else if(pid>0) {
		wait();

		pid = fork();
		if(pid == 0) {
			for(i=0;i<10;i++) {
			if (array[i] > mx2)
       				mx2  = array[i];
			if(array[i] < mn2)
				mn2 = array[i];
			}
			*(ptr+2) = mx2;
			*(ptr+3)=mn2;
		}
		else if(pid>0) {
			wait();
			if(*ptr>*(ptr+1))
				Max = *ptr;
			else
				Max = *(ptr+1);

			if(*(ptr+2)>*(ptr+3))
				Min = *(ptr+3);
			else
				Min = *(ptr+2);

		printf("Maximum element is %d\n",Max);
		printf("Minimum element is %d\n",Min);
		}
		else {
			printf("Forking failed\n");
			exit(-1);
		}

		
	}
	
	else {
		printf("Forking failed\n");
		exit(-1);
	}
}
		
