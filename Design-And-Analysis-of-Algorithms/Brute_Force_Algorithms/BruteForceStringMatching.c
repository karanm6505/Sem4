#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int StringMatch(char text[], char pattern[], int n, int m)
{
    if (m > n) return -1;  
    
    for(int i = 0; i <= (n-m); i++)
    {
        int j = 0;
        while(j < m && pattern[j] == text[i+j])
        {
            j++;
        }
        if(j == m) return i;  
    }
    return -1;  
}
void generate_random_string(char *str, int length) 
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        int key = rand() % (sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
}
int main()
{
    srand(time(0));
    clock_t start, end;
    double cpu_time_used;
    
    int text_sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    int pattern_sizes[] = {5, 10, 20, 25, 30, 40, 50};  
    int num_sizes = sizeof(text_sizes) / sizeof(text_sizes[0]);
    
    printf("Text Length\tPattern Length\tTime (seconds)\n");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < num_sizes; i++)
    {
        int n = text_sizes[i];
        int m = pattern_sizes[i];
        
        char *text = (char*)malloc((n + 1) * sizeof(char));
        char *pattern = (char*)malloc((m + 1) * sizeof(char));
        
        generate_random_string(text, n);
        generate_random_string(pattern, m);
        
        start = clock();
        int result = StringMatch(text, pattern, n, m);
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d\t\t%d\t\t%f\n", n, m, cpu_time_used);
        
        free(text);
        free(pattern);
    }
    
    return 0;
}

