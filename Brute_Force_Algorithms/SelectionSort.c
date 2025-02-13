#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[],int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}
int main() 
{
    srand(time(0));
    clock_t start, end;
    double cpu_time_used;
    
    int sizes[] = {1,5,10,25,50,75,100,250,500,1000,5000,10000,50000,100000,150000,200000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Size\tTime (seconds)\n");
    printf("-------------------------\n");
    
    for(int i = 0; i < num_sizes; i++) 
    {
        int n = sizes[i];
        
        int *arr = (int*)malloc(n * sizeof(int));
        Array(arr, n);
        
        start = clock();
        selectionSort(arr, n);
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, cpu_time_used);
        
        free(arr);
    }
    
    return 0;
}