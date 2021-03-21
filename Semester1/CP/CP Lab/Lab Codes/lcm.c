#include<stdio.h>

int lcm(int a,int b);			//function declaration
int prime(int n);
int main()
{
	int a,b,l;
	printf(" Enter 1 number ");
	scanf("%d",&a);
	printf("\n Enter 2 number ");
	scanf("%d",&b);
	l=lcm(a,b);
	printf("\n lcm of the two number is %d",l);
	return 0;
}
int lcm(int a,int b)			//function defining
{
	int e,s=1,d,i,c,p;
	
	if(a<b)
	{e=b;
	 p=a;
	}	
	else
	{e=a;
	 p=b;
	}
	for(i=1;i<=e;i++)
	{
	 if(prime(i)==1)
	 {	
	  if(a%i==0||b%i==0)
	  {
	    c=e;
	    d=p;
	    
	    while(c%i==0||d%i==0)
	    {
	    s=s*i;
	    if(c%i==0)
	    c=c/i;
	    if(d%i==0)
	    d=d/i;
	    }
	    
	    
	  }
	 }	
	}
	return s;
}
int prime(int n)			//function defination
{
	int i,s=0;
	
	if(n==1)			//checking if the number is one
	s=1;
	else				//checking whether the number is prime or not	
	{
	 for(i=2;i<n;i++)
	 {
	 if(n%i==0)
	 s=1;
	 }
	}
	
	if(s==1)
	return 0;			//0 for non prime numbers
	else
	return 1;			//1 for prime numbers
}
