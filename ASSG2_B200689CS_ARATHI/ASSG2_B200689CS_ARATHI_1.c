#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,sum=0,count=0,fr=0,highest=0;
    scanf("%d",&n);
    int*arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
     {
      scanf("%d",&arr[i]);
      if(arr[i]>=0)
       {
           sum=sum+arr[i]; 
           count++;
       }
      else
       { if(fr==0)
          {highest=arr[i];
			  fr=1;}
	   }
      }
       
     if(count!=0)
       printf("%d %d",sum,count);
     else
       {
           for(i=0;i<n;i++)
           { if(arr[i]>highest)
                highest=arr[i];
           }
           printf("%d 1",highest);
       }
       return 0;
}
