#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}


int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;
}

void countSort(int * A, int n)
{
    int i, j;
    //find the maximum element A
    int max = maximum(A, n);

    //form the new array dynamically
    int *count = (int*)malloc((max+1) * sizeof(int)); //lets say max is 9 
                                                     //then we want an element of size 10
    // initialize the array element to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    // increment thr corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0; // counter for count array
    j = 0; // counter for given arrat

    while (i <= max)
    {
        if(count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;   
        }
        else
            i++;
    }
    

                            
}
int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n); 
    return 0;

}