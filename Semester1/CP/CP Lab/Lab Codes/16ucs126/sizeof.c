#include<stdio.h>
int main()
{
	int a,b,c,s;
	float d;
	char e;			//declaring variable
	c=sizeof(a);
	b=sizeof(d);
	s=sizeof(e);		//assigning sizes of the variable
	printf("size of integer is %d \n",c);
	printf("size of float is %d \n",b);
	printf("size of character is %d \n",s);		//printing 
	return 0;
}
