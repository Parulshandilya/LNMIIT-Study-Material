#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter number");
	scanf("%d",&a);
	b=a%2;
	if(b==0)
	{printf("\neven");
	}
	else
	{printf("\nodd");
	}
	return 0;
}
