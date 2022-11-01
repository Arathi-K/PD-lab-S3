#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m,x,i,j,temp,max_sum=0, min_sum=0;
    scanf("%d %d",&n,&m);
    x=n-m;
    int* arr=(int*)malloc(n*sizeof(int));
      for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
   for(i=1;i<n;i++)
       {
           temp=arr[i];
            j=i-1;
            while(j>=0)
            {
             if(arr[j]>temp)
               {
                   arr[j+1]=arr[j];
                    j--;
                }
                else break;
            }
            arr[j+1]=temp;
       }
      
    for(i=0;i<x;i++)
        min_sum+=arr[i];
    for(i=n-1;i>(n-1-x);i--)
        max_sum+=arr[i];
    printf("%d",max_sum-min_sum);
    return 0;
}
