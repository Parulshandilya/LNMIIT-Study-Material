#include <stdio.h>
long long A[1000000],B[1000000],C[1000000];

int main()
{
    long long i,N,S,j,p;
    
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%lld",&A[i]);
        C[i]=0;
    }
    
    for(i=0;i<N;i++)
    {
    	for(j=i+1;j<N;j++)
    	{
    		if(A[i]>A[j])
    		{C[i]++;
    		}
    		else
    		break;
    		
		}
    	
	}
	 S=0;
      for(i=0;i<N;i++)
    {
        if(S<C[i])
        {S=C[i];
        p=i;
        }
        else if(S==C[i])
        {
            if(A[i]>A[p])
            p=i;
            else
            p=p;
        }
        
     }
    printf("%lld",p+1);
    return 0;
    
}

