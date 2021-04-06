#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while(a[i] <= pivot)
        {
            i++;
        }
        while(a[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = a[i];
            a[j] = a[j];
            a[j] = temp;
        }
    }while(i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = a[low];
    
    return j;
    
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; //index of pivot after partition

    if(low<high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1); // sort left sub array
        quickSort(A, partitionIndex + 1, high); // sort right sub array
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;

    printArray(A, n);
    quickSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}

