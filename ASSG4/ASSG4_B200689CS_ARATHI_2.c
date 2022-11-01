#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct vidh
{
     int Student_id;
     char Student_name[21];
     int Rank;
};

void  MAX_HEAPIFY(struct vidh* arr, int n, int i)
{
     // Initialize largest as root
    int largest;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l].Rank>arr[i].Rank)
        largest = l;
    else largest =i;    
    

    // If right child is larger than largest so far
    if (r < n && arr[r].Rank> arr[largest].Rank)
        largest = r;
  struct vidh temp;

    if (largest != i) 
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp; 
        // Recursively heapify the affected sub-tree
        MAX_HEAPIFY(arr, n, largest);
    }
}

void BUILD_MAX_HEAP(struct vidh* arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        MAX_HEAPIFY(arr,n,i);
}
 


void MIN_HEAPIFY(struct vidh* arr, int n, int i)
{
     // Initialize largest as root
    int smallest;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].Rank< arr[i].Rank)
        smallest = l;
    else smallest =i;
    // If right child is larger than largest so far
    if (r < n && arr[r].Rank < arr[smallest].Rank)
        smallest = r;
    struct vidh temp;
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
void ENTER(struct vidh* s,int rear)
{ 
 // INSERT and place in order
  rear=rear+1;
  scanf("%d",&s[rear].Student_id);
  scanf("%s",s[rear].Student_name);
  scanf("%d",&s[rear].Rank);
  int i=rear;
  struct vidh temp;
  while(i>0 && s[(i-1)/2].Rank>s[i].Rank)
     {
       temp=s[i];
       s[i]= s[(i-1)/2];
       s[(i-1)/2]=temp; 
	 i=(i-1)/2;
     }
}
void INTERVIEW(struct vidh* s,int rear)
{   
    //EXTRACT_MIN(RANK);
//    printf("\n");
    if(rear>=0)
       printf("%d %s",s[0].Student_id,s[0].Student_name);
    else
       printf("-1");
	

   s[0]=s[rear];
   rear=rear-1;
   MIN_HEAPIFY(s,rear+1,0);
}
void HEAPSORT(struct vidh* local,int n)
{   BUILD_MAX_HEAP(local,n);
    // One by one extract an element from heap
    struct vidh temp;
    for (int i =n-1; i >=1; i--) {
        // Move current root to end
        temp=local[0];
        local[0]=local[i];
        local[i]=temp;

        // call max heapify on the reduced heap
        MAX_HEAPIFY(local, i, 0);
    }
}

void LIST(struct vidh* s,int rear)
{// print all IDs'left in the array
/*	for(int i=0;i<=rear;i++)
		printf("%d ",s[i].Student_id);*/
  struct vidh local[1000];
  	for(int i=0;i<=rear;i++)
  {
     local[i]=s[i];
  }
  HEAPSORT(local,rear+1);
  //printf("\n");
  for(int i=0;i<=rear;i++)
  printf("%d ",local[i].Student_id);

  if(rear<0)
     printf("-1");
}
void main()
 {
    char c;
	int rear=-1;
	struct vidh s[1000];
    while(1)
    {
        scanf("%c",&c);
        switch (c)
        {   case 't': exit(0);
            case 'e':
						ENTER(s,rear);
						rear++;
						break;
            case 'i':
						{INTERVIEW(s,rear);rear--;
						printf("\n");
						break;}
            case 'l':{	LIST(s,rear);printf("\n");break;}
        }
    }
}
