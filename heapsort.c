#include <stdio.h>
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void heapify(int arr[], int n, int i)
{ 
    int par = i; 
    int lc = (2 * i) + 1;
    int rc = (2 * i) + 2;

    if (lc < n && arr[lc] > arr[par]) 
        par = lc;
    if (rc < n && arr[rc] > arr[par]) 
        par = rc;
    if (par != i) 
    {
        swap(&arr[i], &arr[par]);
        heapify(arr, n, par); 
     }  
 
}
void buildheap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
}
void heapSort(int arr[], int n) 
{
    
	buildheap(arr,n);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);    
    }
}

int main()
{
    int arr[100], size;
    printf("Enter size of the tree");
    scanf("%d", &size);
    printf("Elements on the tree \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    heapSort(arr, size);
    printf("\nSorted tree\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
