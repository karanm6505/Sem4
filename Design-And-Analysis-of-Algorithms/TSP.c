#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10

typedef struct graph 
{
    int v;
    int g[MAX][MAX];
} Graph;
typedef struct result 
{
    int cost;
    int path[MAX];
    int pathSize;
} Result;
Graph* initGraph()
{
    Graph* g = (Graph *)(malloc(sizeof(Graph)));
    g->v = 0;
    return g;
}
Result* initResult()
{
    Result* result = (Result*)malloc(sizeof(Result));
    result->cost = INT_MAX;
    result->pathSize = 0;
    return result;
}
void populateGraph(Graph* g)
{
    printf("Enter the adjacency matrix row by row:\n");
    for(int i = 0; i < g->v; i++)
    {
        printf("Enter row %d (space separated %d numbers): ", i, g->v);
        for(int j = 0; j < g->v; j++)
        {
            scanf("%d", &g->g[i][j]);
        }
    }
}
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int calculatePathCost(Graph* g, int path[], int n) 
{
    int cost = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        cost += g->g[path[i]][path[i + 1]];
    }
    cost += g->g[path[n-1]][path[0]];
    return cost;
}
void copyPath(int dest[], int src[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        dest[i] = src[i];
    }
}
bool isLexicographicallySmaller(int path1[], int path2[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (path1[i] < path2[i]) return true;
        if (path1[i] > path2[i]) return false;
    }
    return false;
}
void findTSP(Graph* g, int curr_path[], int visited[], int pos, Result* best, int n) 
{
    if (pos == n) 
    {
        int curr_cost = calculatePathCost(g, curr_path, n);
        if (curr_cost < best->cost || 
           (curr_cost == best->cost && isLexicographicallySmaller(curr_path, best->path, n))) 
        {
            best->cost = curr_cost;
            copyPath(best->path, curr_path, n);
            best->pathSize = n;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            curr_path[pos] = i;
            findTSP(g, curr_path, visited, pos + 1, best, n);
            visited[i] = 0;
        }
    }
}
Result* calculate(Graph* g) 
{
    Result* result = initResult();

    int* curr_path = (int*)malloc(g->v * sizeof(int));
    int* visited = (int*)calloc(g->v, sizeof(int));
    
    visited[0] = 1; 
    curr_path[0] = 0;
    
    findTSP(g, curr_path, visited, 1, result, g->v);
    
    free(curr_path);
    free(visited);
    return result;
}
int main() 
{
    int n;
    printf("Enter number of districts: ");
    scanf("%d", &n);
    
    Graph* graph = initGraph();
    graph->v = n;
    populateGraph(graph);
    
    Result* result = calculate(graph);
    
    printf("Minimum Cost: %d\n", result->cost);
    printf("Path: ");
    for (int i = 0; i < result->pathSize; i++) 
    {
        printf("%d", result->path[i]);
        if (i < result->pathSize) 
            printf(" -> ");
        else printf("  ");
    }
    printf("%d\n", result->path[0]);  
    
    free(result);
    free(graph);
    return 0;
}