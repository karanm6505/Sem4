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
int LomutoPartition(int A[], int l, int r) 
{
    int p = A[l];
    int s = l;
    for (int i = l + 1; i <= r; i++) {
        if (A[i] < p) {
            s = s + 1;
            swap(&A[s], &A[i]);
        }
    }
    swap(&A[l], &A[s]);
    return s;
}
int QuickSelect(int A[], int l, int r, int k) 
{        
    if (l == r)  
        return A[l];

    int s = LomutoPartition(A, l, r);

    if (s == k)
        return A[s];
    else if (s > k)
        return QuickSelect(A, l, s - 1, k);
    else
        return QuickSelect(A, s + 1, r, k);  
}
int main() 
{
    srand(time(0));
    clock_t start, end;
    double cpu_time_used;

    int sizes[] = {1, 5, 10, 25, 50, 75, 100, 250, 500, 1000, 5000, 10000, 50000, 100000, 200000, 250000,500000,1000000,2500000,5000000,10000000,25000000,50000000,100000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Size\tTime (seconds)\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for size %d\n", n);
            return 1;
        }

        Array(arr, n);

        start = clock();
        int result = QuickSelect(arr, 0, n - 1, n / 2);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, cpu_time_used);

        free(arr);
    }

    return 0;
}
