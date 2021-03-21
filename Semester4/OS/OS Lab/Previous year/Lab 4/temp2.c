#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<pthread.h>

int k=50;
int semid;
int count =0 ;
sem_t wrt,mutex;
void *reader()
{
	sem_wait(&mutex);
	count ++;
	if(count==1)
	{
		sem_wait(&wrt);
		printf("reading\n");
	}
	sem_post(&mutex);
	printf("reader is in critical section\n");
	sem_wait(&mutex);
	count--;
	if(count==0)
	{
		sem_post(&wrt);
		printf("free from reading");
	}
	sem_post(&mutex);
	
}

void *writer()
{
	sem_wait(&wrt);
	k+=50;
	printf("writed id is in critical section\n");
	sem_post(&wrt);
	printf("free from writer\n");
}

void main()
{
	sem_init(&wrt,0,1);
	sem_init(&mutex,0,1);
	pthread_t p1,p2,p3,p4,p5,p6;
	pthread_create(&p1,NULL,reader,NULL);
	pthread_create(&p2,NULL,writer,NULL);
	pthread_create(&p3,NULL,reader,NULL);
	pthread_create(&p4,NULL,reader,NULL);
	pthread_create(&p5,NULL,reader,NULL);
	pthread_create(&p6,NULL,writer,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);
	pthread_join(p4,NULL);
	pthread_join(p5,NULL);
	pthread_join(p6,NULL);

}

