#include <stdio.h>
#include <limits.h>
#include <time.h>

#define V 100 // Maximum number of vertices

int minDistance(int dist[], int sptSet[], int vertices) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < vertices; v++)
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printSolution(int dist[], int vertices) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src, int vertices) {
    int dist[V];  // Stores shortest distances
    int sptSet[V]; // Shortest path tree set

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    
    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        if (u == -1) break; // No reachable vertices left

        sptSet[u] = 1;

        for (int v = 0; v < vertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, vertices);
}

int main() {
    int vertices, src;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices > V || vertices <= 0) {
        printf("Invalid number of vertices! Must be between 1 and %d.\n", V);
        return 1;
    }

    int graph[V][V];

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    if (src < 0 || src >= vertices) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    start = clock();
    dijkstra(graph, src, vertices);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime executed: %f seconds\n", cpu_time_used);

    return 0;
}
