 #include<stdio.h>
 
 int main()
 {
 	int A[3],i,j,S;
 	A[0]=8;
 	A[1]=8;
 	A[2]=9;

 for(i=0;i<3;i++)
    {
        for(j=i;j<3;j++)
        {
            if(A[i]<A[j])
            {
                S=A[i];
                A[i]=A[j];
                A[j]=S;
                
            }
        }
	}
	for(i=0;i<3;i++)
	{
		printf("%d",A[i]);
	}
}
