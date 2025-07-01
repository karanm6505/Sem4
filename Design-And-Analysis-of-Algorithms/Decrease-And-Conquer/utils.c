#include <stdlib.h>
#include <time.h>
#include "utils.h"

void init_random_seed() 
{
    srand(time(0));
}

void Array(int arr[], int n) 
{
    for(int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 10000;
    }
}
