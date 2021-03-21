#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	printf("enter 1 no \t");
	scanf("%d",&a);
	printf("enter 2 no \t");
	scanf("%d",&b);
	printf("enter 3 no \t");
	scanf("%d",&c);
	printf("enter 4 no \t");
	scanf("%d",&d);
	if(a<b)
	f=a;
	else
	f=b;
	if(c<d)
	e=a;
	else
	e=b;
	if(e>f)
	printf("%d is smallest",f);
	else
	printf("%d is smallest",e);
	return 0;

}
