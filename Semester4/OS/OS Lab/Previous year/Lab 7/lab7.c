#include<stdio.h>



//int a[nop];

int no_of_pages(int mem)
{
	int count;	
	if(mem % 16==0)
		count= mem/16;
	else
		count= ((mem/16)+1);
	return count;
}

struct node{
	int segid;
	char segpart;
};

struct node a[128];

int alocated(int segid,int tnop,int hnop,int snop)
{
	int i,j,count=0;
	int flag=0,tc=0,hc=0,sc=0;
	for(i=0;i<128;i++)
	{
	if(a[i].segid==-10)
		count++;
	}
	i=0;
	if(count>=(tnop+hnop+snop))
	{
		count=0;
		while(i<128)
		{
			if(a[i].segid==-10)
			{
				
				if(tc!=tnop){
					tc++;
					a[i].segpart='t';
				}
				else if(hc!=hnop)
				{
					hc++;
					a[i].segpart='h';
				}
				else if(sc!=snop)
				{
					sc++;
					a[i].segpart='s';
				}
				a[i].segid=segid;
				count++;
			}
			i++;
			if(count==tnop+hnop+snop)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
		return 1;
	else
		return 0;
}

int dealocated(int sid)
{
	int i,flg=0;
	for(i=0;i<128;i++)
	{
		if(a[i].segid==sid)
		{
			flg=1;
			a[i].segid=-10;
			a[i].segpart='f';
		}
	}
	if(flg==1)
		return 1;
	else
		return 0;
	
}

void display()
{
	int i;
	printf("\nMemory Table\n");
	printf("Page Number\tSegment Part\tSegment Number\n");
	for(i=0;i<128;i++)
	{
		printf("%d\t\t%d\t\t%c\n",i,a[i].segpart,a[i].segid);
	} 
}
int main()
{
	int choice=0,i,tre,heap,text,stack,tnop,snop,hnop,sid;
	//printf("hi\n");
	for(i=0;i<128;i++)
	{
		a[i].segid=-1;
		a[i].segpart='f';
	}

	do
	{
		printf("Choose from the following:\n");
		printf("1.alocatedate\n2.Dealocatedate\n");
		printf("Enter your Choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Segment Id,size of text,size of heap,size of stack in terms of size and not page numbers\n");
				scanf("%d%d%d%d",&sid,&text,&heap,&stack);
				tnop=no_of_pages(text);
				hnop=no_of_pages(heap);
				snop=no_of_pages(stack);
				tre=alocated(sid,tnop,hnop,snop);
				if(tre)
				{
					display();
					printf("\n\n");
				}
				else
					printf("Not much memory space left Try to dealocate a segment\n");
				break;
			case 2:
				printf("enter segment id\n");
				scanf("%d",&sid);
				tre=dealocated(sid);
				if(tre)
					printf("dealocated successfully\n");
				else
					printf("segment doesn't exist in memory\n");
				break;
			default:
				break;//exit(0);
		}
	}while(choice==1||choice==2);
	return 0;
}


