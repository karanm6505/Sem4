#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++) 
    {
        for(int j = 0; j < n-i-1; j++) 
        {
            if(arr[j] > arr[j+1]) 
            {
               swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main() 
{
    srand(time(0));  
    clock_t start, end;
    double cpu_time_used;
    
    int sizes[] = {1,5,10,25,50,75,100,250,500,1000,5000,10000,50000,100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Size\tTime (seconds)\n");
    printf("-------------------------\n");
    
    for(int i = 0; i < num_sizes; i++) 
    {
        int n = sizes[i];
        
        int *arr = (int*)malloc(n * sizeof(int));
        
        generate_random_array(arr, n);
        
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, cpu_time_used);
        
        free(arr);
    }
    
    return 0;
}
