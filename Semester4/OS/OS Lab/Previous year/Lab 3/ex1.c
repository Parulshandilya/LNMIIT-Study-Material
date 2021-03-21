#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int x;
void *increment() {
	int i;
	for(i=0;i<10000;i++) {
		x++;
	}
}

void *decrement() {
	int i;
	for(i=0;i<10000;i++) {
		x--;
	}
}

int main() {

	int pthread_equal(pthread_t tid1, pthread_t tid2);
	pthread_t tid1, tid2;
	
	pthread_create(&tid1, NULL, increment,NULL);
	pthread_create(&tid2, NULL, decrement,NULL);


	printf("The value of x is %d\n",x);
	return 0;
}
