#include<stdio.h>
#include<pthread.h>
int bt[20],at[20],pt[20],wt[20],tt[20];
pthread_t tid[20];
int tp,curr=0;
int pl[20];
int i=1;
int k=0,z=0;
void * fun()
{
//printf("Process created\n");
}
void priority_changer()
{
	if(bt[curr]==0)pt[curr]=0;
	//pt[curr]=pt[curr]+1;
	for(int j=0;j<tp;j++)
	{
		if(curr!=j && at[j]<=i && bt[j]!=0)pt[j]=pt[j]+3;
		else if(curr==j) pt[j]=pt[j]+1;
		
	}
}
void current_changer()
{
	
			
		int j=0;
	for(j=0;j<tp;j++)
		{			
			if(at[j]<=i && bt[j]>0 && pt[j]>pt[curr])
				{
					curr=j;z=0;
				}
			else if(pt[j]==pt[curr] && j<curr)curr=j;
			
		}
		bt[curr]--;	
		//i++;	
		if(bt[curr]==-1){z=1;bt[curr]=0;}
			
}
void wait_time_analyser()
{
	for(int j=0;j<tp;j++)
	{
		if(j!=curr && at[j]<i && bt[j]>0)wt[j]++;
	}
}
void  scheduler()
{
	
	i=1;
	int p=tp;
	pt[0]=0;
	while(p)
	{
				
		current_changer();
		priority_changer();
		if(bt[curr]==0 && z!=1){tt[curr]=i-at[curr];p--;pl[k++]=curr;}		
		
		wait_time_analyser();
		
		printf("\ncurrent process =%d current time=%d \n",curr+1,i);
		printf("\n Priority   ");
		for (int n=0;n<tp;n++)printf("     %d",pt[n]);
		printf("\nBurst time   ");
		for (int n=0;n<tp;n++)printf("     %d",bt[n]);
		i++;
	}
}
void * create_Process(void* p)
{
	tp=(int *)p;
	//printf("In create process");
	int n=(int)p;
	for(int i=0;i<n;i++)
	{
	int r=0;
	r=pthread_create(&tid[i],NULL,fun,NULL);
	if(r!=0)printf("Process creation failed");
	pthread_join(tid[i],NULL);	
	scanf("%d",&bt[i]);
	scanf("%d",&at[i]);
	pt[i]=0;
	pl[i]=1;
	}
}

int main()
{
	pthread_t tid1;
	int n;
	scanf("%d",&n);
	int r=pthread_create(&tid1,NULL,create_Process,(void*)n);
	if(r!=0)printf("Thread creation failed");
	pthread_join(tid1,NULL);
	scheduler();
	printf("\n");
	for(int i=0;i<tp;i++)
	{
		printf("%d  %d  %d \n ",pl[i]+1,tt[i],wt[i]);
	}
}
