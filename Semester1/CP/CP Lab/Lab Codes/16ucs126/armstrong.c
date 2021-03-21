#include<stdio.h>
int main()
{
	int a,b,c,s;
	c=0;
	printf("Enter the number to be checked \t");
	scanf("%d",&a);
	s=a;
	while(a!=0)
	{b=a%10;
	c=b*b*b+c;
	a=a/10;
	}
	
	if(c==s)
	printf("Number is an armstrong");
	else
	printf("Number is not an armstrong");
	return 0;
}
