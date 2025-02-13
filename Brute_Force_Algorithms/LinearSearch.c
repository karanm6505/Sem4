#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int linearSearch(int A[], int n, int key)
{
    int i = 0;
    while(i<n && A[i]!=key)
    {
        i++;
    }
    if(i<n) return i;
    else return -1; 
}

int main() 
{
    init_random_seed();
    clock_t start, end;
    double cpu_time_used;
    
    int sizes[] = {1,5,10,25,50,75,100,250,500,1000,5000,10000,50000,100000,200000,500000,1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Size\tTime (seconds)\n");
    printf("-------------------------\n");
    
    for(int i = 0; i < num_sizes; i++) 
    {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        Array(arr, n);
        
        // We'll search for a number that doesn't exist to get worst-case timing
        int key = 10001;  // Outside our random range of 0-10000
        
        start = clock();
        linearSearch(arr, n, key);  // Worst case - element not found
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, cpu_time_used);
        
        free(arr);
    }
    
    return 0;
}
