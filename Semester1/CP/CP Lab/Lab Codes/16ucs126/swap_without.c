#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter a");
	scanf("%d",&a);
	printf("\n Enter b");
	scanf("%d",&b);			//taking the values from user
	a=a+b;				//we assigned sum of the numbers in a
	b=a-b;				//we assigned value of a in b by subtracting the value of b from the sum 
	a=a-b;				//we assigned value of b in a by subtracting the value of a from the sum 
	printf("\nDisplaying the swaped numbers");
	printf("\n a=%d ",a);
	printf("\n b=%d ",b);
	return 0;
}
