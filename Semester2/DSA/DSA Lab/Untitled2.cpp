#include <stdio.h>

int main()
{
    long long N,j;
    int M;
    int i;
    long long A[1000000000],B[6],S,t=0;
    scanf("%lld",&N);
    scanf("%d",&M);
    
        for(j=0;j<N;j++)
        {
        scanf("%lld",&A[j]);    
        }
    
     for(i=0;i<M;i++)
    {
        for(j=i;j<M;j++)
        {
            if(A[i]>A[j])
            {
                S=A[i];
                A[i]=A[j];
                A[j]=S;
                
            }
        }
    }
    S=0;
     for(i=M-N;i<M;i++)
    {
        S=S+A[i];
        
        
    }
    printf("%lld",S);
    
    return 0;
}
