#include<stdio.h> 

main(){
	int i;
	int j;
	int n=5;
	int m=4;
	
	for (j=1;j<m+1;j++){
		for (i=1;i<j+1;i++){
			printf("%d ",j);
		}
		printf("\n");
	}
}
