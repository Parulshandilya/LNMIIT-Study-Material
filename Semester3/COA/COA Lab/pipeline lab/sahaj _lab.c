#include <stdio.h>
#include <string.h>

typedef struct opcode{
	char s[20];
	char opc[20];	
}opcode;

typedef struct regi{
	char s[20];
	char reg[20];
}regi;

int main(){
	int i;
	opcode 	op[4]={{"00000","ADD"},{"00001","SUB"},{"00010","AND"},{"00011","OR"}};
	regi r[9] = {{"0000","R1"},{"0001","R2"},{"0010","R3"},{"0011","R4"},{"0100","R5"},{"0101","R6"},{"0110","R7"},{"0111","R8"},{"1000","R9"}};
	char last1[4];
	char last2[4];
	char opf[5];
	int count=0;
	int p=4;
	while(p--){
		count++;
		char s[20];
		char q[6];
		char a1[5];
		char a2[5];
		char a3[5];
		scanf("%s",s);
		for(i=0;i<5;i++)
			q[i]=s[i];
		q[5]='\0';
		for(i=5;i<9;i++)
			a1[i-5]=s[i];
		a1[4]='\0';
		for(i=9;i<13;i++)
			a2[i-9]=s[i];
		a2[4]='\0';
		for(i=13;i<17;i++)
			a3[i-13]=s[i];
		a3[4]='\0';
		//printf("%s %s %s %s\n",q,a1,a2,a3);
		//printf("%s\n",last);
		for(i=0;i<4;i++){
			if(strcmp(op[i].s,q)){
				strcpy(opf,op[i].s);
			}
		}
		for(i=0;i<9;i++){
			if(strcmp(r[i].s,a1)==0){
				if(strcmp(last1,a1)==0){
					printf("Hazard for %s between %d and %d instruction\n",r[i].reg,count,count-1);
					break;
				}
				if(strcmp(last2,a1)==0){
					printf("Hazard for %s between %d and %d instruction\n",r[i].reg,count,count-2);
					break;
				}
			}
		}
		for(i=0;i<9;i++){
			if(strcmp(r[i].s,a2)==0){
				if(strcmp(last1,a2)==0){
					printf("Hazard for %s between %d and %d instruction\n",r[i].reg,count,count-1);
				break;
				}
				if(strcmp(last2,a2)==0){
					printf("Hazard for %s between %d and %d instruction\n",r[i].reg,count,count-2);
				break;
				}
			}
		}
		for(i=0;i<9;i++){
			if(strcmp(r[i].s,a3)==0){
				strcpy(last2,last1);
				strcpy(last1,a3);
				break;
			}	
		}
	}
	return 0;
}
