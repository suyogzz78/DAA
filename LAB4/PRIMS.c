#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define V 100

int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int vertices) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph, vertices);
}

int main() {
    int vertices;
    clock_t start, end;
    double cpu_time_used;



    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);
    start = clock();
    primMST(graph, vertices);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime executed: %f seconds\n", cpu_time_used);

    return 0;
}