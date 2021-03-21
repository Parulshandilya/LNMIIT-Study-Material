#include<stdio.h>
int main()
{
	int s,i,n,c=0,t=0;
	printf("enter a number");
	scanf("%d",&n);
	s=n;
	while(n!=0)
	{c=c+1;
	n=n/10;
	}
	n=s;
	for(i=0;i<c;i++)
	{
	t=t*10+n%10;
	n=n/10;
	}
	printf("reversed number is:%d",t);
	if(t==s)
	{
	printf("number is a palindrome");
	}
	else
	{
	printf("number is not a palindrome");
	}
	return 0;
}
