#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<pthread.h>

int semid;
int rcount=0,wcount=0 ;
sem_t rsem,wsem;
sem_t x,y,z;
void *reader()
{
		sem_wait(&z);
		sem_wait(&rsem);		
		sem_wait(&x);
		rcount ++;
		if(rcount==1)
		{
			sem_wait(&wsem);
			printf("Reader id is in critical section\n");
		}
		sem_post(&x);
		sem_post(&rsem);
		sem_post(&z);
		printf("Reading\n");
		sem_wait(&x);
		rcount--;
		if(rcount==0)
		{
			sem_post(&wsem);
			printf("free from reading\n");
		}
		sem_post(&x);
}

void *writer()
{
		sem_wait(&y);
		wcount++;
		if(wcount==1) {
			sem_wait(&rsem);
			printf("Writer id is in critical section\n");
		}
		sem_post(&y);
		sem_wait(&wsem);
		printf("Writing\n");
		sem_post(&wsem);
		sem_wait(&y);
		wcount--;
		if(wcount==0) {
			sem_post(&rsem);
			printf("free from writer\n");
		}
		sem_post(&y);

}

void main()
{
	sem_init(&wsem,0,1);
	sem_init(&rsem,0,1);
	sem_init(&x,0,1);
	sem_init(&y,0,1);
	sem_init(&z,0,1);
	pthread_t p1,p2,p3,p4,p5,p6;
	pthread_create(&p1,NULL,writer,NULL);
	pthread_create(&p2,NULL,writer,NULL);
	pthread_create(&p3,NULL,reader,NULL);
	pthread_create(&p4,NULL,writer,NULL);
	pthread_create(&p5,NULL,reader,NULL);
	pthread_create(&p6,NULL,writer,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);
	pthread_join(p4,NULL);
	pthread_join(p5,NULL);
	pthread_join(p6,NULL);

}

