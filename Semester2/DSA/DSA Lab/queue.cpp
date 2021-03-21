#include<stdio.h>
#include<stdlib.h>
int s[50];
int top=-1;
void push(int x)
{
	s[++top]=x;
}
int pop()
{
	return[top--];
}

int main()
{
	
}
