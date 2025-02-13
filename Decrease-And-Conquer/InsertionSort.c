#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void insertionSort(int A[], int n)
{ 
    for(int i = 1; i < n; i++)
    {
        int v = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];    
            j--;
        }
        A[j+1] = v;
    }
}

int main() 
{
    srand(time(0));  
    clock_t start, end;
    double cpu_time_used;
    
    int sizes[] = {1,5,10,25,50,75,100,250,500,1000,5000,10000,50000,100000,200000,250000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Size\tTime (seconds)\n");
    printf("-------------------------\n");
    
    for(int i = 0; i < num_sizes; i++) 
    {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        Array(arr, n);
        
        start = clock();
        insertionSort(arr, n);
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, cpu_time_used);
        
        free(arr);
    }
    
    return 0;
}