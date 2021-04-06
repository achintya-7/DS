#include<stdio.h>

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}

void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n-1; i++) // no of passes
    {
        for (int j = 0; j < n-1-i; j++) // no of comparisions, reducing by 1 after every pass
            {
                if(a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
    }
    
}

void bubblesortAddaptive(int *a, int n)
{
    int temp;
    int isSorted = 0;

    for(int i = 0; i<n-1; i++)
    {
        printf("working on pass number : %d \n", i+1);
        isSorted = 1;
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    isSorted = 0;
                }
        }    
        if(isSorted)
        {
            return; // will end the function, here it means the array
                    // is already sorted
        }

    }
        
}
int main()
{
    int a[] = {1, 34, 4, 53, 91, 232};
    int n = 6;
    printArray(a, n);
    bubblesortAddaptive(a, n); // sorting the array
    printArray(a, n); // array after sorting
}