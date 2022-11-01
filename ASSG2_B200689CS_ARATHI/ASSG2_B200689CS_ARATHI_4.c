#include<stdio.h>
#include<stdlib.h>
int* INSERTIONSORTAS(int* arr,int n) 
{int i,j,temp;
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
     
       return arr;
}
int* INSERTIONSORTDS(int* arr,int n) 
{int i,j,temp;
    for(i=1;i<n;i++)
       {
           temp=arr[i];
            j=i-1;
            while(j>=0)
            {
             if(arr[j]<temp)
               {
                   arr[j+1]=arr[j];
                    j--;
                }
                else break;
            }
            arr[j+1]=temp;
       }
     
  return arr;
}
int PRINT(int*arr,int n)
{
    int i;
    for(i=0;i<n;i++)
          printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
int main()
{    
    int n,i,j=0,k=0,evn_no,odd_no;
    scanf("%d",&n);
    int*arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);//all input over
    if(n%2==0)
       {
        evn_no=n/2;
        odd_no=n/2;
       }
      else
       {
        evn_no=(n+1)/2;
        odd_no=(n-1)/2;
       }
    int*even=(int*)malloc(evn_no*sizeof(int));
    int*odd=(int*)malloc(odd_no*sizeof(int));
    for(i=0;i<n;i++)
        {
        if(i%2==0)
           {even[j]=arr[i];j++;}
        else
           {odd[k]=arr[i];k++;}
        }//even and odd positioned arrays created
    INSERTIONSORTAS(even,evn_no);
    INSERTIONSORTDS(odd,odd_no);
    PRINT(even,evn_no);
    PRINT(odd,odd_no);
     return 0;
}
