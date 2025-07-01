#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;
typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initStack(Stack* s) 
{
    s->top = -1;
}
void push(Stack* s, int value)
{
    s->items[++s->top] = value;
}
int pop(Stack* s) 
{
    return s->items[s->top--];
}
int isStackEmpty(Stack* s) 
{
    return s->top == -1;
}


void initQueue(Queue* q)
{
    q->front = q->rear = -1;
}
void enqueue(Queue* q, int value) 
{
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}
int dequeue(Queue* q) 
{
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}
int isQueueEmpty(Queue* q) 
{
    return q->front == -1;
}

Graph* createGraph(int vertices) 
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = vertices;
    
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adj[i][j] = 0;
            
    return graph;
}
void addEdge(Graph* graph, int v, int w)
{
    graph->adj[v][w] = 1;
}
void topologicalSortUtil(Graph* graph, int v, int* visited, Stack* stack) {
    visited[v] = 1;
    
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }
    
    push(stack, v);
}
void topologicalSortDFS(Graph* graph) 
{
    Stack stack;
    initStack(&stack);
    
    int* visited = (int*)calloc(graph->V, sizeof(int));
    
    for (int i = 0; i < graph->V; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, &stack);
    
    printf("Topological Sort (DFS): ");
    while (!isStackEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    
    free(visited);
}
void topologicalSortSourceRemoval(Graph* graph) 
{
    int* inDegree = (int*)calloc(graph->V, sizeof(int));
    Queue queue;
    initQueue(&queue);
    
    for (int i = 0; i < graph->V; i++)
        for (int j = 0; j < graph->V; j++)
            if (graph->adj[i][j])
                inDegree[j]++;
    
    for (int i = 0; i < graph->V; i++)
        if (inDegree[i] == 0)
            enqueue(&queue, i);
    
    printf("Topological Sort (Source Removal): ");
    while (!isQueueEmpty(&queue)) {
        int u = dequeue(&queue);
        printf("%d ", u);
        
        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[u][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    enqueue(&queue, i);
            }
        }
    }
    printf("\n");
    
    free(inDegree);
}
int main() {
    Graph* g = createGraph(6);
    addEdge(g, 5, 2);
    addEdge(g, 5, 0);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);
    addEdge(g, 2, 3);
    addEdge(g, 3, 1);
    
    int choice;
    do {
        printf("\nTopological Sort Methods:\n");
        printf("1. DFS Method\n");
        printf("2. Source Removal Method\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                topologicalSortDFS(g);
                break;
            case 2:
                topologicalSortSourceRemoval(g);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    
    free(g);
    return 0;
}
