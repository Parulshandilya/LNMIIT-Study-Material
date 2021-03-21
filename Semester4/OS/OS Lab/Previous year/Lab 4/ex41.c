#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/sem.h>

union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };
union semun arg;
struct sembuf signal, wait;

int semid;
int x;
void *increment() {
	int i;
	semop(semid,&wait,1);
	for(i=0;i<10000;i++) {
		x++;
	}
	semop(semid,&signal,1);
}

void *decrement() {
	int i;
	semop(semid,&wait,1);
	for(i=0;i<10000;i++) {
		x--;
	}
	semop(semid,&signal,1);
}

int main() {
	
	arg.val=1;
	wait.sem_num=0;
	wait.sem_op=-1;
	wait.sem_flg=0;
	signal.sem_num==0;
	signal.sem_op=1;
	signal.sem_flg=0;

	key_t key=12345;
	int semflg=IPC_CREAT|0666;

	semid = semget(key,1,semflg);
	semctl(semid,0,SETVAL,arg);


	pthread_t tid1, tid2;
	
	pthread_create(&tid1, NULL, increment,NULL);
	pthread_create(&tid2, NULL, decrement,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	printf("The value of x is %d\n",x);
	return 0;
}
