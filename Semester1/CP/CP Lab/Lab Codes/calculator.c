#include<stdio.h>
int main()
{
	int c,a,b;
	float s;
	char c1;
	do
	{
	printf("1 Add the Numbers");
	printf("\n2 Subtract the Numbers");
	printf("\n3 Multiply the Numbers");
	printf("\n4 Divide the Numbers");
	printf("\nEnter your choice:\t");
	scanf("%d",&c);
	printf("\nEnter first number:\t");
	scanf("%d",&a);
	printf("\nEnter second number:\t");
	scanf("%d",&b);
	switch(c)
	{
	case 1:
	s=a+b;
	break;
	case 2:
	s=a-b;
	break;
	case 3:
	s=a*b;
	break;
	case 4:
	while(b==0)
	{printf("Enter second number again");
	scanf("%d",&b);
	}
	s=(float)a/(float)b;
	break;
	default:
	printf("\nInvalid entry");
	}
	printf("Result is: %.2f",s);
	printf("\nIf you want to calculate again enter y for yes and n for n ");
	scanf(" %c",&c1);
	}while(c1=='y');
	return 0;
}
