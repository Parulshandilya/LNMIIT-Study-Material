#include<stdio.h>

int prime(int n);			//function declaration

int main()
{
	int i,a;
	printf("Prime numbers between 300 to 500 are:");	
	for(i=300;i<=500;i++)
	{
	 a=prime(i);			//calling the function prime
	 if(a==1)
	 {
	 printf("%d,",i);
	 }	
	}	
	return 0;

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
