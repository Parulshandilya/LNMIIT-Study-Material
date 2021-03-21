#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter first number a");
	scanf("%d",&a);
	printf("\n enter second number b");
	scanf("%d",&b);
	c=a;		//saving the value of a in c
	a=b;		//changing the value of a as that of b
	b=c;		//changing the value of b as that of a
	printf("\n Displaying a and b after interchanging");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	return 0;
}
