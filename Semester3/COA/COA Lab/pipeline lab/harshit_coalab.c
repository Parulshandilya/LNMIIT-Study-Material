#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f[100]={0},d[100]={0},e[100]={0},w[100]={0},reg[15]={0};
// LOAD = 001
// SUB = 010
// AND = 011
// NOP=100
int Register(char a[],int index)
{
	char b[10];
	int i,l;
	for(i=0;i<4;i++)
	{
		b[i]=a[i+index];
		//printf("%c",a[i]);
	}
	b[i]='\0';
	
	if(strcmp(b,"0000")==0)
	{
        	return 0;
	}
	if(strcmp(b,"0001")==0)
	{
        	return 1;
	}
	if(strcmp(b,"0010")==0)
	{
        	return 2;
	}
	if(strcmp(b,"0011")==0)
	{
	        return 3;
	}
	if(strcmp(b,"0100")==0)
	{
	        return 4;
	}
	if(strcmp(b,"0101")==0)
	{
	        return 5;
	}
	if(strcmp(b,"0110")==0)
	{
        	return 6;
	}
	if(strcmp(b,"0111")==0)
	{
        	return 7;
	}
	if(strcmp(b,"1000")==0)
	{
	        return 8;
	}

	if(strcmp(b,"1001")==0)
	{
	        return 9;
	}
	if(strcmp(b,"1010")==0)
	{
        	return 10;
	}
	if(strcmp(b,"1011")==0)
	{
        	return 11;
	}
	if(strcmp(b,"1100")==0)
	{
        	return 12;
	}
	if(strcmp(b,"1101")==0)
	{
        	return 13;
	}
	if(strcmp(b,"1110")==0)
	{
        	return 14;
	}
	if(strcmp(b,"1111")==0)
	{
        	return 15;
	}
}
int getOpcode(char a[])
{
	char b[10];
	int i,l;
	for(i=0;i<3;i++)
	{
		b[i]=a[i];
	}
	b[i]='\0';
	if(strcmp(b,"001")==0)
	{
		return 1;
	}
	if(strcmp(b,"010")==0)
	{
		return 2;
	}
	if(strcmp(b,"011")==0)
	{
		return 3;
	}
	if(strcmp(b,"100")==0)
	{
		return 4;
	}
	
}
int main()
{
	char inst[100],op1[100],op2[100],op3[100];
	int opcode[100],oper1[100],oper2[100],oper3[100],i=0;
	FILE* fp = fopen("input.txt","r");
	while(fscanf(fp,"%s",inst)==1){
	
		opcode[i]=getOpcode(inst);
		oper1[i]=Register(inst,3);
		oper2[i]=Register(inst,7);
		oper3[i]=Register(inst,11);
		printf("%d %d %d\n",oper1[i],oper2[i],oper3[i]);
		if(reg[oper1[i]]==2||reg[oper2[i]]==2)//if oper3 was previously in write mode and now in read mode display error
		{
			printf(" DATA HAZARD\n");
			if(reg[oper1[i]]==2){
				printf("hazard at register: %d\n", oper1[i]);
			}
			if(reg[oper2[i]]==2){
				printf("hazard at register: %d\n", oper2[i]);
			}
		}
		if(i>=0){
			f[i]=1;
			
		}
		if(i>=1){
			d[i-1]=1;
			
		}	
		if(i>=2){
			e[i-2]=1;
			
		}
		if(i>=3){
			w[i-3]=1;
			
			
		}
		reg[oper1[i]]=1;//read
		reg[oper2[i]]=1;//read			
		reg[oper3[i]]=2;//write
		
		i++;
	}	
	
	
	
}


