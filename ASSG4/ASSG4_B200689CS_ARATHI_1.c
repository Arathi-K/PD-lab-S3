#include <stdio.h>
#include <stdlib.h>
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap

int comp=0;

void MAX_HEAPIFY(int* arr, int n, int i)
{
     // Initialize largest as root
    int largest,temp;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    comp++;
    if (l < n && arr[l] > arr[i])
        largest = l;
    else largest =i;    
    
    if (l >= n)
        comp--;

    // If right child is larger than largest so far
    comp++;
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    if (r >= n)
        comp--;

    // If largest is not root
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
// main function to do heap sort
void HEAPSORT(int* arr, int n)
{
    // Build heap (rearrange array)
    BUILD_MAX_HEAP(arr,n);
    // One by one extract an element from heap
    for (int i = n - 1; i >=1; i--) {
        // Move current root to end
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
 
        // call max heapify on the reduced heap
        MAX_HEAPIFY(arr, i, 0);
    }
}
 
// Driver code
int main()
{   int n,i;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(i = 0; i < n; ++i)
       scanf("%d",&arr[i]);
    HEAPSORT(arr, n);
    for (i = 0; i < n; ++i)
        printf("%d ",arr[i]);
    printf("\n%d ",comp);

    return 0;
}
