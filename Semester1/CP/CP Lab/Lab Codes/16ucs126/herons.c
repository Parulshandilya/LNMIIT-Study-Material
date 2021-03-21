#include<stdio.h>
#include<math.h>
int main ()
{
	float a,b,c,f,s;
	printf("Enter side 1:");
	scanf("%f",&a);
	printf("\n Enter side 2:");
	scanf("%f",&b);
	printf("\n Enter side 3:");
	scanf("%f",&c);			//taking input from user 
	s=(a+b+c)/2;	
	f=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("\n area is %f /n",f);
	return 0;
}
