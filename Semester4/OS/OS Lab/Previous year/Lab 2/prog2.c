#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define size 10
 int max=0, min=999, avg=0;
void *average(void *args)
{
	int *val = (int*) args;
	int i,sum=0;
	for(i=0; i<size;i++)
	{
		sum+=val[i];
	}
	avg=sum/size;
}

void *maximum(void *args)
{
	int i;
	int *val = (int*) args;
	for(i=0;i<size;i++) {
		if(val[i]>max)
			max = val[i];
	}
}

void *minimum(void *args)
{
	int i;
	int *val = (int*) args;
	for(i=0;i<size;i++) {
		if(val[i]<min)
			min = val[i];
	}
}


int main() {

	int arr[size],i;
	for (i = 0; i < size ; i++)
	{
		scanf("%d",&arr[i]);
	}
	pthread_t tid1,tid2,tid3;
	
	pthread_create(&tid1, NULL, average, (void*) arr);
	pthread_create(&tid2, NULL, maximum, (void*) arr);
	pthread_create(&tid3, NULL, minimum, (void*) arr);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	printf("Maximum=%d\n",max);
	printf("Minimum=%d\n",min);
	printf("Average=%d\n",avg);
	return 0;
}

