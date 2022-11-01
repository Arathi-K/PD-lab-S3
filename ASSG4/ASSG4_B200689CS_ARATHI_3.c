#include <stdio.h>
#include<string.h>

struct Amoeba
{
     int Amoeba_Size;
     char Amoeba_Name[21];
};
struct Amoeba READ(struct Amoeba a)
{
   scanf("%s %d",a.Amoeba_Name,&a.Amoeba_Size);
//	printf("i...%s %d \n",a.Amoeba_Name,a.Amoeba_Size);
   return a; 
}
int INSERT(struct Amoeba* W,int rear,struct Amoeba a )
{
	rear=rear+1;
	int i=rear;
//	printf(".....%d ",rear);
	W[rear].Amoeba_Size=a.Amoeba_Size;
	strcpy(W[rear].Amoeba_Name,a.Amoeba_Name);

	struct Amoeba temp;
    while (i>0 && W[(i-1)/2].Amoeba_Size>W[i].Amoeba_Size)
	{
		temp.Amoeba_Size=W[i].Amoeba_Size;
        W[i].Amoeba_Size=W[(i-1)/2].Amoeba_Size;
        W[(i-1)/2].Amoeba_Size=temp.Amoeba_Size;

		strcpy(temp.Amoeba_Name,W[i].Amoeba_Name);
       strcpy( W[i].Amoeba_Name,W[(i-1)/2].Amoeba_Name);
       strcpy(W[(i-1)/2].Amoeba_Name,temp.Amoeba_Name);

		i=(i-1)/2;
	}
  //  printf("inserted...%s %d \n",W[i].Amoeba_Name,W[i].Amoeba_Size); 
	return rear;
}
void  MAX_HEAPIFY(struct Amoeba* arr, int n, int i)
{
     // Initialize largest as root
    int largest;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].Amoeba_Size>arr[i].Amoeba_Size)
        largest = l;
    else largest =i;


    // If right child is larger than largest so far
    if (r < n && arr[r].Amoeba_Size> arr[largest].Amoeba_Size)
        largest = r;
  struct Amoeba temp;

    if (largest != i)
    {
        temp.Amoeba_Size=arr[i].Amoeba_Size;
        arr[i].Amoeba_Size=arr[largest].Amoeba_Size;
        arr[largest].Amoeba_Size=temp.Amoeba_Size;

        strcpy(temp.Amoeba_Name,arr[i].Amoeba_Name);
        strcpy(arr[i].Amoeba_Name,arr[largest].Amoeba_Name);
        strcpy(arr[largest].Amoeba_Name,temp.Amoeba_Name);


        // Recursively heapify the affected sub-tree
        MAX_HEAPIFY(arr, n, largest);
    }
}
void BUILD_MAX_HEAP(struct Amoeba* arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        MAX_HEAPIFY(arr,n,i);
}
void HEAPSORT(struct Amoeba* local,int n)
{   BUILD_MAX_HEAP(local,n);
    // One by one extract an element from heap
    struct Amoeba temp;
    for (int i =n-1; i >=1; i--) {
        // Move current root to end
        temp.Amoeba_Size=local[0].Amoeba_Size;
        local[0].Amoeba_Size=local[i].Amoeba_Size;
        local[i].Amoeba_Size=temp.Amoeba_Size;

        strcpy(temp.Amoeba_Name,local[0].Amoeba_Name);
        strcpy(local[0].Amoeba_Name,local[i].Amoeba_Name);
        strcpy(local[i].Amoeba_Name,temp.Amoeba_Name);


        // call max heapify on the reduced heap
        MAX_HEAPIFY(local, i, 0);
    }
}
void COMBINE(struct Amoeba* W,int rear)
{  // MIN_HEAPIFY(W, rear,0);
	HEAPSORT(W,rear+1);
	int f=0,s=0;
	
	int countf=0;
 //   for(int i=0;i<=rear;i++)
        // printf("......iii%d ",W[i].Amoeba_Size);
	  for(int i=0;i<=rear;i++)
	           if (W[i].Amoeba_Size==W[0].Amoeba_Size)
	              countf++;
	      
	 //printf("countf = %d", countf);
	  if(countf>1)
	  {   
	      for(int i=1;i<countf;i++)
	      {
	          if (strcmp(W[f].Amoeba_Name,W[i].Amoeba_Name)>0)
		     	 f=i;
          }
	      //printf("\n f = %d", f);
	      for(int i=0;i<countf;i++)
	      {
	          if(i != f)
	          {
	            if (strcmp(W[s].Amoeba_Name,W[i].Amoeba_Name)>0)
		     	    s=i;
		     	    
	          }
	          
          }
         // printf("\n s = %d", s);
	      
	  }
	  else
	  {   s=1;
	      int counts=0;
	      for(int i=1;i<=rear;i++)
	           if (W[i].Amoeba_Size==W[1].Amoeba_Size)
	              counts++;
	     
	       if(counts>1)
	       {   
	          for(int i=1;i<=counts;i++)
	           {
	             if (strcmp(W[s].Amoeba_Name,W[i].Amoeba_Name)>0)
		     	  s=i;
                }     
	       }
	  }
            int sum;
   			if(rear!=0)
			{
			   	sum=W[f].Amoeba_Size + W[s].Amoeba_Size;
				printf("%s %s %d \n",W[f].Amoeba_Name,W[s].Amoeba_Name,sum);
			}
			else
			   printf("%s %d \n",W[f].Amoeba_Name,W[f].Amoeba_Size);
			   
            W[f].Amoeba_Size=sum;
     	//	struct Amoeba temp=W[s];
			struct Amoeba temp;
			temp.Amoeba_Size = W[s].Amoeba_Size;
			strcpy(temp.Amoeba_Name, W[s].Amoeba_Name);


			W[s].Amoeba_Size = W[rear].Amoeba_Size;
			strcpy(W[s].Amoeba_Name, W[rear].Amoeba_Name);


			W[rear].Amoeba_Size = temp.Amoeba_Size;
			strcpy(W[rear].Amoeba_Name, temp.Amoeba_Name);
       	//	 W[s]=W[rear];
       	//	 W[rear]=temp;
			rear--;
			if(rear>=0)
			COMBINE(W,rear);

}
void main()
{   int n;
	scanf("%d",&n);
	struct Amoeba a;
	struct Amoeba W[n];
	int rear=-1;
	for(int i=0;i<n;i++)
	{
		a=READ(a);
	//	printf("kkk...%s %d \n",a.Amoeba_Name,a.Amoeba_Size);

		rear = INSERT(W,rear,a);
	}
/*	for(int i=0;i<n;i++)
		printf("last...%s %d \n",W[i].Amoeba_Name,W[i].Amoeba_Size);*/

    COMBINE(W,rear);
}
