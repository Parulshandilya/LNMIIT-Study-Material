#include<stdio.h>
int main()
{
	int d,f;
	printf("Enter number of days:\t");
	scanf("%d",&d);
	if(d<=5&&d>=1)
	{f=2*d;
	printf("Fine money is: Rs %d",f);
	}
	else if(d<=10&&d>=6)
	{f=10+5*(d-5);
	printf("Fine money is Rs %d",f);
	}
	else if(d<=30&&d>=11)
	{f=35+10*(d-10);
	printf("Fine money is Rs %d",f);
	}
	else if(d>30)
	printf("Membership Cancelled!!!");
	else
	printf("Invalid entry");
	return 0;
}
