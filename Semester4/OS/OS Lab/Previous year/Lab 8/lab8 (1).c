#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define memsize 64
#define pagesize 16
struct page
{
	int process;
	int pgno;
	int dirty;
};
typedef struct page page;
struct stack
{
	int top;
	page table[memsize/pagesize];
};
typedef struct stack stack;
stack u;
sem_t mutex;
int n2;
void initialize()
{
	int i;
	u.top=-1;
	for(i=0;i<memsize/pagesize;i++)
		u.table[i].dirty=0;
}
void status()
{
	int i;	
	for(i=0;i<memsize/pagesize;i++)
	{
		if(u.table[i].dirty==0)
			printf("%d is empty page frame\n",i);
		else
			printf("%d has process no %d and its page no is %d\n",i,u.table[i].process,u.table[i].pgno);
	}
}
void *allocate(void *temp)
{
	int pid = (int *)temp;
	sem_wait(&mutex);
	allocatepage(pid,n2);
	status();
	sem_post(&mutex);
	/*sleep(8);
	sem_wait(&mutex);
	//deallocate(pid);
	sem_post(&mutex);*/
} 
void allocatepage(int pid,int pno)
{
	int i,flag=0,sol;
	for(i=0;i<u.top;i++)
	{
		if(u.table[i].dirty==1 && u.table[i].process==pid && u.table[i].pgno==pno)
		{
			u.table[i].process=u.table[u.top].process;
			u.table[u.top].process=pid;
			u.table[i].pgno=u.table[u.top].pgno;
			u.table[u.top].pgno=pno;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		for(i=0;i<memsize/pagesize;i++)
		{
			if(u.table[i].dirty==0 && u.top<=memsize/pagesize-1)
			{
				u.top++;
				u.table[i].dirty=1;
				u.table[i].process=pid;
				u.table[i].pgno=pno;
				flag=2;
				break;
			}
		}
	}
	if(flag==0)
	{
		u.table[u.top].process=pid;
		u.table[u.top].pgno=pno;
		flag=3;
	}
	if(flag==1)
		printf("Page was already allocated\n");
	else if(flag==2)
		printf("Page Fault Occurred.Page allocated successfully\n");
	else if(flag==3)
		printf("Page was Replaced\n");	
}
int main()
{
	pthread_t pid[8];
	int i,n1;
	initialize();
	sem_init(&mutex,0,1);
	for(i = 0; i < 8; i++)
	{	
		n1=rand()%8;
		n2=rand()%7;
		printf("%d : %d\n",n1,n2);	
		pthread_create(&pid[i], NULL, allocate, (void *)n1);
		pthread_join(pid[i],NULL);
	}
	
	/*for(i = 0; i < 4; i++){
		pthread_join(pid[i],NULL);	
	}*/
	return 0;
}
