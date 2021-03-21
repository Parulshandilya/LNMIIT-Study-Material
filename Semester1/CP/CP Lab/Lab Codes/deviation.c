#include<stdio.h>
#include<math.h>

float average(int a1,int a2,int a3,int a4, int a5);	//function declaration
float deviation(int a1,int a2,int a3,int a4, int a5);
int sum(int a1,int a2,int a3,int a4, int a5);

int main()
{
	int a1,a2,a3,a4,a5,s;			        //declaring variables
	float avg,sd;
	
	printf(" Enter 1 number ");			//taking inputs from users
	scanf("%d",&a1);
	printf("\n Enter 2 number ");
	scanf("%d",&a2);
	printf("\n Enter 3 number ");
	scanf("%d",&a3);
	printf("\n Enter 4 number ");
	scanf("%d",&a4);
	printf("\n Enter 5 number ");
	scanf("%d",&a5);
	
	s=sum(a1,a2,a3,a4,a5);				//calling functions
	avg=average(a1,a2,a3,a4,a5);
	sd=deviation(a1,a2,a3,a4,a5);
	
	printf("\n Sum is %d",s);			//printing results
	printf("\n Average is %.2f",avg);
	printf("\n Standard deviation is %.2f",sd);

	return 0;
}
int sum(int a1,int a2,int a3,int a4, int a5)
{
	int s;						//declaring variable for this function
	s=a1+a2+a3+a4+a5;				//calculating sum
	return s;					//returning value
}
float average(int a1,int a2,int a3,int a4, int a5)
{
	float avg;
	avg=(float)sum(a1,a2,a3,a4,a5)/5;
	return avg;
}
float deviation(int a1,int a2,int a3,int a4, int a5)
{
	float m,a,sd;					//declaring variable for this function
	m=average(a1,a2,a3,a4,a5);			//calling function for average
	a=(a1-m)*(a1-m)+(a2-m)*(a2-m)+(a3-m)*(a3-m)+(a4-m)*(a4-m)+(a5-m)*(a5-m);
	sd=sqrt(a/5);					//calculating standard deviation
	return sd;					//returning value
}
