#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("\nenter 1 number	");
	scanf("%d",&a);
	printf("\nenter 2 number	");
	scanf("%d",&b);
	printf("\nenter 3 number	");
	scanf("%d",&c);
	if(a>b)
	{
		if(b>c)
		{d=c;
		}
		else
		{d=b;
		}
	}
	else if(a<c) 
	{	d=a;
	}
	else
	{	d=c;
	}
	printf("smallest is %d",d);
	return 0;
}
