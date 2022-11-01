#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void  MAX_HEAPIFY(int* arr, int n, int i)
{
     // Initialize largest as root
    int largest;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l]>arr[i])
        largest = l;
    else largest =i;    
    

    // If right child is larger than largest so far
    if (r < n && arr[r]> arr[largest])
        largest = r;
  int temp;

    if (largest != i) 
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
 
        // Recursively heapify the affected sub-tree
        MAX_HEAPIFY(arr, n, largest);
    }
}
void BUILD_MAX_HEAP(int* arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        MAX_HEAPIFY(arr,n,i);
}
void HEAPSORT(int* local,int n)
{   BUILD_MAX_HEAP(local,n);
    // One by one extract an element from heap
    int temp;
    for (int i =n-1; i >=1; i--)
    {
        // Move current root to end
        temp=local[0];
        local[0]=local[i];
        local[i]=temp;

        // call max heapify on the reduced heap
        MAX_HEAPIFY(local, i, 0);
      }
}

void MIN_HEAPIFY(int* arr, int n, int i)
{
     // Initialize largest as root
    int smallest;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l]< arr[i])
        smallest = l;
    else smallest =i;
    // If right child is larger than largest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    int temp;
    // If largest is not root
    if (smallest != i)
    {
        temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;

        // Recursively heapify the affected sub-tree
        MIN_HEAPIFY(arr, n,smallest);
    }
}
void DISPLAY_QUEUE(int *Q,int rear)
{
    int local[rear+1];
    for(int i=0;i<=rear;i++)
   {
     local[i]=Q[i];
   }
  HEAPSORT(local,rear+1);
  //printf("\n");
  for(int i=0;i<=rear;i++)
     printf("%d ",local[i]);
 
}
void CHANGE_TOKEN_NUMBER(int*Q,int i,int x,int rear)
{
    Q[i]=x;
   // for(int j=0;j<=rear;j++)
     //   printf("%d",Q[j]);                    
    int temp;
     while(i>0 && Q[(i-1)/2]>Q[i] )
     {
       temp=Q[i];
       Q[i]= Q[(i-1)/2];
       Q[(i-1)/2]=temp; 
       i=(i-1)/2;
     }
     /*for(int j=0;j<=rear;j++)
       printf("%d",Q[j]); */
   //  MIN_HEAPIFY(Q,rear+1,i);
}
void GET_NEXT_PATIENT(int* Q,int rear)
{
   if(rear>=0) printf("%d ",Q[0]);
   else  printf("-1");
}
void INSERT_PATIENT(int* Q,int rear,int k)
{ 
 // INSERT and place in order
  Q[rear]=k;
  int i=rear;
  int temp;
  while(i>0 && Q[(i-1)/2]>Q[i])
     {
       temp=Q[i];
       Q[i]= Q[(i-1)/2];
       Q[(i-1)/2]=temp; 
       i=(i-1)/2;
     }
        //printf("inserted %d at %d\n",k,i);
}

void EXTRACT_NEXT_PATIENT(int* Q,int rear)
{   if(rear>=0)
    {
        printf("%d ",Q[0]);
        Q[0]=Q[rear];
        MIN_HEAPIFY(Q,rear,0);
    }
    else
        printf("-1");
    
    //   printf("new array after exraction is:");
      // for(int i=0;i<=rear;i++)
        //        printf("%d",Q[i]);
}
void main()
 {
    char c;
    int k,x,i,rear=-1;
    int Q[10000];
    while(1)
    {
        scanf("%c",&c);
        switch (c)
        {   case 's': exit(0);
            case 'i': rear++;
                       scanf("%d",&k); 
                     INSERT_PATIENT(Q,rear,k);
                     break;
            case 'e':  EXTRACT_NEXT_PATIENT(Q,rear);
                        rear--;
                        printf("\n");
                        break;
            case 'm': GET_NEXT_PATIENT(Q,rear);
                            printf("\n");
                            break;
            case 'c':scanf("%d %d",&k,&x);
                        for(i=0;i<=rear;i++)
                            if(k==Q[i])
                            {   
                //                printf("rear before changing %d into %d at i=%d is %d\n",k,x,i,rear);
                            CHANGE_TOKEN_NUMBER(Q,i,x,rear);break;
                                   /* {
                                        for(i=0;i<=rear;i++)
                                           if(k==Q[i])printf("%d",i);break;
                                    }*/
                                    //printf("rear after changing%d\n",rear);
                            }
                     break;
            case 'd': DISPLAY_QUEUE(Q,rear);
                       printf("\n");
            
        }
    }
}
