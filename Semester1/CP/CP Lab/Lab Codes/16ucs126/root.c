#include<stdio.h>
#include<math.h>
int main()
{
	float p,q,d,a,b,c;
	l:
	printf("\n Enter value of a for ax^2+bx+c");
	scanf("%f",&a);
	printf("Enter value of b for ax^2+bx+c");
	scanf("%f",&b);
	printf("Enter value of c for ax^2+bx+c");
	scanf("%f",&c);
	d=b*b-4*a*c;
	if (d<0)
	{
	printf("Roots are not real");
	goto l;
	}
	else
	{
	p=(-b+sqrt(d))/2*a;
	q=(-b-sqrt(d))/2*a;
	printf("%2f and %2f are the roots of the equation",p,q);
	}
	return 0;
}
