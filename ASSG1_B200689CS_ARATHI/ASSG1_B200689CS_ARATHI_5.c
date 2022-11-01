#include <stdio.h>
#include <stdlib.h>

int* merge(int *A1,int *A2,int n1,int n2)
{
    int*A3 = (int*)malloc((n1+n2)*sizeof(int));
    for(int i=0;i<n1;i++)
        A3[i]=A1[i];
    for(int i=n1,j=0;i<(n1+n2);i++,j++)
        A3[i]=A2[j];
    return A3;
}

int arrange(int n3, int *A3)
{
	int i, j, k,m=0, count=1, status=0, prev=0;
	int*A4 = (int*)malloc((n3)*sizeof(int));
	for(i=1;i<=n3;i++)
    {
        for(k=0;k<i-1;k++)
        {
            if(A3[i-1]==A3[k])
            prev = 1;
        }
 
		if(prev == 0)
        {
            for(j=i;j<n3;j++)
            {
                if(A3[i-1]==A3[j])
                {
                    if(count == 1)
                    {
                        printf("%d ",A3[i-1]);
						A4[m] = A3[i-1];
						m++;
                    }
                    printf("%d ",A3[j]);
                    count++;
                }
            }
        }
		count = 1;
		prev = 0;

	}

	for(int i=0;i<n3;i++)
	{
		for(int j=0;j<k;j++)
		{

			if(A3[i] == A4[j])
			{
				status = 1;
			    break;
			}
		}
	if(status == 0)
		printf("%d ",A3[i]);
	status = 0;
	}
	free(A4);
    return 0;
}


int main()
{
    int n1,n2,i;
    scanf("%d %d ",&n1,&n2);
    int*A1 = (int*)malloc(n1*sizeof(int));
    for(i=0;i<n1;i++)
        scanf("%d",&A1[i]);
    int*A2 = (int*)malloc(n2*sizeof(int));
    for(i=0;i<n2;i++)
        scanf("%d",&A2[i]);
    int*A3=(int*)malloc((n1+n2)*sizeof(int));
    A3=merge(A1,A2,n1,n2);
    arrange(n1+n2,A3);

    return 0;
}

