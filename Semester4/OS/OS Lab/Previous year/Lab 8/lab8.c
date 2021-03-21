#include<stdio.h>
#define PG_SIZE 16
#define main_mem 4

struct PageTable {
	int thread;
	int fr_no;
};

struct PageTable ptable[4];

struct Process {
	int pages;
	int pid;
};

int main() { 

	int n,i,pd,pg;
	int present,frame,recent,counthit=0,countfault=0;
	printf("Enter number of processes:\n");
	scanf("%d",&n);
	for(i=0;i<4;i++)
		ptable[i].thread=0;
	for(i=0;i<4;i++)
		ptable[i].fr_no=0;
	struct Process proc[n];
	
	printf("Process Id \t Number of Pages\n");
	
	for(i=0;i<n;i++) {
		proc[i].pid=i+1;
		proc[i].pages=rand()%7;
		
		printf(" %d \t \t %d \n", proc[i].pid, proc[i].pages);
	}
	
	printf("Enter the process id:\n");
	scanf("%d",&pd);

	while(pd!=0) {
		
		printf("Enter the pages required in process %d: \n",pd);
		scanf("%d",&pg);
		
		if(pg<=proc[pd-1].pages) {
			for(i=0;i<4;i++) {
				if(ptable[i].thread==pd && ptable[i].fr_no==pg) {
					present=1;
					recent=i;
					counthit++;
					printf("Hit occured!\n");
					break;
				}
			}
			if(present==0) {
				for(i=0;i<4;i++) {
					if(ptable[i].thread==0) {
						printf("Page fault occured!\n");
						ptable[i].thread=pd;
						ptable[i].fr_no=pg;
						recent=i;
						frame=1;
						countfault++;
						break;
					}
				}
			}		
				
			if(frame==0) {
				printf("Page fault occured\n");
				countfault++;
				ptable[recent].fr_no=pg;
				ptable[recent].thread=pd;
				break;
			}
		
			printf("Page is in memory\n");
			printf("Process Id \t Frame No\n");
			for(i=0;i<4;i++)
				printf("%d \t \t %d\n",ptable[i].thread,ptable[i].fr_no);
		}
		printf("Enter process id\n");
		scanf("%d",&pd);
		present=0;
		frame=0;
	}

	
	printf("Hits are : %d and Faults are : %d",counthit,countfault);
	
	return 0;
}
