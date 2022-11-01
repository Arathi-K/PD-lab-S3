#include <stdio.h>
#include<stdlib.h>
int main()
{
    int ar_size,i,last,element,status=-1;
    scanf("%d",&ar_size);
    int* ar =(int*)malloc(ar_size*sizeof(int));
    for(i=0;i<ar_size;i++)
       scanf("%d",&ar[i]); 
    for(i=0;i<ar_size;i++)   
       { element=ar[i];
         do
         {
         last=ar[i]%10;
         ar[i]=ar[i]/10;
         }while((ar[i]%10 <= last)&& ar[i]>0);
         if(ar[i]==0)
           {printf("%d ",element);status=1;}
        }
    if(status!=1)
      printf("-1");
    return 0;
    
}
