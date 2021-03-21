#include<stdio.h>
int main()
{	
	int s,l,i;
	l=0;
	printf("Enter the number to be checked \t");
	scanf("%d",&s);			//Taking number from user
	for(i=1;i<s;i++)		
	{
	 				
	 if(s%i==0)			//Finding factors
	 l=l+i;				//Adding factors
	}	
	if(s==l)
	printf("Number is a perfect number");	//Checking if the number is perfect or not
	else
	printf("Not a perfect number");
	return 0;
}
