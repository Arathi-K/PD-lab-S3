#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, k, count=1, status=-1, prev=0;
    scanf("%d",&n);
    int* A = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    for(i=1;i<=n;i++)
    {
        for(k=0;k<i-1;k++)
        {
            if(A[i-1]==A[k])
            prev = 1;
        }
        if(prev == 0)
        {
            for(j=i;j<n;j++)
            {
                if(A[i-1]==A[j])
                {
                    if(count == 1)
                    {
                        printf("%d ",A[i-1]);
                        printf("%d ",i-1);
                    }
                    printf("%d ",j);
                    status=1;
                    count++;
                }
            }
        }
        if(count > 1)
            printf("%d\n",count);
        count = 1;
        prev = 0;
        
    }
    if(status == -1)
      printf("%d\n",status);
      
    return 0;
    
}
                              
