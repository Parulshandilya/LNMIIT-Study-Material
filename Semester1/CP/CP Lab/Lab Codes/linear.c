#include<stdio.h>
int main()
{
	int x1,x2,x3,y1,y2,y3,s;
	char c;
	do
	{
	printf("\nenter the value of x1\t");
	scanf("%d",&x1);
	printf("\nenter the value of x2\t");
	scanf("%d",&x2);
	printf("\nenter the value of x3\t");
	scanf("%d",&x3);
	printf("\nenter the value of y1\t");
	scanf("%d",&y1);
	printf("\nenter the value of y2\t");
	scanf("%d",&y2);
	printf("\nenter the value of y3\t");
	scanf("%d",&y3);
	s=x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2;
	if(s==0)
	printf("\ncollinear");
	else
	printf("\nnot collinear");
	printf("Enter y if you want to repeat the process");
	scanf(" %c",&c);
	}while(c=='y');
	return 0;
}
