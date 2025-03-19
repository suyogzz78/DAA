#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int findRoot(Subset subsets[], int i) {
    while (subsets[i].parent != i) {
        subsets[i].parent = subsets[subsets[i].parent].parent; 
        i = subsets[i].parent;
    }
    return i;
}

void uniteSets(Subset subsets[], int x, int y) {
    int rootX = findRoot(subsets, x);
    int rootY = findRoot(subsets, y);

    if (rootX != rootY) {
        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}

void findMST(Edge edges[], int V, int E) {
    if (E < V - 1) {  
        printf("MST is not possible. Not enough edges.\n");
        return;
    }

    qsort(edges, E, sizeof(Edge), compareEdges);

    Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int mstSize = 0, edgeIndex = 0;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    
    while (mstSize < V - 1 && edgeIndex < E) {
        Edge nextEdge = edges[edgeIndex++];
        int rootU = findRoot(subsets, nextEdge.u);
        int rootV = findRoot(subsets, nextEdge.v);

        if (rootU != rootV) {
            printf("%d -- %d == %d\n", nextEdge.u + 1, nextEdge.v + 1, nextEdge.weight); 
            uniteSets(subsets, rootU, rootV);
            mstSize++;
        }
    }

    if (mstSize != V - 1) {
        printf("MST could not be formed completely. The graph may be disconnected.\n");
    }
}

int main() {
    int V, E;
    clock_t start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    if (V <= 0 || E < 0) {
        printf("Invalid input. Number of vertices and edges must be non-negative.\n");
        return 1;
    }

    Edge edges[E];
    printf("Enter edge details (u v weight) [1-based indexing]:\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);

        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid edge. Vertices should be in range [1, %d].\n", V);
            i--; 
            continue;
        }

        edges[i].u = u - 1; 
        edges[i].v = v - 1; 
        edges[i].weight = weight;
    }

    start = clock();
    findMST(edges, V, E);
    end = clock();

    printf("\nTime executed: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}
