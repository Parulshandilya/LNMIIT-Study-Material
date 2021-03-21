#include<stdio.h>
#include<pthread.h>
int queue1[20],queue2[20],queue3[20];
int que_no,index1=0,index2=0,index3=0;
int bt[20],rt[20],wt[20],tt_tme[20],count=0,a[20]; //burst time, reponse time, wait time, turnout time, count of process that are completed.
int tq1=4,tq2=8,tq3=16,tme=0; //time quantums of all queues.
pthread_t tid[20];

void q1(){
	int i=0;
	//printf("queue1");
	for (;i<index1;i++){
		if (a[queue1[i]]==0) continue;
		if(a[queue1[i]]-tq1>0){
			a[queue1[i]]-=tq1;
			tme+=tq1;
			if(rt[queue1[i]]==0)
	       		rt[queue1[i]]=tme;
	       	queue2[index2++]=queue1[i];
	    }
		else {
			if(rt[queue1[i]]==0)
	       		rt[queue1[i]]=tme;
	       	tme+=a[queue1[i]];
			a[queue1[i]]=0;
			tt_tme[queue1[i]]=tme;
			wt[queue1[i]]=tt_tme[queue1[i]]-bt[queue1[i]];	
			count++;		
			printf("P%d ",queue1[i]+1);
		}
	}
}
void q2(int n){
	//printf("queue2");
	if (count==n)
		return;
	int i=0;
	for (;i<index2;i++){
		if (a[queue2[i]]==0) continue;
		if(a[queue2[i]]-tq2>0){
			a[queue2[i]]-=tq2;
			tme+=tq2;
			if(rt[queue2[i]]==0)
	       		rt[queue2[i]]=tme;
	       	queue3[index3++]=queue2[i];
	    }
		else {
			if(rt[queue2[i]]==0)
	       		rt[queue2[i]]=tme;
	       	tme+=a[queue2[i]];
			a[queue2[i]]=0;
			tt_tme[queue2[i]]=tme;
			wt[queue2[i]]=tt_tme[queue2[i]]-bt[queue2[i]];	
			count++;
			printf("P%d ",queue2[i]+1);		
		}
	}
}

void q3(int n){
	int i=0;
	//printf("queue3");
	while (count!=n){
		for (i=0;i<index3;i++){
			if (a[queue3[i]]==0) continue;
			if(a[queue3[i]]-tq3>0){
				a[queue3[i]]-=tq3;
				tme+=tq3;
				if(rt[queue3[i]]==0)
			   		rt[queue3[i]]=tme;
			}
			else {
				if(rt[queue3[i]]==0)
			   		rt[queue3[i]]=tme;
			   	tme+=a[queue3[i]];
				a[queue3[i]]=0;
				tt_tme[queue3[i]]=tme;
				wt[queue3[i]]=tt_tme[queue3[i]]-bt[queue3[i]];	
				count++;	
				printf("P%d ",queue3[i]+1);	
			}
		}
	}
}

void mlqf(int n){
	int i=0;
	
	//printf("in mlqf");
	for (i=0;i<n;i++) {
		a[i]=bt[i];
		queue1[index1++]=i;
	}
	q1();
	q2(n);
	q3(n);	
}

void * fun(){
  printf("Process created\n " );
}

void * createProcess(void * no){
	
	int n=(int)no;
	for(int i=0;i<n;i++){
		int rv=0;
		rv=pthread_create(&tid[i],NULL,fun,NULL);
		pthread_join(tid[i],NULL);
		scanf("%d",&bt[i]);
	}
	
}

int main(){
	int n;
	scanf("%d",&n);	
	int rv2=0;
	pthread_t tid2;
	rv2=pthread_create(&tid2,NULL,createProcess,(void * )n);
	//if (rv2){
		pthread_join(tid2,NULL);
		pthread_t tid3;
		int rv3=0;
		rv3=pthread_create(&tid3,NULL,mlqf,(void *)n);
		//if (rv3)
		pthread_join(tid3,NULL);
	//}
		
	

	pthread_exit(NULL);
	return 0;
	
}
