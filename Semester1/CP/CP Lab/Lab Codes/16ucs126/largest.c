#include<stdio.h>
int main()
{
	int a,b,c;
	printf(" enter first number");
	scanf("%d",&a);
	printf("\n enter second number");
	scanf("%d",&b);
	printf("\n enter third number");
	scanf("%d",&c);
	if(a>b&&a>c)
	{	
		printf("\n Largest number is %d",a);
	}
	else if(b>a&&b>c)
	{	
		printf("\n Largest number is %d",b);
	}
	else if(c>a&&c>b)
	{	
		printf("\n Largest number is %d",c);
	}
	return 0;
}
