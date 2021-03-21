#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<assert.h>
#include<semaphore.h>
#define R 5
#define W 2
sem_t reader,writer;
int read_cnt=0,x=0;
void* write()
{
    assert(sem_wait(&writer)>=0);
    x+=1;
    assert(sem_post(&writer)>=0);
}
void* read()
{
    assert(sem_wait(&reader)>=0);
    read_cnt++;
    if(read_cnt==1)
        assert(sem_wait(&writer)>=0);
    assert(sem_post(&reader)>=0);
    assert(sem_wait(&reader)>=0);
    read_cnt--;
    if(read_cnt==0)
        assert(sem_post(&writer)>=0);
    assert(sem_post(&reader)>=0);
}
int main()
{
	assert(sem_init(&reader,0,1)>=0);
	assert(sem_init(&writer,0,1)>=0);
	pthread_t t1[W],t2[R];
	int i;
	for(i=0;i<W;i++)
		assert(pthread_create(&t1[i],NULL,write,NULL)==0);
	for(i=0;i<R;i++)
		assert(pthread_create(&t2[i],NULL,read,NULL)==0);
	for(i=0;i<W;i++)
		pthread_join(t1[i],NULL);
	for(i=0;i<R;i++)
		pthread_join(t2[i],NULL);
	printf("%d\n",x);
	sem_destroy(&reader);
	sem_destroy(&writer);
	return 0;
}
