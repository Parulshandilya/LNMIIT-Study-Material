#include<stdio.h>
int calsum(int a);
int main()
{
	int n,s;
	printf("Enter the number \t");
	scanf("%d",&n);
	s=calsum(n);
	printf("\n Sum is %d",s);
	return 0;
}
int calsum(int a)
{
	int s=0;
	while(a!=0)
	{
	s=s+a%10;
	a=a/10;
	}
	return s;
}
