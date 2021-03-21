#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t pingsem, pongsem,dingsem,dongsem;
int j=1; 
void * ping(void *arg) 
{
	int i;
    for (i=1;i<=10;i++) {
        sem_wait(&pingsem);
        printf("%d ping\n",j++);
        sem_post(&pongsem);
    }
}

void *
pong(void *arg) 
{
	int i;
    for (i=1;i<=10;i++) {
        sem_wait(&pongsem);
        printf("%d pong\n",j++);
        sem_post(&dingsem);
    }
}
void *
ding(void *arg) 
{
	int i;
    for (i=1;i<=10;i++) {
        sem_wait(&dingsem);
        printf("%d ding\n",j++);
        sem_post(&dongsem);
    }
}

void *
dong(void *arg) 
{
	int i;
    for (i=1;i<=10;i++) {
        sem_wait(&dongsem);
        printf("%d dong\n",j++);
        sem_post(&pingsem);
    }
}

int 
main(void) 
{
    sem_init(&pingsem, 0, 1);
    sem_init(&pongsem, 0, 0);
	sem_init(&dingsem,0,0);
	sem_init(&dongsem,0,0);
    pthread_t ping_thread, pong_thread, ding_thread,dong_thread; 
    pthread_create(&ping_thread, NULL, ping, NULL);
    pthread_create(&pong_thread, NULL, pong, NULL);
    pthread_create(&ding_thread, NULL, ding, NULL);
	pthread_create(&dong_thread, NULL, dong, NULL);
    pthread_join(ping_thread, NULL);
    pthread_join(pong_thread, NULL);
	pthread_join(ding_thread, NULL);
	pthread_join(dong_thread, NULL);
    return 0;
}
