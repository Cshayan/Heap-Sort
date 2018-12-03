#include <stdio.h>
#include <stdlib.h>

void heapify_maxHeap(int arr[], int n, int i)
{
    int temp;
    int largest = i;
    int left = (2*i)+1;
    int right = (2*i)+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        // swap
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //recursively call again
        heapify_maxHeap(arr, n, largest);
    }
}
void build_maxHeap(int arr[], int n)
{
    int i;
    //In array representation of complete binary tree the non-leaf index always starts from (n/2)-1
    for(i=(n/2)-1; i>=0; i--)
        heapify_maxHeap(arr, n, i);
}
int heap_sort(int arr[], int n)
{
    build_maxHeap(arr, n);

    int i, temp;
    for(i=n-1; i>=0; i--)
    {
        //swap the root of max-heap with the last element
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        //call again max-heap function
        heapify_maxHeap(arr, i, 0);
    }
    return arr;
}
int main()
{
    int *arr;
    int n, i;
    printf("\nEnter the size of the array:- ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\nEnter the array to be sorted:- \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    arr = heap_sort(arr, n);
    printf("\nAfter sorting :-\n ");
    for(i=0; i< n; i++)
        printf("%d\t", arr[i]);

        printf("\n");
}
