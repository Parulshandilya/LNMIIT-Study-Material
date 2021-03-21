#include <stdio.h>

int main()
{
    long long A[100],B[100],i,N,S,j,p,C[100];
    
    scanf("%lld",&N);
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
